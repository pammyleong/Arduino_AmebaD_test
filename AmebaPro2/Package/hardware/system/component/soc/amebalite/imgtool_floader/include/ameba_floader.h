/********************************************************************************
 * Copyright (c) 2014, Realtek Semiconductor Corp.
 * All rights reserved.
 *
 * This module is a confidential and proprietary property of RealTek and
 * possession or use of this module requires written permission of RealTek.
 *******************************************************************************
 */
#include "ameba_floader_rom_parse.h"
#include "xmodem_uart_rom.h"

#ifndef _AMEBA_FLASHLOADER_H
#define _AMEBA_FLASHLOADER_H

#undef IMAGE_WRITE_PARSER
#undef OTP_PROGRAM_ENABLE

#define SUPPORT_LARGE_CAPACITY

#define IS_FLASH_ADDR(addr)			((addr >= SPI_FLASH_BASE) && (addr <= 0x0FFFFFFF))

/*read loguart register cost 199.92ns*/
#define XDEBUG_GPIO					_PA_6
#define WAIT_FRAME_TIME				(5000 * 1000) 		/* 1 sec, wait frame timeout */
#define WAIT_CHAR_TIME				(2500 * 1000)		/* 0.5 sec, wait char timeout */
#define WAIT_TIME_SERVER			(10000 * 1000)		/* 2 sec, server wait timeout */
#define WAIT_HANDSHAKE_TIME			(5000 * 1000)		/* 1 sec, handshake timeout */
#define WAIT_NAK_PERIOD				(250 * 1000)		/* 50 ms, period of send NAK when handshake */

#define FRAME_BUF_ADDR				(char*)(MSP_RAM_HP_NS + 4 - 16 * 1024)
#define HANDSHAKE_BAUD				115200

u32 Get_FlashWriteMethod(void);
u32 Get_LogUartPinmux(void);
void Reboot_Uart_Download(void);
void Cache_Flush_FlashData(u32 Address, u32 Bytes);


#endif

