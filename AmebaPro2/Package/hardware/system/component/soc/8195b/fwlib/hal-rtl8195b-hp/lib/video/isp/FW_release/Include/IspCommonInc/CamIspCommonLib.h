#ifndef _CAMISPLIB_H_
#define _CAMISPLIB_H_

// g_wDynamicISPEn bit map definition
#define DYNAMIC_GAMMA_EN		0x0001
//#define DYNAMIC_SHARPNESS_EN	0x0002
#define DYNAMIC_BLC_EN			0x0004
#define DYNAMIC_CCM_BRIGHT_EN			0x0008
#define DYNAMIC_SHARPPARAM_EN	0x0010
#define DYNAMIC_STA_EN				0x0020
#define DYNAMIC_LSC_EN				0x0040
#define DYNAMIC_LSC_CT_EN				0x0080
//#define DYNAMIC_YGAMMA_EN			0x0080	// hemonel 2011-06-01: delete dynamic Ygamma
#define DYNAMIC_UVOFFSET_EN		0x0100
#define DYNAMIC_CCM_CT_EN			0x0200
#define DYNAMIC_HDR_EN				0x0400
#define DYNAMIC_UVCOLORTUNE_EN	0x0800

// focus
#define FOCUS_AUTO_MOD_MANUAL	0x00
#define FOCUS_AUTO_MOD_AUTO		0x01

//isp special effect
#define ISP_SPECIAL_EFFECT_NORMAL			0x0001
#define ISP_SPECIAL_EFFECT_MONOCHROME 	0x0002
#define ISP_SPECIAL_EFFECT_GRAY			0x0004
#define ISP_SPECIAL_EFFECT_NEGATIVE		0x0008
#define ISP_SPECIAL_EFFECT_SEPIA			0x0010
#define ISP_SPECIAL_EFFECT_GREENISH		0x0020
#define ISP_SPECIAL_EFFECT_REDDISH		0x0040
#define ISP_SPECIAL_EFFECT_BLUISH			0x0080

#define ISP_SPECIAL_EFFECT_AQUA			0x0000
#define ISP_SPECIAL_EFFECT_GREEN			0x0000
#define ISP_SPECIAL_EFFECT_EDGEDRAW		0x0000
#define ISP_SPECIAL_EFFECT_RELIEVO		0x0000

// EV compensation resolution
#define EVCOMP_SIXTHSTEP		0x0001		// 1/6
#define EVCOMP_QUARTERSTEP	0x0002		// 1/4
#define EVCOMP_THIRDSTEP		0x0004		// 1/3
#define EVCOMP_HALFSTEP		0x0008		// 1/2
#define EVCOMP_FULLSTEP		0x0010		// 1

// LED torch mode
#define TORCH_OFF	0
#define TORCH_ON	1

// LED flash mode
#define FLASH_OFF				0x00
#define FLASH_ON				0x01
#define FLASH_AUTO				0x04
#define FLASH_RED_EYE_REDUCE	0x10

// Flash capture status
#define END_FLASH				0
#define PRE_FLASH				1
#define MAIN_FLASH				2
#define FLASH_CAPTURE			3

// ROI Auto Controls
#define ROI_AE_SUPPORT			0x0001
#define ROI_AF_SUPPORT			0x0008

// ISO
#ifdef _EXT_ISO_ENABLE_
#define ISO_AUTO 	0x0001
#define ISO_50 		0x0002
#define ISO_80 		0x0004
#define ISO_100 		0x0008
#define ISO_200 		0x0010
#define ISO_400 		0x0020
#define ISO_800 		0x0040
#define ISO_1600 	0x0080
#define ISO_3200 	0x0100
#define ISO_6400 	0x0200
#define ISO_12800 	0x0400
#define ISO_25600 	0x0800
#endif

//SCENE MODE
#ifdef _SCENE_MODE_
#define SCENEMODE_AUTO			0x0001
#define SCENEMODE_MACRO 			0x0002
#define SCENEMODE_PORTRAIT 		0x0004
#define SCENEMODE_SPORT 			0x0008
#define SCENEMODE_SNOW 			0x0010
#define SCENEMODE_NIGHT 			0x0020
#define SCENEMODE_BEACH 			0x0040
#define SCENEMODE_SUNSET 			0x0080
#define SCENEMODE_CANDLELIGHT 	0x0100
#define SCENEMODE_LANDSCAPE 		0x0200
#define SCENEMODE_NIGHTPORTRAIT 	0x0400
#define SCENEMODE_BACKLIT 			0x0800
#define SCENEMODE_MANUAL 			0x8000
#endif

// JPEG
void StartJpegEncoder(U8 byStreamID);
void StopJpegEncoder(void);
void JpegResolutionNorm(U16 wFormat, U16 * pwWidth, U16 * pwHeight);

// property page
void ExposureTimeSet(U32 dwSetValue);
void ExposureTimeAutoSet(U8 bySetValue);
void LowLightCompSet(U8 bySetValue);
void WhiteBalanceTempSet(U16 wSetValue, U16 wRGain, U16 wGGain, U16 wBGain, bit bIsTemperature);
void BrightnessSet(S8 sbySetValue);
void ContrastSet(U8 bySetValue);
void SaturationSet(U8 bySetValue);
void HueSet(S16 swSetValue);
void SharpnessSet(U8 bySetValue);
void GammaSet(U16 wSetValue);
void BackLightCompSet(U8 bySetValue);
void GainSet(U8 bySetValue);
void PwrLinFreqSet(U8 bySetValue);
void WhiteBalanceModeSet(U8 setValue);
void PanTiltSet(S8 sbyPanSetValue, S8 sbyTiltSetValue);
void ZoomSet(U8 bySetValue);
void RollSet(U8 bySetValue);
void FocusSet(U16 wSetValue);
void FocusAutoSet(U8 bySetValue);
void ExpTimeSet(S8 sbySetValue);
void SetBKSpecailEffect(U8 byEffect);
void	SetBkHueRT(S16 swSetValue);
void SetBKSpecailEffect(U8 byEffect);

void SetISPSpecailEffect(U16 wEffect);
void SetEVCompensation(S16 wEVCompValue, S16 wEVCompRes);
void SetISO(U16 wISOValue);
U16 ColorTemperature(void);
void CloseFlash(void);
void SetLEDTorch(U8 byTorchMode, U8 byIntensity);
void SetLEDFlash(U8 byFlashMode, U8 byIntensity);
void StartLEDFlash(void);
void SetLedFlashISPParams(void);
void RecoverISPParams(void);
bit JudgeNeedFlash(void);
void FlashCapturePro(void);
void SetROI(U16 wWinTop, U16 wWinLeft, U16 wWinBottom, U16 wWinRight, U16 bmWinControls);
U8 GetAEStatus(void);
U8 GetAWBStatus(void);
U8 GetAFStatus(void);
void SetSceneMode(U16 wSceneModeDes);


// IspPro
void InitIspParamsByResolution(void);
void SF_IRQ_InitISP(void);
void SF_IRQ_InitISPHW(void);
void InitISP(void);
void ISP_Main(void);
void ISPProInterrupt(void);
void ISPProHwTimerInt(void);
void SetDynISPBaseAEGain(U16 wAEC_Gain);
void SetDynISPBaseColorTemp(U16 wColorTempature);
void SetBackendISP(U8 byStreamID, U16 wSensorWidth, U16 wSensorHeight, U16 wUsbWidth, U16 wUsbHeight, U16 wFormat, U8 byOpenSensor);
void InitIspInterrupt(void);
void ISP3AStart(void);
void ISP3AStop(void);
void WaitFrameSync(U8 byISPINTNum, U8 byWaitSignal);
void ClearIspIntAll(void);
U8 SetIspOutputFmt(U8 byStreamID, U8 byIspOutputFmt);
void ManualIQParameter(U8 byIdx);
void UpdateIQParameter(U8 byIRModeEn, bit bForceUpdate);

// Isp Var
void Init_ISP_GlobalVars(void);

//AE
void SetISPAEGain(float fTotalGain, float fSnrGain, U8 byDelayFrm);
float GetISPGain(void);
U8 SetISPGain(U16 uISPGain, U8 byDelayFrm);
void SetExpTime_Gain(float fAE_Value);

//AWB
void SetBKAWBGain(U16 wRGain,U16 wGGain,U16 wBGain,U8 byflag);

// IspHal
void SetBLCWindowStart(U16 const wHorStart, U16 const wVerStart);

// Zoom
void EnableZoom(U8 byStreamID, U8 byEnableFlag);

// OSD
void DisableOSD(U8 byStreamID);

//For CPU interface
U8 GetCoordinateInfo(U8 byCmdType, U8 byStreamID);

// Motion Detect
U8 MtdCmdPro(U8 bySubCmd, U8 byMtdIdx, U8 byLen ,U16 wFirstBlkIndex, U16 wBlkNum);

// Private Mask
U8 MaskCmdPro(U8 bySubCmd, U8 byStreamID, U8 byLen ,U16 wFirstBlkIndex, U16 wBlkNum);

// OSD
U8 OSDCmdPro(U8 bySubCmd, U8 byStreamID, U8 byLen, U16 wAddr);

// TPNR
void EnableTPNR(U8 byEn);

// Other ISP
U8 OtherISPCmdPro(U8 bySubCmd, U8 byIdx, U8 byLen);
void DisableDehaze(void);
void EnableLDC(void);
void SetStreamsFRC(U8 byFrm0, U8 byFrm1, U8 byFrm2, U8 byFrm3, U8 byFrm4);

#endif 	//_ISP3_LIB_H_
