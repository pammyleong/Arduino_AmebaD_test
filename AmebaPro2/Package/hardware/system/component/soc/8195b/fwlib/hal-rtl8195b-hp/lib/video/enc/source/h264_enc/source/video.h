#ifndef _VIDEO_H_
#define _VIDEO_H_

#include "hal_isp.h"
#include "hal_encorder.h"
#include "hal_video.h"

#define DEFAULT -255
#define MAX_BPS_ADJUST 20

/* Structure for command line options */
typedef struct {
//	char *input;
//	char *inputMvc;
//	char *output;
	char *userData;
	i32 firstPic;
	i32 lastPic;
	i32 width;
	i32 height;
	i32 lumWidthSrc;
	i32 lumHeightSrc;
	i32 horOffsetSrc;
	i32 verOffsetSrc;
	i32 outputRateNumer;
	i32 outputRateDenom;
	i32 inputRateNumer;
	i32 inputRateDenom;
	i32 refFrameAmount;
	i32 level;
	i32 hrdConformance;
	i32 cpbSize;
	i32 intraPicRate;
	i32 longTermPicRate;
	i32 constIntraPred;
	i32 disableDeblocking;
	i32 mbRowPerSlice;
	i32 qpHdr;
	i32 qpMin;
	i32 qpMax;
	i32 bitPerSecond;
	i32 picRc;
	i32 mbRc;
	i32 picSkip;
	i32 rotation;
	i32 inputFormat;
	i32 colorConversion;
	i32 videoBufferSize;
	i32 videoRange;
	i32 chromaQpOffset;
	i32 filterOffsetA;
	i32 filterOffsetB;
	i32 trans8x8;
	i32 enableCabac;
	i32 cabacInitIdc;
	i32 testId;
	i32 burst;
	i32 bursttype;
	i32 quarterPixelMv;
	i32 sei;
	i32 idrHdr;
	i32 byteStream;
	i32 videoStab;
	i32 gopLength;
	i32 intraQpDelta;
	i32 fixedIntraQp;
	i32 mbQpAdjustment;
	i32 mbQpAutoBoost;
	i32 testParam;
	i32 mvOutput;
	i32 mvPredictor;
	i32 cirStart;
	i32 cirInterval;
	i32 intraSliceMap1;
	i32 intraSliceMap2;
	i32 intraSliceMap3;
	i32 intraAreaEnable;
	i32 intraAreaTop;
	i32 intraAreaLeft;
	i32 intraAreaBottom;
	i32 intraAreaRight;
	i32 roi1AreaEnable;
	i32 roi2AreaEnable;
	i32 roi1AreaTop;
	i32 roi1AreaLeft;
	i32 roi1AreaBottom;
	i32 roi1AreaRight;
	i32 roi2AreaTop;
	i32 roi2AreaLeft;
	i32 roi2AreaBottom;
	i32 roi2AreaRight;
	i32 roi1DeltaQp;
	i32 roi2DeltaQp;
	i32 adaptiveRoiMotion;
	i32 adaptiveRoiColor;
	i32 adaptiveRoi;
	i32 viewMode;
	i32 psnr;
	i32 traceRecon;
	i32 scaledWidth;
	i32 scaledHeight;
	i32 interlacedFrame;
	i32 fieldOrder;
	i32 enableRfc;
	i32 rfcLumBufLimit;
	i32 rfcChrBufLimit;
	i32 bpsAdjustFrame[MAX_BPS_ADJUST];
	i32 bpsAdjustBitrate[MAX_BPS_ADJUST];
	i32 gdrDuration;
	i32 roiMapEnable;
	i32 qpOffset[3];
	char *roiMapIndexFile;
	i32 inputLineBufMode;
	i32 inputLineBufDepth;

	// Added by Raymond
	i32 ipf;				// Added by Raymond
	i32 drop;				// Added by Raymond
	i32 stream_id;
	void *video;			//
	void *h264_handle;		//
	void *jpeg_handle;		//

	volatile u8 start_enc;	// 0: stop 1: start 2: close
	volatile u8 start_jpg;	// 0: stop 1: start	2: close
	volatile u8 isp_used;	// H264/JPEG use ISP channel
	i32 ispRateNumer;				// Added by Raymond
	i32 voe;				// Added by Raymond
	i32 record;				// Added by Raymond

	// JPEG usage
	i32 qLevel;
	i32 thumbnail;

	// Added by Raymond
} commandLine_s;





#endif
