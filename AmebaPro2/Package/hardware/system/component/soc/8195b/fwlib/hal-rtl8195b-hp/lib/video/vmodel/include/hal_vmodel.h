 /**************************************************************************//**
  * @file     hal_vmodel.h
  * @brief    The SW model to outout h.264 stream
  *           Includes Registers and data type definition.
  * @version  V1.00
  * @date     2017-06-12
  *
  * @note
  *
  ******************************************************************************
  *
  * Copyright(c) 2007 - 2016 Realtek Corporation. All rights reserved.
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
 
#ifndef _HAL_VMODEL_H_
#define _HAL_VMODEL_H_

#ifdef  __cplusplus
extern "C"
{
#endif


#include "cmsis.h"

//#define __PXP_RUN__

#ifdef __PXP_RUN__

#ifdef _PRINT_OFF
    #define DBG_ENC_INFO (...)
    #define DBG_ENC_WARN (...)
    #define DBG_ENC_ERR (...)
#else
    #define DBG_ENC_INFO rtl_printf
    #define DBG_ENC_WARN rtl_printf
    #define DBG_ENC_ERR rtl_printf
#endif

#endif

#define ENC_OUT_ADDR 0x70000000    // should be same as the target address of gdb restoring 
#define FRAME_NUM 30	// Fixed, can't be modified

typedef void (*vmodel_callback_t) (void *);


/**
  \brief  The data structure to handle the video SW model, includes the configuration, register base address
          and interrupt call back functions.
*/
typedef struct hal_vmodel_adapter_s {

	hal_timer_adapter_t isp_timer_adt;
	hal_timer_adapter_t enc_timer_adt;
	u8 isp_done_fr_cnt; /*! 1-based. this count updated when isp interrupt asserted */
	u8 enc_done_fr_cnt; /*! 1-based. this count updated when encoder interrupt asserted */
	bool isp_run;
	u8 rsvd0;
	vmodel_callback_t isp_fr_done_cb;      /*! callback function for isp frame done */
    void *isp_fr_done_cb_arg;   /*! the argument for isp frame done callback function */
	vmodel_callback_t enc_done_cb;      /*! callback function for encoder done */
    void *enc_done_cb_arg;   /*! the argument for encoder done callback function */

} hal_vmodel_adapter_t, *phal_vmodel_adapter_t;


hal_status_t hal_vmodel_init_rtl8195bhp(hal_vmodel_adapter_t *pvmodel_adpt);
void hal_vmodel_isp_start_rtl8195bhp(hal_vmodel_adapter_t *pvmodel_adpt, vmodel_callback_t isp_fr_done_cb, void *arg);
void hal_vmodel_start_enc_rtl8195bhp(hal_vmodel_adapter_t *pvmodel_adpt, vmodel_callback_t enc_done_cb, void *arg);
void hal_vmodel_read_enc_result_rtl8195bhp(u32 *enc_size, u32 *enc_addr);
void hal_vmodel_get_enc_header_rtl8195bhp(u32 *head_size, u32 *head_addr);
void hal_vmodel_get_enc_end_rtl8195bhp(hal_vmodel_adapter_t *pvmodel_adpt, u32 *end_size, u32 *end_addr);

#ifdef  __cplusplus
}
#endif

#endif  // end of "#define _HAL_VMODEL_H_"

