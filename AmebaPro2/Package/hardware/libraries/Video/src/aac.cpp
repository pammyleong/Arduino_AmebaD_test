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
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n"fmt"\r\n", __func__, __LINE__, ## args); } while (0);
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
void AACClass::init(void) {
	AACData = AAC_Init(); 

	AAC_Set_Params(AACData->priv, SAMPLERATE, CH, BITLENGTH, OUTPUTFORMAT, MPEGVER, MEMTOTALSIZE, MEMBLOCKSIZE, MEMFRAMESIZE);
	printf("AAC_Set_Params done\r\n");
	
	AAC_Set_Queue_Length(AACData->priv);
	printf("AAC_Set_Queue_Length done\r\n");
	
	AAC_Init_Queue_Items(AACData->priv);
	printf("AAC_Init_Queue_Items done\r\n");
	
	AAC_Init_Mem_Pool(AACData->priv);
	printf("AAC_Init_Mem_Pool done\r\n");
	
	AAC_Apply(AACData->priv);
	printf("AAC_Apply done\r\n");
}
        
//-------------------------------------------------------------------------------//
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

//-------------------------------------------------------------------------------//
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
//-------------------------------------------------------------------------------//