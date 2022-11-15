#include "StreamIO.h"
#include "WiFi.h"
#include "audio.h"
#include "camera.h"
#include "rtsp.h"

CameraSetting camset1(VIDEO_FHD, CAM_FPS, VIDEO_H264, 0, 
                     0, 0, 0, 0, 
                     0, 0, 0, 0,
                     0, 0);

CameraSetting camset2(0, 0, 0, 0, 
                      VIDEO_HD, CAM_FPS, VIDEO_H264, 0, 
                      0, 0, 0, 0,
                      0, 0);
CameraClass cam1;
CameraClass cam2;
Audio audio;
AAC aac;
RTSP rtsp1;
RTSP rtsp2;
StreamIO streamIO1_1In1Out(1, 1);  // SISO for Audio -> AAC
StreamIO streamIO2_3In2Out(3, 2);  // MIMO for Video1 (FHD), Video2 (HD) and Audio -> RTSP1 and RTSP2

char ssid[] = "yourNetwork";   //  your network SSID (name)
char pass[] = "password";    // your network password
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
    cam1.init(camset1);
    cam1.open(camset1);

    cam2.init(camset2);
    cam2.open(camset2);

    // init audio & aac
    audio.init();
    audio.open();
    aac.init();

    // init rtsp
    rtsp1.enableAudio();
    rtsp1.init(camset1);
    rtsp1.open();

    rtsp2.enableAudio();
    rtsp2.init(camset2);
    rtsp2.open();

    // SISO for Audio [AAC-AUDIO]
    streamIO1_1In1Out.create();
    streamIO1_1In1Out.registerInput(audio.getIO());
    streamIO1_1In1Out.registerOutput(aac.getIO());
    if (streamIO1_1In1Out.start() != 0) {
        Serial.println("camera io link 1 start failed");
    }

    streamIO2_3In2Out.create();
    streamIO2_3In2Out.registerInput1(cam1.getIO());
    streamIO2_3In2Out.registerInput2(cam2.getIO());
    streamIO2_3In2Out.registerInput3(aac.getIO());

    streamIO2_3In2Out.registerOutput1(rtsp1.getIO());
    streamIO2_3In2Out.registerOutput2(rtsp2.getIO());

    if (streamIO2_3In2Out.start() != 0) {
        Serial.println("camera io link 1 start failed");
    }
    
    cam1.start(camset1);
    cam2.start(camset2);
}

void loop() {
    // do nothing
}
