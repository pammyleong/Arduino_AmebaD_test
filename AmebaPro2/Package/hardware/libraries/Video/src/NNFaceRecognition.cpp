#include <Arduino.h>
#include "NNFaceRecognition.h"

#define DEBUG 1

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

//#define NN_WIDTH    576//640
//#define NN_HEIGHT   320//640

NNFaceRecognition::NNFaceRecognition(void){}
NNFaceRecognition::~NNFaceRecognition(void){}

void NNFaceRecognition::getRTSPParams(int ch, VideoSetting& config) { 
    RTSPwidth = config._w;
    RTSPheight = config._h;

    getRTSPFR(ch, RTSPwidth, RTSPheight);
}

void NNFaceRecognition::configVideo(int ch, VideoSetting& config) { // to config CH 4 for NN
    width = config._w;
    height = config._h;

    CAMDBG("Width [Ch%d]:%d  Height [Ch%d]:%d", ch, width, ch, height);

    if (_p_mmf_context == NULL) {
        _p_mmf_context = nnFaceRecogInit();
    }
    if (_p_mmf_context == NULL) {
        CAMDBG("NN init failed\r\n");
        return;
    }
}

void NNFaceRecognition::OSDDisplay(void) {
    OSDBeginFR();
}
