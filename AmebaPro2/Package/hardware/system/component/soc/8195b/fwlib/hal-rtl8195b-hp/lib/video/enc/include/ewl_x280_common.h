/*------------------------------------------------------------------------------
--                                                                            --
--       This software is confidential and proprietary and may be used        --
--        only as expressly authorized by a licensing agreement from          --
--                                                                            --
--                            Hantro Products Oy.                             --
--                                                                            --
--                   (C) COPYRIGHT 2006 HANTRO PRODUCTS OY                    --
--                            ALL RIGHTS RESERVED                             --
--                                                                            --
--                 The entire notice above must be reproduced                 --
--                  on all copies and should not be removed.                  --
--                                                                            --
--------------------------------------------------------------------------------
--
--  Abstract : Hantro 6280/7280/8270/8290 Encoder Wrapper Layer for OS services
--
------------------------------------------------------------------------------*/
#ifndef __EWL_X280_COMMON_H__
#define __EWL_X280_COMMON_H__

#include <stdio.h>
#include <signal.h>

#include <cmsis.h>
#include <ewl.h>
#include "tm9_cp3.h"


/* Macro for debug printing */
#undef PTRACE


#ifdef TRACE_EWL
//#   include "platform.h"
#ifdef __PXP_RUN__
#include "rtl_libc.h"
#endif
#define PTRACE DBG_ENC_INFO
#else
#define PTRACE(...)  /* no trace */
#endif


#if 0 // remove warring message redefine with encasiccontroller.h
#define ASIC_STATUS_RFC_BUFF_OVERFLOW   0x800
#define ASIC_STATUS_LINE_BUFFER_DONE    0x400
#define ASIC_STATUS_SLICE_READY         0x100
#define ASIC_STATUS_TEST_COPY_RDY       0x80
#define ASIC_STATUS_TEST_IRQ            0x40
#define ASIC_STATUS_BUFF_FULL           0x20
#define ASIC_STATUS_RESET               0x10
#define ASIC_STATUS_ERROR               0x08
#define ASIC_STATUS_FRAME_READY         0x04
#define ASIC_IRQ_LINE                   0x01

#if 1
//#ifdef RT_LINE_BUF
#define ASIC_STATUS_ALL     (ASIC_STATUS_SLICE_READY |\
                             ASIC_STATUS_TEST_IRQ |\
                             ASIC_STATUS_TEST_COPY_RDY |\
                             ASIC_STATUS_FRAME_READY | \
                             ASIC_STATUS_BUFF_FULL | \
                             ASIC_STATUS_RESET | \
                             ASIC_STATUS_ERROR | \
                             ASIC_STATUS_LINE_BUFFER_DONE | \
                             ASIC_STATUS_RFC_BUFF_OVERFLOW)
#else
#define ASIC_STATUS_ALL     (ASIC_STATUS_SLICE_READY |\
                             ASIC_STATUS_TEST_IRQ |\
                             ASIC_STATUS_TEST_COPY_RDY |\
                             ASIC_STATUS_FRAME_READY | \
                             ASIC_STATUS_BUFF_FULL | \
                             ASIC_STATUS_RESET | \
                             ASIC_STATUS_ERROR | \
                             ASIC_STATUS_RFC_BUFF_OVERFLOW)
#endif
#endif
/* the encoder device driver nod */
#ifndef MEMALLOC_MODULE_PATH
#define MEMALLOC_MODULE_PATH        "/tmp/dev/memalloc"
#endif

#ifndef ENC_MODULE_PATH
#define ENC_MODULE_PATH             "/tmp/dev/hx280"
#endif

#ifndef SDRAM_LM_BASE
#define SDRAM_LM_BASE               0x00000000
#endif

/* EWL internal information for Linux */
typedef struct
{
    u32 clientType;
//	int fd_mem;              /* /dev/mem */	// AmebaPro don't use it by Raymond
//	int fd_enc;              /* /dev/hx280 */ // AmebaPro don't use it by Raymond
//	int fd_memalloc;         /* /dev/memalloc */ // AmebaPro don't use it by Raymond
	u32 regSize;             /* IO mem size */
	u32 regBase;
    volatile u32 *pRegBase;  /* IO mem base */
#ifdef PCIE_FPGA_VERIFICATION
    u32 linMemBase;          /* start address of linear memory  wxh added for pcie verification */
#endif
#ifdef PCIE_FPGA_VERI_LINEBUF
    u32 sram_base;
    u32 sram_size;
    volatile u32 *psrame;  /* srame mem base */ 
#endif
    int semid;
    int sigio_needed;

    void *sema;
    void *hw_sema;

    uint32_t cycle_time[7];	// cycle point 0: pre calc.
							// cycle point 1: DDR register update
							// cycle point 2: register write
    						// cycle point 3: HW encode time
    						// cycle point 4: switch time
    						// cycle point 5: post calc. time
    						// cycle point 6: Non used
} hx280ewl_t;

//Add by chris: we don't need this
//void HandleSIGIO(hx280ewl_t * enc);

/**
 *  @brief calculator cycle
 *  @param[in]  hx280ewl_t: encoder struct
 *  @param[in]  u32 sp: calc. cycle point.
 */
__STATIC_INLINE void hal_enc_calc_cycle (const void *inst, u32 sp)
{
    hx280ewl_t *enc = (hx280ewl_t *) inst;

   	enc->cycle_time[sp] = CP3_Read_Counter(COUNTER0_LO);
    if(sp > 0) {
    	enc->cycle_time[sp-1] = enc->cycle_time[sp] - enc->cycle_time[sp-1];
    }
//	return enc->cycle_time[sp-1];
}

/**
 *  @brief get cycle form calculator cycle function
 *  @param[in]  hx280ewl_t: encoder struct
 *  @param[in]  u32 sp: calc. cycle point.
 *  @returns    cycle time.
 */

__STATIC_INLINE uint32_t hal_enc_get_cycle (const void *inst, u32 sp)
{
    hx280ewl_t *enc = (hx280ewl_t *) inst;
	return enc->cycle_time[sp];
}

#endif /* __EWLX280_COMMON_H__ */
