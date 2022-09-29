#include <Arduino.h>
#include "rtsp.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "rtsp_drv.h"

#ifdef __cplusplus
}
#endif

static data_content_t *rtspData = NULL;


RTSP::RTSP(){};
RTSP::~RTSP(){};

/**
  * @brief  none
  * @param  none
  * @retval  none
  */
void RTSP::RTSP_Init(void) {
	int a = RTSP_Set_Apply ();
    
    if (a > 0){
        rtspData = RTSP_Open();
    }
}


