#ifndef _RTL8195A_MII_TEST_H_
#define _RTL8195A_MII_TEST_H_


typedef enum _MII_TEST_FUNC_ {
	MII_TEST_MAC_INIT,					// 0
	MII_TEST_T2R_LBK_CRC_CHECKSUM,		// 1
	MII_TEST_T2R_LBK_LSO,				// 2
	MII_TEST_T2R_LBK_VLAN,				// 3
	MII_TEST_SMI,						// 4
	MII_TEST_MAC_TX,					// 5
	MII_TEST_MAC_RX,					// 6
	RMII_TEST_TX,						// 7
	RMII_TEST_RX,						// 8
	PHY_MODE_TEST_TX,					// 9
	PHY_MODE_TEST_RX,					// 10
	MII_HAL_API_TEST_TX					 = 20,
	MII_HAL_API_TEST_RX					 = 21,
	MII_WOL_TEST						 = 22
}MII_TEST_FUNC;


/* Function Prototype */
extern void *
_memset( void *s, int c, SIZE_T n );

#endif  // #ifndef _RTL8195A_MII_TEST_H_


