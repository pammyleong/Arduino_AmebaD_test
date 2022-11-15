#include "StreamIO.h"
#include "WiFi.h"
#include "audio.h"
#include "camera.h"
#include "rtsp.h"

CameraSetting camset;
CameraClass cam;
AudioClass audio;
AACClass aac;
RTSPClass rtsp;
StreamIOClass streamIO1_1In1Out(1, 1);  // Single Input Single Output
StreamIOClass streamIO2_2In1Out(2, 1);  // Multi Input Single Output

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
    cam.init(camset);
    cam.open(camset);

    // init audio & aac
    audio.init();
    audio.open();
    aac.init();

    // init rtsp
    rtsp.enableAudio();
    rtsp.init(camset);
    rtsp.open();

    // SISO for Audio [AUDIO-AAC]
    streamIO1_1In1Out.create();
    streamIO1_1In1Out.registerInput(audio.getIO());
    streamIO1_1In1Out.registerOutput(aac.getIO());
    if (streamIO1_1In1Out.start() != 0) {
        Serial.println("camera io link 1 start failed");
    }

    // MISO [V-A-RTSP]
    streamIO2_2In1Out.create();
    streamIO2_2In1Out.registerInput1(cam.getIO());
    streamIO2_2In1Out.registerInput2(aac.getIO());
    streamIO2_2In1Out.registerOutput(rtsp.getIO());
    if (streamIO2_2In1Out.start() != 0) {
        Serial.println("camera io link 2 start failed");
    }

    cam.start(camset);
}

void loop() {
    // do nothing
}
