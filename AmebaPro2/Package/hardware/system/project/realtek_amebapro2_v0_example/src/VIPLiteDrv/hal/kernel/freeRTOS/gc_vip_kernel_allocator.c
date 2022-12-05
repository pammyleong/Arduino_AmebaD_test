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
#include "gc_vip_kernel_allocator.h"
#if vpmdENABLE_MMU


/******* These functions need to be implemented when MMU is enable ************/

/*
@brief get user space logical address.
@param, context, the contect of kernel space.
@param, node, dynamic allocate node info.
@param, virtual, the VIP's virtual address.
@param, logical, use space logical address.
@param, video memory type see gckvip_video_memory_type_e
*/
vip_status_e gckvip_allocator_get_userlogical(
	gckvip_context_t *context,
	gckvip_dyn_allocate_node_t *node,
	vip_uint32_t virtual,
	void **logical,
	vip_uint8_t memory_type
)
{
	vip_status_e status = VIP_SUCCESS;

	*logical = node->user_logical;

	return status;
}

/*
@brief get kernel space logical address.
@param, context, the contect of kernel space.
@param, node, dynamic allocate node info.
@param, virtual, the VIP's virtual address.
@param, logical, kernel space logical address.
@param, video memory type see gckvip_video_memory_type_e
*/
vip_status_e gckvip_allocator_get_kernellogical(
	gckvip_context_t *context,
	gckvip_dyn_allocate_node_t *node,
	vip_uint32_t virtual,
	void **logical,
	vip_uint8_t memory_type
)
{
	vip_status_e status = VIP_SUCCESS;

	*logical = node->kerl_logical;

	return status;
}

/*
@brief get cpu physical address.
@param, context, the contect of kernel space.
@param, node, dynamic allocate node info.
@param, logical, user space or kernel space logical address.
@param, physical, CPU physical address.
@param, video memory type see gckvip_video_memory_type_e
*/
vip_status_e gckvip_allocator_get_cpuphysical(
	gckvip_context_t *context,
	gckvip_dyn_allocate_node_t *node,
	void *logical,
	phy_address_t *physical,
	vip_uint8_t memory_type
)
{
	vip_status_e status = VIP_SUCCESS;

	*physical = node->physical_table[0];

	return status;
}

/*
@brief convert user's memory to CPU physical. And map to VIP virtual address. for vip_create_buffer_from_handle() API
@param, context, the contect of kernel space.
@param, logical, the logical address(handle) should be wraped.
@param, memory_type The type of this VIP buffer memory. see vip_buffer_memory_type_e.
@param, node, dynamic allocate node info.
*/
vip_status_e gckvip_allocator_wrap_usermemory(
	gckvip_context_t *context,
	vip_ptr logical,
	vip_uint32_t memory_type,
	gckvip_dyn_allocate_node_t *node
)
{
	vip_status_e status = VIP_SUCCESS;

	PRINTK_D("wrap usermemory logical=0x%" PRIx64", size=0x%x, memory_type=0x%x\n",
			 GCKVIPPTR_TO_UINT64(logical), node->size, memory_type);

	gcOnError(gckvip_os_allocate_memory(sizeof(phy_address_t), (void **)&node->physical_table));
	gcOnError(gckvip_os_allocate_memory(sizeof(vip_uint32_t), (void **)&node->size_table));

	/* fill physical_table/size_table/physical_num */
	/* physical is equal to logical on RTOS and physical is contiguous */
	node->physical_table[0] = (phy_address_t)logical;
	node->size_table[0] = node->size;
	node->physical_num = 1;

	node->kerl_logical = logical;
	node->user_logical = logical;

	return status;

onError:
	PRINTK_E("failed to wrap user memory, status=%d\n", status);
	if (node->size_table != VIP_NULL) {
		gckvip_os_free_memory(node->size_table);
	}
	if (node->physical_table != VIP_NULL) {
		gckvip_os_free_memory(node->physical_table);
	}

	return status;
}
/*
@brief un-wrap user memory(handle). for vip_create_buffer_from_handle() API
@param context, the contect of kernel space.
@param, node, dynamic allocate node info.
*/
vip_status_e gckvip_allocator_unwrap_usermemory(
	gckvip_context_t *context,
	gckvip_dyn_allocate_node_t *node
)
{
	vip_status_e status = VIP_SUCCESS;

	if (node->size_table != VIP_NULL) {
		gckvip_os_free_memory(node->size_table);
	}
	if (node->physical_table != VIP_NULL) {
		gckvip_os_free_memory(node->physical_table);
	}

	return status;
}
#endif

/*
@brief Flush CPU cache for dynamic alloc video memory and wrap user memory.
@param context, the contect of kernel space.
@param node, dynamic allocate node info.
@param physical, the physical address should be flush CPU cache.
@param logical, the logical address should be flush.
@param size, the size of the memory should be flush.
@param type The type of operate cache.
*/
#if vpmdENABLE_FLUSH_CPU_CACHE
vip_status_e gckvip_alloctor_flush_cache(
	gckvip_context_t *context,
	gckvip_dyn_allocate_node_t *node,
	phy_address_t physical,
	void *logical,
	vip_uint32_t size,
	gckvip_cache_type_e type
)
{
	vip_status_e status = VIP_SUCCESS;

	/* please implement this function if video memory and wrap user memory has enabled cache */

	PRINTK_D("allocator flush cache physical=0x%" PRIx64", logical=0x%" PRIx64", size=0x%x, type=0x%x\n",
			 physical, GCKVIPPTR_TO_UINT64(logical), size, type);

	return status;
}
#endif

/*
@brief allocate memory from system. get the physical address table each page. get size table of eache page
@param context, the contect of kernel space.
@param node, dynamic allocate noe.
@param align, the size of alignment for this video memory.
@param flag the flag of this video memroy. see gckvip_video_mem_alloc_flag_e.
*/
vip_status_e gckvip_allocator_dyn_alloc(
	gckvip_context_t *context,
	gckvip_dyn_allocate_node_t *node,
	vip_uint32_t align,
	vip_uint32_t alloc_flag
)
{
	vip_status_e status = VIP_SUCCESS;


	/* fill physical_table/size_table/physical_num */

	return status;
}

/*
@brief free a dynamic allocate memory.
@param context, the contect of kernel space.
@param node, dynamic allocate node info.
*/
vip_status_e gckvip_allocator_dyn_free(
	gckvip_context_t *context,
	gckvip_dyn_allocate_node_t *node
)
{
	vip_status_e status = VIP_SUCCESS;

	return status;
}

