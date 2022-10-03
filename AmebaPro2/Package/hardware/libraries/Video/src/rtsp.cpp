#include <Arduino.h>
#include "rtsp.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "rtsp_drv.h"

#ifdef __cplusplus
}
#endif


#define ON  1
#define OFF 0

RTSP::RTSP(){
	rtsp_ptr = (void *)&rtspData;
};

RTSP::~RTSP(){};

//Initialization of RTSP setting
void* RTSP::Init(void) {
	
	RTSP_Init();
	RTSP_Select_Stream(rtsp_ptr, ch_idx);
	RTSP_Set_Params(rtsp_ptr, fps, bps, VC);
	RTSP_Set_Apply(rtsp_ptr);

	return rtsp_ptr;
}

// start streaming
void RTSP::RTSP_Open(void){
		
	if (RTSP_Init() == NULL) {
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
	//RTSP_DeInit();
}


//RTSP rtsp(0, 30, 8196, 1);

