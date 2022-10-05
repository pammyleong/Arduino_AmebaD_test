#ifndef camera_drv_h
#define camera_drv_h

#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "mmf2_module.h"

// Function 1: define parameters to initialize the ISP heap size for VOE
int cameraConfig(int enable, int w, int h, int bps, int snapshot);

// Function 2: collect parameters
mm_context_t *cameraInit(void);

// Function 3: set video parameter, init queue and opens camera
void cameraOpen(void *p, int stream_id, int type, int res, int w, int h, int bps, int fps, int gop, int rc_mode);

// Function 4: start camera
void cameraStart(void *p, int channel);

// Function 5: disable video streaming
void cameraStopVideoStream(void *p);

// Function 6: deinit parameters assigned to ISP and VOE
mm_context_t *cameraDeInit(void *p);

// Functions externed from module_video
extern void *video_create(void *parent);
extern void *video_destroy(void *p);
extern int video_control(void *p, int cmd, int arg);
extern int video_close(int ch);
extern void *video_del_item(void *p, void *d);
extern void *video_deinit(void);

#endif
