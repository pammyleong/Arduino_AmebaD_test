#ifndef __NN_FACEDETECTION_H__
#define __NN_FACEDETECTION_H__

#include "VideoStream.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "module_vipnn.h"

#ifdef __cplusplus
}
#endif

class NNFaceDetection:public MMFModule {
    public:
        void configVideo(VideoSetting& config);
        void configFaceRecogCascadedMode(uint8_t enable);
        void begin(void);
        void end(void);

        void setResultCallback(void);
        void getResult(void);
    private:
        uint8_t cascaded_mode = 0;
        nn_data_param_t roi_nn = {0};
};

#endif
