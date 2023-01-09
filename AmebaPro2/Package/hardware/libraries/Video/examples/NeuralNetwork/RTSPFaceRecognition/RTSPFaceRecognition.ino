// Demo for face detection

#include "WiFi.h"
#include "StreamIO.h"
#include "VideoStream.h"
#include "RTSP.h"
#include "NNFaceDetection.h"
#include "NNFaceRecognition.h"

#define CHANNEL   0
#define CHANNELNN 3

// Default preset configurations for each video channel:
// Channel 0 : 1920 x 1080 30FPS H264
// Channel 1 : 1280 x 720  30FPS H264
// Channel 2 : 1920 x 1080 30FPS MJPEG

VideoSetting config(VIDEO_FHD, 30, VIDEO_H264, 0);
VideoSetting configNN(VIDEO_VGA, 10, VIDEO_RGB, 0);
NNFaceDetection FaceDetec;
NNFaceDetection FaceNet;
NNFaceRecognition FaceRecog;

RTSP rtsp;
StreamIO videoStreamer(1, 1);  // 1 Input Video -> 1 Output RTSP
StreamIO videoStreamerNN(1, 1);  // SISO

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
    Camera.configVideoChannel(CHANNEL, config);
    Camera.configVideoChannel(CHANNELNN, configNN);
    Camera.videoInit();

    // Configure RTSP with identical video format information
    rtsp.configVideo(config);
    rtsp.begin();

    // Congifure Model 1: Face Detection model
    FaceDetec.getRTSPParams(CHANNEL, config);
    FaceDetec.configVideo(CHANNELNN, configNN, 1);

    // Configure Model 2: Face Net model
    // FaceNet.getRTSPParams(CHANNEL, config);
    FaceNet.configVideo(CHANNELNN, configNN, 2);

    // Configure Face Recognition model
    // FaceRecog.getRTSPParams(CHANNEL, config);
    FaceRecog.configVideo(CHANNELNN, configNN);
    
    // ------------- linker --------------
    // Configure StreamIO object to stream data from video channel to RTSP
    videoStreamer.registerInput(Camera.getStream(CHANNEL));
    videoStreamer.registerOutput(rtsp);
    if (videoStreamer.begin() != 0) {
        Serial.println("StreamIO link start failed");
    }
    // Start data stream from video channel
    Camera.channelBegin(CHANNEL);

    // nn
    // SISO: Facedet -> Facenet
    videoStreamerNN.registerInput(FaceDetec);
    videoStreamerNN.registerOutput(FaceNet);
    // SISO: Facenet -> Facerecog
    videoStreamerNN.registerInput(FaceNet);
    videoStreamerNN.registerOutput(FaceRecog);
    // SISO: video RGB -> Face Detect
    videoStreamerNN.registerInput(Camera.getStream(CHANNELNN));
    videoStreamerNN.setStackSize();
    videoStreamerNN.setTaskPriority();
    videoStreamerNN.registerOutput(FaceDetec);
    if (videoStreamerNN.begin() != 0) {
        Serial.println("StreamIO link start failed");
    }

    FaceDetec.begin();
    FaceDetec.YUV();

    FaceDetec.OSDDisplay();

    delay(1000);
    printInfo();
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

    Serial.println("- RTSP -");
    Serial.print("rtsp://");
    Serial.print(ip);
    Serial.print(":");
    rtsp.printInfo();
}