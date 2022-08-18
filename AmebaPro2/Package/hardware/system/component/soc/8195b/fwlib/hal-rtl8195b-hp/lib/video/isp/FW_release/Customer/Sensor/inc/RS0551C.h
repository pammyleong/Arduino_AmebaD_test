#ifndef _RS0551C_H_
#define _RS0551C_H_

//-------------------------System Controlller Register-------------------------------
#define GPIO_OE						0x0002
#define GPIO_VALUE					0x0003
#define GPIO_PULLUP_CTRL			0x0004
#define GPIO_PULLDOWN_CTRL		0x0005
#define GPIO_DRIVE_CTRL				0x0006

#define GPIO0_EN	0x01
#define GPIO1_EN	0x02
#define GPIO2_EN	0x04
#define GPIO3_EN	0x08

//-------------------------Fix Pattern Model Register-------------------------------
#define FIX_PATTERN_BASE_ADDR		0x0200
#define FIXP_FRAME_WIDTH_H		0x0200
#define FIXP_FRAME_WIDTH_L			0x0201
#define FIXP_FRAME_HEIGTH_H		0x0202
#define FIXP_FRAME_HEIGTH_L		0x0203
#define FIXP_DUMMY_PIXEL_H			0x0204
#define FIXP_DUMMY_PIXEL_L			0x0205	//EVEN Only
#define FIXP_DUMMY_LINE_H			0x0206
#define FIXP_DUMMY_LINE_L			0x0207
#define FIXP_SPEED_CTRL				0x0208
#define FIXP_FRAME_NUM				0x0209
#define FIXP_CTRL					0x0210

//24-COLOR
#define COLOR_BLOCK_START_X_L		0x0211
#define COLOR_BLOCK_START_Y_L		0x0212
#define COLOR_BLOCK_START_XY_H	0x0213
#define COLOR_BLOCK_WIDTH_L		0x0214
#define COLOR_BLOCK_HEIGHT_L		0x0215
#define COLOR_BLOCK_WH_H			0x0216
#define COLOR_BLOCK_MARGIN_WIDTH_L		0x0217
#define COLOR_BLOCK_MARGIN_HEIGTH_L		0x0218
#define COLOR_BLOCK_MARGIN_WH_H			0x0219

//-FIXP_CTRL
#define FIXP_RUN								0x80
#define FIXP_STOP							0x00
#define FIXP_IMAGE_SEL_YUYV				0x40
#define FIXP_IMAGE_SEL_RAW					0x00
#define FIXP_IMAGE_MODE_BAYER_COLOR		0x00
#define FIXP_IMAGE_MODE_BWS				0x10
#define FIXP_IMAGE_MODE_CRC_SAME			0x20
#define FIXP_IMAGE_MODE_CRC_DIFF			0x30

//----------------------------TX IF Model Register---------------------------------
//MIPI TX APHY Controller
#define BANDGAP_CTRL				0x050C
#define DSI_POWER_CTRL0			0x0409
#define DSI_POWER_CTRL1			0x0417

//MIPI TX Timing Controller
#define MIPI_TX_INIT_TIME_L			0x0303
#define MIPI_TX_INIT_TIME_H			0x0304
#define MIPI_HS_EXIT_TIME			0x0305
#define MIPI_TX_LP01_TIME			0x0306
#define MIPI_TX_CLK_POST_TIME		0x0307
#define MIPI_TX_CLK_LP00_TIME		0x0308
#define MIPI_TX_CLK_HS0_TIME		0x0309
#define MIPI_TX_CLK_PRE_TIME		0x030A
#define MIPI_TX_DATA_LP00_TIME		0x030B
//#define MIPI_TX_CLK_LP00_TIME		0x030C
#define MIPI_TX_TRAIL_TIME			0x030D
#define MIPI_TX_VALID_TIME			0x030E

//MIPI TX Controller
#define MIPI_TX_ENABLE_CTRL		0x0300
#define MIPI_TX_DATA_TYPE			0x0301
#define MIPI_TX_CONFIG				0x0302
#define MIPI_TX_DATA_SRC			0x0311

//MIPI APHY PLL CLK Controller
#define DSI_CMU_CTRL0				0x0406
#define DSI_CMU_CTRL1				0x0408
#define DSI_SSC_FC_L				0x040D
#define DSI_SSC_FC_H				0x040E
#define DSI_SSC_NC_L				0x040F
#define DSI_SSC_NC_H				0x0410

//----------------------------DVP IF Model Register--------------------------------
#define DVP_ENABLE_CTRL			0x0700
#define DVP_CLK_CTRL				0x0701
#define DVP_VSYNC_CTRL				0x0702
#define DVP_HSYNC_CTRL				0x0703
#define DVP_PCLK_CTRL				0x0704
#define DVP_FRAME_WIDTH_L			0x0705
#define DVP_FRAME_WIDTH_H			0x0706
#define DVP_FRAME_HEIGHT_L			0x0707
#define DVP_FRAME_HEIGHT_H		0x0708
#define DVP_VSYNC_BREAK_L			0x0709
#define DVP_VSYNC_BREAK_H			0x070A
#define DVP_HSYNC_BREAK_L			0x070B
#define DVP_HSYNC_BREAK_H			0x070C
#define DVP_VHSYNC_BREAK_L		0x070D
#define DVP_VHSYNC_BREAK_H		0x070E
#define DVP_HVSYNC_BREAK_L		0x070F
#define DVP_HVSYNC_BREAK_H		0x0710
#define DVP_DUMMY_LEFT_L			0x0711
#define DVP_DUMMY_LEFT_H			0x0712
#define DVP_DUMMY_RIGHT_L			0x0713
#define DVP_DUMMY_RIGHT_H			0x0714
#define DVP_DUMMY_BOTTOM_L		0x0715
#define DVP_DUMMY_BOTTOM_H		0x0716
#define DVP_DATA_LEFT_L				0x0717
#define DVP_DATA_LEFT_H			0x0718
#define DVP_DATA_RIGHT_L			0x0719
#define DVP_DATA_RIGHT_H			0x071A
#define DVP_DATA_BOTTOM_L			0x071B
#define DVP_DATA_BOTTOM_H			0x071C

//-MIPI_TX_ENABLE_CTRL
#define MIPI_TX_ENABLE			0x01
//-MIPI_TX_DATA_TYPE
#define DATA_TYPE_RAW8			0x00
#define DATA_TYPE_RAW10		0x01
#define DATA_TYPE_RAW12		0x10
#define DATA_TYPE_RAW14		0x11
//-MIPI_TX_CONFIG
#define LINE_START_END_EN		0x10
#define NON_CTINUOUS_CLK		0x08
#define LANE_SWITCH_EN			0x04
#define LANE1_EN				0x02
#define LANE0_EN				0x01
//-MIPI_TX_DATA_SRC
#define DATA_SRC_FIXP			0x00
#define DATA_SRC_CCS			0x01
//-BANDGAP_CTRL
#define BANDGAP_VOLT_1144		0x00
#define BANDGAP_VOLT_1163		0x20
#define BANDGAP_VOLT_1181		0x40
#define BANDGAP_VOLT_1119		0x60
#define BANDGAP_VOLT_1218		0x80
#define BANDGAP_VOLT_1236		0xA0
#define BANDGAP_VOLT_1255		0xC0
#define BANDGAP_VOLT_1273		0xE0
#define PWDB_K_EN				0x02
#define RT_POW1_EN				0x00
//-DSI_POWER_CTRL0
#define DSI_CMU_SELLDO			0x00
#define DSI_CMU_SEL3V3			0x20
#define DSI_CMU_PWDB_EN		0x08
#define DSI_CMU_LDO_EN			0x04
#define DSI_CMU_BYPASS_PI		0x02
#define DSI_CMU_SEL_POSTDIV	0x01
//-DSI_POWER_CTRL1
#define DSI_POW_EN				0x01
//-DSI_CMU_CTRL0
#define DSI_CMU_CP_0uA			0x00
#define DSI_CMU_CP_1uA25		0x20
#define DSI_CMU_CP_2uA5		0x40
#define DSI_CMU_CP_3uA75		0x60
#define DSI_CMU_CP_5uA			0x80
#define DSI_CMU_CP_6uA25		0xA0
#define DSI_CMU_CP_7uA5		0xC0
#define DSI_CMU_CP_8uA75		0xE0
#define DSI_CMU_CP_DOUBLE		0x10
#define DSI_CMU_PREDIV_1		0x00
#define DSI_CMU_PREDIV_2		0x04
#define DSI_CMU_PREDIV_4		0x08
#define DSI_CMU_PREDIV_8		0x0C
#define DSI_CMU_LDOREF_1V13	0x00
#define DSI_CMU_LDOREF_1V26	0x01
#define DSI_CMU_LDOREF_1V41	0x02
#define DSI_CMU_LDOREF_1V53	0x03
//-DSI_CMU_CTRL1
#define DSI_CMU_POSTDIV_0		0x00
#define DSI_CMU_POSTDIV_2		0x02
#define DSI_CMU_POSTDIV_3		0x03
#define DSI_CMU_POSTDIV_4		0x04
#define DSI_CMU_POSTDIV_5		0x05
#define DSI_CMU_POSTDIV_6		0x06
#define DSI_CMU_POSTDIV_7		0x07
#define DSI_CMU_POSTDIV_MAX	0x3F

//-DVP_ENABLE_CTRL
#define DVP_EN					0x01
//-DVP_VSYNC_CTRL
#define DVP_VSYNC_HIGH_ACTIVE	0x40
//-DVP_HSYNC_CTRL
#define DVP_HSYNC_HIGH_ACTIVE	0x40
//-DVP_PCLK_CTRL
#define DVP_RISINGEDGE_OUTPUT	0x00
#define DVP_FALINGEDGE_OUTPUT	0x01

//------------------------------Macro definition-----------------------------------
#define NoMask	0

#define TURN_RS0551C_LED_ON(X)		{	Write_SenReg_Mask(GPIO_VALUE, (X), (X)); \
										Write_SenReg_Mask(GPIO_OE, (X), (X));}

#define TURN_RS0551C_LED_OFF(X)		{	Write_SenReg_Mask(GPIO_VALUE, (~(X)), (X)); \
										Write_SenReg_Mask(GPIO_OE, (~(X)), (X));}

//------------------------------Function Declare----------------------------------
void CfgRS0551CControlAttr(void);
void RS0551CSetFormatFps(U16 SetFormat, U8 Fps);
void RS0551C_PORBEF(void);
void RS0551C_POR(void);
void RS0551C_POR_OFF(U8 byDelayCtrl);

#endif
