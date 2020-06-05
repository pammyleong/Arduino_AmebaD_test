/********************************************************************************
 * Copyright (c) 2014, Realtek Semiconductor Corp.
 * All rights reserved.
 *
 * This module is a confidential and proprietary property of RealTek and
 * possession or use of this module requires written permission of RealTek.
 *******************************************************************************
 */

#define STX 0x02
#define SOH 0x01
#define ACK 0x06
#define CAN 0x18
#define EOT 0x04
#define NAK 0X15
#define BAUDCHK 0x07
#define RXREG 0x31
#define TXREG 0x29
#define XMERASE 0x17
#define WRITESTATUS 0x26
#define CHECKSUM 0x27
#define XM_REDOWNLOAD 0x35
#define MAXRETRANS 0x06

void xmodem_reset(void);

bool xmodem_handshake(void);

uint8_t* mymemset(uint8_t* xbuff, int index, int num);

uint8_t* mymemcpy(uint8_t* dest, int d_i, uint8_t* src, int d_s, int num);

int startTrans(uint8_t * src, int srcsz, bool use1k, uint32_t addr);

int endtrans(void);

bool TX_Data(const char* name, uint32_t dst_addr, bool flashloaderflag);

bool WriteStatusRegister(uint8_t cmd, uint8_t len, uint8_t* val);

bool WriteRegFromXmodem(void);

bool ReadReg(uint32_t address, uint32_t *value);

bool WriteReg(uint32_t address, uint32_t *value);

bool ErashFlashFromXmodem(void);

bool EraseFlash(uint32_t address,uint32_t len_4k);

uint32_t calculateChecksum(char *name);

uint32_t getChecksumFromXmodem();

uint32_t xmodem_checksum(char *name, uint32_t address);

void redownload(void);

bool download_images(bool flashloaderflag);

void EnterUartDownloadMode();
