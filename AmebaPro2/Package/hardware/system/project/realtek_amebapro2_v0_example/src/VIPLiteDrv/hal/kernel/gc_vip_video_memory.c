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

#include <gc_vip_hardware.h>
#include <gc_vip_kernel.h>
#include <gc_vip_kernel_port.h>
#include <gc_vip_kernel_drv.h>
#include <gc_vip_video_memory.h>
#include <gc_vip_kernel_allocator.h>
#include <gc_vip_kernel_debug.h>
#if vpmdENABLE_DEBUGFS
#include <gc_vip_kernel_os_debug.h>
#endif


#if vpmdENABLE_MMU
#define _write_page_entry(page_entry, entry_value) \
        *(vip_uint32_t*)(page_entry) = (vip_uint32_t)(entry_value)

#define _read_page_entry(page_entry)  *(vip_uint32_t*)(page_entry)

typedef struct _gcvip_mmu_table_entry {
	vip_uint32_t low;
	vip_uint32_t high;
} gcvip_mmu_table_entry_t;

static vip_uint32_t mmu_set_page(
	vip_uint32_t page_address,
	vip_uint32_t page_address_ext
)
{
	vip_uint32_t entry = page_address
						 /* AddressExt */
						 | (page_address_ext << 4)
						 /* Ignore exception */
						 | (0 << 1)
						 /* Present */
						 | (1 << 0);

	/* writable */
	entry |= (1 << 2);

	return entry;
}

/*
@brief allocate MMU pages.
@param context, the contect of kernel space.
@param num_mtlb, the number of MTLB.
@param, num_stlb, the number of STLB.
@param, page_type, the type of this page. GCVIP_MMU_1M_PAGE / GCVIP_MMU_4K_PAGE ...
@param, info, page information
*/
static vip_status_e mmu_get_page_info(
	gckvip_context_t *context,
	vip_int32_t num_mtlb,
	vip_int32_t num_stlb,
	vip_uint8_t page_type,
	gckvip_mmu_page_info_t *info
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0, j = 0;
	vip_uint32_t count = 0;
	vip_uint32_t *stlb_logical = VIP_NULL;
	vip_uint32_t stlb_entry_num = (GCVIP_MMU_1M_PAGE == page_type) ? gcdMMU_STLB_1M_ENTRY_NUM : \
								  gcdMMU_STLB_4K_ENTRY_NUM;
	vip_uint32_t mtlb_start = 0, mtlb_end = 0;

	if ((0 > num_mtlb) || (0 > num_stlb) || (VIP_NULL == info)) {
		PRINTK_E("failed to get stlb, parameter is 0 or tlb < 0\n");
		return VIP_ERROR_IO;
	}

	if (GCVIP_MMU_1M_PAGE == page_type) {
		mtlb_start = 0;
		mtlb_end = gcdMMU_1M_MTLB_COUNT;
	} else {
		mtlb_start = gcdMMU_1M_MTLB_COUNT;
		mtlb_end = gcdMMU_1M_MTLB_COUNT + gcdMMU_4K_MTLB_COUNT;
	}

	for (i = mtlb_start; i < mtlb_end; i++) {
		if (GCVIP_MMU_1M_PAGE == page_type) {
			stlb_logical = (vip_uint32_t *)((vip_uint8_t *)context->ptr_STLB_1M->logical + \
											(i * gcdMMU_STLB_1M_SIZE));
		} else if (GCVIP_MMU_4K_PAGE == page_type) {
			stlb_logical = (vip_uint32_t *)((vip_uint8_t *)context->ptr_STLB_4K->logical + \
											((i - gcdMMU_1M_MTLB_COUNT) * gcdMMU_STLB_4K_SIZE));
		} else {
			PRINTK_E("free page info, page type error\n");
			return VIP_ERROR_INVALID_ARGUMENTS;
		}

		for (j = 0; j < stlb_entry_num; j++) {
			if (0 == stlb_logical[j]) {
				if (0 == count) {
					info->mtlb_start = i;
					info->stlb_start = j;
				}

				count++;
				if (count == (vip_uint32_t)num_stlb) {
					info->mtlb_end = i;
					info->stlb_end = j;
					break;
				}
			} else {
				count = 0;
			}
		}

		if (j < stlb_entry_num) {
			break;
		}
	}

	if (i >= mtlb_end) {
		PRINTK_E("failed to get stlb, without enough space, 1M MTLB count=%d\n",
				 gcdMMU_1M_MTLB_COUNT);
		gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
	}

	PRINTK_D("map mmu get page type=%s, mtlb_num=%d, stlb_num=%d, mtlb: %d ~ %d, stlb: %d ~ %d\n",
			 (page_type == GCVIP_MMU_1M_PAGE) ? "1M" : "4K", num_mtlb, num_stlb,
			 info->mtlb_start, info->mtlb_end, info->stlb_start, info->stlb_end);

onError:
	return status;
}

/*
@brief free MMU page info.
@param context, the contect of kernel space.
@param, page_type, the type of this page. GCVIP_MMU_1M_PAGE / GCVIP_MMU_4K_PAGE ...
@param, page_info, page information
*/
static vip_status_e mmu_free_page_info(
	gckvip_context_t *context,
	vip_uint8_t page_type,
	gckvip_mmu_page_info_t *page_info
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0, j = 0;
	vip_uint32_t *stlb_logical = VIP_NULL;
	vip_uint32_t stlb_entry_num = (GCVIP_MMU_1M_PAGE == page_type) ? gcdMMU_STLB_1M_ENTRY_NUM : \
								  gcdMMU_STLB_4K_ENTRY_NUM;

	if (page_info == VIP_NULL) {
		PRINTK_E("failed to free page info\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	for (i = page_info->mtlb_start; i <= page_info->mtlb_end; i++) {
		vip_uint32_t s_last = (i == page_info->mtlb_end) ? page_info->stlb_end : (stlb_entry_num - 1);
		vip_uint32_t s_start = 0;

		if (GCVIP_MMU_1M_PAGE == page_type) {
			stlb_logical = (vip_uint32_t *)((vip_uint8_t *)context->ptr_STLB_1M->logical +
											(i * gcdMMU_STLB_1M_SIZE));
		} else if (GCVIP_MMU_4K_PAGE == page_type) {
			stlb_logical = (vip_uint32_t *)((vip_uint8_t *)context->ptr_STLB_4K->logical +
											((i - gcdMMU_1M_MTLB_COUNT) * gcdMMU_STLB_4K_SIZE));
		} else {
			PRINTK_E("free page info, page type error\n");
			return VIP_ERROR_INVALID_ARGUMENTS;
		}

		if (i > page_info->mtlb_start) {
			s_start = 0;
		} else {
			s_start = page_info->stlb_start;
		}

		for (j = s_start; j <= s_last; j++) {
			_write_page_entry(stlb_logical + j, 0);
		}
	}

	PRINTK_I("free page mtlb: %d ~ %d, stlb : %d ~ %d, page type=%s\n",
			 page_info->mtlb_start, page_info->mtlb_end, page_info->stlb_start,
			 page_info->stlb_end, (page_type == GCVIP_MMU_1M_PAGE) ? "1M" : "4K");

	return status;
}

/*
@brief initialize all MTLB bits.
@param context, the contect of kernel space.
*/
static vip_status_e mmu_fill_mtlb(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0;
	vip_uint32_t stlb_physical = 0;
	vip_uint32_t *mtlb_logical = (vip_uint32_t *)context->MTLB.logical;
	vip_uint32_t mtlb_value = 0;

	/* 0 ~~ 1m_mtlb_num MTLB for 1Mbytes page */
	stlb_physical = context->ptr_STLB_1M->physical;
	for (i = 0; i < gcdMMU_1M_MTLB_COUNT; i++) {
		mtlb_value = stlb_physical
					 /* 1MB page size */
					 | (1 << 3)
					 /* Ignore exception */
					 | (0 << 1)
					 /* Present */
					 | (1 << 0);

		_write_page_entry(mtlb_logical + i, mtlb_value);

		stlb_physical += gcdMMU_STLB_1M_SIZE;
	}

	/* 1m_mtlb_num ~~  (gcdMMU_1M_MTLB_COUNT + gcdMMU_4K_MTLB_COUNT) for 4Kbytes page */
	stlb_physical = context->ptr_STLB_4K->physical;
	for (i = gcdMMU_1M_MTLB_COUNT; i < (gcdMMU_1M_MTLB_COUNT + gcdMMU_4K_MTLB_COUNT); i++) {
		mtlb_value = stlb_physical
					 /* 4KB page size */
					 | (0 << 2)
					 /*Ignore exception */
					 | (0 << 1)
					 /* Present */
					 | (1 << 0);

		_write_page_entry(mtlb_logical + i, mtlb_value);

		stlb_physical += gcdMMU_STLB_4K_SIZE;
	}

#if vpmdENABLE_FLUSH_CPU_CACHE
	gckvip_flush_cache(context->MTLB.handle, context->MTLB.physical,
					   context->MTLB.logical, context->MTLB.size, GCKVIP_CACHE_FLUSH);
#endif

	return status;
}

/*
@brief fill stlb.
@param context, the contect of kernel space.
@param info mmu page information.
@param page_type the type of page should be mapped. GCVIP_MMU_1M_PAGE/GCVIP_MMU_4K_PAGE
*/
static vip_status_e mmu_fill_stlb(
	gckvip_context_t *context,
	gckvip_mmu_page_info_t *info,
	vip_uint8_t page_type,
	phy_address_t physical
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0;
	vip_uint32_t *stlb_logical = VIP_NULL;
	vip_uint32_t s_start = 0;
	vip_uint32_t stlb_entry_num = 0;
	vip_uint32_t max_mtlb_num = 0;
	phy_address_t physical_align = 0;
	vip_uint32_t physical_low = 0;
	vip_uint32_t physical_high = 0;
	vip_uint32_t page_size = 0;
	vip_uint32_t phy_start = 0;

	if ((VIP_NULL == context) || (VIP_NULL == info)) {
		PRINTK_E("failed to fill stlb, parameter is NULL\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	switch (page_type) {
	case GCVIP_MMU_1M_PAGE: {
		stlb_entry_num = gcdMMU_STLB_1M_ENTRY_NUM;
		max_mtlb_num = gcdMMU_1M_MTLB_COUNT;
		physical_align = physical & ~gcdMMU_PAGE_1M_MASK;
		page_size = gcdMMU_PAGE_1M_SIZE;
	}
	break;

	case GCVIP_MMU_4K_PAGE: {
		stlb_entry_num = gcdMMU_STLB_4K_ENTRY_NUM;
		max_mtlb_num = gcdMMU_1M_MTLB_COUNT + gcdMMU_4K_MTLB_COUNT;
		physical_align = physical & ~gcdMMU_PAGE_4K_MASK;
		page_size = gcdMMU_PAGE_4K_SIZE;
	}
	break;

	default:
		PRINTK_E("failed to fill stlb, not support this page type=%d\n", page_type);
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}


	physical_low = (vip_uint32_t)(physical_align & 0xFFFFFFFF);
	if (physical_align & 0xFFFFFFFF00000000ULL) {
		/* make 32-bits system happy */
		phy_address_t phy_tmp = (physical_align >> 16);
		physical_high = (vip_uint32_t)(phy_tmp >> 16);
	} else {
		physical_high = 0;
	}

	phy_start = physical_low;

	for (i = info->mtlb_start; i <= info->mtlb_end; i++) {
		vip_uint32_t s_last = (i == info->mtlb_end) ? info->stlb_end : (stlb_entry_num - 1);

		if (i >= max_mtlb_num) {
			PRINTK_E("MMU MTLB size is greater than max mtlb num %d > %d, page type=%d\n",
					 i, max_mtlb_num, page_type);
			gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
		}

		if (i > info->mtlb_start) {
			s_start = 0;
		} else {
			s_start = info->stlb_start;
		}

		if (GCVIP_MMU_1M_PAGE == page_type) {
			stlb_logical = (vip_uint32_t *)((vip_uint8_t *)context->ptr_STLB_1M->logical + \
											(i * gcdMMU_STLB_1M_SIZE));
		} else if (GCVIP_MMU_4K_PAGE == page_type) {
			stlb_logical = (vip_uint32_t *)((vip_uint8_t *)context->ptr_STLB_4K->logical + \
											((i - gcdMMU_1M_MTLB_COUNT) * gcdMMU_STLB_4K_SIZE));
		}

		while (s_start <= s_last) {
			vip_uint32_t entry_value = 0;
			entry_value = mmu_set_page(phy_start, physical_high);

			_write_page_entry(stlb_logical + s_start, entry_value);

			if (GCVIP_MMU_1M_PAGE == page_type) {
				PRINTK_D("mtlb: %d, stlb: %d, phy_h=0x%x, phy_l=0x%x, size=0x%x\n",
						 i, s_start, physical_high, phy_start, page_size);
			}

			phy_start += page_size;
			s_start++;
		}
	}

onError:
	return status;
}

/*
@brief mmap axi sram.
@param context, the contect of kernel space.
*/
static vip_status_e mmu_map_axi_sram(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_mmu_page_info_t info;
	vip_int32_t num_stlb = 0;
	vip_int32_t num_mtlb = 0;
	vip_uint32_t *stlb_logical = VIP_NULL;
	vip_uint32_t axi_address = context->axi_sram_address;
	vip_uint32_t phy_start = axi_address & ~gcdMMU_PAGE_1M_MASK;
	vip_uint32_t offset = axi_address - phy_start;
	vip_uint32_t i = 0;

	num_stlb = (context->axi_sram_size + gcdMMU_PAGE_1M_SIZE - 1) / gcdMMU_PAGE_1M_SIZE;
	num_mtlb = (context->axi_sram_size + (1 << gcdMMU_MTLB_SHIFT) - 1) / (1 << gcdMMU_MTLB_SHIFT);
	if (offset > 0) {
		num_stlb += 1; /* offset in page */
	}

	if (num_stlb > 0) {
		vip_uint32_t entry_value = 0;
		PRINTK_I("mapping AIX-SRAM..\n");
		gcOnError(mmu_get_page_info(context, num_mtlb, num_stlb, GCVIP_MMU_1M_PAGE, &info));

		context->axi_sram_address = (info.mtlb_start << gcdMMU_MTLB_SHIFT) |
									(info.stlb_start << gcdMMU_STLB_1M_SHIFT) |
									(axi_address & gcdMMU_PAGE_1M_MASK);

		PRINTK_I("axi sram size=0x%xbytes, mtlb: %d  ~ %d, stlb: %d ~ %d, "
				 "physical=0x%08x to virtual=0x%08x\n",
				 context->axi_sram_size, info.mtlb_start, info.mtlb_end, info.stlb_start,
				 info.stlb_end, axi_address, context->axi_sram_address);

		stlb_logical = (vip_uint32_t *)((vip_uint8_t *)context->ptr_STLB_1M->logical + \
										(info.mtlb_start * gcdMMU_STLB_1M_SIZE));

		for (i = info.stlb_end + 1; i < gcdMMU_STLB_1M_ENTRY_NUM; i++) {
			entry_value = mmu_set_page(0xFFFFFFFF & ~gcdMMU_PAGE_1M_MASK, 0xF);
			_write_page_entry(stlb_logical + i, entry_value);
		}

		status = mmu_fill_stlb(context, &info, GCVIP_MMU_1M_PAGE, phy_start);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to fill stlb in map AXI SRAM\n");
		}
	}

	return status;

onError:
	PRINTK_E("failed to map AXI-SRAM status=%d.\n", status);
	return status;
}

/*
@brief mmap vip sram.
@param context, the contect of kernel space.
*/
static vip_status_e mmu_map_vip_sram(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_mmu_page_info_t info;
	vip_int32_t num_stlb = 0;
	vip_int32_t num_mtlb = 0;
	vip_uint32_t *stlb_logical = VIP_NULL;
	phy_address_t phy_start = 0xFFF00000;
	vip_uint32_t i = 0;

	num_stlb = (context->vip_sram_size + gcdMMU_PAGE_1M_SIZE - 1) / gcdMMU_PAGE_1M_SIZE;
	num_mtlb = (context->vip_sram_size + (1 << gcdMMU_MTLB_SHIFT) - 1) / (1 << gcdMMU_MTLB_SHIFT);

	if (num_stlb > 0) {
		vip_uint32_t entry_value = 0;
		vip_int32_t try_count = gcdMMU_STLB_1M_ENTRY_NUM;
		PRINTK_I("mapping VIP-SRAM..\n");
		while (try_count > 0) {
			gcOnError(mmu_get_page_info(context, num_mtlb, num_stlb, GCVIP_MMU_1M_PAGE, &info));
			try_count--;
			if (4 == info.stlb_start) {
				/* re-Map VIP-sram to 0x400000 address */
				break;
			} else {
				/* mark this page is used */
				stlb_logical = (vip_uint32_t *)((vip_uint8_t *)context->ptr_STLB_1M->logical + \
												(info.mtlb_start * gcdMMU_STLB_1M_SIZE));
				entry_value = mmu_set_page(0xFFFFFFFF & ~gcdMMU_PAGE_1M_MASK, 0xF);
				_write_page_entry(stlb_logical + info.stlb_start, entry_value);
			}
		}
		stlb_logical = (vip_uint32_t *)((vip_uint8_t *)context->ptr_STLB_1M->logical + \
										(info.mtlb_start * gcdMMU_STLB_1M_SIZE));

		for (i = info.stlb_end + 1; i < gcdMMU_STLB_1M_ENTRY_NUM; i++) {
			entry_value = mmu_set_page(0xFFFFFFFF & ~gcdMMU_PAGE_1M_MASK, 0xF);
			_write_page_entry(stlb_logical + i, entry_value);
		}

		context->vip_sram_address = (info.mtlb_start << gcdMMU_MTLB_SHIFT) |
									(info.stlb_start << gcdMMU_STLB_1M_SHIFT);

		PRINTK_I("vip sram size=0x%xbytes, mtlb : %d ~ %d, stlb : %d ~ %d, "
				 "physical=0x%" PRIx64" to virtual=0x%08x\n",
				 context->vip_sram_size, info.mtlb_start, info.mtlb_end,
				 info.stlb_start, info.stlb_end, phy_start,
				 context->vip_sram_address);

		status = mmu_fill_stlb(context, &info, GCVIP_MMU_1M_PAGE, phy_start);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to fill stlb in map VIP SRAM\n");
		}
	}

	return status;

onError:
	PRINTK_E("failed to map VIP-SRAM status=%d.\n", status);
	return status;
}

/*
@brief mmap reserve memory heap.
@param context, the contect of kernel space.
*/
#if vpmdENABLE_VIDEO_MEMORY_HEAP
static vip_status_e mmu_map_reserve_memory(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;
	phy_address_t heap_phy_base = context->physical_base;
	vip_uint32_t heap_size = context->mem_size;
	phy_address_t phy_start = heap_phy_base & ~gcdMMU_PAGE_1M_MASK;
	vip_uint32_t m_start = 0;
	vip_uint32_t s_start = 0;
	vip_int32_t num_mtlb = 0;
	vip_int32_t num_stlb = 0;
	gckvip_mmu_page_info_t info;
	vip_uint32_t offset = (vip_uint32_t)(heap_phy_base - phy_start);

	if (heap_size > gcdMMU_1M_PAGE_VIDEO_MEMORY_SIZE) {
		PRINTK_E("reserve memory size %d is bigger than 1M page size %d\n",
				 heap_size, gcdMMU_1M_PAGE_VIDEO_MEMORY_SIZE);
		return VIP_ERROR_IO;
	}


	/* 16Mbytes per-MTLB, 1Mbytes per-STLB */
	num_stlb = (heap_size + gcdMMU_PAGE_1M_SIZE - 1) / gcdMMU_PAGE_1M_SIZE;
	num_mtlb = (heap_size + (1 << gcdMMU_MTLB_SHIFT) - 1) / (1 << gcdMMU_MTLB_SHIFT);
	if (offset > 0) {
		num_stlb += 1; /* offset in page */
	}

	if (num_stlb > 0) {
		PRINTK_I("mapping reserve memory..\n");
		gcOnError(mmu_get_page_info(context, num_mtlb, num_stlb, GCVIP_MMU_1M_PAGE, &info));

		m_start = info.mtlb_start;
		s_start = info.stlb_start;

		context->vip_virtual_base = (m_start << gcdMMU_MTLB_SHIFT) |
									(s_start << gcdMMU_STLB_1M_SHIFT) |
									(heap_phy_base & gcdMMU_PAGE_1M_MASK);

		PRINTK_I("reserve memroy physical=0x%" PRIx64", vip virtual=0x%08x,"
				 "size=0x%xbytes, mtlb : %d ~ %d, stlb : %d ~ %d\n",
				 heap_phy_base, context->vip_virtual_base, heap_size, m_start,
				 info.mtlb_end, s_start, info.stlb_end);

		status = mmu_fill_stlb(context, &info, GCVIP_MMU_1M_PAGE, heap_phy_base);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to fill stlb in map reserve memory\n");
		}
	}

	return status;

onError:
	PRINTK_E("failed to map reserve memory status=%d.\n", status);
	return status;
}
#endif

/*
@brief commnit commands to setup MMU.
@param context, the contect of kernel space.
*/
static vip_status_e gcvip_mem_mmu_setup(
	gckvip_context_t *context
)
{
#define STATES_SIZE   8
	vip_status_e status = VIP_SUCCESS;
	void *handle = VIP_NULL;
	vip_uint32_t physical = 0;
	vip_uint32_t *logical = VIP_NULL;
	vip_uint32_t size = STATES_SIZE * sizeof(vip_uint32_t);
	vip_uint32_t idleState = 0;
	vip_int32_t try_count = 0;
	vip_uint32_t alloc_flag = GCVIP_VIDEO_MEM_ALLOC_FLAG_CONTIGUOUS |
							  GCVIP_VIDEO_MEM_ALLOC_FLAG_4GB_ADDR |
							  GCVIP_VIDEO_MEM_ALLOC_FLAG_NONE_CACHE |
							  GCVIP_VIDEO_MEM_ALLOC_FLAG_NO_MMU_PAGE;

	gcOnError(gckvip_mem_allocate_videomemory(context, size + APPEND_COMMAND_SIZE,
			  &handle, (void **)&logical, &physical,
			  gcdVIP_MEMORY_ALIGN_SIZE,
			  alloc_flag));
	PRINTK_I("mmu command size=%dbytes, logical=0x%" PRIx64", physical=0x%08x\n",
			 size, GCKVIPPTR_TO_UINT64(logical), physical);

	if (physical & 0xFFFFFFFF00000000ULL) {
		PRINTK_E("MMU initialize buffer only support 32bit physical address\n");
		gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
	}

	logical[0] = 0x0801006b;
	logical[1] = 0xfffe0000;
	logical[2] = 0x08010e12;
	logical[3] = 0x00490000;
	logical[4] = 0x08010e02;
	logical[5] = 0x00000701;
	logical[6] = 0x48000000;
	logical[7] = 0x00000701;

	/* Submit commands. */
	logical[STATES_SIZE] = (2 << 27);
	logical[STATES_SIZE + 1] = 0;
	gckvip_os_memorybarrier();
	size += END_SIZE;

#if vpmdENABLE_FLUSH_CPU_CACHE
	gckvip_flush_cache(handle, physical, logical, size, GCKVIP_CACHE_FLUSH);
#endif

	gckvip_write_register(0x00654, physical);
	gckvip_os_memorybarrier();
	gckvip_write_register(0x003A4, 0x00010000 | ((size + 7) >> 3));

	/* Wait until MMU configure finishes. */
	gckvip_read_register(0x00004, &idleState);
	while (((idleState & 0x01) != 0x01) && (try_count < 100)) {
		try_count++;
		gckvip_os_delay(1);
		gckvip_read_register(0x00004, &idleState);
	}

	if (try_count >= 100) {
		PRINTK_E("failed to setup MMU, idleState=0x%x, commands dump:\n", idleState);
#if vpmdENABLE_HANG_DUMP
		gckvip_dump_data(logical, physical, size);
		gckvip_dump_states(context);
#endif
		gcGoOnError(VIP_ERROR_TIMEOUT);
	}

	PRINTK_I("mmu setup check vip idle status=0x8%x, try_count=%d\n",
			 idleState, try_count);

onError:
	if (handle != VIP_NULL) {
		gckvip_mem_free_videomemory(context, handle);
	}

	return status;
}

#if vpmdENABLE_SECURE
/*
@brief initialize secure MMU page table and allocate MMU,
       map vip-sram, axi-sram, reseverd memory if you system have this.
@param context, the contect of kernel space.
*/
vip_status_e gckvip_mem_mmu_secure_init(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t alloc_flag = GCVIP_VIDEO_MEM_ALLOC_FLAG_NO_MMU_PAGE |
							  GCVIP_VIDEO_MEM_ALLOC_FLAG_4GB_ADDR |
							  GCVIP_VIDEO_MEM_ALLOC_FLAG_CONTIGUOUS |
							  GCVIP_VIDEO_MEM_ALLOC_FLAG_NONE_CACHE |
							  GCVIP_VIDEO_MEM_ALLOC_FLAG_SECURE_MEM;
	vip_uint32_t flush_mmu_flag = GCVIP_VIDEO_MEM_ALLOC_FLAG_4GB_ADDR |
								  GCVIP_VIDEO_MEM_ALLOC_FLAG_CONTIGUOUS |
								  GCVIP_VIDEO_MEM_ALLOC_FLAG_NONE_CACHE |
								  GCVIP_VIDEO_MEM_ALLOC_FLAG_SECURE_MEM;

	PRINTK_D("secure 1M MTLB count=%d, 4K MTLB count=%d, 1M entry count pre-MTLB=%d,"
			 "4K STLB entry count pre-MTLB=%d\n",
			 gcdMMU_1M_MTLB_COUNT, gcdMMU_4K_MTLB_COUNT,
			 gcdMMU_STLB_1M_ENTRY_NUM, gcdMMU_STLB_4K_ENTRY_NUM);

	PRINTK_D("secure 1M page memory size=%dMbytes, 4K page memory size=%dMbyte, one mtlb size=%dMbytes\n",
			 gcdMMU_1M_PAGE_VIDEO_MEMORY_SIZE / 1024 / 1024,
			 gcdMMU_4K_PAGE_VIDEO_MEMORY_SIZE / 1024 / 1024,
			 gcdMMU_1K_MODE_ONE_MTLB_MEMORY / 1024 / 1024);

	if ((gcdMMU_1M_MTLB_COUNT + gcdMMU_4K_MTLB_COUNT) > gcdMMU_MTLB_ENTRY_NUM) {
		PRINTK_E("secure failed init mmu more than max MTLB count\n");
		gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
	}

	context->work_mode = GCKVIP_WORK_MODE_SECURITY;

	context->secu_STLB_1M.size = gcdMMU_1M_MTLB_COUNT * gcdMMU_STLB_1M_SIZE;
	gcOnError(gckvip_mem_allocate_videomemory(context, context->secu_STLB_1M.size,
			  &context->secu_STLB_1M.handle,
			  (void **)&context->secu_STLB_1M.logical,
			  &context->secu_STLB_1M.physical,
			  1024,
			  alloc_flag));
	PRINTK_D("secure STLB 1M size=%dbytes, logical=0x%" PRIx64", physical=0x%08x\n",
			 context->secu_STLB_1M.size, GCKVIPPTR_TO_UINT64(context->secu_STLB_1M.logical),
			 context->secu_STLB_1M.physical);
	gckvip_os_zero_memory(context->secu_STLB_1M.logical, context->secu_STLB_1M.size);

	context->secu_STLB_4K.size = gcdMMU_4K_MTLB_COUNT * gcdMMU_STLB_4K_SIZE;
	gcOnError(gckvip_mem_allocate_videomemory(context, context->secu_STLB_4K.size,
			  &context->secu_STLB_4K.handle,
			  (void **)&context->secu_STLB_4K.logical,
			  &context->secu_STLB_4K.physical,
			  gcdVIP_MEMORY_ALIGN_SIZE,
			  alloc_flag));
	PRINTK_D("secure STLB 4K size=%dbytes, logical=%" PRIx64", physical=0x%08x\n",
			 context->secu_STLB_4K.size, GCKVIPPTR_TO_UINT64(context->secu_STLB_4K.logical),
			 context->secu_STLB_4K.physical);
	gckvip_os_zero_memory(context->secu_STLB_4K.logical, context->secu_STLB_4K.size);

	/* re-location secure mode page table */
	context->ptr_STLB_1M = &context->secu_STLB_1M;
	context->ptr_STLB_4K = &context->secu_STLB_4K;
	context->ptr_MMU_flush = &context->secu_MMU_flush;
	context->work_mode = GCKVIP_WORK_MODE_SECURITY;
	context->work_mode_last_submit = context->work_mode;

	mmu_fill_mtlb(context);

	status = mmu_map_vip_sram(context);
	if (status != VIP_SUCCESS) {
		PRINTK_E("secure failed to map vip sram\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	status = mmu_map_axi_sram(context);
	if (status != VIP_SUCCESS) {
		PRINTK_E("secure failed to map axi sram\n");
		gcGoOnError(VIP_ERROR_IO);
	}

#if vpmdENABLE_VIDEO_MEMORY_HEAP
	{
		vip_uint32_t cap = gckvip_heap_capability(&context->video_mem_heap);
		if (cap & GCVIP_VIDEO_MEM_ALLOC_FLAG_SECURE_MEM) {
			status = mmu_map_reserve_memory(context);
			if (status != VIP_SUCCESS) {
				PRINTK_E("secure failed to map reserve memory in secure mode\n");
				gcGoOnError(VIP_ERROR_IO);
			}
		}
	}
#endif

	/* fill flush mmu cache load states */
	context->secu_MMU_flush.size = FLUSH_MMU_STATES_SIZE + LINK_SIZE;
	gcOnError(gckvip_mem_allocate_videomemory(context, context->secu_MMU_flush.size,
			  &context->secu_MMU_flush.handle,
			  (void **)&context->secu_MMU_flush.logical,
			  &context->secu_MMU_flush.physical,
			  gcdVIP_MEMORY_ALIGN_SIZE,
			  flush_mmu_flag));
	PRINTK_D("secure MMU flush size=%dbytes, logical=0x%" PRIx64", vip virtual=0x%08x\n",
			 context->secu_MMU_flush.size, GCKVIPPTR_TO_UINT64(context->secu_MMU_flush.logical),
			 context->secu_MMU_flush.physical);
	gckvip_os_zero_memory(context->secu_MMU_flush.logical, context->secu_MMU_flush.size);

	{
		vip_uint32_t *data = (vip_uint32_t *)context->secu_MMU_flush.logical;
		vip_uint32_t count = 0;
		data[count] = ((8 << 27) | ((FLUSH_MMU_STATES_SIZE + 7) >> 3));
		count++;
		data[count] = context->secu_MMU_flush.physical + LINK_SIZE;
		count++;
		data[count] = 0x08010061;
		count++;
		data[count] = 0xffffff7f;
		count++;
		data[count] = 0x08010e02;
		count++;
		data[count] = 0x30000701;
		count++;
		data[count] = 0x48000000;
		count++;
		data[count] = 0x30000701;
		count++;
		data[count] = ((8 << 27) | ((FLUSH_MMU_STATES_SIZE + 7) >> 3));
		count++;
		data[count] = context->secu_MMU_flush.physical + FLUSH_MMU_STATES_SIZE;
		count++;
		if (count * sizeof(vip_uint32_t) > FLUSH_MMU_STATES_SIZE) {
			PRINTK_E("secure flush mmu cache memory overflow %d > %d\n",
					 count * sizeof(vip_uint32_t), FLUSH_MMU_STATES_SIZE);
			gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
		}
	}

	/* flush mmu command for switching page table */
	context->secu_MMU_flush_page.size = FLUSH_MMU_STATES_SIZE + LINK_SIZE;
	gcOnError(gckvip_mem_allocate_videomemory(context, context->secu_MMU_flush_page.size,
			  &context->secu_MMU_flush_page.handle,
			  (void **)&context->secu_MMU_flush_page.logical,
			  &context->secu_MMU_flush_page.physical,
			  gcdVIP_MEMORY_ALIGN_SIZE,
			  flush_mmu_flag));
	PRINTK_D("secu MMU flush page table size=%dbytes, logical=0x%" PRIx64", vip virtual=0x%08x\n",
			 context->secu_MMU_flush_page.size, GCKVIPPTR_TO_UINT64(context->secu_MMU_flush_page.logical),
			 context->secu_MMU_flush_page.physical);
	gckvip_os_zero_memory(context->secu_MMU_flush_page.logical, context->secu_MMU_flush_page.size);

	{
		vip_uint32_t *data = (vip_uint32_t *)context->secu_MMU_flush_page.logical;
		vip_uint32_t count = 0;
		data[count] = 0x08010061;
		count++;
		data[count] = 0xffffff7f;
		count++;
		data[count] = 0x08010e02;
		count++;
		data[count] = 0x30000701;
		count++;
		data[count] = 0x48000000;
		count++;
		data[count] = 0x30000701;
		count++;
		data[count] = (2 << 27);
		count++;
		data[count] = 0;
		count++;
		if (count * sizeof(vip_uint32_t) > FLUSH_MMU_STATES_SIZE) {
			PRINTK_E("secure flush mmu cache memory overflow %d > %d\n",
					 count * sizeof(vip_uint32_t), FLUSH_MMU_STATES_SIZE);
			gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
		}
		context->secu_MMU_flush_page.size = count * sizeof(vip_uint32_t);
	}

	context->flush_mmu = 1;

#if vpmdENABLE_FLUSH_CPU_CACHE
	gckvip_flush_cache(context->secu_STLB_1M.handle, context->secu_STLB_1M.physical,
					   context->secu_STLB_1M.logical, context->secu_STLB_1M.size,
					   GCKVIP_CACHE_FLUSH);
	gckvip_flush_cache(context->secu_STLB_4K.handle, context->secu_STLB_4K.physical,
					   context->secu_STLB_4K.logical, context->secu_STLB_4K.size,
					   GCKVIP_CACHE_FLUSH);
	gckvip_flush_cache(context->secu_MMU_flush.handle, context->secu_MMU_flush.physical,
					   context->secu_MMU_flush.logical, context->secu_MMU_flush.size,
					   GCKVIP_CACHE_FLUSH);
	gckvip_flush_cache(context->secu_MMU_flush_page.handle, context->secu_MMU_flush_page.physical,
					   context->secu_MMU_flush_page.logical, context->secu_MMU_flush_page.size,
					   GCKVIP_CACHE_FLUSH);
#endif

	PRINTK_I("secure mmu initalize done...\n");
onError:
	return status;
}

/*
@brief un-initialize secure MMU page table.
@param context, the contect of kernel space.
*/
vip_status_e gckvip_mem_mmu_secure_uninit(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;

	context->ptr_STLB_1M = &context->secu_STLB_1M;
	context->ptr_STLB_4K = &context->secu_STLB_4K;
	context->ptr_MMU_flush = &context->secu_MMU_flush;
	context->work_mode = GCKVIP_WORK_MODE_SECURITY;

	if (context->secu_MMU_flush_page.handle != VIP_NULL) {
		gckvip_mem_free_videomemory(context, context->secu_MMU_flush_page.handle);
		context->secu_MMU_flush_page.handle = VIP_NULL;
	}

	if (context->secu_MMU_flush.handle != VIP_NULL) {
		gckvip_mem_free_videomemory(context, context->secu_MMU_flush.handle);
		context->secu_MMU_flush.handle = VIP_NULL;
	}

	if (context->secu_STLB_1M.handle != VIP_NULL) {
		gckvip_mem_free_videomemory(context, context->secu_STLB_1M.handle);
		context->secu_STLB_1M.handle = VIP_NULL;
	}

	if (context->secu_STLB_4K.handle != VIP_NULL) {
		gckvip_mem_free_videomemory(context, context->secu_STLB_4K.handle);
		context->secu_STLB_4K.handle = VIP_NULL;
	}

	return status;
}

vip_status_e gckvip_mem_mmu_flush_cache(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_int32_t count = 100;
	vip_uint32_t idle_reg = 0;

	PRINTK_D("switch stlb, flush mmu cache physical=0x%08X, size=0x%x\n",
			 context->ptr_MMU_flush_page->physical, context->ptr_MMU_flush_page->size);

	gckvip_write_register(0x00654, context->ptr_MMU_flush_page->physical);
	gckvip_os_memorybarrier();
	gckvip_write_register(0x003A4, 0x00010000 | ((context->ptr_MMU_flush_page->size + 7) >> 3));

	/* waiting for hardware idle */
	gckvip_read_register(0x00004, &idle_reg);
	while ((count > 0) && ((idle_reg & 0x7FFFFFFF) != 0x7FFFFFFF)) {
		gckvip_os_delay(1);
		gckvip_read_register(0x00004, &idle_reg);
		count--;
	}

	if (count <= 0) {
		PRINTK_E("failed to flush mmu cache, hw idle=0x%x\n", idle_reg);
		status = VIP_ERROR_FAILURE;
	}

	return status;
}

vip_status_e gckvip_mem_mmu_switch(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_int32_t count = 100;
	vip_uint32_t idle_reg = 0;

	/* waiting for hardware idle */
	gckvip_read_register(0x00004, &idle_reg);
	while ((count > 0) && ((idle_reg & 0x7FFFFFFF) != 0x7FFFFFFF)) {
		gckvip_os_delay(1);
		gckvip_read_register(0x00004, &idle_reg);
		count--;
	}
	if (count <= 0) {
		PRINTK_E("failed to switch mmu page table, hw idle=0x%x\n", idle_reg);
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	if (context->work_mode_last_submit == GCKVIP_WORK_MODE_NORMAL) {
		context->ptr_MMU_flush_page = &context->MMU_flush_page;
	} else {
		context->ptr_MMU_flush_page = &context->secu_MMU_flush_page;
	}

	status = gckvip_mem_mmu_flush_cache(context);
	if (status != VIP_SUCCESS) {
		PRINTK_E("switch mmu, failed to flush mmu cache\n");
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	/* re-location secure mode page table */
	if (context->work_mode == GCKVIP_WORK_MODE_NORMAL) {
		context->ptr_STLB_1M = &context->STLB_1M;
		context->ptr_STLB_4K = &context->STLB_4K;
		context->ptr_MMU_flush = &context->MMU_flush;
	} else {
		context->ptr_STLB_1M = &context->secu_STLB_1M;
		context->ptr_STLB_4K = &context->secu_STLB_4K;
		context->ptr_MMU_flush = &context->secu_MMU_flush;
	}

	mmu_fill_mtlb(context);

	PRINTK_I("switch mmu page table done..\n");

onError:
	return status;
}
#endif

/*
@brief initialize MMU table and allocate MMU, map vip-sram,
       axi-sram, reseverd memory if you system have this.
@param context, the contect of kernel space.
*/
vip_status_e gckvip_mem_mmu_init(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_mmu_table_entry_t *entry = VIP_NULL;
	vip_uint32_t config = 0;
	vip_uint32_t ext = 0;
	vip_uint32_t alloc_flag = GCVIP_VIDEO_MEM_ALLOC_FLAG_NO_MMU_PAGE |
							  GCVIP_VIDEO_MEM_ALLOC_FLAG_4GB_ADDR |
							  GCVIP_VIDEO_MEM_ALLOC_FLAG_CONTIGUOUS |
							  GCVIP_VIDEO_MEM_ALLOC_FLAG_NONE_CACHE;
	vip_uint32_t flush_mmu_flag = GCVIP_VIDEO_MEM_ALLOC_FLAG_4GB_ADDR |
								  GCVIP_VIDEO_MEM_ALLOC_FLAG_CONTIGUOUS |
								  GCVIP_VIDEO_MEM_ALLOC_FLAG_NONE_CACHE;

	PRINTK_D("1M MTLB count=%d, 4K MTLB count=%d, 1M entry count pre-MTLB=%d,"
			 "4K STLB entry count pre-MTLB=%d\n",
			 gcdMMU_1M_MTLB_COUNT, gcdMMU_4K_MTLB_COUNT,
			 gcdMMU_STLB_1M_ENTRY_NUM, gcdMMU_STLB_4K_ENTRY_NUM);

	PRINTK_D("1M page memory size=%dMbytes, 4K page memory size=%dMbyte, one mtlb size=%dMbytes\n",
			 gcdMMU_1M_PAGE_VIDEO_MEMORY_SIZE / 1024 / 1024,
			 gcdMMU_4K_PAGE_VIDEO_MEMORY_SIZE / 1024 / 1024,
			 gcdMMU_1K_MODE_ONE_MTLB_MEMORY / 1024 / 1024);
	if ((gcdMMU_1M_MTLB_COUNT + gcdMMU_4K_MTLB_COUNT) > gcdMMU_MTLB_ENTRY_NUM) {
		PRINTK_E("failed init mmu more than max MTLB count\n");
		gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
	}

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_create_mutex(&context->mmu_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create mutex for mmu\n");
		gcGoOnError(VIP_ERROR_IO);
	}
	status = gckvip_os_create_mutex(&context->wrap_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create mutex for wrap memory\n");
		gcGoOnError(VIP_ERROR_IO);
	}
#endif

	/* allocate memory for MTLB, STLB, MMU_Entry */
	context->MTLB.size = (gcdMMU_1M_MTLB_COUNT + gcdMMU_4K_MTLB_COUNT) * sizeof(vip_uint32_t);
	gcOnError(gckvip_mem_allocate_videomemory(context, context->MTLB.size,
			  &context->MTLB.handle,
			  (void **)&context->MTLB.logical,
			  &context->MTLB.physical,
			  1024,
			  alloc_flag));
	PRINTK_D("MTLB size=%dbytes, logical=0x%" PRIx64", physical=0x%08x\n",
			 context->MTLB.size, GCKVIPPTR_TO_UINT64(context->MTLB.logical),
			 context->MTLB.physical);
	gckvip_os_zero_memory(context->MTLB.logical, context->MTLB.size);

	context->STLB_1M.size = gcdMMU_1M_MTLB_COUNT * gcdMMU_STLB_1M_SIZE;
	gcOnError(gckvip_mem_allocate_videomemory(context, context->STLB_1M.size,
			  &context->STLB_1M.handle,
			  (void **)&context->STLB_1M.logical,
			  &context->STLB_1M.physical,
			  gcdVIP_MEMORY_ALIGN_SIZE,
			  alloc_flag));
	PRINTK_D("STLB 1M size=%dbytes, logical=0x%" PRIx64", physical=0x%08x\n",
			 context->STLB_1M.size, GCKVIPPTR_TO_UINT64(context->STLB_1M.logical),
			 context->STLB_1M.physical);
	gckvip_os_zero_memory(context->STLB_1M.logical, context->STLB_1M.size);

	context->STLB_4K.size = gcdMMU_4K_MTLB_COUNT * gcdMMU_STLB_4K_SIZE;
	gcOnError(gckvip_mem_allocate_videomemory(context, context->STLB_4K.size,
			  &context->STLB_4K.handle,
			  (void **)&context->STLB_4K.logical,
			  &context->STLB_4K.physical,
			  gcdVIP_MEMORY_ALIGN_SIZE,
			  alloc_flag));
	PRINTK_D("STLB 4K size=%dbytes, logical=0x%" PRIx64", physical=0x%08x\n",
			 context->STLB_4K.size, GCKVIPPTR_TO_UINT64(context->STLB_4K.logical),
			 context->STLB_4K.physical);
	gckvip_os_zero_memory(context->STLB_4K.logical, context->STLB_4K.size);

	context->MMU_entry.size = 1024;
	gcOnError(gckvip_mem_allocate_videomemory(context, context->MMU_entry.size,
			  &context->MMU_entry.handle,
			  (void **)&context->MMU_entry.logical,
			  &context->MMU_entry.physical,
			  gcdVIP_MEMORY_ALIGN_SIZE,
			  alloc_flag));
	PRINTK_D("MMU entry size=%dbytes, logical=0x%" PRIx64", physical=0x%08x\n",
			 context->MMU_entry.size, GCKVIPPTR_TO_UINT64(context->MMU_entry.logical),
			 context->MMU_entry.physical);
	gckvip_os_zero_memory(context->MMU_entry.logical, context->MMU_entry.size);

	config  = context->MTLB.physical;
	ext = 0;

	/* more than 40bit physical address */
	if (ext & 0xFFFFFF00) {
		PRINTK_E("fail to init mmu, more than 40bits physical address\n");
		gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
	}

	config |= 1; /* 1K mode */

	entry = (gcvip_mmu_table_entry_t *)context->MMU_entry.logical;
	entry->low = config;
	entry->high = ext;

	/* re-location secure mode page table */
	context->ptr_STLB_1M = &context->STLB_1M;
	context->ptr_STLB_4K = &context->STLB_4K;
	context->ptr_MMU_flush = &context->MMU_flush;
#if vpmdENABLE_SECURE
	context->work_mode = GCKVIP_WORK_MODE_NORMAL;
#endif

	mmu_fill_mtlb(context);

	status = mmu_map_vip_sram(context);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to map vip sram\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	status = mmu_map_axi_sram(context);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to map axi sram\n");
		gcGoOnError(VIP_ERROR_IO);
	}

#if vpmdENABLE_VIDEO_MEMORY_HEAP
	{
		vip_uint32_t cap = gckvip_heap_capability(&context->video_mem_heap);
		if ((cap & GCVIP_VIDEO_MEM_ALLOC_FLAG_SECURE_MEM) != GCVIP_VIDEO_MEM_ALLOC_FLAG_SECURE_MEM) {
			status = mmu_map_reserve_memory(context);
			if (status != VIP_SUCCESS) {
				PRINTK_E("failed to map reserve memory in secure mode\n");
				gcGoOnError(VIP_ERROR_IO);
			}
		}
	}
#endif

	/* fill flush mmu cache load states */
	context->MMU_flush.size = FLUSH_MMU_STATES_SIZE + LINK_SIZE;
	gcOnError(gckvip_mem_allocate_videomemory(context, context->MMU_flush.size,
			  &context->MMU_flush.handle,
			  (void **)&context->MMU_flush.logical,
			  &context->MMU_flush.physical,
			  gcdVIP_MEMORY_ALIGN_SIZE,
			  flush_mmu_flag));
	PRINTK_D("MMU flush size=%dbytes, logical=0x%" PRIx64", vip virtual=0x%08x\n",
			 context->MMU_flush.size, GCKVIPPTR_TO_UINT64(context->MMU_flush.logical),
			 context->MMU_flush.physical);
	gckvip_os_zero_memory(context->MMU_flush.logical, context->MMU_flush.size);

	{
		vip_uint32_t *data = (vip_uint32_t *)context->MMU_flush.logical;
		vip_uint32_t count = 0;
		data[count] = ((8 << 27) | ((FLUSH_MMU_STATES_SIZE + 7) >> 3));
		count++;
		data[count] = context->MMU_flush.physical + LINK_SIZE;
		count++;
		data[count] = 0x08010061;
		count++;
		data[count] = 0xffffff7f;
		count++;
		data[count] = 0x08010e02;
		count++;
		data[count] = 0x30000701;
		count++;
		data[count] = 0x48000000;
		count++;
		data[count] = 0x30000701;
		count++;
		data[count] = ((8 << 27) | ((FLUSH_MMU_STATES_SIZE + 7) >> 3));
		count++;
		data[count] = context->MMU_flush.physical + FLUSH_MMU_STATES_SIZE;
		count++;
		if (count * sizeof(vip_uint32_t) > FLUSH_MMU_STATES_SIZE) {
			PRINTK_E("flush mmu cache memory overflow %d > %d\n",
					 count * sizeof(vip_uint32_t), FLUSH_MMU_STATES_SIZE);
			gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
		}
	}

#if vpmdENABLE_SECURE
	context->MMU_flush_page.size = FLUSH_MMU_STATES_SIZE + LINK_SIZE;
	gcOnError(gckvip_mem_allocate_videomemory(context, context->MMU_flush_page.size,
			  &context->MMU_flush_page.handle,
			  (void **)&context->MMU_flush_page.logical,
			  &context->MMU_flush_page.physical,
			  gcdVIP_MEMORY_ALIGN_SIZE,
			  flush_mmu_flag));
	PRINTK_D("MMU flush page table size=%dbytes, logical=0x%" PRIx64", vip virtual=0x%08x\n",
			 context->MMU_flush_page.size, GCKVIPPTR_TO_UINT64(context->MMU_flush_page.logical),
			 context->MMU_flush_page.physical);
	gckvip_os_zero_memory(context->MMU_flush_page.logical, context->MMU_flush_page.size);

	{
		vip_uint32_t *data = (vip_uint32_t *)context->MMU_flush_page.logical;
		vip_uint32_t count = 0;
		data[count] = 0x08010061;
		count++;
		data[count] = 0xffffff7f;
		count++;
		data[count] = 0x08010e02;
		count++;
		data[count] = 0x30000701;
		count++;
		data[count] = 0x48000000;
		count++;
		data[count] = 0x30000701;
		count++;
		data[count] = (2 << 27);
		count++;
		data[count] = 0;
		count++;
		if (count * sizeof(vip_uint32_t) > FLUSH_MMU_STATES_SIZE) {
			PRINTK_E("flush mmu cache memory overflow %d > %d\n",
					 count * sizeof(vip_uint32_t), FLUSH_MMU_STATES_SIZE);
			gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
		}
		context->MMU_flush_page.size = count * sizeof(vip_uint32_t);
	}
#endif

	context->flush_mmu = 1;

#if vpmdENABLE_SECURE
	status = gckvip_mem_mmu_secure_init(context);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to init secure mmu\n");
	}
	context->work_mode = GCKVIP_WORK_MODE_NORMAL;
	context->work_mode_last_submit = context->work_mode;
#endif

	/* default working in NORMAL mode */
	context->ptr_STLB_1M = &context->STLB_1M;
	context->ptr_STLB_4K = &context->STLB_4K;
	context->ptr_MMU_flush = &context->MMU_flush;

	mmu_fill_mtlb(context);

#if vpmdENABLE_FLUSH_CPU_CACHE
	gckvip_flush_cache(context->MTLB.handle, context->MTLB.physical,
					   context->MTLB.logical, context->MTLB.size, GCKVIP_CACHE_FLUSH);
	gckvip_flush_cache(context->STLB_1M.handle, context->STLB_1M.physical,
					   context->STLB_1M.logical, context->STLB_1M.size, GCKVIP_CACHE_FLUSH);
	gckvip_flush_cache(context->STLB_4K.handle, context->STLB_4K.physical,
					   context->STLB_4K.logical, context->STLB_4K.size, GCKVIP_CACHE_FLUSH);
	gckvip_flush_cache(context->MMU_entry.handle, context->MMU_entry.physical,
					   context->MMU_entry.logical, context->MMU_entry.size, GCKVIP_CACHE_FLUSH);
	gckvip_flush_cache(context->MMU_flush.handle, context->MMU_flush.physical,
					   context->MMU_flush.logical, context->MMU_flush.size, GCKVIP_CACHE_FLUSH);
#if vpmdENABLE_SECURE
	gckvip_flush_cache(context->MMU_flush_page.handle, context->MMU_flush_page.physical,
					   context->MMU_flush_page.logical, context->MMU_flush_page.size, GCKVIP_CACHE_FLUSH);
#endif
#endif

#if vpmdENABLE_SECURE
	PRINTK_I("mmu initalize done, work mode=%s\n",
			 (context->work_mode == GCKVIP_WORK_MODE_NORMAL) ? "NORMAL" : "SECURE");
#endif

onError:
	return status;
}

/*
@brief un-initialize MMU.
@param context, the contect of kernel space.
*/
vip_status_e gckvip_mem_mmu_uninit(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;
#if vpmdENABLE_SECURE
	context->ptr_STLB_1M = &context->STLB_1M;
	context->ptr_STLB_4K = &context->STLB_4K;
	context->ptr_MMU_flush = &context->MMU_flush;
	context->work_mode = GCKVIP_WORK_MODE_NORMAL;
#endif

	if (context->MMU_flush.handle != VIP_NULL) {
		gckvip_mem_free_videomemory(context, context->MMU_flush.handle);
		context->MMU_flush.handle = VIP_NULL;
	}

#if vpmdENABLE_SECURE
	if (context->MMU_flush_page.handle != VIP_NULL) {
		gckvip_mem_free_videomemory(context, context->MMU_flush_page.handle);
		context->MMU_flush_page.handle = VIP_NULL;
	}
#endif

	if (context->MTLB.handle != VIP_NULL) {
		gckvip_mem_free_videomemory(context, context->MTLB.handle);
		context->MTLB.handle = VIP_NULL;
	}

	if (context->STLB_1M.handle != VIP_NULL) {
		gckvip_mem_free_videomemory(context, context->STLB_1M.handle);
		context->STLB_1M.handle = VIP_NULL;
	}

	if (context->STLB_4K.handle != VIP_NULL) {
		gckvip_mem_free_videomemory(context, context->STLB_4K.handle);
		context->STLB_4K.handle = VIP_NULL;
	}

	if (context->MMU_entry.handle != VIP_NULL) {
		gckvip_mem_free_videomemory(context, context->MMU_entry.handle);
		context->MMU_entry.handle = VIP_NULL;
	}

#if vpmdENABLE_SECURE
	gckvip_mem_mmu_secure_uninit(context);

	context->ptr_STLB_1M = &context->STLB_1M;
	context->ptr_STLB_4K = &context->STLB_4K;
	context->ptr_MMU_flush = &context->MMU_flush;

	context->work_mode = GCKVIP_WORK_MODE_NORMAL;
	context->work_mode_last_submit = context->work_mode;
#endif

#if vpmdENABLE_MULTIPLE_TASK
	if (context->mmu_mutex != VIP_NULL) {
		gckvip_os_destroy_mutex(context->mmu_mutex);
		context->mmu_mutex = VIP_NULL;
	}
	if (context->wrap_mutex != VIP_NULL) {
		gckvip_os_destroy_mutex(context->wrap_mutex);
		context->wrap_mutex = VIP_NULL;
	}
#endif

	return status;
}

/*
@brief enable MMU.
@param context, the context of kernel space.
*/
vip_status_e gckvip_mem_mmu_enable(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;

	gckvip_write_register(0x0038C,
						  context->MMU_entry.physical);

	gckvip_write_register(0x00390, 0);

	gckvip_write_register(0x00394, 1);

	gcvip_mem_mmu_setup(context);

	/* enable MMU */
	gckvip_write_register(0x00388, 0x01);

	PRINTK_I("mmu enable done...\n");

	return status;
}

/*
@brief map dynamic memory to VIP virtual for all pages are 4Kbytes or 1Mbytes.
       only can handle all pages are 4Kbyes or 1Mbytes.
@param context, the contect of kernel space.
@param OUT page_info, MMU page information for this memory.
@param IN physical_table, physical address table that need to be mapped.
@param IN physical_num, the number of physical address.
@param IN size_table, the size of memory in physical_table.
@param IN page type, GCVIP_MMU_1M_PAGE or GCVIP_MMU_4K_PAGE MMU page.
@param OUT virtual, VIP virtual address.
*/
static vip_status_e gckvip_mem_map_dyn_page(
	gckvip_context_t *context,
	gckvip_mmu_page_info_t *page_info,
	phy_address_t *physical_table,
	vip_uint32_t physical_num,
	vip_uint32_t *size_table,
	vip_uint8_t page_type,
	vip_uint32_t *virtual
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint64_t i = 0;
	vip_int32_t num_stlb = 0;
	vip_int32_t num_mtlb = 0;
	vip_uint32_t count = 0;
	vip_uint32_t page_size = 0;
	vip_uint32_t stlb_entry_num = 0;
	vip_uint32_t max_mtlb_num = 0;
	vip_uint32_t stlb_shift = 0;
	vip_uint32_t page_mask = 0;
	vip_uint32_t total_size = 0;
	vip_uint32_t offset = 0;
	vip_uint32_t stlb_start = 0;
	vip_uint32_t mtlb_start = 0;
	gckvip_mmu_page_info_t info;
	gckvip_mmu_page_info_t info_tmp;

	if ((virtual == VIP_NULL) || (physical_table == VIP_NULL) ||
		(page_info == VIP_NULL) || (size_table == VIP_NULL)) {
		PRINTK_E("map dyn page parameter is NULL\n");
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_lock_mutex(context->mmu_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock mmu mutex\n");
		return VIP_ERROR_FAILURE;
	}
#endif

	PRINTK_D("dyn map page physical_num=%d page_type=%s\n",
			 physical_num, (page_type == GCVIP_MMU_1M_PAGE) ? "1M byte" : "4K byte");

	for (i = 0; i < physical_num; i++) {
		total_size += size_table[i];
	}

	switch (page_type) {
	case GCVIP_MMU_1M_PAGE: {
		stlb_entry_num = gcdMMU_STLB_1M_ENTRY_NUM;
		max_mtlb_num = gcdMMU_1M_MTLB_COUNT;
		page_size = gcdMMU_PAGE_1M_SIZE;
		stlb_shift = gcdMMU_STLB_1M_SHIFT;
		page_mask = gcdMMU_PAGE_1M_MASK;
	}
	break;

	case GCVIP_MMU_4K_PAGE: {
		stlb_entry_num = gcdMMU_STLB_4K_ENTRY_NUM;
		max_mtlb_num = gcdMMU_1M_MTLB_COUNT + gcdMMU_4K_MTLB_COUNT;
		page_size = gcdMMU_PAGE_4K_SIZE;
		stlb_shift = gcdMMU_STLB_4K_SHIFT;
		page_mask = gcdMMU_PAGE_4K_MASK;
	}
	break;

	default:
		PRINTK_E("failed to fill stlb, not support this page type=%d\n", page_type);
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	/* check pages */
	for (i = 1; i < physical_num; i++) {
		if (size_table[i] != page_size) {
			PRINTK_E("map dyn page function not support this page size. index=%d, size=0x%x\n",
					 i, size_table[i]);
			gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
		}
		if ((physical_table[i] % page_size) != 0) {
			PRINTK_E("map dyn page function not support address align. index=%d, "
					 "address=0x%" PRIx64"\n", i, physical_table[i]);
			gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
		}
	}

	offset = (vip_uint32_t)physical_table[0] & page_mask;

	total_size += offset;

	if (physical_num > 1) {
		num_stlb = physical_num;
	} else {
		num_stlb = (total_size + page_size - 1) / page_size;
		PRINTK_D("dyn page physical=0x%" PRIx64", size=0x%xbytes, total_size=0x%x, offset=0x%x\n",
				 physical_table[0], size_table[0], total_size, offset);
		num_stlb++;
	}
	num_mtlb = (total_size + (1 << gcdMMU_MTLB_SHIFT) - 1) / (1 << gcdMMU_MTLB_SHIFT);

	if ((num_mtlb > 0) && (num_stlb > 0)) {
		gcOnError(mmu_get_page_info(context, num_mtlb, num_stlb, page_type, &info));

		if (info.mtlb_end >= max_mtlb_num) {
			PRINTK_E("MMU MTLB size %d is greater than max mtlb size %d, page type=%d\n",
					 info.mtlb_end, max_mtlb_num, page_type);
			gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
		}

		mtlb_start = info.mtlb_start;
		stlb_start = info.stlb_start;

		*virtual = (mtlb_start << gcdMMU_MTLB_SHIFT)  |
				   (stlb_start << stlb_shift)         |
				   ((vip_uint32_t)physical_table[0] & page_mask);

		if (1 == physical_num) {
			info_tmp.mtlb_start = mtlb_start;
			info_tmp.mtlb_end = info.mtlb_end;
			info_tmp.stlb_start = stlb_start;
			info_tmp.stlb_end = info.stlb_end;

			status = mmu_fill_stlb(context, &info_tmp, page_type, physical_table[0]);
			if (status != VIP_SUCCESS) {
				PRINTK_E("failed to fill stlb... physical_num=%d\n", physical_num);
				gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
			}
		} else {
			for (i = mtlb_start; i <= info.mtlb_end; i++) {
				vip_uint32_t s_start = 0;
				vip_uint32_t s_last = (i == info.mtlb_end) ? info.stlb_end : (stlb_entry_num - 1);

				if (i > mtlb_start) {
					s_start = 0;
				} else {
					s_start = stlb_start; /* first stlb page */
				}

				while (s_start <= s_last) {
					info_tmp.mtlb_start = i;
					info_tmp.mtlb_end = i;
					info_tmp.stlb_start = s_start;
					info_tmp.stlb_end = s_start;

					status = mmu_fill_stlb(context, &info_tmp, page_type, physical_table[count]);
					count++;
					s_start++;

					if (count > physical_num) {
						PRINTK_E("map dyn page failed, count=%d is large than number of"
								 "table num=%d, page_num=%d\n", count, physical_num, physical_num);
						gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
					}
				}
			}
		}
	} else {
		PRINTK_E("failed to map dyn page type %d, mtlb num=%d, stlb num=%d\n",
				 page_type, num_mtlb, num_stlb);
		gcGoOnError(VIP_ERROR_IO);
	}

	page_info->mtlb_start = info.mtlb_start;
	page_info->stlb_start = info.stlb_start;
	page_info->mtlb_end = info.mtlb_end;
	page_info->stlb_end = info.stlb_end;
	page_info->page_type = page_type;

	context->flush_mmu = 1;

#if vpmdENABLE_FLUSH_CPU_CACHE
	if (GCVIP_MMU_1M_PAGE == page_type) {
		gckvip_flush_cache(context->ptr_STLB_1M->handle, context->ptr_STLB_1M->physical,
						   context->ptr_STLB_1M->logical, context->ptr_STLB_1M->size,
						   GCKVIP_CACHE_FLUSH);
	} else if (GCVIP_MMU_4K_PAGE == page_type) {
		gckvip_flush_cache(context->ptr_STLB_4K->handle, context->ptr_STLB_4K->physical,
						   context->ptr_STLB_4K->logical, context->ptr_STLB_4K->size,
						   GCKVIP_CACHE_FLUSH);
	}
#endif

	PRINTK_D("map dyn page, page count=%d, page type=%s, mtlb: %d ~ %d, stlb: %d ~ %d, "
			 "virtual=0x%08x\n",
			 physical_num, (page_info->page_type == GCVIP_MMU_1M_PAGE) ? "1M" : "4K",
			 page_info->mtlb_start, page_info->mtlb_end,
			 page_info->stlb_start, page_info->stlb_end, *virtual);

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(context->mmu_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock mmu mutex\n");
	}
#endif

	return status;

onError:
#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(context->mmu_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock mmu mutex\n");
	}
#endif
	PRINTK_E("failed to get vip virtual in mapping dynamic page, status=%d\n", status);
	return status;
}

/*
@brief map dynamic memory to VIP virtual.
@param context, the contect of kernel space.
@param OUT page_info, MMU page information for this memory.
@param IN physical_table, physical address table that need to be mapped.
@param IN physical_num, the number of physical address.
@param IN size_table, the size of memory in physical_table.
@param IN page_type, vip mmu page table size, 1M or 4K byte.
@param OUT virtual, VIP virtual address.
*/
vip_status_e gckvip_mem_map_dyn_memory(
	gckvip_context_t *context,
	gckvip_mmu_page_info_t *page_info,
	phy_address_t *physical_table,
	vip_uint32_t physical_num,
	vip_uint32_t *size_table,
	vip_uint32_t page_type,
	vip_uint32_t *virtual
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t index = 0;
	vip_int32_t num_stlb = 0;
	vip_int32_t num_mtlb = 0;
	vip_uint32_t physical = 0;
	gckvip_mmu_page_info_t info;
	vip_bool_e all_4k = vip_true_e;
	vip_bool_e all_1M = vip_true_e;
	vip_int32_t offset = 0;
	vip_uint32_t physical_align = 0;

	/* 16Mbytes per-MTLB, 4Kbytes per-STLB */
	if ((virtual == VIP_NULL) || (page_info == VIP_NULL) || (physical_table == VIP_NULL)) {
		PRINTK_E("map dyn memory parameter is NULL\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	if ((VIP_NULL == context->MTLB.handle) || (VIP_NULL == context->ptr_STLB_4K->handle)) {
		PRINTK_E("mmu page table is NULL\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	PRINTK_D("%s dyn map memory physical_num=%d\n",
			 (context->ptr_STLB_4K == &context->STLB_4K) ? "NORMAL" : "SECURE", physical_num);

	/* The size of each item in size_table[] is the same or divisible,
	   call gckvip_mem_map_dyn_page() function
	*/
	info.mtlb_start = 0;
	info.mtlb_end = 0;
	info.stlb_start = 0;
	info.stlb_end = 0;
	for (index = 1; index < physical_num; index++) {
		if ((gcdMMU_PAGE_4K_SIZE == size_table[index]) && all_4k) {
			all_4k = vip_true_e;
		} else {
			if (index != (physical_num - 1)) {
				/* not last one physical table */
				all_4k = vip_false_e;
			}
		}

		if ((gcdMMU_PAGE_1M_SIZE == size_table[index]) && all_1M) {
			all_1M = vip_true_e;
		} else {
			if (index != (physical_num - 1)) {
				/* not last one physical table */
				all_1M = vip_false_e;
			}
		}
	}

	if ((1 == physical_num) && (GCVIP_MMU_1M_PAGE == page_type)) {
		/* only one physical table should be mapped. we use 1M MMU page table for it */
		gcOnError(gckvip_mem_map_dyn_page(context, page_info, physical_table, 1,
										  size_table, GCVIP_MMU_1M_PAGE, virtual));
		return status;
	} else if (all_1M && (GCVIP_MMU_1M_PAGE == page_type)) {
		/* check physical base address should alignment to 1M byte */
		for (index = 1; index < physical_num; index++) {
			if (gcdMMU_PAGE_1M_SIZE == physical_table[index]) {
				PRINTK_I("physical index=%d base address 0x%" PRIx64" not alignment to 1M bytes\n",
						 index, physical_table[index]);
				all_1M = vip_false_e;
				break;
			}
		}

		if (all_1M) {
			/* all pages are 1M byte */
			gcOnError(gckvip_mem_map_dyn_page(context, page_info, physical_table, physical_num,
											  size_table, GCVIP_MMU_1M_PAGE, virtual));
			return status;
		}
	} else if (all_4k) {
		/* check physical base address should alignment to 4K bytes */
		for (index = 1; index < physical_num; index++) {
			if (gcdMMU_PAGE_4K_SIZE == physical_table[index]) {
				PRINTK_I("physical index=%d base address 0x%" PRIx64" not alignment to 4K bytes\n",
						 index, physical_table[index]);
				all_4k = vip_false_e;
				break;
			}
		}
		if (all_4k) {
			/* for Linux 4k page size ?, all pages are 4K bytes */
			gcOnError(gckvip_mem_map_dyn_page(context, page_info, physical_table, physical_num,
											  size_table, GCVIP_MMU_4K_PAGE, virtual));
			return status;
		}
	}

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_lock_mutex(context->mmu_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock mmu mutex\n");
		return VIP_ERROR_FAILURE;
	}
#endif

	/* used 4K MMU page size by default */
	/* check physical base address should alignment to 4K bytes */
	for (index = 1; index < physical_num; index++) {
		if (physical_table[index] % gcdMMU_PAGE_4K_SIZE) {
			PRINTK_I("failed to mmu page table, physical index=%d base address not alignment to 4K bytes\n");
			gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
		}
	}

	for (index = 0; index < physical_num; index++) {
		vip_uint32_t size_tmp = 0;
		physical = (vip_uint32_t)(physical_table[index] & 0xFFFFFFFF);
		physical_align = physical & ~gcdMMU_PAGE_4K_MASK;
		offset = physical - physical_align;

		if ((offset > 0) && (size_table[index] > (vip_uint32_t)(gcdMMU_PAGE_4K_SIZE - offset))) {
			size_tmp = size_table[index] - (vip_uint32_t)(gcdMMU_PAGE_4K_SIZE - offset);
			num_stlb = 1;
		} else {
			num_stlb = 0;
			size_tmp = size_table[index];
		}
		num_stlb += (size_tmp + gcdMMU_PAGE_4K_SIZE - 1) / gcdMMU_PAGE_4K_SIZE;
		num_mtlb = (size_table[index] + (1 << gcdMMU_MTLB_SHIFT) - 1) / (1 << gcdMMU_MTLB_SHIFT);

		if (num_stlb > 0) {
			gcOnError(mmu_get_page_info(context, num_mtlb, num_stlb, GCVIP_MMU_4K_PAGE, &info));

			if (info.mtlb_end >= (gcdMMU_1M_MTLB_COUNT + gcdMMU_4K_MTLB_COUNT)) {
				PRINTK_E("MMU MTLB size is greater than %d\n",
						 gcdMMU_1M_MTLB_COUNT + gcdMMU_4K_MTLB_COUNT);
				gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
			}

			/* VIP virtual is contigous, only get the start address */
			if (0 == index) {
				*virtual = (info.mtlb_start << gcdMMU_MTLB_SHIFT)     |
						   (info.stlb_start << gcdMMU_STLB_4K_SHIFT)  |
						   ((vip_uint32_t)physical & gcdMMU_PAGE_4K_MASK);

				page_info->mtlb_start = info.mtlb_start;
				page_info->stlb_start = info.stlb_start;
			}

			PRINTK_D("idex=%d, mtlb: %d ~ %d, stlb: %d ~ %d, num stlb: %d, physical=0x%x, size=0x%xbytes\n",
					 index, info.mtlb_start, info.mtlb_end, info.stlb_start, info.stlb_end,
					 num_stlb, physical_table[index], size_table[index]);

			/* mapped stlb */
			status = mmu_fill_stlb(context, &info, GCVIP_MMU_4K_PAGE, physical_table[index]);
			if (status != VIP_SUCCESS) {
				PRINTK_E("failed to fill stlb in map dyn memory\n");
				gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
			}
		}
	}

	page_info->mtlb_end = info.mtlb_end;
	page_info->stlb_end = info.stlb_end;
	page_info->page_type = GCVIP_MMU_4K_PAGE;

	context->flush_mmu = 1;

#if vpmdENABLE_FLUSH_CPU_CACHE
	gckvip_flush_cache(context->ptr_STLB_4K->handle, context->ptr_STLB_4K->physical,
					   context->ptr_STLB_4K->logical, context->ptr_STLB_4K->size,
					   GCKVIP_CACHE_FLUSH);
#endif

	PRINTK_D("map dyn memory, page count =%d, mtlb: %d ~ %d, stlb: %d ~ %d\n",
			 physical_num, page_info->mtlb_start, page_info->mtlb_end,
			 page_info->stlb_start, page_info->stlb_end);

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(context->mmu_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock mmu mutex\n");
	}
#endif

	return status;

onError:
#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(context->mmu_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock mmu mutex\n");
	}
#endif
	PRINTK_E("failed to get vip virtual in mapping dynamic memory, status=%d\n", status);
	return status;
}

/*
@brief un-map MMU page and free resource for dynamic allocate memory.
@param context, the contect of kernel space.
*/
vip_status_e gckvip_mem_unmap_dyn_memory(
	gckvip_context_t *context,
	void *handle
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_video_mem_handle_t *ptr = (gckvip_video_mem_handle_t *)handle;

	if (VIP_NULL == ptr) {
		PRINTK_E("failed to unmap page table mmory, handle is NULL\n");
		return VIP_ERROR_FAILURE;
	}

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_lock_mutex(context->mmu_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock mmu mutex\n");
		return VIP_ERROR_FAILURE;
	}
#endif

	if ((GCVIP_VIDEO_MEMORY_TYPE_DYN_ALLOC & ptr->memory_type) ||
		((GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER & ptr->memory_type) != 0)) {
		gckvip_dyn_allocate_node_t *node = &ptr->node.dyn_node;
		gckvip_mmu_page_info_t *page_info = &node->mmu_page_info;
		gcOnError(mmu_free_page_info(context, page_info->page_type, page_info));

		context->flush_mmu = 1;

#if vpmdENABLE_FLUSH_CPU_CACHE
		if (GCVIP_MMU_1M_PAGE == page_info->page_type) {
			gckvip_flush_cache(context->ptr_STLB_1M->handle, context->ptr_STLB_1M->physical,
							   context->ptr_STLB_1M->logical, context->ptr_STLB_1M->size,
							   GCKVIP_CACHE_FLUSH);
		} else if (GCVIP_MMU_4K_PAGE == page_info->page_type) {
			gckvip_flush_cache(context->ptr_STLB_4K->handle, context->ptr_STLB_4K->physical,
							   context->ptr_STLB_4K->logical, context->ptr_STLB_4K->size,
							   GCKVIP_CACHE_FLUSH);
		}
#endif
	}

onError:
#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(context->mmu_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock mmu mutex\n");
	}
#endif
	return status;
}

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
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_video_mem_handle_t *ptr = VIP_NULL;
	gckvip_dyn_allocate_node_t *node = VIP_NULL;
	vip_uint32_t i = 0;
	vip_uint32_t pos = 0;
	vip_uint32_t total_size = 0;
	vip_uint32_t contiguous = vip_true_e;
#if vpmdENABLE_SECURE
	vip_uint32_t secure_flag = GCVIP_VIDEO_MEMORY_TYPE_NORMAL;
#endif

	if ((VIP_NULL == physical_table) && (VIP_NULL == size_table)) {
		PRINTK_E("failed to wrap user physical, parameter is NULL\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	if (physical_num < 1) {
		PRINTK_E("failed to wrap user physical, physical num is %d\n", physical_num);
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

#if vpmdENABLE_SECURE
	if (GCKVIP_WORK_MODE_SECURITY == context->work_mode) {
		context->ptr_STLB_1M = &context->secu_STLB_1M;
		context->ptr_STLB_4K = &context->secu_STLB_4K;
		secure_flag = GCVIP_VIDEO_MEMORY_TYPE_SECURE;
	} else {
		context->ptr_STLB_1M = &context->STLB_1M;
		context->ptr_STLB_4K = &context->STLB_4K;
		secure_flag = GCVIP_VIDEO_MEMORY_TYPE_NORMAL;
	}
#endif

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_lock_mutex(context->wrap_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock wrap user memory mutex\n");
		return VIP_ERROR_FAILURE;
	}
#endif

	PRINTK_I("user physical, phy_table[0]=0x%lx, size_table[0]=0x%x, physical_num=%d, memory_type=%d\n",
			 physical_table[0], size_table[0], physical_num, memory_type);

	if (context->wrap_handle_num >= MAX_WRAP_USER_MEMORY_NUM) {
		PRINTK_E("failed to wrap physical. wrap handle overflow, driver define max handle count=%d\n",
				 MAX_WRAP_USER_MEMORY_NUM);
		gcGoOnError(VIP_ERROR_IO);
	}

	gckvip_os_allocate_memory(sizeof(gckvip_video_mem_handle_t), (void **)&ptr);
	if (VIP_NULL == ptr) {
		PRINTK_E("failed to allocate memory for wrap physical video memory handle\n");
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	for (i = 0; i < context->wrap_handle_num; i++) {
		if (VIP_NULL == context->wrap_handles[i]) {
			pos = i;
			break;
		}
	}

	/* check for free space */
	if (i >= context->wrap_handle_num) {
		context->wrap_handle_num++;
		pos = i;
	}
	context->wrap_handles[pos] = ptr;

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(context->wrap_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock wrap user memory mutex\n");
	}
#endif

	node = &ptr->node.dyn_node;
	gckvip_os_zero_memory(node, sizeof(gckvip_dyn_allocate_node_t));

	for (i = 0; i < physical_num; i++) {
		total_size += size_table[i];
	}
	node->size = total_size;

	/* check physical table are contiguous ? */
	for (i = 0; i < physical_num - 1; i++) {
		if ((physical_table[i] + size_table[i]) != physical_table[i + 1]) {
			contiguous = vip_false_e;
			break;
		}
	}

	if (vip_true_e == contiguous) {
		vip_uint32_t temp_size[2] = {total_size, 0};
		vip_uint32_t virtual_tmp = 0;
		vip_uint32_t offset = physical_table[0] & (gcdMMU_PAGE_1M_MASK);

		/* get page base address */
		physical_table[0] = physical_table[0] & (~gcdMMU_PAGE_1M_MASK);

		gcOnError(gckvip_mem_map_dyn_memory(context, &node->mmu_page_info, physical_table,
											1, temp_size, GCVIP_MMU_1M_PAGE, &virtual_tmp));
		node->vip_virtual_address = virtual_tmp + offset;
		PRINTK_D("user physical contiguous, base physical=0x%" PRIx64", offset=0x%x, virtual=0x%08x,"
				 "size=0x%x\n",
				 physical_table[0], offset, node->vip_virtual_address, node->size);
	} else {
		vip_uint32_t virtual_tmp = 0;
		vip_uint32_t offset = physical_table[0] & (gcdMMU_PAGE_4K_MASK);

		/* get page base address */
		physical_table[0] = physical_table[0] & (~gcdMMU_PAGE_4K_MASK);

		gcOnError(gckvip_mem_map_dyn_memory(context, &node->mmu_page_info, physical_table,
											physical_num, size_table, GCVIP_MMU_4K_PAGE,  &virtual_tmp));
		node->vip_virtual_address = virtual_tmp + offset;
		PRINTK_D("user physical, base physical=0x%" PRIx64", offset=0x%x, physical_num=%d, virtual=0x%08x"
				 "size=0x%x\n",
				 physical_table[0], offset, physical_num, node->vip_virtual_address, node->size);
	}
	node->user_logical = VIP_NULL;
	node->kerl_logical = VIP_NULL;

	ptr->memory_type = GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER_PHYSICAL;

	if (virtual != VIP_NULL) {
		*virtual = node->vip_virtual_address;
	} else {
		PRINTK_E("failed to wrap physical, virtual pointer is NULL\n");
		gcGoOnError(VIP_ERROR_IO);
	}

#if vpmdENABLE_SECURE
	ptr->memory_type |= secure_flag;
#endif

	*handle = (void *)ptr;

	return status;

onError:
#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(context->wrap_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock wrap user memory mutex\n");
	}
#endif
	if (ptr != VIP_NULL) {
		gckvip_os_free_memory(ptr);
		*handle = VIP_NULL;
	}
	return status;
}

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
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0;
	vip_uint32_t wrap_handle_num = context->wrap_handle_num;
	gckvip_video_mem_handle_t *ptr = VIP_NULL;
	gckvip_dyn_allocate_node_t *node = VIP_NULL;
	vip_uint32_t pos = 0;

	if (0 == wrap_handle_num) {
		PRINTK_E("the the number of wrap handle is zero.\n");
		return status;
	}

	if (VIP_NULL == handle) {
		PRINTK_E("failed to unwrap user physical, handle is NULL\n");
		return VIP_ERROR_FAILURE;
	}

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_lock_mutex(context->wrap_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock wrap user memory mutex\n");
		return VIP_ERROR_FAILURE;
	}
#endif

	/* search wrap handle */
	for (i = 0; i < wrap_handle_num; i++) {
		if (handle == context->wrap_handles[i]) {
			ptr = (gckvip_video_mem_handle_t *)handle;
			if (ptr != VIP_NULL) {
				node = &ptr->node.dyn_node;
				pos = i;
				break;
			}
		}
	}
	/* re-search wrap virtual address */
	if (i == wrap_handle_num) {
		for (i = 0; i < wrap_handle_num; i++) {
			ptr = context->wrap_handles[i];
			if (ptr != VIP_NULL) {
				node = &ptr->node.dyn_node;
				if (virtual == node->vip_virtual_address) {
					pos = i;
					break;
				}
			}
		}
	}

	if ((VIP_NULL == ptr) && (i == wrap_handle_num)) {
		PRINTK_E("failed to unwrap user physical, not sreach warp handle\n");
		gcGoOnError(VIP_ERROR_IO);
	}

#if vpmdENABLE_SECURE
	if ((ptr->memory_type & GCVIP_VIDEO_MEMORY_TYPE_SECURE) == GCVIP_VIDEO_MEMORY_TYPE_SECURE) {
		context->ptr_STLB_1M = &context->secu_STLB_1M;
		context->ptr_STLB_4K = &context->secu_STLB_4K;
	} else {
		context->ptr_STLB_1M = &context->STLB_1M;
		context->ptr_STLB_4K = &context->STLB_4K;
	}
#endif

	if (GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER_PHYSICAL & ptr->memory_type) {
		/* free mmu page table */
		gckvip_mem_unmap_dyn_memory(context, ptr);
	}

	gckvip_os_free_memory(ptr);

	/* unwrap memory successfully */
	context->wrap_handles[pos] = VIP_NULL;
	if (pos == (wrap_handle_num - 1)) {
		/* this is last handle, reduce the number of wrap handle */
		context->wrap_handle_num--;
	}

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(context->wrap_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock wrap user memory mutex\n");
	}
#endif

	return status;

onError:
#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(context->wrap_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock wrap user memory mutex\n");
	}
#endif
	PRINTK_E("failed to un-wrap user physical memroy.\n");
	return status;
}

/*
@brief wrap user memory to VIP virtual address.
@param IN context, the contect of kernel space.
@param IN logical, the user space logical address(handle).
@param IN size, the size of the memory.
@param IN  memory_type The type of this VIP buffer memory. see vip_buffer_memory_type_e.
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
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_video_mem_handle_t *ptr = VIP_NULL;
	gckvip_dyn_allocate_node_t *node = VIP_NULL;
	vip_uint32_t i = 0;
	vip_uint32_t pos = 0;
#if vpmdENABLE_SECURE
	vip_uint32_t secure_flag = GCVIP_VIDEO_MEMORY_TYPE_NORMAL;
#endif

	if (VIP_NULL == logical) {
		PRINTK_E("failed to wrap user memory, parameter is NULL\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_lock_mutex(context->wrap_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock wrap user memory mutex\n");
		return VIP_ERROR_FAILURE;
	}
#endif

	if (context->wrap_handle_num >= MAX_WRAP_USER_MEMORY_NUM) {
		PRINTK_E("failed to wrap memory. wrap handle overflow, driver define max handle count=%d\n",
				 MAX_WRAP_USER_MEMORY_NUM);
		gcGoOnError(VIP_ERROR_IO);
	}

#if vpmdENABLE_SECURE
	if (GCKVIP_WORK_MODE_SECURITY == context->work_mode) {
		context->ptr_STLB_1M = &context->secu_STLB_1M;
		context->ptr_STLB_4K = &context->secu_STLB_4K;
		secure_flag = GCVIP_VIDEO_MEMORY_TYPE_SECURE;
	} else {
		context->ptr_STLB_1M = &context->STLB_1M;
		context->ptr_STLB_4K = &context->STLB_4K;
		secure_flag = GCVIP_VIDEO_MEMORY_TYPE_NORMAL;
	}
#endif

	gckvip_os_allocate_memory(sizeof(gckvip_video_mem_handle_t), (void **)&ptr);
	if (VIP_NULL == ptr) {
		PRINTK_E("failed to allocate memory for video memory ptr\n");
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	for (i = 0; i < context->wrap_handle_num; i++) {
		if (VIP_NULL == context->wrap_handles[i]) {
			pos = i;
			break;
		}
	}

	/* check for free space */
	if (i >= context->wrap_handle_num) {
		context->wrap_handle_num++;
		pos = i;
	}
	context->wrap_handles[pos] = ptr;

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(context->wrap_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock wrap user memory mutex\n");
	}
#endif

	node = &ptr->node.dyn_node;
	gckvip_os_zero_memory(node, sizeof(gckvip_dyn_allocate_node_t));
	node->size = size;

	if (logical != VIP_NULL) {
		vip_uint8_t page_type = GCVIP_MMU_4K_PAGE;
		/* get physical_table/size_table/physical_num */
		gcOnError(gckvip_allocator_wrap_usermemory(context, logical, memory_type, node));

		/* mapping VIP MMU page table */
		if ((1 == node->physical_num) && (node->size_table[0] >= gcdMMU_PAGE_1M_SIZE)) {
			page_type = GCVIP_MMU_1M_PAGE;
		}

		gcOnError(gckvip_mem_map_dyn_memory(context, &node->mmu_page_info, node->physical_table,
											node->physical_num, node->size_table, page_type,
											&node->vip_virtual_address));

		ptr->memory_type = GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER_LOGICAL;
	} else {
		PRINTK_E("failed to wrap user memory, logical is NULL\n");
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	if (virtual != VIP_NULL) {
		*virtual = node->vip_virtual_address;
	} else {
		PRINTK_E("failed to wrap memory, virtual pointer is NULL\n");
		gcGoOnError(VIP_ERROR_IO);
	}

#if vpmdENABLE_SECURE
	ptr->memory_type |= secure_flag;
#endif
	PRINTK_D("wrap user memory logical=0x%" PRIx64", physial base=0x%" PRIx64", "
			 "virtual=0x%08x, size=0x%x, mem_type=0x%x\n", GCKVIPPTR_TO_UINT64(logical),
			 node->physical_table[0], node->vip_virtual_address, node->size, ptr->memory_type);

	*handle = (void *)ptr;

	return status;

onError:
#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(context->wrap_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock wrap user memory mutex\n");
	}
#endif
	if (node->physical_table != VIP_NULL) {
		gckvip_os_free_memory(node->physical_table);
		node->physical_table = VIP_NULL;
	}
	if (ptr != VIP_NULL) {
		gckvip_os_free_memory(ptr);
		*handle = VIP_NULL;
	}
	return status;
}

/*
@brief un-wrap user memory to VIP virtual address.
@param context, the contect of kernel space.
@param handle, the handle of video memory.
@param virtual, VIP virtual address.
*/
vip_status_e gckvip_mem_unwrap_usermemory(
	gckvip_context_t *context,
	void *handle,
	vip_uint32_t virtual
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0;
	vip_uint32_t wrap_handle_num = context->wrap_handle_num;
	gckvip_video_mem_handle_t *ptr = VIP_NULL;
	gckvip_dyn_allocate_node_t *node = VIP_NULL;
	vip_uint32_t pos = 0;

	if (0 == wrap_handle_num) {
		PRINTK_E("the the number of wrap handle is zero.\n");
		return status;
	}

	if (VIP_NULL == handle) {
		PRINTK_E("failed to unwrap user memory, handle is NULL\n");
		return VIP_ERROR_FAILURE;
	}
#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_lock_mutex(context->wrap_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock wrap user memory mutex\n");
		return VIP_ERROR_FAILURE;
	}
#endif

	PRINTK_D("unwrap user memory, handle=0x%" PRIx64", virtual=0x%x\n",
			 GCKVIPPTR_TO_UINT64(handle), virtual);

	/* search wrap handle */
	for (i = 0; i < wrap_handle_num; i++) {
		if (handle == context->wrap_handles[i]) {
			ptr = (gckvip_video_mem_handle_t *)handle;
			if (ptr != VIP_NULL) {
				node = &ptr->node.dyn_node;
				pos = i;
				break;
			}
		}
	}
	/* re-search wrap virtual address */
	if (i == wrap_handle_num) {
		for (i = 0; i < wrap_handle_num; i++) {
			ptr = context->wrap_handles[i];
			if (ptr != VIP_NULL) {
				node = &ptr->node.dyn_node;
				if (virtual == node->vip_virtual_address) {
					pos = i;
					break;
				}
			}
		}
	}

	if ((VIP_NULL == ptr) || (i == wrap_handle_num) || (VIP_NULL == node)) {
		PRINTK_E("failed to unwrap memory, not sreach warp handle\n");
		gcGoOnError(VIP_ERROR_IO);
	}

#if vpmdENABLE_SECURE
	if ((ptr->memory_type & GCVIP_VIDEO_MEMORY_TYPE_SECURE) == GCVIP_VIDEO_MEMORY_TYPE_SECURE) {
		context->ptr_STLB_1M = &context->secu_STLB_1M;
		context->ptr_STLB_4K = &context->secu_STLB_4K;
	} else {
		context->ptr_STLB_1M = &context->STLB_1M;
		context->ptr_STLB_4K = &context->STLB_4K;
	}
#endif

	/* free mmu page table */
	gckvip_mem_unmap_dyn_memory(context, ptr);

	/* unwrap user memory */
	if (GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER_LOGICAL & ptr->memory_type) {
		gckvip_allocator_unwrap_usermemory(context, node);
	}

	gckvip_os_free_memory(ptr);

	/* unwrap memory successfully */
	context->wrap_handles[pos] = VIP_NULL;
	if (pos == (wrap_handle_num - 1)) {
		/* this is last handle, reduce the number of wrap handle */
		context->wrap_handle_num--;
	}

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(context->wrap_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock wrap user memory mutex\n");
	}
#endif

	return status;

onError:
#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_unlock_mutex(context->wrap_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to unlock wrap user memory mutex\n");
	}
#endif
	PRINTK_E("failed to un-wrap memroy.\n");
	return status;
}

#endif

/*
@brief initialize video memory heap.
@param context, the contect of kernel space.
*/
#if vpmdENABLE_VIDEO_MEMORY_HEAP
vip_status_e gckvip_mem_heap_init(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;
	phy_address_t physical = 0;
	phy_address_t align_physical = 0;
	void *mem = VIP_NULL;
	vip_uint32_t size = 0;
	vip_uint32_t node_cap = 0;
	vip_int32_t diff = 0;
	vip_uint8_t *logical = VIP_NULL;

	status = gckvip_drv_get_videomemory_info(&context->user_mem_base, &context->kernel_mem_base,
			 &context->physical_base, &context->mem_size);
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to get vip memory information\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	PRINTK_I("video memory heap base physical=0x%" PRIx64, " user logical=0x%" PRIx64","
			 "kernel logical=0x%" PRIx64", size=0x%x bytes\n",
			 context->physical_base, GCKVIPPTR_TO_UINT64(context->user_mem_base),
			 GCKVIPPTR_TO_UINT64(context->kernel_mem_base), context->mem_size);

#if !vpmdENABLE_MMU
	if ((context->physical_base + context->mem_size) >= 0xffffffff) {
		PRINTK_E("fail to init video memory heap, mmu disabled, physical=0x%" PRIx64"\n",
				 context->physical_base + context->mem_size);
		gcGoOnError(VIP_ERROR_IO);
	}
#endif

	context->vip_virtual_base = (vip_uint32_t)context->physical_base; /* MMU is disabled */
	mem = context->kernel_mem_base;
	physical = context->physical_base;
	size = context->mem_size;
	align_physical = GCVIP_ALIGN(physical, gcdVIP_MEMORY_ALIGN_SIZE);
	diff = (vip_uint32_t)(align_physical - physical);
	logical = (vip_uint8_t *)mem;

	if (size > 0x6400000) {/* 100M bytes*/
		node_cap = size / 1024 / 100; /* 100k bytes pre-node */
	} else if (size > 0x1400000) { /* 20M bytes*/
		node_cap = size / 1024 / 20; /* 20k bytes pre-node */
	} else if (size > 0x400000) { /* 4M bytes*/
		node_cap = size / 1024 / 16; /* 16k bytes pre-node */
	} else {
		node_cap = size / 1024;
	}

	if (diff > 0) {
		physical = align_physical;
		logical = (vip_uint8_t *)mem + diff;
		size -= diff;
		PRINTK_E("video memory auto alignment 256bytes, org_logical=%,"
				 "org_physical=0x%" PRIx64, " alig_log=0x%" PRIx64", align_physical=0x%" PRIx64"\n",
				 mem, context->physical_base, GCKVIPPTR_TO_UINT64(logical), physical);
	}

	status = gckvip_heap_construct(&context->video_mem_heap, size, logical, physical, node_cap);
	if (status != VIP_SUCCESS) {
		PRINTK_E("fail to construct video memory heap\n");
		gcGoOnError(VIP_ERROR_IO);
	}

onError:
	return status;
}

/*
@brief destory video memory heap.
@param context, the contect of kernel space.
*/
vip_status_e gckvip_mem_heap_destroy(
	gckvip_context_t *context
)
{
	PRINTK_I("video memory heap destroy....\n");
	gckvip_heap_destroy(&context->video_mem_heap);

	return VIP_SUCCESS;
}
#endif

/*
@brief Get VIP accessible physical address corresponding to the logical address.
@param context, the contect of kernel space.
@param handle, the handle of video memory.
@param IN logical, the kernel or user space logical address.
@param OUT physical, the CPU's physical address corresponding to logical.
*/
vip_status_e gckvip_mem_get_cpuphysical(
	gckvip_context_t *context,
	void *handle,
	void *logical,
	phy_address_t *physical
)
{
	vip_status_e status = VIP_SUCCESS;
#if vpmdENABLE_VIDEO_MEMORY_HEAP
	vip_int32_t offset = -1;
#endif

	if (VIP_NULL == handle) {
		PRINTK_E("failed to get cpu physical, handle is NULL\n");
		gcGoOnError(VIP_ERROR_IO);
	}

#if vpmdENABLE_VIDEO_MEMORY_HEAP
	offset = (vip_uint8_t *)logical - (vip_uint8_t *)context->kernel_mem_base;

	if ((offset >= 0) && ((vip_uint32_t)offset < context->mem_size)) {
		/* logical is kernel space address */
		*physical = (phy_address_t)(context->physical_base + offset);
	} else {
		/* check logical address in user sapce again */
		offset = (vip_uint8_t *)logical - (vip_uint8_t *)context->user_mem_base;
		if ((offset >= 0) && ((vip_uint32_t)offset < context->mem_size)) {
			*physical = (phy_address_t)(context->physical_base + offset);
		} else
#endif
		{
			/* is dynamic alloc memory */
			gckvip_video_mem_handle_t *ptr = (gckvip_video_mem_handle_t *)handle;
#if vpmdENABLE_MMU
			if ((GCVIP_VIDEO_MEMORY_TYPE_DYN_ALLOC & ptr->memory_type) ||
				(GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER & ptr->memory_type)) {
				gckvip_dyn_allocate_node_t *node = &ptr->node.dyn_node;
				gcOnError(gckvip_allocator_get_cpuphysical(context, node, logical,
						  physical, ptr->memory_type));
			} else {
				PRINTK_E("faied to get cpu physical\n");
				status = VIP_ERROR_OUT_OF_MEMORY;
			}
#else
			if (GCVIP_VIDEO_MEMORY_TYPE_DYN_ALLOC & ptr->memory_type) {
				vip_int32_t offset = -1;
				gckvip_dyn_allocate_node_t *node = &ptr->node.dyn_node;
				offset = (vip_uint8_t *)logical - (vip_uint8_t *)node->user_logical;
				if ((offset >= 0) && ((vip_uint32_t)offset < node->size)) {
					/* logical is kernel space address */
					*physical = (phy_address_t)(node->physical_table[0] + offset);
				} else {
					/* check logical address in user sapce again */
					offset = (vip_uint8_t *)logical - (vip_uint8_t *)node->kerl_logical;
					if ((offset >= 0) && ((vip_uint32_t)offset < node->size)) {
						*physical = (phy_address_t)(node->physical_table[0] + offset);
					}
				}
			} else {
				PRINTK_E("faied to get cpu physical\n");
				status = VIP_ERROR_OUT_OF_MEMORY;
			}
#endif
		}
#if vpmdENABLE_VIDEO_MEMORY_HEAP
	}
#endif

onError:
	return status;
}

/*
@brief Get vip accessible kernel space logical address corresponding to the physical address.
@param context, the contect of kernel space.
@param handle, the handle of video memory.
@param IN physical, the physical address or VIP's virtual of video memory.
@param OUT logical, kerenl space logical address.
*/
vip_status_e gckvip_mem_get_kernellogical(
	gckvip_context_t *context,
	void *handle,
	vip_uint32_t physical,
	void **logical
)
{
	vip_status_e status = VIP_SUCCESS;
#if vpmdENABLE_VIDEO_MEMORY_HEAP
	vip_int64_t offset = -1;
#endif

	if (VIP_NULL == handle) {
		PRINTK_E("failed to get kernel logical, hanlde is NULL\n");
		gcGoOnError(VIP_ERROR_IO);
	}

#if vpmdENABLE_VIDEO_MEMORY_HEAP
	if (((phy_address_t)physical >= context->physical_base) &&
		((phy_address_t)physical < (context->physical_base + context->mem_size))) {
		offset = (phy_address_t)physical - context->physical_base;
	} else if (((phy_address_t)physical >= context->vip_virtual_base) &&
			   ((phy_address_t)physical < (context->vip_virtual_base + context->mem_size))) {
		offset = (phy_address_t)physical - context->vip_virtual_base;
	}

	if ((offset >= 0) && ((vip_uint32_t)offset < context->mem_size)) {
		*logical = (void *)((vip_uint8_t *)context->kernel_mem_base + offset);
	} else
#endif
	{
		gckvip_video_mem_handle_t *ptr = (gckvip_video_mem_handle_t *)handle;
#if vpmdENABLE_MMU
		if ((GCVIP_VIDEO_MEMORY_TYPE_DYN_ALLOC & ptr->memory_type) ||
			(GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER & ptr->memory_type)) {
			gckvip_dyn_allocate_node_t *node = &ptr->node.dyn_node;
			gcOnError(gckvip_allocator_get_kernellogical(context, node, physical,
					  logical, ptr->memory_type));
		} else {
			PRINTK_E("failed to get kernel logical address, physical=0x%x\n", physical);
			status = VIP_ERROR_OUT_OF_MEMORY;
		}
#else
		if (GCVIP_VIDEO_MEMORY_TYPE_DYN_ALLOC & ptr->memory_type) {
			vip_int32_t offset = -1;
			gckvip_dyn_allocate_node_t *node = &ptr->node.dyn_node;
			if (((phy_address_t)physical >= node->physical_table[0]) &&
				((phy_address_t)physical < (node->physical_table[0] + node->size))) {
				offset = (phy_address_t)physical - node->physical_table[0];
			}

			if ((offset >= 0) && ((vip_uint32_t)offset < node->size)) {
				*logical = (void *)((vip_uint8_t *)node->kerl_logical + offset);
			}
		}
#endif
	}

onError:
	return status;
}

/*
@brief Get vip accessible user space logical address corresponding to the physical address.
@param context, the contect of kernel space.
@param handle, the handle of video memory.
@param IN physical, the physical address of video memory.
@param OUT logical, the user space logical.
*/
vip_status_e gckvip_mem_get_userlogical(
	gckvip_context_t *context,
	void *handle,
	vip_uint32_t physical,
	void **logical
)
{
	vip_status_e status = VIP_SUCCESS;
#if vpmdENABLE_VIDEO_MEMORY_HEAP
	vip_int64_t offset = -1;
#endif

	if (VIP_NULL == handle) {
		PRINTK_E("failed to get user logical, handle is NULL\n");
		gcGoOnError(VIP_ERROR_IO);
	}

#if vpmdENABLE_VIDEO_MEMORY_HEAP
	if ((physical >= context->physical_base) &&
		(physical < (context->physical_base + context->mem_size))) {
		offset = physical - context->physical_base;
	} else if ((physical >= context->vip_virtual_base) &&
			   (physical < (context->vip_virtual_base + context->mem_size))) {
		offset = physical - context->vip_virtual_base;
	}

	if ((offset >= 0) && ((vip_uint32_t)offset < context->mem_size)) {
		*logical = (void *)((vip_uint8_t *)context->user_mem_base + offset);
	} else
#endif
	{
		gckvip_video_mem_handle_t *ptr = (gckvip_video_mem_handle_t *)handle;
#if vpmdENABLE_MMU
		if ((GCVIP_VIDEO_MEMORY_TYPE_DYN_ALLOC & ptr->memory_type) ||
			(GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER & ptr->memory_type)) {
			gckvip_dyn_allocate_node_t *node = &ptr->node.dyn_node;
			gcOnError(gckvip_allocator_get_userlogical(context, node, physical,
					  logical, ptr->memory_type));
		} else {
			PRINTK_E("faied to get user logical address, physical=0x%x\n", physical);
			status = VIP_ERROR_OUT_OF_MEMORY;
		}
#else
		if (GCVIP_VIDEO_MEMORY_TYPE_DYN_ALLOC & ptr->memory_type) {
			vip_int32_t offset = -1;
			gckvip_dyn_allocate_node_t *node = &ptr->node.dyn_node;
			if ((physical >= node->physical_table[0]) &&
				(physical < (node->physical_table[0] + node->size))) {
				offset = physical - node->physical_table[0];
			}

			if ((offset >= 0) && ((vip_uint32_t)offset < node->size)) {
				*logical = (void *)((vip_uint8_t *)node->user_logical + offset);
			}
		}
#endif
	}

onError:
	return status;
}

/*
@brief Get vip virtual address. vip virtual is equal to physical when MMU is disabled.
@param context, the contect of kernel space.
@param handle, the handle of video memory.
@param IN physical, the physical address of video memory.
@param OUT virtual, the virtual address of VIP.
*/
vip_status_e gckvip_mem_get_vipvirtual(
	gckvip_context_t *context,
	void *handle,
	phy_address_t physical,
	vip_uint32_t *virtual
)
{
	vip_status_e status = VIP_SUCCESS;

	if (VIP_NULL == virtual) {
		PRINTK_E("virtual is MULL, failed\n");
		gcGoOnError(VIP_ERROR_IO);
	}

#if vpmdENABLE_VIDEO_MEMORY_HEAP
	if ((physical >= context->physical_base) &&
		(physical < (context->physical_base + context->mem_size))) {
		/* is reserve memory */
#if vpmdENABLE_MMU
		vip_int64_t offset = -1;
		offset = (vip_int64_t)(physical - context->physical_base);
		if ((offset >= 0) && ((vip_uint32_t)offset < context->mem_size)) {
			*virtual = context->vip_virtual_base + offset;
		}
#else
		*virtual = physical;
#endif
	} else
#endif
	{
		gckvip_video_mem_handle_t *ptr = (gckvip_video_mem_handle_t *)handle;
#if vpmdENABLE_MMU
		if ((GCVIP_VIDEO_MEMORY_TYPE_DYN_ALLOC & ptr->memory_type) ||
			(GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER & ptr->memory_type)) {
			*virtual = physical;
		} else {
			PRINTK_E("faied to get virtual address\n");
			gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
		}
#else
		if (GCVIP_VIDEO_MEMORY_TYPE_DYN_ALLOC & ptr->memory_type) {
			*virtual = physical;
		}
#endif
	}

onError:
	return status;
}

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
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint8_t heap_alloc = 0;
	gckvip_video_mem_handle_t *ptr = VIP_NULL;
	phy_address_t phy_addr = 0;
#if vpmdENABLE_SECURE
	vip_uint32_t secure_flag = GCVIP_VIDEO_MEMORY_TYPE_NORMAL;
#endif

	if ((VIP_NULL == memory) || (VIP_NULL == context) ||
		(VIP_NULL == physical) || (VIP_NULL == handle)) {
		PRINTK_E("failed to allocate memory, parameter is NULL\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

#if vpmdENABLE_SECURE
	if (GCKVIP_WORK_MODE_SECURITY == context->work_mode) {
		/* allocate secure memory */
		context->ptr_STLB_1M = &context->secu_STLB_1M;
		context->ptr_STLB_4K = &context->secu_STLB_4K;
		alloc_flag |= GCVIP_VIDEO_MEM_ALLOC_FLAG_SECURE_MEM;
		secure_flag = GCVIP_VIDEO_MEMORY_TYPE_SECURE;
	} else {
		context->ptr_STLB_1M = &context->STLB_1M;
		context->ptr_STLB_4K = &context->STLB_4K;
		alloc_flag |= GCVIP_VIDEO_MEM_ALLOC_FLAG_NONE_SECURE_MEM;
		secure_flag = GCVIP_VIDEO_MEMORY_TYPE_NORMAL;
	}
#endif

#if vpmdENABLE_MMU
#if vpmdENABLE_VIDEO_MEMORY_HEAP
	if ((gckvip_heap_query(&context->video_mem_heap, GCVIP_ALIGN(size, align))) &&
		((gckvip_heap_capability(&context->video_mem_heap) & alloc_flag) == alloc_flag)) {
		gckvip_heap_node_t *node = (gckvip_heap_node_t *)gckvip_heap_alloc(&context->video_mem_heap,
								   size, memory, &phy_addr,
								   align);
		if (node != VIP_NULL) {
			gcOnError(gckvip_os_allocate_memory(sizeof(gckvip_video_mem_handle_t), (void **)&ptr));
			ptr->memory_type = GCVIP_VIDEO_MEMORY_TYPE_VIDO_HEAP;
			ptr->node.heap_node = node;
			*handle = (void *)ptr;
			heap_alloc = 1;
		} else {
			PRINTK_E("failed to allocate memory from heap\n");
			gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
		}
	} else
#endif
	{
		gckvip_dyn_allocate_node_t *node = VIP_NULL;
		gcOnError(gckvip_os_allocate_memory(sizeof(gckvip_video_mem_handle_t), (void **)&ptr));
		gckvip_os_zero_memory(&ptr->node.dyn_node, sizeof(gckvip_dyn_allocate_node_t));
		ptr->memory_type = GCVIP_VIDEO_MEMORY_TYPE_DYN_ALLOC;
		ptr->node.dyn_node.size = GCVIP_ALIGN(size, align);

		node = &ptr->node.dyn_node;

		/* get physical table and size table */
		gcOnError(gckvip_allocator_dyn_alloc(context, node, align, alloc_flag));

		/* check base address is aligned */
		if ((node->physical_num > 0) && (node->physical_table != VIP_NULL)) {
			vip_uint32_t i = 0;
			for (i = 0; i < node->physical_num; i++) {
				if ((node->physical_table[i] & (align - 1)) != 0) {
					PRINTK_E("dyn allocate vido memory physical not align to %d, page_index=%d, "
							 "physical=0x%" PRIx64"\n", align, i, node->physical_table[i]);
					gcGoOnError(VIP_ERROR_FAILURE);
				}
			}
		} else {
			PRINTK_E("physical num is 0 or physical table is NULL\n");
			gcGoOnError(VIP_ERROR_FAILURE);
		}

		if (0x00 == (alloc_flag & GCVIP_VIDEO_MEM_ALLOC_FLAG_NO_MMU_PAGE)) {
			/* mapped VIP virtual */
			vip_uint8_t page_type = 0;
			if ((node->mem_flag & GCVIP_MEM_FLAG_1M_CONTIGUOUS) ||
				(node->mem_flag & GCVIP_MEM_FLAG_CONTIGUOUS) ||
				(node->mem_flag & GCVIP_MEM_FLAG_CMA)) {
				vip_uint32_t total_size = 0;
				vip_uint32_t k = 0;
				for (k = 0; k < node->physical_num; k++) {
					total_size += node->size_table[k];
				}
				if (total_size > gcdMMU_PAGE_1M_SIZE) {
					page_type = GCVIP_MMU_1M_PAGE;
				} else {
					page_type = GCVIP_MMU_4K_PAGE;
				}
			} else {
				page_type = GCVIP_MMU_4K_PAGE;
			}
			gcOnError(gckvip_mem_map_dyn_memory(context, &node->mmu_page_info, node->physical_table,
												node->physical_num, node->size_table, page_type,
												&node->vip_virtual_address));
		} else {
			node->mem_flag |= GCVIP_MEM_FLAG_NO_MMU_PAGE;
			if (0x00 == (alloc_flag & GCVIP_VIDEO_MEM_ALLOC_FLAG_CONTIGUOUS)) {
				PRINTK_E("failed to allocate, NO MMU page alloc flag only support contiguous alloc flag\n");
				gcGoOnError(VIP_ERROR_FAILURE);
			}
			if (node->physical_num != 1) {
				PRINTK_E("failed to allocate, NO MMU page alloc flag  and contiguous,"
						 "physical_num must is  1, then %d\n",
						 node->physical_num);
				gcGoOnError(VIP_ERROR_FAILURE);
			}
			node->vip_virtual_address = (vip_uint32_t)node->physical_table[0];
			PRINTK_I("dyn allocate video memory contiguous and no mmu page, physical=0x%x\n",
					 node->vip_virtual_address);
		}

		phy_addr = node->physical_table[0];

		*physical = ptr->node.dyn_node.vip_virtual_address;
		*memory = ptr->node.dyn_node.kerl_logical;
		*handle = (void *)ptr;
	}
#else
#if vpmdENABLE_VIDEO_MEMORY_HEAP
	if (gckvip_heap_query(&context->video_mem_heap, GCVIP_ALIGN(size, align))) {
		gckvip_heap_node_t *node = (gckvip_heap_node_t *)gckvip_heap_alloc(&context->video_mem_heap,
								   size, memory, &phy_addr, align);
		if (node != VIP_NULL) {
			gcOnError(gckvip_os_allocate_memory(sizeof(gckvip_video_mem_handle_t), (void **)&ptr));
			ptr->memory_type = GCVIP_VIDEO_MEMORY_TYPE_VIDO_HEAP;
			ptr->node.heap_node = node;
			*handle = (void *)ptr;
			heap_alloc = 1;
		} else {
			PRINTK_E("failed to allocate memory from heap, mmu disabled path\n");
			gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
		}
	} else
#endif
	{
		gckvip_dyn_allocate_node_t *node = VIP_NULL;
		gcOnError(gckvip_os_allocate_memory(sizeof(gckvip_video_mem_handle_t), (void **)&ptr));
		gckvip_os_zero_memory(&ptr->node.dyn_node, sizeof(gckvip_dyn_allocate_node_t));
		ptr->memory_type = GCVIP_VIDEO_MEMORY_TYPE_DYN_ALLOC;
		ptr->node.dyn_node.size = GCVIP_ALIGN(size, align);

		node = &ptr->node.dyn_node;

		/* get physical address */
		gcOnError(gckvip_allocator_dyn_alloc(context, node, align, alloc_flag));

		/* check base address is aligned */
		if ((1 == node->physical_num) && (node->physical_table != VIP_NULL)) {
			if ((node->physical_table[0] & (align - 1)) != 0) {
				PRINTK_E("dyn allocate vido memory physical not align to %d, physical=0x%" PRIx64"\n",
						 align, node->physical_table[0]);
				gcGoOnError(VIP_ERROR_FAILURE);
			}
		} else {
			PRINTK_E("physical num is larger than 1, is %d or physical table is NULL\n",
					 node->physical_num);
			gcGoOnError(VIP_ERROR_FAILURE);
		}

		phy_addr = node->physical_table[0];
		*physical = (vip_uint32_t)node->physical_table[0];
		*memory = ptr->node.dyn_node.kerl_logical;
		*handle = (void *)ptr;
	}

	if (phy_addr & 0xFFFFFFFF00000000ULL) {
		PRINTK_E("failed to allocate memory, MMU disabled, physical=0x%" PRIx64"\n", phy_addr);
		gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
	}
#endif

	if (*handle == VIP_NULL) {
		PRINTK_E("failed to allocate video memory from heap, size=0x%x\n", size);
		gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
	} else {
		vip_uint32_t virtual = 0;

		if (heap_alloc) {
			/* phy_addr is physical address in DDR, virtual is VIP's virtual */
			if (0x00 == (alloc_flag & GCVIP_VIDEO_MEM_ALLOC_FLAG_NO_MMU_PAGE)) {
				gcOnError(gckvip_mem_get_vipvirtual(context, *handle, phy_addr, &virtual));
			} else {
				virtual = (vip_uint32_t)phy_addr;
			}
		} else {
			virtual = *physical;
		}

#if (vpmdENABLE_DEBUG_LOG >= 4)
		{
			vip_uint32_t *logical = VIP_NULL;
			gcOnError(gckvip_mem_get_userlogical(context, *handle, virtual, (void **)&logical));
			PRINTK_D("video memory %s, physical=0x%" PRIx64", virtual=0x%08x, kernel logical=0x%" PRIx64","
					 "user logical=0x%" PRIx64", handle=0x%" PRIx64", size=0x%x, align=0x%x, allo_flag=0x%x\n",
					 heap_alloc ? "heap_alloc" : "dyn_alloc", phy_addr, virtual,
					 GCKVIPPTR_TO_UINT64(*memory), GCKVIPPTR_TO_UINT64(logical),
					 GCKVIPPTR_TO_UINT64(*handle), size, align, alloc_flag);
		}
#endif

		status = VIP_SUCCESS;
		*physical = virtual;
	}

#if vpmdENABLE_DEBUGFS
	gckvip_debug_videomemory_profile_alloc(GCVIP_ALIGN(size, align));
#endif

	if ((alloc_flag & GCVIP_VIDEO_MEM_ALLOC_FLAG_4GB_ADDR) &&
		(phy_addr & 0xFFFFFFFF00000000ULL)) {
		PRINTK_E("failed to allocate, physical=0x%" PRIx64" is larger than 4G, alloc_flag=0x%x\n",
				 phy_addr, alloc_flag);
	}

	if ((*physical % align) != 0) {
		PRINTK_E("failed to allocate, physical=0x%08x, not align=0x%x\n",
				 *physical, align);
		gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
	}

#if vpmdENABLE_SECURE
	ptr->memory_type |= secure_flag;
#endif

	return status;

onError:
	if (ptr != VIP_NULL) {
		gckvip_os_free_memory(ptr);
	}
	*handle = VIP_NULL;
	*memory = VIP_NULL;
	*physical = 0;
	PRINTK_E("failed to allocate video memory status=%d\n", status);
	return status;
}

/*
@brief free video memory.
@param context, the contect of kernel space.
@handle the handle of video memory.
*/
vip_status_e gckvip_mem_free_videomemory(
	gckvip_context_t *context,
	void *handle
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_video_mem_handle_t *ptr = (gckvip_video_mem_handle_t *)handle;

#if vpmdENABLE_DEBUGFS
	gckvip_debug_videomemory_profile_free(handle);
#endif

	PRINTK_D("free video memory handle=0x%" PRIx64"\n", GCKVIPPTR_TO_UINT64(ptr));

	if (ptr != VIP_NULL) {
#if vpmdENABLE_SECURE
		if ((ptr->memory_type & GCVIP_VIDEO_MEMORY_TYPE_SECURE) == GCVIP_VIDEO_MEMORY_TYPE_SECURE) {
			context->ptr_STLB_1M = &context->secu_STLB_1M;
			context->ptr_STLB_4K = &context->secu_STLB_4K;
		} else {
			context->ptr_STLB_1M = &context->STLB_1M;
			context->ptr_STLB_4K = &context->STLB_4K;
		}
#endif

		if (GCVIP_VIDEO_MEMORY_TYPE_VIDO_HEAP & ptr->memory_type) {
#if vpmdENABLE_VIDEO_MEMORY_HEAP
			gcOnError(gckvip_heap_free(&context->video_mem_heap, ptr->node.heap_node));
#else
			PRINTK_E("fail to free memory, video memory heap has been disable,"
					 "vpmdENABLE_VIDEO_MEMORY_HEAP=0\n");
#endif
		} else if (GCVIP_VIDEO_MEMORY_TYPE_DYN_ALLOC & ptr->memory_type) {
			gckvip_dyn_allocate_node_t *node = &ptr->node.dyn_node;
			/* unmap mmu */
#if vpmdENABLE_MMU
			if (0x00 == (node->mem_flag & GCVIP_MEM_FLAG_NO_MMU_PAGE)) {
				gcOnError(gckvip_mem_unmap_dyn_memory(context, handle));
			}
#endif
			/* free pages */
			gcOnError(gckvip_allocator_dyn_free(context, node));
		} else {
			PRINTK_E("failed mem free video memory, error memory type=0x%x\n", ptr->memory_type);
			gcGoOnError(VIP_ERROR_OUT_OF_MEMORY);
		}
		gcOnError(gckvip_os_free_memory(ptr));
	} else {
		PRINTK_E("mem free video memory parameter is NULL\n");
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	return status;

onError:
	PRINTK_E("failed to free video memory\n");

	return status;
}

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
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_video_mem_handle_t *ptr = VIP_NULL;
	gckvip_context_t *context = gckvip_get_context();
	void *kernel_logical = VIP_NULL;
	phy_address_t cpu_physical = 0;
	vip_uint32_t vip_virtual = physical;

	if (VIP_NULL == handle) {
		PRINTK_E("failed to flush video memory cache, handle is NULL\n");
		return VIP_ERROR_FAILURE;
	}

	ptr = (gckvip_video_mem_handle_t *)handle;

#if vpmdENABLE_MULTIPLE_TASK
	gckvip_os_lock_mutex(context->flush_cache_mutex);
#endif

	/* get kernel space logical */
	gcOnError(gckvip_mem_get_kernellogical(context, handle, vip_virtual, (void **)&kernel_logical));
	/* get cpu physical */
	gcOnError(gckvip_mem_get_cpuphysical(context, handle, kernel_logical, &cpu_physical));

	if ((GCVIP_VIDEO_MEMORY_TYPE_WRAP_USER_LOGICAL & ptr->memory_type) ||
		(GCVIP_VIDEO_MEMORY_TYPE_DYN_ALLOC & ptr->memory_type)) {
		/* flush dynamic video memory CPU cache */
		gckvip_dyn_allocate_node_t *node = &ptr->node.dyn_node;
		gcOnError(gckvip_alloctor_flush_cache(context, node, cpu_physical, kernel_logical, size, type));
	} else if (GCVIP_VIDEO_MEMORY_TYPE_VIDO_HEAP & ptr->memory_type) {
		gcOnError(gckvip_os_flush_cache(cpu_physical, kernel_logical, size, type));
	} else {
		PRINTK_E("flush cache, no the memory type=0x%x, handle=0x%lx\n", ptr->memory_type, handle);
	}

#if vpmdENABLE_MULTIPLE_TASK
	gckvip_os_unlock_mutex(context->flush_cache_mutex);
#endif

	return status;

onError:
#if vpmdENABLE_MULTIPLE_TASK
	gckvip_os_unlock_mutex(context->flush_cache_mutex);
#endif
	PRINTK_E("failed to gckvip flush cache, handle=0x%" PRIx64", physical=0x%x, size=0x%x\n",
			 GCKVIPPTR_TO_UINT64(handle), physical, size);
	return status;
}
#endif
