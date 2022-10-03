#ifndef rtsp_drv_h
#define rtsp_drv_h
#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "mmf2_module.h"

void* RTSP_Init (void);

int RTSP_Select_Stream (void *p, int arg);

int RTSP_Set_Apply (void *p);

int RTSP_Set_Streaming      (void *p, int arg);

int RTSP_Set_Params (void *p, uint32_t rtsp_fps, uint32_t rtsp_bps, int video_codec);

void* RTSP_DeInit (void *p);


// extern function 

extern void *rtsp2_create (void *parent);

extern void *rtsp2_destroy(void *p);

extern int rtsp2_control(void *p, int cmd, int arg);

extern int rtsp2_handle(void *p, void *input, void *output);


#endif


