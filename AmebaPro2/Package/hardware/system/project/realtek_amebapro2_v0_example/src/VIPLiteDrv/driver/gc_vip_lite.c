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

#include <gc_vip_lite.h>
#include <gc_vip_lite_network.h>
#include <gc_vip_lite_debug.h>
#include <gc_vip_platform_config.h>
#include <gc_vip_user.h>
#include <gc_vip_hardware.h>
#include <vip_lite.h>


#if vpmdENABLE_SECURE
#define GCVIP_NETWORK_SET_WORK_MODE()  \
    status = gcvip_user_set_workmode(network->work_mode);   \
    if (status != VIP_SUCCESS) {    \
        gcvip_error("failed to set work mode=%s\n", \
                   (network->work_mode == GCKVIP_WORK_MODE_NORMAL) ? "Normal" : "Secure"); \
        return VIP_ERROR_NETWORK_INCOMPATIBLE;  \
    }
#define GCVIP_BUFFER_SET_WORK_MODE(memory_type)    \
    if (memory_type & VIP_BUFFER_MEMORY_TYPE_SECURE) {    \
        status = gcvip_user_set_workmode(GCKVIP_WORK_MODE_SECURITY);  \
    }   \
    else {  \
        status = gcvip_user_set_workmode(GCKVIP_WORK_MODE_NORMAL);    \
    }   \
    if (status != VIP_SUCCESS) {    \
        gcvip_error("failed to set work mode, memory_type=0x%x\n", memory_type);  \
        return VIP_ERROR_IO; \
    }
#define GCVIP_CHECK_WORK_MODE(memory_type)  \
do {    \
    vip_uint8_t flag = vip_true_e;  \
    if ((memory_type & VIP_BUFFER_MEMORY_TYPE_SECURE) &&    \
        (network->work_mode != GCKVIP_WORK_MODE_SECURITY)) {    \
            flag = vip_false_e; \
    }   \
    if ((GCKVIP_WORK_MODE_SECURITY == network->work_mode) && \
        ((memory_type & VIP_BUFFER_MEMORY_TYPE_SECURE) != VIP_BUFFER_MEMORY_TYPE_SECURE)) {\
            flag = vip_false_e; \
    }   \
    if (vip_false_e == flag) {  \
        gcvip_error("failed check work mode, buffer work mode=%s, network mode=%s\n",   \
                   (memory_type & VIP_BUFFER_MEMORY_TYPE_SECURE) ? "Secure" : "Normal", \
                   (GCKVIP_WORK_MODE_SECURITY == network->work_mode) ? "Secure" : "Normal");\
        return VIP_ERROR_INVALID_ARGUMENTS; \
    }   \
} while(0);
#else
#define GCVIP_NETWORK_SET_WORK_MODE()
#define GCVIP_BUFFER_SET_WORK_MODE(memory_type)
#define GCVIP_CHECK_WORK_MODE(memory_type)
#endif

/***** API implementations. *****/

/*
@ brief Get viplite driver version.
*/
VIP_API
vip_uint32_t vip_get_version(void)
{
	vip_uint32_t version = (VERSION_MAJOR << 16) | (VERSION_MINOR << 8) | (VERSION_SUB_MINOR);
	return version;
}

/*
@ brief Init vip lite engine.
*/
VIP_API
vip_status_e vip_init(void)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t sys_mem_size = SYSTEM_MEMORY_HEAP_SIZE;
	vip_uint32_t video_mem_size = VIDEO_MEMORY_HEAP_SIZE;

	status = gcvip_init(sys_mem_size, video_mem_size);

	return status;
}

/*
@ brief Destroy vip lite engine.
*/
VIP_API
vip_status_e vip_destroy(void)
{
	vip_status_e status = VIP_SUCCESS;

	status = gcvip_destroy();

	return status;
}

/*
@brief Create a buffer used by the network's input and output.
       CPU's cache will be flush in gcvip_set_input/output function.
@param create_param The parametes of buffer be created.
@param size_of_param The size of create paramters.
@param buffer The returns buffer object.
*/
VIP_API
vip_status_e vip_create_buffer(
	IN vip_buffer_create_params_t *create_param,
	IN vip_uint32_t size_of_param,
	OUT vip_buffer *buffer
)
{
	vip_uint32_t buf_size = 0;
	vip_buffer_t *buff = VIP_NULL;
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0;
	/* After NBG format 0x0001000B version, network's input/output support up to 6 dimenisons.
	   We to do this defines for forward compatibility application*/
	typedef struct _vip_buffer_create_params_old_t {
		vip_uint32_t   num_of_dims;
		vip_int32_t    sizes[4];
		vip_int32_t    channels;
		vip_enum       data_format;
		vip_enum       quant_format;
		union {
			struct {
				vip_uint8_t fixed_point_pos;
			} dfp;

			struct {
				vip_float_t        scale;
				vip_int32_t        zeroPoint;
			} affine;
		}
		quant_data;
	} vip_buffer_create_params_old_t;

	if (VIP_NULL == create_param) {
		gcvip_error("create param is NULL.\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	if (VIP_NULL == buffer) {
		gcvip_error("buffer is NULL.\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	GCVIP_BUFFER_SET_WORK_MODE(create_param->memory_type);

	/* Allocate memory. */
	status = gcvip_user_allocate_memory(sizeof(vip_buffer_t), (void **)&buff);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to allocate memory for buffer.\n");
		*buffer = VIP_NULL;
		return VIP_ERROR_OUT_OF_MEMORY;
	}

	/* change the vip_buffer_create_params_t defines after NBG format 0x0001000B version */
	if (size_of_param == sizeof(vip_buffer_create_params_old_t)) {
		vip_buffer_create_params_old_t *param = (vip_buffer_create_params_old_t *)create_param;
		buff->param.num_of_dims = param->num_of_dims;
		buff->param.data_format = param->data_format;
		buff->param.quant_format = param->quant_format;
		for (i = 0; i < param->num_of_dims; i++) {
			buff->param.sizes[i] = param->sizes[i];
		}
		if (VIP_BUFFER_QUANTIZE_DYNAMIC_FIXED_POINT == param->quant_format) {
			buff->param.quant_data.dfp.fixed_point_pos = param->quant_data.dfp.fixed_point_pos;
		} else if (VIP_BUFFER_QUANTIZE_TF_ASYMM == param->quant_format) {
			buff->param.quant_data.affine.scale = param->quant_data.affine.scale;
			buff->param.quant_data.affine.zeroPoint = param->quant_data.affine.zeroPoint;
		}
	} else {
		buff->param.num_of_dims = create_param->num_of_dims;
		buff->param.data_format = create_param->data_format;
		buff->param.quant_format = create_param->quant_format;
		for (i = 0; i < create_param->num_of_dims; i++) {
			buff->param.sizes[i] = create_param->sizes[i];
		}
		for (i = create_param->num_of_dims; i < MAX_NUM_DIMS; i++) {
			buff->param.sizes[i] = 1;
		}
		if (VIP_BUFFER_QUANTIZE_DYNAMIC_FIXED_POINT == create_param->quant_format) {
			buff->param.quant_data.dfp.fixed_point_pos = create_param->quant_data.dfp.fixed_point_pos;
		} else if (VIP_BUFFER_QUANTIZE_TF_ASYMM == create_param->quant_format) {
			buff->param.quant_data.affine.scale = create_param->quant_data.affine.scale;
			buff->param.quant_data.affine.zeroPoint = create_param->quant_data.affine.zeroPoint;
		}
	}

	buf_size = gcvip_get_format_size(create_param->data_format);
	for (i = 0; i < create_param->num_of_dims; i++) {
		buf_size *= create_param->sizes[i];
	}

	if ((0 == create_param->num_of_dims) || (0 == buf_size)) {
		gcvip_error("failed to create buffer, dim_num=%d, shape[%d, %d, %d, %d] \n",
					create_param->num_of_dims, create_param->sizes[0], create_param->sizes[1],
					create_param->sizes[2], create_param->sizes[3]);
		gcvip_error("fail to create buffer, param is invalid\n");
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	status = gcvip_user_allocate_videomemory((vip_uint8_t **)&buff->memory.logical,
			 &buff->memory.handle, &buff->memory.physical,
			 buf_size, gcdVIP_MEMORY_ALIGN_SIZE);
	if (status == VIP_SUCCESS) {
		*buffer = buff;
		buff->param.memory_type = create_param->memory_type;
		buff->allocated = GCVIP_BUFFER_ALLOCATE_FROM_INTERNAL;
		buff->memory.size = buf_size;
		buff->object.type = GCVIP_OBJ_BUFFER;
	} else {
		gcvip_error("fail to create buffer, alloc video memory fail\n");
		gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
	}

	gcvip_user_zero_memory(buff->memory.logical, buf_size);

	gcvip_debug("dim_num=%d, dims[%d,%d,%d,%d], logical=%p, phyical=0x%08x, handle=%p, size=0x%x\n",
				create_param->num_of_dims, create_param->sizes[0], create_param->sizes[1],
				create_param->sizes[2], create_param->sizes[3], buff->memory.logical,
				buff->memory.physical, buff->memory.handle, buf_size);

	return status;
onError:
	gcvip_error("fail to create vip buffer\n");
	if (buff != VIP_NULL) {
		gcvip_user_free_memory(buff);
		*buffer = VIP_NULL;
	}
	return status;
}

/*
@brief create a buffer from user contiguous or scatter non-contiguous physical address.
@param create_param The parametes of buffer be created.
@param physical_table Physical address table. should be wraped for VIP hardware.
@param size_table The size of physical memory for each physical_table element.
@param physical_num The number of physical table element.
       physical_num is 1 when create buffer from contiguous phyiscal.
@param buffer vip lite buffer object.
*/
VIP_API
vip_status_e vip_create_buffer_from_physical(
	IN vip_buffer_create_params_t *create_param,
	IN vip_address_t *physical_table,
	IN vip_uint32_t *size_table,
	IN vip_uint32_t physical_num,
	OUT vip_buffer *buffer
)
{
	vip_uint32_t buf_size = 0;
	vip_uint32_t total_size = 0;
	vip_buffer_t *buff = VIP_NULL;
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0;
	vip_uint32_t physical = 0;
	void *handle = VIP_NULL;

	if ((VIP_NULL == create_param) || (VIP_NULL == buffer) ||
		(VIP_NULL == physical_table) || (VIP_NULL == size_table)) {
		gcvip_error("failed to create buffer from physical, parameter is NULL\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	GCVIP_BUFFER_SET_WORK_MODE(create_param->memory_type);

	/* check buffer size */
	for (i = 0; i < physical_num; i++) {
		total_size += size_table[i];
	}

	buf_size = gcvip_get_format_size(create_param->data_format);
	for (i = 0; i < create_param->num_of_dims; i++) {
		buf_size *= create_param->sizes[i];
	}

	if (buf_size > total_size) {
		gcvip_error("failed to create buffer. buffer size is bigger than physical total size."
					"0x%x > 0x%x, shape [",
					buf_size, total_size);
		gcvip_os_print("data format=%d ", create_param->data_format);
		for (i = 0; i < create_param->num_of_dims; i++) {
			gcvip_os_print("%d ", create_param->sizes[i]);
		}
		gcvip_os_print("]\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	if ((0 == create_param->num_of_dims) || (0 == buf_size)) {
		gcvip_error("failed to create buffer, dim_num=%d, shape[%d, %d, %d, %d] \n",
					create_param->num_of_dims, create_param->sizes[0], create_param->sizes[1],
					create_param->sizes[2], create_param->sizes[3]);
		gcvip_error("fail to create buffer, param is invalid\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	status = gcvip_user_allocate_memory(sizeof(vip_buffer_t), (void **)&buff);
	if (VIP_NULL == buff) {
		gcvip_error("failed to allocate memory for buffer.\n");
		*buffer = VIP_NULL;
		return VIP_ERROR_OUT_OF_MEMORY;
	}

	buff->param.num_of_dims = create_param->num_of_dims;
	buff->param.data_format = create_param->data_format;
	buff->param.quant_format = create_param->quant_format;
	buff->param.memory_type = create_param->memory_type;
	for (i = 0; i < create_param->num_of_dims; i++) {
		buff->param.sizes[i] = create_param->sizes[i];
	}
	for (i = create_param->num_of_dims; i < MAX_NUM_DIMS; i++) {
		buff->param.sizes[i] = 1;
	}
	if (VIP_BUFFER_QUANTIZE_DYNAMIC_FIXED_POINT == create_param->quant_format) {
		buff->param.quant_data.dfp.fixed_point_pos = create_param->quant_data.dfp.fixed_point_pos;
	} else if (VIP_BUFFER_QUANTIZE_TF_ASYMM == create_param->quant_format) {
		buff->param.quant_data.affine.scale = create_param->quant_data.affine.scale;
		buff->param.quant_data.affine.zeroPoint = create_param->quant_data.affine.zeroPoint;
	}

#if vpmdENABLE_MMU
	if (0 == physical_num) {
		gcvip_error("failed to create buffer from physical, physical number=%d\n", physical_num);
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}
	status = gcvip_user_wrap_userphysical(physical_table, size_table, physical_num,
										  create_param->memory_type, &physical, &handle);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to create buffer from physical. physical_num=%d\n", physical_num);
		gcGoOnError(VIP_ERROR_FAILURE);
	}
#else
	if (physical_num != 1) {
		gcvip_error("failed to create buffer from physical mmu is disabled, physical number=%d\n",
					physical_num);
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}
	if (physical_table[0] > 0xFFFFFFFF) {
		gcvip_error("failed to create buffer from physical mmu is disabled, physical address=0x%lx\n",
					physical_table[0]);
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}
	physical = (vip_uint32_t)physical_table[0];
#endif

	/*
	   MMU enabled, physical is CPU physical address.
	   MMU disabled, physica is VIP virtual address.
	*/
	buff->memory.physical = physical;
	buff->memory.logical = VIP_NULL;
	buff->memory.size = total_size;
	buff->memory.handle = handle;
	buff->allocated = GCVIP_BUFFER_ALLOCATE_FROM_USER_PHYSICAL;
	buff->object.type = GCVIP_OBJ_BUFFER;
	*buffer = buff;

	gcvip_debug("from physical[0]=0x%" PRIx64", physical_num=%d, phyical(vip virtual)=0x%08x, "
				"handle=%p, total_size=0x%x\n",
				physical_table[0], physical_num, buff->memory.physical, buff->memory.handle, total_size);

	return status;

onError:
	gcvip_error("fail to create vip buffer for physical\n");
	if (buff != VIP_NULL) {
		gcvip_user_free_memory(buff);
	}
	return status;
}

/*
@brief create a buffer from handle.
@param create_param The parametes of buffer be created.
@param handle_logical The logical address of the handle.
       create vip buffer from the logical address.
@param the handle_size should be aligned to 64byte for easy flash CPU cache.
@param buffer vip lite buffer object.
*/
VIP_API
vip_status_e vip_create_buffer_from_handle(
	IN vip_buffer_create_params_t *create_param,
	IN vip_ptr handle_logical,
	IN vip_uint32_t handle_size,
	OUT vip_buffer *buffer
)
{
	vip_status_e status = VIP_SUCCESS;
#if vpmdENABLE_MMU
	vip_uint32_t buf_size = 0;
	vip_buffer_t *buff = VIP_NULL;
	vip_uint32_t i = 0;
	vip_uint32_t physical = 0;
	void *handle = VIP_NULL;

	if ((VIP_NULL == create_param) || (VIP_NULL == buffer) || (VIP_NULL == handle_logical)) {
		gcvip_error("failed to create buffer from handle, parameter is NULL,"
					"param=%p, buffer=%p, logical=%p\n",
					create_param, buffer, handle_logical);
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	GCVIP_BUFFER_SET_WORK_MODE(create_param->memory_type);

	buf_size = gcvip_get_format_size(create_param->data_format);
	for (i = 0; i < create_param->num_of_dims; i++) {
		buf_size *= create_param->sizes[i];
	}

	if (buf_size > handle_size) {
		gcvip_error("failed to create buffer. buffer size is bigger than handle size."
					"0x%x > 0x%x, shape [",
					buf_size, handle_size);
		gcvip_os_print("data format=%d ", create_param->data_format);
		for (i = 0; i < create_param->num_of_dims; i++) {
			gcvip_os_print("%d ", create_param->sizes[i]);
		}
		gcvip_os_print("]\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	} else {
		vip_uint32_t tmp = GCVIP_ALIGN(buf_size, 64); /* the cache line is 64 bytes? aligned */
		if (tmp >= handle_size) {
			buf_size = tmp;
		}
	}

	if ((0 == create_param->num_of_dims) || (0 == buf_size)) {
		gcvip_error("failed to create buffer, dim_num=%d, shape[%d, %d, %d, %d] \n",
					create_param->num_of_dims, create_param->sizes[0], create_param->sizes[1],
					create_param->sizes[2], create_param->sizes[3]);
		gcvip_error("fail to create buffer, param is invalid\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	status = gcvip_user_allocate_memory(sizeof(vip_buffer_t), (void **)&buff);
	if (VIP_NULL == buff) {
		gcvip_error("failed to allocate memory for buffer.\n");
		*buffer = VIP_NULL;
		return VIP_ERROR_OUT_OF_MEMORY;
	}

	buff->param.num_of_dims = create_param->num_of_dims;
	buff->param.data_format = create_param->data_format;
	buff->param.quant_format = create_param->quant_format;
	buff->param.memory_type = create_param->memory_type;
	for (i = 0; i < create_param->num_of_dims; i++) {
		buff->param.sizes[i] = create_param->sizes[i];
	}
	for (i = create_param->num_of_dims; i < MAX_NUM_DIMS; i++) {
		buff->param.sizes[i] = 1;
	}
	if (VIP_BUFFER_QUANTIZE_DYNAMIC_FIXED_POINT == create_param->quant_format) {
		buff->param.quant_data.dfp.fixed_point_pos = create_param->quant_data.dfp.fixed_point_pos;
	} else if (VIP_BUFFER_QUANTIZE_TF_ASYMM == create_param->quant_format) {
		buff->param.quant_data.affine.scale = create_param->quant_data.affine.scale;
		buff->param.quant_data.affine.zeroPoint = create_param->quant_data.affine.zeroPoint;
	}

	status = gcvip_user_wrap_usermemory(handle_logical, handle_size, create_param->memory_type,
										&physical, &handle);
	if (status != VIP_SUCCESS) {
		/* failed to wrap user memory, and allocate a video memory for it */
		gcvip_error("failed to create buffer from handle=%p, size=0x%xbytes\n",
					handle_logical, handle_size);
		gcGoOnError(status);
	}

	buff->memory.physical = physical;
	buff->memory.logical = (vip_uint8_t *)handle_logical;
	buff->memory.size = handle_size;
	buff->memory.handle = handle;
	buff->allocated = GCVIP_BUFFER_ALLOCATE_FROM_USER_MEMORY;
	buff->object.type = GCVIP_OBJ_BUFFER;
	*buffer = buff;

	gcvip_debug("logical=%p, phyical=0x%08x, handle=%p, size=0x%x\n", buff->memory.logical,
				buff->memory.physical, buff->memory.handle, handle_size);

	return status;

onError:
	gcvip_error("fail to create vip buffer for handle\n");
	if (buff != VIP_NULL) {
		gcvip_user_free_memory(buff);
	}
#else
	gcvip_error("failed to create buffer from memory, NOT support. Please enable MMU first\n");
	status = VIP_ERROR_FAILURE;
#endif

	return status;
}

/*
@brief destroy viplite buffer object.
@param buffer vip_buffer object.
*/
VIP_API
vip_status_e vip_destroy_buffer(
	IN vip_buffer buffer
)
{
	vip_status_e status = VIP_SUCCESS;

	if (VIP_NULL == buffer) {
		gcvip_error("failed to destroy buffer, buffer is NULL\n");
		return VIP_ERROR_IO;
	}

	GCVIP_BUFFER_SET_WORK_MODE(buffer->param.memory_type);

	if (GCVIP_BUFFER_ALLOCATE_FROM_INTERNAL == buffer->allocated) {
		status = gcvip_user_free_videomemory(buffer->memory.handle);
		if (status != VIP_SUCCESS) {
			gcvip_error("failed to free video memory\n");
			return VIP_ERROR_IO;
		}
	}

#if vpmdENABLE_MMU
	else if (GCVIP_BUFFER_ALLOCATE_FROM_USER_MEMORY == buffer->allocated) {
		gcvip_user_unwrap_usermemory(buffer->memory.handle, buffer->memory.physical);
	} else if (GCVIP_BUFFER_ALLOCATE_FROM_USER_PHYSICAL == buffer->allocated) {
		gcvip_user_unwrap_userphysical(buffer->memory.handle, buffer->memory.physical);
	}
#endif

	if (GCVIP_BUFFER_ALLOCATE_NONE != buffer->allocated) {
		status = gcvip_user_free_memory(buffer);
		if (status != VIP_SUCCESS) {
			gcvip_error("failed to free buffer memory\n");
			return VIP_ERROR_IO;
		}
	}

	return status;
}

/*
@brief get the logical address of buffer.
@param buffer vip_buffer object.
*/
VIP_API
void *vip_map_buffer(
	IN vip_buffer buffer
)
{
	if (buffer != VIP_NULL) {
		return buffer->memory.logical;
	} else {
		gcvip_error("error, buffer is NULL\n");
		return VIP_NULL;
	}
}

/*
@brief unmap buffer, NOT use.
@param buffer vip_buffer object.
*/
VIP_API
vip_status_e vip_unmap_buffer(
	IN vip_buffer buffer
)
{
	gcvip_debug("unmap buffer=%p\n", buffer);
	return VIP_SUCCESS;
}

/*
@brief get the size of buffer.
@param buffer vip_buffer object.
*/
VIP_API
vip_uint32_t vip_get_buffer_size(
	IN vip_buffer buffer
)
{
	if (buffer != VIP_NULL) {
		return buffer->memory.size;
	} else {
		gcvip_error("error, buffer is NULL\n");
		return 0;
	}
}

/*
@brief Operate the vip buffer CPU cache. flush, invalidate cache.
       You should call vip_flush_buffer API to flush buffer cache for input.
       and invalidate buffer for network's output if these memories with CPU cache.
@param buffer The vip buffer object.
@param type The type of this operation. see vip_buffer_operation_type_e.
*/
VIP_API
vip_status_e vip_flush_buffer(
	IN vip_buffer buffer,
	IN vip_buffer_operation_type_e type
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_videomemory_t *memory = VIP_NULL;

	if (VIP_NULL == buffer) {
		gcvip_error("failed to flush vip buffer, buffer is NULL\n");
		return VIP_ERROR_FAILURE;
	}
	GCVIP_BUFFER_SET_WORK_MODE(buffer->param.memory_type);

	if ((buffer->allocated <= GCVIP_BUFFER_ALLOCATE_NONE) ||
		(buffer->allocated >= GCVIP_BUFFER_ALLOCATE_MAX)) {
		gcvip_error("failed to flush vip buffer, buffer doesn't allocated\n");
		return VIP_ERROR_FAILURE;
	}

	memory = &buffer->memory;

	gcvip_debug("flush buffer logical=%p, physical=0x%08x, size=0x%x, handle=%p, type=%s\n",
				memory->logical, memory->physical, memory->size, memory->handle,
				(type == VIP_BUFFER_OPER_TYPE_FLUSH) ? "FLUSH" : "INVALIDATE");

	switch (type) {
	case VIP_BUFFER_OPER_TYPE_FLUSH: {
		status = gcvip_user_flush_cache(memory->handle,
										memory->physical,
										memory->logical,
										memory->size,
										GCKVIP_CACHE_FLUSH);
	}
	break;

	case VIP_BUFFER_OPER_TYPE_INVALIDATE: {
		status = gcvip_user_flush_cache(memory->handle,
										memory->physical,
										memory->logical,
										memory->size,
										GCKVIP_CACHE_INVALID);
	}
	break;

	default:
		gcvip_error("flush buffer cache not supports this type=%d\n", type);
		status = VIP_ERROR_FAILURE;
		break;
	}

	return status;
}

/*
@brief  Create a network object from the given binary data.
@param  data, NBG file path or the buffer of NBG. different data according to type.
@param  size_of_data, the bytes size of data. the byte size of NBG buffer.
@param  type, vip_create_network_type_e.
@param  network, return network object which created by NBG.
*/
VIP_API
vip_status_e vip_create_network(
	IN void *data,
	IN vip_uint32_t size_of_data,
	IN vip_enum type,
	OUT vip_network *network
)
{
	vip_network nw = VIP_NULL;
	vip_status_e status = VIP_SUCCESS;

	if (VIP_NULL == data) {
		gcvip_error("network data is NULL\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	status = gcvip_user_allocate_memory(sizeof(vip_network_t), (void **)&nw);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to allocate memory for network object\n");
		return status;
	}
	gcvip_user_zero_memory(nw, sizeof(vip_network_t));
	nw->object.type = GCVIP_OBJ_NETWORK;

#if vpmdENABLE_SECURE
	gcvip_info("create network, work mode=%s",
			   (type & VIP_CREATE_NETWORK_MODE_NORMAL) ? "Normal" : "Secure");
	if (type & VIP_CREATE_NETWORK_MODE_NORMAL) {
		nw->work_mode = GCKVIP_WORK_MODE_NORMAL;
	} else if (type & VIP_CREATE_NETWORK_MODE_SECURE) {
		nw->work_mode = GCKVIP_WORK_MODE_SECURITY;
	} else {
		gcvip_error("failed, not support this work mode, type=0x%x\n", type);
		gcGoOnError(VIP_ERROR_INVALID_NETWORK);
	}
	status = gcvip_user_set_workmode(nw->work_mode);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to set work mode type=0x%x\n", type);
		gcGoOnError(VIP_ERROR_INVALID_NETWORK);
	}
#endif

	if (VIP_CREATE_NETWORK_FROM_FILE & type) {
		gcvip_file_t fp = gcvip_os_open_file((vip_char_t *)data, FILE_READ);
		if (fp != VIP_NULL) {
			status = gcvip_create_network_from_file(fp, nw);
			gcvip_os_close_file(fp);
		} else {
			gcvip_error("failed to open NBG file=%s\n", (vip_char_t *)data);
			gcGoOnError(VIP_ERROR_INVALID_NETWORK);
		}
	} else if (VIP_CREATE_NETWORK_FROM_MEMORY & type) {
		status = gcvip_create_network_from_memory(nw, data, size_of_data);
	} else if (VIP_CREATE_NETWORK_FROM_FLASH & type) {
#if vpmdCREATE_NETWORK_FROM_FLASH
		status = gcvip_create_network_from_memory(nw, data, size_of_data);
#else
		gcvip_error("fail to create network, you should set vpmdCREATE_NETWORK_FROM_FLASH"
					"to 1 in gc_vip_common.h first\n");
#endif
	} else {
		gcvip_error("failed, not support this create network type=0x%x\n", type);
		gcGoOnError(VIP_ERROR_INVALID_NETWORK);
	}

	gcvip_info("create network=%p\n", nw);

	if (VIP_SUCCESS == status) {
		*network = nw;
	} else {
		gcvip_error("failed to create network status=%d\n", status);
		gcGoOnError(VIP_ERROR_INVALID_NETWORK);
	}

	return status;

onError:
	*network = VIP_NULL;
	if (nw != VIP_NULL) {
		gcvip_user_free_memory(nw);
	}
	return status;
}

/*! \brief Weak dup a vip_network object.
*\param network vip_network to dup.
*\param dup_network output vip_network.
*\return <tt>\ref vip_status_e </tt>
*/
VIP_API
vip_status_e vip_weak_dup_network(
	IN vip_network network,
	OUT vip_network *dup_network
)
{
	vip_status_e status = VIP_SUCCESS;
#if vpmdENABLE_GROUP_MODE
	vip_network copy = VIP_NULL;
	vip_uint32_t i = 0;
	vip_uint32_t j = 0;
	vip_uint32_t k = 0;
	if (!network || !dup_network) {
		gcvip_error("Unexpected null inputs.");
		return VIP_ERROR_FAILURE;
	}

	if (vip_false_e == network->prepared_network) {
		gcvip_error("failed to dup network, please prepare original network first\n");
		return VIP_ERROR_FAILURE;
	}

	status = gcvip_user_allocate_memory(sizeof(vip_network_t), (void **)&copy);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to allocate memory for network object\n");
		return status;
	}
	gcvip_user_zero_memory(copy, sizeof(vip_network_t));
	gcvip_user_memcopy(copy, network, sizeof(vip_network_t));

	/* Copy segments */
	gcOnError(gcvip_user_allocate_memory(sizeof(gcvip_lite_segment_t) * copy->segment_num,
										 (void **)&copy->segments));
	gcvip_user_memcopy(copy->segments, network->segments,
					   sizeof(gcvip_lite_segment_t) * copy->segment_num);

	for (i = 0; i < network->segment_num; i ++) {
		const gcvip_videomemory_t *orig_alloc = &network->segments[i].states_buffer;
		gcvip_videomemory_t *copy_alloc = &copy->segments[i].states_buffer;
		gcOnError(gcvip_user_allocate_videomemory((vip_uint8_t **)&copy_alloc->logical,
				  &copy_alloc->handle,
				  &copy_alloc->physical,
				  orig_alloc->size + APPEND_COMMAND_SIZE,
				  gcdVIP_MEMORY_ALIGN_SIZE));
		gcvip_user_memcopy(copy_alloc->logical, orig_alloc->logical, orig_alloc->size + APPEND_COMMAND_SIZE);
	}
	/* Copy inputs and outputs */
	gcOnError(gcvip_user_allocate_memory(sizeof(gcvip_io_patch_info_t) * network->fixed.header.input_count,
										 (void **) &copy->network_inputs));
	gcOnError(gcvip_user_allocate_memory(sizeof(gcvip_io_patch_info_t) * network->fixed.header.output_count,
										 (void **) &copy->network_outputs));
	gcvip_user_memcopy(copy->network_inputs, network->network_inputs,
					   sizeof(gcvip_io_patch_info_t) * network->fixed.header.input_count);
	gcvip_user_memcopy(copy->network_outputs, network->network_outputs,
					   sizeof(gcvip_io_patch_info_t) * network->fixed.header.output_count);

	/* Copy nnCmd and tpCmd */
	if (network->fixed.nn_op_data_table.size > 0) {
		gcOnError(gcvip_user_allocate_videomemory(&copy->nnCmds.logical, &copy->nnCmds.handle,
				  &copy->nnCmds.physical, network->nnCmds.size,
				  gcdVIP_MEMORY_ALIGN_SIZE));
		gcvip_user_memcopy(copy->nnCmds.logical, network->nnCmds.logical, network->nnCmds.size);
		copy->nn_ops = (void *)copy->nnCmds.logical;
	}

	if (network->fixed.tp_op_data_table.size > 0) {
		gcOnError(gcvip_user_allocate_videomemory(&copy->tpCmds.logical, &copy->tpCmds.handle,
				  &copy->tpCmds.physical, network->tpCmds.size,
				  gcdVIP_MEMORY_ALIGN_SIZE));
		gcvip_user_memcopy(copy->tpCmds.logical, network->tpCmds.logical, network->tpCmds.size);

		copy->tp_ops = (gcvip_bin_tp_operation_t *)copy->tpCmds.logical;
	}

	for (i = 0; i < copy->n_inputs; i ++) {
		const gcvip_io_patch_info_t *orig_io = &network->network_inputs[i];
		gcvip_io_patch_info_t *copy_io = &copy->network_inputs[i];

		vip_uint32_t size = sizeof(vip_address_t) * orig_io->slice_num;
		gcOnError(gcvip_user_allocate_memory(size, (void **)&copy_io->logical_in_cmd));
		gcvip_user_memcopy(copy_io->logical_in_cmd, orig_io->logical_in_cmd, size);

		size = sizeof(vip_uint32_t)  * orig_io->slice_num;
		gcOnError(gcvip_user_allocate_memory(size, (void **)&copy_io->physical_in_cmd));
		gcvip_user_memcopy(copy_io->physical_in_cmd, orig_io->physical_in_cmd, size);
		gcOnError(gcvip_user_allocate_memory(size, (void **)&copy_io->offsets));
		gcvip_user_memcopy(copy_io->offsets, orig_io->offsets, size);

		for (j = 0; j < orig_io->slice_num; j ++) {
			const vip_uint32_t physical = orig_io->physical_in_cmd[j];
			vip_uint32_t orig_base = 0;
			vip_uint32_t offset = 0;
			const gcvip_videomemory_t *copy_mem = VIP_NULL;
			if ((physical >= network->nnCmds.physical) &&
				(physical <= (network->nnCmds.physical + network->nnCmds.size))) {
				orig_base = network->nnCmds.physical;
				copy_mem = &copy->nnCmds;
			} else if ((physical >= network->tpCmds.physical) &&
					   (physical <= (network->tpCmds.physical + network->tpCmds.size))) {
				orig_base = network->tpCmds.physical;
				copy_mem = &copy->tpCmds;
			} else {
				for (k = 0; k < network->segment_num; k ++) {
					gcvip_videomemory_t *buffer = &network->segments[k].states_buffer;
					if ((physical >= buffer->physical) &&
						(physical <= (buffer->physical + buffer->size))) {
						orig_base = buffer->physical;
						copy_mem = &copy->segments[k].states_buffer;
					}
				}
			}
			if (physical < orig_base) {
				gcvip_error("Invalid physical=%#x, base=%#x.\n", physical, orig_base);
				gcGoOnError(VIP_ERROR_FAILURE);
			}
			offset = physical - orig_base;
			copy_io->physical_in_cmd[j] = copy_mem->physical + offset;
			copy_io->logical_in_cmd[j] = GCVIPPTR_TO_UINT64(copy_mem->logical + offset);
		}
	}

	for (i = 0; i < copy->n_outputs; i ++) {
		const gcvip_io_patch_info_t *orig_io = &network->network_outputs[i];
		gcvip_io_patch_info_t *copy_io = &copy->network_outputs[i];

		vip_uint32_t size = sizeof(vip_address_t) * orig_io->slice_num;
		gcOnError(gcvip_user_allocate_memory(size, (void **)&copy_io->logical_in_cmd));
		gcvip_user_memcopy(copy_io->logical_in_cmd, orig_io->logical_in_cmd, size);

		size = sizeof(vip_uint32_t)  * orig_io->slice_num;
		gcOnError(gcvip_user_allocate_memory(size, (void **)&copy_io->physical_in_cmd));
		gcvip_user_memcopy(copy_io->physical_in_cmd, orig_io->physical_in_cmd, size);
		gcOnError(gcvip_user_allocate_memory(size, (void **)&copy_io->offsets));
		gcvip_user_memcopy(copy_io->offsets, orig_io->offsets, size);

		for (j = 0; j < orig_io->slice_num; j ++) {
			const vip_uint32_t physical = orig_io->physical_in_cmd[j];
			vip_uint32_t orig_base = 0;
			vip_uint32_t offset = 0;
			const gcvip_videomemory_t *copy_mem = VIP_NULL;
			if ((physical >= network->nnCmds.physical) &&
				(physical <= (network->nnCmds.physical + network->nnCmds.size))) {
				orig_base = network->nnCmds.physical;
				copy_mem = &copy->nnCmds;
			} else if ((physical >= network->tpCmds.physical) &&
					   (physical <= (network->tpCmds.physical + network->tpCmds.size))) {
				orig_base = network->tpCmds.physical;
				copy_mem = &copy->tpCmds;
			} else {
				for (k = 0; k < network->segment_num; k ++) {
					gcvip_videomemory_t *buffer = &network->segments[k].states_buffer;
					if ((physical >= buffer->physical) &&
						(physical <= (buffer->physical + buffer->size))) {
						orig_base = buffer->physical;
						copy_mem = &copy->segments[k].states_buffer;
					}
				}
			}

			if (physical < orig_base) {
				gcvip_error("Invalid physical=%#x, base=%#x.\n", physical, orig_base);
				gcGoOnError(VIP_ERROR_FAILURE);
			}
			offset = physical - orig_base;
			copy_io->physical_in_cmd[j] = copy_mem->physical + offset;
			copy_io->logical_in_cmd[j] = GCVIPPTR_TO_UINT64(copy_mem->logical + offset);
		}
	}

	status = gcvip_weak_dup_network(network, copy);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to weak dup network status=%d\n", status);
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	copy->weak_dup = vip_true_e;
	*dup_network = copy;
onError:
#else
	gcvip_error("not support group mode, please set vpmdENABLE_GROUP_MODE 1\n");
	status = VIP_ERROR_NOT_SUPPORTED;
#endif
	return status;
}

/*
@brief destory network object.
@param network The network object which created by vip_create_network().
*/
VIP_API
vip_status_e vip_destroy_network(
	IN vip_network network
)
{
	vip_network_t *nw = (vip_network_t *)network;
	vip_status_e status = VIP_SUCCESS;
	GCVIP_CHECK_NETWORK();
	GCVIP_NETWORK_SET_WORK_MODE();

	status = gcvip_destroy_network(network);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to destroy network=%p\n", network);
	}

	status = gcvip_user_free_memory(nw);

	return status;
}

/*
@brief query network's information. input/ouput/network name information.
@param network The network object which created by vip_create_network().
@param property The property be query. see vip_network_property_e.
@param value The returns value data.
*/
VIP_API
vip_status_e vip_query_network(
	IN vip_network network,
	IN vip_enum property,
	OUT void *value
)
{
	vip_status_e status = VIP_SUCCESS;
	GCVIP_CHECK_NETWORK();
	GCVIP_NETWORK_SET_WORK_MODE();

	status = gcvip_query_network(network, property, value);
	return status;
}

/*
@brief set network property.
    1. support dynamic input shape.
    2. set network work mode for broker.
@param network The network object which created by vip_create_network().
@param property The property be set. see vip_network_property_e.
@param value The set data.
*/
VIP_API
vip_status_e vip_set_network(
	IN vip_network network,
	IN vip_enum property,
	IN void *value
)
{
	vip_status_e status = VIP_SUCCESS;
	GCVIP_CHECK_NETWORK();
	GCVIP_NETWORK_SET_WORK_MODE();

	status = gcvip_set_network(network, property, value);

	return status;
}


/*
@brief interpreter the network for preparing command buffer,
       memory pool for running network on hardware.
@param network The network object which created by vip_create_network().
*/
VIP_API
vip_status_e vip_prepare_network(
	IN vip_network network
)
{
	vip_status_e status = VIP_SUCCESS;
	GCVIP_CHECK_NETWORK();
	GCVIP_NETWORK_SET_WORK_MODE();

	status = gcvip_prepare_network(network);
	return status;
}

/*
@brief query input shape, quant, format and so on.
@param index The index of network input.
@param property The property be query. see vip_buffer_property_e.
@param value, The returns value data.
*/
VIP_API
vip_status_e vip_query_input(
	IN vip_network network,
	IN vip_uint32_t index,
	IN vip_enum property,
	OUT void *value
)
{
	vip_status_e status = VIP_SUCCESS;
	GCVIP_CHECK_NETWORK();
	GCVIP_NETWORK_SET_WORK_MODE();

	status = gcvip_query_input(network, index, property, value);
	return status;
}

/*
@brief query output shape, quan, format and so on.
@param index The index of network output.
@param property The property be query. see vip_buffer_property_e.
@param value, The returns value data.
*/
VIP_API
vip_status_e vip_query_output(
	IN vip_network network,
	IN vip_uint32_t index,
	IN vip_enum property,
	OUT void *value
)
{
	vip_status_e status = VIP_SUCCESS;
	GCVIP_CHECK_NETWORK();
	GCVIP_NETWORK_SET_WORK_MODE();

	status = gcvip_query_output(network, index, property, value);
	return status;
}

/*
@brief set input buffer for network or change network input buffer.
@param index The index of network inputs.
@param input The input buffer of network.
*/
VIP_API
vip_status_e vip_set_input(
	IN vip_network network,
	IN vip_uint32_t index,
	IN vip_buffer input
)
{
	vip_status_e status = VIP_SUCCESS;
	GCVIP_CHECK_NETWORK();
	GCVIP_CHECK_WORK_MODE(input->param.memory_type);
	GCVIP_NETWORK_SET_WORK_MODE();

	status = gcvip_set_input(network, index, input);
	return status;
}

/*
@brief set output buffer for network.
@param index The index of network outputs.
@param input The output buffer of network.
*/
VIP_API
vip_status_e vip_set_output(
	IN vip_network network,
	IN vip_uint32_t index,
	IN vip_buffer output
)
{
	vip_status_e status = VIP_SUCCESS;
	GCVIP_CHECK_NETWORK();
	GCVIP_CHECK_WORK_MODE(output->param.memory_type);
	GCVIP_NETWORK_SET_WORK_MODE();

	status = gcvip_set_output(network, index, output);
	return status;
}

/*
@brief Run the network object. Assume all related resource are ready.
@param network The network object which created by vip_create_network().
*/
VIP_API
vip_status_e vip_run_network(
	IN vip_network network
)
{
	vip_status_e status = VIP_SUCCESS;
	GCVIP_CHECK_NETWORK();
	GCVIP_NETWORK_SET_WORK_MODE();
	status = gcvip_run_network(network);
	return status;
}

/*
@brief Kick off the network commands to HW. without waiting from HW.
       Assume all related resource are ready.
@param network The network object which created by vip_create_network().
*/
VIP_API
vip_status_e vip_trigger_network(
	IN vip_network network
)
{
	vip_status_e status = VIP_SUCCESS;
	GCVIP_CHECK_NETWORK();
	GCVIP_NETWORK_SET_WORK_MODE();
	status = gcvip_trigger_network(network);
	return status;
}

/*
@brief Wait for HW to finish executing the submitted network.
@param network The network object which created by vip_create_network().
*/
VIP_API
vip_status_e vip_wait_network(
	IN vip_network network
)
{
	vip_status_e status = VIP_SUCCESS;
	GCVIP_CHECK_NETWORK();
	GCVIP_NETWORK_SET_WORK_MODE();

	/* wait for last layer finish */
	status = gcvip_wait_network(network);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to wait network in vip wait network\n");
	}

	return status;
}

/*
@brief Finish running the network. matched with vip_prepare_network and vip_create_network.
@param network The network object which created by vip_create_network().
*/
VIP_API
vip_status_e vip_finish_network(
	IN vip_network network
)
{
	vip_status_e status = VIP_SUCCESS;
	GCVIP_CHECK_NETWORK();
	GCVIP_NETWORK_SET_WORK_MODE();

	status = gcvip_finish_network(network);
	return status;
}

/*
@brief Give user applications more control over power management for VIP cores.
@param perperty Control VIP core frequency and power status by property. see vip_power_property_e.
@param value The value for vip_power_property_e property.
       Please see vip_power_frequency_t if property is setting to VIP_POWER_PROPERTY_SET_FREQUENCY.
*/
VIP_API
vip_status_e vip_power_management(
	IN vip_enum property,
	IN void *value
)
{
	vip_status_e status = VIP_SUCCESS;

	if ((property <= VIP_POWER_PROPERTY_NONE) || (property >= VIP_POWER_PROPERTY_MAX)) {
		gcvip_error("not support this property=%d\n", property);
		return VIP_ERROR_FAILURE;
	}

	status = gcvip_user_power_management(property, value);

	return status;
}

/*
@brief Create a vip_group object to run multiple tasks(network or node) and
       without interrupte between each task.
@param count The maximum number of tasks supports by this group.
@param group Return vip_group object be created.
*/
VIP_API
vip_status_e vip_create_group(
	IN vip_uint32_t count,
	OUT vip_group *group
)
{
	vip_status_e status = VIP_SUCCESS;
#if vpmdENABLE_GROUP_MODE
	vip_group_t *new_graph = VIP_NULL;

	if (VIP_NULL == group) {
		gcvip_error("failed to create group, parameter is NULL\n");
		return VIP_ERROR_FAILURE;
	}

	if (0 == count) {
		gcvip_error("failed to create group, count is 0\n");
		return VIP_ERROR_FAILURE;
	}

	gcvip_info("create group the max support task count=%d\n", count);

	status = gcvip_user_allocate_memory(sizeof(vip_group_t), (void **)&new_graph);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to allocate memory for group\n");
		gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
	}
	gcvip_user_zero_memory(new_graph, sizeof(vip_group_t));

	status = gcvip_user_allocate_memory(sizeof(gcvip_group_item_t) * count,
										(void **)&new_graph->tasks);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to allocate memory for group\n");
		gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
	}

	new_graph->max_task_num = count;

#if vpmdENABLE_MULTIPLE_TASK
	status = gcvip_os_create_mutex(&new_graph->mutex);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to create mutex for group\n");
	}
#endif

	*group = new_graph;

	return status;

onError:
	if (new_graph != VIP_NULL) {
		if (new_graph->tasks != VIP_NULL) {
			gcvip_user_free_memory(new_graph->tasks);
			new_graph->tasks = VIP_NULL;
		}
		gcvip_user_free_memory(new_graph);
	}
#else
	gcvip_error("not support group mode, please set vpmdENABLE_GROUP_MODE 1\n");
	*group = VIP_NULL;
	status = VIP_ERROR_NOT_SUPPORTED;
#endif
	return status;
}

/*
@brief Destroy group object which created by vip_create_group.
@param group vip_group object.
*/
VIP_API
vip_status_e vip_destroy_group(
	IN vip_group group
)
{
	vip_status_e status = VIP_SUCCESS;

#if vpmdENABLE_GROUP_MODE
	if (group != VIP_NULL) {
		if (group->tasks != VIP_NULL) {
			gcvip_user_free_memory(group->tasks);
			group->tasks = VIP_NULL;
		}

#if vpmdENABLE_MULTIPLE_TASK
		if (group->mutex != VIP_NULL) {
			gcvip_os_destroy_mutex(group->mutex);
			group->mutex = VIP_NULL;
		}
#endif

		status = gcvip_user_free_memory(group);
	}
#else
	gcvip_error("not support group mode, please set vpmdENABLE_GROUP_MODE 1\n");
	status = VIP_ERROR_NOT_SUPPORTED;
#endif

	return status;
}

/*
@brief add a vip_network object into group.
@param group vip_group object, network be added into group.
@param network vip_network added into group.
*/
VIP_API
vip_status_e vip_add_network(
	IN vip_group group,
	IN vip_network network
)
{
	vip_status_e status = VIP_SUCCESS;
#if vpmdENABLE_GROUP_MODE
	vip_uint32_t count = group->count;
	GCVIP_CHECK_NETWORK();

#if vpmdENABLE_MULTIPLE_TASK
	gcvip_os_lock_mutex(group->mutex);
#endif

	if (count > (group->max_task_num - 1)) {
		gcvip_error("failed to add network, task count is more than max=%d\n",
					group->max_task_num);
		return VIP_ERROR_FAILURE;
	}
	if (network->segment_num > 1) {
		gcvip_error("failed to add network, cur network segment num=%d\n",
					network->segment_num);
		gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
	}

	group->tasks[count].object.type = GCVIP_OBJ_NETWORK;
	group->tasks[count].task = (vip_ptr)network;

	if (count > 0) {
		gcvip_videomemory_t *pre_cmd = VIP_NULL;
		status = gcvip_group_item_get_command(&group->tasks[count - 1], &pre_cmd);
		if (status != VIP_SUCCESS) {
			goto onError;
		}

		status = gcvip_link_command(pre_cmd, &network->segments[0].states_buffer);
		if (status != VIP_SUCCESS) {
			gcvip_error("Fail to link commands\n");
			group->tasks[count].object.type = GCVIP_OBJ_NONE;
			group->tasks[count].task = VIP_NULL;
			goto onError;
		}
	}

	group->count++;
	group->run_task_num++;

onError:
#if vpmdENABLE_MULTIPLE_TASK
	gcvip_os_unlock_mutex(group->mutex);
#endif

#else
	gcvip_error("not support group mode, please set vpmdENABLE_GROUP_MODE 1\n");
	status = VIP_ERROR_NOT_SUPPORTED;
#endif

	return status;
}

/*
@brief run tasks in group. ony issue a interrupt after tasks complete.
@param group vip_group object
@param the number of task will be run. eg: num = 4, the 0, 1, 2, 3 taks index in group will be run(inference).
*/
VIP_API
vip_status_e vip_run_group(
	IN vip_group group,
	IN vip_uint32_t num
)
{
	vip_status_e status = VIP_SUCCESS;
#if vpmdENABLE_GROUP_MODE
	gcvip_videomemory_t *last_cmd = VIP_NULL;
	gcvip_videomemory_t *first_cmd = VIP_NULL;

#if vpmdENABLE_MULTIPLE_TASK
	gcvip_os_lock_mutex(group->mutex);
#endif

	if (num > group->run_task_num) {
		gcvip_error("failed run group, num=%d, task in group count=%d\n",
					num, group->run_task_num);
		return VIP_ERROR_FAILURE;
	} else if (num == 0) {
		gcvip_error("No task to run\n");
		return VIP_ERROR_FAILURE;
	}

	/* link tasks */
	if (num == 1) {
		group->run_task_num = num;
		/* check original network weight data */
		if (GCVIP_OBJ_NETWORK == group->tasks[0].object.type) {
			vip_network network = (vip_network)&group->tasks[0];
			if ((network->weak_dup) && (VIP_NULL == network->LCD.handle)) {
				gcvip_error("failed the weak network coefficient data is destroy\n");
				gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
			}
		}
	} else if (num != group->run_task_num) {
		vip_uint32_t i = 0;
		gcvip_videomemory_t *pre_cmd = VIP_NULL;
		gcvip_videomemory_t *cur_cmd = VIP_NULL;
		group->run_task_num = num;
		for (i = 0; i < num; i++) {
			status = gcvip_group_item_get_command(&group->tasks[i], &cur_cmd);
			if (status != VIP_SUCCESS) {
				gcvip_error("failed to get task[%d] cmd buffer, status=%d\n", i, status);
				gcGoOnError(VIP_ERROR_IO);
			}
			if (pre_cmd) {
				status = gcvip_link_command(pre_cmd, cur_cmd);
				if (status != VIP_SUCCESS) {
					gcvip_error("failed to link commands, num=%d, run_task_num=%d\n",
								num, group->run_task_num);
					gcGoOnError(VIP_ERROR_IO);
				}
			}
			pre_cmd = cur_cmd;
		}
	}

	gcOnError(gcvip_group_item_get_command(&group->tasks[0], &first_cmd));
	gcOnError(gcvip_group_item_get_command(&group->tasks[num - 1], &last_cmd));

	if (!first_cmd || !last_cmd) {
		gcvip_error("Link command error.");
		gcGoOnError(VIP_ERROR_FAILURE);
	}
	/* update input and output of tasks in group */
	status = gcvip_update_group_io(group, num);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to update group input and output, run task count=%d\n", num);
		gcGoOnError(VIP_ERROR_IO);
	}

	status = gcvip_commit_multiple_command(first_cmd, last_cmd, GCKVIP_SUBMIT_WITH_EVENT);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to commit multiple commands\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	status = gcvip_wait_group(group);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to wait group=%p..\n", group);
		gcGoOnError(VIP_ERROR_IO);
	}

onError:
#if vpmdENABLE_MULTIPLE_TASK
	gcvip_os_unlock_mutex(group->mutex);
#endif

#else
	gcvip_error("not support group mode, please set vpmdENABLE_GROUP_MODE 1\n");
	status = VIP_ERROR_NOT_SUPPORTED;
#endif

	return status;
}

/*
@brief change parameters of PPU.
@param network the network object.
@param param the params of PPU.
@param index, NOT used now. default is zero.
*/
VIP_API
vip_status_e vip_set_ppu_param(
	IN vip_network network,
	IN vip_ppu_param_t *param,
	IN vip_uint32_t index
)
{
	vip_status_e status = VIP_SUCCESS;
#if vpmdENABLE_CHANGE_PPU_PARAM
	vip_uint32_t global_offset[3] = {0, 0, 0};
	vip_uint32_t global_scale[3] = {0, 0, 0};
	vip_uint32_t work_size[3] = {0, 0, 0};
	vip_uint32_t group_count[3] = {0, 0, 0};
	vip_ppu_param_patch_info_t *ppu_param_i = VIP_NULL;
	GCVIP_CHECK_NETWORK();

	if (VIP_NULL == param) {
		gcvip_error("failed to set ppu param, param is NULL\n");
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	if (param->work_dim > 3) {
		gcvip_error("failed to set ppu param, work dim=%d\n", param->work_dim);
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	if (VIP_NULL == network->ppu_param_info) {
		gcvip_error("failed to set ppu param, not patch ppu param\n");
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	if (!network->prepared_network) {
		gcvip_error("failed please change ppu param after calling prepare network\n");
		gcOnError(VIP_ERROR_FAILURE);
	}

	ppu_param_i = &network->ppu_param_info[index];

	if (VIP_NULL == ppu_param_i) {
		gcvip_error("failed to change ppu param ppu_param_info is NULL\n");
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	if (param->work_dim != network->ppu_work_dim) {
		gcvip_warning("warning set work-dim=%d, nbg work-dim=%d\n",
					  param->work_dim, network->ppu_work_dim);
	}

	global_offset[0] = param->global_offset[0];
	global_scale[0] = param->global_scale[0];
	work_size[0] = param->local_size[0] ? param->local_size[0] : 1;
	group_count[0] = param->global_size[0] / param->local_size[0];

	if (param->work_dim > 1) {
		global_offset[1] = param->global_offset[1];
		global_scale[1] = param->global_scale[1];
		work_size[1] = param->local_size[1] ? param->local_size[1] : 1;
		group_count[1] = param->global_size[1] / param->local_size[1];
	}

	if (param->work_dim > 2) {
		global_offset[2] = param->global_offset[2];
		global_scale[2] = param->global_scale[2];
		work_size[2] = param->local_size[2] ? param->local_size[2] : 1;
		group_count[2] = param->global_size[2] / param->local_size[2];
	}

	GCVIP_SET_VALUE((vip_uint32_t *)ppu_param_i->glooffset_x_logic, global_offset[0]);
	GCVIP_SET_VALUE((vip_uint32_t *)ppu_param_i->glooffset_y_logic, global_offset[1]);
	GCVIP_SET_VALUE((vip_uint32_t *)ppu_param_i->glooffset_z_logic, global_offset[2]);

	GCVIP_SET_VALUE((vip_uint32_t *)ppu_param_i->gloscale_x_logic, global_scale[0] & 0xFF);
	GCVIP_SET_VALUE((vip_uint32_t *)ppu_param_i->gloscale_y_logic, global_scale[1] & 0xFF);
	GCVIP_SET_VALUE((vip_uint32_t *)ppu_param_i->gloscale_z_logic, global_scale[2] & 0xFF);

	GCVIP_SET_VALUE(ppu_param_i->grocount_x_logic, group_count[0] - 1);
	GCVIP_SET_VALUE(ppu_param_i->grocount_y_logic, group_count[1] - 1);
	GCVIP_SET_VALUE(ppu_param_i->grocount_z_logic, group_count[2] - 1);

	GCVIP_SET_VALUE(ppu_param_i->grosize_x_logic, (work_size[0] - 1) & 0x3FF);
	GCVIP_SET_VALUE(ppu_param_i->grosize_y_logic, (work_size[1] - 1) & 0x3FF);
	GCVIP_SET_VALUE(ppu_param_i->grosize_z_logic, (work_size[2] - 1) & 0x3FF);
#else
	gcvip_error("not support set ppu parameters\n");
	gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
#endif

onError:
	return status;
}
