/**************************************************************************//**
 * @file     hal_voe.h
 * @brief    The HAL API implementation for the VOE module
 * @version  V1.00
 * @date     2017-10-26
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

#ifndef HAL_VOE_H
#define HAL_VOE_H

#include "cmsis.h"

#ifdef __cplusplus
extern "C" {
#endif

#define VOE_ADDR_BASE 0x40490000


// define VOE Send buffer type
#define ISP_TYPE			0	// ISP type
#define H264_TYPE			1	// H264 type
#define JPEG_TYPE			2	// H264 type

// define VOE mode status
#define VOE_MODE_DIS		0	// VOE disable
#define VOE_MODE_REG_W		1	// VOE ERAC register write
#define VOE_MODE_FULL		2	// VOE free run

/** 
 * @addtogroup hs_hal_voe VOE
 * @{
 * @brief The VOE HAL APIs.
 */


typedef void (*voe_callback_t) (void *);

/*
  \brief  The data structure to handle the voe module, includes the configuration, register base address and interrupt call back functions.
*/
typedef struct hal_voe_adapter_s {

    u32 fw_bin_addr;                /*! voe fw binary image address */
    u32 itcm_image_len;             /*! voe km fw itcm image size */
    u32 dtcm_image_len;             /*! voe km fw dtcm image size */
    voe_callback_t km_message_cb;   /*! callback function for km message */
    void *km_message_cb_para;        /*! the argument for km message callback function */

    voe_callback_t lb_overflow_cb;  /*! callback function for line buffer overflow */
    void *lb_overflow_cb_para;       /*! the argument for line buffer overflow */

    voe_callback_t erac_finish_cb;  /*! callback function for line buffer overflow */
    void *erac_finish_cb_para;      /*! the argument for line buffer overflow */

    u32 voe_send_message;
	u32 voe_cmd;

	u32 voe_enc_status[2];
} hal_voe_adapter_t, *phal_voe_adapter_t;


//hal_status_t hal_voe_erac_wr(u32 data_addr, u32 offset, u16 wr_num, voe_callback_t wait_cmd_sent_cb, void *cb_para);
hal_status_t hal_voe_erac_wr(u32 data_addr, u32 offset, u16 wr_num, voe_callback_t callback, void *arg);

void hal_voe_receive_message(hal_voe_adapter_t *pvoe_adpt);

bool hal_voe_get_receive_message_status(void);

void hal_voe_clean_receive_message_status(void);

hal_status_t hal_voe_start(hal_voe_adapter_t *pvoe_adpt, voe_callback_t receive_cmd_cb, void *cb_para);

hal_status_t hal_voe_erac_init(hal_voe_adapter_t *pvoe_adpt, voe_callback_t wait_cmd_sent_cb, void *cb_para);



// Added By Raymond new commmand  20180928
hal_status_t hal_voe_h264_idr(u32 addr, u16 idr_size, u32 voe_channel);
hal_status_t hal_voe_h264_start(u32 inst_addr, u32 stream_id, u32 type);
hal_status_t hal_voe_h264_stop(u16 stream_id);
hal_status_t hal_voe_buf_send(u32 addr, u32 stream_id, u32 buffer, u32 type);
hal_status_t hal_voe_h264_release(u16 stream_id,u32 slot_id);
hal_status_t hal_voe_h264_ready(u32 *channel, u32 *slot, u32 *addr, u32 *size, u32 *type);
hal_status_t hal_voe_h264_schedule(u32 sequence_cnt, u32 *sequence_table);


hal_status_t hal_voe_h264_isr_config(bool enable, voe_callback_t wait_cmd_sent_cb, void *cb_para);

u32 hal_voe_h264_swreg_addr(u32 channel);
u32 hal_voe_jpeg_swreg_addr(void);

u16 hal_voe_parse_cmd(u32 voe_message);

bool hal_voe_check_receive_H264_isr(u16 tm_receive_cmd);

bool hal_voe_check_erac_write_cmd(void);


void hal_voe_set_lb_overflow_int(hal_voe_adapter_t *pvoe_adpt, voe_callback_t callback, void *arg, u8 int_en);
//void hal_voe_send_message_to_km(u32 cmd, u32 payload, hal_voe_adapter_t *pvoe_adpt);
void hal_voe_deinit(void);


// Raymond Added
hal_status_t hal_voe_cmd_cb(voe_callback_t receive_cmd_cb, void *cb_para);
u16 hal_voe_cmd(void);
u16 hal_voe_cmd_data(void);	// Added By Raymond



/** @} */ /* End of group hs_hal_voe */

#ifdef __cplusplus
}
#endif

#endif /* RTL8195BHP_LCDC_H */

