 /**************************************************************************//**
  * @file     rtl8195bhp_voe.h
  * @brief    The HAL related definition and macros for the VOE module.
  *           Includes Registers and data type definition.
  * @version  V1.00
  * @date     2017-10-24
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
 
#ifndef _RTL8195BHP_VOE_H_
#define _RTL8195BHP_VOE_H_

#ifdef  __cplusplus
extern "C"
{
#endif

#include "rtl8195bhp_voe_type.h"
#include "hal_api.h"
#include "hal_timer.h"

/** 
 * @addtogroup hs_hal_voe VOE
 * @{
 * @brief The VOE HAL APIs.
 */



#if 0 
#ifdef __PXP_RUN__

#ifdef _PRINT_OFF
    #define DBG_VOE_INFO(...)
    #define DBG_VOE_WARN(...)
    #define DBG_VOE_ERR(...)
#else
    #define DBG_VOE_INFO rtl_printf
    #define DBG_VOE_WARN rtl_printf
    #define DBG_VOE_ERR rtl_printf
#endif

#endif
#endif 

#define VOE_SHARE_MEMORY        		0x40490000

#define TM2KM_CMD_BASE          		0x40490000	// TM --> KM Command value base
#define KM2TM_CMD_BASE           		0x40490010	// KM --> TM Command value base


#define VOE_RESERVED_TABLE_START        0x40490100	// Reserved:
#define VOE_RESERVED_TABLE_END          0x404905E0

#define ENC2VOE_CMD						0x40490000	// ENC2VOE CMD address base 0x0 0x4 0x8 0xc
#define ENC2VOE_IDR_ADDR	           	0x40490010	// IDR header address
#define ENC_SW_REG_FOR_VOE1             0x40490600	// Encoder1: length: 0x500
#define ENC_SW_REG_FOR_VOE2             0x40490B00	// Encoder2: length: 0x500
#define JPG_SW_REG_FOR_VOE              0x40491000	// JPEG    : length: 0x500
#define JPG_SW_REG_FOR_VOE_END          0x404914E4


#define VOE_STATUS_OK       0x0
#define ROM_INIT_ERR        0x1
#define ITCM_INIT_ERR       0x2
#define DTCM_INIT_ERR       0x3
#define REBOOT_CMD_ERR      0x4
#define FW_REBOOT_ERR       0x5



/** 
 *  @brief To setup voe km message interrupt.
 *
 *  @param int_en to enable/disable the interrupt.
 * 
 *  @returns void
 */
__inline void hal_voe_km_message_int_rtl8195bhp(bool int_en)
{
    VOE->reg_interrupt_mask_of_external_cpu_b.bit_km_message_isr_en = int_en;
}

/** 
 *  @brief To setup voe line buffer overflow interrupt.
 *
 *  @param int_en to enable/disable the interrupt.
 * 
 *  @returns void
 */
__inline void hal_voe_lb_overflow_int_rtl8195bhp(bool int_en)
{
    VOE->reg_interrupt_mask_of_external_cpu_b.bit_lbcu_ap_overflow_en = int_en;
}


/** 
 *  @brief return the valid status of message VOE sent.
 *
 *  @param void
 *
 *  @returns 1: There is valid message VOE sent 0: no message to process 
 */
__inline bool hal_voe_check_message_voe_queue_rtl8195bhp(void)
{
	return (bool)(VOE->reg_read_message_external_ctrl_b.bit_invalid_voe_queue);
}


/** 
 *  @brief return the status of message TM sent.
 *
 *  @param void
 *
 *  @returns 1: VOE hadn't processed the message 0: no message to process 
 */
__inline bool hal_voe_check_message_ap_queue_rtl8195bhp(void)
{
	return (bool)(VOE->reg_send_message_external_ctrl_b.bit_invalid_ap_queue);
}

/** 
 *  @brief Set KM message to TM9 interrupt.
 *
 *  @param int_en The bit map to enable/disable the interrupt.
 * 
 *  @returns void
 */
__inline void hal_voe_set_km_message_int_rtl8195bhp(u8 int_en)
{
    VOE->reg_interrupt_mask_of_external_cpu_b.bit_km_message_isr_en = int_en;
}

/**
 *  @brief Set KM ERAC to TM9 interrupt.
 *
 *  @param int_en The bit map to enable/disable the interrupt.
 *
 *  @returns void
 */
__inline void hal_voe_set_erac_int(u8 int_en)
{
    VOE->reg_interrupt_mask_of_external_cpu_b.bit_erac_ap_finish_en = int_en;
}



hal_status_t hal_voe_init_rtl8195bhp(irq_handler_t voe_isr, u32 fw_bin_addr, u32 itcm_image_len, u32 dtcm_image_len);
void hal_voe_write_cmd_data1_rtl8195bhp(u32 data);
void hal_voe_write_cmd_data2_rtl8195bhp(u32 data);
void hal_voe_write_cmd_data3_rtl8195bhp(u32 data);
void hal_voe_write_cmd_data4_rtl8195bhp(u32 data);
void hal_voe_power_off_rtl8195bhp(void);



/**
 *  @brief Send data to VOE
 *
 *  @param[in]  data 	:	transfer data to VOE share memory.
 *  @param[in]  cmd		:	The ISP channel number. (range: 0 ~ 3)
 *
 *  @returns Result.
 *
 */
__STATIC_INLINE void hal_voe_write_cmd_data_rtl8195bhp(u32 data,u32 cmd)
{
    HAL_WRITE32(VOE_SHARE_MEMORY, (cmd<<2) ,data);
}

/**
 *  @brief Read data from VOE
 *
 *  @param[in]  data 	:	transfer data to VOE share memory.
 *  @param[in]  cmd		:	The ISP channel number. (range: 0 ~ 3)
 *
 *  @returns Result.
 *
 */
__STATIC_INLINE u32 hal_voe_read_cmd_data_rtl8195bhp(u32 cmd)
{
	return HAL_READ32(KM2TM_CMD_BASE, (cmd<<2));
}

/** @} */ /* End of group hs_hal_voe */

#ifdef  __cplusplus
}
#endif

#endif  // end of "#define _RTL8195BH_PWM_H_"

