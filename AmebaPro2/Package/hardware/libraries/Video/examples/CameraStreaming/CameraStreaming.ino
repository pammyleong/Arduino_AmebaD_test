#include "CameraIO.h"
#include "camera.h"
#include "rtsp.h"
#include "WiFi.h"

CameraIOClass camio(1, 1);
CameraClass cam;
RTSPClass rtsp;

char ssid[] = "YourNetwork";     //  your network SSID (name)
char pass[] = "password";  	// your network password
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
    cam.pVideo = cam.init();
    cam.open(cam.pVideo);

    // init rtsp
    rtsp.pRTSP = rtsp.init();
    rtsp.open(rtsp.pRTSP);

    // create camera io linker
    camio.datalinker = camio.create();

    // add input
    camio.registerInput(camio.datalinker, cam.pVideo);
    
    // add output
    camio.registerOutput(camio.datalinker, rtsp.pRTSP);
    
    if(camio.start(camio.datalinker) != 0) {
        Serial.println("camera io link start failed");
    }    
    cam.start(cam.pVideo);
}


void loop() {
// do nothing
}

