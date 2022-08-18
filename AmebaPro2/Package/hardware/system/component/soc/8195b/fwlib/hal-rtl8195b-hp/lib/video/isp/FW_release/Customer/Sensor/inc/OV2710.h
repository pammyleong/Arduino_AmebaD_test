#ifndef _OV2710_H_
#define _OV2710_H_

void OV2710SetFormatFps(U16 SetFormat, U8 Fps);
void CfgOV2710ControlAttr(void);
void SetOV2710ImgDir(U8 bySnrImgDir);
void SetOV2710IntegrationTime(U16 wEspline);
void SetOV2710Gain(float fGain);
U8 SetOV2710DigitalGain(float fGain);
U8 SetOV2710AnalogGain(float fGain);
float GetOV2710AnalogGain(void);
float GetOV2710DigitalGain(void);
void SetOV2710Exposuretime_Gain(float fExpTime, float fTotalGain);
void InitOV2710IspParams();
void OV2710_POR();
void OV2710_PORBEF();
void OV2710_POR_OFF(U8 byDelayCtrl);
void InitOV2710IspParams();
void SetOV2710DynamicISP(U16 wAEC_Gain);
void SetOV2710DynamicISP_AWB(U16 wColorTempature);
void SetOV2710Gain(float fGain);
#endif // _OV9710_H_


