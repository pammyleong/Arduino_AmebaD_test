#include "array_drv.h"
#include "mmf2_link.h"
#include "mmf2_siso.h"
#include "module_array.h"

#define USE_H265 1

#if USE_H265
#include "sample_h265.h"
#define VIDEO_TYPE VIDEO_HEVC
#define VIDEO_CODEC AV_CODEC_ID_H265
#else
#include "sample_h264.h"
#define VIDEO_TYPE VIDEO_H264
#define VIDEO_CODEC AV_CODEC_ID_H264
#endif

// array
static array_params_t h264_array_params = {
    .type                   = 0,
    .codec_id               = 0,
    .mode                   = 0,
    .u = {
        .v = {
            .fps            = 0,
            .h264_nal_size  = 0,
        }
    }
};

// init array
mm_context_t* arrayInit(void) {
    return mm_module_open(&array_module);
}

// deinit and release all resources for array
mm_context_t* arrayDeinit(mm_context_t *p) {
    return mm_module_close(p);
}

// Set parameters for array
void arraySetParams(void *p, uint32_t array_type, uint32_t array_encoder, uint32_t array_fps, uint32_t h264_nal_size) {
    h264_array_params.type = array_type;
    h264_array_params.codec_id = array_encoder;
    h264_array_params.mode = ARRAY_MODE_LOOP;
    h264_array_params.u.v.fps = array_fps;
    h264_array_params.u.v.h264_nal_size = h264_nal_size;

    array_control(p, CMD_ARRAY_SET_PARAMS, (int)&h264_array_params);
}

// Set array setting
void arraySetArray(void *p) {
    // Video array input (H264/H265)
    array_t array;
#if USE_H265
    array.data_addr = (uint32_t) h265_sample;
    array.data_len = (uint32_t) h265_sample_len;
#else
    array.data_addr = (uint32_t) h264_sample;
    array.data_len = (uint32_t) h264_sample_len;
#endif
    int i = 0;
    char tempchar;

    for (i = 0; i < 16; i++) {
        memcpy(&tempchar, (void const*)(array.data_addr + i), 1);
        printf("%02X", tempchar);
    }
    printf("\r\n");
    array_control(p, CMD_ARRAY_SET_ARRAY, (int)&array);
}

// Set array transmission queue
void arraySetQueue(mm_context_t *p) {
    mm_module_ctrl(p, MM_CMD_SET_QUEUE_LEN, 6);
    mm_module_ctrl(p, MM_CMD_INIT_QUEUE_ITEMS, MMQI_FLAG_DYNAMIC);
}

// apply array settings for transmission
void arraySetApply(void *p) {
    array_control(p, CMD_ARRAY_APPLY, 0);
}

// start array transmission
void arrayStart(mm_context_t *p) {
    array_control(p, CMD_ARRAY_STREAMING, ON); // streamming on
}

// stop array transmission
void arrayStop(mm_context_t *p) {
    array_control(p, CMD_ARRAY_STREAMING, OFF); // streamming off
}

