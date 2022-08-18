/**************************************************************************//**
 * @file      rtl8195blp_vdr_type.h
 * @brief
 * @version   V1.00
 * @date      2017-11-1 16:2:3
 *
 * @note
 *
 ******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation. All rights reserved.
 * 
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 ******************************************************************************/

#ifndef _RTL8195BLP_VENDOR_VDR_TYPE_H_
#define _RTL8195BLP_VENDOR_VDR_TYPE_H_

#ifdef  __cplusplus
extern "C"
{
#endif

/// @cond DOXYGEN_GENERAL_REG_TYPE || DOXYGEN_VDR_REG_TYPE

/**
 * @addtogroup ls_hal_vdr_reg VDR Registers.
 * @ingroup ls_hal_vdr
 * @{
 */

/**
  \brief Union type to access vdr_watch_dog_tmr (@ 0x00000000).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000000) Watch Dog Timer Control Register                           */
  
  struct {
    __IOM uint32_t bit_vndr_divfactor : 16;   /*!< [15..0] Dividing factor. Watch dog timer is count with LP 32KHz/(divfactor+1).
                                                   Minimum dividing factor is 1.                                             */
    __IOM uint32_t wdt_en     : 1;            /*!< [16..16] Set 1 to enable watch dog timer                                  */
    __IM  uint32_t            : 7;
    __OM  uint32_t wdt_clear  : 1;            /*!< [24..24] Write 1 to clear timer                                           */
    __IOM uint32_t cnt_limit  : 4;            /*!< [28..25] 0: 0x001 1: 0x003 2: 0x007 3: 0x00F 4: 0x01F 5: 0x03F
                                                   6: 0x07F 7: 0x0FF 8: 0x1FF 9: 0x3FF 10: 0x7FF 11~15: 0xFFF                */
    __IM  uint32_t            : 1;
    __IOM uint32_t wdt_mode   : 1;            /*!< [30..30] 1: Reset system, 0: Interrupt CPU                                */
    __IOM uint32_t wdt_to     : 1;            /*!< [31..31] Watch dog timer timeout. 1 cycle pulse                           */
  } b;                                        /*!< bit fields for vdr_watch_dog_tmr */
} vdr_watch_dog_tmr_t, *pvdr_watch_dog_tmr_t;

/**
  \brief Union type to access vdr_low_pri_int_mod (@ 0x00000004).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000004) Low Priority Interrupt Mode Control Register               */
  
  struct {
    __IOM uint32_t low_pri_int_mod : 32;      /*!< [31..0] Each bit control corresponding interrupt mode. 1: Rising
                                                   edge trigger 0: High level active                                         */
  } b;                                        /*!< bit fields for vdr_low_pri_int_mod */
} vdr_low_pri_int_mod_t, *pvdr_low_pri_int_mod_t;

/**
  \brief Union type to access vdr_low_pri_int_imr (@ 0x00000008).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000008) Low Priority Interrupt Mask Control Register               */
  
  struct {
    __IOM uint32_t low_pri_int_imr : 32;      /*!< [31..0] Each bit enable corresponding interrupt. 1: Enable 0:
                                                   Disable                                                                   */
  } b;                                        /*!< bit fields for vdr_low_pri_int_imr */
} vdr_low_pri_int_imr_t, *pvdr_low_pri_int_imr_t;

/**
  \brief Union type to access vdr_low_pri_int_isr (@ 0x0000000C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000000C) Low Priority Interrupt Status Register                     */
  
  struct {
    __IOM uint32_t wdt_tm     : 1;            /*!< [0..0] 1: watchdog reset event of TM                                      */
    __IOM uint32_t adp_in     : 1;            /*!< [1..1] 1: adapter in                                                      */
    __IOM uint32_t bod        : 1;            /*!< [2..2] 1: Brown out detected                                              */
    __IOM uint32_t swr_d_ocp  : 1;            /*!< [3..3] 1: indicate SWR_D OCP event interrupt                              */
    __IM  uint32_t            : 5;
    __IOM uint32_t rxi_bus    : 1;            /*!< [9..9] RXI300 bus interrupt status                                        */
  } b;                                        /*!< bit fields for vdr_low_pri_int_isr */
} vdr_low_pri_int_isr_t, *pvdr_low_pri_int_isr_t;

/**
  \brief Union type to access vdr_i2c_dat_fifo_ctrl (@ 0x00000020).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000020) I2C Data FIFO Swap Control Register                        */
  
  struct {
    __IOM uint32_t tx_swp_en  : 1;            /*!< [0..0] i2c0_tx_bit_swap_en                                                */
    __IOM uint32_t rx_swp_en  : 1;            /*!< [1..1] i2c0_rx_bit_swap_en                                                */
  } b;                                        /*!< bit fields for vdr_i2c_dat_fifo_ctrl */
} vdr_i2c_dat_fifo_ctrl_t, *pvdr_i2c_dat_fifo_ctrl_t;

/**
  \brief Union type to access vdr_i2c_dglch_ctrl (@ 0x00000024).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000024) I2C Deglitch Control Register                              */
  
  struct {
    __IOM uint32_t en         : 1;            /*!< [0..0] I2C deglitch calibrator enable. 1: Enable, 0: Done/Disable         */
    __IM  uint32_t            : 7;
    __IOM uint32_t dat_p_dglch_sts : 1;       /*!< [8..8] SDA positive deglitch filter status. 0: failed, 1:success          */
    __IOM uint32_t dat_n_dglch_sts : 1;       /*!< [9..9] SDA negative deglitch filter status. 0: failed, 1:success          */
    __IOM uint32_t clk_p_dglch_sts : 1;       /*!< [10..10] SCL positive deglitch filter status. 0: failed, 1:success        */
    __IOM uint32_t clk_n_dglch_sts : 1;       /*!< [11..11] SCL negative deglitch filter status. 0: failed, 1:success        */
  } b;                                        /*!< bit fields for vdr_i2c_dglch_ctrl */
} vdr_i2c_dglch_ctrl_t, *pvdr_i2c_dglch_ctrl_t;

/**
  \brief Union type to access vdr_gdma_isr (@ 0x00000030).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000030) GDMA ISR Register                                          */
  
  struct {
    __IM  uint32_t gdma0_ch0_isr : 1;         /*!< [0..0] GDMA 0 ISR for Channel 0                                           */
    __IM  uint32_t gdma0_ch1_isr : 1;         /*!< [1..1] GDMA 0 ISR for Channel 1                                           */
    __IM  uint32_t gdma0_ch2_isr : 1;         /*!< [2..2] GDMA 0 ISR for Channel 2                                           */
    __IM  uint32_t gdma0_ch3_isr : 1;         /*!< [3..3] GDMA 0 ISR for Channel 3                                           */
  } b;                                        /*!< bit fields for vdr_gdma_isr */
} vdr_gdma_isr_t, *pvdr_gdma_isr_t;

/**
  \brief Union type to access vdr_uart_isr (@ 0x00000034).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000034) UART Interrupt Status Register                             */
  
  struct {
    __IM  uint32_t uart0_isr  : 1;            /*!< [0..0] 1: UART 0 interrupt pending status                                 */
    __IM  uint32_t uart1_isr  : 1;            /*!< [1..1] 1: UART 1 interrupt pending status                                 */
  } b;                                        /*!< bit fields for vdr_uart_isr */
} vdr_uart_isr_t, *pvdr_uart_isr_t;

/**
  \brief Union type to access vdr_anack_cal_ctrl (@ 0x00000040).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000040) ANA Clock Calibration Control Register                     */
  
  struct {
    __IM  uint32_t vdr_anack_cal_rpt : 16;    /*!< [15..0] the calibration value of ANA clock where the calibration
                                                   clock is bus generic clock.                                               */
    __IM  uint32_t            : 8;
    __IOM uint32_t vdr_anack_cal_sel : 2;     /*!< [25..24] 00: caliabration of 4M for 32 cycles 01: calibration
                                                   of 100K for 8 cycles 10: calibration of 32K for 8 cycles
                                                   11: rsvd                                                                  */
    __IM  uint32_t            : 5;
    __IOM uint32_t vdr_anack_cal_cmd : 1;     /*!< [31..31] 1: polling ANACK Calibration enable and indicate busy
                                                   when calibration is on going 0: calibration is done                       */
  } b;                                        /*!< bit fields for vdr_anack_cal_ctrl */
} vdr_anack_cal_ctrl_t, *pvdr_anack_cal_ctrl_t;

/**
  \brief Union type to access vdr_lp_fll2m_k_ctrl (@ 0x00000044).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000044) LP FLL2M Calibration Control Register                      */
  
  struct {
    __IOM uint32_t en         : 1;            /*!< [0..0] calibration enable. 1: enable calibration, 0: calibration
                                                   done/ disable                                                             */
    __IOM uint32_t clk_en     : 1;            /*!< [1..1] calibration clock enable                                           */
    __IM  uint32_t            : 6;
    __IOM uint32_t t_dly      : 4;            /*!< [11..8] Delay count for new 2M stable                                     */
    __IOM uint32_t div_cnt    : 2;            /*!< [13..12] 2MOSC divide count 0: divided by 16 1: divided by 32
                                                   2: divided by 64 3: diveded by 128                                        */
    __IM  uint32_t            : 2;
    __IM  uint32_t cali_cnt   : 16;           /*!< [31..16] Real 2MOSC count                                                 */
  } b;                                        /*!< bit fields for vdr_lp_fll2m_k_ctrl */
} vdr_lp_fll2m_k_ctrl_t, *pvdr_lp_fll2m_k_ctrl_t;

/**
  \brief Union type to access vdr_mbist_ctrl0 (@ 0x000000A0).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000A0) MBIST Control Register0                                    */
  
  struct {
    __IOM uint32_t mbist_en   : 1;            /*!< [0..0] Set reset_n of mbist controller                                    */
    __IOM uint32_t mbist_cke  : 1;            /*!< [1..1] Set clock enable of mbist controller                               */
    __IM  uint32_t            : 6;
    __IOM uint32_t mbist_ctrlr_addr : 5;      /*!< [12..8] Set mbist controller address                                      */
  } b;                                        /*!< bit fields for vdr_mbist_ctrl0 */
} vdr_mbist_ctrl0_t, *pvdr_mbist_ctrl0_t;

/**
  \brief Union type to access vdr_mbist_ctrl1 (@ 0x000000A4).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000A4) MBIST Control Register1                                    */
  
  struct {
    __IOM uint32_t mbist_ctrlr_data : 32;     /*!< [31..0] Indirectly write to mbist controller with write strobe/Indirectly
                                                   read from mbist controller                                                */
  } b;                                        /*!< bit fields for vdr_mbist_ctrl1 */
} vdr_mbist_ctrl1_t, *pvdr_mbist_ctrl1_t;

/** @} */ /* End of group ls_hal_vdr_reg */
/// @endcond /* End of condition DOXYGEN_GENERAL_REG_TYPE || DOXYGEN_VDR_REG_TYPE */


#ifdef  __cplusplus
}
#endif

#endif    // end of #ifndef _RTL8195BLP_VENDOR_VDR_TYPE_H_

