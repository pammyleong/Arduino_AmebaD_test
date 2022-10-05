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

static video_params_t video_params = {
	.stream_id      = 0, // = V1_CHANNEL,
	.type           = 0, // = VIDEO_TYPE,
	.resolution     = 0, // = V1_RESOLUTION,
	.width          = 0, // = V1_WIDTH,
	.height         = 0, // = V1_HEIGHT,
	.bps            = 0, // = V1_BPS,
	.fps            = 0, // = V1_FPS,
	.gop            = 0, // = V1_GOP,
	.rc_mode        = 0, // = V1_RCMODE,
	.use_static_addr = 1
};

int cameraConfig(int enable, int w, int h, int bps, int snapshot){
    printf("[cameraConfig] Start \r\n");
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

mm_context_t *cameraInit(void){
    printf("[%s] cameraInit Starts\n\r", __FUNCTION__);
    mm_context_t* video_data = (mm_context_t *)rtw_malloc(sizeof(mm_context_t));
    printf("[%s] cameraInit 1\n\r", __FUNCTION__);
    if (!video_data) {
		return NULL;
	}
    printf("[%s] cameraInit 2\n\r", __FUNCTION__);
	memset(video_data, 0, sizeof(mm_context_t));
    printf("[%s] cameraInit 3\n\r", __FUNCTION__);
	video_data->queue_num = 1;		// default 1 queue, can set multiple queue by command MM_CMD_SET_QUEUE_NUM
	video_data->priv = video_create(video_data);
    printf("[%s] cameraInit 4\n\r", __FUNCTION__);

	if (!video_data->priv) {
		printf("[%s] [ERROR] fail------\n\r", __FUNCTION__);
//	    if (video_data->priv) {
//		    video_destroy(video_data->priv);
//	    }
    	if (video_data) {
            video_destroy(video_data->priv);
    		free(video_data);
    	}
    	return NULL;
	}
    
	printf("[%s] module open - free heap %d\n\r", __FUNCTION__, xPortGetFreeHeapSize());

    
    return video_data;
}

void cameraOpen(void *p, int stream_id, int type, int res, int w, int h, int bps, int fps, int gop, int rc_mode){
    // assign value parsing from user level
    video_params.stream_id = stream_id;
    video_params.type = type;
    video_params.resolution = res;
    video_params.width = w;
    video_params.height = h;
    video_params.bps = bps;
    video_params.fps = fps;
    video_params.gop = gop;
    video_params.rc_mode = rc_mode;

//    video_data = p;
    if (p) {
        video_control(p, CMD_VIDEO_SET_PARAMS, (int)&video_params);
        mm_module_ctrl(p, MM_CMD_SET_QUEUE_LEN, fps*3);
        mm_module_ctrl(p, MM_CMD_INIT_QUEUE_ITEMS, MMQI_FLAG_DYNAMIC);
    } else {
		printf("[%s] video open fail\n\r", __FUNCTION__);
		return;
	}
}

void cameraStart(void *p, int channel){
    video_control(p, CMD_VIDEO_APPLY, channel);
}

mm_context_t *cameraDeInit(void *p){
    mm_queue_item_t *tmp_item;
    mm_context_t *video_data = (mm_context_t *)rtw_malloc(sizeof(mm_context_t));
	video_data = p;
	for (int i = 0; i < video_data->queue_num; i++) {
		if (video_data->port[i].output_recycle && video_data->port[i].output_ready) {
			while (xQueueReceive(video_data->port[i].output_ready, (void *)&tmp_item, 0) == pdTRUE) {
				xQueueSend(video_data->port[i].output_recycle, (void *)&tmp_item, 0);
			}
			printf("[%s] module close - move item to recycle\n\r", __FUNCTION__);
			while (xQueueReceive(video_data->port[i].output_recycle, (void *)&tmp_item, 0) == pdTRUE) {
				printf("[%s] module close - tmp_item %x\n\r", __FUNCTION__, tmp_item);
				if (tmp_item) {
					printf("[%s] module close - data_addr %x\n\r", __FUNCTION__, tmp_item->data_addr);
					if (i == 0) {
						if (tmp_item->data_addr) {
							video_del_item(video_data->priv, (void *)tmp_item->data_addr);
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
				xQueueSend(video_data->port[i].output_ready, (void *)&tmp_item, 0);
			}
			printf("[%s] module close - clean resource in recycle\n\r", __FUNCTION__);
			// create port
			vQueueDelete(video_data->port[i].output_recycle);
			vQueueDelete(video_data->port[i].output_ready);

			printf("[%s] module close - free port\n\r", __FUNCTION__);
		}
	}
	// cannot delete item after destory
	video_destroy(video_data->priv);

	free(video_data);
	printf("[%s] module close - free context\n\r", __FUNCTION__);
	printf("[%s] module close - free heap %d\n\r", __FUNCTION__, xPortGetFreeHeapSize());
    video_deinit();
    
    return NULL;
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


