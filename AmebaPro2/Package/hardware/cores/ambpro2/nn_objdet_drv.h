#ifndef nn_objdet_drv_h
#define nn_objdet_drv_h

#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "mmf2_module.h"

mm_context_t* nnObjDetInit(void);

void nnSetObjDetModel(void *p);

void nnSetInputObjDetParam(void *p);

void nnSetObjDetDisppost(void *p);

void nnSetObjDetConfThres(void *p);

void nnObjDetNMSThres(void *p);

void nnObjDetSetApply(void *p);

// Function externed from module_vipnn
extern int vipnn_control(void *p, int cmd, int arg);

#endif