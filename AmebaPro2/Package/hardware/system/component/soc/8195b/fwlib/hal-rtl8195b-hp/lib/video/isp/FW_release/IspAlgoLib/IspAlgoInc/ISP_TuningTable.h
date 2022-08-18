#ifndef _ISP_Tuning_IQ_H_
#define _ISP_Tuning_IQ_H_

#define IQ_TEXTURE_PARAM_GROUPS		8
#define IQ_TEXTURE_PARAM_MAX_NUMS	170

typedef struct IQ_HEADER
{
	U8 byAPVersion;
	U16 wIQTableLength;
	U8 byIQVersionH;
	U8 byIQVersionL;
	U8 byReserved0;
	U8 byReserved1;
	U8 byReserved2;
} IQ_HEADER_t;

typedef struct IQ_BLC_Offset
{
	// BLC
	U8 byOffsetR;
	U8 byOffsetG1;
	U8 byOffsetG2;
	U8 byOffsetB;
} IQ_BLC_Offset_t;

typedef struct IQ_BLC
{
	IQ_BLC_Offset_t normal;
} IQ_BLC_t;

typedef struct IQ_LSC_Circle
{
	// Circle LSC
	U8 abyCurve[4][48];
	U16 awCenter[8];
	U8 byStep;
} IQ_LSC_Circle_t;

typedef struct IQ_LSC_Micro
{
	// Micro LSC
	U8 byGridmode;
	U8 abyMatrix[4][3][320];
} IQ_LSC_Micro_t;

typedef struct IQ_LSC_PARA
{
	IQ_LSC_Circle_t nlsc;
	IQ_LSC_Micro_t mlsc;
} IQ_LSC_PARA_t;

typedef struct IQ_LSC_Dynamic
{
	U16 wGainThL;
	U16 wGainThH;
	U8 byAdjustRateL;
	U8 byAdjustRateH;
	U8 abyGainR[6];
	U8 abyGainB[6];
	U8 byStartThd;
	U8 byStopThd;
	U16 wColorTempBuffer;
	U16 awColorTempTh[5];
	U8 abyRatebyCT[6][3];
}IQ_LSC_Dynamic_t;

typedef struct IQ_LSC
{
	IQ_LSC_PARA_t lsc_2M;
#ifdef _MULTIPLE_LSC_CONFIG_
	IQ_LSC_PARA_t lsc_5M;
	IQ_LSC_PARA_t lsc_8M;
#endif	
	IQ_LSC_Dynamic_t dynamic;
} IQ_LSC_t;

typedef struct IQ_CCM_PARA
{
	S16 aswCCM[4][9];
} IQ_CCM_PARA_t;

typedef struct IQ_CCM_LS_TH
{
	U16 wDynamicD65CWF_ThH;
	U16 wDynamicD65CWF_ThL;
	U16 wDynamicCWFA_ThH;
	U16 wDynamicCWFA_ThL;
	U16 wDynamicCCMAHzn_ThH;
	U16 wDynamicCCMAHzn_ThL;
} IQ_CCM_LS_TH_t;

typedef struct IQ_CCM_AEGAIN_TH
{
	U16 wDynamicLumaGainThL;
	U16 wDynamicLumaGainThH;
} IQ_CCM_AEGAIN_TH_t;

typedef struct IQ_CCM
{
	// CCM
	S16 aswNormal[4][9];
	S16 aswLow[4][9];
	IQ_CCM_LS_TH_t lsth;
	IQ_CCM_AEGAIN_TH_t aeth;
} IQ_CCM_t;

typedef struct IQ_Gamma
{
	// Gamma
	U8 abyNor[28];
	U8 abyLowlux[28];
	U16 wDynamicGainThL;
	U16 wDynamicGainThH;
} IQ_Gamma_t;

typedef struct IQ_AE_Target
{
	// jack_hu 2012-08-16: AE4.0 parameters
	U16 wHistRatio_L;
	U16 wHistRatio_H;
	U8 byMeanTarget_L;
	U8 byMeanTarget;
	U8 byMeanTarget_H;
	U8 byHistPosTh_L;
	U8 byHistPosTh_H;
	U8 byDynamicMeanDecExtent;
} IQ_AE_Target_t;

typedef struct IQ_AE_Limit
{
	U8 byMaxStep50Hz;
	U8 byMaxStep60Hz;
	U16 wGlobalgainmax;		// hemonel 2011-12-05: IQ version 2 only modify these field
	U16 wGainTh_ContFps[5];
	U8 byManualMinFps;
	U16 wGainTh_15fps;
	U16 wGainTh_30fps;
	U8 byHighLightModeTh;
} IQ_AE_Limit_t;

typedef struct IQ_AE_Weight
{
	U8 byWeight[25];
} IQ_AE_Weight_t;

typedef struct IQ_AE_Sensitivity
{
	float fAdjustTh; // jack_hu 2012-08-16: AE4.0 parameters
	U8 byLatency;
	U8 bySameBlockDiffTh;
	U8 bySameBlockNumTh;
} IQ_AE_Sensitivity_t;

struct iq_ae_fast {
	float fAE_fast_adjstep_greater_th_pow;
	float fAE_fast_adjstep_greater_th_h;
	float fAE_fast_adjstep_greater_th_m;
	float fAE_fast_adjstep_greater_th_l;
	float fAE_fast_adjstep_less_th_l;
	float fAE_fast_adjstep_less_th_h;
	float fAE_fast_adjstep_less_th_pow;
};

struct iq_ae_slow {
	float fAE_slow_adjstep_less_th_l;
	float fAE_slow_adjstep_less_th_m;
	float fAE_slow_adjstep_less_th_h;
	float fAE_slow_adjstep_greater_th_l;
	float fAE_slow_adjstep_greater_th_m;
	float fAE_slow_adjstep_greater_th_h;
};

typedef struct IQ_AE
{
	IQ_AE_Target_t target;
	IQ_AE_Limit_t limit;
	IQ_AE_Weight_t weight;
	IQ_AE_Sensitivity_t sensitivity;
	struct iq_ae_fast fast_step;
	struct iq_ae_slow slow_step;
} IQ_AE_t;

typedef struct IQ_AWB_Simple
{
	U8 abyGainR[6];
	U8 abyGainB[6];
	U8 byK1;
	U16 wB1;
	U16 wB2;
	S8 sbyK3;
	S16 swB3;
	S8 sbyK4;
	S16 swB4;
	S8 sbyK5;
	S16 swB5;
	S8 sbyK6;
	S16 swB6;
	U16 wB_Up;
	U16 wB_Down;
	S16 swB_Left;
	S16 swB_Right;
	U8 byBright_Max;
	U8 byBright_Min;
	U16 wRGBSumMinLimit;
} IQ_AWB_Simple_t;

typedef struct IQ_AWB_Advanced
{
	U16 wPixelNumTh;
	U8 byRGMax;
	U8 byRGMin;
	U8 byBGMax;
	U8 byBGMin;
	U8 byYMax;
	U8 byYMin;
	U8 byFtGainTh;
} IQ_AWB_Advanced_t;

typedef struct IQ_AWB_Sensitivity
{
	U16 wGainDiffTh;
	U8 byGainStep;
	U8 byYmeanMinLimitTh;
	U8 byColorDiffTh;
	U8 byDiffWindowsTh;
} IQ_AWB_Sensitivity_t;

typedef struct IQ_AWB
{
	IQ_AWB_Simple_t simple;
	IQ_AWB_Advanced_t advanced;
	IQ_AWB_Sensitivity_t sensitivity;
} IQ_AWB_t;

typedef struct IQ_AF_PeakTh
{
	U32 dwPeakSharpTh;
	float fHighPeakRatioThFine;
	float fLowPeakRatioThFine;
	float fHighPeakRatioThRough;
	float fLowPeakRatioThRough;
} IQ_AF_PeakTh_t;

typedef struct IQ_AF_Sensitivity
{
	float fSharpDiffRatioTh;
	U8 byColorDiffTh;
	U8 byColorChangeBlockNumTh;
	U8 byDiffTimesTh;
	U8 byMoveColorThd;
	U8 byMoveBlockNumThd;
} IQ_AF_Sensitivity_t;

typedef struct IQ_AF_SearchParams
{
	U8 byTotalSteps;
	U16 wRoughEntrance_Th;
	U8 byFineStep;
	U8 byRoughStep;
	float fFineSearchSharpRatioTh;
	float fRoughSearchSharpRatioTh;
	U8 byDecreaseTimesTh_Fine;
	U8 byDecreaseTimesTh_Rough;
	U8 byDirChangeTimesTh;
	U8 byNGPos;
	U16 wPos[32];
} IQ_AF_SearchParams_t;

typedef struct IQ_AF
{
	U8 byStatisTh;
	IQ_AF_PeakTh_t peakth;
	IQ_AF_Sensitivity_t sensitivity;
	IQ_AF_SearchParams_t searchparams;
	U16 wDistance[32];
} IQ_AF_t;

typedef struct IQ_Texture_Denoise_Th
{
	U16 wDynamicGainTh[IQ_TEXTURE_PARAM_GROUPS-1];
}IQ_Texture_Denoise_Th_t;

typedef struct IQ_Texture_Sharpness
{
	U8 sharpness_h;
	U8 sharpness_v;
}IQ_Texture_Sharpness_t;

typedef struct REG
{
	U16 wAddr;
	U8 byValue;
} REG_t;

typedef struct IQ_Texture_Reg_Table
{
	REG_t reg[IQ_TEXTURE_PARAM_MAX_NUMS];
}IQ_Texture_Reg_Table_t;

typedef struct IQ_Texture
{	
	IQ_Texture_Denoise_Th_t th;
	IQ_Texture_Sharpness_t sharpness[IQ_TEXTURE_PARAM_GROUPS];
	IQ_Texture_Reg_Table_t static_param;
	IQ_Texture_Reg_Table_t dynamic_param[IQ_TEXTURE_PARAM_GROUPS];
} IQ_Texture_t;

typedef struct IQ_UV_Offset
{
	S8 byA_U;
	S8 byA_V;
	S8 byD65_U;
	S8 byD65_V;
	U16 wDynamicUV_A_Th;
	U16 wDynamicUV_D65_Th;
} IQ_UV_Offset_t;

typedef struct IQ_UV_Color_Tune
{
	U8 abyAUvColorTune[3][4];
	U8 abyD65UvColorTune[3][4];
	U16 wDynamicUV_A_Th;
	U16 wDynamicUV_D65_Th;
}IQ_UV_Color_Tune_t;

typedef struct IQ_NLC
{
	U8 byG[16];
	S8 byRDiff[16];
	S8 byBDiff[16];
}IQ_NLC_t;

typedef struct
{
	U8 bytgamma_th;
	U8 bytgamma_rate;
	U8 byhdr_lpf_coef[9];
	U8 byhdr_curver[28];
	U8 byhdr_step;
	U8 bylocal_constrast_curver[16];
	U8 bylocal_constrast_rate_min;
	U8 bylocal_constrast_rate_max;
	U8 bylocal_constrast_step;
#if ((_ISP_VERSION_ == _ISP_5_1_)||(_ISP_VERSION_ == _ISP_5_1_T_))
	U8 byisp_hdr_inc_rate_0;
	U8 byisp_hdr_inc_rate_1;
#endif
} IQ_HDR_REG_t;

typedef struct
{
	U16 byHistDevMin;
	U16 byHistDevMax;
	U16 byLowPartPctMin;
	U16 byLowPartPctMax;
	float abyHistDistWt[10];
} IQ_HDR_Dynamic_t;

typedef struct
{
	IQ_HDR_REG_t hdrreg;
	IQ_HDR_Dynamic_t hdrdmc;
} IQ_HDR_t;

typedef struct IQ_LDC
{
	U32 ldc_scalecoff0;
	U32 ldc_scalecoff1_cx_square;
	U16 ldc_x_inv0;
	U32 ldc_x_inv1_cx;
	U32 ldc_y_inv0;
	U32 ldc_y_inv1_cy;
	U16 ldc_x_center;
	U16 ldc_y_center;
	U32 ldc_x0_cx_square;
	U32 ldc_y0_cy_square;
	U8 ldc_en;
} IQ_LDC_t;

typedef struct
{
	U16 wGainThL;
	U16 wGainThH;
	U8 byAdjustRateL;
	U8 byAdjustRateH;
	U8 abyRate[3];
}IQ_LSC_IR_t;

typedef struct
{
	IQ_AE_Target_t target;
	IQ_AE_Weight_t weight;
} IQ_AE_IR_t;

typedef struct
{
	IQ_LSC_IR_t IRlsc;
	IQ_AE_IR_t IRae;
	IQ_CCM_t IRccm;
	IQ_Gamma_t IRgamma;
	IQ_Texture_t IRtexture;	
}IQ_IR_t;

typedef struct IQTABLE
{
	IQ_HEADER_t header;
	IQ_BLC_t blc;
	IQ_LSC_t lsc;
	IQ_CCM_t ccm;
	IQ_Gamma_t gamma;
	IQ_AE_t ae;
	IQ_AWB_t awb;
	IQ_AF_t af;
	IQ_Texture_t texture;
	IQ_UV_Color_Tune_t uvcolortune;
	IQ_UV_Offset_t uvoffset;
	IQ_NLC_t nlc;
	IQ_HDR_t hdr;
	IQ_LDC_t ldc;
	IQ_IR_t ir;
}IQTABLE_t;

#define IQ_TABLE_AP_VERSION	0x1A	// this version sync FW IQ table with IQ tuning AP

#ifdef _SCENE_MODE_
typedef struct SceneModePrmDiff
{
         //AWB parameter
	U16  wAWBRGainShiftRate;
	U16  wAWBBGainShiftRate;
         //AF parameter
	U8 	byAFPosStart;
	U8 	byAFPosEnd;
         //Other parameter
} SceneModePrmDiff_t;
typedef struct ScenemodePrm
{
	//used in snow mode
	U8 bySnowModeAETargetShiftRate;
	U8 byBacklitModeAETargetShiftRate;
	//used in candlelight mode
	U16	wCandlelightAWBGainR;
	U16	wCandlelightAWBGainB;
	//used in candle light mode
	S8	sbyAWB_K3;
	S16	swAWB_B3;
	S8	sbyAWB_K4;
	S16	swAWB_B4;
	S8	sbyAWB_K5;
	S16	swAWB_B5;
	S8	sbyAWB_K6;
	S16	swAWB_B6;
	S16	swAWB_B_left;
	S16	swAWB_B_right;
	//used in defferent mode
	SceneModePrmDiff_t tSceneModePrmDiff[12];
}SceneModePrm_t;
#endif

// other ISP IQ struct without ISP table
#ifdef _OUTDOOR_AWB_BOUNDARY_
typedef struct Dyanmic_AWB_Boundary
{
		S8 byAWB_K3;
		S16 wAWB_B3;
		S8 byAWB_K4;
		S16 wAWB_B4;
		S8 byAWB_K5;
		S16 wAWB_B5;
		S8 byAWB_K6;
		S16 wAWB_B6;
} Dyanmic_AWB_Boundary_t;
#endif

typedef struct IspParaDayNightSwitch
{
	IQ_CCM_t*		pIQTableccm;
	IQ_Texture_t* 	pIQTableTexture;
}IspParaDayNightSwitch_t;

#endif
