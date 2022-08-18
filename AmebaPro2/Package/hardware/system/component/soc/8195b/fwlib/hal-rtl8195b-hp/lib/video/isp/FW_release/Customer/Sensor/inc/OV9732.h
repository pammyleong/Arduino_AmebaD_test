#ifndef _OV9732_H_
#define _OV9732_H_

void OV9732SetFormatFps(U16 SetFormat, U8 Fps);
void CfgOV9732ControlAttr(void);
void SetOV9732ImgDir(U8 bySnrImgDir);
void SetOV9732IntegrationTime(U16 wEspline);
void SetOV9732Gain(float fGain);
float GetOV9732AnalogGain(void);
float GetOV9732DigitalGain(void);
U8 SetOV9732AnalogGain(float fGain);
U8 SetOV9732DigitalGain(float fGain);
void SetOV9732Exposuretime_Gain(float fExpTime, float fTotalGain);
void OV9732_POR(void);
void OV9732_PORBEF(void);
void OV9732_POR_OFF(U8 byDelayCtrl);
void InitOV9732IspParams(void);
void InitOV9732IspParamsByResolution(U16 wCurWidth, U16 wCurHeight);
void SetOV9732DynamicISP(U16 wAEC_Gain);
void SetOV9732DynamicISP_AWB(U16 wColorTempature);
#endif // _OV9732_H_

