#ifndef rtsp_drv_h
#define rtsp_drv_h
#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "camera_drv.h"


data_content_t *RTSP_open (void);

extern void *rtsp2_create (void *parent);

extern void *rtsp2_destroy(void *p);

extern int rtsp2_control(void *p, int cmd, int arg);

extern int rtsp2_handle(void *p, void *input, void *output);

#endif


