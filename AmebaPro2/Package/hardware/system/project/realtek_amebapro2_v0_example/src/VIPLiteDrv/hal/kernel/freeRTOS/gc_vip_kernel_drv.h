/******************************************************************************\
|* Copyright (c) 2017-2021 by Vivante Corporation.  All Rights Reserved.      *|
|*                                                                            *|
|* The material in this file is confidential and contains trade secrets of    *|
|* of Vivante Corporation.  This is proprietary information owned by Vivante  *|
|* Corporation.  No part of this work may be disclosed, reproduced, copied,   *|
|* transmitted, or used in any way for any purpose, without the express       *|
|* written permission of Vivante Corporation.                                 *|
|*                                                                            *|
\******************************************************************************/

#ifndef __GC_VIP_KERNEL_DRV_H__
#define __GC_VIP_KERNEL_DRV_H__

#include <gc_vip_common.h>
#include "FreeRTOS.h"
#include "semphr.h"

typedef uintptr_t  gckvip_uintptr_t;

/*
@brief Set power on/off and clock on/off
@param state, power status. refer to gckvip_power_status_e.
*/
vip_status_e gckvip_drv_set_power_clk(
	vip_uint32_t state
);

/*
@brief Get hardware register base address.
@param base, hardwarae register base address.
*/
vip_status_e gckvip_drv_get_reg_base(
	void **base
);

#if vpmdENABLE_VIDEO_MEMORY_HEAP
/*
@brief Get video memory information.
@param memory, the logical base address of video memory heap.
@param memory_kernel, the logical base address of video memory heap.
@param physical, the physical base address of video memory heap.
@param size, the size of video memory heap.
*/
vip_status_e gckvip_drv_get_videomemory_info(
	void **memory,
	void **memory_kernel,
	phy_address_t *physical,
	vip_uint32_t *size
);
#endif

/*
@brief Get SRAM information.
@param axi_sarm_size, the size of AXI SRAM.
@param axi_sram_address, the base address of AXI SRAM.
@param vip_sram_sizew, the size of VIP SRAM.
@param vip_sram_address, the base address of VIP SRAM.
*/
vip_status_e gckvip_drv_get_sram_info(
	vip_uint32_t *axi_sram_size,
	vip_uint32_t *axi_sram_address,
	vip_uint32_t *vip_sram_size,
	vip_uint32_t *vip_sram_address
);

/*
@brief Get interrupt irq information.
@param sem, semphore for interrupt.
@param irq_flag, flag for interrupt.
*/
vip_status_e gckvip_drv_get_irq(
	void **sem,
	vip_uint32_t **irq_flag
);

/*
@brief do some initialize in this function.
@param, vip_memsizem, the size of video memory heap.
*/
vip_status_e gckvip_drv_init(
	vip_uint32_t vip_memsize
);

/*
@brief do some un-initialize in this function.
*/
vip_status_e gckvip_drv_exit(void);

#endif /* __GC_VIP_KERNEL_DRV_H__ */
