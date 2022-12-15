#ifndef nn_facerecog_drv_h
#define nn_facerecog_drv_h

#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "mmf2_module.h"

void getRTSPFR (int ch, uint32_t width, uint32_t height);

mm_context_t* nnFaceRecogInit(void);

void nnFaceRecogSetThres(void *p);

void nnFaceRecogOSDDraw(void *p);

void OSDBeginFR(void);

// Function externed from module_vipnn
extern int vipnn_control(void *p, int cmd, int arg);

#endif