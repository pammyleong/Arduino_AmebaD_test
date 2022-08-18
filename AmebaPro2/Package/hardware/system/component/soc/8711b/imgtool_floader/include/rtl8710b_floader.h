/********************************************************************************
 * Copyright (c) 2014, Realtek Semiconductor Corp.
 * All rights reserved.
 *
 * This module is a confidential and proprietary property of RealTek and
 * possession or use of this module requires written permission of RealTek.
 *******************************************************************************
 */
#ifndef _RTL8710B_FLASHLOADER_H
#define _RTL8710B_FLASHLOADER_H

#define IS_FLASH_ADDR(addr)			((addr >= SPI_FLASH_BASE) && (addr <= 0x0FFFFFFF))
#define FLASH_ERASE_AND_WRITE		0
#define FLASH_WRITE_ONLY			BIT_SOC_XMODEM_FLASH_EMPTY
#define FLASH_ERASE_WRITE_PAGE		BIT_SOC_XMODEM_PAGE_PG
#define FLASH_WRITE_PAGE_ONLY		(BIT_SOC_XMODEM_FLASH_EMPTY | BIT_SOC_XMODEM_PAGE_PG)

#define XDEBUG_GPIO					_PA_12
#define WAIT_FRAME_TIME			(2500 * 1000) 			/* 1 sec, wait frame timeout, ACUT: (2500 * 10000) */
#define WAIT_CHAR_TIME				(1250 * 1000)			/* 0.5 sec, wait char timeout ACUT: (1250 * 10000) */
#define WAIT_TIME_SERVER			(5000 * 1000)			/* 2 sec, server wait timeout */
#define WAIT_HANDSHAKE_TIME		(2500 * 1000)			/* 1 sec, handshake timeout, ACUT: (2500 * 10000)  */

#define FRAME_BUF_ADDR				(char*)(__rom_top_4k_start_ - 16 * 1024)
#define HANDSHAKE_BAUD				1500000

extern u8 __rom_top_4k_start_[];

void FLASH_SW_CS_Control(u32 GPIO_State);
void FLASH_TxData256B(u32 StartAddr, u32 DataPhaseLen, u8* pData);
__INLINE u32 Get_FlashWriteMethod(void);
__INLINE u32 Get_LogUartPinmux(void);
void Reboot_Uart_Download(void);
void Cache_Flush_FlashData(u32 Address, u32 Bytes);

#endif

