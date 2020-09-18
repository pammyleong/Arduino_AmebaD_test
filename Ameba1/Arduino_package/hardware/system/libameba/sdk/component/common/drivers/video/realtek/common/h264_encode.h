#ifndef _H264_ENCODE_H_
#define _H264_ENCODE_H_

#include <inttypes.h>

#define H264_MAX_RING_SIZE 6
#define H264_FRAME_BUF     30*1024

struct h264_context
{
    uint8_t ring_tail;
    uint8_t ring_head;
    uint8_t ring[H264_MAX_RING_SIZE][H264_FRAME_BUF];
    uint32_t ring_len[H264_MAX_RING_SIZE];

    uint8_t bDriverStopped;
    uint8_t bSurpriseRemoved;
    void *wakeup_sema;
};

int h264_enc_init(void *ctx);

typedef void (*h264_enc_handle)(void *id);

//int register_h264_enc_handle(h264_enc_handler handle, void *data);

#endif