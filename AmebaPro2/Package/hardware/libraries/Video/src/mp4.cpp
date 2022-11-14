#include <Arduino.h>

#include "mp4.h"
#include "mp4_drv.h"

#define DEBUG 1

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

MP4Class::MP4Class(void) {
    // Video parameters
    mp4Params.width = 1920;
    mp4Params.height = 1080;
    mp4Params.fps = 30;
    mp4Params.gop = 30;

    // Audio parameters
    mp4Params.sample_rate = 8000;
    mp4Params.channel = 1;
    mp4Params.mp4_audio_format = AUDIO_AAC;

    // MP4 recording parameters
    mp4Params.record_length = 60; //seconds
    mp4Params.record_type = STORAGE_ALL;
    mp4Params.record_file_num = 1;
    memset(mp4Params.record_file_name, 0, sizeof(mp4Params.record_file_name));
    strncpy(mp4Params.record_file_name, "AmebaPro_recording", sizeof(mp4Params.record_file_name));
    mp4Params.fatfs_buf_size = 256 * 1024; // 32kb multiple
}

/**
  * @brief  Initialization for MP4 module by setting up MP4 paramters
  * @param  obj  : object pointer to Camera Settings
  * @retval none
  */
void MP4Class::init(CameraSetting& obj) {
    mp4Data = mp4Init();
    if (mp4Data == NULL) {
        CAMDBG("MP4_Init failed\r\n");
        return;
    }
    CAMDBG("MP4_Init done\r\n");

    if(obj._resolution) {
        mp4Params.width = obj._w;
        mp4Params.height = obj._h;
        mp4Params.fps = obj._fps;
        mp4Params.gop = obj._fps;
    }
    if(obj._v2_resolution) {
        mp4Params.width = obj._v2_w;
        mp4Params.height = obj._v2_h;
        mp4Params.fps = obj._v2_fps;
        mp4Params.gop = obj._v2_fps;
    }
    if(obj._v3_resolution) {
        mp4Params.width = obj._v3_w;
        mp4Params.height = obj._v3_h;
        mp4Params.fps = obj._v3_fps;
        mp4Params.gop = obj._v3_fps;
    }
}

/**
  * @brief  Deinit and release all the resources set for MP4
  * @param  none
  * @retval none
  */
void MP4Class::deInit(void) {
    if (mp4Data == NULL) {
        return;
    }
    if (mp4DeInit(mp4Data) == NULL) {
        mp4Data = NULL;
        CAMDBG("MP4 DeInit\r\n");
    } else {
        CAMDBG("MP4 DeInit failed\r\n");
    }
}

/**
  * @brief  Start MP4 module recording data to SD card
  * @param  none
  * @retval none
  */
void MP4Class::startRecording(void) {
    if (mp4Data == NULL) {
        CAMDBG("Need MP4 init first\r\n");
        return;
    }
    mp4SetParams(mp4Data->priv, &mp4Params);
    mp4SetLoopMode(mp4Data->priv, loopEnable);
    mp4RecordingStart(mp4Data->priv, &mp4Params);
}

/**
  * @brief  Stop MP4 module recording data to SD card
  * @param  none
  * @retval none
  */
void MP4Class::stopRecording(void) {
    if (mp4Data == NULL) {
        CAMDBG("Need MP4 init first\r\n");
        return;
    }
    mp4RecordingStop(mp4Data->priv);
}

/**
  * @brief  Set filename of recordings saved to SD card
  * @param  filename : pointer to character array containing filename
  * @retval none
  */
void MP4Class::setRecordingFileName(const char* filename) {
    memset(mp4Params.record_file_name, 0, sizeof(mp4Params.record_file_name));
    strncpy(mp4Params.record_file_name, filename, sizeof(mp4Params.record_file_name));
}

/**
  * @brief  Set filename of recordings saved to SD card
  * @param  filename : String class object containing filename
  * @retval none
  */
void MP4Class::setRecordingFileName(String filename) {
    setRecordingFileName(filename.c_str());
}

/**
  * @brief  Set maximum recording duration of each file saved to SD card
  * @param  secs : maximum recording duration expressed in seconds
  * @retval none
  */
void MP4Class::setRecordingDuration(uint32_t secs) {
    mp4Params.record_length = secs;
}

/**
  * @brief  Set total number of recordings saved to SD card, filenames will have a number appended
  * @param  count : total number of recording files
  * @retval none
  */
void MP4Class::setRecordingFileCount(uint32_t count) {
    mp4Params.record_file_num = count;
}

/**
  * @brief  Enable loop recording, oldest file will be overwritten once total file count is reached
  * @param  enable : integer, 1 to enable, 0 to disable
  * @retval none
  */
void MP4Class::setLoopRecording(int enable) {
    loopEnable = enable;
}

/**
  * @brief  Select data streams to record, 0 for video and audio, 1 for video only, 2 for audio only
  * @param  type : integer from 0 to 2 inclusive
  * @retval none
  */
void MP4Class::setRecordingDataType(uint8_t type) {
    if (type <= STORAGE_AUDIO) {
        mp4Params.record_type = type;
    }
}

/**
  * @brief  Get filename of recordings
  * @param  none
  * @retval String class object containing filename
  */
String MP4Class::getRecordingFileName() {
    return String(mp4Params.record_file_name);
}

/**
  * @brief  Get maximum recording duration of each file saved to SD card
  * @param  none
  * @retval maximum recording duration expressed in seconds
  */
uint32_t MP4Class::getRecordingDuration() {
    return (mp4Params.record_length);
}

/**
  * @brief  Set total number of recordings saved to SD card, filenames will have a number appended
  * @param  count : total number of recording files
  * @retval none
  */
uint32_t MP4Class::getRecordingFileCount() {
    return (mp4Params.record_file_num);
}

/**
  * @brief  Select data streams to record, 0 for video and audio, 1 for video only, 2 for audio only
  * @param  type : integer from 0 to 2 inclusive
  * @retval none
  */
uint8_t MP4Class::getRecordingState(void) {
    if (mp4Data == NULL) {
        CAMDBG("Need MP4 init first\r\n");
        return 0;
    }
    return mp4RecordingState(mp4Data->priv);
}

/**
  * @brief  Get MP4 module mm_context_t pointer
  * @param  none
  * @retval mm_context_t pointer
  */
mm_context_t *MP4Class::getIO(void) {
    return mp4Data;
}

