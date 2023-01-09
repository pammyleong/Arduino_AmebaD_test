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
    width = config._w;
    height = config._h;

    CAMDBG("Width:%d  Height:%d", width, height);
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

void NNObjectDetection::configObjDetModel(float confidence_threshold, float nms_threshold) {
    configODModel(confidence_threshold, nms_threshold);
}

void NNObjectDetection::configObjDetOSD(int ch, VideoSetting& config) {
    RTSPwidth = config._w;
    RTSPheight = config._h;
    configODOSD(ch, RTSPwidth, RTSPheight);
}

void NNObjectDetection::beginObjDetOSD(void) {
    ODOSD();
}

//void NNObjDetection::begin(void) {
//    cameraStart(_p_mmf_context->priv, 4); // 4 is the channel for NN
//    cameraYUV(_p_mmf_context->priv);
//}
//
//void NNObjDetection::end(void) {
//    // to be done
//}
