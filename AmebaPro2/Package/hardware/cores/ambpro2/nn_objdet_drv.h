#ifndef nn_objdet_drv_h
#define nn_objdet_drv_h

#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "mmf2_module.h"

void configODOSD(int ch, uint16_t width, uint16_t height);

//void configODModel(float confidence_thres, float nms_thres);

void configODModel(float confidence_thres, float nms_thres, uint16_t nn_width, uint16_t nn_height);

mm_context_t* nnODInit(void);

void nnSetODModel(void *p);

void nnSetInputODParams(void *p);

void nnSetODDisppost(void *p);

void nnSetODConfThres(void *p);

void nnODNMSThres(void *p);

void nnODSetApply(void *p);

// Function externed from module_vipnn
extern int vipnn_control(void *p, int cmd, int arg);

#endif