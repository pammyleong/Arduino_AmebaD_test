/****************************************************************************
*
*    The MIT License (MIT)
*
*    Copyright (c) 2017 - 2021 Vivante Corporation
*
*    Permission is hereby granted, free of charge, to any person obtaining a
*    copy of this software and associated documentation files (the "Software"),
*    to deal in the Software without restriction, including without limitation
*    the rights to use, copy, modify, merge, publish, distribute, sublicense,
*    and/or sell copies of the Software, and to permit persons to whom the
*    Software is furnished to do so, subject to the following conditions:
*
*    The above copyright notice and this permission notice shall be included in
*    all copies or substantial portions of the Software.
*
*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
*    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
*    DEALINGS IN THE SOFTWARE.
*
*****************************************************************************/

#include <gc_vip_hardware.h>
#include <gc_vip_kernel_port.h>
#include <gc_vip_kernel_drv.h>
#include <gc_vip_video_memory.h>
#include <gc_vip_common.h>
#include <gc_vip_kernel_pm.h>

/*
@brief software resrt hardware.
*/
static vip_status_e reset_vip(void)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t control = 0, idle = 0;
	vip_uint32_t count = 0;
	vip_uint32_t try_count = 0;
	vip_uint32_t value = 0;

	gckvip_write_register(0x00000, 0x00010900);

	while ((count < 2) && (try_count < 10)) {
		/* Disable clock gating. */
		gckvip_write_register(0x00104, 0x00000000);

		/* Disable pulse-eater. */
		control = 0x01590880 | 0x20000;      /* Disable auto-pulse.*/
		gckvip_write_register(0x0010C, control);
		gckvip_write_register(0x0010C, (control | 0x1));
		gckvip_write_register(0x0010C, control);
		gckvip_write_register(0x00000, 0x00010900 | 0x200);    /* FSCALE_CMD_LOAD */
		gckvip_write_register(0x00000, 0x00010900);

		/* Wait for clock being stable. */
		gckvip_os_delay(1);

		/* Isolate the VIP. */
		control = 0x00010900 | 0x80000;
		gckvip_write_register(0x00000, control);
		/* Reset VIP in TA. */
		gckvip_write_register(0x003A8, 0x1);

		/* Wait for reset. */
		gckvip_os_delay(1);

		/* Reset soft reset bit. */
		gckvip_write_register(0x00000, SETBIT(control, 12, 0));

		/* Reset VIP isolation. */
		control &= ~0x80000;
		gckvip_write_register(0x00000, control);

		/* Read idle register. */
		gckvip_read_register(0x00004, &idle);
		if ((idle & 0x1) == 0) {    /* if either FE or MC is not idle, try again. */
			PRINTK("reset vip read idle=0x%08X\n", idle);
			try_count++;
			continue;
		}

#if vpmdENABLE_CAPTURE_IN_KERNEL
		PRINTK("@[register.wait 0x%05X 0x%08X 0x%08X]\n", 0x00004, 0x1, idle);
#endif

		/* Read reset register. */
		gckvip_read_register(0x00000, &control);
		if ((control & 0x30000) != 0x30000) {
			PRINTK("reset vip control=0x%08X\n", control);
			try_count++;
			continue;
		}

#if vpmdENABLE_CAPTURE_IN_KERNEL
		PRINTK("@[register.wait 0x%05X 0x%08X 0x%08X]\n", 0x00000, 0x30000, control);
#endif

		gckvip_read_register(0x00388, &control);
		if (control & 0x01) {
			PRINTK("mmu control=0x%08X\n", control);
			try_count++;
			continue;
		}

#if vpmdENABLE_CAPTURE_IN_KERNEL
		PRINTK("@[register.wait 0x%05X 0x%08X 0x%08X]\n", 0x00388, 0x001, control);
#endif

		count++;
	}

	gckvip_write_register(0x0055C, 0x00FFFFFF);
	gckvip_read_register(0x00090, &value);
	value &= 0xFFFFFFBF;
	gckvip_write_register(0x00090, value);

	return status;
}

/*
@brief initialzie vip hardware register.
*/
static vip_status_e init_vip(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t control = 0xcdcdcdcd;
	vip_uint32_t data = 0xcdcdcdcd;

	/* Disable isolate VIP bit. */
	gcOnError(gckvip_write_register(0x00000, SETBIT(0x00010900, 19, 0)));
	gcOnError(gckvip_read_register(0x00000, &control));

	/* Enable debug register. */
	gcOnError(gckvip_write_register(0x00000, SETBIT(control, 11, 0)));
	gckvip_write_register(0x003A8, SETBIT(0, 1, 1));

	/* Reset memory counters. */
	gckvip_write_register(0x0003C, ~0U);
	gckvip_write_register(0x0003C, 0);

	/* Enable clock gating. */
	gckvip_read_register(0x00100, &data);
	data = SETBIT(data, 0, 1);
	gckvip_write_register(0x00100, data);

	/* 2. enable MMU */
#if vpmdENABLE_MMU
	status = gckvip_mem_mmu_enable(context);
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to enable MMU\n");
		gcGoOnError(VIP_ERROR_IO);
	}
#endif

	gckvip_read_register(0x00104, &data);
	/* Disable GPIPE clock gating. */
	data = SETBIT(data, 22, 1);
	/* Disable RA HZ clock gating. */
	data = SETBIT(data, 17, 1);
	/* Disable RA EZ clock gating. */
	data = SETBIT(data, 16, 1);
	if (((context->chip_ver1 & 0x9000) == 0x9000) &&
		((context->chip_ver2 & 0x8300) == 0x8300)) {
		data = SETBIT(data, 3, 1);
	}
	gckvip_write_register(0x00104, data);

	gckvip_read_register(0x0010C, &data);
	data = SETBIT(data, 16, 0);
	data = SETBIT(data, 17, 1);
	gckvip_write_register(0x0010C, data);

	if (0 == context->axi_sram_size) {
		gckvip_read_register(0x00090, &data);
		data |= SETBIT(data, 6, 1);
		gckvip_write_register(0x00090, data);
	}

onError:
	return status;
}

#if vpmdENABLE_DEBUG_LOG > 2
static vip_status_e check_clock_begin(
	vip_uint64_t *start_MC,
	vip_uint64_t *start_SH
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint64_t mc_start, sh_start;

	mc_start = gckvip_os_get_time();
	gckvip_write_register(0x00438, 0);
	*start_MC = mc_start;

	gckvip_write_register(0x00470, 0xFF << 24);
	sh_start = gckvip_os_get_time();
	gckvip_write_register(0x00470, 0x4 << 24);
	*start_SH = sh_start;

	return status;
}

static vip_status_e check_clock_end(
	vip_uint64_t *end_MC,
	vip_uint64_t *end_SH,
	vip_uint64_t *cycles_MC,
	vip_uint64_t *cycles_SH
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint64_t mc_end = 0, sh_end = 0;
	vip_uint32_t mc_cycles = 0, sh_cycles = 0;

	mc_end = gckvip_os_get_time();
	gckvip_read_register(0x00438, &mc_cycles);
	if (mc_cycles == 0) {
		status = VIP_ERROR_IO;
		return status;
	}

	sh_end = gckvip_os_get_time();
	gckvip_read_register(0x0045C, &sh_cycles);
	if (sh_cycles == 0) {
		sh_cycles = mc_cycles;
	}

	*end_MC = mc_end;
	*end_SH = sh_end;
	*cycles_MC = (vip_uint64_t)mc_cycles;
	*cycles_SH = (vip_uint64_t)sh_cycles;

	return status;
}
#endif

#if vpmdENABLE_WAIT_LINK_LOOP
/*
@brief generate a wait-link command for command buffer.
*/
static vip_uint32_t *cmd_wait_link(
	vip_uint32_t *command,
	vip_uint32_t time,
	vip_uint32_t bytes,
	vip_uint32_t address
)
{
	command[0] = ((7 << 27) | (time));
	command[1] = 0;

	gckvip_os_memorybarrier();

	command[2] = ((8 << 27) | ((bytes + 7) >> 3));
	gckvip_os_memorybarrier();
	command[3] = address;

	gckvip_os_memorybarrier();

	/* Return the link command location, for later to modify. */
	return command;
}

#else

/*
@brief append END command at the command address.
*/
static vip_uint32_t cmd_append_end(
	vip_uint32_t *command
)
{
	command[0] = (2 << 27);
	command[1] = 0;

	gckvip_os_memorybarrier();

	return END_SIZE;
}
#endif

/*
@brief Link to a new command buffer address.
*/
#if vpmdENABLE_MMU || vpmdENABLE_WAIT_LINK_LOOP
static vip_uint32_t *cmd_update_link(
	vip_uint32_t *command,
	vip_uint32_t bytes,
	vip_uint32_t address
)
{
	command[1] = address;
	/*
	  you need to make sure that Link[1] is written to memory before Link[0].
	  So, call memory barrier in here.
	*/
	gckvip_os_memorybarrier();

	command[0] = ((8 << 27) | ((bytes + 7) >> 3));

	/* Memory barrier. */
	gckvip_os_memorybarrier();

	return &command[0];
}
#endif

/*
@brief append EVENT command at the command address.
*/
static vip_uint32_t cmd_append_event(
	vip_uint32_t *command,
	vip_uint32_t block,
	vip_uint32_t id
)
{
	command[0] = ((1 << 27) | (1 << 16) | (0x0E01));
	command[1] = ((id & 0x0000000f) | (block));

	/* Make sure the event ID gets written out before VIP can access it. */
	gckvip_os_memorybarrier();

	return 8;
}

/*
@brief
    do initialze hardware
*/
vip_status_e gckvip_hw_init(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t mmu_status = 0;

	PRINTK_I("hardware initialize..\n");

	/* 1. Init VIP. */
	status = init_vip(context);
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to init vip\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	/* 2. Enable all Interrupt EVENTs. */
	gckvip_write_register(0x00014, 0xFFFFFFFF);

	gckvip_os_memorybarrier();

	gckvip_read_register(0x00388, &mmu_status);
	if ((mmu_status & 0x01) == 0x00) {
		PRINTK_I("   MMU is disabled\n");
	} else {
		PRINTK_I("   MMU is enabled\n");
	}

onError:
	return status;
}


/* shut down VIP hardware */
vip_status_e gckvip_hw_destroy(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;

	return status;
}

/*
@ brief
    Do a software HW reset.
*/
vip_status_e gckvip_hw_reset()
{
	return reset_vip();
}

/*
@ brief
    Insert flush mmu cache load states
*/
#if vpmdENABLE_MMU
vip_status_e gckvip_hw_flush_mmu(
	gckvip_context_t *context,
	gckvip_submit_t *submit
)
{
	vip_uint32_t physical = submit->cmd_physical;
	vip_uint8_t *flush_logical_end = (vip_uint8_t *)context->ptr_MMU_flush->logical + FLUSH_MMU_STATES_SIZE;
	vip_uint32_t size = 0;

	if (submit->cmd_size > gcdVIP_MAX_CMD_SIZE) {
		size = gcdVIP_MAX_CMD_SIZE;
	} else {
#if vpmdENABLE_WAIT_LINK_LOOP
		size = submit->cmd_size + WAIT_LINK_SIZE + EVENT_SIZE;
#else
		size = submit->cmd_size + END_SIZE + EVENT_SIZE;
#endif
	}

	/* link flush mmu states and command buffer */
	cmd_update_link((vip_uint32_t *)flush_logical_end, size, physical);

#if vpmdENABLE_FLUSH_CPU_CACHE
	gckvip_flush_cache(context->ptr_MMU_flush->handle, context->ptr_MMU_flush->physical,
					   context->ptr_MMU_flush->logical, FLUSH_MMU_STATES_SIZE + LINK_SIZE,
					   GCKVIP_CACHE_FLUSH);
#endif

	return VIP_SUCCESS;
}
#endif

#if vpmdENABLE_WAIT_LINK_LOOP
/*
@ brief
    trigger hardware, NPU start to run.
    write wait/link physical base address
    to command control register for starting vip.
*/
vip_status_e gckvip_hw_trigger(
	gckvip_context_t *context
)
{
	cmd_wait_link(context->waitlinkbuf_logical, WAIT_TIME_EXE,
				  context->waitlinkbuf_size, context->waitlinkbuf_physical);

#if vpmdENABLE_FLUSH_CPU_CACHE
	gckvip_flush_cache(context->waitlinkbuf_handle, context->waitlinkbuf_physical,
					   context->waitlinkbuf_logical, context->waitlinkbuf_size,
					   GCKVIP_CACHE_FLUSH);
#endif

	gckvip_write_register(0x00654, context->waitlinkbuf_physical);
	/* Make sure writing to command buffer and previous AHB register is done. */
	gckvip_os_memorybarrier();

	gckvip_write_register(0x003A4, 0x00010000 | ((context->waitlinkbuf_size + 7) >> 3));

	PRINTK_D("wait-link, setup FE done..\n");

	return VIP_SUCCESS;
}

/*
@ brief
    submit a command to hardware.
*/
vip_status_e gckvip_hw_submit(
	gckvip_context_t *context,
	gckvip_submit_t *submit
)
{
	vip_uint32_t *ptr = VIP_NULL;
	vip_uint32_t trigger_physical = submit->cmd_physical;
	vip_uint32_t trigger_size = 0;
	vip_uint32_t last_cmd_size = submit->last_cmd_size;
	vip_uint32_t cmd_size = submit->cmd_size;

	if ((VIP_NULL == submit->cmd_logical) || (VIP_NULL == submit->last_cmd_logical)) {
		PRINTK_E("failed to submit hardware command, logical=0x%" PRIx64", last_logical=0x%" PRIx64"\n",
				 GCKVIPPTR_TO_UINT64(submit->cmd_logical), GCKVIPPTR_TO_UINT64(submit->last_cmd_logical));
		return VIP_ERROR_FAILURE;
	}

	if (submit->cmd_size > 0) {
		context->vip_idle = vip_false_e;
		context->power_status = GCKVIP_POWER_ON;

		/* Append the PE event command. */
		if (GCKVIP_SUBMIT_WITH_EVENT == submit->wait_event) {
			last_cmd_size += cmd_append_event((vip_uint32_t *)(submit->last_cmd_logical + last_cmd_size),
											  (1 << 6), 4);
		}
		/* Append the wait-link command combo to the command buffer. */
		ptr = cmd_wait_link((vip_uint32_t *)(submit->last_cmd_logical + last_cmd_size),
							WAIT_TIME_EXE, WAIT_LINK_SIZE,
							submit->last_cmd_physical + last_cmd_size);
		last_cmd_size += WAIT_LINK_SIZE;

#if vpmdENABLE_FLUSH_CPU_CACHE
		gckvip_flush_cache(submit->last_cmd_handle, submit->last_cmd_physical + submit->last_cmd_size,
						   submit->last_cmd_logical + submit->last_cmd_size, APPEND_COMMAND_SIZE,
						   GCKVIP_CACHE_FLUSH);
#endif

		/* submit group */
		if (submit->cmd_logical == submit->last_cmd_logical) {
			cmd_size = last_cmd_size;
		} else {
			cmd_size += LINK_SIZE;
		}

		if (cmd_size > gcdVIP_MAX_CMD_SIZE) {
			trigger_size = gcdVIP_MAX_CMD_SIZE - 7;
		} else {
			trigger_size = cmd_size;
		}

#if vpmdENABLE_MMU
		if (1 == context->flush_mmu) {
			trigger_physical = context->ptr_MMU_flush->physical;
			trigger_size = context->ptr_MMU_flush->size;
			context->flush_mmu = 0;
		}
#endif

		/* Update the link command to wait-link buffer. */
		cmd_update_link(context->waitlink_pos, trigger_size, trigger_physical);

#if vpmdENABLE_FLUSH_CPU_CACHE
		gckvip_flush_cache(context->waitlinkbuf_handle, context->waitlinkbuf_physical,
						   context->waitlink_pos, context->waitlinkbuf_size,
						   GCKVIP_CACHE_FLUSH);
#endif

		context->waitlink_pos = ptr;
	} else {
		PRINTK_E("error, submit size is 0\n");
	}

	return VIP_SUCCESS;
}

/*
@ brief
    hardware go back to WL.
*/
vip_status_e gckvip_hw_idle(
	gckvip_context_t *context
)
{
	if (vip_false_e == context->vip_idle) {
		/* switch to the kernel's WL command. */
		/* Ensure the kernel WL is a closed loop. */
		cmd_wait_link(context->waitlinkbuf_logical, WAIT_TIME_EXE,
					  context->waitlinkbuf_size, context->waitlinkbuf_physical);

#if vpmdENABLE_FLUSH_CPU_CACHE
		gckvip_flush_cache(context->waitlinkbuf_handle, context->waitlinkbuf_physical,
						   context->waitlinkbuf_logical, context->waitlinkbuf_size,
						   GCKVIP_CACHE_FLUSH);
#endif

		/* Update the command link to the kernel WL command. */
		cmd_update_link(context->waitlink_pos, context->waitlinkbuf_size, context->waitlinkbuf_physical);

		context->waitlink_pos = context->waitlinkbuf_logical;
		context->vip_idle = vip_true_e;

#if vpmdPOWER_OFF_TIMEOUT
#if vpmdENABLE_MULTIPLE_TASK
		gckvip_os_lock_mutex(context->power_mutex);
#endif

		context->power_status = GCKVIP_POWER_IDLE;
		gckvip_os_stop_timer(context->power_timer);
		gckvip_os_start_timer(context->power_timer, vpmdPOWER_OFF_TIMEOUT);

		context->user_query_power = vip_false_e; /* user commands is complete */

#if vpmdENABLE_MULTIPLE_TASK
		gckvip_os_unlock_mutex(context->power_mutex);
#endif
#endif
	} else {
		PRINTK_D("vip in idle status, don't need going to idle again\n");
	}

	return VIP_SUCCESS;
}
#else
vip_status_e gckvip_hw_submit(
	gckvip_context_t *context,
	gckvip_submit_t *submit
)
{
	vip_uint32_t trigger_physical = submit->cmd_physical;
	vip_uint32_t trigger_size = 0;
	vip_uint32_t last_cmd_size = submit->last_cmd_size;
	vip_uint32_t cmd_size = submit->cmd_size;

	if ((VIP_NULL == submit->cmd_logical) || (VIP_NULL == submit->last_cmd_logical)) {
		PRINTK_E("failed to submit hardware command, logical=0x%" PRIx64", last_logical=0x%" PRIx64"\n",
				 GCKVIPPTR_TO_UINT64(submit->cmd_logical), GCKVIPPTR_TO_UINT64(submit->last_cmd_logical));
		return VIP_ERROR_FAILURE;
	}

	if (submit->cmd_size > 0) {
		gckvip_pm_set_frequency(context->core_fscale_percent);
		context->power_status = GCKVIP_POWER_ON;

		context->vip_idle = vip_false_e;

		/* Append the PE event command. */
		if (GCKVIP_SUBMIT_WITH_EVENT == submit->wait_event) {
			last_cmd_size += cmd_append_event((vip_uint32_t *)(submit->last_cmd_logical + last_cmd_size),
											  (1 << 6), 4);
		}

		last_cmd_size += cmd_append_end((vip_uint32_t *)(submit->last_cmd_logical + last_cmd_size));

#if vpmdENABLE_FLUSH_CPU_CACHE
		gckvip_flush_cache(submit->last_cmd_handle, submit->last_cmd_physical + submit->last_cmd_size,
						   submit->last_cmd_logical + submit->last_cmd_size, APPEND_COMMAND_SIZE,
						   GCKVIP_CACHE_FLUSH);
#endif


		/* submit group */
		if (submit->cmd_logical == submit->last_cmd_logical) {
			cmd_size = last_cmd_size;
		} else {
			cmd_size += LINK_SIZE;
		}

		if (cmd_size > gcdVIP_MAX_CMD_SIZE) {
			trigger_size = gcdVIP_MAX_CMD_SIZE - 7;
		} else {
			trigger_size = cmd_size + 7;
		}

#if vpmdENABLE_MMU
		if (1 == context->flush_mmu) {
			trigger_physical = context->ptr_MMU_flush->physical;
			trigger_size = context->ptr_MMU_flush->size + 7;
			context->flush_mmu = 0;
		}
#endif

		// rtk, cmdbufferaddr <- trigger_physical, cmdbufferAhbcontrol = 0x10000|(trigger_size>>3) ????
		gckvip_write_register(0x00654, trigger_physical);
		/* Make sure writing to command buffer and previous AHB register is done. */
		gckvip_os_memorybarrier();

		gckvip_write_register(0x003A4, 0x00010000 | (trigger_size >> 3));
	} else {
		PRINTK_I("ignore this submit, size is 0\n");
	}

	return VIP_SUCCESS;
}

/*
@ brief query hardware status, runnign or idle.
*/
vip_status_e gckvip_hw_idle(
	gckvip_context_t *context
)
{
	if (vip_false_e == context->vip_idle) {
		gckvip_pm_set_frequency(1);

#if vpmdPOWER_OFF_TIMEOUT
#if vpmdENABLE_MULTIPLE_TASK
		gckvip_os_lock_mutex(context->power_mutex);
#endif

		context->power_status = GCKVIP_POWER_IDLE;
		gckvip_os_stop_timer(context->power_timer);
		gckvip_os_start_timer(context->power_timer, vpmdPOWER_OFF_TIMEOUT);

		context->user_query_power = vip_false_e; /* user commands is complete */

#if vpmdENABLE_MULTIPLE_TASK
		gckvip_os_unlock_mutex(context->power_mutex);
#endif
#endif

		context->vip_idle = vip_true_e;
	} else {
		PRINTK_I("vip in idle status, don't need going to idle again\n");
	}

	return VIP_SUCCESS;
}
#endif

#if vpmdENABLE_DEBUG_LOG > 2
/*
@ brief
    get frequency of MC and SH.
*/
vip_status_e gckvip_hw_get_clock(
	vip_uint64_t *clk_MC,
	vip_uint64_t *clk_SH
)
{
	vip_uint64_t mc_start = 0, sh_start = 0, mc_end = 0, sh_end = 0;
	vip_uint64_t mc_cycles = 0, sh_cycles = 0;
	vip_uint64_t mc_freq = 0, sh_freq = 0;
	vip_uint32_t data = 1000000U << 12;
	vip_uint32_t diff = 0, div = 0;
	vip_status_e status = VIP_SUCCESS;

	status = check_clock_begin(&mc_start, &sh_start);
	if (status != VIP_SUCCESS) {
		return status;
	}

	gckvip_os_delay(50);

	status = check_clock_end(&mc_end, &sh_end, &mc_cycles, &sh_cycles);
	if (status != VIP_SUCCESS) {
		return status;
	}

	diff = (vip_uint32_t)(mc_end - mc_start);
	diff = diff <= 0 ? 1 : diff; // rtk
	div = data / diff;
	mc_freq = (mc_cycles * (vip_uint64_t)div) >> 12;
	*clk_MC = mc_freq;

	diff = (vip_uint32_t)(sh_end - sh_start);
	diff = diff <= 0 ? 1 : diff; // rtk
	div = data / diff;
	sh_freq = (sh_cycles * (vip_uint64_t)div) >> 12;
	*clk_SH = sh_freq;

	return status;
}
#endif

vip_status_e gckvip_hw_read_info(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;

	gckvip_write_register(0x00000, 0x00010900);

	gckvip_read_register(0x00020, &context->chip_ver1);

	gckvip_read_register(0x00024, &context->chip_ver2);

	gckvip_read_register(0x00030, &context->chip_cid);

	gckvip_read_register(0x00028, &context->chip_date);

	PRINTK_I("ver1=0x%04x, ver2=0x%04x, cid=0x%04x, date=0x%08x\n",
			 context->chip_ver1, context->chip_ver2, context->chip_cid,
			 context->chip_date);

	return status;
}

/*
@brief  read a hardware register.
@param  address, the address of hardware register.
@param  data, read data from register.
*/
vip_status_e gckvip_read_register(
	vip_uint32_t address,
	vip_uint32_t *data
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_context_t *context = gckvip_get_context();
	if (VIP_NULL == context->reg_base) {
		PRINTK_E("failed to read register, base address is NULL\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	if (GCKVIP_POWER_OFF == context->power_status) {
		PRINTK_E("HW is power off status.\n");
		return VIP_ERROR_NOT_SUPPORTED;
	}

#if vpmdENABLE_MULTIPLE_TASK
	if (context->reg_mutex != VIP_NULL) {
		status = gckvip_os_lock_mutex(context->reg_mutex);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to lock video register mutex write register\n");
			return VIP_ERROR_FAILURE;
		}
	}
#endif

	gcOnError(gckvip_os_read_reg(context->reg_base, address, data));

onError:
#if vpmdENABLE_MULTIPLE_TASK
	if (context->reg_mutex != VIP_NULL) {
		status = gckvip_os_unlock_mutex(context->reg_mutex);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to unlock video register mutex write register\n");
		}
	}
#endif
	return status;
}

/*
@brief  write a hardware register.
@param  address, the address of hardware register.
@param  data, write data to register.
*/
vip_status_e gckvip_write_register(
	vip_uint32_t address,
	vip_uint32_t data
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_context_t *context = gckvip_get_context();
	if (VIP_NULL == context->reg_base) {
		PRINTK_E("failed to write register, base address is NULL\n");
		return VIP_ERROR_OUT_OF_MEMORY;
	}

	if (GCKVIP_POWER_OFF == context->power_status) {
		PRINTK_E("HW is power off status.\n");
		return VIP_ERROR_NOT_SUPPORTED;
	}

#if vpmdENABLE_MULTIPLE_TASK
	if (context->reg_mutex != VIP_NULL) {
		status = gckvip_os_lock_mutex(context->reg_mutex);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to lock video register mutex write register\n");
			return VIP_ERROR_FAILURE;
		}
	}
#endif

	gcOnError(gckvip_os_write_reg(context->reg_base, address, data));

onError:
#if vpmdENABLE_MULTIPLE_TASK
	if (context->reg_mutex != VIP_NULL) {
		status = gckvip_os_unlock_mutex(context->reg_mutex);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to unlock video register mutex write register\n");
		}
	}
#endif
	return status;
}

/*
@brief query hardware is idle.
*/
vip_bool_e gckvip_hw_query_idle(void)
{
	vip_uint32_t data = 0;
	gckvip_context_t *context = gckvip_get_context();

	if (vip_false_e == context->vip_idle) {
		return vip_false_e;
	}

	gckvip_read_register(0x00004, &data);

	/* SH/NN/TP are idle */
	if (data & (1 < 3) && (data & (1 < 18)) && (data & (1 < 19))) {
		return vip_true_e;
	} else {
		return vip_false_e;
	}
}

/*
@brief poll to waiting hardware going to idle.
@param timeout the number of milliseconds this waiting.
*/
vip_status_e gckvip_hw_wait_poll(
	vip_uint32_t timeout
)
{
#define POLL_SPACE   5  /* 5ms */
	vip_status_e status = VIP_SUCCESS;
	vip_int32_t count = (vip_int32_t)timeout / POLL_SPACE;
	vip_uint32_t idle_reg = 0;
	gckvip_context_t *context = gckvip_get_context();

	PRINTK_I("poll hardware...\n");
	if (vip_true_e == context->vip_idle) {
		PRINTK_I("wait poll, hardware is in idle status\n");
		return VIP_SUCCESS;
	}

#if vpmdENABLE_WAIT_LINK_LOOP
	gckvip_read_register(0x00004, &idle_reg);
	while ((count > 0) && ((idle_reg & 0xFFFFE) != 0xFFFFE)) {
		gckvip_os_delay(POLL_SPACE);
		gckvip_read_register(0x00004, &idle_reg);
		count--;
	}

	if (count > 0) {
		vip_uint32_t address = 0;
		vip_uint32_t max_address = 0;
		count = (vip_int32_t)timeout / POLL_SPACE;
		gckvip_read_register(0x00664, &address);
		max_address = context->curr_command.cmd_physical + context->curr_command.cmd_size - WAIT_LINK_SIZE;
		while (count > 0) {
			/* check loop on command wait-link cmds */
			if ((address < max_address) && (address >= context->curr_command.cmd_physical)) {
				break;
			}
			gckvip_os_delay(POLL_SPACE);
			gckvip_read_register(0x00664, &address);
			count--;
		}

		if (count > 0) {
			status = VIP_SUCCESS;
		} else {
			PRINTK_E("poll hardware read idle status=0x%x, address=0x%08x, wait-link=0x%08x, size=0x%x\n",
					 idle_reg, address, context->waitlinkbuf_physical, context->waitlinkbuf_size);
			status = VIP_ERROR_TIMEOUT;
		}
	} else {
		PRINTK_E("poll hardware wait-link read idle status=0x%x\n", idle_reg);
		status = VIP_ERROR_TIMEOUT;
	}
#else
	gckvip_read_register(0x00004, &idle_reg);
	while ((count > 0) && ((idle_reg & 0xFFFFF) != 0xFFFFF)) {
		gckvip_os_delay(POLL_SPACE);
		gckvip_read_register(0x00004, &idle_reg);
		count--;
	}

	if (count > 0) {
		status = VIP_SUCCESS;
	} else {
		PRINTK_E("poll hardware read idle status=0x%x\n", idle_reg);
		status = VIP_ERROR_TIMEOUT;
	}
#endif

	return status;
}

/*
@brief waiting for hardware going to idle.
@param context, the contect of kernel space.
@param timeout the number of milliseconds this waiting.
*/
vip_status_e gckvip_hw_wait_idle(
	gckvip_context_t *context,
	vip_uint32_t timeout
)
{
#define POLL_SPACE   5  /* 5ms */
	vip_status_e status = VIP_SUCCESS;
	vip_int32_t count = (vip_int32_t)timeout / POLL_SPACE;
	vip_uint32_t idle_reg = 0;

#if vpmdENABLE_WAIT_LINK_LOOP
	/* wait function module idle */
	gckvip_read_register(0x00004, &idle_reg);
	while ((count > 0) && ((idle_reg & 0xFFFFE) != 0xFFFFE)) {
		gckvip_os_delay(POLL_SPACE);
		gckvip_read_register(0x00004, &idle_reg);
		count--;
	}

	if (count <= 0) {
		PRINTK_E("hw wait idle, function module not idle=0x%x\n", idle_reg);
	}

	if ((context->waitlink_pos != VIP_NULL) && (context->waitlinkbuf_logical != VIP_NULL)) {
		/* wait FE idle, modify WAIT cmd to END cmd for ending FE */
		if (context->waitlink_pos != context->waitlinkbuf_logical) {
			context->waitlink_pos[1] = 0;
			context->waitlinkbuf_logical[1] = 0;
			gckvip_os_memorybarrier();
			context->waitlink_pos[0] = (2 << 27);
			context->waitlinkbuf_logical[0] = (2 << 27);
		} else {
			context->waitlink_pos[1] = 0;
			gckvip_os_memorybarrier();
			context->waitlink_pos[0] = (2 << 27);
		}
	}

	gckvip_os_delay(1); /* waiting idle */
	gckvip_read_register(0x00004, &idle_reg);
#else
	gckvip_read_register(0x00004, &idle_reg);
	while ((count > 0) && ((idle_reg & 0xFFFFF) != 0xFFFFF)) {
		gckvip_os_delay(POLL_SPACE);
		gckvip_read_register(0x00004, &idle_reg);
		count--;
	}
#endif

	PRINTK_I("wait hw idle done, reg=0x%x\n", idle_reg);

	if ((idle_reg & 0x7FFFFFFF) != 0x7FFFFFFF) {
		const char *module_name[] = {
			"FE",        "NULL",      "NULL",      "SH",        "NULL",
			"NULL",      "NULL",      "NULL",      "NULL",      "NULL",
			"NULL",      "NULL",      "NULL",      "FE BLT",    "MC",
			"NULL",      "NULL",      "NULL",      "NN",        "TP",
			"Scaler"
		};
		vip_uint32_t n_modules = sizeof(module_name) / sizeof(const char *);
		vip_uint32_t i = 0;

		for (i = 0; i < n_modules; i++) {
			if ((idle_reg & 0x01) == 0) {
				if (14 == i) {
					if (context->chip_cid != 0xba) {
						PRINTK_E("wait hw idle, %s not idle.\n", module_name[i]);
					}
				} else {
					PRINTK_E("wait hw idle, %s not idle.\n", module_name[i]);
				}
			}
			idle_reg >>= 1;
		}
	}

	return status;
}
