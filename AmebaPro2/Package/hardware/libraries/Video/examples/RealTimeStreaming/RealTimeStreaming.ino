/**
 *  This function describes how to use the Realtek RTSP API. 
*/

#include "rtsp.h"

/* Create a RTSP object */
RTSP rtsp;

void setup() {
    //Serial.begin(115200);
	rtsp.Init();
}

void loop() {
	rtsp.RTSP_Open();
	rtsp.RTSP_Close();
	rtsp.DeInit();
}
