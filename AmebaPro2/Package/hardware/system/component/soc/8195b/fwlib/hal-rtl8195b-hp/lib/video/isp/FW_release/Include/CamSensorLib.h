#ifndef _CAMSENSOR_H_
#define _CAMSENSOR_H_

#define QUXGA_FRM		0x8000		//3264*2448
#define QSXGA_FRM		0x4000		//2592*1944
#define SHD_FRM			0x2000		//2304*1296
#define QXGA_FRM		0x1000		//2048*1536
#define HD1080P_FRM		0x0800		//1920*1080
#define LUXGA_FRM		0x0400		// 1632*1224
#define UXGA_FRM		0x0200		// 1600*1200
#define SXGA_FRM		0x0100		// 1280*1024
#define LXVGA_FRM		0x0080		// 1280*972
#define XVGA_FRM		0x0040		// 1280*960
#define HD800P_FRM		0x0020		// 1280*800
#define HD720P_FRM		0x0010		//  1280*720
#define XGA_FRM			0x0008		// 1024*768
#define QHD_FRM			0x0004		// 960*540
#define SVGA_FRM		0x0002		// 800*600
#define VGA_FRM			0x0001		// 640*480

#define SENSOR_SIZE_MASK		0x0F
#define SENSOR_SIZE_UNKNOWN	0x00
#define SENSOR_SIZE_VGA		0x01	// 640*480
#define SENSOR_SIZE_QHD		0x02	// 960*540
#define SENSOR_SIZE_HD720P		0x03	// 1280*720
#define SENSOR_SIZE_HD800P		0x04	// 1280*800
#define SENSOR_SIZE_XVGA		0x05	// 1280*960
#define SENSOR_SIZE_SXGA		0x06	// 1280*1024
#define SENSOR_SIZE_UXGA		0x07	// 1600*1200
#define SENSOR_SIZE_FHD		0x08	// 1920*1080
#define SENSOR_SIZE_QXGA		0x09	// 2048*1536
#define SENSOR_SIZE_3M4		0x0A	// 2304*1536
#define SENSOR_SIZE_QSXGA		0x0B	// 2592*1944
#define SENSOR_SIZE_QUXGA		0x0C	//3264*2448

#define SENSOR_LSC_8M		0x2
#define SENSOR_LSC_5M		0x1
#define SENSOR_LSC_1080P		0x0

//special effect
#define SNR_EFFECT_NORMAL             0x00
#define SNR_EFFECT_MONOCHROME 0x01
#define SNR_EFFECT_NEGATIVE          0x02
#define SNR_EFFECT_SEPIA                 0x04
#define SNR_EFFECT_AQUA                  0x08
#define SNR_EFFECT_GREEN                0x10
#define SNR_EFFECT_GREENISH		    0x20
#define SNR_EFFECT_REDDISH			0x40
#define SNR_EFFECT_BLUISH			0x80
#define SNR_EFFECT_GRAY		0x81
#define SNR_EFFECT_EDGEDRAW	0x82
#define SNR_EFFECT_RELIEVO		0x83

// image direction set
#define SNR_IMG_DIR_NORMAL              0x0
#define SNR_IMG_DIR_FLIP                 0x2
#define SNR_IMG_DIR_MIRROR               0x1
#define SNR_IMG_DIR_FLIP_MIRROR     0x3

/***********MI2020*********/
#define  MI2020_ADDR_MODE_REG   0x338c
#define  MI2020_DATA_INOUT_REG  0x3390
/***********MI1330*********/
#define  MI1330_ADDR_MODE_REG   0x098c
#define  MI1330_DATA_INOUT_REG  0x0990
/////////////////////////////////////////////////////////////////////
#define  MIVAR_LOGIC_ACCESS    0X2000

#define  MIVAR_DATA_WIDTH_16   0x0000
#define  MIVAR_DATA_WIDTH_8     0x8000

#define  MIVAR_DATA_WIDTH_16_PHY  (MIVAR_DATA_WIDTH_16)
#define  MIVAR_DATA_WIDTH_8_PHY     (MIVAR_DATA_WIDTH_8)

//always logic access
#define  MIVAR_DATA_WIDTH_16_LOG   (MIVAR_DATA_WIDTH_16|MIVAR_LOGIC_ACCESS)
#define  MIVAR_DATA_WIDTH_8_LOG     (MIVAR_DATA_WIDTH_8|MIVAR_LOGIC_ACCESS)

#define  MIVAR_ACCESS_READ   0
#define  MIVAR_ACCESS_WRITE  1

#define MI_DRV_ID_MON    (0 <<8)
#define MI_DRV_ID_SEQ     (1 <<8)
#define MI_DRV_ID_AE     (2 <<8)
#define MI_DRV_ID_AWB    (3 <<8)
#define MI_DRV_ID_ANTF   (4 <<8)
#define MI_DRV_ID_AF       (5 <<8)
#define MI_DRV_ID_AFM     (6 <<8)
#define MI_DRV_ID_MODE   (7 <<8)
#define MI_DRV_ID_HSTG   (11 <<8)

// sensor status
#define SENSOR_OPEN		1
#define SENSOR_CLOSED		0

// I2C
#define I2C_ADDR_MODE_BA     (0<<4)
#define I2C_ADDR_MODE_WA       (1<<4)
#define I2C_ADDR_MODE_PA         (2<<4)
#define I2C_ADDR_MODE_MASK         (0xF<<4)

#define I2C_ACCESS_DATAWIDTH_1            1
#define I2C_ACCESS_DATAWIDTH_2             2
#define I2C_ACCESS_DATAWIDTH_MASK     0xF

#define EN_DELAYTIME 1
#define DIS_DELAYTIME 0

// Sensor Power: An integer means a voltage. For example, 18 means 1.8V.
#define SNR_POWER_NONE	0
#define SNR_POWER_1V2	12
#define SNR_POWER_1V5	15
#define SNR_POWER_1V8	18
#define SNR_POWER_2V7	27
#define SNR_POWER_2V8	28
#define SNR_POWER_3V3	33

// Sensor Power on/off sequence
#define SNR_POWER_IO      0
#define SNR_POWER_ANALOG  1
#define SNR_POWER_CORE    2
#define SNR_POWER_CTRL_MASK_1ST (3 << 0)
#define SNR_POWER_CTRL_MASK_2ND (3 << 2)
#define SNR_POWER_CTRL_MASK_3RD (3 << 4)
#define SENSOR_POWER_SEQUENCE(s, s_1st, s_2nd, s_3rd) 	(s) = (s_1st & 3) | \
		((s_2nd & 3) << 2) | \
		((s_3rd & 3) << 4)

// Structure Definitions
typedef struct
{
	U8 byAddress;
	U8 byData;
} t_RegSettingBB;

typedef struct
{
	U16 wAddress;
	U8 byData;
} t_RegSettingWB;

typedef struct
{
	U16 wAddress;
	U16 wData;
} t_RegSettingWW;
typedef struct
{
	U16 wAddress;
	U16 wData;
	U8 byDataWidth;
} t_VarSettingWW;

typedef struct
{
	U8 byI2CID;
	U8 byMode_DataWidth;
	U8 byI2CPageSelAddr;

} SnrRegAccessProp_t;

typedef struct SensorPower {
	U8 byIOPower;
	U8 byAnalogPower;
	U8 byCorePower;

	U8 bySnrPowerOnSeq;
	U16 wPwrOnFirstDelay;	// us
	U16 wPwrOnSecondDelay;	// us
	U8 bySnrPowerOffSeq;
	U16 wPwrOffFirstDelay;	// us
	U16 wPwrOffSecondDelay;	// us
} SensorPower_t;

// Functions
bit Write_SenReg_Mask(U16 address, U16 wData, U16 wMask);
void ReadSensorID(void);
void SetSensorFormatFps(U16 SetFormat,U8 Fps);
void Reset_Sensor(void);
void StopSensor(U8 byDelayCtrl);
void	SetSensorIntegrationTime(U32 dwSetValue);
void SetSensorIntegrationTimeAuto(U8 bySetValue);
void SetSensorLowLightComp(U8 bySetValue);
void	SetSensorSharpness(U8 bySetValue);
void SetSensorPwrLineFreq(U8 byFps, U8 bySetValue);
void SetSensorBackLightComp(U8 bySetValue);
void	SetSensorWBTemp(U16 wSetValue, U16 wRgain, U16 wGgain, U16 wBgain, bit bIsTemperature);
void	SetSensorWBMode(U8 bySetValue);
void	SetSensorImgDir(U8 bySnrImgDir);
void CfgSensorControlAttr(void );
void PreviewToCapture(U16 wPreviewWidth, U16 wStillWidth);
void CaptureToPreview();
void SetSensorDynIspBaseAEGain(U16 wAEC_Gain);
void SetSensorDynIspBaseColorTemp(U16 wColorTempature);

void GetSensorPclkHsync(U16 wSensorSPFormat,U8 byFps);
void SetSensorGain(float fGain);
float GetSensorAnalogGain(void);
float GetSensorDigitalGain(void);
U8 SetSensorAnalogGain(U16 wGain);
U8 SetSensorDigitalGain(U16 wGain);

U16 GetSensorFormatWidth(U16 const Format, bit const Flag);
U16 GetSensorFormatHeight(U16 const Format, bit const Flag);

//CusXu.c
void	SetBkSaturation(U8 bySetValue);
void SetBkBrightness(S8 sbySetValue);
void	SetBkContrast(U8 bySetValue);
void	SetBkHue (S16 swSetValue);
void SetGainParam(U8 byGain);
void SetGammaParam(U16 wSetValue);
U8 MappingSharpness(U8 bySetValue, U8 byDef);
void InitCustomizedVars(void);
#endif //_CAMSENSOR_H_
