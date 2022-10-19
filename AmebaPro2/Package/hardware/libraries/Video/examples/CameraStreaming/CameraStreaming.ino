#include "CameraIO.h"
#include "camera.h"
#include "rtsp.h"
#include "WiFi.h"

CameraIOClass camio(1, 1); // Single Input Single Output
CameraClass cam;
CameraSetting camset(VIDEO_FHD, VIDEO_H264, CAM_FPS, 0);


RTSPClass rtsp;

char ssid[] = "Aurical_5G";     //  your network SSID (name)
char pass[] = "wyy170592";  	// your network password
int status = WL_IDLE_STATUS;    // the Wifi radio's status

#define VERSION     1

void setup() {

    Serial.begin(115200);
    Serial.println("Just setup");
    
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
//    cam.init(VERSION);
    cam.init(&camset);
    cam.open(VERSION);

    // init rtsp
    rtsp.init();
    rtsp.open();

    // create camera io linker
    camio.create();

    // add input
    camio.registerInput(cam.getIO());
    
    // add output
    camio.registerOutput(rtsp.getIO());
    
    if(camio.start() != 0) {
        Serial.println("camera io link start failed");
    }    
    
    cam.start(VERSION);
}


void loop() {
// do nothing
}

