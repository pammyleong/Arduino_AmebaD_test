#include <Arduino.h>
#include "Array.h"

#define DEBUG 0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

Array::Array(void) {
}

Array::~Array(void) {
    if (_p_mmf_context == NULL) {
        return;
    }
    end();
    if (arrayDeinit(_p_mmf_context) == NULL) {
        _p_mmf_context = NULL;
    } else {
        CAMDBG("Array deinit failed\r\n");
    }
}

/**
  * @brief  Configure Array module by setting up paramters. 
  * @param  config : 
  * @retval none
  */
void Array::configArray(void) {
    // Init array if not previously done so
    if (_p_mmf_context == NULL) {
        _p_mmf_context = arrayInit();
    }
    if (_p_mmf_context == NULL) {
        CAMDBG("Array init failed\r\n");
        return;
    }

    uint32_t array_type;
    uint32_t array_encoder;
    uint32_t array_fps;
    uint32_t h264_nal_size;

    array_type = AVMEDIA_TYPE_VIDEO;
    array_encoder = AV_CODEC_ID_RGB888;
    array_fps = 5;
    h264_nal_size = 0;

    arraySetParams(_p_mmf_context->priv, array_type, array_encoder, array_fps, h264_nal_size);
    arraySetArray(_p_mmf_context->priv);
    arraySetQueue(_p_mmf_context);
    arraySetApply(_p_mmf_context->priv);
}

/**
  * @brief  Start array streaming
  * @param  none
  * @retval none
  */
void Array::begin(void) {
    if (_p_mmf_context == NULL) {
        printf("Need array init first\r\n");
    } else {
        arrayStart(_p_mmf_context);
        CAMDBG("Start array streaming\r\n");
    }
}

/**
  * @brief  Stop array streaming
  * @param  none
  * @retval none
  */
void Array::end(void) {
    if (_p_mmf_context == NULL) {
        printf("Need array init first\r\n");
    } else {
        arrayStop(_p_mmf_context);
        CAMDBG("Stop array streaming\r\n");
    }
}