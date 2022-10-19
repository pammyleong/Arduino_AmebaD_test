#ifndef __RTSP_H__
#define __RTSP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "aac_drv.h"
#include "avcodec.h"

#ifdef __cplusplus
}
#endif

class AACClass {
    public:
        AACClass(void);
        ~AACClass(void);

        void AACinit(void);
        void AACdeInit(void);
        mm_context_t *AACgetIO(void);
        
    private:
        mm_context_t *AACData;
};

class AudioClass {
    public:
        AudioClass(void);
        ~AudioClass(void);

        void init(void);
        void deinit(void);
        
        void open(void);
        void open(mm_context_t *p, int sample_rate, int word_lengh, int mic_gain, int dmic_l_gain, int dmic_r_gain, int use_mic_type, int channel, int enable_aec);
        void close(void);
        
    private:
        mm_context_t *audioData;
};

#endif



