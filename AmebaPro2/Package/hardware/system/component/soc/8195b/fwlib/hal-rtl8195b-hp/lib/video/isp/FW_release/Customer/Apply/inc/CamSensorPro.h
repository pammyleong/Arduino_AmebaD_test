#ifndef _CAMSENSORPRO_H_
#define _CAMSENSORPRO_H_

#define CTT_INDEX_MAX 6

typedef struct OV_FpsSetting
{
	U8 byFps;
	U16 wExtraDummyPixel;   // register 0x2a,0x2b: dummy pixel adjustment
	U8  byClkrc; // register 0x11: clock pre-scalar
	U32 dwPixelClk;
} OV_FpsSetting_t;

typedef struct GC_FpsSetting
{
	U8 byFps;
	U16 wExtraDummyPixel;   // register 0x2a,0x2b: dummy pixel adjustment
	//U8  byExtraDummyLine;
	U16  byExtraDummyLine;
	U8  byClkrc; // register 0x11: clock pre-scalar
	U32 dwPixelClk;
} GC_FpsSetting_t;

typedef struct
{
	U8 byFps;
	U8 byHB;   // register 0x2a,0x2b: dummy pixel adjustment
	U8 byVB;
	U8  byClkrc; // register 0x11: clock pre-scalar
	U32 dwPixelClk;
} GC0307FpsSetting_t;

typedef struct OV_CTT
{
	U16 wCT;	// color temperature
	U16 wRgain;	// r gain
	U16 wGgain;	// g gain
	U16 wBgain;	// b gain
} OV_CTT_t;

typedef struct OV_BandingFilter
{
	U16 wD50Base; // 50Hz, banding filter base value, Minimum AEC value
	U8  byD50Step; // 50Hz, banding filter Maximun step
	U16 wD60Base; // 60Hz, banding filter base value, Minimum AEC value
	U8  byD60Step; // 60Hz, banding filter Maximun step
} OV_BandingFilter_t;

void WriteSensorSettingBB(U16 length, t_RegSettingBB const  pSetting[]);
void WriteSensorSettingWB(U16 length, t_RegSettingWB const pSetting[]);
void WriteSensorSettingWW(U16 length, t_RegSettingWW const pSetting[]);
OV_CTT_t OV_SetColorTemperature(U16 wSetValue);

#if (defined(RTS58XX_SP_MI1330)||defined(RTS58XX_SP_MI2020))
void WriteMIVarSettingWW(U16 length, t_RegSettingWW pSetting[]);
U8 Read_MI_Vairable ( U16 dWidth_driverID_offset,U16* pwData) ;
U8 Write_MI_Vairable ( U16 dWidth_driverID_offset,U16 wData) ;
U8 MI_PollWaitRefreshDone(U8 byTimeout);
void Write_MI_Vairable_Mask(U16 address, U16 wData, U16 wMask);
U8 MapWBTemp2MicronSensorWBPositon(U16 wSetValue);
U16 MapMicronSensorWBPositon2WBTemp(U8 byPosition);
#endif
#endif