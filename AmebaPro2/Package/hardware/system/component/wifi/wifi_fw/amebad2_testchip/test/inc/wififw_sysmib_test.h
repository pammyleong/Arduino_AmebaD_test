#ifndef __WIFIFW_SYSMIB_TEST_H__
#define __WIFIFW_SYSMIB_TEST_H__

//1.) Xdata Section
typedef struct _mib_info_test_ {

	//3 HAL
	HAL_DATA_8721D          IntHdl;

	//u8              FEISRBitMap[4];
	//u8              FWISRBitMap[4];
	//u8              FTISRBitMap[4];
	u32   FWISRBitMap;
	u32   FW1ISRBitMap;
	u32   FE1ISRBitMap;
	u32   FE2ISRBitMap;
	u32   FE3ISRBitMap;
	u32   FE4ISRBitMap;
	u32   FE5ISRBitMap;
	u32   FE6ISRBitMap;

	u32   FTISRBitMap;
	u32   FT1ISRBitMap;
	u32   FT2ISRBitMap;

	u32   zbimr;
	u32   zbisr;
	u32   ZBISRBitMap;
	union {
		u32             TSFOnBcnErly1;
		u8              TSFOnBcnErly1Arr[4];
	} TSFOnBcnErly1Union;
	union {
		u32             TSFOnBcnErly2;
		u8              TSFOnBcnErly2Arr[4];
	} TSFOnBcnErly2Union;
	union {
		u32             TSFOnTBTT1;
		u8              TSFOnTBTT1Arr[4];
	} TSFOnTBTT1Union;
	union {
		u32             TSFOnTBTT2;
		u8              TSFOnTBTT2Arr[4];
	} TSFOnTBTT2Union;
	union {
		u32             TSFOnDWEarly;
		u8              TSFOnDWEarlyArr[4];
	} TSFOnDWEarlyUnion;
	union {
		u32             TSFOnDWEnd;
		u8              TSFOnDWEndArr[4];
	} TSFOnDWEndUnion;
	union {
		u32             TSFOnP2POn;
		u8              TSFOnP2POnArr[4];
	} TSFOnP2POnUnion;
	union {
		u32             TSFOnP2POff;
		u8              TSFOnP2POffArr[4];
	} TSFOnP2POffUnion;
	u32             DeltaTSF1;
	u32             DeltaTSF2;
	u8              MbssidCnt;
	u8              ErlyAdjCnt;
	u8              TestItem;

	u32             baseAddr;

	u8               WL2BTMailboxSent;
} mib_info_test, *Pmib_info_test;


#ifdef __TEST_C__
mib_info_test SysMibTest;
#else
extern  mib_info_test SysMibTest;
#endif

#endif