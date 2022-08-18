/**************************************************************************//**
 * @file      rtl8195blp_aon_type.h
 * @brief
 * @version   V1.00
 * @date      2019-5-23 15:47:22
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

#ifndef _RTL8195BLP_AON_AON_TYPE_H_
#define _RTL8195BLP_AON_AON_TYPE_H_

#ifdef  __cplusplus
extern "C"
{
#endif

/// @cond DOXYGEN_GENERAL_REG_TYPE || DOXYGEN_AON_REG_TYPE

/**
 * @addtogroup ls_hal_aon_reg AON Registers.
 * @ingroup ls_hal_aon
 * @{
 */

/**
  \brief Union type to access aon_iso_ctrl (@ 0x00000004).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000004) Isolation Control Register                                 */
  
  struct {
    __IOM uint32_t aon_iso_lp : 1;            /*!< [0..0] Isolation LP to AON domain; 0: disable isolation                   */
    __IOM uint32_t int_clk_sel : 1;           /*!< [1..1] interrupt clock source selection, 0: 100k, 1: 128k/32k             */
    __IOM uint32_t aux_func_clk_sel : 1;      /*!< [2..2] auxiliary function clock source selection, 0: 100K, 1:
                                                   128k/32k                                                                  */
    __IOM uint32_t laon_funen : 1;            /*!< [3..3] LS AON function Enable                                             */
    __IM  uint32_t            : 12;
    __IOM uint32_t lponfun_fen : 1;           /*!< [16..16] 1: Enable LPON                                                   */
    __IOM uint32_t rtc_interface_en : 1;      /*!< [17..17] 1:Enable RTC interface, need delay 4ms                           */
  } b;                                        /*!< bit fields for aon_iso_ctrl */
} aon_iso_ctrl_t, *paon_iso_ctrl_t;

/**
  \brief Union type to access aon_sw_reserv0 (@ 0x0000000C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000000C) SW Reserved Register                                       */
  
  struct {
    __IOM uint32_t pwr_sts    : 32;           /*!< [31..0] reserved for SW: to indicate current power mode status            */
  } b;                                        /*!< bit fields for aon_sw_reserv0 */
} aon_sw_reserv0_t, *paon_sw_reserv0_t;

/**
  \brief Union type to access aon_ldo_ctrl0 (@ 0x00000010).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000010) LDO Control Register0                                      */
  
  struct {
    __IM  uint32_t            : 2;
    __IOM uint32_t aon_ck_100_en : 1;         /*!< [2..2] 1: Enable aon 100k                                                 */
    __IM  uint32_t            : 9;
    __IOM uint32_t aon_ldo_v09_adj : 4;       /*!< [15..12] AON LDO voltage select: 0000: 0.600V; 0001: 0.631V;
                                                   0010: 0.660V; 0011: 0.692V; 0100: 0.719V; 0101: 0.749V;
                                                   0110: 0.782V; 0111: 0.817V; 1000: 0.856V; 1001: 0.899V;
                                                   1010: 0.952V; 1011: 0.998V; 1100: 1.049V; 1101: 1.096V;
                                                   1110: 1.149V; 1111: 1.196V;                                               */
    __IOM uint32_t aon_ldo_slp_en : 1;        /*!< [16..16] Enable LDO12H sleep mode                                         */
    __IM  uint32_t            : 3;
    __IOM uint32_t aon_bod_vsel : 3;          /*!< [22..20] Brown Out Detection Voltage: Reset Voltage: 000: 0.475
                                                   ~ 0.450; 001: 1.947 ~ 1.844; 010: 2.030 ~ 1.923; 011: 2.121
                                                   ~ 2.009; 100: 2.199 ~ 2.083; 101: 2.284 ~ 2.163; 110: 2.375
                                                   ~ 2.250; 111: 2.448 ~ 2.320; _x000D_Interrupt Voltage:
                                                   000: 0.575 ~ 0.550; 001: 2.357 ~ 2.254; 010: 2.457 ~ 2.350;
                                                   011: 2.567 ~ 2.455; 100: 2.662 ~ 2.546; 101: 2.764 ~ 2.644;
                                                   110: 2.875 ~ 2.750; 111: 2.964 ~ 2.835;                                   */
    __IM  uint32_t            : 2;
    __IOM uint32_t ldo_vbat_diode_en : 1;     /*!< [25..25] 5V LDO power mos diode for inrush current(5V normal
                                                   mode=0)                                                                   */
    __IOM uint32_t aon_bg_current_en : 1;     /*!< [26..26] BG current power on(BOD or 5V normal mode need =1)               */
  } b;                                        /*!< bit fields for aon_ldo_ctrl0 */
} aon_ldo_ctrl0_t, *paon_ldo_ctrl0_t;

/**
  \brief Union type to access aon_ldo_ctrl1 (@ 0x00000014).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000014) LDO Control Register1                                      */
  
  struct {
    __IM  uint32_t            : 1;
    __IOM uint32_t ldo_vbat_en : 1;           /*!< [1..1] 1:5V LDO reference ON                                              */
    __IM  uint32_t            : 6;
    __IOM uint32_t ldo_lp_en  : 1;            /*!< [8..8] 1: enable                                                          */
    __IOM uint32_t ldo_lp_slp : 1;            /*!< [9..9] 1: SLEEP                                                           */
    __IOM uint32_t ldo_lp_adj : 4;            /*!< [13..10] ldo voltage: 0000: 0.600V; 0001: 0.631V; 0010: 0.660V;
                                                   0011: 0.692V; 0100: 0.719V; 0101: 0.749V; 0110: 0.782V;
                                                   0111: 0.817V; 1000: 0.856V; 1001: 0.899V; 1010: 0.952V;
                                                   1011: 0.998V; 1100: 1.049V; 1101: 1.096V; 1110: 1.149V;
                                                   1111: 1.196V;                                                             */
  } b;                                        /*!< bit fields for aon_ldo_ctrl1 */
} aon_ldo_ctrl1_t, *paon_ldo_ctrl1_t;

/**
  \brief Union type to access aon_mem_pwr_ctrl (@ 0x0000001C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000001C) Memory Power (Deep Sleep) Control Register                 */
  
  struct {
    __IOM uint32_t retmem_ds_en : 1;          /*!< [0..0] Enable retaination memory for deep sleep mode                      */
    __IOM uint32_t retmem_sd_en : 1;          /*!< [1..1] Enable retaination memory for power shutdown mode                  */
    __IM  uint32_t            : 2;
    __IOM uint32_t sram_ds_en : 1;            /*!< [4..4] Enable SRAM for deep sleep mode                                    */
    __IOM uint32_t sram_sd_en : 1;            /*!< [5..5] Enable SRAM for power shutdown mode                                */
    __IM  uint32_t            : 2;
    __IOM uint32_t dtcm_ds_en : 1;            /*!< [8..8] Enable DTCM for deep sleep mode                                    */
    __IOM uint32_t dtcm_sd_en : 1;            /*!< [9..9] Enable DTCM for power shutdown mode                                */
  } b;                                        /*!< bit fields for aon_mem_pwr_ctrl */
} aon_mem_pwr_ctrl_t, *paon_mem_pwr_ctrl_t;

/**
  \brief Union type to access aon_xtal_32k_ctrl0 (@ 0x00000020).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000020) 32K Xtal Control Register0                                 */
  
  struct {
    __IOM uint32_t xtal_en    : 1;            /*!< [0..0] xtal enable                                                        */
    __IM  uint32_t            : 15;
    __IOM uint32_t xtal_cur_main : 2;         /*!< [17..16] xtal main current                                                */
    __IOM uint32_t xtal_cur_gm_ini : 4;       /*!< [21..18] initial gm current                                               */
    __IOM uint32_t xtal_cur_gm : 4;           /*!< [25..22] awake gm current                                                 */
    __IOM uint32_t xtal_cur_rep : 2;          /*!< [27..26] replica buffer current                                           */
    __IOM uint32_t xtal_gm    : 4;            /*!< [31..28] gm size                                                          */
  } b;                                        /*!< bit fields for aon_xtal_32k_ctrl0 */
} aon_xtal_32k_ctrl0_t, *paon_xtal_32k_ctrl0_t;

/**
  \brief Union type to access aon_xtal_32k_ctrl1 (@ 0x00000024).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000024) 32K Xtal Control Register1                                 */
  
  struct {
    __IOM uint32_t en_xtal_cap_init : 1;      /*!< [0..0] internal cap enable as initial                                     */
    __IOM uint32_t en_xtal_cap_awk : 1;       /*!< [1..1] internal cap enable as awake                                       */
    __IOM uint32_t xtal_sc_xi : 6;            /*!< [7..2] xi cap                                                             */
    __IOM uint32_t xtal_sc_xo : 6;            /*!< [13..8] xo cap                                                            */
    __IOM uint32_t xtal_tok   : 2;            /*!< [15..14] 00: 100ms 01:200ms 10:400ms 11: 800ms                            */
    __IOM uint32_t enb_xtal_fbres : 1;        /*!< [16..16] 0: enable feedback resistor                                      */
    __IOM uint32_t xtal_gm_rep : 3;           /*!< [19..17] repilca size                                                     */
    __IOM uint32_t xtal_sc_xi_ext : 1;        /*!< [20..20] 0: w/i 4pF cap 1: w/o 4pF cap                                    */
    __IOM uint32_t xtal_sc_xo_ext : 1;        /*!< [21..21] 0: w/i 4pF cap 1: w/o 4pF cap                                    */
  } b;                                        /*!< bit fields for aon_xtal_32k_ctrl1 */
} aon_xtal_32k_ctrl1_t, *paon_xtal_32k_ctrl1_t;

/**
  \brief Union type to access aon_fast_boot_ctrl (@ 0x00000028).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000028) Fast Boot Control register                                 */
  
  struct {
    __IOM uint32_t fast_boot_addr : 32;       /*!< [31..0] reserved for SW: fast boot control. To store the RAM
                                                   code entry point for fast boot.                                           */
  } b;                                        /*!< bit fields for aon_fast_boot_ctrl */
} aon_fast_boot_ctrl_t, *paon_fast_boot_ctrl_t;

/**
  \brief Union type to access aon_osc_32k_ctrl (@ 0x0000002C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000002C) 32K Oscillator Control Register                            */
  
  struct {
    __IOM uint32_t osc32k_en  : 1;            /*!< [0..0] osc enable                                                         */
    __IM  uint32_t            : 7;
    __IOM uint32_t osc32k_rcal : 6;           /*!< [13..8] osc frequency is highier as RCAL's larger                         */
    __IM  uint32_t            : 6;
    __IOM uint32_t sel_ldo_vref : 1;          /*!< [20..20] 0: LDO low valtage setting 1:high voltage                        */
    __IOM uint32_t sel_h      : 1;            /*!< [21..21] 0: OSC128K 1:XTAL32K                                             */
    __IOM uint32_t sel_l      : 1;            /*!< [22..22] 0: OSC1K 1:XTAL1K                                                */
  } b;                                        /*!< bit fields for aon_osc_32k_ctrl */
} aon_osc_32k_ctrl_t, *paon_osc_32k_ctrl_t;

/**
  \brief Union type to access aon_wake_tmr (@ 0x00000030).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000030) AON Wake Up Timer Register                                 */
  
  struct {
    __IOM uint32_t wake_tm0_tc : 30;          /*!< [29..0] AON wake timer0 counter value                                     */
    __IM  uint32_t            : 1;
    __IOM uint32_t wake_tm0_en : 1;           /*!< [31..31] AON wake timer0 Enable                                           */
  } b;                                        /*!< bit fields for aon_wake_tmr */
} aon_wake_tmr_t, *paon_wake_tmr_t;

/**
  \brief Union type to access aon_io_pad_ctrl (@ 0x00000038).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000038) AON IO Pad Control Register                                */
  
  struct {
    __IOM uint32_t gpioa13_pwd33 : 1;         /*!< [0..0] 1: power down GPIOA13                                              */
    __IOM uint32_t gpioa13_shd : 1;           /*!< [1..1] 0: shut down GPIOA13                                               */
    __IM  uint32_t            : 2;
    __IOM uint32_t gpioa13_h3l1_sel : 1;      /*!< [4..4] GPIOA13 Voltage Select: 0: 1.8V, 1: 3V                             */
    __IOM uint32_t gpioa13_drv_sel : 1;       /*!< [5..5] GPIOA13 Driving Select: 0: 8mA, 1: 16mA                            */
    __IOM uint32_t gpioa13_smt_en : 1;        /*!< [6..6] Enable GPIOA13 schmitt trigger                                     */
    __IM  uint32_t            : 1;
    __IOM uint32_t gpioa13_pull_ctrl : 2;     /*!< [9..8] 2b'00: high impedence; 2b'01: pull low; 2b'10: pull high;
                                                   2b'11: reserved                                                           */
    __IM  uint32_t            : 6;
    __IOM uint32_t gpioa_rstb33 : 1;          /*!< [16..16] 0: Reset GPIOA                                                   */
    __IOM uint32_t hs_gpio_rstb33 : 1;        /*!< [17..17] 0: Reset HS GPIO                                                 */
  } b;                                        /*!< bit fields for aon_io_pad_ctrl */
} aon_io_pad_ctrl_t, *paon_io_pad_ctrl_t;

/**
  \brief Union type to access aon_gpio_wake_ctrl (@ 0x0000003C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000003C) AON GPIO Wake Up Control Register                          */
  
  struct {
    __IOM uint32_t gpio_wake_en : 1;          /*!< [0..0] 1: Enable GPIOA_13 as AON wake source                              */
    __IOM uint32_t wake_pol_sel : 1;          /*!< [1..1] 0: Falling edge 1: Rising edge                                     */
    __IOM uint32_t wake_gpio_mux_en : 1;      /*!< [2..2] 1: Enable GPIOA13 Wake pinmux                                      */
    __IM  uint32_t            : 4;
    __IOM uint32_t wake_gpio_deb_en : 1;      /*!< [7..7] 1: Enable gpio debounce                                            */
    __IOM uint32_t wake_gpio_deb_cyc : 15;    /*!< [22..8] The GPIO signal will be filtered by the number of debounce
                                                   cycles of specified in this register. (100k)                              */
  } b;                                        /*!< bit fields for aon_gpio_wake_ctrl */
} aon_gpio_wake_ctrl_t, *paon_gpio_wake_ctrl_t;

/**
  \brief Union type to access aon_charg_ctrl0 (@ 0x00000040).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000040) Battery Charger Control Register0                          */
  
  struct {
    __IOM uint32_t en_flag_out : 1;           /*!< [0..0] 1: Enable flag out                                                 */
    __IM  uint32_t            : 15;
    __IOM uint32_t pow_chg    : 1;            /*!< [16..16] POW_CHG                                                          */
    __IOM uint32_t enotp_chg0a : 1;           /*!< [17..17] 1: ICG = 0 when OTP                                              */
    __IOM uint32_t pow_cv_chg : 1;            /*!< [18..18] 1: LDO mode, 0: Current limit SW                                 */
    __IOM uint32_t pow_dvdet_m2 : 1;          /*!< [19..19] dvdet_M2 enable                                                  */
    __IOM uint32_t endisbias_m2 : 1;          /*!< [20..20] enable M2 VC disable bias                                        */
    __IM  uint32_t            : 1;
    __IOM uint32_t vbat_ftune : 5;            /*!< [26..22] Vout def = (5'b10011+1)*100mV + (5'b10000)*10mV + 2040mV
                                                   = 4.2V                                                                    */
    __IOM uint32_t vbat_ctune : 5;            /*!< [31..27] Vout= (CTUNE+1)*100mV+(FTUNE)*10mV+2040mV                        */
  } b;                                        /*!< bit fields for aon_charg_ctrl0 */
} aon_charg_ctrl0_t, *paon_charg_ctrl0_t;

/**
  \brief Union type to access aon_charg_ctrl12 (@ 0x00000044).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000044) Battery Charger Control Register12                         */
  
  struct {
    __IM  uint32_t            : 6;
    __IOM uint32_t m2_icharge_ftune : 3;      /*!< [8..6] FT                                                                 */
    __IOM uint32_t m2_icharge_ctune : 3;      /*!< [11..9] CT                                                                */
    __IM  uint32_t            : 4;
    __IOM uint32_t pow_bias   : 1;            /*!< [16..16] Set as 1 to enable the charger                                   */
    __IOM uint32_t pow_adp_det : 1;           /*!< [17..17] It should be set as 1                                            */
    __IOM uint32_t pow_vbat_det : 1;          /*!< [18..18] It should be set as 1                                            */
    __IOM uint32_t bg_r1_tune : 3;            /*!< [21..19] LPBG R1 tune                                                     */
    __IOM uint32_t bg_r2_tune : 3;            /*!< [24..22] LPBG R2 tune                                                     */
    __IOM uint32_t bg_vref_tune : 3;          /*!< [27..25] LPBG VREF 1.2V fine tune                                         */
    __IOM uint32_t ldo733_ibe : 3;            /*!< [30..28] TUNE LDO733 Iq, increase the current to gain LDO bandwidth       */
    __IOM uint32_t pow_otp    : 1;            /*!< [31..31] OTP CMP power enable                                             */
  } b;                                        /*!< bit fields for aon_charg_ctrl12 */
} aon_charg_ctrl12_t, *paon_charg_ctrl12_t;

/**
  \brief Union type to access aon_charg_ctrl34 (@ 0x00000048).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000048) Battery Charger Control Register34                         */
  
  struct {
    __IOM uint32_t sel_adpin_vr_h : 3;        /*!< [2..0] Defined by POWER_DET data sheet                                    */
    __IOM uint32_t sel_adpin_vr_l : 3;        /*!< [5..3] Defined by POWER_DET data sheet                                    */
    __IOM uint32_t sel_vbat_vr_h : 3;         /*!< [8..6] Defined by POWER_DET data sheet                                    */
    __IOM uint32_t sel_vbat_vr_l : 3;         /*!< [11..9] Defined by POWER_DET data sheet                                   */
    __IOM uint32_t vr_sel_otp_l : 3;          /*!< [14..12] Defined by POWER_DET data sheet                                  */
    __IM  uint32_t            : 1;
    __IOM uint32_t sel_hv33_aon_vr_h : 3;     /*!< [18..16] Defined by POWER_DET data sheet                                  */
    __IOM uint32_t sel_hv33_aon_vr_l : 3;     /*!< [21..19] Defined by POWER_DET data sheet                                  */
    __IOM uint32_t sel_dvdd_aon_vr_h : 3;     /*!< [24..22] Defined by POWER_DET data sheet                                  */
    __IOM uint32_t sel_dvdd_aon_vr_l : 3;     /*!< [27..25] Defined by POWER_DET data sheet                                  */
    __IOM uint32_t vr_sel_otp_h : 3;          /*!< [30..28] Defined by POWER_DET data sheet                                  */
  } b;                                        /*!< bit fields for aon_charg_ctrl34 */
} aon_charg_ctrl34_t, *paon_charg_ctrl34_t;

/**
  \brief Union type to access aon_charg_ctrl56 (@ 0x0000004C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000004C) Battery Charger Control Register56                         */
  
  struct {
    __IOM uint32_t trim1khz   : 4;            /*!< [3..0] TRIM 1K OSI CODE                                                   */
    __IM  uint32_t            : 1;
    __IOM uint32_t sdosi      : 1;            /*!< [5..5] SD 1k OSI                                                          */
    __IOM uint32_t bypasst    : 1;            /*!< [6..6] Test for CHG DIG timmer                                            */
    __IOM uint32_t timeouts   : 1;            /*!< [7..7] 0: 16hr, 1:32hr                                                    */
    __IM  uint32_t            : 2;
    __IOM uint32_t dis_aon_sd : 1;            /*!< [10..10] When DVDD and HV33 are ready, 1: turn ON CHG; 0: turn
                                                   OFF CHG while ADP don't exist.                                            */
    __IOM uint32_t soc_en_ldp309 : 1;         /*!< [11..11] When DVDD and HV33 ready, 1: turn ON LDO309; 0: turn
                                                   OFF LDO309. When ADP and HV33 ready, system will auto open
                                                   LDO309.                                                                   */
    __IOM uint32_t sel_vr_temp45_l : 2;       /*!< [13..12] Defined by POWER_DET data sheet                                  */
    __IOM uint32_t sel_vr_temp0_l : 2;        /*!< [15..14] Defined by POWER_DET data sheet                                  */
  } b;                                        /*!< bit fields for aon_charg_ctrl56 */
} aon_charg_ctrl56_t, *paon_charg_ctrl56_t;

/**
  \brief Union type to access aon_pmc_ctrl (@ 0x00000050).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000050) Power Management Control Register                          */
  
  struct {
    __IOM uint32_t ldo_hwen_cond_chk_dis0 : 1;/*!< [0..0] 1: disable FSM check HW LP LDO enable condition when
                                                   power on; (chip en and VBAT_33_OK)                                        */
    __IOM uint32_t ldo_hwen_cond_chk_dis1 : 1;/*!< [1..1] 1: disable FSM check HW LP LDO enable condition when
                                                   power on; (BOD)                                                           */
  } b;                                        /*!< bit fields for aon_pmc_ctrl */
} aon_pmc_ctrl_t, *paon_pmc_ctrl_t;

/**
  \brief Union type to access aon_pm_opt (@ 0x00000054).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000054) Power Management Optional Control Register                 */
  
  struct {
    __IOM uint32_t ldo_vbat_en : 1;           /*!< [0..0] 1: Enable FSM to enable LDO_VBAT when power on                     */
    __IM  uint32_t            : 7;
    __IOM uint32_t ldo_aon_mod_sel : 1;       /*!< [8..8] 1: Normal, 0:slp                                                   */
    __IOM uint32_t aon_reg_clk_en : 1;        /*!< [9..9] When enter dslp, 1: enable clk; 0: gated                           */
    __IOM uint32_t osc_100k_en : 1;           /*!< [10..10] When enter dslp, 1: enable clk; 0: disable                       */
  } b;                                        /*!< bit fields for aon_pm_opt */
} aon_pm_opt_t, *paon_pm_opt_t;

/**
  \brief Union type to access aon_wake_opt_msk (@ 0x00000058).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000058) AON Wake Option Mask Register                              */
  
  struct {
    __IOM uint32_t gpio_wake_msk : 1;         /*!< [0..0] 1: enable GPIO wake                                                */
    __IOM uint32_t aon_wake_tim0_msk : 1;     /*!< [1..1] 1: enable AON timer wake                                           */
    __IOM uint32_t rtc_wake_msk : 1;          /*!< [2..2] 1: enable RTC wake                                                 */
    __IOM uint32_t adp_wake_msk : 1;          /*!< [3..3] 1: enable Adapter wake flag0 rising edge                           */
  } b;                                        /*!< bit fields for aon_wake_opt_msk */
} aon_wake_opt_msk_t, *paon_wake_opt_msk_t;

/**
  \brief Union type to access aon_wake_opt_sts (@ 0x0000005C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000005C) AON Wake Status Register                                   */
  
  struct {
    __IOM uint32_t gpio_wake_sts : 1;         /*!< [0..0] 1: Indicate GPIO wake                                              */
    __IOM uint32_t aon_wake_tim0_sts : 1;     /*!< [1..1] 1: Indicate AON timer wake                                         */
    __IOM uint32_t rtc_wake_sts : 1;          /*!< [2..2] 1: Indicate RTC wake                                               */
    __IOM uint32_t adp_wake_sts : 1;          /*!< [3..3] 1: Indicate Adapter wake                                           */
  } b;                                        /*!< bit fields for aon_wake_opt_sts */
} aon_wake_opt_sts_t, *paon_wake_opt_sts_t;

/**
  \brief Union type to access aon_lsfif_cmd (@ 0x00000080).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000080) Low Speed Function Interface Command Register              */
  
  struct {
    __IOM uint32_t lsfif_ad   : 16;           /*!< [15..0] LSF register access address. BIT_AON_LSFIF_AD[15:8]=8'h00:
                                                   RTC register base address                                                 */
    __IM  uint32_t            : 8;
    __IOM uint32_t lsfif_we   : 4;            /*!< [27..24] LSF register byte write enable. This field is valid
                                                   during LSF register write transfer, and is ignored during
                                                   LSF register read transfer                                                */
    __IOM uint32_t lsfif_wr   : 1;            /*!< [28..28] LSF register write transfer indicator. 1: LSF register
                                                   write transfer, 0: LSF register read transfer                             */
    __IM  uint32_t            : 2;
    __IOM uint32_t lsfif_poll : 1;            /*!< [31..31] LSF (low speed function) register access polling bit.
                                                   Set this bit to do LSF register read or write transfer
                                                   depend on BIT_AON_LSFIF_WR. When transfer done, this bit
                                                   will be clear by HW                                                       */
  } b;                                        /*!< bit fields for aon_lsfif_cmd */
} aon_lsfif_cmd_t, *paon_lsfif_cmd_t;

/**
  \brief Union type to access aon_lsfif_rwd (@ 0x00000084).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000084) Low Speed Function Interface R/W Data Register             */
  
  struct {
    __IOM uint32_t aon_lsfif_rwd : 32;        /*!< [31..0] LSF(low speed function) write                                     */
  } b;                                        /*!< bit fields for aon_lsfif_rwd */
} aon_lsfif_rwd_t, *paon_lsfif_rwd_t;

/**
  \brief Union type to access aon_rtc_imr (@ 0x00000088).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000088) RTC Interrupt Mask Register                                */
  
  struct {
    __IOM uint32_t cnt_sec_imr : 1;           /*!< [0..0] Interrupt mask of RTC seconds counter                              */
    __IOM uint32_t cnt_min_imr : 1;           /*!< [1..1] Interrupt mask of RTC minutes counter                              */
    __IOM uint32_t cnt_hrs_imr : 1;           /*!< [2..2] Interrupt mask of RTC hours counter                                */
    __IOM uint32_t cnt_dow_imr : 1;           /*!< [3..3] Interrupt mask of RTC day of week counter                          */
    __IOM uint32_t cnt_dom_imr : 1;           /*!< [4..4] Interrupt mask of RTC day of month counter                         */
    __IOM uint32_t cnt_mth_imr : 1;           /*!< [5..5] Interrupt mask of RTC month counter                                */
    __IOM uint32_t cnt_yrs_imr : 1;           /*!< [6..6] Interrupt mask of RTC years counter                                */
    __IOM uint32_t cnt_doy_imr : 1;           /*!< [7..7] Interrupt mask of RTC day of year counter                          */
    __IOM uint32_t alrm_sec_imr : 1;          /*!< [8..8] Interrupt mask of RTC second alarm                                 */
    __IOM uint32_t alrm_min_imr : 1;          /*!< [9..9] Interrupt mask of RTC minute alarm                                 */
    __IOM uint32_t alrm_hrs_imr : 1;          /*!< [10..10] Interrupt mask of RTC hour alarm                                 */
    __IOM uint32_t alrm_dow_imr : 1;          /*!< [11..11] Interrupt mask of RTC day of week alarm                          */
    __IOM uint32_t alrm_dom_imr : 1;          /*!< [12..12] Interrupt mask of RTC day of month alarm                         */
    __IOM uint32_t alrm_mth_imr : 1;          /*!< [13..13] Interrupt mask of RTC month alarm                                */
    __IOM uint32_t alrm_yrs_imr : 1;          /*!< [14..14] Interrupt mask of RTC year alarm                                 */
    __IOM uint32_t alrm_doy_imr : 1;          /*!< [15..15] Interrupt mask of RTC day of year alarm                          */
    __IOM uint32_t alrm_imr   : 1;            /*!< [16..16] Interrupt mask of RTC alarm                                      */
  } b;                                        /*!< bit fields for aon_rtc_imr */
} aon_rtc_imr_t, *paon_rtc_imr_t;

/**
  \brief Union type to access aon_rtc_isr (@ 0x0000008C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000008C) RTC Interrupt Status Register                              */
  
  struct {
    __IOM uint32_t cnt_sec_isr : 1;           /*!< [0..0] Indicate increment of the second timer                             */
    __IOM uint32_t cnt_min_isr : 1;           /*!< [1..1] Indicate increment of the minute timer                             */
    __IOM uint32_t cnt_hrs_isr : 1;           /*!< [2..2] Indicate increment of the hour timer                               */
    __IOM uint32_t cnt_dow_isr : 1;           /*!< [3..3] Indicate increment of the day-of-week timer                        */
    __IOM uint32_t cnt_dom_isr : 1;           /*!< [4..4] Indicate increment of the day-of-month timer                       */
    __IOM uint32_t cnt_mth_isr : 1;           /*!< [5..5] Indicate increment of the month timer                              */
    __IOM uint32_t cnt_yrs_isr : 1;           /*!< [6..6] Indicate increment of the year timer                               */
    __IOM uint32_t cnt_doy_isr : 1;           /*!< [7..7] Indicate increment of the Day-of-year timer                        */
    __IOM uint32_t alrm_sec_isr : 1;          /*!< [8..8] Indicate Second timer value match ALRM_SEC                         */
    __IOM uint32_t alrm_min_isr : 1;          /*!< [9..9] Indicate Minute timer value match ALRM_MIN                         */
    __IOM uint32_t alrm_hrs_isr : 1;          /*!< [10..10] Indicate Hour timer value match ALRM_HRS                         */
    __IOM uint32_t alrm_dow_isr : 1;          /*!< [11..11] Indicate DOW timer value match ALRM_DOW                          */
    __IOM uint32_t alrm_dom_isr : 1;          /*!< [12..12] Indicate DOM timer value match ALRM_DOM                          */
    __IOM uint32_t alrm_mth_isr : 1;          /*!< [13..13] Indicate MTH timer value match ALRM_MTH                          */
    __IOM uint32_t alrm_yrs_isr : 1;          /*!< [14..14] Indicate Year timer value match ALRM_YRS                         */
    __IOM uint32_t alrm_doy_isr : 1;          /*!< [15..15] Indicate DOY timer value match ALRM_DOY                          */
    __IOM uint32_t alrm_isr   : 1;            /*!< [16..16] Indicate ALL timer value match ALRM value                        */
  } b;                                        /*!< bit fields for aon_rtc_isr */
} aon_rtc_isr_t, *paon_rtc_isr_t;

/** @} */ /* End of group ls_hal_aon_reg */
/// @endcond /* End of condition DOXYGEN_GENERAL_REG_TYPE || DOXYGEN_AON_REG_TYPE */


#ifdef  __cplusplus
}
#endif

#endif    // end of #ifndef _RTL8195BLP_AON_AON_TYPE_H_

