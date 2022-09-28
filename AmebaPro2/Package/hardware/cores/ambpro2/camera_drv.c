#include "camera_drv.h"
#include "mmf2_link.h"
#include "mmf2_siso.h"
#include "base_type.h"
#include "hal_video.h"
#include "video_api.h"
#include "sensor.h"
#include "module_video.h"
// include for testing rtsp, remember to remove before official release
//#include "module_rtsp2.h"
//#include "rtsp/rtsp_api.h"

#define OSD_ENABLE 1
#define MD_ENABLE  1
#define HDR_ENABLE 1

data_content_t *cameraInit(void){
    data_content_t *ctx = (data_content_t *)rtw_malloc(sizeof(data_content_t));
    if (!ctx) {
		return NULL;
	}
	memset(ctx, 0, sizeof(data_content_t));
	ctx->queue_num = 1;		// default 1 queue, can set multiple queue by command MM_CMD_SET_QUEUE_NUM
	
	video_create(ctx);

	if (!ctx->priv) {
		printf("[%s] [ERROR] fail------\n\r", __FUNCTION__);
	    if (ctx->priv) {
		    video_destroy(ctx->priv);
	    }
    	if (ctx) {
    		free(ctx);
    	}
    	return NULL;
	}
    
	printf("[%s] module open - free heap %d\n\r", __FUNCTION__, xPortGetFreeHeapSize());

    return ctx;
}

int cameraConfig(int enable, int w, int h, int bps, int snapshot){
    int voe_heap_size = 0;
	isp_info_t info;

	if (USE_SENSOR == SENSOR_GC4653) {
		info.sensor_width = 2560;
		info.sensor_height = 1440;
		info.sensor_fps = 15;
	} else {
		info.sensor_width = 1920;
		info.sensor_height = 1080;
		info.sensor_fps = 30;
	}

#if OSD_ENABLE
	info.osd_enable = 1;
#endif

#if MD_ENABLE
	info.md_enable = 1;
#endif

#if HDR_ENABLE
	info.hdr_enable = 1;
#endif

	video_set_isp_info(&info);

	voe_heap_size =  video_buf_calc(enable, w, h, bps, snapshot,
        0,0,0,0,0,
        0,0,0,0,0,
        0,0,0);
    
	return voe_heap_size;
}


