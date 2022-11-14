#include "CameraIO.h"
#include "camera.h"
#include "audio.h"
#include "mp4.h"

CameraClass cam;
CameraSetting camset(1);
// CameraSetting camset;
// CameraSetting camset(VIDEO_FHD, CAM_FPS, VIDEO_H264, 0);
AudioClass audio;
AACClass aac;
MP4Class mp4;
CameraIOClass camioSISO(1, 1);   // Single Input Single Output
CameraIOClass camioMISO(2, 1);  // Multi Input Single Output

void setup() {
    Serial.begin(115200);

    // init camera
    cam.init(camset);
    cam.open(camset);

    // init audio & aac
    audio.init();
    audio.open();
    aac.init();

    // init SD card for saving MP4 file
    mp4.init(camset);
    mp4.setRecordingDuration(30);
    mp4.setRecordingFileCount(1);
    mp4.setRecordingFileName("TestRecordingAudioVideo");

    // SISO for Audio [AUDIO -> AAC]
    camioSISO.create();
    camioSISO.registerInput(audio.getIO());
    camioSISO.registerOutput(aac.getIO());
    if (camioSISO.start() != 0) {
        Serial.println("camera io link 1 start failed");
    }

    // MISO [Video + AAC -> MP4]
    camioMISO.create();
    camioMISO.registerInput1(cam.getIO());
    camioMISO.registerInput2(aac.getIO());
    camioMISO.registerOutput(mp4.getIO());

    if (camioMISO.start() != 0) {
        Serial.println("camera io link 2 start failed");
    }

    cam.start(camset);
    mp4.startRecording();
}

void loop() {
    // do nothing
}
