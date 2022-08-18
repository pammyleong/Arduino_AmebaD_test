#ifndef HANTRO_JEPG_ENCODER
#define HANTRO_JPEG_ENCODER
#include "jpegencapi.h"
//#include "memory_encoder.h"
//#include "isp_api.h"

#include "video.h"
#include "EncJpegInstance.h"


struct jpeg_context {
	JpegEncInst encoder;
//	struct hantro_jpeg_parm jpeg_parm;
	//JpegEncCfg cfg;
	//struct encoder_list_head encoder_jpeg_lh;

	u32 LumSize;
	u32 CbSize;

	uint32_t source_addr;
	uint32_t dest_addr;
	uint32_t dest_len;
	uint32_t dest_actual_len;

	// Added By Raymond
	uint32_t voe;
};

void *jpeg_open(void);
int jpeg_encode(void *ctx);
int jpeg_release(void *ctx);
int jpeg_initial(void *ctx, commandLine_s *cmdl);
int jpeg_encode(void *ctx);

int jpeg_voe_start(void *ctx);

//extern int hantro_jpeg_init_param(struct hantro_jpeg_parm *jpeg_parm);
//extern void print_jpeg_enc_parameters(const JpegEncCfg *pEncCfg);
void jpeg_info(void);

#endif
