#include "WiFi.h"
#include "StreamIO.h"
#include "camera.h"
#include "audio.h"
#include "rtsp.h"

// Default preset configurations for each video channel:
// Channel 0 : 1920 x 1080 30FPS H264
// Channel 1 : 1280 x 720  30FPS H264
// Channel 2 : 1920 x 1080 30FPS MJPEG

VideoSetting config1(VIDEO_FHD, CAM_FPS, VIDEO_H264, 0);
VideoSetting config2(VIDEO_HD, CAM_FPS, VIDEO_H264, 0);
Audio audio;
AAC aac;
RTSP rtsp1;
RTSP rtsp2;
StreamIO audioStreamer(1, 1);  // 1 Input Audio -> 1 Output AAC
StreamIO avMixStreamer(3, 2); // 3 Input Video1 + Video2 + Audio -> 2 Output RTSP1 + RTSP2

char ssid[] = "Aurical_5G";  //  your network SSID (name)
char pass[] = "wyy170592";     // your network password
int status = WL_IDLE_STATUS;   // the Wifi radio's status

void setup() {
    Serial.begin(115200);

    // attempt to connect to Wifi network:
    while (status != WL_CONNECTED) {
        Serial.print("Attempting to connect to WPA SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network:
        status = WiFi.begin(ssid, pass);

        // wait 2 seconds for connection:
        delay(2000);
    }

    // Configure both camera video channels with corresponding video format information
    Camera.channelConfig(0, config1);
    Camera.channelConfig(1, config2);
    Camera.videoInit();

    // Configure audio peripheral for audio data output
    audio.init();
    audio.open();
    // Configure AAC audio encoder
    aac.init();

    // Configure both RTSP with corresponding video format information
    rtsp1.enableAudio();
    rtsp1.init(config1);
    rtsp1.open();

    rtsp2.enableAudio();
    rtsp2.init(config2);
    rtsp2.open();

    // Configure StreamIO object to stream data from audio channel to AAC encoder
    audioStreamer.registerInput(audio);
    audioStreamer.registerOutput(aac);
    if (audioStreamer.start() != 0) {
        Serial.println("StreamIO link start failed");
    }

    // Configure StreamIO object to stream data from video channels and AAC encoder to rtsp outputs
    avMixStreamer.registerInput1(Camera.getStream(0));
    avMixStreamer.registerInput2(Camera.getStream(1));
    avMixStreamer.registerInput3(aac);
    avMixStreamer.registerOutput1(rtsp1);
    avMixStreamer.registerOutput2(rtsp2);
    if (avMixStreamer.start() != 0) {
        Serial.println("StreamIO link start failed");
    }

    // Start data stream from video channels
    Camera.channelStart(0);
    Camera.channelStart(1);
}

void loop() {
    // do nothing
}
