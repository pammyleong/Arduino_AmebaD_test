#include "CameraIO.h"
#include "WiFi.h"
#include "camera.h"
#include "rtsp.h"

CameraSetting camset(VIDEO_FHD, CAM_FPS, VIDEO_H264, 0,
                     0, 0, 0, 0,
                     0, 0, 0, 0,
                     0, 0);

CameraSetting camset2(0, 0, 0, 0,
                      VIDEO_HD, CAM_FPS, VIDEO_H264, 0,
                      0, 0, 0, 0,
                      0, 0);
CameraClass cam;
CameraClass cam2;
RTSPClass rtsp;
RTSPClass rtsp1;
CameraIOClass camio1_2In2Out(2, 2);  // Multi Input Multi Output

char ssid[] = "Aurical_5G";   //  your network SSID (name)
char pass[] = "wyy170592";    // your network password
int status = WL_IDLE_STATUS;  // the Wifi radio's status

void setup() {
    Serial.begin(115200);

    if (WiFi.status() == WL_NO_SHIELD) {
        Serial.println("WiFi shield not present");
        // don't continue:
        while (true)
            ;
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

    cam2.init(&camset2);
    cam2.open(&camset2);

    // init rtsp
    rtsp.init(&camset);
    rtsp.open();

    rtsp1.init(&camset2);
    rtsp1.open();

    // create camera io linker
    camio1_2In2Out.create();
    camio1_2In2Out.registerInput1(cam.getIO());
    camio1_2In2Out.registerInput2(cam2.getIO());
    camio1_2In2Out.registerOutput1(rtsp.getIO());
    camio1_2In2Out.registerOutput2(rtsp1.getIO());
    if (camio1_2In2Out.start() != 0) {
        Serial.println("camera io link 1 start failed");
    }

    cam.start(&camset);
    cam2.start(&camset2);
}

void loop() {
    // do nothing
}
