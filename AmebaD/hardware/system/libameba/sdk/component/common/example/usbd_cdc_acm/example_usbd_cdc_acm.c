#include <platform_opts.h>
#if defined(CONFIG_EXAMPLE_USBD_CDC_ACM) && CONFIG_EXAMPLE_USBD_CDC_ACM
#include <platform/platform_stdlib.h>
#include "device/core/inc/usb.h"
#include "device/class/cdc_acm/inc/usbd_cdc_acm_if.h"

#define ACM_BULK_IN_BUF_SIZE  256
#define ACM_BULK_OUT_BUF_SIZE 256

static int acm_init(void)
{
    usbd_cdc_acm_set_bulk_transfer_buffer_size(ACM_BULK_OUT_BUF_SIZE, ACM_BULK_IN_BUF_SIZE);
    return ESUCCESS;
}

static int acm_deinit(void)
{
    return ESUCCESS;
}

static int acm_receive(void *buf, u16 length)
{
    u16 len = (length > ACM_BULK_OUT_BUF_SIZE) ? ACM_BULK_OUT_BUF_SIZE : length;
    // Echo the received message back to host
    usbd_cdc_acm_transmit_data(buf, len);
    return ESUCCESS;
}

usbd_cdc_acm_usr_cb_t cdc_acm_usr_cb = {
    .init = acm_init,
    .deinit = acm_deinit,
    .receive = acm_receive,
};

static void example_usbd_cdc_acm_thread(void *param)
{
    int ret = 0;
    UNUSED(param);
    
    usbd_cdc_acm_register(&cdc_acm_usr_cb);
    
    ret = usb_init();
    if (ret != 0) {
        printf("\n\rUSB init fail\n\r");
        goto example_usbd_cdc_acm_thread_fail;
    }

    vTaskDelay(100);
    
    printf("\n\rUSBD CDC ACM demo started\n\r");

example_usbd_cdc_acm_thread_fail:
    vTaskDelete(NULL);
}

void example_usbd_cdc_acm(void)
{
    if (xTaskCreate(example_usbd_cdc_acm_thread, "example_usbd_cdc_acm_thread", 1024, NULL,
            tskIDLE_PRIORITY + 5, NULL) != pdPASS) {
        printf("\n\rUSBD CDC ACM create thread fail\n\r");
    }
}

#endif

