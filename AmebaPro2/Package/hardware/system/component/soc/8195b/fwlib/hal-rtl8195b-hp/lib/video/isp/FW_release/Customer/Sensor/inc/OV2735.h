#ifndef _OV2735_H_
#define _OV2735_H_

void OV2735SetFormatFps(U16 SetFormat, U8 Fps);
void CfgOV2735ControlAttr(void);
void SetOV2735ImgDir(U8 bySnrImgDir);
void SetOV2735IntegrationTime(U16 wEspline);
void SetOV2735Gain(float fGain);
float GetOV2735AnalogGain(void);
float GetOV2735DigitalGain(void);
U8 SetOV2735AnalogGain(float fGain);
U8 SetOV2735DigitalGain(float fGain);
void SetOV2735Exposuretime_Gain(float fExpTime, float fTotalGain);
void OV2735_POR(void);
void OV2735_PORBEF(void);
void OV2735_POR_OFF(U8 byDelayCtrl);
void InitOV2735IspParams(void);
void InitOV2735IspParamsByResolution(U16 wCurWidth, U16 wCurHeight);
void SetOV2735DynamicISP(U16 wAEC_Gain);
void SetOV2735DynamicISP_AWB(U16 wColorTempature);
#endif // _OV2735_H_

