/*
*******************************************************************************
*                           Cardreader RTS5151 project
*
*                           Layer:
*                           Module:
*
*
*
*
* File : Define.h
*******************************************************************************
*/
/**
*******************************************************************************
  \file Define.h
  \brief Constant and macro definintion.



* \version 0.1
* \date 2006

*******************************************************************************/

/*=============================================================================

                            EDIT HISTORY FOR MODULE

 when           who         what, where, why
 -----------    ---------   ---------------------------------------------------
 2006/1/13      JinZhong    Create this file

==============================================================================*/


#ifndef	_CAMREGLIB_H_
#define	_CAMREGLIB_H_


// hardware register paritial definition
#define DATA0_HOST_TO_MCU				0x7000
#define DATA0_MCU_TO_HOST				0x7020

#define MCU_WRITE1_TRIGGER_CPU_INT_L		0x704C
#define MCU_WRITE1_TRIGGER_CPU_INT_H		0x704D

#define	ISP_CONTROL0					0x8000
#define	ISP_INT_FLAG1					0x8009
#define	ISP_SHIFTREG_FSYNC_EN		0x8018
#define	ISP_SHIFTREG_FSYNC_A			0x8019
#define	ISP_SHIFTREG_FSYNC_B			0x801A
#define	ISP_SHIFTREG_FSYNC_C			0x801B
#define	ISP_SHIFTREG_FSYNC_D			0x801C
#define	AE_STATIS_LOC 					0x8027 //0:before gamma  ;1:after gamma
#define	ISP_DATA_ENABLE				0x802A
#define ISP_DATA_DELAY				0x802B
#define ISP_MIPI_TRANSFER_EN     		0x802D

#define  ISP_NLSC_R_ADJ_RATE			0x8109
#define  ISP_NLSC_G_ADJ_RATE			0x810A
#define  ISP_NLSC_B_ADJ_RATE			0x810B

#define ISP_RGBIR_CTRL				0x803e

#define	ISP_HUE_SIN_X					0x841C
#define	ISP_HUE_COS_X					0x841D
#define	ISP_HUE_SIN_Y					0x841E
#define	ISP_HUE_COS_Y					0x841F
#define	ISP_CONTRAST					0x8425
#define	ISP_Y_OFFSET					0x8427
#define	ISP_Y_GAIN						0x8428
#define	ISP_U_GAIN						0x842A
#define	ISP_V_GAIN						0x842C
#define	ISP_YGAMMA_P0					0x8430
#define	ISP_YGAMMA_P1					0x8431
#define	ISP_YGAMMA_P2					0x8432
#define	ISP_YGAMMA_P3					0x8433
#define	ISP_YGAMMA_P4					0x8434
#define	ISP_YGAMMA_P5					0x8435
#define	ISP_YGAMMA_P6					0x8436
#define	ISP_YGAMMA_P7					0x8437
#define	ISP_YGAMMA_P8					0x8438
#define	ISP_YGAMMA_P9					0x8439
#define	ISP_YGAMMA_PA					0x843A
#define	ISP_YGAMMA_PB					0x843B
#define	ISP_YGAMMA_PC					0x843C
#define	ISP_YGAMMA_PD					0x843D
#define	ISP_YGAMMA_PE					0x843E
#define	ISP_YGAMMA_PF					0x843F
#define	ISP_YGAMMA_SYNC				0x8440

#define	JPEG_ISP_CTRL				0x86b8

#define ISP_DEHAZE_INT_FLAG			0x8E3A
#define ISP_DEHAZE_INT_EN			0x8E3B

#define EPA_STAT                                 0XFE3A
#define EP_FIFO_FLUSH				0xFE44

// hardware register bit definition
#define ISP_INT0            0x00
#define ISP_INT1            0x01

// ISP_CONTROL0		8000
#define ISP_FRAME_STOP					0x04
#define ISP_STOP						0x08
#define ISP_TRANSFER_IDLE				0x10
#define ISP_TRANSFER_GET_STILLIMG		0x40
#define ISP_TRANSFER_START				0x80

//ISP_INT_EN1 && ISP_INT_FLAG1	8008 & 8009
#define ISP_FLICK_DETECT_INT 0x10
#define ISP_DATA_END_INT    0x08
#define ISP_DATA_START_INT  0x04
#define ISP_FRM_END_INT     0x02

// ISP_MIPI_TRANSFER_EN	0x802D
#define SEL_MIPI_DATA    0x01
#define SEL_CCS_DATA   0x00

//JPEG_ISP_CTRL		0x86b8
#define JPEG_ISP_START		0x01
#define JPEG_ISP_STOP		0x02

// ISP_DEHAZE_INT_FLAG	0x8E3A
// ISP_DEHAZE_INT_EN	0x8E3B
#define DEHAZE_PART_ONE_INT		0x01
#define DEHAZE_PART_TWO_INT		0x02
#define DEHAZE_CURVE_BLEND_INT	0x04

//CCS_CONTROL 0xFECD
#define CCS_SSOR_MODE_12BIT			0x40
#define CCS_SSOR_MODE_8P2			0x30
#define CCS_SSOR_MODE_2P8			0x20
#define CCS_SSOR_MODE_8BIT		0x10
#define CCS_SSOR_MODE_NORM		0x00
#define CCS_PCLK_STOP_EN			0x08
#define PIXEL_SAMPLE_RISING		0x04
#define PIXEL_SAMPLE_FALLING		0x00
#define VSYNC_ACTIVE_HIGH		0x02
#define VSYNC_ACTIVE_LOW		0x00
#define HSYNC_ACTIVE_HIGH		0x01
#define HSYNC_ACTIVE_LOW		0x00

//HISPI_LVDS_MODE		0xFD02
#define	HISPI_PACKED_SP_MODE	0x00
#define	HISPI_STREAM_SP_MODE	0x01
#define	LVDS_MODE				0x02
#define	HISPI_FLR_EXIST			0x04
#define	HISPI_LVDS_LOW_BIT_FIRST		0x00
#define	HISPI_LVDS_HIGH_BIT_FIRST	0x20

//HISPI_LVDS_WORD_FORMAT		0xFD03
#define	HISPI_LVDS_RAW8			0x00
#define	HISPI_LVDS_RAW10			0x01
#define	HISPI_LVDS_RAW12			0x02

//HISPI_LVDS_LANE_ENABLE		0xFD08
#define	HISPI_LVDS_LANE0_EN		0x01
#define	HISPI_LVDS_LANE1_EN		0x02
#define	HISPI_LVDS_LANE2_EN		0x04
#define	HISPI_LVDS_LANE3_EN		0x08

//MIPI_DPHY_CONTROL			 0xFE13 
#define PIX_DIN_MIPI_SEL	0x80
#define MIPI_CRC16_EN      	 0x40
#define MIPI_ECC_EN       	 0x20
#define MIPI_BIT_SWITCH    	 0x10
#define MIPI_CLK_LANE_EN	0x08
#define LANE1_LANE0_SWITCH  	 0x04
#define MIPI_DATA_LANE1_EN  0x02
#define MIPI_DATA_LANE0_EN  0x01
#define MIPI_DATA_LANE_ALL_EN	(MIPI_DATA_LANE0_EN|MIPI_DATA_LANE1_EN)

// MIPI_DPHY_DATA_FMT	0xFE14
#define MIPI_DATA_FORMAT_RAW8   0x00
#define MIPI_DATA_FORMAT_RAW10  0x01
#define MIPI_DATA_FORMAT_YUV    0x02
#define MIPI_DATA_FORMAT_JPEG   0x03

#define MIPI_YUV_TYPE_NULL      0x00
#define MIPI_YUV_TYPE_UYVY      0x00
#define MIPI_YUV_TYPE_VYUY      0x10
#define MIPI_YUV_TYPE_YVYU      0x20
#define MIPI_YUV_TYPE_YUYV      0x30

// MIPI_DPHY_DEGLITCH		0xFE16
#define CLK_LANE_DEGLITCH_CONFIG    0x04
#define LANE1_DEGLITCH_CONFIG   0x2
#define LANE0_DEGLITCH_CONFIG     0x1

// MIPI_DPHY_DATA_TYPE		0xFE15
#define MIPI_DATA_TYPE_YUYV8    0x1E
#define MIPI_DATA_TYPE_YUYV10   0x1F
#define MIPI_DATA_TYPE_RAW8     0x2A
#define MIPI_DATA_TYPE_RAW10    0x2B
#define MIPI_DATA_TYPE_MJPG     0x30

// MIPI_DPHY_DIVSEL		0xFE17
#define MIPI_32BITSAPHY_HSCLK_DIVBY32    0x05
#define MIPI_16BITSAPHY_HSCLK_DIVBY16   0x01
#define MIPI_8BITSAPHY_HSCLK_DIVBY8     0x00

// MIPI_DPHY_ACTIVE_LEVEL	0xFE2C
#define CLK_LANE_TERM_ENABLE_CONFIGURE 0x04
#define LANE1_TERN_ENABLE_CONFIGURE 0x02
#define LANE0_TERM_ENABLE_CONFIGURE 0x01

// MIPI_DPHY_HS_TERM			0xFE27
#define HSTERM_EN_TIME_00	0x00
#define HSTERM_EN_TIME_11	0x11
#define HSTERM_EN_TIME_22	0x22
#define HSTERM_EN_TIME_33	0x33
#define HSTERM_EN_TIME_44	0x44
#define HSTERM_EN_TIME_55	0x55
#define HSTERM_EN_TIME_66	0x66
#define HSTERM_EN_TIME_77	0x77
#define HSTERM_EN_TIME_88	0x88
#define HSTERM_EN_TIME_99	0x99
#define HSTERM_EN_TIME_AA	0xAA
#define HSTERM_EN_TIME_BB	0xBB
#define HSTERM_EN_TIME_CC	0xCC
#define HSTERM_EN_TIME_DD	0xDD
#define HSTERM_EN_TIME_EE	0xEE
#define HSTERM_EN_TIME_FF	0xFF

//System clock
#ifndef _IC_CODE_
#define SYS_CLOCK_20M		0x00
#endif
#define SYS_CLOCK_200M		0x20
#define SYS_CLOCK_100M		0x40
#define SYS_CLOCK_50M		0x60
#define SYS_CLOCK_25M		0x80
#define SYS_CLOCK_12_5M	0xA0

#define SYS_CLOCK_300M		0x01
#define SYS_CLOCK_150M		0x21
#define SYS_CLOCK_75M		0x41
#define SYS_CLOCK_37_5M	0x61
#define SYS_CLOCK_18_75M	0x81

//Sensor clock
#define SNR_CLOCK_24M		0x42	// USBPLL=480M, src=USBPLL/5, div=4
#define SNR_CLOCK_24M_SSC	0x55	// PLL4=288M, src=PLL4/3, div=4
#define SNR_CLOCK_27M		0x74	// PLL4=324M,src=PLL4/2, div=6
#define SNR_CLOCK_54M		0x34	// PLL4=216M,src=PLL4/2, div=2
#define SNR_CLOCK_37M125	0x54	// PLL4=297M,src=PLL4/2, div=4
#define SNR_CLOCK_74M25		0x34	// PPL4=297M,src=PLL4/2, div=2

#endif
