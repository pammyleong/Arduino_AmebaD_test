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

class NNObjectDetection:public MMFModule {
    public:
        void configVideo(VideoSetting& config);
        void configThreshold(float confidence_threshold, float nms_threshold);
        void begin(void);
        void end(const MMFModule& module);
        void setCallback(void (*od_callback)(objdetect_res_t *));
        objdetect_res_t* getResult(void);

    private:
        static int checkList(int class_indx);
        static void setDispCallback(void *p, void *img_param);
        static objdetect_res_t _p_objdet_result;
        static void (*OD_user_CB)(objdetect_res_t *);
        nn_data_param_t od_param = {0};
        float nn_confidence_thresh = 0;
        float nn_nms_thresh = 0;
};
#endif
