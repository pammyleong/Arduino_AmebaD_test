// Demo for face recog

#include "WiFi.h"
#include "StreamIO.h"
#include "VideoStream.h"
#include "RTSP.h"
#include "NN.h"
#include "VideoStreamOverlay.h"

#define CHANNEL   0
#define CHANNELNN 3

// Customised resolution for NN
#define NNWIDTH 576
#define NNHEIGHT 320

#define OSDTEXTWIDTH 16
#define OSDTEXTHEIGHT 32

// Default preset configurations for each video channel:
// Channel 0 : 1920 x 1080 30FPS H264
// Channel 1 : 1280 x 720  30FPS H264
// Channel 2 : 1920 x 1080 30FPS MJPEG

VideoSetting config(VIDEO_FHD, 30, VIDEO_H264, 0);
VideoSetting configNN(NNWIDTH, NNHEIGHT, 10, VIDEO_RGB, 0);
NNFaceDetection FaceDet;
NNFaceDetection FaceNet;
NNFaceRecognition FaceRecog;

RTSP rtsp;
StreamIO videoStreamer(1, 1);  // 1 Input Video -> 1 Output RTSP
StreamIO videoStreamerFNFR(1, 1);
StreamIO videoStreamerFDFN(1, 1);  // 1 Input Video -> 1 Output Face Recog
StreamIO videoStreamerRGBFD(1, 1);

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

    FaceDet.configModel(configNN);
    
    // Congifure Model 1: Face Detection model
    FaceDet.configVideo(configNN, 1);

    // Configure Model 2: FaceNet model
    FaceNet.configVideo(configNN, 2);

    // Configure Face Recognition model
    FaceRecog.configVideo();

    // ------------- linker --------------
    // Configure StreamIO object to stream data from video channel to RTSP
    videoStreamer.registerInput(Camera.getStream(CHANNEL));
    videoStreamer.registerOutput(rtsp);
    if (videoStreamer.begin() != 0) {
        Serial.println("StreamIO link start failed");
    }
    // Start data stream from video channel
    Camera.channelBegin(CHANNEL);

    // NN
    // SISO: Facenet -> FaceRecog
    videoStreamerFNFR.registerInput(FaceNet);
    videoStreamerFNFR.registerOutput(FaceRecog);
    if (videoStreamerFNFR.begin() != 0) {
        Serial.println("StreamIO link start failed");
    }
    // SISO: Facedet -> Facenet
    videoStreamerFDFN.registerInput(FaceDet);
    videoStreamerFDFN.registerOutput(FaceNet);
    if (videoStreamerFDFN.begin() != 0) {
        Serial.println("StreamIO link start failed");
    }
    // SISO: RGB -> Facedet
    videoStreamerRGBFD.registerInput(Camera.getStream(CHANNELNN));
    videoStreamerRGBFD.setStackSize();
    videoStreamerRGBFD.setTaskPriority();
    videoStreamerRGBFD.registerOutput(FaceDet);
    if (videoStreamerRGBFD.begin() != 0) {
        Serial.println("StreamIO link start failed");
    }
    
    Camera.channelBegin(CHANNELNN);

    // called temporary to pass RTSP ch, w and h to CB fn in .c before CB fn is move to .cpp  
    FaceRecog.configOSD(CHANNEL, config);
    OSD.config(CHANNEL, config, OSDTEXTWIDTH, OSDTEXTHEIGHT);
    OSD.begin();
    
    // Using UART to reg faces
    // To be done

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