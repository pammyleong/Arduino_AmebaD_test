#include <Arduino.h>
#include "NN.h"

#define DEBUG 0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

VIPNN::VIPNN(){}

VIPNN::~VIPNN(){}

void VIPNN::configVideo(VideoSetting& config) {
    if (_p_mmf_context == NULL) {
        _p_mmf_context = nnFacedetInit();
    }
    if (_p_mmf_context == NULL) {
        CAMDBG("NN init failed\r\n");
        return;
    }

    uint32_t NN_width;
    uint32_t NN_height;
    uint32_t NN_rgb = 0; // set to 1 if want RGB->BGR or BGR->RGB

    NN_width = config._w;
    NN_height = config._h;

}

FaceRecg::FaceRecg(){

}

FaceRecg::~FaceRecg(){
    
}

