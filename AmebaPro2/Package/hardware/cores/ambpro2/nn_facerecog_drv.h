#ifndef nn_facerecog_drv_h
#define nn_facerecog_drv_h

#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "mmf2_module.h"
#include "timers.h"

void getRTSPFR (int ch, uint32_t width, uint32_t height);

void nnFacerecogSetThreshold(void *p);

void nnFacerecogSetOSDDraw(void *p);

void osd_cleanup_callback(TimerHandle_t xTimer);

void face_draw_object(void *p, void *img_param);

mm_context_t* nnFaceRecgInit(void);

void nnSetFaceRecgModel1(void *p);

void nnSetFaceRecgModel2(void *p);

void nnSetFaceRecgCascade(void *p);

void nnSetFaceRecgInputParam(void *p);

void nnSetFaceRecgOutput(void *p);

void nnSetFaceRecgDatagroup(mm_context_t *ctx, int status);

void nnFaceRecgSetApply(void *p);

void nnSetFaceRecgThreshold(void *p);

void nnSetFaceRecgThreshold(void *p);

// Function externed from module_vipnn
extern int vipnn_control(void *p, int cmd, int arg);
extern int facerecog_control(void *p, int cmd, int arg);

#endif