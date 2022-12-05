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

#include <gc_vip_user.h>
#include <gc_vip_hardware.h>
#include <gc_vip_user_heap.h>
#include <gc_vip_user_port.h>

#if vpmdENABLE_MEMORY_PROFILING
struct node_list {
	void *handle;       /* profile memory handle */
	vip_uint32_t size;  /* the size of memory */
	struct node_list *prev;
	struct node_list *next;
};

typedef struct _gcvip_profiler {
	vip_uint32_t system_memory;
	vip_uint32_t system_peak;
	vip_uint32_t system_allocs;
	vip_uint32_t system_frees;

	vip_uint32_t video_memory;
	vip_uint32_t video_peak;
	vip_uint32_t video_allocs;
	vip_uint32_t video_frees;

	struct node_list node;
} gcvip_profiler_t;
#endif

/* user context. */
typedef struct _gcvip_user_context {
#if vpmdENABLE_SYS_MEMORY_HEAP
	heap_t     sys_mem_heap;
	void       *sys_mem_heap_addr;

#if vpmdENABLE_MULTIPLE_TASK
	void       *heap_mutex;
#endif
#endif

#if vpmdENABLE_MEMORY_PROFILING
	gcvip_profiler_t profiler;
#endif

#if vpmdENABLE_CAPTURE
	void *capture_file;
#endif

	void *os_private; /* private data for user os */
} gcvip_user_context_t;

/* User context object. */
gcvip_user_context_t    uContext;
#define GET_CONTEXTU()  gcvip_user_context_t *context = &uContext

#if vpmdENABLE_MEMORY_PROFILING
static vip_int32_t profile_add_node(
	void *handle,
	vip_uint32_t size
)
{
	gcvip_profiler_t *profiler = VIP_NULL;
	struct node_list *p = VIP_NULL;
	GET_CONTEXTU();

	profiler = &context->profiler;
	p = &profiler->node;

	while (p->next) {
		p = p->next;
	}
	if (gcvip_os_allocate_memory(sizeof(struct node_list), (void **)&p->next)) {
		return 1;
	}
	p->next->handle = handle;
	p->next->size = size;
	p->next->prev = p;
	p->next->next = NULL;

	return 0;
}

static void profile_remove_node(
	void *handle
)
{
	gcvip_profiler_t *profiler = VIP_NULL;
	struct node_list *p = VIP_NULL;
	GET_CONTEXTU();

	profiler = &context->profiler;
	p = &profiler->node;

	while (p && p->handle != handle) {
		p = p->next;
	}

	if (p && p->handle == handle) {
		p->prev->next = p->next;
		if (p->next != NULL) {
			p->next->prev = p->prev;
		}
		gcvip_os_free_memory(p);
	} else {
		gcvip_error("Doesn't find the node\n");
	}
}

static vip_uint32_t profile_get_size(
	void *handle
)
{
	gcvip_profiler_t *profiler = VIP_NULL;
	struct node_list *p = VIP_NULL;
	vip_uint32_t size = 0;
	GET_CONTEXTU();

	profiler = &context->profiler;
	p = &profiler->node;

	while (p) {
		if (p->handle == handle) {
			break;
		}
		p = p->next;
	}

	if (p != VIP_NULL) {
		size = p->size;
	}

	return size;
}

static  void profile_reset()
{
	gcvip_profiler_t *profiler = VIP_NULL;
	GET_CONTEXTU();

	profiler = &context->profiler;
	gcvip_user_zero_memory(profiler, sizeof(gcvip_profiler_t));
}

static void profile_report()
{
	gcvip_profiler_t *profiler = VIP_NULL;
	GET_CONTEXTU();

	profiler = &context->profiler;

	gcvip_os_print("========== Memory Statistics ========\n");
	gcvip_os_print("Current Video Memory Used: %d bytes.\n", profiler->video_memory);
	gcvip_os_print("Video Peak Memory Used:    %d bytes.\n", profiler->video_peak);
	gcvip_os_print("Video Memory Alloc Count:  %d times.\n", profiler->video_allocs);
	gcvip_os_print("Video Memory Free Count:  %d times.\n", profiler->video_frees);

	gcvip_os_print("\n");

#if vpmdENABLE_SYS_MEMORY_HEAP
	if (context->sys_mem_heap_addr != VIP_NULL) {
		gcvip_os_print("Current System Memory Used: %d bytes.\n", profiler->system_memory);
		gcvip_os_print("System Peak Memory Used:    %d bytes.\n", profiler->system_peak);
		gcvip_os_print("System Memory Alloc Count:  %d times.\n", profiler->system_allocs);
		gcvip_os_print("System Memory Free Count:  %d times.\n", profiler->system_frees);
	}
#endif
	gcvip_os_print("==============  End =================\n");
}

static void profile_add_video_memory(
	vip_uint32_t bytes
)
{
	gcvip_profiler_t *profiler = VIP_NULL;
	GET_CONTEXTU();

	profiler = &context->profiler;

	profiler->video_allocs++;
	profiler->video_memory += bytes;
	if (profiler->video_memory > profiler->video_peak) {
		profiler->video_peak = profiler->video_memory;
	}
}

static void profile_remove_video_memory(
	vip_uint32_t bytes
)
{
	gcvip_profiler_t *profiler = VIP_NULL;
	GET_CONTEXTU();

	profiler = &context->profiler;

	profiler->video_frees++;
	profiler->video_memory -= bytes;
}

static void profile_add_system_memory(
	vip_uint32_t bytes
)
{
	gcvip_profiler_t *profiler = VIP_NULL;
	GET_CONTEXTU();

	profiler = &context->profiler;

	profiler->system_allocs++;
	profiler->system_memory += bytes;
	if (profiler->system_memory > profiler->system_peak) {
		profiler->system_peak = profiler->system_memory;
	}
}

static void profile_remove_system_memory(
	vip_uint32_t bytes
)
{
	gcvip_profiler_t *profiler = VIP_NULL;
	GET_CONTEXTU();

	profiler = &context->profiler;

	profiler->system_frees++;
	profiler->system_memory -= bytes;
}
#endif

#if vpmdENABLE_SYS_MEMORY_HEAP
static vip_status_e heap_alloc_memory(
	IN vip_uint32_t size,
	OUT void **memory
)
{
	vip_status_e status = VIP_SUCCESS;
	void *memory_alloc = VIP_NULL;
	void *handle = VIP_NULL;
	GET_CONTEXTU();

#if vpmdENABLE_MULTIPLE_TASK
	gcvip_os_lock_mutex(context->heap_mutex);
#endif

	if (gcvip_heap_max_size(&context->sys_mem_heap) > size) {
		handle = gcvip_heap_alloc(&context->sys_mem_heap, size, &memory_alloc);
		if (handle == VIP_NULL) {
			gcvip_error("fail to allocate system memory from heap, \n");
			gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
		}
		*memory = memory_alloc;
	} else {
		gcvip_info("system memory heap is not enough, bypass for system allocte\n");
		status = gcvip_os_allocate_memory(size, memory);
	}

onError:
#if vpmdENABLE_MULTIPLE_TASK
	gcvip_os_unlock_mutex(context->heap_mutex);
#endif
	return status;
}

static vip_status_e heap_free_memory(
	IN void *memory
)
{
	vip_status_e status = VIP_SUCCESS;
	GET_CONTEXTU();

#if vpmdENABLE_MULTIPLE_TASK
	gcvip_os_lock_mutex(context->heap_mutex);
#endif

	status = gcvip_heap_free_mem(&context->sys_mem_heap, memory);

#if vpmdENABLE_MULTIPLE_TASK
	gcvip_os_unlock_mutex(context->heap_mutex);
#endif

	return status;
}
#endif

/*
@Brief Initialize resource in user layer.
@param sys_mem_size The size of system memory heap.
@param video_mem_size The size of video memory heap.
*/
vip_status_e gcvip_user_init(
	IN vip_uint32_t sys_mem_size,
	IN vip_uint32_t video_mem_size
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_initialize_t init_data;
#if vpmdENABLE_SYS_MEMORY_HEAP
	void *pool = VIP_NULL;
	vip_uint32_t node_cap = 0;
	heap_t *heap = VIP_NULL;
#endif
	GET_CONTEXTU();

#if vpmdENABLE_MEMORY_PROFILING
	profile_reset();
#endif
	gcvip_os_zero_memory(context, sizeof(gcvip_user_context_t));

#if vpmdENABLE_SYS_MEMORY_HEAP
	if (sys_mem_size > 0x1000000) { /* 10M byte */
		node_cap = sys_mem_size / 4096; /* 4k bytes pre-node */
	} else if (sys_mem_size > 0x100000) { /* 1M byte */
		node_cap = sys_mem_size / 1024; /* 1k bytes pre-node */
	} else if (sys_mem_size > 0x80000) { /* 512K byte */
		node_cap = sys_mem_size / 512; /* 512 bytes pre-node */
	} else if (sys_mem_size > 0x19000) { /* 100k byte */
		node_cap = sys_mem_size / 256; /* 256 bytes pre-node */
	} else if (sys_mem_size > 0x2800) { /* 10k byte */
		node_cap = sys_mem_size / 125; /* 125 bytes pre-node */
	} else {
		node_cap = 60;
	}
	/* 1. create system memory heap, allocate a memory for using system memory heap */
	if (node_cap > 0) {
		heap = &context->sys_mem_heap;
		status = gcvip_os_allocate_memory(sys_mem_size, &pool);
		if (status != VIP_SUCCESS) {
			gcvip_error("fail to acquire system memory heap\n");
			sys_mem_size = 0;
			pool = VIP_NULL;
		}

		context->sys_mem_heap_addr = pool;
		gcvip_debug("system memory heap size=0x%x bytes, address=%p, node capacity=%d\n",
					sys_mem_size, pool, node_cap);

		if (pool != VIP_NULL) {
			status = gcvip_heap_construct(heap, sys_mem_size, pool, node_cap);
			if (status != VIP_SUCCESS) {
				gcvip_error("fail to construce user heap\n");
				gcGoOnError(VIP_ERROR_IO);
			}
		} else {
			gcvip_error("system memory heap base addrss is NULL\n");
		}

#if vpmdENABLE_MULTIPLE_TASK
		if (context->sys_mem_heap_addr != VIP_NULL) {
			status = gcvip_os_create_mutex(&context->heap_mutex);
			if (status != VIP_SUCCESS) {
				gcvip_error("failed to create mutex for system memory heap\n");
				gcGoOnError(VIP_ERROR_IO);
			}
		}
#endif
	} else
#endif
	{
		gcvip_info("allocate dynamic memory from system for system memory\n");
	}

	/*2. init user space OS */
	status = gcvip_os_init(&context->os_private, video_mem_size);
	if (status != VIP_SUCCESS) {
		gcvip_error("fail to initialize OS\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	/*3. init kernel space */
	init_data.video_mem_size = video_mem_size;
	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_INIT, &init_data);
	if (status != VIP_SUCCESS) {
		gcvip_error("fail to call kernel for cmd init\n");
		gcGoOnError(VIP_ERROR_IO);
	}

onError:
	return status;
}

/*
@Brief Free resources at user layer.
*/
vip_status_e gcvip_user_destroy(void)
{
	vip_status_e status = VIP_SUCCESS;
	GET_CONTEXTU();

	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_DESTROY, VIP_NULL);
	if (status != VIP_SUCCESS) {
		gcvip_error("fail to call kernel cmd destroy\n");
	}

	status = gcvip_os_uninit(&context->os_private);
	context->os_private = VIP_NULL;

#if vpmdENABLE_SYS_MEMORY_HEAP
	if (context->sys_mem_heap_addr != VIP_NULL) {
		gcvip_heap_destroy(&context->sys_mem_heap);
	}
#endif

#if vpmdENABLE_MEMORY_PROFILING
	profile_report();
#endif

#if vpmdENABLE_SYS_MEMORY_HEAP
	/* free system memory heap */
	if (context->sys_mem_heap_addr != VIP_NULL) {
		gcvip_os_free_memory(context->sys_mem_heap_addr);
		context->sys_mem_heap_addr = VIP_NULL;
	}
#if vpmdENABLE_MULTIPLE_TASK
	if (context->heap_mutex != VIP_NULL) {
		gcvip_os_destroy_mutex(context->heap_mutex);
	}
#endif
#endif

	return status;
}

/*
@Brief Wait VIP to finsh current jobs (job is in the handle object pointer).
@param, handle, the video memory hendle of command buffer.
*/
vip_status_e gcvip_user_wait(
	IN void *handle
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_wait_t wait_t;
	GET_CONTEXTU();

	wait_t.mask = 0xffffffff;
	wait_t.time_out = vpmdHARDWARE_TIMEOUT;
	wait_t.handle = GCVIPPTR_TO_UINT32(handle); /* which command buffer handle need to be waited? */

	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_WAIT, &wait_t);
	CHECK_STATUS();

onError:
	return status;
}

/*
@Brief Submit the commands (network) to HW to run.
@param param The submit param structure.
*/
vip_status_e gcvip_user_submit(
	IN gcvip_submit_param_t *param
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_commit_t commit;
	GET_CONTEXTU();
	gcIsNULL(param);

	if (0 == param->cmd_size) {
		gcvip_error("failed to user submit, command size is 0\n");
		return VIP_ERROR_FAILURE;
	}

	commit.cmd_size = param->cmd_size;
	commit.cmd_logical = GCVIPPTR_TO_UINT64(param->cmd_logical);
	commit.cmd_physical = param->cmd_physical;
	commit.cmd_handle = GCVIPPTR_TO_UINT32(param->cmd_handle);
	commit.last_cmd_size = param->last_cmd_size;
	commit.last_cmd_logical = GCVIPPTR_TO_UINT64(param->last_cmd_logical);
	commit.last_cmd_physical = param->last_cmd_physical;
	commit.last_cmd_handle = GCVIPPTR_TO_UINT32(param->last_cmd_handle);

	commit.wait_event = param->wait_event;

	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_SUBMIT, &commit);
	CHECK_STATUS();

onError:
	return status;
}

/*
@Brief Allocate a buffer, which could be used for command, intermediate pools, input/output and so on.
@param handle video memory handle.
@param memory, user space logical address.
@param physical, the virtual address of VIP when .
@param size, the size of of user memory should be unwraped.
@param align, The alignment size of the video memory.
*/
vip_status_e gcvip_user_allocate_videomemory(
	vip_uint8_t **memory,
	void **handle,
	vip_uint32_t *physical,
	vip_uint32_t  size,
	vip_uint32_t align
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_allocation_t allocation;
	GET_CONTEXTU();

	allocation.size = size;
	allocation.align = align;
	allocation.alloc_flag = GCVIP_VIDEO_MEM_ALLOC_FLAG_MAP_USER |
							GCVIP_VIDEO_MEM_ALLOC_FLAG_NONE_CACHE;

	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_ALLOCATION, &allocation);
	if (status == VIP_SUCCESS) {
		*memory = GCVIPUINT64_TO_PTR(allocation.logical);
		*handle = GCVIPUINT32_TO_PTR(allocation.handle);
		if (physical != VIP_NULL) {
			*physical = allocation.physical;
		}

#if vpmdENABLE_MEMORY_PROFILING
		profile_add_node(*handle, size);
		profile_add_video_memory(size);
#endif
	} else {
		gcvip_error("fail to allocate video memory\n");
		gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
	}

	gcvip_debug("video memory logical=%p, pyhsical=0x%08x, size=0x%x, handle=0x%x\n",
				*memory, allocation.physical, allocation.size, allocation.handle);
onError:
	return status;
}

/*
@ Brief Free a video memory buffer.
@param handle video memory handle.
*/
vip_status_e gcvip_user_free_videomemory(
	void *handle
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_deallocation_t allocation;
	GET_CONTEXTU();
	gcIsNULL(handle);

	allocation.handle = GCVIPPTR_TO_UINT32(handle);

	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_DEALLOCATION, &allocation);

#if vpmdENABLE_MEMORY_PROFILING
	profile_remove_video_memory(profile_get_size(handle));
	profile_remove_node(handle);
#endif
	CHECK_STATUS();

onError:
	return status;
}

/*
@brief create a buffer from user contiguous or scatter non-contiguous physical address.
@param physical_table Physical address table. should be wraped for VIP hardware.
@param size_table The size of physical memory for each physical_table element.
@param physical_num The number of physical table element. physical_num is 1 when create buffer from contiguous phyiscal.
@param memory_type The type of this VIP buffer memory. see vip_buffer_memory_type_e.
@param virtual The VIP hardware virtual address mapped by MMU.
@param handle The handle of video memory.
*/
vip_status_e gcvip_user_wrap_userphysical(
	IN vip_address_t *physical_table,
	IN vip_uint32_t *size_table,
	IN vip_uint32_t physical_num,
	IN vip_uint32_t memory_type,
	OUT vip_uint32_t *virtual,
	OUT void **handle
)
{
	vip_status_e status = VIP_SUCCESS;

#if vpmdENABLE_MMU
	vip_uint32_t i = 0;
	gckvip_wrap_user_physical_t *data = VIP_NULL;
	GET_CONTEXTU();

	gcOnError(gcvip_user_allocate_memory(sizeof(gckvip_wrap_user_physical_t), (void **)&data));

	for (i = 0; i < physical_num; i++) {
		data->physical_table[i] = physical_table[i];
		data->size_table[i] = size_table[i];
	}

	data->memory_type = memory_type;
	data->physical_num = physical_num;

	if (0 == physical_num) {
		gcvip_error("failed to wrap user physical, physical_num is 0\n");
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	if (physical_num > MAX_WRAP_USER_PHYSICAL_TABLE_SIZE) {
		gcvip_error("failed to wrap user physical, only supports physical num is small than %d\n", MAX_WRAP_USER_PHYSICAL_TABLE_SIZE);
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_WRAP_USER_PHYSICAL, data);
	CHECK_STATUS();

	*virtual = data->virtual;
	*handle = GCVIPUINT32_TO_PTR(data->handle);

	gcvip_user_free_memory(data);

	return status;
onError:
	gcvip_error("failed to wrap user physical.\n");
#endif
	return status;
}

/*
@Brief UnWrap a user physical.
@param handle video memory handle.
@param physical, the virtual address of VIP.
*/
vip_status_e gcvip_user_unwrap_userphysical(
	IN void *handle,
	IN vip_uint32_t physical
)
{
	vip_status_e status = VIP_SUCCESS;

#if vpmdENABLE_MMU
	gckvip_unwrap_user_memory_t data;
	GET_CONTEXTU();

	data.handle = GCVIPPTR_TO_UINT32(handle);
	data.virtual = physical;

	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_UNWRAP_USER_PHYSICAL, &data);
	CHECK_STATUS();

onError:
#endif
	return status;
}

/*
@Brief Wrap a user memory.
@param handle video memory handle.
@param logical, user space logical address.
@param size, the size of of user memory should be unwraped.
@param memory_type The type of this VIP buffer memory. see vip_buffer_memory_type_e.
@param virtual The VIP virtual address mapped from logical/physical address.
*/
vip_status_e gcvip_user_wrap_usermemory(
	IN vip_ptr logical,
	IN vip_uint32_t size,
	IN vip_uint32_t memory_type,
	OUT vip_uint32_t *virtual,
	OUT void **handle
)
{
	vip_status_e status = VIP_SUCCESS;

#if vpmdENABLE_MMU
	gckvip_wrap_user_memory_t data;
	GET_CONTEXTU();
	gcIsNULL(logical);

	data.logical = GCVIPPTR_TO_UINT64(logical);
	data.size = size;
	data.memory_type = memory_type;

	if (VIP_NULL == virtual) {
		gcvip_error("failed to wrap user memory, parameter is NULL\n");
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_WRAP_USER_MEMORY, &data);
	CHECK_STATUS();

	*virtual = data.virtual;
	*handle = GCVIPUINT32_TO_PTR(data.handle);

onError:
#endif
	return status;
}

/*
@Brief UnWrap a user memory.
@param handle video memory handle.
@param physical, the virtual address of VIP.
*/
vip_status_e gcvip_user_unwrap_usermemory(
	IN void *handle,
	IN vip_uint32_t physical
)
{
	vip_status_e status = VIP_SUCCESS;

#if vpmdENABLE_MMU
	gckvip_unwrap_user_memory_t data;
	GET_CONTEXTU();

	data.handle = GCVIPPTR_TO_UINT32(handle);
	data.virtual = physical;

	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_UNWRAP_USER_MEMORY, &data);
	CHECK_STATUS();

onError:
#endif
	return status;
}

/*
@Brief Allocate a system memory.
@param size The size of memory.
@param memory Allocate memory object.
*/
vip_status_e gcvip_user_allocate_memory(
	IN vip_uint32_t size,
	OUT void **memory
)
{
	vip_status_e status = VIP_SUCCESS;
#if vpmdENABLE_SYS_MEMORY_HEAP
	GET_CONTEXTU();
	if ((context->sys_mem_heap_addr != VIP_NULL) && (context->sys_mem_heap.free_bytes > size) &&
		((context->sys_mem_heap.node_count + 1) < context->sys_mem_heap.node_capacity)) {
		status = heap_alloc_memory(size, memory);
	} else
#endif
	{
		status = gcvip_os_allocate_memory(size, memory);
	}

	if (status != VIP_SUCCESS) {
		gcvip_error("fail to allocate system memory\n");
		status = VIP_ERROR_OUT_OF_MEMORY;
	}
#if vpmdENABLE_MEMORY_PROFILING
	else {
		profile_add_node(*memory, size);
		profile_add_system_memory(size);
	}
#endif

	return status;
}

/*
@Brief Free system memory.
@param memory The memory object should be free.
*/
vip_status_e gcvip_user_free_memory(
	IN void *memory
)
{
	vip_status_e status;
#if vpmdENABLE_SYS_MEMORY_HEAP
	GET_CONTEXTU();
#endif
	gcIsNULL(memory);

#if vpmdENABLE_SYS_MEMORY_HEAP
	if (context->sys_mem_heap_addr != VIP_NULL) {
		status = heap_free_memory(memory);
		if (status != VIP_SUCCESS) {
			/* try to free system memory */
			status = gcvip_os_free_memory(memory);
		}
	} else
#endif
	{
		status = gcvip_os_free_memory(memory);
	}

#if vpmdENABLE_MEMORY_PROFILING
	profile_remove_system_memory(profile_get_size(memory));
	profile_remove_node(memory);
#endif

	CHECK_STATUS();

onError:
	return status;
}

/*
@Brief Copy memory data from src to dst.
@param dst Destination memory.
@param src Source memory.
@param size The size of memory shoule be copy.
*/
vip_status_e gcvip_user_memcopy(
	IN void *dst,
	IN const void *src,
	IN vip_uint32_t size
)
{
	vip_status_e status = VIP_SUCCESS;

	gcIsNULL(dst);
	status = gcvip_os_memcopy(dst, src, size);

onError:
	return status;
}

/*
brief fill zero to memory
param memory
param size The size of memory should be fill zero.
*/
vip_status_e gcvip_user_zero_memory(
	IN void *memory,
	IN vip_uint32_t size
)
{
	vip_status_e status = VIP_SUCCESS;

	gcIsNULL(memory);
	status = gcvip_os_zero_memory(memory, size);

onError:
	return status;
}

/*
brief read a hardware register
param address the address read.
param data data read to address.
*/
vip_status_e gcvip_user_read_reg(
	IN  vip_uint32_t address,
	OUT vip_uint32_t *data
)
{
	gckvip_reg_t reg;
	vip_status_e status = VIP_SUCCESS;
	GET_CONTEXTU();
	gcIsNULL(data);

	reg.reg = address;

	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_READ_REG, &reg);
	CHECK_STATUS();

	if (data != VIP_NULL) {
		*data = reg.data;
	}

onError:
	return status;
}

/*
brief write a hardware register
param address the address write.
param data data write to address.
*/
vip_status_e gcvip_user_write_reg(
	IN  vip_uint32_t address,
	IN  vip_uint32_t data
)
{
	gckvip_reg_t reg;
	vip_status_e status = VIP_SUCCESS;
	GET_CONTEXTU();

	reg.reg = address;
	reg.data = data;

	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_WRITE_REG, &reg);
	CHECK_STATUS();

onError:
	return status;
}

/*
brief dump string to file.
param stream the object stream.  FILE * pointer.
param buffer string store in buffer object.
*/
vip_status_e gcvip_user_print_string(
	IN void *stream,
	IN vip_char_t *buffer
)
{
	vip_status_e status = VIP_SUCCESS;
	GET_CONTEXTU();

	status = gcvip_os_print_string(context->os_private, stream, buffer);

	return status;
}

/*
brief Query address infomation. wait-link buffer address for Agent driver.
param data, query address info stucture.
*/
vip_status_e gcvip_user_query_address_info(
	IN void *data
)
{
	vip_status_e status = VIP_SUCCESS;
#if vpmdENABLE_USE_AGENT_TRIGGER
	GET_CONTEXTU();
	gcIsNULL(data);

	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_QUERY_ADDRESS_INFO, data);
	CHECK_STATUS();

onError:
#endif
	return status;
}

/*
brief Query power infomation. power status.
param data, query power info stucture.
*/
vip_status_e gcvip_user_query_power_info(
	IN void *data
)
{
	vip_status_e status = VIP_SUCCESS;
#if vpmdPOWER_OFF_TIMEOUT || vpmdENABLE_USER_CONTROL_POWER
	GET_CONTEXTU();
	gcIsNULL(data);

	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_QUERY_POWER_INFO, data);
	CHECK_STATUS();

onError:
#endif
	return status;
}

/*
brief Query feature database.
@param data, query database stucture.
*/
vip_status_e gcvip_user_query_database(
	IN void *data
)
{
	vip_status_e status = VIP_SUCCESS;
	GET_CONTEXTU();
	gcIsNULL(data);

	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_QUERY_DATABASE, data);
	CHECK_STATUS();

onError:
	return status;
}

/*
brief Set network work mode. this function should be called before vip_create_network.
@param mode, work mode.
*/
vip_status_e gcvip_user_set_workmode(
	IN vip_uint8_t mode
)
{
	vip_status_e status = VIP_SUCCESS;
#if vpmdENABLE_SECURE
	gckvip_set_work_mode_t data;
	GET_CONTEXTU();

	data.work_mode = mode;

	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_SET_WORK_MODE, &data);
	CHECK_STATUS();

onError:
#endif
	return status;
}

/*
@brief Flush video memory CPU cache.
@param hanlde, the video memory handle be flush.
@param physical, the physical base address be flush.
@param logical, the logical base address be flush.
@param size, the size of memory should be flush. So flush memory address range is physical to physical+size.
@param type, the type of flush cache. see gckvip_cache_type_e.
*/
vip_status_e gcvip_user_flush_cache(
	IN void *handle,
	IN vip_uint32_t physical,
	IN void *logical,
	IN vip_uint32_t size,
	IN vip_uint8_t type
)
{
	vip_status_e status = VIP_SUCCESS;

#if vpmdENABLE_MMU || vpmdENABLE_FLUSH_CPU_CACHE
	gckvip_operate_cache_t data;
	GET_CONTEXTU();
	gcIsNULL(handle);

	if ((type >= GCKVIP_CACHE_MAX) || (type == GCKVIP_CACHE_NONE)) {
		gcvip_error("invalid flush cache type=%d\n", type);
		return VIP_ERROR_FAILURE;
	}

	data.logical = GCVIPPTR_TO_UINT64(logical);
	/*
	  when MMU enable, physical is VIP's virtual address.
	  when MMU disable, physical is CPU/VIP physical address.
	*/
	data.physical = physical;
	data.size = size;
	data.handle = GCVIPPTR_TO_UINT32(handle);
	data.type = (gckvip_cache_type_e)type;

	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_OPERATE_CACHE, &data);
	CHECK_STATUS();

onError:
#endif

	return status;
}

/*
@brief Get flash base address of NBG store.
@param size[IN/OUT], the size of NBG. the size can be modified according to the size of NBG in flash.
@param logical[OUT], the logical address of NBG in flash location. (only for Linux). without logical in RTOS, it should be equal to physical address.
@param physical[OUT], the physical address of NBG in flash logcation.
*/
vip_status_e gcvip_user_get_flashaddress(
	OUT vip_uint32_t *size,
	OUT vip_uint8_t **logical,
	OUT vip_uint32_t *physical
)
{
	vip_status_e status = VIP_SUCCESS;

#if vpmdCREATE_NETWORK_FROM_FLASH
	GET_CONTEXTU();
	status = gcvip_os_get_flashaddress(context->os_private, size, logical, physical);
#endif

	CHECK_STATUS();
onError:
	return status;
}

/*
@brief Give user applications more control over power management for VIP cores.
@perperty Control VIP core frequency and power status by property. see vip_power_property_e.
@value The value for vip_power_property_e property.
*/
vip_status_e gcvip_user_power_management(
	IN vip_enum property,
	IN void *value
)
{
	vip_status_e status = VIP_SUCCESS;
#if vpmdENABLE_USER_CONTROL_POWER
	gckvip_power_management_t power;
	GET_CONTEXTU();

	power.property = property;

	if (VIP_POWER_PROPERTY_SET_FREQUENCY == property) {
		vip_power_frequency_t *freq = (vip_power_frequency_t *)value;
		if (VIP_NULL == freq) {
			gcvip_error("failed to power management control, set frequency value is NULL\n");
			return VIP_ERROR_FAILURE;
		}
		power.fscale_percent = freq->fscale_percent;
	}
	status = gcvip_os_call_kernel(context->os_private, KERNEL_CMD_POWER_MANAGEMENT, &power);
	CHECK_STATUS();

onError:
#else
	gcvip_error("not support this feature, please set vpmdENABLE_USER_CONTROL_POWER to 1 first\n");
	status = VIP_ERROR_NOT_SUPPORTED;
#endif
	return status;
}
