/**************************************************************************//**
 * @file      rtl8195bhp_video_sys_type.h
 * @brief
 * @version   V1.10
 * @date      2017-5-23 10:15:0
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

#ifndef _RTL8195BHP_VIDEO_SYS_TYPE_H_
#define _RTL8195BHP_VIDEO_SYS_TYPE_H_

#ifdef  __cplusplus
extern "C"
{
#endif

/// @cond DOXYGEN_VIDEO_REG_TYPE

/**
 * @addtogroup hs_hal_video_reg VIDEO Registers.
 * @ingroup hs_hal_video
 * @{
 */



/* =========================================================================================================================== */
/* ================                                         VIDEO_SYS                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief Video group system (VIDEO_SYS)
  */

typedef struct {                                /*!< (@ 0x40000000) VIDEO_SYS Structure                                        */
  
  union {
    __IOM uint16_t reg_sys_pwr_ctrl;            /*!< (@ 0x00000000) reg_sys_pwr_ctrl                                           */
    
    struct {
      __IOM uint16_t bit_soc_spc_en : 1;        /*!< [0..0] 1:enable HS SOC domain small power cut                             */
      __IOM uint16_t bit_soc_lpc_en : 1;        /*!< [1..1] 1:enable HS SOC domain large power cut                             */
      __IOM uint16_t bit_video_spc_en : 1;      /*!< [2..2] 1:enable video domain small power cut                              */
      __IOM uint16_t bit_video_lpc_en : 1;      /*!< [3..3] 1:enable video domain large power cut                              */
      __IOM uint16_t bit_wlon_spc_en : 1;       /*!< [4..4] 1:enable WLON domain small power cut                               */
      __IOM uint16_t bit_wlon_lpc_en : 1;       /*!< [5..5] 1:enable WLON domain large power cut                               */
    } reg_sys_pwr_ctrl_b;
  } ;
  
  union {
    __IOM uint16_t reg_sys_iso_ctrl;            /*!< (@ 0x00000002) reg_sys_iso_ctrl                                           */
    
    struct {
      __IOM uint16_t bit_sys_iso_hssoc : 1;     /*!< [0..0] 1: isolation HS SoC to HS ON domain; 0: disable isolation          */
      __IOM uint16_t bit_sys_iso_vdo : 1;       /*!< [1..1] 1: isolation Vedio to HS on domain; 0: disable isolation           */
      __IOM uint16_t bit_sys_iso_wl : 1;        /*!< [2..2] 1: isolation WLON to HS on domain; 0: disable isolation            */
    } reg_sys_iso_ctrl_b;
  } ;
  __IM  uint32_t  RESERVED;
  
  union {
    __IOM uint32_t reg_sys_func_en;             /*!< (@ 0x00000008) reg_sys_func_en                                            */
    
    struct {
      __IOM uint32_t bit_hs_fen_eeldr : 1;      /*!< [0..0] 1: enable EE Loader; 0: disable EE loader                          */
      __IM  uint32_t            : 1;
      __IOM uint32_t bit_tm9_en : 1;            /*!< [2..2] 1: enable TM9 ; 0: reset                                           */
      __IOM uint32_t bit_platform_en : 1;       /*!< [3..3] 1: enable platform                                                 */
      __IOM uint32_t bit_vendor_en : 1;         /*!< [4..4] 1: enable vendor                                                   */
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_hssys_clk_auto_gated : 1;/*!< [8..8] 1: Enable HS syson register auto gated                           */
      __IM  uint32_t            : 7;
      __IOM uint32_t bit_hs_soc_en : 1;         /*!< [16..16] 1: enable HS SOC domain                                          */
      __IOM uint32_t bit_hs_video_en : 1;       /*!< [17..17] 1: enable video domain                                           */
    } reg_sys_func_en_b;
  } ;
  __IM  uint32_t  RESERVED1[9];
  
  union {
    __IOM uint32_t reg_hs_pll_isp_ctrl0;        /*!< (@ 0x00000030) reg_hs_pll_isp_ctrl0                                       */
    
    struct {
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_pll_isp_div_sel : 3;   /*!< [5..3] output divider selection. Default=000 000=/1, 100=/4,
                                                     110=/8, 111=/16                                                           */
      __IOM uint32_t bit_pll_isp_ps_en : 1;     /*!< [6..6] phase selector enable                                              */
      __IOM uint32_t bit_pll_isp_div2_en : 1;   /*!< [7..7] output clk div 2 enable                                            */
      __IOM uint32_t bit_pll_isp_clk_en : 1;    /*!< [8..8] output clk enable                                                  */
      __IOM uint32_t bit_pll_isp_fref_edge_sel : 1;/*!< [9..9] 0:fref,1:frefb                                                  */
      __IOM uint32_t bit_pll_isp_c3_set : 2;    /*!< [11..10] Cp selection. Default=5p 00: Cp=3p, 01: Cp=4p, 10:
                                                     Cp=5p, 11: Cp=6p                                                          */
      __IOM uint32_t bit_pll_isp_r3_sel : 3;    /*!< [14..12] R3 selection. Default=1k 000: R3=0k, 001: R3=0.5k,
                                                     010: R3=1k, 011: R3=1.5k, 100: R3=2k, 101: R3=2.5k, 110:
                                                     R3=3k, 111: R3=3.5k;                                                      */
      __IOM uint32_t bit_pll_isp_cs_sel : 2;    /*!< [16..15] Cs selection. Default=50p 00: Cs=30p, 01: Cs=40p, 10:
                                                     Cs=50p, 11: Cs=60p                                                        */
      __IOM uint32_t bit_pll_isp_rs_sel : 3;    /*!< [19..17] Rs selection. Default=14k 000: Rs=2k, 001: Rs=4k, 010:
                                                     Rs=6k, 011: Rs=8k, 100: Rs=10k, 101: Rs=12k, 110: Rs=14k,
                                                     111: Rs=16k;                                                              */
      __IOM uint32_t bit_pll_isp_cp_sel : 2;    /*!< [21..20] Cp selection. Default=3p 00: Cp=3p, 01: Cp=4p, 10:
                                                     Cp=5p, 11: Cp=6p                                                          */
      __IOM uint32_t bit_pll_isp_ps_sel : 3;    /*!< [24..22] PLL_ISP_PS_SEL                                                   */
      __IOM uint32_t bit_pll_isp_wdg_en : 1;    /*!< [25..25] 0: watch dog on ,1: watch dog off                                */
      __IOM uint32_t bit_pll_isp_cpc_sel : 3;   /*!< [28..26] charge pump current selection . Default=5u CP current
                                                     select : 000: Icp=5uA, 001: Icp=10uA, 010: Icp=15uA, 011:
                                                     Icp=20uA; 100:Icp=25uA, 101: Icp=30uA, 110: Icp=35uA, 111:
                                                     Icp=40uA;                                                                 */
      __IOM uint32_t bit_pll_isp_en : 1;        /*!< [29..29] (need pwl signal) 0->1                                           */
      __IOM uint32_t bit_pll_isp_div_en : 1;    /*!< [30..30] input divider enable (need pwl signal) 0->1                      */
      __IOM uint32_t bit_pll_isp_powcut_en : 1; /*!< [31..31] erc enable.                                                      */
    } reg_hs_pll_isp_ctrl0_b;
  } ;
  
  union {
    __IOM uint32_t reg_hs_pll_isp_ctrl1;        /*!< (@ 0x00000034) reg_hs_pll_isp_ctrl1                                       */
    
    struct {
      __IM  uint32_t            : 5;
      __IOM uint32_t bit_pll_isp_divn_sdm : 6;  /*!< [10..5] PLL_ISP_DIVN_SDM                                                  */
      __IOM uint32_t bit_pll_isp_bb_dbg_sel_afe_sdm : 4;/*!< [14..11] PLL_ISP_BB_DBG_SEL_AFE_SDM                               */
      __IOM uint32_t bit_pll_isp_trig_rreq_en : 1;/*!< [15..15] freq. step up or step down enable                              */
      __IOM uint32_t bit_pll_isp_step_freq_sel : 4;/*!< [19..16] step size selection for switching freq.                       */
      __IOM uint32_t bit_pll_isp_tbase_freq_sel : 4;/*!< [23..20] for output clk step up or step down                          */
      __IOM uint32_t bit_pll_isp_freq_sel : 4;  /*!< [27..24] output clk selection, Default=400MHz                             */
      __IOM uint32_t bit_pll_isp_xtal_sel : 4;  /*!< [31..28] xtal selection, Default=40MHz 0000: 40MHz, 0001: 25MHz,
                                                     0010: 13MHz, 0011: 19.2MHz 0100: 20MHz, 0101: 26MHz, 0110:
                                                     38.4MHz, 0111: 17.664MHz 1000: 16MHz, 1001: 14.138MHz 1010:
                                                     12MHz, 1011: 52MHz 1100: 48MHz, 1101: 27MHz, 1110: 24MHz,
                                                     1111: none                                                                */
    } reg_hs_pll_isp_ctrl1_b;
  } ;
  
  union {
    __IOM uint32_t reg_hs_pll_isp_ctrl2;        /*!< (@ 0x00000038) reg_hs_pll_isp_ctrl2                                       */
    
    struct {
      __IM  uint32_t            : 5;
      __IOM uint32_t bit_pll_isp_ssc_en : 1;    /*!< [5..5] ssc enable. Default=0                                              */
      __IOM uint32_t bit_pll_isp_ssc_freq_sel : 13;/*!< [18..6] ssc freq selection                                             */
      __IOM uint32_t bit_pll_isp_ssc_step_sel : 13;/*!< [31..19] ssc step size selection.                                      */
    } reg_hs_pll_isp_ctrl2_b;
  } ;
  
  union {
    __IOM uint32_t reg_hs_pll_isp_ctrl3;        /*!< (@ 0x0000003C) reg_hs_pll_isp_ctrl3                                       */
    
    struct {
      __IM  uint32_t            : 15;
      __IOM uint32_t bit_pll_isp_sdm_order_sel : 1;/*!< [15..15] SDM order: 0:2nd order, 1:3rd order                           */
      __IOM uint32_t bit_pll_isp_sdm_fon : 3;   /*!< [18..16] N code, feedback divider number 1 for 1/8                        */
      __IOM uint32_t bit_pll_isp_sdm_fof : 13;  /*!< [31..19] F code, feedback divider number 1for 1/8*1/2^13                  */
    } reg_hs_pll_isp_ctrl3_b;
  } ;
  
  union {
    __IOM uint32_t reg_hs_pll_isps_ctrl0;       /*!< (@ 0x00000040) reg_hs_pll_isps_ctrl0                                      */
    
    struct {
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_pll_isps_div_sel : 3;  /*!< [5..3] output divider selection. Default=000 000=/1, 100=/4,
                                                     110=/8, 111=/16                                                           */
      __IOM uint32_t bit_pll_isps_ps_en : 1;    /*!< [6..6] phase selector enable                                              */
      __IOM uint32_t bit_pll_isps_div2_en : 1;  /*!< [7..7] output clk div 2 enable                                            */
      __IOM uint32_t bit_pll_isps_clk_en : 1;   /*!< [8..8] output clk enable                                                  */
      __IOM uint32_t bit_pll_isps_fref_edge_sel : 1;/*!< [9..9] 0:fref,1:frefb                                                 */
      __IOM uint32_t bit_pll_isps_c3_set : 2;   /*!< [11..10] Cp selection. Default=5p 00: Cp=3p, 01: Cp=4p, 10:
                                                     Cp=5p, 11: Cp=6p                                                          */
      __IOM uint32_t bit_pll_isps_r3_sel : 3;   /*!< [14..12] R3 selection. Default=1k 000: R3=0k, 001: R3=0.5k,
                                                     010: R3=1k, 011: R3=1.5k, 100: R3=2k, 101: R3=2.5k, 110:
                                                     R3=3k, 111: R3=3.5k;                                                      */
      __IOM uint32_t bit_pll_isps_cs_sel : 2;   /*!< [16..15] Cs selection. Default=50p 00: Cs=30p, 01: Cs=40p, 10:
                                                     Cs=50p, 11: Cs=60p                                                        */
      __IOM uint32_t bit_pll_isps_rs_sel : 3;   /*!< [19..17] Rs selection. Default=14k 000: Rs=2k, 001: Rs=4k, 010:
                                                     Rs=6k, 011: Rs=8k, 100: Rs=10k, 101: Rs=12k, 110: Rs=14k,
                                                     111: Rs=16k;                                                              */
      __IOM uint32_t bit_pll_isps_cp_sel : 2;   /*!< [21..20] Cp selection. Default=3p 00: Cp=3p, 01: Cp=4p, 10:
                                                     Cp=5p, 11: Cp=6p                                                          */
      __IOM uint32_t bit_pll_isps_ps_sel : 3;   /*!< [24..22] PLL_ISPS_PS_SEL                                                  */
      __IOM uint32_t bit_pll_isps_wdg_en : 1;   /*!< [25..25] 0: watch dog on ,1: watch dog off                                */
      __IOM uint32_t bit_pll_isps_cpc_sel : 3;  /*!< [28..26] charge pump current selection . Default=5u CP current
                                                     select : 000: Icp=5uA, 001: Icp=10uA, 010: Icp=15uA, 011:
                                                     Icp=20uA; 100:Icp=25uA, 101: Icp=30uA, 110: Icp=35uA, 111:
                                                     Icp=40uA;                                                                 */
      __IOM uint32_t bit_pll_isps_en : 1;       /*!< [29..29] (need pwl signal) 0->1                                           */
      __IOM uint32_t bit_pll_isps_div_en : 1;   /*!< [30..30] input divider enable (need pwl signal) 0->1                      */
      __IOM uint32_t bit_pll_isps_powcut_en : 1;/*!< [31..31] erc enable.                                                      */
    } reg_hs_pll_isps_ctrl0_b;
  } ;
  
  union {
    __IOM uint32_t reg_hs_pll_isps_ctrl1;       /*!< (@ 0x00000044) reg_hs_pll_isps_ctrl1                                      */
    
    struct {
      __IM  uint32_t            : 5;
      __IOM uint32_t bit_pll_isps_divn_sdm : 6; /*!< [10..5] PLL_ISPS_DIVN_SDM                                                 */
      __IOM uint32_t bit_pll_isps_bb_dbg_sel_afe_sdm : 4;/*!< [14..11] PLL_ISPS_BB_DBG_SEL_AFE_SDM                             */
      __IOM uint32_t bit_pll_isps_trig_rreq_en : 1;/*!< [15..15] freq. step up or step down enable                             */
      __IOM uint32_t bit_pll_isps_step_freq_sel : 4;/*!< [19..16] step size selection for switching freq.                      */
      __IOM uint32_t bit_pll_isps_tbase_freq_sel : 4;/*!< [23..20] for output clk step up or step down                         */
      __IOM uint32_t bit_pll_isps_freq_sel : 4; /*!< [27..24] output clk selection, Default=74.25MHz/37.125MHz 0010:
                                                     74.25MHz/37.125MHz (297MHz/4, 297MHz/8) 0100: 54MHz/27MHz
                                                     (216MHz/4, 216MHz/8) 0110: 24MHz/12MHz (192MHz/8, 192MHz/16)              */
      __IOM uint32_t bit_pll_isps_xtal_sel : 4; /*!< [31..28] xtal selection, Default=40MHz 0000: 40MHz, 0001: 25MHz,
                                                     0010: 13MHz, 0011: 19.2MHz 0100: 20MHz, 0101: 26MHz, 0110:
                                                     38.4MHz, 0111: 17.664MHz 1000: 16MHz, 1001: 14.138MHz 1010:
                                                     12MHz, 1011: 52MHz 1100: 48MHz, 1101: 27MHz, 1110: 24MHz,
                                                     1111: none                                                                */
    } reg_hs_pll_isps_ctrl1_b;
  } ;
  
  union {
    __IOM uint32_t reg_hs_pll_isps_ctrl2;       /*!< (@ 0x00000048) reg_hs_pll_isps_ctrl2                                      */
    
    struct {
      __IM  uint32_t            : 5;
      __IOM uint32_t bit_pll_isps_ssc_en : 1;   /*!< [5..5] ssc enable. Default=0                                              */
      __IOM uint32_t bit_pll_isps_ssc_freq_sel : 13;/*!< [18..6] ssc freq selection                                            */
      __IOM uint32_t bit_pll_isps_ssc_step_sel : 13;/*!< [31..19] ssc step size selection.                                     */
    } reg_hs_pll_isps_ctrl2_b;
  } ;
  
  union {
    __IOM uint32_t reg_hs_pll_isps_ctrl3;       /*!< (@ 0x0000004C) reg_hs_pll_isps_ctrl3                                      */
    
    struct {
      __IM  uint32_t            : 15;
      __IOM uint32_t bit_pll_isps_sdm_order_sel : 1;/*!< [15..15] SDM order: 0:2nd order, 1:3rd order                          */
      __IOM uint32_t bit_pll_isps_sdm_fon : 3;  /*!< [18..16] N code, feedback divider number 1 for 1/8                        */
      __IOM uint32_t bit_pll_isps_sdm_fof : 13; /*!< [31..19] F code, feedback divider number 1for 1/8*1/2^13                  */
    } reg_hs_pll_isps_ctrl3_b;
  } ;
  
  union {
    __IOM uint32_t reg_hs_pll_sys_ctrl0;        /*!< (@ 0x00000050) reg_hs_pll_sys_ctrl0                                       */
    
    struct {
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_pll_sys_div_sel : 3;   /*!< [5..3] output divider selection. Default=000 000=/1, 100=/4,
                                                     110=/8, 111=/16                                                           */
      __IOM uint32_t bit_pll_sys_ps_en : 1;     /*!< [6..6] phase selector enable                                              */
      __IOM uint32_t bit_pll_sys_div2_en : 1;   /*!< [7..7] output clk div 2 enable                                            */
      __IOM uint32_t bit_pll_sys_clk_en : 1;    /*!< [8..8] output clk enable                                                  */
      __IOM uint32_t bit_pll_sys_fref_edge_sel : 1;/*!< [9..9] 0:fref,1:frefb                                                  */
      __IOM uint32_t bit_pll_sys_c3_set : 2;    /*!< [11..10] Cp selection. Default=5p 00: Cp=3p, 01: Cp=4p, 10:
                                                     Cp=5p, 11: Cp=6p                                                          */
      __IOM uint32_t bit_pll_sys_r3_sel : 3;    /*!< [14..12] R3 selection. Default=1k 000: R3=0k, 001: R3=0.5k,
                                                     010: R3=1k, 011: R3=1.5k, 100: R3=2k, 101: R3=2.5k, 110:
                                                     R3=3k, 111: R3=3.5k;                                                      */
      __IOM uint32_t bit_pll_sys_cs_sel : 2;    /*!< [16..15] Cs selection. Default=50p 00: Cs=30p, 01: Cs=40p, 10:
                                                     Cs=50p, 11: Cs=60p                                                        */
      __IOM uint32_t bit_pll_sys_rs_sel : 3;    /*!< [19..17] Rs selection. Default=14k 000: Rs=2k, 001: Rs=4k, 010:
                                                     Rs=6k, 011: Rs=8k, 100: Rs=10k, 101: Rs=12k, 110: Rs=14k,
                                                     111: Rs=16k;                                                              */
      __IOM uint32_t bit_pll_sys_cp_sel : 2;    /*!< [21..20] Cp selection. Default=3p 00: Cp=3p, 01: Cp=4p, 10:
                                                     Cp=5p, 11: Cp=6p                                                          */
      __IOM uint32_t bit_pll_sys_ps_sel : 3;    /*!< [24..22] PLL_SYS_PS_SEL                                                   */
      __IOM uint32_t bit_pll_sys_wdg_en : 1;    /*!< [25..25] 0: watch dog on ,1: watch dog off                                */
      __IOM uint32_t bit_pll_sys_cpc_sel : 3;   /*!< [28..26] charge pump current selection . Default=5u CP current
                                                     select : 000: Icp=5uA, 001: Icp=10uA, 010: Icp=15uA, 011:
                                                     Icp=20uA; 100:Icp=25uA, 101: Icp=30uA, 110: Icp=35uA, 111:
                                                     Icp=40uA;                                                                 */
      __IOM uint32_t bit_pll_sys_en : 1;        /*!< [29..29] (need pwl signal) 0->1                                           */
      __IOM uint32_t bit_pll_sys_div_en : 1;    /*!< [30..30] input divider enable (need pwl signal) 0->1                      */
      __IOM uint32_t bit_pll_sys_powcut_en : 1; /*!< [31..31] erc enable.                                                      */
    } reg_hs_pll_sys_ctrl0_b;
  } ;
  
  union {
    __IOM uint32_t reg_hs_pll_sys_ctrl1;        /*!< (@ 0x00000054) reg_hs_pll_sys_ctrl1                                       */
    
    struct {
      __IM  uint32_t            : 5;
      __IOM uint32_t bit_pll_sys_divn_sdm : 6;  /*!< [10..5] PLL_SYS_DIVN_SDM                                                  */
      __IOM uint32_t bit_pll_sys_bb_dbg_sel_afe_sdm : 4;/*!< [14..11] PLL_SYS_BB_DBG_SEL_AFE_SDM                               */
      __IOM uint32_t bit_pll_sys_trig_rreq_en : 1;/*!< [15..15] freq. step up or step down enable                              */
      __IOM uint32_t bit_pll_sys_step_freq_sel : 4;/*!< [19..16] step size selection for switching freq.                       */
      __IOM uint32_t bit_pll_sys_tbase_freq_sel : 4;/*!< [23..20] for output clk step up or step down                          */
      __IOM uint32_t bit_pll_sys_freq_sel : 4;  /*!< [27..24] output clk selection, Default=300MHz                             */
      __IOM uint32_t bit_pll_sys_xtal_sel : 4;  /*!< [31..28] xtal selection, Default=40MHz 0000: 40MHz, 0001: 25MHz,
                                                     0010: 13MHz, 0011: 19.2MHz 0100: 20MHz, 0101: 26MHz, 0110:
                                                     38.4MHz, 0111: 17.664MHz 1000: 16MHz, 1001: 14.138MHz 1010:
                                                     12MHz, 1011: 52MHz 1100: 48MHz, 1101: 27MHz, 1110: 24MHz,
                                                     1111: none                                                                */
    } reg_hs_pll_sys_ctrl1_b;
  } ;
  
  union {
    __IOM uint32_t reg_hs_pll_sys_ctrl2;        /*!< (@ 0x00000058) reg_hs_pll_sys_ctrl2                                       */
    
    struct {
      __IM  uint32_t            : 5;
      __IOM uint32_t bit_pll_sys_ssc_en : 1;    /*!< [5..5] ssc enable. Default=0                                              */
      __IOM uint32_t bit_pll_sys_ssc_freq_sel : 13;/*!< [18..6] ssc freq selection                                             */
      __IOM uint32_t bit_pll_sys_ssc_step_sel : 13;/*!< [31..19] ssc step size selection.                                      */
    } reg_hs_pll_sys_ctrl2_b;
  } ;
  
  union {
    __IOM uint32_t reg_hs_pll_sys_ctrl3;        /*!< (@ 0x0000005C) reg_hs_pll_sys_ctrl3                                       */
    
    struct {
      __IM  uint32_t            : 15;
      __IOM uint32_t bit_pll_sys_sdm_order_sel : 1;/*!< [15..15] SDM order: 0:2nd order, 1:3rd order                           */
      __IOM uint32_t bit_pll_sys_sdm_fon : 3;   /*!< [18..16] N code, feedback divider number 1 for 1/8                        */
      __IOM uint32_t bit_pll_sys_sdm_fof : 13;  /*!< [31..19] F code, feedback divider number 1for 1/8*1/2^13                  */
    } reg_hs_pll_sys_ctrl3_b;
  } ;
  
  union {
    __IOM uint32_t reg_hs_pll_enc_ctrl0;        /*!< (@ 0x00000060) reg_hs_pll_enc_ctrl0                                       */
    
    struct {
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_pll_enc_div_sel : 3;   /*!< [5..3] output divider selection. Default=000 000=/1, 100=/4,
                                                     110=/8, 111=/16                                                           */
      __IOM uint32_t bit_pll_enc_ps_en : 1;     /*!< [6..6] phase selector enable                                              */
      __IOM uint32_t bit_pll_enc_div2_en : 1;   /*!< [7..7] output clk div 2 enable                                            */
      __IOM uint32_t bit_pll_enc_clk_en : 1;    /*!< [8..8] output clk enable                                                  */
      __IOM uint32_t bit_pll_enc_fref_edge_sel : 1;/*!< [9..9] 0:fref,1:frefb                                                  */
      __IOM uint32_t bit_pll_enc_c3_set : 2;    /*!< [11..10] Cp selection. Default=5p 00: Cp=3p, 01: Cp=4p, 10:
                                                     Cp=5p, 11: Cp=6p                                                          */
      __IOM uint32_t bit_pll_enc_r3_sel : 3;    /*!< [14..12] R3 selection. Default=1k 000: R3=0k, 001: R3=0.5k,
                                                     010: R3=1k, 011: R3=1.5k, 100: R3=2k, 101: R3=2.5k, 110:
                                                     R3=3k, 111: R3=3.5k;                                                      */
      __IOM uint32_t bit_pll_enc_cs_sel : 2;    /*!< [16..15] Cs selection. Default=50p 00: Cs=30p, 01: Cs=40p, 10:
                                                     Cs=50p, 11: Cs=60p                                                        */
      __IOM uint32_t bit_pll_enc_rs_sel : 3;    /*!< [19..17] Rs selection. Default=14k 000: Rs=2k, 001: Rs=4k, 010:
                                                     Rs=6k, 011: Rs=8k, 100: Rs=10k, 101: Rs=12k, 110: Rs=14k,
                                                     111: Rs=16k;                                                              */
      __IOM uint32_t bit_pll_enc_cp_sel : 2;    /*!< [21..20] Cp selection. Default=3p 00: Cp=3p, 01: Cp=4p, 10:
                                                     Cp=5p, 11: Cp=6p                                                          */
      __IOM uint32_t bit_pll_enc_ps_sel : 3;    /*!< [24..22] PLL_ENC_PS_SEL                                                   */
      __IOM uint32_t bit_pll_enc_wdg_en : 1;    /*!< [25..25] 0: watch dog on ,1: watch dog off                                */
      __IOM uint32_t bit_pll_enc_cpc_sel : 3;   /*!< [28..26] charge pump current selection . Default=5u CP current
                                                     select : 000: Icp=5uA, 001: Icp=10uA, 010: Icp=15uA, 011:
                                                     Icp=20uA; 100:Icp=25uA, 101: Icp=30uA, 110: Icp=35uA, 111:
                                                     Icp=40uA;                                                                 */
      __IOM uint32_t bit_pll_enc_en : 1;        /*!< [29..29] (need pwl signal) 0->1                                           */
      __IOM uint32_t bit_pll_enc_div_en : 1;    /*!< [30..30] input divider enable (need pwl signal) 0->1                      */
      __IOM uint32_t bit_pll_enc_powcut_en : 1; /*!< [31..31] erc enable.                                                      */
    } reg_hs_pll_enc_ctrl0_b;
  } ;
  
  union {
    __IOM uint32_t reg_hs_pll_enc_ctrl1;        /*!< (@ 0x00000064) reg_hs_pll_enc_ctrl1                                       */
    
    struct {
      __IM  uint32_t            : 5;
      __IOM uint32_t bit_pll_enc_divn_sdm : 6;  /*!< [10..5] PLL_ENC_DIVN_SDM                                                  */
      __IOM uint32_t bit_pll_enc_bb_dbg_sel_afe_sdm : 4;/*!< [14..11] PLL_ENC_BB_DBG_SEL_AFE_SDM                               */
      __IOM uint32_t bit_pll_enc_trig_rreq_en : 1;/*!< [15..15] freq. step up or step down enable                              */
      __IOM uint32_t bit_pll_enc_step_freq_sel : 4;/*!< [19..16] step size selection for switching freq.                       */
      __IOM uint32_t bit_pll_enc_tbase_freq_sel : 4;/*!< [23..20] for output clk step up or step down                          */
      __IOM uint32_t bit_pll_enc_freq_sel : 4;  /*!< [27..24] output clk selection, Default=240MHz                             */
      __IOM uint32_t bit_pll_enc_xtal_sel : 4;  /*!< [31..28] xtal selection, Default=40MHz 0000: 40MHz, 0001: 25MHz,
                                                     0010: 13MHz, 0011: 19.2MHz 0100: 20MHz, 0101: 26MHz, 0110:
                                                     38.4MHz, 0111: 17.664MHz 1000: 16MHz, 1001: 14.138MHz 1010:
                                                     12MHz, 1011: 52MHz 1100: 48MHz, 1101: 27MHz, 1110: 24MHz,
                                                     1111: none                                                                */
    } reg_hs_pll_enc_ctrl1_b;
  } ;
  
  union {
    __IOM uint32_t reg_hs_pll_enc_ctrl2;        /*!< (@ 0x00000068) reg_hs_pll_enc_ctrl2                                       */
    
    struct {
      __IM  uint32_t            : 5;
      __IOM uint32_t bit_pll_enc_ssc_en : 1;    /*!< [5..5] ssc enable. Default=0                                              */
      __IOM uint32_t bit_pll_enc_ssc_freq_sel : 13;/*!< [18..6] ssc freq selection                                             */
      __IOM uint32_t bit_pll_enc_ssc_step_sel : 13;/*!< [31..19] ssc step size selection.                                      */
    } reg_hs_pll_enc_ctrl2_b;
  } ;
  
  union {
    __IOM uint32_t reg_hs_pll_enc_ctrl3;        /*!< (@ 0x0000006C) reg_hs_pll_enc_ctrl3                                       */
    
    struct {
      __IM  uint32_t            : 15;
      __IOM uint32_t bit_pll_enc_sdm_order_sel : 1;/*!< [15..15] SDM order: 0:2nd order, 1:3rd order                           */
      __IOM uint32_t bit_pll_enc_sdm_fon : 3;   /*!< [18..16] N code, feedback divider number 1 for 1/8                        */
      __IOM uint32_t bit_pll_enc_sdm_fof : 13;  /*!< [31..19] F code, feedback divider number 1for 1/8*1/2^13                  */
    } reg_hs_pll_enc_ctrl3_b;
  } ;
  __IM  uint32_t  RESERVED2[12];
  
  union {
    __IOM uint32_t reg_hs_pll_test;             /*!< (@ 0x000000A0) reg_hs_pll_test                                            */
    
    struct {
      __IOM uint32_t bit_pll_test_agpio_en : 1; /*!< [0..0] AGPIO enable                                                       */
      __IOM uint32_t bit_pll_test_agpio_output_en : 1;/*!< [1..1] AGPIO output enable                                          */
      __IOM uint32_t bit_pll_test_agpio_dri_sel : 2;/*!< [3..2] AGPIO driving sel                                              */
      __IOM uint32_t bit_pll_test_clk_sel : 4;  /*!< [7..4] ckmon clk sel 1111:CK_400M_ISP 1110:READY_400M 1101:CK_ISPS
                                                     1100:READY_ISPS 1011:CK_300M_SYS 1010:READY_300M 1001:CK_240M_ENC
                                                     1000:READY_240M_ENC 0111:CK_80M_PERI 0110:READY_80M_PERI
                                                     0101:CK_98P304M_I2S 0100:CK_24P576M_I2S 0011:READY_I2S
                                                     0010:CK_45P158M_PCM 0001:READY_45P158M_PCM 0000:TL                        */
      __IOM uint32_t bit_pll_test_clk_mon_en : 1;/*!< [8..8] ckmon enable                                                      */
      __IOM uint32_t bit_pll_test_clk_set : 1;  /*!< [9..9] xtal clk from 0 special route 1 APR                                */
      __IOM uint32_t bit_pll_test_xtal_gated : 1;/*!< [10..10] 1 for ISO ck_fref/ck_frefb                                      */
      __IM  uint32_t            : 13;
      __IOM uint32_t bit_pll_isp_rdy : 1;       /*!< [24..24] ISP PLL ready                                                    */
      __IOM uint32_t bit_pll_isps_rdy : 1;      /*!< [25..25] ISPS PLL ready                                                   */
      __IOM uint32_t bit_pll_sys_rdy : 1;       /*!< [26..26] SYS PLL ready                                                    */
      __IOM uint32_t bit_pll_enc_rdy : 1;       /*!< [27..27] Encoder PLL ready                                                */
      __IOM uint32_t bit_pll_peri_rdy : 1;      /*!< [28..28] PERI PLL ready                                                   */
      __IOM uint32_t bit_pll_i2s_rdy : 1;       /*!< [29..29] I2S PLL ready                                                    */
      __IOM uint32_t bit_pll_pcm_rdy : 1;       /*!< [30..30] PCM PLL ready                                                    */
    } reg_hs_pll_test_b;
  } ;
  __IM  uint32_t  RESERVED3[90];
  
  union {
    __IOM uint32_t reg_hs_share_mem_ctrl;       /*!< (@ 0x0000020C) reg_hs_share_mem_ctrl                                      */
    
    struct {
      __IOM uint32_t bit_hs_share_mem_en : 1;   /*!< [0..0] Memory function enable: 0: disable, 1: enable                      */
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_hs_share_mem_clk_en : 1;/*!< [4..4] Memory clock enable: 0: disable, 1: enable                        */
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_hs_share_mem_mod_sel : 1;/*!< [8..8] Mode selection: 0: used by platform, 1: used by H264
                                                     encoder                                                                   */
    } reg_hs_share_mem_ctrl_b;
  } ;
  __IM  uint32_t  RESERVED4[11];
  
  union {
    __IOM uint32_t reg_hs_isp_ctrl;             /*!< (@ 0x0000023C) reg_hs_isp_ctrl                                            */
    
    struct {
      __IOM uint32_t bit_hs_isp_en : 1;         /*!< [0..0] 1. Enable ISP                                                      */
      __IOM uint32_t bit_hs_isp_clk_en : 1;     /*!< [1..1] 1. Enable ISP CLK                                                  */
      __IM  uint32_t            : 2;
      __IOM uint32_t bit_hs_isp_i2c_mux_en : 1; /*!< [4..4] 1. Enable ISP I2C MUX                                              */
      __IOM uint32_t bit_hs_isp_parallel_mux_en : 1;/*!< [5..5] 1. Enable ISP parallel MUX (GPIOD_3~15)                        */
      __IOM uint32_t bit_hs_isp_ctrl_mux_en : 1;/*!< [6..6] 1. Enable ISP Control MUX                                          */
      __IOM uint32_t bit_hs_isp_ctrl_mux_sel : 1;/*!< [7..7] ISP Control is muxed on 0: GPIOC_2~7, GPIOD_2 1: GPIOC_2~7,
                                                     GPIOE_13                                                                  */
      __IOM uint32_t bit_hs_encoder_en : 1;     /*!< [8..8] 1: Enable Encoder                                                  */
      __IOM uint32_t bit_hs_encoder_clk_en : 1; /*!< [9..9] 1: Enable Encoder CLK                                              */
      __IM  uint32_t            : 2;
      __IOM uint32_t bit_hs_voe_en : 1;         /*!< [12..12] 1: Enable VOE                                                    */
      __IOM uint32_t bit_hs_voe_clk_en : 1;     /*!< [13..13] 1: Enable VOE CLK                                                */
      __IM  uint32_t            : 2;
      __IOM uint32_t bit_hs_mjpeg_en : 1;       /*!< [16..16] 1: Enable Motion JPEG                                            */
      __IOM uint32_t bit_hs_mjpeg_clk_en : 1;   /*!< [17..17] 1: Enable Motion JPEG CLK                                        */
      __IM  uint32_t            : 2;
      __IOM uint32_t bit_mipi_signal_sw : 1;    /*!< [20..20] 1: enable mipi signal                                            */
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_hs_lcdc_en : 1;        /*!< [24..24] 1: Enable LCDC                                                   */
      __IOM uint32_t bit_hs_lcdc_clk_en : 1;    /*!< [25..25] 1: Enable LCDC CLK                                               */
      __IM  uint32_t            : 2;
      __IOM uint32_t bit_hs_lcdc_mux_en : 1;    /*!< [28..28] 1: Enable LCDC MUX                                               */
      __IOM uint32_t bit_hs_lcdc_mode_sel : 1;  /*!< [29..29] 1: MCU (GPIOD_2~9, GPIOE_0~12); 0: RGB (GPIOD_2~9,
                                                     GPIOE_0~11)                                                               */
      __IOM uint32_t bit_hs_rlcdc_en : 1;       /*!< [30..30] 1: Enable reduce pin of LCDC MCU mode : GPIOE_0~12
                                                     RGB mode : GPIOE_0~5, 8~11                                                */
    } reg_hs_isp_ctrl_b;
  } ;
  __IM  uint32_t  RESERVED5[16];
  
  union {
    __IOM uint32_t reg_pad_pwd;                 /*!< (@ 0x00000280) reg_pad_pwd                                                */
    
    struct {
      __IOM uint32_t bit_gpiob_padpwd : 1;      /*!< [0..0] 1: power down GPIO pad group B                                     */
      __IOM uint32_t bit_gpioc_padpwd : 1;      /*!< [1..1] 1: power down GPIO pad group C                                     */
      __IOM uint32_t bit_gpiod_padpwd : 1;      /*!< [2..2] 1: power down GPIO pad group D                                     */
      __IOM uint32_t bit_gpioe_padpwd : 1;      /*!< [3..3] 1: power down GPIO pad group E                                     */
      __IOM uint32_t bit_gpiof_padpwd : 1;      /*!< [4..4] 1: power down GPIO pad group F                                     */
      __IOM uint32_t bit_gpiog_padpwd : 1;      /*!< [5..5] 1: power down GPIO pad group G                                     */
      __IOM uint32_t bit_gpioh_padpwd : 1;      /*!< [6..6] 1: power down GPIO pad group H                                     */
      __IOM uint32_t bit_gpioijk_padpwd : 1;    /*!< [7..7] 1: power down GPIO pad group IJK                                   */
    } reg_pad_pwd_b;
  } ;
  __IM  uint32_t  RESERVED6;
  
  union {
    __IOM uint32_t reg_gpio_dh_shdn;            /*!< (@ 0x00000288) reg_gpio_dh_shdn                                           */
    
    struct {
      __IOM uint32_t bit_gpiod10_shdn_n : 1;    /*!< [0..0] 0: shutdown GPIOD10 PAD; 1: enable GPIOD10 PAD                     */
      __IOM uint32_t bit_gpiod11_shdn_n : 1;    /*!< [1..1] 0: shutdown GPIOD11 PAD; 1: enable GPIOD11 PAD                     */
      __IOM uint32_t bit_gpiod12_shdn_n : 1;    /*!< [2..2] 0: shutdown GPIOD12 PAD; 1: enable GPIOD12 PAD                     */
      __IOM uint32_t bit_gpiod13_shdn_n : 1;    /*!< [3..3] 0: shutdown GPIOD13 PAD; 1: enable GPIOD13 PAD                     */
      __IOM uint32_t bit_gpiod14_shdn_n : 1;    /*!< [4..4] 0: shutdown GPIOD14 PAD; 1: enable GPIOD14 PAD                     */
      __IOM uint32_t bit_gpiod15_shdn_n : 1;    /*!< [5..5] 0: shutdown GPIOD15 PAD; 1: enable GPIOD15 PAD                     */
      __IM  uint32_t            : 10;
      __IOM uint32_t bit_gpioh0_shdn_n : 1;     /*!< [16..16] 0: shutdown GPIOH0 PAD; 1: enable GPIOH0 PAD                     */
      __IOM uint32_t bit_gpioh1_shdn_n : 1;     /*!< [17..17] 0: shutdown GPIOH1 PAD; 1: enable GPIOH1 PAD                     */
      __IOM uint32_t bit_gpioh2_shdn_n : 1;     /*!< [18..18] 0: shutdown GPIOH2 PAD; 1: enable GPIOH2 PAD                     */
      __IOM uint32_t bit_gpioh3_shdn_n : 1;     /*!< [19..19] 0: shutdown GPIOH3 PAD; 1: enable GPIOH3 PAD                     */
    } reg_gpio_dh_shdn_b;
  } ;
} VIDEO_SYS_Type;                               /*!< Size = 652 (0x28c)    													   */        


/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripheralAddr
  * @{
  */

#define VIDEO_SYS_BASE              0x40000000UL

/** @} */ /* End of group Device_Peripheral_peripheralAddr */


/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_declaration
  * @{
  */

#define VIDEO_SYS                   ((VIDEO_SYS_Type*)         VIDEO_SYS_BASE)



/** @} */ /* End of group Device_Peripheral_declaration */




/**
  \brief Union type to access video_sys_reg_sys_pwr_ctrl (@ 0x00000000).
*/
typedef union {
  __IOM uint16_t w;                           /*!< (@ 0x00000000) w                                           */
  
  struct {
    __IOM uint16_t bit_soc_spc_en : 1;        /*!< [0..0] 1:enable HS SOC domain small power cut                             */
    __IOM uint16_t bit_soc_lpc_en : 1;        /*!< [1..1] 1:enable HS SOC domain large power cut                             */
    __IOM uint16_t bit_video_spc_en : 1;      /*!< [2..2] 1:enable video domain small power cut                              */
    __IOM uint16_t bit_video_lpc_en : 1;      /*!< [3..3] 1:enable video domain large power cut                              */
    __IOM uint16_t bit_wlon_spc_en : 1;       /*!< [4..4] 1:enable WLON domain small power cut                               */
    __IOM uint16_t bit_wlon_lpc_en : 1;       /*!< [5..5] 1:enable WLON domain large power cut                               */
  } b;
} video_sys_reg_sys_pwr_ctrl_t, *pvideo_sys_reg_sys_pwr_ctrl_t;

/**
  \brief Union type to access video_sys_reg_sys_iso_ctrl (@ 0x00000002).
*/
typedef union {
  __IOM uint16_t w;                           /*!< (@ 0x00000002) w                                           */
  
  struct {
    __IOM uint16_t bit_sys_iso_hssoc : 1;     /*!< [0..0] 1: isolation HS SoC to HS ON domain; 0: disable isolation          */
    __IOM uint16_t bit_sys_iso_vdo : 1;       /*!< [1..1] 1: isolation Vedio to HS on domain; 0: disable isolation           */
    __IOM uint16_t bit_sys_iso_wl : 1;        /*!< [2..2] 1: isolation WLON to HS on domain; 0: disable isolation            */
  } b;
} video_sys_reg_sys_iso_ctrl_t, *pvideo_sys_reg_sys_iso_ctrl_t;

/**
  \brief Union type to access video_sys_reg_sys_func_en (@ 0x00000008).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000008) w                                            */
  
  struct {
    __IOM uint32_t bit_hs_fen_eeldr : 1;      /*!< [0..0] 1: enable EE Loader; 0: disable EE loader                          */
    __IM  uint32_t            : 1;
    __IOM uint32_t bit_tm9_en : 1;            /*!< [2..2] 1: enable TM9 ; 0: reset                                           */
    __IOM uint32_t bit_platform_en : 1;       /*!< [3..3] 1: enable platform                                                 */
    __IOM uint32_t bit_vendor_en : 1;         /*!< [4..4] 1: enable vendor                                                   */
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_hssys_clk_auto_gated : 1;/*!< [8..8] 1: Enable HS syson register auto gated                           */
    __IM  uint32_t            : 7;
    __IOM uint32_t bit_hs_soc_en : 1;         /*!< [16..16] 1: enable HS SOC domain                                          */
    __IOM uint32_t bit_hs_video_en : 1;       /*!< [17..17] 1: enable video domain                                           */
  } b;
} video_sys_reg_sys_func_en_t, *pvideo_sys_reg_sys_func_en_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_isp_ctrl0 (@ 0x00000030).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000030) w                                       */
  
  struct {
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_pll_isp_div_sel : 3;   /*!< [5..3] output divider selection. Default=000 000=/1, 100=/4,
                                                   110=/8, 111=/16                                                           */
    __IOM uint32_t bit_pll_isp_ps_en : 1;     /*!< [6..6] phase selector enable                                              */
    __IOM uint32_t bit_pll_isp_div2_en : 1;   /*!< [7..7] output clk div 2 enable                                            */
    __IOM uint32_t bit_pll_isp_clk_en : 1;    /*!< [8..8] output clk enable                                                  */
    __IOM uint32_t bit_pll_isp_fref_edge_sel : 1;/*!< [9..9] 0:fref,1:frefb                                                  */
    __IOM uint32_t bit_pll_isp_c3_set : 2;    /*!< [11..10] Cp selection. Default=5p 00: Cp=3p, 01: Cp=4p, 10:
                                                   Cp=5p, 11: Cp=6p                                                          */
    __IOM uint32_t bit_pll_isp_r3_sel : 3;    /*!< [14..12] R3 selection. Default=1k 000: R3=0k, 001: R3=0.5k,
                                                   010: R3=1k, 011: R3=1.5k, 100: R3=2k, 101: R3=2.5k, 110:
                                                   R3=3k, 111: R3=3.5k;                                                      */
    __IOM uint32_t bit_pll_isp_cs_sel : 2;    /*!< [16..15] Cs selection. Default=50p 00: Cs=30p, 01: Cs=40p, 10:
                                                   Cs=50p, 11: Cs=60p                                                        */
    __IOM uint32_t bit_pll_isp_rs_sel : 3;    /*!< [19..17] Rs selection. Default=14k 000: Rs=2k, 001: Rs=4k, 010:
                                                   Rs=6k, 011: Rs=8k, 100: Rs=10k, 101: Rs=12k, 110: Rs=14k,
                                                   111: Rs=16k;                                                              */
    __IOM uint32_t bit_pll_isp_cp_sel : 2;    /*!< [21..20] Cp selection. Default=3p 00: Cp=3p, 01: Cp=4p, 10:
                                                   Cp=5p, 11: Cp=6p                                                          */
    __IOM uint32_t bit_pll_isp_ps_sel : 3;    /*!< [24..22] PLL_ISP_PS_SEL                                                   */
    __IOM uint32_t bit_pll_isp_wdg_en : 1;    /*!< [25..25] 0: watch dog on ,1: watch dog off                                */
    __IOM uint32_t bit_pll_isp_cpc_sel : 3;   /*!< [28..26] charge pump current selection . Default=5u CP current
                                                   select : 000: Icp=5uA, 001: Icp=10uA, 010: Icp=15uA, 011:
                                                   Icp=20uA; 100:Icp=25uA, 101: Icp=30uA, 110: Icp=35uA, 111:
                                                   Icp=40uA;                                                                 */
    __IOM uint32_t bit_pll_isp_en : 1;        /*!< [29..29] (need pwl signal) 0->1                                           */
    __IOM uint32_t bit_pll_isp_div_en : 1;    /*!< [30..30] input divider enable (need pwl signal) 0->1                      */
    __IOM uint32_t bit_pll_isp_powcut_en : 1; /*!< [31..31] erc enable.                                                      */
  } b;
} video_sys_reg_hs_pll_isp_ctrl0_t, *pvideo_sys_reg_hs_pll_isp_ctrl0_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_isp_ctrl1 (@ 0x00000034).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000034) w                                       */
  
  struct {
    __IM  uint32_t            : 5;
    __IOM uint32_t bit_pll_isp_divn_sdm : 6;  /*!< [10..5] PLL_ISP_DIVN_SDM                                                  */
    __IOM uint32_t bit_pll_isp_bb_dbg_sel_afe_sdm : 4;/*!< [14..11] PLL_ISP_BB_DBG_SEL_AFE_SDM                               */
    __IOM uint32_t bit_pll_isp_trig_rreq_en : 1;/*!< [15..15] freq. step up or step down enable                              */
    __IOM uint32_t bit_pll_isp_step_freq_sel : 4;/*!< [19..16] step size selection for switching freq.                       */
    __IOM uint32_t bit_pll_isp_tbase_freq_sel : 4;/*!< [23..20] for output clk step up or step down                          */
    __IOM uint32_t bit_pll_isp_freq_sel : 4;  /*!< [27..24] output clk selection, Default=400MHz                             */
    __IOM uint32_t bit_pll_isp_xtal_sel : 4;  /*!< [31..28] xtal selection, Default=40MHz 0000: 40MHz, 0001: 25MHz,
                                                   0010: 13MHz, 0011: 19.2MHz 0100: 20MHz, 0101: 26MHz, 0110:
                                                   38.4MHz, 0111: 17.664MHz 1000: 16MHz, 1001: 14.138MHz 1010:
                                                   12MHz, 1011: 52MHz 1100: 48MHz, 1101: 27MHz, 1110: 24MHz,
                                                   1111: none                                                                */
  } b;
} video_sys_reg_hs_pll_isp_ctrl1_t, *pvideo_sys_reg_hs_pll_isp_ctrl1_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_isp_ctrl2 (@ 0x00000038).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000038) w                                       */
  
  struct {
    __IM  uint32_t            : 5;
    __IOM uint32_t bit_pll_isp_ssc_en : 1;    /*!< [5..5] ssc enable. Default=0                                              */
    __IOM uint32_t bit_pll_isp_ssc_freq_sel : 13;/*!< [18..6] ssc freq selection                                             */
    __IOM uint32_t bit_pll_isp_ssc_step_sel : 13;/*!< [31..19] ssc step size selection.                                      */
  } b;
} video_sys_reg_hs_pll_isp_ctrl2_t, *pvideo_sys_reg_hs_pll_isp_ctrl2_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_isp_ctrl3 (@ 0x0000003C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000003C) w                                       */
  
  struct {
    __IM  uint32_t            : 15;
    __IOM uint32_t bit_pll_isp_sdm_order_sel : 1;/*!< [15..15] SDM order: 0:2nd order, 1:3rd order                           */
    __IOM uint32_t bit_pll_isp_sdm_fon : 3;   /*!< [18..16] N code, feedback divider number 1 for 1/8                        */
    __IOM uint32_t bit_pll_isp_sdm_fof : 13;  /*!< [31..19] F code, feedback divider number 1for 1/8*1/2^13                  */
  } b;
} video_sys_reg_hs_pll_isp_ctrl3_t, *pvideo_sys_reg_hs_pll_isp_ctrl3_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_isps_ctrl0 (@ 0x00000040).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000040) w                                      */
  
  struct {
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_pll_isps_div_sel : 3;  /*!< [5..3] output divider selection. Default=000 000=/1, 100=/4,
                                                   110=/8, 111=/16                                                           */
    __IOM uint32_t bit_pll_isps_ps_en : 1;    /*!< [6..6] phase selector enable                                              */
    __IOM uint32_t bit_pll_isps_div2_en : 1;  /*!< [7..7] output clk div 2 enable                                            */
    __IOM uint32_t bit_pll_isps_clk_en : 1;   /*!< [8..8] output clk enable                                                  */
    __IOM uint32_t bit_pll_isps_fref_edge_sel : 1;/*!< [9..9] 0:fref,1:frefb                                                 */
    __IOM uint32_t bit_pll_isps_c3_set : 2;   /*!< [11..10] Cp selection. Default=5p 00: Cp=3p, 01: Cp=4p, 10:
                                                   Cp=5p, 11: Cp=6p                                                          */
    __IOM uint32_t bit_pll_isps_r3_sel : 3;   /*!< [14..12] R3 selection. Default=1k 000: R3=0k, 001: R3=0.5k,
                                                   010: R3=1k, 011: R3=1.5k, 100: R3=2k, 101: R3=2.5k, 110:
                                                   R3=3k, 111: R3=3.5k;                                                      */
    __IOM uint32_t bit_pll_isps_cs_sel : 2;   /*!< [16..15] Cs selection. Default=50p 00: Cs=30p, 01: Cs=40p, 10:
                                                   Cs=50p, 11: Cs=60p                                                        */
    __IOM uint32_t bit_pll_isps_rs_sel : 3;   /*!< [19..17] Rs selection. Default=14k 000: Rs=2k, 001: Rs=4k, 010:
                                                   Rs=6k, 011: Rs=8k, 100: Rs=10k, 101: Rs=12k, 110: Rs=14k,
                                                   111: Rs=16k;                                                              */
    __IOM uint32_t bit_pll_isps_cp_sel : 2;   /*!< [21..20] Cp selection. Default=3p 00: Cp=3p, 01: Cp=4p, 10:
                                                   Cp=5p, 11: Cp=6p                                                          */
    __IOM uint32_t bit_pll_isps_ps_sel : 3;   /*!< [24..22] PLL_ISPS_PS_SEL                                                  */
    __IOM uint32_t bit_pll_isps_wdg_en : 1;   /*!< [25..25] 0: watch dog on ,1: watch dog off                                */
    __IOM uint32_t bit_pll_isps_cpc_sel : 3;  /*!< [28..26] charge pump current selection . Default=5u CP current
                                                   select : 000: Icp=5uA, 001: Icp=10uA, 010: Icp=15uA, 011:
                                                   Icp=20uA; 100:Icp=25uA, 101: Icp=30uA, 110: Icp=35uA, 111:
                                                   Icp=40uA;                                                                 */
    __IOM uint32_t bit_pll_isps_en : 1;       /*!< [29..29] (need pwl signal) 0->1                                           */
    __IOM uint32_t bit_pll_isps_div_en : 1;   /*!< [30..30] input divider enable (need pwl signal) 0->1                      */
    __IOM uint32_t bit_pll_isps_powcut_en : 1;/*!< [31..31] erc enable.                                                      */
  } b;
} video_sys_reg_hs_pll_isps_ctrl0_t, *pvideo_sys_reg_hs_pll_isps_ctrl0_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_isps_ctrl1 (@ 0x00000044).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000044) w                                      */
  
  struct {
    __IM  uint32_t            : 5;
    __IOM uint32_t bit_pll_isps_divn_sdm : 6; /*!< [10..5] PLL_ISPS_DIVN_SDM                                                 */
    __IOM uint32_t bit_pll_isps_bb_dbg_sel_afe_sdm : 4;/*!< [14..11] PLL_ISPS_BB_DBG_SEL_AFE_SDM                             */
    __IOM uint32_t bit_pll_isps_trig_rreq_en : 1;/*!< [15..15] freq. step up or step down enable                             */
    __IOM uint32_t bit_pll_isps_step_freq_sel : 4;/*!< [19..16] step size selection for switching freq.                      */
    __IOM uint32_t bit_pll_isps_tbase_freq_sel : 4;/*!< [23..20] for output clk step up or step down                         */
    __IOM uint32_t bit_pll_isps_freq_sel : 4; /*!< [27..24] output clk selection, Default=74.25MHz/37.125MHz 0010:
                                                   74.25MHz/37.125MHz (297MHz/4, 297MHz/8) 0100: 54MHz/27MHz
                                                   (216MHz/4, 216MHz/8) 0110: 24MHz/12MHz (192MHz/8, 192MHz/16)              */
    __IOM uint32_t bit_pll_isps_xtal_sel : 4; /*!< [31..28] xtal selection, Default=40MHz 0000: 40MHz, 0001: 25MHz,
                                                   0010: 13MHz, 0011: 19.2MHz 0100: 20MHz, 0101: 26MHz, 0110:
                                                   38.4MHz, 0111: 17.664MHz 1000: 16MHz, 1001: 14.138MHz 1010:
                                                   12MHz, 1011: 52MHz 1100: 48MHz, 1101: 27MHz, 1110: 24MHz,
                                                   1111: none                                                                */
  } b;
} video_sys_reg_hs_pll_isps_ctrl1_t, *pvideo_sys_reg_hs_pll_isps_ctrl1_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_isps_ctrl2 (@ 0x00000048).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000048) w                                      */
  
  struct {
    __IM  uint32_t            : 5;
    __IOM uint32_t bit_pll_isps_ssc_en : 1;   /*!< [5..5] ssc enable. Default=0                                              */
    __IOM uint32_t bit_pll_isps_ssc_freq_sel : 13;/*!< [18..6] ssc freq selection                                            */
    __IOM uint32_t bit_pll_isps_ssc_step_sel : 13;/*!< [31..19] ssc step size selection.                                     */
  } b;
} video_sys_reg_hs_pll_isps_ctrl2_t, *pvideo_sys_reg_hs_pll_isps_ctrl2_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_isps_ctrl3 (@ 0x0000004C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000004C) w                                      */
  
  struct {
    __IM  uint32_t            : 15;
    __IOM uint32_t bit_pll_isps_sdm_order_sel : 1;/*!< [15..15] SDM order: 0:2nd order, 1:3rd order                          */
    __IOM uint32_t bit_pll_isps_sdm_fon : 3;  /*!< [18..16] N code, feedback divider number 1 for 1/8                        */
    __IOM uint32_t bit_pll_isps_sdm_fof : 13; /*!< [31..19] F code, feedback divider number 1for 1/8*1/2^13                  */
  } b;
} video_sys_reg_hs_pll_isps_ctrl3_t, *pvideo_sys_reg_hs_pll_isps_ctrl3_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_sys_ctrl0 (@ 0x00000050).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000050) w                                       */
  
  struct {
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_pll_sys_div_sel : 3;   /*!< [5..3] output divider selection. Default=000 000=/1, 100=/4,
                                                   110=/8, 111=/16                                                           */
    __IOM uint32_t bit_pll_sys_ps_en : 1;     /*!< [6..6] phase selector enable                                              */
    __IOM uint32_t bit_pll_sys_div2_en : 1;   /*!< [7..7] output clk div 2 enable                                            */
    __IOM uint32_t bit_pll_sys_clk_en : 1;    /*!< [8..8] output clk enable                                                  */
    __IOM uint32_t bit_pll_sys_fref_edge_sel : 1;/*!< [9..9] 0:fref,1:frefb                                                  */
    __IOM uint32_t bit_pll_sys_c3_set : 2;    /*!< [11..10] Cp selection. Default=5p 00: Cp=3p, 01: Cp=4p, 10:
                                                   Cp=5p, 11: Cp=6p                                                          */
    __IOM uint32_t bit_pll_sys_r3_sel : 3;    /*!< [14..12] R3 selection. Default=1k 000: R3=0k, 001: R3=0.5k,
                                                   010: R3=1k, 011: R3=1.5k, 100: R3=2k, 101: R3=2.5k, 110:
                                                   R3=3k, 111: R3=3.5k;                                                      */
    __IOM uint32_t bit_pll_sys_cs_sel : 2;    /*!< [16..15] Cs selection. Default=50p 00: Cs=30p, 01: Cs=40p, 10:
                                                   Cs=50p, 11: Cs=60p                                                        */
    __IOM uint32_t bit_pll_sys_rs_sel : 3;    /*!< [19..17] Rs selection. Default=14k 000: Rs=2k, 001: Rs=4k, 010:
                                                   Rs=6k, 011: Rs=8k, 100: Rs=10k, 101: Rs=12k, 110: Rs=14k,
                                                   111: Rs=16k;                                                              */
    __IOM uint32_t bit_pll_sys_cp_sel : 2;    /*!< [21..20] Cp selection. Default=3p 00: Cp=3p, 01: Cp=4p, 10:
                                                   Cp=5p, 11: Cp=6p                                                          */
    __IOM uint32_t bit_pll_sys_ps_sel : 3;    /*!< [24..22] PLL_SYS_PS_SEL                                                   */
    __IOM uint32_t bit_pll_sys_wdg_en : 1;    /*!< [25..25] 0: watch dog on ,1: watch dog off                                */
    __IOM uint32_t bit_pll_sys_cpc_sel : 3;   /*!< [28..26] charge pump current selection . Default=5u CP current
                                                   select : 000: Icp=5uA, 001: Icp=10uA, 010: Icp=15uA, 011:
                                                   Icp=20uA; 100:Icp=25uA, 101: Icp=30uA, 110: Icp=35uA, 111:
                                                   Icp=40uA;                                                                 */
    __IOM uint32_t bit_pll_sys_en : 1;        /*!< [29..29] (need pwl signal) 0->1                                           */
    __IOM uint32_t bit_pll_sys_div_en : 1;    /*!< [30..30] input divider enable (need pwl signal) 0->1                      */
    __IOM uint32_t bit_pll_sys_powcut_en : 1; /*!< [31..31] erc enable.                                                      */
  } b;
} video_sys_reg_hs_pll_sys_ctrl0_t, *pvideo_sys_reg_hs_pll_sys_ctrl0_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_sys_ctrl1 (@ 0x00000054).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000054) w                                       */
  
  struct {
    __IM  uint32_t            : 5;
    __IOM uint32_t bit_pll_sys_divn_sdm : 6;  /*!< [10..5] PLL_SYS_DIVN_SDM                                                  */
    __IOM uint32_t bit_pll_sys_bb_dbg_sel_afe_sdm : 4;/*!< [14..11] PLL_SYS_BB_DBG_SEL_AFE_SDM                               */
    __IOM uint32_t bit_pll_sys_trig_rreq_en : 1;/*!< [15..15] freq. step up or step down enable                              */
    __IOM uint32_t bit_pll_sys_step_freq_sel : 4;/*!< [19..16] step size selection for switching freq.                       */
    __IOM uint32_t bit_pll_sys_tbase_freq_sel : 4;/*!< [23..20] for output clk step up or step down                          */
    __IOM uint32_t bit_pll_sys_freq_sel : 4;  /*!< [27..24] output clk selection, Default=300MHz                             */
    __IOM uint32_t bit_pll_sys_xtal_sel : 4;  /*!< [31..28] xtal selection, Default=40MHz 0000: 40MHz, 0001: 25MHz,
                                                   0010: 13MHz, 0011: 19.2MHz 0100: 20MHz, 0101: 26MHz, 0110:
                                                   38.4MHz, 0111: 17.664MHz 1000: 16MHz, 1001: 14.138MHz 1010:
                                                   12MHz, 1011: 52MHz 1100: 48MHz, 1101: 27MHz, 1110: 24MHz,
                                                   1111: none                                                                */
  } b;
} video_sys_reg_hs_pll_sys_ctrl1_t, *pvideo_sys_reg_hs_pll_sys_ctrl1_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_sys_ctrl2 (@ 0x00000058).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000058) w                                       */
  
  struct {
    __IM  uint32_t            : 5;
    __IOM uint32_t bit_pll_sys_ssc_en : 1;    /*!< [5..5] ssc enable. Default=0                                              */
    __IOM uint32_t bit_pll_sys_ssc_freq_sel : 13;/*!< [18..6] ssc freq selection                                             */
    __IOM uint32_t bit_pll_sys_ssc_step_sel : 13;/*!< [31..19] ssc step size selection.                                      */
  } b;
} video_sys_reg_hs_pll_sys_ctrl2_t, *pvideo_sys_reg_hs_pll_sys_ctrl2_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_sys_ctrl3 (@ 0x0000005C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000005C) w                                       */
  
  struct {
    __IM  uint32_t            : 15;
    __IOM uint32_t bit_pll_sys_sdm_order_sel : 1;/*!< [15..15] SDM order: 0:2nd order, 1:3rd order                           */
    __IOM uint32_t bit_pll_sys_sdm_fon : 3;   /*!< [18..16] N code, feedback divider number 1 for 1/8                        */
    __IOM uint32_t bit_pll_sys_sdm_fof : 13;  /*!< [31..19] F code, feedback divider number 1for 1/8*1/2^13                  */
  } b;
} video_sys_reg_hs_pll_sys_ctrl3_t, *pvideo_sys_reg_hs_pll_sys_ctrl3_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_enc_ctrl0 (@ 0x00000060).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000060) w                                       */
  
  struct {
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_pll_enc_div_sel : 3;   /*!< [5..3] output divider selection. Default=000 000=/1, 100=/4,
                                                   110=/8, 111=/16                                                           */
    __IOM uint32_t bit_pll_enc_ps_en : 1;     /*!< [6..6] phase selector enable                                              */
    __IOM uint32_t bit_pll_enc_div2_en : 1;   /*!< [7..7] output clk div 2 enable                                            */
    __IOM uint32_t bit_pll_enc_clk_en : 1;    /*!< [8..8] output clk enable                                                  */
    __IOM uint32_t bit_pll_enc_fref_edge_sel : 1;/*!< [9..9] 0:fref,1:frefb                                                  */
    __IOM uint32_t bit_pll_enc_c3_set : 2;    /*!< [11..10] Cp selection. Default=5p 00: Cp=3p, 01: Cp=4p, 10:
                                                   Cp=5p, 11: Cp=6p                                                          */
    __IOM uint32_t bit_pll_enc_r3_sel : 3;    /*!< [14..12] R3 selection. Default=1k 000: R3=0k, 001: R3=0.5k,
                                                   010: R3=1k, 011: R3=1.5k, 100: R3=2k, 101: R3=2.5k, 110:
                                                   R3=3k, 111: R3=3.5k;                                                      */
    __IOM uint32_t bit_pll_enc_cs_sel : 2;    /*!< [16..15] Cs selection. Default=50p 00: Cs=30p, 01: Cs=40p, 10:
                                                   Cs=50p, 11: Cs=60p                                                        */
    __IOM uint32_t bit_pll_enc_rs_sel : 3;    /*!< [19..17] Rs selection. Default=14k 000: Rs=2k, 001: Rs=4k, 010:
                                                   Rs=6k, 011: Rs=8k, 100: Rs=10k, 101: Rs=12k, 110: Rs=14k,
                                                   111: Rs=16k;                                                              */
    __IOM uint32_t bit_pll_enc_cp_sel : 2;    /*!< [21..20] Cp selection. Default=3p 00: Cp=3p, 01: Cp=4p, 10:
                                                   Cp=5p, 11: Cp=6p                                                          */
    __IOM uint32_t bit_pll_enc_ps_sel : 3;    /*!< [24..22] PLL_ENC_PS_SEL                                                   */
    __IOM uint32_t bit_pll_enc_wdg_en : 1;    /*!< [25..25] 0: watch dog on ,1: watch dog off                                */
    __IOM uint32_t bit_pll_enc_cpc_sel : 3;   /*!< [28..26] charge pump current selection . Default=5u CP current
                                                   select : 000: Icp=5uA, 001: Icp=10uA, 010: Icp=15uA, 011:
                                                   Icp=20uA; 100:Icp=25uA, 101: Icp=30uA, 110: Icp=35uA, 111:
                                                   Icp=40uA;                                                                 */
    __IOM uint32_t bit_pll_enc_en : 1;        /*!< [29..29] (need pwl signal) 0->1                                           */
    __IOM uint32_t bit_pll_enc_div_en : 1;    /*!< [30..30] input divider enable (need pwl signal) 0->1                      */
    __IOM uint32_t bit_pll_enc_powcut_en : 1; /*!< [31..31] erc enable.                                                      */
  } b;
} video_sys_reg_hs_pll_enc_ctrl0_t, *pvideo_sys_reg_hs_pll_enc_ctrl0_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_enc_ctrl1 (@ 0x00000064).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000064) w                                       */
  
  struct {
    __IM  uint32_t            : 5;
    __IOM uint32_t bit_pll_enc_divn_sdm : 6;  /*!< [10..5] PLL_ENC_DIVN_SDM                                                  */
    __IOM uint32_t bit_pll_enc_bb_dbg_sel_afe_sdm : 4;/*!< [14..11] PLL_ENC_BB_DBG_SEL_AFE_SDM                               */
    __IOM uint32_t bit_pll_enc_trig_rreq_en : 1;/*!< [15..15] freq. step up or step down enable                              */
    __IOM uint32_t bit_pll_enc_step_freq_sel : 4;/*!< [19..16] step size selection for switching freq.                       */
    __IOM uint32_t bit_pll_enc_tbase_freq_sel : 4;/*!< [23..20] for output clk step up or step down                          */
    __IOM uint32_t bit_pll_enc_freq_sel : 4;  /*!< [27..24] output clk selection, Default=240MHz                             */
    __IOM uint32_t bit_pll_enc_xtal_sel : 4;  /*!< [31..28] xtal selection, Default=40MHz 0000: 40MHz, 0001: 25MHz,
                                                   0010: 13MHz, 0011: 19.2MHz 0100: 20MHz, 0101: 26MHz, 0110:
                                                   38.4MHz, 0111: 17.664MHz 1000: 16MHz, 1001: 14.138MHz 1010:
                                                   12MHz, 1011: 52MHz 1100: 48MHz, 1101: 27MHz, 1110: 24MHz,
                                                   1111: none                                                                */
  } b;
} video_sys_reg_hs_pll_enc_ctrl1_t, *pvideo_sys_reg_hs_pll_enc_ctrl1_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_enc_ctrl2 (@ 0x00000068).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000068) w                                       */
  
  struct {
    __IM  uint32_t            : 5;
    __IOM uint32_t bit_pll_enc_ssc_en : 1;    /*!< [5..5] ssc enable. Default=0                                              */
    __IOM uint32_t bit_pll_enc_ssc_freq_sel : 13;/*!< [18..6] ssc freq selection                                             */
    __IOM uint32_t bit_pll_enc_ssc_step_sel : 13;/*!< [31..19] ssc step size selection.                                      */
  } b;
} video_sys_reg_hs_pll_enc_ctrl2_t, *pvideo_sys_reg_hs_pll_enc_ctrl2_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_enc_ctrl3 (@ 0x0000006C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000006C) w                                       */
  
  struct {
    __IM  uint32_t            : 15;
    __IOM uint32_t bit_pll_enc_sdm_order_sel : 1;/*!< [15..15] SDM order: 0:2nd order, 1:3rd order                           */
    __IOM uint32_t bit_pll_enc_sdm_fon : 3;   /*!< [18..16] N code, feedback divider number 1 for 1/8                        */
    __IOM uint32_t bit_pll_enc_sdm_fof : 13;  /*!< [31..19] F code, feedback divider number 1for 1/8*1/2^13                  */
  } b;
} video_sys_reg_hs_pll_enc_ctrl3_t, *pvideo_sys_reg_hs_pll_enc_ctrl3_t;

/**
  \brief Union type to access video_sys_reg_hs_pll_test (@ 0x000000A0).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000000A0) w                                            */
  
  struct {
    __IOM uint32_t bit_pll_test_agpio_en : 1; /*!< [0..0] AGPIO enable                                                       */
    __IOM uint32_t bit_pll_test_agpio_output_en : 1;/*!< [1..1] AGPIO output enable                                          */
    __IOM uint32_t bit_pll_test_agpio_dri_sel : 2;/*!< [3..2] AGPIO driving sel                                              */
    __IOM uint32_t bit_pll_test_clk_sel : 4;  /*!< [7..4] ckmon clk sel 1111:CK_400M_ISP 1110:READY_400M 1101:CK_ISPS
                                                   1100:READY_ISPS 1011:CK_300M_SYS 1010:READY_300M 1001:CK_240M_ENC
                                                   1000:READY_240M_ENC 0111:CK_80M_PERI 0110:READY_80M_PERI
                                                   0101:CK_98P304M_I2S 0100:CK_24P576M_I2S 0011:READY_I2S
                                                   0010:CK_45P158M_PCM 0001:READY_45P158M_PCM 0000:TL                        */
    __IOM uint32_t bit_pll_test_clk_mon_en : 1;/*!< [8..8] ckmon enable                                                      */
    __IOM uint32_t bit_pll_test_clk_set : 1;  /*!< [9..9] xtal clk from 0 special route 1 APR                                */
    __IOM uint32_t bit_pll_test_xtal_gated : 1;/*!< [10..10] 1 for ISO ck_fref/ck_frefb                                      */
    __IM  uint32_t            : 13;
    __IOM uint32_t bit_pll_isp_rdy : 1;       /*!< [24..24] ISP PLL ready                                                    */
    __IOM uint32_t bit_pll_isps_rdy : 1;      /*!< [25..25] ISPS PLL ready                                                   */
    __IOM uint32_t bit_pll_sys_rdy : 1;       /*!< [26..26] SYS PLL ready                                                    */
    __IOM uint32_t bit_pll_enc_rdy : 1;       /*!< [27..27] Encoder PLL ready                                                */
    __IOM uint32_t bit_pll_peri_rdy : 1;      /*!< [28..28] PERI PLL ready                                                   */
    __IOM uint32_t bit_pll_i2s_rdy : 1;       /*!< [29..29] I2S PLL ready                                                    */
    __IOM uint32_t bit_pll_pcm_rdy : 1;       /*!< [30..30] PCM PLL ready                                                    */
  } b;
} video_sys_reg_hs_pll_test_t, *pvideo_sys_reg_hs_pll_test_t;

/**
  \brief Union type to access video_sys_reg_hs_share_mem_ctrl (@ 0x0000020C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000020C) w                                      */
  
  struct {
    __IOM uint32_t bit_hs_share_mem_en : 1;   /*!< [0..0] Memory function enable: 0: disable, 1: enable                      */
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_hs_share_mem_clk_en : 1;/*!< [4..4] Memory clock enable: 0: disable, 1: enable                        */
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_hs_share_mem_mod_sel : 1;/*!< [8..8] Mode selection: 0: used by platform, 1: used by H264
                                                   encoder                                                                   */
  } b;
} video_sys_reg_hs_share_mem_ctrl_t, *pvideo_sys_reg_hs_share_mem_ctrl_t;

/**
  \brief Union type to access video_sys_reg_hs_isp_ctrl (@ 0x0000023C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000023C) w                                            */
  
  struct {
    __IOM uint32_t bit_hs_isp_en : 1;         /*!< [0..0] 1. Enable ISP                                                      */
    __IOM uint32_t bit_hs_isp_clk_en : 1;     /*!< [1..1] 1. Enable ISP CLK                                                  */
    __IM  uint32_t            : 2;
    __IOM uint32_t bit_hs_isp_i2c_mux_en : 1; /*!< [4..4] 1. Enable ISP I2C MUX                                              */
    __IOM uint32_t bit_hs_isp_parallel_mux_en : 1;/*!< [5..5] 1. Enable ISP parallel MUX (GPIOD_3~15)                        */
    __IOM uint32_t bit_hs_isp_ctrl_mux_en : 1;/*!< [6..6] 1. Enable ISP Control MUX                                          */
    __IOM uint32_t bit_hs_isp_ctrl_mux_sel : 1;/*!< [7..7] ISP Control is muxed on 0: GPIOC_2~7, GPIOD_2 1: GPIOC_2~7,
                                                   GPIOE_13                                                                  */
    __IOM uint32_t bit_hs_encoder_en : 1;     /*!< [8..8] 1: Enable Encoder                                                  */
    __IOM uint32_t bit_hs_encoder_clk_en : 1; /*!< [9..9] 1: Enable Encoder CLK                                              */
    __IM  uint32_t            : 2;
    __IOM uint32_t bit_hs_voe_en : 1;         /*!< [12..12] 1: Enable VOE                                                    */
    __IOM uint32_t bit_hs_voe_clk_en : 1;     /*!< [13..13] 1: Enable VOE CLK                                                */
    __IM  uint32_t            : 2;
    __IOM uint32_t bit_hs_mjpeg_en : 1;       /*!< [16..16] 1: Enable Motion JPEG                                            */
    __IOM uint32_t bit_hs_mjpeg_clk_en : 1;   /*!< [17..17] 1: Enable Motion JPEG CLK                                        */
    __IM  uint32_t            : 2;
    __IOM uint32_t bit_mipi_signal_sw : 1;    /*!< [20..20] 1: enable mipi signal                                            */
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_hs_lcdc_en : 1;        /*!< [24..24] 1: Enable LCDC                                                   */
    __IOM uint32_t bit_hs_lcdc_clk_en : 1;    /*!< [25..25] 1: Enable LCDC CLK                                               */
    __IM  uint32_t            : 2;
    __IOM uint32_t bit_hs_lcdc_mux_en : 1;    /*!< [28..28] 1: Enable LCDC MUX                                               */
    __IOM uint32_t bit_hs_lcdc_mode_sel : 1;  /*!< [29..29] 1: MCU (GPIOD_2~9, GPIOE_0~12); 0: RGB (GPIOD_2~9,
                                                   GPIOE_0~11)                                                               */
    __IOM uint32_t bit_hs_rlcdc_en : 1;       /*!< [30..30] 1: Enable reduce pin of LCDC MCU mode : GPIOE_0~12
                                                   RGB mode : GPIOE_0~5, 8~11                                                */
  } b;
} video_sys_reg_hs_isp_ctrl_t, *pvideo_sys_reg_hs_isp_ctrl_t;

/**
  \brief Union type to access video_sys_reg_pad_pwd (@ 0x00000280).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000280) w                                                */
  
  struct {
    __IOM uint32_t bit_gpiob_padpwd : 1;      /*!< [0..0] 1: power down GPIO pad group B                                     */
    __IOM uint32_t bit_gpioc_padpwd : 1;      /*!< [1..1] 1: power down GPIO pad group C                                     */
    __IOM uint32_t bit_gpiod_padpwd : 1;      /*!< [2..2] 1: power down GPIO pad group D                                     */
    __IOM uint32_t bit_gpioe_padpwd : 1;      /*!< [3..3] 1: power down GPIO pad group E                                     */
    __IOM uint32_t bit_gpiof_padpwd : 1;      /*!< [4..4] 1: power down GPIO pad group F                                     */
    __IOM uint32_t bit_gpiog_padpwd : 1;      /*!< [5..5] 1: power down GPIO pad group G                                     */
    __IOM uint32_t bit_gpioh_padpwd : 1;      /*!< [6..6] 1: power down GPIO pad group H                                     */
    __IOM uint32_t bit_gpioijk_padpwd : 1;    /*!< [7..7] 1: power down GPIO pad group IJK                                   */
  } b;
} video_sys_reg_pad_pwd_t, *pvideo_sys_reg_pad_pwd_t;

/**
  \brief Union type to access video_sys_reg_gpio_dh_shdn (@ 0x00000288).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000288) w                                           */
  
  struct {
    __IOM uint32_t bit_gpiod10_shdn_n : 1;    /*!< [0..0] 0: shutdown GPIOD10 PAD; 1: enable GPIOD10 PAD                     */
    __IOM uint32_t bit_gpiod11_shdn_n : 1;    /*!< [1..1] 0: shutdown GPIOD11 PAD; 1: enable GPIOD11 PAD                     */
    __IOM uint32_t bit_gpiod12_shdn_n : 1;    /*!< [2..2] 0: shutdown GPIOD12 PAD; 1: enable GPIOD12 PAD                     */
    __IOM uint32_t bit_gpiod13_shdn_n : 1;    /*!< [3..3] 0: shutdown GPIOD13 PAD; 1: enable GPIOD13 PAD                     */
    __IOM uint32_t bit_gpiod14_shdn_n : 1;    /*!< [4..4] 0: shutdown GPIOD14 PAD; 1: enable GPIOD14 PAD                     */
    __IOM uint32_t bit_gpiod15_shdn_n : 1;    /*!< [5..5] 0: shutdown GPIOD15 PAD; 1: enable GPIOD15 PAD                     */
    __IM  uint32_t            : 10;
    __IOM uint32_t bit_gpioh0_shdn_n : 1;     /*!< [16..16] 0: shutdown GPIOH0 PAD; 1: enable GPIOH0 PAD                     */
    __IOM uint32_t bit_gpioh1_shdn_n : 1;     /*!< [17..17] 0: shutdown GPIOH1 PAD; 1: enable GPIOH1 PAD                     */
    __IOM uint32_t bit_gpioh2_shdn_n : 1;     /*!< [18..18] 0: shutdown GPIOH2 PAD; 1: enable GPIOH2 PAD                     */
    __IOM uint32_t bit_gpioh3_shdn_n : 1;     /*!< [19..19] 0: shutdown GPIOH3 PAD; 1: enable GPIOH3 PAD                     */
  } b;
} video_sys_reg_gpio_dh_shdn_t, *pvideo_sys_reg_gpio_dh_shdn_t;


/** @} */ /* End of group hs_hal_video_reg */
/// @endcond /* End of condition DOXYGEN_VIDEO_REG_TYPE */


#ifdef  __cplusplus
}
#endif

#endif    // end of #ifndef _RTL8195B_HP_VIDEO_SYS_TYPE_H_

