##################################################################################
#                                                                                #
#                             Example example_usbh_msc_new                   #
#                                                                                #
##################################################################################

Date: 2021-6-24

Table of Contents
~~~~~~~~~~~~~~~~~
 - Description
 - Setup Guide
 - Parameter Setting and Configuration
 - Result description
 - Other Reference
 - Supported List

 
Description
~~~~~~~~~~~
        With USB host v2.0 interface, Ameba can be designed to a USB msc specific host.
        In this application, Ameba boots up as USB host which can communicate with msc specific USB device as 
        USB flash disk.
    
Setup Guide
~~~~~~~~~~~
        In order to run this application successfully, the hardware setup should be confirm before moving on.
        1. Connect USB flash disk to the micro USB connector on Ameba develop board.
        2. For GCC environmnet, type command "make menuconfig" and choose CONFIG USB => Enable USB => USB OTG Type => 
           USB_OTG_HOST_MODE_NEW and then choose USB Host Type => USB_HOST_MSC,
           this will auto-generate following lines in platform_autoconf.h:
               #define CONFIG_USB_OTG_EN              1
               #define CONFIG_USB_HOST_NEW_EN         1
               #define CONFIG_USBH_MSC            1
           And for IAR environment, manually edit platform_autoconf.h as above.
        3. Rebuild the project with command make xip EXAMPLE=usbh_msc_new and download firmware to Ameba develop board.
        4. Reset and check the log via serial console.

Parameter Setting and Configuration
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        None.
    
Result description
~~~~~~~~~~~~~~~~~~
        On the serial console, USB msc specific host mount/read/write file log will be printed, 
        make sure there is no error reported.

Other Reference
~~~~~~~~~~~~~~~
        None.

Supported List
~~~~~~~~~~~~~~
[Supported List]
        Supported : Ameba-D2
        Source code not in project: Ameba-1, Ameba-z, Ameba-pro, Ameba-D