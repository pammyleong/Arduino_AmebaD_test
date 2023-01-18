#ifndef __NNOBJECTDETECTION_H__
#define __NNOBJECTDETECTION_H__

#include "VideoStream.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "nn_utils/class_name.h"
#include "module_vipnn.h"

#ifdef __cplusplus
}
#endif

#undef min
#undef max
#include <vector>

class ObjectDetectionResult {
    friend class NNObjectDetection;
    public:
        const char* name(void);
        uint8_t score(void);
        float xmin(void);
        float xmax(void);
        float ymin(void);
        float ymax(void);

    private:
        detobj_t result = {0};
};

class NNObjectDetection:public MMFModule {
    public:
        NNObjectDetection(void);
        ~NNObjectDetection(void);

        void configVideo(VideoSetting& config);
        void configThreshold(float confidence_threshold, float nms_threshold);
        void begin(void);
        void end(void);

        void setResultCallback(void (*od_callback)(objdetect_res_t *));
        objdetect_res_t* getResult(void);
        uint16_t getResultCount(void);
        ObjectDetectionResult getResult(uint16_t index);
//        const char* getObjectName(uint8_t id);

    private:
        static void ODResultCallback(void *p, void *img_param);

        static std::vector<ObjectDetectionResult> object_result_vector;
        static objdetect_res_t objdet_result;
        static void (*OD_user_CB)(objdetect_res_t *);

        nn_data_param_t roi_nn = {0};
        float od_confidence_thresh = 0.5;
        float od_nms_thresh = 0.3;
};
#endif
