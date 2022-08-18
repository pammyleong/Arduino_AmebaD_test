/**************************************************************************//**
 * @file     efuse_boot_cfg.h
 * @brief    Define the structure types for boot flow configuration those from eFuse.
 * @version  V1.00
 * @date     2020-05-01
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

#ifndef _EFUSE_BOOT_CFG_H
#define _EFUSE_BOOT_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
#include "platform_conf.h"

// TODO: modification for 8710c: defines the system configuration in eFuse
/**
  \brief  Define the boot method
*/
enum boot_type_e {
    BootFromFlash               = 0,
    BootFromUART                = 1,
    BootFromSDIOD               = 3,
    BootFromTestModeUART        = 4
};

/**
  \brief  Define the debugging port configuration
*/
enum debug_port_cfg_e {
    DbgPorSWD           = 0,
    DbgPorJTag          = 1
};

/**
  \brief  Define the pin selection for flash boot
*/
enum flas_boot_pin_sel_e {
    BootFlash_DualIOS0  = 0,    /*!< flash pin on A[7, 8, 11, 10, (9, 12)] */
    BootFlash_DualIOS1  = 1,    /*!< flash pin on B[8, 11, 12, 7, (6, 10)] */
    BootFlash_DualIOS2  = 2     /*!< flash pin on A[15,16, 19, 20, (17,18)] */
};

/**
  \brief  Define the UART port selection for UART boot
*/
enum uart_boot_port_sel_e {
    BootUART2           = 0,
    BootUART1           = 1,
    BootUART0           = 2
};

/**
  \brief  Define the pin selection for UART boot
*/
enum uart_boot_pin_sel_e {
    BootUART_S0         = 0,
    BootUART_S1         = 1
};

/**
  \brief  Define the boot debugging UART port selection
*/
enum boot_dbg_uart_sel_e {
    BootDbgUART2        = 0,
    BootDbgUART1        = 1,
    BootDbgUART0        = 2
};

/**
  \brief  Define the boot debugging message on/off control
*/
enum boot_dbg_msg_ctrl_e {
    BootDbgMsgOn        = 0,
    BootDbgMsgOff       = 1
};

/**
  \brief  Define the X-Tal selection in eFuse.
*/
enum xtal_sel_e {
    XTAL_40M       = 0,
    XTAL_26M       = 1
};

typedef struct boot_comm_cfg_s {
    __IOM uint8_t boot_sel        : 4;       /*!< [3..0] Boot method selection */
    __IOM uint8_t cfg             : 4;       /*!< [7..4] Boot configuration */
} boot_comm_cfg_t, *pboot_comm_cfg_t;

typedef struct flash_boot_cfg_s {
    __IOM uint8_t boot_sel        : 4;       /*!< [3..0] Boot method selection */
    __IOM uint8_t io_mode_sel     : 1;       /*!< [4] Flash IO mode selection */
    __IOM uint8_t pin_sel         : 2;       /*!< [5..6] flash pin selection */
} flash_boot_cfg_t, *pflash_boot_cfg_t;

typedef struct uart_boot_cfg_s {
    __IOM uint8_t boot_sel        : 4;       /*!< [3..0] Boot method selection */
    __IOM uint8_t rx_pin_sel      : 1;       /*!< [4] UART RX pin selection */
    __IOM uint8_t tx_pin_sel      : 1;       /*!< [5] UART TX pin selection */
    __IOM uint8_t port_sel        : 2;       /*!< [7..6] UART port selection */
} uart_boot_cfg_t, *puart_boot_cfg_t;

typedef union {
  __IOM uint8_t byte;
  union{
    boot_comm_cfg_t boot_comm;
    flash_boot_cfg_t flash_boot;
    uart_boot_cfg_t uart_boot;
  } bit;
} efuse_boot_cfg1_t, *pefuse_boot_cfg1_t;

typedef union {
  __IOM uint8_t byte;
  
  struct {
    __IOM uint8_t dbg_port_mode   : 1;       /*!< [0..0] debug port mode selection: 0: SWD, 1: JTAG */
    __IOM uint8_t uart_baud_sel   : 3;       /*!< [3..1] UART boot baud rate selection */    
    __IM  uint8_t : 2;                       /*!< [5..4] Reserved */
    __IOM uint8_t nsk_mode        : 1;       /*!< [6..6] Secure book No-Share-Key mode enable: 0: disable, 1: enable */
    __IOM uint8_t secure_lock     : 1;       /*!< [7..7] Secure book lock: is allow to load un-encrypted image */
  } bit;
} efuse_boot_cfg2_t, *pefuse_boot_cfg2_t;

typedef union {
  __IOM uint8_t byte;
  
  struct {
    __IOM uint8_t rx_pin_sel      : 1;       /*!< [0..0] Log UART RX pin selection */
    __IOM uint8_t tx_pin_sel      : 1;       /*!< [1..1] Log UART TX pin selection */
    __IOM uint8_t port_sel        : 2;       /*!< [3..2] Log UART port selection */
    __IOM uint8_t dbg_en          : 1;       /*!< [4..4] Boot debugging message enable */
    __IM  uint8_t : 3;
  } bit;
} efuse_boot_dbg_port_cfg_t, *pefuse_boot_dbg_port_cfg_t;

typedef union {
  __IOM uint32_t word;
  
  struct {
    efuse_boot_cfg1_t cfg1;                 /*!< [0..7] boot configuration 1 */
    efuse_boot_cfg2_t cfg2;                 /*!< [8..15] boot configuration 2 */
    efuse_boot_dbg_port_cfg_t dbg_cfg;      /*!< [16..23] log UART configuration */
    __IOM uint8_t reserved;                 /*!< [31..24] reserved */
  } byte;
} efuse_boot_cfg_t, *pefuse_boot_cfg_t;

/**
  \brief Union type to access super_sec_ef_ctrl (@ 0x50002c80).
*/
typedef union {
  __OM  uint32_t w;                           /*!< (@ 0x50002c80) Super Secure eFuse Control Register                        */
  
  struct {
    __OM  uint32_t sec_super_sec_ef_lock : 1; /*!< [0..0] When this bit is written to '1', this bit can not be
                                                   written to '0'. Beside the high speed platform is reset.
                                                   1: Super secure zone can not be accessed. 0: Super secure
                                                   zone just can be accessed by secure state. (AXI_PORT[1]
                                                   = 0)                                                                      */
  } b;
} super_sec_ef_ctrl_t, *psuper_sec_ef_ctrl_t;

typedef union {
  __IOM uint8_t byte;

  struct {
    __IOM uint8_t ldo_d_mode_sel    : 1;       /*!< [0..0] ldod mode selection 1: LDO */
    __IOM uint8_t boost_en          : 1;       /*!< [1..1] Enable boost */
    __IOM uint8_t chg_en            : 1;       /*!< [2..2] Enable CHG */
    __IM  uint8_t                   : 5;       /*!< [7..3] Reserved */
  } bit;
} efuse_regu_cfg1_t, *pefuse_regu_cfg1_t;

typedef union {
  __IOM uint8_t byte;
  
  struct {
    __IOM uint8_t swrm_en           : 1;       /*!< [0..0] SWRM Enable  */
    __IOM uint8_t swrm_mode_en      : 1;       /*!< [1..1] SWRM mode selection */
    __IOM uint8_t ldod_src_mem_en   : 1;       /*!< [2..2] enable ldod as mem power source; 0: enable */
    __IOM uint8_t ldod_src_adj      : 4;       /*!< [6..3] ldod output adj  */
    __IM  uint8_t                   : 1;       /*!< [7..7] Reserved */
  } bit;
} efuse_regu_cfg2_t, *pefuse_regu_cfg2_t;

/**
  \brief  Define the device life cycle state in eFuse.
*/
enum dev_lfc_state_e {
    LfC_RMA                     = 0,    // Life Cycle State: RMA state    
    LfC_Deployed                = 4,    // Life Cycle State: Deployed state
    LfC_Development             = 6,    // Life Cycle State: Development/Device manufacture state
    LfC_Chip_Manufactur         = 7     // Life Cycle State: Chip manufacture state
};

typedef union {
  __IOM uint8_t byte;
  
  struct {
    __IOM uint8_t dev_lfc_state     : 3;       /*!< [2..0] device life cycle state  */
    __IM  uint8_t                   : 4;       /*!< [6..3] Reserved */
    __IOM uint8_t secure_lock       : 1;       /*!< [7..7] Secure book lock: is allow to load un-encrypted image */
  } bit;
} efuse_dev_lfc_state_t, *pefuse_dev_lfc_state_t;

typedef union {
  __IOM uint32_t word;
  
  struct {
    __IOM uint32_t bt_en           : 2;       /*!< [1..0] BT function enable */
    __IOM uint32_t bt_mesh_en      : 2;       /*!< [3..2] BT mesh network function enable */
    __IOM uint32_t trust_zone_en   : 2;       /*!< [5..4] trust zone enable */
    __IOM uint32_t sec_boot_en     : 2;       /*!< [7..6] secure boot enable */
    __IM  uint32_t                 : 2;       /*!< [9..8] Reserved */
    __IOM uint32_t limit_io        : 2;       /*!< [11..10] limit_io enable */
    __IOM uint32_t cpu_clk_sel     : 2;       /*!< [13..12] cpu clock select */
    __IOM uint32_t mcm_flash_type  : 2;       /*!< [15..14] MCM flash type: 11/00: 2M, 01: 1M, 10: 2M downgrad as 1M */
    __IM  uint32_t                 : 18;      /*!< [31..16] Reserved */
  } bit;
} efuse_chip_func_en_t, *pefuse_chip_func_en_t;

#define EFuseBootCfg1Offset         (0x18)
#define EFuseBootCfg2Offset         (0x19)
#define EFuseDbgMsgCfgOffset        (0x1A)
#define EFuseAutoLoadRegBase        (0x40000020UL)

// Registers for eFuse auto-load 
//#define BootCfg1Reg                 ((efuse_boot_cfg1_t *)(EFuseAutoLoadRegBase + EFuseBootCfg1Offset))
//#define BootCfg2Reg                 ((efuse_boot_cfg2_t *)(EFuseAutoLoadRegBase + EFuseBootCfg2Offset))
//#define BootDbgMsgCfgReg            ((efuse_boot_dbg_port_cfg_t *)(EFuseAutoLoadRegBase + EFuseDbgMsgCfgOffset))
#define eFuseBootCfg                ((efuse_boot_cfg_t *)(EFuseAutoLoadRegBase + EFuseBootCfg1Offset))

#define SuperSecEFCtrlReg           ((super_sec_ef_ctrl_t*)(0x50002c80))

#define EFusePackageSel             (0x1F8)
#define EFuseClkSel                 (0x1F9)
#define EFuseReguSel                (0x1FA)
#define EFuseReguSel2               (0x1FB)


#ifdef __cplusplus
}
#endif

#endif /* _EFUSE_BOOT_CFG_H */
