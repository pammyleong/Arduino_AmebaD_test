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

#ifndef _GC_VIP_KERNEL_DEBUG_H
#define _GC_VIP_KERNEL_DEBUG_H

#include <gc_vip_common.h>
#include <vip_lite.h>
#include <gc_vip_kernel.h>

#if vpmdENABLE_HANG_DUMP
vip_status_e gckvip_dump_data(
	vip_uint32_t *data,
	vip_uint32_t physical,
	vip_uint32_t size
);

vip_status_e gckvip_dump_states(
	gckvip_context_t *context
);

vip_status_e gckvip_dump_command(
	gckvip_submit_t *submit
);

vip_status_e gckvip_hang_dump(void);

vip_status_e gckvip_dump_waitlink(
	vip_uint32_t *data,
	vip_uint32_t physical
);

#if vpmdENABLE_MMU
vip_status_e gckvip_dump_flush_MMUCmds(
	gckvip_video_memory_t *buffer
);
#endif

#if vpmdENABLE_HANG_DUMP > 1
vip_status_e gckvip_dump_AHB_register(void);
#endif
#endif

#if vpmdENABLE_DEBUG_LOG > 2
void gckvip_report_clock(void);

vip_status_e gckvip_dump_options(void);
#endif

#endif
