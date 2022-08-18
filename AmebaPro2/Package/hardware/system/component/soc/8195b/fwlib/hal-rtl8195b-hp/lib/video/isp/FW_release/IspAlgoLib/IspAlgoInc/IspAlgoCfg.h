#ifndef _ISPALGO_H_
#define _ISPALGO_H_

#define _ISP_5_0_	0x01	// bit 0
#define _ISP_5_1_	0x02	// bit 1
#define _ISP_5_1_T_	0x04	// bit 2
#define _ISP_6_0_   0x08    // bit 3

#define _ISP_VERSION_	_ISP_5_1_

#define _IQ_TABLE_ADD_GBGRBALANCE_TEXTURE_
#ifdef _IQ_TABLE_ADD_GBGRBALANCE_TEXTURE_
#define IQ_TABLE_OFFSET_INCREASE 3
#else
#define IQ_TABLE_OFFSET_INCREASE 0
#endif

// HW HDR
#define _HW_HDR_ENABLE_
//#define _HW_HDR_level120_LSC_
//#define _HDR_FACE_JUDGE_
//#define _HDR_OUTDOOR_WINDOWS_DYN_YGAIN_
#define _HDR_TEST_
//////////////////////////////
//Select ONE project
//#define PROJECT_CS15
#define PROJECT_YOGA
//#define PROJECT_CNFFH10
//////////////////////////////

// AE
//#define _DISCRATE_FRAME_RATE_ 	// use discrate frame rate control, like 7.5, 15, 30
//#define _FACIAL_EXPOSURE_	// enable face detection for Lenovo
//#define _FACIALAEWINSET_XU_
//#define _AE_WINYMEAN_SORTING_
#ifndef _HW_HDR_ENABLE_
#define _AE_NEW_SPEED_ENABLE_
#endif
//#define _AE_ST_WIN_CROP_
//#define _MAX_ETGAIN_ENABLE_
#define _BACKLIT_DYN_AE_WEIGHT_
#define _NEW_AE_HIGHLIGHT_EXIT_MODE_

//AWB
//#define _AWB_SAMEBLOCK_
//#define _AWB_6_0_
#ifdef _AWB_6_0_
#define _AWB_SATURATION_BOUNDARY_
#define _AWB_STABLE_WHITEPOINT_
#define _AWB_DECOLORBLOCK_
#endif

//AF
//#define _AF_ENABLE_
#ifdef _AF_ENABLE_
//#define _AF_4BYTE_OPERATION_
//#define _AF_5_0_
#endif

// Scene Detect
//#define _SCENE_DETECTION_
#ifdef _SCENE_DETECTION_
//#define _SCENE_CHANGE_AE_BOUNDARY_
#endif

//#define _ENABLE_OUTDOOR_DETECT_
#ifdef _ENABLE_OUTDOOR_DETECT_
//#define _OUTDOOR_AWB_BOUNDARY_
//#define _OUTDOOR_CCM_
#endif

//AB
#define _ENABLE_ANTI_FLICK_
#ifdef _ENABLE_ANTI_FLICK_
#define _STATIC_FLICK_DETECT_
//#define _FLICK_DETECT_FPS_THRESHOLD_
#define _DEFENT_OBJECT_MOVEMENT_
//#define _FLICK_DETECT_GAIN_THRESHOLD_
#endif

#if (_CHIP_ID_ == _RTL8195B_)
#define _DEHAZE_ENABLE_
#endif

#define _UVC_REALTEK_EXTENDEDUNIT_
#ifdef _UVC_REALTEK_EXTENDEDUNIT_
//#define _FLASH_LED_ENABLE_
//#define _EXT_ISO_ENABLE_
//#define _SCENE_MODE_			//Must Enable AF and Extendedunit to make SCENE MODE work
#endif

/**********************************************************
**** ISP Verison Control for vendor command to report to RealCam********
**********************************************************/
#define _ISP_AE_VER_		0x000400	// AE Verison4.0
#ifdef _AWB_6_0_
#define _ISP_AWB_VER_		0x000600		// AWB Verison6.0
#else
#define _ISP_AWB_VER_		0x000400	// AWB Verison4.0
#endif
#ifdef _AF_5_0_
#define _ISP_AF_VER_			0x000500		// AF Verison5.0
#else
#define _ISP_AF_VER_		0x000400	// AF Verison4.0
#endif

/**************************
**** ISP Test options******
**************************/
//#define _AUTOBANDING_FFT_TEST_
#ifdef _AF_ENABLE_
//#define _AF_TEST_
#endif
//#define _AE_KEEP_LAST_MODE_

#endif // _ISPALGO_H_

