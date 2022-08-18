//////////////////////
/// How To Start ///
/////////////////////

====================  Configuration Start =========================
cd project/realtek_amebaD2_testchip_va0_example/GCC-RELEASE/project_lp
make menuconfig
	<CONFIG TEST MODE --> 
		[ * ] Select EQC
make xip

cd project/realtek_amebaD2_testchip_va0_example/GCC-RELEASE/project_hp
make menuconfig
	<CONFIG TEST MODE --> 
		[ * ] Select EQC
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
		[ * ] Select EQC
make xip
====================  Configuration End =========================

/////////////////////////////////
/// Command Information ///
////////////////////////////////
Other CMD
	============= Sleep CMD INFO =====================
	PG 0		1/ KM4 enters power gate state
	@CG 0		2/ KM0 enters clock gate state
	@DSLP 0		3/ System enters dslp state
	tickps dslp 1000	4/ amebaSmart enters DSLP for 1s then wakeup

	============= EQC cmd external =====================	
	eqc		1/ default all cases to test, it takes 2min in worst cases 
	help		2/ dump case bits for eqc case XXXX(Hex) cmd
	eqc case XXXX	2/ set eqc test case use cmd HELP to get mor information
	eqc stop		3/ if you want to stop last eqc cmd thread, use this cmd
	eqc debug info	4/ dump debug info level message
	~eqc		5/ CA7 DDR memory test
	~eqc debug info	6/ dump CA7 debug info level message

////////////////////////////////////////
/// Interface test case Description ///
////////////////////////////////////////
====================QFN144 Interface test case description start =======================
GPIO loop test	GPIO OUTPUT--> INPUT
	GPIO_A3/A4
	GPIO_A6/D0
	GPIO_D1/D2
	GPIO_E0/E1
	GPIO_E2/E3
	GPIO_E4/ID： ID only input
LP_I2C0->HP_I2C2 loop test	400Kbps
	PA10 --- PA12     SCL
	PA9 --- PA11       SDA
UART0 -> UART2 loop test	
	PA7 -- PA14
	PA8 -- PA13;  
SPI1/SPI2 loop test	
	MOSI: PB10 -- PB19
	MISO: PB11 -- PB20
	CLK   : PB12 -- PB22
	CSS   : PB13 -- PB21
ADC	CTC, ADC and Bias 1/2/3/4/5 test
	CapTouch 0 测试 调整mbias current，量测并读取PCB寄生电容值（外挂电容固定）
	 ADC1 -> BIAS1
	ADC2 -> BIAS2
	ADC5-> BIAS3
	VBAT_measure -> BIAS4
Audio path loop test	
	AOUT_R->M1/M2
	AOUT_L->M3/M4/M5
U-disk read/write test	
	DP/DM: loopback
	ID/Vbus: 改变ID状态，检测VBUS电压？VBUS去处
MIPI	MIPI display：显示结果
	后续添加显示测试结果(TODO)
WIFI	WIFI 2G/5G TX/RX test with AP
BT	BT TX/RX test with AP（x）暂时不添加
====================QFN144 Interface test case description end =======================

NOTE：This readme is specific for QFN144 test case