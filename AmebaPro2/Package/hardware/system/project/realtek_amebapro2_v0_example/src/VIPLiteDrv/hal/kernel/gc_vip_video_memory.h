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

#ifndef _GC_VIP_VIDEO_MEMORY_H
#define _GC_VIP_VIDEO_MEMORY_H

#include <gc_vip_kernel.h>

typedef enum _gckvip_mem_flag {
	GCVIP_MEM_FLAG_NONE               = 0x0000,
	/* Physical contiguous. */
	GCVIP_MEM_FLAG_CONTIGUOUS         = 0x0001,
	/* Physical non contiguous. */
	GCVIP_MEM_FLAG_NON_CONTIGUOUS     = 0x0002,
	/* Need 32bit address. */
	GCVIP_MEM_FLAG_4GB_ADDR           = 0x0004,
	/* without mmaped VIP's MMU page */
	GCVIP_MEM_FLAG_NO_MMU_PAGE        = 0x0008,
	/* user memory PFN map */
	GCVIP_MEM_FLAG_USER_MEMORY_PFN    = 0x0010,
	/* user memory page map */
	GCVIP_MEM_FLAG_USER_MEMORY_PAGE   = 0x0020,
	/* need map user space logical address */
	GCVIP_MEM_FLAG_MAP_USER           = 0x0040,
	/* allocate physical memory 1M byte contiguous */
	GCVIP_MEM_FLAG_1M_CONTIGUOUS      = 0x0080,
	/* allocate memory for CMA */
	GCVIP_MEM_FLAG_CMA                = 0x00100,
	GCVIP_MEM_FLAG_NONE_CACHE         = 0x00200,
	GCVIP_MEM_FLAG_MAX,
} gckvip_mem_flag_e;

typedef enum _gckvip_video_memory_type {
	GCVIP_VIDEO_MEMORY_TYPE_NONE               = 0x000,
	/* indicate this memory is allocated from video memory heap */
	GCVIP_VIDEO_MEMORY_TYPE_VIDO_HEAP          = 0x001,
	/* indicate this memory is allocated from dynamic memory */
	GCVIP_VIDEO_MEMORY_TYPE_DYN_ALLOC          = 0x002,
	/* indicate this memory is created from user logical */
	GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER_LOGICAL  = 0x004,
	/* indicate this memory is created from user physical */
	GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER_PHYSICAL = 0x008,
	GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER = GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER_LOGICAL |
										GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER_PHYSICAL,

	/* indicate this memory is normal memory */
	GCVIP_VIDEO_MEMORY_TYPE_NORMAL             = 0x010,
	/* indicate this memory is secure memory */
	GCVIP_VIDEO_MEMORY_TYPE_SECURE             = 0x020,

} gckvip_video_memory_type_e;

enum {
	GCVIP_MMU_1M_PAGE         = 0,
	GCVIP_MMU_4K_PAGE         = 1,
};

#define gcdMMU_MTLB_SHIFT           24 /* 16Mbytes per-MTLB */
#define gcdMMU_STLB_4K_SHIFT        12
#define gcdMMU_STLB_64K_SHIFT       16
#define gcdMMU_STLB_1M_SHIFT        20
#define gcdMMU_STLB_16M_SHIFT       24

#define gcdMMU_MTLB_BITS            (32 - gcdMMU_MTLB_SHIFT)
#define gcdMMU_PAGE_4K_BITS         gcdMMU_STLB_4K_SHIFT
#define gcdMMU_STLB_4K_BITS         (32 - gcdMMU_MTLB_BITS - gcdMMU_PAGE_4K_BITS)
#define gcdMMU_PAGE_64K_BITS        gcdMMU_STLB_64K_SHIFT
#define gcdMMU_STLB_64K_BITS        (32 - gcdMMU_MTLB_BITS - gcdMMU_PAGE_64K_BITS)
#define gcdMMU_PAGE_1M_BITS         gcdMMU_STLB_1M_SHIFT
#define gcdMMU_STLB_1M_BITS         (32 - gcdMMU_MTLB_BITS - gcdMMU_PAGE_1M_BITS)
#define gcdMMU_PAGE_16M_BITS        gcdMMU_STLB_16M_SHIFT
#define gcdMMU_STLB_16M_BITS        4

#define gcdMMU_MTLB_ENTRY_NUM       (1 << gcdMMU_MTLB_BITS)
#define gcdMMU_MTLB_SIZE            (gcdMMU_MTLB_ENTRY_NUM << 2)
#define gcdMMU_STLB_4K_ENTRY_NUM    (1 << gcdMMU_STLB_4K_BITS)
#define gcdMMU_STLB_4K_SIZE         (gcdMMU_STLB_4K_ENTRY_NUM << 2)
#define gcdMMU_PAGE_4K_SIZE         (1 << gcdMMU_STLB_4K_SHIFT)
#define gcdMMU_STLB_64K_ENTRY_NUM   (1 << gcdMMU_STLB_64K_BITS)
#define gcdMMU_STLB_64K_SIZE        (gcdMMU_STLB_64K_ENTRY_NUM << 2)
#define gcdMMU_PAGE_64K_SIZE        (1 << gcdMMU_STLB_64K_SHIFT)
#define gcdMMU_STLB_1M_ENTRY_NUM    (1 << gcdMMU_STLB_1M_BITS)
#define gcdMMU_STLB_1M_SIZE         (gcdMMU_STLB_1M_ENTRY_NUM << 2)
#define gcdMMU_PAGE_1M_SIZE         (1 << gcdMMU_STLB_1M_SHIFT)
#define gcdMMU_STLB_16M_ENTRY_NUM   (1 << gcdMMU_STLB_16M_BITS)
#define gcdMMU_STLB_16M_SIZE        (gcdMMU_STLB_16M_ENTRY_NUM << 2)
#define gcdMMU_PAGE_16M_SIZE        (1 << gcdMMU_STLB_16M_SHIFT)

#define gcdMMU_MTLB_MASK            (~((1U << gcdMMU_MTLB_SHIFT)-1))
#define gcdMMU_STLB_4K_MASK         ((~0U << gcdMMU_STLB_4K_SHIFT) ^ gcdMMU_MTLB_MASK)
#define gcdMMU_PAGE_4K_MASK         (gcdMMU_PAGE_4K_SIZE - 1)
#define gcdMMU_STLB_64K_MASK        ((~((1U << gcdMMU_STLB_64K_SHIFT)-1)) ^ gcdMMU_MTLB_MASK)
#define gcdMMU_PAGE_64K_MASK        (gcdMMU_PAGE_64K_SIZE - 1)
#define gcdMMU_STLB_1M_MASK         ((~((1U << gcdMMU_STLB_1M_SHIFT)-1)) ^ gcdMMU_MTLB_MASK)
#define gcdMMU_PAGE_1M_MASK         (gcdMMU_PAGE_1M_SIZE - 1)
#define gcdMMU_STLB_16M_MASK        0x0F000000
#define gcdMMU_PAGE_16M_MASK        (gcdMMU_PAGE_16M_SIZE - 1)

/* Page offset definitions. */
#define gcdMMU_OFFSET_4K_BITS       (32 - gcdMMU_MTLB_BITS - gcdMMU_STLB_4K_BITS)
#define gcdMMU_OFFSET_4K_MASK       ((1U << gcdMMU_OFFSET_4K_BITS) - 1)
#define gcdMMU_OFFSET_64K_BITS      (32 - gcdMMU_MTLB_BITS - gcdMMU_STLB_64K_BITS)
#define gcdMMU_OFFSET_64K_MASK      ((1U << gcdMMU_OFFSET_64K_BITS) - 1)
#define gcdMMU_OFFSET_1M_BITS       (32 - gcdMMU_MTLB_BITS - gcdMMU_STLB_1M_BITS)
#define gcdMMU_OFFSET_1M_MASK       ((1U << gcdMMU_OFFSET_1M_BITS) - 1)
#define gcdMMU_OFFSET_16M_BITS      (32 - gcdMMU_MTLB_BITS)
#define gcdMMU_OFFSET_16M_MASK      ((1U << gcdMMU_OFFSET_16M_BITS) - 1)

#define gcdMMU_MTLB_ENTRY_HINTS_BITS 6
#define gcdMMU_MTLB_ENTRY_STLB_MASK  (~((1U << gcdMMU_MTLB_ENTRY_HINTS_BITS) - 1))

#define gcdMMU_MTLB_PRESENT         0x00000001
#define gcdMMU_MTLB_EXCEPTION       0x00000002
#define gcdMMU_MTLB_4K_PAGE         (0 << 2)
#define gcdMMU_MTLB_64K_PAGE        (1 << 2)
#define gcdMMU_MTLB_1M_PAGE         (2 << 2)
#define gcdMMU_MTBL_16M_PAGE        (3 << 2)

#define gcdMMU_STLB_PRESENT         0x00000001
#define gcdMMU_STLB_EXCEPTION       0x00000002
#define gcdMMU_STBL_WRITEABLE       0x00000004

/* You can configure total video memory size and 1M page size for decreasing MMU tale size */

/* maximum 4K page size */
#define gcdMMU_4K_PAGE_VIDEO_MEMORY_SIZE     (1024 << 20)

/* maximum reserved memory size + 1M dyna alloc memory */
#define gcdMMU_1M_PAGE_VIDEO_MEMORY_SIZE     (1536 << 20)

/* maximum video memory size */
#define gcdMMU_TOTAL_VIDEO_MEMORY            (gcdMMU_4K_PAGE_VIDEO_MEMORY_SIZE + gcdMMU_1M_PAGE_VIDEO_MEMORY_SIZE)


#define gcdMMU_1K_MODE_ONE_MTLB_MEMORY       (0x1000000)  /* 16M bytes */
#define gcdMMU_1M_MTLB_COUNT        (gcdMMU_1M_PAGE_VIDEO_MEMORY_SIZE / gcdMMU_1K_MODE_ONE_MTLB_MEMORY)
#define gcdMMU_4K_MTLB_COUNT        (gcdMMU_4K_PAGE_VIDEO_MEMORY_SIZE / gcdMMU_1K_MODE_ONE_MTLB_MEMORY)


typedef struct _gckvip_mmu_page_info {
	vip_uint32_t mtlb_start;
	vip_uint32_t mtlb_end;
	vip_uint32_t stlb_start;
	vip_uint32_t stlb_end;
	vip_uint32_t page_type;
} gckvip_mmu_page_info_t;

typedef struct _gckvip_dyn_allocate_node {
	/* a handle of allocate */
	void *alloc_handle;

	/* VIP MMU page table information */
	gckvip_mmu_page_info_t mmu_page_info;

	/***allocator output physical_table/physical_num/size_table in gc_vip_kernel_allocator.c****/
	/* the phyiscal address of each page(segment) */
	phy_address_t *physical_table;
	/* the number of physical_table element */
	vip_uint32_t physical_num;
	/* the size of each page table element */
	vip_uint32_t *size_table;

	/* the number of page, Linux only? */
	vip_uint32_t num_pages;
	/* user space logical address. Linux only? */
	vip_uint8_t *user_logical;
	/* kernel space logical address. Linux only?
	  shoule be equal to user_logical and physical in RTOS?
	*/
	vip_uint8_t *kerl_logical;
	/* VIP's virtual address */
	vip_uint32_t vip_virtual_address;

	/*  the total size of this video memory */
	vip_uint32_t size;

	/*  a handle for flush CPU's cache */
	void *flush_cache_handle;

	/* video memory flag, see gckvip_mem_flag_e */
	vip_uint32_t mem_flag;
} gckvip_dyn_allocate_node_t;

typedef struct _gckvip_video_mem_handle {
	vip_uint8_t memory_type;

	union {
#if vpmdENABLE_VIDEO_MEMORY_HEAP
		gckvip_heap_node_t *heap_node;
#endif
		gckvip_dyn_allocate_node_t dyn_node;
	} node;

} gckvip_video_mem_handle_t;

/************** function defines *****************/
vip_status_e gckvip_mem_heap_init(
	gckvip_context_t *context
);

vip_status_e gckvip_mem_heap_destroy(
	gckvip_context_t *context
);

vip_status_e gckvip_mem_get_cpuphysical(
	gckvip_context_t *context,
	void *handle,
	void *logical,
	phy_address_t *physical
);

vip_status_e gckvip_mem_get_kernellogical(
	gckvip_context_t *context,
	void *handle,
	vip_uint32_t physical,
	void **logical
);

vip_status_e gckvip_mem_get_userlogical(
	gckvip_context_t *context,
	void *handle,
	vip_uint32_t physical,
	void **logical
);

vip_status_e gckvip_mem_get_vipvirtual(
	gckvip_context_t *context,
	void *handle,
	phy_address_t physical,
	vip_uint32_t *virtual
);

/*
@brief allocate a video memory from heap or system(MMU enabled).
@param context, the contect of kernel space.
@param size, the size of video memory be allocated.
@param handle, the handle of video memory.
@param memory, kernel space logical address.
@param physical,
    disable MMU, physical is CPU's physical address.
    enable MMU, physical is VIP's virtual address.
@param align the size of video memory alignment.
@flag the flag of this video memroy. see gckvip_video_mem_alloc_flag_e.
*/
vip_status_e gckvip_mem_allocate_videomemory(
	gckvip_context_t *context,
	vip_uint32_t size,
	void **handle,
	void **memory,
	vip_uint32_t *physical,
	vip_uint32_t align,
	vip_uint32_t alloc_flag
);

vip_status_e gckvip_mem_free_videomemory(
	gckvip_context_t *context,
	void *handle
);

/*
@brief flush video memory CPU cache
@param handle the video memory handle
@param physical flush memory start physical address.
@param logical flush memory start logical addrss.
@param size the size of memory be flushed.
@param type The type of operate cache. see gckvip_cache_type_e.
*/
#if vpmdENABLE_FLUSH_CPU_CACHE
vip_status_e gckvip_flush_cache(
	void *handle,
	vip_uint32_t physical,
	void *logical,
	vip_uint32_t size,
	gckvip_cache_type_e type
);
#endif

#if vpmdENABLE_MMU
/*
@brief wrap user memory to VIP virtual address.
@param IN context, the contect of kernel space.
@param IN physical_table Physical address table. should be wraped for VIP hardware.
@param IN size_table The size of physical memory for each physical_table element.
@param IN physical_num The number of physical table element.
@param IN memory_type The type of this VIP buffer memory. see vip_buffer_memory_type_e.
@param OUT virtual, VIP virtual address.
@param OUT handle, the handle of video memory.
*/
vip_status_e gckvip_mem_wrap_userphysical(
	gckvip_context_t *context,
	vip_address_t *physical_table,
	vip_uint32_t *size_table,
	vip_uint32_t physical_num,
	vip_uint32_t memory_type,
	vip_uint32_t *virtual,
	void **handle
);

/*
@brief un-wrap user memory to VIP virtual address.
@param context, the contect of kernel space.
@param handle, the handle of video memory.
@param virtual, VIP virtual address.
*/
vip_status_e gckvip_mem_unwrap_userphysical(
	gckvip_context_t *context,
	void *handle,
	vip_uint32_t virtual
);

/*
@brief wrap user memory to VIP virtual address.
@param IN context, the contect of kernel space.
@param IN logical, the user space logical address(handle).
@param IN size, the size of the memory.
@param IN memory_type The type of this VIP buffer memory. see vip_buffer_memory_type_e.
@param OUT virtual, VIP virtual address.
@param OUT handle, the handle of video memory.
*/
vip_status_e gckvip_mem_wrap_usermemory(
	gckvip_context_t *context,
	vip_ptr logical,
	vip_uint32_t size,
	vip_uint32_t memory_type,
	vip_uint32_t *virtual,
	void **handle
);

vip_status_e gckvip_mem_unwrap_usermemory(
	gckvip_context_t *context,
	void *handle,
	vip_uint32_t virtual
);

vip_status_e gckvip_mem_map_dyn_memory(
	gckvip_context_t *context,
	gckvip_mmu_page_info_t *page_info,
	phy_address_t *physical_table,
	vip_uint32_t num_page,
	vip_uint32_t *size_table,
	vip_uint32_t page_type,
	vip_uint32_t *virtual
);

vip_status_e gckvip_mem_unmap_dyn_memory(
	gckvip_context_t *context,
	void *handle
);

vip_status_e gckvip_mem_mmu_init(
	gckvip_context_t *context
);

vip_status_e gckvip_mem_mmu_uninit(
	gckvip_context_t *context
);

vip_status_e gckvip_mem_mmu_enable(
	gckvip_context_t *context
);

#if vpmdENABLE_SECURE
vip_status_e gckvip_mem_mmu_switch(
	gckvip_context_t *context
);
#endif
#endif

#endif
