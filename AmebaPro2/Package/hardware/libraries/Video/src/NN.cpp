#include <Arduino.h>
#include "NN.h"

#define DEBUG 0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

// Object Detection
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

// Face Detection
// configuration of Face Detection module when cascaded by Face Recognition module
void NNFaceDetection::configVideo(VideoSetting& config, int faceRecogFlag) { // to config CH 4 for NN

    if (_p_mmf_context == NULL) {
        _p_mmf_context = nnFDInit();
    }
    if (_p_mmf_context == NULL) {
        CAMDBG("NN init failed\r\n");
        return;
    }
    
    if (faceRecogFlag == 0){                        // Facedetect only
        nnSetFDModel(_p_mmf_context->priv);
        nnSetFDInputParam(_p_mmf_context->priv);
        nnSetFDDisppost(_p_mmf_context->priv);
        nnFDSetApply(_p_mmf_context->priv);
    } else if (faceRecogFlag == 1) {
        nnSetFDModel(_p_mmf_context->priv);    // Facedetect cascade with Facenet
        nnSetFDInputParam(_p_mmf_context->priv);
        nnSetFDOutput(_p_mmf_context->priv);
        nnSetFDDatagroup(_p_mmf_context, MM_GROUP_START);
        cameraSetQLen(_p_mmf_context, 1);
        cameraSetQItem(_p_mmf_context);
        nnFDSetApply(_p_mmf_context->priv);
    } else if (faceRecogFlag == 2) {
        nnSetFNModel(_p_mmf_context->priv);   // Facenet
        nnSetFDCascade(_p_mmf_context->priv);
        nnSetFDOutput(_p_mmf_context->priv);
        nnSetFDDatagroup(_p_mmf_context, MM_GROUP_END);
        cameraSetQLen(_p_mmf_context, 1);
        cameraSetQItem(_p_mmf_context);
        nnFDSetApply(_p_mmf_context->priv);
    } else {
        printf("WARNING MESSEAGE \r\n");
    }
}

void NNFaceDetection::configModel(VideoSetting& config) {
     configFD(config._w, config._h);
}

void NNFaceDetection::configOSD(int ch, VideoSetting& config) {
    configFDOSD(ch, config._w, config._h);
}

// Face Recog
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