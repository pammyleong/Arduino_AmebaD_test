#ifndef __NN_FACERECOGNITION_H__
#define __NN_FACERECOGNITION_H__

#include "VideoStream.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "module_vipnn.h"

#ifdef __cplusplus
}
#endif

class NNFaceRecognition:public MMFModule {
    public:
        void begin(void);
        void end(void);

        void getResult(void);
        void setResultCallback(void);
    private:
        mm_context_t* facerecog_ctx = NULL;
        void* facerecog_siso_ctx = NULL;
};

#endif

