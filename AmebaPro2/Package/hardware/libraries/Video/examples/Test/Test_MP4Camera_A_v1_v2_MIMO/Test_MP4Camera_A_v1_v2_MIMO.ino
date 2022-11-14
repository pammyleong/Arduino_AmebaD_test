#include "CameraIO.h"
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
CameraIOClass camio1_1In1Out(1, 1);  // Single Input Single Output
CameraIOClass camio2_3In2Out(3, 2);  // Multi Input Multi Output

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
    camio1_1In1Out.create();
    camio1_1In1Out.registerInput(audio.getIO());
    camio1_1In1Out.registerOutput(aac.getIO());
    if (camio1_1In1Out.start() != 0) {
        Serial.println("camera io link 1 start failed");
    }

    // MISO [Video + Video + AAC -> MP4 + MP4]
    camio2_3In2Out.create();
    camio2_3In2Out.registerInput1(cam.getIO());
    camio2_3In2Out.registerInput2(cam2.getIO());
    camio2_3In2Out.registerInput3(aac.getIO());

    camio2_3In2Out.registerOutput1(mp4.getIO());
    camio2_3In2Out.registerOutput2(mp41.getIO());

    if (camio2_3In2Out.start() != 0) {
        Serial.println("camera io link 1 start failed");
    }

    // camio1_2In2Out.create();
    // camio1_2In2Out.registerInput1(cam.getIO());
    // camio1_2In2Out.registerInput2(cam2.getIO());
    // camio1_2In2Out.registerOutput1(rtsp.getIO());
    // camio1_2In2Out.registerOutput2(rtsp1.getIO());
    // if (camio1_2In2Out.start() != 0) {
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
