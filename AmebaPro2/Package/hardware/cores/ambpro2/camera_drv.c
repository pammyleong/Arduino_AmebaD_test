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

static mm_context_t *video_data;

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

void *cameraInit(void){
    video_data = (mm_context_t *)rtw_malloc(sizeof(mm_context_t));
    if (!video_data) {
		return NULL;
	}
	memset(video_data, 0, sizeof(mm_context_t));
	video_data->queue_num = 1;		// default 1 queue, can set multiple queue by command MM_CMD_SET_QUEUE_NUM
	video_data->priv = video_create(video_data);

	if (!video_data->priv) {
		printf("[%s] [ERROR] fail------\n\r", __FUNCTION__);
//	    if (video_data->priv) {
//		    video_destroy(video_data->priv);
//	    }
    	if (video_data) {
    		free(video_data);
    	}
    	return NULL;
	}
    
	printf("[%s] module open - free heap %d\n\r", __FUNCTION__, xPortGetFreeHeapSize());

    return video_data;
}

void cameraOpen(int stream_id, int type, int res, int w, int h, int bps, int fps, int gop, int rc_mode){
// ---------------- Troubleshoot whether needs to reinit again -------------------
//    video_data = (mm_context_t *)rtw_malloc(sizeof(mm_context_t));
//    mm_context_t *video_ctx = cameraInit(); // video_module
// -------------------------------------------------------------------------------
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
    
    if (video_data) {
        video_control(video_data, CMD_VIDEO_SET_PARAMS, (int)&video_params);
        mm_module_ctrl(video_data, MM_CMD_SET_QUEUE_LEN, fps*3);
        mm_module_ctrl(video_data, MM_CMD_INIT_QUEUE_ITEMS, MMQI_FLAG_DYNAMIC);
    } else {
		rt_printf("video open fail\n\r");
		return;
	}
}

void *cameraDeInit(void){
    // ---------------- Troubleshoot whether needs to reinit again -------------------
    //    whether video data is parsed in via input parameter
    // -------------------------------------------------------------------------------

    mm_queue_item_t *tmp_item;
    
	for (int i = 0; i < video_data->queue_num; i++) {
		if (video_data->port[i].output_recycle && video_data->port[i].output_ready) {
			while (xQueueReceive(video_data->port[i].output_ready, (void *)&tmp_item, 0) == pdTRUE) {
				xQueueSend(video_data->port[i].output_recycle, (void *)&tmp_item, 0);
			}
			//mm_printf("module close - move item to recycle\n\r");
			while (xQueueReceive(video_data->port[i].output_recycle, (void *)&tmp_item, 0) == pdTRUE) {
				//mm_printf("module close - tmp_item %x\n\r", tmp_item);
				if (tmp_item) {
					//mm_printf("module close - data_addr %x\n\r", tmp_item->data_addr);
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
			//mm_printf("module close - clean resource in recycle\n\r");
			// create port
			vQueueDelete(video_data->port[i].output_recycle);
			vQueueDelete(video_data->port[i].output_ready);

			//mm_printf("module close - free port\n\r");
		}
	}
	// cannot delete item after destory
	video_destroy(video_data->priv);

	free(video_data);
	//mm_printf("module close - free context\n\r");
	//rt_printf("module close - free heap %d\n\r", xPortGetFreeHeapSize());
    video_deinit();
    
    return NULL;
}

void cameraStopVideoStream(void){
    // ---------------- Troubleshoot whether needs to reinit again -------------------
    //    video_data = (mm_context_t *)rtw_malloc(sizeof(mm_context_t));
    //    whether video data is parsed in via input parameter
    // -------------------------------------------------------------------------------
    video_ctx_t *ctx = (video_ctx_t *)video_data;
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


