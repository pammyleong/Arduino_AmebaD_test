#include "CameraIO.h"
#include "camera.h"
#include "rtsp.h"
#include "WiFi.h"

#define USE_SISO 1
#define USE_MISO 0
#define USE_SIMO 0

#if USE_SISO
CameraIOClass camio(1, 1); // Single Input Single Output
#endif

#if USE_SIMO
CameraIOClass camio(1, 2);
#endif

#if USE_MISO
CameraIOClass camio(2, 1);
#endif

CameraClass cam;
//CameraSetting camset;
CameraSetting camset(1); 
//CameraSetting camset(VIDEO_FHD, CAM_FPS, VIDEO_H264, 0);

RTSPClass rtsp;
#if USE_SIMO
RTSPClass rtsp1;
#endif

char ssid[] = "Aurical_5G";     // your network SSID (name)
char pass[] = "wyy170592";  	// your network password
int status = WL_IDLE_STATUS;    // the Wifi radio's status

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
    cam.init(&camset);
    cam.open(&camset);

    // init rtsp
    rtsp.init(&camset);
    rtsp.open();

#if USE_SIMO
    rtsp1.init(&camset);
    rtsp1.open();
#endif

    // create camera io linker
    camio.create();

    // add input
    camio.registerInput(cam.getIO());
    
#if USE_MISO // currently no example for testing miso
//    camio.registerInput0(rtsp.getIO());
//    camio.registerInput1(xxxx.getIO());
#endif 
    // add output
    camio.registerOutput(rtsp.getIO());

#if USE_SIMO
    camio.registerOutput0(rtsp.getIO());
    camio.registerOutput1(rtsp1.getIO());
#endif

    if(camio.start() != 0) {
        Serial.println("camera io link start failed");
    }    
    
    cam.start(&camset);
}


void loop() {
// do nothing
}

