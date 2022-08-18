#ifndef _EXAMPLE_WIFI_SPEAKER_PLAYER_H_
#define _EXAMPLE_WIFI_SPEAKER_PLAYER_H_

#include "ameba_soc.h"
#include "wifi_conf.h"
#include "lwipconf.h"
#include "section_config.h"

#include "freertos_service.h"
#include "inic_ipc.h"
#include "platform_stdlib.h"
#include "ameba_rcc.h"
#include "ameba_soc.h"
#include "ameba_sport.h"
#include "ameba_audio.h"
#include "timer_api.h"


#define APMODE  0
#define AMIC	1

#define DMA_PAGE_SIZE 	2048
#define DMA_PAGE_NUM  	5
#define ZERO_BUF_SIZE 	2048
#define PCM_PAGE_SIZE	1024
#define MAX_POOL_SIZE	15
#define PCM_POOL_SIZE	20
#define TRX_POOL_SIZE   20


// for AMIC MODE
#define AMIC_DMA_PAGE_NUM   8
#define AMIC_DMA_PAGE_SIZE  1024
#define AMIC_SP_RATE SP_44P1K
#define AMIC_SR_RATE SR_44P1K
#define PLAY_DELAY_TIME 5


#if !APMODE
#undef MAX_POOL_SIZE
#define MAX_POOL_SIZE 20
#undef PCM_POOL_SIZE
#define PCM_POOL_SIZE	40
#undef TRX_POOL_SIZE
#define TRX_POOL_SIZE	40
#endif


/* message type */
#define TYPE_AUDIO_INFO		0
#define TYPE_AUDIO_CTRL		1
#define TYPE_AUDIO_VOLUME 	2


#define IPC_INT_CHAN_SPEAKER_TRX_TRAN	2

#define IPC_EVT_AUDIO_INFO	0
#define IPC_EVT_AUDIO_PCM	1
#define IPC_EVT_AUDIO_RX_DONE 2
#define IPC_EVT_AUDIO_CTRL 	3
#define IPC_EVT_AUDIO_READ_DONE 4

#define VOLUME_MIN 0
#define VOLUME_MAX 175   // 5V maximum 0x86(134), 12V maximum 0x96(150)
#define IE_SIZE 18


#define SYNC_TIMER_IDX	3

typedef struct {
	int16_t pcm[1024];
	u32 length;
	u32 seq;
	u32 rsvd[14]; 
}WMS_PCM_BLOCK;


typedef struct {
	_list list;
	WMS_PCM_BLOCK block;
	u8 is_used;
	u8 is_dummy;
	int index;
}WMS_PCM_INFO;

typedef struct {
	u8 id;
	u8 len;
	u8 oui[3];
	u8 state;
	u32 tsf;
	u32 seq;
	u32 offset;
	u32 volume;
	u8 bcn;
}wms_beacon_t;

typedef struct {
	_list list;
	inic_ipc_ex_msg_t ipc_ex_msg;
	u8 is_used;
}WMS_IPC_MSG;

typedef struct {
	u32 sampleRate;
	u32 nChannels;
	u32 wordLen;
	u32 period_size;
	u32 streamid;
	u32 state;
	u32 type;	/* audio info type */
	u32 delay;
	u32 volume;
	u32 mute;
	u32 seq;
	u32 tsf;
	u32 filetype;
	u32 mode;
	u32 rsvd[2];
}WMS_AUDIO_INFO;


/**
  * @brief  The enumeration lists audio control state.
  */
enum WMS_AUDIO_STATUS {
	AUDIO_NONE = 0,
	AUDIO_PLAY,
	AUDIO_PAUSE,
	AUDIO_STOP,
	AUDIO_VOLUME,
	AUDIO_MUTE,
	AUDIO_INIT,
};

/**
  * @brief  The enumeration lists file encode type.
  */
enum CODEC_ID {
	CODEC_NONE = 0,
	CODEC_AAC,
	CODEC_M4A,
	CODEC_WAV,
	CODEC_PCM,
};

enum WIDTH_TYPE {
	WIDTH_16BIT = 0,
	WIDTH_24BIT,
};

/**
  * @brief  The enumeration lists application mode.
  */
enum MODE_TYPE {
	MODE_WMS = 0,
	MODE_LIPSYNC,
};

/**
  * @brief  The enumeration lists the results of the function.
  */
enum {
	WMS_OK  = 0,    /**< Success */
	WMS_TRUE = 1,   /* return ture */
	WMS_FAIL     = -1,
	WMS_DROP	 = -2,
};



typedef struct {
	GDMA_InitTypeDef       	SpTxGdmaInitStruct;              //Pointer to GDMA_InitTypeDef
	GDMA_InitTypeDef       	SpRxGdmaInitStruct;              //Pointer to GDMA_InitTypeDef
} WS_SP_GDMA_STRUCT, *pWS_SP_GDMA_STRUCT;

typedef struct {
	u8 tx_gdma_own;
	u32 tx_addr;
	u32 tx_length;
	u32 tx_seq;
	u8 tx_dummy;
} TX_BLOCK, *pTX_BLOCK;


typedef struct {
	TX_BLOCK tx_block[DMA_PAGE_NUM];
	TX_BLOCK tx_zero_block;
	u8 tx_gdma_cnt;
	u8 tx_usr_cnt;
	u8 tx_empty_flag;
	u32 aac_len;
	u32 pcm_len;
} WS_SP_TX_INFO, *pWS_SP_TX_INFO;


typedef struct {
	u32 sp_clock;
	u32 sp_sample_rate;
	u32 codec_sample_rate;
	u32 word_len;
	u32 ch_len;
	u32 mono_stereo;
	u32 tdm_mode;
	u32 fifo_num;
	u32 din_sel;
} WS_SP_OBJ, *pWS_SP_OBJ;


typedef struct {
	SP_InitTypeDef SpTx_InitStruct;
	SP_InitTypeDef SpRx_InitStruct;
	CODEC_InitTypeDef CODECTx_InitStruct;
	CODEC_InitTypeDef CODECRx_InitStruct;
	WS_SP_GDMA_STRUCT SPGdmaStruct;
	WS_SP_TX_INFO sp_tx_info;
	WS_SP_OBJ sp_obj;
}WMS_DMA_OBJ;

typedef struct {
	u32 rx_cnt;
	u32 tx_cnt;
}WMS_AMIC_PARAM;

struct wms_player_adapter {
	_sema rxsema;        /* ipc message rx semaphore */
	_sema syncsema;		 /* play sync semaphore */ 
	_queue ipc_msg_queue; /* ipc message queue */ 
	_queue pcm_queue;		/* pcm queue */ 
	WMS_AUDIO_INFO audio_info;	/* audio information */ 
	WMS_DMA_OBJ dma;
	WMS_AMIC_PARAM amic;
	_timer retry_timer;		/* frame retry timer */ 
	u8 streamid;	/* stream id */
	u32 txseq;     /* current pcm seq */
	u32 rxseq;    /* last pcm seq */
	u32 playseq;    /* last pcm seq */
	u32 syncseq;
	u8 playstate;	    /* audio play state */
	u8 rxstate;    /* audio play state */
	u32 syncus;      /* delay time for sync */
	u32 tsf0;
	u16 diff;       /* gdma offset difference */
	u8 adjust;      /* gdma offset adjust flag */
	u8 audio_init;  /* audio initialize flag */
	u8 filetype;    /* audio playing file type enum CODEC_ID */
	u8 filewidth;   /* audio playing pcm data word length */
	u8 mode;        /* current working mode, wms/lipsync */
	u8 exist;       /* dummy frame filled flag */
	u32 lighting;   /* led lingting interval */
	u32 deltavolume; /* ease in ease out step */
	u32 easein;      /* ease in flag */
};


enum {
	WS_ERROR = 0,
	WS_WARNING,
	WS_INFO,
	WS_DEBUG,
	WS_NONE,
};
	
#define WS_DEBUG_ON	1
#if WS_DEBUG_ON
#define WS_DEBUGF(level, fmt, arg...)     \
do {\
	if (level <= WS_DEBUG) {\
		if (level <= WS_ERROR) {\
			printf("\n\rerror %s, " fmt "\n\r", __func__, ##arg);\
		} \
		else if(level == WS_WARNING){\
			printf("warning %s, " fmt "\n", __func__, ##arg);\
		} \
		else if(level == WS_INFO){\
			printf("info %s, " fmt "\n", __func__, ##arg);\
		} \
		else if(level == WS_DEBUG){\
			printf("debug %s, " fmt "\n", __func__, ##arg);\
		} \
	}\
}while(0)
#else
#define WS_DEBUGF(level, fmt, arg...)
#endif


void wms_player_start();
void sync_timer_reload(uint32_t tid, uint32_t duration_us);

#endif
