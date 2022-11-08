#include "CameraIO.h"
#include "WiFi.h"
#include "camera.h"
#include "rtsp.h"

// MAX output for now is 2
CameraIOClass camio1(1, 2);  // Single Input Multiple Output

CameraClass cam;
CameraSetting camset;

// both rtsp using the same params setting
RTSPClass rtsp;
RTSPClass rtsp1;

char ssid[] = "Aurical_5G";   // your network SSID (name)
char pass[] = "wyy170592";    // your network password
int status = WL_IDLE_STATUS;  // the Wifi radio's status

void setup() {
    Serial.begin(115200);
    Serial.println("Just setup");

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
    cam.init(camset);
    cam.open(camset);

    // init rtsp
    rtsp.init(camset);
    rtsp.open();

    rtsp1.init(camset);
    rtsp1.open();

    // create camera io linker
    camio1.create();
    camio1.registerInput(cam.getIO());
    camio1.registerOutput1(rtsp.getIO());
    camio1.registerOutput2(rtsp1.getIO());

    if (camio1.start() != 0) {
        Serial.println("camera io link start failed");
    }

    cam.start(camset);
    Serial.println("Cam start!");
}

void loop() {}
