#include "WiFi.h"
#include "StreamIO.h"
#include "camera.h"
#include "rtsp.h"

#define CHANNEL 0

// Default preset configurations for each video channel:
// Channel 0 : 1920 x 1080 30FPS H264
// Channel 1 : 1280 x 720  30FPS H264
// Channel 2 : 1920 x 1080 30FPS MJPEG

VideoSetting config(CHANNEL);
RTSP rtsp;
StreamIO videoStreamer(1, 1);  // 1 Input Video -> 1 Output RTSP

char ssid[] = "Aurical_5G";  // your network SSID (name)
char pass[] = "wyy170592";     // your network password
int status = WL_IDLE_STATUS;  // the Wifi radio's status

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

    // Configure camera video channel with video format information
    Camera.channelConfig(CHANNEL, config);
    Camera.videoInit();

    // Configure RTSP with identical video format information
    rtsp.init(config);
    rtsp.open();

    // Configure StreamIO object to stream data from video channel to RTSP
    videoStreamer.registerInput(Camera.getStream(CHANNEL));
    videoStreamer.registerOutput(rtsp);
    if (videoStreamer.start() != 0) {
        Serial.println("StreamIO link start failed");
    }

    // Start data stream from video channel
    Camera.channelStart(CHANNEL);
}

void loop() {
    // Do nothing
}
