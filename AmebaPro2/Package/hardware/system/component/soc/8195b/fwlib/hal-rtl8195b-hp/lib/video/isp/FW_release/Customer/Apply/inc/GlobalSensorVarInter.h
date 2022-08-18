#ifndef _CAMSENSORVARINTER_H_
#define _CAMSENSORVARINTER_H_

// Sensor module global variable declare
// These variables may be used only in Sensor module

extern OV_CTT_t g_asOvCTT[CTT_INDEX_MAX];

extern U8 g_byOVAEW_BLC;
extern U8 g_byOVAEB_BLC;
extern U8 g_byOVAEW_Normal;
extern U8 g_byOVAEB_Normal;

void InitSensorGlobalVar(void);
#endif
