#include <Arduino.h>
#include "rtsp.h"

#define ON  1
#define OFF 0

RTSP::RTSP(){
	//rtsp_ptr = (void *)&rtspData;
};

RTSP::~RTSP(){};

//Initialization of RTSP setting
void* RTSP::Init(void) {
	printf("[%s] RTSP start Init\r\n", __FUNCTION__);
	rtspData = RTSP_Init(); // ret rtsp_data to mm_context_t 
	printf("rstp_ptr= %d\n\r", rtspData);
	
	printf("[%s] RTSP Init done\r\n", __FUNCTION__);
	
	RTSP_Select_Stream(rtspData->priv, ch_idx);
	printf("[%s] RTSP RTSP_Select_Stream\r\n", __FUNCTION__);
	
	RTSP_Set_Params(rtspData->priv, fps, bps, VC);
	printf("[%s] RTSP RTSP_Set_Params\r\n", __FUNCTION__);

	RTSP_Set_Apply(rtspData->priv);
	printf("[%s] RTSP RTSP_Set_Apply\r\n", __FUNCTION__);

	return rtspData->priv;
}

// start streaming
void RTSP::RTSP_Open(void){
		
	if (rtspData->priv == NULL) {
		printf("Streaming failed, RTSP not initialised yet.");
	}
	else {
		RTSP_Set_Streaming(rtspData->priv, ON);
	}
}

//stop streaming
void RTSP::RTSP_Close(void){
	RTSP_Set_Streaming(rtspData->priv, OFF);
}

// release all resource for RTSP
void RTSP::DeInit(void){
	if (RTSP_DeInit(rtspData->priv) == NULL) {
		printf("RTSP DeInit.");
	}
	else {
		printf("RTSP need to be DeInit.");
	}
}
