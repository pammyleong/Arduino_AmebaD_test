#include "rtsp_drv.h"
#include "mmf2_link.h"
#include "mmf2_siso.h"
#include "mmf2_module.h"
#include "sensor.h"
#include "rtsp/rtsp_api.h"
#include "module_rtsp2.h"
//#include "camera_drv.sh"

//#include "avcodec.h"

int channel_idx = 0;
//static u32 stream_flow_id_bitmap = 0;
//static _mutex stream_flow_id_bitmap_lock = NULL;

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

	return rtsp2_control(RTSP_Open(), CMD_RTSP2_SELECT_STREAM, channel_idx);
}

int RTSP_Set_Apply (void) {
    return rtsp2_control(RTSP_Open(), CMD_RTSP2_SET_APPLY, 0);
}

int RTSP_Set_Streaming (int arg) {

	return rtsp2_control(RTSP_Open(), CMD_RTSP2_SET_STREAMMING, arg);
}

int RTSP_Set_Params (int arg) {

	return rtsp2_control(RTSP_Open(), CMD_RTSP2_SET_PARAMS, arg);
}

data_content_t *RTSP_DeInit (data_content_t *ctx){
    mm_queue_item_t *tmp_item;
    
	for (int i = 0; i < ctx->queue_num; i++) {
		if (ctx->port[i].output_recycle && ctx->port[i].output_ready) {
			while (xQueueReceive(ctx->port[i].output_ready, (void *)&tmp_item, 0) == pdTRUE) {
				xQueueSend(ctx->port[i].output_recycle, (void *)&tmp_item, 0);
			}
			//mm_printf("module close - move item to recycle\n\r");
			while (xQueueReceive(ctx->port[i].output_recycle, (void *)&tmp_item, 0) == pdTRUE) {
				//mm_printf("module close - tmp_item %x\n\r", tmp_item);
				if (tmp_item) {
					//mm_printf("module close - data_addr %x\n\r", tmp_item->data_addr);
					if (i == 0) {
//						if (tmp_item->data_addr && ctx->module->del_item) {
//							ctx->module->del_item(ctx->priv, (void *)tmp_item->data_addr);
//						}
					} else {
						if (tmp_item->data_addr) {
							free((void *)tmp_item->data_addr);
						}
					}
					tmp_item->data_addr = 0;
					free(tmp_item);
					tmp_item = NULL;
				}
				xQueueSend(ctx->port[i].output_ready, (void *)&tmp_item, 0);
			}
			//mm_printf("module close - clean resource in recycle\n\r");
			// create port
			vQueueDelete(ctx->port[i].output_recycle);
			vQueueDelete(ctx->port[i].output_ready);

			//mm_printf("module close - free port\n\r");
		}
	}
	// call module destory, cannot delete item after destory
	rtsp2_destroy(ctx->priv);

	free(ctx);
	//mm_printf("module close - free context\n\r");
	//rt_printf("module close - free heap %d\n\r", xPortGetFreeHeapSize());
	return NULL;
}


