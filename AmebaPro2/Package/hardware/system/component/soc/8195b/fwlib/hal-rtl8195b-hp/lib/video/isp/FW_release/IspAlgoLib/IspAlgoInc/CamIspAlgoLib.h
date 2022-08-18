#ifndef _ISPALGOLIB_H_
#define _ISPALGOLIB_H_

#define _WDR_DISABLE_MODE_		0U
#define _WDR_MANUAL_MODE_		1U
#define _WDR_AUTO_WEAK_MODE_	2U
#define _WDR_AUTO_MEDIAN_MODE_	3U
#define _WDR_AUTO_STRONG_MODE_	4U

// Isp Algo Var
void Init_ISPAlgo_GlobalVars(void);

// AE
void SetROIAEWindow(U16 wTop, U16 wLeft, U16 wBottom, U16 wRight);
void EnableAEFreeWindow(bit bAEFreeWinEnable);
void InitAECSetting(void);
void ISP_AEStaticsStart(void);
void SetAECWindow(U16 wStart_X,U16 wStart_Y,U16 wWidth, U16 wHeight);
void AECProcess(void);
void AECProDS(void);
void GetAEStat(void);

// AWB
void SetAWBWindow(U16 wWidth, U16 wHeight);
void InitAWBParams(void);
void InitAWBRoughTuneParameters(void);
void GetAWBStat(void);
#ifdef _AWB_DECOLORBLOCK_
void GetAWBDeClusterColorGain(void);
#endif
void GetAWBGrayworldGain(void);
void GetAWBGrayworldGain2(void);
void GetAWBFineTuneGain(void);
void GetAWBFinalGain(void);
void SetBKAWBGain(U16 wRGain,U16 wGGain,U16 wBGain,U8 byflag);
void SetAWBGain(void);
void ISP_AWBStaticsStart(void);
void InitColorTemperatureTable(void);
U16 GetColorTemperature(U8 byBgain, U8 byRgain);
#ifdef _SCENE_MODE_
void AdaptSceneMode(void);
#endif
void GetCurAWBGain(U16 *wRGain, U16 *wGGain, U16 *wBGain);

// VCM
U8 VCM_Write(U16 wData);

// AF
void AutoFocus(void);
void ISP_AFStaticsStart(void);
void SetROIAFWindow(U16 wTop, U16 wLeft, U16 wBottom, U16 wRight);
void InitAFSetting(U16 wWidth, U16 wHeight);
void GetAFStat(void);
void RestartAF(void);

// AB
void AutoBanding(void);
void InitAutoBandingSetting(U16 width, U16 height);
void ABStaticsStart(void);
void ResetPLFreqDetect(void);
void StartPLFreqDetect(void);
void ResetOutDoorDetect();

// AS
void ASDetectWhiteScene();
void ASDetectYellowScene();
void ASChangeAEBoundary();
void ASGetLightSource();
#ifdef _ENABLE_OUTDOOR_DETECT_
void OutdoorModeDetect();
void AWBDynamicBoundarybyScene();
#endif

// HDR
void HdrTune(const U8 byMode);
void SetHWHDR(void);
U8 HdrBackLightComp(void);
void EnableHDR(const U8 byEn);
void SetWDRMode(const U8 byMode);
void SetWDRManualLevel(const U8 byLevel);

// Dehaze
void SetDehazeEnable(U8 byEn);
void InitDehaze(void);
void DisableDehaze(void);
void TriggerDehaze(void);
void DehazeIntPro(U8 byDehazeIntFlag);

//AEC Status
#define AE_STABLE 0x00
#define AE_LTLOWER 0x01
#define AE_GTUPPER 0x02
#define AE_FORCE	0x03
#define AE_MINEPTG	0x04
#define AE_MAXEPTG	0x05

// WB Mode
#define WB_TEMPERATURE_MODE		0
#define WB_AUTO_MODE			1
#define WB_COMPONENT_MODE		2

// AWB Status
#define AWB_STABLE 0x01
#define AWB_UNSTABLE 0x02

//PWR_LINE_FRQ
#define PWR_LINE_FRQ_OFF 	0x00
#define  PWR_LINE_FRQ_50      0x01
#define  PWR_LINE_FRQ_60      0x02
#define PWR_LINE_FRQ_AUTO     0x03

// exposure
#define EXPOSURE_TIME_AUTO_MOD_MANUAL     0X01
#define EXPOSURE_TIME_AUTO_MOD_AUTO          0X02
#define EXPOSURE_TIME_AUTO_MOD_SHUTPRO   0X04
#define EXPOSURE_TIME_AUTO_MOD_APERTPRO 0X08

// IQ Mode
#define IQ_AUTO_MODE	0x00
#define IQ_MANUAL_MODE	0x01

// ROI Mode
#define ROI_MODE_CONTINUOUS		0
#define ROI_MODE_SINGLE			1

// ROI AE Status
#define ROI_AE_QUIT			0x00
#define ROI_AE_INIT			0x01
#define ROI_AE_START_ADJUST	0x02
#define ROI_AE_ADJUST			0x03
#define ROI_AE_STABLE			0x04
#define ROI_AE_BACK_TO_NORMAL	0x05

// hemonel 2009-11-26: define new control struct for min, max, res and default to be all changed.
typedef struct
{
	U8 Min;
	U8 Max;
	U8 Res;
	U8 Def;
	U8 Des;
	U8 Last;
} CtlItemU8_t;

typedef struct
{
	S8 Min;
	S8 Max;
	U8 Res;
	S8 Def;
	S8 Des;
	S8 Last;
} CtlItemS8_t;

typedef struct
{
	U16 Min;
	U16 Max;
	U16 Res;
	U16 Def;
	U16 Des;
	U16 Last;
} CtlItemU16_t;

typedef struct
{
	S16 Min;
	S16 Max;
	U16 Res;
	S16  Def;
	S16  Des;
	S16  Last;
} CtlItemS16_t;

typedef struct
{
	U32 Min;
	U32 Max;
	U32 Res;
	U32 Def;
	U32 Des;
	U32 Last;
} CtlItemU32_t;

typedef struct
{
	S32 Min;
	S32 Max;
	U32 Res;
	S32 Def;
	S32 Des;
	S32 Last;
} CtlItemS32_t;

typedef struct ROICtlParams
{
	U16 wTop;
	U16 wLeft;
	U16 wBottom;
	U16 wRight;
	U16 bmAutoControls;
}ROICtlParams_t;

typedef struct CtlItemROI
{
	//ROICtlParams_t Min;
	ROICtlParams_t Max;
	//ROICtlParams_t Res;
	//ROICtlParams_t Def;
	ROICtlParams_t Des;
	ROICtlParams_t Last;
}CtlItemROI_t;

typedef struct WBComponentCtlParams
{
	U16 wRGain;
	U16 wGGain;
	U16 wBGain;
}WBComponentCtlParams_t;

typedef struct CtlItemWBComponent
{
	//ROICtlParams_t Min;
	WBComponentCtlParams_t Max;
	//ROICtlParams_t Res;
	//ROICtlParams_t Def;
	WBComponentCtlParams_t Des;
	WBComponentCtlParams_t Last;
}CtlItemWBComponent_t;

typedef struct ZoomParam
{
	U16 wStartX;
	U16 wStartY;
	U16 wScaleX;
	U16 wScaleY;
	U16 wRemainderX;
	U16 wRemainderY;
}ZoomParam_t;


// ------callback function declare start-------
// system block callback function

// customer block callback function
void SetSensorExposuretime_Gain(float fExpTime, float fTotalGain);
S8 DynamicAETargetDelta(U32 dwAEC_EtGain);

// -------callback function declare end------

#endif // _ISPALGOLIB_H_
