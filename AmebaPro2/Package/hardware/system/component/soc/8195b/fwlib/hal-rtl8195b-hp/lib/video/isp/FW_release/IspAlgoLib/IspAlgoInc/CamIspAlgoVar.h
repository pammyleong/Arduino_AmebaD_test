#ifndef _ISPALGOVAR_H_
#define _ISPALGOVAR_H_


// AWB
extern U8 g_aAWBRoughGain_R[6];
extern U8 g_aAWBRoughGain_B[6];
extern U8 g_byAWB_K1;
extern U16 g_wAWB_B1;
extern U16 g_wAWB_B2;
extern S8 g_byAWB_K3;
extern S16 g_wAWB_B3;
extern S8 g_byAWB_K4;
extern S16 g_wAWB_B4;
extern S8 g_byAWB_K5;
extern S16 g_wAWB_B5;
extern S8 g_byAWB_K6;
extern S16 g_wAWB_B6;
extern U16 g_wAWB_B_Up;
extern U16 g_wAWB_B_Down;
extern S16 g_swAWB_B_Left;
extern S16 g_swAWB_B_Right;
extern U8 g_byAWB_Win_Bright_Max;
extern U8 g_byAWB_Win_Bright_Min;
extern U16 g_wAWB_RGB_SumTh;
extern U16 g_wTemPixelNumThread_L;
extern U8 g_byAWBFineMax_RG;
extern U8 g_byAWBFineMin_RG;
extern U8 g_byAWBFineMax_BG;
extern U8 g_byAWBFineMin_BG;
extern U8 g_byAWBFineMax_Bright;
extern U8 g_byAWBFineMin_Bright;
extern U8 g_byFtGainTh;
extern U16 g_wAWBGainDiffTh;
extern U8 g_byAWBGainStep;
extern U8 g_byAWBFixed_YmeanTh;
extern U8 g_byAWBColorDiff_Th;
extern U8 g_byAWBDiffWindowsTh;
extern U8 g_byAWB_WinMeanR[5][5];
extern U8 g_byAWB_WinMeanG[5][5];
extern U8 g_byAWB_WinMeanB[5][5];
extern U8 g_byAWBWin_Rgain_FirstProject[5][5];
extern U8 g_byAWBWin_Bgain_FirstProject[5][5];
extern U8 g_byAWBWin_Brightness[5][5];
extern U16 g_wProjectGR;
extern U16 g_wProjectGB;
extern U16 g_wGWLastGR;
extern U16 g_wGWLastGB;
extern U16 g_wFtGR;
extern U16 g_wFtGB;
extern U16 g_wAWBFinalGainR;
extern U16 g_wAWBFinalGainB;
extern U16 g_wAWBRGain_Last;
extern U16 g_wAWBGGain_Last;
extern U16 g_wAWBBGain_Last;
extern U8 g_byAWBWinInitRGain[5][5];
extern U8 g_byAWBWinInitBGain[5][5];
extern U8 g_byISPAWBStaticsEn;
extern U8 g_byAWBStatus;
extern U8 g_byAWBEnterStableDelay;
extern U8 g_byAWB_Hold;
extern U8 g_byAWB_SameBlock_Hold;
extern U8 g_byAWBDiffWindows;
extern U16 g_wAWBSTnum;
extern U8 g_byAWBExitStableDelay;
extern U8 g_byAWBStableDelay_Cfg;
extern U16 g_wAWBColorTemperature;
extern U8 g_byAWBToolFlag;
extern U8 g_abyColorTemperatureTable_gain[6];

#ifdef _AWB_6_0_
extern float g_fAWBSatRange;
extern U8 g_byAWBSatMax;
extern S16 g_wAWB_B7;
extern S16 g_wAWB_B8;
extern S16 g_wAWB_B9;
extern S16 g_wAWB_B10;
extern S16 g_wAWBCluster_B1;
extern S16 g_wAWBCluster_B2;
#endif // _AWB_6_0_

#ifdef _AWB_STABLE_WHITEPOINT_
//restrict fine tune gain
extern U8 g_byProjectGBDiff;
extern U8 g_byProjectGRDiff;
extern U8 g_byProjectGBDiffTh;
extern U8 g_byProjectGRDiffTh;
extern U16 g_wProjectGBLast;
extern U16 g_wProjectGRLast;
extern U16 g_wFtGBLast;
extern U16 g_wFtGRLast;
extern U8 g_byFtGainPos;
extern U8 g_byFtGainPosLast;
#endif // _AWB_STABLE_WHITEPOINT_

#ifdef _AWB_DECOLORBLOCK_
extern U8 g_byAWBBin1Count;
extern U8 g_byAWBBin2Count;
extern U8 g_byAWBBin3Count;
extern U8 g_byAWBBin4Count;
extern U8 g_byAWBBin1GBAvg;
extern U8 g_byAWBBin1GRAvg;
extern U8 g_byAWBBin2GBAvg;
extern U8 g_byAWBBin2GRAvg;
extern U8 g_byAWBBinAvgDiffMax;
extern U8 g_byAWBBin1Diff;
extern U8 g_byAWBBin2Diff;
extern U8 g_byAWBBinAvgDiff[2];
extern U8 g_byAWBClusterLine;
extern U8 g_byAWBClusterRate1;
extern U8 g_byAWBClusterRate2;
extern U8 g_byAWBDeClusterStrength1L;
extern U8 g_byAWBDeClusterStrength1M;
extern U8 g_byAWBDeClusterStrength1R;
extern U8 g_byAWBDeClusterStrength2;
extern S8 byAWBClusterCWFStrength;
extern U16 g_wAWBDeClusterGB1;
extern U16 g_wAWBDeClusterGR1;
extern U16 g_wAWBDeClusterGB2;
extern U16 g_wAWBDeClusterGR2;
extern U8 g_byDeClusterGainTh;
#endif // _AWB_DECOLORBLOCK_

extern U8 g_byAWBWinLastGR[5][5];
extern U8 g_byAWBWinLastGB[5][5];

extern U8 g_byAWBStage;
extern U8 g_byAWBStart;
extern U32 g_dwISP_AWB_FINE_SUM_R;
extern U32 g_dwISP_AWB_FINE_SUM_G;
extern U32 g_dwISP_AWB_FINE_SUM_B;
extern U32 g_dwISP_AWB_FINE_WP_NUM;
extern U32 g_adwISP_AWB_WP_NUM[6];


// AE
extern float g_fAE_fast_adjstep_greater_th_pow;
extern float g_fAE_fast_adjstep_greater_th_h;
extern float g_fAE_fast_adjstep_greater_th_m;
extern float g_fAE_fast_adjstep_greater_th_l;
extern float g_fAE_fast_adjstep_less_th_l;
extern float g_fAE_fast_adjstep_less_th_h;
extern float g_fAE_fast_adjstep_less_th_pow;
extern float g_fAE_slow_adjstep_less_th_l;
extern float g_fAE_slow_adjstep_less_th_m;
extern float g_fAE_slow_adjstep_less_th_h;
extern float g_fAE_slow_adjstep_greater_th_l;
extern float g_fAE_slow_adjstep_greater_th_m;
extern float g_fAE_slow_adjstep_greater_th_h;
extern U16 g_wYpercentage_Th_L;
extern U16 g_wYpercentage_Th_H;
extern U8 g_byAEC_Mean_Target_L;
extern U8 g_byAEC_Mean_Target;
extern U8 g_byAEC_Mean_Target_H;
extern U8 g_byAEC_HistPos_Th_L;
extern U8 g_byAEC_HistPos_Th_H;
extern U8 g_byAE_Hist_MeanTargetDec_Extent;
extern U8 g_byAEMaxStep50Hz;
extern U8 g_byAEMaxStep60Hz;
extern U16 g_wAECGlobalgainmax;
extern U16 g_wAEC_ContFps_Th[5];
extern U8 g_byAEC_ManualMinFps;
extern U16 g_wAEC_Gain_Threshold_15fps;
extern U16 g_wAEC_Gain_Threshold_30fps;
extern U8 g_byAEC_HighLight_Thread;
extern U8 g_byAE_WinWeight[25];
extern float g_fAEC_Adjust_Th;
extern U8 g_byAE_Delay_Cfg;
extern U8 g_byAEC_Stable_BlockDiffTh;
extern U8 g_byAEC_Stable_BlockNumTh;
extern U8 g_byAEC_Control;
extern U8 g_byAEDecreaseRate;
extern U8 g_byAEMeanValue;
extern U8 g_byAEC_HistPos_L;
extern U8 g_byAEC_HistPos_H;
extern U8 g_byAE_OverExpTargetDecVal;
extern U16 g_wAE_Hist_StNum[64];
extern U8 g_byAE_WinYMean[25];
extern U8 g_byAEC_Backlight_Ratio;
extern U16 g_wAECExposureRowMax;
extern U16 g_wAEC_LineNumber;
extern U8 g_byAEC_Mode;
extern U8 g_byAECStatus;
extern float g_fSensorRowTimes;
extern float g_fAEC_EtGain;
extern U16 g_wAFRInsertDummylines;
extern float g_fCurExpTime;
extern float g_fAEC_SmoothExpectYmeanCmp_all;
extern float g_fAEC_SetEtgain;
extern U8 g_byAEC_AdjustStatus;
extern float g_fAEC_Min_ExpTime;
extern U8 g_byAEForce_Adjust;
extern U8 g_byISPAEStaticsEn;
extern U8 g_byAE_Stable_WinYMean[25];
extern U8 g_byAE_StableOut_DelayCnt;
extern float g_fAEC_Gain;
extern U16 g_wAEC_CurGain_Threshold_15fps;
extern U16 g_wAEC_CurGain_Threshold_30fps;
extern float g_fAEC_HistPos_LH_Target;
extern float g_fAEC_HistPos_LH_Target_Th;
extern float g_fAEC_HighContrast_Exp_L;
extern U32 g_dwHistTotalNum;
extern U8 g_byAEFreeWinEnable;
extern U32 g_dwAEFreeWinSize;
extern U16 g_wAEStatWinStartX;
extern U16 g_wAEStatWinStartY;
extern U16 g_wAEStatWinWidth;
extern U16 g_wAEStatWinHeight;
extern U16 g_wSTnum;
extern U8 g_byFirstStatic;

#ifdef _AE_NEW_SPEED_ENABLE_
extern U8 g_byAE_SpeedMode;
extern U8 g_byAE_LastStatus;
extern U8 g_byAESpeedSelect;
#else
extern U8 g_byAEC_AdjustMode;
#endif
extern U8 g_byAE_StaticsDelay;

#ifdef _FACIAL_EXPOSURE_
extern U16 g_wZoomStartX;
extern U16 g_wZoomStartY;
extern U16 g_wZoomScale_h;
extern U16 g_wZoomScale_v;
extern U16 g_wAE_WinStartX;
extern U16 g_wAE_WinStartY;
extern U16 g_wAE_WinWidth;
extern U16 g_wAE_WinHeight;
extern U8 g_byAEFaceWindowSet;
extern U8 g_bySimilar;
extern U8 g_bySimilar_last;
extern U8 g_byFaceExposure_En;
extern U8 g_byFaceLostTime;
#endif

#ifdef _FACIALAEWINSET_XU_
extern U8 g_byXU_FacialAEWin_Set;
extern U8 g_byaFacial_AE_Parameters[7];
#endif

extern float g_fAEC_EtGain_Max;

#ifdef _NEW_AE_HIGHLIGHT_EXIT_MODE_
extern U8 g_byAEAdjStepSel;
extern U8 g_byHighLightModeStatus;
extern U8 g_byAEC_HighLight_ExitThread;
#endif

extern U8 g_byLastFps;
extern float g_fEtMax;

extern U16 g_wAELastStatWinStartX;
extern U16 g_wAELastStatWinStartY;
extern U16 g_wAELastStatWinWidth;
extern U16 g_wAELastStatWinHeight;
extern U16 g_wAEC_ManualIQGain;
extern U32 g_dwSnrCurExpTime;
extern S8 g_sbyAEC_Mean_Target_Delta;

extern U8 code gc_byAE_WinWeight[25];

#ifdef _BACKLIT_DYN_AE_WEIGHT_
extern U8 code g_byAE_WinWeight_center[25];
extern U8 code g_byAE_WinWeight_spot[25];
#endif


// AF
extern U8 g_byAFStatisTh;
extern U32 g_dwAF_PeakSharpTh;
extern float g_fAFHighPeakRatioThFine;
extern float g_fAFLowPeakRatioThFine;
extern float g_fAFHighPeakRatioThRough;
extern float g_fAFLowPeakRatioThRough;
extern float g_fAF_SharpDiff_Ratio_Th;
extern U8 g_byAF_ColorDiff_Th;
extern U8 g_byAFColorChangeBlockNumTh;
extern U8 g_byAFDiffTimes_Th;
extern U8 g_byAFMoveColor_Thd;
extern U8 g_byAFMoveBlockNum_Thd;
extern U8 g_byAFTotalSteps;
extern U16 g_wAFRoughEntrance_Th;
extern U8 g_byAF_FineStep;
extern U8 g_byAF_RoughStep;
extern float g_fAFFineSearchSharpRatioTh;
extern float g_fAFRoughSearchSharpRatioTh;
extern U8 g_byAF_DecreaseTimesTh_Fine;
extern U8 g_byAF_DecreaseTimesTh_Rough;
extern U8 g_byAFDirChangeTimes_Th;
extern U8 g_byAF_NGPos;
extern U16 g_wAFPos[32];
extern U8 g_byAFControl;
extern U8 g_byAFStatus;
extern U32 g_dwAFCurrentSharp;
extern U32 g_dwAFSharpLast1;
extern U32 g_dwAFSharpLast2;
extern U32 g_dwAFSharpLast3;
extern U32 g_dwAFSharpLast4;
extern U32 g_dwAFLocalValleySharpness;
extern U32 g_dwAF_LocalPeakSharp;
extern U32 g_dwAFStableSharpness;
extern float g_fAFSharpChange;
extern U16 g_wAF_CurPosition;
extern U8 g_byAFPosIndex;
extern U8 g_byAFPosIndexLast1;
extern U8 g_byAFPosIndexLast2;
extern U8 g_bySearchingDir;
extern U8 g_byAFSearchDirectionChangeTimes;
extern U8 g_byAFSearchTimes;
extern U8 g_byAFSearchStep;
extern float g_fAFHighPeakRatioTh;
extern float g_fAFLowPeakRatioTh;
extern float g_fAF_SearchSharpRatioTh;
extern U8 g_byAF_DecreaseTimesTh;
extern U8 g_byAF_IsDecreasing;
extern U8 g_byAF_DecreaseTimes;
extern U8 g_byAF_IncreaseTimes;
extern U8 g_byAF_CertainPosIndex;
extern U8 g_byAF_LocalPeakPosIndex;
extern U8 g_byAFMaxSharpPos;
extern U32 g_dwAFMaxSharpness;
extern U8 g_byAFStablePosIndex;
extern U8  g_byAFSharpDiffStatTimes;
extern U8  g_byAFColorDiffStatTimes;
extern U8  g_byAFStable_RMean[5][5];
extern U8  g_byAFStable_GMean[5][5];
extern U8  g_byAFStable_BMean[5][5];
extern U8 g_byIsMoving;
extern U8 g_byAFSearchMinPos;
extern U8 g_byAFSearchMaxPos;
extern U8 g_byAF_CurPosIndex;
extern U8 g_byAFTraverseMode;
extern U16 g_wAFTraversePos;
extern U32 g_dwISP_AF_SUM0;
extern U32 g_dwISP_AF_SUM1;
extern U32 g_dwISP_AF_NUM0;
extern U32 g_dwISP_AF_NUM1;
extern U32 g_adwWinChangeSum[5][5];

//wade added
extern U8 g_byAFPosIndexLast3;
extern U8 g_byAFPosIndexLast4;
extern U16 g_wAF_CertainPos;
extern U32 g_dwAFColorDiffBlk;
extern U32 g_dwAFCurrentSharpBlockBase;
extern U8 g_byAFColorDiffBlockCount;
extern U8 g_byBlkChoose;
extern U8 g_bySmallBlkUpBound;
extern U8 g_bySmallBlkLowBound;



// AB
extern U8 g_byISPABStaticsEn;
extern U8 g_byABLastWinYMean[25];
extern U8 g_byABPresentWinYMean[25];
extern U8 g_byABBypassThreshold;
extern U8 g_byABStableBlockDiffTh;
extern U8 g_byABDetectClass;
extern U8 g_byABOutDoor;
extern U8 g_byABFlickerUnDetectCnt;
extern U8 g_byABFlickerDetectCnt;
extern U8 g_byABCurrentStep;
extern U8 g_byABRatioThreshold;
extern U8 g_byABRatioMaxThreshold;
extern U8 g_byABRatioThirdThreshold;
extern U8 g_byABRatioSecThreshold;
extern U8 g_byABRatioMinThreshold;
extern U8 g_byABDctCntThreshold;
extern U8 g_byABIFExceedFpsThreshold;
extern U8 g_byABDummylines;
extern U8 g_byABDetectMinFps;
extern U8 g_byABDetectMaxGain;
extern U8 g_byABDynamicDctCntSetting;
extern U8 g_byABStaticDctCntSetting;
extern U8 g_byABCurPowerLine;
extern U8 g_byABDetectStatis;
extern U8 g_byABDetectType;
extern U8 g_byABDetectCount;
extern U8 g_byABStart;
extern U8 g_byABIfFlickExist;
extern U32 g_byABRatioSum;
extern U32 g_byABLastRatioSum;
extern U32 g_dwSumX;
extern U32 g_dwSum127;
extern U8 g_byABBypass;


// AS
#ifdef _ENABLE_OUTDOOR_DETECT_
extern U8 g_byOutdoorET;
extern U8 g_byIndoorET;
extern U8 g_byOutDoorScene;
extern U8 g_byOutdoorModeEnter_Thd;
extern U8 g_byOutdoorModeExit_Thd;
#endif
extern U8 g_byWhiteScene;
extern U8 g_byWhite_Edge_TH;
extern U8 g_byWhite_Edge_HD_TH;
extern U8 g_byWhite_Edge_Dark_TH;
extern U8 g_byWhite_Edge_Block_TH;
extern U8 g_byWhite_Edge_Block_Dark_TH;
extern U8 g_byAddAE_U;
extern U8 g_byYellowScene;


// WDR
extern U8 g_byHDRLevel;
extern U8 g_byNonLow10Avg;
extern U8 g_byLow10Avg;
extern U8 g_byHistContrast;
extern U8 g_byWDRTarget_orig;
extern U8 g_byWDR_Disable;
extern U8 g_byForceHDRlevel;
extern U8 g_byWDREnhance;
extern U8 g_byWDRTarget;
extern U8 g_byWDRLack;
extern U8 g_byForceWDRLack;
extern U8 g_byWDRGammaLevel;
extern U8 g_byForceWDRTarget;
extern U8 g_byWDRGammaDisable;
extern U8 g_byCenterDarkWt;
extern U8 g_byCenterDarkEnhance;
extern U8 g_byWDRCenterEnhanceDisable;
extern U8 g_byCenterBrightness;
extern U8 g_bySideBrightness;
extern U8 g_byForceCenterDarkEnhance;
extern U8 g_byWDRTargetOrigUp;
extern U8 g_byWDRTargetOrigDown;
extern U32 g_dwLow10Num;
extern U8 g_byLAvg;
extern U8 g_byRAvg;
extern U8 g_byHDRLevelNOW;
extern U8 g_byWDRTargetLimit;
extern U8 g_byWDRLackStepUp;
extern U8 g_byWDRLackStepDown;
extern U8 g_byWDRStepUp;
extern U8 g_byWDRStepDown;
extern U8 g_byWDR_AECEnhanceEnable;
extern U8 g_byWDR_AECEnhance;
extern U8 g_byWDR_AECEnhanceThH;
extern U8 g_byWDR_AECEnhanceThL;
extern U8 g_byAEC_Mean_TargetOrig;
extern U8 g_byAEC_Mean_Target_LOrig;
extern U8 g_byAEC_Mean_Target_HOrig;
extern U8 g_byAEC_Mean_Target_WDR;
extern U8 g_byAEC_Mean_Target_L_WDR;
extern U8 g_byAEC_Mean_Target_H_WDR;
extern U8 g_byWDR_ForceAEMeanTarget;
extern U8 g_byWDR_AEDelay;
extern U32 g_dwNonLow10Num;
extern float g_fLow10Ratio;
extern float g_fLow20Ratio;
extern U32 g_dwLow20Num;
extern U8 g_byLow20Avg;
extern U8 g_byLow10to20Avg;
extern float g_fHigh10Ratio;
extern U8 g_byWDRContrastADJEn;
extern U8 g_byWDRContrastDelay;
extern U8 g_byWDRMode;
extern U8 g_byWDRManualLevel;


// Dehaze
#ifdef _DEHAZE_ENABLE_
extern U8 g_byDehazeEnable;
extern U8 g_byDehazeSceneChange;
extern U8 g_byDehazeUpdate;
extern U32 g_dwDehazeHistSum;
extern U32 g_dwDehazeNormFactor;
extern U8 g_byDehazeDarkChMean;
extern U8 g_byDehazeGradMean;
extern U8 g_byFirstTriggerDehaze;
#endif


// ISP Algo registers
extern U32 r_dwISP_AWB_WIN_SUM_R;
extern U32 r_dwISP_AWB_WIN_SUM_G;
extern U32 r_dwISP_AWB_WIN_SUM_B;
extern U32 r_adwISP_AWB_WP_NUM[6];
extern U32 r_dwISP_AWB_FINE_SUM_R;
extern U32 r_dwISP_AWB_FINE_SUM_G;
extern U32 r_dwISP_AWB_FINE_SUM_B;
extern U32 r_dwISP_AWB_FINE_WP_NUM;

extern U16 r_wISP_AE_HWIN_START_X;
extern U16 r_wISP_AE_HWIN_START_Y;
extern U16 r_wISP_AE_HWIN_END_X;
extern U16 r_wISP_AE_HWIN_END_Y;
extern U16 r_wISP_AE_YWIN_START_X;
extern U16 r_wISP_AE_YWIN_START_Y;
extern U16 r_wISP_AE_YWIN_END_X;
extern U16 r_wISP_AE_YWIN_END_Y;
extern U32 r_dwISP_AE_YSUM;
extern U16 r_wISP_AE_SUM_HISTO;

extern U16 r_wISP_AF_WIN_START_X;
extern U16 r_wISP_AF_WIN_START_Y;
extern U32 r_adwISP_AF_SUM[5][5];
extern U16 r_wISP_AF_START0_X;
extern U16 r_wISP_AF_START0_Y;
extern U16 r_wISP_AF_END0_X;
extern U16 r_wISP_AF_END0_Y;
extern U16 r_wISP_AF_START1_X;
extern U16 r_wISP_AF_START1_Y;
extern U16 r_wISP_AF_END1_X;
extern U16 r_wISP_AF_END1_Y;
extern U32 r_dwISP_AF_SUM0;
extern U32 r_dwISP_AF_SUM1;
extern U32 r_dwISP_AF_NUM0;
extern U32 r_dwISP_AF_NUM1;



extern CtlItemU8_t  PwrLineFreqItem;
extern U16 g_wSensorHsyncWidth;
extern U32 g_dwPclk;
extern CtlItemU16_t BackLightCompItem;
extern CtlItemU8_t LowLightCompItem;
extern CtlItemU8_t ExposureTimeAutoItem;
extern CtlItemU8_t RtkExtROIModeItem;
extern CtlItemU8_t RtkExtIQModeItem;
extern U8 g_byROIAEStatus;
extern float g_fEVCompensateRate;
extern U8 g_byAELock;
extern U8 g_byCurFps;
extern U16 g_wSensorCurFormatWidth;
extern U16 g_wSensorCurFormatHeight;
extern U16 g_wSensorWidthBefBLC;
extern U16 g_wSensorHeightBefBLC;
extern U8 g_byContrast_Def;
extern IQTABLE_t code ct_IQ_Table;

extern U8 g_byStreamFRC[5];

extern U8 g_byAECSetDynamicFps;
extern U8 g_bysetdynfps_flag;
extern U8 g_byAECDynamicFps;
extern U8 g_byAECLastDynamicFps;
extern U16 g_wAECMaxDummyLines;

#endif // _ISPALGOVAR_H_

