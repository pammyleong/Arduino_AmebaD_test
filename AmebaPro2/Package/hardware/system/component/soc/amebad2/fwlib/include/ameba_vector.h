/**
  ******************************************************************************
  * @file    ameba_vector.h
  * @author
  * @version V1.0.0
  * @date    2016-05-17
  * @brief   This file contains all the functions prototypes for the IRQ firmware
  *          library.
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2016, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef _AMEBA_VECTOR_TABLE_H_
#define _AMEBA_VECTOR_TABLE_H_

/** @addtogroup AmebaD_Platform
  * @{
  */

/** @defgroup IRQ
  * @brief IRQ modules
  * @{
  */

/** @addtogroup IRQ
  * @verbatim
  *****************************************************************************************
  * Introduction
  *****************************************************************************************
  * IRQ table, please refer to IRQ Exported Constants->IRQn_enum->IRQn
  *
  *****************************************************************************************
  * how to use
  *****************************************************************************************
  *		1. register/unregister IRQ use: InterruptRegister/InterruptUnRegister
  *		2. enable/disable IRQ use: InterruptEn/InterruptDis
  *
  *****************************************************************************************
  * @endverbatim
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup IRQ_Exported_Types IRQ Exported Types
  * @{
  */
typedef s32 IRQn_Type;
typedef void (*HAL_VECTOR_FUN)(void);
typedef u32(*IRQ_FUN)(void *Data);
typedef void (*Fault_Patch)(uint32_t *MSP, uint32_t *PSP, uint32_t lr, uint32_t fault_id);
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup IRQ_Exported_Constants IRQ Exported Constants
  * @{
  */
/** @defgroup IRQn_enum
  * @{
  */
enum IRQn {
	/******  Processor Exceptions Numbers ********/
	NonMaskableInt_IRQn			= -14,	/*!< 2 Non Maskable Interrupt */
	HardFault_IRQn			= -13,	/*!< 3 Hard Fault, all classes of Fault */
	MemoryManagement_IRQn			= -12,	/*!< 4 Cortex-M3 Memory Management Interrupt */
	BusFault_IRQn			= -11,	/*!< 5 Cortex-M3 Bus Fault Interrupt */
	UsageFault_IRQn			= -10,	/*!< 6 Cortex-M3 Usage Fault Interrupt */
	SVCall_IRQn			= -5,	/*!< 11 Cortex-M3 SV Call Interrupt  */
	DebugMonitor_IRQn			= -4,	/*!< 12 Cortex-M3 Debug Monitor Interrupt */
	PendSV_IRQn			= -2,	/*!< 14 Cortex-M3 Pend SV Interrupt */
	SysTick_IRQn			= -1,	/*!< 15 Cortex-M3 System Tick Interrupt */

	/******  Specific Interrupt Numbers ************/
	AON_TIM_IRQ			= 79,
	TIMER0_IRQ			= 0,
	TIMER1_IRQ			= 1,
	TIMER2_IRQ			= 2,
	TIMER3_IRQ			= 3,
	TIMER4_IRQ			= 4,
	TIMER5_IRQ			= 5,
	TIMER6_IRQ			= 6,
	TIMER7_IRQ			= 7,
	UART_LOG_IRQ			= 8,
	GPIOA_IRQ			= 9,
	GPIOB_IRQ			= 10,
	GPIOC_IRQ			= 11,
	RTC_IRQ			= 12,
	CTOUCH_IRQ			= 13,
	ADC_IRQ			= 14,
	ADC_COMP_IRQ			= 15,
	BOR_IRQ			= 16,
	PWR_DOWN_IRQ			= 17,
	VADBT_OR_VADPC_IRQ			= 18,
	SPI_FLASH_IRQ			= 19,
	DEBUG_TIMER_IRQ			= 20,
	THERMAL_IRQ			= 21,
	I2C0_IRQ			= 22,
	RSIP_IRQ			= 23,
	IPC_NP_IRQ			= 24,
	GDMA0_CHANNEL0_IRQ			= 25,
	GDMA0_CHANNEL1_IRQ			= 26,
	GDMA0_CHANNEL2_IRQ			= 27,
	GDMA0_CHANNEL3_IRQ			= 28,
	GDMA0_CHANNEL4_IRQ			= 29,
	GDMA0_CHANNEL5_IRQ			= 30,
	GDMA0_CHANNEL6_IRQ			= 31,
	GDMA0_CHANNEL7_IRQ			= 32,
	LCDC_IRQ			= 33,
	WL_DMA_IRQ			= 34,
	WL_PROTOCOL_IRQ			= 35,
	AES_IRQ			= 36,
	SHA_IRQ			= 37,
	SDIO_HOST_IRQ			= 38,
	USB_OTG_IRQ			= 39,
	SPI0_IRQ			= 40,
	SPI1_IRQ			= 41,
	RSVD_IRQ			= 42,
	RSA_IRQ			= 43,
	ECDSA_IRQ			= 44,
	ED25519_IRQ			= 45,
	PSRAMC_IRQ			= 46,
	DDR_IRQ			= 47,
	RXI300_HP_IRQ			= 48,
	IR_IRQ			= 49,
	UART0_IRQ			= 50,
	UART1_IRQ			= 51,
	UART2_IRQ			= 52,
	UART3_BT_IRQ			= 53,
	TRNG_IRQ			= 54,
	I2C1_IRQ			= 55,
	I2C2_IRQ			= 56,
	TIMER8_IRQ			= 57,
	TIMER9_IRQ			= 58,
	WDG1_IRQ			= 59,
	WDG2_IRQ			= 60,
	WDG3_IRQ			= 61,
	WDG4_IRQ			= 62,
	SPORT0_IRQ			= 63,
	SPORT1_IRQ			= 64,
	SPORT2_IRQ			= 65,
	SPORT3_IRQ			= 66,
	BT_SCB_IRQ			= 67,
	LEDC_IRQ			= 68,
	MIPI_DSI_IRQ			= 69,
	AES_S_IRQ			= 70,
	SHA_S_IRQ			= 71,
	AON_WAKEPIN_IRQ			= 72,
	ZIGBEE_IRQ			= 73,
	BT_WAKE_HOST_IRQ			= 74,
	TIMER10_IRQ			= 75,
	TIMER11_IRQ			= 76,
	TIMER12_IRQ			= 77,
	TIMER13_IRQ			= 78,
};
/**
  * @}
  */


/** @defgroup LPIRQn_enum
  * @{
  */
enum LPIRQn {
	/******  Processor Exceptions Numbers ********/
	NonMaskableInt_IRQn_LP			= -14,	/*!< 2 Non Maskable Interrupt */
	HardFault_IRQn_LP			= -13,	/*!< 3 Hard Fault, all classes of Fault */
	MemoryManagement_IRQn_LP			= -12,	/*!< 4 Cortex-M3 Memory Management Interrupt */
	BusFault_IRQn_LP			= -11,	/*!< 5 Cortex-M3 Bus Fault Interrupt */
	UsageFault_IRQn_LP			= -10,	/*!< 6 Cortex-M3 Usage Fault Interrupt */
	SVCall_IRQn_LP			= -5,	/*!< 11 Cortex-M3 SV Call Interrupt  */
	DebugMonitor_IRQn_LP			= -4,	/*!< 12 Cortex-M3 Debug Monitor Interrupt */
	PendSV_IRQn_LP			= -2,	/*!< 14 Cortex-M3 Pend SV Interrupt */
	SysTick_IRQn_LP			= -1,	/*!< 15 Cortex-M3 System Tick Interrupt */

	/******  Specific Interrupt Numbers ************/
	IPC_IRQ_LP			= 0,
	RXI300_IRQ_LP			= 1,
	WIFI_FISR_FESR_IRQ_LP			= 2,
	WIFI_FTSR_MAILBOX_IRQ_LP			= 3,
	AON_TIM_IRQ_LP			= 4,
	NP_WAKE_IRQ_LP			= 5,
	AP_WAKE_IRQ_LP			= 6,
	WDG0_IRQ_LP			= 7,
	TIMER0_IRQ_LP			= 8,
	TIMER1_IRQ_LP			= 9,
	TIMER2_IRQ_LP			= 10,
	TIMER3_IRQ_LP			= 11,
	TIMER4_IRQ_LP			= 12,
	TIMER5_IRQ_LP			= 13,
	TIMER6_IRQ_LP			= 14,
	TIMER7_IRQ_LP			= 15,
	UART_LOG_IRQ_LP			= 16,
	GPIOA_IRQ_LP			= 17,
	GPIOB_IRQ_LP			= 18,
	GPIOC_IRQ_LP			= 19,
	RTC_IRQ_LP			= 20,
	CTOUCH_IRQ_LP			= 21,
	ADC_IRQ_LP			= 22,
	ADC_COMP_IRQ_LP			= 23,
	BOR_IRQ_LP			= 24,
	PWR_DOWN_IRQ_LP			= 25,
	VADBT_OR_VADPC_IRQ_LP			= 26,
	SPI_FLASH_IRQ_LP			= 27,
	DEBUG_TIMER_IRQ_LP			= 28,
	THERMAL_IRQ_LP			= 29,
	I2C0_IRQ_LP			= 30,
	RSIP_IRQ_LP			= 31,
	AON_WAKEPIN_IRQ_LP			= 32,
	BT_WAKE_HOST_IRQ_LP			= 33,
	NFIQOUT0_OR_NIRQOUT0_IRQ_LP			= 34,
	NFIQOUT1_OR_NIRQOUT1_IRQ_LP			= 35,
	WL_DMA_IRQ_LP			= 36,
	WL_PROTOCOL_IRQ_LP			= 37,
	TIMER10_IRQ_LP			= 38,
	TIMER11_IRQ_LP			= 39,
	TIMER12_IRQ_LP			= 40,
	TIMER13_IRQ_LP			= 41,

};
/**
  * @}
  */


/** @defgroup APIRQn_enum
  * @{
  */
enum APIRQn {
	/******  Processor Exceptions Numbers ********/
	NonMaskableInt_IRQn_AP			= -14,	/*!< 2 Non Maskable Interrupt */
	HardFault_IRQn_AP			= -13,	/*!< 3 Hard Fault, all classes of Fault */
	MemoryManagement_IRQn_AP			= -12,	/*!< 4 Cortex-M3 Memory Management Interrupt */
	BusFault_IRQn_AP			= -11,	/*!< 5 Cortex-M3 Bus Fault Interrupt */
	UsageFault_IRQn_AP			= -10,	/*!< 6 Cortex-M3 Usage Fault Interrupt */
	SVCall_IRQn_AP			= -5,	/*!< 11 Cortex-M3 SV Call Interrupt  */
	DebugMonitor_IRQn_AP			= -4,	/*!< 12 Cortex-M3 Debug Monitor Interrupt */
	PendSV_IRQn_AP			= -2,	/*!< 14 Cortex-M3 Pend SV Interrupt */
	SysTick_IRQn_AP			= -1,	/*!< 15 Cortex-M3 System Tick Interrupt */

	/******  Specific Interrupt Numbers ************/
	AON_TIM_IRQ_AP			= 95,
	TIMER0_IRQ_AP			= 0,
	TIMER1_IRQ_AP			= 1,
	TIMER2_IRQ_AP			= 2,
	TIMER3_IRQ_AP			= 3,
	TIMER4_IRQ_AP			= 4,
	TIMER5_IRQ_AP			= 5,
	TIMER6_IRQ_AP			= 6,
	TIMER7_IRQ_AP			= 7,
	UART_LOG_IRQ_AP			= 8,
	GPIOA_IRQ_AP			= 9,
	GPIOB_IRQ_AP			= 10,
	GPIOC_IRQ_AP			= 11,
	RTC_IRQ_AP			= 12,
	CTOUCH_IRQ_AP			= 13,
	ADC_IRQ_AP			= 14,
	ADC_COMP_IRQ_AP			= 15,
	BOR_IRQ_AP			= 16,
	PWR_DOWN_IRQ_AP			= 17,
	VADBT_OR_VADPC_IRQ_AP			= 18,
	SPI_FLASH_IRQ_AP			= 19,
	DEBUG_TIMER_IRQ_AP			= 20,
	THERMAL_IRQ_AP			= 21,
	I2C0_IRQ_AP			= 22,
	RSIP_IRQ_AP			= 23,
	IPC_AP_IRQ_AP			= 24,
	GDMA0_CHANNEL0_IRQ_AP			= 25,
	GDMA0_CHANNEL1_IRQ_AP			= 26,
	GDMA0_CHANNEL2_IRQ_AP			= 27,
	GDMA0_CHANNEL3_IRQ_AP			= 28,
	GDMA0_CHANNEL4_IRQ_AP			= 29,
	GDMA0_CHANNEL5_IRQ_AP			= 30,
	GDMA0_CHANNEL6_IRQ_AP			= 31,
	GDMA0_CHANNEL7_IRQ_AP			= 32,
	LCDC_IRQ_AP			= 33,
	WL_DMA_IRQ_AP			= 34,
	WL_PROTOCOL_IRQ_AP			= 35,
	AES_IRQ_AP			= 36,
	SHA_IRQ_AP			= 37,
	SDIO_HOST_IRQ_AP			= 38,
	USB_OTG_IRQ_AP			= 39,
	SPI0_IRQ_AP			= 40,
	SPI1_IRQ_AP			= 41,
	RSVD_IRQ_AP			= 42,
	RSA_IRQ_AP			= 43,
	ECDSA_IRQ_AP			= 44,
	ED25519_IRQ_AP			= 45,
	PSRAMC_IRQ_AP			= 46,
	DDR_IRQ_AP			= 47,
	RXI300_HP_IRQ_AP			= 48,
	IR_IRQ_AP			= 49,
	UART0_IRQ_AP			= 50,
	UART1_IRQ_AP			= 51,
	UART2_IRQ_AP			= 52,
	UART3_BT_IRQ_AP			= 53,
	TRNG_IRQ_AP			= 54,
	I2C1_IRQ_AP			= 55,
	I2C2_IRQ_AP			= 56,
	TIMER8_IRQ_AP			= 57,
	TIMER9_IRQ_AP			= 58,
	WDG1_IRQ_AP			= 59,
	WDG2_IRQ_AP			= 60,
	WDG3_IRQ_AP			= 61,
	WDG4_IRQ_AP			= 62,
	SPORT0_IRQ_AP			= 63,
	SPORT1_IRQ_AP			= 64,
	SPORT2_IRQ_AP			= 65,
	SPORT3_IRQ_AP			= 66,
	BT_SCB_IRQ_AP			= 67,
	LEDC_IRQ_AP			= 68,
	PMUIRQ0_IRQ_AP			= 69,
	MIPI_DSI_IRQ_AP			= 70,
	AXIERIRQ_IRQ_AP			= 71,
	AES_S_IRQ_AP			= 72,
	SHA_S_IRQ_AP			= 73,
	AON_WAKEPIN_IRQ_AP			= 74,
	ZIGBEE_IRQ_AP			= 75,
	BT_WAKE_HOST_IRQ_AP			= 76,
	CTIIRQ_IRQ_AP			= 77,
	TIMER10_IRQ_AP			= 78,
	TIMER11_IRQ_AP			= 79,
	TIMER12_IRQ_AP			= 80,
	TIMER13_IRQ_AP			= 81,
};
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup IRQ_Exported_Functions IRQ Exported Functions
  * @{
  */
extern _LONG_CALL_ void irq_table_init(u32 StackP);
extern _LONG_CALL_ BOOL irq_register(IRQ_FUN IrqFun, IRQn_Type IrqNum, u32 Data, u32 Priority);
extern _LONG_CALL_ BOOL irq_unregister(IRQn_Type IrqNum);
extern _LONG_CALL_ void irq_enable(IRQn_Type   IrqNum);
extern _LONG_CALL_ void irq_disable(IRQn_Type   IrqNum);
extern _LONG_CALL_ BOOL FaultPatch_register(Fault_Patch PatchFun);

#ifdef ARM_CORE_CA7
#define InterruptRegister_edge		irq_register_edge
#endif
#define InterruptRegister			irq_register
#define InterruptUnRegister		irq_unregister

#define InterruptEn(a,b)			irq_enable(a)
#define InterruptDis(a)			irq_disable(a)
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/* Other Definitions --------------------------------------------------------*/
extern IRQ_FUN UserIrqFunTable[];
extern u32 UserIrqDataTable[];
extern HAL_VECTOR_FUN  NewVectorTable[];

#if defined (ARM_CORE_CM4)
#define MAX_VECTOR_TABLE_NUM			(80+16)
#define MAX_PERIPHERAL_IRQ_NUM		80
#define MAX_IRQ_PRIORITY_VALUE			7
#else
#if defined(CONFIG_RLE1080_A_CUT)
#define MAX_VECTOR_TABLE_NUM			(16+36)
#define MAX_PERIPHERAL_IRQ_NUM		36
#else
#define MAX_VECTOR_TABLE_NUM			(16+44)
#define MAX_PERIPHERAL_IRQ_NUM		44
#endif
#define MAX_IRQ_PRIORITY_VALUE			3
#endif

#define MSP_RAM_LP			0x2301FFFC
#define MSPLIM_RAM_HP		0x30001000
#define MSP_RAM_HP			0x30002FFC
#define MSP_RAM_HP_NS		0x2001BFFC

#define BIT_EXCRETURN_S			BIT(6)	/* Indicates whether a Secure or Non-secure stack is used to restore stack frame on exception return. 0: Non-secure, 1: Secure*/
#define BIT_EXCRETURN_MODE		BIT(3)	/* Indicates the Mode that was stacked from. 0: Handler mode, 1: Thread mode */
#define BIT_EXCRETURN_SPSEL		BIT(2)	/* Stack pointer selection. The value of this bit indicates the transitory value of the CONTROL.SPSEL bit 
											associated with the Security state of the exception as indicated by EXC_RETURN.ES. 0: MSP, 1: PSP*/
#define BIT_EXCRETURN_ES		BIT(0)	/* The security domain the exception was taken to. 0: Non-secure, 1: Secure */

#define BIT_CONTROL_SPSEL		BIT(1)	/* Stack-pointer select. Defines the stack pointer to be used. 0: use MSP, 1: in thread mode, use PSP */

#endif //_AMEBA_VECTOR_TABLE_H_
/******************* (C) COPYRIGHT 2016 Realtek Semiconductor *****END OF FILE****/
