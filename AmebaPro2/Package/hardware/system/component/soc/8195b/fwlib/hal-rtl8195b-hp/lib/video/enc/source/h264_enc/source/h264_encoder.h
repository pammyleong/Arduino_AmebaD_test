#ifndef HANTRO_H264_ENCODER
#define HANTRO_H264_ENCODER

#include "h264encapi.h"
#include "vidstbapi.h"

#include "EncGetOption.h"
#include "video.h"


struct h264_context {
	H264EncInst encoder;
     //H264EncConfig cfg;
	//H264EncCodingCtrl codingCfg;
	H264EncRateCtrl rcCfg;	// debug by Raymond
	//H264EncPreProcessingCfg preProcCfg;

	H264EncIn encin;
	H264EncOut encout;

	VideoStbInst stab;
	VideoStbResult stb_result;
	H264EncPictureCodingType codingType;

	uint32_t width;
	uint32_t height;
	int ratenum;
	int gop;
	int videostab;
	H264EncPictureType input_type;
	long index;
	uint32_t stream_id;
	long bitsum;
	uint32_t source_addr;
	uint32_t dest_addr;
	uint32_t dest_len;
	uint32_t dest_actual_len;
	uint32_t stab_addr;

	uint32_t scaled_addr;
	uint32_t scaled_len;

	uint32_t ipf;
	u32 lumSize;
	u32 chrSize;
	// Added By Raymond
	uint32_t voe;
//	u32 h264_slot;

	void *voe_cb;

};

void *h264_open(void);
int h264_voe_start(void *ctx);

int h264_encode(void *ctx);

int h264_release(void *ctx);
int h264_info(void);
int h264_initial(void *ctx, commandLine_s *cmdl);
int h264_dyn_set(void *ctx, u32 bps, u32 gop);


/*
extern int print_enc_parameters(const H264EncConfig *pEncCfg,
		const H264EncCodingCtrl *pCodeParams,
		const H264EncRateCtrl *pRateCtrl,
		const H264EncPreProcessingCfg *pPreProcCfg);
extern int hantro_h264_init_param(struct h264_parameter *h264_parm);
*/

//extern int h264_info(void);

#endif
