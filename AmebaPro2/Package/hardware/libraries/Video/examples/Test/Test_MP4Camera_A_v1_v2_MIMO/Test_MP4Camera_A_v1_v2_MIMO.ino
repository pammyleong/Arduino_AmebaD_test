#include "StreamIO.h"
#include "audio.h"
#include "camera.h"
#include "mp4.h"

CameraSetting camset(VIDEO_FHD, CAM_FPS, VIDEO_H264, 0, 
                     0, 0, 0, 0, 
                     0, 0, 0, 0,
                     0, 0);

CameraSetting camset2(0, 0, 0, 0, 
                      VIDEO_HD, CAM_FPS, VIDEO_H264, 0, 
                      0, 0, 0, 0,
                      0, 0);
CameraClass cam;
CameraClass cam2;
AudioClass audio;
AACClass aac;
MP4Class mp4;
MP4Class mp41;
StreamIOClass streamIO1_1In1Out(1, 1);  // Single Input Single Output
StreamIOClass streamIO2_3In2Out(3, 2);  // Multi Input Multi Output

void setup() {
    Serial.begin(115200);

    // init camera
    cam.init(camset);
    cam.open(camset);

    cam2.init(camset2);
    cam2.open(camset2);

    // init audio & aac
    audio.init();
    audio.open();
    aac.init();

    // init SD card for saving MP4 files
    mp4.init(camset);
    mp4.setRecordingDuration(15);
    mp4.setRecordingFileCount(1);
    mp4.setRecordingFileName("TestRecordingAudioVideo1");

    mp41.init(camset2);
    mp41.setRecordingDuration(30);
    mp41.setRecordingFileCount(1);
    mp41.setRecordingFileName("TestRecordingAudioVideo2");

    // SISO for Audio [AUDIO -> AAC]
    streamIO1_1In1Out.create();
    streamIO1_1In1Out.registerInput(audio.getIO());
    streamIO1_1In1Out.registerOutput(aac.getIO());
    if (streamIO1_1In1Out.start() != 0) {
        Serial.println("camera io link 1 start failed");
    }

    // MISO [Video + Video + AAC -> MP4 + MP4]
    streamIO2_3In2Out.create();
    streamIO2_3In2Out.registerInput1(cam.getIO());
    streamIO2_3In2Out.registerInput2(cam2.getIO());
    streamIO2_3In2Out.registerInput3(aac.getIO());

    streamIO2_3In2Out.registerOutput1(mp4.getIO());
    streamIO2_3In2Out.registerOutput2(mp41.getIO());

    if (streamIO2_3In2Out.start() != 0) {
        Serial.println("camera io link 1 start failed");
    }

    // streamIO1_2In2Out.create();
    // streamIO1_2In2Out.registerInput1(cam.getIO());
    // streamIO1_2In2Out.registerInput2(cam2.getIO());
    // streamIO1_2In2Out.registerOutput1(rtsp.getIO());
    // streamIO1_2In2Out.registerOutput2(rtsp1.getIO());
    // if (streamIO1_2In2Out.start() != 0) {
    //     Serial.println("camera io link 1 start failed");
    // }

    cam.start(camset);
    cam2.start(camset2);
    mp4.startRecording();
    mp41.startRecording();
}

void loop() {
    // do nothing
}
