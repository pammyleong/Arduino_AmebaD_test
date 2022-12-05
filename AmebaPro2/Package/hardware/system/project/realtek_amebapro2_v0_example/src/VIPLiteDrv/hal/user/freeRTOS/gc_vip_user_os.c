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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <gc_vip_user_port.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#define malloc      pvPortMalloc
#define free        vPortFree

/*
@brief initialize OS env.
@param mem_size, the size of video memory.
*/
vip_status_e gcvip_os_init(
	void **os,
	vip_uint32_t mem_size
)
{
	return VIP_SUCCESS;
}

/*
@brief uninitialize OS env.
@param os, os object.
*/
vip_status_e gcvip_os_uninit(
	void **os
)
{
	return VIP_SUCCESS;
}

/*
@brief allocate memory from system.
@param size, the size of memory.
@param memory, memory object.
*/
vip_status_e gcvip_os_allocate_memory(
	IN  vip_uint32_t size,
	OUT void **memory
)
{
	void *allco_memory = VIP_NULL;

	if (size == 0 || !memory) {
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	allco_memory = malloc(size);
	if (!allco_memory) {
		return VIP_ERROR_OUT_OF_MEMORY;
	}

	*memory = allco_memory;

	return VIP_SUCCESS;
}

/*
@brief free memory.
@param memory, memory object.
*/
vip_status_e gcvip_os_free_memory(
	IN void *memory
)
{
	if (!memory) {
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	free(memory);

	return VIP_SUCCESS;
}

vip_status_e gcvip_os_memcopy(
	IN void *dst,
	IN const void *src,
	IN vip_uint32_t size
)
{
	if (!dst || !src || size == 0) {
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	memcpy(dst, src, size);

	return VIP_SUCCESS;
}

vip_status_e gcvip_os_zero_memory(
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
@brief call 'kernel space' functions entry. kernel spce is only for Linux system. freeRTOS is no kernel space concept.
       so, this function is entry for 'kernel function'.
@param os, os object create in gcvip_os_init.
@param command, kenrel space command.
@param data, pass to kernel space function data or kernel space return data.
*/
vip_status_e gcvip_os_call_kernel(
	IN void *os,
	IN OUT gckvip_command_id_e command,
	IN OUT void *data
)
{
	return gckvip_kernel_call(command, data);
}

vip_status_e gcvip_os_print(
	IN const vip_char_t *message,
	...
)
{
	vip_status_e error = VIP_SUCCESS;
	char strbuf[256] = {'\0'};
	va_list varg;
	va_start(varg, message);
	vsnprintf(strbuf, 256, message, varg);
	va_end(varg);

	printf("%s\r", strbuf);

	return error;
}

vip_status_e gcvip_os_snprint(
	OUT vip_char_t *buffer,
	IN const vip_uint32_t size,
	IN const vip_char_t *message,
	...
)
{
	vip_status_e error = VIP_SUCCESS;
	va_list arg;
	va_start(arg, message);
	vsnprintf(buffer, size, message, arg);
	va_end(arg);

	return error;
}

/*
@brief open a file.
@param name, file name.
@param mode, opem mode.
*/
#include "nn_file_op.h"
gcvip_file_t gcvip_os_open_file(
	vip_char_t *name,
	gcvip_file_mode_e mode
)
{
	// TODO : integarte FWFS to VFS
	return (gcvip_file_t *)nn_f_open(name, mode);
	//return (gcvip_file_t *)NULL;
}

vip_status_e gcvip_os_read_file(
	void *dst,
	vip_uint32_t size,
	gcvip_file_t file
)
{
	vip_status_e status = VIP_SUCCESS;

	nn_f_read((void *)file, dst, size);

	return status;
}

vip_status_e gcvip_os_write_file(
	void *data,
	vip_uint32_t size,
	gcvip_file_t file
)
{
	vip_status_e status = VIP_SUCCESS;
	// not implement
	return status;
}

void gcvip_os_close_file(
	gcvip_file_t file
)
{
	nn_f_close((void *)file);
}

/*
typedef enum _gcvip_file_seek {
	GCVIP_FILE_CUR = 0,
	GCVIP_FILE_SET,
	GCVIP_FILE_END
} gcvip_file_seek_e;
*/
/*
@brief seek file location.
*/
vip_status_e gcvip_os_seek_file(
	vip_int32_t offset,
	gcvip_file_seek_e pos,
	gcvip_file_t file
)
{
	int os_pos_map[] = {SEEK_CUR, SEEK_SET, SEEK_END};

	vip_status_e status = VIP_SUCCESS;
	nn_f_seek((void *)file, offset, os_pos_map[pos]);

	return status;
}

/*
@brief get process id.
*/
vip_uint32_t gcvip_os_get_pid(void)
{
	vip_uint32_t pid = (vip_uint32_t)xTaskGetCurrentTaskHandle();
	/* need implement it */
	return pid;
}

/*
@brief get thread id.
*/
vip_uint32_t gcvip_os_get_tid(void)
{
	vip_uint32_t tid = (vip_uint32_t)xTaskGetCurrentTaskHandle();
	/* need implement it */
	return tid;
}

/*
@brief dump string into file.
@param os object, create in gcvip_os_init() if user os lyaer neccessary this.
@param buffer, which memory should be dump.
*/
vip_status_e gcvip_os_print_string(
	IN void *os,
	IN void *stream,
	IN vip_char_t *buffer
)
{
	/* without file system in freeRTOS, so print to screen */
	gcvip_os_print(buffer);

	return VIP_SUCCESS;
}

#if vpmdENABLE_MULTIPLE_TASK
/*
@brief create mutex.
@param mutex. mutex object
*/
vip_status_e gcvip_os_create_mutex(
	vip_ptr *mutex
)
{
	*mutex = xSemaphoreCreateMutex();
	return VIP_SUCCESS;
}

vip_status_e gcvip_os_lock_mutex(
	vip_ptr mutex
)
{
	xSemaphoreTake(mutex, 0xFFFFFFFF);
	return VIP_SUCCESS;
}

vip_status_e gcvip_os_unlock_mutex(
	vip_ptr mutex
)
{
	xSemaphoreGive(mutex);
	return VIP_SUCCESS;
}

/*
@brief destroy mutex.
@param mutex. mutex object
*/
vip_status_e gcvip_os_destroy_mutex(
	vip_ptr mutex
)
{
	if (mutex != NULL) {
		vSemaphoreDelete(mutex);
	}
	return VIP_SUCCESS;
}
#endif

/*
@brief get flash base address which store NBG location in flash, you should port this funciton in your platform.
@param os, os object create in gcvip_os_init.
@param size, the size of NBG. the size can be modified according to the size of NBG in flash.
@param logical, the logical address of NBG in flash location. (only for Linux)
@param physical, the physical address of NBG in flash logcation.
*/
#if vpmdCREATE_NETWORK_FROM_FLASH
vip_status_e gcvip_os_get_flashaddress(
	void *os,
	vip_uint32_t *size,
	vip_uint8_t **logical,
	vip_uint32_t *physical
)
{
	vip_status_e error = VIP_SUCCESS;

	while (1);

	return error;
}
#endif

/*
@brief get the current system time.
*/
vip_uint64_t gcvip_os_get_time(void)
{
	vip_uint64_t time = (vip_uint64_t)xTaskGetTickCount();
	return time;
}

/*
@brief compare two strings.
@param s1, string one.
@param s2, string two.
*/
vip_int32_t gcvip_os_strcmp(
	vip_char_t *s1,
	vip_char_t *s2
)
{
	return strcmp(s1, s2);
}

/*
@brief copy string src to dest.
@param dest, destation buffer.
@param src, resource buffer.
*/
vip_char_t *gcvip_os_strcpy(
	vip_char_t *dest,
	vip_char_t *src
)
{
	vip_char_t *r = dest;

	if ((VIP_NULL == dest) || (VIP_NULL == src)) {
		gcvip_error("failed to strcpy, parameter is NULL\n");
		return VIP_NULL;
	}

	/* without strcpy() function in freeRTOS */
	while ((*r++ = *src++) != '\0');

	return dest;
}
