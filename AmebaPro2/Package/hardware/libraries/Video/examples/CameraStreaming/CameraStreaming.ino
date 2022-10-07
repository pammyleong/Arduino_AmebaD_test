#include "CameraIO.h"
#include "camera.h"
#include "rtsp.h"
#include "WiFi.h"

void *datalinker = NULL;

CameraIOClass camio(1, 1);
CameraClass cam;
RTSPClass rtsp;

char ssid[] = "yourNetwork";     // your network SSID (name)
char pass[] = "Password";        // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status


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
    
    mm_context_t *p1=(mm_context_t *)cam.init();
    cam.open(p1);
    mm_context_t *p2=(mm_context_t *)rtsp.init();
    rtsp.open(p2);
    datalinker = camio.create();

    // add input
    camio.registerInput(datalinker, (uint32_t)p1, 0);
    // add output
    camio.registerOutput(datalinker, (uint32_t)p2, 0);
    
    if(camio.start(datalinker) != 0) {
        Serial.println("camera io link start failed");
    }    
    cam.start();
}


void loop() {
// do nothing
}

