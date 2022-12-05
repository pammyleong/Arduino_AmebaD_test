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
//#include <string.h>
#include "FreeRTOS.h"
#include "gc_vip_kernel_drv.h"
#include "gc_vip_hardware.h"
#include "gc_vip_kernel.h"
#include "gc_vip_platform_config.h"
//RTK_removed
//#include "gicv2.h"
#include "task.h"

#define npuInt_PRI (((uint32_t)configUNIQUE_INTERRUPT_PRIORITIES) - 5UL)


typedef struct _gckvip_device_t {
	void *vip_reg;             /* Mapped cpu virtual address for register memory base */

#if vpmdENABLE_VIDEO_MEMORY_HEAP
	void *cpu_virtual;         /* Mapped cpu virtual address for the VIP memory. */
	phy_address_t cpu_physical;     /* CPU physical adddress for the VIP memory */
	phy_address_t vip_physical;     /* VIP physical address which VIP would issue to access */
	vip_uint32_t vip_memsize;
#endif

	vip_int32_t irq_enabled;
	vip_int32_t registered;
	vip_int32_t init;
	vip_uint32_t int_flags;
	SemaphoreHandle_t xIntSemaphore;

	vip_uint32_t power_status;  /* power on or off */
} gckvip_device_t;


static gckvip_device_t vip_dev;
static portBASE_TYPE xHigherPriorityTaskWoken;

/*
@brief interrupte handle function.
*/
/*
uint32_t __get_BASEPRI(void)
{
  register uint32_t result;

  asm ( "mov %0, basepri\n" : "=r" (result) );
  return(result);
}
*/

static void irq_handler(void)
{
	vip_uint32_t value = 0;

	uint32_t basepri = __get_BASEPRI();
	if (basepri != 0) {
		printf("in NN IRQ basepri = %d\n\r", basepri);
	}
	xHigherPriorityTaskWoken = pdFALSE;

	gckvip_read_register(0x00010, &value);

	if (value != 0x00) {
		vip_dev.int_flags = value;
		xSemaphoreGiveFromISR(vip_dev.xIntSemaphore, &xHigherPriorityTaskWoken);
	}
}

/*
@brief Get hardware register base address.
@param base, hardwarae register base address.
*/
vip_status_e gckvip_drv_get_reg_base(void **base)
{
	vip_dev.vip_reg = (void *)AHB_REGISTER_BASE_ADDRESS,

	*base = vip_dev.vip_reg;

	if (vip_dev.vip_reg == VIP_NULL) {
		PRINTK("vipcore, register map is NULL\n");
		return VIP_ERROR_IO;
	}

	return VIP_SUCCESS;
}

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
)
{
	vip_status_e status = VIP_SUCCESS;

	*memory = vip_dev.cpu_virtual;
	*memory_kernel = vip_dev.cpu_virtual;
	*physical = vip_dev.vip_physical;
	*size = vip_dev.vip_memsize;

	if ((vip_dev.cpu_virtual == VIP_NULL)  || (vip_dev.vip_physical == 0) || (vip_dev.vip_memsize == 0)) {
		PRINTK("vipcore, video memory is NULL\n");
		status = VIP_ERROR_IO;
	}

	return status;
}
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
)
{
	if ((VIP_NULL == axi_sram_size) || (VIP_NULL == vip_sram_size)
		|| (VIP_NULL == axi_sram_address) || (VIP_NULL == vip_sram_address)) {
		PRINTK("failed to get sram size, param is NULL\n");
		return VIP_ERROR_OUT_OF_MEMORY;
	}

	*axi_sram_size = AXI_SRAM_SIZE;
	*vip_sram_size = VIP_SRAM_SIZE;
	*axi_sram_address = AXI_SRAM_BASE_ADDRESS;
	*vip_sram_address = VIP_SRAM_BASE_ADDRESS;

	return VIP_SUCCESS;
}

/*
@brief Get interrupt irq information.
@param sem, semphore for interrupt.
@param int_flags, flag for interrupt.
*/
vip_status_e gckvip_drv_get_irq(
	void **sem,
	vip_uint32_t **int_flags
)
{
	vip_dev.int_flags = 0;

	*sem = (void *)&vip_dev.xIntSemaphore;
	*int_flags = (vip_uint32_t *)&vip_dev.int_flags;

	return VIP_SUCCESS;
}

/*
@brief Set power on/off and clock on/off
@param state, power status. refer to gckvip_power_status_e.
*/
vip_status_e gckvip_drv_set_power_clk(
	vip_uint32_t state
)
{
	vip_status_e status = VIP_SUCCESS;

	if (state == GCKVIP_POWER_ON) {
		if (state != vip_dev.power_status) {
			/* power/clock on here */

			vip_dev.power_status = GCKVIP_POWER_ON;
		}
	} else if (state == GCKVIP_POWER_OFF) {
		if (state != vip_dev.power_status) {
			/* power/clock off here */

			vip_dev.power_status = GCKVIP_POWER_OFF;
		}
	} else {
		PRINTK("vipcore, no this state=%d in set power clk\n", state);
		status = VIP_ERROR_FAILURE;
	}

	return status;
}

#if defined(CONFIG_PLATFORM_8735B)
#include "rtl8735b.h"
#include "hal_irq.h"
#endif

/*
@brief do some initialize in this function.
@param, vip_memsizem, the size of video memory heap.
*/
vip_status_e gckvip_drv_init(
	vip_uint32_t vip_memsize
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_dev.init = 0;

	/* power on VIP */
	status = gckvip_drv_set_power_clk(GCKVIP_POWER_ON);
	if (status != VIP_SUCCESS) {
		PRINTK("vipcore, failed to power on\n");
		goto exit;
	}

#if vpmdENABLE_VIDEO_MEMORY_HEAP
	if (!vip_dev.cpu_virtual) {
		vip_dev.vip_memsize  = VIDEO_MEMORY_HEAP_SIZE;
		vip_dev.cpu_virtual  = (void *)VIDEO_MEMORY_HEAP_BASE_ADDRESS;
		vip_dev.cpu_physical = VIDEO_MEMORY_HEAP_BASE_ADDRESS;
		vip_dev.vip_physical = VIDEO_MEMORY_HEAP_BASE_ADDRESS;
	}
	PRINTK("gck vip_drv_init, video memory heap base: 0x%08X, size: 0x%08X\n",
		   vip_dev.cpu_virtual, vip_dev.vip_memsize);

	vip_memsize = vip_memsize;/* Keep compiler happy. */
#endif

#if defined(CONFIG_PLATFORM_8735B)
	if (!vip_dev.irq_enabled) {
		hal_irq_disable(NN_IRQn);
		__ISB();
		hal_irq_set_vector(NN_IRQn, (uint32_t)irq_handler);
		printf("NN IRQ default priority : %d, set to %d\n\r", hal_irq_get_priority(NN_IRQn), NN_IRQPri);
		hal_irq_set_priority(NN_IRQn, NN_IRQPri);
		hal_irq_enable(NN_IRQn);

		//plat_gic_irq_register(IRQ_LINE_NUMBER, npuInt_PRI, 1, (InterruptHandler)irq_handler);
		vip_dev.irq_enabled = 1;
	}

	if (!vip_dev.init) {
		vip_dev.xIntSemaphore = xSemaphoreCreateBinary();
		if (vip_dev.xIntSemaphore == NULL) {
			PRINTK("gck vip_drv_init xIntSemaphore fail\n");
			goto exit;
		}
	}
#endif

#if 0 //RTK_reomoved
	if (!vip_dev.irq_enabled) {
		plat_gic_irq_register(IRQ_LINE_NUMBER, npuInt_PRI, 1, (InterruptHandler)irq_handler);
		vip_dev.irq_enabled = 1;
	}

	if (!vip_dev.init) {
		vip_dev.xIntSemaphore = xSemaphoreCreateBinary();
		if (vip_dev.xIntSemaphore == NULL) {
			PRINTK("gck vip_drv_init xIntSemaphore fail\n");
			goto exit;
		}
	}
#endif

	vip_dev.init = 1;

exit:
	return status;
}

/*
@brief do some un-initialize in this function.
*/
vip_status_e gckvip_drv_exit(void)
{
	vip_status_e status = VIP_SUCCESS;

#if defined(CONFIG_PLATFORM_8735B)
	if (vip_dev.irq_enabled) {
		//plat_gic_irq_unregister(IRQ_LINE_NUMBER);
		hal_irq_disable(NN_IRQn);
		__ISB();
		hal_irq_set_vector(NN_IRQn, (uint32_t)NULL);
	}

	if (vip_dev.xIntSemaphore) {
		vSemaphoreDelete(vip_dev.xIntSemaphore);
		vip_dev.init = 0;
	}
#endif

#if vpmdENABLE_VIDEO_MEMORY_HEAP
	if (vip_dev.cpu_physical) {
		vip_dev.cpu_virtual = NULL;
		vip_dev.vip_memsize  = 0;
		vip_dev.cpu_physical = 0;
		vip_dev.vip_physical = 0;
	}
#endif

	status = gckvip_drv_set_power_clk(GCKVIP_POWER_OFF);
	if (status != VIP_SUCCESS) {
		PRINTK("vipcore, failed to power off\n");
	}

	return status;
}
