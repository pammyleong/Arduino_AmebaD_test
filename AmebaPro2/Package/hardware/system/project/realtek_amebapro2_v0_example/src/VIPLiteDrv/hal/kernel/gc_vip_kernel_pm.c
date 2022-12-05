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
#include <gc_vip_kernel.h>
#include <gc_vip_kernel_port.h>
#include <gc_vip_kernel_pm.h>
#include <gc_vip_kernel_drv.h>
#include <gc_vip_kernel_util.h>

/*
@brief a timer handle for power off VIP.
@param context, the kernel context.
*/
#if vpmdPOWER_OFF_TIMEOUT
vip_status_e power_manage_thread(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;

	while (1) {
		if (VIP_SUCCESS == gckvip_os_wait_signal(context->power_signal, WAIT_SIGNAL_TIMEOUT)) {
			gckvip_os_lock_mutex(context->power_mutex);
			/* wait signal next time */
			gckvip_os_set_signal(context->power_signal, vip_false_e);

			PRINTK_D("power management thread wake up\n");
			if (vip_false_e == context->power_thread_running) {
				break;
			}

			/* power off and cut down clock */
			if ((context->power_status == GCKVIP_POWER_IDLE) &&
				(vip_false_e == context->user_query_power)) {
				gckvip_hw_wait_idle(context, 128); /* waiting hw 128ms */

				status = gckvip_drv_set_power_clk(GCKVIP_POWER_OFF);
				if (VIP_SUCCESS != status) {
					PRINTK_E("failed to power off hardware in power management thread, status=%d\n",
							 status);
				}
				context->power_status = GCKVIP_POWER_OFF;
			}
			gckvip_os_unlock_mutex(context->power_mutex);
		}
	}
	PRINTK_I("power management thread exit\n");

	return status;
}

int debug = 1;
void power_off_timer_handle(
	gckvip_context_t *context
)
{
	gckvip_queue_status_e queue_status = GCKVIP_QUEUE_EMPTY;

#if vpmdENABLE_MULTIPLE_TASK
	queue_status = gckvip_queue_status(&context->mt_input_queue);
#endif

	PRINTK_D("power off timer handle start. vip_idle=%s. timeout=%dms, muti-task queue staus=%s\n",
			 (context->vip_idle == vip_true_e) ? "idle" : "busy", vpmdPOWER_OFF_TIMEOUT,
			 (GCKVIP_QUEUE_EMPTY == queue_status) ? "empty" : "not-empty");

	/* power off the hardware, now it is idle status */
	if (gckvip_hw_query_idle() && (GCKVIP_QUEUE_EMPTY == queue_status)) {
		gckvip_os_set_signal(context->power_signal, vip_true_e);
	} else {
		PRINTK_D("power timer check, vip status not idle or cmd queue not enpty, by pass power off\n");
	}
}
#endif

/*
@bried initialize driver power management module.
*/
vip_status_e gckvip_pm_init(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;

#if vpmdPOWER_OFF_TIMEOUT
	status = gckvip_os_create_mutex(&context->power_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create mutex for power memory\n");
		gcGoOnError(VIP_ERROR_IO);
	}
	status = gckvip_os_create_signal(&context->power_signal);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create a signal for power\n");
		gcGoOnError(VIP_ERROR_IO);
	}
	status = gckvip_os_create_thread((void *)power_manage_thread,
									 (void *)context,
									 &context->power_thread);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create a thread for supporting power manage.\n");
		gcGoOnError(VIP_ERROR_IO);
	}
	context->power_thread_running = vip_true_e;

	status = gckvip_os_create_timer(power_off_timer_handle, (vip_ptr)context, &context->power_timer);
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to create timer for power off\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	PRINTK_I("power management is enabled...\n");
#endif

	/* create signals for system suspend/resume feature */
#if vpmdENABLE_SUSPEND_RESUME
	status = gckvip_os_create_signal(&context->resume_signal);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create resume signal\n");
		gcGoOnError(VIP_ERROR_IO);
	}
	context->wait_resume_signal = vip_false_e;
#endif

#if vpmdENABLE_USER_CONTROL_POWER
	status = gckvip_os_create_mutex(&context->user_pm_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create mutex for power memory\n");
		gcGoOnError(VIP_ERROR_IO);
	}
	context->user_pm_status = GCKVIP_USER_PM_ON;
#endif

	/* hardware has been power on in gckvip_os_init */
	context->power_status = GCKVIP_POWER_ON;

	return status;

#if vpmdENABLE_USER_CONTROL_POWER || vpmdENABLE_SUSPEND_RESUME || vpmdPOWER_OFF_TIMEOUT
onError:
#endif
#if vpmdPOWER_OFF_TIMEOUT
	if (context->power_mutex != VIP_NULL) {
		gckvip_os_destroy_mutex(context->power_mutex);
	}
	if (context->power_signal != VIP_NULL) {
		gckvip_os_destroy_signal(context->power_signal);
	}
	if (context->power_thread != VIP_NULL) {
		gckvip_os_destroy_thread(context->power_thread);
	}
	if (context->power_timer != VIP_NULL) {
		gckvip_os_stop_timer(context->power_timer);
		gckvip_os_destroy_timer(context->power_timer);
	}
#endif

#if vpmdENABLE_SUSPEND_RESUME
	if (context->resume_signal != VIP_NULL) {
		gckvip_os_destroy_signal(context->resume_signal);
	}
#endif
	return status;
}

/*
@bried un-initialize driver power management module.
*/
vip_status_e gckvip_pm_uninit(
	gckvip_context_t *context
)
{
#if vpmdPOWER_OFF_TIMEOUT
	context->power_thread_running = vip_false_e;
	gckvip_os_set_signal(context->power_signal, vip_true_e); /* power thread exit */

	if (context->power_thread != VIP_NULL) {
		gckvip_os_destroy_thread(context->power_thread);
	}
	if (context->power_timer != VIP_NULL) {
		gckvip_os_stop_timer(context->power_timer);
		gckvip_os_destroy_timer(context->power_timer);
	}
	if (context->power_mutex != VIP_NULL) {
		gckvip_os_destroy_mutex(context->power_mutex);
	}
	gckvip_os_destroy_signal(context->power_signal);

#endif

#if vpmdENABLE_SUSPEND_RESUME
	gckvip_os_destroy_signal(context->resume_signal);
	context->wait_resume_signal = vip_false_e;
#endif

#if vpmdENABLE_USER_CONTROL_POWER
	if (context->user_pm_mutex != VIP_NULL) {
		gckvip_os_destroy_mutex(context->user_pm_mutex);
		context->user_pm_mutex  = VIP_NULL;
	}
#endif
	/* power off in gckvip_os_close */
	context->power_status = GCKVIP_POWER_OFF;

	return VIP_SUCCESS;
}

/*
@brief  initialize hardware for system resume and power management
*/
vip_status_e gckvip_pm_resume(void)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_context_t *context = gckvip_get_context();

#if vpmdENABLE_MULTIPLE_TASK
	if (context->initialize_mutex != VIP_NULL) {
		gckvip_os_lock_mutex(context->initialize_mutex);
	}
#endif

	context->power_status = GCKVIP_POWER_NONE;
	if (context->initialize > 0) {
		PRINTK_D("power management start power on and clock up..\n");
		status = gckvip_drv_set_power_clk(GCKVIP_POWER_ON); /* power on hardware */
		if (status != VIP_SUCCESS) {
			PRINTK_E("vipcore, failed to power on hardware\n");
			gcGoOnError(VIP_ERROR_FAILURE);
		}

		context->power_status = GCKVIP_POWER_CLK_ON;
		gckvip_os_delay(2); /* waiting power stable */

		PRINTK_D("start to re-initialize hardware..\n");
		status = gckvip_hw_reset();
		if (status != VIP_SUCCESS) {
			PRINTK_E("fail to software reset hardware\n");
			gcGoOnError(VIP_ERROR_IO);
		}

		status = gckvip_hw_init(context);
		if (status != VIP_SUCCESS) {
			PRINTK_E("fail to initialize hardware\n");
			gcGoOnError(VIP_ERROR_IO);
		}

#if vpmdENABLE_WAIT_LINK_LOOP
		gckvip_hw_trigger(context);
		context->waitlink_pos = context->waitlinkbuf_logical;
		gckvip_os_delay(1);
#endif

		status = gckvip_init_commands();
		if (status != VIP_SUCCESS) {
			PRINTK_E("fail to initialize status\n");
			gcGoOnError(VIP_ERROR_IO);
		}

#if vpmdENABLE_SUSPEND_RESUME
		if (vip_true_e == context->wait_resume_signal) {
			context->wait_resume_signal = vip_false_e;
			PRINTK_I("wake up resume signal..\n");
			gckvip_os_set_signal(context->resume_signal, vip_true_e);
		}
#endif

		context->power_status = GCKVIP_POWER_RESUME;
	} else {
		PRINTK_E("doesn't initialize vip hardware or hardware is power on status\n");
		gcGoOnError(VIP_ERROR_FAILURE);
	}

#if vpmdENABLE_MULTIPLE_TASK
	if (context->initialize_mutex != VIP_NULL) {
		gckvip_os_unlock_mutex(context->initialize_mutex);
	}
#endif

	context->core_fscale_percent = 100;

	return status;

onError:
	gckvip_drv_set_power_clk(GCKVIP_POWER_OFF);

#if vpmdENABLE_MULTIPLE_TASK
	if (context->initialize_mutex != VIP_NULL) {
		gckvip_os_unlock_mutex(context->initialize_mutex);
	}
#endif
	return status;
}

#if vpmdENABLE_SUSPEND_RESUME
/*
@brief  uninitialize hardware for system suspend
*/
vip_status_e gckvip_pm_suspend(void)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_context_t *context = gckvip_get_context();

	if (GCKVIP_POWER_OFF == context->power_status) {
		return VIP_SUCCESS;
	}

#if vpmdENABLE_MULTIPLE_TASK
	if (context->initialize_mutex != VIP_NULL) {
		gckvip_os_lock_mutex(context->initialize_mutex);
	}
#endif

	if (0 == context->initialize) {
#if vpmdENABLE_MULTIPLE_TASK
		if (context->initialize_mutex != VIP_NULL) {
			gckvip_os_unlock_mutex(context->initialize_mutex);
		}
#endif
		return VIP_SUCCESS;
	}

	context->power_status = GCKVIP_POWER_SUSPEND;
	PRINTK_I("suspend vip idle status=%s\n", context->vip_idle ? "idle" : "busy");

	if (vip_false_e == context->vip_idle) {
		/* have a task is running on VIP, waiting for the task is finished */
		PRINTK_I("suspend, waiting for task finish...\n");
		gckvip_hw_wait_idle(context, 2000);
	}

	/* power off and rise down clock */
	status = gckvip_drv_set_power_clk(GCKVIP_POWER_OFF);
	if (status != VIP_SUCCESS) {
		PRINTK_E("vipcore, failed to power of in suspend\n");
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	context->power_status = GCKVIP_POWER_SUSPEND_OFF;

onError:
#if vpmdENABLE_MULTIPLE_TASK
	if (context->initialize_mutex != VIP_NULL) {
		gckvip_os_unlock_mutex(context->initialize_mutex);
	}
#endif
	return status;
}
#endif

vip_status_e gckvip_pm_set_frequency(
	vip_uint8_t fscale_percent
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t bk_data = 0;
	vip_uint32_t value = 0;
	vip_uint32_t sh_value = 0;
	vip_uint32_t fscale = 0;
	gckvip_context_t *context = gckvip_get_context();

	if (context->last_fscale_percent != fscale_percent) {
		if (0 == fscale_percent) {
			PRINTK_E("set hardware frequency, fscale percent is 0. force set to minimum value 1.\n");
			fscale_percent = 1;
		}

		if (fscale_percent > 100) {
			PRINTK_E("set hardware frequency, fscale percent is more than 100."
					 "force set to maximum vaue 100.\n");
			fscale_percent = 100;
		}

		fscale = 64 * fscale_percent / 100;

		if (fscale < 1) {
			fscale = 1;
		} else if (fscale > 64) {
			fscale = 64;
		}
		PRINTK_D("set hardware frequency fscale=%d, percent=%d\n", fscale, fscale_percent);

		/* get power control */
		gckvip_read_register(0x00104, &bk_data);

		/* disable all clock gating */
		gckvip_write_register(0x00104, 0x00000bff);

		/* scale the core clock */
		value = SETBIT(value, 0, 0);
		value = SETBIT(value, 1, 0);
		value = SETBIT(value, 2, fscale);
		value = SETBIT(value, 9, 1);
		gckvip_write_register(0x00000, value);

		/* done loading the frequency scaler */
		value = SETBIT(value, 9, 0);
		gckvip_write_register(0x00000, value);

		/* scale the ppu clock */
		sh_value = SETBIT(sh_value, 16, 0);
		sh_value = SETBIT(sh_value, 17, 1);
		sh_value = SETBIT(sh_value, 1, fscale);
		sh_value = SETBIT(sh_value, 0, 1);

		gckvip_write_register(0x0010C, sh_value);

		/* done loading the PPU frequency scaler. */
		sh_value = SETBIT(sh_value, 0, 0);
		gckvip_write_register(0x0010C, sh_value);

		gckvip_write_register(0x00104, bk_data);

		context->last_fscale_percent = fscale_percent;
	}

	return status;
}

#if vpmdENABLE_USER_CONTROL_POWER
vip_status_e gckvip_pm_power_management(
	gckvip_power_management_t *power
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_context_t *context = gckvip_get_context();

	switch (power->property) {
	case VIP_POWER_PROPERTY_SET_FREQUENCY: {
		if ((GCKVIP_USER_PM_OFF != context->user_pm_status) &&
			(GCKVIP_POWER_OFF != context->power_status)) {
			status = gckvip_pm_set_frequency(power->fscale_percent);
			if (status != VIP_SUCCESS) {
				PRINTK_E("failed to set hardware frequency..\n");
				gcGoOnError(VIP_ERROR_FAILURE);
			}
		} else {
			PRINTK_E("failed to set hardware frequency, hardware is power off status, user=%d, power=%d\n",
					 context->user_pm_status, context->power_status);
			gcGoOnError(VIP_ERROR_FAILURE);
		}

		if (power->fscale_percent > 100) {
			context->core_fscale_percent = 100;
		} else {
			context->core_fscale_percent = power->fscale_percent;
		}
	}
	break;

	case VIP_POWER_PROPERTY_OFF: {
		if (GCKVIP_USER_PM_ON == context->user_pm_status) {
			gckvip_queue_status_e queue_status = GCKVIP_QUEUE_EMPTY;
#if vpmdENABLE_MULTIPLE_TASK
			queue_status = gckvip_queue_status(&context->mt_input_queue);
#endif

			if (context->vip_idle && (GCKVIP_QUEUE_EMPTY == queue_status)) {
				PRINTK_D("hardware is idle, power off immediately\n");
				/* hardware is idle status, power off hardware immediately */
				gckvip_hw_wait_idle(context, 128); /* waiting hw 128ms */
				status = gckvip_drv_set_power_clk(GCKVIP_POWER_OFF);
				if (status != VIP_SUCCESS) {
					PRINTK_E("failed to power off hardware user control api\n");
					gcGoOnError(VIP_ERROR_FAILURE);
				} else {
					context->power_status = GCKVIP_POWER_OFF;
					context->user_pm_switch = 1;
				}

				context->user_pm_status = GCKVIP_USER_PM_OFF;
			} else {
				PRINTK_D("power off when VIP finishes executing the current VIP command buffer,"
						 "vip_idle=%d, queue_status=%d\n",
						 context->vip_idle, queue_status);
				/* power off hardware when vip is idle */
				context->user_pm_status = GCKVIP_USER_PM_OFF_WAIT_HW;
			}
		} else {
			PRINTK_E("the hardware is already power off\n");
		}
	}
	break;

	case VIP_POWER_PROPERTY_ON: {
		if (GCKVIP_USER_PM_OFF == context->user_pm_status) {
			status = gckvip_pm_resume();  /* initialize and resume hardware */
			if (status != VIP_SUCCESS) {
				PRINTK_E("failed to init hardware for power management ON\n");
				gcGoOnError(VIP_ERROR_FAILURE);
			}
		} else {
			PRINTK_E("the hardware is already powered on\n");
		}
		context->user_pm_status = GCKVIP_USER_PM_ON;
	}
	break;

	case VIP_POWER_PROPERTY_STOP: {
		context->user_pm_status = GCKVIP_USER_PM_STOP;
	}
	break;

	case VIP_POWER_PROPERTY_START: {
		context->user_pm_status = GCKVIP_USER_PM_ON;
	}
	break;

	default:
		PRINTK_E("application setting power management, not support property=%d\n",
				 power->property);
		break;
	}

onError:
	return status;
}
#endif
