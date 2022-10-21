#include <Arduino.h>
#include "aac.h"
#include "faac.h"
#include "faaccfg.h"

#define DEBUG 0

// For aac
#define SAMPLERATE     8000
#define CH             1
#define BITLENGTH      FAAC_INPUT_16BIT
#define OUTPUTFORMAT   1
#define MPEGVER        MPEG4
#define MEMTOTALSIZE   10 * 1024
#define MEMBLOCKSIZE   128
#define MEMFRAMESIZE   1024

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

//-------------------------------------------------------------------------------//
/**
  * @brief  
  * @param  none
  * @retval none
  */
void AACClass::AACinit(void) {
	AACData = AAC_Init(); 

	AACOpen(AACData, SAMPLERATE, CH, BITLENGTH, OUTPUTFORMAT, MPEGVER, MEMTOTALSIZE, MEMBLOCKSIZE, MEMFRAMESIZE);

//	AAC_Set_Params(AACData->priv, SAMPLERATE, CH, BITLENGTH, OUTPUTFORMAT, MPEGVER, MEMTOTALSIZE, MEMBLOCKSIZE, MEMFRAMESIZE);
//	printf("AAC_Set_Params done\r\n");
//	
//	AAC_Set_Queue_Length(AACData->priv);
//	printf("AAC_Set_Queue_Length done\r\n");
//	
//	AAC_Init_Queue_Items(AACData->priv);
//	printf("AAC_Init_Queue_Items done\r\n");
//	
//	AAC_Init_Mem_Pool(AACData->priv);
//	printf("AAC_Init_Mem_Pool done\r\n");
//	
//	AAC_Apply(AACData->priv);
//	printf("AAC_Apply done\r\n");
}
        
//-------------------------------------------------------------------------------//
/**
  * @brief  
  * @param  none
  * @retval 
  */
mm_context_t *AACClass::AACgetIO(void) {
	if (AACData == NULL) {
		printf("Failed, please init AAC first.\r\n");	
		return NULL;
	}

	else {
		return AACData;
	}
}

//-------------------------------------------------------------------------------//
/**
  * @brief  
  * @param  
  * @retval none
  */
void AACClass::AACdeInit(){
	 if (AAC_DeInit(AACData->priv) == NULL) {
        CAMDBG("AAC DeInit.\r\n");
    }
    else {
        CAMDBG("AAC need to be DeInit.\r\n");
    }
}
//-------------------------------------------------------------------------------//

AudioClass::AudioClass(void){
    audioData = NULL;
};
AudioClass::~AudioClass(){};

void AudioClass::init(void) {
    audioData = audio_Init();
}

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

void AudioClass::open(mm_context_t *p, uint32_t sample_rate, uint32_t word_length, audio_mic_gain mic_gain, audio_dmic_gain dmic_l_gain, audio_dmic_gain dmic_r_gain, uint8_t use_mic_type, int channel, uint32_t enable_aec){
  
    audioOpen(p, sample_rate, word_length, mic_gain, dmic_l_gain, dmic_r_gain, use_mic_type, channel, enable_aec);
}

/**
  * @brief  
  * @param  none
  * @retval 
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

