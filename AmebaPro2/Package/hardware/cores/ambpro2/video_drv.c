#include "video_drv.h"
#include "mmf2_link.h"
#include "mmf2_siso.h"
#include "base_type.h"
#include "hal_video.h"
#include "video_api.h"
#include "module_video.h"
#include "sensor.h"

#define OSD_ENABLE      1
#define MD_ENABLE       1
#define HDR_ENABLE      1
#define DEBUG           0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

extern int incb[5];
extern int enc_queue_cnt[5];

uint32_t image_addr = 0;
uint32_t image_len = 0;

static video_params_t video_params = {
    .stream_id      = 0, 
    .type           = 0, 
    .resolution     = 0, 
    .width          = 0, 
    .height         = 0, 
    .bps            = 0,
    .fps            = 0, 
    .gop            = 0, 
    .rc_mode        = 0, 
    .use_static_addr = 1
};

int cameraConfig(int v1_enable, int v1_w, int v1_h, int v1_bps, int v1_snapshot,
                        int v2_enable, int v2_w, int v2_h, int v2_bps, int v2_snapshot,
                        int v3_enable, int v3_w, int v3_h, int v3_bps, int v3_snapshot,
                        int v4_enable, int v4_w, int v4_h) {

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

    voe_heap_size = video_voe_presetting(v1_enable, v1_w, v1_h, v1_bps, v1_snapshot, 
                                         v2_enable, v2_w, v2_h, v2_bps, v2_snapshot, 
                                         v3_enable, v3_w, v3_h, v3_bps, v3_snapshot, 
                                         v4_enable, v4_w, v4_h);
    CAMDBG("voe_heap_size assigned.");
    return voe_heap_size;
}

mm_context_t *cameraInit(void) {
    CAMDBG("cameraInit Starts");
    mm_context_t* videoData = (mm_context_t *)rtw_malloc(sizeof(mm_context_t));
    if (!videoData) {
        return NULL;
    }
    memset(videoData, 0, sizeof(mm_context_t));
    videoData->queue_num = 1;       // default 1 queue, can set multiple queue by command MM_CMD_SET_QUEUE_NUM
    videoData->module = &video_module;
    videoData->priv = video_module.create(videoData);
    if (!videoData->priv) {
        CAMDBG("[ERROR] fail------");
        if (videoData->priv) {
            video_module.destroy(videoData->priv);
        }
        if (videoData) {
            free(videoData);
        }
        return NULL;
    }
    CAMDBG("module open - free heap %d",xPortGetFreeHeapSize());

    return videoData;
}

void cameraOpen(mm_context_t *p, void *p_priv, int stream_id, int type, int res, int w, int h, int bps, int fps, int gop, int rc_mode, int snapshot) {
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

    CAMDBG("2 %d    %d    %d    %d    %d    %d    %d    %d    %d",stream_id, type, res, w, h, bps, fps, gop, rc_mode);

    if (p) {
        video_control(p_priv, CMD_VIDEO_SET_PARAMS, (int)&video_params);
        mm_module_ctrl(p, MM_CMD_SET_QUEUE_LEN, fps*3);
        mm_module_ctrl(p, MM_CMD_INIT_QUEUE_ITEMS, MMQI_FLAG_DYNAMIC);
        mm_module_ctrl(p, CMD_VIDEO_SNAPSHOT, 0);
        CAMDBG("cameraOpen done");
    } else {
        CAMDBG("cameraOpen fail");
    }
}

void cameraOpenNN(mm_context_t *p, void *p_priv, int stream_id, int type, int res, int w, int h, int bps, int fps, int gop, int direct_output) {
    // assign value parsing from user level
    video_params.stream_id = stream_id;
    video_params.type = type;
    video_params.resolution = res;
    video_params.width = w;
    video_params.height = h;
    video_params.bps = bps;
    video_params.fps = fps;
    video_params.gop = gop;
    video_params.direct_output = direct_output;
    video_params.use_static_addr = 1;
    // define NN region of interest
    video_params.use_roi = 1;
    video_params.roi.xmin = 0;
    video_params.roi.ymin = 0;
    video_params.roi.xmax = 1920;
    video_params.roi.ymax = 1080;

    CAMDBG("V4 %d    %d    %d    %d    %d    %d    %d    %d    %d",stream_id, type, res, w, h, bps, fps, gop, direct_output);

    if (p) {
        video_control(p_priv, CMD_VIDEO_SET_PARAMS, (int)&video_params);
        mm_module_ctrl(p, MM_CMD_SET_QUEUE_LEN, 2);
        mm_module_ctrl(p, MM_CMD_INIT_QUEUE_ITEMS, MMQI_FLAG_DYNAMIC);
        CAMDBG("cameraOpen done");
    } else {
        CAMDBG("cameraOpen fail");
    }
}

// set the queue length of video object 
void cameraSetQLen(mm_context_t *p, int length) {
    mm_module_ctrl(p, MM_CMD_SET_QUEUE_LEN, length);
}

// set the queue item of video object 
void cameraSetQItem(mm_context_t *p) {
    mm_module_ctrl(p, MM_CMD_INIT_QUEUE_ITEMS, MMQI_FLAG_DYNAMIC);
}

void cameraStart(void *p, int channel) {
    video_control(p, CMD_VIDEO_APPLY, channel);
}

void cameraYUV(void *p) {
    video_control(p, CMD_VIDEO_YUV, 2);
}

void cameraSnapshot(void *p, int arg) {
    video_control(p, CMD_VIDEO_SNAPSHOT, arg);
}

void cameraSnapshotRegCB(mm_context_t *p, int (*ssCB)(uint32_t, uint32_t)) {
    mm_module_ctrl(p, CMD_VIDEO_SNAPSHOT_CB, (int)ssCB);
}

mm_context_t *cameraDeinit(mm_context_t *p) {
    mm_queue_item_t *tmp_item;
    mm_context_t *video_data = (mm_context_t *)rtw_malloc(sizeof(mm_context_t));
    video_data = p;
    for (int i = 0; i < video_data->queue_num; i++) {
        if (video_data->port[i].output_recycle && video_data->port[i].output_ready) {
            while (xQueueReceive(video_data->port[i].output_ready, (void *)&tmp_item, 0) == pdTRUE) {
                xQueueSend(video_data->port[i].output_recycle, (void *)&tmp_item, 0);
            }
            CAMDBG("module close - move item to recycle");
            while (xQueueReceive(video_data->port[i].output_recycle, (void *)&tmp_item, 0) == pdTRUE) {
                CAMDBG("module close - tmp_item %x",(unsigned int)tmp_item);
                if (tmp_item) {
                    CAMDBG("module close - data_addr %x", (unsigned int)tmp_item->data_addr);
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
            CAMDBG("module close - clean resource in recycle");
            // create port
            vQueueDelete(video_data->port[i].output_recycle);
            vQueueDelete(video_data->port[i].output_ready);

            CAMDBG("module close - free port");
        }
    }
    // cannot delete item after destory
    video_destroy(video_data->priv);
    free(video_data);
    CAMDBG("module close - free context");
    CAMDBG("module close - free heap %d", xPortGetFreeHeapSize());
    video_deinit();
    return NULL;
}

void cameraStopVideoStream(void *p, int channel) {
    video_control(p, CMD_VIDEO_STREAM_STOP, channel);
}
