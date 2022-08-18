/**************************************************************************//**
 * @file      rtl8195blp_hs_syson_type.h
 * @brief
 * @version   V1.00
 * @date      2019-5-22 18:11:46
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

#ifndef _RTL8195BLP_SYSON_HS_SYSON_TYPE_H_
#define _RTL8195BLP_SYSON_HS_SYSON_TYPE_H_

#ifdef  __cplusplus
extern "C"
{
#endif

/// @cond DOXYGEN_GENERAL_REG_TYPE || DOXYGEN_SYSON_REG_TYPE

/**
 * @addtogroup ls_hal_hs_syson_reg HS_SYSON Registers.
 * @ingroup ls_hal_syson
 * @{
 */

/**
  \brief Union type to access hs_syson_sys_pwr_ctrl (@ 0x00000000).
*/
typedef union {
  __IOM uint16_t w;                           /*!< (@ 0x00000000) System Power Control Register                              */
  
  struct {
    __IOM uint16_t soc_spc_en : 1;            /*!< [0..0] 1:enable HS SOC domain small power cut                             */
    __IOM uint16_t soc_lpc_en : 1;            /*!< [1..1] 1:enable HS SOC domain large power cut                             */
    __IOM uint16_t video_spc_en : 1;          /*!< [2..2] 1:enable video domain small power cut                              */
    __IOM uint16_t video_lpc_en : 1;          /*!< [3..3] 1:enable video domain large power cut                              */
    __IOM uint16_t wlon_spc_en : 1;           /*!< [4..4] 1:enable WLON domain small power cut                               */
    __IOM uint16_t wlon_lpc_en : 1;           /*!< [5..5] 1:enable WLON domain large power cut                               */
  } b;                                        /*!< bit fields for hs_syson_sys_pwr_ctrl */
} hs_syson_sys_pwr_ctrl_t, *phs_syson_sys_pwr_ctrl_t;

/**
  \brief Union type to access hs_syson_sys_iso_ctrl (@ 0x00000002).
*/
typedef union {
  __IOM uint16_t w;                           /*!< (@ 0x00000002) System Isolation Control Register                          */
  
  struct {
    __IOM uint16_t sys_iso_hssoc : 1;         /*!< [0..0] 1: isolation HS SoC to HS ON domain; 0: disable isolation          */
    __IOM uint16_t sys_iso_vdo : 1;           /*!< [1..1] 1: isolation Vedio to HS on domain; 0: disable isolation           */
    __IOM uint16_t sys_iso_wl : 1;            /*!< [2..2] 1: isolation WLON to HS on domain; 0: disable isolation            */
  } b;                                        /*!< bit fields for hs_syson_sys_iso_ctrl */
} hs_syson_sys_iso_ctrl_t, *phs_syson_sys_iso_ctrl_t;

/**
  \brief Union type to access hs_syson_hs_clk_ctrl (@ 0x00000004).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000004) HS System Clock Control Register                           */
  
  struct {
    __IOM uint32_t clk_eeldr_clk : 1;         /*!< [0..0] 1: enable EE Loader clock; 0: disable EE loader                    */
    __IM  uint32_t            : 1;
    __IOM uint32_t tm9_clk_en : 1;            /*!< [2..2] 1: enable TM9 clock ; 0: reset                                     */
    __IOM uint32_t platform_clk_en : 1;       /*!< [3..3] 1: enable HS platform clock ;                                      */
    __IOM uint32_t vendor_clk_en : 1;         /*!< [4..4] 1: enable HS Vendor clock ;                                        */
    __IOM uint32_t dram_sce_clk_en : 1;       /*!< [5..5] 1: Enable DDR SCE CLK                                              */
    __IOM uint32_t flash_sce_clk_en : 1;      /*!< [6..6] 1: Enable flash SCE CLK                                            */
  } b;                                        /*!< bit fields for hs_syson_hs_clk_ctrl */
} hs_syson_hs_clk_ctrl_t, *phs_syson_hs_clk_ctrl_t;

/**
  \brief Union type to access hs_syson_sys_func_en (@ 0x00000008).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000008) HS System Function Enable Control Register                 */
  
  struct {
    __IOM uint32_t hs_fen_eeldr : 1;          /*!< [0..0] 1: enable EE Loader; 0: disable EE loader                          */
    __IM  uint32_t            : 1;
    __IOM uint32_t tm9_en     : 1;            /*!< [2..2] 1: enable TM9 ; 0: reset                                           */
    __IOM uint32_t platform_en : 1;           /*!< [3..3] 1: enable platform                                                 */
    __IOM uint32_t vendor_en  : 1;            /*!< [4..4] 1: enable vendor                                                   */
    __IOM uint32_t dram_sce_en : 1;           /*!< [5..5] 1: Enable DDR SCE                                                  */
    __IOM uint32_t flash_sce_en : 1;          /*!< [6..6] 1: Enable flash SCE                                                */
    __IM  uint32_t            : 9;
    __IOM uint32_t hs_soc_en  : 1;            /*!< [16..16] 1: enable HS SOC domain                                          */
    __IOM uint32_t hs_video_en : 1;           /*!< [17..17] 1: enable video domain                                           */
  } b;                                        /*!< bit fields for hs_syson_sys_func_en */
} hs_syson_sys_func_en_t, *phs_syson_sys_func_en_t;

/**
  \brief Union type to access hs_syson_sys_clk_ctrl1 (@ 0x00000014).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000014) System Clock Control Register1                             */
  
  struct {
    __IOM uint32_t syspll_cksl : 1;           /*!< [0..0] divider PLL clock source selection: 0: 300MHz; 1: 200Mhz           */
    __IM  uint32_t            : 3;
    __IOM uint32_t syspll_dvsl : 4;           /*!< [7..4] PLL clock divider value selection                                  */
    __IOM uint32_t sys_cksl   : 1;            /*!< [8..8] system clock source selection 1: PLL divider out 0: 4M             */
    __IOM uint32_t sys_dven   : 1;            /*!< [9..9] system clock divider enable 1: multiply 0.5 0: bypass              */
  } b;                                        /*!< bit fields for hs_syson_sys_clk_ctrl1 */
} hs_syson_sys_clk_ctrl1_t, *phs_syson_sys_clk_ctrl1_t;

/**
  \brief Union type to access hs_syson_sys_boot_ctrl (@ 0x00000020).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000020) System Boot Control Register                               */
  
  struct {
    __IOM uint32_t skip_ls_img_load : 1;      /*!< [0..0] If this bit is set, the HS boot loader will skip the
                                                   LS image loading. This bit is valid only when ls_rom_rdy=1.
                                                   1: skip to load LS image.                                                 */
    __IOM uint32_t ls_rom_rdy : 1;            /*!< [1..1] Indicate the LS ROM code initial done. 1: LS ROM code
                                                   ready.                                                                    */
    __IOM uint32_t debuger_pin_en : 1;        /*!< [2..2] 1: Enable debuger mux                                              */
    __IOM uint32_t debuger_mode_sel : 2;      /*!< [4..3] 00: SWD; 01: JTAG; 10: JTAG chain mode                             */
    __IOM uint32_t debuger_pin_sel : 1;       /*!< [5..5] LS CPU backup the debugger pin configuration here, for
                                                   restoring after resume from WDT or power saving. Debuger
                                                   is muxed on 00: GPIOE_0~4; 01: GPIOC_2~6                                  */
    __IM  uint32_t            : 7;
    __IOM uint32_t lp_aon_wsts_gpio : 1;      /*!< [13..13] Indicate AON GPIO A13 Wakeup event                               */
    __IOM uint32_t lp_aon_wsts_systim : 1;    /*!< [14..14] Indicate AON SYSTimer Wakeup event                               */
    __IOM uint32_t lp_aon_wsts_rtc : 1;       /*!< [15..15] Indicate RTC Wakeup event                                        */
    __IOM uint32_t lp_aon_wsts_adp : 1;       /*!< [16..16] Indicate Adapter Wakeup event                                    */
    __IOM uint32_t lp_wsts_systim : 1;        /*!< [17..17] Indocate SYSTimer Wakeup event                                   */
    __IOM uint32_t lp_wsts_gtim : 1;          /*!< [18..18] Indicate GTimer0~7 Wakeup system event                           */
    __IOM uint32_t lp_wsts_swrd_ocp : 1;      /*!< [19..19] Indicate DCORE SWR OCP event                                     */
    __IOM uint32_t lp_wsts_bod : 1;           /*!< [20..20] Indicate BOD Wakeup event                                        */
    __IOM uint32_t lp_wsts_gpio : 1;          /*!< [21..21] Indicate GPIO Wakeup event                                       */
    __IOM uint32_t lp_wsts_pwm : 1;           /*!< [22..22] Indicate PWM Wakeup event                                        */
    __IOM uint32_t lp_wsts_wlan : 1;          /*!< [23..23] Indicate WLAN Wakeup event                                       */
    __IOM uint32_t lp_wsts_uart : 1;          /*!< [24..24] Indicate UART Wakeup event                                       */
    __IOM uint32_t lp_wsts_i2c : 1;           /*!< [25..25] Indicate I2C Wakeup event                                        */
    __IOM uint32_t lp_wsts_adc : 1;           /*!< [26..26] Indicate ADC Wakeup event                                        */
    __IOM uint32_t lp_wsts_comp : 1;          /*!< [27..27] Indicate Comparetor Wakeup event                                 */
    __IOM uint32_t lp_wsts_sgpio : 1;         /*!< [28..28] Indicate SGPIO Wakeup event                                      */
    __IOM uint32_t lp_wsts_aon : 1;           /*!< [29..29] Indicate AON Wakeup event (0x128)                                */
    __IOM uint32_t lp_wsts_hs : 1;            /*!< [30..30] Indicate HS Wakeup event                                         */
  } b;                                        /*!< bit fields for hs_syson_sys_boot_ctrl */
} hs_syson_sys_boot_ctrl_t, *phs_syson_sys_boot_ctrl_t;

/**
  \brief Union type to access hs_syson_hs_pll_sys_ctrl0 (@ 0x00000050).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000050) HS PLL Control Register0                                   */
  
  struct {
    __IM  uint32_t            : 3;
    __IOM uint32_t pll_sys_div_sel : 3;       /*!< [5..3] output divider selection. Default=000 000=/1, 100=/4,
                                                   110=/8, 111=/16                                                           */
    __IOM uint32_t pll_sys_ps_en : 1;         /*!< [6..6] phase selector enable                                              */
    __IOM uint32_t pll_sys_div2_en : 1;       /*!< [7..7] output clk div 2 enable                                            */
    __IOM uint32_t pll_sys_clk_en : 1;        /*!< [8..8] output clk enable                                                  */
    __IOM uint32_t pll_sys_fref_edge_sel : 1; /*!< [9..9] 0:fref,1:frefb                                                     */
    __IOM uint32_t pll_sys_c3_set : 2;        /*!< [11..10] Cp selection. Default=5p 00: Cp=3p, 01: Cp=4p, 10:
                                                   Cp=5p, 11: Cp=6p                                                          */
    __IOM uint32_t pll_sys_r3_sel : 3;        /*!< [14..12] R3 selection. Default=1k 000: R3=0k, 001: R3=0.5k,
                                                   010: R3=1k, 011: R3=1.5k, 100: R3=2k, 101: R3=2.5k, 110:
                                                   R3=3k, 111: R3=3.5k;                                                      */
    __IOM uint32_t pll_sys_cs_sel : 2;        /*!< [16..15] Cs selection. Default=50p 00: Cs=30p, 01: Cs=40p, 10:
                                                   Cs=50p, 11: Cs=60p                                                        */
    __IOM uint32_t pll_sys_rs_sel : 3;        /*!< [19..17] Rs selection. Default=14k 000: Rs=2k, 001: Rs=4k, 010:
                                                   Rs=6k, 011: Rs=8k, 100: Rs=10k, 101: Rs=12k, 110: Rs=14k,
                                                   111: Rs=16k;                                                              */
    __IOM uint32_t pll_sys_cp_sel : 2;        /*!< [21..20] Cp selection. Default=3p 00: Cp=3p, 01: Cp=4p, 10:
                                                   Cp=5p, 11: Cp=6p                                                          */
    __IOM uint32_t pll_sys_ps_sel : 3;        /*!< [24..22] PLL power state selection                                        */
    __IOM uint32_t pll_sys_wdg_en : 1;        /*!< [25..25] 0: watch dog on ,1: watch dog off                                */
    __IOM uint32_t pll_sys_cpc_sel : 3;       /*!< [28..26] charge pump current selection . Default=5u CP current
                                                   select : 000: Icp=5uA, 001: Icp=10uA, 010: Icp=15uA, 011:
                                                   Icp=20uA; 100:Icp=25uA, 101: Icp=30uA, 110: Icp=35uA, 111:
                                                   Icp=40uA;                                                                 */
    __IOM uint32_t pll_sys_en : 1;            /*!< [29..29] (need pwl signal) 0->1                                           */
    __IOM uint32_t pll_sys_div_en : 1;        /*!< [30..30] input divider enable (need pwl signal) 0->1                      */
    __IOM uint32_t pll_sys_powcut_en : 1;     /*!< [31..31] erc enable.                                                      */
  } b;                                        /*!< bit fields for hs_syson_hs_pll_sys_ctrl0 */
} hs_syson_hs_pll_sys_ctrl0_t, *phs_syson_hs_pll_sys_ctrl0_t;

/**
  \brief Union type to access hs_syson_hs_pll_sys_ctrl1 (@ 0x00000054).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000054) HS PLL Control Register1                                   */
  
  struct {
    __IM  uint32_t            : 5;
    __IOM uint32_t pll_sys_divn_sdm : 6;      /*!< [10..5] pll_sys_divn_sdm                                                  */
    __IOM uint32_t pll_sys_bb_dbg_sel_afe_sdm : 4;/*!< [14..11] pll_sys_bb_dbg_sel_afe_sdm                                   */
    __IOM uint32_t pll_sys_trig_rreq_en : 1;  /*!< [15..15] freq. step up or step down enable                                */
    __IOM uint32_t pll_sys_step_freq_sel : 4; /*!< [19..16] step size selection for switching freq.                          */
    __IOM uint32_t pll_sys_tbase_freq_sel : 4;/*!< [23..20] for output clk step up or step down                              */
    __IOM uint32_t pll_sys_freq_sel : 4;      /*!< [27..24] output clk selection, Default=300MHz                             */
    __IOM uint32_t pll_sys_xtal_sel : 4;      /*!< [31..28] xtal selection, Default=40MHz. 0000: 40MHz, 0001: 25MHz,
                                                   0010: 13MHz, 0011: 19.2MHz 0100: 20MHz, 0101: 26MHz, 0110:
                                                   38.4MHz, 0111: 17.664MHz 1000: 16MHz, 1001: 14.138MHz,
                                                   1010: 12MHz, 1011: 52MHz, 1100: 48MHz, 1101: 27MHz, 1110:
                                                   24MHz, 1111: none                                                         */
  } b;                                        /*!< bit fields for hs_syson_hs_pll_sys_ctrl1 */
} hs_syson_hs_pll_sys_ctrl1_t, *phs_syson_hs_pll_sys_ctrl1_t;

/**
  \brief Union type to access hs_syson_hs_pll_sys_ctrl3 (@ 0x0000005C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000005C) HS PLL Control Register3                                   */
  
  struct {
    __IOM uint32_t pll_sys_200m_div_en : 1;   /*!< [0..0] 1 : enable 200M DIV                                                */
    __IOM uint32_t pll_sys_200m_en : 1;       /*!< [1..1] 1 : enable 200M clk                                                */
    __IM  uint32_t            : 13;
    __IOM uint32_t pll_sys_sdm_order_sel : 1; /*!< [15..15] SDM order: 0:2nd order, 1:3rd order                              */
    __IOM uint32_t pll_sys_sdm_fon : 3;       /*!< [18..16] N code, feedback divider number 1 for 1/8                        */
    __IOM uint32_t pll_sys_sdm_fof : 13;      /*!< [31..19] F code, feedback divider number 1for 1/8*1/2^13                  */
  } b;                                        /*!< bit fields for hs_syson_hs_pll_sys_ctrl3 */
} hs_syson_hs_pll_sys_ctrl3_t, *phs_syson_hs_pll_sys_ctrl3_t;

/**
  \brief Union type to access hs_syson_hs_pll_peri_ctrl0 (@ 0x00000070).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000070) HS PLL Peripheral Control Register0                        */
  
  struct {
    __IM  uint32_t            : 3;
    __IOM uint32_t pll_peri_div_sel : 3;      /*!< [5..3] output divider selection. Default=000 000=/1, 100=/4,
                                                   110=/8, 111=/16                                                           */
    __IOM uint32_t pll_peri_ps_en : 1;        /*!< [6..6] phase selector enable                                              */
    __IOM uint32_t pll_peri_div2_en : 1;      /*!< [7..7] output clk div 2 enable                                            */
    __IOM uint32_t pll_peri_clk_en : 1;       /*!< [8..8] output clk enable                                                  */
    __IOM uint32_t pll_peri_fref_edge_sel : 1;/*!< [9..9] 0:fref,1:frefb                                                     */
    __IOM uint32_t pll_peri_c3_set : 2;       /*!< [11..10] Cp selection. Default=5p 00: Cp=3p, 01: Cp=4p, 10:
                                                   Cp=5p, 11: Cp=6p                                                          */
    __IOM uint32_t pll_peri_r3_sel : 3;       /*!< [14..12] R3 selection. Default=1k 000: R3=0k, 001: R3=0.5k,
                                                   010: R3=1k, 011: R3=1.5k, 100: R3=2k, 101: R3=2.5k, 110:
                                                   R3=3k, 111: R3=3.5k;                                                      */
    __IOM uint32_t pll_peri_cs_sel : 2;       /*!< [16..15] Cs selection. Default=50p 00: Cs=30p, 01: Cs=40p, 10:
                                                   Cs=50p, 11: Cs=60p                                                        */
    __IOM uint32_t pll_peri_rs_sel : 3;       /*!< [19..17] Rs selection. Default=14k 000: Rs=2k, 001: Rs=4k, 010:
                                                   Rs=6k, 011: Rs=8k, 100: Rs=10k, 101: Rs=12k, 110: Rs=14k,
                                                   111: Rs=16k;                                                              */
    __IOM uint32_t pll_peri_cp_sel : 2;       /*!< [21..20] Cp selection. Default=3p 00: Cp=3p, 01: Cp=4p, 10:
                                                   Cp=5p, 11: Cp=6p                                                          */
    __IOM uint32_t pll_peris_ps_sel : 3;      /*!< [24..22] pll_peris_ps_sel                                                 */
    __IOM uint32_t pll_peri_wdg_en : 1;       /*!< [25..25] 0: watch dog on ,1: watch dog off                                */
    __IOM uint32_t pll_peri_cpc_sel : 3;      /*!< [28..26] charge pump current selection . Default=5u CP current
                                                   select : 000: Icp=5uA, 001: Icp=10uA, 010: Icp=15uA, 011:
                                                   Icp=20uA; 100:Icp=25uA, 101: Icp=30uA, 110: Icp=35uA, 111:
                                                   Icp=40uA;                                                                 */
    __IOM uint32_t pll_peri_en : 1;           /*!< [29..29] (need pwl signal) 0->1                                           */
    __IOM uint32_t pll_peri_div_en : 1;       /*!< [30..30] input divider enable (need pwl signal) 0->1                      */
    __IOM uint32_t pll_peri_powcut_en : 1;    /*!< [31..31] erc enable.                                                      */
  } b;                                        /*!< bit fields for hs_syson_hs_pll_peri_ctrl0 */
} hs_syson_hs_pll_peri_ctrl0_t, *phs_syson_hs_pll_peri_ctrl0_t;

/**
  \brief Union type to access hs_syson_hs_pll_peri_ctrl1 (@ 0x00000074).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000074) HS PLL Peripheral Control Register1                        */
  
  struct {
    __IM  uint32_t            : 5;
    __IOM uint32_t pll_peri_divn_sdm : 6;     /*!< [10..5] pll_peri_divn_sdm                                                 */
    __IOM uint32_t pll_peri_bb_dbg_sel_afe_sdm : 4;/*!< [14..11] pll_peri_bb_dbg_sel_afe_sdm                                 */
    __IOM uint32_t pll_peri_trig_rreq_en : 1; /*!< [15..15] freq. step up or step down enable                                */
    __IOM uint32_t pll_peri_step_freq_sel : 4;/*!< [19..16] step size selection for switching freq.                          */
    __IOM uint32_t pll_peri_tbase_freq_sel : 4;/*!< [23..20] for output clk step up or step down                             */
    __IOM uint32_t pll_peri_freq_sel : 4;     /*!< [27..24] output clk selection, Default=80MHz                              */
    __IOM uint32_t pll_peri_xtal_sel : 4;     /*!< [31..28] xtal selection, Default=40MHz. 0000: 40MHz, 0001: 25MHz,
                                                   0010: 13MHz, 0011: 19.2MHz, 0100: 20MHz, 0101: 26MHz, 0110:
                                                   38.4MHz, 0111: 17.664MHz, 1000: 16MHz, 1001: 14.138MHz,
                                                   1010: 12MHz, 1011: 52MHz, 1100: 48MHz, 1101: 27MHz, 1110:
                                                   24MHz, 1111: none                                                         */
  } b;                                        /*!< bit fields for hs_syson_hs_pll_peri_ctrl1 */
} hs_syson_hs_pll_peri_ctrl1_t, *phs_syson_hs_pll_peri_ctrl1_t;

/**
  \brief Union type to access hs_syson_hs_pll_test (@ 0x000000A0).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000A0) HS PLL Test Register                                       */
  
  struct {
    __IOM uint32_t pll_test_agpio_en : 1;     /*!< [0..0] AGPIO enable                                                       */
    __IOM uint32_t pll_test_agpio_output_en : 1;/*!< [1..1] AGPIO output enable                                              */
    __IOM uint32_t pll_test_agpio_dri_sel : 2;/*!< [3..2] AGPIO driving sel                                                  */
    __IOM uint32_t pll_test_clk_sel : 4;      /*!< [7..4] ckmon clk sel: 1111:CK_400M_ISP; 1110:READY_400M; 1101:CK_ISPS;
                                                   1100:READY_ISPS; 1011:CK_300M_SYS; 1010:READY_300M; 1001:CK_240M_ENC;
                                                   1000:READY_240M_ENC; 0111:CK_80M_PERI; 0110:READY_80M_PERI;
                                                   0101:CK_98P304M_I2S; 0100:CK_24P576M_I2S 0011:READY_I2S;
                                                   0010:CK_45P158M_PCM; 0001:READY_45P158M_PCM; 0000:TL                      */
    __IOM uint32_t pll_test_clk_mon_en : 1;   /*!< [8..8] ckmon enable                                                       */
    __IOM uint32_t xtal_clk_sel : 1;          /*!< [9..9] xtal clk from 0 special route 1 APR                                */
    __IOM uint32_t xtal_pwr_iso : 1;          /*!< [10..10] xtal power isolation                                             */
    __IM  uint32_t            : 13;
    __IOM uint32_t pll_isp_rdy : 1;           /*!< [24..24] ISP PLL ready                                                    */
    __IOM uint32_t pll_isps_rdy : 1;          /*!< [25..25] ISPS PLL ready                                                   */
    __IOM uint32_t pll_sys_rdy : 1;           /*!< [26..26] SYS PLL ready                                                    */
    __IOM uint32_t pll_enc_rdy : 1;           /*!< [27..27] Encoder PLL ready                                                */
    __IOM uint32_t pll_peri_rdy : 1;          /*!< [28..28] PERI PLL ready                                                   */
    __IOM uint32_t pll_i2s_rdy : 1;           /*!< [29..29] I2S PLL ready                                                    */
    __IOM uint32_t pll_pcm_rdy : 1;           /*!< [30..30] PCM PLL ready                                                    */
  } b;                                        /*!< bit fields for hs_syson_hs_pll_test */
} hs_syson_hs_pll_test_t, *phs_syson_hs_pll_test_t;

/**
  \brief Union type to access hs_syson_hs_efuse_ctrl0 (@ 0x000000A4).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000A4) HS EFuse Control Register0                                 */
  
  struct {
    __IOM uint32_t efuse_autoload_sus : 1;    /*!< [0..0] 1: Autoload successful 0: Autoload fail                            */
    __IOM uint32_t efuse_ldall : 1;           /*!< [1..1] 1: SW enable HWSM to autoload excluding Efuse 0x00~ 0x31           */
    __IOM uint32_t efuse_sys_aldn : 1;        /*!< [2..2] 1: SYS Config autoload done; 0: autoload not ready                 */
    __IOM uint32_t efuse_sdio_aldn : 1;       /*!< [3..3] 1: SDIO Config autoload done; 0: autoload not ready                */
    __IM  uint32_t            : 3;
    __IOM uint32_t hs_efldr_clk_sel : 1;      /*!< [7..7] 1: PLL CLK; 0: 4M                                                  */
    __IOM uint32_t efuse_unlock : 8;          /*!< [15..8] 1: unlock efuse                                                   */
    __IOM uint32_t ldoe25_en  : 1;            /*!< [16..16] Power on LDOE25                                                  */
  } b;                                        /*!< bit fields for hs_syson_hs_efuse_ctrl0 */
} hs_syson_hs_efuse_ctrl0_t, *phs_syson_hs_efuse_ctrl0_t;

/**
  \brief Union type to access hs_syson_hs_efuse_ctrl1 (@ 0x000000A8).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000A8) HS EFuse Control Register1                                 */
  
  struct {
    __IOM uint32_t sys_ef_data : 8;           /*!< [7..0] Access Data                                                        */
    __IOM uint32_t sys_ef_addr : 10;          /*!< [17..8] Access Address                                                    */
    __IOM uint32_t sys_ef_alden : 1;          /*!< [18..18] Autoload Enable                                                  */
    __IOM uint32_t sys_ef_pdwn : 1;           /*!< [19..19] Efuse power down                                                 */
    __IOM uint32_t sys_ef_pgts : 4;           /*!< [23..20] Programming setup time. In the unit of cycle time.(125ns)        */
    __IOM uint32_t sys_ef_rdt : 4;            /*!< [27..24] E-fuse read time: in the unit of cycle time                      */
    __IOM uint32_t sys_ef_pgpd : 3;           /*!< [30..28] E-fuse program time: 000: 5000ns, 001: 5100ns, 010:
                                                   5200ns, 011: 5900ns 100: 6500ns, 101: 7000ns, 110: 7500ns,
                                                   111: 8000ns                                                               */
    __IOM uint32_t sys_ef_rwflag : 1;         /*!< [31..31] Write 1 for Program; Write 0 for Read Access                     */
  } b;                                        /*!< bit fields for hs_syson_hs_efuse_ctrl1 */
} hs_syson_hs_efuse_ctrl1_t, *phs_syson_hs_efuse_ctrl1_t;

/**
  \brief Union type to access hs_syson_hs_ad_iso (@ 0x0000016C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000016C) HS AD Power Isolation Control Register                     */
  
  struct {
    __IOM uint32_t aux_ad0_iso : 1;           /*!< [0..0] Aux AD0 Power Isolation                                            */
    __IOM uint32_t aux_ad1_iso : 1;           /*!< [1..1] Aux AD1 Power Isolation                                            */
    __IOM uint32_t aux_ad2_iso : 1;           /*!< [2..2] Aux AD2 Power Isolation                                            */
    __IOM uint32_t aux_ad3_iso : 1;           /*!< [3..3] Aux AD3 Power Isolation                                            */
    __IOM uint32_t aux_ad4_iso : 1;           /*!< [4..4] Aux AD4 Power Isolation                                            */
    __IOM uint32_t aux_ad5_iso : 1;           /*!< [5..5] Aux AD5 Power Isolation                                            */
    __IOM uint32_t aux_ad6_iso : 1;           /*!< [6..6] Aux AD6 Power Isolation                                            */
    __IOM uint32_t aux_ad7_iso : 1;           /*!< [7..7] Aux AD7 Power Isolation                                            */
  } b;                                        /*!< bit fields for hs_syson_hs_ad_iso */
} hs_syson_hs_ad_iso_t, *phs_syson_hs_ad_iso_t;

/**
  \brief Union type to access hs_syson_hs_flash_ctrl (@ 0x00000210).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000210) HS Flash Control Register                                  */
  
  struct {
    __IOM uint32_t hs_flash_en : 1;           /*!< [0..0] 1: Enable FLASH                                                    */
    __IOM uint32_t hs_flash_clk_en : 1;       /*!< [1..1] 1: Enable FLASH CLK                                                */
    __IM  uint32_t            : 2;
    __IM  uint32_t hs_flash_init_ok : 1;      /*!< [4..4] BOOT_finish                                                        */
    __IOM uint32_t hs_flash_speedup : 1;      /*!< [5..5] spic_speed_up                                                      */
    __IM  uint32_t            : 2;
    __IOM uint32_t hs_flash_mux_en : 1;       /*!< [8..8] 1: Enable FLASH MUX                                                */
    __IOM uint32_t hs_flash_mode_sel : 1;     /*!< [9..9] 0: QPI Mode; 1: OCT mode (GPIOF_0~10)                              */
    __IOM uint32_t hs_flash_quad_bit_mux_en : 1;/*!< [10..10] QPI mode quad bit mux enable                                   */
    __IOM uint32_t hs_flash_qpi_mux_sel : 1;  /*!< [11..11] 0: GPIOF_0,3,4,7,9,10; 1: GPIOB_0~5                              */
  } b;                                        /*!< bit fields for hs_syson_hs_flash_ctrl */
} hs_syson_hs_flash_ctrl_t, *phs_syson_hs_flash_ctrl_t;

/**
  \brief Union type to access hs_syson_hs_flash_phy_ctrl0 (@ 0x00000214).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000214) HS Flash PHY Control Register 0                            */
  
  struct {
    __IOM uint32_t hs_flash_phy_en : 1;       /*!< [0..0] Enable rx data, must enable first.                                 */
    __IOM uint32_t hs_flash_phy_output_phase_en : 1;/*!< [1..1] Tx Coase tuning for DTR. Delay 0.5 spic_clk period of
                                                   sclk                                                                      */
    __IOM uint32_t hs_flash_phy_merge_phase_en : 1;/*!< [2..2] Rx tuning for DTR. If upper lane & lower lane data are
                                                   reversed, set this bit to recover. 0: posedge rx data first
                                                   1: negedge rx data first                                                  */
    __IOM uint32_t hs_flash_phy_dqs_en : 1;   /*!< [3..3] Enable DQS to fetch rx data. Enable Rx tuning via DQS
                                                   for offset 218 bit 8 to bit23 and offset 214 bit 16 to
                                                   bit 19                                                                    */
    __IOM uint32_t hs_flash_phy_dqs_ddr_en : 1;/*!< [4..4] Enable DQS to fetch double data rate rx data. Must enable
                                                   before using DTR mode. Enable Rx tuning for offset 218
                                                   bit 8 to bit23 and offset 214 bit 16 to bit 19                            */
    __IOM uint32_t hs_flash_phy_dly_en : 2;   /*!< [6..5] Rx tuning when the deviation of high lane and low lane
                                                   is up to 1 cycle due to the process. 0 : delay lower lane
                                                   a spic_clk period 1 : delay upper lane a spic_clk period                  */
    __IM  uint32_t            : 9;
    __IOM uint32_t hs_flash_phy_fetch_phase : 4;/*!< [19..16] Rx coarse tune.bit 16 : delay 0.5 spic_clk period to
                                                   fetch lower lane databit 17 : delay 0.5 spic_clk period
                                                   to fetch upper lane data bit 18 : delay 0.5 spic_clk period
                                                   to sync lower lane data to spic bit 19 : delay 0.5 spic_clk
                                                   period to sync upper lane data to spic bit 16 = bit 17,
                                                   bit 18 = bit 19.                                                          */
  } b;                                        /*!< bit fields for hs_syson_hs_flash_phy_ctrl0 */
} hs_syson_hs_flash_phy_ctrl0_t, *phs_syson_hs_flash_phy_ctrl0_t;

/**
  \brief Union type to access hs_syson_hs_flash_phy_ctrl1 (@ 0x00000218).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000218) HS Flash PHY Control Register 1                            */
  
  struct {
    __IOM uint32_t hs_flash_phy_output_dly_sel : 8;/*!< [7..0] Tx fine tung for DTR. Select delay level of sclk delay
                                                   line                                                                      */
    __IOM uint32_t hs_flash_phy_dqsl_dly_sel : 8;/*!< [15..8] select delay level of DQS on the lower lane. Rx fine
                                                   tune for 4IO and first 4IO of 8IO. If offset 214 bit 3
                                                   is enabled, the delay is based on DQS, otherwise, the delay
                                                   is based on sclk                                                          */
    __IOM uint32_t hs_flash_phy_dqsu_dly_sel : 8;/*!< [23..16] select delay level of DQS on the upper lane. Rx fine
                                                   tune for last 4IO of 8IO. If offset 214 bit 3 is enabled,
                                                   the delay is based on DQS, otherwise, the delay is based
                                                   on sclk                                                                   */
  } b;                                        /*!< bit fields for hs_syson_hs_flash_phy_ctrl1 */
} hs_syson_hs_flash_phy_ctrl1_t, *phs_syson_hs_flash_phy_ctrl1_t;

/**
  \brief Union type to access hs_syson_hs_debugger_ctrl (@ 0x00000224).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000224) HS Debugger Control Register                               */
  
  struct {
    __IOM uint32_t debuger_pin_en : 1;        /*!< [0..0] 1: Enable debuger mux                                              */
    __IOM uint32_t debuger_mode_sel : 2;      /*!< [2..1] 00: SWD; 01: JTAG 10: JTAG chain mode                              */
    __IOM uint32_t debuger_pin_sel : 1;       /*!< [3..3] debuger is muxed on 00: GPIOE_0~4 01: GPIOC_2~6                    */
  } b;                                        /*!< bit fields for hs_syson_hs_debugger_ctrl */
} hs_syson_hs_debugger_ctrl_t, *phs_syson_hs_debugger_ctrl_t;

/**
  \brief Union type to access hs_syson_hs_iopad_pwr_ctrl (@ 0x00000280).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000280) HS IO Pad Power Control Register                           */
  
  struct {
    __IOM uint32_t gpiob_padpwd : 1;          /*!< [0..0] 1: power down GPIO pad group B                                     */
    __IOM uint32_t gpioc_padpwd : 1;          /*!< [1..1] 1: power down GPIO pad group C                                     */
    __IOM uint32_t gpiod_padpwd : 1;          /*!< [2..2] 1: power down GPIO pad group D                                     */
    __IOM uint32_t gpioe_padpwd : 1;          /*!< [3..3] 1: power down GPIO pad group E                                     */
    __IOM uint32_t gpiof_padpwd : 1;          /*!< [4..4] 1: power down GPIO pad group F                                     */
    __IOM uint32_t gpiog_padpwd : 1;          /*!< [5..5] 1: power down GPIO pad group G                                     */
    __IOM uint32_t gpioh_padpwd : 1;          /*!< [6..6] 1: power down GPIO pad group H                                     */
    __IOM uint32_t gpioijk_padpwd : 1;        /*!< [7..7] 1: power down GPIO pad group IJK                                   */
  } b;                                        /*!< bit fields for hs_syson_hs_iopad_pwr_ctrl */
} hs_syson_hs_iopad_pwr_ctrl_t, *phs_syson_hs_iopad_pwr_ctrl_t;

/** @} */ /* End of group ls_hal_hs_syson_reg */
/// @endcond /* End of condition DOXYGEN_GENERAL_REG_TYPE || DOXYGEN_HS_SYSON_REG_TYPE */


#ifdef  __cplusplus
}
#endif

#endif    // end of #ifndef _RTL8195BLP_SYSON_HS_SYSON_TYPE_H_

