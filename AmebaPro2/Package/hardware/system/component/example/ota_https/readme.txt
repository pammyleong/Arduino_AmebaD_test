##################################################################################
#                                                                                #
#                      OTA HTTPS UPDATING EXAMPLE                                #
#                                                                                #
##################################################################################

Date: 2019-10-24

Table of Contents
~~~~~~~~~~~~~~~~~
 - Description
 - Setup Guide
 - Parameter Setting and Configuration
 - Result description
 - Supported List


Description
~~~~~~~~~~~
    This example is designed for firmware update by Over-the-air programming (OTA) 
        via Wireless Network Connection. Download OTA_ALL.bin from the https download server
        (in tools\DownloadServer(HTTP)) automatically.


Setup Guide
~~~~~~~~~~~
        1. Add ota_https example to SDK
        
        /component/common/example/ota_https
        .
        |-- example_ota_https.c
        |-- example_ota_https.h
        `-- readme.txt
        
        
        2. Enable CONFIG_EXAMPLE_OTA_HTTPS in [platform_opts.h]
        /* For https ota update example */
        #define CONFIG_EXAMPLE_OTA_HTTPS     1

        3. Enable HTTPS_OTA_UPDATE 
        [RTL8721d_ota.h]
            #define HTTPS_OTA_UPDATE
        
        4. Add example_ota_https() to [example_entry.c]
        #if CONFIG_EXAMPLE_OTA_HTTPS
            #include <ota_https/example_ota_https.h>
        #endif
        void example_entry(void)
        {
        #if CONFIG_EXAMPLE_OTA_HTTPS
            example_ota_https();
        #endif
        }
        
        5. Add example_ota_https example source files to project
        (a) For IAR project, add example_ota_https example to group <example> 
            $PROJ_DIR$\..\..\..\component\common\example\ota_https\example_ota_https.c
        (b) For GCC project, add example_ota_https example to example Makefile
            CSRC += $(DIR)/ota_https/example_ota_https.c


Parameter Setting and Configuration
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Modify SSL_MAX_CONTENT_LEN in SSL config and configTOTAL_HEAP_SIZE in freertos config for large size file.
        If the transmitted fils size is larger than 16kbytes, SSL_MAX_CONTENT_LEN should be set to 16384.
        FreeRTOS heap may be increased for ssl buffer allocation.
        (ex. If using 16kbytes * 2 for ssl input/output buffer, heap should be increased from 60kbytes to 80kbytes.)
    set: [config_rsa.h]
            #define SSL_MAX_CONTENT_LEN     16384
         [FreeRTOSConfig.h]
            #define configTOTAL_HEAP_SIZE   ( ( size_t ) ( 80 * 1024 ) )
    Modify PORT, HOST and RESOURCE based on your HTTP download server.
        e.g.: SERVER: http://m-apps.oss-cn-shenzhen.aliyuncs.com/051103061600.bin
        set:    #define PORT    443
                #define HOST    "m-apps.oss-cn-shenzhen.aliyuncs.com"
                #define RESOURCE    "051103061600.bin"
        For local local network download, Set it with IP and OTA_ALL.bin
        set:    #define PORT    443
                #define HOST    "192.168.1.100"
                #define RESOURCE    "OTA_ALL.bin"

        Note: Remember to Set the server start.bat with the same PORT and RESOURCE.


Result description
~~~~~~~~~~~~~~~~~~
    Make automatical Wi-Fi connection when booting by using wlan fast connect example.
    A https download example thread will be started automatically when booting.
    Using the example with the tool in tools\DownloadServer(HTTP) with RESOURCE file.


Supported List
~~~~~~~~~~~~~~
    Supported :
        Ameba-D, 

