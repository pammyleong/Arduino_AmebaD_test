/**************************************************************************//**
 * @file      rtl8195bhp_video.h
 * @brief
 * @version   V1.00
 * @date      2017-5-3 10:19:19
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

#ifndef _RTL8195BHP_VIDEO_H_
#define _RTL8195BHP_VIDEO_H_

#ifdef  __cplusplus
extern "C"
{
#endif

#include "rtl8195bhp_video_sys_type.h"


/** 
 *  @brief To enable or disable the video domain small power cut.
 *
 *  @param en  Enable control: 0: disable, 1: enable.
 *
 *  @returns void
 */
__STATIC_INLINE
void hal_videosys_en_video_smallpwr_rtl8195bhp (BOOL en)
{
    VIDEO_SYS->reg_sys_pwr_ctrl_b.bit_video_spc_en = en;
}

/** 
 *  @brief To enable or disable the video domain large power cut.
 *
 *  @param en  Enable control: 0: disable, 1: enable.
 *
 *  @returns void
 */
__STATIC_INLINE
void hal_videosys_en_video_largepwr_rtl8195bhp (BOOL en)
{
    VIDEO_SYS->reg_sys_pwr_ctrl_b.bit_video_lpc_en = en;
}

/** 
 *  @brief To enable video domain.
 *
 *  @param en  Enable control: 0: disable, 1: enable.
 *
 *  @returns void
 */
__STATIC_INLINE
void hal_videosys_en_video_domain_rtl8195bhp(BOOL en)
{
    VIDEO_SYS->reg_sys_func_en_b.bit_hs_video_en = en;
}


/** 
 *  @brief To check video domain enable or not.
 *
 *  @param void.
 *
 *  @returns 0: video domain disable, 1: video domain enable
 */
__STATIC_INLINE
bool hal_videosys_check_video_domain_rtl8195bhp(void)
{
    return VIDEO_SYS->reg_sys_func_en_b.bit_hs_video_en;
}


/** 
 *  @brief To return video power cut status.
 *
 *  @param void.
 *
 *  @returns the read value of sys_pwr_ctrl
 */
__STATIC_INLINE
u32 hal_videosys_video_power_status_rtl8195bhp (void)
{
    return (u32)VIDEO_SYS->reg_sys_pwr_ctrl;
}

/** 
 *  @brief To return the enable status of all video group IP.
 *
 *  @param void.
 *
 *  @returns the read value of sys_pwr_ctrl
 */
__STATIC_INLINE
u32 hal_videosys_video_en_status_rtl8195bhp (void)
{
    return (u32)VIDEO_SYS->reg_hs_isp_ctrl;
}

/** 
 *  @brief To enable video isolation.
 *
 *  @param en  Enable control: 0: disable, 1: enable.
 *
 *  @returns void
 */
__STATIC_INLINE
void hal_videosys_en_video_iso_rtl8195bhp(BOOL en)
{
    VIDEO_SYS->reg_sys_iso_ctrl_b.bit_sys_iso_vdo = en;
}

void hal_video_sys_init_rtl8195bhp(void);
void hal_video_sys_deinit_rtl8195bhp(void);
void hal_video_sys_sharemem_en_rtl8195bhp(void);



#ifdef  __cplusplus
}
#endif

#endif    // end of #ifndef _RTL8195BHP_VIDEO_H_

