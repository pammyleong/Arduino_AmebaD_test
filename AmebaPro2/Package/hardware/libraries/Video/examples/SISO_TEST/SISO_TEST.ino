#include "CameraIO.h"
#include "camera.h"
#include "rtsp.h"
#include "WiFi.h"

void *datalinker = NULL;

CameraIOClass CAMIO(1, 1);
Camera cam;
RTSP rtsp;

char ssid[] = "Aurical_5G";     //  your network SSID (name)
char pass[] = "wyy170592";  // your network password
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
    
    mm_context_t *p1=(mm_context_t *)cam.Init();
    cam.Open(p1);
    Serial.println("cam.Open() done");
    
    mm_context_t *p2=(mm_context_t *)rtsp.Init();
    rtsp.Open(p2);
    Serial.println("rtsp.Open() done");

    datalinker = CAMIO.create();
    Serial.println("CAMIO.create() done");


    // add input
    CAMIO.registerInput(datalinker, (uint32_t)p1, 0);
    Serial.println("CAMIO.registerInput done");
    
    // add output
    CAMIO.registerOutput(datalinker, (uint32_t)p2, 0);
    Serial.println("CAMIO.registerOutput done");
    
    if(CAMIO.start(datalinker) != 0) {
        Serial.println("camera io link start failed");
    }
    Serial.println("camera io link start done");
    
    cam.Start();
}


void loop() {
// do nothing

}

