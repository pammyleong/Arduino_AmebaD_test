#include <Arduino.h>
#include "rtsp.h"

#define ON  1
#define OFF 0

RTSP::RTSP(){
	rtsp_ptr = (void *)&rtspData;
};

RTSP::~RTSP(){};

//Initialization of RTSP setting
void* RTSP::Init(void) {
	
	rtsp_ptr = RTSP_Init(); // ret rtsp_data to mm_context_t 
	RTSP_Select_Stream(rtsp_ptr, ch_idx);
	RTSP_Set_Params(rtsp_ptr, fps, bps, VC);
	RTSP_Set_Apply(rtsp_ptr);

	return rtsp_ptr;
}

// start streaming
void RTSP::RTSP_Open(void){
		
	if (rtsp_ptr == NULL) {
		printf("Streaming failed, RTSP not initialised yet.");
	}
	else {
		RTSP_Set_Streaming(rtsp_ptr, ON);
	}
}

//stop streaming
void RTSP::RTSP_Close(void){
	RTSP_Set_Streaming(rtsp_ptr, OFF);
}

// release all resource for RTSP
void RTSP::DeInit(void){
	if (RTSP_DeInit(rtsp_ptr) == NULL) {
		printf("RTSP DeInit.");
	}
	else {
		printf("RTSP need to be DeInit.");
	}
}
