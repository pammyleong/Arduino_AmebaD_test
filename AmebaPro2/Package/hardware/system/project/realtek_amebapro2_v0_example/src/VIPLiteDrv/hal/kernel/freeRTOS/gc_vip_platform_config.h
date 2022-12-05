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


#ifndef _GC_VIP_PLATFORM_CONFIG_H
#define _GC_VIP_PLATFORM_CONFIG_H

// rtk, for NN_BASE
#include "rtl8735b.h"

/* default size 2M for system memory heap, access by CPU only */
#define SYSTEM_MEMORY_HEAP_SIZE         34000 //(2 << 20)

extern uint32_t __nn_eram_start__[];
extern uint32_t __nn_eram_end__[];

/* default size xx bytes for video memory heap, access by VIP */
#define VIDEO_MEMORY_HEAP_SIZE          ( (uint32_t)__nn_eram_end__ - (uint32_t)__nn_eram_start__ ) //(16*1024*1024) //x5000000


/* defalut base pyhsical address of video memory heap */
#define VIDEO_MEMORY_HEAP_BASE_ADDRESS  ( (uint32_t*)__nn_eram_start__ ) //0x73000000 //0x32000000


/* AHB register base physical address */
#define AHB_REGISTER_BASE_ADDRESS       NN_BASE //0xff100000


/* The size of AHB register */
#define AHB_REGISTER_SIZE               0x800 //0x00020000


/* irq line number */
#define IRQ_LINE_NUMBER                 179


/* the size of VIP SRAM */
#define VIP_SRAM_SIZE                   0x20000 //0x100000

/*
The base address of VIP SRAM.
VIP SRAM is a SRAM inside VIP core. It needs to be mapped to a 32 bits address space.
The VIP_SRAM_BASE_ADDRESS is a base address for mapping VIP SRAM, so the VIP SRAM has been mapped to [VIP_SRAM_BASE_ADDRESS ~~ VIP_SRAM_BASE_ADDRESS + VIP_SRAM_SIZE] range.
After this mapping, VIP core access VIP SRAM through VIP_SRAM_BASE_ADDRESS ~~ VIP_SRAM_BASE_ADDRESS+VIP_SRAM_SIZE address range.
Actually, The value of VIP_SRAM_BASE_ADDRESS may not be on DRAM.

example:

The size of DRAM is 1G bytes. So DRAM memory address range is [0 ~~ 0x40000000].
In this case, you can set the value of vip_sram_address to 0x50000000. 0x50000000 is outside of DRAM. 0x50000000 is not a real physical address on SRAM.

If set value to zero, driver will reserve an unused memory fro VIP-SRAM.
If you need to specify address for VIP-SRAM, this value can be outside the range of video memory.
The address shoule be aligned to 64byte.
*/
#define VIP_SRAM_BASE_ADDRESS           0x00

/* the size of AXI SRAM, please set the value to zero if chip without AXI-SRAM. otherwise, follow chip real AXI-SRAM size setting. */
#define AXI_SRAM_SIZE                   0 //0x800000

/* the physical base address of AXI SRAM. The value of AXI_SRAM_BASE_ADDRESS is should be real address of AXI-SRAM on chip if the chip have AXI-SRAM. */
#define AXI_SRAM_BASE_ADDRESS           0xffffffff //0xF0800000

#endif
