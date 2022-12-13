#ifndef __NNFACEDETCTION_H__
#define __NNFACEDETCTION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "nn_facedet_drv.h"

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

class NNFaceDetection:public MMFModule {
    public:
        NNFaceDetection(void);
        ~NNFaceDetection(void);
        
        void getRTSPParams(int ch, VideoSetting& config);
        void configVideo(int ch, VideoSetting& config);
        void begin(void);
        void end(void);
        void YUV(void);
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
