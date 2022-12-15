#ifndef __NNFACERECOGNITION_H__
#define __NNFACERECOGNITION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "nn_facerecog_drv.h"

#ifdef __cplusplus
}
#endif

#include "VideoStream.h"

//class NNModelSetting {
//    friend class NNSetting;
//
//    public:
//
//    private:
//};

class NNFaceRecognition:public MMFModule  {
    public:
        NNFaceRecognition(void);
        ~NNFaceRecognition(void);
        
        void getRTSPParams(int ch, VideoSetting& config);
        void configVideo(int ch, VideoSetting& config);
        void OSDDisplay(void);
    private:
        uint32_t width;
        uint32_t height;
        uint32_t RTSPwidth;
        uint32_t RTSPheight;
};

//class FaceRecg:public MMFModule {
//     public:
//        FaceRecg(void);
//        ~FaceRecg(void);
//    private:
//};

#endif
