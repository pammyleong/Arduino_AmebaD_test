#ifndef _AR0237_H_
#define _AR0237_H_

/*
typedef struct AR0237_FpsSetting
{
    U8 byFps;
    U8 bySys_Clk_div; //  system clock divider
    U8 byPre_Clk_div; //  parameter of PLL
    U8 byPll_Mul;		// PLL multiply
    U16 Serial_Format; 
    U16 wLine_length_PCK;   // cam_sensor_cfg_line_length_pck
    U16 wCoarse_intergation_time;   //  cam_sensor_cfg_frame_length_lines
    U16 wextra_delay; //sensor_cfg_fine_integ_time_min
    U32 dwPixelClk;	
} AR0237_FpsSetting_t;
*/

typedef struct AR0237_FpsSetting
{
    U8 byFps;
    U16 frame_length_line;   // cam_sensor_cfg_line_length_pck	
    U16 wLine_length_PCK;   // cam_sensor_cfg_line_length_pck	
    U32 dwPixelClk;	
} AR0237_FpsSetting_t;

void AR0237SetFormatFps(U16 SetFormat, U8 Fps);
void CfgAR0237ControlAttr(void);
void SetAR0237ImgDir(U8 bySnrImgDir);
void SetAR0237IntegrationTime(U16 wEspline);
void SetAR0237Gain(float fGain);
U8 SetAR0237AnalogGain(float fGain);
U8 SetAR0237DigitalGain(float fGain);
float GetAR0237AnalogGain(void);
float GetAR0237DigitalGain(void);
void SetAR0237Exposuretime_Gain(float fExpTime, float fTotalGain);
void AR0237_PORBEF(void);
void AR0237_POR();
void AR0237_POR_OFF(U8 byDelayCtrl);
void InitAR0237IspParams();
void InitAR0237IspParamsByResolution(U16 wCurWidth, U16 wCurHeight);
void SetAR0237DynamicISP(U16 wAEC_Gain);
void SetAR0237DynamicISP_AWB(U16 wColorTempature);

#endif // _AR0237_H_

