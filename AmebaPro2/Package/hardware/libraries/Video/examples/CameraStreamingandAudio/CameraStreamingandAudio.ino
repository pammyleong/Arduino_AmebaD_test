#include "CameraIO.h"
#include "camera.h"
#include "rtsp.h"
#include "WiFi.h"
#include "aac.h"

CameraIOClass camio(1, 1); // Single Input Single Output
CameraIOClass camio1(1, 2); // Single Input Multi Output
CameraIOClass camio2(2, 1); // Multi Input Single Output
CameraIOClass camio3(1, 1); // Single Input Single Output


//CameraSetting camset;
//CameraSetting camset(VIDEO_FHD, CAM_FPS, VIDEO_H264, 0);
CameraClass cam;
CameraClass cam1;

CameraSetting camset(1); 

RTSPClass rtsp;
RTSPClass rtsp1; // Use for SIMO
AudioClass audio;
AACClass aac;

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
	cam.init(&camset);
	cam.open(&camset);
	Serial.println("cam init done");

//	cam1.init(&camset);
//	cam1.open(&camset);
//	Serial.println("cam init done");

	// init audio
	audio.init(); // Init to parse params to mm_context_t
	audio.open(); // running all the commands for audio
	Serial.println("audio init done");

	// init aac
	aac.AACinit(); // Init to parse params to mm_context_t and running all the commands for aac
	Serial.println("AAC init done");

	// init rtsp
//	rtsp.RTSP_Test();
	rtsp.init(&camset);
	rtsp.open();
	
	Serial.println("rtsp done");

	// Used for SIMO
	// rtsp1.init(&camset);
	// rtsp1.open();

	// ================================= create camera io linker
	// For siso
	camio.create();
	camio.registerInput(audio.getIO());
	camio.registerOutput(aac.AACgetIO());	
	if(camio.start() != 0) {
		Serial.println("camera io link start failed");
	}	 
	Serial.println("SISO 1 done");

	Serial.println("audio start");

	// For miso
	camio2.create();
	Serial.println("miso create done");
	
	camio2.registerInput0(cam.getIO());
	Serial.println("reg in 0 done");
	
	camio2.registerInput1(aac.AACgetIO());
	Serial.println("reg in 1 done");
	
	camio2.registerOutput(rtsp.getIO());
	Serial.println("reg out done");
	
	if(camio2.start() != 0) {
		Serial.println("camera io link start failed");
	}	 

	Serial.println("MISO done");

	cam.start(&camset);

	Serial.println("camera start");



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


