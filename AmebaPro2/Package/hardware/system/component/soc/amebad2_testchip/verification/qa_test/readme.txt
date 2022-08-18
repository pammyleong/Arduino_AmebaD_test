//////////////////////
/// How To Start ///
/////////////////////

====================  Configuration Start =========================
cd project/realtek_amebaD2_testchip_va0_example/GCC-RELEASE/project_lp
make menuconfig
	<CONFIG TEST MODE --> 
		[ * ] Select QA
make xip

cd project/realtek_amebaD2_testchip_va0_example/GCC-RELEASE/project_hp
make menuconfig
	<CONFIG TEST MODE --> 
		[ * ] Select QA
	<CONFIG WIFI -->
		[ * ] Enable Wifi
	<CONFIG NETWORK -->
		[ * ] Enable Network
	<SSL Config-->
		[ * ] MBEDTLS Enable
make xip

cd project/realtek_amebaD2_testchip_va0_example/GCC-RELEASE/project_ap
make menuconfig
	<CONFIG TEST MODE --> 
		[ * ] Select QA
	< GUI Config  --->
 		[ * ]Enable GUI (NEW)
 		[ * ] LittlevGL (NEW)
	<CONFIG WIFI -->
		[ * ] Enable INIC IPC
make xip
====================  Configuration End =========================

////////////////////////////////////////
/// Interface test case Description ///
////////////////////////////////////////

Case:	Included:	CMD		DESCRIPTION		
WIFI	Yes	qa wifi		1. wifi mp ctx at 2.4G channel 7 for 5min. then ctx at 5G channel 153 for 5min
MIPI	Yes	qa mipi		1. mipi show test	
EMMC	Yes	qa emmc		1. example emmc 
AUDIO	Yes	qa audio		1. audio recored and speak AMIC1/2/3/5, FFT test. SNR should be around 90dB
		qa audio 88 0xaf	1. audio recored and speak AMIC1/2/3/4/5, 调整放音音量（0x0-0xFF）
		qa audio 144	1. audio recored and speak AMIC1/2/3/4/5
		qa audio 144 0xaf	1. audio recored and speak AMIC1/2/3/4/5, 调整放音音量（0x0-0xFF）
GPIO	Yes	qa gpio88  1/0	1. dedicated gpio output High or Low
		qa gpio144 1/0	1. dedicated gpio output High or Low
ADC	Yes	qa adc 88		1. adc detect key status at channel 2 for QFN88
		qa adc 144	1. adc detect key status at channel 7 for QFN144
touch	Yes	~guishow		1. get gui interface and detect touch coordinate
BT	NO	--


CA7 work in 1.0GHz
	
Other CMD
	============= Sleep CMD INFO =====================
	PG 0		1/ KM4 enters power gate state
	@CG 0		2/ KM0 enters clock gate state
	@DSLP 0		3/ System enters dslp state
	tickps dslp 1000	4/ amebaSmart enters DSLP for 1s then wakeup

	============= QA cmd external =====================	
	qa all		1/ wifi thread + audio thread
	qa debug info	2/ dump debug info level message

	==================== memory test choose ddr or psram ===========
	qa mem		1. ddr/psram read/write test from 0x62000000 - 0x64000000 (PSRAM 512Mbits, DDR depends on package)
	qa stop		1. stop memory test
	~qa mem		1. memory test on AP  (NOTE: memory test should be on AP or NP, as they operate the same memory space)
	~qa stop		1. memory test stop 
