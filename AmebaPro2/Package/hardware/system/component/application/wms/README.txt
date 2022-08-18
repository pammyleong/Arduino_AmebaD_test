This wms application is used to run as a wifi multi-channel speaker. In order to run the application the following steps must be followed.

	1. In terminal, change to the directory ”project/realtek_amebaD2_testchip_va0_example/GCC-RELEASE/project_ap”, 
	type ”make menuconfig”, and enable wms related configurations (MENUCONFIG FOR CHIP CONFIG -> WMS Config -> Enable WMS).
	
	2. Call wms_app_start() from app_entry.c in a properly position.
	
	3. Copy Makefile to ”project/realtek_amebaD2_testchip_va0_example/GCC-RELEASE/project_ap/asdk/make”.
	
	4. Build and flash the binary to test.

[Supported List]
	Supported :
	    Ameba-D2 testchip
	Source code not in project:

[Compilation Tips]
	1. Modify high throughput related macros:
	#define MEM_SIZE                (23*1024)
	#define MEMP_NUM_TCP_SEG        60
	#define PBUF_POOL_SIZE          60
	#define TCP_SND_BUF             (10*TCP_MSS)
	#define TCP_SND_QUEUELEN        (6* TCP_SND_BUF/TCP_MSS)
	#define TCP_WND                 (8*TCP_MSS)
	#define NR_XMITBUFF	(128)//(8)
	#define NR_XMITFRAME	100	//NR_XMITBUFF + NR_XMIT_EXTBUFF
	#define MAX_SKB_BUF_NUM			80//10
	2. Modify heap size:
	#define configTOTAL_HEAP_SIZE					( 1152 * 1024 )
	3. Modify memory layout:
	CA7_IMG (rx) :                          ORIGIN = 0x08200000, LENGTH = 0x08500000 - 0x08200000	/* CA7 BL1 and FIP: 1024k */
	4. For master node, enable EMMC
	(1) component\soc\amebad2_testchip\fwlib\include\ameba_sd.h
	#define  SDIO 		    EMMC
	(2) component\file_system\fatfs\r0.14b\include\ffconf.h
	#define FF_USE_LFN		3
	