/**
 *  This function describes how to use the Realtek RTSP API. 
*/

#include "rtsp.h"

/* Create a RTSP object */
RTSP rtsp;

void setup() {
    Serial.begin(115200);
	Serial.println("RTSP start");
	rtsp.Init();
	Serial.println("RTSP Open");
	rtsp.RTSP_Open();

	Serial.println("---------------");
	rtsp.RTSP_Close();
	Serial.println("RTSP Closed");
	rtsp.DeInit();
}

void loop() {

}
