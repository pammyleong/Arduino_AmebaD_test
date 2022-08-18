/**************************************************************************//**
 * @file      rtl8195bhp_lcdc_type.h
 * @brief
 * @version   V1.10
 * @date      2017-05-03
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

#ifndef _RTL8195BHP_LCDC_TYPE_H_
#define _RTL8195BHP_LCDC_TYPE_H_

#ifdef  __cplusplus
extern "C"
{
#endif

/// @cond DOXYGEN_LCDC_REG_TYPE

/**
 * @addtogroup hs_hal_lcdc_reg LCDC Registers.
 * @ingroup hs_hal_lcdc
 * @{
 */

/**
  * @brief LCD Controller, YUV to RGB565 , 8/9/16/18 MCU8080-I/-II I/F, 6/16/18 Parallel RGB I/F (LCDC)
  */

typedef struct {                                /*!< (@ 0x40494000) LCDC Structure                                             */
  
  union {
    __IOM uint32_t reg_imagesize;        /*!< (@ 0x00000000) Dimension of image                                         */
    
    struct {
      __IOM uint32_t imagewidth : 10;           /*!< [9..0] The width of image ( Y-channel based). IMAGEWIDTH is
                                                     a multiple of 4, and [1:0] always set to 0.                               */
      __IM  uint32_t            : 6;
      __IOM uint32_t imageheight : 10;          /*!< [25..16] The height of image ( Y-channel based ). IMAGEHEIGHT
                                                     is an even value, and the LSB for this field is always
                                                     set to 0.                                                                 */
    } reg_imagesize_b;
  } ;
  
  union {
    __IOM uint32_t reg_yuvoffset;        /*!< (@ 0x00000004) The offset for YUV to RGB                                  */
    
    struct {
      __IOM uint32_t yoffset    : 8;            /*!< [7..0] The offset of Y channel                                            */
      __IOM uint32_t cboffset   : 8;            /*!< [15..8] The offset of Cb(U)channel                                        */
      __IOM uint32_t croffset   : 8;            /*!< [23..16] The offset of Cr(V)channel                                       */
    } reg_yuvoffset_b;
  } ;
  
  union {
    __IOM uint32_t reg_covcoef1;         /*!< (@ 0x00000008) The conversion coefficients 1/5                            */
    
    struct {
      __IOM uint32_t rcoefy     : 11;           /*!< [10..0] The Y coefficient of R channel's reproduction(signed
                                                     value)                                                                    */
      __IM  uint32_t            : 5;
      __IOM uint32_t rcoefcb    : 11;           /*!< [26..16] The Cb coefficient of R channel's reproduction(signed
                                                     value)                                                                    */
    } reg_covcoef1_b;
  } ;
  
  union {
    __IOM uint32_t reg_covcoef2;         /*!< (@ 0x0000000C) The conversion coefficients 2/5                            */
    
    struct {
      __IOM uint32_t rcoefcr    : 11;           /*!< [10..0] The Cr coefficient of R channel's reproduction(signed
                                                     value)                                                                    */
      __IM  uint32_t            : 5;
      __IOM uint32_t gcoefy     : 11;           /*!< [26..16] TheY coefficient of G channel's reproduction(signed
                                                     value)                                                                    */
    } reg_covcoef2_b;
  } ;
  
  union {
    __IOM uint32_t reg_covcoef3;         /*!< (@ 0x00000010) The conversion coefficients 3/5                            */
    
    struct {
      __IOM uint32_t gcoefcb    : 11;           /*!< [10..0] The Cb coefficient of G channel's reproduction(signed
                                                     value)                                                                    */
      __IM  uint32_t            : 5;
      __IOM uint32_t gcoefcr    : 11;           /*!< [26..16] The Cr coefficient of G channel's reproduction(signed
                                                     value)                                                                    */
    } reg_covcoef3_b;
  } ;
  
  union {
    __IOM uint32_t reg_covcoef4;         /*!< (@ 0x00000014) The conversion coefficients 4/5                            */
    
    struct {
      __IOM uint32_t bcoefy     : 11;           /*!< [10..0] The Y coefficient of B channel's reproduction(signed
                                                     value)                                                                    */
      __IM  uint32_t            : 5;
      __IOM uint32_t bcoefcb    : 11;           /*!< [26..16] The Cb coefficient of B channel's reproduction(signed
                                                     value)                                                                    */
    } reg_covcoef4_b;
  } ;
  
  union {
    __IOM uint32_t reg_covcoef5;         /*!< (@ 0x00000018) The conversion coefficients 5/5                            */
    
    struct {
      __IOM uint32_t bcoefcr    : 11;           /*!< [10..0] The Cr coefficient of B channel's reproduction(signed
                                                     value)                                                                    */
    } reg_covcoef5_b;
  } ;
  
  union {
    __IOM uint32_t reg_dtreduction_ctl;  /*!< (@ 0x0000001C) The control of depth reduction                             */
    
    struct {
      __IOM uint32_t enround    : 1;            /*!< [0..0] Enable rounding process when reducing depth                        */
      __IOM uint32_t endither   : 1;            /*!< [1..1] Enable 1D dithering                                                */
      __IOM uint32_t gainbit    : 2;            /*!< [3..2] Digital gain. 00: 1x, 01: 2x, 10: 4x, Others: Reserved             */
      __IOM uint32_t dilinerst  : 1;            /*!< [4..4] Reset dithering error when new line start                          */
    } reg_dtreduction_ctl_b;
  } ;
  
  union {
    __IOM uint32_t reg_interface_ctl;    /*!< (@ 0x00000020) The control of output interface                            */
    
    struct {
      __IOM uint32_t interfacemode : 5;         /*!< [4..0] 00000: 8-bit MCU 8080-I 00001: 8-bit MCU 8080-II 00010:
                                                     9-bit MCU 8080-I 00011: 9-bit MCU 8080-II 00100: 16-bit
                                                     MCU 8080-I 00101: 16-bit MCU 8080-II 00110: 18-bit MCU
                                                     8080-I 00111: 18-bit MCU 8080-II 01000: 6-bit RGB parallel
                                                     I/F 01001: 16-bit RGB parallel I/F Others: Reserved                       */
      __IOM uint32_t rgbifsyncmode : 2;         /*!< [6..5] 00 : synchronized with ENABLE signal                               */
      __IM  uint32_t            : 1;
      __IOM uint32_t mcuifmode  : 2;            /*!< [9..8] 00 : synchronized with panel internal clock                        */
    } reg_interface_ctl_b;
  } ;
  
  union {
    __IOM uint32_t reg_lcd_command;      /*!< (@ 0x00000024) The command to LCD driver                                  */
    
    struct {
      __IOM uint32_t lcdcmd     : 8;            /*!< [7..0] The command to LCD driver, writing register trigger command
                                                     process.                                                                  */
      __IOM uint32_t cmdtype    : 2;            /*!< [9..8] The command type. 00 = The command will only write parameters
                                                     to LCD 01 = This command will read data back or can write
                                                     parameters and read data back. 10 = This command will write
                                                     frame data continuously. Others: same as 0x00.                            */
      __IOM uint32_t instcmd    : 1;            /*!< [10..10] 0: process command after current refresh frame done.
                                                     1: process command instantly.                                             */
      __IOM uint32_t parasrc    : 1;            /*!< [11..11] 0: the parameters of command were stored at DMA FIFO
                                                     1: the parameters of command were stored at PARAADDRFor
                                                     both cases, placed the parameters from LSB to MSB in sequence.This
                                                     is only valid for CMDTYPE = 00 or 01                                      */
      __IM  uint32_t            : 18;
      __IM  uint32_t cmdresult  : 1;            /*!< [30..30] 0: process command successfully1: process command failed
                                                     (reserved)                                                                */
      __IM  uint32_t commandbusy : 1;           /*!< [31..31] Declare IP had a command to be processed                         */
    } reg_lcd_command_b;
  } ;
  
  union {
    __IOM uint32_t reg_cmd_wrrd_num;     /*!< (@ 0x00000028) The WR/RD pulse number of CMD                              */
    
    struct {
      __IOM uint32_t wrnum      : 10;           /*!< [9..0] The number of write pulse -1, these pulses generated
                                                     before RD pulse. When PARASRC is DMA FIFO, the max value
                                                     of WRNUM is 1020. This is invalid for CMDTYPE = 10.                     */
      __IM  uint32_t            : 6;
      __IOM uint32_t rdnum      : 4;            /*!< [19..16] The number of read pulse-1, these pulses generated
                                                     after WR pulse. This is only valid for CMDTYPE = 01                       */
    } reg_cmd_wrrd_num_b;
  } ;
  
  union {
    __IOM uint32_t reg_paramaddr;        /*!< (@ 0x0000002C) The start address of CMD parameters                        */
    
    struct {
      __IOM uint32_t paraaddr   : 32;           /*!< [31..0] The start address of command parameters. Placed the
                                                     parameters from LSB to MSB in sequence. The first one place
                                                     at LSB and the fourth at MSB. This is only valid for CMDTYPE
                                                     = 00 or 01. [5:0] always set to 0 and is unaffected by
                                                     a write operation,                                                        */
    } reg_paramaddr_b;
  } ;
  
  union {
    __IOM uint32_t reg_frbuffer0;        /*!< (@ 0x00000030) The start address of frame buffer0                         */
    
    struct {
      __IOM uint32_t frbuff0    : 32;           /*!< [31..0] The start address of frame buffer 0. [5:0] always set
                                                     to 0 and is unaffected by a write operation,                              */
    } reg_frbuffer0_b;
  } ;
  
  union {
    __IOM uint32_t reg_frbuffer1;        /*!< (@ 0x00000034) The start address of frame buffer1                         */
    
    struct {
      __IOM uint32_t frbuff1    : 32;           /*!< [31..0] The start address of frame buffer 1. [5:0] always set
                                                     to 0 and is unaffected by a write operation,                              */
    } reg_frbuffer1_b;
  } ;
  
  union {
    __IOM uint32_t reg_frbuffer2;        /*!< (@ 0x00000038) The start address of frame buffer1                         */
    
    struct {
      __IOM uint32_t frbuff2    : 32;           /*!< [31..0] The start address of frame buffer 2. [5:0] always set
                                                     to 0 and is unaffected by a write operation,                              */
    } reg_frbuffer2_b;
  } ;
  
  union {
    __IOM uint32_t reg_frtrans_dma_config;/*!< (@ 0x0000003C) The configuration of frame transfer and DMA               */
    
    struct {
      __IOM uint32_t ispfirstwr : 1;            /*!< [0..0] 0: ISP is not writing the first frame. 1: ISP is writing
                                                     the first frame, all 3 buffers are not available. This
                                                     register is only valid just at the moment of starting frame
                                                     transfer. ( RGB I/F: set LCDCEN register ; MCU I/F: write
                                                     LCDCMD register )                                                         */
      __IOM uint32_t rdotst     : 3;            /*!< [3..1] The value of read outstanding -1                                   */
      __IM  uint32_t bufid      : 2;            /*!< [5..4] Indicate the buffer ID DMA is fetching data( for debug)            */
      __IM  uint32_t yuvfmt     : 1;            /*!< [6..6] Indicate the yuv format configuration of current design
                                                     0: YUV422 semi-planar (NV16) 1: YUV422 interleaved (YUY2)                 */
      __IM  uint32_t            : 1;
      __IM  uint32_t dmaintv    : 24;           /*!< [31..8] The interval cycle count between two DMA requests. Unit:
                                                     bus clock cycle.( for debug)                                              */
    } reg_frtrans_dma_config_b;
  } ;
  
  union {
    __IOM uint32_t reg_interrupt_config; /*!< (@ 0x00000040) The configuration of interrupts                            */
    
    struct {
      __IOM uint32_t dmauninten : 1;            /*!< [0..0] DMA FIFO underflow interrupt enable                                */
      __IOM uint32_t paraovinten : 1;           /*!< [1..1] Parameters overflow interrupt enable                               */
      __IOM uint32_t cmdeinten  : 1;            /*!< [2..2] Command done interrupt enable                                      */
      __IOM uint32_t lcdfrdinten : 1;           /*!< [3..3] LCD refresh frame done interrupt enable                            */
      __IOM uint32_t rxuninten  : 1;            /*!< [4..4] Receive FIFO underflow interrupt enable                            */
      __IOM uint32_t parauninten : 1;           /*!< [5..5] Parameters underflow interrupt enable                              */
      __IOM uint32_t rxflhdatinten : 1;         /*!< [6..6] RX FIFO flush valid data interrupt enable                          */
      __IM  uint32_t            : 9;
      __IM  uint32_t dmaunintcnt : 8;           /*!< [23..16] DMA FIFO underflow interrupt count                               */
    } reg_interrupt_config_b;
  } ;
  
  union {
    __IOM uint32_t reg_err_handle;       /*!< (@ 0x00000044) The registers for error handling                           */
    
    struct {
      __IOM uint32_t erroutdata : 16;           /*!< [15..0] Output data when DMA FIFO underflow occurred. ( directly
                                                     mapping to output D[15:0] )                                               */
      __IOM uint32_t dmaunmode  : 1;            /*!< [16..16] 0: output last data, 1: output ERROUTDATA.                       */
    } reg_err_handle_b;
  } ;
  
  union {
    __IOM uint32_t reg_rgbif_config;     /*!< (@ 0x00000048) The configuration of RGB Interface                         */
    
    struct {
      __IOM uint32_t clkdiv     : 10;           /*!< [9..0] DCLK clock divider. The LSB for this field is always
                                                     set to 0 and is unaffected by a write operation, which
                                                     ensures an even value is held in this register. The frequency
                                                     of SCLK is derived from the following equation: DCLK =
                                                     SYS_Clk/( CLKDIV +2) where CLKDIV is any even value between
                                                     0 and 1022.                                                               */
      __IM  uint32_t            : 6;
      __IOM uint32_t dclkpl     : 1;            /*!< [16..16] The polarity of the DCLK active edge. 0 = data fetched
                                                     at DCLK rising edge, 1 = data fetched at DCLK falling edge.               */
      __IOM uint32_t vspl       : 1;            /*!< [17..17] The VSYNC pulse polarity. 0 = Low level sync clock,
                                                     1 = High level sync clock.                                                */
      __IOM uint32_t hspl       : 1;            /*!< [18..18] The HSYNC pulse polarity. 0 = Low level sync clock,
                                                     1 = High level sync clock.                                                */
      __IOM uint32_t enpl       : 1;            /*!< [19..19] The ENABLE pulse polarity. 0 = Low level for active
                                                     data, 1 = High level for active data.                                     */
      __IOM uint32_t datpl      : 1;            /*!< [20..20] The Data pulse polarity. 0 = Normal, 1 = Inverted                */
    } reg_rgbif_config_b;
  } ;
  
  union {
    __IOM uint32_t reg_vsync_timing;     /*!< (@ 0x0000004C) The configuration of vsync timing                          */
    
    struct {
      __IOM uint32_t vsw        : 4;            /*!< [3..0] Vertical sync signal width -1. Unit: inactive lines                */
      __IM  uint32_t            : 4;
      __IOM uint32_t vbp        : 4;            /*!< [11..8] Back porch line number-1. The number of inactive lines
                                                     at the start of a frame, after vertical synchronization
                                                     period.                                                                   */
      __IM  uint32_t            : 4;
      __IOM uint32_t vfp        : 4;            /*!< [19..16] Front porch line number-1. The number of inactive lines
                                                     at the end of a frame, before vertical synchronization
                                                     period.                                                                   */
      __IM  uint32_t            : 4;
      __IOM uint32_t rgbifupdate : 1;           /*!< [24..24] Force HW updates RGB I/F Timing shadow register at
                                                     starting of VSYNC pulse. CPU writes 1 to force HW updating.
                                                     After updated, HW cleared this bit.                                       */
    } reg_vsync_timing_b;
  } ;
  
  union {
    __IOM uint32_t reg_hsync_timing;     /*!< (@ 0x00000050) The configuration of hsync timing                          */
    
    struct {
      __IOM uint32_t hsw        : 8;            /*!< [7..0] Horizontal sync signal width -1. Unit: DCLK                        */
      __IOM uint32_t hbp        : 8;            /*!< [15..8] Horizontal back porch -1. The number of DCLK periods
                                                     between the falling edge of HSYNC and the start of active
                                                     data.                                                                     */
      __IOM uint32_t hfp        : 8;            /*!< [23..16] Horizontal front porch -1. The number of DCLK periods
                                                     between the end of active data and the rising edge of HSYNC.              */
    } reg_hsync_timing_b;
  } ;
  
  union {
    __IM  uint32_t reg_sync_status;      /*!< (@ 0x00000054) The status of H/V sync                                     */
    
    struct {
      __IM  uint32_t vsstatus   : 2;            /*!< [1..0] VSYNC Status : 00 = VSYNC, 01 = VBP, 11 = ACTIVE, 10
                                                     = VFP                                                                     */
      __IM  uint32_t hsstatus   : 2;            /*!< [3..2] HSYNC Status : 00 = HSYNC, 01 = HBP, 11 = ACTIVE, 10
                                                     = HFP                                                                     */
    } reg_sync_status_b;
  } ;
  
  union {
    __OM  uint32_t reg_dmadata;          /*!< (@ 0x00000058) The data register of DMA buffer                            */
    
    struct {
      __OM  uint32_t dmadr      : 32;           /*!< [31..0] DMA FIFO buffer register. When writing to this register,
                                                     you must right-justify the data.                                          */
    } reg_dmadata_b;
  } ;
  
  union {
    __IM  uint32_t reg_rxdata;           /*!< (@ 0x0000005C) The data register of RX buffer                             */
    
    struct {
      __IM  uint32_t rxdr       : 32;           /*!< [31..0] Receive FIFO buffer register. Read data are automatically
                                                     right-justified.                                                          */
    } reg_rxdata_b;
  } ;
  
  union {
    __IOM uint32_t reg_interrupt_status; /*!< (@ 0x00000060) The status of LCDC interrupt                               */
    
    struct {
      __IOM uint32_t dmaunints  : 1;            /*!< [0..0] DMA FIFO underflow interrupt status. Write 1 to clear
                                                     it. 0: No DMA FIFO underflow interrupt generated, 1: this
                                                     interrupt generated, when DMA FIFO underflow.                             */
      __IOM uint32_t paraovints : 1;            /*!< [1..1] Parameters overflow interrupt status. Write 1 to clear
                                                     it. 0: No parameters overflow interrupt generated, 1: this
                                                     interrupt generated, when parameters overflow: ( (write_pulse_num
                                                     + 3 ) >>2) < SW_write32breg_times                                         */
      __IOM uint32_t cmdeints   : 1;            /*!< [2..2] Command done interrupt status. Write 1 to clear it. 0:
                                                     No Command done interrupt generated, 1: this interrupt
                                                     generated, when Command processed done.                                   */
      __IOM uint32_t lcdfrdints : 1;            /*!< [3..3] LCD refresh frame done interrupt status. Write 1 to clear
                                                     it. 0: No LCD refresh frame done interrupt generated, 1:
                                                     this interrupt generated, when sending LCD frame done.                    */
      __IOM uint32_t rxunints   : 1;            /*!< [4..4] Receive FIFO underflow interrupt status. This interrupt
                                                     happened when ((RXFIFO_valid_byte + 3 ) >>2) < SW_read32bits_times.
                                                     Write 1 to clear this interrupt. 0 : RXUNINT interrupt
                                                     is not active after masking, 1 : RXUNINT interrupt is active
                                                     after masking                                                             */
      __IOM uint32_t paraunints : 1;            /*!< [5..5] Parameters underflow interrupt status. Write 1 to clear
                                                     it. 0: No parameters underflow interrupt generated, 1:
                                                     this interrupt generated, when parameters underflow: (
                                                     (write_pulse_num + 3 ) >>2) > SW_write32breg_times.                       */
      __IOM uint32_t rxflhdatints : 1;          /*!< [6..6] RX FIFO flush valid data interrupt status. This interrupt
                                                     happened when flushing RX FIFO that was still not empty.
                                                     Write 1 to clear this interrupt. 0 : RXFLHDATINT interrupt
                                                     is not active after masking, 1 : RXFLHDATINT interrupt
                                                     is active after masking                                                   */
      __IM  uint32_t            : 9;
      __IM  uint32_t dmaunintrs : 1;            /*!< [16..16] DMA FIFO underflow raw interrupt status ( wasn't impacted
                                                     by enable bit)                                                            */
      __IM  uint32_t paraovintrs : 1;           /*!< [17..17] Parameters overflow raw interrupt status ( wasn't impacted
                                                     by enable bit)                                                            */
      __IM  uint32_t cmdeintrs  : 1;            /*!< [18..18] Command done raw interrupt status. ( wasn't impacted
                                                     by enable bit)                                                            */
      __IM  uint32_t lcdfrdintrs : 1;           /*!< [19..19] LCD refresh frame done raw interrupt status. ( wasn't
                                                     impacted by enable bit)                                                   */
      __IM  uint32_t rxunintrs  : 1;            /*!< [20..20] Receive FIFO underflow raw interrupt status. ( wasn't
                                                     impacted by enable bit)                                                   */
      __IM  uint32_t paraunintrs : 1;           /*!< [21..21] Parameters underflow raw interrupt status. ( wasn't
                                                     impacted by enable bit)                                                   */
      __IM  uint32_t rxflhdatintrs : 1;         /*!< [22..22] RX FIFO flush valid data raw interrupt status. ( wasn't
                                                     impacted by enable bit)                                                   */
    } reg_interrupt_status_b;
  } ;
  
  union {
    __IOM uint32_t reg_mcuif_config;     /*!< (@ 0x00000064) The MCU I/F configuration                                  */
    
    struct {
      __IOM uint32_t cspl       : 1;            /*!< [0..0] The CS pulse polarity. 0 = Low level for active pulse,
                                                     1 = High level for active pulse.                                          */
      __IOM uint32_t rspl       : 1;            /*!< [1..1] The RS pulse polarity. 0 = Low level for command address,
                                                     1 = High level for command address.                                       */
      __IOM uint32_t wrpl       : 1;            /*!< [2..2] The WR pulse polarity. 0 = Low level for active pulse,
                                                     1 = High level for active pulse.                                          */
      __IOM uint32_t rdpl       : 1;            /*!< [3..3] The RD pulse polarity. 0 = Low level for active pulse,
                                                     1 = High level for active pulse.                                          */
      __IOM uint32_t datapl     : 1;            /*!< [4..4] The Data pulse polarity. 0 = Normal, 1 = Inverted                  */
      __IOM uint32_t tepl       : 1;            /*!< [5..5] The TE pulse polarity. 0 = Low level for active pulse,
                                                     1 = High level for active pulse.                                          */
      __IOM uint32_t mcusypl    : 1;            /*!< [6..6] The MCU VSYNC pulse polarity. 0 = Low level for active
                                                     pulse, 1 = High level for active pulse.                                   */
      __IM  uint32_t            : 1;
      __IOM uint32_t mcuifupdate : 1;           /*!< [8..8] Force HW updates MCU I/F Timing shadow register at specific
                                                     timing. CPU writes 1 to force HW updating. After updated,
                                                     HW cleared this bit.                                                      */
      __IM  uint32_t            : 7;
      __IOM uint32_t tedelay    : 16;           /*!< [31..16] The delay interval -45. This interval is from detected
                                                     TE signal to starting frame transfer. Unit: WR pulse width
                                                     The maximum value is 6553265531 The real delay interval
                                                     could be TEDELAY+5 or TEDELAY+6                                           */
    } reg_mcuif_config_b;
  } ;
  
  union {
    __IOM uint32_t reg_mcuif_vsync_cfg;  /*!< (@ 0x00000068) The MCU I/F Vsync Mode Configuration                       */
    
    struct {
      __IOM uint32_t mcuvsw     : 8;            /*!< [7..0] VSYNC signal width-1. Unit: WRPERIOD (only for MCU VSYNC
                                                     mode)                                                                     */
      __IM  uint32_t            : 8;
      __IOM uint32_t mcuvspd    : 16;           /*!< [31..16] MCUIFMODE = 1 :VSYNC idle period. This value equals
                                                     to VSYNC period-IMAGEWIDTH * IMAGEHEIGHT * WR_pulse_per_pixel-5.Unit:
                                                     WR pulse width MCUIFMODE = 0: The buffer time between frames.
                                                     This value equals to the time of a frame's end to the next's
                                                     start -5. Unit: WR pulse width MCUIFMODE = 2 : invalid
                                                     usage The maximum value is 65531                                          */
    } reg_mcuif_vsync_cfg_b;
  } ;
  
  union {
    __IOM uint32_t reg_mcuif_timing1;    /*!< (@ 0x0000006C) The MCU I/F Timing 1                                       */
    
    struct {
      __IOM uint32_t wrperiod   : 10;           /*!< [9..0] WR pulse width-2. The LSB for this field is always set
                                                     to 0 and is unaffected by a write operation, which ensures
                                                     an even value is held in this register. The minimum limitation
                                                     of WR pulse width is 4. Unit: SYS_Clk                                     */
      __IM  uint32_t            : 6;
      __IOM uint32_t rdactw     : 8;            /*!< [23..16] RD active pulse width -1. Unit: WRPERIOD                         */
      __IOM uint32_t rdinactw   : 8;            /*!< [31..24] RD inactive pulse width -1. Unit: WRPERIOD                       */
    } reg_mcuif_timing1_b;
  } ;
  
  union {
    __IOM uint32_t reg_basic_ctl;        /*!< (@ 0x00000070) The basic control of LCDC                                  */
    
    struct {
      __IOM uint32_t lcdcen     : 1;            /*!< [0..0] Enable LCDC                                                        */
      __IOM uint32_t lcdcdis    : 1;            /*!< [1..1] During the period of valid line(VTIMING =valid data),
                                                     this disable action will be performed after the last valid
                                                     line had transferred.                                                     */
      __IOM uint32_t lcdcinsdis : 1;            /*!< [2..2] Disable LCDC instantly. HW will reset LCDC internal states
                                                     and disable LCDC then clear both this bit and LCDCEN.                     */
    } reg_basic_ctl_b;
  } ;
  
  union {
    __IOM uint32_t reg_mbist_ctl;        /*!< (@ 0x00000074) The registers of MBIST                                     */
    
    struct {
      __IM  uint32_t            : 1;
      __IOM uint32_t bist_mode  : 1;            /*!< [1..1] MBIST                                                              */
      __IOM uint32_t drf_bist_mode : 1;         /*!< [2..2] MBIST                                                              */
      __IOM uint32_t drf_test_resume : 1;       /*!< [3..3] MBIST                                                              */
      __IOM uint32_t bist_rstn  : 1;            /*!< [4..4] MBIST                                                              */
      __IOM uint32_t bist_pd_0  : 1;            /*!< [5..5] MBIST                                                              */
      __IM  uint32_t            : 2;
      __IM  uint32_t drf_bist_done : 1;         /*!< [8..8] MBIST                                                              */
      __IM  uint32_t drf_bist_fail_0 : 1;       /*!< [9..9] MBIST                                                              */
      __IM  uint32_t drf_start_pause : 1;       /*!< [10..10] MBIST                                                            */
      __IM  uint32_t bist_done  : 1;            /*!< [11..11] MBIST                                                            */
      __IM  uint32_t bist_fail_0 : 1;           /*!< [12..12] MBIST                                                            */
    } reg_mbist_ctl_b;
  } ;
  
  union {
    __IM  uint32_t reg_version;          /*!< (@ 0x00000078) The version of LCDC H/W                                    */
    
    struct {
      __IM  uint32_t version    : 16;           /*!< [15..0] H/W version, 0x300 means version 3                                */
      __IM  uint32_t reversion  : 16;           /*!< [31..16] H/W reversion                                                    */
    } reg_version_b;
  } ;
  
  union {
    __IOM uint32_t reg_uvfrbuffer0;      /*!< (@ 0x0000007C) The start address of frame buffer0                         */
    
    struct {
      __IOM uint32_t uvfrbuff0  : 32;           /*!< [31..0] The start address of UV frame buffer 0. [5:0] always
                                                     set to 0 and is unaffected by a write operation. This register
                                                     is invalid when YUVFMT =1.                                                */
    } reg_uvfrbuffer0_b;
  } ;
  
  union {
    __IOM uint32_t reg_uvfrbuffer1;      /*!< (@ 0x00000080) The start address of frame buffer1                         */
    
    struct {
      __IOM uint32_t uvfrbuff1  : 32;           /*!< [31..0] The start address of UV frame buffer 1. [5:0] always
                                                     set to 0 and is unaffected by a write operation. This register
                                                     is invalid when YUVFMT =1.                                                */
    } reg_uvfrbuffer1_b;
  } ;
  
  union {
    __IOM uint32_t reg_uvfrbuffer2;      /*!< (@ 0x00000084) The start address of frame buffer1                         */
    
    struct {
      __IOM uint32_t uvfrbuff2  : 32;           /*!< [31..0] The start address of UV frame buffer 2. [5:0] always
                                                     set to 0 and is unaffected by a write operation. This register
                                                     is invalid when YUVFMT =1.                                                */
    } reg_uvfrbuffer2_b;
  } ;
} LCDC_Type;                                    /*!< Size = 136 (0x88)                                                         */


/** @} */ /* End of group Device_Peripheral_peripherals */


/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripheralAddr
  * @{
  */

#define LCDC_BASE                   0x40494000UL

/** @} */ /* End of group Device_Peripheral_peripheralAddr */


/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_declaration
  * @{
  */

#define LCDC                        ((LCDC_Type*)              LCDC_BASE)

/** @} */ /* End of group Device_Peripheral_declaration */



/**
  \brief Union type to access lcdc_reg_imagesize (@ 0x00000000).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000000) Dimension of image                                         */
  
  struct {
    __IOM uint32_t imagewidth : 10;           /*!< [9..0] The width of image ( Y-channel based). IMAGEWIDTH is
                                                   a multiple of 4, and [1:0] always set to 0.                               */
    __IM  uint32_t            : 6;
    __IOM uint32_t imageheight : 10;          /*!< [25..16] The height of image ( Y-channel based ). IMAGEHEIGHT
                                                   is an even value, and the LSB for this field is always
                                                   set to 0.                                                                 */
  } b;
} lcdc_reg_imagesize_t, *plcdc_reg_imagesize_t;

/**
  \brief Union type to access lcdc_reg_yuvoffset (@ 0x00000004).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000004) The offset for YUV to RGB                                  */
  
  struct {
    __IOM uint32_t yoffset    : 8;            /*!< [7..0] The offset of Y channel                                            */
    __IOM uint32_t cboffset   : 8;            /*!< [15..8] The offset of Cb(U)channel                                        */
    __IOM uint32_t croffset   : 8;            /*!< [23..16] The offset of Cr(V)channel                                       */
  } b;
} lcdc_reg_yuvoffset_t, *plcdc_reg_yuvoffset_t;

/**
  \brief Union type to access lcdc_reg_covcoef1 (@ 0x00000008).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000008) The conversion coefficients 1/5                            */
  
  struct {
    __IOM uint32_t rcoefy     : 11;           /*!< [10..0] The Y coefficient of R channel's reproduction(signed
                                                   value)                                                                    */
    __IM  uint32_t            : 5;
    __IOM uint32_t rcoefcb    : 11;           /*!< [26..16] The Cb coefficient of R channel's reproduction(signed
                                                   value)                                                                    */
  } b;
} lcdc_reg_covcoef1_t, *plcdc_reg_covcoef1_t;

/**
  \brief Union type to access lcdc_reg_covcoef2 (@ 0x0000000C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000000C) The conversion coefficients 2/5                            */
  
  struct {
    __IOM uint32_t rcoefcr    : 11;           /*!< [10..0] The Cr coefficient of R channel's reproduction(signed
                                                   value)                                                                    */
    __IM  uint32_t            : 5;
    __IOM uint32_t gcoefy     : 11;           /*!< [26..16] TheY coefficient of G channel's reproduction(signed
                                                   value)                                                                    */
  } b;
} lcdc_reg_covcoef2_t, *plcdc_reg_covcoef2_t;

/**
  \brief Union type to access lcdc_reg_covcoef3 (@ 0x00000010).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000010) The conversion coefficients 3/5                            */
  
  struct {
    __IOM uint32_t gcoefcb    : 11;           /*!< [10..0] The Cb coefficient of G channel's reproduction(signed
                                                   value)                                                                    */
    __IM  uint32_t            : 5;
    __IOM uint32_t gcoefcr    : 11;           /*!< [26..16] The Cr coefficient of G channel's reproduction(signed
                                                   value)                                                                    */
  } b;
} lcdc_reg_covcoef3_t, *plcdc_reg_covcoef3_t;

/**
  \brief Union type to access lcdc_reg_covcoef4 (@ 0x00000014).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000014) The conversion coefficients 4/5                            */
  
  struct {
    __IOM uint32_t bcoefy     : 11;           /*!< [10..0] The Y coefficient of B channel's reproduction(signed
                                                   value)                                                                    */
    __IM  uint32_t            : 5;
    __IOM uint32_t bcoefcb    : 11;           /*!< [26..16] The Cb coefficient of B channel's reproduction(signed
                                                   value)                                                                    */
  } b;
} lcdc_reg_covcoef4_t, *plcdc_reg_covcoef4_t;

/**
  \brief Union type to access lcdc_reg_covcoef5 (@ 0x00000018).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000018) The conversion coefficients 5/5                            */
  
  struct {
    __IOM uint32_t bcoefcr    : 11;           /*!< [10..0] The Cr coefficient of B channel's reproduction(signed
                                                   value)                                                                    */
  } b;
} lcdc_reg_covcoef5_t, *plcdc_reg_covcoef5_t;

/**
  \brief Union type to access lcdc_reg_dtreduction_ctl (@ 0x0000001C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000001C) The control of depth reduction                             */
  
  struct {
    __IOM uint32_t enround    : 1;            /*!< [0..0] Enable rounding process when reducing depth                        */
    __IOM uint32_t endither   : 1;            /*!< [1..1] Enable 1D dithering                                                */
    __IOM uint32_t gainbit    : 2;            /*!< [3..2] Digital gain. 00: 1x, 01: 2x, 10: 4x, Others: Reserved             */
    __IOM uint32_t dilinerst  : 1;            /*!< [4..4] Reset dithering error when new line start                          */
  } b;
} lcdc_reg_dtreduction_ctl_t, *plcdc_reg_dtreduction_ctl_t;

/**
  \brief Union type to access lcdc_reg_interface_ctl (@ 0x00000020).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000020) The control of output interface                            */
  
  struct {
    __IOM uint32_t interfacemode : 5;         /*!< [4..0] 00000: 8-bit MCU 8080-I 00001: 8-bit MCU 8080-II 00010:
                                                   9-bit MCU 8080-I 00011: 9-bit MCU 8080-II 00100: 16-bit
                                                   MCU 8080-I 00101: 16-bit MCU 8080-II 00110: 18-bit MCU
                                                   8080-I 00111: 18-bit MCU 8080-II 01000: 6-bit RGB parallel
                                                   I/F 01001: 16-bit RGB parallel I/F Others: Reserved                       */
    __IOM uint32_t rgbifsyncmode : 2;         /*!< [6..5] 00 : synchronized with ENABLE signal                               */
    __IM  uint32_t            : 1;
    __IOM uint32_t mcuifmode  : 2;            /*!< [9..8] 00 : synchronized with panel internal clock                        */
  } b;
} lcdc_reg_interface_ctl_t, *plcdc_reg_interface_ctl_t;

/**
  \brief Union type to access lcdc_reg_lcd_command (@ 0x00000024).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000024) The command to LCD driver                                  */
  
  struct {
    __IOM uint32_t lcdcmd     : 8;            /*!< [7..0] The command to LCD driver, writing register trigger command
                                                   process.                                                                  */
    __IOM uint32_t cmdtype    : 2;            /*!< [9..8] The command type. 00 = The command will only write parameters
                                                   to LCD 01 = This command will read data back or can write
                                                   parameters and read data back. 10 = This command will write
                                                   frame data continuously. Others: same as 0x00.                            */
    __IOM uint32_t instcmd    : 1;            /*!< [10..10] 0: process command after current refresh frame done.
                                                   1: process command instantly.                                             */
    __IOM uint32_t parasrc    : 1;            /*!< [11..11] 0: the parameters of command were stored at DMA FIFO
                                                   1: the parameters of command were stored at PARAADDRFor
                                                   both cases, placed the parameters from LSB to MSB in sequence.This
                                                   is only valid for CMDTYPE = 00 or 01                                      */
    __IM  uint32_t            : 18;
    __IM  uint32_t cmdresult  : 1;            /*!< [30..30] 0: process command successfully1: process command failed
                                                   (reserved)                                                                */
    __IM  uint32_t commandbusy : 1;           /*!< [31..31] Declare IP had a command to be processed                         */
  } b;
} lcdc_reg_lcd_command_t, *plcdc_reg_lcd_command_t;

/**
  \brief Union type to access lcdc_reg_cmd_wrrd_num (@ 0x00000028).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000028) The WR/RD pulse number of CMD                              */
  
  struct {
    __IOM uint32_t wrnum      : 10;           /*!< [9..0] The number of write pulse -1, these pulses generated
                                                   before RD pulse. When writing frame command, set this register
                                                   as 0 and the WR pulses for frame data was determined by
                                                   image dimension. When PARASRC is DMA FIFO, the max value
                                                   of WRNUM is 1020. This is invalid for CMDTYPE = 10 HW will
                                                   generate WR pulses and send equivalent data according to
                                                   WRNUM information and the count of writing DMAFIFO will
                                                   not impact the number of WR pulses and data sending.                      */
    __IM  uint32_t            : 6;
    __IOM uint32_t rdnum      : 4;            /*!< [19..16] The number of read pulse-1, these pulses generated
                                                   after WR pulse. This is only valid for CMDTYPE = 01                       */
  } b;
} lcdc_reg_cmd_wrrd_num_t, *plcdc_reg_cmd_wrrd_num_t;

/**
  \brief Union type to access lcdc_reg_paramaddr (@ 0x0000002C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000002C) The start address of CMD parameters                        */
  
  struct {
    __IOM uint32_t paraaddr   : 32;           /*!< [31..0] The start address of command parameters. Placed the
                                                   parameters from LSB to MSB in sequence. The first one place
                                                   at LSB and the fourth at MSB. This is only valid for CMDTYPE
                                                   = 00 or 01. [5:0] always set to 0 and is unaffected by
                                                   a write operation,                                                        */
  } b;
} lcdc_reg_paramaddr_t, *plcdc_reg_paramaddr_t;

/**
  \brief Union type to access lcdc_reg_frbuffer0 (@ 0x00000030).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000030) The start address of frame buffer0                         */
  
  struct {
    __IOM uint32_t frbuff0    : 32;           /*!< [31..0] The start address of frame buffer 0. [5:0] always set
                                                   to 0 and is unaffected by a write operation,                              */
  } b;
} lcdc_reg_frbuffer0_t, *plcdc_reg_frbuffer0_t;

/**
  \brief Union type to access lcdc_reg_frbuffer1 (@ 0x00000034).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000034) The start address of frame buffer1                         */
  
  struct {
    __IOM uint32_t frbuff1    : 32;           /*!< [31..0] The start address of frame buffer 1. [5:0] always set
                                                   to 0 and is unaffected by a write operation,                              */
  } b;
} lcdc_reg_frbuffer1_t, *plcdc_reg_frbuffer1_t;

/**
  \brief Union type to access lcdc_reg_frbuffer2 (@ 0x00000038).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000038) The start address of frame buffer1                         */
  
  struct {
    __IOM uint32_t frbuff2    : 32;           /*!< [31..0] The start address of frame buffer 2. [5:0] always set
                                                   to 0 and is unaffected by a write operation,                              */
  } b;
} lcdc_reg_frbuffer2_t, *plcdc_reg_frbuffer2_t;

/**
  \brief Union type to access lcdc_reg_frtrans_dma_config (@ 0x0000003C).
*/
typedef union {
  __IOM uint32_t reg_frtrans_dma_config;                                /*!< (@ 0x0000003C) The configuration of frame transfer and DMA               */
  
  struct {
    __IOM uint32_t ispfirstwr : 1;            /*!< [0..0] 0: ISP is not writing the first frame. 1: ISP is writing
                                                   the first frame, all 3 buffers are not available. This
                                                   register is only valid just at the moment of starting frame
                                                   transfer. ( RGB I/F: set LCDCEN register ; MCU I/F: write
                                                   LCDCMD register )                                                         */
    __IOM uint32_t rdotst     : 3;            /*!< [3..1] The value of read outstanding -1                                   */
    __IM  uint32_t bufid      : 2;            /*!< [5..4] Indicate the buffer ID DMA is fetching data( for debug)            */
    __IM  uint32_t yuvfmt     : 1;            /*!< [6..6] Indicate the yuv format configuration of current design
                                                   0: YUV422 semi-planar (NV16) 1: YUV422 interleaved (YUY2)                 */
    __IM  uint32_t            : 1;
    __IM  uint32_t dmaintv    : 24;           /*!< [31..8] The interval cycle count between two DMA requests. Unit:
                                                   bus clock cycle.( for debug)                                              */
  } b;
} lcdc_reg_frtrans_dma_config, *plcdc_reg_frtrans_dma_config;

/**
  \brief Union type to access lcdc_reg_interrupt_config (@ 0x00000040).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000040) The configuration of interrupts                            */
  
  struct {
    __IOM uint32_t dmauninten : 1;            /*!< [0..0] DMA FIFO underflow interrupt enable                                */
    __IOM uint32_t paraovinten : 1;           /*!< [1..1] Parameters overflow interrupt enable                               */
    __IOM uint32_t cmdeinten  : 1;            /*!< [2..2] Command done interrupt enable                                      */
    __IOM uint32_t lcdfrdinten : 1;           /*!< [3..3] LCD refresh frame done interrupt enable                            */
    __IOM uint32_t rxuninten  : 1;            /*!< [4..4] Receive FIFO underflow interrupt enable                            */
    __IOM uint32_t parauninten : 1;           /*!< [5..5] Parameters underflow interrupt enable                              */
    __IOM uint32_t rxflhdatinten : 1;         /*!< [6..6] RX FIFO flush valid data interrupt enable                          */
    __IM  uint32_t            : 9;
    __IM  uint32_t dmaunintcnt : 8;           /*!< [23..16] DMA FIFO underflow interrupt count                               */
  } b;
} lcdc_reg_interrupt_config_t, *plcdc_reg_interrupt_config_t;

/**
  \brief Union type to access lcdc_reg_err_handle (@ 0x00000044).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000044) The registers for error handling                           */
  
  struct {
    __IOM uint32_t erroutdata : 16;           /*!< [15..0] Output data when DMA FIFO underflow occurred. ( directly
                                                   mapping to output D[15:0] )                                               */
    __IOM uint32_t dmaunmode  : 1;            /*!< [16..16] 0: output last data, 1: output ERROUTDATA.                       */
  } b;
} lcdc_reg_err_handle_t, *plcdc_reg_err_handle_t;

/**
  \brief Union type to access lcdc_reg_rgbif_config (@ 0x00000048).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000048) The configuration of RGB Interface                         */
  
  struct {
    __IOM uint32_t clkdiv     : 10;           /*!< [9..0] DCLK clock divider. The LSB for this field is always
                                                   set to 0 and is unaffected by a write operation, which
                                                   ensures an even value is held in this register. The frequency
                                                   of SCLK is derived from the following equation: DCLK =
                                                   SYS_Clk/( CLKDIV +2) where CLKDIV is any even value between
                                                   0 and 1022.                                                               */
    __IM  uint32_t            : 6;
    __IOM uint32_t dclkpl     : 1;            /*!< [16..16] The polarity of the DCLK active edge. 0 = data fetched
                                                   at DCLK rising edge, 1 = data fetched at DCLK falling edge.               */
    __IOM uint32_t vspl       : 1;            /*!< [17..17] The VSYNC pulse polarity. 0 = Low level sync clock,
                                                   1 = High level sync clock.                                                */
    __IOM uint32_t hspl       : 1;            /*!< [18..18] The HSYNC pulse polarity. 0 = Low level sync clock,
                                                   1 = High level sync clock.                                                */
    __IOM uint32_t enpl       : 1;            /*!< [19..19] The ENABLE pulse polarity. 0 = Low level for active
                                                   data, 1 = High level for active data.                                     */
    __IOM uint32_t datpl      : 1;            /*!< [20..20] The Data pulse polarity. 0 = Normal, 1 = Inverted                */
  } b;
} lcdc_reg_rgbif_config_t, *plcdc_reg_rgbif_config_t;

/**
  \brief Union type to access lcdc_reg_vsync_timing (@ 0x0000004C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000004C) The configuration of vsync timing                          */
  
  struct {
    __IOM uint32_t vsw        : 4;            /*!< [3..0] Vertical sync signal width -1. Unit: inactive lines                */
    __IM  uint32_t            : 4;
    __IOM uint32_t vbp        : 4;            /*!< [11..8] Back porch line number-1. The number of inactive lines
                                                   at the start of a frame, after vertical synchronization
                                                   period.                                                                   */
    __IM  uint32_t            : 4;
    __IOM uint32_t vfp        : 4;            /*!< [19..16] Front porch line number-1. The number of inactive lines
                                                   at the end of a frame, before vertical synchronization
                                                   period.                                                                   */
    __IM  uint32_t            : 4;
    __IOM uint32_t rgbifupdate : 1;           /*!< [24..24] Force HW updates RGB I/F Timing shadow register at
                                                   starting of VSYNC pulse. CPU writes 1 to force HW updating.
                                                   After updated, HW cleared this bit.                                       */
  } b;
} lcdc_reg_vsync_timing_t, *plcdc_reg_vsync_timing_t;

/**
  \brief Union type to access lcdc_reg_hsync_timing (@ 0x00000050).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000050) The configuration of hsync timing                          */
  
  struct {
    __IOM uint32_t hsw        : 8;            /*!< [7..0] Horizontal sync signal width -1. Unit: DCLK                        */
    __IOM uint32_t hbp        : 8;            /*!< [15..8] Horizontal back porch -1. The number of DCLK periods
                                                   between the falling edge of HSYNC and the start of active
                                                   data.                                                                     */
    __IOM uint32_t hfp        : 8;            /*!< [23..16] Horizontal front porch -1. The number of DCLK periods
                                                   between the end of active data and the rising edge of HSYNC.              */
  } b;
} lcdc_reg_hsync_timing_t, *plcdc_reg_hsync_timing_t;

/**
  \brief Union type to access lcdc_reg_sync_status (@ 0x00000054).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000054) The status of H/V sync                                     */
  
  struct {
    __IM  uint32_t vsstatus   : 2;            /*!< [1..0] VSYNC Status : 00 = VSYNC, 01 = VBP, 11 = ACTIVE, 10
                                                   = VFP                                                                     */
    __IM  uint32_t hsstatus   : 2;            /*!< [3..2] HSYNC Status : 00 = HSYNC, 01 = HBP, 11 = ACTIVE, 10
                                                   = HFP                                                                     */
  } b;
} lcdc_reg_sync_status_t, *plcdc_reg_sync_status_t;

/**
  \brief Union type to access lcdc_reg_dmadata (@ 0x00000058).
*/
typedef union {
  __OM  uint32_t w;                           /*!< (@ 0x00000058) The data register of DMA buffer                            */
  
  struct {
    __OM  uint32_t dmadr      : 32;           /*!< [31..0] DMA FIFO buffer register. When writing to this register,
                                                   you must right-justify the data.                                          */
  } b;
} lcdc_reg_dmadata_t, *plcdc_reg_dmadata_t;

/**
  \brief Union type to access lcdc_reg_rxdata (@ 0x0000005C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000005C) The data register of RX buffer                             */
  
  struct {
    __IM  uint32_t rxdr       : 32;           /*!< [31..0] Receive FIFO buffer register. Read data are automatically
                                                   right-justified.                                                          */
  } b;
} lcdc_reg_rxdata_t, *plcdc_reg_rxdata_t;

/**
  \brief Union type to access lcdc_reg_interrupt_status (@ 0x00000060).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000060) The status of LCDC interrupt                               */
  
  struct {
    __IOM uint32_t dmaunints  : 1;            /*!< [0..0] DMA FIFO underflow interrupt status. Write 1 to clear
                                                   it. 0: No DMA FIFO underflow interrupt generated, 1: this
                                                   interrupt generated, when DMA FIFO underflow.                             */
    __IOM uint32_t paraovints : 1;            /*!< [1..1] Parameters overflow interrupt status. Write 1 to clear
                                                   it. 0: No parameters overflow interrupt generated, 1: this
                                                   interrupt generated, when parameters overflow: ( (write_pulse_num
                                                   + 3 ) >>2) < SW_write32breg_times                                         */
    __IOM uint32_t cmdeints   : 1;            /*!< [2..2] Command done interrupt status. Write 1 to clear it. 0:
                                                   No Command done interrupt generated, 1: this interrupt
                                                   generated, when Command processed done.                                   */
    __IOM uint32_t lcdfrdints : 1;            /*!< [3..3] LCD refresh frame done interrupt status. Write 1 to clear
                                                   it. 0: No LCD refresh frame done interrupt generated, 1:
                                                   this interrupt generated, when sending LCD frame done.                    */
    __IOM uint32_t rxunints   : 1;            /*!< [4..4] Receive FIFO underflow interrupt status. This interrupt
                                                   happened when ((RXFIFO_valid_byte + 3 ) >>2) < SW_read32bits_times.
                                                   Write 1 to clear this interrupt. 0 : RXUNINT interrupt
                                                   is not active after masking, 1 : RXUNINT interrupt is active
                                                   after masking                                                             */
    __IOM uint32_t paraunints : 1;            /*!< [5..5] Parameters underflow interrupt status. Write 1 to clear
                                                   it. 0: No parameters underflow interrupt generated, 1:
                                                   this interrupt generated, when parameters underflow: (
                                                   (write_pulse_num + 3 ) >>2) > SW_write32breg_times.                       */
    __IOM uint32_t rxflhdatints : 1;          /*!< [6..6] RX FIFO flush valid data interrupt status. This interrupt
                                                   happened when flushing RX FIFO that was still not empty.
                                                   Write 1 to clear this interrupt. 0 : RXFLHDATINT interrupt
                                                   is not active after masking, 1 : RXFLHDATINT interrupt
                                                   is active after masking                                                   */
    __IM  uint32_t            : 9;
    __IM  uint32_t dmaunintrs : 1;            /*!< [16..16] DMA FIFO underflow raw interrupt status ( wasn't impacted
                                                   by enable bit)                                                            */
    __IM  uint32_t paraovintrs : 1;           /*!< [17..17] Parameters overflow raw interrupt status ( wasn't impacted
                                                   by enable bit)                                                            */
    __IM  uint32_t cmdeintrs  : 1;            /*!< [18..18] Command done raw interrupt status. ( wasn't impacted
                                                   by enable bit)                                                            */
    __IM  uint32_t lcdfrdintrs : 1;           /*!< [19..19] LCD refresh frame done raw interrupt status. ( wasn't
                                                   impacted by enable bit)                                                   */
    __IM  uint32_t rxunintrs  : 1;            /*!< [20..20] Receive FIFO underflow raw interrupt status. ( wasn't
                                                   impacted by enable bit)                                                   */
    __IM  uint32_t paraunintrs : 1;           /*!< [21..21] Parameters underflow raw interrupt status. ( wasn't
                                                   impacted by enable bit)                                                   */
    __IM  uint32_t rxflhdatintrs : 1;         /*!< [22..22] RX FIFO flush valid data raw interrupt status. ( wasn't
                                                   impacted by enable bit)                                                   */
  } b;
} lcdc_reg_interrupt_status_t, *plcdc_reg_interrupt_status_t;

/**
  \brief Union type to access lcdc_reg_mcuif_config (@ 0x00000064).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000064) The MCU I/F configuration                                  */
  
  struct {
    __IOM uint32_t cspl       : 1;            /*!< [0..0] The CS pulse polarity. 0 = Low level for active pulse,
                                                   1 = High level for active pulse.                                          */
    __IOM uint32_t rspl       : 1;            /*!< [1..1] The RS pulse polarity. 0 = Low level for command address,
                                                   1 = High level for command address.                                       */
    __IOM uint32_t wrpl       : 1;            /*!< [2..2] The WR pulse polarity. 0 = Low level for active pulse,
                                                   1 = High level for active pulse.                                          */
    __IOM uint32_t rdpl       : 1;            /*!< [3..3] The RD pulse polarity. 0 = Low level for active pulse,
                                                   1 = High level for active pulse.                                          */
    __IOM uint32_t datapl     : 1;            /*!< [4..4] The Data pulse polarity. 0 = Normal, 1 = Inverted                  */
    __IOM uint32_t tepl       : 1;            /*!< [5..5] The TE pulse polarity. 0 = Low level for active pulse,
                                                   1 = High level for active pulse.                                          */
    __IOM uint32_t mcusypl    : 1;            /*!< [6..6] The MCU VSYNC pulse polarity. 0 = Low level for active
                                                   pulse, 1 = High level for active pulse.                                   */
    __IM  uint32_t            : 1;
    __IOM uint32_t mcuifupdate : 1;           /*!< [8..8] Force HW updates MCU I/F Timing shadow register at specific
                                                   timing. CPU writes 1 to force HW updating. After updated,
                                                   HW cleared this bit.                                                      */
    __IM  uint32_t            : 7;
    __IOM uint32_t tedelay    : 16;           /*!< [31..16] The delay interval -5. This interval is from detected
                                                   TE signal to starting frame transfer. Unit: WR pulse width
                                                   The maximum value is 6553265531 The real delay interval
                                                   could be TEDELAY+5 or TEDELAY+6                                           */
  } b;
} lcdc_reg_mcuif_config_t, *plcdc_reg_mcuif_config_t;

/**
  \brief Union type to access lcdc_reg_mcuif_vsync_cfg (@ 0x00000068).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000068) The MCU I/F Vsync Mode Configuration                       */
  
  struct {
    __IOM uint32_t mcuvsw     : 8;            /*!< [7..0] VSYNC signal width-1. Unit: WRPERIOD (only for MCU VSYNC
                                                   mode)                                                                     */
    __IM  uint32_t            : 8;
    __IOM uint32_t mcuvspd    : 16;           /*!< [31..16] MCUIFMODE = 1 :VSYNC idle period. This value equals
                                                   to VSYNC period-IMAGEWIDTH * IMAGEHEIGHT * WR_pulse_per_pixel-5.Unit:
                                                   WR pulse width MCUIFMODE = 0: The buffer time between frames.
                                                   This value equals to the time of a frame's end to the next's
                                                   start -5. Unit: WR pulse width MCUIFMODE = 2 : invalid
                                                   usage The maximum value is 65531                                          */
  } b;
} lcdc_reg_mcuif_vsync_cfg_t, *plcdc_reg_mcuif_vsync_cfg_t;

/**
  \brief Union type to access lcdc_reg_mcuif_timing1 (@ 0x0000006C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000006C) The MCU I/F Timing 1                                       */
  
  struct {
    __IOM uint32_t wrperiod   : 10;           /*!< [9..0] WR pulse width-2. The LSB for this field is always set
                                                   to 0 and is unaffected by a write operation, which ensures
                                                   an even value is held in this register. The minimum limitation
                                                   of WR pulse width is 4. Unit: SYS_Clk                                     */
    __IM  uint32_t            : 6;
    __IOM uint32_t rdactw     : 8;            /*!< [23..16] RD active pulse width -1. Unit: WRPERIOD                         */
    __IOM uint32_t rdinactw   : 8;            /*!< [31..24] RD inactive pulse width -1. Unit: WRPERIOD                       */
  } b;
} lcdc_reg_mcuif_timing1_t, *plcdc_reg_mcuif_timing1_t;

/**
  \brief Union type to access lcdc_reg_basic_ctl (@ 0x00000070).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000070) The basic control of LCDC                                  */
  
  struct {
    __IOM uint32_t lcdcen     : 1;            /*!< [0..0] Enable LCDC                                                        */
    __IOM uint32_t lcdcdis    : 1;            /*!< [1..1] During the period of valid line(VTIMING =valid data),
                                                   this disable action will be performed after the last valid
                                                   line had transferred.                                                     */
    __IOM uint32_t lcdcinsdis : 1;            /*!< [2..2] Disable LCDC instantly. HW will reset LCDC internal states
                                                   and disable LCDC then clear both this bit and LCDCEN.                     */
  } b;
} lcdc_reg_basic_ctl_t, *plcdc_reg_basic_ctl_t;

/**
  \brief Union type to access lcdc_reg_mbist_ctl (@ 0x00000074).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000074) The registers of MBIST                                     */
  
  struct {
    __IM  uint32_t            : 1;
    __IOM uint32_t bist_mode  : 1;            /*!< [1..1] MBIST                                                              */
    __IOM uint32_t drf_bist_mode : 1;         /*!< [2..2] MBIST                                                              */
    __IOM uint32_t drf_test_resume : 1;       /*!< [3..3] MBIST                                                              */
    __IOM uint32_t bist_rstn  : 1;            /*!< [4..4] MBIST                                                              */
    __IOM uint32_t bist_pd_0  : 1;            /*!< [5..5] MBIST                                                              */
    __IM  uint32_t            : 2;
    __IM  uint32_t drf_bist_done : 1;         /*!< [8..8] MBIST                                                              */
    __IM  uint32_t drf_bist_fail_0 : 1;       /*!< [9..9] MBIST                                                              */
    __IM  uint32_t drf_start_pause : 1;       /*!< [10..10] MBIST                                                            */
    __IM  uint32_t bist_done  : 1;            /*!< [11..11] MBIST                                                            */
    __IM  uint32_t bist_fail_0 : 1;           /*!< [12..12] MBIST                                                            */
  } b;
} lcdc_reg_mbist_ctl_t, *plcdc_reg_mbist_ctl_t;

/**
  \brief Union type to access lcdc_reg_version (@ 0x00000078).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000078) The version of LCDC H/W                                    */
  
  struct {
    __IM  uint32_t version    : 16;           /*!< [15..0] H/W version, 0x300 means version 3                                */
    __IM  uint32_t reversion  : 16;           /*!< [31..16] H/W reversion                                                    */
  } b;
} lcdc_reg_version_t, *plcdc_reg_version_t;

/**
  \brief Union type to access lcdc_reg_uvfrbuffer0 (@ 0x0000007C).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x0000007C) The start address of frame buffer0                         */
  
  struct {
    __IOM uint32_t uvfrbuff0  : 32;           /*!< [31..0] The start address of UV frame buffer 0. [5:0] always
                                                   set to 0 and is unaffected by a write operation. This register
                                                   is invalid when YUVFMT =1.                                                */
  } b;
} lcdc_reg_uvfrbuffer0_t, *plcdc_reg_uvfrbuffer0_t;

/**
  \brief Union type to access lcdc_reg_uvfrbuffer1 (@ 0x00000080).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000080) The start address of frame buffer1                         */
  
  struct {
    __IOM uint32_t uvfrbuff1  : 32;           /*!< [31..0] The start address of UV frame buffer 1. [5:0] always
                                                   set to 0 and is unaffected by a write operation. This register
                                                   is invalid when YUVFMT =1.                                                */
  } b;
} lcdc_reg_uvfrbuffer1_t, *plcdc_reg_uvfrbuffer1_t;

/**
  \brief Union type to access lcdc_reg_uvfrbuffer2 (@ 0x00000084).
*/
typedef union {
  __IOM uint32_t w;                           /*!< (@ 0x00000084) The start address of frame buffer1                         */
  
  struct {
    __IOM uint32_t uvfrbuff2  : 32;           /*!< [31..0] The start address of UV frame buffer 2. [5:0] always
                                                   set to 0 and is unaffected by a write operation. This register
                                                   is invalid when YUVFMT =1.                                                */
  } b;
} lcdc_reg_uvfrbuffer2_t, *plcdc_reg_uvfrbuffer2_t;


/** @} */ /* End of group hs_hal_lcdc_reg */
/// @endcond /* End of condition DOXYGEN_LCDC_REG_TYPE */

#ifdef  __cplusplus
}
#endif


#endif    // end of #ifndef _RTL8195BHP_LCDC_TYPE_H_

