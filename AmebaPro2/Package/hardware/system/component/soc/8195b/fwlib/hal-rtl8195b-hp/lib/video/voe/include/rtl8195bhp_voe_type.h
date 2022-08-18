/**************************************************************************//**
 * @file     rtl8195bhp_voe_type.h
 * @brief    CMSIS HeaderFile
 * @version  0.1
 * @date     05. October 2017
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

#ifndef _RTL8195BHP_VOE_TYPE_H_
#define _RTL8195BHP_VOE_TYPE_H_

#ifdef  __cplusplus
extern "C"
{
#endif

/// @cond DOXYGEN_VOE_REG_TYPE

/**
 * @addtogroup hs_hal_voe_reg VOE Registers.
 * @ingroup hs_hal_voe
 * @{
 */


/* =========================================================================================================================== */
/* ================                                            VOE                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Control video data flow from ISP to Encoder. KM(MCU) is used for offloading encoder register setting and encoder head calculation. (VOE)
  */

typedef struct {                                /*!< (@ 0x40492000) VOE Structure                                              */
  
  union {
    __IOM uint32_t reg_voe_system_ctrl;         /*!< (@ 0x00000000) reg_voe_system_ctrl                                        */
    
    struct {
      __IOM uint32_t bit_clock_gating_dis : 1;  /*!< [0..0] 0': Disable VOE clock; '1': Enable VOE clock                       */
      __IOM uint32_t bit_voe_reset_dis : 1;     /*!< [1..1] 0': Disable VOE function; '1': Enable VOE function                 */
      __IOM uint32_t bit_km_reset_dis : 1;      /*!< [2..2] 0': Disable KM; '1': Enable KM                                     */
    } reg_voe_system_ctrl_b;
  } ;
  
  union {
    __IOM uint32_t reg_km_fw_base_address;      /*!< (@ 0x00000004) reg_km_fw_base_address                                     */
    
    struct {
      __IOM uint32_t bit_km_fw_base_addr : 32;  /*!< [31..0] When KM boots, rom code should read this register to
                                                     get the location of ram code. Then, it also should read
                                                     REG_KM_FW_LEN and copy the fw into memory of VOE.                         */
    } reg_km_fw_base_address_b;
  } ;
  
  union {
    __IOM uint32_t reg_km_fw_len;               /*!< (@ 0x00000008) reg_km_fw_len                                              */
    
    struct {
      __IOM uint32_t bit_km_fw_len : 32;        /*!< [31..0] Same ad REG_KM_FW_BASE_ADDRESS                                    */
    } reg_km_fw_len_b;
  } ;
  
  union {
    __IOM uint32_t reg_send_message_external_ctrl;/*!< (@ 0x0000000C) reg_send_message_external_ctrl                           */
    
    struct {
      __IOM uint32_t bit_message : 30;          /*!< [29..0] Message from AP                                                   */
      __IM  uint32_t            : 1;
      __IOM uint32_t bit_invalid_ap_queue : 1;  /*!< [31..31] 0': Default value '1': Trigger interrupt to KM.                  */
    } reg_send_message_external_ctrl_b;
  } ;
  
  union {
    __IOM uint32_t reg_read_message_external_ctrl;/*!< (@ 0x00000010) reg_read_message_external_ctrl                           */
    
    struct {
      __IM  uint32_t bit_message : 30;          /*!< [29..0] Message from VOE and thie field equal to 0x108[29:0]
                                                     REG_SEND_MESSAGE_KM_CTRL                                                  */
      __IM  uint32_t            : 1;
      __IOM uint32_t bit_invalid_voe_queue : 1; /*!< [31..31] 0': Default value; When this bit is written to '0',
                                                     FSM should clean the bit 0x108[31] REG_SEND_MESSAGE_KM_CTRL.
                                                     And FSM also should clean 0x108[29:0] '1': Trigger interrupt
                                                     to the external CPU                                                       */
    } reg_read_message_external_ctrl_b;
  } ;
  
  union {
    __IOM uint32_t reg_interrupt_status_of_external_cpu;/*!< (@ 0x00000014) reg_interrupt_status_of_external_cpu               */
    
    struct {
      __IOM uint32_t bit_km_message_isr_status : 1;/*!< [0..0] 0': default '1': When KM set 0x108[31] REG_SEND_MESSAGE_KM_CTRL,
                                                     FSM will set this bit to '1'. And this bit will be clear
                                                     with writing '1'.                                                         */
      __IM  uint32_t            : 7;
      __IOM uint32_t bit_erac_finish : 1;       /*!< [8..8] ERAC                                                               */
      __IM  uint32_t            : 8;
      __IOM uint32_t bit_line_buffer_overflow : 1;/*!< [17..17] Line buffer overflow                                           */
      __IM  uint32_t            : 6;
      __IOM uint32_t bit_fbcu_excpu_slice_done : 1;/*!< [24..24] Compress engine to external cpu indicating slice compress
                                                     done.                                                                     */
      __IOM uint32_t bit_fbcu_excpu_frame_done : 1;/*!< [25..25] compress engine to external cpu indicating frame compress
                                                     done.                                                                     */
    } reg_interrupt_status_of_external_cpu_b;
  } ;
  
  union {
    __IOM uint32_t reg_interrupt_mask_of_external_cpu;/*!< (@ 0x00000018) reg_interrupt_mask_of_external_cpu                   */
    
    struct {
      __IOM uint32_t bit_km_message_isr_en : 1; /*!< [0..0] 0': Default; disable interrupt '1': Enable the interrupt
                                                     where KM set 0x108[31] REG_SEND_MESSAGE_KM_CTRL.                          */
      __IM  uint32_t            : 7;
      __IOM uint32_t bit_erac_ap_finish_en : 1; /*!< [8..8] ERAC finsh write/read                                              */
      __IM  uint32_t            : 8;
      __IOM uint32_t bit_lbcu_ap_overflow_en : 1;/*!< [17..17] Line buffer overflow mask                                       */
      __IM  uint32_t            : 6;
      __IOM uint32_t bit_fbcu_ap_slice_done_en : 1;/*!< [24..24] FBCU slice done int enable                                    */
      __IOM uint32_t bit_fbcu_ap_frame_done_en : 1;/*!< [25..25] fbcu frame done int enable                                    */
    } reg_interrupt_mask_of_external_cpu_b;
  } ;
} VOE_Type;                                     /*!< Size = 28 (0x1c)                                                    */


//#define VOE_BASE                    0x40492000UL

#define VOE                         ((VOE_Type*)               VOE_BASE)



/**
  \brief Union type to access voe_reg_voe_system_ctrl (@ 0x00000000).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000000) w                                        */
  
  struct {
    __IOM uint32_t bit_clock_gating_dis : 1;  /*!< [0..0] 0': Disable VOE clock; '1': Enable VOE clock                       */
    __IOM uint32_t bit_voe_reset_dis : 1;     /*!< [1..1] 0': Disable VOE function; '1': Enable VOE function                 */
    __IOM uint32_t bit_km_reset_dis : 1;      /*!< [2..2] 0': Disable KM; '1': Enable KM                                     */
  } b;                                        /*!< bit fields for voe_reg_voe_system_ctrl */
} voe_reg_voe_system_ctrl_t, *pvoe_reg_voe_system_ctrl_t;

/**
  \brief Union type to access voe_reg_km_fw_base_address (@ 0x00000004).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000004) w                                     */
  
  struct {
    __IOM uint32_t bit_km_fw_base_addr : 32;  /*!< [31..0] When KM boots, rom code should read this register to
                                                   get the location of ram code. Then, it also should read
                                                   REG_KM_FW_LEN and copy the fw into memory of VOE.                         */
  } b;                                        /*!< bit fields for voe_reg_km_fw_base_address */
} voe_reg_km_fw_base_address_t, *pvoe_reg_km_fw_base_address_t;

/**
  \brief Union type to access voe_reg_km_fw_len (@ 0x00000008).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000008) w                                              */
  
  struct {
    __IOM uint32_t bit_km_fw_len : 32;        /*!< [31..0] Same ad REG_KM_FW_BASE_ADDRESS                                    */
  } b;                                        /*!< bit fields for voe_reg_km_fw_len */
} voe_reg_km_fw_len_t, *pvoe_reg_km_fw_len_t;

/**
  \brief Union type to access voe_reg_send_message_external_ctrl (@ 0x0000000C).
*/
typedef union {
  __IOM uint32_t w;                                 /*!< (@ 0x0000000C) reg_send_message_external_ctrl                           */
  
  struct {
    __IOM uint32_t bit_message : 30;          /*!< [29..0] Message from AP                                                   */
    __IM  uint32_t            : 1;
    __IOM uint32_t bit_invalid_ap_queue : 1;  /*!< [31..31] 0': Default value '1': Trigger interrupt to KM.                  */
  } b;                                        /*!< bit fields for voe_reg_send_message_external_ctrl */
} voe_reg_send_message_external_ctrl_t, *pvoe_reg_send_message_external_ctrl_t;

/**
  \brief Union type to access voe_reg_read_message_external_ctrl (@ 0x00000010).
*/
typedef union {
  __IOM uint32_t w;                                 /*!< (@ 0x00000010) reg_read_message_external_ctrl                           */
  
  struct {
    __IM  uint32_t bit_message : 30;          /*!< [29..0] Message from VOE and thie field equal to 0x108[29:0]
                                                   REG_SEND_MESSAGE_KM_CTRL                                                  */
    __IM  uint32_t            : 1;
    __IOM uint32_t bit_invalid_voe_queue : 1; /*!< [31..31] 0': Default value; When this bit is written to '0',
                                                   FSM should clean the bit 0x108[31] REG_SEND_MESSAGE_KM_CTRL.
                                                   And FSM also should clean 0x108[29:0] '1': Trigger interrupt
                                                   to the external CPU                                                       */
  } b;                                        /*!< bit fields for voe_reg_read_message_external_ctrl */
} voe_reg_read_message_external_ctrl_t, *pvoe_reg_read_message_external_ctrl_t;

/**
  \brief Union type to access voe_reg_interrupt_status_of_external_cpu (@ 0x00000014).
*/
typedef union {
  __IOM uint32_t w;                                       /*!< (@ 0x00000014) reg_interrupt_status_of_external_cpu               */
  
  struct {
    __IOM uint32_t bit_km_message_isr_status : 1;/*!< [0..0] 0': default '1': When KM set 0x108[31] REG_SEND_MESSAGE_KM_CTRL,
                                                   FSM will set this bit to '1'. And this bit will be clear
                                                   with writing '1'.                                                         */
    __IM  uint32_t            : 7;
    __IOM uint32_t bit_erac_finish : 1;       /*!< [8..8] ERAC                                                               */
    __IM  uint32_t            : 8;
    __IOM uint32_t bit_line_buffer_overflow : 1;/*!< [17..17] Line buffer overflow                                           */
    __IM  uint32_t            : 6;
    __IOM uint32_t bit_fbcu_excpu_slice_done : 1;/*!< [24..24] Compress engine to external cpu indicating slice compress
                                                   done.                                                                     */
    __IOM uint32_t bit_fbcu_excpu_frame_done : 1;/*!< [25..25] compress engine to external cpu indicating frame compress
                                                   done.                                                                     */
  } b;                                        /*!< bit fields for voe_reg_interrupt_status_of_external_cpu */
} voe_reg_interrupt_status_of_external_cpu_t, *pvoe_reg_interrupt_status_of_external_cpu_t;

/**
  \brief Union type to access voe_reg_interrupt_mask_of_external_cpu (@ 0x00000018).
*/
typedef union {
  __IOM uint32_t w;                                     /*!< (@ 0x00000018) reg_interrupt_mask_of_external_cpu                   */
  
  struct {
    __IOM uint32_t bit_km_message_isr_en : 1; /*!< [0..0] 0': Default; disable interrupt '1': Enable the interrupt
                                                   where KM set 0x108[31] REG_SEND_MESSAGE_KM_CTRL.                          */
    __IM  uint32_t            : 7;
    __IOM uint32_t bit_erac_ap_finish_en : 1; /*!< [8..8] ERAC finsh write/read                                              */
    __IM  uint32_t            : 8;
    __IOM uint32_t bit_lbcu_ap_overflow_en : 1;/*!< [17..17] Line buffer overflow mask                                       */
    __IM  uint32_t            : 6;
    __IOM uint32_t bit_fbcu_ap_slice_done_en : 1;/*!< [24..24] FBCU slice done int enable                                    */
    __IOM uint32_t bit_fbcu_ap_frame_done_en : 1;/*!< [25..25] fbcu frame done int enable                                    */
  } b;                                        	 /*!< bit fields for voe_reg_interrupt_mask_of_external_cpu					*/
} voe_reg_interrupt_mask_of_external_cpu_t, *pvoe_reg_interrupt_mask_of_external_cpu_t;


/** @} */ /* End of group hs_hal_voe_reg */
/// @endcond /* End of condition DOXYGEN_VOE_REG_TYPE */


#ifdef  __cplusplus
}
#endif


#endif    // end of #ifndef _RTL8195BHP_VOE_TYPE_H_

