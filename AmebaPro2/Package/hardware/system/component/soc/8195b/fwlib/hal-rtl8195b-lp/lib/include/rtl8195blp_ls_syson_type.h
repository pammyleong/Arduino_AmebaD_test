/**************************************************************************//**
 * @file      rtl8195blp_ls_syson_type.h
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

#ifndef _RTL8195BLP_SYSON_LS_SYSON_TYPE_H_
#define _RTL8195BLP_SYSON_LS_SYSON_TYPE_H_

#ifdef  __cplusplus
extern "C"
{
#endif

/// @cond DOXYGEN_GENERAL_REG_TYPE || DOXYGEN_SYSON_REG_TYPE

/**
 * @addtogroup ls_hal_ls_syson_reg LS_SYSON Registers.
 * @ingroup ls_hal_syson
 * @{
 */

/**
  \brief Union type to access ls_syson_sys_pwr_ctrl (@ 0x00000000).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000000) System Power Control Register                              */
  
  struct {
    __IM  uint32_t            : 16;
    __IOM uint32_t sys_iso_lpsoc : 1;         /*!< [16..16] 1: isolation LP SoC to LP ON domain; 0: disable isolation        */
    __IOM uint32_t sys_iso_efuse : 1;         /*!< [17..17] 1: isolation LP EFUSE to LP ON domain; 0: disable isolation      */
    __IM  uint32_t            : 2;
    __IOM uint32_t sys_iso_hpon : 1;          /*!< [20..20] 1: isolation HPON to LPON                                        */
    __IM  uint32_t            : 3;
    __IOM uint32_t sys_iso_xtal : 1;          /*!< [24..24] 1: isolatino XTAL to LPON; 0: disable isolation                  */
  } b;                                        /*!< bit fields for ls_syson_sys_pwr_ctrl */
} ls_syson_sys_pwr_ctrl_t, *pls_syson_sys_pwr_ctrl_t;

/**
  \brief Union type to access ls_syson_sys_func_en (@ 0x00000008).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000008) System Function Enable Control Register                    */
  
  struct {
    __IM  uint32_t            : 1;
    __IOM uint32_t sys_fen_eeldr : 1;         /*!< [1..1] 1: enable EE Loader; 0: disable EE loader                          */
    __IOM uint32_t retmem_en  : 1;            /*!< [2..2] 1: enable retention memory                                         */
    __IOM uint32_t sys_platform_en : 1;       /*!< [3..3] 1: enable LP platform ; 0: reset                                   */
    __IOM uint32_t sys_km0_en : 1;            /*!< [4..4] 1: enable KM0, 0: reset                                            */
    __IOM uint32_t vendor_en  : 1;            /*!< [5..5] 1: enable Vendor, 0: reset                                         */
    __IM  uint32_t            : 3;
    __IOM uint32_t sys_mem_lpmc_sel : 1;      /*!< [9..9] select memory mode control source, 0: AON, 1: LS_SYSON             */
    __IM  uint32_t            : 6;
    __IOM uint32_t lp_soc_domain_en : 1;      /*!< [16..16] 1: enable LP SOC domain                                          */
    __IM  uint32_t            : 7;
    __IOM uint32_t sys_fen_sic_mst : 1;       /*!< [24..24] 1: enable SIC                                                    */
    __IOM uint32_t hs_access_en : 1;          /*!< [25..25] 1: enable LP access HS                                           */
    __IM  uint32_t            : 4;
    __IOM uint32_t sys_33macro_en : 1;        /*!< [30..30] 3.3v domain IP PWD_B                                             */
    __IOM uint32_t sys_amacro_en : 1;         /*!< [31..31] Analog IP PWD_B                                                  */
  } b;                                        /*!< bit fields for ls_syson_sys_func_en */
} ls_syson_sys_func_en_t, *pls_syson_sys_func_en_t;

/**
  \brief Union type to access ls_syson_hs_sys_func_en (@ 0x0000000C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000000C) HS System Function Enable Control Register                 */
  
  struct {
    __IOM uint32_t hs_func_en : 1;            /*!< [0..0] 1: enable HS Function ; 0: reset                                   */
    __IM  uint32_t            : 3;
    __IOM uint32_t hs_sysckgen_en : 1;        /*!< [4..4] HS system clock generator function enable                          */
  } b;                                        /*!< bit fields for ls_syson_hs_sys_func_en */
} ls_syson_hs_sys_func_en_t, *pls_syson_hs_sys_func_en_t;

/**
  \brief Union type to access ls_syson_sys_clk_ctrl0 (@ 0x00000010).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000010) System Clock Control Register0                             */
  
  struct {
    __IOM uint32_t bit_syson_ck_sysreg_en : 1;/*!< [0..0] 1: Enable SYSON register clock; 0: gated SYSON Register
                                                   clock                                                                     */
    __IOM uint32_t bit_syson_ck_eeldr_en : 1; /*!< [1..1] 1: enable EE LDR clock; 0: gated EE LDR clock                      */
    __IOM uint32_t bit_retmem_clk_en : 1;     /*!< [2..2] 1: enable retention memory clock                                   */
    __IOM uint32_t bit_platform_clk_en : 1;   /*!< [3..3] 1: enable platform clock                                           */
    __IOM uint32_t bit_km0_clk_en : 1;        /*!< [4..4] 1: enable KM0 clock                                                */
    __IOM uint32_t bit_vendor_clk_en : 1;     /*!< [5..5] 1: enable Vendor clock                                             */
    __IM  uint32_t            : 2;
    __IOM uint32_t bit_ls32k_src_sel : 1;     /*!< [8..8] 32K clock source selection: 0:128K; 1:Xtal                         */
  } b;                                        /*!< bit fields for ls_syson_sys_clk_ctrl0 */
} ls_syson_sys_clk_ctrl0_t, *pls_syson_sys_clk_ctrl0_t;

/**
  \brief Union type to access ls_syson_sys_clk_sts (@ 0x00000014).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000014) System status Register                                     */
  
  struct {
    __IM  uint32_t xtal32k_rdy : 1;           /*!< [0..0] 1: Xtal_32k ready                                                  */
    __IM  uint32_t osc128k_rdy : 1;           /*!< [1..1] 1: OSC_128K ready                                                  */
    __IM  uint32_t            : 6;
    __IM  uint32_t bg_dcore_rdy : 1;          /*!< [8..8] 1: Dcore BG ready                                                  */
  } b;                                        /*!< bit fields for ls_syson_sys_clk_sts */
} ls_syson_sys_clk_sts_t, *pls_syson_sys_clk_sts_t;

/**
  \brief Union type to access ls_syson_efuse_boot_cfg1 (@ 0x00000030).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000030) Efuse Boot Configuration1 Register                         */
  
  struct {
    __IOM uint32_t dbg_port_cfg : 2;          /*!< [1..0] debuger port configuration: 00: HS:SWD; LS: SWD 01: HS:
                                                   J-TAG Chain mode, LS: J-TAG Chain mode 10: HS: J-TAG, LS:
                                                   SWD 11: Reserved                                                          */
    __IOM uint32_t dbg_port_pin_sel : 1;      /*!< [2..2] debugger port pin selection: 0:S0, 1:S1                            */
    __IM  uint32_t            : 3;
    __IOM uint32_t dbg_uart_sel : 1;          /*!< [6..6] debugging UART port selection                                      */
    __IOM uint32_t dbg_msg_ctrl : 1;          /*!< [7..7] debugging message on/off control                                   */
  } b;                                        /*!< bit fields for ls_syson_efuse_boot_cfg1 */
} ls_syson_efuse_boot_cfg1_t, *pls_syson_efuse_boot_cfg1_t;

/**
  \brief Union type to access ls_syson_lp_swr_ctrl0 (@ 0x00000040).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000040) LP Switch Regulator Control Register0                      */
  
  struct {
    __IOM uint32_t regu_bg_en : 1;            /*!< [0..0] 1: enable regu BG                                                  */
    __IOM uint32_t swr_sldo_en : 1;           /*!< [1..1] 1: enable SWR SLDO                                                 */
    __IOM uint32_t swr_m_en   : 1;            /*!< [2..2] 1: enable SWR mode                                                 */
    __IOM uint32_t ldo_m_en   : 1;            /*!< [3..3] 1: enable LDO mode                                                 */
    __IOM uint32_t ldod_enb   : 1;            /*!< [4..4] 1: disable LDO diode                                               */
    __IM  uint32_t            : 3;
    __IOM uint32_t vol_l1_sel : 4;            /*!< [11..8] 0000: 0.889, 0001: 0.906, 0010: 0.923, 0011: 0.941,
                                                   0100: 0.980, 0101: 1.000, 0110: 1.021, 0111: 1.043, 1000:
                                                   1.090, 1001: 1.116, 1010: 1.143, 1011: 1.200, 1100: 1.231,
                                                   1101: 1.263, 1110: 1.297, 1111: 1.333                                     */
    __IOM uint32_t std_l1_sel : 2;            /*!< [13..12] STD_L1<1:0> time: 00: 750u; 01: 1.5m; 10: 3m; 11: 12.288m        */
    __IOM uint32_t fpwm_l1    : 1;            /*!< [14..14] FPWM_L1 = 1 => force PWM; FPWM_L1 = 0 => force PFM               */
    __IOM uint32_t type_l     : 1;            /*!< [15..15] 1:type3, 0:type2                                                 */
    __IOM uint32_t c1_l1_sel  : 2;            /*!< [17..16] 00 => 1.03p; 01 => 2.06p; 10 => 3.1p; 11 => 4.12p                */
    __IOM uint32_t c2_l1_sel  : 2;            /*!< [19..18] 00 => 13f; 01 => 26f; 10 => 39f; 11 => 41f;                      */
    __IOM uint32_t c3_l1_sel  : 2;            /*!< [21..20] 00 => 1.59p; 01 => 3.2p; 10 => 4.76p; 11 => 6.34p                */
    __IOM uint32_t r1_l1_sel  : 2;            /*!< [23..22] 00 => 900k; 01 => 720k; 10 => 900k; 11 => 1080k;                 */
    __IOM uint32_t r2_l1_sel  : 2;            /*!< [25..24] 00 => 2.5M; 01 => 2.0M; 10 => 1.5M; 11 => 1.0M;                  */
    __IOM uint32_t r3_l1_sel  : 2;            /*!< [27..26] 00 => 36k; 01 => 30k; 10 => 24k; 11 => 24k;                      */
    __IOM uint32_t freq_l_sel : 4;            /*!< [31..28] 0000: 455.3k 0001: 673.4k 0010: 887.6k 0011: 1.097M
                                                   0100: 1.303M 0101: 1.506M 0110: 1.705M 0111: 1.900M 1000:
                                                   2.094M 1001: 2.281M 1010: 2.467M 1011: 2.646M 1100: 2.826M
                                                   1101: 2.996M 1110: 3.166M 1111: 3.327M                                    */
  } b;                                        /*!< bit fields for ls_syson_lp_swr_ctrl0 */
} ls_syson_lp_swr_ctrl0_t, *pls_syson_lp_swr_ctrl0_t;

/**
  \brief Union type to access ls_syson_lp_swr_ctrl1 (@ 0x00000044).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000044) LP Switch Regulator Control Register1                      */
  
  struct {
    __IOM uint32_t swr_powocp_l1 : 1;         /*!< [0..0] POWOCP_L1=1=> enable over current protection                       */
    __IOM uint32_t swr_ocp_l1_sel : 3;        /*!< [3..1] Voltage Current: 000: 0.4 288 001: 0.5 360 010: 0.6 432
                                                   011: 0.7 504 100: 0.8 576 101: 0.9 648 110: 1.0 720 111:
                                                   1.1 792                                                                   */
    __IOM uint32_t swr_enocpmux_l : 1;        /*!< [4..4] swr_enocpmux_l                                                     */
    __IOM uint32_t swr_zcd_en : 1;            /*!< [5..5] Enable ZCD                                                         */
    __IOM uint32_t swr_zcd_out_en : 1;        /*!< [6..6] ZCD output enable                                                  */
    __IOM uint32_t swr_bypass_l : 1;          /*!< [7..7] 1:bypass SSR latch                                                 */
    __IOM uint32_t swr_enfpwmdelay_h : 1;     /*!< [8..8] 1:PFM=>PWM delay                                                   */
    __IOM uint32_t swr_zcdc_h : 2;            /*!< [10..9] 00:0.1u(PFM); 01:0.2u; 10:0.3u(PWM); 11:0.4u                      */
    __IOM uint32_t swr_tbox_l1_sel : 2;       /*!< [12..11] TBOX_L1<1:0> output: 00: CKOVER/RAMPOVER; 01: NI/PI;
                                                   10: CKSS/SSOVER; 11: i/NIOFF_H                                            */
    __IOM uint32_t swr_vofb_sel : 1;          /*!< [13..13] 0:vo15; 1:LX_SPS                                                 */
    __IOM uint32_t swr_vreepfm_l_sel : 4;     /*!< [17..14] 0000: 0.65 0001: 0.70 0010: 0.75 0011: 0.80 0100: 0.85
                                                   0101: 0.90 0110: 0.95 0111: 1.00 1000: 1.05 1001: 1.10
                                                   1010: 1.15 1011: 1.20 1100: 1.25 1101: 1.30 1110: 1.35
                                                   1111: 1.40                                                                */
    __IOM uint32_t swr_mos_half_l : 1;        /*!< [18..18] 1:power mos half                                                 */
    __IOM uint32_t swr_pfm_isch_l_sel : 2;    /*!< [20..19] swr_pfm_isch_l_sel                                               */
    __IOM uint32_t swr_clk_sel : 2;           /*!< [22..21] 00:out of phase CKSS; 01:out of phase PWM_CTRIL; 10:ckout;
                                                   11:HG                                                                     */
    __IOM uint32_t swr_ldor_l : 1;            /*!< [23..23] 1:ldos res short                                                 */
    __IOM uint32_t swr_adj_sldo_sel : 4;      /*!< [27..24] 0000: 0.600 0001: 0.631 0010: 0.660 0011: 0.692 0100:
                                                   0.719 0101: 0.749 0110: 0.782 0111: 0.817 1000: 0.856 1001:
                                                   0.899 1010: 0.952 1011: 0.998 1100: 1.049 1101: 1.096 1110:
                                                   1.149 1111: 1.196                                                         */
    __IOM uint32_t swr_opow_auto_l : 1;       /*!< [28..28] swr_opow_auto_l                                                  */
    __IOM uint32_t swr_zcd_sdz_l_sel : 2;     /*!< [30..29] swr_zcd_sdz_l_sel                                                */
    __IOM uint32_t swr_autozcd_l : 1;         /*!< [31..31] 0:register 1:10000                                               */
  } b;                                        /*!< bit fields for ls_syson_lp_swr_ctrl1 */
} ls_syson_lp_swr_ctrl1_t, *pls_syson_lp_swr_ctrl1_t;

/**
  \brief Union type to access ls_syson_lp_swr_ctrl2 (@ 0x00000048).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000048) LP Switch Regulator Control Register2                      */
  
  struct {
    __IM  uint32_t swr_zcd_offset_h_sel : 5;  /*!< [4..0] swr_zcd_offset_h_sel                                               */
    __IOM uint32_t swr_cot_i_l : 2;           /*!< [6..5] swr_cot_i_l                                                        */
    __IOM uint32_t swr_encot_l : 1;           /*!< [7..7] swr_encot_l                                                        */
    __IOM uint32_t swr_on_end_l_en : 1;       /*!< [8..8] swr_on_end_l_en                                                    */
    __IOM uint32_t swr_no_offtime_l : 1;      /*!< [9..9] swr_no_offtime_l                                                   */
    __IOM uint32_t swr_pow_minoff_l : 1;      /*!< [10..10] swr_pow_minoff_l                                                 */
    __IOM uint32_t swr_endn_l : 2;            /*!< [12..11] swr_endn_l                                                       */
    __IOM uint32_t swr_endp_l : 2;            /*!< [14..13] swr_endp_l                                                       */
    __IOM uint32_t swr_sdzn_l : 2;            /*!< [16..15] swr_sdzn_l                                                       */
    __IOM uint32_t swr_sdzp_l : 2;            /*!< [18..17] swr_sdzp_l                                                       */
    __IOM uint32_t swr_ensr_l : 1;            /*!< [19..19] swr_ensr_l                                                       */
    __IOM uint32_t swr_zcd_hw_auto_en : 1;    /*!< [20..20] SPS HW ZCD code auto count function enable                       */
    __IM  uint32_t            : 5;
    __IOM uint32_t swr_zcd_sw_mode_en : 1;    /*!< [26..26] SPS ZCD SW mode enable                                           */
  } b;                                        /*!< bit fields for ls_syson_lp_swr_ctrl2 */
} ls_syson_lp_swr_ctrl2_t, *pls_syson_lp_swr_ctrl2_t;

/**
  \brief Union type to access ls_syson_lp_swr_ctrl3 (@ 0x0000004C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000004C) LP Switch Regulator Control Register3                      */
  
  struct {
    __IOM uint32_t swr_ocp_en : 1;            /*!< [0..0] SPS OCP function enable                                            */
    __IOM uint32_t swr_ocp_thd : 15;          /*!< [15..1] SPS OCP threshold                                                 */
    __IOM uint32_t swr_ocp_wnd : 16;          /*!< [31..16] SPS OCP time windows                                             */
  } b;                                        /*!< bit fields for ls_syson_lp_swr_ctrl3 */
} ls_syson_lp_swr_ctrl3_t, *pls_syson_lp_swr_ctrl3_t;

/**
  \brief Union type to access ls_syson_lp_ldo_ctrl0 (@ 0x00000050).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000050) LP LDO Control Register0                                   */
  
  struct {
    __IM  uint32_t            : 18;
    __IOM uint32_t ck100k_en  : 1;            /*!< [18..18] 1:100K on                                                        */
    __IM  uint32_t            : 8;
    __IOM uint32_t ldo_vbat_load : 2;         /*!< [28..27] ldo_vbat_load                                                    */
    __IOM uint32_t ldo_vbat_stby : 2;         /*!< [30..29] 00:normal:0.5mA~700mA; 01:standby:1uA~11mA; 11:sleep:1uA~1.2mA   */
    __IOM uint32_t ldo_vbat_out_sel_b0 : 1;   /*!< [31..31] LDO battery output valtage selection bit0: 00:3.3V;
                                                   01:3.4V; 10:3.5V; 11:3.2V                                                 */
  } b;                                        /*!< bit fields for ls_syson_lp_ldo_ctrl0 */
} ls_syson_lp_ldo_ctrl0_t, *pls_syson_lp_ldo_ctrl0_t;

/**
  \brief Union type to access ls_syson_lp_ldo_ctrl (@ 0x00000054).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000054) LP LDO Control Register                                    */
  
  struct {
    __IOM uint32_t ldo_vbat_out_sel_b1 : 1;   /*!< [0..0] LDO battery output valtage selection bit1: 00:3.3V; 01:3.4V;
                                                   10:3.5V; 11:3.2V                                                          */
    __IM  uint32_t            : 1;
    __IOM uint32_t ldo_lp11_en : 1;           /*!< [2..2] 1:enable                                                           */
    __IOM uint32_t ldo_lp11_slp : 1;          /*!< [3..3] 1:sleep                                                            */
    __IOM uint32_t ldp_lp11_adj : 4;          /*!< [7..4] ldo voltage: 0000: 0.600V; 0001: 0.631V; 0010: 0.660V;
                                                   0011: 0.692V; 0100: 0.719V; 0101: 0.749V; 0110: 0.782V;
                                                   0111: 0.817V; 1000: 0.856V; 1001: 0.899V; 1010: 0.952V;
                                                   1011: 0.998V; 1100: 1.049V; 1101: 1.096V; 1110: 1.149V;
                                                   1111: 1.196V;                                                             */
    __IM  uint32_t            : 6;
    __IOM uint32_t ldo_core_pc_mode_en : 1;   /*!< [14..14] 1:power cut on(anapar_ldo<38:39>=00 or 01 or 11). [39:38]=
                                                   00: LDO OFF; 01: PC OFF; 10: LDO mode (SWR=1.25V); 11:
                                                   PC mode(SWR=1.1V )                                                        */
    __IOM uint32_t ldo_core_en : 1;           /*!< [15..15] 1:ldo on                                                         */
    __IOM uint32_t ldo_core_stby : 1;         /*!< [16..16] 1:standby                                                        */
    __IOM uint32_t ldo_core_arj : 4;          /*!< [20..17] ldo voltage: 0000: 0.600V 0001: 0.631V 0010: 0.660V
                                                   0011: 0.692V 0100: 0.719V 0101: 0.749V 0110: 0.782V 0111:
                                                   0.817V 1000: 0.856V 1001: 0.899V 1010: 0.952V 1011: 0.998V
                                                   1100: 1.049V 1101: 1.096V 1110: 1.149V 1111: 1.196V                       */
    __IOM uint32_t ldo_src_diode_en : 1;      /*!< [21..21] 1:diode off(note anapar_ldo[46]=1 then anapar_ldo[45]=1)         */
    __IOM uint32_t ldo_src_en : 1;            /*!< [22..22] 1:power cut on                                                   */
    __IOM uint32_t ldo_src_bypass : 1;        /*!< [23..23] not use(without bypass mode)                                     */
    __IOM uint32_t ldo_src_rst : 1;           /*!< [24..24] 1:res on                                                         */
    __IOM uint32_t ldo_src_adj : 4;           /*!< [28..25] ldo voltage: 0000: 1.399V 0001: 1.517V 0010: 1.612V
                                                   0011: 1.703V 0100: 1.806V 0101: 1.901V 0110: 2.001V 0111:
                                                   2.101V 1000: 2.204V 1001: 2.318V 1010: 2.410V 1011: 2.512V
                                                   1100: 2.621V 1101: 2.741V 1110: 2.827V 1111: 2.918V                       */
  } b;                                        /*!< bit fields for ls_syson_lp_ldo_ctrl */
} ls_syson_lp_ldo_ctrl_t, *pls_syson_lp_ldo_ctrl_t;

/**
  \brief Union type to access ls_syson_chg_flg (@ 0x0000005C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000005C) Charger Flag                                               */
  
  struct {
    __IM  uint32_t vbat_3v_okb_l : 1;         /*!< [0..0] 1: VBAT Power not exist                                            */
    __IM  uint32_t vbat_3v_ok_l : 1;          /*!< [1..1] 1: VBAT Power exist                                                */
    __IM  uint32_t dvdd_aon_det_l : 1;        /*!< [2..2] 1: DVDD exist                                                      */
    __IM  uint32_t hv33_aon_det_l : 1;        /*!< [3..3] 1: CHG LDO733 Vout exist                                           */
    __IM  uint32_t adp_det_l  : 1;            /*!< [4..4] 1: Adapter Power exist                                             */
    __IM  uint32_t bgok_l     : 1;            /*!< [5..5] 1: BG OK                                                           */
    __IM  uint32_t otp_det_l  : 1;            /*!< [6..6] 1: TEMP>OTP                                                        */
    __IM  uint32_t            : 1;
    __IM  uint32_t cc_cv      : 1;            /*!< [8..8] 1: CHG in CV mode, 0:CHG in CC mode                                */
    __IM  uint32_t chg_over   : 1;            /*!< [9..9] 1: CHG Current < 10%; 0: CC_fast Current                           */
    __IM  uint32_t adphibatb  : 1;            /*!< [10..10] 0: ADP > BAT                                                     */
    __IM  uint32_t            : 14;
    __IM  uint32_t chgdigctrl : 1;            /*!< [25..25] 1: CHG_STOP is 1; 0: CHG_STOP is 0                               */
    __IM  uint32_t lv09_det   : 1;            /*!< [26..26] 1: LV09 output 0.9V                                              */
    __IM  uint32_t vbat2d3_det : 1;           /*!< [27..27] 1: VBAT larger than 2.3V                                         */
    __IM  uint32_t temp45_det : 1;            /*!< [28..28] 1: R_temp larger than 45 degree                                  */
    __IM  uint32_t temp0_det  : 1;            /*!< [29..29] 1: R_temp less than 0 degree                                     */
    __IM  uint32_t enrtemp    : 1;            /*!< [30..30] 0: R_temp connect to GND(Disable OTP)                            */
    __IM  uint32_t clk_1k     : 1;            /*!< [31..31] 1: Output 1kHz                                                   */
  } b;                                        /*!< bit fields for ls_syson_chg_flg */
} ls_syson_chg_flg_t, *pls_syson_chg_flg_t;

/**
  \brief Union type to access ls_syson_lp_xtal_ctrl0 (@ 0x00000060).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000060) LP XTAL Control Register 0                                 */
  
  struct {
    __IOM uint32_t xtal_bg_en : 1;            /*!< [0..0] Enable BG(for xtal and AFE)                                        */
    __IOM uint32_t xtal_en    : 1;            /*!< [1..1] Enable xtal                                                        */
    __IOM uint32_t xtal_ctrler_clk_en : 1;    /*!< [2..2] Enable xtal controller clk                                         */
    __IM  uint32_t            : 5;
    __IOM uint32_t xtal_gmp_sel : 5;          /*!< [12..8] GMP: 0~31 Note: LPS set to 11111                                  */
    __IOM uint32_t xtal_gmn_sel : 5;          /*!< [17..13] GMN: 0~31                                                        */
    __IOM uint32_t xtal_sc_xi_sel : 6;        /*!< [23..18] 1:add cap, 0:degrade cap. (200fF per unit) MSB at anapar_xtal
                                                   67                                                                        */
    __IOM uint32_t xtal_sc_xo_sel : 6;        /*!< [29..24] 1:add cap, 0:degrade cap. (200fF per unit) MSB at anapar_xtal
                                                   68                                                                        */
    __IOM uint32_t xtal_gated_ok0 : 1;        /*!< [30..30] 1:Gated xtal OK0                                                 */
    __IOM uint32_t xtal_xq_sel : 1;           /*!< [31..31] 0: schmitt trigger, 1:replica INV(for AFE)                       */
  } b;                                        /*!< bit fields for ls_syson_lp_xtal_ctrl0 */
} ls_syson_lp_xtal_ctrl0_t, *pls_syson_lp_xtal_ctrl0_t;

/**
  \brief Union type to access ls_syson_lp_xtal_ctrl1 (@ 0x00000064).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000064) LP XTAL Control Register 1                                 */
  
  struct {
    __IOM uint32_t xtal_ldo_vol_sel : 2;      /*!< [1..0] 11: 1.3V 10:1.2V 01:1.1V 00:1.0V (before startup)                  */
    __IOM uint32_t xtal_gm_sep : 1;           /*!< [2..2] 0: GMP=GMN                                                         */
    __IOM uint32_t xtal_gated_rf1p : 1;       /*!< [3..3] RF1P Clock source gated control, 1:gated, 0: clock enable
                                                   (for A/G mode) Note: LPS set to 1                                         */
    __IOM uint32_t xtal_gated_rf1n : 1;       /*!< [4..4] RF1N Clock source gated control, 1:gated, 0: clock enable
                                                   (for A/G mode) Note: LPS set to 1                                         */
    __IOM uint32_t xtal_drv_rf1_sel : 2;      /*!< [6..5] Driving control of RF1 clock buffer, 11:large current,
                                                   00: small current                                                         */
    __IOM uint32_t xtal_gated_afep : 1;       /*!< [7..7] AFEP Clock source gated control, 1:gated, 0: clock enable
                                                   Note: LPS set to 1                                                        */
    __IOM uint32_t xtal_gated_afen : 1;       /*!< [8..8] AFEN Clock source gated control, 1:gated, 0: clock enable
                                                   Note: LPS set to 1                                                        */
    __IOM uint32_t xtal_drv_afe_sel : 2;      /*!< [10..9] Driving control of AFE clock buffer, 11:large current,
                                                   00: small current                                                         */
    __IOM uint32_t xtal_gated_usbp : 1;       /*!< [11..11] USBP Clock source gated control, 1:gated, 0: clock
                                                   enable Note: LPS set to 1                                                 */
    __IOM uint32_t xtal_gated_usbn : 1;       /*!< [12..12] USBN Clock source gated control, 1:gated, 0: clock
                                                   enable Note: LPS set to 1                                                 */
    __IOM uint32_t xtal_drv_usb_sel : 2;      /*!< [14..13] Driving control of USB clock buffer, 11:large current,
                                                   00: small current                                                         */
    __IOM uint32_t xtal_gated_digi : 1;       /*!< [15..15] DIGI Clock source gated control, 1:gated, 0: clock
                                                   enable                                                                    */
    __IOM uint32_t xtal_gated_lps : 1;        /*!< [16..16] LPS Clock source gated control, 1:gated, 0: clock enable         */
    __IOM uint32_t xtal_drv_digi_sel : 2;     /*!< [18..17] Driving control of DIGI clock buffer, 11:large current,
                                                   00: small current Note: LPS set to 00                                     */
    __IOM uint32_t xtal_drv_rf_latch : 1;     /*!< [19..19] 1: latch enable                                                  */
    __IOM uint32_t xtal_delay_afe : 1;        /*!< [20..20] 1: ck delay by 3 inverters, 0: ck delay by 17 inverters          */
    __IOM uint32_t xtal_aack_pk_manu : 1;     /*!< [21..21] 1: manual for peak detector peak selection                       */
    __IOM uint32_t xtal_delay_usb : 1;        /*!< [22..22] 1: ck delay by 3 inverters, 0: ck delay by 17 inverters          */
    __IOM uint32_t xtal_rf_initial_xq_sel : 1;/*!< [23..23] 0: schmitt trigger, 1:replica INV(for OK0=0)                     */
    __IOM uint32_t xtal_rf_awake_xq_sel : 1;  /*!< [24..24] 0: schmitt trigger, 1:replica INV(for OK0=1)                     */
    __IOM uint32_t xtal_tok_sel : 3;          /*!< [27..25] For cycles / 40MHz / 26MHz. 000: 8 / 200n / 300n; 001:
                                                   16 / 400n / 600n; 010: 32 / 800n / 1.2u; 011: 64 / 1.6u
                                                   / 2.5u; 100: 2^14 / 0.4m / 0.6m; 101: 2^15 / 0.8m / 1.2m;
                                                   110: 2^16 / 1.6m / 2.5m; 111: 2^17 / 3.2m / 4.9m                          */
    __IOM uint32_t xtal_lpmode_en : 1;        /*!< [28..28] 1: xtal low power mode enable                                    */
    __IOM uint32_t xtal_aac_gm_en : 1;        /*!< [29..29] 1: enable xtal aac gm control                                    */
    __IOM uint32_t xtal_aac_pkdet_en : 1;     /*!< [30..30] 1: enable xtal aac peak detector                                 */
    __IOM uint32_t xtal_manu_pk_sel : 1;      /*!< [31..31] XI Vpk-to-Vpk: 00: 0.7; 01: 0.8; 10: 0.9; 11: 1                  */
  } b;                                        /*!< bit fields for ls_syson_lp_xtal_ctrl1 */
} ls_syson_lp_xtal_ctrl1_t, *pls_syson_lp_xtal_ctrl1_t;

/**
  \brief Union type to access ls_syson_lp_xtal_ctrl3 (@ 0x0000006C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000006C) LP XTAL Control Register 3                                 */
  
  struct {
    __IOM uint32_t xtal_pdsw  : 2;            /*!< [1..0] XTAL analog AAC peak detector source follower size, 00:
                                                   small 11: large                                                           */
    __IOM uint32_t xtal_pdck_vref_en : 1;     /*!< [2..2] 1: analog AAC VREF from PDCK digital circuit 0: analog
                                                   AAC VREF from XTAL_VREF_SEL                                               */
    __IOM uint32_t xtal_vref_sel : 5;         /*!< [7..3] Analog AAC VREF, 430mV~740mV, 10mV/step                            */
    __IOM uint32_t xtal_pdck_manu : 1;        /*!< [8..8] 1: open analog AAC loop for PDCK manual                            */
    __IOM uint32_t xtal_pdck_manu_ok : 1;     /*!< [9..9] 1: force PDCK_OK=1 for PDCK manual                                 */
    __IOM uint32_t xtal_lps_clk_en : 1;       /*!< [10..10] 1: enable XTAL LPS clock Note: LPS set to 1                      */
    __IOM uint32_t xtal_schmitt_en : 1;       /*!< [11..11] 1: enable XTAL SCHMITT Note: LPS set to 0                        */
    __IOM uint32_t xtal_ckdigi_sel : 1;       /*!< [12..12] 1: DIGI CLK from self-bias 0: DIGI CLK from schmitt              */
    __IOM uint32_t xtal_gated_dbpp : 1;       /*!< [13..13] DBPP Clock source gated control, 1:gated, 0: clock
                                                   enable Note: LPS set to 1                                                 */
    __IOM uint32_t xtal_gated_dbpn : 1;       /*!< [14..14] DBPN Clock source gated control, 1:gated, 0: clock
                                                   enable Note: LPS set to 1                                                 */
    __IOM uint32_t xtal_drv_dbp_sel : 2;      /*!< [16..15] Driving control of DBP clock buffer, 11:large current,
                                                   00: small current                                                         */
    __IOM uint32_t xtal_drv_dly_dbp : 1;      /*!< [17..17] 1: ck delay by 3 inverters, 0: ck delay by 17 inverters          */
    __IOM uint32_t xtal_aac_rst_n : 1;        /*!< [18..18] AAC digital circuit reset (low to high)                          */
    __IOM uint32_t xtal_aac_en : 1;           /*!< [19..19] 0: disable aac cali function; 1: enable aac cali function.
                                                   Autoload bit, pmc refer it for doing AAC func                             */
    __IOM uint32_t xtal_aac_trig_en : 1;      /*!< [20..20] Set by pmc and clr by HW finish calibration                      */
    __IOM uint32_t xtal_aac_digi_en : 1;      /*!< [21..21] 1:enable aac digital circuit                                     */
    __IOM uint32_t xtal_gm_manual : 5;        /*!< [26..22] Gm manual at EN_XTAL_AAC_DIGI=0                                  */
    __IOM uint32_t xtal_gm_stup_sel : 5;      /*!< [31..27] aac gm start up setting (when pkdet=0, gm value is
                                                   the maximum)                                                              */
  } b;                                        /*!< bit fields for ls_syson_lp_xtal_ctrl3 */
} ls_syson_lp_xtal_ctrl3_t, *pls_syson_lp_xtal_ctrl3_t;

/**
  \brief Union type to access ls_syson_lp_xtal_ctrl4 (@ 0x00000070).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000070) LP XTAL Control Register 4                                 */
  
  struct {
    __IOM uint32_t xtal_clk_set : 3;          /*!< [2..0] aac settling cycles (4M ring) : 000: 2^8; 001: 2^9; 010:
                                                   2^10; 011: 2^11. (512us / for 4MHz): 100: 2^12; 101: 2^13;
                                                   110: 2^ 14;111: 2^15                                                      */
    __IOM uint32_t xtal_gm_init_set : 5;      /*!< [7..3] aac gm initial setting                                             */
    __IOM uint32_t xtal_gm_step : 1;          /*!< [8..8] aac gm searching step. 0:step 1, 1:step 2                          */
    __IOM uint32_t xtal_aac_gm_offset : 5;    /*!< [13..9] aac calibrated gm result +/- offset                               */
    __IOM uint32_t xtal_offset_plus : 1;      /*!< [14..14] 0: aac calibrated gm result - offset, 1: aac calibrated
                                                   gm result + offset                                                        */
    __IOM uint32_t xtal_aac_mode_sel : 2;     /*!< [16..15] XTAL_AACK_PK_SEL<1:0>'s XTAL_GM_OUT<4:0> calibration
                                                   result. 11: XTAL_AACK_PK_SEL=<11>'s XTAL_GM_OUT; 10: XTAL_AACK_PK_SEL=<10
                                                   's XTAL_GM_OUT; 01: XTAL_AACK_PK_SEL=<01>'s XTAL_GM_OUT;
                                                   00: XTAL_AACK_PK_SEL=<00>'s XTAL_GM_OUT                                   */
    __IOM uint32_t xtal_aac_lpow : 1;         /*!< [17..17] AACK low power mode, 1:gating input clk                          */
    __IOM uint32_t xtal_aac_lut_manual_en : 1;/*!< [18..18] 1: enable LUT data: GM_MANUAL<4:0> , sel: AAC_MODE<1:0>          */
    __IOM uint32_t xtal_pk_start_sel : 2;     /*!< [20..19] AAC peak sel start (star>end)                                    */
    __IOM uint32_t xtal_pk_end_sel : 2;       /*!< [22..21] AAC peak sel end (star>end)                                      */
    __IOM uint32_t xtal_decoder_rst_n : 1;    /*!< [23..23] Decoder digital circuit reset (low to high)                      */
    __IOM uint32_t xtal_pdck_digi_en : 1;     /*!< [24..24] 1:enable xtal PDCK                                               */
    __IOM uint32_t xtal_mode_sel : 2;         /*!< [26..25] xtal_mode_sel (xtal_mode_sel<1:0>): 00: normal mode;
                                                   01: LPS mode; 10: normal mode; 11: high performance mode                  */
    __IOM uint32_t xtal_manu_en : 1;          /*!< [27..27] 1: enable xtal mode manual                                       */
    __IOM uint32_t xtal_mode_manual_sel : 2;  /*!< [29..28] 00: normal mode; 01: LPS mode; 10: normal mode; 11:
                                                   high performance mode                                                     */
    __IOM uint32_t xtal_ov_unit_set : 2;      /*!< [31..30] xtal_ov_unit_set[1:0]: overlap time settling cycles
                                                   (4M ring). 000: 2^3 2us; 001: 2^4 4us; 010: 2^5 8us; 011:
                                                   2^6 16us; 100: 2^7 32us; 101: 2^8 64us; 110: 2^9 128us;
                                                   111: 2^10 256us                                                           */
  } b;                                        /*!< bit fields for ls_syson_lp_xtal_ctrl4 */
} ls_syson_lp_xtal_ctrl4_t, *pls_syson_lp_xtal_ctrl4_t;

/**
  \brief Union type to access ls_syson_lp_xtal_ctrl5 (@ 0x00000074).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000074) LP XTAL Control Register 5                                 */
  
  struct {
    __IOM uint32_t xtal_ov_unit_set : 1;      /*!< [0..0] xtal_ov_unit_set[2]: overlap time settling cycles (4M
                                                   ring): 000: 2^3 2us; 001: 2^4 4us; 010: 2^5 8us; 011: 2^6
                                                   16us; 100: 2^7 32us; 101: 2^8 64us; 110: 2^9 128us; 111:
                                                   2^10 256us                                                                */
    __IOM uint32_t xtal_ov_ratio_sel : 2;     /*!< [2..1] overlap unit times (4M ring): 00: 2^9 128us; 01:2^10
                                                   256us; 10:2^11 512us; 11:2^12 1.024 1ms                                   */
    __IOM uint32_t xtal_md_lpow : 1;          /*!< [3..3] XTAL mode decoder low power mode 1: gated input clock              */
    __IOM uint32_t xtal_ldo_ok : 2;           /*!< [5..4] 11: 1.3V 10:1.2V 01:1.1V 00:1.0V (after started)                   */
    __IOM uint32_t xtal_wait_cyc_sel : 6;     /*!< [11..6] Next state wait cycle, 250ns/unit                                 */
    __IOM uint32_t xtal_pdck_digi_rst_n : 1;  /*!< [12..12] PDCK digital circuit reset (low to high)                         */
    __IOM uint32_t xtal_pdck_search_mode : 1; /*!< [13..13] 0: binary search, 1: full search from 31                         */
    __IOM uint32_t xtal_pdck_wait_cyc_set : 2;/*!< [15..14] 00: 2^8 64us; 01:2^9 128us; 10:2^10 256us; 11:2^11
                                                   512us                                                                     */
    __IOM uint32_t xtal_vref_manual : 5;      /*!< [20..16] VREF manual at EN_XTAL_PDCK_DIGI=0                               */
    __IOM uint32_t xtal_vref_init_set : 5;    /*!< [25..21] PDCK VREF initial setting                                        */
    __IOM uint32_t xtal_pdck_unit_sel : 2;    /*!< [27..26] PDCK settling cycles (4M ring): 00: 2^4 4us; 01: 2^5
                                                   8us; 10: 2^6 16us; 11: 2^7 32us                                           */
    __IOM uint32_t xtal_pdck_vref_sel : 4;    /*!< [31..28] xtal_pdck_vref_sel[3:0]: PDCK calibrated result +offset.
                                                   Note: LPS set to >1. Default=0. set to >1 before enter
                                                   LPS; set to 0 when leave LPS                                              */
  } b;                                        /*!< bit fields for ls_syson_lp_xtal_ctrl5 */
} ls_syson_lp_xtal_ctrl5_t, *pls_syson_lp_xtal_ctrl5_t;

/**
  \brief Union type to access ls_syson_lp_xtal_ctrl6 (@ 0x00000078).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000078) LP XTAL Control Register 6                                 */
  
  struct {
    __IOM uint32_t xtal_pdck_vref_sel : 1;    /*!< [0..0] xtal_pdck_vref_sel[4]: PDCK calibrated result +offset.
                                                   Note: LPS set to >1                                                       */
    __IOM uint32_t xtal_pdck_lpow : 1;        /*!< [1..1] PDCK low power mode, 1:gating input clk                            */
  } b;                                        /*!< bit fields for ls_syson_lp_xtal_ctrl6 */
} ls_syson_lp_xtal_ctrl6_t, *pls_syson_lp_xtal_ctrl6_t;

/**
  \brief Union type to access ls_syson_lp_syspll_ctrl0 (@ 0x00000080).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000080) LP System PLL Control Register                             */
  
  struct {
    __IOM uint32_t lp_pll_bg_en : 1;          /*!< [0..0] Enable BG                                                          */
    __IOM uint32_t lp_pll_bg_i_en : 1;        /*!< [1..1] Enable BG current                                                  */
    __IOM uint32_t lp_pll_mbias_en : 1;       /*!< [2..2] Enable MBIAS                                                       */
  } b;                                        /*!< bit fields for ls_syson_lp_syspll_ctrl0 */
} ls_syson_lp_syspll_ctrl0_t, *pls_syson_lp_syspll_ctrl0_t;

/**
  \brief Union type to access ls_syson_lp_fll2m_ctrl (@ 0x00000098).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000098) LP System FLL Control Register                             */
  
  struct {
    __IOM uint32_t osr_en     : 1;            /*!< [0..0] Circuit enable                                                     */
    __IM  uint32_t            : 7;
    __IOM uint32_t cur_sel    : 8;            /*!< [15..8] Oscillator bias current ctrl                                      */
    __IOM uint32_t cap_sel    : 4;            /*!< [19..16] Oscillator cap ctrl                                              */
    __IOM uint32_t vcm_sel    : 4;            /*!< [23..20] Osillator comparator CM mode select                              */
    __IOM uint32_t bias_cur_sel : 4;          /*!< [27..24] Oscillator Iptat current select                                  */
  } b;                                        /*!< bit fields for ls_syson_lp_fll2m_ctrl */
} ls_syson_lp_fll2m_ctrl_t, *pls_syson_lp_fll2m_ctrl_t;

/**
  \brief Union type to access ls_syson_sys_pinmux_ctrl (@ 0x000000A4).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000A4) System Pin Mux Control Register                            */
  
  struct {
    __IOM uint32_t bit_sys_fen_sic : 1;       /*!< [0..0] 1: enable SIC function enable; 0: reset                            */
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_sic_pin_en : 1;        /*!< [4..4] 1: Enable SIC PINMUX function GPIOA_0~1; 0: disable                */
    __IM  uint32_t            : 3;
    __IOM uint32_t swd_jtag_en : 1;           /*!< [8..8] 1: Enable LS debugger(when eFuse controlled debugger
                                                   function enable is on); 0: Disable                                        */
  } b;                                        /*!< bit fields for ls_syson_sys_pinmux_ctrl */
} ls_syson_sys_pinmux_ctrl_t, *pls_syson_sys_pinmux_ctrl_t;

/**
  \brief Union type to access ls_syson_sdm_idr_ctrl0 (@ 0x000000A8).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000A8) SDM IDR Control Resgister0                                 */
  
  struct {
    __IOM uint32_t bit_ls_sdm_addr : 6;       /*!< [5..0] SDM register offset                                                */
    __IM  uint32_t            : 2;
    __IOM uint32_t bit_ls_sdm_en : 1;         /*!< [8..8] SDM function. 1: Enable; 0: Disable                                */
    __IOM uint32_t bit_ls_sdm_clk_en : 1;     /*!< [9..9] SDM Pclk. 1: Enable; 0: Disable                                    */
  } b;                                        /*!< bit fields for ls_syson_sdm_idr_ctrl0 */
} ls_syson_sdm_idr_ctrl0_t, *pls_syson_sdm_idr_ctrl0_t;

/**
  \brief Union type to access ls_syson_sdm_idr_ctrl1 (@ 0x000000AC).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000AC) SDM IDR Control Resgister1                                 */
  
  struct {
    __IOM uint32_t bit_ls_sdm_data : 32;      /*!< [31..0] SDM register data, support byte write                             */
  } b;                                        /*!< bit fields for ls_syson_sdm_idr_ctrl1 */
} ls_syson_sdm_idr_ctrl1_t, *pls_syson_sdm_idr_ctrl1_t;

/**
  \brief Union type to access ls_syson_hptgie (@ 0x000000B0).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000B0) HP Toggle Interrupt Enable Register                        */
  
  struct {
    __IOM uint32_t hptgie0    : 1;            /*!< [0..0] This bit is used to control the enable of the interrupt
                                                   triggered by the HPTG0 toggles.0/1: Disable / Enable Interrupt            */
    __IOM uint32_t hptgie1    : 1;            /*!< [1..1] This bit is used to control the enable of the interrupt
                                                   triggered by the HPTG1 toggles.0/1: Disable / Enable Interrupt            */
    __IOM uint32_t hptgie2    : 1;            /*!< [2..2] This bit is used to control the enable of the interrupt
                                                   triggered by the HPTG2 toggles.0/1: Disable / Enable Interrupt            */
    __IOM uint32_t hptgie3    : 1;            /*!< [3..3] This bit is used to control the enable of the interrupt
                                                   triggered by the HPTG3 toggles.0/1: Disable / Enable Interrupt            */
    __IOM uint32_t hptgie4    : 1;            /*!< [4..4] This bit is used to control the enable of the interrupt
                                                   triggered by the HPTG4 toggles.0/1: Disable / Enable Interrupt            */
    __IOM uint32_t hptgie5    : 1;            /*!< [5..5] This bit is used to control the enable of the interrupt
                                                   triggered by the HPTG5 toggles.0/1: Disable / Enable Interrupt            */
    __IOM uint32_t hptgie6    : 1;            /*!< [6..6] This bit is used to control the enable of the interrupt
                                                   triggered by the HPTG6 toggles.0/1: Disable / Enable Interrupt            */
    __IOM uint32_t hptgie7    : 1;            /*!< [7..7] This bit is used to control the enable of the interrupt
                                                   triggered by the HPTG7 toggles.0/1: Disable / Enable Interrupt            */
    __IM  uint32_t            : 8;
    __IOM uint32_t h2ltgie0   : 1;            /*!< [16..16] This bit is used to control the enable of the interrupt
                                                   triggered by the H2LTG0 toggles.0/1: Disable / Enable Interrupt           */
    __IOM uint32_t h2ltgie1   : 1;            /*!< [17..17] This bit is used to control the enable of the interrupt
                                                   triggered by the H2LTG1 toggles.0/1: Disable / Enable Interrupt           */
    __IOM uint32_t h2ltgie2   : 1;            /*!< [18..18] This bit is used to control the enable of the interrupt
                                                   triggered by the H2LTG2 toggles.0/1: Disable / Enable Interrupt           */
    __IOM uint32_t h2ltgie3   : 1;            /*!< [19..19] This bit is used to control the enable of the interrupt
                                                   triggered by the H2LTG3 toggles.0/1: Disable / Enable Interrupt           */
    __IOM uint32_t h2ltgies   : 1;            /*!< [20..20] This bit is used to control the enable of the interrupt
                                                   triggered by the H2LTGS toggles.0/1: Disable/Enable Interrupt             */
  } b;                                        /*!< bit fields for ls_syson_hptgie */
} ls_syson_hptgie_t, *pls_syson_hptgie_t;

/**
  \brief Union type to access ls_syson_hptgis (@ 0x000000B4).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000B4) HP Toggle Interrupt Status Register                        */
  
  struct {
    __IOM uint32_t hptgis0    : 1;            /*!< [0..0] This bit is used to show the interrupt status which is
                                                   triggered by the HPTG0 toggles. This usually means the
                                                   HP CPU has updated the register HWLR0.0: No interrupt;
                                                   1: Interrupt is pending. Write 1 to clear.                                */
    __IOM uint32_t hptgis1    : 1;            /*!< [1..1] This bit is used to show the interrupt status which is
                                                   triggered by the HPTG1 toggles. This usually means the
                                                   HP CPU has updated the register HWLR1.0: No interrupt;
                                                   1: Interrupt is pending. Write 1 to clear.                                */
    __IOM uint32_t hptgis2    : 1;            /*!< [2..2] This bit is used to show the interrupt status which is
                                                   triggered by the HPTG2 toggles. This usually means the
                                                   HP CPU has updated the register HWLR2.0: No interrupt;
                                                   1: Interrupt is pending. Write 1 to clear.                                */
    __IOM uint32_t hptgis3    : 1;            /*!< [3..3] This bit is used to show the interrupt status which is
                                                   triggered by the HPTG3 toggles. This usually means the
                                                   HP CPU has updated the register HWLR3.0: No interrupt;
                                                   1: Interrupt is pending. Write 1 to clear.                                */
    __IOM uint32_t hptgis4    : 1;            /*!< [4..4] This bit is used to show the interrupt status which is
                                                   triggered by the HPTG4 toggles. This usually means the
                                                   HP CPU has updated the register HWLR4.0: No interrupt;
                                                   1: Interrupt is pending. Write 1 to clear.                                */
    __IOM uint32_t hptgis5    : 1;            /*!< [5..5] This bit is used to show the interrupt status which is
                                                   triggered by the HPTG5 toggles. This usually means the
                                                   HP CPU has updated the register HWLR5.0: No interrupt;
                                                   1: Interrupt is pending. Write 1 to clear.                                */
    __IOM uint32_t hptgis6    : 1;            /*!< [6..6] This bit is used to show the interrupt status which is
                                                   triggered by the HPTG6 toggles. This usually means the
                                                   HP CPU has updated the register HWLR6.0: No interrupt;
                                                   1: Interrupt is pending. Write 1 to clear.                                */
    __IOM uint32_t hptgis7    : 1;            /*!< [7..7] This bit is used to show the interrupt status which is
                                                   triggered by the HPTG7 toggles. This usually means the
                                                   HP CPU has updated the register HWLR7.0: No interrupt;
                                                   1: Interrupt is pending. Write 1 to clear.                                */
    __IM  uint32_t            : 8;
    __IOM uint32_t h2ltgis0   : 1;            /*!< [16..16] This bit is used to show the interrupt status which
                                                   is triggered by the H2LTG0 toggles. This usually means
                                                   the HP CPU has updated the register HLRW0.0: No interrupt;
                                                   1: Interrupt is pending. Write 1 to clear.                                */
    __IOM uint32_t h2ltgis1   : 1;            /*!< [17..17] This bit is used to show the interrupt status which
                                                   is triggered by the H2LTG1 toggles. This usually means
                                                   the HP CPU has updated the register HLRW1.0: No interrupt;
                                                   1: Interrupt is pending. Write 1 to clear.                                */
    __IOM uint32_t h2ltgis2   : 1;            /*!< [18..18] This bit is used to show the interrupt status which
                                                   is triggered by the H2LTG2 toggles. This usually means
                                                   the HP CPU has updated the register HLRW2.0: No interrupt;
                                                   1: Interrupt is pending. Write 1 to clear.                                */
    __IOM uint32_t h2ltgis3   : 1;            /*!< [19..19] This bit is used to show the interrupt status which
                                                   is triggered by the H2LTG3 toggles. This usually means
                                                   the HP CPU has updated the register HLRW3.0: No interrupt;
                                                   1: Interrupt is pending. Write 1 to clear.                                */
    __IOM uint32_t h2ltgiss   : 1;            /*!< [20..20] This bit is used to show the interrupt status which
                                                   is triggered by the H2LTGS toggles. This usually means
                                                   the HP CPU has updated the register REG_SEMA.0: No interrupt;
                                                   1: Interrupt is pending. Write 1 to clear.                                */
  } b;                                        /*!< bit fields for ls_syson_hptgis */
} ls_syson_hptgis_t, *pls_syson_hptgis_t;

/**
  \brief Union type to access ls_syson_mem_ctrl0 (@ 0x000000D0).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000D0) Memory Ctrl0 Register                                      */
  
  struct {
    __IOM uint32_t bit_snps_ram_rm : 4;       /*!< [3..0] bit_snps_ram_rm                                                    */
    __IOM uint32_t bit_snps_ram_rme : 1;      /*!< [4..4] bit_snps_ram_rme                                                   */
    __IOM uint32_t bit_snps_ram_ra : 2;       /*!< [6..5] bit_snps_ram_ra                                                    */
    __IOM uint32_t bit_snps_ram_wa : 3;       /*!< [9..7] bit_snps_ram_wa                                                    */
    __IOM uint32_t bit_snps_ram_wpulse : 3;   /*!< [12..10] bit_snps_ram_wpulse                                              */
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_snps_rom_rm : 4;       /*!< [19..16] bit_snps_rom_rm                                                  */
    __IOM uint32_t bit_snps_rom_rme : 1;      /*!< [20..20] bit_snps_rom_rme                                                 */
  } b;                                        /*!< bit fields for ls_syson_mem_ctrl0 */
} ls_syson_mem_ctrl0_t, *pls_syson_mem_ctrl0_t;

/**
  \brief Union type to access ls_syson_mem_pmctrl0 (@ 0x000000D4).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000D4) Memory Power Mode Ctrl0 Register                           */
  
  struct {
    __IOM uint32_t mem_dslp_pm_en : 1;        /*!< [0..0] mem_dslp_pm_en                                                     */
    __IOM uint32_t mem_slp_pm_en : 1;         /*!< [1..1] mem_slp_pm_en                                                      */
  } b;                                        /*!< bit fields for ls_syson_mem_pmctrl0 */
} ls_syson_mem_pmctrl0_t, *pls_syson_mem_pmctrl0_t;

/**
  \brief Union type to access ls_syson_mem_pmctrl1 (@ 0x000000D8).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000D8) Memory Power Mode Ctrl1 Register                           */
  
  struct {
    __IOM uint32_t bit_retmem_nor_ls : 1;     /*!< [0..0] bit_retmem_nor_ls                                                  */
    __IOM uint32_t bit_retmem_nor_ds : 1;     /*!< [1..1] bit_retmem_nor_ds                                                  */
    __IOM uint32_t bit_retmem_nor_sd : 1;     /*!< [2..2] bit_retmem_nor_sd                                                  */
    __IM  uint32_t            : 1;
    __IOM uint32_t bit_busmem_nor_ls : 1;     /*!< [4..4] bit_busmem_nor_ls                                                  */
    __IOM uint32_t bit_busmem_nor_ds : 1;     /*!< [5..5] bit_busmem_nor_ds                                                  */
    __IOM uint32_t bit_busmem_nor_sd : 1;     /*!< [6..6] bit_busmem_nor_sd                                                  */
    __IM  uint32_t            : 1;
    __IOM uint32_t bit_dtcm_nor_ls : 1;       /*!< [8..8] bit_dtcm_nor_ls                                                    */
    __IOM uint32_t bit_dtcm_nor_ds : 1;       /*!< [9..9] bit_dtcm_nor_ds                                                    */
    __IOM uint32_t bit_dtcm_nor_sd : 1;       /*!< [10..10] bit_dtcm_nor_sd                                                  */
    __IM  uint32_t            : 1;
    __IOM uint32_t bit_itcm_nor_ls : 1;       /*!< [12..12] bit_itcm_nor_ls                                                  */
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_retmem_slp_ls : 1;     /*!< [16..16] bit_retmem_slp_ls                                                */
    __IOM uint32_t bit_retmem_slp_ds : 1;     /*!< [17..17] bit_retmem_slp_ds                                                */
    __IOM uint32_t bit_retmem_slp_sd : 1;     /*!< [18..18] bit_retmem_slp_sd                                                */
    __IM  uint32_t            : 1;
    __IOM uint32_t bit_busmem_slp_ls : 1;     /*!< [20..20] bit_busmem_slp_ls                                                */
    __IOM uint32_t bit_busmem_slp_ds : 1;     /*!< [21..21] bit_busmem_slp_ds                                                */
    __IOM uint32_t bit_busmem_slp_sd : 1;     /*!< [22..22] bit_busmem_slp_sd                                                */
    __IM  uint32_t            : 1;
    __IOM uint32_t bit_dtcm_slp_ls : 1;       /*!< [24..24] bit_dtcm_slp_ls                                                  */
    __IOM uint32_t bit_dtcm_slp_ds : 1;       /*!< [25..25] bit_dtcm_slp_ds                                                  */
    __IOM uint32_t bit_dtcm_slp_sd : 1;       /*!< [26..26] bit_dtcm_slp_sd                                                  */
    __IM  uint32_t            : 1;
    __IOM uint32_t bit_itcm_slp_ls : 1;       /*!< [28..28] bit_itcm_slp_ls                                                  */
  } b;                                        /*!< bit fields for ls_syson_mem_pmctrl1 */
} ls_syson_mem_pmctrl1_t, *pls_syson_mem_pmctrl1_t;

/**
  \brief Union type to access ls_syson_lp_efuse_ctrl0 (@ 0x000000E4).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000E4) eFuse Control Register0                                    */
  
  struct {
    __IOM uint32_t efuse_autoload_sus : 1;    /*!< [0..0] 1: Autoload successful (autoload valid); 0: Autoload
                                                   fail                                                                      */
    __IOM uint32_t efuse_ldall : 1;           /*!< [1..1] 1: SW enable HWSM to autoload all 0: SW enable HWSM to
                                                   autoload excluding Efuse 0x00~ 0x31                                       */
    __IM  uint32_t            : 6;
    __IOM uint32_t efuse_unlock : 8;          /*!< [15..8] eFuse unlock                                                      */
  } b;                                        /*!< bit fields for ls_syson_lp_efuse_ctrl0 */
} ls_syson_lp_efuse_ctrl0_t, *pls_syson_lp_efuse_ctrl0_t;

/**
  \brief Union type to access ls_syson_lp_efuse_ctrl1 (@ 0x000000E8).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000E8) eFuse Control Register1                                    */
  
  struct {
    __IOM uint32_t sys_ef_data : 8;           /*!< [7..0] Access Data                                                        */
    __IOM uint32_t sys_ef_addr : 10;          /*!< [17..8] Access Address                                                    */
    __IOM uint32_t sys_ef_alden : 1;          /*!< [18..18] Autoload Enable                                                  */
    __IM  uint32_t            : 1;
    __IOM uint32_t sys_ef_pgts : 4;           /*!< [23..20] Programming setup time. In the unit of cycle time.(125ns)        */
    __IOM uint32_t sys_ef_rdt : 4;            /*!< [27..24] E-fuse read time: in the unit of cycle time                      */
    __IOM uint32_t sys_ef_pgpd : 3;           /*!< [30..28] E-fuse program time: 000: 5000ns, 001: 5100ns, 010:
                                                   5200ns, 011: 5900ns, 100: 6500ns, 101: 7000ns, 110: 7500ns,
                                                   111: 8000ns                                                               */
  } b;                                        /*!< bit fields for ls_syson_lp_efuse_ctrl1 */
} ls_syson_lp_efuse_ctrl1_t, *pls_syson_lp_efuse_ctrl1_t;

/**
  \brief Union type to access ls_syson_lp_efuse_test (@ 0x000000EC).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000EC) eFuse Control Test Register                                */
  
  struct {
    __IOM uint32_t sys_ef_scan_tthd : 7;      /*!< [6..0] Bit number for all cells scan test                                 */
    __IOM uint32_t sys_ef_trpt : 1;           /*!< [7..7] Test Scan Report: 1 : Fail, 0 : OK                                 */
    __IOM uint32_t sys_ef_cell_sel : 2;       /*!< [9..8] Efuse Cell Selection: 00: WIFI Efuse others: reserved              */
    __IM  uint32_t            : 1;
    __IOM uint32_t sys_ef_force_pgmen : 1;    /*!< [11..11] SW force PGMEN input of efuse to high. (for the bank
                                                   selected by 0x34[9:8])                                                    */
    __IOM uint32_t sys_ef_scan_end : 4;       /*!< [15..12] Residual bytes Setting for SCAN (0~15)                           */
    __IOM uint32_t sys_ef_scan_start : 9;     /*!< [24..16] SCAN start Address (unit in byte)                                */
    __IM  uint32_t            : 6;
    __IOM uint32_t sw_ldoe25_pc_en : 1;       /*!< [31..31] SW Turn on power cut 25                                          */
  } b;                                        /*!< bit fields for ls_syson_lp_efuse_test */
} ls_syson_lp_efuse_test_t, *pls_syson_lp_efuse_test_t;

/**
  \brief Union type to access ls_syson_sys_sw_boot_ctrl (@ 0x000000F8).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000F8) SW used boot control register                              */
  
  struct {
    __IOM uint32_t sys_fast_boot_en : 32;     /*!< [31..0] reserved for SW: fast boot control. To store the RAM
                                                   code entry point for fast boot.                                           */
  } b;                                        /*!< bit fields for ls_syson_sys_sw_boot_ctrl */
} ls_syson_sys_sw_boot_ctrl_t, *pls_syson_sys_sw_boot_ctrl_t;

/**
  \brief Union type to access ls_syson_sys_slp_wake_event (@ 0x00000100).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000100) REG_SYS_SLP_WAKE_EVENT_MSK0                                */
  
  struct {
    __IOM uint32_t lp_wevt_systim : 1;        /*!< [0..0] 1: Enable SYSTimer event wakeup system                             */
    __IOM uint32_t lp_wevt_gtim : 1;          /*!< [1..1] 1: enable Gtimer 0~7 Wakeup LP event; 0: disable the
                                                   event to wakeup system                                                    */
    __IOM uint32_t lp_wevt_swrd_ocp : 1;      /*!< [2..2] 1: enable DCORE SWR OCP wakeup event; 0: disable the
                                                   event to wakeup system                                                    */
    __IOM uint32_t lp_wevt_bod : 1;           /*!< [3..3] 1: enable BOD Wakeup event; 0: disable the event to wakeup
                                                   system                                                                    */
    __IOM uint32_t lp_wevt_gpio : 1;          /*!< [4..4] 1: enable GPIO Wakeup event; 0: disable the event to
                                                   wakeup system                                                             */
    __IOM uint32_t lp_wevt_pwm : 1;           /*!< [5..5] 1: enable PWM Wakeup event; 0: disable the event to wakeup
                                                   system                                                                    */
    __IM  uint32_t            : 2;
    __IOM uint32_t lp_wevt_wlan : 1;          /*!< [8..8] 1: enable WLAN Wakeup event; 0: disable the event to
                                                   wakeup system                                                             */
    __IM  uint32_t            : 11;
    __IOM uint32_t lp_wevt_uart : 1;          /*!< [20..20] 1: enable UART Wakeup event; 0: disable the event to
                                                   wakeup system                                                             */
    __IM  uint32_t            : 3;
    __IOM uint32_t lp_wevt_i2c : 1;           /*!< [24..24] 1: enable I2C Wakeup event; 0: disable the event to
                                                   wakeup system                                                             */
    __IM  uint32_t            : 1;
    __IOM uint32_t lp_wevt_adc : 1;           /*!< [26..26] 1: enable ADC Wakeup event; 0: disable the event to
                                                   wakeup system                                                             */
    __IOM uint32_t lp_wevt_comp : 1;          /*!< [27..27] 1: enable Comparetor Wakeup event; 0: disable the event
                                                   to wakeup system                                                          */
    __IOM uint32_t lp_wevt_sgpio : 1;         /*!< [28..28] 1: enable SGPIO Wakeup event; 0: disable the event
                                                   to wakeup system                                                          */
    __IOM uint32_t lp_wevt_aon : 1;           /*!< [29..29] 1: enable AON Wakeup event; 0: disable the event to
                                                   wakeup system                                                             */
    __IOM uint32_t lp_wevt_hs : 1;            /*!< [30..30] 1: enable HS Wakeup event; 0: disable the event to
                                                   wakeup system                                                             */
  } b;                                        /*!< bit fields for ls_syson_sys_slp_wake_event */
} ls_syson_sys_slp_wake_event_t, *pls_syson_sys_slp_wake_event_t;

/**
  \brief Union type to access ls_syson_sys_slp_wake_sts (@ 0x00000104).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000104) REG_SYS_SLP_WAKE_EVENT_STATUS0                             */
  
  struct {
    __IOM uint32_t lp_wsts_systim : 1;        /*!< [0..0] 1: Indocate SYSTimer Wakeup event                                  */
    __IM  uint32_t lp_wsts_gtim : 1;          /*!< [1..1] 1: Indicate GTimer0~7 Wakeup system event                          */
    __IM  uint32_t lp_wsts_swrd_ocp : 1;      /*!< [2..2] 1: Indicate DCORE SWR OCP event                                    */
    __IOM uint32_t lp_wsts_bod : 1;           /*!< [3..3] 1: Indicate BOD Wakeup event                                       */
    __IM  uint32_t lp_wsts_gpio : 1;          /*!< [4..4] 1: Indicate GPIO Wakeup event                                      */
    __IM  uint32_t lp_wsts_pwm : 1;           /*!< [5..5] 1: Indicate PWM Wakeup event                                       */
    __IM  uint32_t            : 2;
    __IM  uint32_t lp_wsts_wlan : 1;          /*!< [8..8] 1: Indicate WLAN Wakeup event                                      */
    __IM  uint32_t            : 11;
    __IM  uint32_t lp_wsts_uart : 1;          /*!< [20..20] 1: Indicate UART Wakeup event                                    */
    __IM  uint32_t            : 3;
    __IM  uint32_t lp_wsts_i2c : 1;           /*!< [24..24] 1: Indicate I2C Wakeup event                                     */
    __IM  uint32_t            : 1;
    __IM  uint32_t lp_wsts_adc : 1;           /*!< [26..26] 1: Indicate ADC Wakeup event                                     */
    __IM  uint32_t lp_wsts_comp : 1;          /*!< [27..27] 1: Indicate Comparetor Wakeup event                              */
    __IM  uint32_t lp_wsts_sgpio : 1;         /*!< [28..28] 1: Indicate SGPIO Wakeup event                                   */
    __IM  uint32_t lp_wsts_aon : 1;           /*!< [29..29] 1: Indicate AON Wakeup event (0x128)                             */
    __IM  uint32_t lp_wsts_hs : 1;            /*!< [30..30] 1: Indicate HS Wakeup event                                      */
  } b;                                        /*!< bit fields for ls_syson_sys_slp_wake_sts */
} ls_syson_sys_slp_wake_sts_t, *pls_syson_sys_slp_wake_sts_t;

/**
  \brief Union type to access ls_syson_wl_int_ctrl (@ 0x00000110).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000110) WL Interrupt Control Register                              */
  
  struct {
    __IOM uint32_t wl_on_isr  : 1;            /*!< [0..0] WL On interrupt status                                             */
    __IOM uint32_t wl_off_isr : 1;            /*!< [1..1] WL Off interrupt status                                            */
    __IM  uint32_t            : 14;
    __IOM uint32_t wl_on_imr  : 1;            /*!< [16..16] WL On interrupt mask                                             */
    __IOM uint32_t wl_off_imr : 1;            /*!< [17..17] WL Off interrupt mask                                            */
  } b;                                        /*!< bit fields for ls_syson_wl_int_ctrl */
} ls_syson_wl_int_ctrl_t, *pls_syson_wl_int_ctrl_t;

/**
  \brief Union type to access ls_syson_wl_pwr_ctrl (@ 0x00000114).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000114) WL Power Control Register                                  */
  
  struct {
    __IOM uint32_t hw_auto_rsp_en : 1;        /*!< [0..0] 1: enable HW auto response                                         */
    __IM  uint32_t            : 7;
    __IM  uint32_t req_state  : 1;            /*!< [8..8] Req2active real state                                              */
    __IM  uint32_t real_state : 1;            /*!< [9..9] Ready2active real state                                            */
    __IM  uint32_t            : 6;
    __IOM uint32_t km0_set_state : 1;         /*!< [16..16] 1: KM0 set ready                                                 */
    __IOM uint32_t km0_clr_state : 1;         /*!< [17..17] 1: KM0 CLR ready                                                 */
  } b;                                        /*!< bit fields for ls_syson_wl_pwr_ctrl */
} ls_syson_wl_pwr_ctrl_t, *pls_syson_wl_pwr_ctrl_t;

/**
  \brief Union type to access ls_syson_sys_pwr_mgt_ctrl (@ 0x00000118).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000118) System Power Management Control Register                   */
  
  struct {
    __IOM uint32_t lp_pm_cmd_dslp : 1;        /*!< [0..0] 1: command LP SM to enter deep sleep state                         */
    __IOM uint32_t lp_pm_cmd_slp : 1;         /*!< [1..1] 1: command LP SM to enter sleep state                              */
  } b;                                        /*!< bit fields for ls_syson_sys_pwr_mgt_ctrl */
} ls_syson_sys_pwr_mgt_ctrl_t, *pls_syson_sys_pwr_mgt_ctrl_t;

/**
  \brief Union type to access ls_syson_sys_pwr_mgt_op (@ 0x00000120).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000120) System Power Management Option Control Register            */
  
  struct {
    __IOM uint32_t slp_pmopt_soc_en : 1;      /*!< [0..0] 1: power enable SOC platform when enter into power mode;
                                                   0: power off SoC domain                                                   */
    __IOM uint32_t slp_pmopt_4m_en : 1;       /*!< [1..1] 1: Enable 4M CLK when enter into power mode; 0: Disable
                                                   4M CLK                                                                    */
    __IOM uint32_t slp_pmopt_platform_clk_en : 1;/*!< [2..2] 1 : Enable platform clock when enter power mode0 : Disable
                                                   platform clock                                                            */
    __IOM uint32_t slp_pmopt_mem_pm_en : 1;   /*!< [3..3] 1: Enable memory when enter into power mode; reference
                                                   to 0xD8                                                                   */
    __IOM uint32_t slp_pmopt_ldo_nor_en : 1;  /*!< [4..4] 1: Enable LDO normal mode when enter into power mode;              */
    __IOM uint32_t slp_pmopt_syson_clk_gated : 1;/*!< [5..5] 1: Gated SYSON REG clock when enter into power mode;            */
    __IM  uint32_t            : 3;
    __IOM uint32_t dslp_pmopt_4m_en : 1;      /*!< [9..9] 1: Enable 4M CLK when enter into power mode; 0: Disable
                                                   4M CLK                                                                    */
  } b;                                        /*!< bit fields for ls_syson_sys_pwr_mgt_op */
} ls_syson_sys_pwr_mgt_op_t, *pls_syson_sys_pwr_mgt_op_t;

/**
  \brief Union type to access ls_syson_aon_wlp_wake_event (@ 0x00000128).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000128) REG_AON_WLP_EVENT_MSK                                      */
  
  struct {
    __IOM uint32_t gpio_wake  : 1;            /*!< [0..0] 1: enable GPIO wake                                                */
    __IOM uint32_t aon_wake_tim0 : 1;         /*!< [1..1] 1: enable AON timer wake                                           */
    __IOM uint32_t rtc_wake   : 1;            /*!< [2..2] 1: enable RTC wake                                                 */
    __IOM uint32_t adp_wake   : 1;            /*!< [3..3] 1: enable Adapter wake                                             */
  } b;                                        /*!< bit fields for ls_syson_aon_wlp_wake_event */
} ls_syson_aon_wlp_wake_event_t, *pls_syson_aon_wlp_wake_event_t;

/**
  \brief Union type to access ls_syson_aon_wlp_wake_sts (@ 0x0000012C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000012C) REG_AON_WLP_EVENT_STS                                      */
  
  struct {
    __IOM uint32_t gpio_wsts  : 1;            /*!< [0..0] 1: Indicate GPIO wake                                              */
    __IOM uint32_t aon_wsts_tim0 : 1;         /*!< [1..1] 1: Indicate AON timer wake                                         */
    __IOM uint32_t rtc_wsts   : 1;            /*!< [2..2] 1: Indicate RTC wake                                               */
    __IOM uint32_t adp_wsts   : 1;            /*!< [3..3] 1: Indicate Adapter wake                                           */
  } b;                                        /*!< bit fields for ls_syson_aon_wlp_wake_sts */
} ls_syson_aon_wlp_wake_sts_t, *pls_syson_aon_wlp_wake_sts_t;

/**
  \brief Union type to access ls_syson_gpioa_ctrl (@ 0x00000140).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000140) GPIOA Control Register                                     */
  
  struct {
    __IOM uint32_t gpioa_pwd33 : 1;           /*!< [0..0] 1: power down GPIO pad group A                                     */
    __IOM uint32_t gpioa_rstb33 : 1;          /*!< [1..1] 0: Reset GPIO pad Group A                                          */
    __IOM uint32_t gpioa_shdn_n : 1;          /*!< [2..2] 0: shutdown GPIO PAD Group A; 1: enable GPIO PAD group
                                                   A excluding GPIOA 0~9 shutdown control                                    */
    __IM  uint32_t            : 1;
    __IOM uint32_t gpioa_h3l1_sel : 1;        /*!< [4..4] GPIO Group A Voltage Select: 0: 1.8V, 1: 3V                        */
    __IOM uint32_t gpioa_drv_sel : 1;         /*!< [5..5] GPIO Group A Driving Select: 0: 8mA, 1: 16mA                       */
    __IM  uint32_t            : 2;
    __IOM uint32_t gpioa0_shdn_n : 1;         /*!< [8..8] 0: shutdown GPIOA0 PAD; 1: enable GPIOA0 PAD                       */
    __IOM uint32_t gpioa1_shdn_n : 1;         /*!< [9..9] 0: shutdown GPIOA1 PAD; 1: enable GPIOA1 PAD                       */
    __IOM uint32_t gpioa2_shdn_n : 1;         /*!< [10..10] 0: shutdown GPIOA2 PAD; 1: enable GPIOA2 PAD                     */
    __IOM uint32_t gpioa3_shdn_n : 1;         /*!< [11..11] 0: shutdown GPIOA3 PAD; 1: enable GPIOA3 PAD                     */
    __IOM uint32_t gpioa4_shdn_n : 1;         /*!< [12..12] 0: shutdown GPIOA4 PAD; 1: enable GPIOA4 PAD                     */
    __IOM uint32_t gpioa5_shdn_n : 1;         /*!< [13..13] 0: shutdown GPIOA5 PAD; 1: enable GPIOA5 PAD                     */
    __IOM uint32_t gpioa6_shdn_n : 1;         /*!< [14..14] 0: shutdown GPIOA6 PAD; 1: enable GPIOA6 PAD                     */
  } b;                                        /*!< bit fields for ls_syson_gpioa_ctrl */
} ls_syson_gpioa_ctrl_t, *pls_syson_gpioa_ctrl_t;

/**
  \brief Union type to access ls_syson_gpioa_pull_ctrl (@ 0x00000144).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000144) GPIOA Pull Control Register                                */
  
  struct {
    __IOM uint32_t gpioa0_pull_ctrl : 2;      /*!< [1..0] 2b'00: high impedence; 2b'01: pull low; 2b'10: pull high;
                                                   2b'11: reserved                                                           */
    __IOM uint32_t gpioa1_pull_ctrl : 2;      /*!< [3..2] 2b'00: high impedence; 2b'01: pull low; 2b'10: pull high;
                                                   2b'11: reserved                                                           */
    __IOM uint32_t gpioa2_pull_ctrl : 2;      /*!< [5..4] 2b'00: high impedence; 2b'01: pull low; 2b'10: pull high;
                                                   2b'11: reserved                                                           */
    __IOM uint32_t gpioa3_pull_ctrl : 2;      /*!< [7..6] 2b'00: high impedence; 2b'01: pull low; 2b'10: pull high;
                                                   2b'11: reserved                                                           */
    __IOM uint32_t gpioa4_pull_ctrl : 2;      /*!< [9..8] 2b'00: high impedence; 2b'01: pull low; 2b'10: pull high;
                                                   2b'11: reserved                                                           */
    __IOM uint32_t gpioa5_pull_ctrl : 2;      /*!< [11..10] 2b'00: high impedence; 2b'01: pull low; 2b'10: pull
                                                   high; 2b'11: reserved                                                     */
    __IOM uint32_t gpioa6_pull_ctrl : 2;      /*!< [13..12] 2b'00: high impedence; 2b'01: pull low; 2b'10: pull
                                                   high; 2b'11: reserved                                                     */
    __IOM uint32_t gpioa7_pull_ctrl : 2;      /*!< [15..14] 2b'00: high impedence; 2b'01: pull low; 2b'10: pull
                                                   high; 2b'11: reserved                                                     */
    __IOM uint32_t gpioa8_pull_ctrl : 2;      /*!< [17..16] 2b'00: high impedence; 2b'01: pull low; 2b'10: pull
                                                   high; 2b'11: reserved                                                     */
    __IOM uint32_t gpioa9_pull_ctrl : 2;      /*!< [19..18] 2b'00: high impedence; 2b'01: pull low; 2b'10: pull
                                                   high; 2b'11: reserved                                                     */
    __IOM uint32_t gpioa10_pull_ctrl : 2;     /*!< [21..20] 2b'00: high impedence; 2b'01: pull low; 2b'10: pull
                                                   high; 2b'11: reserved                                                     */
    __IOM uint32_t gpioa11_pull_ctrl : 2;     /*!< [23..22] 2b'00: high impedence; 2b'01: pull low; 2b'10: pull
                                                   high; 2b'11: reserved                                                     */
    __IOM uint32_t gpioa12_pull_ctrl : 2;     /*!< [25..24] 2b'00: high impedence; 2b'01: pull low; 2b'10: pull
                                                   high; 2b'11: reserved                                                     */
  } b;                                        /*!< bit fields for ls_syson_gpioa_pull_ctrl */
} ls_syson_gpioa_pull_ctrl_t, *pls_syson_gpioa_pull_ctrl_t;

/**
  \brief Union type to access ls_syson_gpioa_smt_ctrl (@ 0x00000148).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000148) GPIOA Smitt Triggerl Control Register                      */
  
  struct {
    __IOM uint32_t gpioa0_smt_en : 1;         /*!< [0..0] Enable GPIOA0 schmitt trigger                                      */
    __IOM uint32_t gpioa1_smt_en : 1;         /*!< [1..1] Enable GPIOA1 schmitt trigger                                      */
    __IOM uint32_t gpioa2_smt_en : 1;         /*!< [2..2] Enable GPIOA2 schmitt trigger                                      */
    __IOM uint32_t gpioa3_smt_en : 1;         /*!< [3..3] Enable GPIOA3 schmitt trigger                                      */
    __IOM uint32_t gpioa4_smt_en : 1;         /*!< [4..4] Enable GPIOA4 schmitt trigger                                      */
    __IOM uint32_t gpioa5_smt_en : 1;         /*!< [5..5] Enable GPIOA5 schmitt trigger                                      */
    __IOM uint32_t gpioa6_smt_en : 1;         /*!< [6..6] Enable GPIOA6 schmitt trigger                                      */
    __IOM uint32_t gpioa7_smt_en : 1;         /*!< [7..7] Enable GPIOA7 schmitt trigger                                      */
    __IOM uint32_t gpioa8_smt_en : 1;         /*!< [8..8] Enable GPIOA8 schmitt trigger                                      */
    __IOM uint32_t gpioa9_smt_en : 1;         /*!< [9..9] Enable GPIOA9 schmitt trigger                                      */
    __IOM uint32_t gpioa10_smt_en : 1;        /*!< [10..10] Enable GPIOA10 schmitt trigger                                   */
    __IOM uint32_t gpioa11_smt_en : 1;        /*!< [11..11] Enable GPIOA11 schmitt trigger                                   */
    __IOM uint32_t gpioa12_smt_en : 1;        /*!< [12..12] Enable GPIOA12 schmitt trigger                                   */
  } b;                                        /*!< bit fields for ls_syson_gpioa_smt_ctrl */
} ls_syson_gpioa_smt_ctrl_t, *pls_syson_gpioa_smt_ctrl_t;

/**
  \brief Union type to access ls_syson_lp_gdma_ctrl (@ 0x00000180).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000180) LP-GDMA Control Register                                   */
  
  struct {
    __IOM uint32_t lp_gdma_en : 1;            /*!< [0..0] enable LP GDMA block                                               */
    __IOM uint32_t lp_gdma_clk_en : 1;        /*!< [1..1] enable LP GDMA clock                                               */
    __IM  uint32_t            : 2;
    __IOM uint32_t lp_gdma_clk_alws_en : 1;   /*!< [4..4] gdma clk always enable                                             */
    __IOM uint32_t lp_gdma_clk_alws_dis : 1;  /*!< [5..5] gdma clk always disable                                            */
  } b;                                        /*!< bit fields for ls_syson_lp_gdma_ctrl */
} ls_syson_lp_gdma_ctrl_t, *pls_syson_lp_gdma_ctrl_t;

/**
  \brief Union type to access ls_syson_lp_gpio_ctrl (@ 0x00000184).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000184) GPIO Control Register                                      */
  
  struct {
    __IOM uint32_t lp_gpio_en : 1;            /*!< [0..0] 1: Enable LP GPIO block                                            */
    __IOM uint32_t lp_gpio_pclk_en : 1;       /*!< [1..1] 1: Enable LP GPIO Pclock                                           */
    __IOM uint32_t lp_gpio_sclk_en : 1;       /*!< [2..2] 1: Enable LP GPIO Sclock                                           */
    __IOM uint32_t lp_gpio_intr_clk_sel : 1;  /*!< [3..3] select interrupt clock source, 0: APB clock, 1: debounce
                                                   clock                                                                     */
  } b;                                        /*!< bit fields for ls_syson_lp_gpio_ctrl */
} ls_syson_lp_gpio_ctrl_t, *pls_syson_lp_gpio_ctrl_t;

/**
  \brief Union type to access ls_syson_lp_timer_ctrl (@ 0x00000188).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000188) G-Timer Control Register                                   */
  
  struct {
    __IOM uint32_t lp_timer_en : 1;           /*!< [0..0] 1: Enable LP Timer block                                           */
    __IOM uint32_t lp_pclk_en : 1;            /*!< [1..1] 1: Enable LP Timer Group0 Pclock                                   */
    __IOM uint32_t lp_sclk_en : 1;            /*!< [2..2] 1: Enable LP Timer Group0 Sclock                                   */
    __IOM uint32_t lp_intr_clk_sel : 1;       /*!< [3..3] select interrupt clock source, 0: APB clock, 1: timer
                                                   counter clock (controlled by BIT_SCLK_SEL[1:0])                           */
    __IOM uint32_t lp_timer_src_sel : 2;      /*!< [5..4] 00: 4MHz; 01: 2MHz; 10: 32KHz                                      */
  } b;                                        /*!< bit fields for ls_syson_lp_timer_ctrl */
} ls_syson_lp_timer_ctrl_t, *pls_syson_lp_timer_ctrl_t;

/**
  \brief Union type to access ls_syson_lp_tef_ctrl (@ 0x0000018C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000018C) Timer Event Function Control Register                      */
  
  struct {
    __IOM uint32_t pwm_en     : 1;            /*!< [0..0] TEF function enable control. 1: Enable LP TEF block                */
    __IOM uint32_t pwm_pclk_en : 1;           /*!< [1..1] TEF P-Clk enable control. 1: Enable LP TEF Pclock                  */
    __IOM uint32_t pwm_sclk_en : 1;           /*!< [2..2] TEF S-Clk enable control. 1: Enable LP TEF Sclock                  */
    __IOM uint32_t pwm_int_clk_sel : 1;       /*!< [3..3] TEF(Timer Event Function) clock source selection. 0:
                                                   APB CLK; 1: TIMER CLK                                                     */
    __IM  uint32_t            : 4;
    __IOM uint32_t pwm0_pin_en : 1;           /*!< [8..8] Enable pwm0 mux                                                    */
    __IOM uint32_t pwm1_pin_en : 1;           /*!< [9..9] Enable pwm1 mux                                                    */
    __IOM uint32_t pwm2_pin_en : 1;           /*!< [10..10] Enable pwm2 mux                                                  */
    __IOM uint32_t pwm3_pin_en : 1;           /*!< [11..11] Enable pwm3 mux                                                  */
    __IOM uint32_t pwm4_pin_en : 1;           /*!< [12..12] Enable pwm4 mux                                                  */
    __IOM uint32_t pwm5_pin_en : 1;           /*!< [13..13] Enable pwm5 mux                                                  */
    __IOM uint32_t pwm6_pin_en : 1;           /*!< [14..14] Enable pwm6 mux                                                  */
    __IOM uint32_t pwm7_pin_en : 1;           /*!< [15..15] Enable pwm7 mux                                                  */
    __IOM uint32_t pwm0_pin_sel : 2;          /*!< [17..16] PWM0 is muxed on: 00: GPIOA_0; 01: GPIOA_7; others
                                                   : rsvd                                                                    */
    __IOM uint32_t pwm1_pin_sel : 2;          /*!< [19..18] PWM1 is muxed on: 00: GPIOA_1; 01: GPIOA_8; others:
                                                   rsvd                                                                      */
    __IOM uint32_t pwm2_pin_sel : 2;          /*!< [21..20] PWM2 is muxed on: 00: GPIOA_2; 01: GPIOA_9; others:
                                                   rsvd                                                                      */
    __IOM uint32_t pwm3_pin_sel : 2;          /*!< [23..22] PWM3 is muxed on: 00: GPIOA_3; 01: GPIOA_10; others:
                                                   rsvd                                                                      */
    __IOM uint32_t pwm4_pin_sel : 2;          /*!< [25..24] PWM4 is muxed on: 00: GPIOA_4; others: rsvd                      */
    __IOM uint32_t pwm5_pin_sel : 2;          /*!< [27..26] PWM5 is muxed on: 00: GPIOA_5; others: rsvd                      */
    __IOM uint32_t pwm6_pin_sel : 2;          /*!< [29..28] PWM6 is muxed on: 00: GPIOA_6; others: rsvd                      */
    __IOM uint32_t pwm7_pin_sel : 2;          /*!< [31..30] PWM7 is muxed on: 00: GPIOA_13; others: rsvd                     */
  } b;                                        /*!< bit fields for ls_syson_lp_tef_ctrl */
} ls_syson_lp_tef_ctrl_t, *pls_syson_lp_tef_ctrl_t;

/**
  \brief Union type to access ls_syson_lp_adc_ctrl (@ 0x00000190).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000190) ADC Control Register                                       */
  
  struct {
    __IOM uint32_t en         : 1;            /*!< [0..0] 1: Enable LP ADC block                                             */
    __IOM uint32_t pclk_en    : 1;            /*!< [1..1] 1: Enable LP ADC Pclock                                            */
    __IOM uint32_t sclk_en    : 1;            /*!< [2..2] 1: Enable LP ADC Sclock                                            */
    __IOM uint32_t int_clk_sel : 1;           /*!< [3..3] 0: pclk; 1:sclk                                                    */
    __IM  uint32_t            : 4;
    __IOM uint32_t adc0_mux_en : 1;           /*!< [8..8] 1: ADC0 is muxed on GPIOA_0                                        */
    __IOM uint32_t adc1_mux_en : 1;           /*!< [9..9] 1: ADC1 is muxed on GPIOA_1                                        */
    __IOM uint32_t adc2_mux_en : 1;           /*!< [10..10] 1: ADC2 is muxed on GPIOA_2                                      */
    __IOM uint32_t adc3_mux_en : 1;           /*!< [11..11] 1: ADC3 is muxed on GPIOA_3                                      */
    __IOM uint32_t adc4_mux_en : 1;           /*!< [12..12] 1: ADC4 is muxed on GPIOA_4                                      */
    __IOM uint32_t adc5_mux_en : 1;           /*!< [13..13] 1: ADC5 is muxed on GPIOA_5                                      */
    __IOM uint32_t adc6_mux_en : 1;           /*!< [14..14] 1: ADC6 is muxed on GPIOA_6                                      */
  } b;                                        /*!< bit fields for ls_syson_lp_adc_ctrl */
} ls_syson_lp_adc_ctrl_t, *pls_syson_lp_adc_ctrl_t;

/**
  \brief Union type to access ls_syson_lp_uart_ctrl (@ 0x00000194).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000194) UART Control Register                                      */
  
  struct {
    __IOM uint32_t lp_uart0_en : 1;           /*!< [0..0] 1: Enable LP UART0 block                                           */
    __IOM uint32_t lp_uart0_bd_en : 1;        /*!< [1..1] 1: Enable LP UART0 bus domain                                      */
    __IOM uint32_t lp_uart0_pclk_en : 1;      /*!< [2..2] 1: Enable LP UART0 Pclock                                          */
    __IOM uint32_t lp_uart0_sclk_en : 1;      /*!< [3..3] 1: Enable LP UART0 Sclock                                          */
    __IOM uint32_t lp_uart0_mux_en : 1;       /*!< [4..4] 1. Enable UART0 MUX                                                */
    __IOM uint32_t lp_uart0_flow_ctrl_en : 1; /*!< [5..5] 1. Enable RTS/CTS                                                  */
    __IOM uint32_t lp_uart0_mux_sel : 1;      /*!< [6..6] 0: UART0 is muxed to GPIOA_7~8                                     */
    __IM  uint32_t            : 1;
    __IOM uint32_t lp_uart1_en : 1;           /*!< [8..8] 1: Enable LP UART1 block                                           */
    __IOM uint32_t lp_uart1_bd_en : 1;        /*!< [9..9] 1: Enable LP UART1 bus domain                                      */
    __IOM uint32_t lp_uart1_pclk_en : 1;      /*!< [10..10] 1: Enable LP UART1 Pclock                                        */
    __IOM uint32_t lp_uart1_sclk_en : 1;      /*!< [11..11] 1: Enable LP UART1 Sclock                                        */
    __IOM uint32_t lp_uart1_mux_en : 1;       /*!< [12..12] 1. Enable UART1 MUX                                              */
    __IOM uint32_t lp_uart1_flow_ctrl_en : 1; /*!< [13..13] 1. Enable RTS/CTS                                                */
    __IOM uint32_t lp_uart1_mux_sel : 1;      /*!< [14..14] 0: UART0 is muxed to GPIOA_0~3                                   */
  } b;                                        /*!< bit fields for ls_syson_lp_uart_ctrl */
} ls_syson_lp_uart_ctrl_t, *pls_syson_lp_uart_ctrl_t;

/**
  \brief Union type to access ls_syson_lp_i2c_ctrl (@ 0x0000019C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000019C) I2C Control Register                                       */
  
  struct {
    __IOM uint32_t en         : 1;            /*!< [0..0] 1: Enable LP I2C block                                             */
    __IOM uint32_t pclk_en    : 1;            /*!< [1..1] 1: Enable LP I2C Pclock                                            */
    __IOM uint32_t sclk_en    : 1;            /*!< [2..2] 1: Enable LP I2C Sclock                                            */
    __IM  uint32_t            : 1;
    __IOM uint32_t mux_en     : 1;            /*!< [4..4] 1: Enable I2C MUX                                                  */
    __IOM uint32_t mux_sel    : 2;            /*!< [6..5] I2C is muxed on: 00 : GPIOA_2~3; 01 : GPIOA_4~5; 10 :
                                                   GPIOA_7~8; 11 : GPIOA_9~A                                                 */
    __IM  uint32_t            : 9;
    __IOM uint32_t fltr_en    : 1;            /*!< [16..16] Filter Enable. 1: Enable, 0: Disable                             */
    __IOM uint32_t cali_in_en : 1;            /*!< [17..17] RC Calibrate Input Enable. 1: Enable, 0: Disable                 */
    __IOM uint32_t ana_en     : 1;            /*!< [18..18] RC Analog Enable. 1: Enable, 0: Disable                          */
    __IOM uint32_t RSVD       : 13;           /*!< [31..19] Reserved                                                         */
  } b;                                        /*!< bit fields for ls_syson_lp_i2c_ctrl */
} ls_syson_lp_i2c_ctrl_t, *pls_syson_lp_i2c_ctrl_t;

/**
  \brief Union type to access ls_syson_lp_sgpio_ctrl (@ 0x000001A0).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000001A0) SGPIO Control Register                                     */
  
  struct {
    __IOM uint32_t lp_sgpio_en : 1;           /*!< [0..0] 1: Enable LP SGPIO block                                           */
    __IOM uint32_t lp_sgpio_pclk_en : 1;      /*!< [1..1] 1: Enable LP SGPIO Pclock                                          */
    __IOM uint32_t lp_sgpio_sclk_en : 1;      /*!< [2..2] 1: Enable LP SGPIO Sclock                                          */
    __IM  uint32_t            : 1;
    __IOM uint32_t lp_sgpio_mux_en : 1;       /*!< [4..4] 1: Enable LP SGPIO MUX                                             */
    __IOM uint32_t lp_sgpio_mux_sel : 1;      /*!< [5..5] SGPIO is muxed on: 00 : GPIOA_2~3; 10 : GPIOA_7~8                  */
    __IOM uint32_t RSVD       : 26;           /*!< [31..6] Reserved                                                          */
  } b;                                        /*!< bit fields for ls_syson_lp_sgpio_ctrl */
} ls_syson_lp_sgpio_ctrl_t, *pls_syson_lp_sgpio_ctrl_t;

/**
  \brief Union type to access ls_syson_lp_qdr_ctrl (@ 0x000001A4).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000001A4) QDR Control Register                                       */
  
  struct {
    __IOM uint32_t lp_qdr_en  : 1;            /*!< [0..0] 1: Enable LP QDR block                                             */
    __IOM uint32_t lp_qdr_pclk_en : 1;        /*!< [1..1] 1: Enable LP QDR Pclock                                            */
    __IOM uint32_t lp_qdr_sclk_en : 1;        /*!< [2..2] 1: Enable LP QDR Sclock                                            */
    __IOM uint32_t lp_qdr_intr_clk_sel : 1;   /*!< [3..3] 0: 2Mhz, 1: 32Khz                                                  */
    __IOM uint32_t lp_qdr_sclk_sel : 1;       /*!< [4..4] 0: 2Mhz, 1: 32Khz                                                  */
    __IM  uint32_t            : 3;
    __IOM uint32_t lp_qdr_mux_en : 1;         /*!< [8..8] 1: Enable QDR MUX                                                  */
    __IOM uint32_t lp_qdr_idx_dis : 1;        /*!< [9..9] 1: Enable QDR IDX                                                  */
    __IOM uint32_t lp_qdr_mux_sel : 1;        /*!< [10..10] QDR is muxed on 00 : GPIOA_0~2 10 : GPIOA_7,8,13                 */
    __IOM uint32_t RSVD       : 21;           /*!< [31..11] Reserved                                                         */
  } b;                                        /*!< bit fields for ls_syson_lp_qdr_ctrl */
} ls_syson_lp_qdr_ctrl_t, *pls_syson_lp_qdr_ctrl_t;

/**
  \brief Union type to access ls_syson_lp_ir_ctrl (@ 0x000001A8).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000001A8) IR Control Register                                        */
  
  struct {
    __IOM uint32_t lp_ir_en   : 1;            /*!< [0..0] 1: Enable LP IR block                                              */
    __IOM uint32_t lp_ir_pclk_en : 1;         /*!< [1..1] 1: Enable LP IR Pclock                                             */
    __IOM uint32_t lp_ir_sclk_en : 1;         /*!< [2..2] 1: Enable LP IR Sclock                                             */
    __IM  uint32_t            : 1;
    __IOM uint32_t lp_ir_mux_en : 1;          /*!< [4..4] 1: Enable LP IR MUX                                                */
    __IOM uint32_t lp_ir_rx_dis : 1;          /*!< [5..5] 1: Disable LP IR RX                                                */
    __IOM uint32_t lp_ir_tx_dis : 1;          /*!< [6..6] 1: Disable LP IR TX                                                */
    __IOM uint32_t lp_ir_mux_sel : 1;         /*!< [7..7] IR is muxed on: 0 : GPIOA_7~8; 1 : GPIOA_2~3                       */
    __IOM uint32_t RSVD       : 24;           /*!< [31..8] Reserved                                                          */
  } b;                                        /*!< bit fields for ls_syson_lp_ir_ctrl */
} ls_syson_lp_ir_ctrl_t, *pls_syson_lp_ir_ctrl_t;

/**
  \brief Union type to access ls_syson_sys_system_cfg0 (@ 0x000001F0).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000001F0) System Configuration Register 0                            */
  
  struct {
    __IM  uint32_t chip_ver   : 4;            /*!< [3..0] Chip version: 0000: A-Cut; 0001: B-Cut; 0010: C-Cut;
                                                   0011: D-Cut etc.                                                          */
    __IM  uint32_t vendor_id  : 2;            /*!< [5..4] Vendor ID/Download FW version ; 00: TSMC , 01: SMIC,
                                                   10: UMC                                                                   */
    __IM  uint32_t            : 1;
    __IM  uint32_t chip_type  : 1;            /*!< [7..7] TestChip ID, 1: Test (RLE); 0: MP (RL)                             */
    __IM  uint32_t            : 16;
    __IM  uint32_t syscfg_alf_en : 1;         /*!< [24..24] 0: Autoload fail                                                 */
    __IM  uint32_t syscfg_test_mod_en : 1;    /*!< [25..25] 0: normal mode 1: test mode                                      */
    __IM  uint32_t syscfg_trp_spsldo_sel : 1; /*!< [26..26] Trapped Selection for SPS 0: SWR mode; 1: LDO mode               */
    __IM  uint32_t            : 1;
    __IM  uint32_t ext_rstb   : 1;            /*!< [28..28] vht_sigb_crc_sel0                                                */
    __IM  uint32_t ext_clk    : 1;            /*!< [29..29] DB_OPT1/EXT_CLK                                                  */
    __IM  uint32_t chg_li_exist : 1;          /*!< [30..30] 1: CHG or Li battery exist                                       */
    __IM  uint32_t syscfg_bd_pkg_sel : 1;     /*!< [31..31] Trapped PKG_ENG_SEL value 0: normal package; 1: engineering
                                                   mode                                                                      */
  } b;                                        /*!< bit fields for ls_syson_sys_system_cfg0 */
} ls_syson_sys_system_cfg0_t, *pls_syson_sys_system_cfg0_t;

/**
  \brief Union type to access ls_syson_sys_system_cfg1 (@ 0x000001F4).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000001F4) System Configuration Register 1                            */
  
  struct {
    __IM  uint32_t syscfg_aldn_sts : 1;       /*!< [0..0] 1: SYS CFG autoload done; 0: SYSCFG autoload not ready
                                                   (if done, system reg can not write)                                       */
    __IM  uint32_t            : 7;
    __IM  uint32_t sys_xclk_vld : 1;          /*!< [8..8] Xtal Clock Stable, 1: Clock Stable                                 */
    __IM  uint32_t sys_syspll_clk_rdy : 1;    /*!< [9..9] SYS PLL Clock Stable, 1: Clock Stable                              */
    __IM  uint32_t            : 6;
    __IM  uint32_t v15_vld    : 1;            /*!< [16..16] 1.5V Power Ready, 1: Power Ready                                 */
    __IM  uint32_t            : 7;
    __IM  uint32_t syscfg_trp_efuse_sel : 1;  /*!< [24..24] 0: EEPROM; 1: EFUSE                                              */
    __IM  uint32_t syscfg_trp_spsldo_sel : 1; /*!< [25..25] Trapped Selection for SPS: 0: SWR mode; 1: LDO mode.
                                                   Trapped SDIO_DEV_SEL value: 0: SDIO device; 1: SDIO host
                                                   mode                                                                      */
    __IM  uint32_t syscfg_trp_sdio_dev_sel : 1;/*!< [26..26] 1 : Host mode; 0 : device mode                                  */
    __IM  uint32_t syscfg_trp_boot_sel : 1;   /*!< [27..27] BOOT type select: 1: Boot Decide from EFUSE setting;
                                                   0: boot from ROM                                                          */
    __IM  uint32_t syscfg_trp_icfg : 4;       /*!< [31..28] Trapped ICFG data value 0: normall mode XXXX: the other
                                                   mode (Test Mode)                                                          */
  } b;                                        /*!< bit fields for ls_syson_sys_system_cfg1 */
} ls_syson_sys_system_cfg1_t, *pls_syson_sys_system_cfg1_t;

/**
  \brief Union type to access ls_syson_sys_system_cfg2 (@ 0x000001F8).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000001F8) System Configuration Register 2                            */
  
  struct {
    __IOM uint32_t syscfg_rom_info : 8;       /*!< [7..0] ROM Information                                                    */
  } b;                                        /*!< bit fields for ls_syson_sys_system_cfg2 */
} ls_syson_sys_system_cfg2_t, *pls_syson_sys_system_cfg2_t;

/** @} */ /* End of group ls_hal_ls_syson_reg */
/// @endcond /* End of condition DOXYGEN_GENERAL_REG_TYPE || DOXYGEN_LS_SYSON_REG_TYPE */


#ifdef  __cplusplus
}
#endif

#endif    // end of #ifndef _RTL8195BLP_SYSON_LS_SYSON_TYPE_H_

