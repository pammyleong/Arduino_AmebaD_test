#include "camera_drv.h"
#include "mmf2_link.h"
#include "mmf2_siso.h"
#include "base_type.h"
#include "hal_video.h"
#include "video_api.h"
#include "module_video.h"
#include "sensor.h"

#define OSD_ENABLE 1
#define MD_ENABLE  1
#define HDR_ENABLE 1

extern int incb[5];
extern int enc_queue_cnt[5];

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

data_content_t *cameraDeInit(data_content_t *ctx){
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
						if (tmp_item->data_addr) {
							video_del_item(ctx->priv, (void *)tmp_item->data_addr);
						}
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
	// cannot delete item after destory
	video_destroy(ctx->priv);

	free(ctx);
	//mm_printf("module close - free context\n\r");
	//rt_printf("module close - free heap %d\n\r", xPortGetFreeHeapSize());
    video_deinit();
    
    return NULL;
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

void cameraStopVideoStream(void *p){
    video_ctx_t *ctx = (video_ctx_t *)p;
    int ch = ctx->params.stream_id;
    
    while (incb[ch]) {
		vTaskDelay(1);
	}
	if (enc_queue_cnt[ch] > 0) {
		printf("CH %d MMF enc_queue_cnt = %d\r\n", ch, enc_queue_cnt[ch]);
		video_encbuf_clean(ch, CODEC_H264 | CODEC_HEVC | CODEC_JPEG);
	}
	enc_queue_cnt[ch] = 0;
	vTaskDelay(10);

	video_close(ch);
}


