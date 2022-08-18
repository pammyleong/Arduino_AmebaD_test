#ifndef _CUSXU_H_
#define _CUSXU_H_

/************control attributes************/
#define CTL_MIN_CT_EXPOSURE_TIME_ABSOLUTE     (1)	// unit:1/10k->us
#define CTL_MAX_CT_EXPOSURE_TIME_ABSOLUTE    (1000000)
#define CTL_RES_CT_EXPOSURE_TIME_ABSOLUTE     (1)
#define CTL_DEF_CT_EXPOSURE_TIME_ABSOLUTE     (10000)	// hemonel 2009-08-25: fix vista/7/xp show different value
#define  CTL_MIN_PU_LOWLIGHTCOMP  (0)
#define  CTL_MAX_PU_LOWLIGHTCOMP  (1)
#define  CTL_RES_PU_LOWLIGHTCOMP  (1)
#define  CTL_DEF_PU_LOWLIGHTCOMP  (1)
#define CTL_MIN_PU_WHITE_BALANCE_TEMPERATURE   (2800)
#define CTL_MAX_PU_WHITE_BALANCE_TEMPERATURE  (6500)
#define CTL_RES_PU_WHITE_BALANCE_TEMPERATURE   (10)
#define CTL_DEF_PU_WHITE_BALANCE_TEMPERATURE   (4600)	//heonel 2010-06-22 follow Dell V0.11  //(4650)
#define CTL_MIN_PU_WHITE_BALANCE_COMPONENT   (0x0000)
#define CTL_MAX_PU_WHITE_BALANCE_COMPONENT  (0x03ff)
#define CTL_RES_PU_WHITE_BALANCE_COMPONENT   (0x0001)
#define CTL_DEF_PU_WHITE_BALANCE_COMPONENT   (0x0100)
#define CTL_MIN_PU_WHITE_BALANCE_MODE_CONTROL   (0)
#define CTL_MAX_PU_WHITE_BALANCE_MODE_CONTROL  (2)
#define CTL_RES_PU_WHITE_BALANCE_MODE_CONTROL   (1)
#define CTL_DEF_PU_WHITE_BALANCE_MODE_CONTROL   (WB_AUTO_MODE)
#define CTL_MIN_PU_BRIGHTNESS   (-64)	// HP commercial
#define CTL_MAX_PU_BRIGHTNESS   (64)	// HP commercial
#define CTL_RES_PU_BRIGHTNESS   (1)
#define CTL_DEF_PU_BRIGHTNESS   (0)
//CONTRAST
#define  CTL_MIN_PU_CONTRAST    (0)
#define  CTL_MAX_PU_CONTRAST    (100) //heonel 2010-06-22 follow Dell V0.11  //(64)
#define  CTL_RES_PU_CONTRAST    (1)
#define  CTL_DEF_PU_CONTRAST    (50)	//heonel 2010-06-22 follow Dell V0.11  //(32)
//HUE
#define  CTL_MIN_PU_HUE    (-180)	//heonel 2010-06-22 follow Dell V0.11  //(-180)
#define  CTL_MAX_PU_HUE    (180)		//heonel 2010-06-22 follow Dell V0.11  //(180)
#define  CTL_RES_PU_HUE    (1)
#define  CTL_DEF_PU_HUE    (0)
//SATURATIONT
#define  CTL_MIN_PU_SATURATION  0
#define  CTL_MAX_PU_SATURATION  (100)	//heonel 2010-06-22 follow Dell V0.11  //(128) 	// HP commercial
#define  CTL_RES_PU_SATURATION  (1)
#define  CTL_DEF_PU_SATURATION  (64) 	// HP commercial

//SHARPNESS
#define  CTL_MIN_PU_SHARPNESS   (0)	//heonel 2010-06-22 follow Dell V0.11  //(0)
#define  CTL_MAX_PU_SHARPNESS   (100)	//heonel 2010-06-22 follow Dell V0.11  //(8)
#define  CTL_RES_PU_SHARPNESS   (1)
#define  CTL_DEF_PU_SHARPNESS   (50)	//heonel 2010-06-22 follow Dell V0.11  //(4)

/*
//Reck Add for Test (More Step for Sharpness)
#define  CTL_MIN_PU_SHARPNESS   (0)
#define  CTL_MAX_PU_SHARPNESS   (108)
#define  CTL_RES_PU_SHARPNESS   (1)
#define  CTL_DEF_PU_SHARPNESS   (30)
*/


//GAMMA
// hemonel 2008-03-04: change Gamma value
#define  CTL_MIN_PU_GAMMA       (100)   // 1.5
#define  CTL_MAX_PU_GAMMA       (500)	//heonel 2010-06-22 follow Dell V0.11  //(500)  // 2.2*2.2
#define  CTL_RES_PU_GAMMA       (1)
#define  CTL_DEF_PU_GAMMA       (300)	//heonel 2010-06-22 follow Dell V0.11  //(220)
//BACKLIGHTCOMP
#define  CTL_MIN_PU_BACKLIGHTCOMP  (0)
#define  CTL_MAX_PU_BACKLIGHTCOMP  (2)	//heonel 2010-06-22 follow Dell V0.11  //(1)
#define  CTL_RES_PU_BACKLIGHTCOMP  (1)
#ifdef _HW_HDR_ENABLE_
#define  CTL_DEF_PU_BACKLIGHTCOMP  (1)	//Reck 2010-08-23 BackLigjt Set to 0 //heonel 2010-06-22 follow Dell V0.11  //(0)
#else
#define  CTL_DEF_PU_BACKLIGHTCOMP  (0)	//Reck 2010-08-23 BackLigjt Set to 0 //heonel 2010-06-22 follow Dell V0.11  //(0)
#endif
//GAIN
#ifdef _MANUAL_ET_GAIN_TEST_
#define  CTL_MIN_PU_GAIN  (16)
#define  CTL_MAX_PU_GAIN  (255)
#else
#define  CTL_MIN_PU_GAIN  (0)
#define  CTL_MAX_PU_GAIN  (128)
#endif
#define  CTL_RES_PU_GAIN  (1)
#define  CTL_DEF_PU_GAIN  (64)
//PWR_LINE_FRQ
#define  CTL_MIN_PU_PWRLINEFRQ  (0)
#define  CTL_MAX_PU_PWRLINEFRQ  (3)
#define  CTL_RES_PU_PWRLINEFRQ  (1)
#define  CTL_DEF_PU_PWRLINEFRQ  (PWR_LINE_FRQ_50) //heonel 2010-06-22 follow Dell V0.11

//Pan
#define  CTL_MIN_PU_PAN  (-16)
#define  CTL_MAX_PU_PAN  (16)
#define  CTL_RES_PU_PAN  (1)
#define  CTL_DEF_PU_PAN  (0)

//Tilt
#define  CTL_MIN_PU_TILT  (-12)
#define  CTL_MAX_PU_TILT  (12)
#define  CTL_RES_PU_TILT  (1)
#define  CTL_DEF_PU_TILT  (0)

//Zoom
#define  CTL_MIN_PU_ZOOM  (0)
#define  CTL_MAX_PU_ZOOM  (3)
#define  CTL_RES_PU_ZOOM  (1)
#define  CTL_DEF_PU_ZOOM  (0)

// Roll
#define  CTL_MIN_PU_ROLL  (0)
#define  CTL_MAX_PU_ROLL  (3)
#define  CTL_RES_PU_ROLL  (1)
#define  CTL_DEF_PU_ROLL  (0)
//Focus Absoulte
#define CTL_MIN_CT_FOCUS_ABSOLUTE     (0)
#define CTL_MAX_CT_FOCUS_ABSOLUTE    (1023)
#define CTL_RES_CT_FOCUS_ABSOLUTE     (1)
#define CTL_DEF_CT_FOCUS_ABSOLUTE     (68)

// Focus Auto
#define CTL_MIN_CT_FOCUS_AUTO   (0)
#define CTL_MAX_CT_FOCUS_AUTO  (1)
#define CTL_RES_CT_FOCUS_AUTO   (1)
#define CTL_DEF_CT_FOCUS_AUTO   (1)

#define CTL_MAX_RTKEXT_SPECIALEFFECT		(ISP_SPECIAL_EFFECT_NORMAL		\
											|ISP_SPECIAL_EFFECT_MONOCHROME	\
											|ISP_SPECIAL_EFFECT_GRAY		\
											|ISP_SPECIAL_EFFECT_NEGATIVE	\
											|ISP_SPECIAL_EFFECT_SEPIA		\
											|ISP_SPECIAL_EFFECT_GREENISH	\
											|ISP_SPECIAL_EFFECT_REDDISH		\
											|ISP_SPECIAL_EFFECT_BLUISH)
#define CTL_DEF_RTKEXT_SPECIALEFFECT		(ISP_SPECIAL_EFFECT_NORMAL)

#define CTL_MIN_RTKEXT_EVCOMP				(-6)	// the max value should be divided by the resolution
#define CTL_MAX_RTKEXT_EVCOMP				(6)		// the min value should be divided by the resolution
#define CTL_RES_RTKEXT_EVCOMP				(EVCOMP_THIRDSTEP)
#define CTL_DEF_RTKEXT_EVCOMP				(0)

#define CTL_MIN_RTKEXT_ROIMODE			(0)
#define CTL_MAX_RTKEXT_ROIMODE			(1)
#define CTL_RES_RTKEXT_ROIMODE			(1)
#define CTL_DEF_RTKEXT_ROIMODE			(0)

#ifdef _EXT_ISO_ENABLE_
#define CTL_MIN_RTKEXT_ISO					(ISO_AUTO)
#define CTL_MAX_RTKEXT_ISO					(ISO_AUTO|ISO_50|ISO_80|ISO_100|ISO_200|ISO_400)
#define CTL_RES_RTKEXT_ISO					(1)
#define CTL_DEF_RTKEXT_ISO					(ISO_AUTO)
#endif

#ifdef _AF_ENABLE_
#define CTL_MAX_RTKEXT_ROI_AUTOFUNCTION		(ROI_AE_SUPPORT|ROI_AF_SUPPORT)
#else
#define CTL_MAX_RTKEXT_ROI_AUTOFUNCTION		(ROI_AE_SUPPORT)
#endif

#define CTL_MIN_RTKEXT_IQMODE			(0)
#define CTL_MAX_RTKEXT_IQMODE			(1)
#define CTL_RES_RTKEXT_IQMODE			(1)
#define CTL_DEF_RTKEXT_IQMODE			(IQ_AUTO_MODE)

#define CTL_MIN_RTKEXT_IQPARAMETER		(0)
#define CTL_MAX_RTKEXT_IQPARAMETER		(IQ_TEXTURE_PARAM_GROUPS-1)
#define CTL_RES_RTKEXT_IQPARAMETER		(1)
#define CTL_DEF_RTKEXT_IQPARAMETER		(0)

#define CTL_MIN_RTKEXT_GAIN		(0x100)
#define CTL_MAX_RTKEXT_GAIN		(0xffff)
#define CTL_RES_RTKEXT_GAIN		(1)
#define CTL_DEF_RTKEXT_GAIN		(0x100)


#define DESC_SIZE_DEV       18
//#define USB_DEVICE_DESCRIPTOR_TYPE                0x01



#endif
