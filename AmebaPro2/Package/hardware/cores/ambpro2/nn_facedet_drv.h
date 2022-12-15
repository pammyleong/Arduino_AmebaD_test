#ifndef nn_facedet_drv_h
#define nn_facedet_drv_h

#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "mmf2_module.h"

void getRTSP (int ch, uint32_t width, uint32_t height);

mm_context_t* nnFacedetInit(void);

void nnSetFacedetModel(void *p);

void nnSetFacedetInputParam(void *p);

void nnSetFacedetDisppost(void *p);

void nnFacedetSetApply(void *p);

void OSDBegin(void);

//static void nn_set_object(void *p, void *img_param);

//void OSDStart(int ch_enable, int ch_w, int ch_h);

// Function externed from module_vipnn
extern int vipnn_control(void *p, int cmd, int arg);

#endif