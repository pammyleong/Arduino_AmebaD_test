#ifndef _DEVICE_H_
#define _DEVICE_H_
/********************************************
		Support Sensor Manufacturer list
*********************************************/
//#define RTS58XX_SP_MICRON
#define RTS58XX_SP_OV
//#define RTS58XX_SP_SETI
//#define RTS58XX_SP_HYNIX
//#define RTS58XX_SP_HIMAX
//#define RTS58XX_SP_GC
//#define RTS58XX_SP_SAMSUNG
//#define RTS58XX_SP_SONY
//#define RTS58XX_SP_RS
//#define RTS58XX_SP_TOSHIBA
//#define RTS58XX_SP_APTINA
//#define RTS58XX_SP_AVSONIC
//#define RTS58XX_SP_SOI
//#define RTS58XX_SP_SMARTSENS

/********************************************
		Support Sensor list
*********************************************/

#ifdef RTS58XX_SP_RS
//#define RTS58XX_SP_RS0551C
#define RTS58XX_SP_FIXP
#endif

#ifdef RTS58XX_SP_OV
//#define RTS58XX_SP_OV2710
#define RTS58XX_SP_OV2735
//#define RTS58XX_SP_OV9732
#endif

#ifdef RTS58XX_SP_HIMAX

#endif

#ifdef RTS58XX_SP_APTINA
//#define RTS58XX_SP_AR0331
#define RTS58XX_SP_AR0237
#endif
#ifdef RTS58XX_SP_SMARTSENS
#define RTS58XX_SP_SC2232
#endif

#define SENSOR_SUPPORT_NUM 24
// define sensor type: high nibble as manufacturer, low nibble as type number
#define SENSOR_MF_MASK	0xFF
#define UNKNOWN_MF		0x00
#define OMNIVISION_MF	0x01
#define MICRON_MF		0x02
#define SAMSUNG_MF        0x03
#define MOBIEN_MF		0x04
#define PIXART_MF		0x05
#define SETI_MF			0x06
#define GALAXYCORE		0x07
#define HYNIX_MF		0x08
#define SONY_MF			0x09
#define HIMAX_MF		0x0A
#define TOSHIBA_MF		0x0B
#define NOVATEK_MF		0x0C
#define BYD_MF			0x0D
#define APTINA_MF		0x0E
//#define AVSONIC_MF		0x0F		// replace the manfacture define with SPECIAL_MF
#define FT2_MF               	0x10
#define SPECIAL_MF		0x15
// IPC new manfacture sensor definition start 0x20
#define SOI_MF			0x20
#define SMARTSENS_MF	0x21


#define SNR_D_TYPE_BAYER 0
#define SNR_D_TYPE_YCbCr  1



#define SENSOR_TYPE_MASK		0xFF
#define SENSOR_TYPE_UNKNOWN	0x00
#define SENSOR_TYPE_1			0x01
#define SENSOR_TYPE_2			0x02
#define SENSOR_TYPE_3			0x03
#define SENSOR_TYPE_4			0x04
#define SENSOR_TYPE_5			0x05
#define SENSOR_TYPE_6			0x06
#define SENSOR_TYPE_7			0x07
#define SENSOR_TYPE_8			0x08
#define SENSOR_TYPE_9			0x09
#define SENSOR_TYPE_10 			0x0A
#define SENSOR_TYPE_11 			0x0B
#define SENSOR_TYPE_12 			0x0C
#define SENSOR_TYPE_13 			0x0D
#define SENSOR_TYPE_14 			0x0E
#define SENSOR_TYPE_15 			0x0F
#define SENSOR_TYPE_16 			0x10
#define SENSOR_TYPE_17 			0x11
#define SENSOR_TYPE_18 			0x12
#define SENSOR_TYPE_19 			0x13
#define SENSOR_TYPE_20 			0x14
#define SENSOR_TYPE_21 			0x15
#define SENSOR_TYPE_22 			0x16
#define SENSOR_TYPE_23			0x17
#define SENSOR_TYPE_24 			0x18
#define SENSOR_TYPE_25 			0x19
#define SENSOR_TYPE_26 			0x1A
#define SENSOR_TYPE_27 			0x1B
#define SENSOR_TYPE_28			0x1C
#define SENSOR_TYPE_29 			0x1D
#define SENSOR_TYPE_30			0x1E
#define SENSOR_TYPE_31 			0x1F
#define SENSOR_TYPE_32 			0x20
#define SENSOR_TYPE_33 			0x21
#define SENSOR_TYPE_34			0x22
#define SENSOR_TYPE_35			0x23
#define SENSOR_TYPE_36			0x24
#define SENSOR_UNKNOWN	((UNKNOWN_MF<<8) |SENSOR_TYPE_UNKNOWN)
// AVSonic SOC sensor
#define SENSOR_AVSONICISPMODEL2	((SPECIAL_MF<<8) | SENSOR_TYPE_4)
// SOI Sensor
#define SENSOR_JXH42		((SOI_MF<<8) | SENSOR_TYPE_1)

// Omnivision sensor
#define SENSOR_OV2710		((OMNIVISION_MF<<8) | SENSOR_TYPE_10)
#define SENSOR_OV9732		((OMNIVISION_MF<<8) | SENSOR_TYPE_35)
#define SENSOR_OV2735		((OMNIVISION_MF<<8) | SENSOR_TYPE_36)

// Himax sensor

// Aptina sensor
#define SENSOR_AR0331		((APTINA_MF<<8) | SENSOR_TYPE_1)

//FT2 sensor model
#define SENSOR_RS0551C			(( FT2_MF<<8)|SENSOR_TYPE_4)
#define SENSOR_FIXP				(( FT2_MF<<8)|SENSOR_TYPE_5)

//smartsens sensor
#define SENSOR_SC2232   ((SMARTSENS_MF<<8)| SENSOR_TYPE_1)//Mark


// I2C ID address of sensor
#define MOBIEN_ID_ADDR		0x42
#define OMNIVISION_ID_ADDR0	0x42	// OV7725, OV7670,OV7690, OV7740
#define OMNIVISION_ID_ADDR1	0x60	//OV9663, OV9710,OV7690,OV2650
#define OMNIVISION_ID_ADDR2	0x20	//OV9726
#define OMNIVISION_ID_ADDR3	0x6C	//OV2710,OV5693
#define OMNIVISION_ID_ADDR4 	0x78    //OV5642 OV3642 OV3640
#define OMNIVISION_ID_ADDR5 	0x7A    //OV2735

#define MICRON_ID_ADDR_2020_1	0x78
#define MICRON_ID_ADDR_2020_2	0x7A
#define MICRON_ID_ADDR_1330_1	0x78      //add 20080927__jqg
#define MICRON_ID_ADDR_1330_2	0x7a
#define MICRON_ID_ADDR_1320_1	0x90
#define MICRON_ID_ADDR_1320_2	0xBA
#define MICRON_ID_ADDR_360	0x90
#define MICRON_ID_ADDR_1040_1	0x90
#define MICRON_ID_ADDR_1040_2 0xBA
#define MICRON_ID_ADDR_2340_1	0x90
#define MICRON_ID_ADDR_2340_2 0xBA
#define MICRON_ID_ADDR_3135_1	0x20
#define MICRON_ID_ADDR_3135_2 0x30
#define SAMSUNG_ID_ADDR		0x5A
#define SAMSUNG_ID_ADDR_6AA_78		0x78
#define SAMSUNG_ID_ADDR_6A1 	0x20
#define SAMSUNG_ID_ADDR_8AA 	0x20
#define TOSHIBA_ID_ADDR_T4K08 	0x78   //sensor ADRSEL pin connect to high->0x78,else->0x7A

#define SETI_ID_ADDR_1			0x66  //SETi SIV100B, SIV120B
#define SETI_ID_ADDR_2			0x6e  //SETi SID120B
#define SETI_ID_ADDR_3			0x6A  //SETi SIM120C

#define HYNIX_ID_ADDR1			0x60 //YACBAA0S, YACBAC1S
#define HYNIX_ID_ADDR2			0x40 //YACC5A2S, YACD5B1S,YACD6A1C
#define HYNIX_ID_ADDR3			0x4C //YACC611
#define HYNIX_ID_ADDR4			0x42 //YACY9A1

#define HIMAX_ID_ADDR1			0x48 //HM1055

#define SONY_ID_ADDR_IMX119PQH5 0x34//0x6C //0x6e
#define SONY_ID_ADDR_IMX188PQ 0x34
#define SONY_ID_ADDR_IMX132PQ 0x6C //0x6e
#define SONY_ID_ADDR_IMX236LQJC	0x34
#define SONY_ID_ADDR_IMX225 0x34 //0x6e//0x34

#define GALAXYCORE_ID_ADDR		0x42	//GC0307
#define GALAXYCORE_ID_ADDR2		0x6e	//GC2023
#define FT2_SENSOR_MODEL_ID_ADDR   0xf4 	//RTS0509 RTS0551C

#define APTINA_ID_ADDR1			0x20 //AR0331

#define SMARTSENS_ID_ADDR1		0x60
// sensor register page address
#define SAMSUNG_PAGE_SEL_ADDR0     0XEC
#define SAMSUNG_PAGE_SEL_ADDR1     0XFC
#define MICRON_PAGE_SEL_ADDR_1320	0xF0
#define MICRON_PAGE_SEL_ADDR_360	0x01
#define SETI_PAGE_SEL_ADDR	0x00
#define HYNIX_PAGE_SEL_ADDR	0x03
#define GC0307_PAGE_SEL_ADDR   0xF0

#endif //_DEVICE_H_
