 /**************************************************************************//**
  * @file     rtl8195bhp_lcdc.h
  * @brief    The HAL related definition and macros for the LCD controller.
  *           Includes Registers and data type definition.
  * @version  V1.00
  * @date     2017-04-27
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
 
#ifndef _RTL8195BHP_LCDC_H_
#define _RTL8195BHP_LCDC_H_

#ifdef  __cplusplus
extern "C"
{
#endif

#include "basic_types.h"
#include "rtl8195bhp_lcdc_type.h"



/** 
 * @addtogroup hs_hal_lcdc LCDC
 * @{
 * @brief The LCDC HAL APIs.
 */




/**
  \brief  The data structure to configure depth reduction module.
*/
typedef struct hal_lcdc_dep_reduction_config_s {
    bool round_en;  /*! Enable rounding process when reducing depth */
    bool dither_en; /*! Enable 1D dithering  */
    u8 dg_gain_mode;    /*! Digital gain. 00: 1x, 01: 2x, 10: 4x, Others: Reserved */
    bool dither_reset_en;   /*! Reset dithering error when new line start */
} hal_lcdc_dep_reduction_config_t;

#if 0
/**
  \brief  The data structure to configure the frame transfer 
*/
typedef struct hal_lcdc_frame_transfer_s {
    u16 err_out_data; /*! output data when DMA FIFO underflow occurred.  */
    u8 rd_outstd; /*! the read outstanding value -1. */
    bool first_frame_wr;  /*! ISP is writing 1st frame, all three buffers aren't available */
    u8 err_out_mode;  /*! 0: output last data, 1: output err_out_data.  */
	u8 rsvd;
} hal_lcdc_frame_transfer_t;
#endif 

/** 
 *  @brief To check command busy status.
 *
 *  @param none.
 * 
 *  @returns the cmd is busy or not
 */
__inline 
bool hal_lcdc_check_cmd_busy_rtl8195bhp(void)
{
    return LCDC->reg_lcd_command_b.commandbusy;
}

/** 
 *  @brief To configure rgb_if dclk.
 *
 *  @param clkdiv The value set to clkdiv register.
 * 
 *  @returns void
 */
__inline 
void hal_lcdc_config_rgbif_clkdiv_rtl8195bhp (u16 clkdiv)
{
    LCDC->reg_rgbif_config_b.clkdiv = clkdiv;
}

/** 
 *  @brief To update rgb interface when frame transfer is processing.
 *
 *  @param en_update update rgb interface configuration.
 * 
 *  @returns void
 */
__inline 
void hal_lcdc_update_rgb_if_rtl8195bhp (bool en_update)
{

    LCDC->reg_vsync_timing_b.rgbifupdate = en_update;

}

/** 
 *  @brief To write parameter to DMA FIFO.
 *
 *  @param para the parameter data for mcu command. this data should be right-justified.
 * 
 *  @returns void
 */
__inline 
void hal_lcdc_write_para_rtl8195bhp (u32 para)
{
	LCDC->reg_dmadata = para;
}

/** 
 *  @brief To read data from RX FIFO.
 *
 *  @param none.
 * 
 *  @returns the data read from lcd panel
 */
__inline 
u32 hal_lcdc_read_data_rtl8195bhp (void)
{
	return LCDC->reg_rxdata;
}

/** 
 *  @brief To update mcu interface when frame transfer is processing.
 *
 *  @param en_update update mcu interface configuration.
 * 
 *  @returns void
 */
__inline 
void hal_lcdc_update_mcu_if_rtl8195bhp (bool en_update)
{

    LCDC->reg_mcuif_config_b.mcuifupdate = en_update;

}

/** 
 *  @brief To enable lcdc
 *
 *  @param none.
 * 
 *  @returns void
 */
__inline 
void hal_lcdc_enable_if_rtl8195bhp (void)
{
    LCDC->reg_basic_ctl_b.lcdcen = 1;
}

/**
 *  @brief To display the enable status of lcdc
 *
 *  @param none.
 * 
 *  @returns bool lcdc enable or not
 */
__inline
bool hal_lcdc_enable_sts_rtl8195bhp (void)
{
    return LCDC->reg_basic_ctl_b.lcdcen;
}

/** 
 *  @brief To configure the timing of starting frame tranfer instantly or after isp frame writing done
 *
 *  @param en starting frame tranfer after isp finished this frame writing
 * 
 *  @returns void
 */
__inline
void hal_lcdc_delay_start_transfer_rtl8195bhp (bool en)
{
	LCDC->reg_frtrans_dma_config_b.ispfirstwr = en;
}

/** 
 *  @brief To check mcu is updating timing or not.
 *
 *  @param none
 * 
 *  @returns 1: is updating,  0: updating done
 */
__inline
bool hal_lcdc_check_mcu_updating_rtl8195bhp (void)
{
   return LCDC->reg_mcuif_config_b.mcuifupdate;
}


/** 
 *  @brief To configure mcu te signals.
 *
 *  @param pmcuif_timing The point to mcu inferface's timing configuration.
 *  @param en_update update mcu interface configuration.
 * 
 *  @returns void
 */
__inline
void hal_lcdc_update_mcu_tedelay_rtl8195bhp (u16 tedelay)
{
	LCDC->reg_mcuif_config_b.tedelay = tedelay;
}

/** 
 *  @brief To configure rgb if's dclk_div.
 *
 *  @param dclk_div The point to rgb inferface's configuration structure.
 * 
 *  @returns void
 */
__inline
void hal_lcdc_rgbif_dclkdiv_rtl8195bhp(u16 dclk_div)
{
    LCDC->reg_rgbif_config_b.clkdiv = dclk_div;
}

/** 
 *  @brief return ISP buffer ID.
 *
 *  @param none
 * 
 *  @returns isp stream3 buffer id 0~2
 */
__inline
u8 hal_lcdc_get_isp_bufid_rtl8195bhp(void)
{
    return LCDC->reg_frtrans_dma_config_b.bufid;
}


/** 
 *  @brief To setup command done interrupt.
 *
 *  @param int_en The bit map to enable/disable the interrupt.
 * 
 *  @returns void
 */

__inline void hal_lcdc_set_cmd_done_int_rtl8195bhp (u8 int_en)
{

    LCDC->reg_interrupt_config_b.cmdeinten = int_en;
	
}


/** 
 *  @brief To setup dma underflow interrupt.
 *
 *  @param int_en The bit map to enable/disable the interrupt.
 * 
 *  @returns void
 */
__inline void hal_lcdc_set_dma_underflow_int_rtl8195bhp(u8 int_en)
{

    LCDC->reg_interrupt_config_b.dmauninten = int_en;
	
}

/** 
 *  @brief To setup parameters overflow interrupt.
 *
 *  @param int_en The bit map to enable/disable the interrupt.
 * 
 *  @returns void
 */
__inline void hal_lcdc_set_para_overflow_int_rtl8195bhp(u8 int_en)
{

	LCDC->reg_interrupt_config_b.paraovinten = int_en;
	
}

/** 
 *  @brief To setup lcd refresh done interrupt.
 *
 *  @param int_en The bit map to enable/disable the interrupt.
 * 
 *  @returns void
 */

__inline void hal_lcdc_set_refresh_done_int_rtl8195bhp(u8 int_en)
{

	LCDC->reg_interrupt_config_b.lcdfrdinten = int_en;
	
}

/** 
 *  @brief To setup receive FIFO underflow interrupt.
 *
 *  @param int_en The bit map to enable/disable the interrupt.
 * 
 *  @returns void
 */

__inline void hal_lcdc_set_rdFIFO_underflow_int_rtl8195bhp(u8 int_en)
{

	LCDC->reg_interrupt_config_b.rxuninten = int_en;
	
}

/** 
 *  @brief To setup parameter underflow interrupt.
 *
 *  @param int_en The bit map to enable/disable the interrupt.
 * 
 *  @returns void
 */

__inline void hal_lcdc_set_para_underflow_int_rtl8195bhp(u8 int_en)
{

	LCDC->reg_interrupt_config_b.parauninten = int_en;
	
}

/** 
 *  @brief To setup receive FIFO flush valid data interrupt.
 *
 *  @param int_en The bit map to enable/disable the interrupt.
 * 
 *  @returns void
 */

__inline void hal_lcdc_set_rdFIFO_flush_valid_int_rtl8195bhp(u8 int_en)
{

    LCDC->reg_interrupt_config_b.rxflhdatinten = int_en;
	
}

/** 
 *  @brief To get interrupt status.
 *
 *  @param none.
 * 
 *  @returns interrupt status
 */

__inline u32 hal_lcdc_get_int_status_rtl8195bhp(void)
{

	return LCDC->reg_interrupt_status;

	
}

/** 
 *  @brief To clear interrupt status.
 *
 *  @param int_bit clear the status of int_bit's interrupt.
 * 
 *  @returns void
 */

__inline void hal_lcdc_clear_int_status_rtl8195bhp(u8 int_bit)
{

	LCDC->reg_interrupt_status |= (1 << int_bit);  // write 1 to clear ISR
	
}

/** 
 *  @brief To clear all interrupt status.
 *
 *  @param none.
 * 
 *  @returns void
 */

__inline void hal_lcdc_clear_all_int_status_rtl8195bhp(void)
{

	LCDC->reg_interrupt_status = 0xFFFFFFFF;  // write 1 to clear ISR
	
}

/** 
 *  @brief To set command parameter number.
 *
 *  @param wr_num the number of write pulse -1.
 *  @param rd_num the number of read pulse -1.
 * 
 *  @returns void
 */

__inline void hal_lcdc_write_cmd_para_number_rtl8195bhp(u16 wr_num, u8 rd_num)
{

	lcdc_reg_cmd_wrrd_num_t cmd_num;	

	cmd_num.b.wrnum = wr_num;
	cmd_num.b.rdnum = rd_num;
	LCDC->reg_cmd_wrrd_num = cmd_num.w;    
	
}


/** 
 *  @brief To set the address of command parameters.
 *
 *  @param para_addr the address of command parameters.
 * 
 *  @returns void
 */

__inline void hal_lcdc_write_cmd_para_addr_rtl8195bhp(u32 para_addr)
{

	LCDC->reg_paramaddr = para_addr;

}


/** 
 *  @brief To write command register.
 *
 *  @param cmd	the command code for lcdc driver.
 *  @param cmd_type the type of this command.
 *  @param inst_cmd process command instantly or after refresh current frame.
 *  @param src_at_extmem the parameter stored at external memory.
 * 
 *  @returns void
 */

__inline void hal_lcdc_write_cmd_register_rtl8195bhp(u8 cmd, u8 cmd_type, bool inst_cmd, bool src_at_extmem)
{
	lcdc_reg_lcd_command_t mcu_cmd_ctl;

	mcu_cmd_ctl.b.cmdtype = cmd_type;
	mcu_cmd_ctl.b.instcmd = inst_cmd;	
	mcu_cmd_ctl.b.parasrc = src_at_extmem;
	mcu_cmd_ctl.b.lcdcmd = cmd;
	
    LCDC->reg_lcd_command = mcu_cmd_ctl.w;    

}


void hal_lcdc_set_resolution_rtl8195bhp(u16 image_width, u16 image_height);
void hal_lcdc_set_rgb2yuc_coef_rtl8195bhp(s16 coef[]);
void hal_lcdc_config_depth_reduction_rtl8195bhp(hal_lcdc_dep_reduction_config_t *pdep_red_config);
void hal_lcdc_set_rgb_if_rtl8195bhp(u8 if_mode, bool bRGBsyncEnable );
void hal_lcdc_set_mcu_if_rtl8195bhp(u8 if_mode, u8 sync_mode);
//void hal_lcdc_execute_mcu_cmd_rtl8195bhp(hal_lcdc_mcu_command_t *pmcu_cmd_t);
void hal_lcdc_enable_all_ints_rtl8195bhp (u8 int_en);
void hal_lcdc_config_rgb_if_rtl8195bhp(u16 dclk_div, u8 dclk_pl, u8 vs_pl, u8 hs_pl, u8 en_pl, u8 dat_pl);
void hal_lcdc_config_rgb_timing_rtl8195bhp (u8 vsw, u8 vbp, u8 vfp, u8 hsw, u8 hbp, u8 hfp, bool en_update);
void hal_lcdc_set_frame_buffer_rtl8195bhp (u32 buf0, u32 buf1, u32 buf2, u32 buf0_uv, u32 buf1_uv, u32 buf2_uv);
void hal_lcdc_read_rgbif_timing_rtl8195bhp (u8 *htiming, u8 *vtiming);
void hal_lcdc_read_interrupt_status_rtl8195bhp (u16 *raw_status, u16 *masked_status);
void hal_lcdc_config_mcu_if_pl_rtl8195bhp (    u8 cs_pl, u8 rs_pl, u8 wr_pl, u8 rd_pl, u8 data_pl, u8 vs_pl);
void hal_lcdc_config_mcu_if_te_rtl8195bhp (u8 te_pl, u16 tedelay);
void hal_lcdc_config_mcu_timing_rtl8195bhp (u16 wr_period, u8 rd_actw, u8 rd_inactw);
void hal_lcdc_config_mcu_vsync_rtl8195bhp (u8 vsw, u16 vspd);
void hal_lcdc_disable_if_rtl8195bhp (bool instant);
void hal_lcdc_read_version_rtl8195bhp (u16 *plcdc_ver, u16 *preversion);
void hal_lcdc_hwctrl_rtl8195bhp(u8 enable, bool MCUmode, bool ReduceMode);

/** @} */ /* End of group hs_hal_lcdc */

#ifdef  __cplusplus
}
#endif

#endif  // end of "#define _RTL8195BHP_LCDC_H_"

