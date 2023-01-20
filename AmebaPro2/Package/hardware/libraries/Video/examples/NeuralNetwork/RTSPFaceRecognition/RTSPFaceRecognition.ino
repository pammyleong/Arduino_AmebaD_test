// Demo for Face Recognition
// Point the camera at the targetted face and use the following commands to register faces,
// Register face: "RE={Name}"
// Reset registered face: "RS"
// Enter Recognition mode: "RC"
// Save registered faces to flash: "SV"
// Load saved faces: "LD"
// Set Threshold: "TH={Threshold}", Threshold value range: 0 -100

#include "WiFi.h"
#include "StreamIO.h"
#include "VideoStream.h"
#include "RTSP.h"
#include "NNFaceDetection.h"
#include "NNFaceRecognition.h"
#include "VideoStreamOverlay.h"

#define CHANNEL   0
#define CHANNELNN 3

// Customised resolution for NN
#define NNWIDTH 576
#define NNHEIGHT 320

// Default preset configurations for each video channel:
// Channel 0 : 1920 x 1080 30FPS H264
// Channel 1 : 1280 x 720  30FPS H264
// Channel 2 : 1920 x 1080 30FPS MJPEG

VideoSetting config(VIDEO_FHD, 30, VIDEO_H264, 0);
VideoSetting configNN(NNWIDTH, NNHEIGHT, 10, VIDEO_RGB, 0);
NNFaceDetection facedet;
NNFaceRecognition facerecog;

RTSP rtsp;
StreamIO videoStreamer(1, 1);  // 1 Input Video -> 1 Output RTSP
StreamIO videoStreamerFDFR(1, 1);  // 1 Input Video -> 1 Output Face Recog
StreamIO videoStreamerRGBFD(1, 1);

char ssid[] = "yourNetwork";     //  your network SSID (name)
char pass[] = "password";  	// your network password
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
    facedet.configVideo(configNN);
    facedet.configFaceRecogCascadedMode(1);
    facedet.begin();

    // Configure Face Recognition model
    facerecog.begin();

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
    videoStreamerFDFR.registerInput(facedet);
    videoStreamerFDFR.registerOutput(facerecog);
    if (videoStreamerFDFR.begin() != 0) {
        Serial.println("StreamIO link start failed");
    }
    // SISO: RGB -> Facedet
    videoStreamerRGBFD.registerInput(Camera.getStream(CHANNELNN));
    videoStreamerRGBFD.setStackSize();
    videoStreamerRGBFD.setTaskPriority();
    videoStreamerRGBFD.registerOutput(facedet);
    if (videoStreamerRGBFD.begin() != 0) {
        Serial.println("StreamIO link start failed");
    }
    
    Camera.channelBegin(CHANNELNN);
    OSD.configVideo(CHANNEL, config);
    OSD.begin();
}

void loop() {
    if (Serial.available() > 0) {
        String input = Serial.readString();
        input.trim();
        int stringLength = input.length();
        char* inputName = new char[input.length() + 1];
        char* inputThreshold = new char[3];

        for (int i = 0; i <= stringLength; i++) {
            if (input[0] == 'R' && input[1] == 'E') {//RE: Register
                for (int j = 3; j <= stringLength; j++) {
                    inputName[j-3] = input[j];
                }
                facerecog.registerFace(inputName);
                break;
            }
            if (input[0] == 'R' && input[1] == 'S') {//RS:Reset
                facerecog.resetRegisteredFace();
                break;
            }
            if (input[0] == 'R' && input[1] == 'C') {//RC:Recognition mode
                facerecog.setRecognitionMode();
                break;
            }
            if (input[0] == 'S') {//SV:Save
                facerecog.saveRegisteredFace();
                break;
            }
            if (input[0] == 'L') {//LD:Load
                facerecog.loadRegisteredFace();
                break;
            }
            if (input[0] == 'T') {//TH:Modify Threshold
                for (int j = 3; j <= 4; j++) {
                    inputThreshold[j-3] = input[j];
                }
                facerecog.setThreshold(inputThreshold);
                break;
            }
        }
    }
}
