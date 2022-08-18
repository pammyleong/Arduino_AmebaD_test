/**
  ******************************************************************************
  * @file    ameba_clk.h
  * @author
  * @version V1.0.0
  * @date    2016-05-17
  * @brief   This file provides firmware functions to manage the following
  *          functionalities of clock control:
  *           - NCO32K clock
  *           - NCO8M clock
  *           - CPU clock
  *           - XTAL clock get
  *           - OSC32K clock
  *           - EXT32K clock
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2015, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef _AMEBA_CLK_H_
#define _AMEBA_CLK_H_

/** @addtogroup AmebaD_Platform
  * @{
  */

/** @defgroup CLOCK
  * @brief CLOCK driver modules
  * @{
  */

/** @addtogroup CLOCK
  * @verbatim
  *****************************************************************************************
  * NCO32K
  *****************************************************************************************
  *	-RTC clock in
  *	-TIM0-TIM3 clock in
  *	-WIFI 32K clock in
  *****************************************************************************************
  * OSC32K OSC8M
  *****************************************************************************************
  *	-OSC32K is used to calibration OSC8M
  *	-OSC8M is used for LP UART when SOC suspend and close XTAL
  *****************************************************************************************
  *****************************************************************************************
  * NCO8M
  *****************************************************************************************
  *	-used for LP UART when SOC active
  *	-Clock in is XTAL (40MHz)
  *	-Clock out is 8MHz
  *
  *****************************************************************************************
  * HS CPU clock
  *****************************************************************************************
  *	-CLK_KM4_200M: 200MHz
  *	-CLK_KM4_100M: 100MHz
  *	-CLK_KM4_50M: 50MHz
  *	-CLK_KM4_25M: 25MHz
  *	-CLK_KM4_XTAL: XTAL
  *
  *****************************************************************************************
  * XTAL clock
  *****************************************************************************************
  *	-Get XTAL clock from EFUSE setting:
  *	-40000000
  *	-25000000
  *	-13000000
  *	-19200000
  *	-20000000
  *	-26000000
  *	-38400000
  *	-17664000
  *	-16000000
  *	-14318000
  *	-12000000
  *	-52000000
  *	-48000000
  *	-26000000
  *	-27000000
  *	-24000000

  *****************************************************************************************
  * EXT32K
  *****************************************************************************************
  *	-External 32K: 32K clock from external 32k source
  *	-Internal 32K: 32K clock from internal 32K source: NCO32K
  *
  *****************************************************************************************
  * @endverbatim
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup CLK_Exported_Constants CLK Exported Constants
  * @{
  */

/** @defgroup LP_CPU_CLK_definitions
  * @{
  */
#define CLK_KM0_XTAL		2 /* if XTAL is 26MHz, we can use it */
#define CLK_KM0_XTALDIV2	3 /* if XTAL is 40MHz, we should use it */
#define CLK_KM0_ANA_4M		0 /* if XTAL OFF, default config */
/**
  * @}
  */

/** @defgroup HS_CPU_CLK_definitions
  * @{
  */
#define CLK_KM4_75M			7
#define CLK_KM4_85P7M		6
#define CLK_KM4_100M		5
#define CLK_KM4_120M		4
#define CLK_KM4_150M		3
#define CLK_KM4_200M		2
#define CLK_KM4_300M		1
#define CLK_KM4_XTAL		0
/**
  * @}
  */

/** @defgroup AP_CPU_CLK_definitions
  * @{
  */
#define CLK_CA7_APPLLDIV2_150M		11
#define CLK_CA7_APPLLDIV2_200M		10
#define CLK_CA7_APPLLDIV2_300M		9
#define CLK_CA7_APPLLDIV2_600M		8
#define CLK_CA7_NPPLL_150M			7
#define CLK_CA7_NPPLL_200M			6
#define CLK_CA7_NPPLL_300M			5
#define CLK_CA7_NPPLL_600M			4
#define CLK_CA7_APPLL_300M			3
#define CLK_CA7_APPLL_400M			2
#define CLK_CA7_APPLL_600M			1
#define CLK_CA7_APPLL_1P2G			0
/**
  * @}
  */

/** @defgroup PLL_SEL_definitions
  * @{
  */
#define PLL_I2S		0
#define PLL_PCM		1

/** @defgroup PLL_ClkTune_definitions
  * @{
  */
#define PLL_AUTO		0
#define PLL_FASTER		1
#define PLL_SLOWER		2

/**
  * @}
  */

/** @defgroup PLL_BandGap_Mask_definitions
  * @{
  */
#define PLL_BG_POW_MASK	((u32)0x00000007)
/**
  * @}
  */

/** @defgroup AP_PLL_SDM_DIVN_definitions
  * @{
  */
#define IS_AP_PLL_SDM_DIVN(Option)		(((Option) <= 0x21) && ((Option) >= 0x12))
/**
  * @}
  */

/** @defgroup HAPB_CLK_definitions
  * @{
  */
#define CKSL_HAPB_LP_BUS  0
#define CKSL_HAPB_PLL        1
/**
  * @}
  */

/** @defgroup HPLFM_CLK_definitions
  * @{
  */
#define CKSL_PLFM_LBUS_CLK        0
#define CKSL_PLFM_NP_CLK   1
/**
  * @}
  */

/** @defgroup CAL_CLK_SEL_definitions
  * @{
  */
#define OSC4M_CAL_CLK		0
#define AON100K_CAL_CLK		1
#define AON128K_CAL_CLK		2
/**
  * @}
  */


/** @defgroup XTAL_MODE_SEL_definitions
  * @{
  */
#define XTAL_NM_MODE		2
#define XTAL_LPS_MODE		1
#define XTAL_HP_MODE		3
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup SDM32K_CLK_Exported_Functions SDM32K_CLK Exported Functions
  * @{
  */
_LONG_CALL_ void SDM32K_Enable(void);
_LONG_CALL_ void SDM32K_TimerCalEnable(u32 RTCCalibration);
/**
  * @}
  */


/** @defgroup CPU_CLK_Exported_Functions CPU_CLK Exported Functions
  * @{
  */
_LONG_CALL_ u32 CPU_ClkGet(void);
_LONG_CALL_ void CPU_ClkSet(u8  CpuType);
/**
  * @}
  */

/** @defgroup XTAL_CLK_Exported_Functions XTAL_CLK Exported Functions
  * @{
  */
_LONG_CALL_ u32 XTAL_ClkGet(void);
/**
  * @}
  */

/** @defgroup PLL_Exported_Functions PLL Exported Functions
  * @{
  */
_LONG_CALL_ void PLL_I2S_Div(int Sportx, u32 div);
_LONG_CALL_ void PLL_I2S_98P304M(u32 NewState);
_LONG_CALL_ void PLL_I2S_45P158M(u32 NewState);
_LONG_CALL_ void PLL_I2S_98P304M_ClkTune(u32 ppm, u32 action);
_LONG_CALL_ void PLL_I2S_45P158M_ClkTune(u32 ppm, u32 action);
_LONG_CALL_ void PLL_NP(u32 NewState);
_LONG_CALL_ void PLL_AP(u32 Option, u32 NewState);
_LONG_CALL_ void PLL_AP_ClkTune(u32 Option);
/**
  * @}
  */


/** @defgroup HAPB_CLK_Exported_Functions
  * @{
  */
_LONG_CALL_ void HAPB_ClkSet(u32 Source);
/**
  * @}
  */


/** @defgroup HPLFM_CLK_Exported_Functions
  * @{
  */
_LONG_CALL_ void HPLFM_ClkSet(u32 Source);
/**
  * @}
  */



/* Registers Definitions --------------------------------------------------------*/
/**************************************************************************//**
 * @defgroup CLK_Register_Definitions CLK Register Definitions
 * @{
 *****************************************************************************/

/**************************************************************************//**
 * @defgroup REG_SYS_SYSPLL_CTRL2
 * @{
 *****************************************************************************/
#define BIT_SYS_SYSPLL_CK_ADC_EN		(0x00000001 << 25) /*!< Set ADC PLL EN */
/** @} */

/** @} */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/* Other definations --------------------------------------------------------*/
u32 OSC4M_Calibration(u32 ppm_limit);
u32 OSC131K_Calibration(u32 ppm_limit);
void OSC4M_Init(void);
void XTAL_AACK(void);
void XTAL_PDCK(void);

#define CA7_GET_CLKSEL(x)		((x >> 2) & 0x3)
#define CA7_GET_CLKDIV(x)		(x & 0x3)

#endif //_AMEBA_CLK_H_
/******************* (C) COPYRIGHT 2016 Realtek Semiconductor *****END OF FILE****/
