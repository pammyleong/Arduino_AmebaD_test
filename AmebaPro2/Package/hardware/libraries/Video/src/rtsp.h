#ifndef __RTSP_H__
#define __RTSP_H__

class RTSP {
    public:
        RTSP(void);
        ~RTSP(void);
        
		void Init(int channel_idx, uint32_t rtsp_fps, uint32_t rtsp_bps, int video_codec);
	   	void RTSP_Open(void);
		void RTSP_Close(void);
		void DeInit(void);
    private:
        
};

#endif



