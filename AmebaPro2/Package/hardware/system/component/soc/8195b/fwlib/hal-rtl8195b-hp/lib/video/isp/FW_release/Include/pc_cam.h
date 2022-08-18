#ifndef _PC_CAM_H_
#define _PC_CAM_H_


/**********************
******Mode option ******
**********************/
#define _IC_CODE_		// ASIC only

/***********************************
******Customer/Internal option ******
***********************************/
//#define _CUSTOMER_FW_

/**********************
******System options ****
**********************/
//#define _SENSOR_ESD_ISSUE_

/**********************
******IC option	 ******
**********************/
#define _MIPI_EXIST_
//#define _HISPI_EXIST_
//#define _LVDS_EXIST_

//#define _RGBIR_SENSOR_
#ifdef _RGBIR_SENSOR_
#define _RGBIR_4X4_
#define _IR_SUBSAMPLE_SIZE_
#endif

/*********************
 ***** SNR Power *****
 ********************/
//#define SDK_BEF_1V0	// default close it
#ifndef SDK_BEF_1V0
#define SNR_HAVE_PWRON_BEF
#endif

/*************************
******sub-Function option ****
**************************/

/**************************
**** Test options***********
**************************/

/**************************
**** debug options***********
**************************/


/****************************
**** VID/PID, FW_Version options*
****************************/
#define _RT_VID_L_      0xda
#define _RT_VID_H_      0x0b

// trunk FW version
#define	FW_TRK_RLS_VER	0x0361	// release version
#define	FW_TRK_RVN_VER	0x0310	// revision version
#define	FW_TRUNK_VERSION	(((U32)FW_TRK_RLS_VER<<16)|FW_TRK_RVN_VER)

// API Version
#define API_MAIN_VER	0x01
#define API_SUB_VER		0x05
#define API_VERSION	(((U16)API_MAIN_VER<<8)|API_SUB_VER)

/**************************
**** UART print debug options*******
**************************/
//#define _RS232_DEBUG_
//#define _ASSERT_ENABLE_
//#define _DEBUG_3A_USE_GPIO_

#ifdef _RS232_DEBUG_
#define RS232_TEST
#define FUNC_IN_OUT_MSG_ENABLE
#define LINE_RUN_MSG
#define DBG_MSG_ENABLE
#define DBG_sCache_MSG_ENABLE
#define CFG_MSG_ENABLE
#define DBG2_MSG_ENABLE
#define MSG_ENABLE
#define WARN_MSG_ENABLE
#define ERR_MSG_ENABLE
#define ISP_MSG_ENABLE
#define DBG_VD_MSG_ENABLE
#define FCALL_DBG_MSG_ENABLE
#define AE_MSG_ENABLE
#define AF_MSG_ENABLE
#define AWB_MSG_ENABLE
#define AB_MSG_ENABLE
#define EPE_MSG_ENABLE
#define DBG_SENSOR_MSG_ENABLE
#define DBG_OV7670_MSG_ENABLE
#define DBG_OV7690_MSG_ENABLE
#define MIPI_MSG_ENABLE
#define DBG_BOOT_ENABLE
#define DBG_MCU_SPDUP_ENABLE
#define MTD_MSG_ENABLE
#define HDR_MSG_ENABLE
#define BULK_MSG_ENABLE
#define GLOBALVAR_INIT_MSG_ENABLE
#define ISO_MSG_ENABLE
#define IDEAEYE_MSG_ENALBE
#define SNR_ENABLE
#define MJPG_TUNE_ENABLE
#define DBG_CPU_CMD
#define IMX225_MSG_ENABLE
#define DEHAZE_MSG_ENABLE
#define LDC_MSG_ENABLE
#define OSD_MSG_ENABLE
#endif
#endif
