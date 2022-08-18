#ifndef _CAMISPREG_H_
#define _CAMISPREG_H_

//////////////////////////////////////
//ISP registers
//////////////////////////////////////

////////////////////////////////
///page0 ISP System Control Registers
#define	ISP_CONTROL1					0x8001
#define	ISP_CONTROL2					0x8002
#define	ISP_CONTROL3					0x8003
#define	ISP_INT_EN0					0x8006
#define	ISP_INT_FLAG0					0x8007
#define	ISP_INT_EN1					0x8008
//#define	ISP_INT_FLAG1					0x8009		// move to camreglib.h
#define	ISP_ABORT_CNT_L				0x800A
#define	ISP_ABORT_CNT_H				0x800B
#define	ISP_FT_WIDTH_L				0x800C  //frame width after blc window 12-bit
#define	ISP_FT_WIDTH_H				0x800D
#define	ISP_FT_HEIGHT_L				0x800E
#define	ISP_FT_HEIGHT_H				0x800F
#define	ISP_FRAME_IDLE					0x801D
#define	ISP_DPC_SPEED_CTRL			0x801E
#define	ISP_INTP_SPEED_CTRL			0x801F
#define	ISP_EEH_SPEED_CTRL			0x8020
#define	ISP_ZOOM_SPEED_CTRL			0x8021
#define	ISP_DPC_LAST_BREAK			0x8022
#define	ISP_INTP_LAST_BREAK			0x8023
#define	ISP_EEH_LAST_BREAK			0x8024
#define	ISP_ZOOM_LAST_BREAK			0x8025
#define ISP_LOW_DISABLE				0x8028
#define ISP_ABORT_ENABLE				0x8029
#define ISP_TEST_CTRL					0x802F
#define ISP_JPEG_CUT_ENABLE			0x8032
#define	ISP_AWB_STATIS_LOC			0x8034
#define ISP_INT_SEL0					0x8035
#define ISP_INT_SEL1					0x8036
#define SNR_FRM_CNT					0x8037
#define	ISP_IMAGE_SEL0				0x803A
#define	ISP_IMAGE_SEL1				0x803B
#define	ISP_IMAGE_SEL2				0x803C
#define ISP_IR_WIDTH_H 			0x8040
#define ISP_IR_WIDTH_L 			0x8041
#define ISP_IR_HEIGHT_H			0x8042
#define ISP_IR_HEIGHT_L			0x8043

#define ISP_YUV422_420_OSD_MODE		0x8050

//////////////////////////////////
//page1 Lens Shading Correction Registers
#define ISP_NLSC_CENTER_X_R_L			0x8100
#define ISP_NLSC_CENTER_X_R_H			0x8101
#define ISP_NLSC_CENTER_Y_R_L			0x8102
#define ISP_NLSC_CENTER_Y_R_H			0x8103
#define ISP_NLSC_DISTANCE_R_L			0x8104//distance between first pixel and center ,11bit
#define ISP_NLSC_DISTANCE_R_H			0x8105
#define ISP_NLSC_ERROR_R_L				0x8106
#define ISP_NLSC_ERROR_R_H			0x8107
#define ISP_NLSC_MODE					0x8108
//#define ISP_NLSC_R_ADJ_RATE			0x8109	// move to CamRegLib.h
//#define ISP_NLSC_G_ADJ_RATE			0x810A
//#define ISP_NLSC_B_ADJ_RATE			0x810B
//normal lsc  R curve from 0x810c~0x813b
#define ISP_NLSC_CURVE_R_BASE			0x810C
//normal lsc  R curve from 0x813c~0x816b
#define ISP_NLSC_CURVE_G_BASE			0x813C
//normal lsc  R curve from 0x816c~0x819b
#define ISP_NLSC_CURVE_B_BASE			0x816C
#define	ISP_MICRO_LSC_PARA_0			0x81A0
#define	ISP_MICRO_LSC_PARA_1			0x81A1
#define	ISP_MICRO_LSC_PARA_2			0x81A2
#define	ISP_MICRO_LSC_PARA_3			0x81A3
#define	ISP_MICRO_LSC_CTRL			0x81A5
#define ISP_MICRO_LSC_ADDR_H			0x81A6
#define	ISP_MICRO_LSC_ADDR_L			0x81A7
#define ISP_NLSC_CENTER_X_G_L			0x81B0
#define ISP_NLSC_CENTER_X_G_H			0x81B1
#define ISP_NLSC_CENTER_Y_G_L			0x81B2
#define ISP_NLSC_CENTER_Y_G_H			0x81B3
#define ISP_NLSC_DISTANCE_G_L			0x81B4//distance between first pixel and center ,11bit
#define ISP_NLSC_DISTANCE_G_H			0x81B5
#define ISP_NLSC_ERROR_G_L				0x81B6
#define ISP_NLSC_ERROR_G_H			0x81B7
#define ISP_NLSC_CENTER_X_B_L			0x81B8
#define ISP_NLSC_CENTER_X_B_H			0x81B9
#define ISP_NLSC_CENTER_Y_B_L			0x81BA
#define ISP_NLSC_CENTER_Y_B_H			0x81BB
#define ISP_NLSC_DISTANCE_B_L			0x81BC//distance between first pixel and center ,11bit
#define ISP_NLSC_DISTANCE_B_H			0x81BD
#define ISP_NLSC_ERROR_B_L				0x81BE
#define ISP_NLSC_ERROR_B_H			0x81BF
#define ISP_NLSC_GAIN_STEP_R 			0x81c0
#define ISP_NLSC_GAIN_STEP_G			0x81c1
#define ISP_NLSC_GAIN_STEP_B 			0x81c2
#define ISP_NLSC_GAIN_CTRL  			0x81c3

#define ISP_NLSC_IR_ADJ_RATE	        0x81C6//Reg 81c6 bit 5:0
#define ISP_NLSC_GAIN_STEP_IR	        0x81C7//Reg 81c7 bit 4:0
#define ISP_NLSC_CENTER_X_IR_L	        0x81C8//Reg 81c8
#define ISP_NLSC_CENTER_X_IR_H	        0x81C9//Reg 81c9 bit 3:0
#define ISP_NLSC_CENTER_Y_IR_L	        0x81CA//Reg 81ca
#define ISP_NLSC_CENTER_Y_IR_H	        0x81CB//Reg 81cb bit 3:0
#define ISP_NLSC_DISTANCE_IR_L	        0x81CC//Reg 81cc
#define ISP_NLSC_DISTANCE_IR_H	        0x81CD//Reg 81cd bit 3:0
#define ISP_NLSC_ERROR_IR_L	            0x81CE //Reg 81ce
#define ISP_NLSC_ERROR_IR_H	        	0x81CF //Reg 81cf bit 5:0
	
#define ISP_NLSC_CURVE_IR_BASE	        0x81D0//Reg 81d0
#define ISP_NLSC_CURVE_IR_P0_L	        0x81D0//Reg 81d0
#define ISP_NLSC_CURVE_IR_P0_H	        0x81D1//Reg 81d1
#define ISP_NLSC_CURVE_IR_P1_L	        0x81D2//Reg 81d2
#define ISP_NLSC_CURVE_IR_P1_H	        0x81D3//Reg 81d3
#define ISP_NLSC_CURVE_IR_P2_L	        0x81D4//Reg 81d4
#define ISP_NLSC_CURVE_IR_P2_H	        0x81D5//Reg 81d5
#define ISP_NLSC_CURVE_IR_P3_L	        0x81D6//Reg 81d6
#define ISP_NLSC_CURVE_IR_P3_H	        0x81D7//Reg 81d7
#define ISP_NLSC_CURVE_IR_P4_L	        0x81D8//Reg 81d8
#define ISP_NLSC_CURVE_IR_P4_H	        0x81D9//Reg 81d9
#define ISP_NLSC_CURVE_IR_P5_L	        0x81DA//Reg 81da
#define ISP_NLSC_CURVE_IR_P5_H	        0x81DB//Reg 81db
#define ISP_NLSC_CURVE_IR_P6_L	        0x81DC//Reg 81dc
#define ISP_NLSC_CURVE_IR_P6_H	        0x81DD//Reg 81dd
#define ISP_NLSC_CURVE_IR_P7_L	        0x81DE//Reg 81de
#define ISP_NLSC_CURVE_IR_P7_H	        0x81DF//Reg 81df
#define ISP_NLSC_CURVE_IR_P8_L	        0x81E0//Reg 81e0
#define ISP_NLSC_CURVE_IR_P8_H	        0x81E1//Reg 81e1
#define ISP_NLSC_CURVE_IR_P9_L	        0x81E2//Reg 81e2
#define ISP_NLSC_CURVE_IR_P9_H	        0x81E3//Reg 81e3
#define ISP_NLSC_CURVE_IR_PA_L	        0x81E4//Reg 81e4
#define ISP_NLSC_CURVE_IR_PA_H	        0x81E5//Reg 81e5
#define ISP_NLSC_CURVE_IR_PB_L	        0x81E6//Reg 81e6
#define ISP_NLSC_CURVE_IR_PB_H	        0x81E7//Reg 81e7
#define ISP_NLSC_CURVE_IR_PC_L	        0x81E8//Reg 81e8
#define ISP_NLSC_CURVE_IR_PC_H	        0x81E9//Reg 81e9
#define ISP_NLSC_CURVE_IR_PD_L	        0x81EA//Reg 81ea
#define ISP_NLSC_CURVE_IR_PD_H	        0x81EB//Reg 81eb
#define ISP_NLSC_CURVE_IR_PE_L	        0x81EC//Reg 81ec
#define ISP_NLSC_CURVE_IR_PE_H	        0x81ED//Reg 81ed
#define ISP_NLSC_CURVE_IR_PF_L	        0x81EE//Reg 81ee
#define ISP_NLSC_CURVE_IR_PF_H	        0x81EF//Reg 81ef
#define ISP_NLSC_CURVE_IR_PG_L	        0x81F0//Reg 81f0
#define ISP_NLSC_CURVE_IR_PG_H	        0x81F1//Reg 81f1
#define ISP_NLSC_CURVE_IR_PH_L	        0x81F2//Reg 81f2
#define ISP_NLSC_CURVE_IR_PH_H	        0x81F3//Reg 81f3
#define ISP_NLSC_CURVE_IR_PI_L	        0x81F4//Reg 81f4
#define ISP_NLSC_CURVE_IR_PI_H	        0x81F5//Reg 81f5
#define ISP_NLSC_CURVE_IR_PJ_L	        0x81F6//Reg 81f6
#define ISP_NLSC_CURVE_IR_PJ_H	        0x81F7//Reg 81f7
#define ISP_NLSC_CURVE_IR_PK_L	        0x81F8//Reg 81f8
#define ISP_NLSC_CURVE_IR_PK_H	        0x81F9//Reg 81f9
#define ISP_NLSC_CURVE_IR_PL_L	        0x81FA//Reg 81fa
#define ISP_NLSC_CURVE_IR_PL_H	        0x81FB//Reg 81fb
#define ISP_NLSC_CURVE_IR_PM_L	        0x81FC//Reg 81fc
#define ISP_NLSC_CURVE_IR_PM_H	  		0x81FD//Reg 81fd
#define ISP_NLSC_CURVE_IR_PN_L	        0x81FE//Reg 81fe
#define ISP_NLSC_CURVE_IR_PN_H	        0x81FF//Reg 81ff
/////////////////////////////
///Page3 : color & brightness on raw/RGB domain
#define	ISP_BLC_START_X_L				0x8300
#define	ISP_BLC_START_X_H				0x8301
#define	ISP_BLC_START_Y_L				0x8302
#define	ISP_BLC_START_Y_H				0x8303
#define	ISP_BLC_OFFSET_GR				0x8304
#define	ISP_BLC_GAIN_GR				0x8305
#define	ISP_BLC_OFFSET_R				0x8306
#define	ISP_BLC_GAIN_R					0x8307
#define	ISP_BLC_OFFSET_B				0x8308
#define	ISP_BLC_GAIN_B					0x8309
#define	ISP_BLC_OFFSET_GB				0x830A
#define	ISP_BLC_GAIN_GB 				0x830B

#define	ISP_CCM_PARA_ADDR_BASE		0x8320
#define	ISP_CCM_R_AFFECT_R_H			0x8320
#define	ISP_CCM_R_AFFECT_R_L			0x8321
#define	ISP_CCM_G_AFFECT_R_H			0x8322
#define	ISP_CCM_G_AFFECT_R_L			0x8323
#define	ISP_CCM_B_AFFECT_R_H			0x8324
#define	ISP_CCM_B_AFFECT_R_L			0x8325
#define	ISP_CCM_R_AFFECT_G_H			0x8326
#define	ISP_CCM_R_AFFECT_G_L			0x8327
#define	ISP_CCM_G_AFFECT_G_H			0x8328
#define	ISP_CCM_G_AFFECT_G_L			0x8329
#define	ISP_CCM_B_AFFECT_G_H			0x832A
#define	ISP_CCM_B_AFFECT_G_L			0x832B
#define	ISP_CCM_R_AFFECT_B_H			0x832C
#define	ISP_CCM_R_AFFECT_B_L			0x832D
#define	ISP_CCM_G_AFFECT_B_H			0x832E
#define	ISP_CCM_G_AFFECT_B_L			0x832F
#define	ISP_CCM_B_AFFECT_B_H			0x8330
#define	ISP_CCM_B_AFFECT_B_L			0x8331
#define	ISP_CCM_SYNC					0x8335

#define	ISP_BRIGHTNESS					0x8338

#define	ISP_GAMMA_ADDR_BASE			0x8340 //0x8340~0x8357
#define	ISP_GAMMA_ADDR_P0			0x8340
#define	ISP_GAMMA_ADDR_P1			0x8341
#define	ISP_GAMMA_ADDR_P2			0x8342
#define	ISP_GAMMA_ADDR_P3			0x8343
#define	ISP_GAMMA_ADDR_P4			0x8344
#define	ISP_GAMMA_ADDR_P5			0x8345
#define	ISP_GAMMA_ADDR_P6			0x8346
#define	ISP_GAMMA_ADDR_P7			0x8347
#define	ISP_GAMMA_ADDR_P8			0x8348
#define	ISP_GAMMA_ADDR_P9			0x8349
#define	ISP_GAMMA_ADDR_PA			0x834A
#define	ISP_GAMMA_ADDR_PB			0x834B
#define	ISP_GAMMA_ADDR_PC			0x834C
#define	ISP_GAMMA_ADDR_PD			0x834D
#define	ISP_GAMMA_ADDR_PE			0x834E
#define	ISP_GAMMA_ADDR_PF			0x834F
#define	ISP_GAMMA_ADDR_PG			0x8350
#define	ISP_GAMMA_ADDR_PH			0x8351
#define	ISP_GAMMA_ADDR_PI			0x8352
#define	ISP_GAMMA_ADDR_PJ			0x8353
#define	ISP_GAMMA_ADDR_PK			0x8354
#define	ISP_GAMMA_ADDR_PL			0x8355
#define	ISP_GAMMA_ADDR_PM			0x8356
#define	ISP_GAMMA_ADDR_PN			0x8357
#define	ISP_GAMMA_ADDR_PO			0x8358
#define	ISP_GAMMA_ADDR_PP			0x8359
#define	ISP_GAMMA_ADDR_PQ			0x835A
#define	ISP_GAMMA_ADDR_PR			0x835B
#define	ISP_GAMMA_SYNC				0x835D

#define	ISP_NLC_G_PARAMETER			0x83C0
#define	ISP_NLC_R_PARAMETER			0x83d0
#define	ISP_NLC_B_PARAMETER			0x83E0
#define	ISP_NLC_SYNC	    				0x83f0
#define	ISP_NLC_SEL	        			0x83f1


//////////////////////////////
///Page4 : color &brightness on YUV domain
#define ISP_UVT_UCENTER1 				0x8410
#define ISP_UVT_VCENTER1 				0x8411
#define ISP_UVT_UINC1					0x8412
#define ISP_UVT_VINC1					0x8413
#define ISP_UVT_UCENTER2 				0x8414
#define ISP_UVT_VCENTER2 				0x8415
#define ISP_UVT_UINC2					0x8416
#define ISP_UVT_VINC2					0x8417
#define ISP_UVT_UCENTER 				0x8418
#define ISP_UVT_VCENTER 				0x8419
#define ISP_UVT_UINC 					0x841A
#define ISP_UVT_VINC 					0x841B

//#define ISP_HUE_SIN_X					0x841C	// move to camreglib.h
//#define ISP_HUE_COS_X					0x841D
//#define ISP_HUE_SIN_Y					0x841E
//#define ISP_HUE_COS_Y					0x841F

#define	ISP_MONO_MEAN 				0x8420
#define	ISP_SPECIAL_TARGET_U			0x8421
#define	ISP_SPECIAL_TARGET_V			0x8422
#define	ISP_SPECIAL_TUNE				0x8423
#define	ISP_CONTRAST_MEAN			0x8424
//#define ISP_CONTRAST					0x8425	// move to camreglib.h
#define	ISP_YMODE						0x8426
//#define ISP_Y_OFFSET					0x8427	// move to camreglib.h
//#define ISP_Y_GAIN						0x8428	// move to camreglib.h
#define	ISP_U_OFFSET					0x8429
//#define ISP_U_GAIN						0x842A	// move to camreglib.h
#define	ISP_V_OFFSET					0x842B
//#define ISP_V_GAIN						0x842C	// move to camreglib.h

//#define ISP_YGAMMA_P0					0x8430	// move to camreglib.h
//#define ISP_YGAMMA_P1					0x8431
//#define ISP_YGAMMA_P2					0x8432
//#define ISP_YGAMMA_P3					0x8433
//#define ISP_YGAMMA_P4					0x8434
//#define ISP_YGAMMA_P5					0x8435
//#define ISP_YGAMMA_P6					0x8436
//#define ISP_YGAMMA_P7					0x8437
//#define ISP_YGAMMA_P8					0x8438
//#define ISP_YGAMMA_P9					0x8439
//#define ISP_YGAMMA_PA					0x843A
//#define ISP_YGAMMA_PB					0x843B
//#define ISP_YGAMMA_PC					0x843C
//#define ISP_YGAMMA_PD					0x843D
//#define ISP_YGAMMA_PE					0x843E
//#define ISP_YGAMMA_PF					0x843F
//#define ISP_YGAMMA_SYNC				0x8440

#define	ISP_RGB2YUV_YR      				0x8450
#define	ISP_RGB2YUV_YG    			  	0x8451
#define	ISP_RGB2YUV_YB      				0x8452
#define	ISP_RGB2YUV_UR      				0x8453
#define	ISP_RGB2YUV_UG      				0x8454
#define	ISP_RGB2YUV_UB      				0x8455
#define	ISP_RGB2YUV_VR      				0x8456
#define	ISP_RGB2YUV_VG      				0x8457
#define	ISP_RGB2YUV_VB      				0x8458
#define	ISP_RGB2YUV_YOFFSET 			0x8459
#define	ISP_RGB2YUV_DITHER_RATE 			0x845a

#define ISP_INTP_EDGE_THD		    0x8460
#define ISP_INTP_DCT_B				0x8461
#define ISP_INTP_DCT_K1                      0x8462
#define ISP_INTP_DCT_K2                      0x8463
#define ISP_INTP_RGB_AFFECT                 0x8464
#define ISP_INTP_GRGB_DIFF                  0x8465
#define ISP_INTP_SHARP_LPF_CTRL             0x8466
#define ISP_INTP_FCRD_EDGE                  0x8467
#define ISP_INTP_FCRD_SMOOTH                0x8468
#define ISP_MOIRE_G_AFFECT                   0x8469
#define ISP_MOIRE_CTRL                       0x846A
#define ISP_MOIRE_MAX                        0x846B
#define ISP_MOIRE_RATE_R                     0x846C
#define ISP_MOIRE_RATE_B                     0x846D
#define ISP_MOIRE_NUM_R_L                    0x846E
#define ISP_MOIRE_NUM_R_H                    0x846F
#define ISP_MOIRE_NUM_G_L                    0x8470
#define ISP_MOIRE_NUM_G_H                    0x8471
#define ISP_MOIRE_NUM_B_L                    0x8472
#define ISP_MOIRE_NUM_B_H                    0x8473
#define ISP_MOIRE_SUM_R_L                    0x8474
#define ISP_MOIRE_SUM_R_M                    0x8475
#define ISP_MOIRE_SUM_R_H                    0x8476
#define ISP_MOIRE_SUM_G_L                    0x8477
#define ISP_MOIRE_SUM_G_M                    0x8478
#define ISP_MOIRE_SUM_G_H                    0x8479
#define ISP_MOIRE_SUM_B_L                    0x847A
#define ISP_MOIRE_SUM_B_M                    0x847B
#define ISP_MOIRE_SUM_B_H                    0x847C
#define ISP_INTP_EDGE_SMOOTH                 0x847D
#define ISP_ILOC_MAX                         0x847E
#define ISP_ILOC_RATE                        0x847F
#define ISP_INTP_SMOOTH_AREA_DCT_PRI_EN      0x8480
#define ISP_INTP_LPF_SEL                    0x8481
#define ISP_INTP_RGB_AFFECT_2                0x8482
#define ISP_INTP_BLEND                       0x8483
#define ISP_INTP_EDGE_DRAW_EN                0x8484
#define ISP_INTP_SMOOTH_IR                   0x8485
#define ISP_INTP_IR_AFFECT_R                 0x8486
#define ISP_INTP_IR_AFFECT_G                 0x8487
#define ISP_INTP_IR_AFFECT_B                 0x8488
#define ISP_INTP_IRC_CTRL                    0x8489
#define ISP_INTP_IR_OFFSET_R                 0x848A
#define ISP_INTP_IR_OFFSET_G                 0x848B
#define ISP_INTP_IR_OFFSET_B                 0x848C
#define ISP_INTP_R_AFFECT_IR                 0x848D
#define ISP_INTP_G_AFFECT_IR                 0x848E
#define ISP_INTP_B_AFFECT_IR                 0x848F
#define ISP_INTP_IR_OFFSET_MAX               0x8490
#define ISP_Y_AFFECT_IR                      0x8491
#define ISP_IR_OFFSET_Y                      0x8492
#define ISP_INTP_IRC_SYNC                    0x8493
#define ISP_INTP_R_IR_BLEND_RATE             0x8494
#define ISP_INTP_G_IR_BLEND_RATE             0x8495
#define ISP_INTP_B_IR_BLEND_RATE             0x8496
#define ISP_INTP_IR_DEBUG_CTRL               0x8497
#define ISP_INTP_R_GAIN                      0x8498
#define ISP_INTP_G_GAIN                      0x8499
#define ISP_INTP_B_GAIN                      0x849a
#define ISP_INTP_IR_GAIN                     0x849b
#define ISP_INTP_CHANNEL_GAIN_CTRL           0x849c
#define ISP_INTP_IR_EDGE                     0x849f



//////////////////////////////////
//page5 NR & INTERPOLATION & IIR & EDGE_ENHANCE
#define ISP_RDLOC_DIST_START_L		0x8500
#define ISP_RDLOC_DIST_START_H		0x8501
#define ISP_RDLOC_DIST_END_L			0x8502
#define ISP_RDLOC_DIST_END_H			0x8503
#define ISP_RDLOC_MAX					0x8504
#define ISP_RDLOC_RATE				0x8505
#define ISP_RDLOC_ENABLE				0x8506
#define ISP_GLOC_MAX					0x8507
#define ISP_GLOC_RATE					0x8508
#define ISP_GLOC_ENABLE				0x8509
#define ISP_RD_MM2_RATE				0x850A
#define ISP_DDP_SEL					0x850B
#define ISP_NR_MODE0_LPF				0x850C
#define ISP_NR_MODE1_LPF				0x850D
#define ISP_NR_COLOR_ENABLE_CTRL		0x850E
#define ISP_NR_COLOR_MAX				0x850F

#define ISP_DDP_CTRL					0x8510
#define ISP_DP_THD_D1					0x8511
#define ISP_DP_BRIGHT_THD_MIN		0x8512
#define ISP_DP_BRIGHT_THD_MAX		0x8513
#define	ISP_DP_DARK_THD_MIN			0x8514
#define	ISP_DP_DARK_THD_MAX			0x8515
#define ISP_DDP_BRIGHT_RATE			0x8517
#define ISP_DDP_DARK_RATE				0x8519
#define ISP_NR_EDGE_THD				0x851A
#define ISP_NR_MM_THD1					0x851D
#define ISP_NR_MODE_IR					0x851e
#define ISP_NR_MODE						0x851F
#define ISP_NR_GRGB_CTRL				0x8520

#define ISP_IR_EDGE_THD					0x8521

#define ISP_NR_GRGB_BLNC_K				0x8522
#define ISP_NR_GRGB_BLNC_D0				0x8523
#define ISP_NR_GRGB_BLNC_D1				0x8524
#define ISP_NR_CHAOS_MAX				0x8525
#define ISP_NR_CHAOS_THD				0x8526
#define ISP_NR_CHAOS_CFG				0x8527

#define ISP_NR_MMM_ENABLE			0x852A
#define ISP_NR_MMM_D0					0x852B
#define ISP_NR_MMM_D1					0x852C
#define ISP_NR_MMM_RATE				0x852D
#define ISP_NR_MMM_MIN				0x852E
#define ISP_NR_MMM_MAX				0x852F

#define	ISP_DP_GROUP_SQUARE	0x8530
#define	ISP_NR_SH_EDGE_LPF  0x8531
#define	ISP_NR_SH_EDGE_K    0x8532
#define	ISP_NR_SH_EDGE_B    0x8533
#define	ISP_NR_SH_LPF_MAX   0x8534
#define	ISP_USM             0x8535
#define	ISP_USM_MODE_LPF    0x8536
#define	ISP_USM_MIN_MAX     0x8537
#define	ISP_NR_EDGE_DRAW_EN 0x8538
#define	ISP_USM_IR          0x8539
#define	ISP_USM_MIN_MAX_IR  0x853A
#define	ISP_NR_MMM_D0_IR    0x853B
#define	ISP_NR_MMM_D1_IR    0x853C
#define	ISP_NR_MMM_RATE_IR  0x853D
#define	ISP_NR_MMM_MIN_IR   0x853E
#define	ISP_NR_MMM_MAX_IR   0x853F

#define ISP_RGB_IIR_CTRL 				0x8550
#define ISP_RGB_VIIR_G_COEF			0x8551
#define ISP_RGB_HLPF_G_COEF			0x8552
#define ISP_RGB_DIIR_MAX				0x8553
#define ISP_RGB_DIIR_COEF				0x8554
#define ISP_RGB_BRIGHT_COEF			0x8555
#define ISP_RGB_DIIR_COFF_CUT			0x8556
#define ISP_RGB_DIIR_CHANGE_THD0  		0x8557
#define ISP_RGB_DIIR_CHANGE_THD1  		0x8558
#define ISP_RGB_DIIR_CHANGE_THD2  		0x8559
#define ISP_RGB_DIIR_CHANGE_THD3  		0x855A
#define ISP_RGB_DIIR_CHANGE_THD4  		0x855B
#define ISP_RGB_VIIR_RB_COEF			0x855C
#define ISP_RGB_HLPF_RB_COEF			0x855D

#define ISP_EDG_DIFF_C0  				0x8560
#define ISP_EDG_DIFF_C1  				0x8561
#define ISP_EDG_DIFF_C2  				0x8562
#define ISP_EDG_DIFF_C3  				0x8563
#define ISP_EDG_DIFF_C4  				0x8564
#define ISP_EDG_DCT_THD1				0x8565

#define ISP_EEH_DTHD_CFG				0x8569
#define ISP_EEH_UVIIR_Y_CUTS			0x856A
#define ISP_EEH_UVIIR_Y_CMIN			0x856B
#define ISP_EEH_IIR_COEF				0x856C
#define ISP_EEH_IIR_CUTS				0x856D
#define ISP_EEH_IIR_STEP				0x856E
#define ISP_EEH_IIR_ENABLE			0x856F
#define ISP_FCRD_MIN					0x8570
#define ISP_FCRD_YCUTS				0x8571
#define ISP_FCRD_CFG					0x8572
#define ISP_FCRD_MAX					0x8573
#define ISP_RELIEVO_BRIGHT			0x8574
#define ISP_SHARPNESS					0x8575


// Edge Enhance
#define ISP_EEH_INDEP_HV_EN  			0x85a0
#define ISP_EEH_INDEP_EDGE_K1 		0x85a1
#define ISP_EEH_INDEP_EDGE_B1 		0x85a2
#define ISP_EDG_DIFF_C5 				0x85a3
#define ISP_EDG_DIFF_C6 				0x85a4
#define ISP_EDG_DIFF_C7 				0x85a5
#define ISP_INDEP_SHARPV_EN 			0x85a6
#define ISP_SHARP_V 					0x85a7
#define ISP_EEH_SRC_SEL 				0x85a8

#define ISP_LOC_DIST_START_L			0x85b0
#define ISP_LOC_DIST_START_H			0x85b1
#define ISP_LOC_DIST_END_L			0x85b2
#define ISP_LOC_DIST_END_H			0x85b3
#define ISP_LOC_MAX					0x85b4
#define ISP_LOC_RATE					0x85b5
#define ISP_LOC_ENABLE					0x85b6

//..................
#define ISP_EEH_SHARP_ARRAY0			0x85E4
#define ISP_EEH_SHARP_ARRAY1			0x85E5
#define ISP_EEH_SHARP_ARRAY2			0x85E6
#define ISP_EEH_SHARP_ARRAY3			0x85E7
#define ISP_EEH_SHARP_ARRAY4			0x85E8
#define ISP_EEH_SHARP_ARRAY5			0x85E9
#define ISP_EEH_SHARP_ARRAY6			0x85EA
#define ISP_EEH_SHARP_ARRAY7			0x85EB
#define ISP_EEH_SHARP_ARRAY8			0x85EC
#define ISP_EEH_SHARP_ARRAY9			0x85ED
#define ISP_EEH_SHARP_ARRAY10		0x85EE
#define ISP_EEH_SHARP_ARRAY11		0x85EF
#define ISP_BRIGHT_TRM_B1				0x85F0
#define ISP_BRIGHT_TRM_B2				0x85F1
#define ISP_BRIGHT_TRM_THD0			0x85F2
#define ISP_BRIGHT_TRM_THD1			0x85F3
#define ISP_BRIGHT_TRM_K				0x85F4
#define ISP_DARK_TRM_B1				0x85F5
#define ISP_DARK_TRM_B2				0x85F6
#define ISP_DARK_TRM_THD0			0x85F7
#define ISP_DARK_TRM_THD1			0x85F8
#define ISP_DARK_TRM_K				0x85F9
#define ISP_BRIGHT_RATE				0x85FA
#define ISP_DARK_RATE					0x85FB


//////////////////////////////////
//Page6 JPEG
//#ifdef _ENABLE_MJPEG_
#define JENC_START	              			0x8680
#define JENC_CONFIGURE             			0x8681
#define JENC_IMAGESIZE_XL          		0x8682
#define JENC_IMAGESIZE_XH         		0x8683
#define JENC_IMAGESIZE_YL          		0x8684
#define JENC_IMAGESIZE_YH         		0x8685
#define JENC_MCUNUM_L              			0x8686
#define JENC_MCUNUM_H              			0x8687
#define JENC_RST_INTERVAL_L        		0x8688
#define JENC_RST_INTERVAL_H        		0x8689

#define JENC_COMPONENT0_L          		0x868A
#define JENC_COMPONENT0_H          		0x868B
#define JENC_COMPONENT1_L          		0x868C
#define JENC_COMPONENT1_H          		0x868D
#define JENC_COMPONENT2_L          		0x868E
#define JENC_COMPONENT2_H          		0x868F
#define JENC_COMPONENT3_L          		0x8690
#define JENC_COMPONENT3_H          		0x8691
#define JENC_FRAME_INTERVAL_L      		0x8692
#define JENC_FRAME_INTERVAL_H      		0x8693
#define JENC_QTABLE_ACCESS            		0x8694
#define JENC_QTABLE_ADDR                 	0x8695
#define JENC_QTABLE_DATA0                 	0x8696
#define JENC_QTABLE_DATA1				0x8697
#define JENC_QTABLE_DATA2                 	0x8698

#define JENC_MEM_OVERFLOW                 	0x8699// not used , zb
#define JENC_ACRA_RATE                 		0x869D
#define JENC_ACRA_INV_NORM_L               	0x86A0
#define JENC_ACRA_INV_NORM_H               0x86A1
//#endif //_ENABLE_MJPEG_

#define ISP_M420_CTRL					0x86A3
#define ISP_M420_INTERNAL_SPEED_CTL	0x86A4
#define ISP_M420_LASTROW_SPEED_CTL	0x86A5

#define ISP_ACRA_RATE_LOAD			0x86A7

#define JENC_FRAMEWIDTH_H 			0x86a8
#define JENC_FRAMEWIDTH_L 			0x86a9
#define JENC_FRAMEHEIGHT_H 			0x86aa
#define JENC_FRAMEHEIGHT_L 			0x86ab

//////////////////////////////////
//Page7 Clolor detect
#define ISP_COLOR_RATE      				0x8780
#define ISP_COLOR_UMIN0     			0x8781
#define ISP_COLOR_UMAX0     			0x8782
#define ISP_COLOR_VMIN0     			0x8783
#define ISP_COLOR_VMAX0     			0x8784
#define ISP_COLOR_UMIN1     			0x8785
#define ISP_COLOR_UMAX1     			0x8786
#define ISP_COLOR_VMIN1    	 			0x8787
#define ISP_COLOR_VMAX1     			0x8788
#define ISP_COLOR_UMIN2     			0x8789
#define ISP_COLOR_UMAX2     			0x878a
#define ISP_COLOR_VMIN2     			0x878b
#define ISP_COLOR_VMAX2     			0x878c
#define ISP_COLOR_UMIN3     			0x878d
#define ISP_COLOR_UMAX3     			0x878e
#define ISP_COLOR_VMIN3     			0x878f
#define ISP_COLOR_VMAX3     			0x8790
#define ISP_COLOR_UMIN4     			0x8791
#define ISP_COLOR_UMAX4     			0x8792
#define ISP_COLOR_VMIN4     			0x8793
#define ISP_COLOR_VMAX4     			0x8794
#define ISP_COLOR_UMIN5     			0x8795
#define ISP_COLOR_UMAX5     			0x8796
#define ISP_COLOR_VMIN5     			0x8797
#define ISP_COLOR_VMAX5     			0x8798
#define ISP_COLOR_CTRL      				0x8799

#define	ISP_COLOR_NUM0 				0x879c
#define	ISP_COLOR_NUM1 				0x87a0
#define	ISP_COLOR_NUM2 				0x87a4
#define	ISP_COLOR_NUM3 				0x87a8
#define	ISP_COLOR_NUM4 				0x87ac
#define	ISP_COLOR_NUM5 				0x87b0
#define	ISP_COLOR_YSUM 				0x87b4


//////////////////////////////////
//Page9 Motion Detect
#define MTD0_EN							0x8900
#define MTD0_SAMPLE					0x8901
#define MTD0_SAMPLE_FRAME				0x8902
#define MTD0_START_X_H					0x8903
#define MTD0_START_X_L					0x8904
#define MTD0_START_Y_H					0x8905
#define MTD0_START_Y_L					0x8906
#define MTD0_WIN_WIDTH_H				0x8907
#define MTD0_WIN_WIDTH_L				0x8908
#define MTD0_WIN_HEIGHT_H				0x8909
#define MTD0_WIN_HEIGHT_L				0x890A
#define MTD0_WINUM_X					0x890B
#define MTD0_WINUM_Y					0x890C
#define MTD0_THD_H						0x890D
#define MTD0_THD_M						0x890E
#define MTD0_THD_L						0x890F
#define MTD0_MOTION_NUM_H				0x8910
#define MTD0_MOTION_NUM_L				0x8911
#define MTD0_STILL_NUM_H				0x8912
#define MTD0_STILL_NUM_L				0x8913
#define MTD0_INT_SEL					0x8914
#define MTD0_INT_EN					0x8915
#define MTD0_INT_FLAG					0x8916

#define MTD1_EN							0x8920
#define MTD1_SAMPLE					0x8921
#define MTD1_SAMPLE_FRAME				0x8922
#define MTD1_START_X_H					0x8923
#define MTD1_START_X_L					0x8924
#define MTD1_START_Y_H					0x8925
#define MTD1_START_Y_L					0x8926
#define MTD1_WIN_WIDTH_H				0x8927
#define MTD1_WIN_WIDTH_L				0x8928
#define MTD1_WIN_HEIGHT_H				0x8929
#define MTD1_WIN_HEIGHT_L				0x892A
#define MTD1_WINUM_X					0x892B
#define MTD1_WINUM_Y					0x892C
#define MTD1_THD_H						0x892D
#define MTD1_THD_M						0x892E
#define MTD1_THD_L						0x892F
#define MTD1_MOTION_NUM_H				0x8930
#define MTD1_MOTION_NUM_L				0x8931
#define MTD1_STILL_NUM_H				0x8932
#define MTD1_STILL_NUM_L				0x8933
#define MTD1_INT_SEL					0x8934
#define MTD1_INT_EN					0x8935
#define MTD1_INT_FLAG					0x8936

#define MTD2_EN							0x8940
#define MTD2_SAMPLE					0x8941
#define MTD2_SAMPLE_FRAME				0x8942
#define MTD2_START_X_H					0x8943
#define MTD2_START_X_L					0x8944
#define MTD2_START_Y_H					0x8945
#define MTD2_START_Y_L					0x8946
#define MTD2_WIN_WIDTH_H				0x8947
#define MTD2_WIN_WIDTH_L				0x8948
#define MTD2_WIN_HEIGHT_H				0x8949
#define MTD2_WIN_HEIGHT_L				0x894A
#define MTD2_WINUM_X					0x894B
#define MTD2_WINUM_Y					0x894C
#define MTD2_THD_H						0x894D
#define MTD2_THD_M						0x894E
#define MTD2_THD_L						0x894F
#define MTD2_MOTION_NUM_H				0x8950
#define MTD2_MOTION_NUM_L				0x8951
#define MTD2_STILL_NUM_H				0x8952
#define MTD2_STILL_NUM_L				0x8953
#define MTD2_INT_SEL					0x8954
#define MTD2_INT_EN					0x8955
#define MTD2_INT_FLAG					0x8956

#define MTD3_EN							0x8960
#define MTD3_SAMPLE					0x8961
#define MTD3_SAMPLE_FRAME				0x8962
#define MTD3_START_X_H					0x8963
#define MTD3_START_X_L					0x8964
#define MTD3_START_Y_H					0x8965
#define MTD3_START_Y_L					0x8966
#define MTD3_WIN_WIDTH_H				0x8967
#define MTD3_WIN_WIDTH_L				0x8968
#define MTD3_WIN_HEIGHT_H				0x8969
#define MTD3_WIN_HEIGHT_L				0x896A
#define MTD3_WINUM_X					0x896B
#define MTD3_WINUM_Y					0x896C
#define MTD3_THD_H						0x896D
#define MTD3_THD_M						0x896E
#define MTD3_THD_L						0x896F
#define MTD3_MOTION_NUM_H				0x8970
#define MTD3_MOTION_NUM_L				0x8971
#define MTD3_STILL_NUM_H				0x8972
#define MTD3_STILL_NUM_L				0x8973
#define MTD3_INT_SEL					0x8974
#define MTD3_INT_EN					0x8975
#define MTD3_INT_FLAG					0x8976

#define MTD4_EN							0x8980
#define MTD4_SAMPLE					0x8981
#define MTD4_SAMPLE_FRAME				0x8982
#define MTD4_START_X_H					0x8983
#define MTD4_START_X_L					0x8984
#define MTD4_START_Y_H					0x8985
#define MTD4_START_Y_L					0x8986
#define MTD4_WIN_WIDTH_H				0x8987
#define MTD4_WIN_WIDTH_L				0x8988
#define MTD4_WIN_HEIGHT_H				0x8989
#define MTD4_WIN_HEIGHT_L				0x898A
#define MTD4_WINUM_X					0x898B
#define MTD4_WINUM_Y					0x898C
#define MTD4_THD_H						0x898D
#define MTD4_THD_M						0x898E
#define MTD4_THD_L						0x898F
#define MTD4_MOTION_NUM_H				0x8990
#define MTD4_MOTION_NUM_L				0x8991
#define MTD4_STILL_NUM_H				0x8992
#define MTD4_STILL_NUM_L				0x8993
#define MTD4_INT_SEL					0x8994
#define MTD4_INT_EN					0x8995
#define MTD4_INT_FLAG					0x8996

#define MTD_FW_DATA_H					0x89A0
#define MTD_FW_DATA_M					0x89A1
#define MTD_FW_DATA_L					0x89A2
#define MTD_FW_ADDR_H					0x89A3
#define MTD_FW_ADDR_L					0x89A4
#define MTD_FW_WRITE					0x89A5
#define MTD_FW_READ					0x89A6
#define MTD_DATA_FMT					0x89A7
#define MTD_DATA_ELEMENT				0x89A8

#define ISP_FRC_EN						0x89C0
#define ISP_FRC_LVUP_VALUE_H			0x89C1
#define ISP_FRC_LVUP_VALUE_L			0x89C2
#define ISP_FRC_MOTION_EN				0x89C3
#define ISP_FRC_FORCE_LV0				0x89C4
#define ISP_FRC_DPFLV0_CH0			0x89C5
#define ISP_FRC_DPFLV1_CH0			0x89C6
#define ISP_FRC_DPFLV2_CH0			0x89C7
#define ISP_FRC_DPFLV0_CH1			0x89C8
#define ISP_FRC_DPFLV1_CH1			0x89C9
#define ISP_FRC_DPFLV2_CH1			0x89CA
#define ISP_FRC_DPFLV0_CH2			0x89CB
#define ISP_FRC_DPFLV1_CH2			0x89CC
#define ISP_FRC_DPFLV2_CH2			0x89CD
#define ISP_FRC_DPFLV0_CH3			0x89CE
#define ISP_FRC_DPFLV1_CH3			0x89CF
#define ISP_FRC_DPFLV2_CH3			0x89D0
#define ISP_FRC_DPFLV0_CH4			0x89D1
#define ISP_FRC_DPFLV1_CH4			0x89D2
#define ISP_FRC_DPFLV2_CH4			0x89D3

//////////////////////////////////
//Page10 Zoom
#define ISP_ZOOM_CH0_START_X_L		0x8A00
#define ISP_ZOOM_CH0_START_X_H		0x8A01
#define ISP_ZOOM_CH0_START_Y_L		0x8A02
#define ISP_ZOOM_CH0_START_Y_H		0x8A03
#define ISP_ZOOM_CH0_STEP_X_L		0x8A04
#define ISP_ZOOM_CH0_STEP_X_H		0x8A05
#define ISP_ZOOM_CH0_STEP_Y_L		0x8A06
#define ISP_ZOOM_CH0_STEP_Y_H		0x8A07
#define ISP_ZOOM_CH0_COEF0			0x8A08
#define ISP_ZOOM_CH0_COEF1			0x8A09
#define ISP_ZOOM_CH0_COEF2			0x8A0A
#define ISP_ZOOM_CH0_COEF3			0x8A0B
#define ISP_ZOOM_CH0_COEF4			0x8A0C
#define ISP_ZOOM_CH0_COEF5			0x8A0D
#define ISP_ZOOM_CH0_COEF6			0x8A0E
#define ISP_ZOOM_CH0_COEF7			0x8A0F
#define ISP_ZOOM_CH0_COEF8			0x8A10
#define ISP_ZOOM_CH0_COEF9			0x8A11
#define ISP_ZOOM_CH0_COEFA			0x8A12
#define ISP_ZOOM_CH0_COEFB			0x8A13
#define ISP_ZOOM_CH0_SYNC			0x8A15
#define ISP_ZOOM_CH0_BK_WIDTH_H		0x8A16
#define ISP_ZOOM_CH0_BK_WIDTH_L		0x8A17
#define ISP_ZOOM_CH0_BK_HEIGHT_H	0x8A18
#define ISP_ZOOM_CH0_BK_HEIGHT_L	0x8A19
#define ISP_ZOOM_CH0_EN				0x8A1A

#define ISP_ZOOM_CH1_START_X_L		0x8A20
#define ISP_ZOOM_CH1_START_X_H		0x8A21
#define ISP_ZOOM_CH1_START_Y_L		0x8A22
#define ISP_ZOOM_CH1_START_Y_H		0x8A23
#define ISP_ZOOM_CH1_STEP_X_L		0x8A24
#define ISP_ZOOM_CH1_STEP_X_H		0x8A25
#define ISP_ZOOM_CH1_STEP_Y_L		0x8A26
#define ISP_ZOOM_CH1_STEP_Y_H		0x8A27
#define ISP_ZOOM_CH1_COEF0			0x8A28
#define ISP_ZOOM_CH1_COEF1			0x8A29
#define ISP_ZOOM_CH1_COEF2			0x8A2A
#define ISP_ZOOM_CH1_COEF3			0x8A2B
#define ISP_ZOOM_CH1_COEF4			0x8A2C
#define ISP_ZOOM_CH1_COEF5			0x8A2D
#define ISP_ZOOM_CH1_COEF6			0x8A2E
#define ISP_ZOOM_CH1_COEF7			0x8A2F
#define ISP_ZOOM_CH1_COEF8			0x8A30
#define ISP_ZOOM_CH1_COEF9			0x8A31
#define ISP_ZOOM_CH1_COEFA			0x8A32
#define ISP_ZOOM_CH1_COEFB			0x8A33
#define ISP_ZOOM_CH1_SYNC			0x8A35
#define ISP_ZOOM_CH1_BK_WIDTH_H		0x8A36
#define ISP_ZOOM_CH1_BK_WIDTH_L		0x8A37
#define ISP_ZOOM_CH1_BK_HEIGHT_H	0x8A38
#define ISP_ZOOM_CH1_BK_HEIGHT_L	0x8A39
#define ISP_ZOOM_CH1_EN				0x8A3A

#define ISP_ZOOM_CH2_START_X_L		0x8A40
#define ISP_ZOOM_CH2_START_X_H		0x8A41
#define ISP_ZOOM_CH2_START_Y_L		0x8A42
#define ISP_ZOOM_CH2_START_Y_H		0x8A43
#define ISP_ZOOM_CH2_STEP_X_L		0x8A44
#define ISP_ZOOM_CH2_STEP_X_H		0x8A45
#define ISP_ZOOM_CH2_STEP_Y_L		0x8A46
#define ISP_ZOOM_CH2_STEP_Y_H		0x8A47
#define ISP_ZOOM_CH2_COEF0			0x8A48
#define ISP_ZOOM_CH2_COEF1			0x8A49
#define ISP_ZOOM_CH2_COEF2			0x8A4A
#define ISP_ZOOM_CH2_COEF3			0x8A4B
#define ISP_ZOOM_CH2_COEF4			0x8A4C
#define ISP_ZOOM_CH2_COEF5			0x8A4D
#define ISP_ZOOM_CH2_COEF6			0x8A4E
#define ISP_ZOOM_CH2_COEF7			0x8A4F
#define ISP_ZOOM_CH2_COEF8			0x8A50
#define ISP_ZOOM_CH2_COEF9			0x8A51
#define ISP_ZOOM_CH2_COEFA			0x8A52
#define ISP_ZOOM_CH2_COEFB			0x8A53
#define ISP_ZOOM_CH2_SYNC			0x8A55
#define ISP_ZOOM_CH2_BK_WIDTH_H		0x8A56
#define ISP_ZOOM_CH2_BK_WIDTH_L		0x8A57
#define ISP_ZOOM_CH2_BK_HEIGHT_H	0x8A58
#define ISP_ZOOM_CH2_BK_HEIGHT_L	0x8A59
#define ISP_ZOOM_CH2_EN				0x8A5A

#define ISP_ZOOM_CH3_START_X_L		0x8A60
#define ISP_ZOOM_CH3_START_X_H		0x8A61
#define ISP_ZOOM_CH3_START_Y_L		0x8A62
#define ISP_ZOOM_CH3_START_Y_H		0x8A63
#define ISP_ZOOM_CH3_STEP_X_L		0x8A64
#define ISP_ZOOM_CH3_STEP_X_H		0x8A65
#define ISP_ZOOM_CH3_STEP_Y_L		0x8A66
#define ISP_ZOOM_CH3_STEP_Y_H		0x8A67
#define ISP_ZOOM_CH3_COEF0			0x8A68
#define ISP_ZOOM_CH3_COEF1			0x8A69
#define ISP_ZOOM_CH3_COEF2			0x8A6A
#define ISP_ZOOM_CH3_COEF3			0x8A6B
#define ISP_ZOOM_CH3_COEF4			0x8A6C
#define ISP_ZOOM_CH3_COEF5			0x8A6D
#define ISP_ZOOM_CH3_COEF6			0x8A6E
#define ISP_ZOOM_CH3_COEF7			0x8A6F
#define ISP_ZOOM_CH3_COEF8			0x8A70
#define ISP_ZOOM_CH3_COEF9			0x8A71
#define ISP_ZOOM_CH3_COEFA			0x8A72
#define ISP_ZOOM_CH3_COEFB			0x8A73
#define ISP_ZOOM_CH3_SYNC			0x8A75
#define ISP_ZOOM_CH3_BK_WIDTH_H		0x8A76
#define ISP_ZOOM_CH3_BK_WIDTH_L		0x8A77
#define ISP_ZOOM_CH3_BK_HEIGHT_H	0x8A78
#define ISP_ZOOM_CH3_BK_HEIGHT_L	0x8A79
#define ISP_ZOOM_CH3_EN				0x8A7A

//////////////////////////////////
//Page11 Private Mask
#define MASK_GLOBLE_EN				0x8B00
#define MASK_COLOR_Y				0x8B01
#define MASK_COLOR_U				0x8B02
#define MASK_COLOR_V				0x8B03
#define MASK_START_X_H				0x8B04
#define MASK_START_X_L				0x8B05
#define MASK_START_Y_H				0x8B06
#define MASK_START_Y_L				0x8B07
#define MASK_WINUM_X				0x8B08
#define MASK_WINUM_Y				0x8B09
#define MASK_WIN_WIDTH_H			0x8B0A
#define MASK_WIN_WIDTH_L			0x8B0B
#define MASK_WIN_HEIGHT_H			0x8B0C
#define MASK_WIN_HEIGHT_L			0x8B0D
#define MASK_FW_WRITE				0x8B0E
#define MASK_FW_READ				0x8B0F
#define MASK_FW_DATA_HHH			0x8B10
#define MASK_FW_DATA_HH				0x8B11
#define MASK_FW_DATA_H				0x8B12
#define MASK_FW_DATA_L				0x8B13
#define MASK_FW_DATA_LL				0x8B14
#define MASK_FW_ADDR				0x8B15
#define MASK1_START_X_H				0x8B16
#define MASK1_START_X_L				0x8B17
#define MASK1_START_Y_H				0x8B18
#define MASK1_START_Y_L				0x8B19
#define MASK1_END_X_H				0x8B1A
#define MASK1_END_X_L				0x8B1B
#define MASK1_END_Y_H				0x8B1C
#define MASK1_END_Y_L				0x8B1D
#define MASK2_START_X_H				0x8B1E
#define MASK2_START_X_L				0x8B1F
#define MASK2_START_Y_H				0x8B20
#define MASK2_START_Y_L				0x8B21
#define MASK2_END_X_H				0x8B22
#define MASK2_END_X_L				0x8B23
#define MASK2_END_Y_H				0x8B24
#define MASK2_END_Y_L				0x8B25
#define MASK3_START_X_H				0x8B26
#define MASK3_START_X_L				0x8B27
#define MASK3_START_Y_H				0x8B28
#define MASK3_START_Y_L				0x8B29
#define MASK3_END_X_H				0x8B2A
#define MASK3_END_X_L				0x8B2B
#define MASK3_END_Y_H				0x8B2C
#define MASK3_END_Y_L				0x8B2D
#define MASK4_START_X_H				0x8B2E
#define MASK4_START_X_L				0x8B2F
#define MASK4_START_Y_H				0x8B30
#define MASK4_START_Y_L				0x8B31
#define MASK4_END_X_H				0x8B32
#define MASK4_END_X_L				0x8B33
#define MASK4_END_Y_H				0x8B34
#define MASK4_END_Y_L				0x8B35

//////////////////////////////////
//Page12 OSD
#define ISP_OSD_JPEG_ENABLE				0x8C00
#define ISP_OSD_JPEG_BLOCK_EN			0x8C01
#define ISP_OSD_JPEG_CHINESE_ADDR_H		0x8C02
#define ISP_OSD_JPEG_CHINESE_ADDR_L		0x8C03
#define ISP_OSD_JPEG_TIME_ADDR_H		0x8C04
#define ISP_OSD_JPEG_TIME_ADDR_L		0x8C05
#define ISP_OSD_JPEG_DATE_ADDR_H		0x8C06
#define ISP_OSD_JPEG_DATE_ADDR_L		0x8C07
#define ISP_OSD_JPEG_CHAR_WIDTH			0x8C08
#define ISP_OSD_JPEG_CHAR_HEIGHT		0x8C09
#define ISP_OSD_JPEG_TIME_ENABLE		0x8C0A
#define ISP_OSD_JPEG_CFG_ADDR_H			0x8C0B
#define ISP_OSD_JPEG_CFG_ADDR_L			0x8C0C
#define ISP_OSD_JPEG_WRAP_EN			0x8C0D
#define ISP_OSD_JPEG_START_X0_H			0x8C10
#define ISP_OSD_JPEG_START_X0_L			0x8C11
#define ISP_OSD_JPEG_START_Y0_H			0x8C12
#define ISP_OSD_JPEG_START_Y0_L			0x8C13
#define ISP_OSD_JPEG_END_X0_H			0x8C14
#define ISP_OSD_JPEG_END_X0_L			0x8C15
#define ISP_OSD_JPEG_END_Y0_H			0x8C16
#define ISP_OSD_JPEG_END_Y0_L			0x8C17
#define ISP_OSD_JPEG_START_X1_H			0x8C18
#define ISP_OSD_JPEG_START_X1_L			0x8C19
#define ISP_OSD_JPEG_START_Y1_H			0x8C1A
#define ISP_OSD_JPEG_START_Y1_L			0x8C1B
#define ISP_OSD_JPEG_END_X1_H			0x8C1C
#define ISP_OSD_JPEG_END_X1_L			0x8C1D
#define ISP_OSD_JPEG_END_Y1_H			0x8C1E
#define ISP_OSD_JPEG_END_Y1_L			0x8C1F
#define ISP_OSD_JPEG_START_X2_H			0x8C20
#define ISP_OSD_JPEG_START_X2_L			0x8C21
#define ISP_OSD_JPEG_START_Y2_H			0x8C22
#define ISP_OSD_JPEG_START_Y2_L			0x8C23
#define ISP_OSD_JPEG_END_X2_H			0x8C24
#define ISP_OSD_JPEG_END_X2_L			0x8C25
#define ISP_OSD_JPEG_END_Y2_H			0x8C26
#define ISP_OSD_JPEG_END_Y2_L			0x8C27
#define ISP_OSD_JPEG_START_X3_H			0x8C28
#define ISP_OSD_JPEG_START_X3_L			0x8C29
#define ISP_OSD_JPEG_START_Y3_H			0x8C2A
#define ISP_OSD_JPEG_START_Y3_L			0x8C2B
#define ISP_OSD_JPEG_END_X3_H			0x8C2C
#define ISP_OSD_JPEG_END_X3_L			0x8C2D
#define ISP_OSD_JPEG_END_Y3_H			0x8C2E
#define ISP_OSD_JPEG_END_Y3_L			0x8C2F
#define ISP_OSD_JPEG_START_X4_H			0x8C30
#define ISP_OSD_JPEG_START_X4_L			0x8C31
#define ISP_OSD_JPEG_START_Y4_H			0x8C32
#define ISP_OSD_JPEG_START_Y4_L			0x8C33
#define ISP_OSD_JPEG_END_X4_H			0x8C34
#define ISP_OSD_JPEG_END_X4_L			0x8C35
#define ISP_OSD_JPEG_END_Y4_H			0x8C36
#define ISP_OSD_JPEG_END_Y4_L			0x8C37
#define ISP_OSD_JPEG_START_X5_H			0x8C38
#define ISP_OSD_JPEG_START_X5_L			0x8C39
#define ISP_OSD_JPEG_START_Y5_H			0x8C3A
#define ISP_OSD_JPEG_START_Y5_L			0x8C3B
#define ISP_OSD_JPEG_END_X5_H			0x8C3C
#define ISP_OSD_JPEG_END_X5_L			0x8C3D
#define ISP_OSD_JPEG_END_Y5_H			0x8C3E
#define ISP_OSD_JPEG_END_Y5_L			0x8C3F

#define ISP_OSD_FHD_ENABLE				0x8C40
#define ISP_OSD_FHD_BLOCK_EN			0x8C41
#define ISP_OSD_FHD_CHINESE_ADDR_H		0x8C42
#define ISP_OSD_FHD_CHINESE_ADDR_L		0x8C43
#define ISP_OSD_FHD_TIME_ADDR_H			0x8C44
#define ISP_OSD_FHD_TIME_ADDR_L			0x8C45
#define ISP_OSD_FHD_DATE_ADDR_H			0x8C46
#define ISP_OSD_FHD_DATE_ADDR_L			0x8C47
#define ISP_OSD_FHD_CHAR_WIDTH			0x8C48
#define ISP_OSD_FHD_CHAR_HEIGHT			0x8C49
#define ISP_OSD_FHD_TIME_ENABLE			0x8C4A
#define ISP_OSD_FHD_CFG_ADDR_H			0x8C4B
#define ISP_OSD_FHD_CFG_ADDR_L			0x8C4C
#define ISP_OSD_FHD_WRAP_EN				0x8C4D
#define ISP_OSD_FHD_START_X0_H			0x8C50
#define ISP_OSD_FHD_START_X0_L			0x8C51
#define ISP_OSD_FHD_START_Y0_H			0x8C52
#define ISP_OSD_FHD_START_Y0_L			0x8C53
#define ISP_OSD_FHD_END_X0_H			0x8C54
#define ISP_OSD_FHD_END_X0_L			0x8C55
#define ISP_OSD_FHD_END_Y0_H			0x8C56
#define ISP_OSD_FHD_END_Y0_L			0x8C57
#define ISP_OSD_FHD_START_X1_H			0x8C58
#define ISP_OSD_FHD_START_X1_L			0x8C59
#define ISP_OSD_FHD_START_Y1_H			0x8C5A
#define ISP_OSD_FHD_START_Y1_L			0x8C5B
#define ISP_OSD_FHD_END_X1_H			0x8C5C
#define ISP_OSD_FHD_END_X1_L			0x8C5D
#define ISP_OSD_FHD_END_Y1_H			0x8C5E
#define ISP_OSD_FHD_END_Y1_L			0x8C5F
#define ISP_OSD_FHD_START_X2_H			0x8C60
#define ISP_OSD_FHD_START_X2_L			0x8C61
#define ISP_OSD_FHD_START_Y2_H			0x8C62
#define ISP_OSD_FHD_START_Y2_L			0x8C63
#define ISP_OSD_FHD_END_X2_H			0x8C64
#define ISP_OSD_FHD_END_X2_L			0x8C65
#define ISP_OSD_FHD_END_Y2_H			0x8C66
#define ISP_OSD_FHD_END_Y2_L			0x8C67
#define ISP_OSD_FHD_START_X3_H			0x8C68
#define ISP_OSD_FHD_START_X3_L			0x8C69
#define ISP_OSD_FHD_START_Y3_H			0x8C6A
#define ISP_OSD_FHD_START_Y3_L			0x8C6B
#define ISP_OSD_FHD_END_X3_H			0x8C6C
#define ISP_OSD_FHD_END_X3_L			0x8C6D
#define ISP_OSD_FHD_END_Y3_H			0x8C6E
#define ISP_OSD_FHD_END_Y3_L			0x8C6F
#define ISP_OSD_FHD_START_X4_H			0x8C70
#define ISP_OSD_FHD_START_X4_L			0x8C71
#define ISP_OSD_FHD_START_Y4_H			0x8C72
#define ISP_OSD_FHD_START_Y4_L			0x8C73
#define ISP_OSD_FHD_END_X4_H			0x8C74
#define ISP_OSD_FHD_END_X4_L			0x8C75
#define ISP_OSD_FHD_END_Y4_H			0x8C76
#define ISP_OSD_FHD_END_Y4_L			0x8C77
#define ISP_OSD_FHD_START_X5_H			0x8C78
#define ISP_OSD_FHD_START_X5_L			0x8C79
#define ISP_OSD_FHD_START_Y5_H			0x8C7A
#define ISP_OSD_FHD_START_Y5_L			0x8C7B
#define ISP_OSD_FHD_END_X5_H			0x8C7C
#define ISP_OSD_FHD_END_X5_L			0x8C7D
#define ISP_OSD_FHD_END_Y5_H			0x8C7E
#define ISP_OSD_FHD_END_Y5_L			0x8C7F

#define ISP_OSD_HD_ENABLE				0x8C80
#define ISP_OSD_HD_BLOCK_EN				0x8C81
#define ISP_OSD_HD_CHINESE_ADDR_H		0x8C82
#define ISP_OSD_HD_CHINESE_ADDR_L		0x8C83
#define ISP_OSD_HD_TIME_ADDR_H			0x8C84
#define ISP_OSD_HD_TIME_ADDR_L			0x8C85
#define ISP_OSD_HD_DATE_ADDR_H			0x8C86
#define ISP_OSD_HD_DATE_ADDR_L			0x8C87
#define ISP_OSD_HD_CHAR_WIDTH			0x8C88
#define ISP_OSD_HD_CHAR_HEIGHT			0x8C89
#define ISP_OSD_HD_TIME_ENABLE			0x8C8A
#define ISP_OSD_HD_CFG_ADDR_H			0x8C8B
#define ISP_OSD_HD_CFG_ADDR_L			0x8C8C
#define ISP_OSD_HD_WRAP_EN				0x8C8D
#define ISP_OSD_HD_START_X0_H			0x8C90
#define ISP_OSD_HD_START_X0_L			0x8C91
#define ISP_OSD_HD_START_Y0_H			0x8C92
#define ISP_OSD_HD_START_Y0_L			0x8C93
#define ISP_OSD_HD_END_X0_H				0x8C94
#define ISP_OSD_HD_END_X0_L				0x8C95
#define ISP_OSD_HD_END_Y0_H				0x8C96
#define ISP_OSD_HD_END_Y0_L				0x8C97
#define ISP_OSD_HD_START_X1_H			0x8C98
#define ISP_OSD_HD_START_X1_L			0x8C99
#define ISP_OSD_HD_START_Y1_H			0x8C9A
#define ISP_OSD_HD_START_Y1_L			0x8C9B
#define ISP_OSD_HD_END_X1_H				0x8C9C
#define ISP_OSD_HD_END_X1_L				0x8C9D
#define ISP_OSD_HD_END_Y1_H				0x8C9E
#define ISP_OSD_HD_END_Y1_L				0x8C9F
#define ISP_OSD_HD_START_X2_H			0x8CA0
#define ISP_OSD_HD_START_X2_L			0x8CA1
#define ISP_OSD_HD_START_Y2_H			0x8CA2
#define ISP_OSD_HD_START_Y2_L			0x8CA3
#define ISP_OSD_HD_END_X2_H				0x8CA4
#define ISP_OSD_HD_END_X2_L				0x8CA5
#define ISP_OSD_HD_END_Y2_H				0x8CA6
#define ISP_OSD_HD_END_Y2_L				0x8CA7
#define ISP_OSD_HD_START_X3_H			0x8CA8
#define ISP_OSD_HD_START_X3_L			0x8CA9
#define ISP_OSD_HD_START_Y3_H			0x8CAA
#define ISP_OSD_HD_START_Y3_L			0x8CAB
#define ISP_OSD_HD_END_X3_H				0x8CAC
#define ISP_OSD_HD_END_X3_L				0x8CAD
#define ISP_OSD_HD_END_Y3_H				0x8CAE
#define ISP_OSD_HD_END_Y3_L				0x8CAF
#define ISP_OSD_HD_START_X4_H			0x8CB0
#define ISP_OSD_HD_START_X4_L			0x8CB1
#define ISP_OSD_HD_START_Y4_H			0x8CB2
#define ISP_OSD_HD_START_Y4_L			0x8CB3
#define ISP_OSD_HD_END_X4_H				0x8CB4
#define ISP_OSD_HD_END_X4_L				0x8CB5
#define ISP_OSD_HD_END_Y4_H				0x8CB6
#define ISP_OSD_HD_END_Y4_L				0x8CB7
#define ISP_OSD_HD_START_X5_H			0x8CB8
#define ISP_OSD_HD_START_X5_L			0x8CB9
#define ISP_OSD_HD_START_Y5_H			0x8CBA
#define ISP_OSD_HD_START_Y5_L			0x8CBB
#define ISP_OSD_HD_END_X5_H				0x8CBC
#define ISP_OSD_HD_END_X5_L				0x8CBD
#define ISP_OSD_HD_END_Y5_H				0x8CBE
#define ISP_OSD_HD_END_Y5_L				0x8CBF

#define ISP_OSD_VGA_ENABLE				0x8CC0
#define ISP_OSD_VGA_BLOCK_EN			0x8CC1
#define ISP_OSD_VGA_CHINESE_ADDR_H		0x8CC2
#define ISP_OSD_VGA_CHINESE_ADDR_L		0x8CC3
#define ISP_OSD_VGA_TIME_ADDR_H			0x8CC4
#define ISP_OSD_VGA_TIME_ADDR_L			0x8CC5
#define ISP_OSD_VGA_DATE_ADDR_H			0x8CC6
#define ISP_OSD_VGA_DATE_ADDR_L			0x8CC7
#define ISP_OSD_VGA_CHAR_WIDTH			0x8CC8
#define ISP_OSD_VGA_CHAR_HEIGHT			0x8CC9
#define ISP_OSD_VGA_TIME_ENABLE			0x8CCA
#define ISP_OSD_VGA_CFG_ADDR_H			0x8CCB
#define ISP_OSD_VGA_CFG_ADDR_L			0x8CCC
#define ISP_OSD_VGA_WRAP_EN				0x8CCD
#define ISP_OSD_VGA_START_X0_H			0x8CD0
#define ISP_OSD_VGA_START_X0_L			0x8CD1
#define ISP_OSD_VGA_START_Y0_H			0x8CD2
#define ISP_OSD_VGA_START_Y0_L			0x8CD3
#define ISP_OSD_VGA_END_X0_H			0x8CD4
#define ISP_OSD_VGA_END_X0_L			0x8CD5
#define ISP_OSD_VGA_END_Y0_H			0x8CD6
#define ISP_OSD_VGA_END_Y0_L			0x8CD7
#define ISP_OSD_VGA_START_X1_H			0x8CD8
#define ISP_OSD_VGA_START_X1_L			0x8CD9
#define ISP_OSD_VGA_START_Y1_H			0x8CDA
#define ISP_OSD_VGA_START_Y1_L			0x8CDB
#define ISP_OSD_VGA_END_X1_H			0x8CDC
#define ISP_OSD_VGA_END_X1_L			0x8CDD
#define ISP_OSD_VGA_END_Y1_H			0x8CDE
#define ISP_OSD_VGA_END_Y1_L			0x8CDF
#define ISP_OSD_VGA_START_X2_H			0x8CE0
#define ISP_OSD_VGA_START_X2_L			0x8CE1
#define ISP_OSD_VGA_START_Y2_H			0x8CE2
#define ISP_OSD_VGA_START_Y2_L			0x8CE3
#define ISP_OSD_VGA_END_X2_H			0x8CE4
#define ISP_OSD_VGA_END_X2_L			0x8CE5
#define ISP_OSD_VGA_END_Y2_H			0x8CE6
#define ISP_OSD_VGA_END_Y2_L			0x8CE7
#define ISP_OSD_VGA_START_X3_H			0x8CE8
#define ISP_OSD_VGA_START_X3_L			0x8CE9
#define ISP_OSD_VGA_START_Y3_H			0x8CEA
#define ISP_OSD_VGA_START_Y3_L			0x8CEB
#define ISP_OSD_VGA_END_X3_H			0x8CEC
#define ISP_OSD_VGA_END_X3_L			0x8CED
#define ISP_OSD_VGA_END_Y3_H			0x8CEE
#define ISP_OSD_VGA_END_Y3_L			0x8CEF
#define ISP_OSD_VGA_START_X4_H			0x8CF0
#define ISP_OSD_VGA_START_X4_L			0x8CF1
#define ISP_OSD_VGA_START_Y4_H			0x8CF2
#define ISP_OSD_VGA_START_Y4_L			0x8CF3
#define ISP_OSD_VGA_END_X4_H			0x8CF4
#define ISP_OSD_VGA_END_X4_L			0x8CF5
#define ISP_OSD_VGA_END_Y4_H			0x8CF6
#define ISP_OSD_VGA_END_Y4_L			0x8CF7
#define ISP_OSD_VGA_START_X5_H			0x8CF8
#define ISP_OSD_VGA_START_X5_L			0x8CF9
#define ISP_OSD_VGA_START_Y5_H			0x8CFA
#define ISP_OSD_VGA_START_Y5_L			0x8CFB
#define ISP_OSD_VGA_END_X5_H			0x8CFC
#define ISP_OSD_VGA_END_X5_L			0x8CFD
#define ISP_OSD_VGA_END_Y5_H			0x8CFE
#define ISP_OSD_VGA_END_Y5_L			0x8CFF

#define ISP_TIME_ENABLE					0x8D40
#define ISP_OSD_DATE_A_PARAM0			0x8D41
#define ISP_OSD_DATE_A_PARAM1			0x8D42
#define ISP_OSD_DATE_A_PARAM2			0x8D43
#define ISP_OSD_DATE_A_PARAM3			0x8D44
#define ISP_OSD_DATE_A_PARAM4			0x8D45
#define ISP_OSD_DATE_A_PARAM5			0x8D46
#define ISP_OSD_DATE_A_PARAM6			0x8D47
#define ISP_OSD_DATE_A_PARAM7			0x8D48
#define ISP_OSD_DATE_B_PARAM0			0x8D49
#define ISP_OSD_DATE_B_PARAM1			0x8D4A
#define ISP_OSD_DATE_B_PARAM2			0x8D4B
#define ISP_OSD_DATE_B_PARAM3			0x8D4C
#define ISP_OSD_DATE_B_PARAM4			0x8D4D
#define ISP_OSD_DATE_B_PARAM5			0x8D4E
#define ISP_OSD_DATE_B_PARAM6			0x8D4F
#define ISP_OSD_DATE_B_PARAM7			0x8D50
#define ISP_OSD_TIME_INIT_PARAM0		0x8D51
#define ISP_OSD_TIME_INIT_PARAM1		0x8D52
#define ISP_OSD_TIME_INIT_PARAM2		0x8D53
#define ISP_OSD_TIME_INIT_PARAM3		0x8D54
#define ISP_OSD_TIME_INIT_PARAM4		0x8D55
#define ISP_OSD_TIME_INIT_PARAM5		0x8D56
#define ISP_OSD_TIME_SYNC				0x8D57
#define ISP_OSD_DATE_SEL				0x8D58
#define ISP_OSD_DIV_LOW_H				0x8D59
#define ISP_OSD_DIV_LOW_L				0x8D5A
#define ISP_OSD_DIV_SYNC				0x8D5B
#define ISP_OSD_INT_FLAG				0x8D5C
#define ISP_OSD_INT_EN					0x8D5D
#define ISP_OSD_INT_SEL					0x8D5E
#define ISP_OSD_MEM_ADDR_H				0x8D5F
#define ISP_OSD_MEM_ADDR_L				0x8D60
#define ISP_OSD_MEM_DATA_HH				0x8D61
#define ISP_OSD_MEM_DATA_H				0x8D62
#define ISP_OSD_MEM_DATA_L				0x8D63
#define ISP_OSD_MEM_DATA_LL				0x8D64
#define ISP_OSD_MEM_WRITE				0x8D65
#define ISP_OSD_MEM_READ				0x8D66
#define ISP_OSD_TIME_CUR_PARAM0			0x8D67
#define ISP_OSD_TIME_CUR_PARAM1			0x8D68
#define ISP_OSD_TIME_CUR_PARAM2			0x8D69
#define ISP_OSD_TIME_CUR_PARAM3			0x8D6A
#define ISP_OSD_TIME_CUR_PARAM4			0x8D6B
#define ISP_OSD_TIME_CUR_PARAM5			0x8D6C
#define ISP_OSD_TIME_REVERSED			0x8D6D
#define ISP_OSD_AMPM_ENABLE				0x8D6E
#define ISP_OSD_AMCODE					0x8D6F
#define ISP_OSD_PMCODE					0x8D70
#define ISP_OSD_AMPMCODE				0x8D71
#define ISP_OSD_SHORT_TIME_FORMAT		0x8D72
#define ISP_OSD_DATE_A_PARAMETER		0x8D80
#define ISP_OSD_DATE_B_PARAMETER		0x8DA0

//Dehaze
#define ISP_DEHAZE_EN				0x8E00
#define ISP_DEHAZE_RUN				0x8E01
#define ISP_DEHAZE_SUBEN			0x8E02
#define ISP_DEHAZE_CURVE_AVAIL		0x8E03

#define ISP_DEHAZE_STORE_BLOCK_WIDTH	0x8E06
#define ISP_DEHAZE_STORE_BLOCK_HEIGHT	0x8E07
#define ISP_DEHAZE_STORE_BLOCK_COLUMN	0x8E08
#define ISP_DEHAZE_STORE_BLOCK_LINE		0x8E09
#define ISP_DEHAZE_STORE_MEAN_DIVIDER_H		0x8E0A
#define ISP_DEHAZE_STORE_MEAN_DIVIDER_L		0x8E0B

#define ISP_DEHAZE_STORE_SAMPLE_HORIZON		0x8E0F
#define ISP_DEHAZE_STORE_SAMPLE_VERTICAL	0x8E10

#define ISP_DEHAZE_HISTO_SUM_H		0x8E1D
#define ISP_DEHAZE_HISTO_SUM_M		0x8E1E
#define ISP_DEHAZE_HISTO_SUM_L		0x8E1F

#define ISP_DEHAZE_CURVE_AFTER_REFINE_EN	0x8E27

#define ISP_DEHAZE_CURVE_NORM_FACTOR_H	0x8E28
#define ISP_DEHAZE_CURVE_NORM_FACTOR_M	0x8E29
#define ISP_DEHAZE_CURVE_NORM_FACTOR_L	0x8E2A

#define ISP_DEHAZE_INT_FLAG			0x8E3A
#define ISP_DEHAZE_INT_EN			0x8E3B
#define ISP_DEHAZE_INT_SEL			0x8E3C

#define ISP_DEHAZE_DARK_MEAN		0x8E5A
#define ISP_DEHAZE_GRADIENT_MEAN	0x8E5C

//////////////////////////////////
//Page13 LDC & Noise Level
#define LDC_ENABLE			0x8F00
#define LDC_DUMMY_PIXEL		0x8F01
#define LDC_OVFL_SPEED_CTRL	0x8F02
#define LDC_INT_EN			0x8F10
#define LDC_INT_SEL			0x8F11
#define LDC_INT_FLAG		0x8F12

#define LDC_SCALECOFF0				0x8F20
#define LDC_SCALECOFF1_CX_SQUARE	0x8F23
#define LDC_X_INV0					0x8F26
#define LDC_X_INV1_CX				0x8F28
#define LDC_Y_INV0					0x8F2B
#define LDC_Y_INV1_CY				0x8F2E
#define LDC_X_CENTER				0x8F31
#define LDC_Y_CENTER				0x8F33
#define LDC_X0_CX_SQUARE			0x8F35
#define LDC_Y0_CY_SQUARE			0x8F38

#define	NL_SAMPLE_RATE					   0x8f40
#define	NL_SMOOTH_THD                      0x8f41
#define	NL_LUMINANCE_MIN                   0x8f42
#define	NL_LUMINANCE_MAX                   0x8f43
#define	NL_LUMINANCE_REFER                 0x8f44
#define	NL_LUMINANCE_LOW_R                 0x8f45
#define	NL_LUMINANCE_LOW_G                 0x8f46
#define	NL_LUMINANCE_LOW_B                 0x8f47
#define	NL_CURVE1_COEF0_R                  0x8f48
#define	NL_CURVE1_COEF1_R                  0x8f49
#define	NL_CURVE1_COEF2_R                  0x8f4a
#define	NL_CURVE2_COEF0_R                  0x8f4b
#define	NL_CURVE2_COEF1_R                  0x8f4c
#define	NL_CURVE2_COEF2_R                  0x8f4d
#define	NL_CURVE3_COEF0_R                  0x8f4e
#define	NL_CURVE1_COEF0_G                  0x8f4f
#define	NL_CURVE1_COEF1_G                  0x8f50
#define	NL_CURVE1_COEF2_G                  0x8f51
#define	NL_CURVE2_COEF0_G                  0x8f52
#define	NL_CURVE2_COEF1_G                  0x8f53
#define	NL_CURVE2_COEF2_G                  0x8f54
#define	NL_CURVE3_COEF0_G                  0x8f55
#define	NL_CURVE1_COEF0_B                  0x8f56
#define	NL_CURVE1_COEF1_B                  0x8f57
#define	NL_CURVE1_COEF2_B                  0x8f58
#define	NL_CURVE2_COEF0_B                  0x8f59
#define	NL_CURVE2_COEF1_B                  0x8f5a
#define	NL_CURVE2_COEF2_B                  0x8f5b
#define	NL_CURVE3_COEF0_B                  0x8f5c
#define	NL_PIXEL_NUM_MAX_L                 0x8f5d
#define	NL_PIXEL_NUM_MAX_H                 0x8f5e
#define	NL_TRIG                            0x8f60
#define	NL_INT_EN                          0x8f61
#define	NL_INT_SEL                         0x8f62
#define	NL_INT_CLR                         0x8f63
#define	NL_FLAG                            0x8f64
#define	NOISE_AMPLITUDE_CENTER_R_FINAL_L   0x8f70
#define	NOISE_AMPLITUDE_CENTER_R_FINAL_M   0x8f71
#define	NOISE_AMPLITUDE_CENTER_R_FINAL_H   0x8f72
#define	NOISE_NUMBER_CENTER_R_FINAL_L      0x8f73
#define	NOISE_NUMBER_CENTER_R_FINAL_H      0x8f74
#define	NOISE_AMPLITUDE_CENTER_G_FINAL_L   0x8f75
#define	NOISE_AMPLITUDE_CENTER_G_FINAL_M   0x8f76
#define	NOISE_AMPLITUDE_CENTER_G_FINAL_H   0x8f77
#define	NOISE_NUMBER_CENTER_G_FINAL_L      0x8f78
#define	NOISE_NUMBER_CENTER_G_FINAL_H      0x8f79
#define	NOISE_AMPLITUDE_CENTER_B_FINAL_L   0x8f7a
#define	NOISE_AMPLITUDE_CENTER_B_FINAL_M   0x8f7b
#define	NOISE_AMPLITUDE_CENTER_B_FINAL_H   0x8f7c
#define	NOISE_NUMBER_CENTER_B_FINAL_L      0x8f7d
#define	NOISE_NUMBER_CENTER_B_FINAL_H      0x8f7e
#define	NOISE_AMPLITUDE_MID_R_FINAL_L      0x8f7f
#define	NOISE_AMPLITUDE_MID_R_FINAL_M      0x8f80
#define	NOISE_AMPLITUDE_MID_R_FINAL_H      0x8f81
#define	NOISE_NUMBER_MID_R_FINAL_L         0x8f82
#define	NOISE_NUMBER_MID_R_FINAL_H         0x8f83
#define	NOISE_AMPLITUDE_MID_G_FINAL_L      0x8f84
#define	NOISE_AMPLITUDE_MID_G_FINAL_M      0x8f85
#define	NOISE_AMPLITUDE_MID_G_FINAL_H      0x8f86
#define	NOISE_NUMBER_MID_G_FINAL_L         0x8f87
#define	NOISE_NUMBER_MID_G_FINAL_H         0x8f88
#define	NOISE_AMPLITUDE_MID_B_FINAL_L      0x8f89
#define	NOISE_AMPLITUDE_MID_B_FINAL_M      0x8f8a
#define	NOISE_AMPLITUDE_MID_B_FINAL_H      0x8f8b
#define	NOISE_NUMBER_MID_B_FINAL_L         0x8f8c
#define	NOISE_NUMBER_MID_B_FINAL_H         0x8f8d
#define	NOISE_AMPLITUDE_OUTER_R_FINAL_L    0x8f8e
#define	NOISE_AMPLITUDE_OUTER_R_FINAL_M    0x8f8f
#define	NOISE_AMPLITUDE_OUTER_R_FINAL_H    0x8f90
#define	NOISE_NUMBER_OUTER_R_FINAL_L       0x8f91
#define	NOISE_NUMBER_OUTER_R_FINAL_H       0x8f92
#define	NOISE_AMPLITUDE_OUTER_G_FINAL_L    0x8f93
#define	NOISE_AMPLITUDE_OUTER_G_FINAL_M    0x8f94
#define	NOISE_AMPLITUDE_OUTER_G_FINAL_H    0x8f95
#define	NOISE_NUMBER_OUTER_G_FINAL_L       0x8f96
#define	NOISE_NUMBER_OUTER_G_FINAL_H       0x8f97
#define	NOISE_AMPLITUDE_OUTER_B_FINAL_L    0x8f98
#define	NOISE_AMPLITUDE_OUTER_B_FINAL_M    0x8f99
#define	NOISE_AMPLITUDE_OUTER_B_FINAL_H    0x8f9a
#define	NOISE_NUMBER_OUTER_B_FINAL_L       0x8f9b
#define	NOISE_NUMBER_OUTER_B_FINAL_H       0x8f9c

#endif
