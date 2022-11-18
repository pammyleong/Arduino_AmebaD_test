#include "StreamIO.h"
#include "camera.h"
#include "mp4.h"

#define CHANNEL 0

// Default preset configurations for each video channel:
// Channel 0 : 1920 x 1080 30FPS H264
// Channel 1 : 1280 x 720  30FPS H264
// Channel 2 : 1920 x 1080 30FPS MJPEG

VideoSetting config(CHANNEL);
MP4 mp4;
StreamIO videoStreamer(1, 1);  // 1 Input Video -> 1 Output RTSP

void setup() {
    Serial.begin(115200);

    // Configure camera video channel with video format information
    Camera.channelConfig(CHANNEL, config);
    Camera.videoInit();

    // Configure MP4 with identical video format information
    // Configure MP4 recording settings
    mp4.init(config);
    mp4.setRecordingDuration(30);
    mp4.setRecordingFileCount(1);
    mp4.setRecordingFileName("TestRecordingVideoOnly");
    mp4.setRecordingDataType(STORAGE_VIDEO);    // Set MP4 to record video only

    // Configure StreamIO object to stream data from video channel to MP4 recording
    videoStreamer.registerInput(Camera.getStream(CHANNEL));
    videoStreamer.registerOutput(mp4);
    if (videoStreamer.start() != 0) {
        Serial.println("StreamIO link start failed");
    }

    // Start data stream from video channel
    Camera.channelStart(CHANNEL);
    // Start recording MP4 data to SD card
    mp4.startRecording();
}

void loop() {
    // do nothing
}
