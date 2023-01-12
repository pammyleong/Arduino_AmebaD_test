#ifndef nn_facerecog_drv_h
#define nn_facerecog_drv_h

#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "mmf2_module.h"
#include "timers.h"

void configFROSD(int ch, uint32_t width, uint32_t height);

//void configFR(uint16_t NN_width, uint16_t NN_height);

mm_context_t* nnFRInit(void);

void nnFRSetThreshold(void *p);

void nnFRSetOSDDraw(void *p);

void FROSD(void);

// Function externed from module_vipnn
extern int vipnn_control(void *p, int cmd, int arg);
extern int facerecog_control(void *p, int cmd, int arg);

#endif