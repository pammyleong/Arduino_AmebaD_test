/**************************************************************************//**
 * @file      rtl8195bhp_encorder.h
 * @brief
 * @version   V1.00
 * @date      2017-11-11 11:11:0
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

#ifndef _RTL8195BHP_ENCORDER_H_
#define _RTL8195BHP_ENCORDER_H_

#ifdef  __cplusplus
extern "C"
{
#endif





/** 
 * @addtogroup hs_hal_enc ENC
 * @{
 * @brief The ENCORDER HAL APIs.
 */

void hal_enc_pll_en_rtl8195bhp(void);
void hal_enc_control_config_rtl8195bhp(void);
void hal_enc_regulator_config_rtl8195bhp(void);
void hal_enc_sharemem_setup_rtl8195bhp(void);
void hal_enc_sharemem_deinit_rtl8195bhp(void);
void hal_enc_control_off_rtl8195bhp(void);
void hal_enc_pll_off_rtl8195bhp(void);



/** @} */ /* End of group hs_hal_lcdc */

#ifdef  __cplusplus
}
#endif

#endif    // end of #ifndef _RTL8195BHP_ENCORDER_H_

