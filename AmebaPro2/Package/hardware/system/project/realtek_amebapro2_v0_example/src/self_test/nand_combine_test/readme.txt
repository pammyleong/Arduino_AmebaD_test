##################################################################################
#                                                                                #
#                      		NAND COMBINE TEST                                #
#                                                                                #
##################################################################################

Date: 2022-03-08

Table of Contents
~~~~~~~~~~~~~~~~~
 - Description
 - Setup Guide
 - Parameter Setting and Configuration
 - Result description
 - Supported List


Description
~~~~~~~~~~~
    This example is designed for nand combine test, and this test is running littlefs test and
    OTA update firmware at the same time.


Setup Guide
~~~~~~~~~~~
        1. Config command: cmake .. -G"Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=../toolchain.cmake -DCUTVER=B -DEXAMPLE=off -DSELF_TEST=nand_combine_test.
	2. Build and download firmware.
	3. Modify firmware version in sdk\project\realtek_amebapro2_v0_example\GCC-RELEASE\mp\amebapro2_firmware_ntz.json.
	e.g. {"type":"VERSION", "length":32, "value":"FEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"} -> {"type":"VERSION", "length":32, "value":"FFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"}.
	4. Build new firmware for update.
	5. Put ota.bin to the download path. 


Parameter Setting and Configuration
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        Modify PORT, HOST and RESOURCE based on your HTTP download server.
        For local local network download, Set it with IP and OTA_ALL.bin
        e.g.    #define PORT    80
                #define HOST    "192.168.1.100"
                #define RESOURCE    "ota.bin"
        Note: Remember to Set the server start.bat with the same PORT and RESOURCE.


Result description
~~~~~~~~~~~~~~~~~~
    Make automatical Wi-Fi connection when booting by using wlan fast connect example.
    A http download example thread will be started automatically when booting.
    Using the example with the tool in tools\DownloadServer(HTTP) with RESOURCE file.
    Please check messgge "**Dump bad block table**" and to confirm whether the bbm idx increases abnormally.


Supported List
~~~~~~~~~~~~~~
[Supported Lis]
        Supported IC:
                Ameba-pro2