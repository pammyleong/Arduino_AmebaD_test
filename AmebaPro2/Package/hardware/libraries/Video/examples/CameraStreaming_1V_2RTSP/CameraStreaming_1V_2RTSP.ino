#include "CameraIO.h"
#include "camera.h"
#include "rtsp.h"
#include "WiFi.h"

CameraIOClass camio(1, 2); // Single Input Multi Output
CameraClass cam;
RTSPClass rtsp;
RTSPClass rtsp1;

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

    // init camera
    cam.init();
    cam.open();

    // init rtsp
    rtsp.init();
    rtsp.open();
    rtsp1.init();
    rtsp1.open();

    // create camera io linker
    camio.create();

    // add input
    camio.registerInput(cam.getIO());
    
    //add output
    camio.registerOutput0(rtsp.getIO());
    camio.registerOutput1(rtsp1.getIO());
    
    if(camio.start() != 0) {
        Serial.println("camera io link start failed");
    }    
    
    cam.start();

//  method 1: Use delay to pause, close and deinit.
//	delay(10000);
//		
//	// pause linker
//	Serial.println("Pause!");
//	camio.pause();
//	delay(5000);
//			
//	// stop module
//	Serial.println("Stop RTSP and camera module");
//	rtsp.close();
//	rtsp1.close();
//	cam.close();
//	
//	// close module (deinit)
//	Serial.println("DeInit RTSP and camera module.");
//	rtsp.deInit();
//	rtsp1.deInit();
//	cam.deInit();

	//Method 2: Use GPIO pins to pause, resume, close and deinit.
	//TBC
	

}

void loop() {
// do nothing
}


