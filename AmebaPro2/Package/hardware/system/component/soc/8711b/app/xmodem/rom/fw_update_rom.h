/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */

#ifndef _FW_UPDATE_ROM_H_
#define _FW_UPDATE_ROM_H_

#include "ameba_soc.h"

#define BOOT_UART_IDX           0
#define BOOT_UART_PIN_MUX       1
#define BOOT_UART_BAUD_RATE     38400
#define BOOT_UART_MAX_IMG_SZ    (32*1024*1024)      // 32M

#define XMODEM_WRITE_FLASH		0x08
#define XMODEM_WRITE_RAM		0x10

extern u32 sector_addr;
_LONG_CALL_ VOID UARTIMG_Write(char *ptr,  unsigned int wr_offset, unsigned int frame_size);
_LONG_CALL_ VOID UARTIMG_WriteParser(char *ptr,  unsigned int wr_offset, unsigned int frame_size);
#endif  // end of "#define _FW_UPDATE_ROM_H_"

