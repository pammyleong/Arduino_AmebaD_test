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

std::vector<ObjectDetectionResult> NNObjectDetection::object_result_vector;
objdetect_res_t NNObjectDetection::objdet_result = {0};
void (*NNObjectDetection::OD_user_CB)(objdetect_res_t*);

NNObjectDetection::NNObjectDetection(void) {
}

NNObjectDetection::~NNObjectDetection(void) {
    end();
}

void NNObjectDetection::configVideo(VideoSetting& config) {
    roi_nn.img.width = config._w;
    roi_nn.img.height = config._h;
    roi_nn.img.rgb = 0;
    roi_nn.img.roi.xmin = 0;
    roi_nn.img.roi.ymin = 0;
    roi_nn.img.roi.xmax = config._w;
    roi_nn.img.roi.ymax = config._h;
}

void NNObjectDetection::configThreshold(float confidence_threshold, float nms_threshold) {
    od_confidence_thresh = confidence_threshold;
    od_nms_thresh = nms_threshold;
}

void NNObjectDetection::begin(void) {
    if (_p_mmf_context == NULL) {
        _p_mmf_context = mm_module_open(&vipnn_module);
    }
    if (_p_mmf_context == NULL) {
        printf("NNObjectDetection init failed\r\n");
        return;
    }

    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_MODEL, (int)&yolov4_tiny);
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_IN_PARAMS, (int)&roi_nn);
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_DISPPOST, (int)ODResultCallback);
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_CONFIDENCE_THRES, (int)&od_confidence_thresh);
    vipnn_control(_p_mmf_context->priv, CMD_VIPNN_SET_NMS_THRES, (int)&od_nms_thresh);
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
        CAMDBG("NNObjectDetection deinit failed\r\n");
    }
}

void NNObjectDetection::setResultCallback(void (*od_callback)(objdetect_res_t *)) {
    OD_user_CB = od_callback;
}

objdetect_res_t* NNObjectDetection::getResult(void) {
    return &objdet_result;
}

uint16_t NNObjectDetection::getResultCount(void) {
    return object_result_vector.size();
}

ObjectDetectionResult NNObjectDetection::getResult(uint16_t index) {
    if (index >= object_result_vector.size()) {
        return ObjectDetectionResult();
    }
    return object_result_vector[index];
}

void NNObjectDetection::ODResultCallback(void *p, void *img_param) {
    (void)img_param;

    objdetect_res_t* result = (objdetect_res_t*)p;
    object_result_vector.clear();
    if (object_result_vector.capacity() < (size_t)result->obj_num) {
        object_result_vector.resize((size_t)result->obj_num);
    }
    for (int i = 0; i < result->obj_num; i++) {
        memcpy(&(object_result_vector[i].result), &(result->res[i]), sizeof(detobj_t));
    }


    memcpy(&objdet_result, p, sizeof(objdetect_res_t));
    if (OD_user_CB != NULL) {
        OD_user_CB(&objdet_result);
    }
}

const char* ObjectDetectionResult::name(void) {
    return coco_name_get_by_id((int)result.type);
}

uint8_t ObjectDetectionResult::score(void) {
    return ((uint8_t)result.score);
}

float ObjectDetectionResult::xmin(void) {
    return result.top_x;
}

float ObjectDetectionResult::xmax(void) {
    return result.bot_x;
}

float ObjectDetectionResult::ymin(void) {
    return result.top_y;
}

float ObjectDetectionResult::ymax(void) {
    return result.bot_y;
}

