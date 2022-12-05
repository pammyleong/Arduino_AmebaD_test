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

#ifndef _GC_VIP_HARDWARE_H
#define _GC_VIP_HARDWARE_H

#include <gc_vip_kernel.h>

#define WAIT_TIME_EXE               200
#define WAIT_LINK_SIZE              16
#define EVENT_SIZE                  8
#define LINK_SIZE                   8
#define END_SIZE                    8

#if vpmdENABLE_MMU
#define FLUSH_MMU_STATES_SIZE       (24 + LINK_SIZE + LINK_SIZE)
#else
#define FLUSH_MMU_STATES_SIZE       0
#endif


#if vpmdENABLE_WAIT_LINK_LOOP
#define APPEND_COMMAND_SIZE (EVENT_SIZE + WAIT_LINK_SIZE)
#else
#define APPEND_COMMAND_SIZE (EVENT_SIZE + END_SIZE)
#endif


#define SETBIT(value, bit, data) \
    (((value) & (~(1 << (bit)))) | ((data) << (bit)))


/*
@ brief
    Initializae HW.
*/
vip_status_e gckvip_hw_init(
	gckvip_context_t *context
);

/*
@ brief
    Destroy and free HW resource.
*/
vip_status_e gckvip_hw_destroy(
	gckvip_context_t *context
);


/*
@ brief
    Do a software HW reset.
*/
vip_status_e gckvip_hw_reset(void);

#if vpmdENABLE_WAIT_LINK_LOOP
/*
@ brief
    Trigger hardware, NPU start to run.
*/
vip_status_e gckvip_hw_trigger(
	gckvip_context_t *context
);
#endif

/*
@ brief
    Submit command buffer to hardware.
*/
vip_status_e gckvip_hw_submit(
	gckvip_context_t *context,
	gckvip_submit_t *submit
);

/*
@ brief
    Insert flush mmu cache load states
*/
#if vpmdENABLE_MMU
vip_status_e gckvip_hw_flush_mmu(
	gckvip_context_t *context,
	gckvip_submit_t *submit
);
#endif

/*
@ brief
    hardware go back to WL.
*/
vip_status_e gckvip_hw_idle(
	gckvip_context_t *context
);

#if vpmdENABLE_DEBUG_LOG > 1
/*
@ brief
    Calculate frequency.
*/
vip_status_e gckvip_hw_get_clock(
	vip_uint64_t *clk_MC,
	vip_uint64_t *clk_SH
);
#endif

vip_status_e gckvip_hw_read_info(
	gckvip_context_t *context
);

/*
@brief  read a hardware register.
@param  address, the address of hardware register.
@param  data, read data from register.
*/
vip_status_e gckvip_read_register(
	vip_uint32_t address,
	vip_uint32_t *data
);

/*
@brief  write a hardware register.
@param  address, the address of hardware register.
@param  data, write data to register.
*/
vip_status_e gckvip_write_register(
	vip_uint32_t address,
	vip_uint32_t data
);

/*
@brief query hardware is idle.
*/
vip_bool_e gckvip_hw_query_idle(void);

/*
@brief poll to waiting hardware going to idle.
@param timeout the number of milliseconds this waiting.
*/
vip_status_e gckvip_hw_wait_poll(
	vip_uint32_t timeout
);

/*
@brief waiting for hardware going to idle.
@param context, the contect of kernel space.
@param timeout the number of milliseconds this waiting.
*/
vip_status_e gckvip_hw_wait_idle(
	gckvip_context_t *context,
	vip_uint32_t timeout
);

#endif
