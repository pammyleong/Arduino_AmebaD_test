#ifndef nn_facedet_drv_h
#define nn_facedet_drv_h

#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "mmf2_module.h"

void configFDOSD(int ch, uint16_t width, uint16_t height);

void configFD(uint16_t NN_width, uint16_t NN_height);

mm_context_t* nnFDInit(void);

void nnSetFDModel(void *p);

void nnSetFNModel(void *p);

void nnSetFDInputParam(void *p);

void nnSetFDDisppost(void *p);

void nnFDSetApply(void *p);

void nnSetFDOutput(void *p);

void nnSetFDDatagroup(mm_context_t *ctx, int status);

void nnSetFDCascade(void *p);

// Function externed from module_vipnn
extern int vipnn_control(void *p, int cmd, int arg);

#endif