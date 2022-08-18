#ifndef _GLOBALSYSVARLIB_H_
#define _GLOBALSYSVARLIB_H_

// System module global variable declare
// These variables may be used in other module

// usb
extern U8 g_byCCICurSnrIntf;
extern CtlItemU32_t  ExposureTimeAbsolutItem;
extern CtlItemU8_t  ExposureTimeAutoItem;
extern CtlItemU8_t  LowLightCompItem;
extern CtlItemS16_t  BrightnessItem;
extern CtlItemU16_t  ContrastItem;
extern CtlItemS16_t  HueItem;
extern CtlItemU16_t  SaturationItem;
extern CtlItemU16_t  SharpnessItem;
extern CtlItemU16_t GammaItem;
extern CtlItemU16_t  WhiteBalanceTempItem;
extern CtlItemWBComponent_t WhiteBalanceComponentItem;
extern CtlItemU16_t  BackLightCompItem;
extern CtlItemU16_t GainItem;
extern CtlItemU8_t  PwrLineFreqItem;
extern CtlItemU8_t  WhiteBalanceModeItem;
extern CtlItemS16_t  PanItem;
extern CtlItemS16_t  TiltItem;
extern CtlItemU16_t  ZoomItem;
extern CtlItemS16_t  RollItem;
extern CtlItemU16_t RtkExtISPSpecialEffectItem;
extern CtlItemS16_t RtkExtEVCompensationItem;
extern CtlItemU16_t RtkExtLEDTorchItem;
extern CtlItemU16_t RtkExtLEDFlashItem;
extern CtlItemROI_t ROIItem;
#ifdef _SCENE_MODE_
extern CtlItemU16_t RtkExtSceneModeItem;
#endif
#ifdef _EXT_ISO_ENABLE_
extern CtlItemU16_t RtkExtISOItem;
#endif
extern CtlItemU8_t RtkExtIQParameterItem;
extern CtlItemU16_t RtkExtGainItem;
#ifdef _AF_ENABLE_
extern CtlItemU16_t  FocusAbsolutItem		;
extern CtlItemU8_t  FocusAutoItem		;
#endif
extern U16 g_wCamTrmCtlSel;
extern U16 g_wProcUnitCtlSel;
extern U32 g_dwRtkExtUnitCtlSel;
extern U8 g_byCamTrmCtlSel_Ext;
extern U8 g_bySnrEffect;
extern U8 g_bySnrImgDir;

extern U32 g_dwIspCurrentClk;
extern U32 g_dwLdc_ispclk;

// sensor
extern SensorPower_t g_SensorPower;
extern U16 g_wSensorCurFrame;
extern U8 g_bySensorIsOpen ;
extern U16 g_wSensor;
extern U8 g_bySensorSize ;
extern U16 g_wSensorSPFormat ;
extern U16 g_wSensorCurFormatWidth ;
extern U16 g_wSensorCurFormatHeight ;
extern U16 g_wCurFrameWidth;
extern U16 g_wCurFrameHeight;
extern U16 g_wSensorMJPGByPass;
extern U8 g_byCurFps;
extern U8 g_byCurFormat;
extern SnrRegAccessProp_t g_SnrRegAccessProp;
extern U8 g_byPreviewDropFrameNumber;
extern VideoAttr_t g_VideoAttr;
extern StreamInfo_t g_aCurStreamInfo[MAX_STREAM_COUNT];
extern StreamInfo_t g_aStreamInfoBackup[MAX_STREAM_COUNT];
extern U32 g_dwCurFrameInterval;
extern U8 g_byHclkSrcType;
extern  U32 g_dwPclk;
extern U16 g_wSensorHsyncWidth;
extern FWVersion_t code g_cVdFwVerSection0;
#ifdef _STILL_IMG_BACKUP_SETTING_
extern U16 g_wPreviewBackupExposure;
extern U16 g_wPreviewBackupGain;
#endif
extern U8 g_bySensor_YuvMode;
extern U8 g_bySensorImageFmt;
extern U8 g_byStartVideo;
extern U8 g_byMTDDetectBackend;
extern U8 g_byMTDWinDetected;

extern U16 data g_wMTDTimeOutCnt;
#ifdef _SENSOR_ESD_ISSUE_
extern U8 g_byStreamOn;
#endif
#ifdef _LENOVO_JAPAN_PROPERTY_PAGE_
extern U8 g_byAWBRGain_Lenovo;
extern U8 g_byAWBGGain_Lenovo;
extern U8 g_byAWBBGain_Lenovo;
extern U8 g_byVendorDriver_Lenovo;
#endif
extern U32 g_dwMIPIclk;

#ifdef _JPEG_QTABLE_TUNE_
extern U8 g_byQTableTune;
extern U8 g_byQTableFrameCnt;
extern U8 g_byQTableTuneCnt1;
extern U8 g_byQTableTuneCnt2;
extern U8 g_byQTableTuneCnt3;
extern U8 g_byQTableTuneCnt4;
extern U8 g_byQTableTuneStatus;
extern U8 g_byJPEGQTableScaleAuto;
extern U8 g_byJPEGQCtnIncCnt; //Continuous Inc Count
extern U8 g_byJPEGQCtnDecCnt; //Continuous Dec Count
#endif

extern U8 g_byMipiRxHSTerm;
extern U8 g_byMipiRxLaneEn;
extern U8 g_byMipiRxDphyType;
extern U8 g_byMipiRxSpecType;
extern U8 g_byMipiRxResistor;
extern U8 g_byMipiClkSkew;
extern U32 g_dwMIPITrueClk;

extern U8 g_byHiSpiLVDSMode;
extern U8 g_byHiSpiLVDSDataFormat;
extern U8 g_byHiSpiLVDSLaneEn;
extern U16 g_wHiSpiLVDSWidth;
extern U16 g_wHiSpiLVDSHeight;

extern U8 g_byRGBIRMode;

extern U8 g_byISPControl1;

#endif //_GLOBAL_VARS_H_
