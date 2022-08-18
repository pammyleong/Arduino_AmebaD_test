#ifndef _AR0237_IQ_H_
#define _AR0237_IQ_H_

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
      		  //{33,33,33,40}, //R / GR / GB / B
      		  	//{0, 0, 0, 0},
      		  	{40, 40, 40, 40},
	},

	// LSC
	{
		// circle LSC for small resolution
		{
			{
				// circle LSC curve
				{
					//{129,   0, 130,   0, 132,   0, 135,   0, 137,   0, 140,   0, 144,   0, 149,   0, 154,   0, 161,   0, 169,   0, 178,   0, 189,   0, 201,   0, 215,   0, 229,   0, 246,   0,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1, },
					//{128,   0, 130,   0, 132,   0, 134,   0, 137,   0, 140,   0, 144,   0, 148,   0, 154,   0, 161,   0, 169,   0, 179,   0, 190,   0, 204,   0, 219,   0, 234,   0, 249,   0,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1, },
					//{128,   0, 129,   0, 131,   0, 133,   0, 135,   0, 138,   0, 142,   0, 145,   0, 150,   0, 156,   0, 164,   0, 172,   0, 183,   0, 195,   0, 208,   0, 221,   0, 233,   0, 246,   0, 246,   0, 246,   0, 246,   0, 246,   0, 246,   0, 246,   0, },
					//{129,   0, 131,   0, 135,   0, 139,   0, 143,   0, 148,   0, 155,   0, 164,   0, 174,   0, 187,   0, 202,   0, 220,   0, 241,   0,  11,   1,  42,   1,  72,   1, 112,   1, 157,   1, 157,   1, 157,   1, 157,   1, 157,   1, 157,   1, 157,   1, },
					//{128,   0, 131,   0, 134,   0, 137,   0, 141,   0, 146,   0, 153,   0, 161,   0, 171,   0, 183,   0, 197,   0, 214,   0, 235,   0,   4,   1,  34,   1,  64,   1, 102,   1, 145,   1, 145,   1, 145,   1, 145,   1, 145,   1, 145,   1, 145,   1, },
					//{128,   0, 130,   0, 133,   0, 136,   0, 140,   0, 144,   0, 150,   0, 157,   0, 165,   0, 175,   0, 187,   0, 202,   0, 219,   0, 241,   0,   9,   1,  33,   1,  61,   1,  93,   1,  93,   1,  93,   1,  93,   1,  93,   1,  93,   1,  93,   1, },
					{128,   0, 130,   0, 134,   0, 138,   0, 142,   0, 147,   0, 154,   0, 163,   0, 173,   0, 185,   0, 200,   0, 217,   0, 238,   0,   8,   1,  38,   1,  68,   1, 107,   1, 151,   1, 151,   1, 151,   1, 151,   1, 151,   1, 151,   1, 151,   1, },
					{129,   0, 131,   0, 133,   0, 137,   0, 141,   0, 146,   0, 153,   0, 161,   0, 171,   0, 183,   0, 197,   0, 213,   0, 234,   0,   3,   1,  32,   1,  61,   1,  99,   1, 141,   1, 141,   1, 141,   1, 141,   1, 141,   1, 141,   1, 141,   1, },
					{129,   0, 131,   0, 133,   0, 136,   0, 140,   0, 144,   0, 150,   0, 156,   0, 165,   0, 175,   0, 187,   0, 201,   0, 218,   0, 240,   0,   8,   1,  32,   1,  60,   1,  91,   1,  91,   1,  91,   1,  91,   1,  91,   1,  91,   1,  91,   1, },

          		      },
				// circle LSC center: R Center Hortizontal, R Center Vertical, G Center Hortizontal, G Center Vertical,B Center Hortizontal, B Center Vertical
				  //{968,578,968,578,968,578}, //For5000k
				  //{947,536,947,536,947,536},
				  {950,538,950,538,950,538},
				// step
				64,
			},

			// micro LSC
			{
				// micro LSC grid mode
				2,
				// micro LSC matrix
				{
					// flip - 0   mirror - 0
					{0},
					// flip - 0   mirror - 1
					{0},
					// flip - 1   mirror - 0
					{0},
					// flip - 1   mirror - 1
					{0},
				},
			},
		},

#ifdef _MULTIPLE_LSC_CONFIG_
		// circle LSC for big resolution
		{
			{
				// circle LSC curve
				{
					{128,   0, 129,   0, 131,   0, 134,   0, 137,   0, 141,   0, 146,   0, 152,   0, 160,   0, 169,   0, 179,   0, 192,   0, 207,   0, 225,   0, 246,   0,  12,   1,  45,   1,  81,   1,  81,   1,  81,   1,  81,   1,  81,   1,  81,   1,  81,   1, },
					{128,   0, 129,   0, 131,   0, 134,   0, 137,   0, 140,   0, 145,   0, 151,   0, 159,   0, 167,   0, 178,   0, 190,   0, 205,   0, 223,   0, 244,   0,  10,   1,  41,   1,  77,   1,  77,   1,  77,   1,  77,   1,  77,   1,  77,   1,  77,   1, },
					{128,   0, 128,   0, 130,   0, 133,   0, 135,   0, 139,   0, 143,   0, 148,   0, 154,   0, 162,   0, 172,   0, 183,   0, 196,   0, 213,   0, 232,   0, 251,   0,  22,   1,  52,   1,  52,   1,  52,   1,  52,   1,  52,   1,  52,   1,  52,   1, },
          		      },
				// circle LSC center: R Center Hortizontal, R Center Vertical, G Center Hortizontal, G Center Vertical,B Center Hortizontal, B Center Vertical
				  {960,540,960,540,960,540}, //For5000k
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
			128,   // Dynamic LSC Gain Threshold Low
			256,  // Dynamic LSC Gain Threshold High
			0x20,	// Dynamic LSC Adjust rate at Gain Threshold Low
			0x0D,	// Dynamic LSC Adjust rate at Gain Threshold High
	             {27,31,38,41,48,50},	// rough r gain before LSC, from A, U30, CWF, D50, D65, D75
          		{104,86,71,51,43,40},	// rough b gain before LSC
			50,		// start threshold of dynamic LSC by CT, white pixel millesimal
			25,		// end threshold of dynamic LSC by CT, white pixel millesimal
			100,		// LSC switch color temperature threshold buffer
			{3100,3800,4700,5800,7000},	// LSC switch color temperature threshold
			{
				//{0x20,0x20,0x20,},//a=2850k
				//{0x20,0x20,0x20,},//3500k
				//{0x20,0x20,0x20,},//cwf=4150k
				//{0x20,0x20,0x20,},//d50=5000k
				//{0x1E,0x20,0x20,},//d65=6500k
				//{0x20,0x20,0x20,},//d75=6500k
				{0x1c,0x1c,0x1c,},
				{0x1c,0x1c,0x1c,},
				{0x1c,0x1c,0x1c,},
				{0x1c,0x1c,0x1c,},
				{0x1c,0x1c,0x1c,},
				{0x1c,0x1c,0x1c,},
			},
		},
	},

	// CCM
	{
		// normal ccm
		{
	            // D65 light CCM
	            //{0x1c0,-80,-112,-70,0x17c/*(0x17c-10)*/,-54,16,-64,0x130},	//For MSOC test, pass premium
	            //{274, -24, 6, -5, 301,-39, -3, 41, 218,},
	            {0x159,-99,9,-83,0x126,44,9,-147,0x189,},
				// D50 light CCM
	            //{0x1a3,-77,-86,-102,0x19c,-54,26,-109,0x153},	//For MSOC test, pass premium
	            {0x150,-80,0,-112,0x150,32,16,-176,0x1a0,},
	            // TL84 light CCM
	            //{0x1cd,-93,-112,-64,0x144,-4,32,-109,0x14d},	//For MSOC test, pass premium
	            {0x160,-48,-48,-96,0x150,16,-16,-128,0x190,},
	            // A light CCM
	            //{0x1bd,-77,-112,-96,0x164,-4,-16,-125,0x18d},	//For MSOC test, pass premium
				{0x1a0,-192,32,-80,0xe0,112,0,-272,0x210,},
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
	            6000, //6200,	// dynamic CCM D65-CWF_H light Color Temperature Switch Threshold
	            5600, //5800,	// dynamic CCM D65-CWF_L light Color Temperature Switch Threshold
	            4600, //4500,	// dynamic CCM CWF_A_H light Color Temperature Switch Threshold
	            4200, //4200,	// dynamic CCM CWF_A_L light Color Temperature Switch Threshold
	            3500, //3200,	// dynamic CCM A_H_H light Color Temperature Switch Threshold
	            3200, //3000,	// dynamic CCM A_H_L light Color Temperature Switch Threshold
		},
		// dynamic CCM Gain Threshold 
		{
			192, //32,	// dynamic CCM Gain Threshold Low
			384, //2048,	// dynamic CCM Gain Threshold High		
		}	
	},

	// Gamma
	{
		// normal light gamma
		{0, 13, 25, 36, 46, 56, 66, 74, 83, 98, 111, 124, 135, 145, 154, 163, 170, 178, 184, 191, 197, 207, 216, 225, 232, 238, 244, 250, },
		// low light gamma
		//{ 0, 31, 45, 55, 63, 71, 78, 84, 90, 100, 110, 119, 127, 135, 142, 149, 156, 162, 168, 174, 180, 191, 201, 211, 221, 230, 238, 247,},
		{0, 13, 25, 36, 46, 56, 66, 74, 83, 98, 111, 124, 135, 145, 154, 163, 170, 178, 184, 191, 197, 207, 216, 225, 232, 238, 244, 250, },
		384,	// dynamic Gamma Gain Threshold Low
		1024,// dynamic Gamma Gain Threshold High
	},

	// AE
	{
		// AE target
		{
			40,	// Histogram Ratio Low
			40,// Histogram Ratio High
			35,	// YMean Target Low
			40, //55,	// YMean Target
			45, //60,	// YMean Target High
			0,	// Histogram Position Low
			170,// Histogram Position High
			7	// Dynamic AE Target decrease value
		},
		// AE limit
		{
			6,	// AE step Max value at 50Hz power line frequency
			8,	// AE step Max value at 60Hz power line frequency
			1024,	// AE global gain Max value
			{560, 560, 1200, 1200, 1200},	// AE continous frame rate gain threshold
			20, //User manual min FPS
			220,	// AE discrete frame rate 15fps gain threshold
			96,	// AE discrete frame rate 30fps gain threshold
			120	,// AE HighLight mode threshold
		},
		// AE weight
		{
			{
				1,1,1,1,1,
				1,2,2,2,1,
				1,2,2,2,1,
				1,2,2,2,1,
				1,1,1,1,1,
			}
		},
		// AE sensitivity
		{
			0.05,// g_fAEC_Adjust_Th
			16,	// AE Latency time
			//20,	// Ymean diff threshold for judge AE same block
			8,	// hemonel 2011-07-14: modify Neil adjust parameter from 20 to 8
			22	// same block count threshold for judge AE scene variation
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
	            //{27,31,38,41,48,50},	// rough r gain before LSC, from A, U30, CWF, D50, D65, D75
          		//{104,86,71,51,43,40},	// rough b gain before LSC
	            {33, 31, 40, 43, 51, 54},
	            {96, 94, 71, 53, 45, 42},
				9,	// K1
	            95, //90,	// B1
	            60, //55,	// B2
	            10,	// sK3
	            32, //25,	// sB3
	            16,	// sK4
	            -74, //-79,	// sB4
	            50,	// sK5
	            -50,	// sB5
	            2,	// sK6
	            10, //11,	// sB6
	            105, //100,	// B_up
	            50, //45,	// B_down
	            43, //40,	// sB_left
	            -94,	// sB_right
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
			20,	// g_byAWBFineMin_Bright
			16// g_byFtGainTh
		},
		// AWB sensitivity
		{
			4, // g_wAWBGainDiffTh
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
				150,		//ISP_SHARPNESS  (0x8575)
				150,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M2
				140,		//ISP_SHARPNESS  (0x8575)
				140,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M3
				130,		//ISP_SHARPNESS  (0x8575)
				130,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M4
				120,		//ISP_SHARPNESS  (0x8575)
				120,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M5
				110,		//ISP_SHARPNESS  (0x8575)
				110,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M6
				100,		//ISP_SHARPNESS  (0x8575)
				100,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M7
				100,		//ISP_SHARPNESS  (0x8575)
				100,		//ISP_SHARP_V  (0x85A7)
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
			{// M0
				// M0 - raw de-noise
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
				0x8520, 0x82,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_NR_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_NR_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_NR_GRGB_BLNC_D1
				//0x8507, 0x00,	//ISP_GLOC_MAX
				//0x8508, 0x00,	//ISP_GLOC_RATE
				0x851A, 0x00,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x02,	//ISP_RDLOC_MAX
				0x8505, 0x0B,	//ISP_RDLOC_RATE
				0x8506, 0x01,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x11,	//ISP_NR_MODE
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
				
				// M0 - interpolation
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

				// M0 - rgb de-noise
				0x8550, 0x03,	//ISP_RGB_IIR_CTRL
				0x8552, 0x33,	//ISP_RGB_HLPF_COEF
				0x8551, 0x30,	//ISP_RGB_VIIR_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x06,	//ISP_RGB_DIIR_COEF
				0x8556, 0x01,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855a, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855b, 0x0a,	//ISP_RGB_DIIR_CHANGE_THD4

				// M0 - edge enhance
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
				0x85B5, 0x5C,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x18,	//ISP_EDG_DIFF_C0
				0x8561, 0x02,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x06,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFC,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				//0x8575, 0xA0,	//ISP_SHARPNESS
				//0x85A7, 0xA0,	//ISP_SHARPNESS_V
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x10,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x0E,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x10,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x12,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x1E,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x28,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x01,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x82,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS	// ???

				0x0000, 0x00,
			},
			{// M1
				// M1 - raw de-noise
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
				0x8520, 0x82,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_NR_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_NR_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_NR_GRGB_BLNC_D1
				/////0x8507, 0x00,	//ISP_GLOC_MAX
				/////0x8508, 0x00,	//ISP_GLOC_RATE
				0x851A, 0x03,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x02,	//ISP_RDLOC_MAX
				0x8505, 0x0B,	//ISP_RDLOC_RATE
				0x8506, 0x01,	//ISP_RDLOC_ENABLE
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
				0x8516, 0x01,	//ISP_NR_BDRY_SEL
				0x8518, 0x00,	//ISP_DPC_SEL

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

				// M1 - rgb de-noise
				0x8550, 0x03,	//ISP_RGB_IIR_CTRL
				0x8552, 0x34,	//ISP_RGB_HLPF_COEF
				0x8551, 0x30,	//ISP_RGB_VIIR_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x06,	//ISP_RGB_DIIR_COEF
				0x8556, 0x01,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08, 	//ISP_RGB_DIIR_CHANGE_THD2
				0x855a, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855b, 0x0a,	//ISP_RGB_DIIR_CHANGE_THD4

				// M1 - edge enhance
				0x8565, 0x08,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x5C,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x18,	//ISP_EDG_DIFF_C0
				0x8561, 0x02,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x06,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFC,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				//0x8575, 0x9C,	//ISP_SHARPNESS
				//0x85A7, 0x9C,	//ISP_SHARPNESS_V
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x10,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x0E,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x10,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x12,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x1E,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x28,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85a8, 0x01,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x82,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS
				0x8574, 0x32,	//ISP_RELIEVO_BRIGHT

				0x0000, 0x00,
			},
			{// M2
				// M2 - raw de-noise
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
				0x8520, 0x82,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_NR_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_NR_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_NR_GRGB_BLNC_D1
				//0x8507, 0x00,	//ISP_GLOC_MAX
				//0x8508, 0x00,	//ISP_GLOC_RATE
				0x851A, 0x07,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x02,	//ISP_RDLOC_MAX
				0x8505, 0x0B,	//ISP_RDLOC_RATE
				0x8506, 0x01,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x66,	//ISP_NR_MODE
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
				0x8516, 0x01,	//ISP_NR_BDRY_SEL
				0x8518, 0x00,	//ISP_DPC_SEL
				
				// M2 - interpolation
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
				
				// M2 - rgb de-noise
				0x8550, 0x03,	//ISP_RGB_IIR_CTRL
				0x8552, 0x44,	//ISP_RGB_HLPF_COEF
				0x8551, 0x40,	//ISP_RGB_VIIR_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x06,	//ISP_RGB_DIIR_COEF
				0x8556, 0x01,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08, 	//ISP_RGB_DIIR_CHANGE_THD2
				0x855a, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855b, 0x0a,	//ISP_RGB_DIIR_CHANGE_THD4
				
				// M2 - edge enhance
				0x8565, 0x08,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x5C,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x18,	//ISP_EDG_DIFF_C0
				0x8561, 0x02,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x06,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFC,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				//0x8575, 0x93,	//ISP_SHARPNESS
				//0x85A7, 0x93,	//ISP_SHARPNESS_V
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x10,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x0E,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x10,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x12,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x14,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x1E,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85a8, 0x01,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS
				0x8574, 0x32,	//ISP_RELIEVO_BRIGHT

				0x0000, 0x00,
			},
			{// M3
				// M3 - raw de-noise
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
				0x8522, 0x02,	//ISP_NR_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_NR_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_NR_GRGB_BLNC_D1
				//0x8507, 0x00,	//ISP_GLOC_MAX
				//0x8508, 0x00,	//ISP_GLOC_RATE
				0x851A, 0x0A,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x02,	//ISP_RDLOC_MAX
				0x8505, 0x0B,	//ISP_RDLOC_RATE
				0x8506, 0x01,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x66,	//ISP_NR_MODE
				0x850C, 0x03,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xFF,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE
				0x8516, 0x01,	//ISP_NR_BDRY_SEL
				0x8518, 0x00,	//ISP_DPC_SEL
				
				// M3 - interpolation
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
				
				// M3 - rgb de-noise
				0x8550, 0x03,	//ISP_RGB_IIR_CTRL
				0x8552, 0x44,	//ISP_RGB_HLPF_COEF
				0x8551, 0x40,	//ISP_RGB_VIIR_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x06,	//ISP_RGB_DIIR_COEF
				0x8556, 0x01,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08, 	//ISP_RGB_DIIR_CHANGE_THD2
				0x855a, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855b, 0x0a,	//ISP_RGB_DIIR_CHANGE_THD4
				
				// M3 - edge enhance
				0x8565, 0x08,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x5C,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x18,	//ISP_EDG_DIFF_C0
				0x8561, 0x02,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x06,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFC,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				//0x8575, 0x87,	//ISP_SHARPNESS
				//0x85A7, 0x87,	//ISP_SHARPNESS_V
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x10,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x0E,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x10,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x12,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x10,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x14,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85a8, 0x01,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS
				0x8574, 0x32,	//ISP_RELIEVO_BRIGHT

				0x0000, 0x00,
			},
			{// M4
				// M4 - raw de-noise
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
				0x8522, 0x02,	//ISP_NR_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_NR_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_NR_GRGB_BLNC_D1
				//0x8507, 0x00,	//ISP_GLOC_MAX
				//0x8508, 0x00,	//ISP_GLOC_RATE
				0x851A, 0x0E,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x02,	//ISP_RDLOC_MAX
				0x8505, 0x0B,	//ISP_RDLOC_RATE
				0x8506, 0x01,	//ISP_RDLOC_ENABLE
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
				0x8516, 0x01,	//ISP_NR_BDRY_SEL
				0x8518, 0x00,	//ISP_DPC_SEL

				// M4 - interpolation
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

				// M4 - rgb de-noise
				0x8550, 0x03,	//ISP_RGB_IIR_CTRL
				0x8552, 0x45,	//ISP_RGB_HLPF_COEF
				0x8551, 0x50,	//ISP_RGB_VIIR_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x06,	//ISP_RGB_DIIR_COEF
				0x8556, 0x01,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08, 	//ISP_RGB_DIIR_CHANGE_THD2
				0x855a, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855b, 0x0a,	//ISP_RGB_DIIR_CHANGE_THD4

				// M4 - edge enhance
				0x8565, 0x09,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x5C,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x18,	//ISP_EDG_DIFF_C0
				0x8561, 0x02,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x06,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFC,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				//0x8575, 0x7D,	//ISP_SHARPNESS
				//0x85A7, 0x7D,	//ISP_SHARPNESS_V
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x10,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x0E,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x10,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x12,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x10,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x14,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85a8, 0x01,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS
				0x8574, 0x32,	//ISP_RELIEVO_BRIGHT

				0x0000, 0x00,
			},
			{// M5
				// M5 - raw de-noise
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
				0x8522, 0x02,	//ISP_NR_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_NR_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_NR_GRGB_BLNC_D1
				//0x8507, 0x00,	//ISP_GLOC_MAX
				//0x8508, 0x00,	//ISP_GLOC_RATE
				0x851A, 0x14,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x08,	//ISP_RDLOC_MAX
				0x8505, 0x2E,	//ISP_RDLOC_RATE
				0x8506, 0x01,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xFF,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE
				0x8516, 0x01,	//ISP_NR_BDRY_SEL
				0x8518, 0x00,	//ISP_DPC_SEL
				
				// M5 - interpolation
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
				
				// M5 - rgb de-noise
				0x8550, 0x03,	//ISP_RGB_IIR_CTRL
				0x8552, 0x45,	//ISP_RGB_HLPF_COEF
				0x8551, 0x50,	//ISP_RGB_VIIR_COEF
				0x855D, 0x66,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x60,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x06,	//ISP_RGB_DIIR_COEF
				0x8556, 0x01,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08, 	//ISP_RGB_DIIR_CHANGE_THD2
				0x855a, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855b, 0x0a,	//ISP_RGB_DIIR_CHANGE_THD4
				
				// M5 - edge enhance
				0x8565, 0x09,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x0C,	//ISP_LOC_MAX
				0x85B5, 0x45,	//ISP_LOC_RATE
				0x85B6, 0x01,	//ISP_LOC_ENABLE
				0x8560, 0x18,	//ISP_EDG_DIFF_C0
				0x8561, 0x02,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x06,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFC,	//ISP_EDG_DIFF_C7
				0x85A6, 0x00,	//ISP_INDEP_SHARPV_EN
				//0x8575, 0x75,	//ISP_SHARPNESS
				//0x85A7, 0x75,	//ISP_SHARPNESS_V
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x10,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x0E,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x10,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x12,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x10,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x14,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85a8, 0x01,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS
				0x8574, 0x32,	//ISP_RELIEVO_BRIGHT

				0x0000, 0x00,
			},
			{// M6
				// M6 - raw de-noise
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
				0x8522, 0x02,	//ISP_NR_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_NR_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_NR_GRGB_BLNC_D1
				//0x8507, 0x00,	//ISP_GLOC_MAX
				//0x8508, 0x00,	//ISP_GLOC_RATE
				0x851A, 0x16,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x08,	//ISP_RDLOC_MAX
				0x8505, 0x2E,	//ISP_RDLOC_RATE
				0x8506, 0x01,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xFF,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE
				0x8516, 0x01,	//ISP_NR_BDRY_SEL
				0x8518, 0x00,	//ISP_DPC_SEL
				
				// M6 - interpolation
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
				
				// M6 - rgb de-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x46,	//ISP_RGB_HLPF_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_COEF
				0x855D, 0x66,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x60,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x06,	//ISP_RGB_DIIR_COEF
				0x8556, 0x01,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08, 	//ISP_RGB_DIIR_CHANGE_THD2
				0x855a, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855b, 0x0a,	//ISP_RGB_DIIR_CHANGE_THD4
				
				// M6 - edge enhance
				0x8565, 0x0A,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x0C,	//ISP_LOC_MAX
				0x85B5, 0x45,	//ISP_LOC_RATE
				0x85B6, 0x01,	//ISP_LOC_ENABLE
				0x8560, 0x18,	//ISP_EDG_DIFF_C0
				0x8561, 0x02,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x06,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFC,	//ISP_EDG_DIFF_C7
				0x85A6, 0x00,	//ISP_INDEP_SHARPV_EN
				//0x8575, 0x6A,	//ISP_SHARPNESS
				//0x85A7, 0x6A,	//ISP_SHARPNESS_V
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x10,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x0E,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x10,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x12,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x10,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x10,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85a8, 0x01,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS
				0x8574, 0x32,	//ISP_RELIEVO_BRIGHT

				0x0000, 0x00,
			},
			{// M7
				// M7 - raw de-noise
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
				0x8522, 0x02,	//ISP_NR_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_NR_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_NR_GRGB_BLNC_D1
				//0x8507, 0x00,	//ISP_GLOC_MAX
				//0x8508, 0x00,	//ISP_GLOC_RATE
				0x851A, 0x18,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x08,	//ISP_RDLOC_MAX
				0x8505, 0x2E,	//ISP_RDLOC_RATE
				0x8506, 0x01,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xFF,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE
				0x8516, 0x01,	//ISP_NR_BDRY_SEL
				0x8518, 0x00,	//ISP_DPC_SEL
				
				// M7 - interpolation
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
				
				// M7 - rgb de-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x46,	//ISP_RGB_HLPF_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_COEF
				0x855D, 0x66,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x60,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x06,	//ISP_RGB_DIIR_COEF
				0x8556, 0x01,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08, 	//ISP_RGB_DIIR_CHANGE_THD2
				0x855a, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855b, 0x0a,	//ISP_RGB_DIIR_CHANGE_THD4
				
				// M7 - edge enhance
				0x8565, 0x0A,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x0C,	//ISP_LOC_MAX
				0x85B5, 0x45,	//ISP_LOC_RATE
				0x85B6, 0x01,	//ISP_LOC_ENABLE
				0x8560, 0x18,	//ISP_EDG_DIFF_C0
				0x8561, 0x02,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x06,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFC,	//ISP_EDG_DIFF_C7
				0x85A6, 0x00,	//ISP_INDEP_SHARPV_EN
				//0x8575, 0x64,	//ISP_SHARPNESS
				//0x85A7, 0x64,	//ISP_SHARPNESS_V
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x10,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x0E,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x10,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x12,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x10,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x10,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85a8, 0x01,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS
				0x8574, 0x32,	//ISP_RELIEVO_BRIGHT
				
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
		0, // 4,		// A light U offset
		0,		// A light V offset
		0, // 4,		// D65 light U offset
		0,		// D65 light V offset
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
			//{80, 69, 59, 48, 41, 35, 30, 26, 23, 21, 19, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
			//{50, 52, 54, 48, 42, 36, 30, 25, 22, 20, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
			//{128,111,84,67,50,40,32,27,24,20,18,17,16,15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
			{72,67,62,57,52,47,43,39,35,32,29,26,23,20,18,16,14,12,10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
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
			9,
			//ISP HDR INC RATE 1
			5,
#endif		
		},
		{
			// Hist dev min
			450,//0,
			// Hist dev max
			800,
			// Low part pct min
			70,
			// low part pct max
			100,
			//Hist distance weight
			{1.6, 1.3, 1.0, 0.7, 0.4, 0.5, 0.8, 1.0, 1.2, 1.5},
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
		//{0x20,0x20,0x20,},// gain low rate
		{0x1c, 0x1c, 0x1c,},
	},

	// IR AE
	{
		// AE target
		{
			40,	// Histogram Ratio Low
			40,// Histogram Ratio High
			30,	// YMean Target Low
			35,	// YMean Target
			40,	// YMean Target High
			0,	// Histogram Position Low
			170,// Histogram Position High
			4	// Dynamic AE Target decrease value
		},
		// AE weight
		{
			{
				// 1,1,1,1,1,
				// 1,10,10,10,1,
				// 1,10,10,10,1,
				// 1,10,10,10,1,
				// 1,1,1,1,1,
				1, 1, 1, 1, 1,
				1, 2, 2, 2, 1,
				1, 2, 2, 2, 1,
				1, 2, 2, 2, 1,
				1, 1, 1, 1, 1,
			}
		},
	},

	// IR CCM
	{
		// normal ccm
		{
			// D65 light CCM
			//{0x206,-244,-18,-98,0x1a9,-71,-10,-244,0x1fe},
			{0x100, 0, 0, 0, 0x100, 0, 0, 0, 0x100},
			// CWF light CCM
			{0x100, 0, 0, 0, 0x100, 0, 0, 0, 0x100},
			// A light CCM
			{0x100, 0, 0, 0, 0x100, 0, 0, 0, 0x100},
			// HORIZON light CCM
			{0x100, 0, 0, 0, 0x100, 0, 0, 0, 0x100},
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
		//{0, 13, 26, 39, 51, 63, 75, 86, 96, 111, 123, 133, 143, 152, 159, 167, 173, 179, 185, 190, 195, 202, 212, 219, 227, 235, 242, 249,},
		{ 0, 12, 23, 34, 45, 55, 64, 73, 82, 97, 112, 126, 138, 148, 156, 164, 172, 178, 184, 190, 194, 204, 212, 220, 226, 234, 241, 248, },
		// low light gamma
		//{ 0, 31, 45, 55, 63, 71, 78, 84, 90, 100, 110, 119, 127, 135, 142, 149, 156, 162, 168, 174, 180, 191, 201, 211, 221, 230, 238, 247,},
		//{0, 13, 26, 39, 51, 63, 75, 86, 96, 111, 123, 133, 143, 152, 159, 167, 173, 179, 185, 190, 195, 202, 212, 219, 227, 235, 242, 249,},
		{ 0, 12, 23, 34, 45, 55, 64, 73, 82, 97, 112, 126, 138, 148, 156, 164, 172, 178, 184, 190, 194, 204, 212, 220, 226, 234, 241, 248, },
		384,	// dynamic Gamma Gain Threshold Low
		1024,// dynamic Gamma Gain Threshold High
	},

	// IR Texture
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
				150,		//ISP_SHARPNESS  (0x8575)
				150,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M4
				140,		//ISP_SHARPNESS  (0x8575)
				140,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M5
				130,		//ISP_SHARPNESS  (0x8575)
				130,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M6
				120,		//ISP_SHARPNESS  (0x8575)
				120,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M7
				120,		//ISP_SHARPNESS  (0x8575)
				120,		//ISP_SHARP_V  (0x85A7)
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
			{// M0
				// M0 - raw de-noise
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
				0x8522, 0x02,	//ISP_NR_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_NR_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_NR_GRGB_BLNC_D1
				//0x8507, 0x00,	//ISP_GLOC_MAX
				//0x8508, 0x00,	//ISP_GLOC_RATE
				0x851A, 0x08,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x02,	//ISP_RDLOC_MAX
				0x8505, 0x0B,	//ISP_RDLOC_RATE
				0x8506, 0x01,	//ISP_RDLOC_ENABLE
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
				0x8516, 0x01,	//ISP_NR_BDRY_SEL
				0x8518, 0x00,	//ISP_DPC_SEL

				// M0 - interpolation
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
				//0x853A, 0x82,	//ISP_MOIRE_CTRL
				0x853B, 0x14,	//ISP_MOIRE_MAX
				//0x853C, 0x89,	//ISP_MOIRE_RATE_R
				//0x853D, 0x83,	//ISP_MOIRE_RATE_B
				0x854D, 0x11,	//ISP_INTP_EDGE_SMOOTH
				//0x8500, 0x0300,	//ISP_RDLOC_DIST_START_L
				//0x8502, 0x0464,	//ISP_RDLOC_DIST_END_L
				0x854E, 0x50,	//ISP_ILOC_MAX
				0x854F, 0x5C,	//ISP_ILOC_RATE

				// M0 - rgb de-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x24,	//ISP_RGB_HLPF_COEF
				0x8551, 0x30,	//ISP_RGB_VIIR_COEF
				0x855D, 0x24,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x06,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08, 	//ISP_RGB_DIIR_CHANGE_THD2
				0x855a, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855b, 0x0a,	//ISP_RGB_DIIR_CHANGE_THD4

				// M0 - edge enhance
				0x8565, 0x08,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x10,	//ISP_LOC_MAX
				0x85B5, 0x5C,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0C,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFC,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFE,	//ISP_EDG_DIFF_C7
				0x85A6, 0x00,	//ISP_INDEP_SHARPV_EN
				//0x8575, 0xA0,	//ISP_SHARPNESS
				//0x85A7, 0xA0,	//ISP_SHARPNESS_V
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x10,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x0E,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x10,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x12,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x10,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x10,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85a8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x82,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS
				0x8574, 0x32,	//ISP_RELIEVO_BRIGHT

				// M0 - 3dnr
				0x8885, 0x02,	//TPNR_REGF_DIST_INNERRADIUS_H
				0x8886, 0x58,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x03,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0x84,	//TPNR_REGF_DIST_OUTERRADIUS_L
				0x8889, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_H
				0x888A, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_L
				0x888C, 0x10,	//TPNR_REGF_DIST_INNERRATE
				0x888D, 0x10,	//TPNR_REGF_DIST_OUTERRATE
				0x888B, 0xF0,	//TPNR_REGF_LUMINANCETERM
				0x8890, 0x2F,	//TPNR_REGF_YAVG_DEFTH0
				0x8891, 0x20,	//TPNR_REGF_YAVG_THRESHOLD_STEP
				0x8892, 0x04,	//TPNR_REGF_YAVG_THRESHOLD_K_H
				0x8893, 0x18,	//TPNR_REGF_YAVG_THRESHOLD_K_L
				0x8894, 0x7D,	//TPNR_REGF_YAVG_MIN_LEARNRATE
				0x8895, 0x2F,	//TPNR_REGF_YTEX_DEFTH0
				0x8896, 0x20,	//TPNR_REGF_YTEX_THRESHOLD_STEP
				0x8897, 0x06,	//TPNR_REGF_YTEX_THRESHOLD_K_H
				0x8898, 0x48,	//TPNR_REGF_YTEX_THRESHOLD_K_L
				0x8899, 0x37,	//TPNR_REGF_YTEX_MIN_LEARNRATE
				0x889A, 0x20,	//TPNR_REGF_YEDGEHANCE

				0x0000, 0x00,
			},
			{// M1
				// M1 - raw de-noise
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
				0x8522, 0x02,	//ISP_NR_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_NR_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_NR_GRGB_BLNC_D1
				//0x8507, 0x00,	//ISP_GLOC_MAX
				//0x8508, 0x00,	//ISP_GLOC_RATE
				0x851A, 0x0A,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x02,	//ISP_RDLOC_MAX
				0x8505, 0x0B,	//ISP_RDLOC_RATE
				0x8506, 0x01,	//ISP_RDLOC_ENABLE
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
				0x8516, 0x01,	//ISP_NR_BDRY_SEL
				0x8518, 0x00,	//ISP_DPC_SEL

				// M1 - interpolation
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
				//0x853A, 0x82,	//ISP_MOIRE_CTRL
				0x853B, 0x14,	//ISP_MOIRE_MAX
				//////////0x853C, 0x8A,	//ISP_MOIRE_RATE_R
				//////////0x853D, 0x91,	//ISP_MOIRE_RATE_B
				0x854D, 0x11,	//ISP_INTP_EDGE_SMOOTH
				//0x8500, 0x0300,	//ISP_RDLOC_DIST_START_L
				//0x8502, 0x0464,	//ISP_RDLOC_DIST_END_L
				0x854E, 0x50,	//ISP_ILOC_MAX
				0x854F, 0x5C,	//ISP_ILOC_RATE

				// M1 - rgb de-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x24,	//ISP_RGB_HLPF_COEF
				0x8551, 0x30,	//ISP_RGB_VIIR_COEF
				0x855D, 0x35,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x07,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08, 	//ISP_RGB_DIIR_CHANGE_THD2
				0x855a, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855b, 0x0a,	//ISP_RGB_DIIR_CHANGE_THD4

				// M1 - edge enhance
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
				0x85B5, 0x5C,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0C,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFC,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFE,	//ISP_EDG_DIFF_C7
				0x85A6, 0x00,	//ISP_INDEP_SHARPV_EN
				//0x8575, 0xA0,	//ISP_SHARPNESS
				//0x85A7, 0xA0,	//ISP_SHARPNESS_V
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x10,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x0E,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x10,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x12,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x10,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x10,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0B,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85a8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x82,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS
				0x8574, 0x32,	//ISP_RELIEVO_BRIGHT

				// M1 - 3dnr
				0x8885, 0x02,	//TPNR_REGF_DIST_INNERRADIUS_H
				0x8886, 0x58,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x03,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0x84,	//TPNR_REGF_DIST_OUTERRADIUS_L
				0x8889, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_H
				0x888A, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_L
				0x888C, 0x10,	//TPNR_REGF_DIST_INNERRATE
				0x888D, 0x10,	//TPNR_REGF_DIST_OUTERRATE
				0x888B, 0xF0,	//TPNR_REGF_LUMINANCETERM
				0x8890, 0x2F,	//TPNR_REGF_YAVG_DEFTH0
				0x8891, 0x20,	//TPNR_REGF_YAVG_THRESHOLD_STEP
				0x8892, 0x04,	//TPNR_REGF_YAVG_THRESHOLD_K_H
				0x8893, 0x40,	//TPNR_REGF_YAVG_THRESHOLD_K_L
				0x8894, 0x78,	//TPNR_REGF_YAVG_MIN_LEARNRATE
				0x8895, 0x2F,	//TPNR_REGF_YTEX_DEFTH0
				0x8896, 0x20,	//TPNR_REGF_YTEX_THRESHOLD_STEP
				0x8897, 0x06,	//TPNR_REGF_YTEX_THRESHOLD_K_H
				0x8898, 0x48,	//TPNR_REGF_YTEX_THRESHOLD_K_L
				0x8899, 0x37,	//TPNR_REGF_YTEX_MIN_LEARNRATE
				0x889A, 0x20,	//TPNR_REGF_YEDGEHANCE

				0x0000, 0x00,
			},
			{// M2
				// M2 - raw de-noise
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
				0x8520, 0x80,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_NR_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_NR_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_NR_GRGB_BLNC_D1
				//0x8507, 0x00,	//ISP_GLOC_MAX
				//0x8508, 0x00,	//ISP_GLOC_RATE
				0x851A, 0x0C,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x02,	//ISP_RDLOC_MAX
				0x8505, 0x0B,	//ISP_RDLOC_RATE
				0x8506, 0x01,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x66,	//ISP_NR_MODE
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
				0x8516, 0x01,	//ISP_NR_BDRY_SEL
				0x8518, 0x00,	//ISP_DPC_SEL
				
				// M2 - interpolation
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
				//0x853A, 0x82,	//ISP_MOIRE_CTRL
				0x853B, 0x14,	//ISP_MOIRE_MAX
				//0x853C, 0x84,	//ISP_MOIRE_RATE_R
				//0x853D, 0x88,	//ISP_MOIRE_RATE_B
				0x854D, 0x11,	//ISP_INTP_EDGE_SMOOTH
				//0x8500, 0x0300,	//ISP_RDLOC_DIST_START_L
				//0x8502, 0x0464,	//ISP_RDLOC_DIST_END_L
				0x854E, 0x50,	//ISP_ILOC_MAX
				0x854F, 0x5C,	//ISP_ILOC_RATE
				
				// M2 - rgb de-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x24,	//ISP_RGB_HLPF_COEF
				0x8551, 0x40,	//ISP_RGB_VIIR_COEF
				0x855D, 0x46,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x08,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08, 	//ISP_RGB_DIIR_CHANGE_THD2
				0x855a, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855b, 0x0a,	//ISP_RGB_DIIR_CHANGE_THD4
				
				// M2 - edge enhance
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
				0x85B5, 0x5C,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0C,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFC,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFE,	//ISP_EDG_DIFF_C7
				0x85A6, 0x00,	//ISP_INDEP_SHARPV_EN
				//0x8575, 0xA0,	//ISP_SHARPNESS
				//0x85A7, 0xA0,	//ISP_SHARPNESS_V
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x10,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x0E,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x10,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x12,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x10,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x10,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0C,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85a8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS
				0x8574, 0x32,	//ISP_RELIEVO_BRIGHT

				// M2 - 3dnr
				0x8885, 0x02,	//TPNR_REGF_DIST_INNERRADIUS_H
				0x8886, 0x58,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x03,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0x84,	//TPNR_REGF_DIST_OUTERRADIUS_L
				0x8889, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_H
				0x888A, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_L
				0x888C, 0x10,	//TPNR_REGF_DIST_INNERRATE
				0x888D, 0x10,	//TPNR_REGF_DIST_OUTERRATE
				0x888B, 0xF0,	//TPNR_REGF_LUMINANCETERM
				0x8890, 0x2F,	//TPNR_REGF_YAVG_DEFTH0
				0x8891, 0x20,	//TPNR_REGF_YAVG_THRESHOLD_STEP
				0x8892, 0x04,	//TPNR_REGF_YAVG_THRESHOLD_K_H
				0x8893, 0x68,	//TPNR_REGF_YAVG_THRESHOLD_K_L
				0x8894, 0x73,	//TPNR_REGF_YAVG_MIN_LEARNRATE
				0x8895, 0x2F,	//TPNR_REGF_YTEX_DEFTH0
				0x8896, 0x20,	//TPNR_REGF_YTEX_THRESHOLD_STEP
				0x8897, 0x06,	//TPNR_REGF_YTEX_THRESHOLD_K_H
				0x8898, 0x48,	//TPNR_REGF_YTEX_THRESHOLD_K_L
				0x8899, 0x37,	//TPNR_REGF_YTEX_MIN_LEARNRATE
				0x889A, 0x20,	//TPNR_REGF_YEDGEHANCE

				0x0000, 0x00,
			},
			{// M3
				// M3 - raw de-noise
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
				0x8520, 0x80,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_NR_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_NR_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_NR_GRGB_BLNC_D1
				//0x8507, 0x00,	//ISP_GLOC_MAX
				//0x8508, 0x00,	//ISP_GLOC_RATE
				0x851A, 0x10,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x02,	//ISP_RDLOC_MAX
				0x8505, 0x0B,	//ISP_RDLOC_RATE
				0x8506, 0x01,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x66,	//ISP_NR_MODE
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
				0x8516, 0x01,	//ISP_NR_BDRY_SEL
				0x8518, 0x00,	//ISP_DPC_SEL
				
				// M3 - interpolation
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
				//0x853A, 0x82,	//ISP_MOIRE_CTRL
				0x853B, 0x14,	//ISP_MOIRE_MAX
				//0x853C, 0x8E,	//ISP_MOIRE_RATE_R
				//0x853D, 0x7E,	//ISP_MOIRE_RATE_B
				0x854D, 0x11,	//ISP_INTP_EDGE_SMOOTH
				//0x8500, 0x0300,	//ISP_RDLOC_DIST_START_L
				//0x8502, 0x0464,	//ISP_RDLOC_DIST_END_L
				0x854E, 0x50,	//ISP_ILOC_MAX
				0x854F, 0x5C,	//ISP_ILOC_RATE
				
				// M3 - rgb de-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x35,	//ISP_RGB_HLPF_COEF
				0x8551, 0x50,	//ISP_RGB_VIIR_COEF
				0x855D, 0x57,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x09,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08, 	//ISP_RGB_DIIR_CHANGE_THD2
				0x855a, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855b, 0x0a,	//ISP_RGB_DIIR_CHANGE_THD4
				
				// M3 - edge enhance
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
				0x85B5, 0x5C,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0C,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFC,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFE,	//ISP_EDG_DIFF_C7
				0x85A6, 0x00,	//ISP_INDEP_SHARPV_EN
				//0x8575, 0x9A,	//ISP_SHARPNESS
				//0x85A7, 0x9A,	//ISP_SHARPNESS_V
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x10,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x0E,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x10,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x12,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0F,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0F,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0D,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85a8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS
				0x8574, 0x32,	//ISP_RELIEVO_BRIGHT

				// M3 - 3dnr
				0x8885, 0x02,	//TPNR_REGF_DIST_INNERRADIUS_H
				0x8886, 0x58,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x03,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0x84,	//TPNR_REGF_DIST_OUTERRADIUS_L
				0x8889, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_H
				0x888A, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_L
				0x888C, 0x10,	//TPNR_REGF_DIST_INNERRATE
				0x888D, 0x10,	//TPNR_REGF_DIST_OUTERRATE
				0x888B, 0xF0,	//TPNR_REGF_LUMINANCETERM
				0x8890, 0x2F,	//TPNR_REGF_YAVG_DEFTH0
				0x8891, 0x20,	//TPNR_REGF_YAVG_THRESHOLD_STEP
				0x8892, 0x04,	//TPNR_REGF_YAVG_THRESHOLD_K_H
				0x8893, 0x90,	//TPNR_REGF_YAVG_THRESHOLD_K_L
				0x8894, 0x6E,	//TPNR_REGF_YAVG_MIN_LEARNRATE
				0x8895, 0x2F,	//TPNR_REGF_YTEX_DEFTH0
				0x8896, 0x20,	//TPNR_REGF_YTEX_THRESHOLD_STEP
				0x8897, 0x06,	//TPNR_REGF_YTEX_THRESHOLD_K_H
				0x8898, 0x48,	//TPNR_REGF_YTEX_THRESHOLD_K_L
				0x8899, 0x37,	//TPNR_REGF_YTEX_MIN_LEARNRATE
				0x889A, 0x20,	//TPNR_REGF_YEDGEHANCE

				0x0000, 0x00,
			},
			{// M4
				// M4 - raw de-noise
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
				0x8522, 0x02,	//ISP_NR_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_NR_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_NR_GRGB_BLNC_D1
				//0x8507, 0x00,	//ISP_GLOC_MAX
				//0x8508, 0x00,	//ISP_GLOC_RATE
				0x851A, 0x12,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x02,	//ISP_RDLOC_MAX
				0x8505, 0x0B,	//ISP_RDLOC_RATE
				0x8506, 0x01,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x66,	//ISP_NR_MODE
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
				0x8516, 0x01,	//ISP_NR_BDRY_SEL
				0x8518, 0x00,	//ISP_DPC_SEL

				// M4 - interpolation
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
				//0x853A, 0x02,	//ISP_MOIRE_CTRL
				0x853B, 0x14,	//ISP_MOIRE_MAX
				//0x853C, 0x7E,	//ISP_MOIRE_RATE_R
				//0x853D, 0xAF,	//ISP_MOIRE_RATE_B
				0x854D, 0x11,	//ISP_INTP_EDGE_SMOOTH
				//0x8500, 0x0300,	//ISP_RDLOC_DIST_START_L
				//0x8502, 0x0464,	//ISP_RDLOC_DIST_END_L
				0x854E, 0x50,	//ISP_ILOC_MAX
				0x854F, 0x5C,	//ISP_ILOC_RATE

				// M4 - rgb de-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x46,	//ISP_RGB_HLPF_COEF
				0x8551, 0x50,	//ISP_RGB_VIIR_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0A,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08, 	//ISP_RGB_DIIR_CHANGE_THD2
				0x855a, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855b, 0x0a,	//ISP_RGB_DIIR_CHANGE_THD4

				// M4 - edge enhance
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
				0x85B5, 0x5C,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x1C,	//ISP_EDG_DIFF_C0
				0x8561, 0x01,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0A,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFE,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x00,	//ISP_INDEP_SHARPV_EN
				//0x8575, 0x8E,	//ISP_SHARPNESS
				//0x85A7, 0x8E,	//ISP_SHARPNESS_V
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x10,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x0E,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x10,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x12,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0E,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0E,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85a8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS
				0x8574, 0x32,	//ISP_RELIEVO_BRIGHT

				// M4 - 3dnr
				0x8885, 0x02,	//TPNR_REGF_DIST_INNERRADIUS_H
				0x8886, 0x58,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x03,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0x84,	//TPNR_REGF_DIST_OUTERRADIUS_L
				0x8889, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_H
				0x888A, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_L
				0x888C, 0x10,	//TPNR_REGF_DIST_INNERRATE
				0x888D, 0x10,	//TPNR_REGF_DIST_OUTERRATE
				0x888B, 0xF0,	//TPNR_REGF_LUMINANCETERM
				0x8890, 0x2F,	//TPNR_REGF_YAVG_DEFTH0
				0x8891, 0x20,	//TPNR_REGF_YAVG_THRESHOLD_STEP
				0x8892, 0x04,	//TPNR_REGF_YAVG_THRESHOLD_K_H
				0x8893, 0xB8,	//TPNR_REGF_YAVG_THRESHOLD_K_L
				0x8894, 0x69,	//TPNR_REGF_YAVG_MIN_LEARNRATE
				0x8895, 0x2F,	//TPNR_REGF_YTEX_DEFTH0
				0x8896, 0x20,	//TPNR_REGF_YTEX_THRESHOLD_STEP
				0x8897, 0x06,	//TPNR_REGF_YTEX_THRESHOLD_K_H
				0x8898, 0x48,	//TPNR_REGF_YTEX_THRESHOLD_K_L
				0x8899, 0x37,	//TPNR_REGF_YTEX_MIN_LEARNRATE
				0x889A, 0x20,	//TPNR_REGF_YEDGEHANCE

				0x0000, 0x00,
			},
			{// M5
				// M5 - raw de-noise
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
				0x8522, 0x02,	//ISP_NR_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_NR_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_NR_GRGB_BLNC_D1
				//0x8507, 0x00,	//ISP_GLOC_MAX
				//0x8508, 0x00,	//ISP_GLOC_RATE
				0x851A, 0x14,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x08,	//ISP_RDLOC_MAX
				0x8505, 0x2E,	//ISP_RDLOC_RATE
				0x8506, 0x01,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xFF,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE
				0x8516, 0x01,	//ISP_NR_BDRY_SEL
				0x8518, 0x00,	//ISP_DPC_SEL
				
				// M5 - interpolation
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
				//0x853A, 0x02,	//ISP_MOIRE_CTRL
				0x853B, 0x14,	//ISP_MOIRE_MAX
				//0x853C, 0x61,	//ISP_MOIRE_RATE_R
				//0x853D, 0xA4,	//ISP_MOIRE_RATE_B
				0x854D, 0x11,	//ISP_INTP_EDGE_SMOOTH
				//0x8500, 0x0300,	//ISP_RDLOC_DIST_START_L
				//0x8502, 0x0464,	//ISP_RDLOC_DIST_END_L
				0x854E, 0x50,	//ISP_ILOC_MAX
				0x854F, 0x5C,	//ISP_ILOC_RATE
				
				// M5 - rgb de-noise
				0x8550, 0x03,	//ISP_RGB_IIR_CTRL
				0x8552, 0x46,	//ISP_RGB_HLPF_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x06,	//ISP_RGB_DIIR_COEF
				0x8556, 0x01,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08, 	//ISP_RGB_DIIR_CHANGE_THD2
				0x855a, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855b, 0x0a,	//ISP_RGB_DIIR_CHANGE_THD4
				
				// M5 - edge enhance
				0x8565, 0x0C,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x0C,	//ISP_LOC_MAX
				0x85B5, 0x45,	//ISP_LOC_RATE
				0x85B6, 0x01,	//ISP_LOC_ENABLE
				0x8560, 0x18,	//ISP_EDG_DIFF_C0
				0x8561, 0x02,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x06,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFC,	//ISP_EDG_DIFF_C7
				0x85A6, 0x00,	//ISP_INDEP_SHARPV_EN
				//0x8575, 0x86,	//ISP_SHARPNESS
				//0x85A7, 0x86,	//ISP_SHARPNESS_V
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x10,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x0E,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x10,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x12,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0D,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0D,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85a8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS
				0x8574, 0x32,	//ISP_RELIEVO_BRIGHT

				// M5 - 3dnr
				0x8885, 0x02,	//TPNR_REGF_DIST_INNERRADIUS_H
				0x8886, 0x58,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x03,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0x84,	//TPNR_REGF_DIST_OUTERRADIUS_L
				0x8889, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_H
				0x888A, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_L
				0x888C, 0x10,	//TPNR_REGF_DIST_INNERRATE
				0x888D, 0x10,	//TPNR_REGF_DIST_OUTERRATE
				0x888B, 0xF0,	//TPNR_REGF_LUMINANCETERM
				0x8890, 0x2F,	//TPNR_REGF_YAVG_DEFTH0
				0x8891, 0x20,	//TPNR_REGF_YAVG_THRESHOLD_STEP
				0x8892, 0x05,	//TPNR_REGF_YAVG_THRESHOLD_K_H
				0x8893, 0xA8,	//TPNR_REGF_YAVG_THRESHOLD_K_L
				0x8894, 0x4B,	//TPNR_REGF_YAVG_MIN_LEARNRATE
				0x8895, 0x2F,	//TPNR_REGF_YTEX_DEFTH0
				0x8896, 0x20,	//TPNR_REGF_YTEX_THRESHOLD_STEP
				0x8897, 0x06,	//TPNR_REGF_YTEX_THRESHOLD_K_H
				0x8898, 0x48,	//TPNR_REGF_YTEX_THRESHOLD_K_L
				0x8899, 0x37,	//TPNR_REGF_YTEX_MIN_LEARNRATE
				0x889A, 0x20,	//TPNR_REGF_YEDGEHANCE
				
				0x0000, 0x00,
			},
			{// M6
				// M6 - raw de-noise
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
				0x8522, 0x02,	//ISP_NR_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_NR_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_NR_GRGB_BLNC_D1
				//0x8507, 0x00,	//ISP_GLOC_MAX
				//0x8508, 0x00,	//ISP_GLOC_RATE
				0x851A, 0x16,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x08,	//ISP_RDLOC_MAX
				0x8505, 0x2E,	//ISP_RDLOC_RATE
				0x8506, 0x01,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x77,	//ISP_NR_MODE
				0x850C, 0x01,	//ISP_NR_MODE0_LPF
				0x850D, 0x01,	//ISP_NR_MODE1_LPF
				0x850F, 0x05,	//ISP_NR_COLOR_MAX
				0x850E, 0x00,	//ISP_NR_COLOR_ENABLE_CTRL
				0x852B, 0x02,	//ISP_NR_MMM_D0
				0x852C, 0x04,	//ISP_NR_MMM_D1
				0x852D, 0xFF,	//ISP_NR_MMM_RATE
				0x852E, 0x10,	//ISP_NR_MMM_MIN
				0x852F, 0x80,	//ISP_NR_MMM_MAX
				0x852A, 0x00,	//ISP_NR_MMM_ENABLE
				0x8516, 0x01,	//ISP_NR_BDRY_SEL
				0x8518, 0x00,	//ISP_DPC_SEL
				
				// M6 - interpolation
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
				//0x853A, 0x02,	//ISP_MOIRE_CTRL
				0x853B, 0x14,	//ISP_MOIRE_MAX
				//0x853C, 0x6F,	//ISP_MOIRE_RATE_R
				//0x853D, 0x9C,	//ISP_MOIRE_RATE_B
				0x854D, 0x11,	//ISP_INTP_EDGE_SMOOTH
				//0x8500, 0x0300,	//ISP_RDLOC_DIST_START_L
				//0x8502, 0x0464,	//ISP_RDLOC_DIST_END_L
				0x854E, 0x50,	//ISP_ILOC_MAX
				0x854F, 0x5C,	//ISP_ILOC_RATE
				
				// M6 - rgb de-noise
				0x8550, 0x03,	//ISP_RGB_IIR_CTRL
				0x8552, 0x56,	//ISP_RGB_HLPF_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_COEF
				0x855D, 0x68,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x06,	//ISP_RGB_DIIR_COEF
				0x8556, 0x01,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08, 	//ISP_RGB_DIIR_CHANGE_THD2
				0x855a, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855b, 0x0a,	//ISP_RGB_DIIR_CHANGE_THD4
				
				// M6 - edge enhance
				0x8565, 0x0C,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x0C,	//ISP_LOC_MAX
				0x85B5, 0x45,	//ISP_LOC_RATE
				0x85B6, 0x01,	//ISP_LOC_ENABLE
				0x8560, 0x18,	//ISP_EDG_DIFF_C0
				0x8561, 0x02,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x06,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFC,	//ISP_EDG_DIFF_C7
				0x85A6, 0x00,	//ISP_INDEP_SHARPV_EN
				//0x8575, 0x7F,	//ISP_SHARPNESS
				//0x85A7, 0x7F,	//ISP_SHARPNESS_V
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x10,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x0E,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x10,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x12,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0C,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0C,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85a8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS
				0x8574, 0x32,	//ISP_RELIEVO_BRIGHT

				// M6 - 3dnr
				0x8885, 0x02,	//TPNR_REGF_DIST_INNERRADIUS_H
				0x8886, 0x58,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x03,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0x84,	//TPNR_REGF_DIST_OUTERRADIUS_L
				0x8889, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_H
				0x888A, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_L
				0x888C, 0x10,	//TPNR_REGF_DIST_INNERRATE
				0x888D, 0x10,	//TPNR_REGF_DIST_OUTERRATE
				0x888B, 0xFF,	//TPNR_REGF_LUMINANCETERM
				0x8890, 0x36,	//TPNR_REGF_YAVG_DEFTH0
				0x8891, 0x20,	//TPNR_REGF_YAVG_THRESHOLD_STEP
				0x8892, 0x05,	//TPNR_REGF_YAVG_THRESHOLD_K_H
				0x8893, 0xD0,	//TPNR_REGF_YAVG_THRESHOLD_K_L
				0x8894, 0x46,	//TPNR_REGF_YAVG_MIN_LEARNRATE
				0x8895, 0x36,	//TPNR_REGF_YTEX_DEFTH0
				0x8896, 0x20,	//TPNR_REGF_YTEX_THRESHOLD_STEP
				0x8897, 0x06,	//TPNR_REGF_YTEX_THRESHOLD_K_H
				0x8898, 0x98,	//TPNR_REGF_YTEX_THRESHOLD_K_L
				0x8899, 0x2D,	//TPNR_REGF_YTEX_MIN_LEARNRATE
				0x889A, 0x20,	//TPNR_REGF_YEDGEHANCE

				0x0000, 0x00,
			},
			{// M7
				// M7 - raw de-noise
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
				0x8522, 0x02,	//ISP_NR_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_NR_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_NR_GRGB_BLNC_D1
				//0x8507, 0x00,	//ISP_GLOC_MAX
				//0x8508, 0x00,	//ISP_GLOC_RATE
				0x851A, 0x1A,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x08,	//ISP_RDLOC_MAX
				0x8505, 0x2E,	//ISP_RDLOC_RATE
				0x8506, 0x01,	//ISP_RDLOC_ENABLE
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
				0x8516, 0x01,	//ISP_NR_BDRY_SEL
				0x8518, 0x00,	//ISP_DPC_SEL
				
				// M7 - interpolation
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
				//0x853A, 0x02,	//ISP_MOIRE_CTRL
				0x853B, 0x14,	//ISP_MOIRE_MAX
				//0x853C, 0x5E,	//ISP_MOIRE_RATE_R
				//0x853D, 0x95,	//ISP_MOIRE_RATE_B
				0x854D, 0x11,	//ISP_INTP_EDGE_SMOOTH
				//0x8500, 0x0300,	//ISP_RDLOC_DIST_START_L
				//0x8502, 0x0464,	//ISP_RDLOC_DIST_END_L
				0x854E, 0x50,	//ISP_ILOC_MAX
				0x854F, 0x5C,	//ISP_ILOC_RATE
				
				// M7 - rgb de-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x68,	//ISP_RGB_HLPF_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_COEF
				0x855D, 0x68,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x40,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0C,	//ISP_RGB_DIIR_COEF
				0x8556, 0x00,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x06,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x07,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x08, 	//ISP_RGB_DIIR_CHANGE_THD2
				0x855a, 0x09,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855b, 0x0a,	//ISP_RGB_DIIR_CHANGE_THD4
				
				// M7 - edge enhance
				0x8565, 0x0C,	//ISP_EDG_DCT_THD1
				0x8569, 0x04,	//ISP_EEH_DTHD_CFG
				0x85B0, 0x00,	//ISP_LOC_DIST_START_L
				0x85B1, 0x03,	//ISP_LOC_DIST_START_H
				0x85B2, 0x64,	//ISP_LOC_DIST_END_L
				0x85B3, 0x04,	//ISP_LOC_DIST_END_H
				0x85A0, 0x01,	//ISP_EEH_INDEP_HV_EN
				0x85A1, 0x18,	//ISP_EEH_INDEP_EDGE_K1
				0x85A2, 0x03,	//ISP_EEH_INDEP_EDGE_B1
				0x85B4, 0x0C,	//ISP_LOC_MAX
				0x85B5, 0x45,	//ISP_LOC_RATE
				0x85B6, 0x01,	//ISP_LOC_ENABLE
				0x8560, 0x18,	//ISP_EDG_DIFF_C0
				0x8561, 0x02,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFD,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x06,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFC,	//ISP_EDG_DIFF_C7
				0x85A6, 0x00,	//ISP_INDEP_SHARPV_EN
				//0x8575, 0x78,	//ISP_SHARPNESS
				//0x85A7, 0x78,	//ISP_SHARPNESS_V
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x10,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x0E,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x0C,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x10,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x12,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x0C,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x0C,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85a8, 0x00,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS
				0x8574, 0x32,	//ISP_RELIEVO_BRIGHT
				
				// M7 - 3dnr
				0x8885, 0x02,	//TPNR_REGF_DIST_INNERRADIUS_H
				0x8886, 0x58,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x03,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0x84,	//TPNR_REGF_DIST_OUTERRADIUS_L
				0x8889, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_H
				0x888A, 0x00,	//TPNR_REGF_DIST_RADIUS_INVXRATE_L
				0x888C, 0x10,	//TPNR_REGF_DIST_INNERRATE
				0x888D, 0x10,	//TPNR_REGF_DIST_OUTERRATE
				0x888B, 0xFF,	//TPNR_REGF_LUMINANCETERM
				0x8890, 0x34,	//TPNR_REGF_YAVG_DEFTH0
				0x8891, 0x20,	//TPNR_REGF_YAVG_THRESHOLD_STEP
				0x8892, 0x05,	//TPNR_REGF_YAVG_THRESHOLD_K_H
				0x8893, 0xF8,	//TPNR_REGF_YAVG_THRESHOLD_K_L
				0x8894, 0x41,	//TPNR_REGF_YAVG_MIN_LEARNRATE
				0x8895, 0x34,	//TPNR_REGF_YTEX_DEFTH0
				0x8896, 0x20,	//TPNR_REGF_YTEX_THRESHOLD_STEP
				0x8897, 0x06,	//TPNR_REGF_YTEX_THRESHOLD_K_H
				0x8898, 0x98,	//TPNR_REGF_YTEX_THRESHOLD_K_L
				0x8899, 0x2D,	//TPNR_REGF_YTEX_MIN_LEARNRATE
				0x889A, 0x20,	//TPNR_REGF_YEDGEHANCE

				0x0000, 0x00,
			}
		},
	},
},  //IR IQ end	
};
#endif // _AR0237_IQ_H_

