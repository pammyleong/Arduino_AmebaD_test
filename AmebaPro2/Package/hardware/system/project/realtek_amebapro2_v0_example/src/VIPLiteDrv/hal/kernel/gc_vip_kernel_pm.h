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

#ifndef _GC_VIP_KERNEL_PM_H
#define _GC_VIP_KERNEL_PM_H

#include <gc_vip_common.h>
#include <vip_lite.h>
#include <gc_vip_kernel.h>

typedef enum _gckvip_user_pm_status_e {
	GCKVIP_USER_PM_NONE           = 0,
	GCKVIP_USER_PM_OFF_WAIT_HW    = 1,
	GCKVIP_USER_PM_OFF            = 2,
	GCKVIP_USER_PM_ON             = 3,
	GCKVIP_USER_PM_STOP           = 4,
	GCKVIP_USER_PM_MAX,
} gckvip_user_pm_status_e;


/*
@bried initialize driver power management module.
*/
vip_status_e gckvip_pm_init(
	gckvip_context_t *context
);

/*
@bried un-initialize driver power management module.
*/
vip_status_e gckvip_pm_uninit(
	gckvip_context_t *context
);

/*
@brief  initialize hardware for system resume and power management
*/
vip_status_e gckvip_pm_resume(void);

#if vpmdENABLE_SUSPEND_RESUME
/*
@brief  uninitialize hardware for system suspend
*/
vip_status_e gckvip_pm_suspend(void);
#endif

#if vpmdENABLE_USER_CONTROL_POWER
vip_status_e gckvip_pm_power_management(
	gckvip_power_management_t *power
);
#endif

vip_status_e gckvip_pm_set_frequency(
	vip_uint8_t fscale_percent
);

#endif
