#include "rtsp_drv.h"
#include "mmf2_link.h"
#include "mmf2_siso.h"
#include "mmf2_module.h"

#include "sensor.h"
#include "rtsp/rtsp_api.h"
#include "module_rtsp2.h"
#include "camera_drv.h"


data_content_t *RTSP_open (void) { //mm_module_open in sdk
	data_content_t *ctx = (data_content_t *)rtw_malloc(sizeof(data_content_t));
	if (!ctx) {
		return NULL;
	}
	memset(ctx, 0, sizeof(data_content_t));

	ctx->queue_num = 1;		// default 1 queue, can set multiple queue by command MM_CMD_SET_QUEUE_NUM
	rtsp2_create(ctx);

	if (!ctx->priv) {
		printf("fail------\n\r");
	    if (ctx->priv) {
		    rtsp2_destroy(ctx->priv);
	    }
    	if (ctx) {
    		free(ctx);
    	}
    	return NULL;
	}
	//	printf("module open - free heap %d\n\r", xPortGetFreeHeapSize());
	return ctx;
}




