#include <Arduino.h>
#include "NNFaceRecognition.h"

#define DEBUG 1

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

NNFaceRecognition::NNFaceRecognition(void){}
NNFaceRecognition::~NNFaceRecognition(void){}

void NNFaceRecognition::getRTSPParams(int ch, VideoSetting& config) { 
    RTSPwidthFR = config._w;
    RTSPheightFR = config._h;

    getRTSPFR(ch, RTSPwidthFR, RTSPheightFR);
}

// configuration for Face Recognition module
// TODO: 
// whether needs ch as input parameter
void NNFaceRecognition::configVideo(int ch, VideoSetting& config) { // to config CH 4 for NN
    width = config._w;
    height = config._h;

    CAMDBG("Width [Ch%d]:%d  Height [Ch%d]:%d", ch, width, ch, height);

    if (_p_mmf_context == NULL) {
        _p_mmf_context = nnFaceRecgInit();
    }
    if (_p_mmf_context == NULL) {
        CAMDBG("NN init failed\r\n");
        return;
    }
    
    nnFacerecogSetThreshold(_p_mmf_context->priv);
    nnFacerecogSetOSDDraw(_p_mmf_context->priv);
}

void NNFaceRecognition::begin(void) {
    cameraStart(_p_mmf_context->priv, 4); // 4 is the channel for NN
}

// void NNFaceRecognition::end(void) {
//     // to be done
// }

// void NNFaceRecognition::YUV(void) {
//     cameraYUV(_p_mmf_context->priv);
// }

// void NNFaceRecognition::OSDDisplay(void) {
//     OSDBegin();
// }

