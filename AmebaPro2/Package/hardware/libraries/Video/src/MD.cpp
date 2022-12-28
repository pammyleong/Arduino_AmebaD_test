#include <Arduino.h>
#include "MD.h"

#define DEBUG 0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

MD::MD(void){}
MD::~MD(void){}

void MD::getOSDParams(int ch, VideoSetting& config) {
    uint32_t RTSPwidthMD = config._w;
    uint32_t RTSPheightMD = config._h;

    MDOSDConfig(ch, RTSPwidthMD, RTSPheightMD);
}

void MD::configVideo (int ch, VideoSetting& config) { // to config 
    if (_p_mmf_context == NULL) {
        _p_mmf_context = MDInit();
    }
    if (_p_mmf_context == NULL) {
        CAMDBG("MD init failed\r\n");
        return;
    }

    int width = config._w;
    int height = config._h;

    setMDParams(_p_mmf_context->priv, width, height);
    printf("SET MD PARAMS DONE\r\n");
    setMDThres(_p_mmf_context->priv);
    printf("SET MD THRES DONE\r\n");
    setMDMask(_p_mmf_context);
    printf("SET MD MASK DONE\r\n");
    setMDDisppost(_p_mmf_context->priv);
    printf("SET MD DISPPOST DONE\r\n");
    setMDTrigBlock(_p_mmf_context->priv); //md triggered when at least 3 motion block triggered
    printf("SET MD TRIG BLOCK DONE\r\n");
}

void MD::begin(void) {
    cameraStart(_p_mmf_context->priv, 4); // 4 is the channel for NN
    printf("MD.cpp begin\r\n");
}

void MD::OSDDraw(void) {
    MDDraw();
}