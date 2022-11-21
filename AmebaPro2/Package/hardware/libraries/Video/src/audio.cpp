#include <Arduino.h>
#include "audio.h"

#define DEBUG 0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

/**
  * @brief  initialize audio stream settings for the audio codec
  * @param  preset: select one of the preset audio stream settings. default preset is 1
  * @retval none
  */
AudioSetting::AudioSetting(uint8_t preset) {
    switch (preset) {
        case 0: {
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            break;
        }
        default: {
            printf("Invalid AudioSetting preset!\r\n");
            return;
            break;
        }
    }
    _preset = preset;
}

Audio::Audio(void) {
    if (_p_mmf_context == NULL) {
        _p_mmf_context = audioInit();
    }
    if (_p_mmf_context == NULL) {
        CAMDBG("Audio init failed\r\n");
        return;
    }
}

Audio::~Audio(void) {
    if (_p_mmf_context == NULL) {
        return;
    }
    end();
    if (audioDeinit(_p_mmf_context) == NULL) {
        _p_mmf_context = NULL;
    } else {
        CAMDBG("Audio deinit failed\r\n");
    }
}

/**
  * @brief  Configure audio module by setting up audio paramters
  * @param  config : AudioSetting object
  * @retval none
  */
void Audio::configAudio(AudioSetting& config) {
    //TBD
}

/**
  * @brief  Open audio module, parameters can be adjusted in audio.h
  * @param  none
  * @retval none
  */
void Audio::begin(void) {
    if (_p_mmf_context == NULL) {
        CAMDBG("Need Audio init first\r\n");
        return;
    }
    int channel = AUDIO_CH;
    uint8_t use_mic_type        = AUDIO_MIC_TYPE;
    uint32_t enable_aec         = AUDIO_AEC_FLAG; 
    uint32_t sample_rate        = AUDIO_SAMPLERATE;
    uint32_t word_length        = AUDIO_WORD_LEN;
    audio_mic_gain mic_gain     = AUDIO_MIC_GAIN;
    audio_dmic_gain dmic_l_gain = AUDIO_DMIC_L_GAIN;
    audio_dmic_gain dmic_r_gain = AUDIO_DMIC_R_GAIN;

    begin(_p_mmf_context, sample_rate, word_length, mic_gain, dmic_l_gain, dmic_r_gain, use_mic_type, channel, enable_aec);
}

/**
  * @brief  Open the audio module
  * @param  p           : pointer to audio object 
            sample_rate : audio data sampling rate
            word_length : word length
            mic gain    : gain of the analog microphone
            dmic_l_gain : gain of the left digital microphone
            dmic_r_gain : gain of the right digital microphone
            use_mic_type: digital or analog microphone 
            channel     : channel name
            enable_aec  : enable or disable Acoustic Echo Cancelling
  * @retval none
  */
void Audio::begin(mm_context_t *p, uint32_t sample_rate, uint32_t word_length, audio_mic_gain mic_gain, audio_dmic_gain dmic_l_gain, audio_dmic_gain dmic_r_gain, uint8_t use_mic_type, int channel, uint32_t enable_aec) {
    audioOpen(p, sample_rate, word_length, mic_gain, dmic_l_gain, dmic_r_gain, use_mic_type, channel, enable_aec);
}

/**
  * @brief  Close the audio module
  * @param  pointer to audio object 
  * @retval none
  */
void Audio::end(void) {
    if (_p_mmf_context == NULL) {
        return;
    }
    audioClose(_p_mmf_context);
}

AAC::AAC(void) {
    if (_p_mmf_context == NULL) {
        _p_mmf_context = AACInit();
    }
    if (_p_mmf_context == NULL) {
        CAMDBG("AAC init failed\r\n");
        return;
    }
}

AAC::~AAC(void) {
    if (_p_mmf_context == NULL) {
        return;
    }
    end();
    if (AACDeinit(_p_mmf_context) == NULL) {
        _p_mmf_context = NULL;
    } else {
        CAMDBG("AAC deinit failed\r\n");
    }
}

/**
  * @brief  Configure AAC module by setting up audio paramters
  * @param  config : AudioSetting object
  * @retval none
  */
void AAC::configAudio(AudioSetting& config) {
    //TBD
}

/**
  * @brief  Start AAC (Advanced Audio Codec) module audio encoder
  * @param  none
  * @retval none
  */
void AAC::begin(void) {
    AACOpen(_p_mmf_context, AAC_SAMPLERATE, AAC_CH, AAC_BIT_LENGTH, AAC_OUTPUT_FORMAT, AAC_MPEG_VER, AAC_MEM_TOTAL_SIZE, AAC_MEM_BLOCK_SIZE, AAC_MEM_FRAME_SIZE);
}

/**
  * @brief  Stop AAC module while transmision is finished
  * @param  none
  * @retval none
  */
void AAC::end(void) {
    if (_p_mmf_context == NULL) {
        return;
    }
    AACStop(_p_mmf_context);
}
