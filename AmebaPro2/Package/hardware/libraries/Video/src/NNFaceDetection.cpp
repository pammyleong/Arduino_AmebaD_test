#include <Arduino.h>
#include "NNFaceDetection.h"

#define DEBUG 1

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

//#define NN_WIDTH    576//640
//#define NN_HEIGHT   320//640

NNFaceDetection::NNFaceDetection(void){}
NNFaceDetection::~NNFaceDetection(void){}

void NNFaceDetection::getRTSPParams(int ch, VideoSetting& config) { 
    RTSPwidth = config._w;
    RTSPheight = config._h;

    getRTSP(ch, RTSPwidth, RTSPheight);
}

/** ======================= to be merged with function below =======================
  * @brief  Configuration of Face Detection module
  * @param  ch     : video channel 4
  *         config : video settings parameters
  * @retval none
  */
void NNFaceDetection::configVideo(int ch, VideoSetting& config) { // to config CH 4 for NN
    width = config._w;
    height = config._h;

    CAMDBG("Width [Ch%d]:%d  Height [Ch%d]:%d", ch, width, ch, height);

    if (_p_mmf_context == NULL) {
        _p_mmf_context = nnFacedetInit();
    }
    if (_p_mmf_context == NULL) {
        CAMDBG("NN init failed\r\n");
        return;
    }

    nnSetFacedetModel(_p_mmf_context->priv);
    nnSetFacedetInputParam(_p_mmf_context->priv);
    nnSetFacedetDisppost(_p_mmf_context->priv);
    nnFacedetSetApply(_p_mmf_context->priv);
}

// configuration of Face Detection module when cascaded by Face Recognition module
void NNFaceDetection::configVideo(int ch, VideoSetting& config, int faceRecogFlag) { // to config CH 4 for NN
    width = config._w;
    height = config._h;

    CAMDBG("Width [Ch%d]:%d  Height [Ch%d]:%d", ch, width, ch, height);

    if (_p_mmf_context == NULL) {
        _p_mmf_context = nnFacedetInit();
    }
    if (_p_mmf_context == NULL) {
        CAMDBG("NN init failed\r\n");
        return;
    }
    
    if (faceRecogFlag == 0){                        // Facedetect only
        nnSetFacedetModel(_p_mmf_context->priv);
        nnSetFacedetInputParam(_p_mmf_context->priv);
        nnSetFacedetDisppost(_p_mmf_context->priv);
        nnFacedetSetApply(_p_mmf_context->priv);
    } 
    else if (faceRecogFlag == 1) {
        nnSetFacedetModel(_p_mmf_context->priv);    // Facedetect cascade with Facenet
        nnSetFacedetInputParam(_p_mmf_context->priv);
        nnSetFacedetOutput(_p_mmf_context->priv);
        nnSetFacedetDatagroup(_p_mmf_context, MM_GROUP_START);
        cameraSetQLen(_p_mmf_context, 1);
        cameraSetQItem(_p_mmf_context);
        nnFacedetSetApply(_p_mmf_context->priv);
    } else if (faceRecogFlag == 2) { 
        nnSetFacedetModel2(_p_mmf_context->priv);   // Facenet
        nnSetFacedetCascade(_p_mmf_context->priv);
        nnSetFacedetOutput(_p_mmf_context->priv);
        nnSetFacedetDatagroup(_p_mmf_context, MM_GROUP_END);
        cameraSetQLen(_p_mmf_context, 1);
        cameraSetQItem(_p_mmf_context);
        nnFacedetSetApply(_p_mmf_context->priv);
    } else {
        printf("WARNING MESSEAGE \r\n");
    }

}

void NNFaceDetection::begin(void) {
    cameraStart(_p_mmf_context->priv, 4); // 4 is the channel for NN
}

void NNFaceDetection::end(void) {
    // to be done
}

void NNFaceDetection::YUV(void) {
    cameraYUV(_p_mmf_context->priv);
}

void NNFaceDetection::OSDDisplay(void) {
    OSDBegin();
}

