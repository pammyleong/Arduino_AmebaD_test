#ifndef __NNOBJDETCTION_H__
#define __NNOBJDETCTION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "nn_objdet_drv.h"

#ifdef __cplusplus
}
#endif

#include "VideoStream.h"


class NNObjDetection:public MMFModule {
    public:
        NNObjDetection(void);
        ~NNObjDetection(void);
        
        void getRTSPParams(int ch, VideoSetting& config);
        void configVideo(int ch, VideoSetting& config);
        void begin(void);
        void end(void);
        // void YUV(void);
        void OSDDisplay(void);
    private:
        uint32_t width;
        uint32_t height;
        uint32_t RTSPwidth;
        uint32_t RTSPheight;
};


#endif
