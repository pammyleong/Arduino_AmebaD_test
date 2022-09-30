#include "CameraIO.h"
#include "camera.h"
#include "rtsp.h"
//#include "WiFi.h"

void *datalinker = NULL;

CameraIOClass CAMIO(1, 1);
Camera cam;
RTSP rtsp;

//char ssid[] = "yourNetwork";     //  your network SSID (name)
//char pass[] = "yourPassword";  // your network password
//int status = WL_IDLE_STATUS;     // the Wifi radio's status


void setup() {

    Serial.begin(115200);
    
//    if (WiFi.status() == WL_NO_SHIELD) {
//        Serial.println("WiFi shield not present");
//        // don't continue:
//        while (true);
//    }
//
//    // attempt to connect to Wifi network:
//    while (status != WL_CONNECTED) {
//        Serial.print("Attempting to connect to WPA SSID: ");
//        Serial.println(ssid);
//        // Connect to WPA/WPA2 network:
//        status = WiFi.begin(ssid, pass);
//
//        // wait 10 seconds for connection:
//        delay(10000);
//    }

    datalinker = CAMIO.create();

    // add input
    CAMIO.registerInput(datalinker, (uint32_t)cam.Init(), 0);

    // add output
    CAMIO.registerOutput(datalinker, (uint32_t)rtsp.Init(), 0);

    if(CAMIO.start(datalinker) != 0) {
        Serial.println("camera io link start failed");
    }
}


void loop() {
// do nothing

}


