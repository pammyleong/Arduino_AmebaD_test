#ifndef __AAC_H__
#define __AAC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "aac_drv.h"
#include "avcodec.h"
#include "audio_api.h"

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
//      void open(mm_context_t *p, int sample_rate, int word_lengh, int mic_gain, int dmic_l_gain, int dmic_r_gain, int use_mic_type, int channel, int enable_aec);
		void open(mm_context_t *p, uint32_t sample_rate, uint32_t word_length, audio_mic_gain mic_gain, audio_dmic_gain dmic_l_gain, audio_dmic_gain dmic_r_gain, uint8_t use_mic_type, int channel, uint32_t enable_aec);

        void close(void);

		mm_context_t *getIO(void);
        
    private:
        mm_context_t *audioData;
};

#endif



