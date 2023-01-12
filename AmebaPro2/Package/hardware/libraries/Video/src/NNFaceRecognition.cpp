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


// configuration for Face Recognition module 
// whether needs ch as input parameter
void NNFaceRecognition::configVideo() { // to config CH 4 for NN
    if (_p_mmf_context == NULL) {
        _p_mmf_context = nnFRInit();
    }
    if (_p_mmf_context == NULL) {
        CAMDBG("NN init failed\r\n");
        return;
    }
    nnFRSetThreshold(_p_mmf_context->priv);
    nnFRSetOSDDraw(_p_mmf_context->priv);
}

void NNFaceRecognition::configOSD(int ch, VideoSetting& config) {
    configFROSD(ch, config._w, config._h);
}

void NNFaceRecognition::beginOSD(void) {
    FROSD();
}
