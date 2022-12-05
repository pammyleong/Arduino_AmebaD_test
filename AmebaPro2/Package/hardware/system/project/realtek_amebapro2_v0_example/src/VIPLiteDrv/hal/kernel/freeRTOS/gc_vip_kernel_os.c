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
#include "FreeRTOS.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "gc_vip_kernel_port.h"
#include "gc_vip_kernel.h"
#include "gc_vip_kernel_drv.h"
#include "gc_vip_kernel_heap.h"
#include "gc_vip_hardware.h"
//RTK_removed
//#include "printf.h"


#define malloc      pvPortMalloc
#define free        vPortFree

/*
@brief Do some initialization works in KERNEL_OS layer.
@param video_mem_size, the size of video memory heap.
*/
vip_status_e gckvip_os_init(
	vip_uint32_t video_mem_size
)
{
	vip_status_e status = VIP_SUCCESS;

	status = gckvip_drv_init(video_mem_size);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to drv init\n");
	}

	return status;
}

/*
@brief Do some un-initialization works in KERNEL_OS layer.
*/
vip_status_e gckvip_os_close()
{
	vip_status_e status = VIP_SUCCESS;

	status = gckvip_drv_exit();
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to drv exit\n");
	}

	return status;
}


/*******************************NOTICE***********************************/
/************************************************************************/
/* *********************need to be ported functions**********************/
/************************************************************************/
/************************************************************************/
/************************************************************************/
/*
@brief Allocate system memory in kernel space.
@param video_mem_size, the size of video memory heap.
@param size, Memory size to be allocated.
@param memory, Pointer to a variable that will hold the pointer to the memory.
*/
vip_status_e gckvip_os_allocate_memory(
	IN  vip_uint32_t size,
	OUT void **memory
)
{
	vip_status_e error = VIP_SUCCESS;

	if (size > 0) {
		*memory = malloc(size);
		if (*memory == VIP_NULL) {
			error = VIP_ERROR_OUT_OF_MEMORY;
		}
	} else {
		error = VIP_ERROR_INVALID_ARGUMENTS;
	}

	return error;
}

/*
@brief Free system memory in kernel space.
@param memory, Memory to be freed.
*/
vip_status_e gckvip_os_free_memory(
	IN void *memory
)
{
	if (memory != VIP_NULL) {
		free(memory);
	}
	return VIP_SUCCESS;
}

/*
@brief Set memory to zero.
@param memory, Memory to be set to zero.
@param size, the size of memory.
*/
vip_status_e gckvip_os_zero_memory(
	IN void *memory,
	IN vip_uint32_t size
)
{
	if (!memory) {
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	memset(memory, 0, size);

	return VIP_SUCCESS;
}

/*
@brief copy src memory to dst memory.
@param dst, Destination memory.
@param src. Source memory
@param size, the size of memory should be copy.
*/
vip_status_e gckvip_os_memcopy(
	IN void *dst,
	IN const void *src,
	IN vip_uint32_t size
)
{
	if ((VIP_NULL == src) || (VIP_NULL == dst))  {
		PRINTK_E("failed to copy memory, parameter is NULL, size: %d bytes\n", size);
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	memcpy(dst, src, size);

	return VIP_SUCCESS;
}

/*
@brief Read a hardware register.
@param reg_base, the base address of hardware register.
@param address, read the register address.
@param data, the data of address be read.
*/
vip_status_e gckvip_os_read_reg(
	IN void *reg_base,
	IN vip_uint32_t address,
	OUT vip_uint32_t *data
)
{
	vip_uint32_t *reg = (vip_uint32_t *)((vip_uint8_t *)reg_base + address);
	*data = *reg;

#if vpmdENABLE_CAPTURE_IN_KERNEL
	PRINTK("@[register.read 0x%05X 0x%08X]\n", address, *data);
#endif

	return VIP_SUCCESS;
}

/*
@brief Write a hardware register.
@param reg_base, the base address of hardware register.
@param address, write the register address.
@param data, the data of address be wrote.
*/
vip_status_e  gckvip_os_write_reg(
	IN void *reg_base,
	IN vip_uint32_t address,
	IN vip_uint32_t data
)
{
	vip_uint32_t *reg = (vip_uint32_t *)((vip_uint8_t *)reg_base + address);
	*reg = data;

#if vpmdENABLE_CAPTURE_IN_KERNEL
	gckvip_os_print("@[register.write 0x%05X 0x%08X]\n", address, data);
#endif

	return VIP_SUCCESS;
}

/*
@brief Waiting for the hardware interrupt. wait interrupt function depend on the type of RTOS
@param irq_queue, the wait queue of interrupt handle.
@param irq_flag, a flag for interrupt.
@param mask, mask data for interrupt.
*/
vip_status_e gckvip_os_wait_interrupt(
	IN void    *irq_queue,
	IN volatile vip_uint32_t *volatile irq_flag,
	IN vip_uint32_t time_out,
	IN vip_uint32_t mask
)
{
	vip_status_e status = VIP_ERROR_TIMEOUT;
	SemaphoreHandle_t *irq_queue_handle = (SemaphoreHandle_t *)irq_queue;
	vip_uint32_t wait_done = vip_false_e;

	while (vip_false_e == wait_done) {
		if (xSemaphoreTake(*irq_queue_handle, time_out) == pdTRUE) {
			PRINTK_D("wait irq flag=0x%x\n", *irq_flag);
			if (*irq_flag & 0x80000000) {
				*irq_flag = 0;
				PRINTK_I("AXI BUS ERROR...\n");
			} else if (*irq_flag & 0x40000000) {
				vip_uint32_t mmu_status = 0;
				*irq_flag = 0;
				gckvip_read_register(0x00388, &mmu_status);
				if (mmu_status & 0x01) {
					PRINTK_I("MMU exception...\n");
				} else {
					PRINTK_I("MMU exception, then MMU is disabled\n");
				}
			} else {
				wait_done = vip_true_e;
				status = VIP_SUCCESS;
			}

			if (vip_false_e == wait_done) {
				vip_uint32_t mmu_status = 0;
				vip_uint32_t address = 0;
				gckvip_read_register(0x00384, &mmu_status);
				gckvip_read_register(0x00380, &address);
				PRINTK_I("MMU status = 0x%08X\n", mmu_status);
				PRINTK_I("MMU exception address = 0x%08X\n", address);
			}
		} else {
			PRINTK_E("freeOS xTestSemaphore time out\n");
		}
	}

	mask = mask;/* Keep compiler happy. */

	return status;
}

/*
@brief delay function.
@param ms, delay unit ms.
*/
void gckvip_os_delay(vip_uint32_t ms)
{
	if (ms > 0) {
		vTaskDelay(ms);
	}
}

/*
@brief Print string.
@param msg, which message to be print.
*/
vip_status_e gckvip_os_print(
	const char *message,
	...
)
{
	vip_status_e error = VIP_SUCCESS;
	char strbuf[256] = {'\0'};
	va_list varg;
	va_start(varg, message);
	vsnprintf(strbuf, 256, message, varg);
	va_end(varg);

	printf("npu %s\r", strbuf);

	return error;
}

/*
@brief Print string to buffer.
@param, size, the size of msg.
@param msg, which message to be print.
*/
vip_status_e gckvip_os_snprint(
	vip_char_t *buffer,
	vip_uint32_t size,
	const vip_char_t *msg,
	...)
{
	vip_status_e error = VIP_SUCCESS;
	va_list varg;
	va_start(varg, msg);
	vsnprintf(buffer, size, msg, varg);
	va_end(varg);

	return error;
}

/*
@brief get the current system time.
*/
vip_uint64_t  gckvip_os_get_time(void)
{
	return (vip_uint64_t)xTaskGetTickCount();
}

/*
@brief Get process id
*/
vip_uint32_t gckvip_os_get_pid(void)
{
	return (vip_uint32_t)xTaskGetCurrentTaskHandle();
}

/*
@brief Memory barrier function for memory consistency.
*/
vip_status_e gckvip_os_memorybarrier(void)
{
	/* please make sure the memory barrier ASM can work well on you platform */
	__asm__ __volatile__("dsb sy":::"cc");

	return VIP_SUCCESS;
}

#if vpmdENABLE_FLUSH_CPU_CACHE
#include "hal_cache.h"
/*
@brief Flush CPU cache for video memory which allocated from heap.
@param physical, the physical address should be flush CPU cache.
@param logical, the logical address should be flush. loggical address only for Linux system. should be equal to physical address in RTOS?
@param size, the size of the memory should be flush.
@param type The type of operate cache. see gckvip_cache_type_e.
*/
vip_status_e gckvip_os_flush_cache(
	phy_address_t physical,
	void *logical,
	vip_uint32_t size,
	vip_uint8_t type
)
{
	/*
		GCKVIP_CACHE_FLUSH          = 1,
		GCKVIP_CACHE_CLEAN          = 2,
		GCKVIP_CACHE_INVALID        = 3,
		GCKVIP_CACHE_MAX            = 4,
	*/

	vip_status_e status = VIP_SUCCESS;

	/* please implement flush cpu cache function if video memory heap has enabled cache */
	//dcache_clean_by_addr((uint32_t *)logical, size);
	uint32_t data = (uint32_t)logical;
	uint32_t data_end = data + size;
	uint32_t b0_start = data & (~31);
	uint32_t b1_end = (data_end + 31) & (~31);

	switch (type) {
	case GCKVIP_CACHE_FLUSH:
		dcache_clean_invalidate_by_addr((uint32_t *)b0_start, b1_end - b0_start);
		break;
	case GCKVIP_CACHE_CLEAN:
		dcache_clean_by_addr((uint32_t *)b0_start, b1_end - b0_start);
		break;
	case GCKVIP_CACHE_INVALID:
		dcache_invalidate_by_addr((uint32_t *)b0_start, b1_end - b0_start);
		break;
	}


	return status;
}
#endif

int gckvip_in_interrupt(void)
{
#ifdef ARM_CORE_CA7
	return __get_mode() != CPSR_M_USR;
#else
#if defined(__ICCARM__)
	return (__get_PSR() & 0x1FF) != 0;
#elif defined(__GNUC__)
	return (__get_xPSR() & 0x1FF) != 0;
#endif
#endif
}

/*
@brief Create a mutex for multiple thread.
@param mutex, create mutex pointer.
*/
vip_status_e gckvip_os_create_mutex(
	vip_ptr *mutex
)
{
	*mutex = xSemaphoreCreateMutex();
	return VIP_SUCCESS;
}

vip_status_e gckvip_os_lock_mutex(
	vip_ptr mutex
)
{
	if (!gckvip_in_interrupt()) {
		xSemaphoreTake(mutex, 0xFFFFFFFF);
	}
	return VIP_SUCCESS;
}

vip_status_e gckvip_os_unlock_mutex(
	vip_ptr mutex
)
{
	if (!gckvip_in_interrupt()) {
		xSemaphoreGive(mutex);
	}
	return VIP_SUCCESS;
}

/*
@brief Destroy a mutex which create in gckvip_os_create_mutex..
@param mutex, create mutex pointer.
*/
vip_status_e gckvip_os_destroy_mutex(
	vip_ptr mutex
)
{
	vSemaphoreDelete(mutex);
	return VIP_SUCCESS;
}

/*
@brief Create a thread.
@param func, the thread handle function.
@param parm, parameter for this thread.
@param handle, the handle for thread.
*/
static int vip_task_count = 0;
vip_status_e gckvip_os_create_thread(
	vip_ptr func,
	vip_ptr parm,
	vip_ptr *handle
)
{
	char vip_task_name[16];
	sprintf(vip_task_name, "vip %x", vip_task_count++);
	xTaskCreate(func, vip_task_name, 2048, parm, tskIDLE_PRIORITY + 1, handle);
	return VIP_SUCCESS;
}

vip_status_e gckvip_os_destroy_thread(
	vip_ptr handle
)
{
	vTaskDelete(handle);
	return VIP_SUCCESS;
}

/*
@brief Create a signal.
@param handle, the handle for signal.
*/
vip_status_e gckvip_os_create_signal(
	vip_ptr *handle
)
{
	*handle = xEventGroupCreate();
	return VIP_SUCCESS;
}

vip_status_e gckvip_os_destroy_signal(
	vip_ptr handle
)
{
	vEventGroupDelete(handle);
	return VIP_SUCCESS;
}

/*
@brief Waiting for a signal.
@param handle, the handle for signal.
@param timeout, the timeout of waiting signal. unit ms.
*/
#include "event_groups.h"
#define BIT_ALL ( 0xffffffff )
#define BIT_0	( 1 << 0 )
#define BIT_1	( 1 << 1 )
vip_status_e gckvip_os_wait_signal(
	vip_ptr handle,
	vip_uint32_t timeout
)
{
	// only wait BIT_1, state = vip_true_e
	EventBits_t bit_state = xEventGroupGetBits(handle);
	if (bit_state & BIT_0) {
		xEventGroupClearBits(handle, BIT_0);

		bit_state = xEventGroupWaitBits(handle, BIT_1, pdTRUE, pdFALSE, timeout);

		if (bit_state != BIT_1) {
			return VIP_ERROR_TIMEOUT;
		}
	}

	return VIP_SUCCESS;
}

vip_status_e gckvip_os_set_signal(
	vip_ptr handle,
	vip_bool_e state
)
{
	EventBits_t bit_state;
	if (state == vip_false_e) {
		bit_state = BIT_0;
	} else {
		bit_state = BIT_1;
	}

	if (gckvip_in_interrupt()) {
		xEventGroupSetBitsFromISR(handle, bit_state, pdFALSE);
	} else {
		xEventGroupSetBits(handle, bit_state);
	}
	return VIP_SUCCESS;
}

#if vpmdPOWER_OFF_TIMEOUT

typedef struct freertos_timer_id_s {
	void (*timer_cb)(void *param);
	void *param;
} freertos_timer_id_t;

void freertos_timer_wrapper(TimerHandle_t  xTimer)
{
	freertos_timer_id_t *id = (freertos_timer_id_t *)pvTimerGetTimerID(xTimer);

	id->timer_cb(id->param);
}

vip_status_e gckvip_os_create_timer(
	vip_ptr func,
	vip_ptr param,
	vip_ptr *timer
)
{
	freertos_timer_id_t *id = malloc(sizeof(freertos_timer_id_t));
	if (!id)	{
		return VIP_ERROR_OUT_OF_MEMORY;
	}

	id->timer_cb = (void (*)(void *))func;
	id->param = param;

	TimerHandle_t tmr = xTimerCreate("viptmr", 600000, pdFALSE, (void *)id, (TimerCallbackFunction_t)freertos_timer_wrapper);
	*timer = (vip_ptr)tmr;
	return VIP_SUCCESS;
}

vip_status_e gckvip_os_start_timer(
	vip_ptr timer,
	vip_uint32_t time_out
)
{
	vip_status_e vip_ret = VIP_SUCCESS;
	BaseType_t  ret = xTimerChangePeriod((TimerHandle_t)timer, time_out, 10);

	if (ret == pdPASS) {
		ret = xTimerStart((TimerHandle_t)timer, 10);
	}

	if (ret == pdFAIL) {
		vip_ret = VIP_ERROR_TIMEOUT;
	}

	return vip_ret;
}

vip_status_e gckvip_os_stop_timer(
	vip_ptr timer
)
{
	vip_status_e vip_ret = VIP_SUCCESS;

	BaseType_t ret = xTimerStop((TimerHandle_t)timer, 10);
	if (ret == pdFAIL) {
		vip_ret = VIP_ERROR_TIMEOUT;
	}

	return vip_ret;
}

vip_status_e gckvip_os_destroy_timer(
	vip_ptr timer
)
{
	vip_status_e vip_ret = VIP_SUCCESS;

	freertos_timer_id_t *id = (freertos_timer_id_t *)pvTimerGetTimerID(timer);
	if (id) {
		free(id);
	}

	BaseType_t ret = xTimerDelete((TimerHandle_t)timer, 10);
	if (ret == pdFAIL) {
		vip_ret = VIP_ERROR_TIMEOUT;
	}

	return vip_ret;
}
#endif
