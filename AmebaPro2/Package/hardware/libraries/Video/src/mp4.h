#ifndef __MP4_H__
#define __MP4_H__

#include "mmf2_module.h"
#include "mp4_muxer.h"

#include "camera.h"

class MP4:public MMFModule {
    public:
        MP4(void);

        void init();
        void init(VideoSetting& obj);
        void deinit(void);

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

    private:
        int loopEnable = 0;
        mp4_params_t mp4Params;
};

#endif
