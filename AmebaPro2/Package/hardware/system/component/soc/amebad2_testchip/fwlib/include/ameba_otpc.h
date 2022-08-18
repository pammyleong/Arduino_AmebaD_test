/**
  ******************************************************************************
  * @file    ameba_otpc.h
  * @author
  * @version V1.0.0
  * @date    2016-05-17
  * @brief   This file contains all the functions prototypes for the OTPC firmware
  *          library.
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2015, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef _AMEBAD2_OTPC_H_
#define _AMEBAD2_OTPC_H_

/** @addtogroup OTPC
  * @verbatim
  *****************************************************************************************
  * logical map space total size 2048byte ,only 1024 byte used now
  *****************************************************************************************
  *
  * 0x00~0x07	8bytes system autoload for software
  * 0x08~0x01F	24bytes  autoload for hardware
  * 0x20~0xCF	WIFI calibration data
  * 0xD0~0x11F	WIFI HCI CIS
  * 0x130~0x13F	WIFI SW/RF  Reserved
  * 0x140~0x1AF	112bytes  autoload for hardware
  * 0x1B0~0x1FF	80bytes BT calibration data
  * 0x1B0~0x1FF	80bytes BT calibration data
  * 0x200~0x20F	ADC calibration data
  * 0x210~0x21F	USB HCI
  * 0x220~0x22F	captouch calibration data
  * 0x230~0x2FF	RSVD for user use
  * 0x300~0x3FF	Realtek RSVD
  * 0x400~0x7FF	No define, SW API can't access.
  *
  *****************************************************************************************
  * physical map (1280B)
  *****************************************************************************************
  *
  * 0x000~0x1FE	For logical efuse, user can read
  * 0x200~0x3FF	Security related function
  * 0x400~0x500 	User define physical area
  *
  *****************************************************************************************
  * USER Section
  *****************************************************************************************
  * can be changed after write
  *
  *0x230~0x2FF	RSVD for user use
  *
  *****************************************************************************************
  * OTP Section (32B)
  *****************************************************************************************
  *
  * can not be changed after write
  *
  *0x400~0x500 	User define physical area
  *
  *****************************************************************************************
  * @endverbatim
  */

/* AUTO_GEN_START */

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup OTPC
* @{
*/

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup OTPC_Register_Definitions OTPC Register Definitions
 * @{
 *****************************************************************************/

/** @defgroup OTPC_OTP_ALD
 * @brief
 * @{
 **/
#define OTPC_MASK_EF_ID1                          ((u32)0x000000FF << 24)          /*!<R 8'h87   */
#define OTPC_EF_ID1(x)                            ((u32)(((x) & 0x000000FF) << 24))
#define OTPC_GET_EF_ID1(x)                        ((u32)(((x >> 24) & 0x000000FF)))
#define OTPC_MASK_EF_ID0                          ((u32)0x000000FF << 16)          /*!<R 8'h30   */
#define OTPC_EF_ID0(x)                            ((u32)(((x) & 0x000000FF) << 16))
#define OTPC_GET_EF_ID0(x)                        ((u32)(((x >> 16) & 0x000000FF)))
#define OTPC_BIT_LOAD_FAIL                        ((u32)0x00000001 << 2)          /*!<R 0  Autoload fail flag */
#define OTPC_BIT_LOAD_DONE                        ((u32)0x00000001 << 1)          /*!<R 0  Autoload done flag */
#define OTPC_BIT_SRST                             ((u32)0x00000001 << 0)          /*!<R/W 0  Soft reset data path except register */
/** @} */

/** @defgroup OTPC_OTP_SCAN
 * @brief
 * @{
 **/
#define OTPC_MASK_EF_SCAN_SADDR                   ((u32)0x000007FF << 19)          /*!<R/W 0  EFuse Scan start Address (unit in byte) */
#define OTPC_EF_SCAN_SADDR(x)                     ((u32)(((x) & 0x000007FF) << 19))
#define OTPC_GET_EF_SCAN_SADDR(x)                 ((u32)(((x >> 19) & 0x000007FF)))
#define OTPC_MASK_EF_SCAN_EADDR                   ((u32)0x000007FF << 8)          /*!<R/W 0  EFuse Scan End address */
#define OTPC_EF_SCAN_EADDR(x)                     ((u32)(((x) & 0x000007FF) << 8))
#define OTPC_GET_EF_SCAN_EADDR(x)                 ((u32)(((x >> 8) & 0x000007FF)))
#define OTPC_BIT_EF_SCAN_FAIL                     ((u32)0x00000001 << 7)          /*!<R 0  Test Scan Report 1: Fail 0: Ok */
#define OTPC_MASK_EF_SCAN_THD                     ((u32)0x0000007F << 0)          /*!<R/WPD/ES 0  Write this field will trig a scan operation */
#define OTPC_EF_SCAN_THD(x)                       ((u32)(((x) & 0x0000007F) << 0))
#define OTPC_GET_EF_SCAN_THD(x)                   ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup OTPC_OTP_AS
 * @brief
 * @{
 **/
#define OTPC_BIT_EF_RD_WR_NS                      ((u32)0x00000001 << 31)          /*!<R/WPD/ET 0  Write this bit will trig an indirect read or write. Write 1: trigger write write 0: trigger read After this operation done, this bit will toggle. */
#define OTPC_MASK_EF_MODE_SEL_NS                  ((u32)0x00000003 << 19)          /*!<R/W 0  OTP Mode Selection 00: User Mode 01: Initial Margin Read Mode 10: Program Margin Read Mode */
#define OTPC_EF_MODE_SEL_NS(x)                    ((u32)(((x) & 0x00000003) << 19))
#define OTPC_GET_EF_MODE_SEL_NS(x)                ((u32)(((x >> 19) & 0x00000003)))
#define OTPC_MASK_EF_ADDR_NS                      ((u32)0x000007FF << 8)          /*!<R/W 0  OTP indirect read or write address */
#define OTPC_EF_ADDR_NS(x)                        ((u32)(((x) & 0x000007FF) << 8))
#define OTPC_GET_EF_ADDR_NS(x)                    ((u32)(((x >> 8) & 0x000007FF)))
#define OTPC_MASK_EF_DATA_NS                      ((u32)0x000000FF << 0)          /*!<R/W/ES 0  OTP indirect read or write data */
#define OTPC_EF_DATA_NS(x)                        ((u32)(((x) & 0x000000FF) << 0))
#define OTPC_GET_EF_DATA_NS(x)                    ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup OTPC_OTP_AS_SEC
 * @brief
 * @{
 **/
#define OTPC_BIT_EF_RD_WR_S                       ((u32)0x00000001 << 31)          /*!<R/WPD/ET 0  Write this bit will trig an indirect read or write. Write 1: trigger write write 0: trigger read After this operation done, this bit will toggle. */
#define OTPC_MASK_EF_MODE_SEL_S                   ((u32)0x00000003 << 19)          /*!<R/W 0  OTP Mode Selection 00: User Mode 01: Initial Margin Read Mode 10: Program Margin Read Mode */
#define OTPC_EF_MODE_SEL_S(x)                     ((u32)(((x) & 0x00000003) << 19))
#define OTPC_GET_EF_MODE_SEL_S(x)                 ((u32)(((x >> 19) & 0x00000003)))
#define OTPC_MASK_EF_ADDR_S                       ((u32)0x000007FF << 8)          /*!<R/W 0  OTP indirect read or write address */
#define OTPC_EF_ADDR_S(x)                         ((u32)(((x) & 0x000007FF) << 8))
#define OTPC_GET_EF_ADDR_S(x)                     ((u32)(((x >> 8) & 0x000007FF)))
#define OTPC_MASK_EF_DATA_S                       ((u32)0x000000FF << 0)          /*!<R/W/ES 0  OTP indirect read or write data */
#define OTPC_EF_DATA_S(x)                         ((u32)(((x) & 0x000000FF) << 0))
#define OTPC_GET_EF_DATA_S(x)                     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup OTPC_OTP_TEST_MODE
 * @brief
 * @{
 **/
#define OTPC_MASK_EF_MODE                         ((u32)0x00000007 << 0)          /*!<R/WPD 0  OTP Test Mode Selection 000: User Read Mode 001: Initial Margin Read Mode 010: Program Margin Read Mode 011: User Write Mode 101: Repair Margin Read Mode 110: Repair Check Mode 111: Repair Program Mode Bit[2]=0: User mode and Test mode Bit[2]=1: Use Repair mode */
#define OTPC_EF_MODE(x)                           ((u32)(((x) & 0x00000007) << 0))
#define OTPC_GET_EF_MODE(x)                       ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup OTPC_OTP_CTRL
 * @brief
 * @{
 **/
#define OTPC_MASK_EF_PG_PWD                       ((u32)0x000000FF << 24)          /*!<R/W 8'b0  OTP program password. OTP can be programed only when this value is 8'h69. */
#define OTPC_EF_PG_PWD(x)                         ((u32)(((x) & 0x000000FF) << 24))
#define OTPC_GET_EF_PG_PWD(x)                     ((u32)(((x >> 24) & 0x000000FF)))
#define OTPC_BIT_EF_AUTO_DSLP                     ((u32)0x00000001 << 0)          /*!<R/W 1'b1  1: OTP auto return back to dslp if no operation */
/** @} */

/** @defgroup OTPC_OTP_TEST
 * @brief
 * @{
 **/
#define OTPC_MASK_EF_RP_CHK                       ((u32)0x00000003 << 3)          /*!<R 0  Check result 2'b00: Good sample 2'b01: Repairable sample 2'b11: Failure sample */
#define OTPC_EF_RP_CHK(x)                         ((u32)(((x) & 0x00000003) << 3))
#define OTPC_GET_EF_RP_CHK(x)                     ((u32)(((x >> 3) & 0x00000003)))
#define OTPC_BIT_EF_RDY                           ((u32)0x00000001 << 2)          /*!<R 1'b1  One OTP operation ready, include 1: Mode set 2: SW read/write Note: If continue read or write, it may need wait this ready, if change read -> write, or write -> read, must wait this rdy bit. And OTP is in a stable state. */
#define OTPC_BIT_EF_TROW_EN                       ((u32)0x00000001 << 1)          /*!<R/W 0  Test row enable */
#define OTPC_BIT_EF_PGRD_IMR                      ((u32)0x00000001 << 0)          /*!<R/W 0  0: Unmask Program Margin Read Mode and Initial Margin Read Mode of OTP_AS_SEC/OTP_AS register 1: Mask Program Margin Read Mode and Initial Margin Read Mode of OTP_AS_SEC/OTP_AS register */
/** @} */

/** @defgroup OTPC_OTP_TIME
 * @brief
 * @{
 **/
#define OTPC_MASK_EF_PPSR                         ((u32)0x00000007 << 9)          /*!<R/W 3'b010  OTP Program Setup time and Recovery time. In the unit of cycle time (5us< Tpps=Tppr <100us) For input clock 20 MHz/26 MHz 0: 4us 1: 15us 2: 30us (default) 3: 45us 4: 60us 5: 75us 6: 90us 7: 101us */
#define OTPC_EF_PPSR(x)                           ((u32)(((x) & 0x00000007) << 9))
#define OTPC_GET_EF_PPSR(x)                       ((u32)(((x >> 9) & 0x00000007)))
#define OTPC_MASK_EF_TPWI                         ((u32)0x00000007 << 6)          /*!<R/W 3'b010  Program Pulse Interval Time (1us<ef_tpwi<5us) For input clock 20 MHz/26 MHz 0: 0.5us 1: 1.5us 2: 2us (default) 3: 2.5us 4: 3us 5: 3.5us 6: 4us 7: 5.5us */
#define OTPC_EF_TPWI(x)                           ((u32)(((x) & 0x00000007) << 6))
#define OTPC_GET_EF_TPWI(x)                       ((u32)(((x >> 6) & 0x00000007)))
#define OTPC_MASK_EF_TPW                          ((u32)0x00000007 << 3)          /*!<R/W 3'b010  Program pulse width time.OTP Program Pulse width Time (10us<ef_tpw<15us) For input clock 20 MHz/26 MHz 0: 9.5us 1: 13us 2: 13.5us (default) 3: 14us 4: 14.5us 5: 15.5us */
#define OTPC_EF_TPW(x)                            ((u32)(((x) & 0x00000007) << 3))
#define OTPC_GET_EF_TPW(x)                        ((u32)(((x >> 3) & 0x00000007)))
#define OTPC_MASK_EF_CSP                          ((u32)0x00000007 << 0)          /*!<R/W 3'b010  IP enable time in program (10us<ef_csp<100us) For input clock 20 MHz/26 MHz 0: 5us 1: 15us 2: 30us (default) 3: 45us 4: 60us 5: 75us 6: 90us 7: 101us */
#define OTPC_EF_CSP(x)                            ((u32)(((x) & 0x00000007) << 0))
#define OTPC_GET_EF_CSP(x)                        ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup OTPC_OTP_ALD_EN
 * @brief
 * @{
 **/
#define OTPC_BIT_LOAD_EN                          ((u32)0x00000001 << 16)          /*!<R/WA0 0  Soft load enable, write one auto clear */
#define OTPC_MASK_LOAD_LZON                       ((u32)0x000000FF << 8)          /*!<R/W 0  Logic load zone select (currently only supports software to trigger autoload in rom area) 0bit: 11'h0 - 11'h7 system data 1bit: 11'h8 - 11'h1F AON hareware data 2bit: 11'h140 - 11'h1AF LS hareware data 3bit: 11'h300 - 11'h32F AON pmc patch 4bit: 11'h340 - 11'h36F LS pmc patch 5bit: 11'h380 - 11'h3FF AON register patch 6bit: 11'h400 - 11'h47F LS register patch 7bit: It's invalid to write 1 or 0. */
#define OTPC_LOAD_LZON(x)                         ((u32)(((x) & 0x000000FF) << 8))
#define OTPC_GET_LOAD_LZON(x)                     ((u32)(((x >> 8) & 0x000000FF)))
#define OTPC_MASK_LOAD_PZON                       ((u32)0x000000FF << 0)          /*!<R/W 0  Check result 2'b00: Good sample 2'b01: Repairable sample 2'b11: Failure sample */
#define OTPC_LOAD_PZON(x)                         ((u32)(((x) & 0x000000FF) << 0))
#define OTPC_GET_LOAD_PZON(x)                     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup OTPC_OTP_DEBUG
 * @brief
 * @{
 **/
#define OTPC_BIT_EF_DEBUG_EN                      ((u32)0x00000001 << 16)          /*!<R/W 0  Debug enable */
#define OTPC_MASK_EF_DEBUG_STATE                  ((u32)0x0000FFFF << 0)          /*!<R 0  State machine operating state [8:5]: autoload state. [4:3]: rd/wr ctrl state. [2:0]: wav state.Working status of different modes. */
#define OTPC_EF_DEBUG_STATE(x)                    ((u32)(((x) & 0x0000FFFF) << 0))
#define OTPC_GET_EF_DEBUG_STATE(x)                ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */
/** @} */



/* Exported types --------------------------------------------------------*/

/** @defgroup OTPC_Exported_Types OTPC Exported Types
  * @{
*****************************************************************************/


/**
 * @brief OTPC Register Declaration
 *****************************************************************************/
typedef struct {
	__IO uint32_t OTPC_OTP_ALD;                           /*!<  Register,  Address offset: 0x000 */
	__IO uint32_t OTPC_OTP_SCAN;                          /*!<  Register,  Address offset: 0x004 */
	__IO uint32_t OTPC_OTP_AS;                            /*!<  Register,  Address offset: 0x008 */
	__IO uint32_t OTPC_OTP_AS_SEC;                        /*!<  Register,  Address offset: 0x00C */
	__IO uint32_t OTPC_OTP_TEST_MODE;                     /*!<  Register,  Address offset: 0x0010 */
	__IO uint32_t OTPC_OTP_CTRL;                          /*!<  Register,  Address offset: 0x014 */
	__IO uint32_t OTPC_OTP_TEST;                          /*!<  Register,  Address offset: 0x018 */
	__IO uint32_t OTPC_OTP_TIME;                          /*!<  Register,  Address offset: 0x01C */
	__IO uint32_t OTPC_OTP_ALD_EN;                        /*!<  Register,  Address offset: 0x020 */
	__IO uint32_t OTPC_OTP_DEBUG;                         /*!<  Register,  Address offset: 0x024 */
} OTPC_TypeDef;
/** @} */
/* AUTO_GEN_END */

/* MANUAL_GEN_START */

/* Exported Constants --------------------------------------------------------*/
/** @defgroup OTPC_Exported_Constants OTPC Exported Constants
  * @{
  */

/**
 * @defgroup OTPC_SEC_CFG1
 * @{
 **/
#define OTPC_BIT_SWD_PWD_EN                       ((u32)0x00000001 << 0)          /*!<PROT 1'b1   */
#define OTPC_BIT_SWD_DBGEN                        ((u32)0x00000001 << 1)          /*!<PROT 1'b1   */
#define OTPC_BIT_SWD_NIDEN                        ((u32)0x00000001 << 2)          /*!<PROT 1'b1   */
#define OTPC_BIT_SWD_SPIDEN                       ((u32)0x00000001 << 3)          /*!<PROT 1'b1   */
#define OTPC_BIT_SWD_SPNIDEN                      ((u32)0x00000001 << 4)          /*!<PROT 1'b1   */
#define OTPC_BIT_SWD_PWD_R_PROTECTION_EN          ((u32)0x00000001 << 5)          /*!<PROT 1'b1   */
#define OTPC_BIT_SWD_PWD_W_FORBIDDEN_EN           ((u32)0x00000001 << 6)          /*!<PROT 1'b1   */
#define OTPC_BIT_HUK_W_FORBIDDEN_EN               ((u32)0x00000001 << 7)          /*!<PROT 1'b1   */
#define OTPC_BIT_PK1_W_FORBIDDEN_EN               ((u32)0x00000001 << 8)          /*!<PROT 1'b1   */
#define OTPC_BIT_PK2_W_FORBIDDEN_EN               ((u32)0x00000001 << 9)          /*!<PROT 1'b1   */
#define OTPC_BIT_S_IPSEC_KEY1_R_PROTECTION_EN     ((u32)0x00000001 << 10)          /*!<PROT 1'b1   */
#define OTPC_BIT_S_IPSEC_KEY1_W_FORBIDDEN_EN      ((u32)0x00000001 << 11)          /*!<PROT 1'b1   */
#define OTPC_BIT_S_IPSEC_KEY2_R_PROTECTION_EN     ((u32)0x00000001 << 12)          /*!<PROT 1'b1   */
#define OTPC_BIT_S_IPSEC_KEY2_W_FORBIDDEN_EN      ((u32)0x00000001 << 13)          /*!<PROT 1'b1   */
#define OTPC_BIT_NS_IPSEC_KEY1_R_PROTECTION_EN    ((u32)0x00000001 << 14)          /*!<PROT 1'b1   */
#define OTPC_BIT_NS_IPSEC_KEY1_W_FORBIDDEN_EN     ((u32)0x00000001 << 15)          /*!<PROT 1'b1   */
#define OTPC_BIT_NS_IPSEC_KEY2_R_PROTECTION_EN    ((u32)0x00000001 << 16)          /*!<PROT 1'b1   */
#define OTPC_BIT_NS_IPSEC_KEY2_W_FORBIDDEN_EN     ((u32)0x00000001 << 17)          /*!<PROT 1'b1   */
#define OTPC_BIT_ECDSA_PRI_KEY1_R_PROTECTION_EN   ((u32)0x00000001 << 18)          /*!<PROT 1'b1   */
#define OTPC_BIT_ECDSA_PRI_KEY1_W_FORBIDDEN_EN    ((u32)0x00000001 << 19)          /*!<PROT 1'b1   */
#define OTPC_BIT_ECDSA_PRI_KEY2_R_PROTECTION_EN   ((u32)0x00000001 << 20)          /*!<PROT 1'b1   */
#define OTPC_BIT_ECDSA_PRI_KEY2_W_FORBIDDEN_EN    ((u32)0x00000001 << 21)          /*!<PROT 1'b1   */
#define OTPC_BIT_RSIP_KEY1_R_PROTECTION_EN        ((u32)0x00000001 << 22)          /*!<PROT 1'b1   */
#define OTPC_BIT_RSIP_KEY1_W_FORBIDDEN_EN         ((u32)0x00000001 << 23)          /*!<PROT 1'b1   */
#define OTPC_BIT_RSIP_KEY2_R_PROTECTION_EN        ((u32)0x00000001 << 24)          /*!<PROT 1'b1   */
#define OTPC_BIT_RSIP_KEY2_W_FORBIDDEN_EN         ((u32)0x00000001 << 25)          /*!<PROT 1'b1   */
#define OTPC_BIT_RSIP_MODE_W_FORBIDDEN_EN         ((u32)0x00000001 << 26)          /*!<PROT 1'b1   */
#define OTPC_BIT_SIC_SECURE_EN                    ((u32)0x00000001 << 27)          /*!<PROT 1'b1   */
#define OTPC_BIT_CPU_PC_DBG_EN                    ((u32)0x00000001 << 28)          /*!<PROT 1'b1   */
#define OTPC_BIT_UDF1_TRUSTZONE_EN                ((u32)0x00000001 << 29)          /*!<PROT 1'b1   */
#define OTPC_BIT_UDF2_TRUSTZONE_EN                ((u32)0x00000001 << 30)          /*!<PROT 1'b1   */
#define OTPC_BIT_CFG_RSVD0                        ((u32)0x00000001 << 31)          /*!<PROT 1'b1   */
/** @} */

/**
 * @defgroup OTPC_SEC_CFG2
 * @brief
 * @{
 **/
#define OTPC_BIT_UART_DOWNLOAD_DISABLE            ((u32)0x00000001 << 0)          /*!<PROT/R 1'b1   */
#define OTPC_BIT_RSIP_EN                          ((u32)0x00000001 << 2)          /*!<PROT/R 1'b1   */
#define OTPC_BIT_SECURE_BOOT_EN                   ((u32)0x00000001 << 3)          /*!<PROT/R 1'b1   */
#define OTPC_BIT_SECURE_BOOT_HW_DIS               ((u32)0x00000001 << 4)          /*!<PROT/R 1'b1   */
#define OTPC_BIT_RDP_EN                           ((u32)0x00000001 << 5)          /*!<PROT/R 1'b1   */
#define OTPC_BIT_BOOT_ROM_EXECUTE_ONLY_EN         ((u32)0x00000001 << 6)          /*!<PROT/R 1'b1   */
#define OTPC_BIT_FAULT_LOG_PRINT_DIS              ((u32)0x00000001 << 7)          /*!<PROT/R 1'b1   */
#define OTPC_MASK_RSIP_MODE                       ((u32)0x00000003 << 8)          /*!<PROT/R 2'b11   */
#define OTPC_RSIP_MODE(x)                         ((u32)(((x) & 0x00000003) << 8))
#define OTPC_GET_RSIP_MODE(x)                     ((u32)(((x >> 8) & 0x00000003)))
#define OTPC_MASK_CFG_RSVD1                       ((u32)0x0000003F << 10)          /*!<PROT/R 6'h3f   */
#define OTPC_CFG_RSVD1(x)                         ((u32)(((x) & 0x0000003F) << 10))
#define OTPC_GET_CFG_RSVD1(x)                     ((u32)(((x >> 10) & 0x0000003F)))
/** @} */

/**
 * @defgroup OTPC_RMA_Data
 * @brief
 * @{
 **/
#define OTPC_MASK_RMA_DATA                        ((u32)0x000000FF << 0)          /*!<PROT/R 8'hff  If the number of 1 is odd , it will goto RMA state . */
#define OTPC_RMA_DATA(x)                          ((u32)(((x) & 0x000000FF) << 0))
#define OTPC_GET_RMA_DATA(x)                      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/**
 * @defgroup OTPC_ROM_Patch
 * @brief
 * @{
 **/
#define OTPC_BIT_ROM_PATCH_EN                     ((u32)0x00000001 << 0)          /*!<PROT/R 1'b1  ROM patch Disable.This Bit will programed by FT if ROM patch do not needed */
#define OTPC_BIT_ROM_PATCH_LWE                    ((u32)0x00000001 << 1)          /*!<PROT/R 1'b1  ROM patch write protection(protect Low 2Kbits) */
#define OTPC_BIT_ROM_PATCH_HWE                    ((u32)0x00000001 << 2)          /*!<PROT/R 1'b1  ROM patch write protection(protect High 2Kbits) */

#define OTPC_PHY_ROM_PATCH_ZONE                     ((u32)0x00000001 << 2)
#define ROM_PATCH_LENGTH 0x200
/** @} */

/** @defgroup EFUSE_Logical_Definitions
  * @{
  */
#define OTP_LMAP_LEN					0x400 /*!< logical map len in byte 0x400~0x7FF resvd*/
#define OTP_MAX_SECTION				(OTP_LMAP_LEN >> 3) /*!< logical map len in section */
#define PGPKT_DATA_SIZE				8 /*!< logical map section len */
#define OTP_MTP_USER_START			0x2D0 /*!< logical map MTP user start address*/
#define OTP_MTP_USER_END			0x2FF /*!< logical map MTP user end address*/
#define OTP_MTP_USER_LEN			(OTP_MTP_USER_END - OTP_MTP_USER_START+1) /*!< logical map MTP user section len in byte 0x2D0~0x2FF*/
/**
  * @}
  */

/** @defgroup EFUSE_Physical_Definitions
  * @{
  */
/*  physical EFUSE len */
#define OTP_REAL_CONTENT_LEN			0x800
#define AVAILABLE_EFUSE_ADDR(addr)		(addr < OTP_REAL_CONTENT_LEN)
/* physical EFUSE write forbid */
#define LOGICAL_MAP_SECTION_LEN		0x1FD /*!< logical mapping efuse len in physical address */
#define OTP_USER_START					0x380 /*!< physical map user start address*/
#define OTP_USER_END					0x4FF /*!< physical map user end address*/
#define OTP_USER_LEN					(OTP_USER_END - OTP_USER_START+1) /*!< physical map user section len in byte 0x380~0x4FF*/
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup OTPC_Exported_Functions OPTC Exported Functions
  * @{
  */

/** @defgroup EFUSE_Physical_Address_Functions
  * @{
  */
extern u32 EFUSERead8(UNUSED_WARN_DIS u32 CtrlSetting, u32 Addr, u8 *Data, UNUSED_WARN_DIS u8 L25OutVoltage);
extern u32 EFUSEWrite8(UNUSED_WARN_DIS u32 CtrlSetting, u32 Addr, u8 Data, UNUSED_WARN_DIS u8 L25OutVoltage);
extern u32 EFUSE_PMAP_READ8(UNUSED_WARN_DIS u32 CtrlSetting, u32 Addr, u8 *Data, UNUSED_WARN_DIS u8 L25OutVoltage);
extern u32 EFUSE_PMAP_WRITE8(UNUSED_WARN_DIS u32 CtrlSetting, u32 Addr, u8 Data, UNUSED_WARN_DIS u8 L25OutVoltage);
extern u32 EFUSE_LMAP_READ(u8 *pbuf);
extern u32 EFUSE_LMAP_WRITE(u32 addr, u32 cnts, u8 *data);
extern u32 EFUSE_RemainLength(void);
/**
  * @}
  */

/**
  * @}
  */

/** @} */

/** @} */

/* Other definitions --------------------------------------------------------*/

enum OTP_OPMode {
	OTP_USER_MODE = 0,
	OTP_PGR_MODE = 2,
};

#define OTP_POLL_TIMES					20000
#define OTP_ACCESS_PWD					0x69
/*meaningless for AmebaD2*/
#define L25EOUTVOLTAGE					7

/* old_EFUSE_definitions */
#define EFUSE_MAP_LEN_8711B			OTP_LMAP_LEN
#define EFUSE_MAX_SECTION_8711B		OTP_MAX_SECTION
#define EFUSE_REAL_CONTENT_LEN		OTP_REAL_CONTENT_LEN
#define EFUSE_OOB_PROTECT_BYTES		(EFUSE_REAL_CONTENT_LEN - LOGICAL_MAP_SECTION_LEN)


/**********************Register definition*********************************/
#define REG_KEY_HUK_0                            0x0310
#define REG_KEY_HUK_1                            0x0314
#define REG_KEY_HUK_2                            0x0318
#define REG_KEY_HUK_3                            0x031C
#define REG_KEY_PK1_0                            0x0320
#define REG_KEY_PK1_1                            0x0324
#define REG_KEY_PK1_2                            0x0328
#define REG_KEY_PK1_3                            0x032C
#define REG_KEY_PK1_4                            0x0330
#define REG_KEY_PK1_5                            0x0334
#define REG_KEY_PK1_6                            0x0338
#define REG_KEY_PK1_7                            0x033C
#define REG_KEY_PK2_0                            0x0340
#define REG_KEY_PK2_1                            0x0344
#define REG_KEY_PK2_2                            0x0348
#define REG_KEY_PK2_3                            0x034C
#define REG_KEY_PK2_4                            0x0350
#define REG_KEY_PK2_5                            0x0354
#define REG_KEY_PK2_6                            0x0358
#define REG_KEY_PK2_7                            0x035C
#define REG_SEC_CFG0                                0x0360
#define REG_SEC_CFG1                                0x0364
#define REG_SEC_CFG2                                0x0368
#define REG_RMA_STATUS                           0x0700
#define REG_ROM_PATCH                             0x0701

/* MANUAL_GEN_END */

#endif
