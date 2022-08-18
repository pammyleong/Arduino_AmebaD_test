/**************************************************************************//**
 * @file      rtl8195bhp_isp_reg_type.h
 * @brief
 * @version   V1.00
 * @date      2017-4-27 13:55:10
 *
 * @note
 *
 ******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 * 
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 * 
 * 
 ******************************************************************************/

#ifndef _RTL8195B_HP_ISP_REG_TYPE_H_
#define _RTL8195B_HP_ISP_REG_TYPE_H_

#ifdef __cplusplus
extern "C"{
#endif

/// @cond DOXYGEN_ISP_REG_TYPE

/**
 * @addtogroup hs_hal_isp_reg ISP Registers.
 * @ingroup hs_hal_isp
 * @{
 */




/* =========================================================================================================================== */
/* ================                                          ISP_REG                                          ================ */
/* =========================================================================================================================== */


/**
  * @brief ISP and MCU register (ISP_REG)
  */

typedef struct {                                /*!< (@ 0x40300000) ISP_REG Structure                                          */
  
  union {
    __IOM uint32_t reg_dat0_host_mcu;           /*!< (@ 0x00000000) ISP Data0 Register(CPU2MCU)                                */
    
    struct {
      __IOM uint32_t bit_cpu_mcu_dat0 : 32;     /*!< [31..0] Data0 from CPU send to MCU                                        */
    } reg_dat0_host_mcu_b;
  } ;
  
  union {
    __IOM uint32_t reg_dat1_host_mcu;           /*!< (@ 0x00000004) ISP Data1 Register(CPU2MCU)                                */
    
    struct {
      __IOM uint32_t bit_cpu_mcu_dat1 : 32;     /*!< [31..0] Data1 from CPU send to MCU                                        */
    } reg_dat1_host_mcu_b;
  } ;
  
  union {
    __IOM uint32_t reg_dat2_host_mcu;           /*!< (@ 0x00000008) ISP Data2 Register(CPU2MCU)                                */
    
    struct {
      __IOM uint32_t bit_cpu_mcu_dat2 : 32;     /*!< [31..0] Data2 from CPU send to MCU                                        */
    } reg_dat2_host_mcu_b;
  } ;
  
  union {
    __IOM uint32_t reg_dat3_host_mcu;           /*!< (@ 0x0000000C) ISP Data3 Register(CPU2MCU)                                */
    
    struct {
      __IOM uint32_t bit_cpu_mcu_dat3 : 32;     /*!< [31..0] Data3 from CPU send to MCU                                        */
    } reg_dat3_host_mcu_b;
  } ;
  
  union {
    __IOM uint32_t reg_dat4_host_mcu;           /*!< (@ 0x00000010) ISP Data4 Register(CPU2MCU)                                */
    
    struct {
      __IOM uint32_t bit_cpu_mcu_dat4 : 32;     /*!< [31..0] Data4 from CPU send to MCU                                        */
    } reg_dat4_host_mcu_b;
  } ;
  
  union {
    __IOM uint32_t reg_dat5_host_mcu;           /*!< (@ 0x00000014) ISP Data5 Register(CPU2MCU)                                */
    
    struct {
      __IOM uint32_t bit_cpu_mcu_dat5 : 32;     /*!< [31..0] Data5 from CPU send to MCU                                        */
    } reg_dat5_host_mcu_b;
  } ;
  
  union {
    __IOM uint32_t reg_dat6_host_mcu;           /*!< (@ 0x00000018) ISP Data6 Register(CPU2MCU)                                */
    
    struct {
      __IOM uint32_t bit_cpu_mcu_dat6 : 32;     /*!< [31..0] Data6 from CPU send to MCU                                        */
    } reg_dat6_host_mcu_b;
  } ;
  
  union {
    __IOM uint32_t reg_dat7_host_mcu;           /*!< (@ 0x0000001C) ISP Data7 Register(CPU2MCU)                                */
    
    struct {
      __IOM uint32_t bit_cpu_mcu_dat7 : 32;     /*!< [31..0] Data7 from CPU send to MCU                                        */
    } reg_dat7_host_mcu_b;
  } ;
  
  union {
    __IM  uint32_t reg_dat0_mcu_host;           /*!< (@ 0x00000020) ISP Data0 Register(MCU2CPU)                                */
    
    struct {
      __IM  uint32_t bit_mcu_cpu_dat0 : 32;     /*!< [31..0] Data0 from MCU send to CPU                                        */
    } reg_dat0_mcu_host_b;
  } ;
  
  union {
    __IM  uint32_t reg_dat1_mcu_host;           /*!< (@ 0x00000024) ISP Data1 Register(MCU2CPU)                                */
    
    struct {
      __IM  uint32_t bit_mcu_cpu_dat1 : 32;     /*!< [31..0] Data1 from MCU send to CPU                                        */
    } reg_dat1_mcu_host_b;
  } ;
  
  union {
    __IM  uint32_t reg_dat2_mcu_host;           /*!< (@ 0x00000028) ISP Data2 Register(MCU2CPU)                                */
    
    struct {
      __IM  uint32_t bit_mcu_cpu_dat2 : 32;     /*!< [31..0] Data2 from MCU send to CPU                                        */
    } reg_dat2_mcu_host_b;
  } ;
  
  union {
    __IM  uint32_t reg_dat3_mcu_host;           /*!< (@ 0x0000002C) ISP Data3 Register(MCU2CPU)                                */
    
    struct {
      __IM  uint32_t bit_mcu_cpu_dat3 : 32;     /*!< [31..0] Data3 from MCU send to CPU                                        */
    } reg_dat3_mcu_host_b;
  } ;
  
  union {
    __IM  uint32_t reg_dat4_mcu_host;           /*!< (@ 0x00000030) ISP Data4 Register(MCU2CPU)                                */
    
    struct {
      __IM  uint32_t bit_mcu_cpu_dat4 : 32;     /*!< [31..0] Data4 from MCU send to CPU                                        */
    } reg_dat4_mcu_host_b;
  } ;
  
  union {
    __IM  uint32_t reg_dat5_mcu_host;           /*!< (@ 0x00000034) ISP Data5 Register(MCU2CPU)                                */
    
    struct {
      __IM  uint32_t bit_mcu_cpu_dat5 : 32;     /*!< [31..0] Data5 from MCU send to CPU                                        */
    } reg_dat5_mcu_host_b;
  } ;
  
  union {
    __IM  uint32_t reg_dat6_mcu_host;           /*!< (@ 0x00000038) ISP Data6 Register(MCU2CPU)                                */
    
    struct {
      __IM  uint32_t bit_mcu_cpu_dat6 : 32;     /*!< [31..0] Data6 from MCU send to CPU                                        */
    } reg_dat6_mcu_host_b;
  } ;
  
  union {
    __IM  uint32_t reg_dat7_mcu_host;           /*!< (@ 0x0000003C) ISP Data7 Register(MCU2CPU)                                */
    
    struct {
      __IM  uint32_t bit_mcu_cpu_dat7 : 32;     /*!< [31..0] Data7 from MCU send to CPU                                        */
    } reg_dat7_mcu_host_b;
  } ;
  
  union {
    __IOM uint32_t reg_cmd0_host_mcu;           /*!< (@ 0x00000040) ISP Cmd0 Register(CPU2MCU)                                 */
    
    struct {
      __IOM uint32_t bit_cpu_mcu_cmd0 : 32;     /*!< [31..0] Cmd0 from CPU send to MCU                                         */
    } reg_cmd0_host_mcu_b;
  } ;
  
  union {
    __IOM uint32_t reg_cmd1_host_mcu;           /*!< (@ 0x00000044) ISP Cmd1 Register(CPU2MCU)                                 */
    
    struct {
      __IOM uint32_t bit_cpu_mcu_cmd1 : 32;     /*!< [31..0] Cmd1 from CPU send to MCU                                         */
    } reg_cmd1_host_mcu_b;
  } ;
  
  union {
    __IM  uint32_t reg_mcu_cmd_sts;             /*!< (@ 0x00000048) MCU command Status Register                                */
    
    struct {
      __IM  uint32_t            : 16;
      __IM  uint32_t bit_mcu_fail_type : 8;     /*!< [23..16] The failed type after MCU processed the CMD                      */
      __IM  uint32_t            : 6;
      __IM  uint32_t bit_mcu_proc_sts : 1;      /*!< [30..30] 0: MCU process the CMD successfully 1: MCU process
                                                     the CMD failed                                                            */
      __IM  uint32_t bit_mcu_busy_sts : 1;      /*!< [31..31] MCU status: 1. HW set 1 after CPU write the CMD0 ,it
                                                     is used to declare that MCU is busy to process the CMD
                                                     from CPU 2. After MCU process the CMD, MCU clear it. When
                                                     MCU clear this bit, HW will set MCU CMD done flag and trigger
                                                     CPU interrupt that indicate MCU in idle state. 3. CPU read
                                                     this bit to check MCU whether can receive new CMD                         */
    } reg_mcu_cmd_sts_b;
  } ;
  __IM  uint32_t  RESERVED[45];
  
  union {
    __IOM uint32_t reg_yuv_frame_y_start_addr_s0_f0;/*!< (@ 0x00000100) Y start address S0 F0 Register                         */
    
    struct {
      __IOM uint32_t bit_yuv_frame_y_start_addr_s0_f0 : 32;/*!< [31..0] Y start address for yuv Stream 0 frame 0 in DDR        */
    } reg_yuv_frame_y_start_addr_s0_f0_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_y_start_addr_s0_f1;/*!< (@ 0x00000104) Y start address S0 F1 Register                         */
    
    struct {
      __IOM uint32_t bit_yuv_frame_y_start_addr_s0_f1 : 32;/*!< [31..0] Y start address for yuv Stream 0 frame 1 in DDR        */
    } reg_yuv_frame_y_start_addr_s0_f1_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_y_start_addr_s0_f2;/*!< (@ 0x00000108) Y start address S0 F2 Register                         */
    
    struct {
      __IOM uint32_t bit_yuv_frame_y_start_addr_s0_f2 : 32;/*!< [31..0] Y start address for yuv Stream 0 frame 2 in DDR        */
    } reg_yuv_frame_y_start_addr_s0_f2_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_y_start_addr_s0_f3;/*!< (@ 0x0000010C) Y start address S0 F3 Register                         */
    
    struct {
      __IOM uint32_t bit_yuv_frame_y_start_addr_s0_f3 : 32;/*!< [31..0] Y start address for yuv Stream 0 frame 3 in DDR        */
    } reg_yuv_frame_y_start_addr_s0_f3_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_y_start_addr_s1_f0;/*!< (@ 0x00000110) Y start address S1 F0 Register                         */
    
    struct {
      __IOM uint32_t bit_yuv_frame_y_start_addr_s1_f0 : 32;/*!< [31..0] Y start address for yuv Stream 1 frame 0 in DDR        */
    } reg_yuv_frame_y_start_addr_s1_f0_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_y_start_addr_s1_f1;/*!< (@ 0x00000114) Y start address S1 F1 Register                         */
    
    struct {
      __IOM uint32_t bit_yuv_frame_y_start_addr_s1_f1 : 32;/*!< [31..0] Y start address for yuv Stream 1 frame 1 in DDR        */
    } reg_yuv_frame_y_start_addr_s1_f1_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_y_start_addr_s1_f2;/*!< (@ 0x00000118) Y start address S1 F2 Register                         */
    
    struct {
      __IOM uint32_t bit_yuv_frame_y_start_addr_s1_f2 : 32;/*!< [31..0] Y start address for yuv Stream 1 frame 2 in DDR        */
    } reg_yuv_frame_y_start_addr_s1_f2_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_y_start_addr_s1_f3;/*!< (@ 0x0000011C) Y start address S1 F3 Register                         */
    
    struct {
      __IOM uint32_t bit_yuv_frame_y_start_addr_s1_f3 : 32;/*!< [31..0] Y start address for yuv Stream 1 frame 3 in DDR        */
    } reg_yuv_frame_y_start_addr_s1_f3_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_y_start_addr_s2_f0;/*!< (@ 0x00000120) Y start address S2 F0 Register                         */
    
    struct {
      __IOM uint32_t bit_yuv_frame_y_start_addr_s2_f0 : 32;/*!< [31..0] Y start address for yuv Stream 2 frame 0 in DDR        */
    } reg_yuv_frame_y_start_addr_s2_f0_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_y_start_addr_s2_f1;/*!< (@ 0x00000124) Y start address S2 F1 Register                         */
    
    struct {
      __IOM uint32_t bit_yuv_frame_y_start_addr_s2_f1 : 32;/*!< [31..0] Y start address for yuv Stream 2 frame 1 in DDR        */
    } reg_yuv_frame_y_start_addr_s2_f1_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_y_start_addr_s2_f2;/*!< (@ 0x00000128) Y start address S2 F2 Register                         */
    
    struct {
      __IOM uint32_t bit_yuv_frame_y_start_addr_s2_f2 : 32;/*!< [31..0] Y start address for yuv Stream 2 frame 2 in DDR        */
    } reg_yuv_frame_y_start_addr_s2_f2_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_y_start_addr_s2_f3;/*!< (@ 0x0000012C) Y start address S2 F3 Register                         */
    
    struct {
      __IOM uint32_t bit_yuv_frame_y_start_addr_s2_f3 : 32;/*!< [31..0] Y start address for yuv Stream 2 frame 3 in DDR        */
    } reg_yuv_frame_y_start_addr_s2_f3_b;
  } ;
  __IM  uint32_t  RESERVED1[20];
  
  union {
    __IOM uint32_t reg_yuv_frame_uv_start_addr_s0_f0;/*!< (@ 0x00000180) UV start address S0 F0 Register                       */
    
    struct {
      __IOM uint32_t bit_yuv_frame_uv_start_addr_s0_f0 : 32;/*!< [31..0] UV start address for yuv Stream 0 frame 0 in DDR      */
    } reg_yuv_frame_uv_start_addr_s0_f0_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_uv_start_addr_s0_f1;/*!< (@ 0x00000184) UV start address S0 F1 Register                       */
    
    struct {
      __IOM uint32_t bit_yuv_frame_uv_start_addr_s0_f1 : 32;/*!< [31..0] UV start address for yuv Stream 0 frame 1 in DDR      */
    } reg_yuv_frame_uv_start_addr_s0_f1_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_uv_start_addr_s0_f2;/*!< (@ 0x00000188) UV start address S0 F2 Register                       */
    
    struct {
      __IOM uint32_t bit_yuv_frame_uv_start_addr_s0_f2 : 32;/*!< [31..0] UV start address for yuv Stream 0 frame 2 in DDR      */
    } reg_yuv_frame_uv_start_addr_s0_f2_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_uv_start_addr_s0_f3;/*!< (@ 0x0000018C) UV start address S0 F3 Register                       */
    
    struct {
      __IOM uint32_t bit_yuv_frame_uv_start_addr_s0_f3 : 32;/*!< [31..0] UV start address for yuv Stream 0 frame 3 in DDR      */
    } reg_yuv_frame_uv_start_addr_s0_f3_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_uv_start_addr_s1_f0;/*!< (@ 0x00000190) UV start address S1 F0 Register                       */
    
    struct {
      __IOM uint32_t bit_yuv_frame_uv_start_addr_s1_f0 : 32;/*!< [31..0] UV start address for yuv Stream 1 frame 0 in DDR      */
    } reg_yuv_frame_uv_start_addr_s1_f0_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_uv_start_addr_s1_f1;/*!< (@ 0x00000194) UV start address S1 F1 Register                       */
    
    struct {
      __IOM uint32_t bit_yuv_frame_uv_start_addr_s1_f1 : 32;/*!< [31..0] UV start address for yuv Stream 1 frame 1 in DDR      */
    } reg_yuv_frame_uv_start_addr_s1_f1_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_uv_start_addr_s1_f2;/*!< (@ 0x00000198) UV start address S1 F2 Register                       */
    
    struct {
      __IOM uint32_t bit_yuv_frame_uv_start_addr_s1_f2 : 32;/*!< [31..0] UV start address for yuv Stream 1 frame 2 in DDR      */
    } reg_yuv_frame_uv_start_addr_s1_f2_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_uv_start_addr_s1_f3;/*!< (@ 0x0000019C) UV start address S1 F3 Register                       */
    
    struct {
      __IOM uint32_t bit_yuv_frame_uv_start_addr_s1_f3 : 32;/*!< [31..0] UV start address for yuv Stream 1 frame 3 in DDR      */
    } reg_yuv_frame_uv_start_addr_s1_f3_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_uv_start_addr_s2_f0;/*!< (@ 0x000001A0) UV start address S2 F0 Register                       */
    
    struct {
      __IOM uint32_t bit_yuv_frame_uv_start_addr_s2_f0 : 32;/*!< [31..0] UV start address for yuv Stream 2 frame 0 in DDR      */
    } reg_yuv_frame_uv_start_addr_s2_f0_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_uv_start_addr_s2_f1;/*!< (@ 0x000001A4) UV start address S2 F1 Register                       */
    
    struct {
      __IOM uint32_t bit_yuv_frame_uv_start_addr_s2_f1 : 32;/*!< [31..0] UV start address for yuv Stream 2 frame 1 in DDR      */
    } reg_yuv_frame_uv_start_addr_s2_f1_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_uv_start_addr_s2_f2;/*!< (@ 0x000001A8) UV start address S2 F2 Register                       */
    
    struct {
      __IOM uint32_t bit_yuv_frame_uv_start_addr_s2_f2 : 32;/*!< [31..0] UV start address for yuv Stream 2 frame 2 in DDR      */
    } reg_yuv_frame_uv_start_addr_s2_f2_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_uv_start_addr_s2_f3;/*!< (@ 0x000001AC) UV start address S2 F3 Register                       */
    
    struct {
      __IOM uint32_t bit_yuv_frame_uv_start_addr_s2_f3 : 32;/*!< [31..0] UV start address for yuv Stream 2 frame 3 in DDR      */
    } reg_yuv_frame_uv_start_addr_s2_f3_b;
  } ;
  __IM  uint32_t  RESERVED2[42];
  
  union {
    __IOM uint32_t reg_overflow_count;          /*!< (@ 0x00000258) Overflow Count Register                                    */
    
    struct {
      __IOM uint32_t bit_s0_count_overflow : 8; /*!< [7..0] Stream 0 Frame Count overflow in buffer (frame count
                                                     > FRAME_BUFFER_COUNT)                                                     */
      __IOM uint32_t bit_s1_count_overflow : 8; /*!< [15..8] Stream 1 Frame Count overflow in buffer (frame count
                                                     > FRAME_BUFFER_COUNT)                                                     */
      __IOM uint32_t bit_s2_count_overflow : 8; /*!< [23..16] Stream 2 Frame Count overflow in buffer (frame count
                                                     > FRAME_BUFFER_COUNT)                                                     */
    } reg_overflow_count_b;
  } ;
  __IM  uint32_t  RESERVED3;
  
  union {
    __IOM uint32_t reg_frame_buf_count;         /*!< (@ 0x00000260) Frame Buffer Count Register                                */
    
    struct {
      __IOM uint32_t bit_s0_frame_buf_count : 3;/*!< [2..0] YUV Frame buffer Count for Stream 0                                */
      __IM  uint32_t            : 1;
      __IOM uint32_t bit_s1_frame_buf_count : 3;/*!< [6..4] YUV Frame buffer Count for Stream 1                                */
      __IM  uint32_t            : 1;
      __IOM uint32_t bit_s2_frame_buf_count : 3;/*!< [10..8] YUV Frame buffer Count for Stream 2                               */
    } reg_frame_buf_count_b;
  } ;
  
  union {
    __IOM uint32_t reg_isp_control;             /*!< (@ 0x00000264) ISP Control Register                                       */
    
    struct {
      __IOM uint32_t bit_reset_yuv_s0 : 1;      /*!< [0..0] 1: Reset YUV Stream 0                                              */
      __IOM uint32_t bit_reset_yuv_s1 : 1;      /*!< [1..1] 1: Reset YUV Stream 1                                              */
      __IOM uint32_t bit_reset_yuv_s2 : 1;      /*!< [2..2] 1: Reset YUV Stream 2                                              */
      __IM  uint32_t            : 5;
      __IOM uint32_t bit_control_yuv_s0 : 1;    /*!< [8..8] 1: START YUV Stream 0 0: STOP YUV Stream 0                         */
      __IOM uint32_t bit_control_yuv_s1 : 1;    /*!< [9..9] 1: START YUV Stream 1 0: STOP YUV Stream 1                         */
      __IOM uint32_t bit_control_yuv_s2 : 1;    /*!< [10..10] 1: START YUV Stream 2 0: STOP YUV Stream 2                       */
    } reg_isp_control_b;
  } ;
  __IM  uint32_t  RESERVED4;
  
  union {
    __IOM uint32_t reg_yuv_y_config_s0;         /*!< (@ 0x0000026C) ISP Y Buf Start Addr Config for S0 Register                */
    
    struct {
      __IOM uint32_t bit_isp_y_start_s0 : 13;   /*!< [12..0] ISP buffer Y start for yuv Stream 0, must be 8-alignment.         */
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_isp_y_len_s0 : 14;     /*!< [29..16] ISP buffer Y length for yuv stream 0, must be 8-alignement.
                                                     All YUV streams share a 8K ISP buffer to store data from
                                                     ISP to OCP bus temporarily.                                               */
    } reg_yuv_y_config_s0_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_uv_config_s0;        /*!< (@ 0x00000270) ISP UV Buf Start Addr Config for S0 Register               */
    
    struct {
      __IOM uint32_t bit_isp_uv_start_s0 : 13;  /*!< [12..0] ISP buffer UV start for yuv Stream 0, must be 8-alignment.        */
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_isp_uv_len_s0 : 14;    /*!< [29..16] ISP buffer UV length for yuv stream 0, must be 8-alignement.     */
    } reg_yuv_uv_config_s0_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_y_config_s1;         /*!< (@ 0x00000274) ISP Y Buf Start Addr Config for S1 Register                */
    
    struct {
      __IOM uint32_t bit_isp_y_start_s1 : 13;   /*!< [12..0] ISP buffer Y start for yuv Stream 1, must be 8-alignment.         */
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_isp_y_len_s1 : 14;     /*!< [29..16] ISP buffer Y length for yuv stream 1, must be 8-alignement.      */
    } reg_yuv_y_config_s1_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_uv_config_s1;        /*!< (@ 0x00000278) ISP UV Buf Start Addr Config for S1 Register               */
    
    struct {
      __IOM uint32_t bit_isp_uv_start_s1 : 13;  /*!< [12..0] ISP buffer UV start for yuv Stream 1, must be 8-alignment.        */
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_isp_uv_len_s1 : 14;    /*!< [29..16] ISP buffer UV length for yuv stream 1, must be 8-alignement.     */
    } reg_yuv_uv_config_s1_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_y_config_s2;         /*!< (@ 0x0000027C) ISP Y Buf Start Addr Config for S2 Register                */
    
    struct {
      __IOM uint32_t bit_isp_y_start_s2 : 13;   /*!< [12..0] ISP buffer Y start for yuv Stream 2, must be 8-alignment.         */
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_isp_y_len_s2 : 14;     /*!< [29..16] ISP buffer Y length for yuv stream 2, must be 8-alignement.      */
    } reg_yuv_y_config_s2_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_uv_config_s2;        /*!< (@ 0x00000280) ISP UV Buf Start Addr Config for S2 Register               */
    
    struct {
      __IOM uint32_t bit_isp_uv_start_s2 : 13;  /*!< [12..0] ISP buffer UV start for yuv Stream 2, must be 8-alignment.        */
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_isp_uv_len_s2 : 14;    /*!< [29..16] ISP buffer UV length for yuv stream 2, must be 8-alignement.     */
    } reg_yuv_uv_config_s2_b;
  } ;
  __IM  uint32_t  RESERVED5[5];
  
  union {
    __IOM uint32_t reg_stream_frame_interval;   /*!< (@ 0x00000298) Stream Frame Interval Config Register                      */
    
    struct {
      __IOM uint32_t bit_stream_frame_interval : 8;/*!< [7..0] Frame interval, interval for data from ISP clock domain
                                                     to OCP clock domain while frame end                                       */
    } reg_stream_frame_interval_b;
  } ;
  __IM  uint32_t  RESERVED6;
  
  union {
    __IOM uint32_t reg_pts_value_config;        /*!< (@ 0x000002A0) PTS Value Config Register                                  */
    
    struct {
      __IOM uint32_t bit_pts_value_config : 32; /*!< [31..0] PTS initial value, use OCP bus clock as its base clock            */
    } reg_pts_value_config_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_buf_status_s0; /*!< (@ 0x000002A4) Frame Buffer Status for YUV Stream 0 Register              */
    
    struct {
      __IM  uint32_t bit_overflow_s0_f0 : 2;    /*!< [1..0] Stream 0 frame 0: 0: ISP Y buffer overflow 1: ISP UV
                                                     buffer overflow                                                           */
      __IOM uint32_t bit_error_s0_f0 : 1;       /*!< [2..2] Stream 0 frame 0 error bit: 0: No error 1: Has error               */
      __IOM uint32_t bit_dat_valid_s0_f0 : 1;   /*!< [3..3] Stream 0 frame 0 Data valid: 0: Release 1: Data Valid,
                                                     Received frame, DIC set this bit to 1                                     */
      __IM  uint32_t bit_overflow_s0_f1 : 2;    /*!< [5..4] Stream 0 frame 1: 0: ISP Y buffer overflow 1: ISP UV
                                                     buffer overflow                                                           */
      __IOM uint32_t bit_error_s0_f1 : 1;       /*!< [6..6] Stream 0 frame 1 error bit: 0: No error 1: Has error               */
      __IOM uint32_t bit_dat_valid_s0_f1 : 1;   /*!< [7..7] Stream 0 frame 1 Data valid: 0: Release 1: Data Valid,
                                                     Received frame, DIC set this bit to 1                                     */
      __IM  uint32_t bit_overflow_s0_f2 : 2;    /*!< [9..8] Stream 0 frame 2: 0: ISP Y buffer overflow 1: ISP UV
                                                     buffer overflow                                                           */
      __IOM uint32_t bit_error_s0_f2 : 1;       /*!< [10..10] Stream 0 frame 2 error bit: 0: No error 1: Has error             */
      __IOM uint32_t bit_dat_valid_s0_f2 : 1;   /*!< [11..11] Stream 0 frame 2 Data valid: 0: Release 1: Data Valid,
                                                     Received frame, DIC set this bit to 1                                     */
      __IM  uint32_t bit_overflow_s0_f3 : 2;    /*!< [13..12] Stream 0 frame 3: 0: ISP Y buffer overflow 1: ISP UV
                                                     buffer overflow                                                           */
      __IOM uint32_t bit_error_s0_f3 : 1;       /*!< [14..14] Stream 0 frame 3 error bit: 0: No error 1: Has error             */
      __IOM uint32_t bit_dat_valid_s0_f3 : 1;   /*!< [15..15] Stream 0 frame 3 Data valid: 0: Release 1: Data Valid,
                                                     Received frame, DIC set this bit to 1                                     */
    } reg_yuv_frame_buf_status_s0_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_buf_status_s1; /*!< (@ 0x000002A8) Frame Buffer Status for YUV Stream 1 Register              */
    
    struct {
      __IM  uint32_t bit_overflow_s1_f0 : 2;    /*!< [1..0] Stream 1 frame 0: 0: ISP Y buffer overflow 1: ISP UV
                                                     buffer overflow                                                           */
      __IOM uint32_t bit_error_s1_f0 : 1;       /*!< [2..2] Stream 1 frame 0 error bit: 0: No error 1: Has error               */
      __IOM uint32_t bit_dat_valid_s1_f0 : 1;   /*!< [3..3] Stream 1 frame 0 Data valid: 0: Release 1: Data Valid,
                                                     Received frame, DIC set this bit to 1                                     */
      __IM  uint32_t bit_overflow_s1_f1 : 2;    /*!< [5..4] Stream 1 frame 1: 0: ISP Y buffer overflow 1: ISP UV
                                                     buffer overflow                                                           */
      __IOM uint32_t bit_error_s1_f1 : 1;       /*!< [6..6] Stream 1 frame 1 error bit: 0: No error 1: Has error               */
      __IOM uint32_t bit_dat_valid_s1_f1 : 1;   /*!< [7..7] Stream 1 frame 1 Data valid: 0: Release 1: Data Valid,
                                                     Received frame, DIC set this bit to 1                                     */
      __IM  uint32_t bit_overflow_s1_f2 : 2;    /*!< [9..8] Stream 1 frame 2: 0: ISP Y buffer overflow 1: ISP UV
                                                     buffer overflow                                                           */
      __IOM uint32_t bit_error_s1_f2 : 1;       /*!< [10..10] Stream 1 frame 2 error bit: 0: No error 1: Has error             */
      __IOM uint32_t bit_dat_valid_s1_f2 : 1;   /*!< [11..11] Stream 1 frame 2 Data valid: 0: Release 1: Data Valid,
                                                     Received frame, DIC set this bit to 1                                     */
      __IM  uint32_t bit_overflow_s1_f3 : 2;    /*!< [13..12] Stream 1 frame 3: 0: ISP Y buffer overflow 1: ISP UV
                                                     buffer overflow                                                           */
      __IOM uint32_t bit_error_s1_f3 : 1;       /*!< [14..14] Stream 1 frame 3 error bit: 0: No error 1: Has error             */
      __IOM uint32_t bit_dat_valid_s1_f3 : 1;   /*!< [15..15] Stream 1 frame 3 Data valid: 0: Release 1: Data Valid,
                                                     Received frame, DIC set this bit to 1                                     */
    } reg_yuv_frame_buf_status_s1_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_frame_buf_status_s2; /*!< (@ 0x000002AC) Frame Buffer Status for YUV Stream 2 Register              */
    
    struct {
      __IM  uint32_t bit_overflow_s2_f0 : 2;    /*!< [1..0] Stream 2 frame 0: 0: ISP Y buffer overflow 1: ISP UV
                                                     buffer overflow                                                           */
      __IOM uint32_t bit_error_s2_f0 : 1;       /*!< [2..2] Stream 2 frame 0 error bit: 0: No error 1: Has error               */
      __IOM uint32_t bit_dat_valid_s2_f0 : 1;   /*!< [3..3] Stream 2 frame 0 Data valid: 0: Release 1: Data Valid,
                                                     Received frame, DIC set this bit to 1                                     */
      __IM  uint32_t bit_overflow_s2_f1 : 2;    /*!< [5..4] Stream 2 frame 1: 0: ISP Y buffer overflow 1: ISP UV
                                                     buffer overflow                                                           */
      __IOM uint32_t bit_error_s2_f1 : 1;       /*!< [6..6] Stream 2 frame 1 error bit: 0: No error 1: Has error               */
      __IOM uint32_t bit_dat_valid_s2_f1 : 1;   /*!< [7..7] Stream 2 frame 1 Data valid: 0: Release 1: Data Valid,
                                                     Received frame, DIC set this bit to 1                                     */
      __IM  uint32_t bit_overflow_s2_f2 : 2;    /*!< [9..8] Stream 2 frame 2: 0: ISP Y buffer overflow 1: ISP UV
                                                     buffer overflow                                                           */
      __IOM uint32_t bit_error_s2_f2 : 1;       /*!< [10..10] Stream 2 frame 2 error bit: 0: No error 1: Has error             */
      __IOM uint32_t bit_dat_valid_s2_f2 : 1;   /*!< [11..11] Stream 2 frame 2 Data valid: 0: Release 1: Data Valid,
                                                     Received frame, DIC set this bit to 1                                     */
      __IM  uint32_t bit_overflow_s2_f3 : 2;    /*!< [13..12] Stream 2 frame 3: 0: ISP Y buffer overflow 1: ISP UV
                                                     buffer overflow                                                           */
      __IOM uint32_t bit_error_s2_f3 : 1;       /*!< [14..14] Stream 2 frame 3 error bit: 0: No error 1: Has error             */
      __IOM uint32_t bit_dat_valid_s2_f3 : 1;   /*!< [15..15] Stream 2 frame 3 Data valid: 0: Release 1: Data Valid,
                                                     Received frame, DIC set this bit to 1                                     */
    } reg_yuv_frame_buf_status_s2_b;
  } ;
  __IM  uint32_t  RESERVED7[4];
  
  union {
    __IM  uint32_t reg_yuv_cur_frame_index_offset_s0;/*!< (@ 0x000002C0) Current Frame Index and Offset for S0 Register        */
    
    struct {
      __IM  uint32_t bit_cur_index : 2;         /*!< [1..0] Current Index                                                      */
      __IM  uint32_t bit_cur_offset : 22;       /*!< [23..2] Current Offset                                                    */
    } reg_yuv_cur_frame_index_offset_s0_b;
  } ;
  
  union {
    __IM  uint32_t reg_yuv_cur_frame_index_offset_s1;/*!< (@ 0x000002C4) Current Frame Index and Offset for S1 Register        */
    
    struct {
      __IM  uint32_t bit_cur_index : 2;         /*!< [1..0] Current Index                                                      */
      __IM  uint32_t bit_cur_offset : 22;       /*!< [23..2] Current Offset                                                    */
    } reg_yuv_cur_frame_index_offset_s1_b;
  } ;
  
  union {
    __IM  uint32_t reg_yuv_cur_frame_index_offset_s2;/*!< (@ 0x000002C8) Current Frame Index and Offset for S2 Register        */
    
    struct {
      __IM  uint32_t bit_cur_index : 2;         /*!< [1..0] Current Index                                                      */
      __IM  uint32_t bit_cur_offset : 22;       /*!< [23..2] Current Offset                                                    */
    } reg_yuv_cur_frame_index_offset_s2_b;
  } ;
  __IM  uint32_t  RESERVED8[2];
  
  union {
    __IOM uint32_t reg_yuv_y_buf_overflow_count;/*!< (@ 0x000002D4) ISP Y Overflow count for YUV Stream Register               */
    
    struct {
      __IOM uint32_t bit_y_buf_overflow_count_s0 : 8;/*!< [7..0] Stream 0 ISP Y buffer overflow count                          */
      __IOM uint32_t bit_y_buf_overflow_count_s1 : 8;/*!< [15..8] Stream 1 ISP Y buffer overflow count                         */
      __IOM uint32_t bit_y_buf_overflow_count_s2 : 8;/*!< [23..16] Stream 2 ISP Y buffer overflow count                        */
    } reg_yuv_y_buf_overflow_count_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuv_uv_buf_overflow_count;/*!< (@ 0x000002D8) ISP UV Overflow count for YUV Stream Register             */
    
    struct {
      __IOM uint32_t bit_yv_buf_overflow_count_s0 : 8;/*!< [7..0] Stream 0 ISP UV buffer overflow count                        */
      __IOM uint32_t bit_uv_buf_overflow_count_s1 : 8;/*!< [15..8] Stream 1 ISP UV buffer overflow count                       */
      __IOM uint32_t bit_uv_buf_overflow_count_s2 : 8;/*!< [23..16] Stream 2 ISP UV buffer overflow count                      */
    } reg_yuv_uv_buf_overflow_count_b;
  } ;
  
  union {
    __IOM uint32_t reg_mjpeg_buf_overflow_count;/*!< (@ 0x000002DC) ISP MJPEG Overflow count Register                          */
    
    struct {
      __IOM uint32_t bit_mjpeg_buf_overflow_count : 8;/*!< [7..0] MJPEG Stream ISP buffer overflow count                       */
    } reg_mjpeg_buf_overflow_count_b;
  } ;
  __IM  uint32_t  RESERVED9[4];
  
  union {
    __IOM uint32_t reg_isp_header_start_addr;   /*!< (@ 0x000002F0) ISP Header Start Address Register                          */
    
    struct {
      __IOM uint32_t bit_isp_header_start_addr : 32;/*!< [31..0] ISP Header Start Address Offset from header of each
                                                     frame of each stream is shown below: Stream0: frame0: 0x0
                                                     frame1: 0x8 frame2: 0x10 frame3: 0x18 Stream1: frame0:
                                                     0x20 frame1: 0x28 frame2: 0x30 frame3: 0x38 Stream2: frame0:
                                                     0x40 frame1: 0x48 frame2: 0x50 frame3: 0x58                               */
    } reg_isp_header_start_addr_b;
  } ;
  
  union {
    __IOM uint32_t reg_isp_burst_len_sel;       /*!< (@ 0x000002F4) ISP OCP Master Burst Length Select Register                */
    
    struct {
      __IOM uint32_t bit_mjpeg_buf_overflow_count : 2;/*!< [1..0] ISP_BUSRT_LEGNTH_SEL 0: 32Byte 1: 64Byte 2: 128Byte          */
    } reg_isp_burst_len_sel_b;
  } ;
  
  union {
    __IOM uint32_t reg_isp_slice_end_cfg;       /*!< (@ 0x000002F8) ISP Slice End Configuration Register                       */
    
    struct {
      __IOM uint32_t bit_isp_s0_slice_end_enable : 1;/*!< [0..0] ISP_S0_SLICE_END_ENABLE 0:disable 1:enable                    */
      __IOM uint32_t bit_isp_s0_slice_height_setting : 3;/*!< [3..1] ISP_S0_SLICE_HEIGHT_SETTING 0: 4 line 1: 8 line 2: 16
                                                     line 3: 32 line 4: 64 line                                                */
      __IM  uint32_t            : 4;
      __IOM uint32_t bit_isp_s1_slice_end_enable : 1;/*!< [8..8] ISP_S1_SLICE_END_ENABLE 0:disable 1:enable                    */
      __IOM uint32_t bit_isp_s1_slice_height_setting : 3;/*!< [11..9] ISP_S1_SLICE_HEIGHT_SETTING 0: 4 line 1: 8 line 2: 16
                                                     line 3: 32 line 4: 64 line                                                */
      __IM  uint32_t            : 4;
      __IOM uint32_t bit_isp_s2_slice_end_enable : 1;/*!< [16..16] ISP_S2_SLICE_END_ENABLE 0:disable 1:enable                  */
      __IOM uint32_t bit_isp_s2_slice_height_setting : 3;/*!< [19..17] ISP_S2_SLICE_HEIGHT_SETTING 0: 4 line 1: 8 line 2:
                                                     16 line 3: 32 line 4: 64 line                                             */
    } reg_isp_slice_end_cfg_b;
  } ;
  
  union {
    __IOM uint32_t reg_isp_frame_down_en;       /*!< (@ 0x000002FC) ISP Frame Down Enable Register                             */
    
    struct {
      __IOM uint32_t bit_isp_frame_down_en : 1; /*!< [0..0] ISP_FRAME_DOWN_EN 0: disable 1: enable                             */
    } reg_isp_frame_down_en_b;
  } ;
  
  union {
    __IOM uint32_t reg_isp_ocpif_dummy;         /*!< (@ 0x00000300) ISP Frame Down Enable Register                             */
    
    struct {
      __IOM uint32_t bit_isp_ocpif_dummy : 32;  /*!< [31..0] ISP_OCPIF_DUMMY                                                   */
    } reg_isp_ocpif_dummy_b;
  } ;
  __IM  uint32_t  RESERVED10[63];
  
  union {
    __IOM uint32_t reg_mcu_spi_base_addr;       /*!< (@ 0x00000400) MCU SPI Base Address Register                              */
    
    struct {
      __IOM uint32_t bit_mcu_spi_base_addr : 32;/*!< [31..0] MCU code base address in serial flash                             */
    } reg_mcu_spi_base_addr_b;
  } ;
  
  union {
    __IOM uint32_t reg_cpu_lock_mcu;            /*!< (@ 0x00000404) CPU Lock MCU Register                                      */
    
    struct {
      __IOM uint32_t bit_cpu_request_lock_mcu : 1;/*!< [0..0] CPU request lock MCU                                             */
      __IM  uint32_t bit_cpu_lock_mcu_done : 1; /*!< [1..1] CPU lock MCU done                                                  */
      __OM  uint32_t bit_cpu_release_lock : 1;  /*!< [2..2] CPU release lock                                                   */
      __OM  uint32_t bit_mcu_cache_miss_flag_clear : 1;/*!< [3..3] MCU cache miss flag clear                                   */
    } reg_cpu_lock_mcu_b;
  } ;
  __IM  uint32_t  RESERVED11[62];
  
  union {
    __IOM uint32_t reg_int_en_mcu_host;         /*!< (@ 0x00000500) MCU Interrupt to Host Enable Register                      */
    
    struct {
      __IOM uint32_t bit_mcu_cmd_done_int_enable : 1;/*!< [0..0] MCU CMD done interrupt enable.                                */
      __IOM uint32_t bit_cache_miss_fail_int_enable : 1;/*!< [1..1] Cache miss fail interrupt enable                           */
      __IOM uint32_t bit_mcu_watchdog_reset_cpu_int_enable : 1;/*!< [2..2] MCU watchdog reset CPU interrupt enable             */
      __IM  uint32_t            : 13;
      __IOM uint32_t bit_mtd0_motion_int_enable : 1;/*!< [16..16] MTD0 motion interrupt enable                                 */
      __IOM uint32_t bit_mtd1_motion_int_enable : 1;/*!< [17..17] MTD1 motion interrupt enable                                 */
      __IOM uint32_t bit_mtd2_motion_int_enable : 1;/*!< [18..18] MTD2 motion interrupt enable                                 */
      __IOM uint32_t bit_mtd3_motion_int_enable : 1;/*!< [19..19] MTD3 motion interrupt enable                                 */
      __IOM uint32_t bit_mtd4_motion_int_enable : 1;/*!< [20..20] MTD4 motion interrupt enable                                 */
      __IOM uint32_t bit_mcu_trig_cpu_int_enable : 11;/*!< [31..21] MCU trigger CPU interrupt enable, bitmap register which
                                                     one bit response one interrupt type for CPU.                              */
    } reg_int_en_mcu_host_b;
  } ;
  
  union {
    __IOM uint32_t reg_int_en_isp_host;         /*!< (@ 0x00000504) MCU Interrupt to Host Enable Register                      */
    
    struct {
      __IOM uint32_t bit_yuv_uv_buf_overflow_int_s0 : 1;/*!< [0..0] YUV Stream 0 UV ISP buffer overflow interrupt              */
      __IOM uint32_t bit_yuv_y_buf_overflow_int_s0 : 1;/*!< [1..1] YUV Stream 0 Y ISP buffer overflow interrupt                */
      __IOM uint32_t bit_yuv_frame_count_overflow_int_s0 : 1;/*!< [2..2] YUV Stream 0 DDR frame count overflow interrupt       */
      __IOM uint32_t bit_yuv_send_to_ddr_done_int_s0 : 1;/*!< [3..3] YUV Stream 0 frame send to DDR done interrupt             */
      __IOM uint32_t bit_yuv_uv_buf_overflow_int_s1 : 1;/*!< [4..4] YUV Stream 1 UV ISP buffer overflow interrupt              */
      __IOM uint32_t bit_yuv_y_buf_overflow_int_s1 : 1;/*!< [5..5] YUV Stream 1 Y ISP buffer overflow interrupt                */
      __IOM uint32_t bit_yuv_frame_count_overflow_int_s1 : 1;/*!< [6..6] YUV Stream 1 DDR frame count overflow interrupt       */
      __IOM uint32_t bit_yuv_send_to_ddr_done_int_s1 : 1;/*!< [7..7] YUV Stream 1 frame send to DDR done interrupt             */
      __IOM uint32_t bit_yuv_uv_buf_overflow_int_s2 : 1;/*!< [8..8] YUV Stream 2 UV ISP buffer overflow interrupt              */
      __IOM uint32_t bit_yuv_y_buf_overflow_int_s2 : 1;/*!< [9..9] YUV Stream 2 Y ISP buffer overflow interrupt                */
      __IOM uint32_t bit_yuv_frame_count_overflow_int_s2 : 1;/*!< [10..10] YUV Stream 2 DDR frame count overflow interrupt     */
      __IOM uint32_t bit_yuv_send_to_ddr_done_int_s2 : 1;/*!< [11..11] YUV Stream 2 frame send to DDR done interrupt           */
    } reg_int_en_isp_host_b;
  } ;
  
  union {
    __IOM uint32_t reg_int_flag_mcu_host;       /*!< (@ 0x00000508) MCU interrupt to Host flag Register                        */
    
    struct {
      __IOM uint32_t bit_mcu_cmd_done_int_flag : 1;/*!< [0..0] MCU CMD done interrupt flag. CPU write 1 clear this flag.       */
      __IOM uint32_t bit_cache_miss_fail_int_flag : 1;/*!< [1..1] Cache miss fail interrupt flag                               */
      __IOM uint32_t bit_mcu_watchdog_reset_cpu_int_flag : 1;/*!< [2..2] MCU watchdog reset CPU interrupt flag                 */
      __IM  uint32_t            : 4;
      __IOM uint32_t bit_mtd0_motion_int_flag : 1;/*!< [7..7] MTD0 motion interrupt flag                                       */
      __IOM uint32_t bit_mtd1_motion_int_flag : 1;/*!< [8..8] MTD1 motion interrupt flag                                       */
      __IOM uint32_t bit_mtd2_motion_int_flag : 1;/*!< [9..9] MTD2 motion interrupt flag                                       */
      __IOM uint32_t bit_mtd3_motion_int_flag : 1;/*!< [10..10] MTD3 motion interrupt flag                                     */
      __IM  uint32_t            : 9;
      __IOM uint32_t bit_mtd4_motion_int_flag : 1;/*!< [20..20] MTD4 motion interrupt flag                                     */
      __IOM uint32_t bit_mcu_int_flag : 11;     /*!< [31..21] MCU interrupt flag. 1. MCU write 1 set interrupt flag
                                                     and trigger CPU interrupt. 2. CPU write 1 clear interrupt
                                                     flag. 3. CPU/MCU write 0 will not influence the interrupt
                                                     flag.                                                                     */
    } reg_int_flag_mcu_host_b;
  } ;
  
  union {
    __IOM uint32_t reg_int_flag_isp_host;       /*!< (@ 0x0000050C) MCU interrupt to Host flag Register                        */
    
    struct {
      __IOM uint32_t bit_yuv_uv_buf_overflow_int_s0 : 1;/*!< [0..0] YUV Stream 0 UV ISP buffer overflow interrupt              */
      __IOM uint32_t bit_yuv_y_buf_overflow_int_s0 : 1;/*!< [1..1] YUV Stream 0 Y ISP buffer overflow interrupt                */
      __IOM uint32_t bit_yuv_frame_count_overflow_int_s0 : 1;/*!< [2..2] YUV Stream 0 DDR frame count overflow interrupt       */
      __IOM uint32_t bit_yuv_send_to_ddr_done_int_s0 : 1;/*!< [3..3] YUV Stream 0 frame send to DDR done interrupt             */
      __IOM uint32_t bit_yuv_uv_buf_overflow_int_s1 : 1;/*!< [4..4] YUV Stream 1 UV ISP buffer overflow interrupt              */
      __IOM uint32_t bit_yuv_y_buf_overflow_int_s1 : 1;/*!< [5..5] YUV Stream 1 Y ISP buffer overflow interrupt                */
      __IOM uint32_t bit_yuv_frame_count_overflow_int_s1 : 1;/*!< [6..6] YUV Stream 1 DDR frame count overflow interrupt       */
      __IOM uint32_t bit_yuv_send_to_ddr_done_int_s1 : 1;/*!< [7..7] YUV Stream 1 frame send to DDR done interrupt             */
      __IOM uint32_t bit_yuv_uv_buf_overflow_int_s2 : 1;/*!< [8..8] YUV Stream 2 UV ISP buffer overflow interrupt              */
      __IOM uint32_t bit_yuv_y_buf_overflow_int_s2 : 1;/*!< [9..9] YUV Stream 2 Y ISP buffer overflow interrupt                */
      __IOM uint32_t bit_yuv_frame_count_overflow_int_s2 : 1;/*!< [10..10] YUV Stream 2 DDR frame count overflow interrupt     */
      __IOM uint32_t bit_yuv_send_to_ddr_done_int_s2 : 1;/*!< [11..11] YUV Stream 2 frame send to DDR done interrupt           */
    } reg_int_flag_isp_host_b;
  } ;
  __IM  uint32_t  RESERVED12[60];
  
  union {
    __IOM uint32_t reg_force_async_rst;         /*!< (@ 0x00000600) Force Async Reset Register                                 */
    
    struct {
      __IOM uint32_t bit_force_mcu_reset : 1;   /*!< [0..0] FORCE_MCU_RESET 1: force async-reset 0: release async-reset        */
      __IOM uint32_t bit_force_isp_reset : 1;   /*!< [1..1] FORCE_ISP_RESET                                                    */
      __IOM uint32_t bit_force_mipi_reset : 1;  /*!< [2..2] FORCE_MIPI_RESET                                                   */
      __IOM uint32_t bit_force_jpeg_reset : 1;  /*!< [3..3] FORCE_JPEG_RESET                                                   */
    } reg_force_async_rst_b;
  } ;
  __IM  uint32_t  RESERVED13[63];
  
  union {
    __IOM uint32_t reg_jpeg_clk_cfg;            /*!< (@ 0x00000700) JPEG Clock Source Select Register                          */
    
    struct {
      __IOM uint32_t bit_jpeg_clk_src_sel : 1;  /*!< [0..0] jpeg_clk_src_sel 0: clk400 1: clk300                               */
      __IOM uint32_t bit_jpeg_clk_div_sel : 3;  /*!< [3..1] jpeg_clk_div_sel[2:0] 000: div1 001: div2 010: div4 011:
                                                     div8 100: div16 101: div32 110: div64 111: div128                         */
      __IOM uint32_t bit_jpeg_clk_en : 1;       /*!< [4..4] jpeg_clk_en 0: disable 1: enable                                   */
    } reg_jpeg_clk_cfg_b;
  } ;
  
  union {
    __IOM uint32_t reg_mcu_clk_cfg_scan;        /*!< (@ 0x00000704) MCU Clock Source Select Register for At-speed
                                                                    Scan Test                                                  */
    
    struct {
      __IOM uint32_t bit_mcu_clk_src_sel : 1;   /*!< [0..0] mcu_clk_src_sel_scan 0: clk400 1: clk300 only for scan
                                                     at-speed test                                                             */
      __IOM uint32_t bit_mcu_clk_div_sel : 3;   /*!< [3..1] mcu_clk_div_sel_scan[2:0] 000: div1 001: div2 010: div4
                                                     011: div8 100: div16 101: div32 110: div64 111: div128
                                                     only for scan at-speed test                                               */
      __IOM uint32_t bit_mcu_clk_en : 1;        /*!< [4..4] mcu_clk_en 0: disable 1: enable function and scan mcu
                                                     clock enable 0: disable 1: enable                                         */
    } reg_mcu_clk_cfg_scan_b;
  } ;
  
  union {
    __IOM uint32_t reg_isp_clk_cfg_scan;        /*!< (@ 0x00000708) ISP Clock Source Select Register for At-speed
                                                                    Scan Test                                                  */
    
    struct {
      __IOM uint32_t bit_isp_clk_src_sel : 1;   /*!< [0..0] isp_clk_src_sel_scan 0: clk400 1: clk300                           */
      __IOM uint32_t bit_isp_clk_div_sel : 3;   /*!< [3..1] isp_clk_div_sel_scan[2:0] 000: div1 001: div2 010: div4
                                                     011: div8 100: div16 101: div32 110: div64 111: div128                    */
      __IOM uint32_t bit_isp_clk_en : 1;        /*!< [4..4] isp_clk_en_scan 0: disable 1: enable                               */
    } reg_isp_clk_cfg_scan_b;
  } ;
  
  union {
    __IOM uint32_t reg_mipi_clk_cfg_scan;       /*!< (@ 0x0000070C) MIPI Clock Source Select Register for At-speed
                                                                    Scan Test                                                  */
    
    struct {
      __IOM uint32_t bit_mipi_clk_src_sel : 1;  /*!< [0..0] mipi_clk_src_sel_scan 0: clk400 1: clk300                          */
      __IOM uint32_t bit_mipi_clk_div_sel : 3;  /*!< [3..1] mipi_clk_div_sel_scan[2:0] 000: div1 001: div2 010: div4
                                                     011: div8 100: div16 101: div32 110: div64 111: div128                    */
      __IOM uint32_t bit_mipi_clk_en : 1;       /*!< [4..4] mipi_clk_en_scan 0: disable 1: enable                              */
    } reg_mipi_clk_cfg_scan_b;
  } ;
  __IM  uint32_t  RESERVED14[60];
  
  union {
    __IOM uint32_t reg_sys_isp_mem_ctl;         /*!< (@ 0x00000800) ISP Memory Control Register                                */
    
    struct {
      __IOM uint32_t bit_isp_mem_rme : 1;       /*!< [0..0] isp memory read margin enable                                      */
      __IOM uint32_t bit_isp_mem_rm : 4;        /*!< [4..1] isp memory read margin                                             */
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_isp_mem_ra : 2;        /*!< [9..8] isp memory read assist                                             */
      __IOM uint32_t bit_isp_mem_wa : 3;        /*!< [12..10] isp_mem_wa [2]: isp memory write assist enable isp_mem_wa
                                                     [1:0]: isp memory write assist                                            */
      __IOM uint32_t bit_isp_mem_wpulse : 3;    /*!< [15..13] isp memory write assist pulse                                    */
      __IOM uint32_t bit_isp_mem_pd : 2;        /*!< [17..16] isp memory(T40LP TSMC Memory) power down isp_mem_pd[0]:
                                                     osd fhd isp_mem_pd[1]: osd hd                                             */
    } reg_sys_isp_mem_ctl_b;
  } ;
  
  union {
    __IOM uint32_t reg_sys_isp_mem_ls;          /*!< (@ 0x00000804) ISP Memory Light Sleep Register                            */
    
    struct {
      __IOM uint32_t bit_mlsc_mem_ls_en : 1;    /*!< [0..0] mlsc memory light sleep enable: 1:enable, 0:disable                */
      __IOM uint32_t bit_awb1_mem_ls_en : 1;    /*!< [1..1] awb1 memory light sleep enable: 1:enable, 0:disable                */
      __IOM uint32_t bit_awb2_mem_ls_en : 1;    /*!< [2..2] awb2 memory light sleep enable: 1:enable, 0:disable                */
      __IOM uint32_t bit_dpc_mem_ls_en : 1;     /*!< [3..3] dpc memory light sleep enable: 1:enable, 0:disable                 */
      __IOM uint32_t bit_intp_mem_ls_en : 1;    /*!< [4..4] intp memory light sleep enable: 1:enable, 0:disable                */
      __IOM uint32_t bit_iir_mem_ls_en : 1;     /*!< [5..5] iir memory light sleep enable: 1:enable, 0:disable                 */
      __IOM uint32_t bit_hdrds_mem_ls_en : 1;   /*!< [6..6] hdrds memory light sleep enable: 1:enable, 0:disable               */
      __IOM uint32_t bit_hdr_mem_ls_en : 1;     /*!< [7..7] hdr memory light sleep enable: 1:enable, 0:disable                 */
      __IOM uint32_t bit_eeh_mem_ls_en : 1;     /*!< [8..8] eeh memory light sleep enable: 1:enable, 0:disable                 */
      __IOM uint32_t bit_zoom_mem_ls_en : 1;    /*!< [9..9] zoom memory light sleep enable: 1:enable, 0:disable                */
      __IOM uint32_t bit_ae_mem_ls_en : 1;      /*!< [10..10] ae memory light sleep enable: 1:enable, 0:disable                */
      __IOM uint32_t bit_fft_mem_ls_en : 1;     /*!< [11..11] fft memory light sleep enable: 1:enable, 0:disable               */
      __IOM uint32_t bit_mtd_mem_ls_en : 1;     /*!< [12..12] mtd memory light sleep enable: 1:enable, 0:disable               */
      __IOM uint32_t bit_dehaze_curve_b_mem_ls_en : 1;/*!< [13..13] dehaze curve b memory light sleep enable: 1:enable,
                                                     0:disable                                                                 */
      __IOM uint32_t bit_dehaze_curve_g_mem_ls_en : 1;/*!< [14..14] dehaze curve g memory light sleep enable: 1:enable,
                                                     0:disable                                                                 */
      __IOM uint32_t bit_dehaze_curve_r_mem_ls_en : 1;/*!< [15..15] dehaze curve r memory light sleep enable: 1:enable,
                                                     0:disable                                                                 */
      __IOM uint32_t bit_dehaze_histo_mem_ls_en : 1;/*!< [16..16] dehaze histo memory light sleep enable: 1:enable, 0:disable  */
      __IOM uint32_t bit_dehaze_pre_mem_ls_en : 1;/*!< [17..17] dehaze pre memory light sleep enable: 1:enable, 0:disable      */
      __IOM uint32_t bit_osd_vga_mem_ls_en : 1; /*!< [18..18] osd vga memory light sleep enable: 1:enable, 0:disable           */
      __IOM uint32_t bit_ldc_mem_ls_en : 1;     /*!< [19..19] ldc memory light sleep enable: 1:enable, 0:disable               */
      __IOM uint32_t bit_mask_mem_ls_en : 1;    /*!< [20..20] mask memory light sleep enable: 1:enable, 0:disable              */
    } reg_sys_isp_mem_ls_b;
  } ;
  
  union {
    __IOM uint32_t reg_sys_isp_mem_ds;          /*!< (@ 0x00000808) ISP Memory Deep Sleep Register                             */
    
    struct {
      __IOM uint32_t bit_mlsc_mem_ds_en : 1;    /*!< [0..0] mlsc memory deep sleep enable: 1:enable, 0:disable                 */
      __IOM uint32_t bit_awb1_mem_ds_en : 1;    /*!< [1..1] awb1 memory deep sleep enable: 1:enable, 0:disable                 */
      __IOM uint32_t bit_awb2_mem_ds_en : 1;    /*!< [2..2] awb2 memory deep sleep enable: 1:enable, 0:disable                 */
      __IOM uint32_t bit_dpc_mem_ds_en : 1;     /*!< [3..3] dpc memory deep sleep enable: 1:enable, 0:disable                  */
      __IOM uint32_t bit_intp_mem_ds_en : 1;    /*!< [4..4] intp memory deep sleep enable: 1:enable, 0:disable                 */
      __IOM uint32_t bit_iir_mem_ds_en : 1;     /*!< [5..5] iir memory deep sleep enable: 1:enable, 0:disable                  */
      __IOM uint32_t bit_hdrds_mem_ds_en : 1;   /*!< [6..6] hdrds memory deep sleep enable: 1:enable, 0:disable                */
      __IOM uint32_t bit_hdr_mem_ds_en : 1;     /*!< [7..7] hdr memory deep sleep enable: 1:enable, 0:disable                  */
      __IOM uint32_t bit_eeh_mem_ds_en : 1;     /*!< [8..8] eeh memory deep sleep enable: 1:enable, 0:disable                  */
      __IOM uint32_t bit_zoom_mem_ds_en : 1;    /*!< [9..9] zoom memory deep sleep enable: 1:enable, 0:disable                 */
      __IOM uint32_t bit_ae_mem_ds_en : 1;      /*!< [10..10] ae memory deep sleep enable: 1:enable, 0:disable                 */
      __IOM uint32_t bit_fft_mem_ds_en : 1;     /*!< [11..11] fft memory deep sleep enable: 1:enable, 0:disable                */
      __IOM uint32_t bit_mtd_mem_ds_en : 1;     /*!< [12..12] mtd memory deep sleep enable: 1:enable, 0:disable                */
      __IOM uint32_t bit_dehaze_curve_b_mem_ds_en : 1;/*!< [13..13] dehaze curve b memory deep sleep enable: 1:enable,
                                                     0:disable                                                                 */
      __IOM uint32_t bit_dehaze_curve_g_mem_ds_en : 1;/*!< [14..14] dehaze curve g memory deep sleep enable: 1:enable,
                                                     0:disable                                                                 */
      __IOM uint32_t bit_dehaze_curve_r_mem_ds_en : 1;/*!< [15..15] dehaze curve r memory deep sleep enable: 1:enable,
                                                     0:disable                                                                 */
      __IOM uint32_t bit_dehaze_histo_mem_ds_en : 1;/*!< [16..16] dehaze histo memory deep sleep enable: 1:enable, 0:disable   */
      __IOM uint32_t bit_dehaze_pre_mem_ds_en : 1;/*!< [17..17] dehaze pre memory deep sleep enable: 1:enable, 0:disable       */
      __IOM uint32_t bit_osd_vga_mem_ds_en : 1; /*!< [18..18] osd vga memory deep sleep enable: 1:enable, 0:disable            */
      __IOM uint32_t bit_ldc_mem_ds_en : 1;     /*!< [19..19] ldc memory deep sleep enable: 1:enable, 0:disable                */
      __IOM uint32_t bit_mask_mem_ds_en : 1;    /*!< [20..20] mask memory deep sleep enable: 1:enable, 0:disable               */
    } reg_sys_isp_mem_ds_b;
  } ;
  
  union {
    __IOM uint32_t reg_sys_isp_mem_sd;          /*!< (@ 0x0000080C) ISP Memory Shut Down Register                              */
    
    struct {
      __IOM uint32_t bit_mlsc_mem_sd_en : 1;    /*!< [0..0] mlsc memory shut down enable: 1:enable, 0:disable                  */
      __IOM uint32_t bit_awb1_mem_sd_en : 1;    /*!< [1..1] awb1 memory shut down enable: 1:enable, 0:disable                  */
      __IOM uint32_t bit_awb2_mem_sd_en : 1;    /*!< [2..2] awb2 memory shut down enable: 1:enable, 0:disable                  */
      __IOM uint32_t bit_dpc_mem_sd_en : 1;     /*!< [3..3] dpc memory shut down enable: 1:enable, 0:disable                   */
      __IOM uint32_t bit_intp_mem_sd_en : 1;    /*!< [4..4] intp memory shut down enable: 1:enable, 0:disable                  */
      __IOM uint32_t bit_iir_mem_sd_en : 1;     /*!< [5..5] iir memory shut down enable: 1:enable, 0:disable                   */
      __IOM uint32_t bit_hdrds_mem_sd_en : 1;   /*!< [6..6] hdrds memory shut down enable: 1:enable, 0:disable                 */
      __IOM uint32_t bit_hdr_mem_sd_en : 1;     /*!< [7..7] hdr memory shut down enable: 1:enable, 0:disable                   */
      __IOM uint32_t bit_eeh_mem_sd_en : 1;     /*!< [8..8] eeh memory shut down enable: 1:enable, 0:disable                   */
      __IOM uint32_t bit_zoom_mem_sd_en : 1;    /*!< [9..9] zoom memory shut down enable: 1:enable, 0:disable                  */
      __IOM uint32_t bit_ae_mem_sd_en : 1;      /*!< [10..10] ae memory shut down enable: 1:enable, 0:disable                  */
      __IOM uint32_t bit_fft_mem_sd_en : 1;     /*!< [11..11] fft memory shut down enable: 1:enable, 0:disable                 */
      __IOM uint32_t bit_mtd_mem_sd_en : 1;     /*!< [12..12] mtd memory shut down enable: 1:enable, 0:disable                 */
      __IOM uint32_t bit_dehaze_curve_b_mem_sd_en : 1;/*!< [13..13] dehaze curve b memory shut down enable: 1:enable, 0:disable */
      __IOM uint32_t bit_dehaze_curve_g_mem_sd_en : 1;/*!< [14..14] dehaze curve g memory shut down enable: 1:enable, 0:disable */
      __IOM uint32_t bit_dehaze_curve_r_mem_sd_en : 1;/*!< [15..15] dehaze curve r memory shut down enable: 1:enable, 0:disable */
      __IOM uint32_t bit_dehaze_histo_mem_sd_en : 1;/*!< [16..16] dehaze histo memory shut down enable: 1:enable, 0:disable    */
      __IOM uint32_t bit_dehaze_pre_mem_sd_en : 1;/*!< [17..17] dehaze pre memory shut down enable: 1:enable, 0:disable        */
      __IOM uint32_t bit_osd_vga_mem_sd_en : 1; /*!< [18..18] osd vga memory shut down enable: 1:enable, 0:disable             */
      __IOM uint32_t bit_ldc_mem_sd_en : 1;     /*!< [19..19] ldc memory shut down enable: 1:enable, 0:disable                 */
      __IOM uint32_t bit_mask_mem_sd_en : 1;    /*!< [20..20] mask memory shut down enable: 1:enable, 0:disable                */
    } reg_sys_isp_mem_sd_b;
  } ;
  
  union {
    __IOM uint32_t reg_sys_jpeg_mem_ctl;        /*!< (@ 0x00000810) JPEG Memory Control Register                               */
    
    struct {
      __IOM uint32_t bit_jpeg_mem_rme : 1;      /*!< [0..0] jpeg memory read margin enable                                     */
      __IOM uint32_t bit_jpeg_mem_rm : 4;       /*!< [4..1] jpeg memory read margin                                            */
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_jpeg_mem_ra : 2;       /*!< [9..8] jpeg memory read assist                                            */
      __IOM uint32_t bit_jpeg_mem_wa : 3;       /*!< [12..10] jpeg_mem_wa [2]: isp memory write assist enable jpeg_mem_wa
                                                     [1:0]: isp memory write assist                                            */
      __IOM uint32_t bit_jpeg_mem_wap : 3;      /*!< [15..13] jpeg memory write assist pulse                                   */
      __IOM uint32_t bit_jpeg_mem_ls_en : 4;    /*!< [19..16] jpeg memory light sleep enable: 1:enable, 0:disable
                                                     jpeg_mem_ls[0]: pre jpeg jpeg_mem_ls[1]: zigzag jpeg_mem_ls[2]:
                                                     qnt jpeg_mem_ls[3]: huffman                                               */
      __IOM uint32_t bit_jpeg_mem_ds_en : 3;    /*!< [22..20] jpeg memory deep sleep enable: 1:enable, 0:disable
                                                     jpeg_mem_ds[0]: pre jpeg jpeg_mem_ds[1]: zigzag jpeg_mem_ds[2]:
                                                     qnt                                                                       */
      __IM  uint32_t            : 1;
      __IOM uint32_t bit_jpeg_mem_sd_en : 4;    /*!< [27..24] jpeg memory shut down enable: 1:enable, 0:disable jpeg_mem_sd[0]:
                                                     pre jpeg jpeg_mem_sd[1]: zigzag jpeg_mem_sd[2]: qnt jpeg_mem_sd[3]:
                                                     huffman                                                                   */
      __IOM uint32_t bit_jpeg_mem_pd : 1;       /*!< [28..28] jpeg memory(T40LP TSMC Memory) power down                        */
    } reg_sys_jpeg_mem_ctl_b;
  } ;
  
  union {
    __IOM uint32_t reg_sys_mcu_mem_ctl;         /*!< (@ 0x00000814) MCU Memory Control Register                                */
    
    struct {
      __IOM uint32_t bit_mcu_mem_rme : 1;       /*!< [0..0] mcu memory read margin enable                                      */
      __IOM uint32_t bit_mcu_mem_rm : 4;        /*!< [4..1] mcu memory read margin                                             */
      __IM  uint32_t            : 3;
      __IOM uint32_t bit_mcu_mem_ra : 2;        /*!< [9..8] mcu memory read assist                                             */
      __IOM uint32_t bit_mcu_mem_wa : 3;        /*!< [12..10] mcu_mem_wa [2]: isp memory write assist enable mcu_mem_wa
                                                     [1:0]: isp memory write assist                                            */
      __IOM uint32_t bit_mcu_mem_wap : 3;       /*!< [15..13] mcu memory write assist pulse                                    */
      __IOM uint32_t bit_mcu_mem_ls_en : 3;     /*!< [18..16] mcu memory light sleep enable: 1:enable, 0:disable
                                                     mcu_mem_ls[0]: cache mcu_mem_ls[1]: iram mcu_mem_ls[2]:
                                                     xdat                                                                      */
      __IOM uint32_t bit_mcu_mem_ds_en : 3;     /*!< [21..19] mcu memory deep sleep enable: 1:enable, 0:disable mcu_mem_ds[0]:
                                                     cache mcu_mem_ds[1]: iram mcu_mem_ds[2]: xdat                             */
      __IM  uint32_t            : 2;
      __IOM uint32_t bit_mcu_mem_sd_en : 3;     /*!< [26..24] mcu memory shut down enable: 1:enable, 0:disable mcu_mem_sd[0]:
                                                     cache mcu_mem_sd[1]: iram mcu_mem_sd[2]: xdat                             */
    } reg_sys_mcu_mem_ctl_b;
  } ;
  
  union {
    __IOM uint32_t reg_sys_mipi_mem_ctl;        /*!< (@ 0x00000818) MIPI Memory Control Register                               */
    
    struct {
      __IOM uint32_t bit_mipi_mem_rme : 1;      /*!< [0..0] mipi memory read margin enable                                     */
      __IOM uint32_t bit_mipi_mem_rm : 4;       /*!< [4..1] mipi memory read margin                                            */
      __IM  uint32_t            : 11;
      __IOM uint32_t bit_mipi_mem_sd_en : 1;    /*!< [16..16] mipi memory shut down enable: 1:enable, 0:disable                */
    } reg_sys_mipi_mem_ctl_b;
  } ;
  
  union {
    __IOM uint32_t reg_sys_ispocp_mem_ctl;      /*!< (@ 0x0000081C) ISPOCP Memory Control Register                             */
    
    struct {
      __IOM uint32_t bit_ispocp_mem_rme : 1;    /*!< [0..0] ispocp memory read margin enable                                   */
      __IOM uint32_t bit_ispocp_mem_rm : 4;     /*!< [4..1] ispocp memory read margin                                          */
      __IM  uint32_t            : 11;
      __IOM uint32_t bit_ispocp_mem_sd_en : 2;  /*!< [17..16] ispocp memory shut down enable: 1:enable, 0:disable
                                                     ispocp_mem_pd[0]: isp ispocp_mem_pd[1]: jpeg                              */
    } reg_sys_ispocp_mem_ctl_b;
  } ;
  
  union {
    __IOM uint32_t reg_sys_mem_bist_rst;        /*!< (@ 0x00000820) Memory BIST Reset Register                                 */
    
    struct {
      __IOM uint32_t bit_isp_bist0_rst : 1;     /*!< [0..0] isp part0 bist reset: 0:reset, 1:release                           */
      __IOM uint32_t bit_isp_bist1_rst : 1;     /*!< [1..1] isp part1 bist reset: 0:reset, 1:release                           */
      __IOM uint32_t bit_jpeg_bist_rst : 1;     /*!< [2..2] jpeg bist reset: 0:reset, 1:release                                */
      __IOM uint32_t bit_mcu_bist_rst : 1;      /*!< [3..3] mcu bist reset: 0:reset, 1:release                                 */
      __IOM uint32_t bit_mipi_bist_rst : 1;     /*!< [4..4] mipi bist reset: 0:reset, 1:release                                */
      __IOM uint32_t bit_ispocp_bist_rst : 1;   /*!< [5..5] ispocp bist reset: 0:reset, 1:release                              */
    } reg_sys_mem_bist_rst_b;
  } ;
  
  union {
    __IOM uint32_t reg_sys_mem_bist_en;         /*!< (@ 0x00000824) Memory BIST Enable Register                                */
    
    struct {
      __IOM uint32_t bit_isp_bist0_en : 1;      /*!< [0..0] isp part0 bist enable: 0:disable, 1:enable                         */
      __IOM uint32_t bit_isp_bist1_en : 1;      /*!< [1..1] isp part1 bist enable: 0:disable, 1:enable                         */
      __IOM uint32_t bit_jpeg_bist_en : 1;      /*!< [2..2] jpeg bist enable: 0:disable, 1:enable                              */
      __IOM uint32_t bit_mcu_bist_en : 1;       /*!< [3..3] mcu bist enable: 0:disable, 1:enable                               */
      __IOM uint32_t bit_mipi_bist_en : 1;      /*!< [4..4] mipi bist enable: 0:disable, 1:enable                              */
      __IOM uint32_t bit_ispocp_bist_en : 1;    /*!< [5..5] ispocp bist enable: 0:disable, 1:enable                            */
    } reg_sys_mem_bist_en_b;
  } ;
  
  union {
    __IOM uint32_t reg_sys_mem_drf_bist_en;     /*!< (@ 0x00000828) Memory DRF BIST Enable Register                            */
    
    struct {
      __IOM uint32_t bit_isp_drf_bist0_en : 1;  /*!< [0..0] isp part0 drf bist enable: 0:disable, 1:enable                     */
      __IOM uint32_t bit_isp_drf_bist1_en : 1;  /*!< [1..1] isp part1 drf bist enable: 0:disable, 1:enable                     */
      __IOM uint32_t bit_jpeg_drf_bist_en : 1;  /*!< [2..2] jpeg drf bist enable: 0:disable, 1:enable                          */
      __IOM uint32_t bit_mcu_drf_bist_en : 1;   /*!< [3..3] mcu drf bist enable: 0:disable, 1:enable                           */
      __IOM uint32_t bit_mipi_drf_bist_en : 1;  /*!< [4..4] mipi drf bist enable: 0:disable, 1:enable                          */
      __IOM uint32_t bit_ispocp_drf_bist_en : 1;/*!< [5..5] ispocp drf bist enable: 0:disable, 1:enable                        */
    } reg_sys_mem_drf_bist_en_b;
  } ;
  
  union {
    __IOM uint32_t reg_sys_mem_drf_bist_resume; /*!< (@ 0x0000082C) Memory DRF BIST Resume Register                            */
    
    struct {
      __IOM uint32_t bit_isp_drf_bist0_resume : 1;/*!< [0..0] isp part0 drf bist resume, high active                           */
      __IOM uint32_t bit_isp_drf_bist1_resume : 1;/*!< [1..1] isp part1 drf bist resume, high active                           */
      __IOM uint32_t bit_jpeg_drf_bist_resume : 1;/*!< [2..2] jpeg drf bist resume, high active                                */
      __IOM uint32_t bit_mcu_drf_bist_resume : 1;/*!< [3..3] mcu drf bist resume, high active                                  */
      __IOM uint32_t bit_mipi_drf_bist_resume : 1;/*!< [4..4] mipi drf bist resume, high active                                */
      __IOM uint32_t bit_ispocp_drf_bist_resume : 1;/*!< [5..5] ispocp drf bist resume, high active                            */
    } reg_sys_mem_drf_bist_resume_b;
  } ;
  
  union {
    __IOM uint32_t reg_sys_mem_drf_resume_sync; /*!< (@ 0x00000830) Memory DRF BIST Resume Sync Register                       */
    
    struct {
      __IOM uint32_t bit_drf_resume_sync_cnt : 7;/*!< [6..0] When drf_resume_sync_en = 1 This means the length of
                                                     drf resume signal count by clk25M                                         */
      __IOM uint32_t bit_drf_resume_sync_en : 1;/*!< [7..7] 1: drf resume signal is sync by drf_resume_sync_cnt 0:
                                                     not sync                                                                  */
    } reg_sys_mem_drf_resume_sync_b;
  } ;
  
  union {
    __IM  uint32_t reg_sys_mem_bist_all;        /*!< (@ 0x00000834) Memory BIST All Register                                   */
    
    struct {
      __IM  uint32_t bit_isp_bist0_done_all : 1;/*!< [0..0] isp bist0 done all                                                 */
      __IM  uint32_t bit_isp_bist1_done_all : 1;/*!< [1..1] isp bist1 done all                                                 */
      __IM  uint32_t bit_jpeg_bist_done_all : 1;/*!< [2..2] jpeg bist done all                                                 */
      __IM  uint32_t bit_mcu_bist_done_all : 1; /*!< [3..3] mcu bist done all                                                  */
      __IM  uint32_t bit_mipi_bist_done_all : 1;/*!< [4..4] mipi bist done all                                                 */
      __IM  uint32_t bit_ispocp_bist_done_all : 1;/*!< [5..5] ispocp bist done all                                             */
      __IM  uint32_t            : 2;
      __IM  uint32_t bit_isp_bist0_ok_all : 1;  /*!< [8..8] isp bist0 ok all                                                   */
      __IM  uint32_t bit_isp_bist1_ok_all : 1;  /*!< [9..9] isp bist1 ok all                                                   */
      __IM  uint32_t bit_jpeg_bist_ok_all : 1;  /*!< [10..10] jpeg bist ok all                                                 */
      __IM  uint32_t bit_mcu_bist_ok_all : 1;   /*!< [11..11] mcu bist ok all                                                  */
      __IM  uint32_t bit_mipi_bist_ok_all : 1;  /*!< [12..12] mipi bist ok all                                                 */
      __IM  uint32_t bit_ispocp_bist_ok_all : 1;/*!< [13..13] ispocp bist ok all                                               */
    } reg_sys_mem_bist_all_b;
  } ;
  
  union {
    __IM  uint32_t reg_sys_mem_drf_bist_all;    /*!< (@ 0x00000838) Memory DRF BIST All Register                               */
    
    struct {
      __IM  uint32_t bit_isp_drf0_bist_done_all : 1;/*!< [0..0] isp drf bist0 done all                                         */
      __IM  uint32_t bit_isp_drf1_bist_done_all : 1;/*!< [1..1] isp drf bist1 done all                                         */
      __IM  uint32_t bit_jpeg_drf_bist_done_all : 1;/*!< [2..2] jpeg drf bist done all                                         */
      __IM  uint32_t bit_mcu_drf_bist_done_all : 1;/*!< [3..3] mcu drf bist done all                                           */
      __IM  uint32_t bit_mipi_drf_bist_done_all : 1;/*!< [4..4] mipi drf bist done all                                         */
      __IM  uint32_t bit_ispocp_drf_bist_done_all : 1;/*!< [5..5] ispocp drf bist done all                                     */
      __IM  uint32_t            : 2;
      __IM  uint32_t bit_isp_drf0_bist_ok_all : 1;/*!< [8..8] isp drf bist0 ok all                                             */
      __IM  uint32_t bit_isp_drf1_bist_ok_all : 1;/*!< [9..9] isp drf bist1 ok all                                             */
      __IM  uint32_t bit_jpeg_drf_bist_ok_all : 1;/*!< [10..10] jpeg drf bist ok all                                           */
      __IM  uint32_t bit_mcu_drf_bist_ok_all : 1;/*!< [11..11] mcu drf bist ok all                                             */
      __IM  uint32_t bit_mipi_drf_bist_ok_all : 1;/*!< [12..12] mipi drf bist ok all                                           */
      __IM  uint32_t bit_ispocp_drf_bist_ok_all : 1;/*!< [13..13] ispocp drf bist ok all                                       */
      __IM  uint32_t            : 2;
      __IM  uint32_t bit_isp_drf0_start_pause_all : 1;/*!< [16..16] isp drf0 start pause all                                   */
      __IM  uint32_t bit_isp_drf1_start_pause_all : 1;/*!< [17..17] isp drf1 start pause all                                   */
      __IM  uint32_t bit_jpeg_drf_start_pause_all : 1;/*!< [18..18] jpeg drf start pause all                                   */
      __IM  uint32_t bit_mcu_drf_start_pause_all : 1;/*!< [19..19] mcu drf start pause all                                     */
      __IM  uint32_t bit_mipi_drf_start_pause_all : 1;/*!< [20..20] mipi drf start pause all                                   */
      __IM  uint32_t bit_ispocp_drf_start_pause_all : 1;/*!< [21..21] ispocp drf start pause all                               */
    } reg_sys_mem_drf_bist_all_b;
  } ;
  
  union {
    __IM  uint32_t reg_sys_isp_mem_bist_done;   /*!< (@ 0x0000083C) ISP Memory BIST Done Register                              */
    
    struct {
      __IM  uint32_t bit_mlsc_mem_bist_done : 1;/*!< [0..0] mlsc memory bist done                                              */
      __IM  uint32_t bit_awb_mem2_bist_done : 1;/*!< [1..1] awb_rgb memory2 bist done                                          */
      __IM  uint32_t bit_dpc_mem_bist_done : 1; /*!< [2..2] dpc memory bist done                                               */
      __IM  uint32_t bit_intp_mem_bist_done : 1;/*!< [3..3] intp memory bist done                                              */
      __IM  uint32_t bit_iir_mem_bist_done : 1; /*!< [4..4] iir memory bist done                                               */
      __IM  uint32_t bit_hdrs_mem_bist_done : 1;/*!< [5..5] hdrds memory bist done                                             */
      __IM  uint32_t bit_hdr_mem_bist_done : 1; /*!< [6..6] hdr memory bist done                                               */
      __IM  uint32_t bit_eeh_mem_bist_done : 1; /*!< [7..7] eeh memory bist done                                               */
      __IM  uint32_t bit_zoom_mem_bist_done : 1;/*!< [8..8] zoom memory bist done                                              */
      __IM  uint32_t bit_ae_mem_bist_done : 1;  /*!< [9..9] ae memory bist done                                                */
      __IM  uint32_t bit_fft_mem_bist_done : 1; /*!< [10..10] fft memory bist done                                             */
      __IM  uint32_t bit_mtd_mem_bist_done : 1; /*!< [11..11] mtd memory bist done                                             */
      __IM  uint32_t bit_dehaze_curve_b_mem_bist_done : 1;/*!< [12..12] dehaze curve b memory bist done                        */
      __IM  uint32_t bit_dehaze_curve_g_mem_bist_done : 1;/*!< [13..13] dehaze curve g memory bist done                        */
      __IM  uint32_t bit_dehaze_curve_r_mem_bist_done : 1;/*!< [14..14] dehaze curve r memory bist done                        */
      __IM  uint32_t bit_dehaze_histo_mem_bist_done : 1;/*!< [15..15] dehaze histo memory bist done                            */
      __IM  uint32_t bit_dehaze_pre_mem_bist_done : 1;/*!< [16..16] dehaze pre memory bist done                                */
      __IM  uint32_t bit_osd_fhd_mem_bist_done : 1;/*!< [17..17] osd fhd memory bist done                                      */
      __IM  uint32_t bit_osd_hs_mem_bist_done : 1;/*!< [18..18] osd hs memory bist done                                        */
      __IM  uint32_t bit_osd_vga_mem_bist_done : 1;/*!< [19..19] osd vga memory bist done                                      */
      __IM  uint32_t bit_ldc_mem_bist_done : 1; /*!< [20..20] ldc memory bist done                                             */
      __IM  uint32_t bit_mask_mem_bist_done : 1;/*!< [21..21] mask memory bist done                                            */
    } reg_sys_isp_mem_bist_done_b;
  } ;
  
  union {
    __IM  uint32_t reg_sys_video_mem_bist_done; /*!< (@ 0x00000840) Video Memory BIST Done Register                            */
    
    struct {
      __IM  uint32_t bit_jpeg_zigzag_mem_bist_done : 1;/*!< [0..0] jpeg zigzag memory bist done                                */
      __IM  uint32_t bit_jpeg_qnt_mem_bist_done : 1;/*!< [1..1] jpeg qnt memory bist done                                      */
      __IM  uint32_t bit_jpeg_dctr_mem_bist_done : 1;/*!< [2..2] jpeg dctr memory bist done                                    */
      __IM  uint32_t bit_jpeg_prejpeg_mem_bist_done : 1;/*!< [3..3] jpeg prejpeg memory bist done                              */
      __IM  uint32_t bit_huffman_mem_bist_done : 1;/*!< [4..4] huffman memory bist done                                        */
      __IM  uint32_t            : 3;
      __IM  uint32_t bit_mcu_cache_mem_bist_done : 1;/*!< [8..8] mcu cache memory bist done                                    */
      __IM  uint32_t bit_mcu_iram_mem_bist_done : 1;/*!< [9..9] mcu iram memory bist done                                      */
      __IM  uint32_t bit_mcu_xdat_mem_bist_done : 1;/*!< [10..10] mcu xdat memory bist done                                    */
      __IM  uint32_t            : 5;
      __IM  uint32_t bit_mipi_mem_bist_done : 1;/*!< [16..16] mipi memory bist done                                            */
      __IM  uint32_t            : 7;
      __IM  uint32_t bit_ispocp_isp_mem_bist_done : 1;/*!< [24..24] ispocp isp memory bist done                                */
      __IM  uint32_t bit_ispocp_jpg_mem_bist_done : 1;/*!< [25..25] ispocp jpeg memory bist done                               */
    } reg_sys_video_mem_bist_done_b;
  } ;
  
  union {
    __IM  uint32_t reg_sys_isp_mem_bist_ok;     /*!< (@ 0x00000844) ISP Memory BIST OK Register                                */
    
    struct {
      __IM  uint32_t bit_mlsc_mem_bist_ok : 1;  /*!< [0..0] mlsc memory bist ok                                                */
      __IM  uint32_t bit_awb_mem2_bist_ok : 1;  /*!< [1..1] awb_rgb memory2 bist ok                                            */
      __IM  uint32_t bit_dpc_mem_bist_ok : 1;   /*!< [2..2] dpc memory bist ok                                                 */
      __IM  uint32_t bit_intp_mem_bist_ok : 1;  /*!< [3..3] intp memory bist ok                                                */
      __IM  uint32_t bit_iir_mem_bist_ok : 1;   /*!< [4..4] iir memory bist ok                                                 */
      __IM  uint32_t bit_hdrs_mem_bist_ok : 1;  /*!< [5..5] hdrds memory bist ok                                               */
      __IM  uint32_t bit_hdr_mem_bist_ok : 1;   /*!< [6..6] hdr memory bist ok                                                 */
      __IM  uint32_t bit_eeh_mem_bist_ok : 1;   /*!< [7..7] eeh memory bist ok                                                 */
      __IM  uint32_t bit_zoom_mem_bist_ok : 1;  /*!< [8..8] zoom memory bist ok                                                */
      __IM  uint32_t bit_ae_mem_bist_ok : 1;    /*!< [9..9] ae memory bist ok                                                  */
      __IM  uint32_t bit_fft_mem_bist_ok : 1;   /*!< [10..10] fft memory bist ok                                               */
      __IM  uint32_t bit_mtd_mem_bist_ok : 1;   /*!< [11..11] mtd memory bist ok                                               */
      __IM  uint32_t bit_dehaze_curve_b_mem_bist_ok : 1;/*!< [12..12] dehaze curve b memory bist ok                            */
      __IM  uint32_t bit_dehaze_curve_g_mem_bist_ok : 1;/*!< [13..13] dehaze curve g memory bist ok                            */
      __IM  uint32_t bit_dehaze_curve_r_mem_bist_ok : 1;/*!< [14..14] dehaze curve r memory bist ok                            */
      __IM  uint32_t bit_dehaze_histo_mem_bist_ok : 1;/*!< [15..15] dehaze histo memory bist ok                                */
      __IM  uint32_t bit_dehaze_pre_mem_bist_ok : 1;/*!< [16..16] dehaze pre memory bist ok                                    */
      __IM  uint32_t bit_osd_fhd_mem_bist_ok : 1;/*!< [17..17] osd fhd memory bist ok                                          */
      __IM  uint32_t bit_osd_hs_mem_bist_ok : 1;/*!< [18..18] osd hs memory bist ok                                            */
      __IM  uint32_t bit_osd_vga_mem_bist_ok : 1;/*!< [19..19] osd vga memory bist ok                                          */
      __IM  uint32_t bit_ldc_mem_bist_ok : 1;   /*!< [20..20] ldc memory bist ok                                               */
      __IM  uint32_t bit_mask_mem_bist_ok : 1;  /*!< [21..21] mask memory bist ok                                              */
    } reg_sys_isp_mem_bist_ok_b;
  } ;
  
  union {
    __IM  uint32_t reg_sys_video_mem_bist_ok;   /*!< (@ 0x00000848) Video Memory BIST OK Register                              */
    
    struct {
      __IM  uint32_t bit_jpeg_zigzag_mem_bist_ok : 1;/*!< [0..0] jpeg zigzag memory bist ok                                    */
      __IM  uint32_t bit_jpeg_qnt_mem_bist_ok : 1;/*!< [1..1] jpeg qnt memory bist ok                                          */
      __IM  uint32_t bit_jpeg_dctr_mem_bist_ok : 1;/*!< [2..2] jpeg dctr memory bist ok                                        */
      __IM  uint32_t bit_jpeg_prejpeg_mem_bist_ok : 1;/*!< [3..3] jpeg prejpeg memory bist ok                                  */
      __IM  uint32_t bit_huffman_mem_bist_ok : 1;/*!< [4..4] huffman memory bist ok                                            */
      __IM  uint32_t            : 3;
      __IM  uint32_t bit_mcu_cache_mem_bist_ok : 1;/*!< [8..8] mcu cache memory bist ok                                        */
      __IM  uint32_t bit_mcu_iram_mem_bist_ok : 1;/*!< [9..9] mcu iram memory bist ok                                          */
      __IM  uint32_t bit_mcu_xdat_mem_bist_ok : 1;/*!< [10..10] mcu xdat memory bist ok                                        */
      __IM  uint32_t            : 5;
      __IM  uint32_t bit_mipi_mem_bist_ok : 1;  /*!< [16..16] mipi memory bist ok                                              */
      __IM  uint32_t            : 7;
      __IM  uint32_t bit_ispocp_isp_mem_bist_ok : 1;/*!< [24..24] ispocp isp memory bist ok                                    */
      __IM  uint32_t bit_ispocp_jpg_mem_bist_ok : 1;/*!< [25..25] ispocp jpeg memory bist ok                                   */
    } reg_sys_video_mem_bist_ok_b;
  } ;
  
  union {
    __IM  uint32_t reg_sys_isp_mem_drf_bist_done;/*!< (@ 0x0000084C) ISP Memory DRF BIST Done Register                         */
    
    struct {
      __IM  uint32_t bit_mlsc_mem_drf_bist_done : 1;/*!< [0..0] mlsc memory drf bist done                                      */
      __IM  uint32_t bit_awb_mem2_drf_bist_done : 1;/*!< [1..1] awb_rgb memory2 drf bist done                                  */
      __IM  uint32_t bit_dpc_mem_drf_bist_done : 1;/*!< [2..2] dpc memory drf bist done                                        */
      __IM  uint32_t bit_intp_mem_drf_bist_done : 1;/*!< [3..3] intp memory drf bist done                                      */
      __IM  uint32_t bit_iir_mem_drf_bist_done : 1;/*!< [4..4] iir memory drf bist done                                        */
      __IM  uint32_t bit_hdrs_mem_drf_bist_done : 1;/*!< [5..5] hdrds memory drf bist done                                     */
      __IM  uint32_t bit_hdr_mem_drf_bist_done : 1;/*!< [6..6] hdr memory drf bist done                                        */
      __IM  uint32_t bit_eeh_mem_drf_bist_done : 1;/*!< [7..7] eeh memory drf bist done                                        */
      __IM  uint32_t bit_zoom_mem_drf_bist_done : 1;/*!< [8..8] zoom memory drf bist done                                      */
      __IM  uint32_t bit_ae_mem_drf_bist_done : 1;/*!< [9..9] ae memory drf bist done                                          */
      __IM  uint32_t bit_fft_mem_drf_bist_done : 1;/*!< [10..10] fft memory drf bist done                                      */
      __IM  uint32_t bit_mtd_mem_drf_bist_done : 1;/*!< [11..11] mtd memory drf bist done                                      */
      __IM  uint32_t bit_dehaze_curve_b_mem_drf_bist_done : 1;/*!< [12..12] dehaze curve b memory drf bist done                */
      __IM  uint32_t bit_dehaze_curve_g_mem_drf_bist_done : 1;/*!< [13..13] dehaze curve g memory drf bist done                */
      __IM  uint32_t bit_dehaze_curve_r_mem_drf_bist_done : 1;/*!< [14..14] dehaze curve r memory drf bist done                */
      __IM  uint32_t bit_dehaze_histo_mem_drf_bist_done : 1;/*!< [15..15] dehaze histo memory drf bist done                    */
      __IM  uint32_t bit_dehaze_pre_mem_drf_bist_done : 1;/*!< [16..16] dehaze pre memory drf bist done                        */
      __IM  uint32_t bit_osd_fhd_mem_drf_bist_done : 1;/*!< [17..17] osd fhd memory drf bist done                              */
      __IM  uint32_t bit_osd_hs_mem_drf_bist_done : 1;/*!< [18..18] osd hs memory drf bist done                                */
      __IM  uint32_t bit_osd_vga_mem_drf_bist_done : 1;/*!< [19..19] osd vga memory drf bist done                              */
      __IM  uint32_t bit_ldc_mem_drf_bist_done : 1;/*!< [20..20] ldc memory drf bist done                                      */
      __IM  uint32_t bit_mask_mem_drf_bist_done : 1;/*!< [21..21] mask memory drf bist done                                    */
    } reg_sys_isp_mem_drf_bist_done_b;
  } ;
  
  union {
    __IM  uint32_t reg_sys_video_mem_drf_bist_done;/*!< (@ 0x00000850) Video Memory BIST Done Register                         */
    
    struct {
      __IM  uint32_t bit_jpeg_zigzag_mem_drf_bist_done : 1;/*!< [0..0] jpeg zigzag memory drf bist done                        */
      __IM  uint32_t bit_jpeg_qnt_mem_drf_bist_done : 1;/*!< [1..1] jpeg zigzag memory drf bist done                           */
      __IM  uint32_t bit_jpeg_dctr_mem_drf_bist_done : 1;/*!< [2..2] jpeg qnt memory drf bist done                             */
      __IM  uint32_t bit_jpeg_prejpeg_mem_drf_bist_done : 1;/*!< [3..3] jpeg dctr memory drf bist done                         */
      __IM  uint32_t bit_huffman_mem_drf_bist_done : 1;/*!< [4..4] jpeg prejpeg memory drf bist done                           */
      __IM  uint32_t            : 3;
      __IM  uint32_t bit_mcu_cache_mem_drf_bist_done : 1;/*!< [8..8] mcu cache memory drf bist done                            */
      __IM  uint32_t bit_mcu_iram_mem_drf_bist_done : 1;/*!< [9..9] mcu iram memory drf bist done                              */
      __IM  uint32_t bit_mcu_xdat_mem_drf_bist_done : 1;/*!< [10..10] mcu xdat memory drf bist done                            */
      __IM  uint32_t            : 5;
      __IM  uint32_t bit_mipi_mem_drf_bist_done : 1;/*!< [16..16] mipi memory drf bist done                                    */
      __IM  uint32_t            : 7;
      __IM  uint32_t bit_ispocp_isp_mem_drf_bist_done : 1;/*!< [24..24] ispocp isp memory drf bist done                        */
      __IM  uint32_t bit_ispocp_jpg_mem_drf_bist_done : 1;/*!< [25..25] ispocp jpeg memory drf bist done                       */
    } reg_sys_video_mem_drf_bist_done_b;
  } ;
  
  union {
    __IM  uint32_t reg_sys_isp_mem_drf_bist_ok; /*!< (@ 0x00000854) ISP Memory DRF BIST OK Register                            */
    
    struct {
      __IM  uint32_t bit_mlsc_mem_drf_bist_ok : 1;/*!< [0..0] mlsc memory drf bist ok                                          */
      __IM  uint32_t bit_awb_mem2_drf_bist_ok : 1;/*!< [1..1] awb_rgb memory2 drf bist ok                                      */
      __IM  uint32_t bit_dpc_mem_drf_bist_ok : 1;/*!< [2..2] dpc memory drf bist ok                                            */
      __IM  uint32_t bit_intp_mem_drf_bist_ok : 1;/*!< [3..3] intp memory drf bist ok                                          */
      __IM  uint32_t bit_iir_mem_drf_bist_ok : 1;/*!< [4..4] iir memory drf bist ok                                            */
      __IM  uint32_t bit_hdrs_mem_drf_bist_ok : 1;/*!< [5..5] hdrds memory drf bist ok                                         */
      __IM  uint32_t bit_hdr_mem_drf_bist_ok : 1;/*!< [6..6] hdr memory drf bist ok                                            */
      __IM  uint32_t bit_eeh_mem_drf_bist_ok : 1;/*!< [7..7] eeh memory drf bist ok                                            */
      __IM  uint32_t bit_zoom_mem_drf_bist_ok : 1;/*!< [8..8] zoom memory drf bist ok                                          */
      __IM  uint32_t bit_ae_mem_drf_bist_ok : 1;/*!< [9..9] ae memory drf bist ok                                              */
      __IM  uint32_t bit_fft_mem_drf_bist_ok : 1;/*!< [10..10] fft memory drf bist ok                                          */
      __IM  uint32_t bit_mtd_mem_drf_bist_ok : 1;/*!< [11..11] mtd memory drf bist ok                                          */
      __IM  uint32_t bit_dehaze_curve_b_mem_drf_bist_ok : 1;/*!< [12..12] dehaze curve b memory drf bist ok                    */
      __IM  uint32_t bit_dehaze_curve_g_mem_drf_bist_ok : 1;/*!< [13..13] dehaze curve g memory drf bist ok                    */
      __IM  uint32_t bit_dehaze_curve_r_mem_drf_bist_ok : 1;/*!< [14..14] dehaze curve r memory drf bist ok                    */
      __IM  uint32_t bit_dehaze_histo_mem_drf_bist_ok : 1;/*!< [15..15] dehaze histo memory drf bist ok                        */
      __IM  uint32_t bit_dehaze_pre_mem_drf_bist_ok : 1;/*!< [16..16] dehaze pre memory drf bist ok                            */
      __IM  uint32_t bit_osd_fhd_mem_drf_bist_ok : 1;/*!< [17..17] osd fhd memory drf bist ok                                  */
      __IM  uint32_t bit_osd_hs_mem_drf_bist_ok : 1;/*!< [18..18] osd hs memory drf bist ok                                    */
      __IM  uint32_t bit_osd_vga_mem_drf_bist_ok : 1;/*!< [19..19] osd vga memory drf bist ok                                  */
      __IM  uint32_t bit_ldc_mem_drf_bist_ok : 1;/*!< [20..20] ldc memory drf bist ok                                          */
      __IM  uint32_t bit_mask_mem_drf_bist_ok : 1;/*!< [21..21] mask memory drf bist ok                                        */
    } reg_sys_isp_mem_drf_bist_ok_b;
  } ;
  
  union {
    __IM  uint32_t reg_sys_video_mem_drf_bist_ok;/*!< (@ 0x00000858) Video Memory BIST OK Register                             */
    
    struct {
      __IM  uint32_t bit_jpeg_zigzag_mem_drf_bist_ok : 1;/*!< [0..0] jpeg zigzag memory drf bist done                          */
      __IM  uint32_t bit_jpeg_qnt_mem_drf_bist_ok : 1;/*!< [1..1] jpeg zigzag memory drf bist ok                               */
      __IM  uint32_t bit_jpeg_dctr_mem_drf_bist_ok : 1;/*!< [2..2] jpeg qnt memory drf bist ok                                 */
      __IM  uint32_t bit_jpeg_prejpeg_mem_drf_bist_ok : 1;/*!< [3..3] jpeg dctr memory drf bist ok                             */
      __IM  uint32_t bit_huffman_mem_drf_bist_ok : 1;/*!< [4..4] jpeg prejpeg memory drf bist ok                               */
      __IM  uint32_t            : 3;
      __IM  uint32_t bit_mcu_cache_mem_drf_bist_ok : 1;/*!< [8..8] mcu cache memory drf bist ok                                */
      __IM  uint32_t bit_mcu_iram_mem_drf_bist_ok : 1;/*!< [9..9] mcu iram memory drf bist ok                                  */
      __IM  uint32_t bit_mcu_xdat_mem_drf_bist_ok : 1;/*!< [10..10] mcu xdat memory drf bist ok                                */
      __IM  uint32_t            : 5;
      __IM  uint32_t bit_mipi_mem_drf_bist_ok : 1;/*!< [16..16] mipi memory drf bist ok                                        */
      __IM  uint32_t            : 7;
      __IM  uint32_t bit_ispocp_isp_mem_drf_bist_ok : 1;/*!< [24..24] ispocp isp memory drf bist ok                            */
      __IM  uint32_t bit_ispocp_jpg_mem_drf_bist_ok : 1;/*!< [25..25] ispocp jpeg memory drf bist ok                           */
    } reg_sys_video_mem_drf_bist_ok_b;
  } ;
  
  union {
    __IM  uint32_t reg_sys_isp_mem_drf_start_pause;/*!< (@ 0x0000085C) ISP Memory DRF Start Pause Register                     */
    
    struct {
      __IM  uint32_t bit_mlsc_mem_drf_start_pause : 1;/*!< [0..0] mlsc memory drf start pause                                  */
      __IM  uint32_t bit_awb_mem2_drf_start_pause : 1;/*!< [1..1] awb_rgb memory2 drf start pause                              */
      __IM  uint32_t bit_dpc_mem_drf_start_pause : 1;/*!< [2..2] dpc memory drf start pause                                    */
      __IM  uint32_t bit_intp_mem_drf_start_pause : 1;/*!< [3..3] intp memory drf start pause                                  */
      __IM  uint32_t bit_iir_mem_drf_start_pause : 1;/*!< [4..4] iir memory drf start pause                                    */
      __IM  uint32_t bit_hdrs_mem_drf_start_pause : 1;/*!< [5..5] hdrds memory drf start pause                                 */
      __IM  uint32_t bit_hdr_mem_drf_start_pause : 1;/*!< [6..6] hdr memory drf start pause                                    */
      __IM  uint32_t bit_eeh_mem_drf_start_pause : 1;/*!< [7..7] eeh memory drf start pause                                    */
      __IM  uint32_t bit_zoom_mem_drf_start_pause : 1;/*!< [8..8] zoom memory drf start pause                                  */
      __IM  uint32_t bit_ae_mem_drf_start_pause : 1;/*!< [9..9] ae memory drf start pause                                      */
      __IM  uint32_t bit_fft_mem_drf_start_pause : 1;/*!< [10..10] fft memory drf start pause                                  */
      __IM  uint32_t bit_mtd_mem_drf_start_pause : 1;/*!< [11..11] mtd memory drf start pause                                  */
      __IM  uint32_t bit_dehaze_curve_b_mem_drf_start_pause : 1;/*!< [12..12] dehaze curve b memory drf start pause            */
      __IM  uint32_t bit_dehaze_curve_g_mem_drf_start_pause : 1;/*!< [13..13] dehaze curve g memory drf start pause            */
      __IM  uint32_t bit_dehaze_curve_r_mem_drf_start_pause : 1;/*!< [14..14] dehaze curve r memory drf start pause            */
      __IM  uint32_t bit_dehaze_histo_mem_drf_start_pause : 1;/*!< [15..15] dehaze histo memory drf start pause                */
      __IM  uint32_t bit_dehaze_pre_mem_drf_start_pause : 1;/*!< [16..16] dehaze pre memory drf start pause                    */
      __IM  uint32_t bit_osd_fhd_mem_drf_start_pause : 1;/*!< [17..17] osd fhd memory drf start pause                          */
      __IM  uint32_t bit_osd_hs_mem_drf_start_pause : 1;/*!< [18..18] osd hs memory drf start pause                            */
      __IM  uint32_t bit_osd_vga_mem_drf_start_pause : 1;/*!< [19..19] osd vga memory drf start pause                          */
      __IM  uint32_t bit_ldc_mem_drf_start_pause : 1;/*!< [20..20] ldc memory drf start pause                                  */
      __IM  uint32_t bit_mask_mem_drf_start_pause : 1;/*!< [21..21] mask memory drf start pause                                */
    } reg_sys_isp_mem_drf_start_pause_b;
  } ;
  
  union {
    __IM  uint32_t reg_sys_video_mem_drf_start_pause;/*!< (@ 0x00000860) Video Memory DRF Start Pause Register                 */
    
    struct {
      __IM  uint32_t bit_jpeg_zigzag_mem_drf_start_pause : 1;/*!< [0..0] jpeg zigzag memory drf bist done                      */
      __IM  uint32_t bit_jpeg_qnt_mem_drf_start_pause : 1;/*!< [1..1] jpeg zigzag memory drf start pause                       */
      __IM  uint32_t bit_jpeg_dctr_mem_drf_start_pause : 1;/*!< [2..2] jpeg qnt memory drf start pause                         */
      __IM  uint32_t bit_jpeg_prejpeg_mem_drf_start_pause : 1;/*!< [3..3] jpeg dctr memory drf start pause                     */
      __IM  uint32_t bit_huffman_mem_drf_start_pause : 1;/*!< [4..4] jpeg prejpeg memory drf start pause                       */
      __IM  uint32_t            : 3;
      __IM  uint32_t bit_mcu_cache_mem_drf_start_pause : 1;/*!< [8..8] mcu cache memory drf start pause                        */
      __IM  uint32_t bit_mcu_iram_mem_drf_start_pause : 1;/*!< [9..9] mcu iram memory drf start pause                          */
      __IM  uint32_t bit_mcu_xdat_mem_drf_start_pause : 1;/*!< [10..10] mcu xdat memory drf start pause                        */
      __IM  uint32_t            : 5;
      __IM  uint32_t bit_mipi_mem_drf_start_pause : 1;/*!< [16..16] mipi memory drf start pause                                */
      __IM  uint32_t            : 7;
      __IM  uint32_t bit_ispocp_isp_mem_drf_start_pause : 1;/*!< [24..24] ispocp isp memory drf start pause                    */
      __IM  uint32_t bit_ispocp_jpg_mem_drf_start_pause : 1;/*!< [25..25] ispocp jpeg memory drf start pause                   */
    } reg_sys_video_mem_drf_start_pause_b;
  } ;
} ISP_REG_Type;                                 /*!< Size = 2148 (0x864)                                                       */

/** @} */ /* End of group Device_Peripheral_peripherals */

/**
  \brief Union type to access isp_reg_dat0_host_mcu (@ 0x00000000).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000000) ISP Data0 Register(CPU2MCU)                                */
  
  struct {
    __IOM uint32_t bit_cpu_mcu_dat0 : 32;     /*!< [31..0] Data0 from CPU send to MCU                                        */
  } b;
} isp_reg_dat0_host_mcu_t, *pisp_reg_dat0_host_mcu_t;

/**
  \brief Union type to access isp_reg_dat1_host_mcu (@ 0x00000004).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000004) ISP Data1 Register(CPU2MCU)                                */
  
  struct {
    __IOM uint32_t bit_cpu_mcu_dat1 : 32;     /*!< [31..0] Data1 from CPU send to MCU                                        */
  } b;
} isp_reg_dat1_host_mcu_t, *pisp_reg_dat1_host_mcu_t;

/**
  \brief Union type to access isp_reg_dat2_host_mcu (@ 0x00000008).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000008) ISP Data2 Register(CPU2MCU)                                */
  
  struct {
    __IOM uint32_t bit_cpu_mcu_dat2 : 32;     /*!< [31..0] Data2 from CPU send to MCU                                        */
  } b;
} isp_reg_dat2_host_mcu_t, *pisp_reg_dat2_host_mcu_t;

/**
  \brief Union type to access isp_reg_dat3_host_mcu (@ 0x0000000C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000000C) ISP Data3 Register(CPU2MCU)                                */
  
  struct {
    __IOM uint32_t bit_cpu_mcu_dat3 : 32;     /*!< [31..0] Data3 from CPU send to MCU                                        */
  } b;
} isp_reg_dat3_host_mcu_t, *pisp_reg_dat3_host_mcu_t;

/**
  \brief Union type to access isp_reg_dat4_host_mcu (@ 0x00000010).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000010) ISP Data4 Register(CPU2MCU)                                */
  
  struct {
    __IOM uint32_t bit_cpu_mcu_dat4 : 32;     /*!< [31..0] Data4 from CPU send to MCU                                        */
  } b;
} isp_reg_dat4_host_mcu_t, *pisp_reg_dat4_host_mcu_t;

/**
  \brief Union type to access isp_reg_dat5_host_mcu (@ 0x00000014).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000014) ISP Data5 Register(CPU2MCU)                                */
  
  struct {
    __IOM uint32_t bit_cpu_mcu_dat5 : 32;     /*!< [31..0] Data5 from CPU send to MCU                                        */
  } b;
} isp_reg_dat5_host_mcu_t, *pisp_reg_dat5_host_mcu_t;

/**
  \brief Union type to access isp_reg_dat6_host_mcu (@ 0x00000018).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000018) ISP Data6 Register(CPU2MCU)                                */
  
  struct {
    __IOM uint32_t bit_cpu_mcu_dat6 : 32;     /*!< [31..0] Data6 from CPU send to MCU                                        */
  } b;
} isp_reg_dat6_host_mcu_t, *pisp_reg_dat6_host_mcu_t;

/**
  \brief Union type to access isp_reg_dat7_host_mcu (@ 0x0000001C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000001C) ISP Data7 Register(CPU2MCU)                                */
  
  struct {
    __IOM uint32_t bit_cpu_mcu_dat7 : 32;     /*!< [31..0] Data7 from CPU send to MCU                                        */
  } b;
} isp_reg_dat7_host_mcu_t, *pisp_reg_dat7_host_mcu_t;

/**
  \brief Union type to access isp_reg_dat0_mcu_host (@ 0x00000020).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000020) ISP Data0 Register(MCU2CPU)                                */
  
  struct {
    __IM  uint32_t bit_mcu_cpu_dat0 : 32;     /*!< [31..0] Data0 from MCU send to CPU                                        */
  } b;
} isp_reg_dat0_mcu_host_t, *pisp_reg_dat0_mcu_host_t;

/**
  \brief Union type to access isp_reg_dat1_mcu_host (@ 0x00000024).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000024) ISP Data1 Register(MCU2CPU)                                */
  
  struct {
    __IM  uint32_t bit_mcu_cpu_dat1 : 32;     /*!< [31..0] Data1 from MCU send to CPU                                        */
  } b;
} isp_reg_dat1_mcu_host_t, *pisp_reg_dat1_mcu_host_t;

/**
  \brief Union type to access isp_reg_dat2_mcu_host (@ 0x00000028).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000028) ISP Data2 Register(MCU2CPU)                                */
  
  struct {
    __IM  uint32_t bit_mcu_cpu_dat2 : 32;     /*!< [31..0] Data2 from MCU send to CPU                                        */
  } b;
} isp_reg_dat2_mcu_host_t, *pisp_reg_dat2_mcu_host_t;

/**
  \brief Union type to access isp_reg_dat3_mcu_host (@ 0x0000002C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000002C) ISP Data3 Register(MCU2CPU)                                */
  
  struct {
    __IM  uint32_t bit_mcu_cpu_dat3 : 32;     /*!< [31..0] Data3 from MCU send to CPU                                        */
  } b;
} isp_reg_dat3_mcu_host_t, *pisp_reg_dat3_mcu_host_t;

/**
  \brief Union type to access isp_reg_dat4_mcu_host (@ 0x00000030).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000030) ISP Data4 Register(MCU2CPU)                                */
  
  struct {
    __IM  uint32_t bit_mcu_cpu_dat4 : 32;     /*!< [31..0] Data4 from MCU send to CPU                                        */
  } b;
} isp_reg_dat4_mcu_host_t, *pisp_reg_dat4_mcu_host_t;

/**
  \brief Union type to access isp_reg_dat5_mcu_host (@ 0x00000034).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000034) ISP Data5 Register(MCU2CPU)                                */
  
  struct {
    __IM  uint32_t bit_mcu_cpu_dat5 : 32;     /*!< [31..0] Data5 from MCU send to CPU                                        */
  } b;
} isp_reg_dat5_mcu_host_t, *pisp_reg_dat5_mcu_host_t;

/**
  \brief Union type to access isp_reg_dat6_mcu_host (@ 0x00000038).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000038) ISP Data6 Register(MCU2CPU)                                */
  
  struct {
    __IM  uint32_t bit_mcu_cpu_dat6 : 32;     /*!< [31..0] Data6 from MCU send to CPU                                        */
  } b;
} isp_reg_dat6_mcu_host_t, *pisp_reg_dat6_mcu_host_t;

/**
  \brief Union type to access isp_reg_dat7_mcu_host (@ 0x0000003C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000003C) ISP Data7 Register(MCU2CPU)                                */
  
  struct {
    __IM  uint32_t bit_mcu_cpu_dat7 : 32;     /*!< [31..0] Data7 from MCU send to CPU                                        */
  } b;
} isp_reg_dat7_mcu_host_t, *pisp_reg_dat7_mcu_host_t;

/**
  \brief Union type to access isp_reg_cmd0_host_mcu (@ 0x00000040).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000040) ISP Cmd0 Register(CPU2MCU)                                 */
  
  struct {
    __IOM uint32_t bit_cpu_mcu_cmd0 : 32;     /*!< [31..0] Cmd0 from CPU send to MCU                                         */
  } b;
} isp_reg_cmd0_host_mcu_t, *pisp_reg_cmd0_host_mcu_t;

/**
  \brief Union type to access isp_reg_cmd1_host_mcu (@ 0x00000044).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000044) ISP Cmd1 Register(CPU2MCU)                                 */
  
  struct {
    __IOM uint32_t bit_cpu_mcu_cmd1 : 32;     /*!< [31..0] Cmd1 from CPU send to MCU                                         */
  } b;
} isp_reg_cmd1_host_mcu_t, *pisp_reg_cmd1_host_mcu_t;

/**
  \brief Union type to access isp_reg_mcu_cmd_sts (@ 0x00000048).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000048) MCU command Status Register                                */
  
  struct {
    __IM  uint32_t            : 16;
    __IM  uint32_t bit_mcu_fail_type : 8;     /*!< [23..16] The failed type after MCU processed the CMD                      */
    __IM  uint32_t            : 6;
    __IM  uint32_t bit_mcu_proc_sts : 1;      /*!< [30..30] 0: MCU process the CMD successfully 1: MCU process
                                                   the CMD failed                                                            */
    __IM  uint32_t bit_mcu_busy_sts : 1;      /*!< [31..31] MCU status: 1. HW set 1 after CPU write the CMD0 ,it
                                                   is used to declare that MCU is busy to process the CMD
                                                   from CPU 2. After MCU process the CMD, MCU clear it. When
                                                   MCU clear this bit, HW will set MCU CMD done flag and trigger
                                                   CPU interrupt that indicate MCU in idle state. 3. CPU read
                                                   this bit to check MCU whether can receive new CMD                         */
  } b;
} isp_reg_mcu_cmd_sts_t, *pisp_reg_mcu_cmd_sts_t;

/**
  \brief Union type to access isp_reg_yuv_frame_y_start_addr_s0_f0 (@ 0x00000100).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_y_start_addr_s0_f0;                                   /*!< (@ 0x00000100) Y start address S0 F0 Register                         */
  
  struct {
    __IOM uint32_t bit_yuv_frame_y_start_addr_s0_f0 : 32;/*!< [31..0] Y start address for yuv Stream 0 frame 0 in DDR        */
  } b;
} isp_reg_yuv_frame_y_start_addr_s0_f0_t, *pisp_reg_yuv_frame_y_start_addr_s0_f0_t;

/**
  \brief Union type to access isp_reg_yuv_frame_y_start_addr_s0_f1 (@ 0x00000104).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_y_start_addr_s0_f1;                                   /*!< (@ 0x00000104) Y start address S0 F1 Register                         */
  
  struct {
    __IOM uint32_t bit_yuv_frame_y_start_addr_s0_f1 : 32;/*!< [31..0] Y start address for yuv Stream 0 frame 1 in DDR        */
  } b;
} isp_reg_yuv_frame_y_start_addr_s0_f1_t, *pisp_reg_yuv_frame_y_start_addr_s0_f1_t;

/**
  \brief Union type to access isp_reg_yuv_frame_y_start_addr_s0_f2 (@ 0x00000108).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_y_start_addr_s0_f2;                                   /*!< (@ 0x00000108) Y start address S0 F2 Register                         */
  
  struct {
    __IOM uint32_t bit_yuv_frame_y_start_addr_s0_f2 : 32;/*!< [31..0] Y start address for yuv Stream 0 frame 2 in DDR        */
  } b;
} isp_reg_yuv_frame_y_start_addr_s0_f2_t, *pisp_reg_yuv_frame_y_start_addr_s0_f2_t;

/**
  \brief Union type to access isp_reg_yuv_frame_y_start_addr_s0_f3 (@ 0x0000010C).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_y_start_addr_s0_f3;                                   /*!< (@ 0x0000010C) Y start address S0 F3 Register                         */
  
  struct {
    __IOM uint32_t bit_yuv_frame_y_start_addr_s0_f3 : 32;/*!< [31..0] Y start address for yuv Stream 0 frame 3 in DDR        */
  } b;
} isp_reg_yuv_frame_y_start_addr_s0_f3_t, *pisp_reg_yuv_frame_y_start_addr_s0_f3_t;

/**
  \brief Union type to access isp_reg_yuv_frame_y_start_addr_s1_f0 (@ 0x00000110).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_y_start_addr_s1_f0;                                   /*!< (@ 0x00000110) Y start address S1 F0 Register                         */
  
  struct {
    __IOM uint32_t bit_yuv_frame_y_start_addr_s1_f0 : 32;/*!< [31..0] Y start address for yuv Stream 1 frame 0 in DDR        */
  } b;
} isp_reg_yuv_frame_y_start_addr_s1_f0_t, *pisp_reg_yuv_frame_y_start_addr_s1_f0_t;

/**
  \brief Union type to access isp_reg_yuv_frame_y_start_addr_s1_f1 (@ 0x00000114).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_y_start_addr_s1_f1;                                   /*!< (@ 0x00000114) Y start address S1 F1 Register                         */
  
  struct {
    __IOM uint32_t bit_yuv_frame_y_start_addr_s1_f1 : 32;/*!< [31..0] Y start address for yuv Stream 1 frame 1 in DDR        */
  } b;
} isp_reg_yuv_frame_y_start_addr_s1_f1_t, *pisp_reg_yuv_frame_y_start_addr_s1_f1_t;

/**
  \brief Union type to access isp_reg_yuv_frame_y_start_addr_s1_f2 (@ 0x00000118).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_y_start_addr_s1_f2;                                   /*!< (@ 0x00000118) Y start address S1 F2 Register                         */
  
  struct {
    __IOM uint32_t bit_yuv_frame_y_start_addr_s1_f2 : 32;/*!< [31..0] Y start address for yuv Stream 1 frame 2 in DDR        */
  } b;
} isp_reg_yuv_frame_y_start_addr_s1_f2_t, *pisp_reg_yuv_frame_y_start_addr_s1_f2_t;

/**
  \brief Union type to access isp_reg_yuv_frame_y_start_addr_s1_f3 (@ 0x0000011C).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_y_start_addr_s1_f3;                                   /*!< (@ 0x0000011C) Y start address S1 F3 Register                         */
  
  struct {
    __IOM uint32_t bit_yuv_frame_y_start_addr_s1_f3 : 32;/*!< [31..0] Y start address for yuv Stream 1 frame 3 in DDR        */
  } b;
} isp_reg_yuv_frame_y_start_addr_s1_f3_t, *pisp_reg_yuv_frame_y_start_addr_s1_f3_t;

/**
  \brief Union type to access isp_reg_yuv_frame_y_start_addr_s2_f0 (@ 0x00000120).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_y_start_addr_s2_f0;                                   /*!< (@ 0x00000120) Y start address S2 F0 Register                         */
  
  struct {
    __IOM uint32_t bit_yuv_frame_y_start_addr_s2_f0 : 32;/*!< [31..0] Y start address for yuv Stream 2 frame 0 in DDR        */
  } b;
} isp_reg_yuv_frame_y_start_addr_s2_f0_t, *pisp_reg_yuv_frame_y_start_addr_s2_f0_t;

/**
  \brief Union type to access isp_reg_yuv_frame_y_start_addr_s2_f1 (@ 0x00000124).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_y_start_addr_s2_f1;                                   /*!< (@ 0x00000124) Y start address S2 F1 Register                         */
  
  struct {
    __IOM uint32_t bit_yuv_frame_y_start_addr_s2_f1 : 32;/*!< [31..0] Y start address for yuv Stream 2 frame 1 in DDR        */
  } b;
} isp_reg_yuv_frame_y_start_addr_s2_f1_t, *pisp_reg_yuv_frame_y_start_addr_s2_f1_t;

/**
  \brief Union type to access isp_reg_yuv_frame_y_start_addr_s2_f2 (@ 0x00000128).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_y_start_addr_s2_f2;                                   /*!< (@ 0x00000128) Y start address S2 F2 Register                         */
  
  struct {
    __IOM uint32_t bit_yuv_frame_y_start_addr_s2_f2 : 32;/*!< [31..0] Y start address for yuv Stream 2 frame 2 in DDR        */
  } b;
} isp_reg_yuv_frame_y_start_addr_s2_f2_t, *pisp_reg_yuv_frame_y_start_addr_s2_f2_t;

/**
  \brief Union type to access isp_reg_yuv_frame_y_start_addr_s2_f3 (@ 0x0000012C).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_y_start_addr_s2_f3;                                   /*!< (@ 0x0000012C) Y start address S2 F3 Register                         */
  
  struct {
    __IOM uint32_t bit_yuv_frame_y_start_addr_s2_f3 : 32;/*!< [31..0] Y start address for yuv Stream 2 frame 3 in DDR        */
  } b;
} isp_reg_yuv_frame_y_start_addr_s2_f3_t, *pisp_reg_yuv_frame_y_start_addr_s2_f3_t;

/**
  \brief Union type to access isp_reg_yuv_frame_uv_start_addr_s0_f0 (@ 0x00000180).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_uv_start_addr_s0_f0;                                    /*!< (@ 0x00000180) UV start address S0 F0 Register                       */
  
  struct {
    __IOM uint32_t bit_yuv_frame_uv_start_addr_s0_f0 : 32;/*!< [31..0] UV start address for yuv Stream 0 frame 0 in DDR      */
  } b;
} isp_reg_yuv_frame_uv_start_addr_s0_f0_t, *pisp_reg_yuv_frame_uv_start_addr_s0_f0_t;

/**
  \brief Union type to access isp_reg_yuv_frame_uv_start_addr_s0_f1 (@ 0x00000184).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_uv_start_addr_s0_f1;                                    /*!< (@ 0x00000184) UV start address S0 F1 Register                       */
  
  struct {
    __IOM uint32_t bit_yuv_frame_uv_start_addr_s0_f1 : 32;/*!< [31..0] UV start address for yuv Stream 0 frame 1 in DDR      */
  } b;
} isp_reg_yuv_frame_uv_start_addr_s0_f1_t, *pisp_reg_yuv_frame_uv_start_addr_s0_f1_t;

/**
  \brief Union type to access isp_reg_yuv_frame_uv_start_addr_s0_f2 (@ 0x00000188).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_uv_start_addr_s0_f2;                                    /*!< (@ 0x00000188) UV start address S0 F2 Register                       */
  
  struct {
    __IOM uint32_t bit_yuv_frame_uv_start_addr_s0_f2 : 32;/*!< [31..0] UV start address for yuv Stream 0 frame 2 in DDR      */
  } b;
} isp_reg_yuv_frame_uv_start_addr_s0_f2_t, *pisp_reg_yuv_frame_uv_start_addr_s0_f2_t;

/**
  \brief Union type to access isp_reg_yuv_frame_uv_start_addr_s0_f3 (@ 0x0000018C).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_uv_start_addr_s0_f3;                                    /*!< (@ 0x0000018C) UV start address S0 F3 Register                       */
  
  struct {
    __IOM uint32_t bit_yuv_frame_uv_start_addr_s0_f3 : 32;/*!< [31..0] UV start address for yuv Stream 0 frame 3 in DDR      */
  } b;
} isp_reg_yuv_frame_uv_start_addr_s0_f3_t, *pisp_reg_yuv_frame_uv_start_addr_s0_f3_t;

/**
  \brief Union type to access isp_reg_yuv_frame_uv_start_addr_s1_f0 (@ 0x00000190).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_uv_start_addr_s1_f0;                                    /*!< (@ 0x00000190) UV start address S1 F0 Register                       */
  
  struct {
    __IOM uint32_t bit_yuv_frame_uv_start_addr_s1_f0 : 32;/*!< [31..0] UV start address for yuv Stream 1 frame 0 in DDR      */
  } b;
} isp_reg_yuv_frame_uv_start_addr_s1_f0_t, *pisp_reg_yuv_frame_uv_start_addr_s1_f0_t;

/**
  \brief Union type to access isp_reg_yuv_frame_uv_start_addr_s1_f1 (@ 0x00000194).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_uv_start_addr_s1_f1;                                    /*!< (@ 0x00000194) UV start address S1 F1 Register                       */
  
  struct {
    __IOM uint32_t bit_yuv_frame_uv_start_addr_s1_f1 : 32;/*!< [31..0] UV start address for yuv Stream 1 frame 1 in DDR      */
  } b;
} isp_reg_yuv_frame_uv_start_addr_s1_f1_t, *pisp_reg_yuv_frame_uv_start_addr_s1_f1_t;

/**
  \brief Union type to access isp_reg_yuv_frame_uv_start_addr_s1_f2 (@ 0x00000198).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_uv_start_addr_s1_f2;                                    /*!< (@ 0x00000198) UV start address S1 F2 Register                       */
  
  struct {
    __IOM uint32_t bit_yuv_frame_uv_start_addr_s1_f2 : 32;/*!< [31..0] UV start address for yuv Stream 1 frame 2 in DDR      */
  } b;
} isp_reg_yuv_frame_uv_start_addr_s1_f2_t, *pisp_reg_yuv_frame_uv_start_addr_s1_f2_t;

/**
  \brief Union type to access isp_reg_yuv_frame_uv_start_addr_s1_f3 (@ 0x0000019C).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_uv_start_addr_s1_f3;                                    /*!< (@ 0x0000019C) UV start address S1 F3 Register                       */
  
  struct {
    __IOM uint32_t bit_yuv_frame_uv_start_addr_s1_f3 : 32;/*!< [31..0] UV start address for yuv Stream 1 frame 3 in DDR      */
  } b;
} isp_reg_yuv_frame_uv_start_addr_s1_f3_t, *pisp_reg_yuv_frame_uv_start_addr_s1_f3_t;

/**
  \brief Union type to access isp_reg_yuv_frame_uv_start_addr_s2_f0 (@ 0x000001A0).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_uv_start_addr_s2_f0;                                    /*!< (@ 0x000001A0) UV start address S2 F0 Register                       */
  
  struct {
    __IOM uint32_t bit_yuv_frame_uv_start_addr_s2_f0 : 32;/*!< [31..0] UV start address for yuv Stream 2 frame 0 in DDR      */
  } b;
} isp_reg_yuv_frame_uv_start_addr_s2_f0_t, *pisp_reg_yuv_frame_uv_start_addr_s2_f0_t;

/**
  \brief Union type to access isp_reg_yuv_frame_uv_start_addr_s2_f1 (@ 0x000001A4).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_uv_start_addr_s2_f1;                                    /*!< (@ 0x000001A4) UV start address S2 F1 Register                       */
  
  struct {
    __IOM uint32_t bit_yuv_frame_uv_start_addr_s2_f1 : 32;/*!< [31..0] UV start address for yuv Stream 2 frame 1 in DDR      */
  } b;
} isp_reg_yuv_frame_uv_start_addr_s2_f1_t, *pisp_reg_yuv_frame_uv_start_addr_s2_f1_t;

/**
  \brief Union type to access isp_reg_yuv_frame_uv_start_addr_s2_f2 (@ 0x000001A8).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_uv_start_addr_s2_f2;                                    /*!< (@ 0x000001A8) UV start address S2 F2 Register                       */
  
  struct {
    __IOM uint32_t bit_yuv_frame_uv_start_addr_s2_f2 : 32;/*!< [31..0] UV start address for yuv Stream 2 frame 2 in DDR      */
  } b;
} isp_reg_yuv_frame_uv_start_addr_s2_f2_t, *pisp_reg_yuv_frame_uv_start_addr_s2_f2_t;

/**
  \brief Union type to access isp_reg_yuv_frame_uv_start_addr_s2_f3 (@ 0x000001AC).
*/
typedef union {
  __IOM uint32_t reg_yuv_frame_uv_start_addr_s2_f3;                                    /*!< (@ 0x000001AC) UV start address S2 F3 Register                       */
  
  struct {
    __IOM uint32_t bit_yuv_frame_uv_start_addr_s2_f3 : 32;/*!< [31..0] UV start address for yuv Stream 2 frame 3 in DDR      */
  } b;
} isp_reg_yuv_frame_uv_start_addr_s2_f3_t, *pisp_reg_yuv_frame_uv_start_addr_s2_f3_t;

/**
  \brief Union type to access isp_reg_overflow_count (@ 0x00000258).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000258) Overflow Count Register                                    */
  
  struct {
    __IOM uint32_t bit_s0_count_overflow : 8; /*!< [7..0] Stream 0 Frame Count overflow in buffer (frame count
                                                   > FRAME_BUFFER_COUNT)                                                     */
    __IOM uint32_t bit_s1_count_overflow : 8; /*!< [15..8] Stream 1 Frame Count overflow in buffer (frame count
                                                   > FRAME_BUFFER_COUNT)                                                     */
    __IOM uint32_t bit_s2_count_overflow : 8; /*!< [23..16] Stream 2 Frame Count overflow in buffer (frame count
                                                   > FRAME_BUFFER_COUNT)                                                     */
  } b;
} isp_reg_overflow_count_t, *pisp_reg_overflow_count_t;

/**
  \brief Union type to access isp_reg_frame_buf_count (@ 0x00000260).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000260) Frame Buffer Count Register                                */
  
  struct {
    __IOM uint32_t bit_s0_frame_buf_count : 3;/*!< [2..0] YUV Frame buffer Count for Stream 0                                */
    __IM  uint32_t            : 1;
    __IOM uint32_t bit_s1_frame_buf_count : 3;/*!< [6..4] YUV Frame buffer Count for Stream 1                                */
    __IM  uint32_t            : 1;
    __IOM uint32_t bit_s2_frame_buf_count : 3;/*!< [10..8] YUV Frame buffer Count for Stream 2                               */
  } b;
} isp_reg_frame_buf_count_t, *pisp_reg_frame_buf_count_t;

/**
  \brief Union type to access isp_reg_isp_control (@ 0x00000264).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000264) ISP Control Register                                       */
  
  struct {
    __IOM uint32_t bit_reset_yuv_s0 : 1;      /*!< [0..0] 1: Reset YUV Stream 0                                              */
    __IOM uint32_t bit_reset_yuv_s1 : 1;      /*!< [1..1] 1: Reset YUV Stream 1                                              */
    __IOM uint32_t bit_reset_yuv_s2 : 1;      /*!< [2..2] 1: Reset YUV Stream 2                                              */
    __IM  uint32_t            : 5;
    __IOM uint32_t bit_control_yuv_s0 : 1;    /*!< [8..8] 1: START YUV Stream 0 0: STOP YUV Stream 0                         */
    __IOM uint32_t bit_control_yuv_s1 : 1;    /*!< [9..9] 1: START YUV Stream 1 0: STOP YUV Stream 1                         */
    __IOM uint32_t bit_control_yuv_s2 : 1;    /*!< [10..10] 1: START YUV Stream 2 0: STOP YUV Stream 2                       */
  } b;
} isp_reg_isp_control_t, *pisp_reg_isp_control_t;

/**
  \brief Union type to access isp_reg_yuv_y_config_s0 (@ 0x0000026C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000026C) ISP Y Buf Start Addr Config for S0 Register                */
  
  struct {
    __IOM uint32_t bit_isp_y_start_s0 : 13;   /*!< [12..0] ISP buffer Y start for yuv Stream 0, must be 8-alignment.         */
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_isp_y_len_s0 : 14;     /*!< [29..16] ISP buffer Y length for yuv stream 0, must be 8-alignement.
                                                   All YUV streams share a 8K ISP buffer to store data from
                                                   ISP to OCP bus temporarily.                                               */
  } b;
} isp_reg_yuv_y_config_s0_t, *pisp_reg_yuv_y_config_s0_t;

/**
  \brief Union type to access isp_reg_yuv_uv_config_s0 (@ 0x00000270).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000270) ISP UV Buf Start Addr Config for S0 Register               */
  
  struct {
    __IOM uint32_t bit_isp_uv_start_s0 : 13;  /*!< [12..0] ISP buffer UV start for yuv Stream 0, must be 8-alignment.        */
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_isp_uv_len_s0 : 14;    /*!< [29..16] ISP buffer UV length for yuv stream 0, must be 8-alignement.     */
  } b;
} isp_reg_yuv_uv_config_s0_t, *pisp_reg_yuv_uv_config_s0_t;

/**
  \brief Union type to access isp_reg_yuv_y_config_s1 (@ 0x00000274).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000274) ISP Y Buf Start Addr Config for S1 Register                */
  
  struct {
    __IOM uint32_t bit_isp_y_start_s1 : 13;   /*!< [12..0] ISP buffer Y start for yuv Stream 1, must be 8-alignment.         */
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_isp_y_len_s1 : 14;     /*!< [29..16] ISP buffer Y length for yuv stream 1, must be 8-alignement.      */
  } b;
} isp_reg_yuv_y_config_s1_t, *pisp_reg_yuv_y_config_s1_t;

/**
  \brief Union type to access isp_reg_yuv_uv_config_s1 (@ 0x00000278).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000278) ISP UV Buf Start Addr Config for S1 Register               */
  
  struct {
    __IOM uint32_t bit_isp_uv_start_s1 : 13;  /*!< [12..0] ISP buffer UV start for yuv Stream 1, must be 8-alignment.        */
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_isp_uv_len_s1 : 14;    /*!< [29..16] ISP buffer UV length for yuv stream 1, must be 8-alignement.     */
  } b;
} isp_reg_yuv_uv_config_s1_t, *pisp_reg_yuv_uv_config_s1_t;

/**
  \brief Union type to access isp_reg_yuv_y_config_s2 (@ 0x0000027C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000027C) ISP Y Buf Start Addr Config for S2 Register                */
  
  struct {
    __IOM uint32_t bit_isp_y_start_s2 : 13;   /*!< [12..0] ISP buffer Y start for yuv Stream 2, must be 8-alignment.         */
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_isp_y_len_s2 : 14;     /*!< [29..16] ISP buffer Y length for yuv stream 2, must be 8-alignement.      */
  } b;
} isp_reg_yuv_y_config_s2_t, *pisp_reg_yuv_y_config_s2_t;

/**
  \brief Union type to access isp_reg_yuv_uv_config_s2 (@ 0x00000280).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000280) ISP UV Buf Start Addr Config for S2 Register               */
  
  struct {
    __IOM uint32_t bit_isp_uv_start_s2 : 13;  /*!< [12..0] ISP buffer UV start for yuv Stream 2, must be 8-alignment.        */
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_isp_uv_len_s2 : 14;    /*!< [29..16] ISP buffer UV length for yuv stream 2, must be 8-alignement.     */
  } b;
} isp_reg_yuv_uv_config_s2_t, *pisp_reg_yuv_uv_config_s2_t;

/**
  \brief Union type to access isp_reg_stream_frame_interval (@ 0x00000298).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000298) Stream Frame Interval Config Register                      */
  
  struct {
    __IOM uint32_t bit_stream_frame_interval : 8;/*!< [7..0] Frame interval, interval for data from ISP clock domain
                                                   to OCP clock domain while frame end                                       */
  } b;
} isp_reg_stream_frame_interval_t, *pisp_reg_stream_frame_interval_t;

/**
  \brief Union type to access isp_reg_pts_value_config (@ 0x000002A0).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000002A0) PTS Value Config Register                                  */
  
  struct {
    __IOM uint32_t bit_pts_value_config : 32; /*!< [31..0] PTS initial value, use OCP bus clock as its base clock            */
  } b;
} isp_reg_pts_value_config_t, *pisp_reg_pts_value_config_t;

/**
  \brief Union type to access isp_reg_yuv_frame_buf_status_s0 (@ 0x000002A4).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000002A4) Frame Buffer Status for YUV Stream 0 Register              */
  
  struct {
    __IM  uint32_t bit_overflow_s0_f0 : 2;    /*!< [1..0] Stream 0 frame 0: 0: ISP Y buffer overflow 1: ISP UV
                                                   buffer overflow                                                           */
    __IOM uint32_t bit_error_s0_f0 : 1;       /*!< [2..2] Stream 0 frame 0 error bit: 0: No error 1: Has error               */
    __IOM uint32_t bit_dat_valid_s0_f0 : 1;   /*!< [3..3] Stream 0 frame 0 Data valid: 0: Release 1: Data Valid,
                                                   Received frame, DIC set this bit to 1                                     */
    __IM  uint32_t bit_overflow_s0_f1 : 2;    /*!< [5..4] Stream 0 frame 1: 0: ISP Y buffer overflow 1: ISP UV
                                                   buffer overflow                                                           */
    __IOM uint32_t bit_error_s0_f1 : 1;       /*!< [6..6] Stream 0 frame 1 error bit: 0: No error 1: Has error               */
    __IOM uint32_t bit_dat_valid_s0_f1 : 1;   /*!< [7..7] Stream 0 frame 1 Data valid: 0: Release 1: Data Valid,
                                                   Received frame, DIC set this bit to 1                                     */
    __IM  uint32_t bit_overflow_s0_f2 : 2;    /*!< [9..8] Stream 0 frame 2: 0: ISP Y buffer overflow 1: ISP UV
                                                   buffer overflow                                                           */
    __IOM uint32_t bit_error_s0_f2 : 1;       /*!< [10..10] Stream 0 frame 2 error bit: 0: No error 1: Has error             */
    __IOM uint32_t bit_dat_valid_s0_f2 : 1;   /*!< [11..11] Stream 0 frame 2 Data valid: 0: Release 1: Data Valid,
                                                   Received frame, DIC set this bit to 1                                     */
    __IM  uint32_t bit_overflow_s0_f3 : 2;    /*!< [13..12] Stream 0 frame 3: 0: ISP Y buffer overflow 1: ISP UV
                                                   buffer overflow                                                           */
    __IOM uint32_t bit_error_s0_f3 : 1;       /*!< [14..14] Stream 0 frame 3 error bit: 0: No error 1: Has error             */
    __IOM uint32_t bit_dat_valid_s0_f3 : 1;   /*!< [15..15] Stream 0 frame 3 Data valid: 0: Release 1: Data Valid,
                                                   Received frame, DIC set this bit to 1                                     */
  } b;
} isp_reg_yuv_frame_buf_status_s0_t, *pisp_reg_yuv_frame_buf_status_s0_t;

/**
  \brief Union type to access isp_reg_yuv_frame_buf_status_s1 (@ 0x000002A8).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000002A8) Frame Buffer Status for YUV Stream 1 Register              */
  
  struct {
    __IM  uint32_t bit_overflow_s1_f0 : 2;    /*!< [1..0] Stream 1 frame 0: 0: ISP Y buffer overflow 1: ISP UV
                                                   buffer overflow                                                           */
    __IOM uint32_t bit_error_s1_f0 : 1;       /*!< [2..2] Stream 1 frame 0 error bit: 0: No error 1: Has error               */
    __IOM uint32_t bit_dat_valid_s1_f0 : 1;   /*!< [3..3] Stream 1 frame 0 Data valid: 0: Release 1: Data Valid,
                                                   Received frame, DIC set this bit to 1                                     */
    __IM  uint32_t bit_overflow_s1_f1 : 2;    /*!< [5..4] Stream 1 frame 1: 0: ISP Y buffer overflow 1: ISP UV
                                                   buffer overflow                                                           */
    __IOM uint32_t bit_error_s1_f1 : 1;       /*!< [6..6] Stream 1 frame 1 error bit: 0: No error 1: Has error               */
    __IOM uint32_t bit_dat_valid_s1_f1 : 1;   /*!< [7..7] Stream 1 frame 1 Data valid: 0: Release 1: Data Valid,
                                                   Received frame, DIC set this bit to 1                                     */
    __IM  uint32_t bit_overflow_s1_f2 : 2;    /*!< [9..8] Stream 1 frame 2: 0: ISP Y buffer overflow 1: ISP UV
                                                   buffer overflow                                                           */
    __IOM uint32_t bit_error_s1_f2 : 1;       /*!< [10..10] Stream 1 frame 2 error bit: 0: No error 1: Has error             */
    __IOM uint32_t bit_dat_valid_s1_f2 : 1;   /*!< [11..11] Stream 1 frame 2 Data valid: 0: Release 1: Data Valid,
                                                   Received frame, DIC set this bit to 1                                     */
    __IM  uint32_t bit_overflow_s1_f3 : 2;    /*!< [13..12] Stream 1 frame 3: 0: ISP Y buffer overflow 1: ISP UV
                                                   buffer overflow                                                           */
    __IOM uint32_t bit_error_s1_f3 : 1;       /*!< [14..14] Stream 1 frame 3 error bit: 0: No error 1: Has error             */
    __IOM uint32_t bit_dat_valid_s1_f3 : 1;   /*!< [15..15] Stream 1 frame 3 Data valid: 0: Release 1: Data Valid,
                                                   Received frame, DIC set this bit to 1                                     */
  } b;
} isp_reg_yuv_frame_buf_status_s1_t, *pisp_reg_yuv_frame_buf_status_s1_t;

/**
  \brief Union type to access isp_reg_yuv_frame_buf_status_s2 (@ 0x000002AC).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000002AC) Frame Buffer Status for YUV Stream 2 Register              */
  
  struct {
    __IM  uint32_t bit_overflow_s2_f0 : 2;    /*!< [1..0] Stream 2 frame 0: 0: ISP Y buffer overflow 1: ISP UV
                                                   buffer overflow                                                           */
    __IOM uint32_t bit_error_s2_f0 : 1;       /*!< [2..2] Stream 2 frame 0 error bit: 0: No error 1: Has error               */
    __IOM uint32_t bit_dat_valid_s2_f0 : 1;   /*!< [3..3] Stream 2 frame 0 Data valid: 0: Release 1: Data Valid,
                                                   Received frame, DIC set this bit to 1                                     */
    __IM  uint32_t bit_overflow_s2_f1 : 2;    /*!< [5..4] Stream 2 frame 1: 0: ISP Y buffer overflow 1: ISP UV
                                                   buffer overflow                                                           */
    __IOM uint32_t bit_error_s2_f1 : 1;       /*!< [6..6] Stream 2 frame 1 error bit: 0: No error 1: Has error               */
    __IOM uint32_t bit_dat_valid_s2_f1 : 1;   /*!< [7..7] Stream 2 frame 1 Data valid: 0: Release 1: Data Valid,
                                                   Received frame, DIC set this bit to 1                                     */
    __IM  uint32_t bit_overflow_s2_f2 : 2;    /*!< [9..8] Stream 2 frame 2: 0: ISP Y buffer overflow 1: ISP UV
                                                   buffer overflow                                                           */
    __IOM uint32_t bit_error_s2_f2 : 1;       /*!< [10..10] Stream 2 frame 2 error bit: 0: No error 1: Has error             */
    __IOM uint32_t bit_dat_valid_s2_f2 : 1;   /*!< [11..11] Stream 2 frame 2 Data valid: 0: Release 1: Data Valid,
                                                   Received frame, DIC set this bit to 1                                     */
    __IM  uint32_t bit_overflow_s2_f3 : 2;    /*!< [13..12] Stream 2 frame 3: 0: ISP Y buffer overflow 1: ISP UV
                                                   buffer overflow                                                           */
    __IOM uint32_t bit_error_s2_f3 : 1;       /*!< [14..14] Stream 2 frame 3 error bit: 0: No error 1: Has error             */
    __IOM uint32_t bit_dat_valid_s2_f3 : 1;   /*!< [15..15] Stream 2 frame 3 Data valid: 0: Release 1: Data Valid,
                                                   Received frame, DIC set this bit to 1                                     */
  } b;
} isp_reg_yuv_frame_buf_status_s2_t, *pisp_reg_yuv_frame_buf_status_s2_t;

/**
  \brief Union type to access isp_reg_yuv_cur_frame_index_offset_s0 (@ 0x000002C0).
*/
typedef union {
  __IOM uint32_t reg_yuv_cur_frame_index_offset_s0;                                    /*!< (@ 0x000002C0) Current Frame Index and Offset for S0 Register        */
  
  struct {
    __IM  uint32_t bit_cur_index : 2;         /*!< [1..0] Current Index                                                      */
    __IM  uint32_t bit_cur_offset : 22;       /*!< [23..2] Current Offset                                                    */
  } b;
} isp_reg_yuv_cur_frame_index_offset_s0_t, *pisp_reg_yuv_cur_frame_index_offset_s0_t;

/**
  \brief Union type to access isp_reg_yuv_cur_frame_index_offset_s1 (@ 0x000002C4).
*/
typedef union {
  __IOM uint32_t reg_yuv_cur_frame_index_offset_s1;                                    /*!< (@ 0x000002C4) Current Frame Index and Offset for S1 Register        */
  
  struct {
    __IM  uint32_t bit_cur_index : 2;         /*!< [1..0] Current Index                                                      */
    __IM  uint32_t bit_cur_offset : 22;       /*!< [23..2] Current Offset                                                    */
  } b;
} isp_reg_yuv_cur_frame_index_offset_s1_t, *pisp_reg_yuv_cur_frame_index_offset_s1_t;

/**
  \brief Union type to access isp_reg_yuv_cur_frame_index_offset_s2 (@ 0x000002C8).
*/
typedef union {
  __IOM uint32_t reg_yuv_cur_frame_index_offset_s2;                                    /*!< (@ 0x000002C8) Current Frame Index and Offset for S2 Register        */
  
  struct {
    __IM  uint32_t bit_cur_index : 2;         /*!< [1..0] Current Index                                                      */
    __IM  uint32_t bit_cur_offset : 22;       /*!< [23..2] Current Offset                                                    */
  } b;
} isp_reg_yuv_cur_frame_index_offset_s2_t, *pisp_reg_yuv_cur_frame_index_offset_s2_t;

/**
  \brief Union type to access isp_reg_yuv_y_buf_overflow_count (@ 0x000002D4).
*/
typedef union {
  __IOM uint32_t reg_yuv_y_buf_overflow_count;                               /*!< (@ 0x000002D4) ISP Y Overflow count for YUV Stream Register               */
  
  struct {
    __IOM uint32_t bit_y_buf_overflow_count_s0 : 8;/*!< [7..0] Stream 0 ISP Y buffer overflow count                          */
    __IOM uint32_t bit_y_buf_overflow_count_s1 : 8;/*!< [15..8] Stream 1 ISP Y buffer overflow count                         */
    __IOM uint32_t bit_y_buf_overflow_count_s2 : 8;/*!< [23..16] Stream 2 ISP Y buffer overflow count                        */
  } b;
} isp_reg_yuv_y_buf_overflow_count_t, *pisp_reg_yuv_y_buf_overflow_count_t;

/**
  \brief Union type to access isp_reg_yuv_uv_buf_overflow_count (@ 0x000002D8).
*/
typedef union {
  __IOM uint32_t reg_yuv_uv_buf_overflow_count;                                /*!< (@ 0x000002D8) ISP UV Overflow count for YUV Stream Register             */
  
  struct {
    __IOM uint32_t bit_yv_buf_overflow_count_s0 : 8;/*!< [7..0] Stream 0 ISP UV buffer overflow count                        */
    __IOM uint32_t bit_uv_buf_overflow_count_s1 : 8;/*!< [15..8] Stream 1 ISP UV buffer overflow count                       */
    __IOM uint32_t bit_uv_buf_overflow_count_s2 : 8;/*!< [23..16] Stream 2 ISP UV buffer overflow count                      */
  } b;
} isp_reg_yuv_uv_buf_overflow_count_t, *pisp_reg_yuv_uv_buf_overflow_count_t;

/**
  \brief Union type to access isp_reg_mjpeg_buf_overflow_count (@ 0x000002DC).
*/
typedef union {
  __IOM uint32_t reg_mjpeg_buf_overflow_count;                               /*!< (@ 0x000002DC) ISP MJPEG Overflow count Register                          */
  
  struct {
    __IOM uint32_t bit_mjpeg_buf_overflow_count : 8;/*!< [7..0] MJPEG Stream ISP buffer overflow count                       */
  } b;
} isp_reg_mjpeg_buf_overflow_count_t, *pisp_reg_mjpeg_buf_overflow_count_t;

/**
  \brief Union type to access isp_reg_isp_header_start_addr (@ 0x000002F0).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000002F0) ISP Header Start Address Register                          */
  
  struct {
    __IOM uint32_t bit_isp_header_start_addr : 32;/*!< [31..0] ISP Header Start Address Offset from header of each
                                                   frame of each stream is shown below: Stream0: frame0: 0x0
                                                   frame1: 0x8 frame2: 0x10 frame3: 0x18 Stream1: frame0:
                                                   0x20 frame1: 0x28 frame2: 0x30 frame3: 0x38 Stream2: frame0:
                                                   0x40 frame1: 0x48 frame2: 0x50 frame3: 0x58                               */
  } b;
} isp_reg_isp_header_start_addr_t, *pisp_reg_isp_header_start_addr_t;

/**
  \brief Union type to access isp_reg_isp_burst_len_sel (@ 0x000002F4).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000002F4) ISP OCP Master Burst Length Select Register                */
  
  struct {
    __IOM uint32_t bit_mjpeg_buf_overflow_count : 2;/*!< [1..0] ISP_BUSRT_LEGNTH_SEL 0: 32Byte 1: 64Byte 2: 128Byte          */
  } b;
} isp_reg_isp_burst_len_sel_t, *pisp_reg_isp_burst_len_sel_t;

/**
  \brief Union type to access isp_reg_isp_slice_end_cfg (@ 0x000002F8).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000002F8) ISP Slice End Configuration Register                       */
  
  struct {
    __IOM uint32_t bit_isp_s0_slice_end_enable : 1;/*!< [0..0] ISP_S0_SLICE_END_ENABLE 0:disable 1:enable                    */
    __IOM uint32_t bit_isp_s0_slice_height_setting : 3;/*!< [3..1] ISP_S0_SLICE_HEIGHT_SETTING 0: 4 line 1: 8 line 2: 16
                                                   line 3: 32 line 4: 64 line                                                */
    __IM  uint32_t            : 4;
    __IOM uint32_t bit_isp_s1_slice_end_enable : 1;/*!< [8..8] ISP_S1_SLICE_END_ENABLE 0:disable 1:enable                    */
    __IOM uint32_t bit_isp_s1_slice_height_setting : 3;/*!< [11..9] ISP_S1_SLICE_HEIGHT_SETTING 0: 4 line 1: 8 line 2: 16
                                                   line 3: 32 line 4: 64 line                                                */
    __IM  uint32_t            : 4;
    __IOM uint32_t bit_isp_s2_slice_end_enable : 1;/*!< [16..16] ISP_S2_SLICE_END_ENABLE 0:disable 1:enable                  */
    __IOM uint32_t bit_isp_s2_slice_height_setting : 3;/*!< [19..17] ISP_S2_SLICE_HEIGHT_SETTING 0: 4 line 1: 8 line 2:
                                                   16 line 3: 32 line 4: 64 line                                             */
  } b;
} isp_reg_isp_slice_end_cfg_t, *pisp_reg_isp_slice_end_cfg_t;

/**
  \brief Union type to access isp_reg_isp_frame_down_en (@ 0x000002FC).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x000002FC) ISP Frame Down Enable Register                             */
  
  struct {
    __IOM uint32_t bit_isp_frame_down_en : 1; /*!< [0..0] ISP_FRAME_DOWN_EN 0: disable 1: enable                             */
  } b;
} isp_reg_isp_frame_down_en_t, *pisp_reg_isp_frame_down_en_t;

/**
  \brief Union type to access isp_reg_isp_ocpif_dummy (@ 0x00000300).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000300) ISP Frame Down Enable Register                             */
  
  struct {
    __IOM uint32_t bit_isp_ocpif_dummy : 32;  /*!< [31..0] ISP_OCPIF_DUMMY                                                   */
  } b;
} isp_reg_isp_ocpif_dummy_t, *pisp_reg_isp_ocpif_dummy_t;

/**
  \brief Union type to access isp_reg_mcu_spi_base_addr (@ 0x00000400).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000400) MCU SPI Base Address Register                              */
  
  struct {
    __IOM uint32_t bit_mcu_spi_base_addr : 32;/*!< [31..0] MCU code base address in serial flash                             */
  } b;
} isp_reg_mcu_spi_base_addr_t, *pisp_reg_mcu_spi_base_addr_t;

/**
  \brief Union type to access isp_reg_cpu_lock_mcu (@ 0x00000404).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000404) CPU Lock MCU Register                                      */
  
  struct {
    __IOM uint32_t bit_cpu_request_lock_mcu : 1;/*!< [0..0] CPU request lock MCU                                             */
    __IM  uint32_t bit_cpu_lock_mcu_done : 1; /*!< [1..1] CPU lock MCU done                                                  */
    __OM  uint32_t bit_cpu_release_lock : 1;  /*!< [2..2] CPU release lock                                                   */
    __OM  uint32_t bit_mcu_cache_miss_flag_clear : 1;/*!< [3..3] MCU cache miss flag clear                                   */
  } b;
} isp_reg_cpu_lock_mcu_t, *pisp_reg_cpu_lock_mcu_t;

/**
  \brief Union type to access isp_reg_int_en_mcu_host (@ 0x00000500).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000500) MCU Interrupt to Host Enable Register                      */
  
  struct {
    __IOM uint32_t bit_mcu_cmd_done_int_enable : 1;/*!< [0..0] MCU CMD done interrupt enable.                                */
    __IOM uint32_t bit_cache_miss_fail_int_enable : 1;/*!< [1..1] Cache miss fail interrupt enable                           */
    __IOM uint32_t bit_mcu_watchdog_reset_cpu_int_enable : 1;/*!< [2..2] MCU watchdog reset CPU interrupt enable             */
    __IM  uint32_t            : 13;
    __IOM uint32_t bit_mtd0_motion_int_enable : 1;/*!< [16..16] MTD0 motion interrupt enable                                 */
    __IOM uint32_t bit_mtd1_motion_int_enable : 1;/*!< [17..17] MTD1 motion interrupt enable                                 */
    __IOM uint32_t bit_mtd2_motion_int_enable : 1;/*!< [18..18] MTD2 motion interrupt enable                                 */
    __IOM uint32_t bit_mtd3_motion_int_enable : 1;/*!< [19..19] MTD3 motion interrupt enable                                 */
    __IOM uint32_t bit_mtd4_motion_int_enable : 1;/*!< [20..20] MTD4 motion interrupt enable                                 */
    __IOM uint32_t bit_mcu_trig_cpu_int_enable : 11;/*!< [31..21] MCU trigger CPU interrupt enable, bitmap register which
                                                   one bit response one interrupt type for CPU.                              */
  } b;
} isp_reg_int_en_mcu_host_t, *pisp_reg_int_en_mcu_host_t;

/**
  \brief Union type to access isp_reg_int_en_isp_host (@ 0x00000504).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000504) MCU Interrupt to Host Enable Register                      */
  
  struct {
    __IOM uint32_t bit_yuv_uv_buf_overflow_int_s0 : 1;/*!< [0..0] YUV Stream 0 UV ISP buffer overflow interrupt              */
    __IOM uint32_t bit_yuv_y_buf_overflow_int_s0 : 1;/*!< [1..1] YUV Stream 0 Y ISP buffer overflow interrupt                */
    __IOM uint32_t bit_yuv_frame_count_overflow_int_s0 : 1;/*!< [2..2] YUV Stream 0 DDR frame count overflow interrupt       */
    __IOM uint32_t bit_yuv_send_to_ddr_done_int_s0 : 1;/*!< [3..3] YUV Stream 0 frame send to DDR done interrupt             */
    __IOM uint32_t bit_yuv_uv_buf_overflow_int_s1 : 1;/*!< [4..4] YUV Stream 1 UV ISP buffer overflow interrupt              */
    __IOM uint32_t bit_yuv_y_buf_overflow_int_s1 : 1;/*!< [5..5] YUV Stream 1 Y ISP buffer overflow interrupt                */
    __IOM uint32_t bit_yuv_frame_count_overflow_int_s1 : 1;/*!< [6..6] YUV Stream 1 DDR frame count overflow interrupt       */
    __IOM uint32_t bit_yuv_send_to_ddr_done_int_s1 : 1;/*!< [7..7] YUV Stream 1 frame send to DDR done interrupt             */
    __IOM uint32_t bit_yuv_uv_buf_overflow_int_s2 : 1;/*!< [8..8] YUV Stream 2 UV ISP buffer overflow interrupt              */
    __IOM uint32_t bit_yuv_y_buf_overflow_int_s2 : 1;/*!< [9..9] YUV Stream 2 Y ISP buffer overflow interrupt                */
    __IOM uint32_t bit_yuv_frame_count_overflow_int_s2 : 1;/*!< [10..10] YUV Stream 2 DDR frame count overflow interrupt     */
    __IOM uint32_t bit_yuv_send_to_ddr_done_int_s2 : 1;/*!< [11..11] YUV Stream 2 frame send to DDR done interrupt           */
  } b;
} isp_reg_int_en_isp_host_t, *pisp_reg_int_en_isp_host_t;

/**
  \brief Union type to access isp_reg_int_flag_mcu_host (@ 0x00000508).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000508) MCU interrupt to Host flag Register                        */
  
  struct {
    __IOM uint32_t bit_mcu_cmd_done_int_flag : 1;/*!< [0..0] MCU CMD done interrupt flag. CPU write 1 clear this flag.       */
    __IOM uint32_t bit_cache_miss_fail_int_flag : 1;/*!< [1..1] Cache miss fail interrupt flag                               */
    __IOM uint32_t bit_mcu_watchdog_reset_cpu_int_flag : 1;/*!< [2..2] MCU watchdog reset CPU interrupt flag                 */
    __IM  uint32_t            : 4;
    __IOM uint32_t bit_mtd0_motion_int_flag : 1;/*!< [7..7] MTD0 motion interrupt flag                                       */
    __IOM uint32_t bit_mtd1_motion_int_flag : 1;/*!< [8..8] MTD1 motion interrupt flag                                       */
    __IOM uint32_t bit_mtd2_motion_int_flag : 1;/*!< [9..9] MTD2 motion interrupt flag                                       */
    __IOM uint32_t bit_mtd3_motion_int_flag : 1;/*!< [10..10] MTD3 motion interrupt flag                                     */
    __IM  uint32_t            : 9;
    __IOM uint32_t bit_mtd4_motion_int_flag : 1;/*!< [20..20] MTD4 motion interrupt flag                                     */
    __IOM uint32_t bit_mcu_int_flag : 11;     /*!< [31..21] MCU interrupt flag. 1. MCU write 1 set interrupt flag
                                                   and trigger CPU interrupt. 2. CPU write 1 clear interrupt
                                                   flag. 3. CPU/MCU write 0 will not influence the interrupt
                                                   flag.                                                                     */
  } b;
} isp_reg_int_flag_mcu_host_t, *pisp_reg_int_flag_mcu_host_t;

/**
  \brief Union type to access isp_reg_int_flag_isp_host (@ 0x0000050C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000050C) MCU interrupt to Host flag Register                        */
  
  struct {
    __IOM uint32_t bit_yuv_uv_buf_overflow_int_s0 : 1;/*!< [0..0] YUV Stream 0 UV ISP buffer overflow interrupt              */
    __IOM uint32_t bit_yuv_y_buf_overflow_int_s0 : 1;/*!< [1..1] YUV Stream 0 Y ISP buffer overflow interrupt                */
    __IOM uint32_t bit_yuv_frame_count_overflow_int_s0 : 1;/*!< [2..2] YUV Stream 0 DDR frame count overflow interrupt       */
    __IOM uint32_t bit_yuv_send_to_ddr_done_int_s0 : 1;/*!< [3..3] YUV Stream 0 frame send to DDR done interrupt             */
    __IOM uint32_t bit_yuv_uv_buf_overflow_int_s1 : 1;/*!< [4..4] YUV Stream 1 UV ISP buffer overflow interrupt              */
    __IOM uint32_t bit_yuv_y_buf_overflow_int_s1 : 1;/*!< [5..5] YUV Stream 1 Y ISP buffer overflow interrupt                */
    __IOM uint32_t bit_yuv_frame_count_overflow_int_s1 : 1;/*!< [6..6] YUV Stream 1 DDR frame count overflow interrupt       */
    __IOM uint32_t bit_yuv_send_to_ddr_done_int_s1 : 1;/*!< [7..7] YUV Stream 1 frame send to DDR done interrupt             */
    __IOM uint32_t bit_yuv_uv_buf_overflow_int_s2 : 1;/*!< [8..8] YUV Stream 2 UV ISP buffer overflow interrupt              */
    __IOM uint32_t bit_yuv_y_buf_overflow_int_s2 : 1;/*!< [9..9] YUV Stream 2 Y ISP buffer overflow interrupt                */
    __IOM uint32_t bit_yuv_frame_count_overflow_int_s2 : 1;/*!< [10..10] YUV Stream 2 DDR frame count overflow interrupt     */
    __IOM uint32_t bit_yuv_send_to_ddr_done_int_s2 : 1;/*!< [11..11] YUV Stream 2 frame send to DDR done interrupt           */
  } b;
} isp_reg_int_flag_isp_host_t, *pisp_reg_int_flag_isp_host_t;

/**
  \brief Union type to access isp_reg_force_async_rst (@ 0x00000600).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000600) Force Async Reset Register                                 */
  
  struct {
    __IOM uint32_t bit_force_mcu_reset : 1;   /*!< [0..0] FORCE_MCU_RESET 1: force async-reset 0: release async-reset        */
    __IOM uint32_t bit_force_isp_reset : 1;   /*!< [1..1] FORCE_ISP_RESET                                                    */
    __IOM uint32_t bit_force_mipi_reset : 1;  /*!< [2..2] FORCE_MIPI_RESET                                                   */
    __IOM uint32_t bit_force_jpeg_reset : 1;  /*!< [3..3] FORCE_JPEG_RESET                                                   */
  } b;
} isp_reg_force_async_rst_t, *pisp_reg_force_async_rst_t;

/**
  \brief Union type to access isp_reg_jpeg_clk_cfg (@ 0x00000700).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000700) JPEG Clock Source Select Register                          */
  
  struct {
    __IOM uint32_t bit_jpeg_clk_src_sel : 1;  /*!< [0..0] jpeg_clk_src_sel 0: clk400 1: clk300                               */
    __IOM uint32_t bit_jpeg_clk_div_sel : 3;  /*!< [3..1] jpeg_clk_div_sel[2:0] 000: div1 001: div2 010: div4 011:
                                                   div8 100: div16 101: div32 110: div64 111: div128                         */
    __IOM uint32_t bit_jpeg_clk_en : 1;       /*!< [4..4] jpeg_clk_en 0: disable 1: enable                                   */
  } b;
} isp_reg_jpeg_clk_cfg_t, *pisp_reg_jpeg_clk_cfg_t;

/**
  \brief Union type to access isp_reg_mcu_clk_cfg_scan (@ 0x00000704).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000704) MCU Clock Source Select Register for At-speed
                                                                  Scan Test                                                  */
  
  struct {
    __IOM uint32_t bit_mcu_clk_src_sel : 1;   /*!< [0..0] mcu_clk_src_sel_scan 0: clk400 1: clk300 only for scan
                                                   at-speed test                                                             */
    __IOM uint32_t bit_mcu_clk_div_sel : 3;   /*!< [3..1] mcu_clk_div_sel_scan[2:0] 000: div1 001: div2 010: div4
                                                   011: div8 100: div16 101: div32 110: div64 111: div128
                                                   only for scan at-speed test                                               */
    __IOM uint32_t bit_mcu_clk_en : 1;        /*!< [4..4] mcu_clk_en 0: disable 1: enable function and scan mcu
                                                   clock enable 0: disable 1: enable                                         */
  } b;
} isp_reg_mcu_clk_cfg_scan_t, *pisp_reg_mcu_clk_cfg_scan_t;

/**
  \brief Union type to access isp_reg_isp_clk_cfg_scan (@ 0x00000708).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000708) ISP Clock Source Select Register for At-speed
                                                                  Scan Test                                                  */
  
  struct {
    __IOM uint32_t bit_isp_clk_src_sel : 1;   /*!< [0..0] isp_clk_src_sel_scan 0: clk400 1: clk300                           */
    __IOM uint32_t bit_isp_clk_div_sel : 3;   /*!< [3..1] isp_clk_div_sel_scan[2:0] 000: div1 001: div2 010: div4
                                                   011: div8 100: div16 101: div32 110: div64 111: div128                    */
    __IOM uint32_t bit_isp_clk_en : 1;        /*!< [4..4] isp_clk_en_scan 0: disable 1: enable                               */
  } b;
} isp_reg_isp_clk_cfg_scan_t, *pisp_reg_isp_clk_cfg_scan_t;

/**
  \brief Union type to access isp_reg_mipi_clk_cfg_scan (@ 0x0000070C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000070C) MIPI Clock Source Select Register for At-speed
                                                                  Scan Test                                                  */
  
  struct {
    __IOM uint32_t bit_mipi_clk_src_sel : 1;  /*!< [0..0] mipi_clk_src_sel_scan 0: clk400 1: clk300                          */
    __IOM uint32_t bit_mipi_clk_div_sel : 3;  /*!< [3..1] mipi_clk_div_sel_scan[2:0] 000: div1 001: div2 010: div4
                                                   011: div8 100: div16 101: div32 110: div64 111: div128                    */
    __IOM uint32_t bit_mipi_clk_en : 1;       /*!< [4..4] mipi_clk_en_scan 0: disable 1: enable                              */
  } b;
} isp_reg_mipi_clk_cfg_scan_t, *pisp_reg_mipi_clk_cfg_scan_t;

/**
  \brief Union type to access isp_reg_sys_isp_mem_ctl (@ 0x00000800).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000800) ISP Memory Control Register                                */
  
  struct {
    __IOM uint32_t bit_isp_mem_rme : 1;       /*!< [0..0] isp memory read margin enable                                      */
    __IOM uint32_t bit_isp_mem_rm : 4;        /*!< [4..1] isp memory read margin                                             */
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_isp_mem_ra : 2;        /*!< [9..8] isp memory read assist                                             */
    __IOM uint32_t bit_isp_mem_wa : 3;        /*!< [12..10] isp_mem_wa [2]: isp memory write assist enable isp_mem_wa
                                                   [1:0]: isp memory write assist                                            */
    __IOM uint32_t bit_isp_mem_wpulse : 3;    /*!< [15..13] isp memory write assist pulse                                    */
    __IOM uint32_t bit_isp_mem_pd : 2;        /*!< [17..16] isp memory(T40LP TSMC Memory) power down isp_mem_pd[0]:
                                                   osd fhd isp_mem_pd[1]: osd hd                                             */
  } b;
} isp_reg_sys_isp_mem_ctl_t, *pisp_reg_sys_isp_mem_ctl_t;

/**
  \brief Union type to access isp_reg_sys_isp_mem_ls (@ 0x00000804).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000804) ISP Memory Light Sleep Register                            */
  
  struct {
    __IOM uint32_t bit_mlsc_mem_ls_en : 1;    /*!< [0..0] mlsc memory light sleep enable: 1:enable, 0:disable                */
    __IOM uint32_t bit_awb1_mem_ls_en : 1;    /*!< [1..1] awb1 memory light sleep enable: 1:enable, 0:disable                */
    __IOM uint32_t bit_awb2_mem_ls_en : 1;    /*!< [2..2] awb2 memory light sleep enable: 1:enable, 0:disable                */
    __IOM uint32_t bit_dpc_mem_ls_en : 1;     /*!< [3..3] dpc memory light sleep enable: 1:enable, 0:disable                 */
    __IOM uint32_t bit_intp_mem_ls_en : 1;    /*!< [4..4] intp memory light sleep enable: 1:enable, 0:disable                */
    __IOM uint32_t bit_iir_mem_ls_en : 1;     /*!< [5..5] iir memory light sleep enable: 1:enable, 0:disable                 */
    __IOM uint32_t bit_hdrds_mem_ls_en : 1;   /*!< [6..6] hdrds memory light sleep enable: 1:enable, 0:disable               */
    __IOM uint32_t bit_hdr_mem_ls_en : 1;     /*!< [7..7] hdr memory light sleep enable: 1:enable, 0:disable                 */
    __IOM uint32_t bit_eeh_mem_ls_en : 1;     /*!< [8..8] eeh memory light sleep enable: 1:enable, 0:disable                 */
    __IOM uint32_t bit_zoom_mem_ls_en : 1;    /*!< [9..9] zoom memory light sleep enable: 1:enable, 0:disable                */
    __IOM uint32_t bit_ae_mem_ls_en : 1;      /*!< [10..10] ae memory light sleep enable: 1:enable, 0:disable                */
    __IOM uint32_t bit_fft_mem_ls_en : 1;     /*!< [11..11] fft memory light sleep enable: 1:enable, 0:disable               */
    __IOM uint32_t bit_mtd_mem_ls_en : 1;     /*!< [12..12] mtd memory light sleep enable: 1:enable, 0:disable               */
    __IOM uint32_t bit_dehaze_curve_b_mem_ls_en : 1;/*!< [13..13] dehaze curve b memory light sleep enable: 1:enable,
                                                   0:disable                                                                 */
    __IOM uint32_t bit_dehaze_curve_g_mem_ls_en : 1;/*!< [14..14] dehaze curve g memory light sleep enable: 1:enable,
                                                   0:disable                                                                 */
    __IOM uint32_t bit_dehaze_curve_r_mem_ls_en : 1;/*!< [15..15] dehaze curve r memory light sleep enable: 1:enable,
                                                   0:disable                                                                 */
    __IOM uint32_t bit_dehaze_histo_mem_ls_en : 1;/*!< [16..16] dehaze histo memory light sleep enable: 1:enable, 0:disable  */
    __IOM uint32_t bit_dehaze_pre_mem_ls_en : 1;/*!< [17..17] dehaze pre memory light sleep enable: 1:enable, 0:disable      */
    __IOM uint32_t bit_osd_vga_mem_ls_en : 1; /*!< [18..18] osd vga memory light sleep enable: 1:enable, 0:disable           */
    __IOM uint32_t bit_ldc_mem_ls_en : 1;     /*!< [19..19] ldc memory light sleep enable: 1:enable, 0:disable               */
    __IOM uint32_t bit_mask_mem_ls_en : 1;    /*!< [20..20] mask memory light sleep enable: 1:enable, 0:disable              */
  } b;
} isp_reg_sys_isp_mem_ls_t, *pisp_reg_sys_isp_mem_ls_t;

/**
  \brief Union type to access isp_reg_sys_isp_mem_ds (@ 0x00000808).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000808) ISP Memory Deep Sleep Register                             */
  
  struct {
    __IOM uint32_t bit_mlsc_mem_ds_en : 1;    /*!< [0..0] mlsc memory deep sleep enable: 1:enable, 0:disable                 */
    __IOM uint32_t bit_awb1_mem_ds_en : 1;    /*!< [1..1] awb1 memory deep sleep enable: 1:enable, 0:disable                 */
    __IOM uint32_t bit_awb2_mem_ds_en : 1;    /*!< [2..2] awb2 memory deep sleep enable: 1:enable, 0:disable                 */
    __IOM uint32_t bit_dpc_mem_ds_en : 1;     /*!< [3..3] dpc memory deep sleep enable: 1:enable, 0:disable                  */
    __IOM uint32_t bit_intp_mem_ds_en : 1;    /*!< [4..4] intp memory deep sleep enable: 1:enable, 0:disable                 */
    __IOM uint32_t bit_iir_mem_ds_en : 1;     /*!< [5..5] iir memory deep sleep enable: 1:enable, 0:disable                  */
    __IOM uint32_t bit_hdrds_mem_ds_en : 1;   /*!< [6..6] hdrds memory deep sleep enable: 1:enable, 0:disable                */
    __IOM uint32_t bit_hdr_mem_ds_en : 1;     /*!< [7..7] hdr memory deep sleep enable: 1:enable, 0:disable                  */
    __IOM uint32_t bit_eeh_mem_ds_en : 1;     /*!< [8..8] eeh memory deep sleep enable: 1:enable, 0:disable                  */
    __IOM uint32_t bit_zoom_mem_ds_en : 1;    /*!< [9..9] zoom memory deep sleep enable: 1:enable, 0:disable                 */
    __IOM uint32_t bit_ae_mem_ds_en : 1;      /*!< [10..10] ae memory deep sleep enable: 1:enable, 0:disable                 */
    __IOM uint32_t bit_fft_mem_ds_en : 1;     /*!< [11..11] fft memory deep sleep enable: 1:enable, 0:disable                */
    __IOM uint32_t bit_mtd_mem_ds_en : 1;     /*!< [12..12] mtd memory deep sleep enable: 1:enable, 0:disable                */
    __IOM uint32_t bit_dehaze_curve_b_mem_ds_en : 1;/*!< [13..13] dehaze curve b memory deep sleep enable: 1:enable,
                                                   0:disable                                                                 */
    __IOM uint32_t bit_dehaze_curve_g_mem_ds_en : 1;/*!< [14..14] dehaze curve g memory deep sleep enable: 1:enable,
                                                   0:disable                                                                 */
    __IOM uint32_t bit_dehaze_curve_r_mem_ds_en : 1;/*!< [15..15] dehaze curve r memory deep sleep enable: 1:enable,
                                                   0:disable                                                                 */
    __IOM uint32_t bit_dehaze_histo_mem_ds_en : 1;/*!< [16..16] dehaze histo memory deep sleep enable: 1:enable, 0:disable   */
    __IOM uint32_t bit_dehaze_pre_mem_ds_en : 1;/*!< [17..17] dehaze pre memory deep sleep enable: 1:enable, 0:disable       */
    __IOM uint32_t bit_osd_vga_mem_ds_en : 1; /*!< [18..18] osd vga memory deep sleep enable: 1:enable, 0:disable            */
    __IOM uint32_t bit_ldc_mem_ds_en : 1;     /*!< [19..19] ldc memory deep sleep enable: 1:enable, 0:disable                */
    __IOM uint32_t bit_mask_mem_ds_en : 1;    /*!< [20..20] mask memory deep sleep enable: 1:enable, 0:disable               */
  } b;
} isp_reg_sys_isp_mem_ds_t, *pisp_reg_sys_isp_mem_ds_t;

/**
  \brief Union type to access isp_reg_sys_isp_mem_sd (@ 0x0000080C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000080C) ISP Memory Shut Down Register                              */
  
  struct {
    __IOM uint32_t bit_mlsc_mem_sd_en : 1;    /*!< [0..0] mlsc memory shut down enable: 1:enable, 0:disable                  */
    __IOM uint32_t bit_awb1_mem_sd_en : 1;    /*!< [1..1] awb1 memory shut down enable: 1:enable, 0:disable                  */
    __IOM uint32_t bit_awb2_mem_sd_en : 1;    /*!< [2..2] awb2 memory shut down enable: 1:enable, 0:disable                  */
    __IOM uint32_t bit_dpc_mem_sd_en : 1;     /*!< [3..3] dpc memory shut down enable: 1:enable, 0:disable                   */
    __IOM uint32_t bit_intp_mem_sd_en : 1;    /*!< [4..4] intp memory shut down enable: 1:enable, 0:disable                  */
    __IOM uint32_t bit_iir_mem_sd_en : 1;     /*!< [5..5] iir memory shut down enable: 1:enable, 0:disable                   */
    __IOM uint32_t bit_hdrds_mem_sd_en : 1;   /*!< [6..6] hdrds memory shut down enable: 1:enable, 0:disable                 */
    __IOM uint32_t bit_hdr_mem_sd_en : 1;     /*!< [7..7] hdr memory shut down enable: 1:enable, 0:disable                   */
    __IOM uint32_t bit_eeh_mem_sd_en : 1;     /*!< [8..8] eeh memory shut down enable: 1:enable, 0:disable                   */
    __IOM uint32_t bit_zoom_mem_sd_en : 1;    /*!< [9..9] zoom memory shut down enable: 1:enable, 0:disable                  */
    __IOM uint32_t bit_ae_mem_sd_en : 1;      /*!< [10..10] ae memory shut down enable: 1:enable, 0:disable                  */
    __IOM uint32_t bit_fft_mem_sd_en : 1;     /*!< [11..11] fft memory shut down enable: 1:enable, 0:disable                 */
    __IOM uint32_t bit_mtd_mem_sd_en : 1;     /*!< [12..12] mtd memory shut down enable: 1:enable, 0:disable                 */
    __IOM uint32_t bit_dehaze_curve_b_mem_sd_en : 1;/*!< [13..13] dehaze curve b memory shut down enable: 1:enable, 0:disable */
    __IOM uint32_t bit_dehaze_curve_g_mem_sd_en : 1;/*!< [14..14] dehaze curve g memory shut down enable: 1:enable, 0:disable */
    __IOM uint32_t bit_dehaze_curve_r_mem_sd_en : 1;/*!< [15..15] dehaze curve r memory shut down enable: 1:enable, 0:disable */
    __IOM uint32_t bit_dehaze_histo_mem_sd_en : 1;/*!< [16..16] dehaze histo memory shut down enable: 1:enable, 0:disable    */
    __IOM uint32_t bit_dehaze_pre_mem_sd_en : 1;/*!< [17..17] dehaze pre memory shut down enable: 1:enable, 0:disable        */
    __IOM uint32_t bit_osd_vga_mem_sd_en : 1; /*!< [18..18] osd vga memory shut down enable: 1:enable, 0:disable             */
    __IOM uint32_t bit_ldc_mem_sd_en : 1;     /*!< [19..19] ldc memory shut down enable: 1:enable, 0:disable                 */
    __IOM uint32_t bit_mask_mem_sd_en : 1;    /*!< [20..20] mask memory shut down enable: 1:enable, 0:disable                */
  } b;
} isp_reg_sys_isp_mem_sd_t, *pisp_reg_sys_isp_mem_sd_t;

/**
  \brief Union type to access isp_reg_sys_jpeg_mem_ctl (@ 0x00000810).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000810) JPEG Memory Control Register                               */
  
  struct {
    __IOM uint32_t bit_jpeg_mem_rme : 1;      /*!< [0..0] jpeg memory read margin enable                                     */
    __IOM uint32_t bit_jpeg_mem_rm : 4;       /*!< [4..1] jpeg memory read margin                                            */
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_jpeg_mem_ra : 2;       /*!< [9..8] jpeg memory read assist                                            */
    __IOM uint32_t bit_jpeg_mem_wa : 3;       /*!< [12..10] jpeg_mem_wa [2]: isp memory write assist enable jpeg_mem_wa
                                                   [1:0]: isp memory write assist                                            */
    __IOM uint32_t bit_jpeg_mem_wap : 3;      /*!< [15..13] jpeg memory write assist pulse                                   */
    __IOM uint32_t bit_jpeg_mem_ls_en : 4;    /*!< [19..16] jpeg memory light sleep enable: 1:enable, 0:disable
                                                   jpeg_mem_ls[0]: pre jpeg jpeg_mem_ls[1]: zigzag jpeg_mem_ls[2]:
                                                   qnt jpeg_mem_ls[3]: huffman                                               */
    __IOM uint32_t bit_jpeg_mem_ds_en : 3;    /*!< [22..20] jpeg memory deep sleep enable: 1:enable, 0:disable
                                                   jpeg_mem_ds[0]: pre jpeg jpeg_mem_ds[1]: zigzag jpeg_mem_ds[2]:
                                                   qnt                                                                       */
    __IM  uint32_t            : 1;
    __IOM uint32_t bit_jpeg_mem_sd_en : 4;    /*!< [27..24] jpeg memory shut down enable: 1:enable, 0:disable jpeg_mem_sd[0]:
                                                   pre jpeg jpeg_mem_sd[1]: zigzag jpeg_mem_sd[2]: qnt jpeg_mem_sd[3]:
                                                   huffman                                                                   */
    __IOM uint32_t bit_jpeg_mem_pd : 1;       /*!< [28..28] jpeg memory(T40LP TSMC Memory) power down                        */
  } b;
} isp_reg_sys_jpeg_mem_ctl_t, *pisp_reg_sys_jpeg_mem_ctl_t;

/**
  \brief Union type to access isp_reg_sys_mcu_mem_ctl (@ 0x00000814).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000814) MCU Memory Control Register                                */
  
  struct {
    __IOM uint32_t bit_mcu_mem_rme : 1;       /*!< [0..0] mcu memory read margin enable                                      */
    __IOM uint32_t bit_mcu_mem_rm : 4;        /*!< [4..1] mcu memory read margin                                             */
    __IM  uint32_t            : 3;
    __IOM uint32_t bit_mcu_mem_ra : 2;        /*!< [9..8] mcu memory read assist                                             */
    __IOM uint32_t bit_mcu_mem_wa : 3;        /*!< [12..10] mcu_mem_wa [2]: isp memory write assist enable mcu_mem_wa
                                                   [1:0]: isp memory write assist                                            */
    __IOM uint32_t bit_mcu_mem_wap : 3;       /*!< [15..13] mcu memory write assist pulse                                    */
    __IOM uint32_t bit_mcu_mem_ls_en : 3;     /*!< [18..16] mcu memory light sleep enable: 1:enable, 0:disable
                                                   mcu_mem_ls[0]: cache mcu_mem_ls[1]: iram mcu_mem_ls[2]:
                                                   xdat                                                                      */
    __IOM uint32_t bit_mcu_mem_ds_en : 3;     /*!< [21..19] mcu memory deep sleep enable: 1:enable, 0:disable mcu_mem_ds[0]:
                                                   cache mcu_mem_ds[1]: iram mcu_mem_ds[2]: xdat                             */
    __IM  uint32_t            : 2;
    __IOM uint32_t bit_mcu_mem_sd_en : 3;     /*!< [26..24] mcu memory shut down enable: 1:enable, 0:disable mcu_mem_sd[0]:
                                                   cache mcu_mem_sd[1]: iram mcu_mem_sd[2]: xdat                             */
  } b;
} isp_reg_sys_mcu_mem_ctl_t, *pisp_reg_sys_mcu_mem_ctl_t;

/**
  \brief Union type to access isp_reg_sys_mipi_mem_ctl (@ 0x00000818).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000818) MIPI Memory Control Register                               */
  
  struct {
    __IOM uint32_t bit_mipi_mem_rme : 1;      /*!< [0..0] mipi memory read margin enable                                     */
    __IOM uint32_t bit_mipi_mem_rm : 4;       /*!< [4..1] mipi memory read margin                                            */
    __IM  uint32_t            : 11;
    __IOM uint32_t bit_mipi_mem_sd_en : 1;    /*!< [16..16] mipi memory shut down enable: 1:enable, 0:disable                */
  } b;
} isp_reg_sys_mipi_mem_ctl_t, *pisp_reg_sys_mipi_mem_ctl_t;

/**
  \brief Union type to access isp_reg_sys_ispocp_mem_ctl (@ 0x0000081C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000081C) ISPOCP Memory Control Register                             */
  
  struct {
    __IOM uint32_t bit_ispocp_mem_rme : 1;    /*!< [0..0] ispocp memory read margin enable                                   */
    __IOM uint32_t bit_ispocp_mem_rm : 4;     /*!< [4..1] ispocp memory read margin                                          */
    __IM  uint32_t            : 11;
    __IOM uint32_t bit_ispocp_mem_sd_en : 2;  /*!< [17..16] ispocp memory shut down enable: 1:enable, 0:disable
                                                   ispocp_mem_pd[0]: isp ispocp_mem_pd[1]: jpeg                              */
  } b;
} isp_reg_sys_ispocp_mem_ctl_t, *pisp_reg_sys_ispocp_mem_ctl_t;

/**
  \brief Union type to access isp_reg_sys_mem_bist_rst (@ 0x00000820).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000820) Memory BIST Reset Register                                 */
  
  struct {
    __IOM uint32_t bit_isp_bist0_rst : 1;     /*!< [0..0] isp part0 bist reset: 0:reset, 1:release                           */
    __IOM uint32_t bit_isp_bist1_rst : 1;     /*!< [1..1] isp part1 bist reset: 0:reset, 1:release                           */
    __IOM uint32_t bit_jpeg_bist_rst : 1;     /*!< [2..2] jpeg bist reset: 0:reset, 1:release                                */
    __IOM uint32_t bit_mcu_bist_rst : 1;      /*!< [3..3] mcu bist reset: 0:reset, 1:release                                 */
    __IOM uint32_t bit_mipi_bist_rst : 1;     /*!< [4..4] mipi bist reset: 0:reset, 1:release                                */
    __IOM uint32_t bit_ispocp_bist_rst : 1;   /*!< [5..5] ispocp bist reset: 0:reset, 1:release                              */
  } b;
} isp_reg_sys_mem_bist_rst_t, *pisp_reg_sys_mem_bist_rst_t;

/**
  \brief Union type to access isp_reg_sys_mem_bist_en (@ 0x00000824).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000824) Memory BIST Enable Register                                */
  
  struct {
    __IOM uint32_t bit_isp_bist0_en : 1;      /*!< [0..0] isp part0 bist enable: 0:disable, 1:enable                         */
    __IOM uint32_t bit_isp_bist1_en : 1;      /*!< [1..1] isp part1 bist enable: 0:disable, 1:enable                         */
    __IOM uint32_t bit_jpeg_bist_en : 1;      /*!< [2..2] jpeg bist enable: 0:disable, 1:enable                              */
    __IOM uint32_t bit_mcu_bist_en : 1;       /*!< [3..3] mcu bist enable: 0:disable, 1:enable                               */
    __IOM uint32_t bit_mipi_bist_en : 1;      /*!< [4..4] mipi bist enable: 0:disable, 1:enable                              */
    __IOM uint32_t bit_ispocp_bist_en : 1;    /*!< [5..5] ispocp bist enable: 0:disable, 1:enable                            */
  } b;
} isp_reg_sys_mem_bist_en_t, *pisp_reg_sys_mem_bist_en_t;

/**
  \brief Union type to access isp_reg_sys_mem_drf_bist_en (@ 0x00000828).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000828) Memory DRF BIST Enable Register                            */
  
  struct {
    __IOM uint32_t bit_isp_drf_bist0_en : 1;  /*!< [0..0] isp part0 drf bist enable: 0:disable, 1:enable                     */
    __IOM uint32_t bit_isp_drf_bist1_en : 1;  /*!< [1..1] isp part1 drf bist enable: 0:disable, 1:enable                     */
    __IOM uint32_t bit_jpeg_drf_bist_en : 1;  /*!< [2..2] jpeg drf bist enable: 0:disable, 1:enable                          */
    __IOM uint32_t bit_mcu_drf_bist_en : 1;   /*!< [3..3] mcu drf bist enable: 0:disable, 1:enable                           */
    __IOM uint32_t bit_mipi_drf_bist_en : 1;  /*!< [4..4] mipi drf bist enable: 0:disable, 1:enable                          */
    __IOM uint32_t bit_ispocp_drf_bist_en : 1;/*!< [5..5] ispocp drf bist enable: 0:disable, 1:enable                        */
  } b;
} isp_reg_sys_mem_drf_bist_en_t, *pisp_reg_sys_mem_drf_bist_en_t;

/**
  \brief Union type to access isp_reg_sys_mem_drf_bist_resume (@ 0x0000082C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000082C) Memory DRF BIST Resume Register                            */
  
  struct {
    __IOM uint32_t bit_isp_drf_bist0_resume : 1;/*!< [0..0] isp part0 drf bist resume, high active                           */
    __IOM uint32_t bit_isp_drf_bist1_resume : 1;/*!< [1..1] isp part1 drf bist resume, high active                           */
    __IOM uint32_t bit_jpeg_drf_bist_resume : 1;/*!< [2..2] jpeg drf bist resume, high active                                */
    __IOM uint32_t bit_mcu_drf_bist_resume : 1;/*!< [3..3] mcu drf bist resume, high active                                  */
    __IOM uint32_t bit_mipi_drf_bist_resume : 1;/*!< [4..4] mipi drf bist resume, high active                                */
    __IOM uint32_t bit_ispocp_drf_bist_resume : 1;/*!< [5..5] ispocp drf bist resume, high active                            */
  } b;
} isp_reg_sys_mem_drf_bist_resume_t, *pisp_reg_sys_mem_drf_bist_resume_t;

/**
  \brief Union type to access isp_reg_sys_mem_drf_resume_sync (@ 0x00000830).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000830) Memory DRF BIST Resume Sync Register                       */
  
  struct {
    __IOM uint32_t bit_drf_resume_sync_cnt : 7;/*!< [6..0] When drf_resume_sync_en = 1 This means the length of
                                                   drf resume signal count by clk25M                                         */
    __IOM uint32_t bit_drf_resume_sync_en : 1;/*!< [7..7] 1: drf resume signal is sync by drf_resume_sync_cnt 0:
                                                   not sync                                                                  */
  } b;
} isp_reg_sys_mem_drf_resume_sync_t, *pisp_reg_sys_mem_drf_resume_sync_t;

/**
  \brief Union type to access isp_reg_sys_mem_bist_all (@ 0x00000834).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000834) Memory BIST All Register                                   */
  
  struct {
    __IM  uint32_t bit_isp_bist0_done_all : 1;/*!< [0..0] isp bist0 done all                                                 */
    __IM  uint32_t bit_isp_bist1_done_all : 1;/*!< [1..1] isp bist1 done all                                                 */
    __IM  uint32_t bit_jpeg_bist_done_all : 1;/*!< [2..2] jpeg bist done all                                                 */
    __IM  uint32_t bit_mcu_bist_done_all : 1; /*!< [3..3] mcu bist done all                                                  */
    __IM  uint32_t bit_mipi_bist_done_all : 1;/*!< [4..4] mipi bist done all                                                 */
    __IM  uint32_t bit_ispocp_bist_done_all : 1;/*!< [5..5] ispocp bist done all                                             */
    __IM  uint32_t            : 2;
    __IM  uint32_t bit_isp_bist0_ok_all : 1;  /*!< [8..8] isp bist0 ok all                                                   */
    __IM  uint32_t bit_isp_bist1_ok_all : 1;  /*!< [9..9] isp bist1 ok all                                                   */
    __IM  uint32_t bit_jpeg_bist_ok_all : 1;  /*!< [10..10] jpeg bist ok all                                                 */
    __IM  uint32_t bit_mcu_bist_ok_all : 1;   /*!< [11..11] mcu bist ok all                                                  */
    __IM  uint32_t bit_mipi_bist_ok_all : 1;  /*!< [12..12] mipi bist ok all                                                 */
    __IM  uint32_t bit_ispocp_bist_ok_all : 1;/*!< [13..13] ispocp bist ok all                                               */
  } b;
} isp_reg_sys_mem_bist_all_t, *pisp_reg_sys_mem_bist_all_t;

/**
  \brief Union type to access isp_reg_sys_mem_drf_bist_all (@ 0x00000838).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000838) Memory DRF BIST All Register                               */
  
  struct {
    __IM  uint32_t bit_isp_drf0_bist_done_all : 1;/*!< [0..0] isp drf bist0 done all                                         */
    __IM  uint32_t bit_isp_drf1_bist_done_all : 1;/*!< [1..1] isp drf bist1 done all                                         */
    __IM  uint32_t bit_jpeg_drf_bist_done_all : 1;/*!< [2..2] jpeg drf bist done all                                         */
    __IM  uint32_t bit_mcu_drf_bist_done_all : 1;/*!< [3..3] mcu drf bist done all                                           */
    __IM  uint32_t bit_mipi_drf_bist_done_all : 1;/*!< [4..4] mipi drf bist done all                                         */
    __IM  uint32_t bit_ispocp_drf_bist_done_all : 1;/*!< [5..5] ispocp drf bist done all                                     */
    __IM  uint32_t            : 2;
    __IM  uint32_t bit_isp_drf0_bist_ok_all : 1;/*!< [8..8] isp drf bist0 ok all                                             */
    __IM  uint32_t bit_isp_drf1_bist_ok_all : 1;/*!< [9..9] isp drf bist1 ok all                                             */
    __IM  uint32_t bit_jpeg_drf_bist_ok_all : 1;/*!< [10..10] jpeg drf bist ok all                                           */
    __IM  uint32_t bit_mcu_drf_bist_ok_all : 1;/*!< [11..11] mcu drf bist ok all                                             */
    __IM  uint32_t bit_mipi_drf_bist_ok_all : 1;/*!< [12..12] mipi drf bist ok all                                           */
    __IM  uint32_t bit_ispocp_drf_bist_ok_all : 1;/*!< [13..13] ispocp drf bist ok all                                       */
    __IM  uint32_t            : 2;
    __IM  uint32_t bit_isp_drf0_start_pause_all : 1;/*!< [16..16] isp drf0 start pause all                                   */
    __IM  uint32_t bit_isp_drf1_start_pause_all : 1;/*!< [17..17] isp drf1 start pause all                                   */
    __IM  uint32_t bit_jpeg_drf_start_pause_all : 1;/*!< [18..18] jpeg drf start pause all                                   */
    __IM  uint32_t bit_mcu_drf_start_pause_all : 1;/*!< [19..19] mcu drf start pause all                                     */
    __IM  uint32_t bit_mipi_drf_start_pause_all : 1;/*!< [20..20] mipi drf start pause all                                   */
    __IM  uint32_t bit_ispocp_drf_start_pause_all : 1;/*!< [21..21] ispocp drf start pause all                               */
  } b;
} isp_reg_sys_mem_drf_bist_all_t, *pisp_reg_sys_mem_drf_bist_all_t;

/**
  \brief Union type to access isp_reg_sys_isp_mem_bist_done (@ 0x0000083C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000083C) ISP Memory BIST Done Register                              */
  
  struct {
    __IM  uint32_t bit_mlsc_mem_bist_done : 1;/*!< [0..0] mlsc memory bist done                                              */
    __IM  uint32_t bit_awb_mem2_bist_done : 1;/*!< [1..1] awb_rgb memory2 bist done                                          */
    __IM  uint32_t bit_dpc_mem_bist_done : 1; /*!< [2..2] dpc memory bist done                                               */
    __IM  uint32_t bit_intp_mem_bist_done : 1;/*!< [3..3] intp memory bist done                                              */
    __IM  uint32_t bit_iir_mem_bist_done : 1; /*!< [4..4] iir memory bist done                                               */
    __IM  uint32_t bit_hdrs_mem_bist_done : 1;/*!< [5..5] hdrds memory bist done                                             */
    __IM  uint32_t bit_hdr_mem_bist_done : 1; /*!< [6..6] hdr memory bist done                                               */
    __IM  uint32_t bit_eeh_mem_bist_done : 1; /*!< [7..7] eeh memory bist done                                               */
    __IM  uint32_t bit_zoom_mem_bist_done : 1;/*!< [8..8] zoom memory bist done                                              */
    __IM  uint32_t bit_ae_mem_bist_done : 1;  /*!< [9..9] ae memory bist done                                                */
    __IM  uint32_t bit_fft_mem_bist_done : 1; /*!< [10..10] fft memory bist done                                             */
    __IM  uint32_t bit_mtd_mem_bist_done : 1; /*!< [11..11] mtd memory bist done                                             */
    __IM  uint32_t bit_dehaze_curve_b_mem_bist_done : 1;/*!< [12..12] dehaze curve b memory bist done                        */
    __IM  uint32_t bit_dehaze_curve_g_mem_bist_done : 1;/*!< [13..13] dehaze curve g memory bist done                        */
    __IM  uint32_t bit_dehaze_curve_r_mem_bist_done : 1;/*!< [14..14] dehaze curve r memory bist done                        */
    __IM  uint32_t bit_dehaze_histo_mem_bist_done : 1;/*!< [15..15] dehaze histo memory bist done                            */
    __IM  uint32_t bit_dehaze_pre_mem_bist_done : 1;/*!< [16..16] dehaze pre memory bist done                                */
    __IM  uint32_t bit_osd_fhd_mem_bist_done : 1;/*!< [17..17] osd fhd memory bist done                                      */
    __IM  uint32_t bit_osd_hs_mem_bist_done : 1;/*!< [18..18] osd hs memory bist done                                        */
    __IM  uint32_t bit_osd_vga_mem_bist_done : 1;/*!< [19..19] osd vga memory bist done                                      */
    __IM  uint32_t bit_ldc_mem_bist_done : 1; /*!< [20..20] ldc memory bist done                                             */
    __IM  uint32_t bit_mask_mem_bist_done : 1;/*!< [21..21] mask memory bist done                                            */
  } b;
} isp_reg_sys_isp_mem_bist_done_t, *pisp_reg_sys_isp_mem_bist_done_t;

/**
  \brief Union type to access isp_reg_sys_video_mem_bist_done (@ 0x00000840).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000840) Video Memory BIST Done Register                            */
  
  struct {
    __IM  uint32_t bit_jpeg_zigzag_mem_bist_done : 1;/*!< [0..0] jpeg zigzag memory bist done                                */
    __IM  uint32_t bit_jpeg_qnt_mem_bist_done : 1;/*!< [1..1] jpeg qnt memory bist done                                      */
    __IM  uint32_t bit_jpeg_dctr_mem_bist_done : 1;/*!< [2..2] jpeg dctr memory bist done                                    */
    __IM  uint32_t bit_jpeg_prejpeg_mem_bist_done : 1;/*!< [3..3] jpeg prejpeg memory bist done                              */
    __IM  uint32_t bit_huffman_mem_bist_done : 1;/*!< [4..4] huffman memory bist done                                        */
    __IM  uint32_t            : 3;
    __IM  uint32_t bit_mcu_cache_mem_bist_done : 1;/*!< [8..8] mcu cache memory bist done                                    */
    __IM  uint32_t bit_mcu_iram_mem_bist_done : 1;/*!< [9..9] mcu iram memory bist done                                      */
    __IM  uint32_t bit_mcu_xdat_mem_bist_done : 1;/*!< [10..10] mcu xdat memory bist done                                    */
    __IM  uint32_t            : 5;
    __IM  uint32_t bit_mipi_mem_bist_done : 1;/*!< [16..16] mipi memory bist done                                            */
    __IM  uint32_t            : 7;
    __IM  uint32_t bit_ispocp_isp_mem_bist_done : 1;/*!< [24..24] ispocp isp memory bist done                                */
    __IM  uint32_t bit_ispocp_jpg_mem_bist_done : 1;/*!< [25..25] ispocp jpeg memory bist done                               */
  } b;
} isp_reg_sys_video_mem_bist_done_t, *pisp_reg_sys_video_mem_bist_done_t;

/**
  \brief Union type to access isp_reg_sys_isp_mem_bist_ok (@ 0x00000844).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000844) ISP Memory BIST OK Register                                */
  
  struct {
    __IM  uint32_t bit_mlsc_mem_bist_ok : 1;  /*!< [0..0] mlsc memory bist ok                                                */
    __IM  uint32_t bit_awb_mem2_bist_ok : 1;  /*!< [1..1] awb_rgb memory2 bist ok                                            */
    __IM  uint32_t bit_dpc_mem_bist_ok : 1;   /*!< [2..2] dpc memory bist ok                                                 */
    __IM  uint32_t bit_intp_mem_bist_ok : 1;  /*!< [3..3] intp memory bist ok                                                */
    __IM  uint32_t bit_iir_mem_bist_ok : 1;   /*!< [4..4] iir memory bist ok                                                 */
    __IM  uint32_t bit_hdrs_mem_bist_ok : 1;  /*!< [5..5] hdrds memory bist ok                                               */
    __IM  uint32_t bit_hdr_mem_bist_ok : 1;   /*!< [6..6] hdr memory bist ok                                                 */
    __IM  uint32_t bit_eeh_mem_bist_ok : 1;   /*!< [7..7] eeh memory bist ok                                                 */
    __IM  uint32_t bit_zoom_mem_bist_ok : 1;  /*!< [8..8] zoom memory bist ok                                                */
    __IM  uint32_t bit_ae_mem_bist_ok : 1;    /*!< [9..9] ae memory bist ok                                                  */
    __IM  uint32_t bit_fft_mem_bist_ok : 1;   /*!< [10..10] fft memory bist ok                                               */
    __IM  uint32_t bit_mtd_mem_bist_ok : 1;   /*!< [11..11] mtd memory bist ok                                               */
    __IM  uint32_t bit_dehaze_curve_b_mem_bist_ok : 1;/*!< [12..12] dehaze curve b memory bist ok                            */
    __IM  uint32_t bit_dehaze_curve_g_mem_bist_ok : 1;/*!< [13..13] dehaze curve g memory bist ok                            */
    __IM  uint32_t bit_dehaze_curve_r_mem_bist_ok : 1;/*!< [14..14] dehaze curve r memory bist ok                            */
    __IM  uint32_t bit_dehaze_histo_mem_bist_ok : 1;/*!< [15..15] dehaze histo memory bist ok                                */
    __IM  uint32_t bit_dehaze_pre_mem_bist_ok : 1;/*!< [16..16] dehaze pre memory bist ok                                    */
    __IM  uint32_t bit_osd_fhd_mem_bist_ok : 1;/*!< [17..17] osd fhd memory bist ok                                          */
    __IM  uint32_t bit_osd_hs_mem_bist_ok : 1;/*!< [18..18] osd hs memory bist ok                                            */
    __IM  uint32_t bit_osd_vga_mem_bist_ok : 1;/*!< [19..19] osd vga memory bist ok                                          */
    __IM  uint32_t bit_ldc_mem_bist_ok : 1;   /*!< [20..20] ldc memory bist ok                                               */
    __IM  uint32_t bit_mask_mem_bist_ok : 1;  /*!< [21..21] mask memory bist ok                                              */
  } b;
} isp_reg_sys_isp_mem_bist_ok_t, *pisp_reg_sys_isp_mem_bist_ok_t;

/**
  \brief Union type to access isp_reg_sys_video_mem_bist_ok (@ 0x00000848).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000848) Video Memory BIST OK Register                              */
  
  struct {
    __IM  uint32_t bit_jpeg_zigzag_mem_bist_ok : 1;/*!< [0..0] jpeg zigzag memory bist ok                                    */
    __IM  uint32_t bit_jpeg_qnt_mem_bist_ok : 1;/*!< [1..1] jpeg qnt memory bist ok                                          */
    __IM  uint32_t bit_jpeg_dctr_mem_bist_ok : 1;/*!< [2..2] jpeg dctr memory bist ok                                        */
    __IM  uint32_t bit_jpeg_prejpeg_mem_bist_ok : 1;/*!< [3..3] jpeg prejpeg memory bist ok                                  */
    __IM  uint32_t bit_huffman_mem_bist_ok : 1;/*!< [4..4] huffman memory bist ok                                            */
    __IM  uint32_t            : 3;
    __IM  uint32_t bit_mcu_cache_mem_bist_ok : 1;/*!< [8..8] mcu cache memory bist ok                                        */
    __IM  uint32_t bit_mcu_iram_mem_bist_ok : 1;/*!< [9..9] mcu iram memory bist ok                                          */
    __IM  uint32_t bit_mcu_xdat_mem_bist_ok : 1;/*!< [10..10] mcu xdat memory bist ok                                        */
    __IM  uint32_t            : 5;
    __IM  uint32_t bit_mipi_mem_bist_ok : 1;  /*!< [16..16] mipi memory bist ok                                              */
    __IM  uint32_t            : 7;
    __IM  uint32_t bit_ispocp_isp_mem_bist_ok : 1;/*!< [24..24] ispocp isp memory bist ok                                    */
    __IM  uint32_t bit_ispocp_jpg_mem_bist_ok : 1;/*!< [25..25] ispocp jpeg memory bist ok                                   */
  } b;
} isp_reg_sys_video_mem_bist_ok_t, *pisp_reg_sys_video_mem_bist_ok_t;

/**
  \brief Union type to access isp_reg_sys_isp_mem_drf_bist_done (@ 0x0000084C).
*/
typedef union {
  __IOM uint32_t reg_sys_isp_mem_drf_bist_done;                                /*!< (@ 0x0000084C) ISP Memory DRF BIST Done Register                         */
  
  struct {
    __IM  uint32_t bit_mlsc_mem_drf_bist_done : 1;/*!< [0..0] mlsc memory drf bist done                                      */
    __IM  uint32_t bit_awb_mem2_drf_bist_done : 1;/*!< [1..1] awb_rgb memory2 drf bist done                                  */
    __IM  uint32_t bit_dpc_mem_drf_bist_done : 1;/*!< [2..2] dpc memory drf bist done                                        */
    __IM  uint32_t bit_intp_mem_drf_bist_done : 1;/*!< [3..3] intp memory drf bist done                                      */
    __IM  uint32_t bit_iir_mem_drf_bist_done : 1;/*!< [4..4] iir memory drf bist done                                        */
    __IM  uint32_t bit_hdrs_mem_drf_bist_done : 1;/*!< [5..5] hdrds memory drf bist done                                     */
    __IM  uint32_t bit_hdr_mem_drf_bist_done : 1;/*!< [6..6] hdr memory drf bist done                                        */
    __IM  uint32_t bit_eeh_mem_drf_bist_done : 1;/*!< [7..7] eeh memory drf bist done                                        */
    __IM  uint32_t bit_zoom_mem_drf_bist_done : 1;/*!< [8..8] zoom memory drf bist done                                      */
    __IM  uint32_t bit_ae_mem_drf_bist_done : 1;/*!< [9..9] ae memory drf bist done                                          */
    __IM  uint32_t bit_fft_mem_drf_bist_done : 1;/*!< [10..10] fft memory drf bist done                                      */
    __IM  uint32_t bit_mtd_mem_drf_bist_done : 1;/*!< [11..11] mtd memory drf bist done                                      */
    __IM  uint32_t bit_dehaze_curve_b_mem_drf_bist_done : 1;/*!< [12..12] dehaze curve b memory drf bist done                */
    __IM  uint32_t bit_dehaze_curve_g_mem_drf_bist_done : 1;/*!< [13..13] dehaze curve g memory drf bist done                */
    __IM  uint32_t bit_dehaze_curve_r_mem_drf_bist_done : 1;/*!< [14..14] dehaze curve r memory drf bist done                */
    __IM  uint32_t bit_dehaze_histo_mem_drf_bist_done : 1;/*!< [15..15] dehaze histo memory drf bist done                    */
    __IM  uint32_t bit_dehaze_pre_mem_drf_bist_done : 1;/*!< [16..16] dehaze pre memory drf bist done                        */
    __IM  uint32_t bit_osd_fhd_mem_drf_bist_done : 1;/*!< [17..17] osd fhd memory drf bist done                              */
    __IM  uint32_t bit_osd_hs_mem_drf_bist_done : 1;/*!< [18..18] osd hs memory drf bist done                                */
    __IM  uint32_t bit_osd_vga_mem_drf_bist_done : 1;/*!< [19..19] osd vga memory drf bist done                              */
    __IM  uint32_t bit_ldc_mem_drf_bist_done : 1;/*!< [20..20] ldc memory drf bist done                                      */
    __IM  uint32_t bit_mask_mem_drf_bist_done : 1;/*!< [21..21] mask memory drf bist done                                    */
  } b;
} isp_reg_sys_isp_mem_drf_bist_done_t, *pisp_reg_sys_isp_mem_drf_bist_done_t;

/**
  \brief Union type to access isp_reg_sys_video_mem_drf_bist_done (@ 0x00000850).
*/
typedef union {
  __IOM uint32_t reg_sys_video_mem_drf_bist_done;                                  /*!< (@ 0x00000850) Video Memory BIST Done Register                         */
  
  struct {
    __IM  uint32_t bit_jpeg_zigzag_mem_drf_bist_done : 1;/*!< [0..0] jpeg zigzag memory drf bist done                        */
    __IM  uint32_t bit_jpeg_qnt_mem_drf_bist_done : 1;/*!< [1..1] jpeg zigzag memory drf bist done                           */
    __IM  uint32_t bit_jpeg_dctr_mem_drf_bist_done : 1;/*!< [2..2] jpeg qnt memory drf bist done                             */
    __IM  uint32_t bit_jpeg_prejpeg_mem_drf_bist_done : 1;/*!< [3..3] jpeg dctr memory drf bist done                         */
    __IM  uint32_t bit_huffman_mem_drf_bist_done : 1;/*!< [4..4] jpeg prejpeg memory drf bist done                           */
    __IM  uint32_t            : 3;
    __IM  uint32_t bit_mcu_cache_mem_drf_bist_done : 1;/*!< [8..8] mcu cache memory drf bist done                            */
    __IM  uint32_t bit_mcu_iram_mem_drf_bist_done : 1;/*!< [9..9] mcu iram memory drf bist done                              */
    __IM  uint32_t bit_mcu_xdat_mem_drf_bist_done : 1;/*!< [10..10] mcu xdat memory drf bist done                            */
    __IM  uint32_t            : 5;
    __IM  uint32_t bit_mipi_mem_drf_bist_done : 1;/*!< [16..16] mipi memory drf bist done                                    */
    __IM  uint32_t            : 7;
    __IM  uint32_t bit_ispocp_isp_mem_drf_bist_done : 1;/*!< [24..24] ispocp isp memory drf bist done                        */
    __IM  uint32_t bit_ispocp_jpg_mem_drf_bist_done : 1;/*!< [25..25] ispocp jpeg memory drf bist done                       */
  } b;
} isp_reg_sys_video_mem_drf_bist_done_t, *pisp_reg_sys_video_mem_drf_bist_done_t;

/**
  \brief Union type to access isp_reg_sys_isp_mem_drf_bist_ok (@ 0x00000854).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000854) ISP Memory DRF BIST OK Register                            */
  
  struct {
    __IM  uint32_t bit_mlsc_mem_drf_bist_ok : 1;/*!< [0..0] mlsc memory drf bist ok                                          */
    __IM  uint32_t bit_awb_mem2_drf_bist_ok : 1;/*!< [1..1] awb_rgb memory2 drf bist ok                                      */
    __IM  uint32_t bit_dpc_mem_drf_bist_ok : 1;/*!< [2..2] dpc memory drf bist ok                                            */
    __IM  uint32_t bit_intp_mem_drf_bist_ok : 1;/*!< [3..3] intp memory drf bist ok                                          */
    __IM  uint32_t bit_iir_mem_drf_bist_ok : 1;/*!< [4..4] iir memory drf bist ok                                            */
    __IM  uint32_t bit_hdrs_mem_drf_bist_ok : 1;/*!< [5..5] hdrds memory drf bist ok                                         */
    __IM  uint32_t bit_hdr_mem_drf_bist_ok : 1;/*!< [6..6] hdr memory drf bist ok                                            */
    __IM  uint32_t bit_eeh_mem_drf_bist_ok : 1;/*!< [7..7] eeh memory drf bist ok                                            */
    __IM  uint32_t bit_zoom_mem_drf_bist_ok : 1;/*!< [8..8] zoom memory drf bist ok                                          */
    __IM  uint32_t bit_ae_mem_drf_bist_ok : 1;/*!< [9..9] ae memory drf bist ok                                              */
    __IM  uint32_t bit_fft_mem_drf_bist_ok : 1;/*!< [10..10] fft memory drf bist ok                                          */
    __IM  uint32_t bit_mtd_mem_drf_bist_ok : 1;/*!< [11..11] mtd memory drf bist ok                                          */
    __IM  uint32_t bit_dehaze_curve_b_mem_drf_bist_ok : 1;/*!< [12..12] dehaze curve b memory drf bist ok                    */
    __IM  uint32_t bit_dehaze_curve_g_mem_drf_bist_ok : 1;/*!< [13..13] dehaze curve g memory drf bist ok                    */
    __IM  uint32_t bit_dehaze_curve_r_mem_drf_bist_ok : 1;/*!< [14..14] dehaze curve r memory drf bist ok                    */
    __IM  uint32_t bit_dehaze_histo_mem_drf_bist_ok : 1;/*!< [15..15] dehaze histo memory drf bist ok                        */
    __IM  uint32_t bit_dehaze_pre_mem_drf_bist_ok : 1;/*!< [16..16] dehaze pre memory drf bist ok                            */
    __IM  uint32_t bit_osd_fhd_mem_drf_bist_ok : 1;/*!< [17..17] osd fhd memory drf bist ok                                  */
    __IM  uint32_t bit_osd_hs_mem_drf_bist_ok : 1;/*!< [18..18] osd hs memory drf bist ok                                    */
    __IM  uint32_t bit_osd_vga_mem_drf_bist_ok : 1;/*!< [19..19] osd vga memory drf bist ok                                  */
    __IM  uint32_t bit_ldc_mem_drf_bist_ok : 1;/*!< [20..20] ldc memory drf bist ok                                          */
    __IM  uint32_t bit_mask_mem_drf_bist_ok : 1;/*!< [21..21] mask memory drf bist ok                                        */
  } b;
} isp_reg_sys_isp_mem_drf_bist_ok_t, *pisp_reg_sys_isp_mem_drf_bist_ok_t;

/**
  \brief Union type to access isp_reg_sys_video_mem_drf_bist_ok (@ 0x00000858).
*/
typedef union {
  __IOM uint32_t reg_sys_video_mem_drf_bist_ok;                                /*!< (@ 0x00000858) Video Memory BIST OK Register                             */
  
  struct {
    __IM  uint32_t bit_jpeg_zigzag_mem_drf_bist_ok : 1;/*!< [0..0] jpeg zigzag memory drf bist done                          */
    __IM  uint32_t bit_jpeg_qnt_mem_drf_bist_ok : 1;/*!< [1..1] jpeg zigzag memory drf bist ok                               */
    __IM  uint32_t bit_jpeg_dctr_mem_drf_bist_ok : 1;/*!< [2..2] jpeg qnt memory drf bist ok                                 */
    __IM  uint32_t bit_jpeg_prejpeg_mem_drf_bist_ok : 1;/*!< [3..3] jpeg dctr memory drf bist ok                             */
    __IM  uint32_t bit_huffman_mem_drf_bist_ok : 1;/*!< [4..4] jpeg prejpeg memory drf bist ok                               */
    __IM  uint32_t            : 3;
    __IM  uint32_t bit_mcu_cache_mem_drf_bist_ok : 1;/*!< [8..8] mcu cache memory drf bist ok                                */
    __IM  uint32_t bit_mcu_iram_mem_drf_bist_ok : 1;/*!< [9..9] mcu iram memory drf bist ok                                  */
    __IM  uint32_t bit_mcu_xdat_mem_drf_bist_ok : 1;/*!< [10..10] mcu xdat memory drf bist ok                                */
    __IM  uint32_t            : 5;
    __IM  uint32_t bit_mipi_mem_drf_bist_ok : 1;/*!< [16..16] mipi memory drf bist ok                                        */
    __IM  uint32_t            : 7;
    __IM  uint32_t bit_ispocp_isp_mem_drf_bist_ok : 1;/*!< [24..24] ispocp isp memory drf bist ok                            */
    __IM  uint32_t bit_ispocp_jpg_mem_drf_bist_ok : 1;/*!< [25..25] ispocp jpeg memory drf bist ok                           */
  } b;
} isp_reg_sys_video_mem_drf_bist_ok_t, *pisp_reg_sys_video_mem_drf_bist_ok_t;

/**
  \brief Union type to access isp_reg_sys_isp_mem_drf_start_pause (@ 0x0000085C).
*/
typedef union {
  __IOM uint32_t reg_sys_isp_mem_drf_start_pause;                                  /*!< (@ 0x0000085C) ISP Memory DRF Start Pause Register                     */
  
  struct {
    __IM  uint32_t bit_mlsc_mem_drf_start_pause : 1;/*!< [0..0] mlsc memory drf start pause                                  */
    __IM  uint32_t bit_awb_mem2_drf_start_pause : 1;/*!< [1..1] awb_rgb memory2 drf start pause                              */
    __IM  uint32_t bit_dpc_mem_drf_start_pause : 1;/*!< [2..2] dpc memory drf start pause                                    */
    __IM  uint32_t bit_intp_mem_drf_start_pause : 1;/*!< [3..3] intp memory drf start pause                                  */
    __IM  uint32_t bit_iir_mem_drf_start_pause : 1;/*!< [4..4] iir memory drf start pause                                    */
    __IM  uint32_t bit_hdrs_mem_drf_start_pause : 1;/*!< [5..5] hdrds memory drf start pause                                 */
    __IM  uint32_t bit_hdr_mem_drf_start_pause : 1;/*!< [6..6] hdr memory drf start pause                                    */
    __IM  uint32_t bit_eeh_mem_drf_start_pause : 1;/*!< [7..7] eeh memory drf start pause                                    */
    __IM  uint32_t bit_zoom_mem_drf_start_pause : 1;/*!< [8..8] zoom memory drf start pause                                  */
    __IM  uint32_t bit_ae_mem_drf_start_pause : 1;/*!< [9..9] ae memory drf start pause                                      */
    __IM  uint32_t bit_fft_mem_drf_start_pause : 1;/*!< [10..10] fft memory drf start pause                                  */
    __IM  uint32_t bit_mtd_mem_drf_start_pause : 1;/*!< [11..11] mtd memory drf start pause                                  */
    __IM  uint32_t bit_dehaze_curve_b_mem_drf_start_pause : 1;/*!< [12..12] dehaze curve b memory drf start pause            */
    __IM  uint32_t bit_dehaze_curve_g_mem_drf_start_pause : 1;/*!< [13..13] dehaze curve g memory drf start pause            */
    __IM  uint32_t bit_dehaze_curve_r_mem_drf_start_pause : 1;/*!< [14..14] dehaze curve r memory drf start pause            */
    __IM  uint32_t bit_dehaze_histo_mem_drf_start_pause : 1;/*!< [15..15] dehaze histo memory drf start pause                */
    __IM  uint32_t bit_dehaze_pre_mem_drf_start_pause : 1;/*!< [16..16] dehaze pre memory drf start pause                    */
    __IM  uint32_t bit_osd_fhd_mem_drf_start_pause : 1;/*!< [17..17] osd fhd memory drf start pause                          */
    __IM  uint32_t bit_osd_hs_mem_drf_start_pause : 1;/*!< [18..18] osd hs memory drf start pause                            */
    __IM  uint32_t bit_osd_vga_mem_drf_start_pause : 1;/*!< [19..19] osd vga memory drf start pause                          */
    __IM  uint32_t bit_ldc_mem_drf_start_pause : 1;/*!< [20..20] ldc memory drf start pause                                  */
    __IM  uint32_t bit_mask_mem_drf_start_pause : 1;/*!< [21..21] mask memory drf start pause                                */
  } b;
} isp_reg_sys_isp_mem_drf_start_pause_t, *pisp_reg_sys_isp_mem_drf_start_pause_t;

/**
  \brief Union type to access isp_reg_sys_video_mem_drf_start_pause (@ 0x00000860).
*/
typedef union {
  __IOM uint32_t reg_sys_video_mem_drf_start_pause;                                    /*!< (@ 0x00000860) Video Memory DRF Start Pause Register                 */
  
  struct {
    __IM  uint32_t bit_jpeg_zigzag_mem_drf_start_pause : 1;/*!< [0..0] jpeg zigzag memory drf bist done                      */
    __IM  uint32_t bit_jpeg_qnt_mem_drf_start_pause : 1;/*!< [1..1] jpeg zigzag memory drf start pause                       */
    __IM  uint32_t bit_jpeg_dctr_mem_drf_start_pause : 1;/*!< [2..2] jpeg qnt memory drf start pause                         */
    __IM  uint32_t bit_jpeg_prejpeg_mem_drf_start_pause : 1;/*!< [3..3] jpeg dctr memory drf start pause                     */
    __IM  uint32_t bit_huffman_mem_drf_start_pause : 1;/*!< [4..4] jpeg prejpeg memory drf start pause                       */
    __IM  uint32_t            : 3;
    __IM  uint32_t bit_mcu_cache_mem_drf_start_pause : 1;/*!< [8..8] mcu cache memory drf start pause                        */
    __IM  uint32_t bit_mcu_iram_mem_drf_start_pause : 1;/*!< [9..9] mcu iram memory drf start pause                          */
    __IM  uint32_t bit_mcu_xdat_mem_drf_start_pause : 1;/*!< [10..10] mcu xdat memory drf start pause                        */
    __IM  uint32_t            : 5;
    __IM  uint32_t bit_mipi_mem_drf_start_pause : 1;/*!< [16..16] mipi memory drf start pause                                */
    __IM  uint32_t            : 7;
    __IM  uint32_t bit_ispocp_isp_mem_drf_start_pause : 1;/*!< [24..24] ispocp isp memory drf start pause                    */
    __IM  uint32_t bit_ispocp_jpg_mem_drf_start_pause : 1;/*!< [25..25] ispocp jpeg memory drf start pause                   */
  } b;
} isp_reg_sys_video_mem_drf_start_pause_t, *pisp_reg_sys_video_mem_drf_start_pause_t;

//=============================================================//
////////////////SENSOR REG///////////////////////////
//=============================================================//
#define SYS_BASE_RF     (0x403F0000)

#define SSOR_CFG_0         (SYS_BASE_RF + 0x8800)
#define SSOR_CFG_1         (SYS_BASE_RF + 0x8804)
#define SSOR_GEN_DAT       (SYS_BASE_RF + 0x8808)
#define SSOR_START         (SYS_BASE_RF + 0x880C)

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripheralAddr
  * @{
  */

#define ISP_REG_BASE                0x40300000UL

/** @} */ /* End of group Device_Peripheral_peripheralAddr */


/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_declaration
  * @{
  */

#define ISP_REG                     ((ISP_REG_Type*)           ISP_REG_BASE)

/** @} */ /* End of group Device_Peripheral_declaration */

#define HAL_ISP_READ32(addr)            (*((volatile u32*)addr))
#define HAL_ISP_WRITE32(addr, value)    ((*((volatile u32*)addr)) = value)


/** @} */ /* End of group hs_hal_isp_reg */
/// @endcond /* End of condition DOXYGEN_ISP_REG_TYPE */

#ifdef  __cplusplus
}
#endif

#endif    // end of #ifndef _RTL8195B_HP_ISP_REG_TYPE_H_


