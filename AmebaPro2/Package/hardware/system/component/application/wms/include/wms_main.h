#ifndef _EXAMPLE_WIFI_SPEAKER_H_
#define _EXAMPLE_WIFI_SPEAKER_H_

#include "ameba_soc.h"
#include "freertos_service.h"
#include "wifi_conf.h"
#include "lwipconf.h"
#include "ff.h"
#include <fatfs_ext/inc/ff_driver.h>
#include <disk_if/inc/sdcard.h>
#include "section_config.h"
#include "libAACdec/include/aacdecoder_lib.h"
#include "wifi_fast_connect.h"

#include "log/log.h"
#include "audio_track.h"
#include "cJSON/cJSON.h"
#include "sockets.h"
#include "wifi.h"
#include "inic_ipc.h"
#include "flash_api.h"
#include "device_lock.h"

#include "wms_audio_sp.h"



#define M4A_DECODE_SIZE		4096

#define MAX_FILE_NAME_LEN 	128
#define MAX_FILE_PATH_LEN 	256
#define MAX_CODEC_LEN		4
#define NODE_TIMEOUT		8*1000  /* 10s */

#ifndef ETH_ALEN
#define ETH_ALEN 6
#endif

#define ETH_ILEN	4

#define DEC_FRAME_LEN		1024
#define MAX_BUF_SIZE 		1470
#define BIT_FLAG_RETRY 		BIT(15)
#define MASK_DATA_LEN		0x7FF
#define BIT_SHIFT_SEGNUM 	11
#define BIT_FLAG_SEG		BIT(15)
#define BITS_PER_CHANNEL	WL_16
#define AUDIO_CHANNEL_DATA		0x0021F000
#define APP_MAX_CONN		8

/* message type */
#define WMS_TYPE_CTRL	0
#define WMS_TYPE_DATA	1
#define WMS_TYPE_RETRY  2
#define WMS_TYPE_HEART	3
#define WMS_TYPE_BCN	4

extern struct wms_adapter g_wms_adapter;
extern struct music_list musiclist;
extern struct node_list nodelist;

struct app_msg {
    int item;
	char *item_str;
};

enum APP_TYPE {
	APP_AUDIO = 0,
	APP_DEVICE,
	APP_MODE,
};

enum METHOD_TYPE {
	METHOD_GETLIST = 0,
	METHOD_GETSTATE,
	METHOD_PLAY,
	METHOD_PAUSE,
	METHOD_STOP,
	METHOD_STATUS,
	METHOD_GET,
	METHOD_VUP,
	METHOD_VDOWN,
	METHOD_VSET,
	METHOD_MUTE,
	METHOD_UNMUTE,
	METHOD_REPEAT_ONE,
	METHOD_REPEAT_ALL,
	METHOD_PREVIOUS,
	METHOD_NEXT,
	METHOD_MODEREQ,
	METHOD_MODESET,
	METHOD_CHANNELSET,
};

enum REPEAT_TYPE {
	REPEAT_NONE = 0,
	REPEAT_ONE,
	REPEAT_ALL,
};

#define WMS_SOFTAP_MODE 0
#define WMS_STA_MODE	1

#define WMS_VERSION 0x0

struct wms_app_conn {
	int sock;                        /*!< Client socket descriptor for connection */
	u8 ip[ETH_ILEN];
	u8 app;
};

struct music{
	char name[MAX_FILE_NAME_LEN];
	u32 id;
	struct music *next;
};

struct music_list {
	struct music *next;
};

struct node{
	u8 mac[ETH_ALEN];
	u8 ip[ETH_ILEN];
	signed char rssi;
	u8 ch;
	u8 state;  /* playing/offline/online */
	u32 timeout;
	struct node *next;
};

struct node_list{
	struct node *next;
	_sema nodesema;  /* node list protect sema */
};

typedef struct packet_attrib_s {
	int client_fd;
	int type;
	int method;
	u8 name[MAX_FILE_NAME_LEN];
	u8 codec_id;
	u8 fileid;
	u32 volume;
	u8 mute;	
	u8 repeat; 
	u8 mode;  /* 0: wms, 1: lipsync */
	u8 ch[4];
	u8 app;   /* app message flag, 1: from app, 0: from voice */
}packet_attrib_t;

typedef struct overflow_check_s {
	int pcm_num;
	int retry_num;
	int tx_num;
	int tx_count;
	int rxframe_count;
	int pcm_count;
	int retry_count;
}overflow_check_t;

struct wms_common_hdr {
	u8 ver;
	u8 type;
	u16 len;
};
struct wms_data_hdr {	
	u32 seq;
	u16 tot_len;
	u8 filetype;
	u16 seg;
};

struct wms_control_hdr {
	u8 type;
};

struct tx_frame {
	_list list;
	u8 buffer[MAX_BUF_SIZE];
	int size;
	u8 is_used;
	int index;
	u8 ctrl;
};

/* retry frame for slave node */
struct s_retry_frame {
	_list list;
	struct wms_data_hdr data_hdr;
	u8 is_used;
	u32 count;
};
/* rerty frame for master node */
struct m_retry_frame {
	u8 buffer[MAX_BUF_SIZE];
	int size;
	u32 seq;
	int fd;
	struct sockaddr_in addr;  /* udp data server address */
	u8 is_used;
};

/* recv frame from EMMC or UDP */
struct rx_frame {
	_list list;
	u32 seq;
	u8 filetype;
	u8 data[4096];
	u32 len;
	u8 type;  /* frame type, aac/pcm , 0: aac, 1: pcm */
	u8 is_used;
	u8 is_retry;
	int index;
};

struct wms_frame_info{
	int hdrlen;
	int commonhdrlen;
	int datahdrlen;
};

typedef struct {
	u8 streamid;  /* stream id */
	u8 ch;			/* channel */
	u8 location[4];
	int volume;	
	u8 mute;	
	u8 repeat;
}WMS_STREAM_INFO;

typedef struct {
	u8 filename[MAX_FILE_NAME_LEN+MAX_CODEC_LEN];  /* music filename */
	u8 filepath[MAX_FILE_PATH_LEN];			/* music filepath */
	u8 fileid;			/* music filename index */
	u8 filetype;
	u8 filewidth;
	u32 offset;
	u32 totm;			/* total music files count */
	int drv_num;
}WMS_MUSIC_INFO;

typedef struct {
	u8 mac[ETH_ALEN];	/* device mac address */
	u8 ip[ETH_ILEN];	/* device ip address */
	u8 ch[4];
}WMS_DEVICE_INFO;

typedef struct {
	int fd;				/* udp data socket fd */
	int ctrlfd;				/* udp control socket fd */
	u8 udpip[ETH_ILEN];		/* udp server ip address */
	u8 unicastip[ETH_ILEN];
	u8 unicastch;
	struct sockaddr_in addr;  /* udp data server address */
	struct sockaddr_in ctrladdr;  /* udp control server address */
	int dataport;
	int ctrlport;
	int heartport;
}WMS_UDP_INFO;

typedef struct {
	u16 segnum; 		/* frame segment number */
	u16 segoffset;		/* frame segment offset */
	u8 segbuf[4096];    /* frame segment buffer */
}rx_frame_seg;

typedef struct {
	u8   ckID[4];
	u32  dwSize;   // file length-8
	u8  fccType[4];  
	u8  fccID[4];
	u32 ckSize;
	u16 wFmtTag;
	u16  wChannels;
	u32  dwSamplesPerSec;
	u32  dwAvgBytesPerSec;
	u16  wBlockAlign;
	u16  uiBitsPerSample;
	//u8 dataID[4];
	//u32 dataSize;  // dwSize - 36
} WMS_WAVE_HEADER; //Format Chunk

struct wms_adapter {
	_xqueue enc_queue;    /* aac frame queue */
	_queue retry_queue;	 /* retry frame queue */
	_xqueue tx_queue;	 /* master udp tx frame queue */
	_sema rxsema;		 /* decode task rx semaphore */
	_sema txsema;		 /* ipc message tx semaphore */
	_sema cachesema;
	_sema retrysema;	 /* master udp tx task semaphore */
	_sema apsema;		 /* softap init done semaphore */
	_sema playsema;     /* app request to play start */
	_sema wmssema;      /* switch to wms mode */
	_sema lipsyncsema;  /* switch to libsync mode */
	_timer retry_timer;  /* child node frame retry timer */
	_timer heart_timer;  /* child node frame heartbeat timer */
	_timer node_timer;   /* node state check timer */
	_timer bcn_timer;   /* replace beacon early */
	struct wms_data_hdr datahdr;  /* udp frame data header */
	WMS_STREAM_INFO stream_info;  /* audio stream information */
	WMS_MUSIC_INFO music_info;
	WMS_DEVICE_INFO dev_info;
	WMS_UDP_INFO udp_info;
	WMS_WAVE_HEADER wave_header;
	WMS_AMIC_PARAM amic;
	rx_frame_seg seg;
	signed char rssithld;  /* rssi threshold */
	u8 firstframe;      /* audio init flag */
	u8 appplay;		/* app request play at first time */
	u8 state;           /* audio state: play/pause/stop */
	u32 syncus;          /* audio start delay time */
	u32 txseq;		/* last read aac frame seq */
	u32 decseq;			/* last decode frame seq */
	u32 syncseq;		/* audio inform seq */
	u32 retryseq;	/* last retry frame seq */
	u8 retry;			/* frame rerty flag */
	u8 switchm;			/* music switch flag */
	u8 unicast;        /* unicast flag */
	u8 switchu;			/* udp address switch flag */
	u32 tsf0;			/* current tsf0 value */
	u8 oldmode;			/* 0: wms, 1: lipsync */
	u8 newmode;			/* 0: wms, 1: lipsync */
	u8 reconnect;      /* wifi reconnect flag */
	u8 decoder;         /* aac decoder handle operation flag */
};

void wms_conn_params_init();
void wms_stream_info_init();
void wms_udpaddr_set(u8 *udpaddr);
int wms_udp_server_bind(struct sockaddr_in *ser_addr, u16 port, u8 prio);
int wms_udp_server_connect(u32 udp_addr, struct sockaddr_in *ser_addr, int port, u8 prio);
void wms_softap_reconnect();
void nodelist_find_dst(struct node_list *list, u8 *ip);
int app_request_play_state(packet_attrib_t *pattrib);
int app_request_nodes_status(packet_attrib_t * pattrib);
int wms_app_state_update(packet_attrib_t *pattrib);
int wms_master_lipsync_create();
int wms_master_wms_create();
int wms_nodelist_del();
void wms_slave_retry_timer_handler(void *param);
void wms_slave_heart_timer_handler(void *param);
int wms_softap_channel_get();
int wms_softap_channel_set();
void wms_app_thread(void *param);
int wms_txframe_enqueue(u8 *buf, int len, u8 ctrl, u8 prio);
void wms_nodelist_print(struct node_list *mlist);
void wms_nodelist_chk_timer_handler();
void wms_rxframe_release_page(int index);
void wms_cacheframe_release_page();

#endif
