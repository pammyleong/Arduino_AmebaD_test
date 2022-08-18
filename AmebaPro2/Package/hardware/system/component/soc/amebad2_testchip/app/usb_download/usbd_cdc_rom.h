/**
  ******************************************************************************
  * @file    usbd_cdc_rom.h
  * @author  Realsil WLAN5 Team
  * @version V1.0.0
  * @date    2020-11-23
  * @brief   This file is the header file for usbd_cdc_rom.c
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2020, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef __USBD_CDC_ROM_H
#define __USBD_CDC_ROM_H

/* Includes ------------------------------------------------------------------*/

#include "usbd_hal_rom.h"

/* Exported defines ----------------------------------------------------------*/

/* CDC Endpoints parameters */
#define CDC_IN_EP                                   0x81U  /* EP1 for BULK IN */
#define CDC_OUT_EP                                  0x02U  /* EP2 for BULK OUT */
#define CDC_CMD_EP                                  0x83U  /* EP3 for INTR IN */

#define CDC_HS_BINTERVAL                            0x10U
#define CDC_FS_BINTERVAL                            0x10U

#define CDC_DATA_HS_MAX_PACKET_SIZE                 512U  /* High speed BULK IN & OUT Packet size */
#define CDC_DATA_FS_MAX_PACKET_SIZE                 64U   /* Full speed BULK IN & OUT Packet size */
#define CDC_CMD_PACKET_SIZE                         8U    /* Control Endpoint Packet size */

#define USB_CDC_CONFIG_DESC_SIZ                     67U
#define CDC_DATA_HS_IN_PACKET_SIZE                  CDC_DATA_HS_MAX_PACKET_SIZE
#define CDC_DATA_HS_OUT_PACKET_SIZE                 CDC_DATA_HS_MAX_PACKET_SIZE

#define CDC_DATA_FS_IN_PACKET_SIZE                  CDC_DATA_FS_MAX_PACKET_SIZE
#define CDC_DATA_FS_OUT_PACKET_SIZE                 CDC_DATA_FS_MAX_PACKET_SIZE

#define CDC_DATA_IN_TRANSFER_SIZE                   2056U /* 5 bytes for RXREG response */
#define CDC_DATA_OUT_TRANSFER_SIZE                  2056U /* 2056 bytes for STX request */

/*  CDC definitions */
#define CDC_SEND_ENCAPSULATED_COMMAND               0x00U
#define CDC_GET_ENCAPSULATED_RESPONSE               0x01U
#define CDC_SET_COMM_FEATURE                        0x02U
#define CDC_GET_COMM_FEATURE                        0x03U
#define CDC_CLEAR_COMM_FEATURE                      0x04U
#define CDC_SET_LINE_CODING                         0x20U
#define CDC_GET_LINE_CODING                         0x21U
#define CDC_SET_CONTROL_LINE_STATE                  0x22U
#define CDC_SEND_BREAK                              0x23U

/* CDC buffer defines */
#define CDC_RX_BUF_ADDR                             (USBD_BUF_START_ADDR)    /* Length >= CDC_DATA_OUT_TRANSFER_SIZE */
#define CDC_TX_BUF_ADDR                             (CDC_RX_BUF_ADDR + 4096) /* Length >= CDC_DATA_IN_TRANSFER_SIZE */

/* Exported types ------------------------------------------------------------*/

typedef struct {
	uint32_t bitrate;
	uint8_t  format;
	uint8_t  paritytype;
	uint8_t  datatype;
} USBD_CDC_LineCodingTypeDef;

typedef struct {
	uint8_t (* Init)(void);
	uint8_t (* DeInit)(void);
	uint8_t (* Control)(uint8_t cmd, uint8_t *pbuf, uint16_t length);
	uint8_t (* Receive)(uint8_t *Buf, uint32_t *Len);

} USBD_CDC_ItfTypeDef;

typedef struct {
	uint32_t Data[CDC_DATA_HS_MAX_PACKET_SIZE / 4U];
	uint8_t  CmdOpCode;
	uint8_t  CmdLength;
	uint8_t  *RxBuffer;
	uint8_t  *TxBuffer;
	uint32_t RxLength;
	uint32_t TxLength;

	__IO uint32_t TxState;
	__IO uint32_t RxState;
} USBD_CDC_HandleTypeDef;

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

uint8_t  USBD_CDC_SetTxBuffer(uint8_t  *pbuff, uint16_t length);
uint8_t  USBD_CDC_SetRxBuffer(uint8_t  *pbuff);
uint8_t  USBD_CDC_ReceivePacket(void);
uint8_t  USBD_CDC_TransmitPacket(void);

#endif  /* __USBD_CDC_ROM_H */

