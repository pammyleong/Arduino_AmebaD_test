/**
 *  This function describes how to use the Realtek RTSP API. 
*/

#include "rtsp.h"
#include "WiFi.h"


/* Create a RTSP object */
RTSP rtsp;

char ssid[] = "Aurical_5G";     //  your network SSID (name)
char pass[] = "wyy170592";  	// your network password
int status = WL_IDLE_STATUS;    // the Wifi radio's status

void setup() {
    Serial.begin(115200);

    if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
	}

	// attempt to connect to Wifi network:
	while (status != WL_CONNECTED) {
	    Serial.print("Attempting to connect to WPA SSID: ");
	    Serial.println(ssid);
	    // Connect to WPA/WPA2 network:
	    status = WiFi.begin(ssid, pass);

	    // wait 10 seconds for connection:
	    delay(10000);
	}
	
	rtsp.Init();
	Serial.println("RTSP Inited");
	
	rtsp.Open(); // Start Streaming
	Serial.println("RTSP Opened");
	
//	rtsp.Close(); // End Streaming
//	Serial.println("RTSP Closed");
//	rtsp.DeInit(); // Release all resources for RTSP
}

void loop() {
// do nothing
}
