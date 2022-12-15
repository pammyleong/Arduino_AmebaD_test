#include <Arduino.h>
#include "NNObjDetection.h"

#define DEBUG 0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

NNObjDetection::NNObjDetection(void){}

NNObjDetection::~NNObjDetection(void){}

void NNObjDetection::getRTSPParams(int ch, VideoSetting& config) { 
    RTSPwidth = config._w;
    RTSPheight = config._h;

    getRTSPOD(ch, RTSPwidth, RTSPheight);
}

void NNObjDetection::configVideo(int ch, VideoSetting& config) {
    width = config._w;
    height = config._h;

    CAMDBG("Width [Ch%d]:%d  Height [Ch%d]:%d", ch, width, ch, height);
    if (_p_mmf_context == NULL) {
        _p_mmf_context = nnObjDetInit();
    }
    if (_p_mmf_context == NULL) {
        CAMDBG("NN init failed\r\n");
        return;
    }
    
    nnSetObjDetModel(_p_mmf_context->priv);
    nnSetInputObjDetParam(_p_mmf_context->priv);
    nnSetObjDetDisppost(_p_mmf_context->priv);
    nnSetObjDetConfThres(_p_mmf_context->priv);
    nnObjDetNMSThres(_p_mmf_context->priv);
    nnObjDetSetApply(_p_mmf_context->priv);
}

void NNObjDetection::begin(void) {
    cameraStart(_p_mmf_context->priv, 4); // 4 is the channel for NN
    cameraYUV(_p_mmf_context->priv);
}

void NNObjDetection::end(void) {
    // to be done
}

// void NNObjDetection::YUV(void) {
//     cameraYUV(_p_mmf_context->priv);
// }

void NNObjDetection::OSDDisplay(void) {
    OSDBeginOD();
}

