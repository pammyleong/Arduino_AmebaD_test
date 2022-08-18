#ifndef _OV2710_IQ_H_
#define _OV2710_IQ_H_

IQTABLE_t code ct_IQ_Table=
{
	// IQ Header
	{
		IQ_TABLE_AP_VERSION,	// AP version
		sizeof(IQTABLE_t),
		0x00,	// IQ version High
		0x00,	// IQ version Low
		0xFF,
		0xFF,
		0xFF
	},

	// BLC
	{
		{16,12,12,16},
	},

	// LSC
	{
		// circle LSC for small resolution
		{
			{
				// circle LSC curve
				{
					{129,   0, 131,   0, 132,   0, 135,   0, 138,   0, 141,   0, 146,   0, 152,   0, 161,   0, 172,   0, 186,   0, 204,   0, 227,   0,   6,   1,  55,   1, 112,   1, 207,   1,  70,   2,  70,   2,  70,   2,  70,   2,  70,   2,  70,   2,  70,   2, },
					{129,   0, 130,   0, 132,   0, 135,   0, 137,   0, 141,   0, 146,   0, 153,   0, 161,   0, 171,   0, 184,   0, 200,   0, 222,   0, 252,   0,  44,   1,  98,   1, 182,   1,  29,   2,  29,   2,  29,   2,  29,   2,  29,   2,  29,   2,  29,   2, },
					{129,   0, 130,   0, 132,   0, 134,   0, 137,   0, 140,   0, 144,   0, 150,   0, 158,   0, 168,   0, 181,   0, 198,   0, 220,   0, 250,   0,  39,   1,  93,   1, 180,   1,  32,   2,  32,   2,  32,   2,  32,   2,  32,   2,  32,   2,  32,   2, },
				},
				// circle LSC center: R Center Hortizontal, R Center Vertical, G Center Hortizontal, G Center Vertical,B Center Hortizontal, B Center Vertical
				{960,492,960,492,960,492}, //For Module No.21
				// step
				64,
			},

			// micro LSC
			{
				// micro LSC grid mode
				2,
				// micro LSC matrix
				{
					{0},
					// flip - 0   mirror - 1
					{0},
					// flip - 1   mirror - 0
					{0},
					// flip - 1   mirror - 1
					{0},
				}	
			},
		},
#ifdef _MULTIPLE_LSC_CONFIG_

		// circle LSC for big resolution
		{
			{
				// circle LSC curve
				{
					{128,   0, 130,   0, 132,   0, 135,   0, 139,   0, 144,   0, 150,   0, 156,   0, 164,   0, 171,   0, 180,   0, 190,   0, 200,   0, 211,   0, 223,   0, 236,   0, 254,   0, 254,   0, 254,   0, 254,   0, 254,   0, 254,   0, 254,   0, 254,   0, },
					{128,   0, 129,   0, 131,   0, 133,   0, 137,   0, 140,   0, 145,   0, 150,   0, 155,   0, 161,   0, 168,   0, 175,   0, 182,   0, 191,   0, 200,   0, 212,   0, 229,   0, 229,   0, 229,   0, 229,   0, 229,   0, 229,   0, 229,   0, 229,   0, },
					{128,   0, 129,   0, 131,   0, 133,   0, 136,   0, 140,   0, 144,   0, 148,   0, 153,   0, 158,   0, 164,   0, 171,   0, 178,   0, 186,   0, 195,   0, 205,   0, 221,   0, 221,   0, 221,   0, 221,   0, 221,   0, 221,   0, 221,   0, 221,   0, },
				},
				// circle LSC center: R Center Hortizontal, R Center Vertical, G Center Hortizontal, G Center Vertical,B Center Hortizontal, B Center Vertical
				{956,590,956,590,956,590}, //For Module No.21
				// step
				64,
			},

			// micro LSC
			{
				// micro LSC grid mode
				2,
				// micro LSC matrix
				{0},
			},
		},
       //   LSC for 8M
        {
            {
                // circle LSC curve
                {
                    {128,   0, 128,   0, 131,   0, 135,   0, 142,   0, 151,   0, 162,   0, 177,   0, 195,   0, 215,   0, 237,   0,   7,   1,  35,   1,  63,   1,  97,   1, 137,   1, 183,   1, 183,   1, 183,   1, 183,   1, 183,   1, 183,   1, 183,   1, 183,   1, },
                    {128,   0, 128,   0, 131,   0, 135,   0, 140,   0, 148,   0, 158,   0, 170,   0, 184,   0, 199,   0, 216,   0, 235,   0,   1,   1,  21,   1,  48,   1,  77,   1, 111,   1, 134,   1, 134,   1, 134,   1, 134,   1, 134,   1, 134,   1, 134,   1, },
                    {128,   0, 129,   0, 131,   0, 134,   0, 138,   0, 145,   0, 152,   0, 162,   0, 173,   0, 186,   0, 202,   0, 219,   0, 238,   0,   2,   1,  26,   1,  54,   1,  90,   1,  90,   1,  90,   1,  90,   1,  90,   1,  90,   1,  90,   1,  90,   1, },
                },
                // circle LSC center: R Center Hortizontal, R Center Vertical, G Center Hortizontal, G Center Vertical,B Center Hortizontal, B Center Vertical
                {1616,1116,1658,1110,1596,1044},
                //step
                128,
            },
            // micro LSC
            {
                // micro LSC grid mode
                2,
                // micro LSC matrix
                {0},
                //step
            },
        },
#endif
		// dynamic LSC
		{
			80,   // Dynamic LSC Gain Threshold Low
			144,  // Dynamic LSC Gain Threshold High
			0x20,	// Dynamic LSC Adjust rate at Gain Threshold Low
			0x10,	// Dynamic LSC Adjust rate at Gain Threshold High
			{26,29,37,40,46,47},	// g_aAWBRoughGain_R
			{73,69,71,53,46,43},	// g_aAWBRoughGain_B
			50,		// start threshold of dynamic LSC by CT, white pixel millesimal
			25,		// end threshold of dynamic LSC by CT, white pixel millesimal
			100,		// LSC switch color temperature threshold buffer
			{3100,3800,4700,5800,7000},	// LSC switch color temperature threshold
			{
				{0x20,0x20,0x20,},//a=2850k
				{0x20,0x20,0x20,},//3500k
				{0x1A,0x20,0x20,},//cwf=4150k
				{0x20,0x20,0x20,},//d50=5000k
				{0x20,0x20,0x20,},//d65=6500k
				{0x20,0x20,0x20,},//d75=6500k
			},
		},
	},

	// CCM
	{
		// normal ccm
		{
			// D65 light CCM
			{0x1e4,-185,-43,-21,0x147,-50,-12,-292,0x230/*+10*/,},	//For MSOC test, pass premium
			// CWF light CCM
			{0x1c6,-169,-32,-87,0x178,-31,-89,-169,0x1ff},	//For MSOC test, pass premium
			// A light CCM
			{0x168,-72,-32,-56,0x176,-62,-4,-161,0x1a5},	//For MSOC test, pass premium
			// HORIZON light CCM
			{0x168,-72,-32,-56,0x176,-62,-4,-161,0x1a5},	//For MSOC test, pass premium
		},
		// low lux ccm
		{
			// D65 light CCM
			{0x1e4,-185,-43,-21,0x147,-50,-12,-292,0x230,},
			// CWF light CCM
			{0x100, 0, 0, 0, 0x100, 0, 0, 0, 0x100},
			// A light CCM
			{0x100, 0, 0, 0, 0x100, 0, 0, 0, 0x100},
			// HORIZON light CCM
			{0x100, 0, 0, 0, 0x100, 0, 0, 0, 0x100},
		},
		// ccm light source switch threshold
		{
			5600,	// dynamic CCM D65-CWF_H light Color Temperature Switch Threshold
			5000,	// dynamic CCM D65-CWF_L light Color Temperature Switch Threshold
			3800,	// dynamic CCM CWF_A_H light Color Temperature Switch Threshold
			3500,	// dynamic CCM CWF_A_L light Color Temperature Switch Threshold
			2700,	// dynamic CCM A_H_H light Color Temperature Switch Threshold
			2500,	// dynamic CCM A_H_L light Color Temperature Switch Threshold
		},
		// dynamic CCM Gain Threshold
		{
			800,	// dynamic CCM Gain Threshold Low
			960,	// dynamic CCM Gain Threshold High
		}
	},

	// Gamma
	{
		// normal light gamma
		{0, 14, 28, 42, 53, 64, 74, 83, 89, 103, 115, 125, 134, 142, 149, 157, 163, 169, 175, 180, 185, 196, 206, 215, 223, 232, 240, 248,}, //Neil 0629 chicony tuning
		// low light gamma
		{0, 20, 40, 56, 69, 80, 87, 93, 99, 109, 119, 128, 136, 143, 150, 157, 163, 169, 175, 181, 186, 196, 206, 215, 224, 232, 240, 248,}, //[Albert, 2011/06/09]
		600,	// dynamic Gamma Gain Threshold Low
		800	// dynamic Gamma Gain Threshold High
	},

	// AE
	{
		// AE target
		{
			40,	// Histogram Ratio Low
			40,// Histogram Ratio High
			50,	// YMean Target Low
			55,	// YMean Target
			60,	// YMean Target High
			10,	// Histogram Position Low
			190,// Histogram Position High
			3	// Dynamic AE Target decrease value
		},
		// AE limit
		{
			6,	// AE step Max value at 50Hz power line frequency
			8,	// AE step Max value at 60Hz power line frequency
			1024,	// AE global gain Max value
			{	// AE continous frame rate gain threshold
				24, //Gain threshold from 30 fps -> 25 fps
				24, //Gain threshold from 25 fps -> 20 fps
				24, //Gain threshold from 20 fps -> 15 fps
				24, //Gain threshold from 15 fps -> 10 fps
				24, //Gain threshold from 10 fps -> 05 fps
			},
			15, //User manual min FPS
			128,	// AE discrete frame rate 15fps gain threshold
			48,	// AE discrete frame rate 30fps gain threshold
			90	// AE HighLight mode threshold
		},
		// AE weight
		{
			{
				1,1,1,1,1,
				1,1,1,1,1,
				1,1,1,1,1,
				1,1,1,1,1,
				1,1,1,1,1,
			}
		},
		// AE sensitivity
		{
			0.05,// g_fAEC_Adjust_Th
			30,	// AE Latency time
			//20,	// Ymean diff threshold for judge AE same block
			6,	// hemonel 2011-07-14: modify Neil adjust parameter from 20 to 8
			20	// same block count threshold for judge AE scene variation
		},
		//AE fast mode step
		{
			0.1,  //g_fAE_fast_adjstep_greater_th_pow
			1.5,  //g_fAE_fast_adjstep_greater_th_h
			1.22, //g_fAE_fast_adjstep_greater_th_m
			1.08, //g_fAE_fast_adjstep_greater_th_l
			0.68,//g_fAE_fast_adjstep_less_th_l
			0.9, //g_fAE_fast_adjstep_less_th_h
			0.125,//g_fAE_fast_adjstep_less_th_pow
		},
		//AE slow mode step
		{
			0.88,// g_fAE_slow_adjstep_less_th_l
			0.95,// g_fAE_slow_adjstep_less_th_m
			0.99,// g_fAE_slow_adjstep_less_th_h
			1.01,// g_fAE_slow_adjstep_greater_th_l
			1.05,// g_fAE_slow_adjstep_greater_th_m
			1.12,// g_fAE_slow_adjstep_greater_th_h
		},
	},

	// AWB
	{
		{
			// AWB simple
			{26,29,37,40,46,47},	// g_aAWBRoughGain_R
			{73,69,71,53,46,43},	// g_aAWBRoughGain_B
			10,	// K1
			85,	// B1
			68,	// B2
			8,	// sK3
			30,	// sB3
			-46,	// sK4
			290,	// sB4
			60,	// sK5
			-110,// sB5
			4,	// sK6
			4,	// sB6
			95,	// B_up
			58,	// B_down
			40,	// sB_left
			320,	// sB_right
			230,	// Ymean range upper limit
			0,	// Ymean range low limit
			500,	// RGB sum threshold for AWB hold
		},
		// AWB advanced
		{
			5,	// white point ratio threshold
			38,	// g_byAWBFineMax_RG
			26,	// g_byAWBFineMin_RG
			38,	// g_byAWBFineMax_BG
			26,	// g_byAWBFineMin_BG
			225,	// g_byAWBFineMax_Bright
			10,	// g_byAWBFineMin_Bright
			16	// g_byFtGainTh
		},
		// AWB sensitivity
		{
			8, // g_wAWBGainDiffTh
			1, // g_byAWBGainStep
			10,	// g_byAWBFixed_YmeanTh
			7,	// g_byAWBColorDiff_Th
			12	// g_byAWBDiffWindowsTh
		}
	},

	// AF
	{
		16,			// AF statis threshold
		// AF Peak Th
		{
			10000,	// peak sharp threshold
			1.08,	// high peak ratio threshold of fine search
			2.0,	// low peak ratio threshold of fine search
			1.12,	// high peak ratio threshold of rough search
			2.8,	// low peak ratio threshold of rough search
		},
		// AF Sensitivity
		{
			0.3,	// sharp diff ratio threshold
			12,		// color diff threshold
			7,		// color change block number threshold
			5,		// diff times threshold
			5,		// move color threshold
			8,
		},
		// AF Search Params
		{
			24,		// total steps
			1200,	// rough search entrance threshold
			1,		// fine step
			2,		// rough step
			1.01,	// sharp ratio threshold of fine search
			1.02,	// sharp ratio threshold of rough search
			4,		// decrease times threshold of fine search
			2,		// decrease times threshold of rough search
			2,		// dirction change times threshold
			12,		// NG position index
			// search position array
			{100, 110, 120, 130, 142, 154, 166, 182, 198, 214, 234, 254, 278, 302, 332, 362, 402, 442, 492, 542, 602, 662, 732, 802},
		},
         	// scene distance (cm) corresponding to VCM position
			{200, 160, 134, 114, 96,  80,  68,  58,  48,  40,  34,  28,  24,  20,  18,  16,  14,  12,  10,  9,   8,   7,   6,   5},
	},

	// Texture
	{		
		// Gain threshold
		{
			2*16, //32, //32,		// dynamic denoise gain threshold 0
			4*16, //64, //80,		// dynamic denoise gain threshold 1
			8*16, //96, //112,		// dynamic denoise gain threshold 2
			16*16, //128, //144,		// dynamic denoise gain threshold 3
			24*16, //160, //216,		// dynamic denoise gain threshold 4
			32*16, //192, //288,		// dynamic denoise gain threshold 5
			48*16, //224, //768,		// dynamic denoise gain threshold 6
		},

		// sharpness
		{
			{	// M0
				160,		//ISP_SHARPNESS  (0x8575)
				160,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M1
				160,		//ISP_SHARPNESS  (0x8575)
				160,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M2
				160,		//ISP_SHARPNESS  (0x8575)
				160,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M3
				0x8C,		//ISP_SHARPNESS  (0x8575)
				0x8C,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M4
				0x78,		//ISP_SHARPNESS  (0x8575)
				0x78,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M5
				100,		//ISP_SHARPNESS  (0x8575)
				100,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M6
				0x50,		//ISP_SHARPNESS  (0x8575)
				0x50,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M7
				0x50,		//ISP_SHARPNESS  (0x8575)
				0x50,		//ISP_SHARP_V  (0x85A7)
			},
		},

		// static parameters
		{			
			0x8001, 0xFF,   //ISP_CONTROL1 (0x8001) //

			// static raw de-noise

			// static interpolation

			// static rgb de-noise

			// static edge enhance
			
			0x0000, 0x00,
		},

		// dynamic parameters
		{
			{ // M0
				//Raw De-noise
				0x8526, 0x04,	//ISP_NR_CHAOS_THD
				0x8525, 0x02,	//ISP_NR_CHAOS_MAX
				0x8527, 0x02,	//ISP_NR_CHAOS_CFG
				0x8510, 0x01,	//ISP_DDP_CTRL
				0x850B, 0x00,	//ISP_DDP_SEL
				0x8511, 0x04,	//ISP_DP_THD_D1
				0x8519, 0x02,	//ISP_DDP_DARK_RATE
				0x8515, 0x10,	//ISP_DP_DARK_THD_MAX
				0x8514, 0x03,	//ISP_DP_DARK_THD_MIN
				0x8517, 0x02,	//ISP_DDP_BRIGHT_RATE
				0x8513, 0x0A,	//ISP_DP_BRIGHT_THD_MAX
				0x8512, 0x02,	//ISP_DP_BRIGHT_THD_MIN
				0x8520, 0x81,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x00,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x00,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xE0,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8460, 0x18,	//ISP_INTP_EDGE_THD
				0x8461, 0x35,	//ISP_INTP_DCT_B
				0x8462, 0x0C,	//ISP_INTP_DCT_K1
				0x8463, 0x0B,	//ISP_INTP_DCT_K2
				0x8464, 0x33,	//ISP_INTP_RGB_AFFECT
				0x8465, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8466, 0x04,	//ISP_INTP_LPF_CTRL
				0x8467, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8468, 0x05,	//ISP_INTP_FCRD_SMOOTH
				0x8469, 0x20,	//ISP_MOIRE_G_AFFECT
				0x846b, 0x14,	//ISP_MOIRE_MAX
				0x847d, 0x11,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x847e, 0x50,	//ISP_ILOC_MAX
				0x847f, 0x20,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x35,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x30,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x06,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x06,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x19,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0A,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFE,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x1B,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x22,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x1A,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x1A,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0A,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0A,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				0x0000, 0x00,
			},
			{ // M1
				//Raw De-noise
				0x8526, 0x04,	//ISP_NR_CHAOS_THD
				0x8525, 0x02,	//ISP_NR_CHAOS_MAX
				0x8527, 0x02,	//ISP_NR_CHAOS_CFG
				0x8510, 0x01,	//ISP_DDP_CTRL
				0x850B, 0x00,	//ISP_DDP_SEL
				0x8511, 0x04,	//ISP_DP_THD_D1
				0x8519, 0x02,	//ISP_DDP_DARK_RATE
				0x8515, 0x10,	//ISP_DP_DARK_THD_MAX
				0x8514, 0x03,	//ISP_DP_DARK_THD_MIN
				0x8517, 0x02,	//ISP_DDP_BRIGHT_RATE
				0x8513, 0x0A,	//ISP_DP_BRIGHT_THD_MAX
				0x8512, 0x02,	//ISP_DP_BRIGHT_THD_MIN
				0x8520, 0x81,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x00,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xE0,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8460, 0x18,	//ISP_INTP_EDGE_THD
				0x8461, 0x35,	//ISP_INTP_DCT_B
				0x8462, 0x0C,	//ISP_INTP_DCT_K1
				0x8463, 0x0B,	//ISP_INTP_DCT_K2
				0x8464, 0x33,	//ISP_INTP_RGB_AFFECT
				0x8465, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8466, 0x04,	//ISP_INTP_LPF_CTRL
				0x8467, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8468, 0x05,	//ISP_INTP_FCRD_SMOOTH
				0x8469, 0x20,	//ISP_MOIRE_G_AFFECT
				0x846b, 0x14,	//ISP_MOIRE_MAX
				0x847d, 0x11,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x847e, 0x50,	//ISP_ILOC_MAX
				0x847f, 0x20,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x35,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x40,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x07,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x0C,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x19,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0A,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFE,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x1B,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x22,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x1A,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x1A,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0A,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0A,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				0x0000, 0x00,
			},
			{ // M2
				//Raw De-noise
				0x8526, 0x04,	//ISP_NR_CHAOS_THD
				0x8525, 0x02,	//ISP_NR_CHAOS_MAX
				0x8527, 0x02,	//ISP_NR_CHAOS_CFG
				0x8510, 0x01,	//ISP_DDP_CTRL
				0x850B, 0x00,	//ISP_DDP_SEL
				0x8511, 0x04,	//ISP_DP_THD_D1
				0x8519, 0x02,	//ISP_DDP_DARK_RATE
				0x8515, 0x10,	//ISP_DP_DARK_THD_MAX
				0x8514, 0x03,	//ISP_DP_DARK_THD_MIN
				0x8517, 0x02,	//ISP_DDP_BRIGHT_RATE
				0x8513, 0x0A,	//ISP_DP_BRIGHT_THD_MAX
				0x8512, 0x02,	//ISP_DP_BRIGHT_THD_MIN
				0x8520, 0x81,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x00,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xE0,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8460, 0x18,	//ISP_INTP_EDGE_THD
				0x8461, 0x35,	//ISP_INTP_DCT_B
				0x8462, 0x0C,	//ISP_INTP_DCT_K1
				0x8463, 0x0B,	//ISP_INTP_DCT_K2
				0x8464, 0x33,	//ISP_INTP_RGB_AFFECT
				0x8465, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8466, 0x04,	//ISP_INTP_LPF_CTRL
				0x8467, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8468, 0x05,	//ISP_INTP_FCRD_SMOOTH
				0x8469, 0x20,	//ISP_MOIRE_G_AFFECT
				0x846b, 0x14,	//ISP_MOIRE_MAX
				0x847d, 0x11,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x847e, 0x50,	//ISP_ILOC_MAX
				0x847f, 0x20,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x46,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x50,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x08,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x12,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x19,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0A,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFE,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x1B,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x22,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x1A,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x1A,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0A,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0A,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				0x0000, 0x00,
			},
			{ // M3
				//Raw De-noise
				0x8526, 0x04,	//ISP_NR_CHAOS_THD
				0x8525, 0x02,	//ISP_NR_CHAOS_MAX
				0x8527, 0x02,	//ISP_NR_CHAOS_CFG
				0x8510, 0x01,	//ISP_DDP_CTRL
				0x850B, 0x00,	//ISP_DDP_SEL
				0x8511, 0x04,	//ISP_DP_THD_D1
				0x8519, 0x02,	//ISP_DDP_DARK_RATE
				0x8515, 0x10,	//ISP_DP_DARK_THD_MAX
				0x8514, 0x03,	//ISP_DP_DARK_THD_MIN
				0x8517, 0x02,	//ISP_DDP_BRIGHT_RATE
				0x8513, 0x0A,	//ISP_DP_BRIGHT_THD_MAX
				0x8512, 0x02,	//ISP_DP_BRIGHT_THD_MIN
				0x8520, 0x81,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x00,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xE0,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8460, 0x18,	//ISP_INTP_EDGE_THD
				0x8461, 0x35,	//ISP_INTP_DCT_B
				0x8462, 0x0C,	//ISP_INTP_DCT_K1
				0x8463, 0x0B,	//ISP_INTP_DCT_K2
				0x8464, 0x33,	//ISP_INTP_RGB_AFFECT
				0x8465, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8466, 0x04,	//ISP_INTP_LPF_CTRL
				0x8467, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8468, 0x05,	//ISP_INTP_FCRD_SMOOTH
				0x8469, 0x20,	//ISP_MOIRE_G_AFFECT
				0x846b, 0x14,	//ISP_MOIRE_MAX
				0x847d, 0x11,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x847e, 0x50,	//ISP_ILOC_MAX
				0x847f, 0x20,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x46,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x09,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x18,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x19,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0A,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFE,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x1B,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x22,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x1A,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x1A,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0A,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0A,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				0x0000, 0x00,
			},
			{ // M4
				//Raw De-noise
				0x8526, 0x04,	//ISP_NR_CHAOS_THD
				0x8525, 0x02,	//ISP_NR_CHAOS_MAX
				0x8527, 0x02,	//ISP_NR_CHAOS_CFG
				0x8510, 0x01,	//ISP_DDP_CTRL
				0x850B, 0x00,	//ISP_DDP_SEL
				0x8511, 0x04,	//ISP_DP_THD_D1
				0x8519, 0x02,	//ISP_DDP_DARK_RATE
				0x8515, 0x10,	//ISP_DP_DARK_THD_MAX
				0x8514, 0x03,	//ISP_DP_DARK_THD_MIN
				0x8517, 0x02,	//ISP_DDP_BRIGHT_RATE
				0x8513, 0x0A,	//ISP_DP_BRIGHT_THD_MAX
				0x8512, 0x02,	//ISP_DP_BRIGHT_THD_MIN
				0x8520, 0x81,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x00,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xE0,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8460, 0x18,	//ISP_INTP_EDGE_THD
				0x8461, 0x35,	//ISP_INTP_DCT_B
				0x8462, 0x0C,	//ISP_INTP_DCT_K1
				0x8463, 0x0A,	//ISP_INTP_DCT_K2
				0x8464, 0x33,	//ISP_INTP_RGB_AFFECT
				0x8465, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8466, 0x04,	//ISP_INTP_LPF_CTRL
				0x8467, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8468, 0x05,	//ISP_INTP_FCRD_SMOOTH
				0x8469, 0x20,	//ISP_MOIRE_G_AFFECT
				0x846b, 0x14,	//ISP_MOIRE_MAX
				0x847d, 0x11,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x847e, 0x50,	//ISP_ILOC_MAX
				0x847f, 0x30,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x57,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0A,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x18,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x16,	//ISP_LOC_MAX
				0x85B5, 0x54,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0A,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFE,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x1B,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x22,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x1A,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x1A,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0A,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0A,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				0x0000, 0x00,
			},
			{ // M5
				//Raw De-noise
				0x8526, 0x04,	//ISP_NR_CHAOS_THD
				0x8525, 0x02,	//ISP_NR_CHAOS_MAX
				0x8527, 0x02,	//ISP_NR_CHAOS_CFG
				0x8510, 0x01,	//ISP_DDP_CTRL
				0x850B, 0x00,	//ISP_DDP_SEL
				0x8511, 0x04,	//ISP_DP_THD_D1
				0x8519, 0x02,	//ISP_DDP_DARK_RATE
				0x8515, 0x10,	//ISP_DP_DARK_THD_MAX
				0x8514, 0x03,	//ISP_DP_DARK_THD_MIN
				0x8517, 0x02,	//ISP_DDP_BRIGHT_RATE
				0x8513, 0x0A,	//ISP_DP_BRIGHT_THD_MAX
				0x8512, 0x02,	//ISP_DP_BRIGHT_THD_MIN
				0x8520, 0x81,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x08,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xE0,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8460, 0x18,	//ISP_INTP_EDGE_THD
				0x8461, 0x35,	//ISP_INTP_DCT_B
				0x8462, 0x0C,	//ISP_INTP_DCT_K1
				0x8463, 0x0A,	//ISP_INTP_DCT_K2
				0x8464, 0x33,	//ISP_INTP_RGB_AFFECT
				0x8465, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8466, 0x04,	//ISP_INTP_LPF_CTRL
				0x8467, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8468, 0x05,	//ISP_INTP_FCRD_SMOOTH
				0x8469, 0x20,	//ISP_MOIRE_G_AFFECT
				0x846b, 0x14,	//ISP_MOIRE_MAX
				0x847d, 0x11,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x847e, 0x50,	//ISP_ILOC_MAX
				0x847f, 0x30,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x57,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0B,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x18,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x16,	//ISP_LOC_MAX
				0x85B5, 0x54,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0A,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFE,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x1B,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x22,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x1A,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x1A,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0A,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0A,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				0x0000, 0x00,
			},
			{ // M6
				//Raw De-noise
				0x8526, 0x04,	//ISP_NR_CHAOS_THD
				0x8525, 0x02,	//ISP_NR_CHAOS_MAX
				0x8527, 0x02,	//ISP_NR_CHAOS_CFG
				0x8510, 0x01,	//ISP_DDP_CTRL
				0x850B, 0x00,	//ISP_DDP_SEL
				0x8511, 0x04,	//ISP_DP_THD_D1
				0x8519, 0x02,	//ISP_DDP_DARK_RATE
				0x8515, 0x10,	//ISP_DP_DARK_THD_MAX
				0x8514, 0x03,	//ISP_DP_DARK_THD_MIN
				0x8517, 0x02,	//ISP_DDP_BRIGHT_RATE
				0x8513, 0x0A,	//ISP_DP_BRIGHT_THD_MAX
				0x8512, 0x02,	//ISP_DP_BRIGHT_THD_MIN
				0x8520, 0x81,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x10,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xE0,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8460, 0x18,	//ISP_INTP_EDGE_THD
				0x8461, 0x35,	//ISP_INTP_DCT_B
				0x8462, 0x0C,	//ISP_INTP_DCT_K1
				0x8463, 0x0A,	//ISP_INTP_DCT_K2
				0x8464, 0x33,	//ISP_INTP_RGB_AFFECT
				0x8465, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8466, 0x04,	//ISP_INTP_LPF_CTRL
				0x8467, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8468, 0x05,	//ISP_INTP_FCRD_SMOOTH
				0x8469, 0x20,	//ISP_MOIRE_G_AFFECT
				0x846b, 0x14,	//ISP_MOIRE_MAX
				0x847d, 0x11,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x847e, 0x50,	//ISP_ILOC_MAX
				0x847f, 0x30,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x68,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x68,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0C,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x18,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x19,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0A,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFE,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x1B,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x22,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x1A,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x1A,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0A,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0A,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				0x0000, 0x00,
			},
			{ // M7
				//Raw De-noise
				0x8526, 0x04,	//ISP_NR_CHAOS_THD
				0x8525, 0x02,	//ISP_NR_CHAOS_MAX
				0x8527, 0x02,	//ISP_NR_CHAOS_CFG
				0x8510, 0x01,	//ISP_DDP_CTRL
				0x850B, 0x00,	//ISP_DDP_SEL
				0x8511, 0x04,	//ISP_DP_THD_D1
				0x8519, 0x02,	//ISP_DDP_DARK_RATE
				0x8515, 0x10,	//ISP_DP_DARK_THD_MAX
				0x8514, 0x03,	//ISP_DP_DARK_THD_MIN
				0x8517, 0x02,	//ISP_DDP_BRIGHT_RATE
				0x8513, 0x0A,	//ISP_DP_BRIGHT_THD_MAX
				0x8512, 0x02,	//ISP_DP_BRIGHT_THD_MIN
				0x8520, 0x81,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x18,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xE0,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8460, 0x18,	//ISP_INTP_EDGE_THD
				0x8461, 0x35,	//ISP_INTP_DCT_B
				0x8462, 0x0C,	//ISP_INTP_DCT_K1
				0x8463, 0x0A,	//ISP_INTP_DCT_K2
				0x8464, 0x33,	//ISP_INTP_RGB_AFFECT
				0x8465, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8466, 0x04,	//ISP_INTP_LPF_CTRL
				0x8467, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8468, 0x05,	//ISP_INTP_FCRD_SMOOTH
				0x8469, 0x20,	//ISP_MOIRE_G_AFFECT
				0x846b, 0x14,	//ISP_MOIRE_MAX
				0x847d, 0x11,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x847e, 0x50,	//ISP_ILOC_MAX
				0x847f, 0x30,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x68,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x68,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0C,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x18,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x19,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0A,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFE,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x1B,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x22,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x1A,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x1A,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0A,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0A,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				0x0000, 0x00,
			}
		},
	},

	// UV color tune
	{
		// A light UV color tune
		{
			//UV color tune 1
			{
				0, //ISP_UVT_UCENTER
				0, //ISP_UVT_VCENTER
				0, //ISP_UVT_UINC
				0, //ISP_UVT_VINC
			},
			//UV color tune 2
			{
				0, //ISP_UVT_UCENTER
				0, //ISP_UVT_VCENTER
				0, //ISP_UVT_UINC
				0, //ISP_UVT_VINC
			},
			//UV color tune 0
			{
				0, //ISP_UVT_UCENTER
				0, //ISP_UVT_VCENTER
				0, //ISP_UVT_UINC
				0, //ISP_UVT_VINC
			},
		},
		// D65 UV color tune
		{
			//UV color tune 1
			{
				0,  //ISP_UVT_UCENTER
				0,    //ISP_UVT_VINC
				0,   //ISP_UVT_UINC
				0,   //ISP_UVT_VINC
			},
			//UV color tune 2
			{
				0, //ISP_UVT_UCENTER
				0, //ISP_UVT_VCENTER
				0, //ISP_UVT_UINC
				0, //ISP_UVT_VINC
			},
			//UV color tune 0
			{
				0,  //ISP_UVT_UCENTER
				0,    //ISP_UVT_VINC
				0,   //ISP_UVT_UINC
				0,   //ISP_UVT_VINC
			},
		},

		3300, // Dynamic UV color tune threshold for A light
		4000,  // Dynamic UV color tune threshold for D65 light
	},

	// UV offset
	{
		2,// 3,		// A light U offset
		-2,// 4,		// A light V offset
		2,// 3,		// D65 light U offset
		-2,// 4,		// D65 light V offset
		3300,	// Dynamic UV offset threshold for A light
		4000		// Dynamic UV offset threshold for D65 light
	},

	// NLC
	{
		// G NLC
		{0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208, 224, 240},
		// R - G diff
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		// B - G diff
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	},

	// HW HDR
	{
		{
			// tgamma threshold
			0x8,
			// tgamma rate
			0x10,
			// HDR LPF COEF
			{0, 1, 3, 5, 6, 6, 5, 4, 2},
			// HDR curver
			{80, 69, 59, 48, 41, 35, 30, 26, 23, 21, 19, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
			//HDR step
			0x4,
			//local constrast curver
			{24, 26, 26, 24, 20, 20, 20,20, 20, 20, 20, 20, 20, 23, 26, 26},
			//local constrast rate min
			0xd,
			//local constrast rate max
			0xd,
			//local constrast step
			0x10,
#if ((_ISP_VERSION_ == _ISP_5_1_)||(_ISP_VERSION_ == _ISP_5_1_T_))
			//ISP HDR INC RATE 0
			5,
			//ISP HDR INC RATE 1
			1,
#endif
		},
		{
			// Hist dev min
			320,
			// Hist dev max
			640,
			// Low part pct min
			36,
			// low part pct max
			100,
			//Hist distance weight
			{1.8, 1.8, 1.5, 1.5, 1.2, 1.0, 0.8, 0.4, 0.0, 0.0},
		}
	},
	// LDC parameters
	{0xE62D0, 0x33C9, 0x4DE7, 0x3F006, 0x43E31, 0x7C8D2, 0x77F, 0x437, 0x383101, 0x11C3D1, 0, },
// IR IQ
{
	// IR LSC
	{
		168,  	// Dynamic LSC Gain Threshold Low
		480,  	// Dynamic LSC Gain Threshold High	
		0x20,	// Dynamic LSC Adjust RateL
		0x00,	// Dynamic LSC Adjust RateH
		{0x20,0x20,0x20,},// gain low rate
	},

	// IR AE
	{
		// AE target
		{
			40,	// Histogram Ratio Low
			40,// Histogram Ratio High
			52,	// YMean Target Low
			58,	// YMean Target
			65,	// YMean Target High
			10,	// Histogram Position Low
			190,// Histogram Position High
			3	// Dynamic AE Target decrease value
		},
		// AE weight
		{
			{
				4,4,4,4,4,
				5,5,5,5,5,
				6,6,7,6,6,
				6,6,7,6,6,
				5,6,5,6,5,
			}
		},
	},

	// IR CCM
	{
		// normal ccm
		{
			// D65 light CCM
			//{0x206,-244,-18,-98,0x1a9,-71,-10,-244,0x1fe},
			{0xFF,0,0,0,0xFF,0,0,0,0xFF},
			// CWF light CCM
			{0x29f,-410,-5,-126,0x172,12,-25,-393,0x2a2},
			// A light CCM
			{0x213,-240,-35,-124,0x189,-12,-83,-640,0x3d3},
			// HORIZON light CCM
			{0x213,-240,-35,-124,0x189,-12,-83,-640,0x3d3},
		},
		// low lux ccm
		{
			// D65 light CCM
			{0x100, 0, 0, 0, 0x100, 0, 0, 0, 0x100},
			// CWF light CCM
			{0x100, 0, 0, 0, 0x100, 0, 0, 0, 0x100},
			// A light CCM
			{0x100, 0, 0, 0, 0x100, 0, 0, 0, 0x100},
			// HORIZON light CCM
			{0x100, 0, 0, 0, 0x100, 0, 0, 0, 0x100},
		},
		// ccm light source switch threshold
		{
			5200,	// dynamic CCM D65-CWF_H light Color Temperature Switch Threshold
			4500,	// dynamic CCM D65-CWF_L light Color Temperature Switch Threshold
			3850,	// dynamic CCM CWF_A_H light Color Temperature Switch Threshold
			3600,	// dynamic CCM CWF_A_L light Color Temperature Switch Threshold
			2700,	// dynamic CCM A_H_H light Color Temperature Switch Threshold
			2500,	// dynamic CCM A_H_L light Color Temperature Switch Threshold
		},
		// dynamic CCM Gain Threshold
		{
			800,	// dynamic CCM Gain Threshold Low
			960,	// dynamic CCM Gain Threshold High
		}
	},

	// IR Gamma
	{
		// normal light gamma
		//{0, 14, 28, 42, 53, 64, 74, 83, 89, 103, 115, 125, 134, 142, 149, 157, 163, 169, 175, 180, 185, 196, 206, 215, 223, 232, 240, 248,}, //Neil 0629 chicony tuning
		//{ 0, 15, 30, 45, 55, 65, 74, 83, 90, 103, 115, 125, 134, 142, 149, 156, 163, 169, 175, 180, 185, 195, 205, 215, 223, 232, 240, 248, },
		//{ 0, 15, 30, 45, 57, 69, 79, 89, 97, 110, 122, 132, 141, 149, 157, 164, 170, 176, 182, 187, 192, 202, 211, 220, 227, 234, 241, 248, },
		{ 0, 16, 32, 47, 60, 72, 82, 91, 99, 113, 126, 137, 146, 155, 162, 169, 175, 180, 185, 190, 195, 204, 212, 220, 227, 234, 241, 248, },
		// low light gamma
		{0, 20, 40, 56, 69, 80, 87, 93, 99, 109, 119, 128, 136, 143, 150, 157, 163, 169, 175, 181, 186, 196, 206, 215, 224, 232, 240, 248,}, //[Albert, 2011/06/09]
		600,	// dynamic Gamma Gain Threshold Low
		800	// dynamic Gamma Gain Threshold High
	},

	// IR texture
	{		
		// Gain threshold
		{
			2*16, //32, //32,		// dynamic denoise gain threshold 0
			4*16, //64, //80,		// dynamic denoise gain threshold 1
			8*16, //96, //112,		// dynamic denoise gain threshold 2
			16*16, //128, //144,		// dynamic denoise gain threshold 3
			24*16, //160, //216,		// dynamic denoise gain threshold 4
			32*16, //192, //288,		// dynamic denoise gain threshold 5
			48*16, //224, //768,		// dynamic denoise gain threshold 6
		},

		// sharpness
		{
			{	// M0
				160,		//ISP_SHARPNESS  (0x8575)
				160,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M1
				160,		//ISP_SHARPNESS  (0x8575)
				160,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M2
				160,		//ISP_SHARPNESS  (0x8575)
				160,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M3
				0xB4,		//ISP_SHARPNESS  (0x8575)
				0xB4,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M4
				0x78,		//ISP_SHARPNESS  (0x8575)
				0x78,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M5
				0x64,		//ISP_SHARPNESS  (0x8575)
				0x64,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M6
				0x50,		//ISP_SHARPNESS  (0x8575)
				0x50,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M7
				0x50,		//ISP_SHARPNESS  (0x8575)
				0x50,		//ISP_SHARP_V  (0x85A7)
			},
		},

		// static parameters
		{			
			0x8001, 0xFF,   //ISP_CONTROL1 (0x8001) //

			// static raw de-noise

			// static interpolation

			// static rgb de-noise

			// static edge enhance
			
			0x0000, 0x00,
		},

		// dynamic parameters
		{
			{ // M0
				//Raw De-noise
				0x8526, 0x04,	//ISP_NR_CHAOS_THD
				0x8525, 0x02,	//ISP_NR_CHAOS_MAX
				0x8527, 0x02,	//ISP_NR_CHAOS_CFG
				0x8510, 0x01,	//ISP_DDP_CTRL
				0x850B, 0x00,	//ISP_DDP_SEL
				0x8511, 0x04,	//ISP_DP_THD_D1
				0x8519, 0x02,	//ISP_DDP_DARK_RATE
				0x8515, 0x10,	//ISP_DP_DARK_THD_MAX
				0x8514, 0x03,	//ISP_DP_DARK_THD_MIN
				0x8517, 0x02,	//ISP_DDP_BRIGHT_RATE
				0x8513, 0x0A,	//ISP_DP_BRIGHT_THD_MAX
				0x8512, 0x02,	//ISP_DP_BRIGHT_THD_MIN
				0x8520, 0x01,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x06,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x11,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xE0,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8530, 0x10,	//ISP_INTP_EDGE_THD
				0x8531, 0x35,	//ISP_INTP_DCT_B
				0x8532, 0x0C,	//ISP_INTP_DCT_K1
				0x8533, 0x0B,	//ISP_INTP_DCT_K2
				0x8534, 0x33,	//ISP_INTP_RGB_AFFECT
				0x8535, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8536, 0x84,	//ISP_INTP_LPF_CTRL
				0x8537, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8538, 0x05,	//ISP_INTP_FCRD_SMOOTH
				0x8539, 0x20,	//ISP_MOIRE_G_AFFECT
				0x853B, 0x14,	//ISP_MOIRE_MAX
				0x854D, 0x11,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x854E, 0x50,	//ISP_ILOC_MAX
				0x854F, 0x20,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x24,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x30,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x24,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x06,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x06,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x19,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0C,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFC,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFE,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x1B,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x22,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x1A,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x1A,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x08,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x08,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				//3DNR
				0x8885, 0x01,	//TPNR_REGF_DIST_INNERRADIUS_H
				0x8886, 0x0C,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x01,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0xDF,	//TPNR_REGF_DIST_OUTERRADIUS_L
				0x8889, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_H
				0x888A, 0x3A,	//TPNR_REGF_DIST_RADIUS_INVXRATE_L
				0x888C, 0x10,	//TPNR_REGF_DIST_INNERRATE
				0x888D, 0x1C,	//TPNR_REGF_DIST_OUTERRATE
				0x888B, 0xB1,	//TPNR_REGF_LUMINANCETERM
				0x8890, 0x2A,	//TPNR_REGF_YAVG_DEFTH0
				0x8891, 0x08,	//TPNR_REGF_YAVG_THRESHOLD_STEP
				0x8892, 0x13,	//TPNR_REGF_YAVG_THRESHOLD_K_H
				0x8893, 0x40,	//TPNR_REGF_YAVG_THRESHOLD_K_L
				0x8894, 0x66,	//TPNR_REGF_YAVG_MIN_LEARNRATE
				0x8895, 0x2A,	//TPNR_REGF_YTEX_DEFTH0
				0x8896, 0x08,	//TPNR_REGF_YTEX_THRESHOLD_STEP
				0x8897, 0x19,	//TPNR_REGF_YTEX_THRESHOLD_K_H
				0x8898, 0xA0,	//TPNR_REGF_YTEX_THRESHOLD_K_L
				0x8899, 0x33,	//TPNR_REGF_YTEX_MIN_LEARNRATE
				0x889A, 0x20,	//TPNR_REGF_YEDGEHANCE
				0x0000, 0x00,
			},
			{ // M1
				//Raw De-noise
				0x8526, 0x04,	//ISP_NR_CHAOS_THD
				0x8525, 0x02,	//ISP_NR_CHAOS_MAX
				0x8527, 0x02,	//ISP_NR_CHAOS_CFG
				0x8510, 0x01,	//ISP_DDP_CTRL
				0x850B, 0x00,	//ISP_DDP_SEL
				0x8511, 0x04,	//ISP_DP_THD_D1
				0x8519, 0x02,	//ISP_DDP_DARK_RATE
				0x8515, 0x10,	//ISP_DP_DARK_THD_MAX
				0x8514, 0x03,	//ISP_DP_DARK_THD_MIN
				0x8517, 0x02,	//ISP_DDP_BRIGHT_RATE
				0x8513, 0x0A,	//ISP_DP_BRIGHT_THD_MAX
				0x8512, 0x02,	//ISP_DP_BRIGHT_THD_MIN
				0x8520, 0x01,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x0A,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x55,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xE0,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8530, 0x12,	//ISP_INTP_EDGE_THD
				0x8531, 0x35,	//ISP_INTP_DCT_B
				0x8532, 0x0C,	//ISP_INTP_DCT_K1
				0x8533, 0x0B,	//ISP_INTP_DCT_K2
				0x8534, 0x33,	//ISP_INTP_RGB_AFFECT
				0x8535, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8536, 0x84,	//ISP_INTP_LPF_CTRL
				0x8537, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8538, 0x05,	//ISP_INTP_FCRD_SMOOTH
				0x8539, 0x20,	//ISP_MOIRE_G_AFFECT
				0x853B, 0x14,	//ISP_MOIRE_MAX
				0x854D, 0x11,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x854E, 0x50,	//ISP_ILOC_MAX
				0x854F, 0x20,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x35,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x40,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x35,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x07,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x0A,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x19,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0C,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFC,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFE,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x1B,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x22,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x1A,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x1A,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x08,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x08,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0B,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				//3DNR
				0x8885, 0x01,	//TPNR_REGF_DIST_INNERRADIUS_H
				0x8886, 0x0C,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x01,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0xDF,	//TPNR_REGF_DIST_OUTERRADIUS_L
				0x8889, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_H
				0x888A, 0x3A,	//TPNR_REGF_DIST_RADIUS_INVXRATE_L
				0x888C, 0x10,	//TPNR_REGF_DIST_INNERRATE
				0x888D, 0x1C,	//TPNR_REGF_DIST_OUTERRATE
				0x888B, 0xB1,	//TPNR_REGF_LUMINANCETERM
				0x8890, 0x2A,	//TPNR_REGF_YAVG_DEFTH0
				0x8891, 0x08,	//TPNR_REGF_YAVG_THRESHOLD_STEP
				0x8892, 0x13,	//TPNR_REGF_YAVG_THRESHOLD_K_H
				0x8893, 0x40,	//TPNR_REGF_YAVG_THRESHOLD_K_L
				0x8894, 0x66,	//TPNR_REGF_YAVG_MIN_LEARNRATE
				0x8895, 0x2A,	//TPNR_REGF_YTEX_DEFTH0
				0x8896, 0x08,	//TPNR_REGF_YTEX_THRESHOLD_STEP
				0x8897, 0x19,	//TPNR_REGF_YTEX_THRESHOLD_K_H
				0x8898, 0xA0,	//TPNR_REGF_YTEX_THRESHOLD_K_L
				0x8899, 0x33,	//TPNR_REGF_YTEX_MIN_LEARNRATE
				0x889A, 0x20,	//TPNR_REGF_YEDGEHANCE
				0x0000, 0x00,
			},
			{ // M2
				//Raw De-noise
				0x8526, 0x04,	//ISP_NR_CHAOS_THD
				0x8525, 0x02,	//ISP_NR_CHAOS_MAX
				0x8527, 0x02,	//ISP_NR_CHAOS_CFG
				0x8510, 0x01,	//ISP_DDP_CTRL
				0x850B, 0x00,	//ISP_DDP_SEL
				0x8511, 0x04,	//ISP_DP_THD_D1
				0x8519, 0x02,	//ISP_DDP_DARK_RATE
				0x8515, 0x10,	//ISP_DP_DARK_THD_MAX
				0x8514, 0x03,	//ISP_DP_DARK_THD_MIN
				0x8517, 0x02,	//ISP_DDP_BRIGHT_RATE
				0x8513, 0x0A,	//ISP_DP_BRIGHT_THD_MAX
				0x8512, 0x02,	//ISP_DP_BRIGHT_THD_MIN
				0x8520, 0x81,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x0F,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xE0,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8530, 0x14,	//ISP_INTP_EDGE_THD
				0x8531, 0x35,	//ISP_INTP_DCT_B
				0x8532, 0x0C,	//ISP_INTP_DCT_K1
				0x8533, 0x0B,	//ISP_INTP_DCT_K2
				0x8534, 0x33,	//ISP_INTP_RGB_AFFECT
				0x8535, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8536, 0x84,	//ISP_INTP_LPF_CTRL
				0x8537, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8538, 0x05,	//ISP_INTP_FCRD_SMOOTH
				0x8539, 0x20,	//ISP_MOIRE_G_AFFECT
				0x853B, 0x14,	//ISP_MOIRE_MAX
				0x854D, 0x11,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x854E, 0x50,	//ISP_ILOC_MAX
				0x854F, 0x20,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x46,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x50,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x46,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x08,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x12,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x19,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0C,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFC,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFE,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x1B,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x22,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x1A,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x1A,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x08,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x08,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0C,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				//3DNR
				0x8885, 0x01,	//TPNR_REGF_DIST_INNERRADIUS_H
				0x8886, 0x0C,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x01,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0xDF,	//TPNR_REGF_DIST_OUTERRADIUS_L
				0x8889, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_H
				0x888A, 0x3A,	//TPNR_REGF_DIST_RADIUS_INVXRATE_L
				0x888C, 0x10,	//TPNR_REGF_DIST_INNERRATE
				0x888D, 0x1C,	//TPNR_REGF_DIST_OUTERRATE
				0x888B, 0xB1,	//TPNR_REGF_LUMINANCETERM
				0x8890, 0x2A,	//TPNR_REGF_YAVG_DEFTH0
				0x8891, 0x08,	//TPNR_REGF_YAVG_THRESHOLD_STEP
				0x8892, 0x13,	//TPNR_REGF_YAVG_THRESHOLD_K_H
				0x8893, 0x40,	//TPNR_REGF_YAVG_THRESHOLD_K_L
				0x8894, 0x66,	//TPNR_REGF_YAVG_MIN_LEARNRATE
				0x8895, 0x2A,	//TPNR_REGF_YTEX_DEFTH0
				0x8896, 0x08,	//TPNR_REGF_YTEX_THRESHOLD_STEP
				0x8897, 0x19,	//TPNR_REGF_YTEX_THRESHOLD_K_H
				0x8898, 0xA0,	//TPNR_REGF_YTEX_THRESHOLD_K_L
				0x8899, 0x33,	//TPNR_REGF_YTEX_MIN_LEARNRATE
				0x889A, 0x20,	//TPNR_REGF_YEDGEHANCE
				0x0000, 0x00,
			},
			{ // M3
				//Raw De-noise
				0x8526, 0x04,	//ISP_NR_CHAOS_THD
				0x8525, 0x02,	//ISP_NR_CHAOS_MAX
				0x8527, 0x02,	//ISP_NR_CHAOS_CFG
				0x8510, 0x01,	//ISP_DDP_CTRL
				0x850B, 0x00,	//ISP_DDP_SEL
				0x8511, 0x04,	//ISP_DP_THD_D1
				0x8519, 0x02,	//ISP_DDP_DARK_RATE
				0x8515, 0x10,	//ISP_DP_DARK_THD_MAX
				0x8514, 0x03,	//ISP_DP_DARK_THD_MIN
				0x8517, 0x02,	//ISP_DDP_BRIGHT_RATE
				0x8513, 0x0A,	//ISP_DP_BRIGHT_THD_MAX
				0x8512, 0x02,	//ISP_DP_BRIGHT_THD_MIN
				0x8520, 0x01,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x14,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xE0,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8530, 0x18,	//ISP_INTP_EDGE_THD
				0x8531, 0x35,	//ISP_INTP_DCT_B
				0x8532, 0x0C,	//ISP_INTP_DCT_K1
				0x8533, 0x0B,	//ISP_INTP_DCT_K2
				0x8534, 0x33,	//ISP_INTP_RGB_AFFECT
				0x8535, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8536, 0x84,	//ISP_INTP_LPF_CTRL
				0x8537, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8538, 0x05,	//ISP_INTP_FCRD_SMOOTH
				0x8539, 0x20,	//ISP_MOIRE_G_AFFECT
				0x853B, 0x14,	//ISP_MOIRE_MAX
				0x854D, 0x11,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x854E, 0x50,	//ISP_ILOC_MAX
				0x854F, 0x20,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x57,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x57,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x09,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x18,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x19,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0C,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFC,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFE,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x1B,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x22,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x1A,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x1A,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x08,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x08,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0D,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				//3DNR
				0x8885, 0x01,	//TPNR_REGF_DIST_INNERRADIUS_H
				0x8886, 0x0C,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x01,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0xDF,	//TPNR_REGF_DIST_OUTERRADIUS_L
				0x8889, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_H
				0x888A, 0x3A,	//TPNR_REGF_DIST_RADIUS_INVXRATE_L
				0x888C, 0x10,	//TPNR_REGF_DIST_INNERRATE
				0x888D, 0x1C,	//TPNR_REGF_DIST_OUTERRATE
				0x888B, 0xB1,	//TPNR_REGF_LUMINANCETERM
				0x8890, 0x2A,	//TPNR_REGF_YAVG_DEFTH0
				0x8891, 0x08,	//TPNR_REGF_YAVG_THRESHOLD_STEP
				0x8892, 0x13,	//TPNR_REGF_YAVG_THRESHOLD_K_H
				0x8893, 0x40,	//TPNR_REGF_YAVG_THRESHOLD_K_L
				0x8894, 0x66,	//TPNR_REGF_YAVG_MIN_LEARNRATE
				0x8895, 0x2A,	//TPNR_REGF_YTEX_DEFTH0
				0x8896, 0x08,	//TPNR_REGF_YTEX_THRESHOLD_STEP
				0x8897, 0x19,	//TPNR_REGF_YTEX_THRESHOLD_K_H
				0x8898, 0xA0,	//TPNR_REGF_YTEX_THRESHOLD_K_L
				0x8899, 0x33,	//TPNR_REGF_YTEX_MIN_LEARNRATE
				0x889A, 0x20,	//TPNR_REGF_YEDGEHANCE
				0x0000, 0x00,
			},
			{ // M4
				//Raw De-noise
				0x8526, 0x04,	//ISP_NR_CHAOS_THD
				0x8525, 0x02,	//ISP_NR_CHAOS_MAX
				0x8527, 0x02,	//ISP_NR_CHAOS_CFG
				0x8510, 0x01,	//ISP_DDP_CTRL
				0x850B, 0x00,	//ISP_DDP_SEL
				0x8511, 0x04,	//ISP_DP_THD_D1
				0x8519, 0x02,	//ISP_DDP_DARK_RATE
				0x8515, 0x10,	//ISP_DP_DARK_THD_MAX
				0x8514, 0x03,	//ISP_DP_DARK_THD_MIN
				0x8517, 0x02,	//ISP_DDP_BRIGHT_RATE
				0x8513, 0x0A,	//ISP_DP_BRIGHT_THD_MAX
				0x8512, 0x02,	//ISP_DP_BRIGHT_THD_MIN
				0x8520, 0x81,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x10,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xE0,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8530, 0x18,	//ISP_INTP_EDGE_THD
				0x8531, 0x35,	//ISP_INTP_DCT_B
				0x8532, 0x0C,	//ISP_INTP_DCT_K1
				0x8533, 0x0A,	//ISP_INTP_DCT_K2
				0x8534, 0x33,	//ISP_INTP_RGB_AFFECT
				0x8535, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8536, 0x84,	//ISP_INTP_LPF_CTRL
				0x8537, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8538, 0x05,	//ISP_INTP_FCRD_SMOOTH
				0x8539, 0x20,	//ISP_MOIRE_G_AFFECT
				0x853B, 0x14,	//ISP_MOIRE_MAX
				0x854D, 0x11,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x854E, 0x50,	//ISP_ILOC_MAX
				0x854F, 0x30,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x57,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0A,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x18,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x16,	//ISP_LOC_MAX
				0x85B5, 0x54,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0A,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFE,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x1B,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x22,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x1A,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x1A,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0A,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0A,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				//3DNR
				0x8885, 0x01,	//TPNR_REGF_DIST_INNERRADIUS_H
				0x8886, 0x0C,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x01,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0xDF,	//TPNR_REGF_DIST_OUTERRADIUS_L
				0x8889, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_H
				0x888A, 0x3A,	//TPNR_REGF_DIST_RADIUS_INVXRATE_L
				0x888C, 0x10,	//TPNR_REGF_DIST_INNERRATE
				0x888D, 0x1C,	//TPNR_REGF_DIST_OUTERRATE
				0x888B, 0xB1,	//TPNR_REGF_LUMINANCETERM
				0x8890, 0x2A,	//TPNR_REGF_YAVG_DEFTH0
				0x8891, 0x08,	//TPNR_REGF_YAVG_THRESHOLD_STEP
				0x8892, 0x13,	//TPNR_REGF_YAVG_THRESHOLD_K_H
				0x8893, 0x40,	//TPNR_REGF_YAVG_THRESHOLD_K_L
				0x8894, 0x66,	//TPNR_REGF_YAVG_MIN_LEARNRATE
				0x8895, 0x2A,	//TPNR_REGF_YTEX_DEFTH0
				0x8896, 0x08,	//TPNR_REGF_YTEX_THRESHOLD_STEP
				0x8897, 0x19,	//TPNR_REGF_YTEX_THRESHOLD_K_H
				0x8898, 0xA0,	//TPNR_REGF_YTEX_THRESHOLD_K_L
				0x8899, 0x33,	//TPNR_REGF_YTEX_MIN_LEARNRATE
				0x889A, 0x20,	//TPNR_REGF_YEDGEHANCE
				0x0000, 0x00,
			},
			{ // M5
				//Raw De-noise
				0x8526, 0x04,	//ISP_NR_CHAOS_THD
				0x8525, 0x02,	//ISP_NR_CHAOS_MAX
				0x8527, 0x02,	//ISP_NR_CHAOS_CFG
				0x8510, 0x01,	//ISP_DDP_CTRL
				0x850B, 0x00,	//ISP_DDP_SEL
				0x8511, 0x04,	//ISP_DP_THD_D1
				0x8519, 0x02,	//ISP_DDP_DARK_RATE
				0x8515, 0x10,	//ISP_DP_DARK_THD_MAX
				0x8514, 0x03,	//ISP_DP_DARK_THD_MIN
				0x8517, 0x02,	//ISP_DDP_BRIGHT_RATE
				0x8513, 0x0A,	//ISP_DP_BRIGHT_THD_MAX
				0x8512, 0x02,	//ISP_DP_BRIGHT_THD_MIN
				0x8520, 0x81,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x16,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xE0,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8530, 0x18,	//ISP_INTP_EDGE_THD
				0x8531, 0x35,	//ISP_INTP_DCT_B
				0x8532, 0x0C,	//ISP_INTP_DCT_K1
				0x8533, 0x0A,	//ISP_INTP_DCT_K2
				0x8534, 0x33,	//ISP_INTP_RGB_AFFECT
				0x8535, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8536, 0x84,	//ISP_INTP_LPF_CTRL
				0x8537, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8538, 0x05,	//ISP_INTP_FCRD_SMOOTH
				0x8539, 0x20,	//ISP_MOIRE_G_AFFECT
				0x853B, 0x14,	//ISP_MOIRE_MAX
				0x854D, 0x11,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x854E, 0x50,	//ISP_ILOC_MAX
				0x854F, 0x30,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x57,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0B,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x18,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x16,	//ISP_LOC_MAX
				0x85B5, 0x54,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0A,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFE,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x1B,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x22,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x1A,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x1A,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0A,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0A,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				//3DNR
				0x8885, 0x01,	//TPNR_REGF_DIST_INNERRADIUS_H
				0x8886, 0x0C,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x01,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0xDF,	//TPNR_REGF_DIST_OUTERRADIUS_L
				0x8889, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_H
				0x888A, 0x3A,	//TPNR_REGF_DIST_RADIUS_INVXRATE_L
				0x888C, 0x10,	//TPNR_REGF_DIST_INNERRATE
				0x888D, 0x1C,	//TPNR_REGF_DIST_OUTERRATE
				0x888B, 0xB1,	//TPNR_REGF_LUMINANCETERM
				0x8890, 0x2A,	//TPNR_REGF_YAVG_DEFTH0
				0x8891, 0x08,	//TPNR_REGF_YAVG_THRESHOLD_STEP
				0x8892, 0x13,	//TPNR_REGF_YAVG_THRESHOLD_K_H
				0x8893, 0x40,	//TPNR_REGF_YAVG_THRESHOLD_K_L
				0x8894, 0x66,	//TPNR_REGF_YAVG_MIN_LEARNRATE
				0x8895, 0x2A,	//TPNR_REGF_YTEX_DEFTH0
				0x8896, 0x08,	//TPNR_REGF_YTEX_THRESHOLD_STEP
				0x8897, 0x19,	//TPNR_REGF_YTEX_THRESHOLD_K_H
				0x8898, 0xA0,	//TPNR_REGF_YTEX_THRESHOLD_K_L
				0x8899, 0x33,	//TPNR_REGF_YTEX_MIN_LEARNRATE
				0x889A, 0x20,	//TPNR_REGF_YEDGEHANCE
				0x0000, 0x00,
			},
			{ // M6
				//Raw De-noise
				0x8526, 0x04,	//ISP_NR_CHAOS_THD
				0x8525, 0x02,	//ISP_NR_CHAOS_MAX
				0x8527, 0x02,	//ISP_NR_CHAOS_CFG
				0x8510, 0x01,	//ISP_DDP_CTRL
				0x850B, 0x00,	//ISP_DDP_SEL
				0x8511, 0x04,	//ISP_DP_THD_D1
				0x8519, 0x02,	//ISP_DDP_DARK_RATE
				0x8515, 0x10,	//ISP_DP_DARK_THD_MAX
				0x8514, 0x03,	//ISP_DP_DARK_THD_MIN
				0x8517, 0x02,	//ISP_DDP_BRIGHT_RATE
				0x8513, 0x0A,	//ISP_DP_BRIGHT_THD_MAX
				0x8512, 0x02,	//ISP_DP_BRIGHT_THD_MIN
				0x8520, 0x81,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x1C,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xE0,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8530, 0x18,	//ISP_INTP_EDGE_THD
				0x8531, 0x35,	//ISP_INTP_DCT_B
				0x8532, 0x0C,	//ISP_INTP_DCT_K1
				0x8533, 0x0A,	//ISP_INTP_DCT_K2
				0x8534, 0x33,	//ISP_INTP_RGB_AFFECT
				0x8535, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8536, 0x84,	//ISP_INTP_LPF_CTRL
				0x8537, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8538, 0x05,	//ISP_INTP_FCRD_SMOOTH
				0x8539, 0x20,	//ISP_MOIRE_G_AFFECT
				0x853B, 0x14,	//ISP_MOIRE_MAX
				0x854D, 0x11,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x854E, 0x50,	//ISP_ILOC_MAX
				0x854F, 0x30,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x68,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x68,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0C,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x18,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x19,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0A,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFE,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x1B,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x22,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x1A,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x1A,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0A,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0A,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				//3DNR
				0x8885, 0x01,	//TPNR_REGF_DIST_INNERRADIUS_H
				0x8886, 0x0C,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x01,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0xDF,	//TPNR_REGF_DIST_OUTERRADIUS_L
				0x8889, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_H
				0x888A, 0x3A,	//TPNR_REGF_DIST_RADIUS_INVXRATE_L
				0x888C, 0x10,	//TPNR_REGF_DIST_INNERRATE
				0x888D, 0x1C,	//TPNR_REGF_DIST_OUTERRATE
				0x888B, 0xB1,	//TPNR_REGF_LUMINANCETERM
				0x8890, 0x2A,	//TPNR_REGF_YAVG_DEFTH0
				0x8891, 0x08,	//TPNR_REGF_YAVG_THRESHOLD_STEP
				0x8892, 0x13,	//TPNR_REGF_YAVG_THRESHOLD_K_H
				0x8893, 0x40,	//TPNR_REGF_YAVG_THRESHOLD_K_L
				0x8894, 0x66,	//TPNR_REGF_YAVG_MIN_LEARNRATE
				0x8895, 0x2A,	//TPNR_REGF_YTEX_DEFTH0
				0x8896, 0x08,	//TPNR_REGF_YTEX_THRESHOLD_STEP
				0x8897, 0x19,	//TPNR_REGF_YTEX_THRESHOLD_K_H
				0x8898, 0xA0,	//TPNR_REGF_YTEX_THRESHOLD_K_L
				0x8899, 0x33,	//TPNR_REGF_YTEX_MIN_LEARNRATE
				0x889A, 0x20,	//TPNR_REGF_YEDGEHANCE
				0x0000, 0x00,
			},
			{ // M7
				//Raw De-noise
				0x8526, 0x04,	//ISP_NR_CHAOS_THD
				0x8525, 0x02,	//ISP_NR_CHAOS_MAX
				0x8527, 0x02,	//ISP_NR_CHAOS_CFG
				0x8510, 0x01,	//ISP_DDP_CTRL
				0x850B, 0x00,	//ISP_DDP_SEL
				0x8511, 0x04,	//ISP_DP_THD_D1
				0x8519, 0x02,	//ISP_DDP_DARK_RATE
				0x8515, 0x10,	//ISP_DP_DARK_THD_MAX
				0x8514, 0x03,	//ISP_DP_DARK_THD_MIN
				0x8517, 0x02,	//ISP_DDP_BRIGHT_RATE
				0x8513, 0x0A,	//ISP_DP_BRIGHT_THD_MAX
				0x8512, 0x02,	//ISP_DP_BRIGHT_THD_MIN
				0x8520, 0x81,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x1C,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xE0,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8530, 0x18,	//ISP_INTP_EDGE_THD
				0x8531, 0x35,	//ISP_INTP_DCT_B
				0x8532, 0x0C,	//ISP_INTP_DCT_K1
				0x8533, 0x0A,	//ISP_INTP_DCT_K2
				0x8534, 0x33,	//ISP_INTP_RGB_AFFECT
				0x8535, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8536, 0x84,	//ISP_INTP_LPF_CTRL
				0x8537, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8538, 0x05,	//ISP_INTP_FCRD_SMOOTH
				0x8539, 0x20,	//ISP_MOIRE_G_AFFECT
				0x853B, 0x14,	//ISP_MOIRE_MAX
				0x854D, 0x11,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x854E, 0x50,	//ISP_ILOC_MAX
				0x854F, 0x30,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x68,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x68,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0C,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x18,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x19,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0A,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFE,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x1B,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x22,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x1A,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x1A,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0A,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0A,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				//3DNR
				0x8885, 0x01,	//TPNR_REGF_DIST_INNERRADIUS_H
				0x8886, 0x0C,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x01,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0xDF,	//TPNR_REGF_DIST_OUTERRADIUS_L
				0x8889, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_H
				0x888A, 0x3A,	//TPNR_REGF_DIST_RADIUS_INVXRATE_L
				0x888C, 0x10,	//TPNR_REGF_DIST_INNERRATE
				0x888D, 0x1C,	//TPNR_REGF_DIST_OUTERRATE
				0x888B, 0xB1,	//TPNR_REGF_LUMINANCETERM
				0x8890, 0x2A,	//TPNR_REGF_YAVG_DEFTH0
				0x8891, 0x08,	//TPNR_REGF_YAVG_THRESHOLD_STEP
				0x8892, 0x13,	//TPNR_REGF_YAVG_THRESHOLD_K_H
				0x8893, 0x40,	//TPNR_REGF_YAVG_THRESHOLD_K_L
				0x8894, 0x66,	//TPNR_REGF_YAVG_MIN_LEARNRATE
				0x8895, 0x2A,	//TPNR_REGF_YTEX_DEFTH0
				0x8896, 0x08,	//TPNR_REGF_YTEX_THRESHOLD_STEP
				0x8897, 0x19,	//TPNR_REGF_YTEX_THRESHOLD_K_H
				0x8898, 0xA0,	//TPNR_REGF_YTEX_THRESHOLD_K_L
				0x8899, 0x33,	//TPNR_REGF_YTEX_MIN_LEARNRATE
				0x889A, 0x20,	//TPNR_REGF_YEDGEHANCE
				0x0000, 0x00,
			}
		},
	}, // IR texture
},  //IR IQ end	

};
#endif // _OV9726_IQ_H_
