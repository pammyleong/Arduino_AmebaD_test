#ifndef nn_drv_h
#define nn_drv_h

#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "mmf2_module.h"


mm_context_t* NNInit(void);

void NNSetModel(void *p);

void NNSetInputParam(void *p);

void NNSetDisppost(void *p);

void NNSetConfThres(void *p);

void NNNMSThres(void *p);

void NNSetApply(void *p);

// Function externed from module_vipnn
int vipnn_control(void *p, int cmd, int arg);

#endif