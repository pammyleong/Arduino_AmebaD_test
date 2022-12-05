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

#include <gc_vip_kernel_pm.h>
#include <gc_vip_hardware.h>
#include <gc_vip_kernel.h>
#include <gc_vip_kernel_port.h>
#include <gc_vip_kernel_drv.h>
#include <gc_vip_kernel_allocator.h>
#include <gc_vip_video_memory.h>
#include <gc_vip_kernel_debug.h>

/* Kernel context object. */
gckvip_context_t kContext = {0};
#define GET_CONTEXTK() gckvip_context_t *context = &kContext

#if vpmdENABLE_MULTIPLE_TASK
#if defined(__linux__)
static DEFINE_MUTEX(kinit_mutex);
#endif
#endif

/************ INTERNAL APIs ***************/
static vip_status_e gckvip_do_wait(void *data);
static vip_status_e gckvip_do_submit(void *data);

/*
@brief Get kernel context object.
*/
gckvip_context_t *gckvip_get_context(void)
{
	GET_CONTEXTK();
	return context;
}

/*
@brief To run any initial commands once in the beginning.
*/
vip_status_e gckvip_init_commands(void)
{
	/* Currently initial commands include:
	1. Program USC cache to 100% usage (FULL).
	*/
	void *handle = VIP_NULL;
	vip_uint32_t physical = 0;
	vip_uint32_t *logical = VIP_NULL;
	vip_uint32_t size = sizeof(vip_uint32_t) * 4;
	vip_status_e status = VIP_SUCCESS;
	gckvip_submit_t submission;
	GET_CONTEXTK();

	gcOnError(gckvip_mem_allocate_videomemory(context, size + APPEND_COMMAND_SIZE,
			  &handle, (void **)&logical, &physical,
			  gcdVIP_MEMORY_ALIGN_SIZE,
			  GCVIP_VIDEO_MEM_ALLOC_FLAG_NONE_CACHE));
	gckvip_os_zero_memory(logical, size + APPEND_COMMAND_SIZE);

	/* Fill command to enable SH counter for clock detection. */
	logical[0] = ((1 << 27) | (1 << 16) | (0x0E12));
	logical[1] = SETBIT(0, 16, 1);
	logical[2] = 0x08010E21;
	logical[3] = 0x00020000;

	/* Submit commands. */
	submission.cmd_logical = (vip_uint8_t *)logical;
	submission.cmd_physical = physical;
	submission.cmd_handle = handle;
	submission.cmd_size = size;
	submission.last_cmd_logical = (vip_uint8_t *)logical;
	submission.last_cmd_physical = physical;
	submission.last_cmd_handle = handle;
	submission.last_cmd_size = size;

#if vpmdENABLE_SECURE
	submission.wait_event = GCKVIP_SUBMIT_NO_EVENT;
#else
	submission.wait_event = GCKVIP_SUBMIT_WITH_EVENT;
#endif

#if vpmdENABLE_MMU
	if (1 == context->flush_mmu) {
		gckvip_hw_flush_mmu(context, &submission);
	}
	gcOnError(gckvip_hw_submit(context, &submission));
#else
	gcOnError(gckvip_hw_submit(context, &submission));
#endif

	context->curr_command.cmd_logical = submission.cmd_logical;
	context->curr_command.cmd_physical = submission.cmd_physical;
	context->curr_command.cmd_size = size + APPEND_COMMAND_SIZE;

	/* Wait to be done. */
	{
		gckvip_wait_t wait_data;
		wait_data.mask = 0xFFFFFFFF;
		wait_data.time_out = 100;/* 100ms timeout for initialize states */
		gcOnError(gckvip_do_wait((void *)&wait_data));
	}

	PRINTK_D("initialize commands done...\n");

onError:
	/* Free initial command buffer. */
	gckvip_mem_free_videomemory(context, handle);

	return VIP_SUCCESS;
}

#if vpmdENABLE_MULTIPLE_TASK
vip_status_e gckvip_multi_thread_handle(
	vip_ptr param
)
{
	gckvip_queue_t *queue = (gckvip_queue_t *)param;
	gckvip_multi_thread_submit_t *submit = VIP_NULL;
	gckvip_queue_data_t *queue_data = VIP_NULL;
	vip_status_e status = VIP_SUCCESS;
	gckvip_wait_t wait_data;
	GET_CONTEXTK();
	context->mt_thread_running = vip_true_e;
	wait_data.mask = 0xFFFFFFFF;
	wait_data.time_out = vpmdHARDWARE_TIMEOUT;

	PRINTK_I("multi-thread process thread start\n");
	gckvip_os_set_signal(context->mt_thread_signal, vip_false_e);

	while (context->mt_thread_running) {
		if (gckvip_queue_read(queue, &queue_data)) {
			if (VIP_NULL == queue_data) {
				PRINTK_E("multi-process read queue data is NULL\n");
				continue;
			}

			submit = (gckvip_multi_thread_submit_t *)(gckvip_uintptr_t)(queue_data->v1);
			PRINTK_I("multi-task start submit command mem_handle=0x%" PRIx64"\n",
					 GCKVIPPTR_TO_UINT64(submit->submit_handle.cmd_handle));
			status = gckvip_do_submit(&submit->submit_handle);
			if (status != VIP_SUCCESS) {
				PRINTK_E("failed to submit command buffer\n");
			}

			status = gckvip_do_wait(&wait_data);
			if (status != VIP_SUCCESS) {
				PRINTK_E("failed to wait interrupt.. exit multi-thread process, status=%d\n",
						 status);
			}
			PRINTK_I("multi-task wait task done\n");

			submit->queue_data.v2 = (vip_status_e)status;
			gckvip_os_set_signal(submit->wait_signal, vip_true_e);
		}
	}

	/* wake up wait the thread exit task */
	gckvip_os_set_signal(context->mt_thread_signal, vip_true_e);

	PRINTK_I("multi-task thread exit\n");

	return status;
}
#endif

/*
@brief initialize hardware and all resource.
*/
static vip_status_e do_init(void *data)
{
	vip_status_e status = VIP_SUCCESS;

	gckvip_initialize_t *init_data = (gckvip_initialize_t *)data;
	GET_CONTEXTK();

#if vpmdENABLE_MULTIPLE_TASK
#if defined(__linux__)
	mutex_lock(&kinit_mutex);
#endif
	if (VIP_NULL == context->initialize_mutex) {
		PRINTK_I("start create initialize mutex ...\n");
		gckvip_os_zero_memory(context, sizeof(gckvip_context_t));
		status = gckvip_os_create_mutex(&context->initialize_mutex);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to create mutex for initialize\n");
			gcGoOnError(VIP_ERROR_IO);
		}
	}
	gckvip_os_lock_mutex(context->initialize_mutex);
#endif
#if (vpmdENABLE_MULTIPLE_TASK || vpmdENABLE_SECURE)
	if (context->initialize >= 1) {
		/* Mark initialized. */
		vip_uint32_t i = 0;
		for (i = 0; i < SUPPORT_MAX_TASK_NUM; i++) {
			if (0 == context->process_id[i]) {
				context->process_id[i] = gckvip_os_get_pid();
				break;
			}
		}
		if (SUPPORT_MAX_TASK_NUM == i) {
			PRINTK_E("failed to initialize, process id is full. support max thread number=%d\n", i);
			gcGoOnError(VIP_ERROR_IO);
		}
		context->initialize++;
		PRINTK_I("vipcore has been initialized, pid=%d\n", gckvip_os_get_pid());

#if (vpmdENABLE_DEBUG_LOG >= 4)
		PRINTK("pids: \n");
		for (i = 0; i < SUPPORT_MAX_TASK_NUM; i++) {
			if (0 != context->process_id[i]) {
				PRINTK("index=%d, pid=%d\n", i, context->process_id[i]);
			}
		}
#endif

#if vpmdENABLE_MULTIPLE_TASK
		gckvip_os_unlock_mutex(context->initialize_mutex);
#if defined(__linux__)
		mutex_unlock(&kinit_mutex);
#endif
#endif

		return VIP_SUCCESS;
	}
#endif

	/* Dump options value */
#if vpmdENABLE_DEBUG_LOG > 2
	gckvip_dump_options();
#endif

#if !vpmdENABLE_MULTIPLE_TASK
	gckvip_os_zero_memory(context, sizeof(gckvip_context_t));
#endif

	context->process_id[0] = gckvip_os_get_pid();

	context->vip_idle = vip_true_e;

#if vpmdENABLE_DEBUGFS
	status = gckvip_os_create_mutex(&context->memory_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create mutex for video memory\n");
		gcGoOnError(VIP_ERROR_IO);
	}
#endif

	/* 0. create resource for supporting multiple process */
#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_create_signal(&context->mt_thread_signal);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create a signal multiple thread\n");
		gcGoOnError(VIP_ERROR_IO);
	}
	status = gckvip_os_create_mutex(&context->mt_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create mutex for supporting multi-thread\n");
		gcGoOnError(VIP_ERROR_IO);
	}
	status = gckvip_os_create_mutex(&context->reg_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create mutex for register memory\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	status = gckvip_os_create_mutex(&context->flush_cache_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create mutex for flush cache mutex\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	status = gckvip_queue_initialize(&context->mt_input_queue);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create input queue for supporting multi-thread\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	status = gckvip_os_create_thread((void *)gckvip_multi_thread_handle,
									 (void *)&context->mt_input_queue,
									 &context->mt_thread_handle);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create a thread for supporting multi-thread\n");
		gcGoOnError(VIP_ERROR_IO);
	}
	{
		vip_uint32_t i = 0;
		for (i = 0; i < SUPPORT_MAX_TASK_NUM; i++) {
			gckvip_multi_thread_submit_t *submit = &context->mt_submit[i];
			status = gckvip_os_create_signal(&submit->wait_signal);
			if (status != VIP_SUCCESS) {
				PRINTK_E("failed to create a signal wait_signal\n");
				gcGoOnError(VIP_ERROR_IO);
			}
			gckvip_os_set_signal(submit->wait_signal, vip_false_e);
			submit->is_empty = vip_true_e;
		}
	}
	PRINTK_I("multi-task is enabled...\n");
#endif

	/* default full clock freq */
	context->core_fscale_percent = 100;

	/* 0.1 initialize video memory data base */
	status = gckvip_database_init(&context->videomem_database);
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to initialize video memory database\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	/* 1. Initialize OS layer and power on hardware. */
	status = gckvip_os_init(init_data->video_mem_size);
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to os initialize\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	/* 2. Initialize power managment */
//RTK removed
#if 1
	status = gckvip_pm_init(context);
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to os initialize power management\n");
		gcGoOnError(VIP_ERROR_IO);
	}
#endif

	/* 3.  Get interrupt, register base address, sram */
	status = gckvip_drv_get_reg_base(&context->reg_base);
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to get register base address\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	status = gckvip_drv_get_irq(&context->irq_queue, &context->irq_flag);
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to get irq\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	status = gckvip_drv_get_sram_info(&context->axi_sram_size,
									  &context->axi_sram_address,
									  &context->vip_sram_size,
									  &context->vip_sram_address);
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to get sram info\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	/* 4. Initialize video memory heap */
#if vpmdENABLE_VIDEO_MEMORY_HEAP
	status = gckvip_mem_heap_init(context);
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to initialize video memory heap\n");
		gcGoOnError(VIP_ERROR_IO);
	}
#endif

	/* 5. Read hardware information */
	gckvip_hw_read_info(context);

	/* 6. Reset hardware. */
	status = gckvip_hw_reset();
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to software reset hardware\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	/* 7. Init MMU page table */
#if vpmdENABLE_MMU
	status = gckvip_mem_mmu_init(context);
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to initialize MMU\n");
		gcGoOnError(VIP_ERROR_IO);
	}
#endif

	/* 8. Init hardware */
	status = gckvip_hw_init(context);
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to hardware initialize\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	/* 9. Start the "wait-link" loop for command queue. */
#if vpmdENABLE_WAIT_LINK_LOOP
	context->waitlinkbuf_size = WAIT_LINK_SIZE;
	status = gckvip_mem_allocate_videomemory(context, context->waitlinkbuf_size,
			 &context->waitlinkbuf_handle,
			 (void **)&context->waitlinkbuf_logical,
			 &context->waitlinkbuf_physical,
			 gcdVIP_MEMORY_ALIGN_SIZE,
			 (GCVIP_VIDEO_MEM_ALLOC_FLAG_CONTIGUOUS |
			  GCVIP_VIDEO_MEM_ALLOC_FLAG_NONE_CACHE));
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to allocate video memory for wait/link buffer\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	gckvip_hw_trigger(context);
	context->waitlink_pos = context->waitlinkbuf_logical;
	PRINTK_I("used wait-link trigger hardware...\n");
	gckvip_os_delay(1);
#endif

#if vpmdENABLE_DEBUG_LOG > 2
	/* 10. Report VIP clocks. just for debuging. */
	gckvip_report_clock();
#endif

	/* 11. Run any initial state commands. */
	status = gckvip_init_commands();
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to initialize states\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	PRINTK_I("do init done initialize num=%d...\n", context->initialize);

	context->recovery_times = 10;

#if vpmdENABLE_DEBUGFS
	{
		vip_uint64_t cur_os_time = gckvip_os_get_time();
		status = gckvip_drv_set_profile_data(cur_os_time, PROFILE_INIT);
		if (status != VIP_SUCCESS) {
			PRINTK_E("fail record cur init time\n");
		}
	}
#endif
	context->initialize = 1;

onError:
#if vpmdENABLE_MULTIPLE_TASK
	if (context->initialize_mutex != VIP_NULL) {
		gckvip_os_unlock_mutex(context->initialize_mutex);
	} else {
		PRINTK_E("error initialize mutex is NULL in do init\n");
	}
#if defined(__linux__)
	mutex_unlock(&kinit_mutex);
#endif
#endif

	return status;
}

/*
@brief destroy resource.
*/
static vip_status_e do_destroy(void)
{
	vip_status_e status = VIP_SUCCESS;
	GET_CONTEXTK();

#if vpmdENABLE_MULTIPLE_TASK
#if defined(__linux__)
	mutex_lock(&kinit_mutex);
#endif
	if (context->initialize_mutex != VIP_NULL) {
		gckvip_os_lock_mutex(context->initialize_mutex);
	} else {
		PRINTK_E("error initialize mutex is NULL in do destory\n");
	}
#endif

	/* Mark uninitialized. */
#if (vpmdENABLE_MULTIPLE_TASK || vpmdENABLE_SECURE)
	{
		vip_uint32_t i = 0;
		for (i = 0; i < SUPPORT_MAX_TASK_NUM; i++) {
			if (gckvip_os_get_pid() == context->process_id[i]) {
				context->process_id[i] = 0;
				break;
			}
		}
	}
	context->initialize--;
	if (context->initialize <= 0) {
#else
	if (context->initialize > 0) {
		context->initialize = 0;
		context->process_id[0] = 0;
#endif

		PRINTK_I("start to destroy vip..\n");
#if vpmdENABLE_MULTIPLE_TASK
		context->mt_thread_running = vip_false_e;
		context->mt_input_queue.queue_stop = vip_true_e;
		/* exit multi-thread process */
		gckvip_os_set_signal(context->mt_input_queue.read_signal, vip_true_e);

		gckvip_os_wait_signal(context->mt_thread_signal, WAIT_SIGNAL_TIMEOUT);
#endif

		/* wait hardware idle, default wait hw idle 128ms */
		if (GCKVIP_POWER_OFF != context->power_status) {
			status = gckvip_hw_wait_idle(context, 128);
			if (status != VIP_SUCCESS) {
				PRINTK_E("error, VIP not going to idle...\n");
			}
		}

#if vpmdENABLE_WAIT_LINK_LOOP
		gckvip_mem_free_videomemory(context, context->waitlinkbuf_handle);
#endif

#if vpmdENABLE_MMU
		status = gckvip_mem_mmu_uninit(context);
		if (status != VIP_SUCCESS) {
			PRINTK_E("fail to uninit mmu\n");
		}
#endif

		status = gckvip_hw_destroy(context);
		if (status != VIP_SUCCESS) {
			PRINTK_E("fail to destroy hardware\n");
		}

#if vpmdENABLE_VIDEO_MEMORY_HEAP
		status = gckvip_mem_heap_destroy(context);
		if (status != VIP_SUCCESS) {
			PRINTK_E("fail to destroy video memory heap\n");
		}
#endif

		status = gckvip_os_close();
		if (status != VIP_SUCCESS) {
			PRINTK_E("fail to destroy os\n");
		}

#if vpmdENABLE_DEBUGFS
		if (context->memory_mutex != VIP_NULL) {
			gckvip_os_destroy_mutex(context->memory_mutex);
		}
#endif
#if vpmdENABLE_MULTIPLE_TASK
		if (context->mt_thread_handle != VIP_NULL) {
			gckvip_os_destroy_thread(context->mt_thread_handle);
		}
		gckvip_queue_destroy(&context->mt_input_queue);
		if (context->mt_mutex != VIP_NULL) {
			gckvip_os_destroy_mutex(context->mt_mutex);
		}
		if (context->reg_mutex != VIP_NULL) {
			gckvip_os_destroy_mutex(context->reg_mutex);
		}
		if (context->flush_cache_mutex != VIP_NULL) {
			gckvip_os_destroy_mutex(context->flush_cache_mutex);
		}
		if (context->mt_thread_signal != VIP_NULL) {
			gckvip_os_destroy_signal(context->mt_thread_signal);
		}
		{
			vip_uint32_t i = 0;
			for (i = 0; i < SUPPORT_MAX_TASK_NUM; i++) {
				gckvip_multi_thread_submit_t *submit = &context->mt_submit[i];
				gckvip_os_destroy_signal(submit->wait_signal);
				submit->is_empty = vip_true_e;
			}
		}
#endif

//RTK removed
#if 0
		/* uninitialize power management*/
		gckvip_pm_uninit(context);
#endif

		gckvip_database_uninit(&context->videomem_database);

#if vpmdENABLE_MULTIPLE_TASK
		/* unlock and destroy initialize mutex last */
		if (context->initialize_mutex != VIP_NULL) {
			gckvip_os_unlock_mutex(context->initialize_mutex);
			PRINTK_I("destroy initialize mutex\n");
			gckvip_os_destroy_mutex(context->initialize_mutex);
			context->initialize_mutex = VIP_NULL;
		}
#endif
		gckvip_os_zero_memory(context, sizeof(gckvip_context_t));
		PRINTK_I("end to destroy vip..\n");
	}
#if vpmdENABLE_MULTIPLE_TASK
	else {
		if (context->initialize_mutex != VIP_NULL) {
			gckvip_os_unlock_mutex(context->initialize_mutex);
		} else {
			PRINTK_E("error initialize mutex is NULL in do destory end\n");
		}
	}
#if defined(__linux__)
	mutex_unlock(&kinit_mutex);
#endif
#endif

	return status;
}

/*
@brief Read a register.
*/
static vip_status_e do_read_register(void *data)
{
	gckvip_reg_t *reg_data = (gckvip_reg_t *)data;
	vip_status_e status = VIP_SUCCESS;
	if (VIP_NULL == data) {
		PRINTK_E("failed to read register, parameter is NULL\n");
		return VIP_ERROR_FAILURE;
	}

	status = gckvip_read_register(reg_data->reg, &reg_data->data);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to read hardware register status=%d\n", status);
	}

	return status;
}

/*
@brief Write a register.
*/
static vip_status_e do_write_register(void *data)
{
	gckvip_reg_t *reg_data = (gckvip_reg_t *)data;
	vip_status_e status = VIP_SUCCESS;
	if (VIP_NULL == data) {
		PRINTK_E("failed to write register, parameter is NULL\n");
		return VIP_ERROR_FAILURE;
	}

	status = gckvip_write_register(reg_data->reg, reg_data->data);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to write hardware register\n");
	}

	return status;
}

/*
@brief free video memory
when MMU disable, allocate video memory from heap. And return physcical address.
when MM enable, allocate video memory from heap and system. return VIP's virtual address.
*/
static vip_status_e do_allocation_videomem(void *data)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_video_memory_t memory;
	gckvip_allocation_t *allocation = (gckvip_allocation_t *)data;
	void *logical = VIP_NULL;
	vip_uint32_t handle_id = 0;
	vip_uint32_t alloc_flag = allocation->alloc_flag;
	GET_CONTEXTK();

#if vpmdENABLE_DEBUGFS
	status = gckvip_os_lock_mutex(context->memory_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock video memory mutex\n");
		return VIP_ERROR_FAILURE;
	}
#endif

	if (allocation->size >= gcdMMU_PAGE_1M_SIZE) {
		alloc_flag |= GCVIP_VIDEO_MEM_ALLOC_FLAG_1M_CONTIGUOUS;
	}

	PRINTK_D("allocate video memory size=0x%x, align=0x%x, type=0x%x\n",
			 allocation->size, allocation->align, allocation->alloc_flag);

	status = gckvip_mem_allocate_videomemory(context, allocation->size, &memory.handle,
			 &memory.logical, &memory.physical,
			 allocation->align, alloc_flag);
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to allocate video memory in allocation videomem, size=0x%x, status=%d\n",
				 allocation->size, status);
		gcGoOnError(status);
	}

	status |= gckvip_mem_get_userlogical(context, memory.handle, memory.physical, &logical);
	status |= gckvip_database_get_id(&context->videomem_database, memory.handle,
									 gckvip_os_get_pid(), &handle_id);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to get handle id for allocate video memory, size=%d\n", allocation->size);
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	allocation->logical = GCKVIPPTR_TO_UINT64(logical);
	allocation->handle = handle_id;
	allocation->physical = memory.physical;

#if vpmdENABLE_DEBUGFS
	status = gckvip_os_unlock_mutex(context->memory_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock video memory mutex\n");
	}
#endif

	return status;

onError:
#if vpmdENABLE_DEBUGFS
	gckvip_os_unlock_mutex(context->memory_mutex);
#endif
	if (memory.handle != VIP_NULL) {
		gckvip_mem_free_videomemory(context, memory.handle);
	}
	allocation->logical = 0;
	allocation->physical = 0;
	allocation->handle = 0;

	return status;
}

/*
@brief free video memory
*/
static vip_status_e do_free_videomem(void *data)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_deallocation_t *allocation = (gckvip_deallocation_t *)data;
	void *handle = VIP_NULL;
	GET_CONTEXTK();

#if vpmdENABLE_DEBUGFS
	status = gckvip_os_lock_mutex(context->memory_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock video memory mutex\n");
		return VIP_ERROR_FAILURE;
	}
#endif

	gcOnError(gckvip_database_get_handle(&context->videomem_database, allocation->handle, &handle));

	gcOnError(gckvip_mem_free_videomemory(context, handle));

	gcOnError(gckvip_database_put_id(&context->videomem_database, allocation->handle));

onError:
#if vpmdENABLE_DEBUGFS
	gckvip_os_unlock_mutex(context->memory_mutex);
#endif
	return status;
}

/*
@brief software rest hardware.
*/
static vip_status_e do_reset_vip(void)
{
	vip_status_e status = VIP_SUCCESS;

	status = gckvip_hw_reset();
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to reset vip\n");
		return VIP_ERROR_NOT_SUPPORTED;
	}

	return status;
}

/*
@brief wait hardware interrupt return.
*/
static vip_status_e gckvip_do_wait(void *data)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_wait_t *info = (gckvip_wait_t *)data;
	vip_uint32_t timeout = info->time_out;
	GET_CONTEXTK();

#if !vpmdENABLE_USE_AGENT_TRIGGER
	if (vip_false_e == context->vip_idle)
#endif
	{
#if vpmdENABLE_SECURE
		/* poll hardware idle */
		status = gckvip_hw_wait_poll(timeout);
#else
		/* wait interrupt */
		if ((VIP_NULL == context->irq_queue) || (VIP_NULL == context->irq_flag)) {
			PRINTK_E("fail to wait interrupt. int queue or int falg is NULL\n");
			return VIP_ERROR_OUT_OF_MEMORY;
		}
		status = gckvip_os_wait_interrupt(context->irq_queue, context->irq_flag, timeout, info->mask);
#endif

		if (status == VIP_ERROR_TIMEOUT) {
#if vpmdENABLE_HANG_DUMP
			if (context->dump_finish == vip_false_e) {
				gckvip_dump_states(context);
				gckvip_dump_command(&context->curr_command);
#if vpmdENABLE_WAIT_LINK_LOOP
				gckvip_dump_waitlink(context->waitlinkbuf_logical, context->waitlinkbuf_physical);
#endif
#if vpmdENABLE_MMU
				gckvip_dump_flush_MMUCmds(context->ptr_MMU_flush);
#endif

#if vpmdENABLE_HANG_DUMP > 1
				gckvip_dump_AHB_register();
#endif
				context->dump_finish = vip_true_e;
			}
#endif

#if vpmdENABLE_RECOVERY
			PRINTK_I("error: wait interrupt timeout, time=%dms\n", timeout);

			if (context->recovery_times < 0) {
				PRINTK_E("fail to recovery.....\n");
				gcGoOnError(VIP_ERROR_TIMEOUT);
			}
			context->recovery_times--;

			/* 1. init hardware */
			gckvip_hw_reset();
			gckvip_hw_init(context);

#if vpmdENABLE_WAIT_LINK_LOOP
			/* 2. set trigger*/
			gckvip_hw_trigger(context);
			context->waitlink_pos = context->waitlinkbuf_logical;
			gckvip_os_delay(1);
#endif

			/* 3. Run any initial state commands. */
			status = gckvip_init_commands();
			if (status == VIP_SUCCESS) {
				PRINTK_E("hardware recovery done.....\n");
				gckvip_hw_idle(context);
				gcOnError(status);
			}

#if vpmdENABLE_HANG_DUMP
			context->dump_finish = vip_false_e;
#endif

#else

			PRINTK_I("error: hardware hang .......timeout=%d..\n", info->time_out);
#if 0
			while (status == VIP_ERROR_TIMEOUT) {
				/* vip hang in here */
				status = gckvip_os_wait_interrupt(context->irq_queue, context->irq_flag, timeout, mask);
			}
#else
			gcGoOnError(VIP_ERROR_FAILURE);
#endif
#endif
		}

		/* Then link back to the WL commands for letting vip going to idle. */
		gcOnError(gckvip_hw_idle(context));

		PRINTK_I("wait task done...\n");

#if vpmdENABLE_USER_CONTROL_POWER
		if (GCKVIP_USER_PM_OFF_WAIT_HW == context->user_pm_status) {
			/* hardware is idle status, power off hardware immediately */
			gckvip_hw_wait_idle(context, 128); /* waiting hw 128ms */
			status = gckvip_drv_set_power_clk(GCKVIP_POWER_OFF);
			if (status != VIP_SUCCESS) {
				PRINTK_E("vipcore, failed to power off hardware\n");
				gcGoOnError(VIP_ERROR_FAILURE);
			} else {
				context->power_status = GCKVIP_POWER_OFF;
				context->user_pm_switch = 1;
			}

			gckvip_os_lock_mutex(context->user_pm_mutex);
			context->user_pm_status = GCKVIP_USER_PM_OFF;
			gckvip_os_unlock_mutex(context->user_pm_mutex);

#if vpmdENABLE_MULTIPLE_TASK
			/* flush command buffer queue */
			status = gckvip_queue_clean(&context->mt_input_queue);
			if (status != VIP_SUCCESS) {
				PRINTK_E("failed to clean up command buffer queue\n");
			}
#endif
			PRINTK_D("wait for hardware idle, power off done\n");
		}
#endif
	}

	return status;

onError:
	PRINTK_E("failed to wait command complete status=%d\n", status);
	return status;
}

static vip_status_e do_wait(void *data)
{
	vip_status_e status = VIP_SUCCESS;

#if vpmdENABLE_MULTIPLE_TASK
	gckvip_wait_t *info = (gckvip_wait_t *)data;
	gckvip_multi_thread_submit_t *submit = VIP_NULL;
	vip_uint32_t handle_id = info->handle;
	vip_uint32_t i = 0;
	vip_bool_e valid_wait = vip_false_e;
	void *mem_handle = VIP_NULL;
	GET_CONTEXTK();

	PRINTK_I("user start do wait...\n");
	gcOnError(gckvip_database_get_handle(&context->videomem_database, handle_id, &mem_handle));

	gckvip_os_lock_mutex(context->mt_mutex);
	for (i = 0; i < SUPPORT_MAX_TASK_NUM; i++) {
		submit = &context->mt_submit[i];
		if ((submit->is_empty != vip_true_e) && (submit->submit_handle.cmd_handle == mem_handle)) {
			valid_wait = vip_true_e;
			break;
		}
	}
	gckvip_os_unlock_mutex(context->mt_mutex);

	if ((vip_true_e == context->mt_thread_running) && valid_wait) {
		vip_uint32_t count = (vpmdHARDWARE_TIMEOUT + (WAIT_SIGNAL_TIMEOUT - 1)) / WAIT_SIGNAL_TIMEOUT;
		if (0 == count) {
			count = 1;
		}
		for (i = 0; i < count; i++) {
			status = gckvip_os_wait_signal(submit->wait_signal, WAIT_SIGNAL_TIMEOUT);
			if (VIP_SUCCESS == status) {
				break;
			} else {
				PRINTK_I("wait task timeout loop index=%d\n", i);
			}
		}
		gckvip_os_set_signal(submit->wait_signal, vip_false_e);
		if ((status != VIP_SUCCESS) && (count == i)) {
#if (vpmdENABLE_DEBUG_LOG >= 4)
			gckvip_os_lock_mutex(context->mt_mutex);
			PRINTK("dump taskS in submit_mt:\n");
			for (i = 0; i < SUPPORT_MAX_TASK_NUM; i++) {
				submit = &context->mt_submit[i];
				if (submit->is_empty != vip_true_e) {
					PRINTK("wait signal=0x%" PRIx64", mem_handle=0x%" PRIx64"\n",
						   GCKVIPPTR_TO_UINT64(submit->wait_signal),
						   GCKVIPPTR_TO_UINT64(submit->submit_handle.cmd_handle));
				}
			}
			gckvip_os_unlock_mutex(context->mt_mutex);
#endif
			PRINTK_E("do wait signal mem_id=0x%x, mem_handle=0x%" PRIx64", status=%d\n",
					 handle_id, GCKVIPPTR_TO_UINT64(mem_handle), status);
			gcGoOnError(status);
		}

		status = (vip_status_e)submit->queue_data.v2;
		if (status != VIP_SUCCESS) {
			PRINTK_E("do wait mt thread fail=%d, mem_id=0x%x, mem_handle=0x%" PRIx64", status=%d\n",
					 status, handle_id, GCKVIPPTR_TO_UINT64(mem_handle), status);
			gcGoOnError(status);
		}
		submit->is_empty = vip_true_e;
	} else {
		PRINTK_D("not wait irq mt_thread=%d valid_wait=%d, vip_idle=%s, mem_handle=0x%" PRIx64"\n",
				 context->mt_thread_running, valid_wait, context->vip_idle ? "true" : "false",
				 GCKVIPPTR_TO_UINT64(mem_handle));
	}
#else
	gcOnError(gckvip_do_wait(data));
#endif
	PRINTK_I("user end do wait...\n");

#if vpmdENABLE_DEBUGFS
	{
		vip_uint64_t cur_os_time = gckvip_os_get_time();
		status = gckvip_drv_set_profile_data(cur_os_time, PROFILE_WAIT);
		if (status != VIP_SUCCESS) {
			PRINTK_E("fail record cur init time\n");
		}
	}
#endif

onError:
	return status;
}

/*
@brief commit commands to hardware.
*/
static vip_status_e gckvip_do_submit(void *data)
{
	vip_status_e status = VIP_SUCCESS;

	gckvip_submit_t *submit = VIP_NULL;
	GET_CONTEXTK();

	/* defined(__linux__) is just for viplite run on Linux.
	   user space logical need to be switched kernel space logical address
	*/
#if defined(__linux__)
	gckvip_submit_t submitTmp;
	gckvip_submit_t *tmp = (gckvip_submit_t *)data;
	gckvip_mem_get_kernellogical(context, tmp->cmd_handle, tmp->cmd_physical,
								 (void **)&submitTmp.cmd_logical);
	submitTmp.cmd_physical = tmp->cmd_physical;
	submitTmp.cmd_handle = tmp->cmd_handle;
	submitTmp.cmd_size = tmp->cmd_size;
	gckvip_mem_get_kernellogical(context, tmp->last_cmd_handle,
								 tmp->last_cmd_physical,
								 (void **)&submitTmp.last_cmd_logical);
	submitTmp.last_cmd_physical = tmp->last_cmd_physical;
	submitTmp.last_cmd_handle = tmp->last_cmd_handle;
	submitTmp.last_cmd_size = tmp->last_cmd_size;
	submitTmp.wait_event = tmp->wait_event;
	submit = &submitTmp;
#else
	submit = (gckvip_submit_t *)data;
#endif

#if vpmdENABLE_SUSPEND_RESUME
	if (GCKVIP_POWER_SUSPEND_OFF == context->power_status) {
		vip_uint32_t count = 0;
		/* waiting for resume */
		/* system suspended, should waiting for resume signal,
		   then a task can be submited to hardware
		*/
		context->wait_resume_signal = vip_true_e;
		gckvip_os_set_signal(context->resume_signal, vip_false_e);
		while (1) {
			PRINTK_I("waiting for system resume, wait count=%d...\n", count);
			if (VIP_SUCCESS == gckvip_os_wait_signal(context->resume_signal, WAIT_SIGNAL_TIMEOUT)) {
				break;
			}
			count++;
		}
		gckvip_os_set_signal(context->resume_signal, vip_false_e);
	}
#endif

	/* power management */
#if vpmdPOWER_OFF_TIMEOUT
	gckvip_os_lock_mutex(context->power_mutex);
	if (context->power_status == GCKVIP_POWER_OFF) {
		gckvip_os_unlock_mutex(context->power_mutex);

//RTK removed
#if 0
		status = gckvip_pm_resume();  /*initialize and resume hardware */
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to init hardware for power management ON\n");
			gcGoOnError(VIP_ERROR_FAILURE);
		}
#endif

		gckvip_os_lock_mutex(context->power_mutex);
		context->power_status = GCKVIP_POWER_ON;

#if vpmdENABLE_MULTIPLE_TASK
		/* re-set timer for multi-task */
		gckvip_os_stop_timer(context->power_timer);
#endif
	}
	gckvip_os_unlock_mutex(context->power_mutex);
#endif

	PRINTK_D("submit command to hardware, command size=0x%x, physical=0x%08x\n",
			 submit->cmd_size, submit->cmd_physical);

#if vpmdENABLE_SECURE
	if ((vip_true_e == context->work_mode_change) &&
		(context->work_mode_last_submit != context->work_mode)) {
		/* re-loading page table */
		PRINTK_I("start switch mmu page table, work mode from %s to %s.\n",
				 (context->work_mode_last_submit == GCKVIP_WORK_MODE_NORMAL) ? "Normal" : "Secure",
				 (context->work_mode == GCKVIP_WORK_MODE_NORMAL) ? "Normal" : "Secure");

		status = gckvip_mem_mmu_switch(context);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to switch mmu\n");
			gcGoOnError(VIP_ERROR_FAILURE);
		}

		context->work_mode_change = vip_false_e;
		context->work_mode_last_submit = context->work_mode;
	}
#endif

#if vpmdENABLE_BW_PROFILING
	gckvip_write_register(0x00438, 0);
	gckvip_write_register(0x00078, 0);
	gckvip_write_register(0x0007C, 0);
	gckvip_write_register(0x00040, 0);
	gckvip_write_register(0x00044, 0);
	gckvip_write_register(0x005C0, 0);
	gckvip_write_register(0x005D0, 0);
	gckvip_write_register(0x0003C, 1);
	gckvip_write_register(0x0003C, 0);
#endif

#if vpmdENABLE_MMU
#if vpmdENABLE_MULTIPLE_TASK
	gckvip_os_lock_mutex(context->mmu_mutex);
#endif
	if (1 == context->flush_mmu) {
		gckvip_hw_flush_mmu(context, submit);
	}

	gcOnError(gckvip_hw_submit(context, submit));
#if vpmdENABLE_MULTIPLE_TASK
	gckvip_os_unlock_mutex(context->mmu_mutex);
#endif
#else
	gcOnError(gckvip_hw_submit(context, submit));
#endif

	context->curr_command.cmd_logical = submit->cmd_logical;
	context->curr_command.cmd_physical = submit->cmd_physical;
	context->curr_command.cmd_size = submit->cmd_size + APPEND_COMMAND_SIZE;
#if vpmdENABLE_HANG_DUMP
	context->execute_count++;
#endif

#if vpmdENABLE_DEBUGFS
	{
		vip_uint64_t cur_os_time = gckvip_os_get_time();
		status = gckvip_drv_set_profile_data(cur_os_time, PROFILE_SUBMIT);
		if (status != VIP_SUCCESS) {
			PRINTK_E("fail record cur init time\n");
		}
	}
#endif

onError:
	return status;
}

static vip_status_e do_submit(void *data)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_commit_t *commit = (gckvip_commit_t *)data;
	GET_CONTEXTK();

	if (context->initialize <= 0) {
		PRINTK_E("driver not initialize, please initialize first\n");
		return VIP_ERROR_FAILURE;
	}

#if vpmdENABLE_SECURE
	PRINTK_I("start do submit, cmd size=0x%x, mode=%s\n", commit->cmd_size,
			 (GCKVIP_WORK_MODE_NORMAL == context->work_mode) ? "Normal" : "Secure");
	{
		vip_uint32_t data = 0;
		gckvip_os_read_reg(context->reg_base, 0x00010, &data);
		PRINTK_I("submit command read irq value=0x%x\n", data);
	}
#else
#if (vpmdENABLE_DEBUG_LOG >= 4)
	{
		void *cmd_handle = VIP_NULL;
		gckvip_database_get_handle(&context->videomem_database,
								   commit->cmd_handle,
								   &cmd_handle);
		PRINTK_I("start do submit, cmd size=0x%x, id=0x%x, handle=0x%" PRIx64"\n",
				 commit->cmd_size, commit->cmd_handle, GCKVIPUINT64_TO_PTR(cmd_handle));
	}
#endif
#endif

#if vpmdENABLE_USER_CONTROL_POWER
	gckvip_os_lock_mutex(context->user_pm_mutex);
	if ((GCKVIP_USER_PM_OFF_WAIT_HW == context->user_pm_status) ||
		(GCKVIP_USER_PM_OFF == context->user_pm_status) ||
		(GCKVIP_USER_PM_STOP == context->user_pm_status)) {
		PRINTK_E("hardware has been stopped or off by user application\n");
		gckvip_os_unlock_mutex(context->user_pm_mutex);
		return VIP_ERROR_FAILURE;
	}
	gckvip_os_unlock_mutex(context->user_pm_mutex);
#endif

#if vpmdENABLE_MULTIPLE_TASK
	if (vip_true_e == context->mt_thread_running) {
		vip_bool_e ret = vip_true_e;
		vip_uint32_t i = 0;
		gckvip_multi_thread_submit_t *submit = VIP_NULL;

		/* delivery the command buffer to multi thread processing */
		status = gckvip_os_lock_mutex(context->mt_mutex);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to lock multiple thread mutex\n");
			gcGoOnError(VIP_ERROR_FAILURE);
		}

		/* get a empty multi thread object */
		for (i = 0; i < SUPPORT_MAX_TASK_NUM; i++) {
			submit = &context->mt_submit[i];
			if (vip_true_e == submit->is_empty) {
				break;
			}
		}

		if (SUPPORT_MAX_TASK_NUM == i) {
			PRINTK_E("multi thread is full, not support so many threads, max_task=%d\n",
					 SUPPORT_MAX_TASK_NUM);
			gckvip_os_unlock_mutex(context->mt_mutex);
			gcGoOnError(VIP_ERROR_FAILURE);
		}
		submit->is_empty = vip_false_e;

		status = gckvip_database_get_handle(&context->videomem_database,
											commit->cmd_handle,
											&submit->submit_handle.cmd_handle);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to convert command buffer video memory id, handle=0x%lx\n",
					 commit->cmd_handle);
			gckvip_os_unlock_mutex(context->mt_mutex);
			gcGoOnError(VIP_ERROR_FAILURE);
		}
		submit->submit_handle.cmd_logical = GCKVIPUINT64_TO_PTR(commit->cmd_logical);
		submit->submit_handle.cmd_physical = commit->cmd_physical;
		submit->submit_handle.cmd_size = commit->cmd_size;

		status = gckvip_database_get_handle(&context->videomem_database,
											commit->last_cmd_handle,
											&submit->submit_handle.last_cmd_handle);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to convert command buffer video memory id, handle=0x%lx\n",
					 commit->last_cmd_handle);
			gckvip_os_unlock_mutex(context->mt_mutex);
			gcGoOnError(VIP_ERROR_FAILURE);
		}
		submit->submit_handle.last_cmd_logical = GCKVIPUINT64_TO_PTR(commit->last_cmd_logical);
		submit->submit_handle.last_cmd_physical = commit->last_cmd_physical;
		submit->submit_handle.last_cmd_size = commit->last_cmd_size;

		submit->submit_handle.wait_event = commit->wait_event;
		submit->queue_data.v1 = GCKVIPPTR_TO_UINT64(submit);

		status = gckvip_os_unlock_mutex(context->mt_mutex);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to unlock multiple thread mutex\n");
			gcGoOnError(VIP_ERROR_FAILURE);
		}

		ret = gckvip_queue_write(&context->mt_input_queue, &submit->queue_data);
		if (!ret) {
			PRINTK_E("failed to write task into queue\n");
			submit->is_empty = vip_true_e;
			gcGoOnError(VIP_ERROR_FAILURE);
		}
	} else {
		PRINTK_E("mutli task thread is not running\n");
		gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
	}
#else
	{
		gckvip_submit_t submit;
		gcOnError(gckvip_database_get_handle(&context->videomem_database,
											 commit->cmd_handle,
											 &submit.cmd_handle));
		submit.cmd_logical = GCKVIPUINT64_TO_PTR(commit->cmd_logical);
		submit.cmd_physical = commit->cmd_physical;
		submit.cmd_size = commit->cmd_size;

		gcOnError(gckvip_database_get_handle(&context->videomem_database,
											 commit->last_cmd_handle,
											 &submit.last_cmd_handle));
		submit.last_cmd_logical = GCKVIPUINT64_TO_PTR(commit->last_cmd_logical);
		submit.last_cmd_physical = commit->last_cmd_physical;
		submit.last_cmd_size = commit->last_cmd_size;

		submit.wait_event = commit->wait_event;

		gcOnError(gckvip_do_submit(&submit));
	}
#endif
	PRINTK_I("end do submit..\n");

onError:
	return status;
}

/*
@brief query wait-link address info for agent driver used.
*/
#if vpmdENABLE_USE_AGENT_TRIGGER
static vip_status_e do_query_address_info(
	void *data
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_query_address_info_t *info = (gckvip_query_address_info_t *)data;

#if vpmdENABLE_WAIT_LINK_LOOP
	void *logical = VIP_NULL;
	GET_CONTEXTK();

	/* get user space logical address of wait/link buffer */
	gckvip_mem_get_userlogical(context, context->waitlinkbuf_handle,
							   context->waitlinkbuf_physical, (void **)&logical);
	info->waitlink_logical = GCKVIPPTR_TO_UINT64(logical);
	info->waitlink_physical = context->waitlinkbuf_physical;
	info->waitlink_size = WAIT_LINK_SIZE;

	PRINTK_D("wait link buffer physical=0x%08X,  user space logical=0x%" PRIx64"\n",
			 info->waitlink_physical, info->waitlink_logical);
#else
	info->waitlink_logical = 0;
	info->waitlink_size = 0;
	info->waitlink_physical = 0;
#endif

	return status;
}
#endif

/*
@brief query hardware database
*/
static vip_status_e do_query_database(
	void *data
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_query_database_t *database = (gckvip_query_database_t *)data;
	GET_CONTEXTK();

#if vpmdENABLE_MULTIPLE_TASK
	if (context->initialize_mutex != VIP_NULL) {
		gckvip_os_lock_mutex(context->initialize_mutex);
	}
#endif

	if (context->initialize > 0) {
		database->axi_sram_base = context->axi_sram_address;
		database->axi_sram_size = context->axi_sram_size;
		database->vip_sram_base = context->vip_sram_address;
		database->vip_sram_size = context->vip_sram_size;
#if vpmdENABLE_VIDEO_MEMORY_HEAP
#if vpmdENABLE_MMU
		database->video_heap_base = context->vip_virtual_base;
#else
		database->video_heap_base = context->physical_base;
#endif
#endif
		database->hw_cid = context->chip_cid;
	} else {
		PRINTK_E("failed to query databse, please call do_init first\n");
		status = VIP_ERROR_IO;
	}

#if vpmdENABLE_MULTIPLE_TASK
	if (context->initialize_mutex != VIP_NULL) {
		gckvip_os_unlock_mutex(context->initialize_mutex);
	}
#endif

	return status;
}

/*
@brief flush CPU cache for video memory heap.
*/
#if vpmdENABLE_FLUSH_CPU_CACHE
static vip_status_e do_flush_cache(
	void *data
)
{
	vip_status_e status = VIP_SUCCESS;
	void *handle = VIP_NULL;
	gckvip_operate_cache_t *operate = (gckvip_operate_cache_t *)data;

	GET_CONTEXTK();

	if (VIP_NULL == operate) {
		PRINTK_E("failed to flush cache, parameter is NULL\n");
		return VIP_ERROR_FAILURE;
	}

	gcOnError(gckvip_database_get_handle(&context->videomem_database, operate->handle, &handle));

	gcOnError(gckvip_flush_cache(handle, operate->physical, GCKVIPUINT64_TO_PTR(operate->logical),
								 operate->size, operate->type));

	return status;

onError:
	PRINTK_E("failed to do flush cache. handle=0x%x physical=0x%x, size=0x%x, type=%d\n",
			 operate->handle, operate->physical, operate->size, operate->type);
	return status;
}
#endif

static vip_status_e do_wrap_user_physical(
	void *data
)
{
	vip_status_e status = VIP_SUCCESS;

#if vpmdENABLE_MMU
	gckvip_wrap_user_physical_t *memory = (gckvip_wrap_user_physical_t *)data;
	void *handle = VIP_NULL;
	vip_uint32_t handle_id = 0;
	GET_CONTEXTK();

	memory->handle = 0;
	status = gckvip_mem_wrap_userphysical(context, memory->physical_table,
										  memory->size_table, memory->physical_num,
										  memory->memory_type, &memory->virtual,
										  &handle);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to wrap user physical, status=%d\n", status);
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	gcOnError(gckvip_database_get_id(&context->videomem_database, handle, gckvip_os_get_pid(), &handle_id));

	PRINTK_I("wrap user physical, physical[0]=0x%lx, physical number=%d, virtual=0x%08x, handle=0x%x\n",
			 memory->physical_table[0], memory->physical_num,  memory->virtual, handle_id);

	memory->handle = handle_id;

onError:
#endif
	return status;
}

/*
@brief  un-wrap user memory
*/
static vip_status_e do_unwrap_user_physical(
	void *data
)
{
	vip_status_e status = VIP_SUCCESS;

#if vpmdENABLE_MMU
	gckvip_unwrap_user_memory_t *memory = (gckvip_unwrap_user_memory_t *)data;
	vip_uint32_t handle_id = memory->handle;
	void *handle = 0;
	GET_CONTEXTK();

	gcOnError(gckvip_database_get_handle(&context->videomem_database, handle_id, &handle));

	status = gckvip_mem_unwrap_userphysical(context, handle, memory->virtual);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unwrap user memory, status=%d\n", status);
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	gcOnError(gckvip_database_put_id(&context->videomem_database, handle_id));

onError:
#endif
	return status;
}

/*
@brief, wrap user memory to VIP. return VIP's virtual address and video memory handle to use space.
*/
static vip_status_e do_wrap_user_memory(
	void *data
)
{
	vip_status_e status = VIP_SUCCESS;

#if vpmdENABLE_MMU
	gckvip_wrap_user_memory_t *memory = (gckvip_wrap_user_memory_t *)data;
	void *handle = VIP_NULL;
	vip_uint32_t handle_id = 0;
	GET_CONTEXTK();

	memory->handle = 0;
	status = gckvip_mem_wrap_usermemory(context, GCKVIPUINT64_TO_PTR(memory->logical), memory->size,
										memory->memory_type, &memory->virtual, &handle);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to wrap user memory, status=%d\n", status);
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	gcOnError(gckvip_database_get_id(&context->videomem_database, handle, gckvip_os_get_pid(), &handle_id));

	PRINTK_I("wrap user memory, logical=0x%" PRIx64", size=0x%08x, virtual=0x%08x, handle=0x%x\n",
			 memory->logical, memory->size, memory->virtual, handle_id);

	memory->handle = handle_id;

onError:
#endif
	return status;
}

/*
@brief  un-wrap user memory
*/
static vip_status_e do_unwrap_user_memory(
	void *data
)
{
	vip_status_e status = VIP_SUCCESS;

#if vpmdENABLE_MMU
	gckvip_unwrap_user_memory_t *memory = (gckvip_unwrap_user_memory_t *)data;
	vip_uint32_t handle_id = memory->handle;
	void *handle = 0;
	GET_CONTEXTK();

	gcOnError(gckvip_database_get_handle(&context->videomem_database, handle_id, &handle));

	status = gckvip_mem_unwrap_usermemory(context, handle, memory->virtual);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unwrap user memory, status=%d\n", status);
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	gcOnError(gckvip_database_put_id(&context->videomem_database, handle_id));

onError:
#endif
	return status;
}

/*
@brief query hardware information, hardware status.
*/
#if vpmdPOWER_OFF_TIMEOUT || vpmdENABLE_USER_CONTROL_POWER
static vip_status_e do_query_power_info(
	void *data
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_query_power_info_t *info = (gckvip_query_power_info_t *)data;
	GET_CONTEXTK();
#if (vpmdENABLE_DEBUG_LOG == 4)
	vip_char_t string[GCKVIP_POWER_MAX][24] = {
		"NONE",
		"OFF",
		"IDLE",
		"CLOCK_ON",
		"ON",
		"SUSPEND",
		"RESUME",
		"SUSPEND_OFF"
	};
#endif

	if (info != VIP_NULL) {
#if vpmdPOWER_OFF_TIMEOUT
		gckvip_os_lock_mutex(context->power_mutex);

		info->power_status = context->power_status;

		gckvip_os_stop_timer(context->power_timer);

		context->user_query_power = vip_true_e;

		gckvip_os_unlock_mutex(context->power_mutex);

		PRINTK_D("power management query power info, power status=%s\n",
				 string[info->power_status]);
#elif vpmdENABLE_USER_CONTROL_POWER
		PRINTK_D("user control power query power info, user pm switch=%d, power status=%s\n",
				 context->user_pm_switch, string[context->power_status]);
		if (context->user_pm_switch) {
			info->power_status = GCKVIP_POWER_OFF;
			context->user_pm_switch =  0;
		} else {
			info->power_status = GCKVIP_POWER_ON;
		}
#else
		info->power_status = GCKVIP_POWER_ON;
#endif
	} else {
		PRINTK_E("failed to query hardware information, parameter is NULL\n");
		status = VIP_ERROR_FAILURE;
	}

	return status;
}
#endif

/*
@brief set work mode.
*/
#if vpmdENABLE_SECURE
static vip_status_e do_set_work_mode(void *data)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_set_work_mode_t *mode = (gckvip_set_work_mode_t *)data;
	GET_CONTEXTK();

	if (context->work_mode != mode->work_mode) {
		context->work_mode = mode->work_mode;
		context->work_mode_change = vip_true_e;
	}

	return status;
}
#endif

/*
@brief Applications more control over power management for VIP cores.
       such as setting core frquency, and power on/off. stop/re-start VIP core.
*/
static vip_status_e do_power_management(void *data)
{
	vip_status_e status = VIP_SUCCESS;

#if vpmdENABLE_USER_CONTROL_POWER
	GET_CONTEXTK();

	gckvip_os_lock_mutex(context->user_pm_mutex);

	status = gckvip_pm_power_management((gckvip_power_management_t *)data);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to set power management..\n");
	}

	gckvip_os_unlock_mutex(context->user_pm_mutex);
#else
	PRINTK_E("not support this feature, please set vpmdENABLE_USER_CONTROL_POWER to 1 first\n");
	status = VIP_ERROR_NOT_SUPPORTED;
#endif

	return status;
}

/*
@brief Destroy kernel space resource.
       This function only use on Linux/Andorid system when used ctrl+c to exit application or
       application crash happend.
       When the appliction exits abnormally, gckvip_destroy() used to free all kenerl space resource.
*/
vip_status_e gckvip_destroy(void)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t process_id = gckvip_os_get_pid();
	vip_bool_e need_destroy = vip_false_e;
	vip_uint32_t i = 0;
	vip_uint32_t first_free_pos = 0;
	gckvip_database_table_t *table = VIP_NULL;
	GET_CONTEXTK();

	/* destroy resource */
#if vpmdENABLE_MULTIPLE_TASK
#if defined(__linux__)
	mutex_lock(&kinit_mutex);
#endif
	if (context->initialize_mutex != VIP_NULL) {
		gckvip_os_lock_mutex(context->initialize_mutex);
	}
#endif
	if (context->initialize > 0) {
		for (i = 0; i < SUPPORT_MAX_TASK_NUM; i++) {
			if (process_id == context->process_id[i]) {
				need_destroy = vip_true_e;
				break;
			}
		}
	}
#if vpmdENABLE_MULTIPLE_TASK
	if (context->initialize_mutex != VIP_NULL) {
		gckvip_os_unlock_mutex(context->initialize_mutex);
	}
#if defined(__linux__)
	mutex_unlock(&kinit_mutex);
#endif
#endif

	/* free all video memory which created by this porcess */
	if (vip_true_e == need_destroy) {
		first_free_pos = gckvip_database_get_freepos(&context->videomem_database);
		for (i = 0; i < first_free_pos; i++) {
			gckvip_database_get_table(&context->videomem_database, i + DATABASE_MAGIC_DATA, &table);
			if ((table->process_id == process_id) && (table->handle != VIP_NULL)) {
				gckvip_video_mem_handle_t *ptr = (gckvip_video_mem_handle_t *)table->handle;

				PRINTK_I("force free video memory handle=0x%" PRIx64"\n", GCKVIPPTR_TO_UINT64(table->handle));

				switch (ptr->memory_type) {
				case GCVIP_VIDEO_MEMORY_TYPE_DYN_ALLOC: {
					gckvip_dyn_allocate_node_t *node = &ptr->node.dyn_node;
					node->mem_flag &= ~GCVIP_MEM_FLAG_MAP_USER;
					gckvip_mem_free_videomemory(context, table->handle);
				}
				break;

				case GCVIP_VIDEO_MEMORY_TYPE_VIDO_HEAP: {
					gckvip_mem_free_videomemory(context, table->handle);
				}
				break;

#if vpmdENABLE_MMU
				case GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER_LOGICAL: {
					gckvip_dyn_allocate_node_t *node = &ptr->node.dyn_node;
					node->mem_flag &= ~GCVIP_MEM_FLAG_MAP_USER;
					gckvip_mem_unwrap_usermemory(context, table->handle, 0);
				}
				break;
#endif

#if vpmdENABLE_MMU
				case GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER_PHYSICAL: {
					gckvip_dyn_allocate_node_t *node = &ptr->node.dyn_node;
					node->mem_flag &= ~GCVIP_MEM_FLAG_MAP_USER;
					gckvip_mem_unwrap_userphysical(context, table->handle, 0);
				}
				break;
#endif

				default:
					break;
				}
				gckvip_database_put_id(&context->videomem_database, i + DATABASE_MAGIC_DATA);
			}
		}
		PRINTK_I("start to destroy resource, pid=%d\n", process_id);
		do_destroy();
	} else {
		PRINTK_I("vip destroyed or other tasks running, initialize=%d\n", context->initialize);
	}

	return status;
}

/*
@brief  dispatch kernel command
@param  command, command type.
@param  data, the data for command type.
*/
vip_status_e gckvip_kernel_call(
	gckvip_command_id_e command,
	void *data
)
{
	vip_status_e status = VIP_SUCCESS;

	switch (command) {
	case KERNEL_CMD_INIT:           /* VIP initialization command. */
		status = do_init(data);
		break;

	case KERNEL_CMD_DESTROY:        /* VIP terminate command. */
		status = do_destroy();
		break;

	case KERNEL_CMD_READ_REG:       /* VIP register read command. */
		status = do_read_register(data);
		break;

	case KERNEL_CMD_WRITE_REG:      /* VIP register write command. */
		status = do_write_register(data);
		break;

	case KERNEL_CMD_WAIT:           /* VIP interrupt wait command. */
		status = do_wait(data);
		break;

	case KERNEL_CMD_SUBMIT:         /* VIP command buffer submit command. */
		status = do_submit(data);
		break;

	case KERNEL_CMD_ALLOCATION:     /* VIP buffer allocation command. */
		status = do_allocation_videomem(data);
		break;

	case KERNEL_CMD_DEALLOCATION:      /* VIP memory reset command. */
		status = do_free_videomem(data);
		break;

	case KERNEL_CMD_RESET_VIP:      /* VIP HW software reset command. */
		status = do_reset_vip();
		break;

#if vpmdENABLE_USE_AGENT_TRIGGER
	case KERNEL_CMD_QUERY_ADDRESS_INFO: /* query viplite's wait-link buffer address information */
		status = do_query_address_info(data);
		break;
#endif

	case KERNEL_CMD_QUERY_DATABASE: /* query vip sram  and axi sram info */
		status = do_query_database(data);
		break;

#if vpmdENABLE_FLUSH_CPU_CACHE
	case KERNEL_CMD_OPERATE_CACHE:    /* flush/clean/invalid cpu cache */
		status = do_flush_cache(data);
		break;
#endif

	case KERNEL_CMD_WRAP_USER_MEMORY: /* wrap user logical address memory to VIP virtual address */
		status = do_wrap_user_memory(data);
		break;

	case KERNEL_CMD_UNWRAP_USER_MEMORY: /* un-warp user memory to VIP virtual */
		status = do_unwrap_user_memory(data);
		break;

	case KERNEL_CMD_WRAP_USER_PHYSICAL:  /* wrap user physical memory to VIP */
		status = do_wrap_user_physical(data);
		break;

	case KERNEL_CMD_UNWRAP_USER_PHYSICAL: /* un-warp physical memory */
		status = do_unwrap_user_physical(data);
		break;

#if vpmdPOWER_OFF_TIMEOUT || vpmdENABLE_USER_CONTROL_POWER
	case KERNEL_CMD_QUERY_POWER_INFO: /* query hardware information */
		status = do_query_power_info(data);
		break;
#endif

#if vpmdENABLE_SECURE
	case KERNEL_CMD_SET_WORK_MODE: /* set network work mode*/
		status = do_set_work_mode(data);
		break;
#endif

	case KERNEL_CMD_POWER_MANAGEMENT:
		status = do_power_management(data);
		break;

	default:
		status = VIP_ERROR_INVALID_ARGUMENTS;
		PRINTK_E("kernel doesn't support this command: %d\n", command);
		break;

	};

	return status;
}
