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
#include <gc_vip_video_memory.h>
#include <gc_vip_kernel_drv.h>
#include <gc_vip_kernel_debug.h>

#if vpmdENABLE_HANG_DUMP
typedef struct _gcsiDEBUG_REGISTERS {
	vip_char_t     *module;
	vip_uint32_t    index;
	vip_uint32_t    shift;
	vip_uint32_t    data;
	vip_uint32_t    count;
	vip_uint32_t    pipeMask;
	vip_uint32_t    selectStart;
	vip_bool_e      avail;
	vip_bool_e      inCluster;
}
gcsiDEBUG_REGISTERS;

static vip_status_e verify_dma(
	vip_uint32_t *address1,
	vip_uint32_t *address2,
	vip_uint32_t *state1,
	vip_uint32_t *state2
)
{
	vip_status_e error = VIP_SUCCESS;
	vip_int32_t i;

	do {
		gckvip_read_register(0x00660, state1);
		gckvip_read_register(0x00660, state1);
		gckvip_read_register(0x00664, address1);
		gckvip_read_register(0x00664, address1);

		for (i = 0; i < 500; i += 1) {
			gckvip_read_register(0x00660, state2);
			gckvip_read_register(0x00660, state2);
			gckvip_read_register(0x00664, address2);
			gckvip_read_register(0x00664, address2);

			if (*address1 != *address2) {
				break;
			}

			if (*state1 != *state2) {
				break;
			}
		}
	} while (0);

	return error;
}

static vip_status_e dump_fe_stack(void)
{
	vip_int32_t i;
	vip_int32_t j;
	vip_uint32_t stack[32][2];
	vip_uint32_t link[32];

	typedef struct _gcsFE_STACK {
		vip_char_t     *name;
		vip_int32_t     count;
		vip_uint32_t    highSelect;
		vip_uint32_t    lowSelect;
		vip_uint32_t    linkSelect;
		vip_uint32_t    clear;
		vip_uint32_t    next;
	}
	gcsFE_STACK;

	static gcsFE_STACK _feStacks[] = {
		{ "PRE_STACK", 32, 0x1A, 0x9A, 0x00, 0x1B, 0x1E },
		{ "CMD_STACK", 32, 0x1C, 0x9C, 0x1E, 0x1D, 0x1E },
	};

	for (i = 0; i < 2; i++) {
		gckvip_write_register(0x00470, _feStacks[i].clear);

		for (j = 0; j < _feStacks[i].count; j++) {
			gckvip_write_register(0x00470, _feStacks[i].highSelect);

			gckvip_read_register(0x00450, &stack[j][0]);

			gckvip_write_register(0x00470, _feStacks[i].lowSelect);

			gckvip_read_register(0x00450, &stack[j][1]);

			gckvip_write_register(0x00470, _feStacks[i].next);

			if (_feStacks[i].linkSelect) {
				gckvip_write_register(0x00470, _feStacks[i].linkSelect);

				gckvip_read_register(0x00450, &link[j]);
			}
		}

		gckvip_os_print("   %s:\n", _feStacks[i].name);

		for (j = 31; j >= 3; j -= 4) {
			gckvip_os_print("     %08X %08X %08X %08X %08X %08X %08X %08X\n",
							stack[j][0], stack[j][1], stack[j - 1][0], stack[j - 1][1],
							stack[j - 2][0], stack[j - 2][1], stack[j - 3][0],
							stack[j - 3][1]);
		}

		if (_feStacks[i].linkSelect) {
			gckvip_os_print("   LINK_STACK:\n");

			for (j = 31; j >= 3; j -= 4) {
				gckvip_os_print("     %08X %08X %08X %08X %08X %08X %08X %08X\n",
								link[j], link[j], link[j - 1], link[j - 1],
								link[j - 2], link[j - 2], link[j - 3], link[j - 3]);
			}
		}

	}

	return VIP_SUCCESS;
}

static vip_status_e _dump_debug_registers(
	IN gcsiDEBUG_REGISTERS *descriptor
)
{
	/* If this value is changed, print formats need to be changed too. */
#define REG_PER_LINE 8
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t select;
	vip_uint32_t i, j, pipe;
	vip_uint32_t datas[REG_PER_LINE];
	vip_uint32_t oldControl, control;

	/* Record control. */
	gckvip_read_register(0x0, &oldControl);

	for (pipe = 0; pipe < 4; pipe++) {
		if (!descriptor->avail) {
			continue;
		}
		if (!(descriptor->pipeMask & (1 << pipe))) {
			continue;
		}

		gckvip_os_print("     %s[%d] debug registers:\n", descriptor->module, pipe);

		/* Switch pipe. */
		gckvip_read_register(0x0, &control);
		control &= ~(0xF << 20);
		control |= (pipe << 20);
		gckvip_write_register(0x0, control);

		for (i = 0; i < descriptor->count; i += REG_PER_LINE) {
			/* Select of first one in the group. */
			select = i + descriptor->selectStart;

			/* Read a group of registers. */
			for (j = 0; j < REG_PER_LINE; j++) {
				/* Shift select to right position. */
				gckvip_write_register(descriptor->index, (select + j) << descriptor->shift);
				gckvip_read_register(descriptor->data, &datas[j]);
			}

			gckvip_os_print("     [%02X] %08X %08X %08X %08X %08X %08X %08X %08X\n",
							select, datas[0], datas[1], datas[2], datas[3], datas[4],
							datas[5], datas[6], datas[7]);
		}
	}

	/* Restore control. */
	gckvip_write_register(0x0, oldControl);
	return status;
}

#if vpmdENABLE_MMU
#define _read_page_entry(page_entry)  *(vip_uint32_t*)(page_entry)

static vip_status_e gckvip_dump_mtlb(
	gckvip_context_t *context
)
{
	gckvip_os_print("\n*****DUMP MMU entry******\n");
	gckvip_dump_data(context->MMU_entry.logical,
					 context->MMU_entry.physical,
					 context->MMU_entry.size
					);

	gckvip_os_print("*****DUMP MTLB******\n");
	gckvip_dump_data(context->MTLB.logical,
					 context->MTLB.physical,
					 context->MTLB.size);

	return VIP_SUCCESS;
}

static vip_status_e gckvip_dump_stlb(
	gckvip_context_t *context
)
{
	vip_uint32_t i = 0;
	vip_uint32_t *logical = (vip_uint32_t *)context->ptr_STLB_1M->logical;
	vip_uint32_t unit = context->ptr_STLB_1M->size / sizeof(vip_uint32_t);
	vip_uint32_t dump_size = 0;
	vip_uint32_t *tmp = VIP_NULL;

	gckvip_os_print("\n*****DUMP STLB Start******\n");
	gckvip_os_print("dump 1Mbytes STLB:\n");

	for (i = 0; i < unit;) {
		if (logical[i] != 0) {
			tmp = (vip_uint32_t *)context->ptr_STLB_1M->logical + i;
			if ((unit - i) >= 8) {
				dump_size = 8 * sizeof(vip_uint32_t);
			} else {
				dump_size = (unit - i) * sizeof(vip_uint32_t);
			}
			gckvip_dump_data(tmp,
							 context->ptr_STLB_1M->physical + sizeof(vip_uint32_t) * i,
							 dump_size);
			i += 8;
		} else {
			i++;
		}
	}

	gckvip_os_print("dump 4Kbytes STLB:\n");
	unit = context->ptr_STLB_4K->size / sizeof(vip_uint32_t);
	logical = (vip_uint32_t *)context->ptr_STLB_4K->logical;
	for (i = 0; i < unit;) {
		if (logical[i] != 0) {
			tmp = (vip_uint32_t *)context->ptr_STLB_4K->logical + i;
			if ((unit - i) >= 8) {
				dump_size = 8 * sizeof(vip_uint32_t);
			} else {
				dump_size = (unit - i) * sizeof(vip_uint32_t);
			}
			gckvip_dump_data(tmp,
							 context->ptr_STLB_4K->physical + sizeof(vip_uint32_t) * i,
							 dump_size);
			i += 8;
		} else {
			i++;
		}
	}
	gckvip_os_print("*****DUMP STLB Done******\n");

	return VIP_SUCCESS;
}

static vip_status_e gckvip_dump_mmu_info(
	gckvip_context_t *context
)
{
	vip_uint32_t mmu_status = 0;
	vip_uint32_t mmu_temp = 0;
	vip_uint32_t address = 0;
	vip_uint32_t mmu = 0;
	vip_uint32_t i = 0;
	vip_uint8_t page_type = GCVIP_MMU_4K_PAGE;
	vip_uint32_t stlb_shift = 0;
	vip_uint32_t stlb_mask = 0;
	vip_uint32_t pgoff_mask = 0;
	vip_uint32_t mtlb = 0;
	vip_uint32_t stlb = 0;
	vip_uint32_t offset = 0;
	vip_uint32_t *stlb_logical = VIP_NULL;

	gckvip_read_register(0x00384, &mmu_status);
	gckvip_os_print("  MMU status = 0x%08X\n", mmu_status);

	if (mmu_status > 0) {
		gckvip_os_print("\n ***********************\n");
		gckvip_os_print("***   MMU ERROR DUMP   ***\n");
		gckvip_os_print("\n ***********************\n");
		mmu_temp = mmu_status;
	}

	for (i = 0; i < 4; i++) {
		mmu = mmu_status & 0xF;
		mmu_status >>= 4;

		if (mmu == 0) {
			continue;
		}

		switch (mmu) {
		case 1:
			gckvip_os_print("  MMU%d: slave not present\n", i);
			break;

		case 2:
			gckvip_os_print("  MMU%d: page not present\n", i);
			break;

		case 3:
			gckvip_os_print("  MMU%d: write violation\n", i);
			break;

		case 4:
			gckvip_os_print("  MMU%d: out of bound", i);
			break;

		case 5:
			gckvip_os_print("  MMU%d: read security violation", i);
			break;

		case 6:
			gckvip_os_print("  MMU%d: write security violation", i);
			break;

		default:
			gckvip_os_print("  MMU%d: unknown state\n", i);
		}

		gckvip_read_register(0x00380, &address);

		if ((address >= context->axi_sram_address) &&
			(address < (context->axi_sram_address + context->axi_sram_size))) {
			gckvip_os_print("  MMU%d: exception address = 0x%08X, mapped AXI SRAM.\n",
							i, address);
			page_type = GCVIP_MMU_1M_PAGE;
		} else if ((address >= context->vip_sram_address) &&
				   (address < (context->vip_sram_address + context->vip_sram_size))) {
			gckvip_os_print("  MMU%d: exception address = 0x%08X, mapped VIP SRAM.\n",
							i, address);
			page_type = GCVIP_MMU_1M_PAGE;
		}
#if vpmdENABLE_VIDEO_MEMORY_HEAP
		else if ((address >= context->vip_virtual_base) &&
				 (address < (context->vip_virtual_base + context->mem_size))) {
			gckvip_os_print("  MMU%d: exception address = 0x%08X, mapped VIP SRAM.\n",
							i, address);
			page_type = GCVIP_MMU_1M_PAGE;
		}
#endif
		else {
			gckvip_os_print("  MMU%d: exception address = 0x%08X, "
							"it is not mapped or dynamic memory.\n",  i, address);
			page_type = GCVIP_MMU_4K_PAGE;
		}

		if (GCVIP_MMU_1M_PAGE == page_type) {
			pgoff_mask = gcdMMU_OFFSET_1M_MASK;
			stlb_shift = gcdMMU_STLB_1M_SHIFT;
			stlb_mask  = gcdMMU_STLB_1M_MASK;
		} else {
			pgoff_mask = gcdMMU_OFFSET_4K_MASK;
			stlb_shift = gcdMMU_STLB_4K_SHIFT;
			stlb_mask  = gcdMMU_STLB_4K_MASK;
		}

		mtlb   = (address & gcdMMU_MTLB_MASK) >> gcdMMU_MTLB_SHIFT;
		stlb   = (address & stlb_mask) >> stlb_shift;
		offset =  address & pgoff_mask;

		gckvip_os_print("  MMU%d: exception address = 0x%08X\n", i, address);
		gckvip_os_print("    MTLB entry = %d\n", mtlb);
		gckvip_os_print("    STLB entry = %d\n", stlb);
		gckvip_os_print("    Offset = 0x%08X (%d)\n", offset, offset);

		/* get page entry*/
		if (GCVIP_MMU_1M_PAGE == page_type) {
			stlb_logical = (vip_uint32_t *)((vip_uint8_t *)context->ptr_STLB_1M->logical + \
											(mtlb * gcdMMU_STLB_1M_SIZE));
		} else if (GCVIP_MMU_4K_PAGE == page_type) {
			stlb_logical = (vip_uint32_t *)((vip_uint8_t *)context->ptr_STLB_4K->logical +  \
											((mtlb - gcdMMU_1M_MTLB_COUNT) * gcdMMU_STLB_4K_SIZE));
		}

		gckvip_os_print("    Page table entry = 0x%08X",
						_read_page_entry(stlb_logical + stlb));

		if (mmu_temp > 0) {
			gckvip_dump_mtlb(context);
			gckvip_dump_stlb(context);
		}
	}

	return VIP_SUCCESS;
}
#endif

/*
    @ brief

    Dump debug register values. So far just for IDLE, FE, PE, and SH.
*/
vip_status_e gckvip_dump_states(
	gckvip_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;

	vip_uint32_t idleState = 0;
	vip_uint32_t dmaaddress1 = 0, dmaaddress2 = 0;
	vip_uint32_t dmastate1 = 0, dmastate2 = 0, dmaReqState = 0;
	vip_uint32_t cmdState = 0, cmdDmaState = 0, cmdFetState = 0, calState = 0;
	vip_uint32_t axiStatus = 0, dmaLo = 0, dmaHi = 0, veReqState = 0;
	vip_uint32_t control = 0, oldControl = 0, pipe = 0, mmuData = 0;
	vip_uint32_t ack_value = 0;

	static vip_char_t *_cmdState[] = {
		"PAR_IDLE_ST", "PAR_DEC_ST", "PAR_ADR0_ST", "PAR_LOAD0_ST",
		"PAR_ADR1_ST", "PAR_LOAD1_ST", "PAR_3DADR_ST", "PAR_3DCMD_ST",
		"PAR_3DCNTL_ST", "PAR_3DIDXCNTL_ST", "PAR_INITREQDMA_ST", "PAR_DRAWIDX_ST",
		"PAR_DRAW_ST", "PAR_2DRECT0_ST", "PAR_2DRECT1_ST", "PAR_2DDATA0_ST",
		"PAR_2DDATA1_ST", "PAR_WAITFIFO_ST", "PAR_WAIT_ST", "PAR_LINK_ST",
		"PAR_END_ST", "PAR_STALL_ST", "INVALID_PAR_ST", "INVALID_PAR_ST",
		"INVALID_PAR_ST", "INVALID_PAR_ST", "INVALID_PAR_ST", "INVALID_PAR_ST",
		"INVALID_PAR_ST", "INVALID_PAR_ST", "INVALID_PAR_ST", "INVALID_PAR_ST"
	};

	static vip_char_t *_cmdDmaState[] = {
		"CMD_IDLE_ST", "CMD_START_ST", "CMD_REQ_ST", "CMD_END_ST"
	};

	static vip_char_t *_cmdFetState[] = {
		"FET_IDLE_ST", "FET_RAMVALID_ST", "FET_VALID_ST", "INVALID_FET_ST"
	};

	static vip_char_t *_reqDmaState[] = {
		"REQ_IDLE_ST", "REQ_WAITIDX_ST", "REQ_CAL_ST", "INVALID_REQ_ST"
	};

	static vip_char_t *_calState[] = {
		"CAL_IDLE_ST", "CAL_LDADR_ST", "CAL_IDXCALC_ST", "INVALID_CAL_ST"
	};

	static vip_char_t *_veReqState[] = {
		"VER_IDLE_ST", "VER_CKCACHE_ST", "VER_MISS_ST", "INVALID_VER_ST"
	};

	/* All module names here. */
	const char *module_name[] = {
		"FE",        "NULL",      "NULL",      "SH",        "NULL",
		"NULL",      "NULL",      "NULL",      "NULL",      "NULL",
		"NULL",      "NULL",      "NULL",      "FE BLT",    "MC",
		"NULL",      "NULL",      "NULL",      "NN",        "TP",
		"Scaler"
	};

	/* must keep order correctly for _dbgRegs,
	   we need ajust some value base on the index
	*/
	static gcsiDEBUG_REGISTERS _dbgRegs[] = {
		{ "RA",  0x474, 16, 0x448, 256, 0x1, 0x00, vip_true_e,  vip_true_e  },
		{ "TX",  0x474, 24, 0x44C, 128, 0x1, 0x00, vip_true_e,  vip_true_e  },
		{ "FE",  0x470,  0, 0x450, 256, 0x1, 0x00, vip_true_e,  vip_false_e },
		{ "PE",  0x470, 16, 0x454, 256, 0x3, 0x00, vip_true_e,  vip_true_e  },
		{ "DE",  0x470,  8, 0x458, 256, 0x1, 0x00, vip_true_e,  vip_false_e },
		{ "SH",  0x470, 24, 0x45C, 256, 0x1, 0x00, vip_true_e,  vip_true_e  },
		{ "PA",  0x474,  0, 0x460, 256, 0x1, 0x00, vip_true_e,  vip_true_e  },
		{ "SE",  0x474,  8, 0x464, 256, 0x1, 0x00, vip_true_e,  vip_true_e  },
		{ "MC",  0x478,  0, 0x468, 256, 0x3, 0x00, vip_true_e,  vip_true_e  },
		{ "HI",  0x478,  8, 0x46C, 256, 0x1, 0x00, vip_true_e,  vip_false_e },
		{ "TPG", 0x474, 24, 0x44C,  32, 0x2, 0x80, vip_true_e, vip_true_e  },
		{ "TFB", 0x474, 24, 0x44C,  32, 0x2, 0xA0, vip_true_e, vip_true_e  },
		{ "USC", 0x474, 24, 0x44C,  64, 0x2, 0xC0, vip_true_e, vip_true_e  },
		{ "L2",  0x478,  0, 0x564, 256, 0x1, 0x00, vip_true_e,  vip_false_e },
		{ "BLT", 0x478, 24, 0x1A4, 256, 0x1, 0x00, vip_true_e, vip_true_e  },
		{ "WD",  0xF0,  16, 0xF4,  256, 0x1, 0x00, vip_true_e, vip_false_e },
		{ "NN",  0x474, 24, 0x44C, 256, 0x2, 0x00, vip_true_e, vip_true_e  },
	};

	static vip_uint32_t _otherRegs[] = {
		0x00040, 0x00044, 0x0004C,
		0x00050, 0x00054, 0x00058,
		0x0005C, 0x00060, 0x0043C,
		0x00440, 0x00444, 0x414, 0x00100
	};

	vip_uint32_t i = 0;
	vip_uint32_t n_modules = sizeof(module_name) / sizeof(const char *);

	/* Verify whether DMA is running. */
	gcOnError(verify_dma(&dmaaddress1, &dmaaddress2, &dmastate1, &dmastate2));

	cmdState    = dmastate2         & 0x1F;
	cmdDmaState = (dmastate2 >> 8)  & 0x03;
	cmdFetState = (dmastate2 >> 10) & 0x03;
	dmaReqState = (dmastate2 >> 12) & 0x03;
	calState    = (dmastate2 >> 14) & 0x03;
	veReqState  = (dmastate2 >> 16) & 0x03;

	/* Get debug value. */
	gckvip_read_register(0x00004, &idleState);
	gckvip_read_register(0x0000C, &axiStatus);
	gckvip_read_register(0x00668, &dmaLo);
	gckvip_read_register(0x00668, &dmaLo);
	gckvip_read_register(0x0066C, &dmaHi);
	gckvip_read_register(0x0066C, &dmaHi);

	gckvip_os_print("\n ***********************************\n");
	gckvip_os_print("\n ******** VIPLite hang dump ********\n");
	gckvip_os_print("\n ***********************************\n");
	gckvip_os_print("   chip ver1     = 0x%08X\n", context->chip_ver1);
	gckvip_os_print("   chip ver2     = 0x%08X\n", context->chip_ver2);
	gckvip_os_print("   chip date     = 0x%08X\n", context->chip_date);
	gckvip_os_print("   chip cid      = 0x%08X\n", context->chip_cid);
	gckvip_os_print("\n ***********************************\n");
	gckvip_os_print("   axi     = 0x%08X\n", axiStatus);
	gckvip_os_print("   idle    = 0x%08X\n", idleState);
	for (i = 0; i < n_modules; i++) {
		if ((idleState & 0x01) == 0) {
			gckvip_os_print("     %s: not idle.\n", module_name[i]);
		}
		idleState >>= 1;
	}
	if ((idleState & 0x80000000) != 0) {
		gckvip_os_print("   AXI low power mode\n");
	}

	if ((dmaaddress1 == dmaaddress2) && (dmastate1 == dmastate2)) {
		gckvip_os_print("   DMA appears to be stuck at this address: 0x%08X \n",
						dmaaddress1);
	} else {
		if (dmaaddress1 == dmaaddress2) {
			gckvip_os_print("   DMA address is constant, but state is changing:\n");
			gckvip_os_print("      0x%08X\n", dmastate1);
			gckvip_os_print("      0x%08X\n", dmastate2);
		} else {
			gckvip_os_print("   DMA is running; known addresses are:\n");
			gckvip_os_print("     0x%08X\n", dmaaddress1);
			gckvip_os_print("     0x%08X\n", dmaaddress2);
		}
	}

	gckvip_os_print("   dmaLow   = 0x%08X\n", dmaLo);
	gckvip_os_print("   dmaHigh  = 0x%08X\n", dmaHi);
	gckvip_os_print("   dmaState = 0x%08X\n", dmastate2);

	gckvip_os_print("     command state       = %d (%s)\n",
					cmdState,    _cmdState   [cmdState]);
	gckvip_os_print("     command DMA state   = %d (%s)\n",
					cmdDmaState, _cmdDmaState[cmdDmaState]);
	gckvip_os_print("     command fetch state = %d (%s)\n",
					cmdFetState, _cmdFetState[cmdFetState]);
	gckvip_os_print("     DMA request state   = %d (%s)\n",
					dmaReqState, _reqDmaState[dmaReqState]);
	gckvip_os_print("     cal state           = %d (%s)\n",
					calState,    _calState   [calState]);
	gckvip_os_print("     VE request state    = %d (%s)\n",
					veReqState,  _veReqState [veReqState]);

	/* read interrupt value */
	gckvip_read_register(0x00010, &ack_value);
	gckvip_os_print("   interrupt ACK value=0x%x", ack_value);

	/* Record control. */
	gckvip_read_register(0x0, &oldControl);

	/* Switch pipe. */
	gckvip_read_register(0x0, &control);
	control &= ~(0xF << 20);
	control |= (pipe << 20);
	gckvip_write_register(0x0, control);

	gckvip_os_print("   Debug registers:\n");
	for (i = 0; i < sizeof(_dbgRegs) / sizeof(_dbgRegs[0]); i += 1) {
		_dump_debug_registers(&_dbgRegs[i]);
	}

	gckvip_os_print("   other registers:\n");
	for (i = 0; i < (sizeof(_otherRegs) / sizeof((_otherRegs)[0])); i += 1) {
		vip_uint32_t read;
		gckvip_read_register(_otherRegs[i], &read);
		gckvip_os_print("      [0x%04X] 0x%08X\n", _otherRegs[i], read);
	}

	/* dump MMU info */
	gckvip_read_register(0x00388, &mmuData);
	if ((mmuData & 0x01) == 0x00) {
		gckvip_os_print("   MMU has been disabled\n");
	}
#if vpmdENABLE_MMU
	else {
		gckvip_os_print("   MMU enabled\n");
		gckvip_dump_mmu_info(context);
	}
#endif

	/* Restore control. */
	gckvip_write_register(0x0, oldControl);

	gckvip_os_print("   dump FE stack:\n");
	dump_fe_stack();

	gckvip_os_print("**************************\n");
	gckvip_os_print("*****   SW COUNTERS  *****\n");
	gckvip_os_print("**************************\n");
	gckvip_os_print("    Execute Count = 0x%08X\n", context->execute_count);
	gckvip_os_print("    Execute Addr  = 0x%08X\n", context->curr_command.cmd_physical);
	gckvip_os_print("    End     Addr  = 0x%08X\n",
					context->curr_command.cmd_physical + context->curr_command.cmd_size);
	gckvip_os_print("    Execute Cmd Size = 0x%08X\n", context->curr_command.cmd_size);

onError:
	return status;
}

vip_status_e gckvip_dump_waitlink(
	vip_uint32_t *data,
	vip_uint32_t physical
)
{
	gckvip_os_print("   WAIT LINK BUF DUMP\n");

	gckvip_os_print("%08X : %08X %08X %08X %08X\n",
					physical, data[0], data[1], data[2], data[3]);

	return VIP_SUCCESS;
}

vip_status_e gckvip_dump_data(
	vip_uint32_t *data,
	vip_uint32_t physical,
	vip_uint32_t size
)
{
	vip_uint32_t i = 0;
	vip_uint32_t line = size / 32;
	vip_uint32_t left = size % 32;

	for (i = 0; i < line; i++) {
		gckvip_os_print("%08X : %08X %08X %08X %08X %08X %08X %08X %08X\n",
						physical, data[0], data[1], data[2], data[3],
						data[4], data[5], data[6], data[7]);
		data += 8;
		physical += 8 * 4;
	}

	switch (left) {
	case 28:
		gckvip_os_print("%08X : %08X %08X %08X %08X %08X %08X %08X\n",
						physical, data[0], data[1], data[2], data[3],
						data[4], data[5], data[6]);
		break;
	case 24:
		gckvip_os_print("%08X : %08X %08X %08X %08X %08X %08X\n",
						physical, data[0], data[1], data[2], data[3],
						data[4], data[5]);
		break;
	case 20:
		gckvip_os_print("%08X : %08X %08X %08X %08X %08X\n",
						physical, data[0], data[1], data[2], data[3],
						data[4]);
		break;
	case 16:
		gckvip_os_print("%08X : %08X %08X %08X %08X\n", physical, data[0],
						data[1], data[2], data[3]);
		break;
	case 12:
		gckvip_os_print("%08X : %08X %08X %08X\n", physical, data[0],
						data[1], data[2]);
		break;
	case 8:
		gckvip_os_print("%08X : %08X %08X\n", physical, data[0], data[1]);
		break;
	case 4:
		gckvip_os_print("%08X : %08X\n", physical, data[0]);
		break;
	default:
		break;
	}

	return VIP_SUCCESS;
}

#if vpmdENABLE_MMU
vip_status_e gckvip_dump_flush_MMUCmds(
	gckvip_video_memory_t *buffer
)
{
	gckvip_os_print("   FLUSH MMU CMD DUMP %dbyte\n", buffer->size);

	gckvip_dump_data((vip_uint32_t *)buffer->logical, buffer->physical, buffer->size);

	return VIP_SUCCESS;
}
#endif

vip_status_e gckvip_dump_command(
	gckvip_submit_t *submit
)
{
	vip_uint32_t dmaAddr = 0xFFFFF;
	vip_uint32_t dmaLo = 0;
	vip_uint32_t dmaHi = 0;

	if (VIP_NULL != submit->cmd_logical) {
		gckvip_os_print("**************************\n");
		gckvip_os_print("   COMMAND BUF DUMP\n");
		gckvip_os_print("**************************\n");
		gckvip_os_print("command total size=0x%xbytes, physical=0x%08x, logical=0x%" PRIx64"\n",
						submit->cmd_size, submit->cmd_physical,
						GCKVIPPTR_TO_UINT64(submit->cmd_logical));

		gckvip_read_register(0x00668, &dmaLo);
		gckvip_read_register(0x0066C, &dmaHi);
		gckvip_read_register(0x00664, &dmaAddr);
		gckvip_os_print("DMA Address = 0x%08X\n", dmaAddr);
		gckvip_os_print("   dmaLow   = 0x%08X\n", dmaLo);
		gckvip_os_print("   dmaHigh  = 0x%08X\n", dmaHi);

		gckvip_dump_data((vip_uint32_t *)submit->cmd_logical, submit->cmd_physical,
						 submit->cmd_size);
	} else {
		gckvip_os_print("can't dump command buffer, it is NULL\n");
	}

	return VIP_SUCCESS;
}

vip_status_e gckvip_hang_dump(void)
{
	gckvip_context_t *context = gckvip_get_context();
	gckvip_dump_states(context);
	gckvip_dump_command(&context->curr_command);

	return VIP_SUCCESS;
}

#if vpmdENABLE_HANG_DUMP > 1
static vip_uint32_t gckvip_read_reg(
	vip_uint32_t address
)
{
	vip_uint32_t data = 0;

	gckvip_read_register(address, &data);

	return data;
}

vip_status_e gckvip_dump_AHB_register(void)
{
	vip_uint32_t reg_size = 0x0005000;
	vip_uint32_t line =  reg_size / 8;
	vip_uint32_t left =  reg_size % 8;
	vip_uint32_t physical = 0;
	vip_uint32_t i = 0;

	gckvip_os_print("**************************\n");
	gckvip_os_print("   AHB REGISTER DUMP\n");
	gckvip_os_print("**************************\n");
	gckvip_os_print("AHB register size: %d bytes\n", reg_size);

	for (i = 0; i < line; i++) {
		gckvip_os_print("address: %08X - %08X, value: %08X %08X %08X %08X %08X %08X %08X %08X\n",
						physical, physical + 8, gckvip_read_reg(physical),
						gckvip_read_reg(physical + 1),
						gckvip_read_reg(physical + 2), gckvip_read_reg(physical + 3),
						gckvip_read_reg(physical + 4), gckvip_read_reg(physical + 5),
						gckvip_read_reg(physical + 6), gckvip_read_reg(physical + 7));
		physical += 8;
	}

	switch (left) {
	case 7:
		gckvip_os_print("address: %08X - %08X, value: %08X %08X %08X %08X %08X %08X %08X\n",
						physical, physical + 7, gckvip_read_reg(physical),
						gckvip_read_reg(physical + 1), gckvip_read_reg(physical + 2),
						gckvip_read_reg(physical + 3), gckvip_read_reg(physical + 4),
						gckvip_read_reg(physical + 5), gckvip_read_reg(physical + 6)
					   );
		break;
	case 6:
		gckvip_os_print("address: %08X - %08X, value: %08X %08X %08X %08X %08X %08X\n",
						physical, physical + 6, gckvip_read_reg(physical),
						gckvip_read_reg(physical + 1), gckvip_read_reg(physical + 2),
						gckvip_read_reg(physical + 3), gckvip_read_reg(physical + 4),
						gckvip_read_reg(physical + 5)
					   );
		break;
	case 5:
		gckvip_os_print("address: %08X - %08X, value: %08X %08X %08X %08X %08X\n",
						physical, physical + 5, gckvip_read_reg(physical),
						gckvip_read_reg(physical + 1), gckvip_read_reg(physical + 2),
						gckvip_read_reg(physical + 3), gckvip_read_reg(physical + 4));
		break;
	case 4:
		gckvip_os_print("address: %08X - %08X, value: %08X %08X %08X %08X\n",
						physical, physical + 4, gckvip_read_reg(physical),
						gckvip_read_reg(physical + 1), gckvip_read_reg(physical + 2),
						gckvip_read_reg(physical + 3));
		break;
	case 3:
		gckvip_os_print("address: %08X - %08X, value: %08X %08X %08X\n",
						physical, physical + 3, gckvip_read_reg(physical),
						gckvip_read_reg(physical + 1),  gckvip_read_reg(physical + 2));
		break;
	case 2:
		gckvip_os_print("address: %08X - %08X, value: %08X %08X\n",
						physical, physical + 2, gckvip_read_reg(physical),
						gckvip_read_reg(physical + 1)
					   );
		break;
	case 1:
		gckvip_os_print("address: %08X, value: %08X\n", physical,
						gckvip_read_reg(physical));
		break;
	default:
		break;
	}

	return VIP_SUCCESS;
}
#endif
#endif

/*
@brief report master clock and PPU clock
*/
#if vpmdENABLE_DEBUG_LOG > 2
void gckvip_report_clock(void)
{
	vip_uint64_t mc_freq, sh_freq;

	PRINTK("VIP Frequency:\n");
	if (VIP_SUCCESS == gckvip_hw_get_clock(&mc_freq, &sh_freq)) {
		PRINTK("   Core Frequency=%ld HZ\n", mc_freq);
		PRINTK("   PPU  Frequency=%ld HZ\n", sh_freq);
	} else {
		PRINTK("unable to get VIP frequency.\n");
	}
}

vip_status_e gckvip_dump_options(void)
{
	PRINTK("vpmdENABLE_RECOVERY=%d\n", vpmdENABLE_RECOVERY);
	PRINTK("vpmdHARDWARE_TIMEOUT=%d\n", vpmdHARDWARE_TIMEOUT);
	PRINTK("vpmdENABLE_HANG_DUMP=%d\n", vpmdENABLE_HANG_DUMP);
	PRINTK("vpmdENABLE_USE_AGENT_TRIGGER=%d\n", vpmdENABLE_USE_AGENT_TRIGGER);
	PRINTK("vpmdENABLE_CAPTURE=%d\n", vpmdENABLE_CAPTURE);
	PRINTK("vpmdENABLE_CAPTURE_IN_KERNEL=%d\n", vpmdENABLE_CAPTURE_IN_KERNEL);
	PRINTK("vpmdDUMP_COMMANDS_EVERY_RUN=%d\n", vpmdDUMP_COMMANDS_EVERY_RUN);
	PRINTK("vpmdCREATE_NETWORK_FROM_FLASH=%d\n", vpmdCREATE_NETWORK_FROM_FLASH);
	PRINTK("vpmdENABLE_WAIT_LINK_LOOP=%d\n", vpmdENABLE_WAIT_LINK_LOOP);
	PRINTK("vpmdENABLE_FLUSH_CPU_CACHE=%d\n", vpmdENABLE_FLUSH_CPU_CACHE);
	PRINTK("vpmdENABLE_LAYER_DUMP=%d\n", vpmdENABLE_LAYER_DUMP);
	PRINTK("vpmdENABLE_CNN_PROFILING=%d\n", vpmdENABLE_CNN_PROFILING);
	PRINTK("vpmdENABLE_BW_PROFILING=%d\n", vpmdENABLE_BW_PROFILING);
	PRINTK("vpmdENABLE_MEMORY_PROFILING=%d\n", vpmdENABLE_MEMORY_PROFILING);
	PRINTK("vpmdENABLE_DEBUG_LOG=%d\n", vpmdENABLE_DEBUG_LOG);
	PRINTK("vpmdENABLE_SUPPORT_CPU_LAYER=%d\n", vpmdENABLE_SUPPORT_CPU_LAYER);
	PRINTK("vpmdENABLE_SYS_MEMORY_HEAP=%d\n", vpmdENABLE_SYS_MEMORY_HEAP);
	PRINTK("vpmdENABLE_VIDEO_MEMORY_HEAP=%d\n", vpmdENABLE_VIDEO_MEMORY_HEAP);
	PRINTK("vpmdENABLE_MMU=%d\n", vpmdENABLE_MMU);
	PRINTK("vpmdENABLE_MULTIPLE_TASK=%d, MAX_TASK_NUM=%d\n",
		   vpmdENABLE_MULTIPLE_TASK, SUPPORT_MAX_TASK_NUM);
	PRINTK("vpmdPOWER_OFF_TIMEOUT=%d\n", vpmdPOWER_OFF_TIMEOUT);
	PRINTK("vpmdENABLE_SECURE=%d\n", vpmdENABLE_SECURE);
	PRINTK("vpmdENABLE_SUSPEND_RESUME=%d\n", vpmdENABLE_SUSPEND_RESUME);
	PRINTK("vpmdENABLE_USER_CONTROL_POWER=%d\n", vpmdENABLE_USER_CONTROL_POWER);
	PRINTK("vpmdENABLE_DEBUGFS=%d\n", vpmdENABLE_DEBUGFS);
	PRINTK("vpmdENABLE_GROUP_MODE=%d\n", vpmdENABLE_GROUP_MODE);
	PRINTK("vpmdENABLE_NODE=%d\n", vpmdENABLE_NODE);
	PRINTK("vpmdENABLE_CHANGE_PPU_PARAM=%d\n", vpmdENABLE_CHANGE_PPU_PARAM);

	return VIP_SUCCESS;
}
#endif
