#ifndef _SC2232_H_
#define _OV2232_H_

void SC2232SetFormatFps(U16 SetFormat, U8 Fps);
void CfgSC2232ControlAttr(void);
void SetSC2232ImgDir(U8 bySnrImgDir);
void SetSC2232IntegrationTime(U16 wEspline);
void SetSC2232Gain(float fGain);
float GetSC2232AnalogGain(void);
float GetSC2232DigitalGain(void);
U8 SetSC2232AnalogGain(float fGain);
U8 SetSC2232DigitalGain(float fGain);
void SetSC2232exposuretime_Gain(float fExpTime, float fTotalGain);
void SC2232_POR(void);
void SC2232_PORBEF(void);
void SC2232_POR_OFF(U8 byDelayCtrl);
void InitSC2232IspParams(void);
void InitSC2232IspParamsByResolution(U16 wCurWidth, U16 wCurHeight);
//void SetSC2232DynamicISP(U16 wAEC_Gain);
void SetSC2232DynamicISP_AWB(U16 wColorTempature);
#endif // _SC2232_H_