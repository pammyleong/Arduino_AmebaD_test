#include <platform_opts.h>
#if defined(CONFIG_EXAMPLE_USBD_AUDIO) && CONFIG_EXAMPLE_USBD_AUDIO
#include "FreeRTOS.h"
#include "task.h"
#include <platform/platform_stdlib.h>
#include "basic_types.h"
#include "usbd_audio/example_usbd_audio.h"
#include "rl6548.h"
#include "freertos_service.h"
#include "osdep_service.h"
#include "device/core/inc/usb.h"
#include "device/class/audio/inc/usb_audio_if.h"

static SP_InitTypeDef SP_InitStruct;
static SP_GDMA_STRUCT SPGdmaStruct;
static SP_OBJ sp_obj;
u8 play_buf[SP_DMA_PAGE_SIZE];
static u8 recv_buf[USB_AUDIO_BUF_SIZE * 2];
_sema recv_sema = NULL;

#ifdef PLATFORM_FREERTOS
xTaskHandle dacTask = NULL;
#else
void *dacTask = NULL;
#endif

static void example_audio_dac_thread(void *param)
{
    u32 tx_addr;
    u32 tx_length;
    u32 rx_addr;
    u32 rx_length;
    pSP_OBJ psp_obj = (pSP_OBJ)param;
    static int send_pos = 0;
    DBG_8195A("Audio dac demo begin......\n");
    sp_init_hal(psp_obj);
#ifdef HEADPHONE_MIC
    sp_init_rx_variables();
#endif
    sp_init_tx_variables();
    /*configure Sport according to the parameters*/
    AUDIO_SP_StructInit(&SP_InitStruct);
    SP_InitStruct.SP_MonoStereo = psp_obj->mono_stereo;
    SP_InitStruct.SP_WordLen = psp_obj->word_len;
    AUDIO_SP_Init(AUDIO_SPORT_DEV, &SP_InitStruct);
    AUDIO_SP_TdmaCmd(AUDIO_SPORT_DEV, ENABLE);
    AUDIO_SP_TxStart(AUDIO_SPORT_DEV, ENABLE);
#ifdef HEADPHONE_MIC
    AUDIO_SP_RdmaCmd(AUDIO_SPORT_DEV, ENABLE);
    AUDIO_SP_RxStart(AUDIO_SPORT_DEV, ENABLE);
#endif
    DBG_8195A("\nWait to play.\n");
#ifdef HEADPHONE_MIC
    rx_addr = (u32)sp_get_free_rx_page();
    rx_length = sp_get_free_rx_length();
    AUDIO_SP_RXGDMA_Init(0, &SPGdmaStruct.SpRxGdmaInitStruct, &SPGdmaStruct, (IRQ_FUN)sp_rx_complete, (u8 *)rx_addr, rx_length);
#endif
    tx_addr = (u32)sp_get_ready_tx_page();
    tx_length = sp_get_ready_tx_length();
    AUDIO_SP_TXGDMA_Init(0, &SPGdmaStruct.SpTxGdmaInitStruct, &SPGdmaStruct, (IRQ_FUN)sp_tx_complete, (u8 *)tx_addr, tx_length);

    while (1) {
        if (xSemaphoreTake(recv_sema, 0xFFFFFFFF) != pdTRUE) {
            continue;
        }

        memcpy(play_buf, &recv_buf[send_pos * SP_DMA_PAGE_SIZE], SP_DMA_PAGE_SIZE);
        send_pos++;
        send_pos = send_pos % 2;

        while (sp_get_free_tx_page() == 0) {
            vTaskDelay(1);
        }

        sp_write_tx_page((u8 *)play_buf, SP_DMA_PAGE_SIZE);
    }

    // vTaskDelete(NULL); // Fix compiling warning
}

static int audio_init(void)
{
    int status = ESUCCESS;
    
    rtw_init_sema(&recv_sema, 0);
    
    sp_obj.sample_rate = SR_48K;
    sp_obj.word_len = WL_16;
    sp_obj.mono_stereo = CH_STEREO;
#ifdef HEADPHONE_MIC
    sp_obj.direction = APP_LINE_OUT | APP_DMIC_IN;
#else
    sp_obj.direction = APP_LINE_OUT;
#endif

    if (xTaskCreate(example_audio_dac_thread, "example_audio_dac_thread", 512, (void *)(&sp_obj),
            tskIDLE_PRIORITY + 1, &dacTask) != pdPASS) {
        printf("\n\rUSBD audio create DAC thread fail\n\r");
        status = -EINVAL;
    }

    return status;
}

static void audio_deinit(void)
{
    // TODO: SP deinit
    
    if (dacTask != NULL) {
        vTaskDelete(dacTask);
        dacTask = NULL;
    }

    rtw_free_sema(&recv_sema);
}

static bool usb_ep_out_packet_process(u8 *p_data, u16 len)
{
    int copy_size = USB_AUDIO_BUF_SIZE;
    static int copy_pos = 0;
    static int send_pos = 0;

    if ((copy_pos + len) <= (USB_AUDIO_BUF_SIZE * 2)) {
        copy_size = len;
        memcpy(&recv_buf[copy_pos], p_data, copy_size);
        copy_pos = copy_pos + len;
    } else {
        copy_size = (USB_AUDIO_BUF_SIZE * 2) - copy_pos;
        memcpy(&recv_buf[copy_pos], p_data, copy_size);
        memcpy(&recv_buf[0], (p_data + (copy_size)), (len - copy_size));
        copy_pos = len - copy_size;
    }

    if (send_pos == 0) {
        if ((copy_pos - send_pos) >= USB_AUDIO_BUF_SIZE) {
            send_pos = USB_AUDIO_BUF_SIZE;
            xSemaphoreGive(recv_sema);
        }
    } else {
        if (copy_pos < send_pos) {
            send_pos = 0;
            xSemaphoreGive(recv_sema);
        }
    }

    return TRUE;
}

u8 mic_recv_pkt_buff[SP_DMA_PAGE_SIZE * RECV_BUF_NUM];

static bool usb_ep_in_packet_process(u8 *p_data, u16 len)
{
    int copy_size;
    static int copy_pos = 0;

    if ((copy_pos + len) <= (USB_AUDIO_BUF_SIZE * RECV_BUF_NUM)) {
        copy_size = len;
        memcpy(p_data, &mic_recv_pkt_buff[copy_pos], len);
        copy_pos = (copy_pos + len) % (USB_AUDIO_BUF_SIZE * RECV_BUF_NUM);
    } else {
        copy_size = (USB_AUDIO_BUF_SIZE * 4) - copy_pos;
        memcpy(p_data, &mic_recv_pkt_buff[copy_pos], copy_size);
        memcpy((p_data + (copy_size)), &mic_recv_pkt_buff[0], (len - copy_size));
        copy_pos = len - copy_size;
    }

    return TRUE;
}

//Set bit chann mode
static void usb_audio_plug_process(uint8_t audio_path, uint8_t bit_res, uint8_t sf,
    uint8_t chann_mode)
{
    UNUSED(audio_path);
    UNUSED(bit_res);
    UNUSED(sf);
    UNUSED(chann_mode);
}

static void usb_audio_unplug_process(uint8_t audio_path)
{
    UNUSED(audio_path);
}

usbd_audio_usr_cb_t audio_usr_cb = {
    .plug      = usb_audio_plug_process,
    .unplug    = usb_audio_unplug_process,
    .put_data  = usb_ep_out_packet_process,
    .pull_data = usb_ep_in_packet_process,
    .set_gain  = NULL,
    .init      = audio_init,
    .deinit    = audio_deinit,
};

static void example_usb_audio_thread(void *param)
{
    int ret = 0;
    
    UNUSED(param);

    usbd_audio_register(&audio_usr_cb);
    
    ret = usb_init();
    if (ret != 0) {
        printf("\n\rUSB init fail\n\r");
        goto example_usb_audio_thread_fail;
    }

    vTaskDelay(10000);

example_usb_audio_thread_fail:
    vTaskDelete(NULL);
}

void example_usbd_audio(void)
{
    if (xTaskCreate(example_usb_audio_thread, "example_usb_audio_thread", 1024 + 512, NULL,
            tskIDLE_PRIORITY + 1, NULL) != pdPASS) {
        printf("\n\rUSBD audio create thread fail\n\r");
    }
}

#endif

