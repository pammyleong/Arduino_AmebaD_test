#include <Arduino.h>
#include "NNObjDetection.h"

#define DEBUG 0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

NNObjectDetection::NNObjectDetection(void){}

NNObjectDetection::~NNObjectDetection(void){}

void NNObjectDetection::configVideo(VideoSetting& config) {
    if (_p_mmf_context == NULL) {
        _p_mmf_context = nnODInit();
    }
    if (_p_mmf_context == NULL) {
        printf("NN init failed\r\n");
        return;
    }
    
    nnSetODModel(_p_mmf_context->priv);
    nnSetInputODParams(_p_mmf_context->priv);
    nnSetODDisppost(_p_mmf_context->priv);
    nnSetODConfThres(_p_mmf_context->priv);
    nnODNMSThres(_p_mmf_context->priv);
    nnODSetApply(_p_mmf_context->priv);
}

void NNObjectDetection::configModel(float confidence_threshold, float nms_threshold, VideoSetting& config) {
    configODModel(confidence_threshold, nms_threshold, config._w, config._h);
}

void NNObjectDetection::configOSD(int ch, VideoSetting& config) {
    configODOSD(ch, config._w, config._h);
}

void NNObjectDetection::beginOSD(void) {
    ODOSD();
}
