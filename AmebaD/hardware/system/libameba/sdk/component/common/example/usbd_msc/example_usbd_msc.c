#include <platform_opts.h>
#if defined(CONFIG_EXAMPLE_USBD_MSC) && CONFIG_EXAMPLE_USBD_MSC
#include <platform/platform_stdlib.h>
#include "device/core/inc/usb.h"
#include "device/class/msc/inc/usbd_msc_if.h"

// This configuration is used to enable a thread to check hotplug event
// and reset USB stack to avoid memory leak, only for example.
// For bus-powered device, it shall be set to 0.
// For self-powered device:
// * it is suggested to check the hotplug event via hardware VBUS GPIO interrupt
//   support other than this software polling thread.
// * while if there is no hardware VBUS GPIO interrupt support, set this configuration
//   to 1 for a better support for hotplug.
// * Set this configuration to 0 to save CPU timeslice for better performance, if
//   there is no need for hotplug support.
#define CONFIG_USDB_MSC_CHECK_USB_STATUS   0

#if CONFIG_USDB_MSC_CHECK_USB_STATUS
static void msc_check_usb_status_thread(void *param)
{
    int ret = 0;
    int usb_status = USB_STATUS_INIT;
    static int old_usb_status = USB_STATUS_INIT;

    UNUSED(param);

    for (;;) {
        vTaskDelay(100);
        usb_status = usb_get_status();
        if (old_usb_status != usb_status) {
            old_usb_status = usb_status;
            if (usb_status == USB_STATUS_DETACHED) {
                printf("\n\rUSB DETACHED\n\r");
                usb_deinit();
                usbd_msc_register();
                ret = usb_init();
                if (ret != 0) {
                    printf("\n\rUSB re-init fail\n\r");
                    break;
                }
            } else if (usb_status == USB_STATUS_ATTACHED) {
                printf("\n\rUSB ATTACHED\n\r");
            } else {
                printf("\n\rUSB INIT\n\r");
            }
        }
    }
    
    vTaskDelete(NULL);
}
#endif // CONFIG_USDB_MSC_CHECK_USB_STATUS

static void example_usbd_msc_thread(void *param)
{
    int ret = 0;
    
    UNUSED(param);
    
    usbd_msc_register();
    
    ret = usb_init();
    if (ret != 0) {
        printf("\n\rUSB init fail\n\r");
        goto example_usbd_msc_thread_fail;
    }

#if CONFIG_USDB_MSC_CHECK_USB_STATUS
    if (xTaskCreate(msc_check_usb_status_thread, "msc_check_usb_status_thread", 512, NULL,
            tskIDLE_PRIORITY + 2, NULL) != pdPASS) {
        printf("\n\rCreate USB status check thread fail\n\r");
        goto example_usbd_msc_thread_fail;
    }
#endif // CONFIG_USDB_MSC_CHECK_USB_STATUS

    printf("\n\rUSBD MSC demo started\n\r");

    vTaskDelete(NULL);
    
    return;
    
example_usbd_msc_thread_fail:
    printf("\n\rUSBD MSC demo init fail\n\r");
    vTaskDelete(NULL);
}

void example_usbd_msc(void)
{
    if (xTaskCreate(example_usbd_msc_thread, "example_usbd_msc_thread", 1024, NULL,
            tskIDLE_PRIORITY + 5, NULL) != pdPASS) {
        printf("\n\rUSBD MSC create thread fail\n\r");
    }
}

#endif

