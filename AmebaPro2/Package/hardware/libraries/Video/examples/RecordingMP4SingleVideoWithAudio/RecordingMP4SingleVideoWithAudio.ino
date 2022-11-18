#include "StreamIO.h"
#include "camera.h"
#include "audio.h"
#include "mp4.h"

#define CHANNEL 0

// Default preset configurations for each video channel:
// Channel 0 : 1920 x 1080 30FPS H264
// Channel 1 : 1280 x 720  30FPS H264
// Channel 2 : 1920 x 1080 30FPS MJPEG

VideoSetting config(CHANNEL);
Audio audio;
AAC aac;
MP4 mp4;
StreamIO audioStreamer(1, 1);  // 1 Input Audio -> 1 Output AAC
StreamIO avMixStreamer(2, 1); // 2 Input Video + Audio -> 1 Output MP4

void setup() {
    Serial.begin(115200);

    // Configure camera video channel with video format information
    Camera.channelConfig(CHANNEL, config);
    Camera.videoInit();

    // Configure audio peripheral for audio data output
    audio.init();
    audio.open();
    // Configure AAC audio encoder
    aac.init();

    // Configure MP4 with identical video format information
    // Configure MP4 recording settings
    mp4.init(config);
    mp4.setRecordingDuration(30);
    mp4.setRecordingFileCount(1);
    mp4.setRecordingFileName("TestRecordingAudioVideo");

    // Configure StreamIO object to stream data from audio channel to AAC encoder
    audioStreamer.registerInput(audio);
    audioStreamer.registerOutput(aac);
    if (audioStreamer.start() != 0) {
        Serial.println("StreamIO link start failed");
    }

    // Configure StreamIO object to stream data from video channel and AAC encoder to MP4 recording
    avMixStreamer.registerInput1(Camera.getStream(CHANNEL));
    avMixStreamer.registerInput2(aac);
    avMixStreamer.registerOutput(mp4);
    if (avMixStreamer.start() != 0) {
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
