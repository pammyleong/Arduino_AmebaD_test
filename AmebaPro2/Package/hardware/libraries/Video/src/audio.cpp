#include <Arduino.h>
#include "audio.h"

// For aac
#define SAMPLERATE     8000
#define CH             1
#define BITLENGTH      FAAC_INPUT_16BIT
#define OUTPUTFORMAT   1
#define MPEGVER        MPEG4
#define MEMTOTALSIZE   10 * 1024
#define MEMBLOCKSIZE   128
#define MEMFRAMESIZE   1024

#define DEBUG 0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

AACClass::AACClass(){
    AACData = NULL;
};
AACClass::~AACClass(){};

AudioClass::AudioClass(void){
    audioData = NULL;
};
AudioClass::~AudioClass(){};

/**
  * @brief  Init audio module
  * @param  none
  * @retval none
  */
void AudioClass::init(void) {
    audioData = audioInit();
}

/**
  * @brief  DeInit audio module
  * @param  none
  * @retval none
  */
void AudioClass::deInit(void) {

} 


/**
  * @brief  Open audio module
  * @param  none
  * @retval none
  */
void AudioClass::open(void) {
    uint32_t sample_rate = ASR_8KHZ;
	uint32_t word_length = WL_16BIT;
	audio_mic_gain mic_gain = MIC_0DB;
	audio_dmic_gain dmic_l_gain = DMIC_BOOST_24DB;
	audio_dmic_gain dmic_r_gain = DMIC_BOOST_24DB;
	uint8_t use_mic_type = USE_AUDIO_AMIC;
	int channel = 1;
	uint32_t enable_aec = 0;
    
    open(audioData, sample_rate, word_length, mic_gain, dmic_l_gain, dmic_r_gain, use_mic_type, channel, enable_aec);
}

/**
  * @brief  Open the audio module
  * @param  p           : pointer to audio content 
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
void AudioClass::open(mm_context_t *p, uint32_t sample_rate, uint32_t word_length, audio_mic_gain mic_gain, audio_dmic_gain dmic_l_gain, audio_dmic_gain dmic_r_gain, uint8_t use_mic_type, int channel, uint32_t enable_aec){
  
    audioOpen(p, sample_rate, word_length, mic_gain, dmic_l_gain, dmic_r_gain, use_mic_type, channel, enable_aec);
}

/**
  * @brief  Close the audio module
  * @param  
  * @retval none
  */
void AudioClass::close(void) {
    
}

/**
  * @brief  Get Audio module data pointer
  * @param  none
  * @retval none
  */
mm_context_t *AudioClass::getIO(void) {
	if (audioData == NULL) {
		printf("Failed, please init audio first.\r\n");	
		return NULL;
	}
	else {
		return audioData;
	}
}

/**
  * @brief  Init AAC (Advanced Audio Codec) module as audio encoder
  * @param  none
  * @retval none
  */
void AACClass::AACinit(void) {
	AACData = AACInit(); 
	AACOpen(AACData, SAMPLERATE, CH, BITLENGTH, OUTPUTFORMAT, MPEGVER, MEMTOTALSIZE, MEMBLOCKSIZE, MEMFRAMESIZE);
}

/**
  * @brief  Get AAC module data pointer
  * @param  none
  * @retval none
  */
mm_context_t *AACClass::AACgetIO(void) {
	if (AACData == NULL) {
		printf("[AAC] Failed, please init AAC first.");
		return NULL;
	}
	else {
		return AACData;
	}
}

/**
  * @brief  Deinit AAC (Advanced Audio Codec) module
  * @param  none
  * @retval none
  */
void AACClass::AACdeInit(void){
	 if (AACDeInit(AACData->priv) == NULL) {
        CAMDBG("AAC DeInit.\r\n");
    }
    else {
        CAMDBG("AAC need to be DeInit.\r\n");
    }
}

