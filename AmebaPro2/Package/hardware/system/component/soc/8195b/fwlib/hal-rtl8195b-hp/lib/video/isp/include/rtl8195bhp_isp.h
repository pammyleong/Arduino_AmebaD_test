/**************************************************************************//**
 * @file      rtl8195bhp_isp.h
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

#ifndef _RTL8195BHP_ISP_H_
#define _RTL8195BHP_ISP_H_

#ifdef __cplusplus
extern "C"{
#endif


/** 
 * @addtogroup hs_hal_isp ISP
 * @{
 * @brief The ISP HAL APIs.
 */

#define ISP_MTD_NUM			5

#define LANE_SEL    0xE4      ///lane_sel : 11_10_01_00
#define LANE_EN     0x3       ///lane_en: 4'b0011, lane0,1


#define ISP_CMD_DATA_REG_NUM		8
#define ISP_CMD_DIRECTION_MASK		0x80

#define ISP_CMD_STATUS_STATUS_BIT	31
#define ISP_CMD_STATUS_RESULT_BIT	30
#define ISP_CMD_STATUS_ERROR_BIT		16
#define ISP_CMD_STATUS_ERROR_MASK	0xff0000

enum isp_force_reset_model {
    force_reset_jpg,
    force_reset_mipi,
    force_reset_mcu,
    force_reset_isp,
    force_mcu_prepare,
    force_mcu_done,
};

enum isp_cmd_data_dir {
    host_to_device = 0,
    device_to_host = 1
};

enum mcu_interrupt_id {
    mcu_cmd_done = 0,
    mcu_cache_miss_fail = 1,
    mcu_watchdog_reset = 2,
    mcu_mtd0_motion = 16,
    mcu_mtd1_motion = 17,
    mcu_mtd2_motion = 18,
    mcu_mtd3_motion = 19,
    mcu_mtd4_motion = 20,
    mcu_interrupt = 21,
};

enum isp_interrupt_id {
    isp_yuv_s0_uv_buf_overflow = 0,
    isp_yuv_s0_y_buf_overflow,
    isp_yuv_s0_ddr_frame_buf_overflow,
    isp_yuv_s0_ddr_frame_finish,
    isp_yuv_s1_uv_buf_overflow,
    isp_yuv_s1_y_buf_overflow,
    isp_yuv_s1_ddr_frame_buf_overflow,
    isp_yuv_s1_ddr_frame_finish,
    isp_yuv_s2_uv_buf_overflow,
    isp_yuv_s2_y_buf_overflow,
    isp_yuv_s2_ddr_frame_buf_overflow,
    isp_yuv_s2_ddr_frame_finish
};

void hal_isp_en_mcu_interrupt_rtl8195bh(BOOL en, int id);
void hal_isp_en_isp_interrupt_rtl8195bh(BOOL en, int id);
u32 hal_isp_get_isp_interrupt_flag_rtl8195bhp(void);
void hal_isp_clear_isp_interrupt_flag_rtl8195bhp(u32 mask);
u32 hal_isp_get_mcu_interrupt_flag_rtl8195bhp(void);
void hal_isp_clear_mcu_interrupt_flag_rtl8195bhp(u32 mask);

void hal_isp_videosys_isp_control_rtl8195bhp(BOOL en, u32 interface);
void hal_isp_videosys_isp_pll_cfg_rtl8195bhp(BOOL en);
void hal_isp_videosys_isp_pll_en_rtl8195bhp(BOOL en);
void hal_isp_videosys_isp_sensor_hclk_cfg_rtl8195bhp(BOOL en, u32 isp_snr_freq);
void hal_isp_videosys_isp_sensor_hclk_en_rtl8195bhp(BOOL en);
u32 hal_isp_videosys_check_isp_pll_ready_rtl8195bhp(void);
u32 hal_isp_videosys_check_isp_sensor_pll_ready_rtl8195bhp(void);
void hal_isp_en_mcu_clk_rtl8195bhp(BOOL en);

u32 hal_isp_get_mcu_start_addr_rtl8195bhp(void);
void hal_isp_set_mcu_start_addr_rtl8195bhp(u32 mcu_addr);
void hal_isp_force_reset_rtl8195bhp(u32 model);
void hal_isp_set_cpu_lock_mcu_rtl8195bhp(u32 selector);
u32 hal_isp_get_cpu_lock_mcu_rtl8195bhp(u32 selector);
#if 1
//#ifndef __PXP_RUN__
hal_status_t hal_isp_pin_ctrl_rtl8195bhp(uint8_t isp_idx, BOOL en);
hal_status_t hal_isp_interface_ctrl_rtl8195bhp(u32 interface, BOOL en);
#else
hal_status_t hal_isp_pin_ctrl_rtl8195bhp(BOOL en);
#endif

int hal_isp_config_isp_header_rtl8195bh(u32 isp_header_addr);
int hal_isp_config_isp_buffer_rtl8195bh(u8 streamid);
u8 hal_isp_get_hw_slow_num_rtl8195bh(u8 streamid);
int hal_isp_config_hw_slot_num_rtl8195bh(u8 streamid, u8 slot_num);
void hal_isp_config_yuv_addr_rtl8195bh(u8 streamid, u8 slot_id, u32 y_addr, u32 uv_addr);
void hal_isp_release_slot_rtl8195bh(u8 streamid, u8 slot_id);
u32 hal_isp_get_yuv_frame_buf_status_rtl8195bh(u8 streamid);
void hal_isp_control_rtl8195bh(u8 streamid, BOOL en);
void hal_isp_reset_stream_rtl8195bh(u8 streamid);

#ifdef __PXP_RUN__
//void hal_isp_snr_cfg_rtl8195bh(u32 width, u32 height, u32 snr_format);
void hal_isp_snr_cfg_rtl8195bh(u16 sensor_w, u16 sensor_h, u16 raw_num, u16 run_frame, u32 snr_format);
void hal_isp_snr_start_rtl8195bh(void);
#endif

u32 hal_isp_get_yuv_cur_frame_index_offset_rtl8195bh(u8 streamid);

void hal_isp_set_cmd1_rtl8195bhp(u32 cmd1);
void hal_isp_set_cmd0_rtl8195bhp(u32 cmd0);
void hal_isp_set_data_host2mcu_rtl8195bhp(u32 offset, u32 value);
u32 hal_isp_get_data_mcu2host_rtl8195bhp(u32 offset);
u8 hal_isp_get_cmd_data_direction_rtl8195bhp(u16 cmdcode);
u32 hal_isp_get_mcu_cmd_status_rtl8195bh(void);
int hal_isp_check_mcu_cmd_status_rtl8195bh(u32 status);
int hal_isp_check_mcu_cmd_result_rtl8195bh(u32 status);
u32 hal_isp_get_mcu_cmd_error_rtl8195bh(u32 status);
u32 hal_isp_check_reset_stream_rtl8195bh(u8 streamid);
u32 hal_isp_check_reset_stream_all_rtl8195bh(void);
void hal_isp_config_slice_signal_rtl8195bh(u8 streamid, u8 slice_line_type, bool enable);
void hal_isp_config_frdn_signal_rtl8195bh(bool enable);



/** @} */ /* End of group hs_hal_isp */

#ifdef  __cplusplus
}
#endif

#endif    // end of #ifndef _RTL8195BHP_ISP_H_


