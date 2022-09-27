#ifndef __CAMERA_H__
#define __CAMERA_H__

/*****************************************************************************
ISP CHANNEL
    0: HEVC
    1: JPEG
    2: NV12
    4: only RGB
*****************************************************************************/
#define V1_CHANNEL 0


/****************************************************************************
ENCODE TYPE
   0:HEVC 
   1:H264 
   2:JPEG 
   3:NV12 
   4:RGB 
   5:HEVC+JPEG 
   6:H264+JPEG
*****************************************************************************/
enum encode_type {
	VIDEO_HEVC = 0,
	VIDEO_H264,
	VIDEO_JPEG,
	VIDEO_NV12,
	VIDEO_RGB,
	VIDEO_NV16,
	VIDEO_HEVC_JPEG,
	VIDEO_H264_JPEG
};

#define	VIDEO_QCIF  0
#define	VIDEO_CIF   1
#define	VIDEO_WVGA  2
#define	VIDEO_VGA   3
#define	VIDEO_D1    4
#define	VIDEO_HD    5
#define	VIDEO_FHD   6
#define	VIDEO_3M    7
#define	VIDEO_5M    8
#define	VIDEO_2K    9

class Camera {
    public:
        Camera(void);
        ~Camera(void);
        void Init(void);
        void DeInit(void);
        void Open(long long t);
        void Close(int s);


    private:
        
};
#endif
