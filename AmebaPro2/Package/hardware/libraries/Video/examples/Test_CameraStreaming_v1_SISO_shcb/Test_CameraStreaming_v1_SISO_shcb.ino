#include "WiFi.h"
#include "StreamIO.h"
#include "Video.h"
#include "RTSP.h"

#define CHANNEL0 0
#define CHANNEL1 1
#define CHANNEL2 2


// Default preset configurations for each video channel:
// Channel 0 : 1920 x 1080 30FPS H264
// Channel 1 : 1280 x 720  30FPS H264
// Channel 2 : 1920 x 1080 30FPS MJPEG

VideoSetting config1(VIDEO_FHD, CAM_FPS, VIDEO_H264, 1);
//VideoSetting config0(CHANNEL0);
//VideoSetting config1(CHANNEL2);

//RTSP rtsp0;
RTSP rtsp1;

StreamIO videoStreamer0(1, 1);  // 1 Input Video -> 1 Output RTSP
//StreamIO videoStreamer1(1, 1);  // 1 Input Video -> 1 Output RTSP

char ssid[] = "Aurical_5G";     //  your network SSID (name)
char pass[] = "wyy170592";  	// your network password
int status = WL_IDLE_STATUS;    // the Wifi radio's status

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
//    Camera.configVideoChannel(CHANNEL0, config0);
    Camera.configVideoChannel(CHANNEL2, config1);
    Camera.videoInit();

//    // Configure RTSP with identical video format information
//    rtsp0.configVideo(config0);
//    rtsp0.begin();

    rtsp1.configVideo(config1);
    rtsp1.begin();

    // Configure StreamIO object to stream data from video channel to RTSP
    videoStreamer0.registerInput(Camera.getStream(CHANNEL2));
    videoStreamer0.registerOutput(rtsp1);
    if (videoStreamer0.begin() != 0) {
        Serial.println("StreamIO0 link start failed");
    }

//    videoStreamer1.registerInput(Camera.getStream(CHANNEL1));
//    videoStreamer1.registerOutput(rtsp1);
//    if (videoStreamer1.begin() != 0) {
//        Serial.println("StreamIO1 link start failed");
//    }

    // Start data stream from video channel
    Camera.channelBegin(CHANNEL2);
//    Camera.channelBegin(CHANNEL1);

//    // Take a snapshot
//    delay(3000);
////    Camera.getImage(CHANNEL0);
//    delay(1000);
//    printInfo();
//
//    delay(10000);
////    Camera.getImage(CHANNEL1);
//    delay(1000);
//    printInfo();
//
//    delay(10000);
////    Camera.getImage(CHANNEL2);
//    delay(1000);
//    printInfo();
}

void loop() {
    // Do nothing
}

void printInfo(void) {
    Serial.println("------------------------------");
    Serial.println("- Summary of Streaming -");
    Serial.println("------------------------------");
    Camera.printInfo();

    IPAddress ip = WiFi.localIP();

//    Serial.println("- RTSP -");
//    Serial.print("rtsp://");
//    Serial.print(ip);
//    Serial.print(":");
//    rtsp0.printInfo();

    Serial.print("rtsp://");
    Serial.print(ip);
    Serial.print(":");
    rtsp1.printInfo();
}
