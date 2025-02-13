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

#include "gc_vip_kernel_heap.h"

#if vpmdENABLE_VIDEO_MEMORY_HEAP
#include <gc_vip_kernel.h>
#include <gc_vip_kernel_port.h>

#define STATUS_USED     0xABBAF00D
#define STATUS_FREE     0x0
#define STATUS_INIT     0xCDCDCDCD

static vip_status_e new_node(
	gckvip_heap_t *heap,
	gckvip_heap_node_t **node
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0;

	do {
		if (heap->node_count >= heap->node_capacity) {
			PRINTK_E("vide mem node count=%d, node capacity=%d\n",
					 heap->node_count, heap->node_capacity);
			status = VIP_ERROR_OUT_OF_RESOURCE;
			break;
		}

		for (i = 0; i < heap->node_capacity; i++) {
			if (heap->nodes[i].status == STATUS_INIT) {
				break;
			}
		}

		*node = &heap->nodes[i];
		heap->node_count++;
	} while (0);

	return status;
}

static vip_status_e del_node(
	gckvip_heap_t *heap,
	gckvip_heap_node_t *node
)
{
	vip_status_e status = VIP_SUCCESS;

	if (VIP_NULL == node) {
		PRINTK_E("failed to delete node, node is NULL\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	node->status = STATUS_INIT;
	heap->node_count--;

	return status;
}

/* Add the list item in front of "head". */
static void add_list(
	gckvip_list_head_t *new,
	gckvip_list_head_t *prev,
	gckvip_list_head_t *next
)
{
	/* Link the new item. */
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static void add_list_tail(
	gckvip_list_head_t *new,
	gckvip_list_head_t *head
)
{
	add_list(new, head->prev, head);
}

/* Remove an entry out of the list. */
static void delete_list(
	gckvip_list_head_t *entry
)
{
	if (entry->prev != VIP_NULL) {
		entry->prev->next = entry->next;
	}
	if (entry->next != VIP_NULL) {
		entry->next->prev = entry->prev;
	}
}

static vip_status_e split_node(
	gckvip_heap_t *heap,
	gckvip_heap_node_t *node,
	vip_uint32_t size,
	vip_uint32_t offset
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_heap_node_t *split = VIP_NULL;

	do {
		/* Allocate a new node. */
		status = new_node(heap, &split);
		if (status != VIP_SUCCESS) {
			PRINTK_E("fail to split node status=%d\n", status);
			break;
		}

		/* Fill in the data of this node of the remaning size. */
		split->offset = node->offset + size + offset;
		split->size = node->size - size - offset;
		split->status = STATUS_FREE;

		/* Add the new node behind the current node. */
		add_list_tail(&split->list, &node->list);

		/* Adjust the size of the current node. */
		node->size = size + offset;
	} while (0);

	return status;
}

vip_bool_e gckvip_heap_query(
	gckvip_heap_t *heap,
	vip_uint32_t size
)
{
	vip_uint32_t max_size = 0;
	gckvip_heap_node_t *pos = VIP_NULL;
	vip_bool_e support = vip_false_e;

#if vpmdENABLE_MULTIPLE_TASK
	vip_status_e status = VIP_SUCCESS;
	status = gckvip_os_lock_mutex(heap->mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock video memory heap mutex\n");
		return vip_false_e;
	}
#endif

	if (0 == heap->node_count) {
#if vpmdENABLE_MULTIPLE_TASK
		vip_status_e status = VIP_SUCCESS;
		status = gckvip_os_lock_mutex(heap->mutex);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to lock video memory heap mutex\n");
		}
#endif
		return vip_false_e;
	}

	pos = (gckvip_heap_node_t *)heap->list.next;

	for (; &pos->list != &heap->list; pos = (gckvip_heap_node_t *)pos->list.next) {
		if (pos->status == STATUS_FREE) {
			if (pos->size > max_size) {
				max_size = pos->size;
			}
		}
	}

	if (max_size > heap->free_bytes) {
		max_size = heap->free_bytes;
	}

	if ((max_size >= size) && ((heap->node_count + 1) < heap->node_capacity)) {
		support = vip_true_e;
	}

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(heap->mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock video memory heap mutex\n");
	}
#endif

	return support;
}

void *gckvip_heap_alloc(
	gckvip_heap_t *heap,
	vip_uint32_t size,
	void **logical,
	phy_address_t *physical,
	vip_uint32_t align
)
{
	vip_uint32_t aligned_size = 0;
	gckvip_heap_node_t *pos = VIP_NULL;
	vip_uint32_t offset = 0;
	vip_status_e status = VIP_SUCCESS;

	if (VIP_NULL == logical) {
		PRINTK_E("heap alloc, logical parameter is NULL\n");
		return VIP_NULL;
	}

#if vpmdENABLE_MULTIPLE_TASK
#if defined(__linux__)
	/* return 4Kbytes alignment on Linux, not request by VIP */
	if (align < 4096) {
		align = 4096;
	}
#endif
	status = gckvip_os_lock_mutex(heap->mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock video memory heap mutex\n");
		return VIP_NULL;
	}
#endif

	/* Align the size to align bytes. */
	aligned_size = GCVIP_ALIGN(size, align);

	/* Check if there is enough free_bytes memory available. */
	if (aligned_size > heap->free_bytes) {
		PRINTK_E("video memory alloc size: 0x%x, free size: 0x%x\n",
				 aligned_size, heap->free_bytes);
		status = VIP_ERROR_IO;
		gcGoOnError(status);
	}

	/* Walk the heap backwards. */
	pos = (gckvip_heap_node_t *)heap->list.next;
	for (; &pos->list != &heap->list; pos = (gckvip_heap_node_t *)pos->list.next) {
		/* Check if the current node is free_bytes and is big enough. */
		offset = GCVIP_ALIGN(pos->offset, align) - pos->offset;
		if ((pos->status == STATUS_FREE) && (pos->size >= (aligned_size + offset))) {
			/* See if we the current node is big enough to split. */
			if ((pos->size - aligned_size) > align) {
				split_node(heap, pos, aligned_size, offset);
			}

			/* Mark the current node as used. */
			pos->status = STATUS_USED;

			/*  Return the logical/physical address. */
			*logical = (vip_uint8_t *)heap->memory + pos->offset + offset;
			if (physical != VIP_NULL) {
				*physical = heap->physical + pos->offset + offset;
			}

			/* Update free size. */
			heap->free_bytes -= aligned_size + offset;

			/* Return the node pointer as a handle. */
			break;
		}
	}

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(heap->mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock video memory heap mutex\n");
	}
#endif

	return (void *)pos;
onError:
#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(heap->mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock video memory heap mutex\n");
	}
#endif
	return VIP_NULL;
}

vip_status_e gckvip_heap_free(
	gckvip_heap_t *heap,
	void *handle
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_heap_node_t *pos = VIP_NULL;
	gckvip_heap_node_t *node = VIP_NULL;

	if (handle == VIP_NULL) {
		PRINTK_E("failed to free heap\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_lock_mutex(heap->mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock video memory heap mutex\n");
		return VIP_ERROR_FAILURE;
	}
#endif

	/* Get pointer to node. */
	node = (gckvip_heap_node_t *)handle;

	if (node->status != STATUS_USED) {
		PRINTK_E("heap memory has been free\n");
		return VIP_SUCCESS;
	}

	/* Mark node as free_bytes. */
	node->status = STATUS_FREE;

	/* Add node size to free_bytes count. */
	heap->free_bytes += node->size;

	pos = (gckvip_heap_node_t *)heap->list.next;
	for (; &pos->list != &heap->list; pos = (gckvip_heap_node_t *)pos->list.next) {
		if (pos->status == STATUS_FREE) {
			if (pos->offset == (node->offset + node->size)) {
				node->size += pos->size;
				delete_list(&pos->list);
				del_node(heap, pos);
			} else if ((pos->offset + pos->size) == node->offset) {
				pos->size += node->size;
				delete_list(&node->list);
				del_node(heap, node);
			}
		}
	}

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(heap->mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock video memory heap mutex\n");
	}
#endif

	return status;
}

vip_status_e gckvip_heap_construct(
	gckvip_heap_t *heap,
	vip_uint32_t size,
	void *logical,
	phy_address_t physical,
	vip_uint32_t node_cap
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_heap_node_t *node = VIP_NULL;
	vip_uint32_t nodes_size = 0;
	vip_uint32_t i = 0;

	if (0 == size) {
		heap->total_size = 0;
		heap->node_count = 0;
		heap->free_bytes = 0;
		return VIP_SUCCESS;
	}

	do {
		GCKVIP_INIT_LIST_HEAD(&heap->list);

		nodes_size = sizeof(gckvip_heap_node_t) * node_cap;
		heap->nodes = (gckvip_heap_node_t *)((vip_uint8_t *)logical + (size - nodes_size));
		heap->node_capacity = node_cap;
		heap->memory = logical;
		heap->free_bytes = size - nodes_size;
		heap->physical = physical;
		heap->total_size = size;
		heap->node_count = 0;

		PRINTK_I("video memory heap total free: 0x%x bytes, node used: 0x%x bytes\n",
				 heap->free_bytes, nodes_size);

		for (i = 0; i < node_cap; i++) {
			heap->nodes[i].status = STATUS_INIT;
		}

		status = new_node(heap, &node);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to new node.\n");
			break;
		}

		node->offset = 0;
		node->size = heap->free_bytes;
		node->status = STATUS_FREE;
		add_list_tail(&node->list, &heap->list);
	} while (0);

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_create_mutex(&heap->mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create mutex for video heap\n");
		return VIP_ERROR_FAILURE;
	}
#endif

	PRINTK_D("video memory heap capability=0x%x\n", gckvip_heap_capability(heap));

	return status;
}

vip_status_e gckvip_heap_destroy(
	gckvip_heap_t *heap
)
{
	gckvip_heap_node_t *pos = VIP_NULL;
	gckvip_heap_node_t *n = VIP_NULL;
	gckvip_list_head_t *hlist = VIP_NULL;

#if vpmdENABLE_MULTIPLE_TASK
	if (heap->mutex != VIP_NULL) {
		gckvip_os_destroy_mutex(heap->mutex);
		heap->mutex = VIP_NULL;
	}
#endif

	if ((heap != VIP_NULL) && (heap->node_count != 0)) {
		pos = (gckvip_heap_node_t *)heap->list.next;
		n = (gckvip_heap_node_t *)pos->list.next;
		hlist = &heap->list;
		/* Process each node. */
		for (; &pos->list != hlist; n = (gckvip_heap_node_t *)pos->list.next) {
			/* Remove it from the linked list. */
			delete_list(&pos->list);

			/* Free up the memory. */
			del_node(heap, pos);
			pos = n;
			if (heap->node_count == 0) {
				break;
			}
		}

		/* zero heap */
		heap->free_bytes = 0;
		hlist = VIP_NULL;
		heap->node_capacity = 0;
		heap->physical = 0;
		heap->nodes = VIP_NULL;
		heap->node_count = 0;
	}

	return VIP_SUCCESS;
}

/*
get video memory heap capability
you can configure the video memory heap capability by youself. see gckvip_video_mem_alloc_flag_e
*/
vip_uint32_t gckvip_heap_capability(
	gckvip_heap_t *heap
)
{
	vip_uint32_t capability = GCVIP_VIDEO_MEM_ALLOC_FLAG_CONTIGUOUS |
							  GCVIP_VIDEO_MEM_ALLOC_FLAG_1M_CONTIGUOUS |
							  GCVIP_VIDEO_MEM_ALLOC_FLAG_MAP_USER |
							  GCVIP_VIDEO_MEM_ALLOC_FLAG_NO_MMU_PAGE |
							  GCVIP_VIDEO_MEM_ALLOC_FLAG_NONE_SECURE_MEM |
							  GCVIP_VIDEO_MEM_ALLOC_FLAG_NONE_CACHE;

	if ((heap->physical + heap->total_size) >= 0xffffffff) {
		capability &= ~GCVIP_VIDEO_MEM_ALLOC_FLAG_4GB_ADDR;
	} else {
		capability |= GCVIP_VIDEO_MEM_ALLOC_FLAG_4GB_ADDR;
	}

	return capability;
}
#endif
