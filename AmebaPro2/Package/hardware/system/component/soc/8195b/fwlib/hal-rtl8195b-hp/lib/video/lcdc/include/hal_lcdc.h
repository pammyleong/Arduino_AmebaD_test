/**************************************************************************//**
 * @file     hal_lcdc.h
 * @brief    The HAL API implementation for the LCD controller.
 *
 * @version  V1.00
 * @date     2017-04-21
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

#ifndef HAL_LCDC_H
#define HAL_LCDC_H

#include "hal_api.h"


#ifdef __cplusplus
extern "C" {
#endif

/** 
 * @addtogroup hs_hal_lcdc LCDC
 * @{
 * @brief The LCDC HAL APIs.
 */

#define LCDC_ISR_NUM 7

/*! define lcdc pin mux selection */
enum  lcdc_pin_sel_e
{
    McuMode       = 0,
    RgbMode       = 1,
    McuMode8Bit   = 2,
    RgbMode6Bit   = 3
};
typedef uint8_t lcdc_pin_sel_t;

/*! define LCDC interface mode */
enum  lcdc_if_mode_e
{
    Mcu8080I8Bit      = 0,
    Mcu8080II8Bit     = 1,
    Mcu8080I9Bit      = 2,
    Mcu8080II9Bit     = 3,
    Mcu8080I16Bit     = 4,
    Mcu8080II16Bit    = 5,
    Mcu8080I18Bit     = 6,
    Mcu8080II18Bit    = 7,    
    RgbParallel6Bit   = 8,
    RgbParallel16Bit  = 9     
};
typedef uint8_t lcdc_if_mode_t;

/*! define lcdc mcu i/f sync method */
enum  lcdc_mcu_sync_mtd_e
{
    ByPanelAlone    = 0,
    ByVsyncOut      = 1,
    ByTESignalIn    = 2
};
typedef uint8_t lcdc_mcu_sync_mtd_t;

/*! define lcdc rgb i/f sync method */
enum  lcdc_rgb_sync_mtd_e
{
    ByEnable        = 0,
    BySyncReg       = 1,
};
typedef uint8_t lcdc_rgb_sync_mtd_t;

/*! define panel sync mode */
enum  lcdc_sync_mode_e
{
    McuPanelAlone   = 0,
    McuVsync        = 1,
    McuTe           = 2,
    RgbEn           = 3,
    RgbSyncReg      = 4,    
};
typedef uint8_t lcdc_sync_mode_t;


/*! define lcdc command type, as REG_LCDCTL_LCD_COMMAND_b.CMDTYPE register */
enum  lcdc_cmd_type_e
{
    LcdcWriteCmd				= 0,    /*! CMD mode: only write parameters to LCD */
    LcdcReadCmd					= 1,    /*! CMD mode: read data back or can write parameters and read data back */
    LcdeFrWriteCmd			= 2,    /*! CMD mode: write frame data continuously */    
};
typedef uint8_t lcdc_cmd_type_t;

/**
  \brief  The data structure to configure mcu interface 
*/
typedef struct hal_lcdc_mcu_timing_s {
    u16 wr_period; /*! WR pulse width-2. unit: sys_clk. */
    u8 rd_actw; /*! RD active pulse width -1. unit: WR pulse  */
    u8 rd_inactw; /*! RD inactive pulse width -1. unit: WR pulse */
} hal_lcdc_mcu_timing_t;


/**
  \brief  The data structure to configure the detail items of mcu command 
*/
typedef struct hal_lcdc_mcu_command_s {
    u8 cmd;  /*! the command send to lcd panel */
    lcdc_cmd_type_t cmd_type; /*! define the access type of this command  */
    bool inst_cmd;    /*! set instant command */
    bool src_at_extmem;   /*! configure the storage of parameters */
    u32 para_addr; /*! the start address for command paramters. */
    u16 wr_num;   /*! The number of write parameters, not include command */
    u8 rd_num;   /*! The number of read parameters */
	u8 rsvd;
} hal_lcdc_mcu_command_t;

typedef void (*lcdc_callback_t) (void *);


/**
  \brief  The data structure to handle the lcd controller, includes the configuration, register base address
          and interrupt call back functions.
*/
typedef struct hal_lcdc_adapter_s {
    lcdc_callback_t me_lsr_callback[LCDC_ISR_NUM];      /*! callback function for lsr */
    void *me_lsr_cb_para[LCDC_ISR_NUM];   /*! the argument for lsr callback function */
    u8 lsr_proc_prior[LCDC_ISR_NUM];   /*! the process priority of lcdc interrupt events */
    lcdc_pin_sel_t pin_sel;         /*! the pinmux selection for different lcd i/f */
    lcdc_if_mode_t if_mode;         /*! define LCDC interface mode */ 
    lcdc_sync_mode_t sync_mode;   /*! define lcdc i/f sync mode */
    bool lcdc_en;                   /*! record lcdc is enable or not */
    bool frame_transfering;         /*! record frame transfer is ongoing or not */  
	u16 rsvd;
	void (*enter_critical)(void);   /*! the function for entering timer critical state */
    void (*exit_critical)(void);    /*! the function for exit timer critical state */
} hal_lcdc_adapter_t, *phal_lcdc_adapter_t;



/**
  \brief  The data structure to configure the frame buffer 
*/
typedef struct hal_lcdc_frame_buffer_s {
    u32 buff0_addr; /*! the start address for frame buffer0. */
    u32 buff1_addr; /*! the start address for frame buffer1. */
    u32 buff2_addr; /*! the start address for frame buffer2. */
    u32 buff0_uv_addr; /*! the start address for frame buffer0. */
    u32 buff1_uv_addr; /*! the start address for frame buffer1. */
    u32 buff2_uv_addr; /*! the start address for frame buffer2. */    
} hal_lcdc_frame_buffer_t;


/**
  \brief  The data structure to simple configuration 
*/
typedef struct hal_lcdc_simple_config_s {
    u16 image_width;        /*! the width of input image. */   
    u16 image_height;       /*! the height of input image. */    
    hal_lcdc_frame_buffer_t fr_buffer; /*! The data structure to configure the frame buffer. */   
} hal_lcdc_simple_config_t;


/**
  \brief  The data structure for mcu command 
*/
typedef struct hal_lcdc_mcu_cmd_s {
    u16 para_num;   /*! parameter number (read or write) */    
    u8 cmd;         /*! mcu 8bit command  */
	u8 rsvd;
} hal_lcdc_mcu_cmd_t;

/**
  \brief  The data structure to configure mcu interface 
*/
typedef struct hal_lcdc_mcuif_config_s {
    u8 cs_pl; /*! 0: low level for active, 1: high level for active. */
    u8 rs_pl; /*! 0: low level for active, 1: high level for active. */
    u8 wr_pl; /*! 0: low level for active, 1: high level for active. */
    u8 rd_pl; /*! 0: low level for active, 1: high level for active. */
    u8 data_pl; /*! 0: normal data, 1: inverted data. */       
    u8 te_pl; /*! 0: low level for active, 1: high level for active. */
    u8 vs_pl; /*! 0: low level for active, 1: high level for active. */         
	u8 rsvd;
    u16 tedelay; /*! The delay interval -5. This interval is from detected TE signal to starting frame transfer. Unit:WR pulse */        
} hal_lcdc_mcuif_config_t;

/**
  \brief  The data structure to configure rgb interface 
*/
typedef struct hal_lcdc_rgb_timing_s {
    u8 vsw; /*! vertical sync signal width -1. unit: inactive lines */
    u8 vbp; /*! back porch line number-1. */
    u8 vfp; /*! front porch line number-1. */
    u8 hsw; /*! horizontal sync signal width -1. Unit: DCLK. */
    u8 hbp; /*! horizontal back porch -1. */
    u8 hfp; /*! horizontal front porch -1. */        
} hal_lcdc_rgb_timing_t;

/**
  \brief  The data structure to configure rgb interface 
*/
typedef struct hal_lcdc_rgb_if_s {
    u16 dclk_div; /*! DCLK clock divider. */
    u8 dclk_pl; /*! 0: dclk active edge at rising, 1: active at falling edge. */
    u8 vs_pl; /*! 0: sync at low level, 1: sync at high level. */
    u8 hs_pl; /*! 0: sync at low level, 1: sync at high level. */
    u8 en_pl; /*! 0: active at low level, 1: active at high level. */
    u8 dat_pl; /*! 0: normal data, 1: inverted data. */        
    bool first_frame_wr;  /*! ISP is writing 1st frame, all three buffers aren't available */
} hal_lcdc_rgb_if_t;



hal_status_t hal_lcdc_init(hal_lcdc_adapter_t *phal_lcdc_adpt, lcdc_if_mode_t if_mode, lcdc_sync_mode_t sync_mode);
hal_status_t hal_lcdc_mcu_write_cmd_mem(hal_lcdc_adapter_t *phal_lcdc_adpt, hal_lcdc_mcu_cmd_t *pcmd_data, u32 para_addr, bool instant);
hal_status_t hal_lcdc_mcu_write_cmd_fifo(hal_lcdc_adapter_t *phal_lcdc_adpt, hal_lcdc_mcu_cmd_t *pcmd_data, bool instant);
hal_status_t hal_lcdc_mcu_read_cmd(hal_lcdc_adapter_t *phal_lcdc_adpt, hal_lcdc_mcu_cmd_t *pcmd_data, bool instant);
hal_status_t hal_lcdc_mcu_continuous_transfer_cmd(hal_lcdc_adapter_t *phal_lcdc_adpt, uint8_t cmd);
hal_status_t hal_lcdc_mcu_terminate_cmd(hal_lcdc_adapter_t *phal_lcdc_adpt);
hal_status_t hal_lcdc_mcu_terminate_fr_transfer(hal_lcdc_adapter_t *phal_lcdc_adpt, bool instant, u8 nop_cmd);
hal_status_t hal_lcdc_rgbif_simple_config(hal_lcdc_adapter_t *phal_lcdc_adpt, hal_lcdc_rgb_timing_t *prgb_timing, hal_lcdc_rgb_if_t *prgb_if_config , hal_lcdc_simple_config_t *psimple_config);
hal_status_t hal_lcdc_deinit(hal_lcdc_adapter_t *phal_lcdc_adpt);
hal_status_t hal_lcdc_mcuif_simple_config(hal_lcdc_adapter_t *phal_lcdc_adpt, hal_lcdc_mcu_timing_t *pmcuif_timing, hal_lcdc_simple_config_t *psimple_config);
void hal_lcdc_config_depth_reduction(hal_lcdc_adapter_t *phal_lcdc_adpt, bool round_en, bool dither_en, u8 dg_gain, bool dither_rst_en);

void hal_lcdc_set_cmd_done_int(hal_lcdc_adapter_t *plcdc_adpt, lcdc_callback_t callback, void *arg, u8 int_en);
void hal_lcdc_set_dma_underflow_int(hal_lcdc_adapter_t *plcdc_adpt, lcdc_callback_t callback, void *arg, u8 int_en);
void hal_lcdc_set_para_overflow_int(hal_lcdc_adapter_t *plcdc_adpt, lcdc_callback_t callback, void *arg, u8 int_en);
void hal_lcdc_set_refresh_done_int(hal_lcdc_adapter_t *plcdc_adpt, lcdc_callback_t callback, void *arg, u8 int_en);
void hal_lcdc_set_rdFIFO_underflow_int(hal_lcdc_adapter_t *plcdc_adpt, lcdc_callback_t callback, void *arg, u8 int_en);
void hal_lcdc_set_para_underflow_int(hal_lcdc_adapter_t *plcdc_adpt, lcdc_callback_t callback, void *arg, u8 int_en);
void hal_lcdc_set_rdFIFO_flush_valid_int(hal_lcdc_adapter_t *plcdc_adpt, lcdc_callback_t callback, void *arg, u8 int_en);
void hal_lcdc_enable(hal_lcdc_adapter_t *plcdc_adpt);
u16 hal_lcdc_read_interrupt_status(void);
void hal_lcdc_disable_if(hal_lcdc_adapter_t *plcdc_adpt, bool instant);
void hal_lcdc_clear_int_status(u8 int_bit);
bool hal_lcdc_enable_sts(void);
bool hal_lcdc_check_cmd_busy(void);
void hal_lcdc_write_para(u32 para);
u32 hal_lcdc_read_data(void);


/** @} */ /* End of group hs_hal_lcdc */

#ifdef __cplusplus
}
#endif

#endif /* HAL_LCDC_H */

