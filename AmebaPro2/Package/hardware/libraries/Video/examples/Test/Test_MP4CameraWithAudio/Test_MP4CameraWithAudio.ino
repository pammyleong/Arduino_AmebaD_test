#include "StreamIO.h"
#include "camera.h"
#include "audio.h"
#include "mp4.h"

CameraClass cam;
CameraSetting camset(1);
// CameraSetting camset;
// CameraSetting camset(VIDEO_FHD, CAM_FPS, VIDEO_H264, 0);
Audio audio;
AAC aac;
MP4 mp4;
StreamIO streamIO_SISO(1, 1);   // Single Input Single Output
StreamIO streamIO_MISO(2, 1);  // Multi Input Single Output

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
    streamIO_SISO.create();
    streamIO_SISO.registerInput(audio.getIO());
    streamIO_SISO.registerOutput(aac.getIO());
    if (streamIO_SISO.start() != 0) {
        Serial.println("camera io link 1 start failed");
    }

    // MISO [Video + AAC -> MP4]
    streamIO_MISO.create();
    streamIO_MISO.registerInput1(cam.getIO());
    streamIO_MISO.registerInput2(aac.getIO());
    streamIO_MISO.registerOutput(mp4.getIO());

    if (streamIO_MISO.start() != 0) {
        Serial.println("camera io link 2 start failed");
    }

    cam.start(camset);
    mp4.startRecording();
}

void loop() {
    // do nothing
}
