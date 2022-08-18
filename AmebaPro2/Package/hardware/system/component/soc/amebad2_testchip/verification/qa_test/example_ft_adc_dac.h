#ifndef _RTL8195A_FT_ADC_DAC_H_
#define _RTL8195A_FT_ADC_DAC_H_

#include "ameba_soc.h"

#define SP_TX_DMA_PAGE_SIZE	512  // 48k-192
#define SP_TX_DMA_PAGE_NUM    4
#define SP_ZERO_BUF_SIZE	128

typedef struct {
	u8 tx_gdma_own;
	u32 tx_addr;
	u32 tx_length;

} TX_BLOCK, *pTX_BLOCK;

typedef struct {
	TX_BLOCK tx_block[SP_TX_DMA_PAGE_NUM];
	TX_BLOCK tx_zero_block;
	u8 tx_gdma_cnt;
	u8 tx_usr_cnt;
	u8 tx_empty_flag;

} SP_TX_INFO, *pSP_TX_INFO;


#define SP_DMA_PAGE_SIZE	4096 // 2 ~ 4096
#define SP_DMA_PAGE_NUM    	8
#define SP_FULL_BUF_SIZE		128

#define SP_DMA_PAGE_SIZE_EXT	4096 // 2 ~ 4096
#define SP_DMA_PAGE_NUM_EXT   	8
#define SP_FULL_BUF_SIZE_EXT		128

#define RECORD_DET_TO	10

typedef   struct {
	char    fccID[4];
	unsigned   long  dwSize;
	unsigned   short    wFormatTag;
	unsigned   short    wChannels;
	unsigned   long     dwSamplesPerSec;
	unsigned   long     dwAvgBytesPerSec;
	unsigned   short    wBlockAlign;
	unsigned   short    uiBitsPerSample;
} WAVE_FMT; //Format Chunk

typedef   struct {
	char    fccID[4];
	unsigned   long     dwSize;
} WAVE_DATA; //Data Chunk

typedef   struct {
	char     fccID[4];
	unsigned   long      dwSize;
	char     fccType[4];
} WAVE_HEAD; //RIFF WAVE Chunk

typedef struct {
	WAVE_HEAD w_header;
	WAVE_FMT w_fmt;
	WAVE_DATA w_data;
} WAVE_HEADER;

typedef struct {
	GDMA_InitTypeDef       	SpTxGdmaInitStruct;              //Pointer to GDMA_InitTypeDef
	GDMA_InitTypeDef       	SpRxGdmaInitStruct;              //Pointer to GDMA_InitTypeDef
	GDMA_InitTypeDef       	SpTxGdmaInitStructExt;              //Pointer to GDMA_InitTypeDef
	GDMA_InitTypeDef       	SpRxGdmaInitStructExt;              //Pointer to GDMA_InitTypeDef
} SP_GDMA_STRUCT, *pSP_GDMA_STRUCT;

typedef struct {
	u8 rx_gdma_own;
	u32 rx_addr;
	u32 rx_length;

} RX_BLOCK, *pRX_BLOCK;

typedef struct {
	RX_BLOCK rx_block[SP_DMA_PAGE_NUM];
	RX_BLOCK rx_full_block;
	u8 rx_gdma_cnt;
	u8 rx_usr_cnt;
	u8 rx_full_flag;

} SP_RX_INFO, *pSP_RX_INFO;

typedef struct {
	u8 rx_gdma_own;
	u32 rx_addr;
	u32 rx_length;

} RX_BLOCK_EXT, *pRX_BLOCK_EXT;

typedef struct {
	RX_BLOCK_EXT rx_block[SP_DMA_PAGE_NUM_EXT];
	RX_BLOCK_EXT rx_full_block;
	u8 rx_gdma_cnt;
	u8 rx_usr_cnt;
	u8 rx_full_flag;

} SP_RX_INFO_EXT, *pSP_RX_INFO_EXT;


typedef struct {
	u32 sp_sample_rate;
	u32 codec_sample_rate;
	u32 word_len;
	u32 mono_stereo;
	u32 direction_tx;
	u32 direction_rx;
	u32 tdm_mode;
	u32 fifo_num;
	u32 mic_num;

} SP_OBJ, *pSP_OBJ;



//--------- Verification control flag >----------------------------------------
// Enable SPI DAC
#define SPI_DAC_OUTPUT      1

// To reduce harmonic for better SNR result
#define FFT_REDUCE_HARMONIC 1
#define FFT_HARMONIC_ORDER  6

// Enable FFT debug msg
#define FFT_DBG_INFO        0

// Engineer verification only
#define FLOW_VERIFICATION   0

//--------- Verification control flag <----------------------------------------


#define ADDA_VERI_SUBJECT_NO    2
typedef enum ADDA_VEFI_TYPE {
	DAC_SRC_SPI_DMA = 0,
	DAC_SRC_I2C_DMA = 1,
};

#define I2C_DAC_FFT_CRITERION     (float32_t)60.000
#define EXTER_DAC_FFT_CRITERION     (float32_t)56.000

extern int FTAdcFFTTest(IN  unsigned char TestItem);

#endif
