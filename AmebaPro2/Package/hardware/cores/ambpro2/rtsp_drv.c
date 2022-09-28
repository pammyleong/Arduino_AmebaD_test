#include "rtsp_drv.h"
#include "mmf2_link.h"
#include "mmf2_siso.h"
#include "mmf2_module.h"

#include "sensor.h"
#include "rtsp/rtsp_api.h"
#include "module_rtsp2.h"
#include "camera_drv.h"

#include "avcodec.h"

static int channel_idx = 0;
static u32 stream_flow_id_bitmap = 0;
static _mutex stream_flow_id_bitmap_lock = NULL;

extern void rtp_stream_statistics_sync(struct stream_context *stream_ctx);

data_content_t *RTSP_Open (void) { //mm_module_open in sdk
	data_content_t *ctx = (data_content_t *)rtw_malloc(sizeof(data_content_t));
	if (!ctx) {
		return NULL;
	}
	memset(ctx, 0, sizeof(data_content_t));

	ctx->queue_num = 1;		// default 1 queue, can set multiple queue by command MM_CMD_SET_QUEUE_NUM
	ctx->priv = rtsp2_create(ctx);

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



int RTSP_Select_Stream (int channel_idx) {

	return rtsp2_control(data_content_t, CMD_RTSP2_SELECT_STREAM, channel_idx);
}


int RTSP_Set_Apply (int arg) {

	return rtsp2_control(data_content_t, CMD_RTSP2_SET_APPLY, arg);
}


int RTSP_Set_Streaming (int arg) {

	return rtsp2_control(data_content_t, CMD_RTSP2_SET_STREAMMING, arg);
}

data_content_t *RTSP_Set_Params (void *p, int arg) {

	return rtsp2_control(data_content_t, CMD_RTSP2_SET_PARAMS, arg);
}

