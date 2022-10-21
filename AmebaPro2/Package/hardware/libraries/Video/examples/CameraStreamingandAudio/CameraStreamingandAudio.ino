#include "CameraIO.h"
#include "camera.h"
#include "audio.h"
#include "rtsp.h"
#include "WiFi.h"

CameraIOClass camio(1, 1); // Single Input Single Output
CameraIOClass camio1(2, 1); // Multi Input Single Output
CameraClass cam;
CameraSetting camset(1); 
//CameraSetting camset;
//CameraSetting camset(VIDEO_FHD, CAM_FPS, VIDEO_H264, 0);
AudioClass audio;
AACClass aac;
RTSPClass rtsp;

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

        // wait 2 seconds for connection:
        delay(2000);
    }

	cam.init(&camset);
	cam.open(&camset);

	audio.init(); 
	audio.open(); 

	aac.AACinit();

	rtsp.init(&camset);
	rtsp.open();
	
	// SISO for Audio [AAC-AUDIO]
	camio.create();
	camio.registerInput(audio.getIO());
	camio.registerOutput(aac.AACgetIO());	
	if(camio.start() != 0) {
		Serial.println("camera io link 1 start failed");
	}
	
	// MISO [V-A-RTSP]
	camio1.create();
	camio1.registerInput0(cam.getIO());
	camio1.registerInput1(aac.AACgetIO());
	camio1.registerOutput(rtsp.getIO());

	if(camio1.start() != 0) {
		Serial.println("camera io link 2 start failed");
	}	 

	cam.start(&camset);

}

void loop() {
// do nothing
}


