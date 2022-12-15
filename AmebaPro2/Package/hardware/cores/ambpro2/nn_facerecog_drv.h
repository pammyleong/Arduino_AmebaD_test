#ifndef nn_facerecog_drv_h
#define nn_facerecog_drv_h

#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "mmf2_module.h"

void nnFacerecogSetThreshold(void *p);

void nnFacerecogSetOSDDraw(void *p);

// Function externed from module_vipnn
extern int vipnn_control(void *p, int cmd, int arg);

#endif