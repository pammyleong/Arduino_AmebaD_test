#include "StreamIO.h"
#include "camera.h"
#include "mp4.h"

// needs to test all 3 camSettings below to ensure code workable
CameraSetting camset;
// CameraSetting camset(1);
//  CameraSetting camset(VIDEO_FHD, CAM_FPS, VIDEO_H264, 0,
//                        0,0,0,0,
//                        0,0,0,0,
//                        0,0);
CameraClass cam;
MP4 mp4;
StreamIO streamIO_1In1Out(1, 1);  // Single Input Single Output

void setup() {
    Serial.begin(115200);

    // init camera
    cam.init(camset);
    cam.open(camset);

    // init SD card for saving MP4 file
    mp4.init(camset);
    mp4.setRecordingDuration(30);
    mp4.setRecordingFileCount(1);
    mp4.setRecordingFileName("TestRecordingVideoOnly");
    mp4.setRecordingDataType(STORAGE_VIDEO);

    // create camera io linker
    streamIO_1In1Out.create();
    streamIO_1In1Out.registerInput(cam.getIO());
    streamIO_1In1Out.registerOutput(mp4.getIO());
    if (streamIO_1In1Out.start() != 0) {
        Serial.println("camera io link start failed");
    }

    cam.start(camset);
    mp4.startRecording();
}

void loop() {
    // do nothing
}
