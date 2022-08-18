#ifndef _CAMSYSLIB_H_
#define _CAMSYSLIB_H_

///////////////////////////////////////////
//soft interrupt registers
///////////////////////////////////////////

#define SF_IRQ_INIT_ISP				0x01
#define SF_IRQ_INIT_ISP_HW			0x02
#define SF_IRQ_FW_PRVIEW			0x04

///////////////////////////////////////////
//video attribute
///////////////////////////////////////////

#define MAX_STREAM_COUNT				5
#define MAX_FRAME_INTERVAL_COUNT		15

// video format
#define FORMAT_TYPE_YUV420_SEMIPLANAR 	0x01
#define FORMAT_TYPE_YUV422_SEMIPLANAR 	0x02
#define FORMAT_TYPE_MJPG					0x04

// stream status
#define STREAM_STOP			0
#define STREAM_START		1
#define STREAM_PAUSE		2

/*video frame diamension*/
#define VIDEO_WIDTH_3264    3264
#define VIDEO_WIDTH_2592    2592
#define VIDEO_WIDTH_2304    2304
#define VIDEO_WIDTH_2048    2048
#define VIDEO_WIDTH_1920    1920
#define VIDEO_WIDTH_1632    1632
#define VIDEO_WIDTH_1600    1600
#define VIDEO_WIDTH_1296    1296
#define VIDEO_WIDTH_1280    1280
#define VIDEO_WIDTH_1024    1024
#define VIDEO_WIDTH_960	960
#define VIDEO_WIDTH_848	848
#define VIDEO_WIDTH_800      800
#define VIDEO_WIDTH_640    	640
#define VIDEO_WIDTH_424	424
#define VIDEO_WIDTH_352    	352
#define VIDEO_WIDTH_320    	320
#define VIDEO_WIDTH_176    	176
#define VIDEO_WIDTH_160    	160

#define VIDEO_HEIGHT_2448   2448
#define VIDEO_HEIGHT_1944   1944
#define VIDEO_HEIGHT_1536   1536
#define VIDEO_HEIGHT_1440   1440
#define VIDEO_HEIGHT_1296   1296
#define VIDEO_HEIGHT_1224   1224
#define VIDEO_HEIGHT_1200   1200
#define VIDEO_HEIGHT_1080   1080
#define VIDEO_HEIGHT_1024   1024
#define VIDEO_HEIGHT_972     972
#define VIDEO_HEIGHT_960     960
#define VIDEO_HEIGHT_900	900
#define VIDEO_HEIGHT_800     800
#define VIDEO_HEIGHT_768     768
#define VIDEO_HEIGHT_720     720
#define VIDEO_HEIGHT_600     600
#define VIDEO_HEIGHT_540	540
#define VIDEO_HEIGHT_480   	480
#define VIDEO_HEIGHT_400   	400
#define VIDEO_HEIGHT_360	360
#define VIDEO_HEIGHT_288   	288
#define VIDEO_HEIGHT_240   	240
#define VIDEO_HEIGHT_200   	200
#define VIDEO_HEIGHT_192   	192
#define VIDEO_HEIGHT_180 	180
#define VIDEO_HEIGHT_144   	144
#define VIDEO_HEIGHT_120   	120

///////////////////////////////////////////
//sensor setting
///////////////////////////////////////////

// sensor format
#define RAW_MODE			0
#define YUV422_MODE		1
#define MJPG_MODE			2

// sensor raw format
#define SNR_RAW8_FORMAT		0
#define SNR_RAW10_FORMAT	1
#define SNR_RAW12_FORMAT	2
#define SNR_YUV422_FORMAT	3

//HCLK source type
#define HCLK_SSC_EN			0x80
#define HCLK_SRC_480M		0x00
#define HCLK_SRC_288M		0x01
#define HCLK_SRC_324M		0x02
#define HCLK_SRC_297M		0x03
#define HCLK_SRC_216M		0x04

// sensor interface
#define MIPI_SNR				0x00
#define DVP_SNR				0x01
#define HISPI_SNR			0x02
#define LVDS_SNR			0x03

///////////////////////////////////////////
//video control
///////////////////////////////////////////

//camera terminal control select bit map

//     D00 = 0   no -  Scanning Mode
//     D01 = 1  yes -  Auto-Exposure Mode
//     D02 = 0   no -  Auto-Exposure Priority
//     D03 = 1  yes -  Exposure Time (Absolute)
//     D04 = 0   no -  Exposure Time (Relative)
//     D05 = 0   no -  Focus (Absolute)
//     D06 = 0   no -  Focus (Relative)
//     D07 = 0   no -  Iris (Absolute)
//     D08 = 0   no -  Iris (Relative)
//     D09 = 0   no -  Zoom (Absolute)
//     D10 = 0   no -  Zoom (Relative)
//     D11 = 0   no -  PanTilt (Absolute)
//     D12 = 0   no -  PanTilt (Relative)
//     D13 = 0   no -  Roll (Absolute)
//     D14 = 0   no -  Roll (Relative)
//     D15 = 0   no -  Reserved
#define CT_CTL_SEL_SCAN_MODE              	(0x0001)
#define CT_CTL_SEL_AUTO_EXP_MODE       	(0x0002)
#define CT_CTL_SEL_AUTO_EXP_PRY       	(0x0004)
#define CT_CTL_SEL_EXPOSURE_TIME_ABS	(0x0008)
#define CT_CTL_SEL_EXPOSURE_TIME_REL	(0x0010)
#define CT_CTL_SEL_FOCUS_ABS			(0x0020)
#define CT_CTL_SEL_FOCUS_REL			(0x0040)
#define CT_CTL_SEL_IRIS_ABS				(0x0080)
#define CT_CTL_SEL_IRIS_REL				(0x0100)
#define CT_CTL_SEL_ZOOM_ABS			(0x0200)
#define CT_CTL_SEL_ZOOM_REL			(0x0400)
#define CT_CTL_SEL_PANTILT_ABS			(0x0800)
#define CT_CTL_SEL_PANTILT_REL			(0x1000)
#define CT_CTL_SEL_ROLL_ABS			(0x2000)
#define CT_CTL_SEL_ROLL_REL			(0x4000)
//     D16 = 0   no -  Reserved
//     D17 = 0   no -  Focus,Auto
//     D18 = 0   no -  Privacy
// Camera Termal control select bit D16~D31 definition
#define CT_CTL_SEL_FOCUS_AUTO			(0x0002)

#define CT_CTL_SEL_FOCUS_AUTO_FOR_PPWB	0x8000	// hemonel 2011-05-05: camera control select bit map D15 is reserved, so use D15 as FocusAuto PPWB change bit

#define CT_CTL_SEL_ROI					(0x20)

//PROCESSING UNIT CONTROL SELECT BIT MAP
//bmControls : 0x7F 0x17
//     D00 = 1  yes -  Brightness
//     D01 = 1  yes -  Contrast
//     D02 = 1  yes -  Hue
//     D03 = 1  yes -  Saturation
//     D04 = 1  yes -  Sharpness
//     D05 = 1  yes -  Gamma
//     D06 = 1  yes -  White Balance Temperature
//     D07 = 0   no -  White Balance Component
//     D08 = 1  yes -  Backlight Compensation
//     D09 = 0  yes -  Gain
//     D10 = 1  yes -  Power Line Frequency
//     D11 = 0   no -  Hue, Auto
//     D12 = 1  yes -  White Balance Temperature, Auto
//     D13 = 0   no -  White Balance Component, Auto
//     D14 = 0   no -  Digital Multiplier
//     D15 = 0   no -  Digital Multiplier Limit

#define PU_CTL_SEL_BRIGHTNESS                        (0x0001)
#define PU_CTL_SEL_CONTRAST                            (0x0002 )
#define PU_CTL_SEL_HUE                                       (0x0004 )
#define PU_CTL_SEL_SATURATION                        (0x0008 )
#define PU_CTL_SEL_SHARPNESS                         (0x0010 )
#define PU_CTL_SEL_GAMMA                                (0x0020 )
#define PU_CTL_SEL_WHITE_BALANCE_TEMPERATURE        (0x0040 )
#define PU_CTL_SEL_WHITE_BALANCE_COMPONENT           (0x0080 )
#define PU_CTL_SEL_BACKLIGHT_COMPENSATION               (0x0100 )
#define PU_CTL_SEL_GAIN                                                         (0x0200 )
#define PU_CTL_SEL_POWER_LINE_FREQUENCY                   (0x0400)
#define PU_CTL_SEL_HUE_AUTO                                               (0x0800)
#define PU_CTL_SEL_WHITE_BALANCE_MODE   (0x1000)
#define PU_CTL_SEL_WHITE_BALANCE_COMPONENT_AUTO      (0x2000)
#define PU_CTL_SEL_DIGITAL_MULTIPLIER                                    (0x4000)
#define PU_CTL_SEL_DIGITAL_MULTIPLIER_LIMIT                        (0x8000)

/*EXTENSION UNIT DBG CONTROLS*/
#define EXU1_CTL_SEL_TCORRECTION		(0x0001)

//RTK EXTENSION UNIT CONTROL SELECT BIT MAP
#define RTK_EXT_CTL_SEL_ISP_SPECIAL_EFFECT	0x00000001
#define RTK_EXT_CTL_SEL_EVCOM					0x00000002
#define RTK_EXT_CTL_SEL_CTE					0x00000004
#define RTK_EXT_CTL_SEL_AE_LOCK				0x00000008
#define RTK_EXT_CTL_SEL_AWB_LOCK				0x00000010
#define RTK_EXT_CTL_SEL_AF_LOCK				0x00000020
#define RTK_EXT_CTL_SEL_LED_TORCH				0x00000040
#define RTK_EXT_CTL_SEL_LED_FLASH				0x00000080
#define RTK_EXT_CTL_SEL_ISO					0x00000100
#define RTK_EXT_CTL_SEL_SCENE_MODE			0x00000200
#define RTK_EXT_CTL_SEL_ROI_MODE				0x00040000
#define RTK_EXT_CTL_SEL_ROI					0x00080000
#define RTK_EXT_CTL_SEL_3ASTS					0x00100000
#define RTK_EXT_CTL_SEL_IQ_MODE				0x10000000
#define RTK_EXT_CTL_SEL_IQ_PARAMETER		0x20000000
#define RTK_EXT_CTL_SEL_GAIN			0x40000000

#define CTL_TRIGGER_STS_NORMAL                           0
#define CTL_TRIGGER_STS_TRNS_STILL                     1
#define CTL_TRIGGER_STS_TRNS_STILL_VIABULK   2
#define CTL_TRIGGER_STS_ABORT_STILL                  3

///////////////////////////////////////////
//CPU Command
///////////////////////////////////////////

//MCU process CMD result type
#define CMD_SUCESS				0x00
#define CMD_FAIL_DBG			0x01
#define CMD_FAIL_GET_DES		0x02
#define CMD_FAIL_PREVIEW		0x03
#define CMD_FAIL_ISP_PRO		0x04
#define CMD_FAIL_CAMERA		0x05
#define CMD_FAIL_RTK_EX_CTL	0x06
#define CMD_FAIL_SPI			0x07
#define CMD_FAIL_LEN_ERR		0x08
#define CMD_FAIL_I2C_ERR		0x09
#define CMD_FAIL_STATUS		0x0A
#define CMD_FAIL_OUTOFRANGE	0x0B
#define CMD_FAIL_NORDY			0x0C
#define CMD_FAIL_INVDREQ		0x0D
#define CMD_FAIL_INVDCTL		0x0D
#define CMD_FAIL_INVD_CMD		0xFF

//CMD type
#define CMD_DBG				0x00
#define CMD_GET_DES		0x01
#define CMD_PREVIEW		0x02
#define CMD_ISP_PRO			0x03
#define CMD_CAMERA			0x04
#define CMD_RTK_EX_CTL		0x05
#define CMD_GET_COORDINATE_INFO	0x06
#define CMD_MTD				0x07
#define CMD_OSD				0x08
#define CMD_PRIVATE_MASK	0x09
#define CMD_OTHER_ISP		0x0a
#define CMD_FT2				0x0b
#define CMD_GPIO			0x0c

//sub cmd type//
#define SUB_CMD_MASK			0x7F

//get device information
#define GET_DEVICE_DES			0x81
#define GET_FRAME_INTERVAL_DES	0x82
#define GET_VS_FMT_DES			0x83
#define GET_ISP_PROCESS_DES	0x84
#define GET_CAMERA_DES			0x85
#define GET_RTK_EXT_CTL_DES	0x86
#define GET_HCLK_CFG_DES		0x87
#define GET_FW_VERSION			0x88
#define GET_SNR_POWER			0x89
#define GET_API_VERSION			0x8a
#define GET_SNR_PWR_SEQ			0x8b

//preview
#define SET_FPS					0x01
#define START_PREVIEW			0x02
#define STOP_PREVIEW			0x03
#define SET_ISP_OUTPUT_FMT		0x04
#define PAUSE_VIDEO				0x05
#define RESUME_VIDEO			0x06
#define SET_FORMAT				0x07
#define SNR_PWRON_BEF			0x09

//Get Coordinate Information
#define GET_SNR_FMT			0x81
#define GET_SCALE_COEFF		0x82
#define GET_ZOOM_START			0x83

// // ISP Processing Unit / Camera Terminal / Rtk Extended Unit Request Codes
#define RC_UNDEFINED 0x00
#define SET_CUR 0x01
#define GET_CUR 0x81
#define GET_MIN 0x82
#define GET_MAX 0x83
#define GET_RES 0x84
#define GET_LEN 0x85
#define GET_INFO 0x86
#define GET_DEF 0x87

//MTD
#define SET_MTD_ENABLE			0x01
#define GET_MTD_ENABLE			0x81
#define SET_MTD_DATA_FORMAT		0x02
#define GET_MTD_DATA_FORMAT		0x82
#define SET_MTD_GRID_MASK		0x03
#define GET_MTD_GRID_MASK		0x83
#define SET_MTD_GRID			0x04
#define GET_MTD_GRID			0x84
#define SET_MTD_RECT			0x05
#define GET_MTD_RECT			0x85
#define SET_MTD_GRID_ABSOLUTE	0x06
#define GET_MTD_GRID_ABSOLUTE	0x86
#define SET_MTD_RECT_ABSOLUTE	0x07
#define GET_MTD_RECT_ABSOLUTE	0x87
#define SET_MTD_SENSITIVITY		0x08
#define GET_MTD_SENSITIVITY		0x88
#define SET_MTD_PERCENTAGE		0x09
#define GET_MTD_PERCENTAGE		0x89
#define SET_MTD_FRAME_INTERVAL	0x0a
#define GET_MTD_FRAME_INTERVAL	0x8a
#define SET_MTD_GRID_RES			0x0b
#define GET_MTD_GRID_RES			0x8b
#define SET_MTD_RECT_RES			0x0c
#define GET_MTD_RECT_RES			0x8c
#define GET_MTD_RESULT				0x8d

//OSD
#define SET_OSD_LIB_CHAR_ATTR			0x01
#define GET_OSD_LIB_CHAR_ATTR			0x81
#define SET_OSD_CHINESE_ADDR			0x02
#define GET_OSD_CHINESE_ADDR			0x82
#define SET_OSD_TIME_DATE_EN			0x03
#define GET_OSD_TIME_DATE_EN			0x83
#define SET_OSD_TIME_DATE_DISPLAY_CFG	0x04
#define GET_OSD_TIME_DATE_DISPLAY_CFG	0x84
#define SET_OSD_TIME_FMT				0x05
#define GET_OSD_TIME_FMT				0x85
#define SET_OSD_CUR_TIME				0x06
#define SET_OSD_CUR_DATE				0x07
#define SET_OSD_NEXT_DATE				0x08
#define SET_OSD_BLK_EN					0x09
#define GET_OSD_BLK_EN					0x89
#define SET_OSD_BLK_ATTR				0x0a
#define GET_OSD_BLK_ATTR				0x8a
#define OSD_WRITE_MEM					0x0b
#define OSD_READ_MEM					0x8b
#define OSD_GET_MEMORY_SIZE				0x8c

//Private Mask
#define	SET_MASK_ENABLE			0x01
#define	GET_MASK_ENABLE			0x81
#define	SET_MASK_COLOR			0x02
#define	GET_MASK_COLOR			0x82
#define	SET_MASK_GRID_BITMAP	0x03
#define	GET_MASK_GRID_BITMAP	0x83
#define	SET_MASK_GRID			0x04
#define	GET_MASK_GRID			0x84
#define SET_MASK_RECT			0x05
#define GET_MASK_RECT			0x85
#define SET_MASK_GRID_ABSOLUTE	0x06
#define GET_MASK_GRID_ABSOLUTE	0x86
#define SET_MASK_RECT_ABSOLUTE	0x07
#define GET_MASK_RECT_ABSOLUTE	0x87
#define SET_MASK_GRID_RES			0x08
#define GET_MASK_GRID_RES			0x88
#define SET_MASK_RECT_RES			0x09
#define GET_MASK_RECT_RES			0x89

//Other ISP
#define SET_ISP_FUN_ENABLE		0x01
#define GET_ISP_FUN_ENABLE		0x81
#define SET_ISP_GRAY_MODE		0x02
#define GET_ISP_GRAY_MODE		0x82
#define GET_IQ_TABLE_ATTR		0x83
#define GET_3A_VERSION			0x84
#define SET_WDR_MODE			0x05
#define GET_WDR_MODE			0x85
#define SET_WDR_LEVEL			0x06
#define GET_WDR_LEVEL			0x86
#define SET_TPNR_LEVEL			0x07
#define GET_TPNR_LEVEL			0x87
#define SET_IR_MODE				0x08
#define GET_IR_MODE				0x88
#define SET_AE_GAIN				0x09
#define GET_AE_GAIN				0x89
#define SET_AE_WEIGHT			0x0a
#define GET_AE_WEIGHT			0x8a
#define GET_AE_STATIS			0x8b
#define GET_AWB_STATIS			0x8c
#define GET_AWB_CT_GAIN			0x8d
#define SET_AE_TARGET_DELTA		0x0e
#define GET_AE_TARGET_DELTA		0x8e
#define SET_STREAM_FFR		0x0f
#define GET_STREAM_FFR		0x8f
#define SET_AWB_INIT_VALUE		0x10
#define SET_AE_INIT_VALUE		0x11
#define SET_AE_STAT_WIN		0x12
#define GET_AE_STAT_WIN		0x92
#define SET_DYNAMIC_FPS			0x15
#define GET_DYNAMIC_FPS			0x95
#define SET_FMT_ZOOM	0x2c
#define GET_FMT_ZOOM	0xac
#define SET_AE_FPS_LIMITE	0x2d
#define GET_AE_FPS_LIMITE	0xad

// GPIO
#define GET_GPIO_USE_STATUS		0x81
#define SET_GPIO_DIR			0x02
#define GET_GPIO_DIR			0x82
#define SET_GPIO_VALUE			0x03
#define GET_GPIO_VALUE			0x83

///////////////////////////////////////////
//Structure Definitions
///////////////////////////////////////////

typedef struct
{
	U16 wMaxWidth;
	U16 wMaxHeight;
	U8 byFormat;
} StreamAttr_t;

typedef struct
{
	U8 byStreamCount;
	StreamAttr_t StreamAttrTable[MAX_STREAM_COUNT];
	U8 byFrameIntervalCount;
	U32 dwFrameIntervalTable[MAX_FRAME_INTERVAL_COUNT];
} VideoAttr_t;

typedef struct
{
	U16 wFormat;
	U16 wWidth;
	U16 wHeight;
	U8 byStatus;
} StreamInfo_t;

///////////////////////////////////////////
//FW Version
///////////////////////////////////////////

typedef struct
{
	U8 byHeader;		// version
	U8 byLen;			// include byHeader
	U32 dwMagictag;		// fix 0x12345678
	U16 wICName;		// exa: 0x5847
	U16 wVID;			// exa: 0x0BDA
	U16 wPID;			// exa: 0x0001
	U32 dwFWVer;
	U32 dwCusVer;
	// Reserved for customer
	U8  Reserved[12];
} FWVersion_t;

///////////////////////////////////////////
//Data interchange between CPU and MCU
///////////////////////////////////////////

#define DATA_IN(byData, byIdx) {XBYTE[DATA0_MCU_TO_HOST+byIdx] = byData;}
#define DATA_OUT(byIdx) (XBYTE[DATA0_HOST_TO_MCU+byIdx])

///////////////////////////////////////////
//Functions
///////////////////////////////////////////

// clock
bit ISPClockOn(void);
U32 GetIspClk(void);
void ChangeSysClock(U8 byStreamID);
void CHANGE_JPEG_CLK(U8 JPEG_CLK);
void CHANGE_ISP_CLK(U8 ISP_CLK);
void JPEG_Clock_Switch(U8 bySwitch);
void ISP_Clock_Switch(U8 bySwitch);
void SNR_Clock_Switch(U8 bySwitch);
void CHANGE_SNR_CLK(U8 bySnrClk);

// CCS
void CCSSetFrameSize(U16 const wWidth,U16 const wHeight);
void CCSBkWindowStart(U16 const wHorStart, U16 const wVerStart);
void CCS_PIN_PULLCTL_ACTIVE(void);
void CCSSetPolarity(U8 byCcsPolarity);

//I2C
bit I2C_WriteByte(U8 byID_Addr, U8 const byAddr, U16 const wData, U8 const byLen);
bit Read_SenReg(U16 address, U16 * pwData);
bit Write_SenReg(U16 address, U16 wData);
bit I2C_NORMAL_Write(U8 const byID_Addr, U32 const dwData, U8 const byLen );

// GPIO
void SetGPIODir(U8 byIdx, BOOL dir);
void SetGPIOVal(U8 byIdx, U8 val);

// sensor util
void Sensor_POR_Common(void);
void ENTER_SENSOR_RESET(void );
void LEAVE_SENSOR_RESET(void );
void Sensor_PWDN(U8 byStat);
void SensorPowerControl(U8 bySwitch,U8 byDelayCtrl );

// CamProcess.c
U8 GetHWStreamID(U8 byStreamID);
bit AllStreamStopped(void);
void ISPFrameAbortPro(void);
U16 GetAppropriateSensorFrame(U16 width, U16 height);

// main
void SoftInterruptOpenBfrConnect(U8 intType);
void SoftInterruptOpenAftConnect(U8 intType);

// extended control
void SetROIMax(void);

// preview
void StopImageTransfer(U8 byDelayCtrl);
void StopSensorCommon(U8 byDelayCtrl);

// JPEG
#ifdef _JPEG_QTABLE_TUNE_
void JpegAcraTuneInc(void);
#endif

#endif
