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
#include "gc_vip_user_heap.h"

#if vpmdENABLE_SYS_MEMORY_HEAP
#include "gc_vip_user_port.h"

#define STATUS_USED     0xABBAF00D
#define STATUS_FREE     0x0
#define STATUS_INIT     0xCDCDCDCD

static vip_status_e new_node(
	heap_t *heap,
	heap_node_t **node
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i;

	do {
		if (heap->node_count >= heap->node_capacity) {
			gcvip_error("sys mem node count=%d, node capacity=%d\n",
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
	heap_t *heap,
	heap_node_t *node
)
{
	vip_status_e status = VIP_SUCCESS;

	if (VIP_NULL == node) {
		gcvip_error("failed to delete node, node is NULL\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	node->status = STATUS_INIT;
	heap->node_count--;

	return status;
}

/* Add the list item in front of "head". */
static void add_list(
	list_head_t *new,
	list_head_t *prev,
	list_head_t *next
)
{
	/* Link the new item. */
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static void add_list_tail(
	list_head_t *new,
	list_head_t *head
)
{
	add_list(new, head->prev, head);
}

/* Remove an entry out of the list. */
static void delete_list(
	list_head_t *entry
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
	heap_t *heap,
	heap_node_t *node,
	vip_uint32_t size
)
{
	vip_status_e status = VIP_SUCCESS;
	heap_node_t *split;

	do {
		/* Allocate a new node. */
		status = new_node(heap, &split);
		if (status != VIP_SUCCESS) {
			gcvip_error("fail to split node status=%d\n", status);
			break;
		}

		/* Fill in the data of this node of the remaning size. */
		split->offset = node->offset + size;
		split->size = node->size - size;
		split->status = STATUS_FREE;

		/* Add the new node behind the current node. */
		add_list_tail(&split->list, &node->list);

		/* Adjust the size of the current node. */
		node->size = size;
	} while (0);

	return status;
}

static void *find_node(
	heap_t *heap,
	void *memory,
	vip_uint32_t status
)
{
	heap_node_t *node = VIP_NULL;
	vip_uint32_t offset = 0;
	vip_uint32_t i;

	offset = (vip_uint8_t *)memory - (vip_uint8_t *)heap->memory;

	for (i = 0; i < heap->node_capacity; i++) {
		if ((heap->nodes[i].offset == offset) &&
			(heap->nodes[i].status == status)) {
			node = &heap->nodes[i];
			break;
		}
	}

	return node;
}

vip_uint32_t gcvip_heap_max_size(
	heap_t *heap
)
{
	vip_uint32_t max_size = 0;
	heap_node_t *pos = VIP_NULL;

	if (0 == heap->node_count) {
		return 0;
	}

	pos = (heap_node_t *)heap->list.next;

	for (; &pos->list != &heap->list; pos = (heap_node_t *)pos->list.next) {
		if (pos->status == STATUS_FREE) {
			if (pos->size > max_size) {
				max_size = pos->size;
			}
		}
	}

	if (max_size > heap->free_bytes) {
		max_size = heap->free_bytes;
	}

	return max_size;
}

void *gcvip_heap_alloc(
	heap_t *heap,
	vip_uint32_t size,
	void **logical
)
{
	heap_node_t *pos = VIP_NULL;

	/* Check if there is enough free_bytes memory available. */
	if (size > heap->free_bytes) {
		gcvip_error("system memory alloc failed. size: 0x%x, free: 0x%x\n",
					size, heap->free_bytes);
		return VIP_NULL;
	}

	/* Walk the heap backwards. */
	for (pos = (heap_node_t *)heap->list.next;
		 &pos->list != &heap->list;
		 pos = (heap_node_t *)pos->list.next) {
		/* Check if the current node is free_bytes and is big enough. */
		if ((pos->status == STATUS_FREE) && (pos->size >= size)) {
			/* See if we the current node is big enough to split. */
			if (pos->size > size) {
				split_node(heap, pos, size);
			}

			/* Mark the current node as used. */
			pos->status = STATUS_USED;

			*logical = (vip_uint8_t *)heap->memory + pos->offset;

			/* Update free size. */
			heap->free_bytes -= size;

			/* Return the node pointer as a handle. */
			return pos;
		}
	}

	/* Out of memory. */
	return VIP_NULL;
}

vip_status_e gcvip_heap_get_memsize(
	heap_t *heap,
	void *memory,
	vip_uint32_t *size
)
{
	vip_status_e status = VIP_SUCCESS;
	heap_node_t *node = VIP_NULL;

	node = find_node(heap, memory, STATUS_USED);
	if (node == VIP_NULL) {
		gcvip_error("fail to get memory size, node is NULL\n");
		status = VIP_ERROR_OUT_OF_RESOURCE;
	} else if (size != VIP_NULL) {
		*size = node->size;
	} else {
		gcvip_error("fail to get memory size, size is NULL\n");
		status = VIP_ERROR_OUT_OF_RESOURCE;
	}

	return status;
}

vip_status_e gcvip_heap_free_mem(
	heap_t *heap,
	void *memory
)
{
	vip_status_e status = VIP_SUCCESS;
	void *node = VIP_NULL;

	do {
		node = find_node(heap, memory, STATUS_USED);
		if (node == VIP_NULL) {
			status = VIP_ERROR_OUT_OF_RESOURCE;
			break;
		}

		status = gcvip_heap_free(heap, node);
	} while (0);

	return status;
}

vip_status_e gcvip_heap_free(
	heap_t *heap,
	void *handle
)
{
	heap_node_t *pos = VIP_NULL;
	heap_node_t *node = VIP_NULL;
	vip_status_e status = VIP_SUCCESS;

	if (handle == VIP_NULL) {
		gcvip_error("failed to free heap\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}
	/* Get pointer to node. */
	node = (heap_node_t *)handle;

	if (node->status != STATUS_USED) {
		gcvip_error("node is used\n");
		return VIP_ERROR_FAILURE;
	}

	/* Mark node as free_bytes. */
	node->status = STATUS_FREE;

	/* Add node size to free_bytes count. */
	heap->free_bytes += node->size;

	pos = (heap_node_t *)heap->list.next;
	for (; &pos->list != &heap->list; pos = (heap_node_t *)pos->list.next) {
		if (pos->offset == (node->offset + node->size)) {
			if (pos->status == STATUS_FREE) {
				node->size += pos->size;
				delete_list(&pos->list);
				del_node(heap, pos);
			}
		} else if ((pos->offset + pos->size) == node->offset) {
			if (pos->status == STATUS_FREE) {
				/* Merge the nodes. */
				pos->size += node->size;
				delete_list(&node->list);
				del_node(heap, node);
			}
		}
	}

	return status;
}

vip_status_e gcvip_heap_construct(
	heap_t *heap,
	vip_uint32_t size,
	void *logical,
	vip_uint32_t node_cap
)
{
	vip_status_e status = VIP_SUCCESS;
	heap_node_t *node = VIP_NULL;
	vip_uint32_t nodes_size = 0;
	vip_uint32_t i = 0;

	do {
		INIT_LIST_HEAD(&heap->list);

		nodes_size = sizeof(heap_node_t) * node_cap;
		heap->nodes = (heap_node_t *)((vip_uint8_t *)logical + (size - nodes_size));
		heap->node_capacity = node_cap;
		heap->memory = logical;
		heap->free_bytes = size - nodes_size;
		heap->node_count = 0;
		heap->node_max_count = 0;
		gcvip_debug("system memory heap total free: 0x%x bytes, node used: 0x%x bytes\n",
					heap->free_bytes, nodes_size);

		for (i = 0; i < node_cap; i++) {
			heap->nodes[i].status = STATUS_INIT;
		}

		status = new_node(heap, &node);
		if (status != VIP_SUCCESS) {
			gcvip_error("failed to new node create heap\n");
			break;
		}

		node->offset = 0;
		node->size = heap->free_bytes;
		node->status = STATUS_FREE;
		add_list_tail(&node->list, &heap->list);
	} while (0);

	return status;
}

vip_status_e gcvip_heap_destroy(
	heap_t *heap
)
{
	heap_node_t *pos = VIP_NULL;
	heap_node_t *n = VIP_NULL;
	list_head_t *hlist = VIP_NULL;

	if ((heap != VIP_NULL) && (heap->node_count != 0)) {
		pos = (heap_node_t *)heap->list.next;
		n = (heap_node_t *)pos->list.next;
		hlist = &heap->list;
		/* Process each node. */
		for (; &pos->list != hlist; n = (heap_node_t *)pos->list.next) {
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
		gcvip_user_zero_memory(heap, sizeof(heap_t));
	}

	return VIP_SUCCESS;
}
#endif
