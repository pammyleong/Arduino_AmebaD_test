#include <Arduino.h>
#include "NNObjectDetection.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "img_sample/input_image_640x360x3.h"
#include "model_yolo.h"

extern int vipnn_control(void *p, int cmd, int arg);

#ifdef __cplusplus
}
#endif

#define DEBUG 0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

objdetect_res_t NNObjectDetection::_p_objdet_result = {0};
void (*NNObjectDetection::OD_user_CB)(objdetect_res_t*);

void NNObjectDetection::configVideo(VideoSetting& config) {
    od_param.img.width = config._w;
    od_param.img.height = config._h;
    od_param.img.roi.xmax = config._w;
    od_param.img.roi.ymax = config._h;
}

void NNObjectDetection::configThreshold(float confidence_threshold, float nms_threshold) {
    nn_confidence_thresh = confidence_threshold;
    nn_nms_thresh = nms_threshold;
}

void NNObjectDetection::begin(void) {
    if (_p_mmf_context == NULL) {
        _p_mmf_context = mm_module_open(&vipnn_module);
    }
    if (_p_mmf_context == NULL) {
        printf("NN init failed\r\n");
        return;
    }

    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_MODEL, (int)&yolov4_tiny);
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_IN_PARAMS, (int)&od_param);
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_DISPPOST, (int)setDispCallback);
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_CONFIDENCE_THRES, (int)&nn_confidence_thresh);
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_NMS_THRES, (int)&nn_nms_thresh);
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_APPLY, 0);
}

void NNObjectDetection::end(void) {
    if (_p_mmf_context == NULL) {
        return;
    }
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_DISPPOST, (int)NULL);
    if (mm_module_close(_p_mmf_context) == NULL) {
        _p_mmf_context = NULL;
    } else {
        CAMDBG("Objdet deinit failed\r\n");
    }
}

void NNObjectDetection::setDispCallback(void *p, void *img_param) {
    memcpy(&_p_objdet_result, (objdetect_res_t *)p, sizeof(objdetect_res_t));
    if (OD_user_CB != NULL) { 
        OD_user_CB(&_p_objdet_result);
    }
}

void NNObjectDetection::setCallback(void (*od_callback)(objdetect_res_t *)) {
    OD_user_CB = od_callback;
    if (OD_user_CB == NULL) {
        printf("No User Callback\r\n");
    }
}

objdetect_res_t* NNObjectDetection::getResult(void) {
    return &_p_objdet_result;
}
