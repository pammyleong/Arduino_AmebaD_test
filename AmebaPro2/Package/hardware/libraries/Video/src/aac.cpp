#include <Arduino.h>
#include "aac.h"

//#define ON  1
//#define OFF 0
#define DEBUG 0

//// video
//#define CH_IDX 0
//
//#define VID_TYPE AVMEDIA_TYPE_VIDEO
//#define AUDIO_TYPE AVMEDIA_TYPE_AUDIO
//#define VID_FPS 30
//#define VID_BPS 2*1024*1024
//#define AV_CODEC AV_CODEC_ID_H264

// For aac
//#define SAMPLERATE     8000
//#define CH             1
//#define BITLENGTH      FAAC_INPUT_16BIT
//#define OUTPUTFORMAT   1
//#define MPEGVER        MPEG4
//#define MEMTOTALSIZE   10 * 1024
//#define MEMBLOCKSIZE   128
//#define MEMFRAMESIZE   1024

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n"fmt"\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

AACClass::AACClass(){
    AACData = NULL;
};
AACClass::~AACClass(){};


/**
  * @brief  
  * @param  none
  * @retval none
  */
void AACClass::init(void) {
	AACData = AAC_Init(); 

	AAC_Set_Params(AACData->priv, sample_rate, channel, bit_length, output_format, mpeg_version, mem_total_size, mem_block_size, mem_frame_size);
	AAC_Set_Queue_Length(AACData->priv);
	AAC_Init_Queue_Items(AACData->priv);
	AAC_Init_Mem_Pool(AACData->priv);
	AAC_Apply(AACData->priv);
}
        

/**
  * @brief  
  * @param  none
  * @retval 
  */
mm_context_t *AACClass::getIO(void) {
	if (AACData == NULL) {
		printf("Failed, please init AAC first.\r\n");	
		return NULL;
	}

	else {
		return AACData;
	}
}


/**
  * @brief  
  * @param  
  * @retval none
  */
void AACClass::deInit(){
	 if (AAC_DeInit(AACData->priv) == NULL) {
        CAMDBG("AAC DeInit.\r\n");
    }
    else {
        CAMDBG("AAC need to be DeInit.\r\n");
    }
}