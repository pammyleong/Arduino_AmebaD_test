#ifndef _GLOBALISPVARLIB_H_
#define _GLOBALISPVARLIB_H_


// ISP module global variable declare
// These variables may be used in other module

// scence detect
#ifdef _OUTDOOR_AWB_BOUNDARY_
extern Dyanmic_AWB_Boundary_t code gc_AWBDynmaicBoundary;
#endif
#ifdef _OUTDOOR_CCM_
extern S16 g_aCCM_Outdoor[9];
#endif

// Low Light Dynamic Saturation
extern U8 g_byCurSaturationRatio;

//CCM
extern S16 g_aCCM[9];
extern S16 g_aCCM_Normal[9];
extern S16 g_aCCM_Low[9];
extern U8 g_byCCMState;
extern S16 g_aCCMTarget[9];

//BLC
extern U8 g_byoffsetR;
extern U8 g_byoffsetG1;
extern U8 g_byoffsetG2;
extern U8 g_byoffsetB;

// windowing
extern U16 g_wSensorWidthBefBLC;
extern U16 g_wSensorHeightBefBLC;

//Gamma
extern U8 g_aGamma_Def[28];
extern U8 g_aCTC_Gamma[28];
extern U8 g_aGammaTarget[28];

//ygamma
extern U8 g_Ygamma[16];

//Sharpness
extern U8 g_bySharpParamIndex_Last;
extern U8 g_bySharpParamIndex_Cur;
extern U8 g_bySharp_EdgeDct_Thd1;
extern U8 g_bySharp_VIIR_G_Coef;
extern U8 g_bySharp_HLPF_G_Coef;
extern U8 g_bySharp_VIIR_RB_Coef;
extern U8 g_bySharp_HLPF_RB_Coef;

// Jpeg
#ifdef _ENABLE_MJPEG_
extern U8 g_byJpeg_ACRA_En;
extern U8    g_byQtableScale;
#endif //_ENABLE_MJPEG_

// Others
extern U8 g_bySaturation_Def;
extern U8 g_bySharpnessH_Def;
extern U8 g_bySharpnessV_Def;
extern U16 g_wDynamicISPEn;
extern S8 g_byU_Offset_Normal;
extern S8 g_byV_Offset_Normal;

// LSC
extern U8 g_bySubResolution_For_LSC;
extern U8 g_byDynamicLSCSet;
extern U8 g_byLastIllumCT;
#ifdef _MULTIPLE_LSC_CONFIG_
extern U8 g_byLSCCurve_Idx;
#endif

//LDC
extern U32 g_ldc_scalecoff0;
extern U32 g_ldc_scalecoff1_cx_square;
extern U16 g_ldc_x_inv0;
extern U32 g_ldc_x_inv1_cx;
extern U32 g_ldc_y_inv0;
extern U32 g_ldc_y_inv1_cy;
extern U16 g_ldc_x_center;
extern U16 g_ldc_y_center;
extern U32 g_ldc_x0_cx_square;
extern U32 g_ldc_y0_cy_square;
extern U8 g_byLDCEnable;

// HDR

// 3A Lock
extern U8 g_byAWBLock;
extern U8 g_byAFLock;

// Flash LED
extern U8 g_byLEDTorchSteps;
extern U8 g_byLEDFlashSteps;
extern U8 g_byFlashCaptureStatus;

//
extern U8 g_byAEKeepLastMode;

// Dark Mode
extern U8 g_byLastYGain;
extern U8 g_byLastUGain;
extern U8 g_byLastVGain;

// IR Mode
extern U8 g_byIRModeEn;
extern IspParaDayNightSwitch_t IspParaSwitch; 

// IQ table
extern IQ_Gamma_t g_byIQGamma;
extern IQ_Texture_Denoise_Th_t g_byIQDenoiseTh;
extern IQ_UV_Color_Tune_t g_byIQUVColorTune;
extern IQ_NLC_t g_byIQNLC;
extern IQ_LSC_Dynamic_t g_sLscDyn;
#ifdef _SCENE_MODE_
extern SceneModePrm_t code tSceneModePrm;
#endif

#endif //_GLOBAL_VARS_H_
