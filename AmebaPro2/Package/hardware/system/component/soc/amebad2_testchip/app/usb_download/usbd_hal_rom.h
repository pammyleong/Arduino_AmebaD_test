/**
  ******************************************************************************
  * @file    usbd_hal_rom.h
  * @author  Realsil WLAN5 Team
  * @version V1.0.0
  * @date    2020-11-23
  * @brief   This file is the header file for usbd_hal_rom.c
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2020, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef USBD_HAL_ROM_H
#define USBD_HAL_ROM_H

/* Includes ------------------------------------------------------------------*/

#include "ameba_soc.h"
#include "usbd_def_rom.h"
#include "usbd_regs_rom.h"
#include "usbd_dbg_rom.h"

/* Exported defines ----------------------------------------------------------*/

/* USB section defines */
#define USBD_DATA_SECTION                      HAL_ROM_DATA_SECTION
#define USBD_BSS_SECTION                       HAL_ROM_BSS_SECTION
#define USBD_TEXT_SECTION                      HAL_ROM_TEXT_SECTION
#define USBD_WEEK                              __weak

/* USB buffer defines */
#define USBD_BUF_START_ADDR                    (MSP_RAM_HP_NS + 4 - 16 * 1024)

/* USB Core SW Configurations */
#define USBD_MAX_NUM_INTERFACES                1U
#define USBD_MAX_NUM_CONFIGURATION             1U
#define USBD_SELF_POWERED                      0U
#define USBD_DMA_ENABLE                        0U
#define USBD_MAX_ENDPOINTS                     4U
#define USBD_RX_FIFO_SIZE                      512U
#define USBD_NPTX_FIFO_SIZE                    256U
#define USBD_PTX_FIFO_SIZE                     64U

/* USB Core HW Configurations */
#define USBD_IN_TOKEN_QUEUE_DEPTH              8U

/* USB Core ID */
#define USB_OTG_CORE_ID_300A                   0x4F54300AU
#define USB_OTG_CORE_ID_310A                   0x4F54310AU

/* USB Core Mode */
#define USB_OTG_MODE_DEVICE                    0U
#define USB_OTG_MODE_HOST                      1U
#define USB_OTG_MODE_DRD                       2U

/* USB Core Speed */
#define USB_OTG_SPEED_HIGH                     0U
#define USB_OTG_SPEED_HIGH_IN_FULL             1U
#define USB_OTG_SPEED_FULL                     3U

/* USB Core Turnaround Timeout Value */
#ifndef USBD_HS_TRDT_VALUE
#define USBD_HS_TRDT_VALUE                     5U
#endif /* USBD_HS_TRDT_VALUE */
#ifndef USBD_FS_TRDT_VALUE
#define USBD_FS_TRDT_VALUE                     9U
#endif /* USBD_HS_TRDT_VALUE */

/* USB Core MPS */
#define USB_OTG_HS_MAX_PACKET_SIZE             512U
#define USB_OTG_FS_MAX_PACKET_SIZE             64U
#define USB_OTG_MAX_EP0_SIZE                   64U

/* USB Core PHY Frequency */
#define DSTS_ENUMSPD_HS_PHY_30MHZ_OR_60MHZ     (0U << 1)
#define DSTS_ENUMSPD_FS_PHY_30MHZ_OR_60MHZ     (1U << 1)
#define DSTS_ENUMSPD_LS_PHY_6MHZ               (2U << 1)
#define DSTS_ENUMSPD_FS_PHY_48MHZ              (3U << 1)

/* USB Core Frame Interval */
#define DCFG_FRAME_INTERVAL_80                 0U
#define DCFG_FRAME_INTERVAL_85                 1U
#define DCFG_FRAME_INTERVAL_90                 2U
#define DCFG_FRAME_INTERVAL_95                 3U

/* USB Core EP0 MPS */
#define DEP0CTL_MPS_64                         0U
#define DEP0CTL_MPS_32                         1U
#define DEP0CTL_MPS_16                         2U
#define DEP0CTL_MPS_8                          3U

/* USB EP Speed */
#define EP_SPEED_LOW                           0U
#define EP_SPEED_FULL                          1U
#define EP_SPEED_HIGH                          2U

/* USB EP Type */
#define EP_TYPE_CTRL                           0U
#define EP_TYPE_ISOC                           1U
#define EP_TYPE_BULK                           2U
#define EP_TYPE_INTR                           3U
#define EP_TYPE_MSK                            3U

/* USB EP Address Mask */
#define EP_ADDR_MSK                            0xFU

/* USB STS Defines */
#define STS_GOUT_NAK                           1U
#define STS_DATA_UPDT                          2U
#define STS_XFER_COMP                          3U
#define STS_SETUP_COMP                         4U
#define STS_SETUP_UPDT                         6U

#define GRXSTS_PKTSTS_IN                       2U
#define GRXSTS_PKTSTS_IN_XFER_COMP             3U
#define GRXSTS_PKTSTS_DATA_TOGGLE_ERR          5U
#define GRXSTS_PKTSTS_CH_HALTED                7U

/* Exported types ------------------------------------------------------------*/

typedef HAL_Status USB_StatusTypeDef;

/* HAL lock definition */
typedef enum {
	USB_HAL_UNLOCKED = 0x00U,
	USB_HAL_LOCKED   = 0x01U
} USB_LockTypeDef;

/* USB configuration structure */
typedef struct {
	uint32_t dev_endpoints;           /*!< Device Endpoints number.
                                         This parameter depends on the used USB core.
                                         This parameter must be a number between Min_Data = 1 and Max_Data = 15 */
	uint32_t speed;                   /*!< USB Core speed.
                                         This parameter can be any value of @ref USB_Core_Speed_                */

	uint32_t dma_enable;              /*!< Enable or disable of the USB embedded DMA used only for OTG HS.        */

	uint32_t ep0_mps;                 /*!< Set the Endpoint 0 Max Packet size.                                    */
} USB_CfgTypeDef;

/* USB endpoint structure */
typedef struct {
	uint8_t   num;                  /*!< Endpoint number
                                       This parameter must be a number between Min_Data = 1 and Max_Data = 15   */

	uint8_t   is_in;                /*!< Endpoint direction
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 1    */

	uint8_t   is_stall;             /*!< Endpoint stall condition
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 1    */

	uint8_t   type;                 /*!< Endpoint type
                                       This parameter can be any value of @ref USB_EP_Type_                     */

	uint8_t   data_pid_start;       /*!< Initial data PID
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 1    */

	uint8_t   even_odd_frame;       /*!< IFrame parity
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 1    */

	uint16_t  tx_fifo_num;          /*!< Transmission FIFO number
                                       This parameter must be a number between Min_Data = 1 and Max_Data = 15   */

	uint32_t  maxpacket;            /*!< Endpoint Max packet size
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 64KB */

	uint8_t   *xfer_buff;           /*!< Pointer to transfer buffer                                               */

	uint32_t  dma_addr;             /*!< 32 bits aligned transfer buffer address                                  */

	uint32_t  xfer_len;             /*!< Current transfer length                                                  */

	uint32_t  xfer_count;           /*!< Partial transfer length in case of multi packet transfer                 */

	uint8_t   is_zlp;               /*!< ZLP packet */
} USB_EPTypeDef;

/* USB device LPM suspend state */
typedef enum {
	LPM_L0 = 0x00, /* on */
	LPM_L1 = 0x01, /* LPM L1 sleep */
	LPM_L2 = 0x02, /* suspend */
	LPM_L3 = 0x03, /* off */
} USB_LPM_StateTypeDef;

/* PCD state */
typedef enum {
	HAL_PCD_STATE_RESET   = 0x00,
	HAL_PCD_STATE_READY   = 0x01,
	HAL_PCD_STATE_ERROR   = 0x02,
	HAL_PCD_STATE_BUSY    = 0x03,
	HAL_PCD_STATE_TIMEOUT = 0x04
} USB_PCD_StateTypeDef;

/* PCD handle structure */
typedef struct {
	USB_CfgTypeDef          Init;        /*!< PCD required parameters            */
	__IO uint8_t            USB_Address; /*!< USB Address                        */
	USB_EPTypeDef           IN_ep[USBD_MAX_ENDPOINTS];   /*!< IN endpoint parameters             */
	USB_EPTypeDef           OUT_ep[USBD_MAX_ENDPOINTS];  /*!< OUT endpoint parameters            */
	USB_LockTypeDef         Lock;        /*!< PCD peripheral status              */
	__IO USB_PCD_StateTypeDef   State;       /*!< PCD communication state        */
	__IO  uint32_t          ErrorCode;   /*!< PCD Error code                     */
	uint32_t                Setup[12];   /*!< Setup packet buffer                */
	USB_LPM_StateTypeDef    LPM_State;   /*!< LPM State                          */
	uint8_t                 PHY_Initialized; /*!< PHY initialized                */
	uint8_t                 ISR_Installed;   /*!< ISR installed                  */
	uint8_t					in_ep_sequece[USBD_MAX_ENDPOINTS];
	void                    *pData;      /*!< Pointer to upper stack Handler */
} USB_PCD_HandleTypeDef;

/* USB device speed */
typedef enum {
	USBD_SPEED_HIGH  = 0U,
	USBD_SPEED_FULL  = 1U,
	USBD_SPEED_LOW   = 2U,
} USBD_SpeedTypeDef;

struct _USBD_HandleTypeDef;

/* USB class structure */
typedef struct {
	uint8_t (*Init)(struct _USBD_HandleTypeDef *pdev, uint8_t cfgidx);
	uint8_t (*DeInit)(struct _USBD_HandleTypeDef *pdev, uint8_t cfgidx);
	/* Control Endpoints*/
	uint8_t (*Setup)(struct _USBD_HandleTypeDef *pdev, USBD_SetupReqTypedef  *req);
	uint8_t (*EP0_TxSent)(struct _USBD_HandleTypeDef *pdev);
	uint8_t (*EP0_RxReady)(struct _USBD_HandleTypeDef *pdev);
	/* Class Specific Endpoints*/
	uint8_t (*DataIn)(struct _USBD_HandleTypeDef *pdev, uint8_t epnum);
	uint8_t (*DataOut)(struct _USBD_HandleTypeDef *pdev, uint8_t epnum);
	uint8_t (*SOF)(struct _USBD_HandleTypeDef *pdev);

	uint8_t  *(*GetDeviceDescriptor)(USBD_SpeedTypeDef speed, uint16_t *length);
	uint8_t  *(*GetLangIDStrDescriptor)(USBD_SpeedTypeDef speed, uint16_t *length);
	uint8_t  *(*GetManufacturerStrDescriptor)(USBD_SpeedTypeDef speed, uint16_t *length);
	uint8_t  *(*GetProductStrDescriptor)(USBD_SpeedTypeDef speed, uint16_t *length);
	uint8_t  *(*GetSerialStrDescriptor)(USBD_SpeedTypeDef speed, uint16_t *length);
	uint8_t  *(*GetHSConfigDescriptor)(uint16_t *length);
	uint8_t  *(*GetFSConfigDescriptor)(uint16_t *length);
	uint8_t  *(*GetOtherSpeedConfigDescriptor)(uint16_t *length);
	uint8_t  *(*GetDeviceQualifierDescriptor)(uint16_t *length);
} USBD_ClassTypeDef;

/* USB device status */
typedef enum {
	USBD_OK   = 0U,
	USBD_BUSY,
	USBD_FAIL,
} USBD_StatusTypeDef;

/* USB device handle structure */
typedef struct {
	uint32_t                status;
	uint32_t                is_used;
	uint32_t                total_length;
	uint32_t                rem_length;
	uint32_t                maxpacket;
} USBD_EndpointTypeDef;

/* USB device handle structure */
typedef struct _USBD_HandleTypeDef {
	uint32_t                dev_config;
	uint32_t                dev_default_config;
	uint32_t                dev_config_status;
	USBD_SpeedTypeDef       dev_speed;
	USBD_EndpointTypeDef    ep_in[USBD_MAX_ENDPOINTS];
	USBD_EndpointTypeDef    ep_out[USBD_MAX_ENDPOINTS];
	uint32_t                ep0_state;
	uint32_t                ep0_data_len;
	uint8_t                 dev_state;
	uint8_t                 dev_old_state;
	uint8_t                 dev_address;
	uint8_t                 dev_connection_status;
	uint8_t                 dev_test_mode;
	uint32_t                dev_remote_wakeup;

	USBD_SetupReqTypedef    request;
	USBD_ClassTypeDef       *pClass;
	void                    *pClassData;
	void                    *pUserData;
	void                    *pData;
} USBD_HandleTypeDef;

/* Unaligned 32 bit type for DFIFO usage */
typedef struct {
	uint32_t data __PACKED;
} USB_Unaligned32TypeDef;

/* Exported macros -----------------------------------------------------------*/

#ifndef UNUSED
#define UNUSED(X)      (void)X
#endif

/* USB registers */
#define USB_GLOBAL     ((USB_OTG_GlobalTypeDef *)(USB_OTG_REG_BASE))
#define USB_PCGCCTL    *(__IO uint32_t *)(USB_OTG_REG_BASE + USB_OTG_PCGCCTL_BASE)
#define USB_DEVICE     ((USB_OTG_DeviceTypeDef *)(USB_OTG_REG_BASE + USB_OTG_DEVICE_BASE))
#define USB_INEP(i)    ((USB_OTG_INEndpointTypeDef *)(USB_OTG_REG_BASE + USB_OTG_IN_ENDPOINT_BASE + ((i) * USB_OTG_EP_REG_SIZE)))
#define USB_OUTEP(i)   ((USB_OTG_OUTEndpointTypeDef *)(USB_OTG_REG_BASE + USB_OTG_OUT_ENDPOINT_BASE + ((i) * USB_OTG_EP_REG_SIZE)))
#define USB_DFIFO(i)   *(__IO uint32_t *)(USB_OTG_REG_BASE + USB_OTG_FIFO_BASE + ((i) * USB_OTG_FIFO_SIZE))

/* Delay macros */
#define USB_DELAY_MS				DelayMs
#define USB_DELAY_US				DelayUs

/* Register access macros */
#define USB_READ32(addr)           (HAL_READ32(0, (addr)))
#define USB_WRITE32(addr, value)   (HAL_WRITE32(0, (addr), (value)))

/* Lock macros */
#define USB_HAL_LOCK(__HANDLE__)                                                   \
									do{ 									       \
										if((__HANDLE__)->Lock == USB_HAL_LOCKED)   \
										{									       \
										   return HAL_BUSY; 				       \
										}									       \
										else								       \
										{									       \
										   (__HANDLE__)->Lock = USB_HAL_LOCKED;    \
										}									       \
									  }while (0U)

#define USB_HAL_UNLOCK(__HANDLE__)                                                 \
									  do{									       \
										  (__HANDLE__)->Lock = USB_HAL_UNLOCKED;   \
										}while (0U)

/* Macro to get variable aligned on 32-bytes, for __ICCARM__ the directive "#pragma data_alignment=32" must be used instead */
/* In HS mode and when the DMA is used, all variables and data structures dealing
   with the DMA during the transaction process should be 32-bytes aligned */
#if defined ( __GNUC__ ) && !defined (__CC_ARM) /* GNU Compiler */
#ifndef __ALIGN_END
#define __ALIGN_END    __attribute__ ((aligned (32)))
#endif /* __ALIGN_END */
#ifndef __ALIGN_BEGIN
#define __ALIGN_BEGIN
#endif /* __ALIGN_BEGIN */
#else
#ifndef __ALIGN_END
#define __ALIGN_END
#endif /* __ALIGN_END */
#ifndef __ALIGN_BEGIN
#if defined   (__CC_ARM)      /* ARM Compiler */
#define __ALIGN_BEGIN    __align(32)
#elif defined (__ICCARM__)    /* IAR Compiler */
#define __ALIGN_BEGIN
#endif /* __CC_ARM */
#endif /* __ALIGN_BEGIN */
#endif /* __GNUC__ */

#ifndef SWAPBYTE
#define  SWAPBYTE(addr)        (((uint16_t)(*((uint8_t *)(addr)))) + \
								   (((uint16_t)(*(((uint8_t *)(addr)) + 1U))) << 8U))
#endif

#ifndef LOBYTE
#define LOBYTE(x)  ((uint8_t)(x & 0x00FFU))
#endif

#ifndef HIBYTE
#define HIBYTE(x)  ((uint8_t)((x & 0xFF00U) >> 8U))
#endif

#ifndef MIN
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif

/* Exported variables --------------------------------------------------------*/

extern USBD_HandleTypeDef USBD_Device;
extern USBD_ClassTypeDef USBD_CDC;

/* Exported functions --------------------------------------------------------*/

USB_StatusTypeDef USB_HalInit(USB_PCD_HandleTypeDef *hpcd);
USB_StatusTypeDef USB_DevInit(USB_PCD_HandleTypeDef *hpcd);
USB_StatusTypeDef USB_EnableGlobalInt(void);
USB_StatusTypeDef USB_DisableGlobalInt(void);
USB_StatusTypeDef USB_SetTurnaroundTime(USB_PCD_HandleTypeDef *hpcd);
USB_StatusTypeDef USB_SetDeviceMode(USB_PCD_HandleTypeDef *hpcd);
USB_StatusTypeDef USB_SetDevSpeed(USB_PCD_HandleTypeDef *hpcd, uint8_t speed);
USB_StatusTypeDef USB_FlushRxFifo(USB_PCD_HandleTypeDef *hpcd);
USB_StatusTypeDef USB_FlushTxFifo(USB_PCD_HandleTypeDef *hpcd, uint32_t num);
USB_StatusTypeDef USB_ActivateEndpoint(USB_PCD_HandleTypeDef *hpcd, USB_EPTypeDef *ep);
USB_StatusTypeDef USB_DeactivateEndpoint(USB_PCD_HandleTypeDef *hpcd, USB_EPTypeDef *ep);
USB_StatusTypeDef USB_EPStartXfer(USB_PCD_HandleTypeDef *hpcd, USB_EPTypeDef *ep);
USB_StatusTypeDef USB_EP0StartXfer(USB_PCD_HandleTypeDef *hpcd, USB_EPTypeDef *ep);
USB_StatusTypeDef USB_WritePacket(USB_PCD_HandleTypeDef *hpcd, uint8_t *src, uint8_t ch_ep_num, uint16_t len);
void             *USB_ReadPacket(USB_PCD_HandleTypeDef *hpcd, uint8_t *dest, uint16_t len);
USB_StatusTypeDef USB_EPSetStall(USB_PCD_HandleTypeDef *hpcd, USB_EPTypeDef *ep);
USB_StatusTypeDef USB_EPClearStall(USB_PCD_HandleTypeDef *hpcd, USB_EPTypeDef *ep);
USB_StatusTypeDef USB_SetDevAddress(USB_PCD_HandleTypeDef *hpcd, uint8_t address);
USB_StatusTypeDef USB_DevConnect(USB_PCD_HandleTypeDef *hpcd);
USB_StatusTypeDef USB_DevDisconnect(USB_PCD_HandleTypeDef *hpcd);
USB_StatusTypeDef USB_StopDevice(USB_PCD_HandleTypeDef *hpcd);
USB_StatusTypeDef USB_ActivateSetup(USB_PCD_HandleTypeDef *hpcd);
USB_StatusTypeDef USB_EP0_OutStart(USB_PCD_HandleTypeDef *hpcd);
USB_StatusTypeDef USB_ResetLearnQueue(USB_PCD_HandleTypeDef *hpcd);
USB_StatusTypeDef USB_EPPredictNextEp(USB_PCD_HandleTypeDef *hpcd, USB_EPTypeDef *ep);
uint8_t           USB_GetDevSpeed(USB_PCD_HandleTypeDef *hpcd);
uint32_t          USB_GetMode(USB_PCD_HandleTypeDef *hpcd);
uint32_t          USB_ReadInterrupts(void);
uint32_t          USB_ReadDevAllOutEpInterrupt(USB_PCD_HandleTypeDef *hpcd);
uint32_t          USB_ReadDevOutEPInterrupt(USB_PCD_HandleTypeDef *hpcd, uint8_t epnum);
uint32_t          USB_ReadDevAllInEpInterrupt(USB_PCD_HandleTypeDef *hpcd);
uint32_t          USB_ReadDevInEPInterrupt(USB_PCD_HandleTypeDef *hpcd, uint8_t epnum);
void              USB_ClearInterrupts(USB_PCD_HandleTypeDef *hpcd, uint32_t interrupt);

#endif /* USBD_HAL_ROM_H */

