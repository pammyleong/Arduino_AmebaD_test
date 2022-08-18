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

#ifndef __GC_VIP_KERNEL_PORT_H__
#define __GC_VIP_KERNEL_PORT_H__

#include <vip_lite_common.h>
#include <gc_vip_common.h>


/* default wait signal timeout 100s */
#define WAIT_SIGNAL_TIMEOUT  (100*1000)

#define GCKVIPPTR_TO_UINT64(p) \
( \
    (vip_uint64_t) (unsigned int) (p)\
)

#define GCKVIPUINT64_TO_PTR(u) \
( \
    (vip_ptr) (unsigned int) (u)\
)

#define PRINTK(...)      gckvip_os_print(__VA_ARGS__);

#if (vpmdENABLE_DEBUG_LOG == 4)
#define PRINTK_D(...)    gckvip_os_print(__VA_ARGS__);
#define PRINTK_I(...)    gckvip_os_print(__VA_ARGS__);
#define PRINTK_W(...)    gckvip_os_print(__VA_ARGS__);
#define PRINTK_E(...)    gckvip_os_print(__VA_ARGS__);
#elif (vpmdENABLE_DEBUG_LOG == 3)
#define PRINTK_D(...)
#define PRINTK_I(...)    gckvip_os_print(__VA_ARGS__);
#define PRINTK_W(...)    gckvip_os_print(__VA_ARGS__);
#define PRINTK_E(...)    gckvip_os_print(__VA_ARGS__);
#elif (vpmdENABLE_DEBUG_LOG == 2)
#define PRINTK_D(...)
#define PRINTK_I(...)
#define PRINTK_W(...)    gckvip_os_print(__VA_ARGS__);
#define PRINTK_E(...)    gckvip_os_print(__VA_ARGS__);
#elif (vpmdENABLE_DEBUG_LOG == 1)
#define PRINTK_D(...)
#define PRINTK_I(...)
#define PRINTK_W(...)
#define PRINTK_E(...)    gckvip_os_print(__VA_ARGS__);
#else
#define PRINTK_D(...)
#define PRINTK_I(...)
#define PRINTK_W(...)
#define PRINTK_E(...)
#endif

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
);

/*
@brief Write a hardware register.
@param reg_base, the base address of hardware register.
@param address, write the register address.
@param data, the data of address be wrote.
*/
vip_status_e gckvip_os_write_reg(
	IN void *reg_base,
	IN vip_uint32_t address,
	IN vip_uint32_t data
);


/************************************************************************/
/************************************************************************/
/* *********************need to be ported functions**********************/
/************************************************************************/
/************************************************************************/
/*************************************************************************/
/*
@brief Allocate system memory in kernel space.
@param video_mem_size, the size of video memory heap.
@param size, Memory size to be allocated.
@param memory, Pointer to a variable that will hold the pointer to the memory.
*/
vip_status_e gckvip_os_allocate_memory(
	IN  vip_uint32_t size,
	OUT void **memory
);

/*
@brief Free system memory in kernel space.
@param memory, Memory to be freed.
*/
vip_status_e gckvip_os_free_memory(
	IN void *memory
);

/*
@brief Set memory to zero.
@param memory, Memory to be set to zero.
@param size, the size of memory.
*/
vip_status_e gckvip_os_zero_memory(
	IN void *memory,
	IN vip_uint32_t size
);

/*
@brief copy src memory to dst memory.
@param dst, Destination memory.
@param src. Source memory
@param size, the size of memory should be copy.
*/
vip_status_e gckvip_os_memcopy(
	OUT void *dst,
	IN const void *src,
	IN vip_uint32_t size
);

/*
@brief Waiting for the hardware interrupt
@param irq_queue, the wait queue of interrupt handle.
@param irq_flag, a flag for interrupt.
@param mask, mask data for interrupt.
*/
vip_status_e gckvip_os_wait_interrupt(
	IN void *irq_queue,
	IN volatile vip_uint32_t *volatile irq_flag,
	IN vip_uint32_t time_out,
	IN vip_uint32_t mask
);

/*
@brief Do some initialization works in KERNEL_OS layer.
@param video_mem_size, the size of video memory heap.
*/
vip_status_e gckvip_os_init(
	IN vip_uint32_t video_mem_size
);

/*
@brief Do some un-initialization works in KERNEL_OS layer.
*/
vip_status_e gckvip_os_close(void);

/*
@brief delay function.
@param ms, delay unit ms.
*/
void gckvip_os_delay(
	IN vip_uint32_t ms
);

/*
@brief Print string.
@param msg, which message to be print.
*/
vip_status_e gckvip_os_print(
	const char *message,
	...
);

/*
@brief Print string to buffer.
@param, size, the size of msg.
@param msg, which message to be print.
*/
vip_status_e gckvip_os_snprint(
	vip_char_t *buffer,
	vip_uint32_t size,
	const vip_char_t *msg,
	...);

/*
@brief get the current system time.
*/
vip_uint64_t gckvip_os_get_time(void);

/*
@brief Memory barrier function for memory consistency.
*/
vip_status_e gckvip_os_memorybarrier(void);

/*
@brief Get process id
*/
vip_uint32_t gckvip_os_get_pid(void);


#if vpmdENABLE_FLUSH_CPU_CACHE
/*
@brief Flush CPU cache for video memory which allocated from heap.
@param physical, the physical address should be flush CPU cache.
@param logical, the logical address should be flush.
@param size, the size of the memory should be flush.
@param type The type of operate cache. see gckvip_cache_type_e.
*/
vip_status_e gckvip_os_flush_cache(
	phy_address_t physical,
	void *logical,
	vip_uint32_t size,
	vip_uint8_t type
);
#endif

/*
@brief Create a mutex for multiple thread.
@param mutex, create mutex pointer.
*/
vip_status_e gckvip_os_create_mutex(
	vip_ptr *mutex
);

vip_status_e gckvip_os_lock_mutex(
	vip_ptr mutex
);

vip_status_e gckvip_os_unlock_mutex(
	vip_ptr mutex
);

/*
@brief Destroy a mutex which create in gckvip_os_create_mutex..
@param mutex, create mutex pointer.
*/
vip_status_e gckvip_os_destroy_mutex(
	vip_ptr mutex
);

/*
@brief Create a thread.
@param func, the thread handle function.
@param parm, parameter for this thread.
@param handle, the handle for thread.
*/
vip_status_e gckvip_os_create_thread(
	vip_ptr func,
	vip_ptr parm,
	vip_ptr *handle
);

/*
@brief Destroy a thread.
@param handle, the handle for thread.
*/
vip_status_e gckvip_os_destroy_thread(
	vip_ptr handle
);

/*
@brief Create a signal.
@param handle, the handle for signal.
*/
vip_status_e gckvip_os_create_signal(
	vip_ptr *handle
);

vip_status_e gckvip_os_destroy_signal(
	vip_ptr handle
);

/*
@brief Waiting for a signal.
@param handle, the handle for signal.
@param timeout, the timeout of waiting signal. unit ms.
*/
vip_status_e gckvip_os_wait_signal(
	vip_ptr handle,
	vip_uint32_t timeout
);

/*
@brief wake up wait signal.
     state is true, wake up waiting signal and chane the signal state to SET.
     state is false, change the signal to RESET so the gckvip_os_wait_signal will block until
     the signal state changed to SET. block waiting signal function.
@param handle, the handle for signal.
*/
vip_status_e gckvip_os_set_signal(
	vip_ptr handle,
	vip_bool_e state
);

#if vpmdPOWER_OFF_TIMEOUT
vip_status_e gckvip_os_create_timer(
	vip_ptr func,
	vip_ptr param,
	vip_ptr *timer
);

vip_status_e gckvip_os_start_timer(
	vip_ptr timer,
	vip_uint32_t time_out
);

vip_status_e gckvip_os_stop_timer(
	vip_ptr timer
);

vip_status_e gckvip_os_destroy_timer(
	vip_ptr timer
);
#endif

#endif /* __GC_VIP_KERNEL_PORT_H__ */
