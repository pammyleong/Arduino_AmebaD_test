#ifndef _ISP_H_
#define _ISP_H_

/**************************
**** ISP options***********
**************************/
// IQ Table
#define IQ_TABLE_START_ADDR	0x7000

//#define _LOWLIGHT_DYN_SATURATION_

#define _FRAME_RATE_CTL_ENABLE_

// others  isp
//#define _DECOLOR_TONE_ENABLE_
//#define _LENOVO_JAPAN_PROPERTY_PAGE_
#if (_CHIP_ID_ == _RLE0745_)
#define _ENABLE_MJPEG_
#endif
#define _USE_BK_SPECIAL_EFFECT_
#define _USE_BK_HSBC_ADJ_
//#define _MULTIPLE_LSC_CONFIG_

//#define _DARK_MODE_ENABLE_
#define _SMOOTH_DYNAMIC_CCM_
//#define _SMOOTH_DYNAMIC_GAMMA_
//#define _FIX_LOWLIGHT_LSC_

#ifdef _ENABLE_MJPEG_
#if (!(defined _IC_CODE_))
#define _JPEG_QTABLE_TUNE_
#endif
#endif

/**************************
**** ISP Test options******
**************************/
//#define _MANUAL_ET_GAIN_TEST_

//#define _OSD_TEST_
//#define _MASK_TEST_
//#define _MTD_TEST_

#endif

