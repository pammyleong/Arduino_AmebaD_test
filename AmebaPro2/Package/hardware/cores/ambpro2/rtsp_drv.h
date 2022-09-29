#ifndef rtsp_drv_h
#define rtsp_drv_h
#include <stdint.h>
#include <FreeRTOS.h>
#include <semphr.h>
#include <diag.h>
#include "camera_drv.h"
//#include "freertos_service.h"
////#include "rtsp/rtsp_api.h"


#define CMD_RTSP2_GET_PARAMS			MM_MODULE_CMD(0x01)
#define CMD_RTSP2_SET_STREAMMING		MM_MODULE_CMD(0x02)
#define CMD_RTSP2_SELECT_STREAM 		MM_MODULE_CMD(0x03)
#define CMD_RTSP2_SET_APPLY				MM_MODULE_CMD(0x0d)




data_content_t *RTSP_Init (void);

int RTSP_Select_Stream (int arg);

int RTSP_Set_Apply (void);

int RTSP_Set_Streaming      (int arg);

int RTSP_Set_Params (void);

data_content_t *RTSP_DeInit (data_content_t *ctx);

void RTSPConfig (uint32_t rtsp_fps, uint32_t rtsp_bps, int video_codec);



// extern function 

extern void *rtsp2_create (void *parent);

extern void *rtsp2_destroy(void *p);

extern int rtsp2_control(void *p, int cmd, int arg);

extern int rtsp2_handle(void *p, void *input, void *output);


#endif


