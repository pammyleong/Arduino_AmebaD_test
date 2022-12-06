#ifndef nn_facedet_drv_h
#define nn_facedet_drv_h

#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "mmf2_module.h"


mm_context_t* nnFacedetInit(void);

void nnSetFacedetModel(void *p);

void nnSetFacedetInputParam(void *p);

void nnSetFacedetDisppost(void *p);

void nnFacedetSetApply(void *p);

// Function externed from module_vipnn
extern int vipnn_control(void *p, int cmd, int arg);

#endif