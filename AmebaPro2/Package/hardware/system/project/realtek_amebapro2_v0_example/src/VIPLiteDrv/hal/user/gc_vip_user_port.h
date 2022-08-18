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


#ifndef __GC_VIP_USER_PORT_H__
#define __GC_VIP_USER_PORT_H__

#include <gc_vip_kernel.h>
#include <gc_vip_user.h>

#define GCVIPPTR_TO_UINT32(p) \
( \
    (vip_uint32_t) (gcvip_uintptr_t) (p)\
)

#define GCVIPUINT32_TO_PTR(u) \
( \
    (vip_ptr) (gcvip_uintptr_t) (u)\
)

#define GCVIPPTR_TO_UINT64(p) \
( \
    (vip_uint64_t) (gcvip_uintptr_t) (p)\
)

#define GCVIPUINT64_TO_PTR(u) \
( \
    (vip_ptr) (gcvip_uintptr_t) (u)\
)

#if defined(__ANDROID__)
#define PRINTF(...)     gcvip_os_print(__VA_ARGS__);
#else
#define PRINTF(...)     gcvip_os_print("[0x%x]%s[%d], ", gcvip_os_get_tid(), __FUNCTION__, __LINE__); \
                        gcvip_os_print(__VA_ARGS__);
#endif

#if (vpmdENABLE_DEBUG_LOG == 4)
#define gcvip_debug(...)    PRINTF(__VA_ARGS__)
#define gcvip_info(...)     PRINTF(__VA_ARGS__)
#define gcvip_warning(...)  PRINTF(__VA_ARGS__)
#define gcvip_error(...)    PRINTF(__VA_ARGS__)
#elif (vpmdENABLE_DEBUG_LOG == 3)
#define gcvip_debug(...)
#define gcvip_info(...)     PRINTF(__VA_ARGS__)
#define gcvip_warning(...)  PRINTF(__VA_ARGS__)
#define gcvip_error(...)    PRINTF(__VA_ARGS__)
#elif (vpmdENABLE_DEBUG_LOG == 2)
#define gcvip_debug(...)
#define gcvip_info(...)
#define gcvip_warning(...)  PRINTF(__VA_ARGS__)
#define gcvip_error(...)    PRINTF(__VA_ARGS__)
#elif (vpmdENABLE_DEBUG_LOG == 1)
#define gcvip_debug(...)
#define gcvip_info(...)
#define gcvip_warning(...)
#define gcvip_error(...)    PRINTF(__VA_ARGS__)
#else
#define gcvip_debug(...)
#define gcvip_info(...)
#define gcvip_warning(...)
#define gcvip_error(...)
#endif

#define CHECK_STATUS()  \
    if (status != VIP_SUCCESS) {    \
        gcvip_error("failed to check status=%d\n", status);    \
        gcGoOnError(status);  \
    }

/*
@brief initialize OS env.
@param mem_size, the size of video memory.
*/
vip_status_e gcvip_os_init(
	void **os,
	vip_uint32_t mem_size
);

/*
@brief uninitialize OS env.
@param os, os object.
*/
vip_status_e gcvip_os_uninit(
	void **os
);

/*
@brief open a file.
@param name, file name.
@param mode, opem mode.
*/
gcvip_file_t gcvip_os_open_file(
	vip_char_t *name,
	gcvip_file_mode_e mode
);

vip_status_e gcvip_os_read_file(
	void *dst,
	vip_uint32_t size,
	gcvip_file_t file
);

vip_status_e gcvip_os_write_file(
	void *data,
	vip_uint32_t size,
	gcvip_file_t file
);

/*
@brief seek file location.
*/
vip_status_e gcvip_os_seek_file(
	vip_int32_t offset,
	gcvip_file_seek_e pos,
	gcvip_file_t  file
);

void gcvip_os_close_file(
	gcvip_file_t file
);

/*
@brief allocate memory from system.
@param size, the size of memory.
@param memory, memory object.
*/
vip_status_e gcvip_os_allocate_memory(
	IN  vip_uint32_t Size,
	OUT void **memory
);

/*
@brief free memory.
@param memory, memory object.
*/
vip_status_e gcvip_os_free_memory(
	IN void *memory
);

vip_status_e gcvip_os_memcopy(
	IN void *dst,
	IN const void *src,
	IN vip_uint32_t size
);

vip_status_e gcvip_os_zero_memory(
	IN void *memory,
	IN vip_uint32_t size
);


/*
@brief call kernel space functions.
@param os, os object create in gcvip_os_init.
@param command, kenrel space command.
@param data, pass to kernel space function data or kernel space return data.
*/
vip_status_e gcvip_os_call_kernel(
	IN void *os,
	IN OUT gckvip_command_id_e command,
	IN OUT void *data
);

vip_status_e gcvip_os_print(
	IN const vip_char_t *message,
	...
);

vip_status_e gcvip_os_snprint(
	OUT vip_char_t *buffer,
	IN const vip_uint32_t size,
	IN  const vip_char_t *message,
	...
);

/*
@brief dump string into file.
@param os object, create in gcvip_os_init().
@param buffer, which memory should be dump.
*/
vip_status_e gcvip_os_print_string(
	IN void *os,
	IN void *stream,
	IN vip_char_t *buffer
);

/*
@brief create mutex.
@param mutex. mutex object
*/
vip_status_e gcvip_os_create_mutex(
	vip_ptr *mutex
);

vip_status_e gcvip_os_lock_mutex(
	vip_ptr mutex
);

vip_status_e gcvip_os_unlock_mutex(
	vip_ptr mutex
);

/*
@brief destroy mutex.
@param mutex. mutex object
*/
vip_status_e gcvip_os_destroy_mutex(
	vip_ptr mutex
);

/*
@brief compare two strings.
@param s1, string one.
@param s2, string two.
*/
vip_int32_t gcvip_os_strcmp(
	vip_char_t *s1,
	vip_char_t *s2
);

/*
@brief copy string src to dest.
@param dest, destation buffer.
@param src, resource buffer.
*/
vip_char_t *gcvip_os_strcpy(
	vip_char_t *dest,
	vip_char_t *src
);

/*
@brief get the current system time.
*/
vip_uint64_t gcvip_os_get_time(void);

/*
@brief get process id.
*/
vip_uint32_t gcvip_os_get_pid(void);

/*
@brief get thread id.
*/
vip_uint32_t gcvip_os_get_tid(void);

/*
@brief get flash base address which store NBG location in flash, you should port this funciton in your platform.
       We don't have an actual flash on our testing platform, so we allocate a video memory instead of it.

@param os, os object create in gcvip_os_init.
@param size, the size of NBG. the size can be modified according to the size of NBG in flash.
@param logical, the logical address of NBG in flash location.
@param physical, the physical address of NBG in flash logcation.
*/
#if vpmdCREATE_NETWORK_FROM_FLASH
vip_status_e gcvip_os_get_flashaddress(
	void *os,
	vip_uint32_t *size,
	vip_uint8_t **logical,
	vip_uint32_t *physical
);
#endif

#endif /* __GC_VIP_USER_OS_H__ */
