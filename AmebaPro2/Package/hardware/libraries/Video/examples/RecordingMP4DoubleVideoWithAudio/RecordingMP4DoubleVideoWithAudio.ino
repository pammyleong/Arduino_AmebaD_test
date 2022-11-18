#include "StreamIO.h"
#include "audio.h"
#include "camera.h"
#include "mp4.h"

// Default preset configurations for each video channel:
// Channel 0 : 1920 x 1080 30FPS H264
// Channel 1 : 1280 x 720  30FPS H264
// Channel 2 : 1920 x 1080 30FPS MJPEG

VideoSetting config1(0);
VideoSetting config2(1);
Audio audio;
AAC aac;
MP4 mp4_1;
MP4 mp4_2;
StreamIO audioStreamer(1, 1);  // 1 Input Audio -> 1 Output AAC
StreamIO avMixStreamer(3, 2); // 3 Input Video1 + Video2 + Audio -> 2 Output MP4_1 + MP4_2

void setup() {
    Serial.begin(115200);

    // Configure both camera video channels with corresponding video format information
    Camera.channelConfig(0, config1);
    Camera.channelConfig(1, config2);
    Camera.videoInit();

    // Configure audio peripheral for audio data output
    audio.init();
    audio.open();
    // Configure AAC audio encoder
    aac.init();

    // Configure MP4 with corresponding video format information
    // Configure MP4 recording settings
    mp4_1.init(config1);
    mp4_1.setRecordingDuration(15);
    mp4_1.setRecordingFileCount(1);
    mp4_1.setRecordingFileName("TestRecordingAudioVideo1");

    mp4_2.init(config2);
    mp4_2.setRecordingDuration(30);
    mp4_2.setRecordingFileCount(1);
    mp4_2.setRecordingFileName("TestRecordingAudioVideo2");

    // Configure StreamIO object to stream data from audio channel to AAC encoder
    audioStreamer.registerInput(audio);
    audioStreamer.registerOutput(aac);
    if (audioStreamer.start() != 0) {
        Serial.println("StreamIO link start failed");
    }

    // Configure StreamIO object to stream data from video channels and AAC encoder to MP4 outputs
    avMixStreamer.registerInput1(Camera.getStream(0));
    avMixStreamer.registerInput2(Camera.getStream(1));
    avMixStreamer.registerInput3(aac);
    avMixStreamer.registerOutput1(mp4_1);
    avMixStreamer.registerOutput2(mp4_2);
    if (avMixStreamer.start() != 0) {
        Serial.println("StreamIO link start failed");
    }

    // Start data stream from video channels
    Camera.channelStart(0);
    Camera.channelStart(1);
    // Start recording MP4 data to SD card
    mp4_1.startRecording();
    mp4_2.startRecording();
}

void loop() {
    // do nothing
}
