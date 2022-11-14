#ifndef __MP4_H__
#define __MP4_H__

#include "mmf2_module.h"
#include "mp4_muxer.h"

#include "camera.h"

class MP4Class {
    public:
        MP4Class(void);

        void init(CameraSetting& obj);
        void deInit(void);

        void startRecording(void);
        void stopRecording(void);

        void setRecordingFileName(const char* filename);
        void setRecordingFileName(String filename);
        void setRecordingDuration(uint32_t secs);
        void setRecordingFileCount(uint32_t count);
        void setLoopRecording(int enable);
        void setRecordingDataType(uint8_t type);

        String getRecordingFileName();
        uint32_t getRecordingDuration();
        uint32_t getRecordingFileCount();
        uint8_t getRecordingState(void);

        mm_context_t *getIO(void);

    private:
        int loopEnable = 0;
        mm_context_t *mp4Data = NULL;
        mp4_params_t mp4Params;
};

#endif
