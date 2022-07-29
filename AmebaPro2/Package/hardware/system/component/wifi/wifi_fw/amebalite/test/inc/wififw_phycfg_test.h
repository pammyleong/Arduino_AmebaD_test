#ifndef __WIFIFW_PHYCFG_TEST_H__
#define __WIFIFW_PHYCFG_TEST_H__


/*--------------------------Define -------------------------------------------*/
#define     rFPGA0_XA_HSSIParameter1    0x820   // RF 3 wire register
#define     rFPGA0_XA_HSSIParameter2    0x824
#define     rFPGA0_XB_HSSIParameter1    0x828
#define     rFPGA0_XB_HSSIParameter2    0x82c

#define     rFPGA0_XA_LSSIParameter     0x840
#define     rFPGA0_XB_LSSIParameter     0x844

#define     TransceiverA_HSPI_Readback  0x8b8   // Transceiver A HSPI Readback
#define     TransceiverB_HSPI_Readback  0x8bc   // Transceiver B HSPI Readback

#define     rFPGA0_XA_LSSIReadBack      0x8a0   // Tranceiver LSSI Readback
#define     rFPGA0_XB_LSSIReadBack      0x8a4
#define     rFPGA0_XC_LSSIReadBack      0x8a8
#define     rFPGA0_XD_LSSIReadBack      0x8ac

#define     bLSSIReadAddress            0x7f800000   // T65 RF

#define     bLSSIReadEdge               0x80000000   //LSSI "Read" edge signal
#define     bLSSIReadBackData           0xfffff     // T65 RF


/*------------------------------Define Enum-----------------------------------*/
typedef enum _RF90_RADIO_PATH {
	RF90_PATH_A = 0,            //Radio Path A
	RF90_PATH_B = 1,            //Radio Path B
	RF90_PATH_C = 2,            //Radio Path C
	RF90_PATH_D = 3,            //Radio Path D

} RF90_RADIO_PATH_E, *PRF90_RADIO_PATH_E;


#define RF90_PATH_MAX           2


/* BB/RF related */
typedef enum _RF_TYPE_8190P {
	RF_TYPE_MIN   = 0,        // 0
	RF_8225       = 1,        // 1 11b/g RF for verification only
	RF_8256       = 2,        // 2 11b/g/n
	RF_8258       = 3,        // 3 11a/b/g/n RF
	RF_6052       = 4,        // 4 11b/g/n RF

	// TODO: We sholud remove this psudo PHY RF after we get new RF.
	RF_PSEUDO_11N = 5,    // 5, It is a temporality RF.
} RF_TYPE_8190P_E, *PRF_TYPE_8190P_E;


/*--------------------------Define MACRO--------------------------------------*/

/*------------------------------Define Struct---------------------------------*/

typedef struct _BB_REGISTER_DEFINITION {
	u16 rf3wireOffset;      // LSSI data:


	u16 rfHSSIPara2;        // wire parameter control2 :

	u16 rfLSSIReadBack;     //LSSI RF readback data SI mode



	u16 rfLSSIReadBackPi;   //LSSI RF readback data PI mode 0x8b8-8bc for Path A and B

} BB_REGISTER_DEFINITION_T, *PBB_REGISTER_DEFINITION_T;

/*------------------------Export global variable------------------------------*/

extern    BB_REGISTER_DEFINITION_T    PHYRegDef[RF90_PATH_MAX];   //Radio A/B/C/D

//========= RF Config     =======================================
// BW and sideband setting
#define     HAL_PRIME_CHNL_OFFSET_DONT_CARE     0
#define     HAL_PRIME_CHNL_OFFSET_LOWER         1
#define     HAL_PRIME_CHNL_OFFSET_UPPER         2


#define    BIT_BW_20MHZ    BIT2


/*--------------------Define Enum---------------------------------------*/

typedef enum _WIRELESS_MODE {
	WIRELESS_MODE_UNKNOWN   = 0x00,
	WIRELESS_MODE_A         = 0x01,
	WIRELESS_MODE_B         = 0x02,
	WIRELESS_MODE_G         = 0x04,
	WIRELESS_MODE_AUTO      = 0x08,
	WIRELESS_MODE_N_24G     = 0x10,
	WIRELESS_MODE_N_5G      = 0x20,
	WIRELESS_MODE_AC_5G     = 0x40
} WIRELESS_MODE;

typedef enum _BAND_TYPE {
	BAND_ON_2_4G = 0,
	BAND_ON_5G,
	BAND_ON_BOTH,
	BANDMAX
} BAND_TYPE, *PBAND_TYPE;


// Represent Channel Width in HT Capabilities
typedef enum _HT_CHANNEL_WIDTH {
	HT_CHANNEL_WIDTH_20 = 0,
	HT_CHANNEL_WIDTH_40 = 1,
	HT_CHANNEL_WIDTH_80 = 2,
	HT_CHANNEL_WIDTH_MAX = 3,
} HT_CHANNEL_WIDTH, *PHT_CHANNEL_WIDTH;



typedef enum _VHT_DATA_SC {
	VHT_DATA_SC_DONOT_CARE          = 0,
	VHT_DATA_SC_20_UPPER_OF_80MHZ   = 1,
	VHT_DATA_SC_20_LOWER_OF_80MHZ   = 2,
	VHT_DATA_SC_20_UPPERST_OF_80MHZ = 3,
	VHT_DATA_SC_20_LOWEST_OF_80MHZ  = 4,
	VHT_DATA_SC_20_RECV1            = 5,
	VHT_DATA_SC_20_RECV2            = 6,
	VHT_DATA_SC_20_RECV3            = 7,
	VHT_DATA_SC_20_RECV4            = 8,
	VHT_DATA_SC_40_UPPER_OF_80MHZ   = 9,
	VHT_DATA_SC_40_LOWER_OF_80MHZ   = 10,
} VHT_DATA_SC, *PVHT_DATA_SC_E;

/*--------------------Function declaration---------------------------------*/
extern void PHY_RFSerialWrite(RF90_RADIO_PATH_E eRFPath, u8 Offset, u32 Data);
extern u32 PHY_RFSerialRead(RF90_RADIO_PATH_E eRFPath, u8 Offset);
extern void PHY_SetRFReg(RF90_RADIO_PATH_E eRFPath, u8 RegAddr, u32 Data);
extern u32 PHY_QueryRFReg(RF90_RADIO_PATH_E eRFPath, u8 RegAddr);
extern void PutBBRegSetting(u16 Addr, u32 BitMask, u32 UserValue);
extern void PHY_InitBBRFRegDef(void);

#endif  //__RTL8720E_PHYCFG_RAM_H__
