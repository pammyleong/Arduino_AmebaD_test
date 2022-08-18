/**************************************************************************//**
 * @file      hal_video.h
 * @brief
 * @version   V1.00
 * @date      2018-8-8 10:19:19
 *
 * @note
 *
 ******************************************************************************
 *
 * Copyright(c) 2007 - 2018 Realtek Corporation. All rights reserved.
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

#ifndef _HAL_VIDEO_H_
#define _HAL_VIDEO_H_

#ifdef  __cplusplus
extern "C"
{
#endif

void hal_video_sys_init(void);
void hal_video_sys_deinit(void);
void hal_video_sys_sharemem_en(void);

#ifdef  __cplusplus
}
#endif

#endif    // end of #ifndef _HAL_VIDEO_H_

