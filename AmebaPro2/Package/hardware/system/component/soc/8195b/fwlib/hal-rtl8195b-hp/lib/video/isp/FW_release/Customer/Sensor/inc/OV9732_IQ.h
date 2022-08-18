#ifndef _OV9732_IQ_H_
#define _OV9732_IQ_H_

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
		{8,8,8,8},
		//{0, 0, 0, 0}
	},

	// LSC
	{
		// circle LSC for small resolution
		{
			{
				// circle LSC curve
				//{
				//	{128,   0, 128,   0, 130,   0, 134,   0, 139,   0, 144,   0, 151,   0, 159,   0, 168,   0, 179,   0, 190,   0, 202,   0, 215,   0, 215,   0, 215,   0, 215,   0, 215,   0, 215,   0, 215,   0, 215,   0, 215,   0, 215,   0, 215,   0, 215,   0, },
				//	{128,   0, 128,   0, 130,   0, 134,   0, 138,   0, 143,   0, 149,   0, 156,   0, 164,   0, 173,   0, 183,   0, 193,   0, 193,   0, 193,   0, 193,   0, 193,   0, 193,   0, 193,   0, 193,   0, 193,   0, 193,   0, 193,   0, 193,   0, 193,   0, },
				//	{128,   0, 128,   0, 130,   0, 134,   0, 138,   0, 143,   0, 149,   0, 156,   0, 163,   0, 171,   0, 180,   0, 188,   0, 188,   0, 188,   0, 188,   0, 188,   0, 188,   0, 188,   0, 188,   0, 188,   0, 188,   0, 188,   0, 188,   0, 188,   0, },
				//},
				{
					{128,   0, 130,   0, 134,   0, 137,   0, 141,   0, 147,   0, 153,   0, 162,   0, 171,   0, 181,   0, 192,   0, 203,   0, 215,   0, 215,   0, 215,   0, 215,   0, 215,   0, 215,   0, 215,   0, 215,   0, 215,   0, 215,   0, 215,   0, 215,   0, },
					{128,   0, 130,   0, 133,   0, 137,   0, 141,   0, 146,   0, 152,   0, 159,   0, 168,   0, 178,   0, 188,   0, 199,   0, 199,   0, 199,   0, 199,   0, 199,   0, 199,   0, 199,   0, 199,   0, 199,   0, 199,   0, 199,   0, 199,   0, 199,   0, },
					{129,   0, 130,   0, 133,   0, 136,   0, 140,   0, 144,   0, 150,   0, 158,   0, 167,   0, 176,   0, 184,   0, 194,   0, 194,   0, 194,   0, 194,   0, 194,   0, 194,   0, 194,   0, 194,   0, 194,   0, 194,   0, 194,   0, 194,   0, 194,   0, },
				},
				// circle LSC center: R Center Hortizontal, R Center Vertical, G Center Hortizontal, G Center Vertical,B Center Hortizontal, B Center Vertical
				//{640,345,641,346,637,352},
				//{606,391,616,368,637,358},
				{628,423,638,416,639,360},
				// step
				64,
			},

			// micro LSC
			{
				// micro LSC grid mode
				1,
				// micro LSC matrix
				{
					{
						0x4, 0x2, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x2, 0x4, 0x4, 0x2, 0x2, 0x2, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x2, 0x4, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2, 0x2, 0x3, 0x3, 0x3, 0x2, 0x3, 0x3, 0x3, 0x2, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2, 0x2, 0x3, 0x2, 0x2, 0x3, 0x2, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x3, 0x3, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x1, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x3, 0x3, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1, 0x4, 0x4, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x1, 0x1, 0x1, 0x2, 0x1, 0x2, 0x1, 0x1, 0x1, 0x4, 0x3, 0x3, 0x4, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x1, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1, 0x4, 0x4, 0x3, 0x3, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2, 0x4, 0x3, 0x4, 0x3, 0x3, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x1, 0x2, 0x2, 0x1, 0x1, 0x1, 0x2, 0x5, 0x5, 0x4, 0x3, 0x4, 0x4, 0x3, 0x2, 0x4, 0x2, 0x3, 0x2, 0x2, 0x1, 0x2, 0x2, 0x2, 0x1, 0x2, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
						0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x2, 0x3, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x2, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x1, 0x1, 0x2, 0x2, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x1, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2, 0x1, 0x1, 0x1, 0x2, 0x1, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
						0x6, 0x5, 0x4, 0x5, 0x5, 0x5, 0x5, 0x5, 0x6, 0x6, 0x4, 0x5, 0x5, 0x5, 0x6, 0x6, 0x7, 0x7, 0x7, 0x8, 0x7, 0x5, 0x5, 0x6, 0x6, 0x6, 0x5, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x7, 0x7, 0x7, 0x8, 0x8, 0x6, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x7, 0x7, 0x7, 0x8, 0x5, 0x5, 0x4, 0x5, 0x6, 0x6, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x6, 0x6, 0x7, 0x6, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x4, 0x3, 0x4, 0x3, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x5, 0x4, 0x4, 0x4, 0x4, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x3, 0x3, 0x2, 0x2, 0x2, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x2, 0x1, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x1, 0x1, 0x1, 0x2, 0x2, 0x3, 0x3, 0x2, 0x3, 0x3, 0x3, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x3, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2, 0x2, 0x2, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x0, 0x1, 0x0, 0x1, 0x2, 0x1, 0x1, 0x0, 0x2, 0x1, 0x2, 0x2, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
					},
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
					{128,   0, 130,   0, 133,   0, 138,   0, 145,   0, 154,   0, 165,   0, 177,   0, 191,   0, 213,   0, 248,   0,  37,   1,  89,   1,  89,   1,  89,   1,  89,   1,  89,   1,  89,   1,  89,   1,  89,   1,  89,   1,  89,   1,  89,   1,  89,   1, },
					{128,   0, 130,   0, 133,   0, 137,   0, 144,   0, 152,   0, 162,   0, 174,   0, 189,   0, 210,   0, 242,   0,  27,   1,  74,   1,  74,   1,  74,   1,  74,   1,  74,   1,  74,   1,  74,   1,  74,   1,  74,   1,  74,   1,  74,   1,  74,   1, },
					{128,   0, 129,   0, 131,   0, 134,   0, 138,   0, 143,   0, 150,   0, 159,   0, 170,   0, 188,   0, 216,   0, 249,   0,  30,   1,  30,   1,  30,   1,  30,   1,  30,   1,  30,   1,  30,   1,  30,   1,  30,   1,  30,   1,  30,   1,  30,   1, },
				},
				// circle LSC center: R Center Hortizontal, R Center Vertical, G Center Hortizontal, G Center Vertical,B Center Hortizontal, B Center Vertical
				{618,404,618,404,618,404},
				// step
				64,
			},

			// micro LSC
			{
				// micro LSC grid mode
				1,
				// micro LSC matrix
				{0},
			},
		},
		//   LSC for 8M
		{
			{
				// circle LSC curve
				{
					{128,   0, 130,   0, 133,   0, 138,   0, 145,   0, 154,   0, 165,   0, 177,   0, 191,   0, 213,   0, 248,   0,  37,   1,  89,   1,  89,   1,  89,   1,  89,   1,  89,   1,  89,   1,  89,   1,  89,   1,  89,   1,  89,   1,  89,   1,  89,   1, },
					{128,   0, 130,   0, 133,   0, 137,   0, 144,   0, 152,   0, 162,   0, 174,   0, 189,   0, 210,   0, 242,   0,  27,   1,  74,   1,  74,   1,  74,   1,  74,   1,  74,   1,  74,   1,  74,   1,  74,   1,  74,   1,  74,   1,  74,   1,  74,   1, },
					{128,   0, 129,   0, 131,   0, 134,   0, 138,   0, 143,   0, 150,   0, 159,   0, 170,   0, 188,   0, 216,   0, 249,   0,  30,   1,  30,   1,  30,   1,  30,   1,  30,   1,  30,   1,  30,   1,  30,   1,  30,   1,  30,   1,  30,   1,  30,   1, },
				},
				// circle LSC center: R Center Hortizontal, R Center Vertical, G Center Hortizontal, G Center Vertical,B Center Hortizontal, B Center Vertical
				{618,404,618,404,618,404},
				// step
				64,
			},

			// micro LSC
			{
				// micro LSC grid mode
				1,
				// micro LSC matrix
				{0},
			},
		},
#endif
		// dynamic LSC
		{
			168,   // Dynamic LSC Gain Threshold Low
			480,  // Dynamic LSC Gain Threshold High
			0x20,	// Dynamic LSC Adjust rate at Gain Threshold Low
			0x00,	// Dynamic LSC Adjust rate at Gain Threshold High
			{33,36,50,54,56,34},	// rough r gain before LSC, from A, U30, CWF, D50, D65, D75
			{81,64,69,44,41,72},	// rough b gain before LSC
			50,		// start threshold of dynamic LSC by CT, white pixel millesimal
			25,		// end threshold of dynamic LSC by CT, white pixel millesimal
			100,		// LSC switch color temperature threshold buffer
			{3100,3800,4600,5800,7000},	// LSC switch color temperature threshold
			{
				{0x19,0x19,0x19,},//a=2850k
				//{0x1f,0x20,0x1d,},//3500k
				{0x19,0x19,0x19,},//3500K
				{0x19,0x19,0x19,},//cwf=4150k
				{0x19,0x19,0x19,},//d50=5000k
				{0x19,0x19,0x19,},//d65=6500k
				{0x19,0x19,0x19,},//d75=6500k
			},
		},
	},

	// CCM
	{
		// normal ccm
		{
			// D65 light CCM
			//{0x1e4,-185,-43,-21,0x147,-50,-12,-292,0x230/*+10*/,},	//For MSOC test, pass premium
			//{0x200,-240,-16,-64,0x180,-64,16,-256,0x1f0},
			//{0x213,-258,-17,-73,0x18d,-68,11,-275,0x208},
			//{0x206,-244,-18,-98,0x1a9,-71,-10,-244,0x1fe},
			//{0x1d6,-208,-8,-91,0x168,-12,4,-244,0x1ef},
			{0x1b0,-175,-3,-73,0x150,-6,13,-207,0x1c2},
			//{0x217,-260,-19,-106,0x1b4,-74,-14,-260,0x212},
			// D50 light CCM
			//{0x293,-272,-131,-124,0x1b9,-60,-3,-368,0x273},	//For MSOC test, pass premium
			//{0x29f,-410,-5,-126,0x172,12,-25,-393,0x2a2},
			{0x170,-112,0,-96,0x180,-32,0,-240,0x1f0},
			// TL84 light CCM
			//{0x1e0,-141,-83,-176,0x200,-80,-115,-461,0x340},	//For MSOC test, pass premium
			//{0x1b0,-107,-69,-167,0x1ca,-35,-134,-540,0x3a1},
			//{0x213,-240,-35,-124,0x189,-12,-83,-640,0x3d3},
			//{0x1b0,-124,-51,-80,0x160,-16,12,-268,0x200},
			//{0x29f,-410,-5,-126,0x172,12,-25,-393,0x2a2},
			{0x233,-318,12,-75,0x131,25,6,-305,0x22b},
			// A light CCM
			//{0x1e0,-141,-83,-176,0x200,-80,-115,-461,0x340},	//For MSOC test, pass premium
			//{0x1b0,-107,-69,-167,0x1ca,-35,-134,-540,0x3a1},
			//{0x213,-240,-35,-124,0x189,-12,-83,-640,0x3d3},
			//{0x1b9,-166,-19,-128,0x180,0,-83,-342,0x2a9},
			{0x1a6,-151,-15,-119,0x173,4,-76,-318,0x28a}
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
			6000, //5200,	// dynamic CCM D65-CWF_H light Color Temperature Switch Threshold
			5500, //4500,	// dynamic CCM D65-CWF_L light Color Temperature Switch Threshold
			4600, //3850,	// dynamic CCM CWF_A_H light Color Temperature Switch Threshold
			4400, //3600,	// dynamic CCM CWF_A_L light Color Temperature Switch Threshold
			3900, //2700,	// dynamic CCM A_H_H light Color Temperature Switch Threshold
			3700, //2500,	// dynamic CCM A_H_L light Color Temperature Switch Threshold
		},
		// dynamic CCM Gain Threshold
		{
			192,	// dynamic CCM Gain Threshold Low
			288,	// dynamic CCM Gain Threshold High
		}
	},

	// Gamma
	{
		// normal light gamma
		//{0, 14, 28, 42, 53, 64, 74, 83, 89, 103, 115, 125, 134, 142, 149, 157, 163, 169, 175, 180, 185, 196, 206, 215, 223, 232, 240, 248,}, //Neil 0629 chicony tuning
		//{ 0, 15, 30, 45, 55, 65, 74, 83, 90, 103, 115, 125, 134, 142, 149, 156, 163, 169, 175, 180, 185, 195, 205, 215, 223, 232, 240, 248, },
		//{ 0, 15, 30, 45, 57, 69, 79, 89, 97, 110, 122, 132, 141, 149, 157, 164, 170, 176, 182, 187, 192, 202, 211, 220, 227, 234, 241, 248, },
		//{ 0, 16, 32, 47, 60, 72, 82, 91, 99, 113, 126, 137, 146, 155, 162, 169, 175, 180, 185, 190, 195, 204, 212, 220, 227, 234, 241, 248, },
		{0, 13, 25, 37, 47, 57, 66, 75, 83, 99, 112, 125, 136, 146, 155, 164, 172, 179, 186, 192, 198, 208, 218, 226, 233, 240, 246, 251},
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
			62, //52,	// YMean Target Low
			68, //58,	// YMean Target
			75, //65,	// YMean Target High
			10,	// Histogram Position Low
			190,// Histogram Position High
			3	// Dynamic AE Target decrease value
		},
		// AE limit
		{
			6,	// AE step Max value at 50Hz power line frequency
			8,	// AE step Max value at 60Hz power line frequency
			1023, //255,	// AE global gain Max value
			{	// AE continous frame rate gain threshold
				560,  //Gain threshold from 30 fps -> 25 fps
				560,  //Gain threshold from 25 fps -> 20 fps
				1024, //Gain threshold from 20 fps -> 15 fps
				1024, //Gain threshold from 15 fps -> 10 fps
				1024, //Gain threshold from 10 fps -> 05 fps
			},
			20, //User manual min FPS
			128,	// AE discrete frame rate 15fps gain threshold
			96,	// AE discrete frame rate 30fps gain threshold
			120	// AE HighLight mode threshold
		},
		// AE weight
		{
			/*{
				4,4,4,4,4,
				5,5,5,5,5,
				6,6,7,6,6,
				6,6,7,6,6,
				5,6,5,6,5,
			}*/
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
			{39/*40*/,39,50,54,62,66},	// g_aAWBRoughGain_R 	A U30 CWF D50 D65 D75
			{74/*76*/,73,66,52,46,40},	// g_aAWBRoughGain_B
			10,	// K1
			104,	// B1
			78,	// B2
			8,	// sK3
			53, //47,	// sB3
			-70,	// sK4
			410,	// sB4
			70, //64,	// sK5
			-80, //-95,// sB5
			6,	// sK6
			0,	// sB6
			113,	// B_up
			69,	// B_down
			61, //55,	// sB_left
			442,	// sB_right
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
			4	// g_byFtGainTh
		},
		// AWB sensitivity
		{
			8, // g_wAWBGainDiffTh
			4, // g_byAWBGainStep
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
			{ // M0
				0xA0,	//ISP_SHARPNESS  (0x8575)
				0xA0,	//ISP_SHARPNESS_V  (0x85A7)
			},
			{	// M1
				0xA0,		//ISP_SHARPNESS  (0x8575)
				0xA0,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M2
				0xA0,		//ISP_SHARPNESS  (0x8575)
				0xA0,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M3
				0x92,		//ISP_SHARPNESS  (0x8575)
				0x88,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M4
				0x92,		//ISP_SHARPNESS  (0x8575)
				0x88,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M5
				0x92,		//ISP_SHARPNESS  (0x8575)
				0x88,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M6
				0x92,		//ISP_SHARPNESS  (0x8575)
				0x88,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M7
				0x92,		//ISP_SHARPNESS  (0x8575)
				0x92,		//ISP_SHARP_V  (0x85A7)
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
				0x851A, 0x0C,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x57,	//ISP_NR_MODE
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
				0x8460, 0x0A,	//ISP_INTP_EDGE_THD
				0x8461, 0x35,	//ISP_INTP_DCT_B
				0x8462, 0x0C,	//ISP_INTP_DCT_K1
				0x8463, 0x0B,	//ISP_INTP_DCT_K2
				0x8464, 0x22,	//ISP_INTP_RGB_AFFECT
				0x8465, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8466, 0x85,	//ISP_INTP_LPF_CTRL
				0x8467, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8468, 0x0A,	//ISP_INTP_FCRD_SMOOTH
				0x8469, 0x20,	//ISP_MOIRE_G_AFFECT
				0x846b, 0x14,	//ISP_MOIRE_MAX
				0x847d, 0x15,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x847e, 0x50,	//ISP_ILOC_MAX
				0x847f, 0x20,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x44,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x60,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0A,	//ISP_RGB_DIIR_COEF
				0x8556, 0x01,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x08,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x0C,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x0E,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x10,	//ISP_RGB_DIIR_CHANGE_THD4

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
				0x8560, 0x14,	//ISP_EDG_DIFF_C0
				0x8561, 0xFF,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFF,	//ISP_EDG_DIFF_C3
				0x8564, 0xFF,	//ISP_EDG_DIFF_C4
				0x85A3, 0x04,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x14,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x10,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x1F,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x1F,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x01,	//ISP_EEH_SRC_SEL
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
				0x851A, 0x0C,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x57,	//ISP_NR_MODE
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
				0x8460, 0x0A,	//ISP_INTP_EDGE_THD
				0x8461, 0x35,	//ISP_INTP_DCT_B
				0x8462, 0x0C,	//ISP_INTP_DCT_K1
				0x8463, 0x0B,	//ISP_INTP_DCT_K2
				0x8464, 0x22,	//ISP_INTP_RGB_AFFECT
				0x8465, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8466, 0x85,	//ISP_INTP_LPF_CTRL
				0x8467, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8468, 0x0A,	//ISP_INTP_FCRD_SMOOTH
				0x8469, 0x20,	//ISP_MOIRE_G_AFFECT
				0x846b, 0x14,	//ISP_MOIRE_MAX
				0x847d, 0x15,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x847e, 0x50,	//ISP_ILOC_MAX
				0x847f, 0x20,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x44,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x60,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x44,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x60,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0A,	//ISP_RGB_DIIR_COEF
				0x8556, 0x01,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x08,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x0C,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x0E,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x10,	//ISP_RGB_DIIR_CHANGE_THD4

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
				0x8560, 0x14,	//ISP_EDG_DIFF_C0
				0x8561, 0xFF,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFF,	//ISP_EDG_DIFF_C3
				0x8564, 0xFF,	//ISP_EDG_DIFF_C4
				0x85A3, 0x04,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x14,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x10,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x1F,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x1F,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0A,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x01,	//ISP_EEH_SRC_SEL
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
				0x8520, 0x00,	//ISP_NR_GRGB_CTRL
				0x8522, 0x02,	//ISP_GRGB_BLNC_K
				0x8523, 0x02,	//ISP_GRGB_BLNC_D0
				0x8524, 0x12,	//ISP_GRGB_BLNC_D1
				0x851A, 0x0C,	//ISP_NR_EDGE_THD
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
				0x852A, 0x01,	//ISP_NR_MMM_ENABLE

				//Interpolation
				0x8460, 0x0C,	//ISP_INTP_EDGE_THD
				0x8461, 0x35,	//ISP_INTP_DCT_B
				0x8462, 0x0C,	//ISP_INTP_DCT_K1
				0x8463, 0x0B,	//ISP_INTP_DCT_K2
				0x8464, 0x44,	//ISP_INTP_RGB_AFFECT
				0x8465, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8466, 0x85,	//ISP_INTP_LPF_CTRL
				0x8467, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8468, 0x0A,	//ISP_INTP_FCRD_SMOOTH
				0x8469, 0x20,	//ISP_MOIRE_G_AFFECT
				0x846b, 0x14,	//ISP_MOIRE_MAX
				0x847d, 0x15,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x847e, 0x50,	//ISP_ILOC_MAX
				0x847f, 0x20,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x44,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x40,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x66,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x60,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0A,	//ISP_RGB_DIIR_COEF
				0x8556, 0x01,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x0C,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x0E,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x10,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x12,	//ISP_RGB_DIIR_CHANGE_THD4

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
				0x8560, 0x14,	//ISP_EDG_DIFF_C0
				0x8561, 0xFF,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFF,	//ISP_EDG_DIFF_C3
				0x8564, 0xFF,	//ISP_EDG_DIFF_C4
				0x85A3, 0x04,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x14,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x10,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x1F,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x1F,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0C,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x01,	//ISP_EEH_SRC_SEL
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
				0x851A, 0x0E,	//ISP_NR_EDGE_THD
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x8504, 0x10,	//ISP_RDLOC_MAX
				0x8505, 0x5C,	//ISP_RDLOC_RATE
				0x8506, 0x00,	//ISP_RDLOC_ENABLE
				0x851D, 0x0A,	//ISP_NR_MM_THD1
				0x850A, 0x02,	//ISP_RD_MM2_RATE
				0x851F, 0x57,	//ISP_NR_MODE
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
				0x8460, 0x0C,	//ISP_INTP_EDGE_THD
				0x8461, 0x35,	//ISP_INTP_DCT_B
				0x8462, 0x0C,	//ISP_INTP_DCT_K1
				0x8463, 0x0B,	//ISP_INTP_DCT_K2
				0x8464, 0x44,	//ISP_INTP_RGB_AFFECT
				0x8465, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8466, 0x88,	//ISP_INTP_LPF_CTRL
				0x8467, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8468, 0x0F,	//ISP_INTP_FCRD_SMOOTH
				0x8469, 0x20,	//ISP_MOIRE_G_AFFECT
				0x846b, 0x14,	//ISP_MOIRE_MAX
				0x847d, 0x18,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x847e, 0x50,	//ISP_ILOC_MAX
				0x847f, 0x20,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x66,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x80,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x66,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x80,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0C,	//ISP_RGB_DIIR_COEF
				0x8556, 0x01,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x0A,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x0C,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x0E,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x10,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x12,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x0E,	//ISP_EDG_DCT_THD1
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
				0x8560, 0x14,	//ISP_EDG_DIFF_C0
				0x8561, 0xFF,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFF,	//ISP_EDG_DIFF_C3
				0x8564, 0xFF,	//ISP_EDG_DIFF_C4
				0x85A3, 0x04,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x14,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x10,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x1B,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x1B,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0C,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x01,	//ISP_EEH_SRC_SEL
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
				0x851F, 0x67,	//ISP_NR_MODE
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
				0x8460, 0x0E,	//ISP_INTP_EDGE_THD
				0x8461, 0x35,	//ISP_INTP_DCT_B
				0x8462, 0x0C,	//ISP_INTP_DCT_K1
				0x8463, 0x0A,	//ISP_INTP_DCT_K2
				0x8464, 0x44,	//ISP_INTP_RGB_AFFECT
				0x8465, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8466, 0x8A,	//ISP_INTP_LPF_CTRL
				0x8467, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8468, 0x0F,	//ISP_INTP_FCRD_SMOOTH
				0x8469, 0x20,	//ISP_MOIRE_G_AFFECT
				0x846b, 0x14,	//ISP_MOIRE_MAX
				0x847d, 0x1A,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x847e, 0x50,	//ISP_ILOC_MAX
				0x847f, 0x30,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x88,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x80,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x88,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0x80,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0D,	//ISP_RGB_DIIR_COEF
				0x8556, 0x01,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x0C,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x0E,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x10,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x12,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x14,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x10,	//ISP_EDG_DCT_THD1
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
				0x8560, 0x14,	//ISP_EDG_DIFF_C0
				0x8561, 0xFF,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFF,	//ISP_EDG_DIFF_C3
				0x8564, 0xFF,	//ISP_EDG_DIFF_C4
				0x85A3, 0x04,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x14,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x10,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x17,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x17,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0D,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x01,	//ISP_EEH_SRC_SEL
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
				0x851A, 0x12,	//ISP_NR_EDGE_THD
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
				0x8460, 0x10,	//ISP_INTP_EDGE_THD
				0x8461, 0x35,	//ISP_INTP_DCT_B
				0x8462, 0x0C,	//ISP_INTP_DCT_K1
				0x8463, 0x0A,	//ISP_INTP_DCT_K2
				0x8464, 0x44,	//ISP_INTP_RGB_AFFECT
				0x8465, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8466, 0x8C,	//ISP_INTP_LPF_CTRL
				0x8467, 0x14,	//ISP_INTP_FCRD_EDGE
				0x8468, 0x0F,	//ISP_INTP_FCRD_SMOOTH
				0x8469, 0x20,	//ISP_MOIRE_G_AFFECT
				0x846b, 0x14,	//ISP_MOIRE_MAX
				0x847d, 0x1C,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x847e, 0x50,	//ISP_ILOC_MAX
				0x847f, 0x30,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x8A,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0xA0,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0x8A,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0xA0,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0D,	//ISP_RGB_DIIR_COEF
				0x8556, 0x01,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x0E,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x10,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x12,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x14,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x16,	//ISP_RGB_DIIR_CHANGE_THD4

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
				0x85B4, 0x16,	//ISP_LOC_MAX
				0x85B5, 0x54,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x14,	//ISP_EDG_DIFF_C0
				0x8561, 0xFF,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFF,	//ISP_EDG_DIFF_C3
				0x8564, 0xFF,	//ISP_EDG_DIFF_C4
				0x85A3, 0x04,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x14,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x10,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x13,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x13,	//ISP_DARK_RATE
				0x856A, 0x08,	//ISP_EEH_UVIIR_Y_CUTS
				0x856B, 0x04,	//ISP_EEH_UVIIR_Y_CMIN
				0x856C, 0x0D,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x01,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x01,	//ISP_EEH_SRC_SEL
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
				0x8460, 0x14,	//ISP_INTP_EDGE_THD
				0x8461, 0x35,	//ISP_INTP_DCT_B
				0x8462, 0x0C,	//ISP_INTP_DCT_K1
				0x8463, 0x0A,	//ISP_INTP_DCT_K2
				0x8464, 0x44,	//ISP_INTP_RGB_AFFECT
				0x8465, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8466, 0x8D,	//ISP_INTP_LPF_CTRL
				0x8467, 0x19,	//ISP_INTP_FCRD_EDGE
				0x8468, 0x14,	//ISP_INTP_FCRD_SMOOTH
				0x8469, 0x20,	//ISP_MOIRE_G_AFFECT
				0x846b, 0x14,	//ISP_MOIRE_MAX
				0x847d, 0x1D,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x847e, 0x50,	//ISP_ILOC_MAX
				0x847f, 0x30,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0xAA,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0xC0,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0xAA,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0xC0,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0D,	//ISP_RGB_DIIR_COEF
				0x8556, 0x02,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x10,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x12,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x14,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x16,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x18,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x14,	//ISP_EDG_DCT_THD1
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
				0x8560, 0x14,	//ISP_EDG_DIFF_C0
				0x8561, 0xFF,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFF,	//ISP_EDG_DIFF_C3
				0x8564, 0xFF,	//ISP_EDG_DIFF_C4
				0x85A3, 0x04,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x14,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x10,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
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
				0x856C, 0x0D,	//ISP_EEH_IIR_COEF
				0x856D, 0x02,	//ISP_EEH_IIR_CUTS
				0x856E, 0x02,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x01,	//ISP_EEH_SRC_SEL
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
				0x851A, 0x04,	//ISP_NR_EDGE_THD
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
				0x8463, 0x0A,	//ISP_INTP_DCT_K2
				0x8464, 0x44,	//ISP_INTP_RGB_AFFECT
				0x8465, 0x1F,	//ISP_INTP_GRGB_DIFF
				0x8466, 0x8D,	//ISP_INTP_LPF_CTRL
				0x8467, 0x19,	//ISP_INTP_FCRD_EDGE
				0x8468, 0x19,	//ISP_INTP_FCRD_SMOOTH
				0x8469, 0x20,	//ISP_MOIRE_G_AFFECT
				0x846b, 0x14,	//ISP_MOIRE_MAX
				0x847d, 0x1D,	//ISP_INTP_EDGE_SMOOTH
				0x8500, 0x00,	//ISP_RDLOC_DIST_START_L
				0x8501, 0x03,	//ISP_RDLOC_DIST_START_H
				0x8502, 0x64,	//ISP_RDLOC_DIST_END_L
				0x8503, 0x04,	//ISP_RDLOC_DIST_END_H
				0x847e, 0x50,	//ISP_ILOC_MAX
				0x847f, 0x30,	//ISP_ILOC_RATE

				//RGB De-noise
				0x8550, 0x07,	//ISP_RGB_IIR_CTRL
				0x8552, 0x44,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x40,	//ISP_RGB_VIIR_G_COEF
				0x855D, 0xAA,	//ISP_RGB_HLPF_RB_COEF
				0x855C, 0xC0,	//ISP_RGB_VIIR_RB_COEF
				0x8553, 0xA2,	//ISP_RGB_DIIR_MAX
				0x8555, 0x0C,	//ISP_RGB_BRIGHT_COEF
				0x8554, 0x0D,	//ISP_RGB_DIIR_COEF
				0x8556, 0x02,	//ISP_RGB_DIIR_COFF_CUT
				0x8557, 0x17,	//ISP_RGB_DIIR_CHANGE_THD0
				0x8558, 0x19,	//ISP_RGB_DIIR_CHANGE_THD1
				0x8559, 0x1B,	//ISP_RGB_DIIR_CHANGE_THD2
				0x855A, 0x1D,	//ISP_RGB_DIIR_CHANGE_THD3
				0x855B, 0x1F,	//ISP_RGB_DIIR_CHANGE_THD4

				//Edge enhance
				0x8565, 0x16,	//ISP_EDG_DCT_THD1
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
				0x8560, 0x14,	//ISP_EDG_DIFF_C0
				0x8561, 0xFF,	//ISP_EDG_DIFF_C1
				0x8562, 0xFF,	//ISP_EDG_DIFF_C2
				0x8563, 0xFF,	//ISP_EDG_DIFF_C3
				0x8564, 0xFF,	//ISP_EDG_DIFF_C4
				0x85A3, 0x04,	//ISP_EDG_DIFF_C5
				0x85A4, 0x01,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFD,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x14,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x10,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
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
				0x856E, 0x02,	//ISP_EEH_IIR_STEP
				0x856F, 0x01,	//ISP_EEH_IIR_ENABLE
				0x85A8, 0x01,	//ISP_EEH_SRC_SEL
				0x8573, 0x1F,	//ISP_FCRD_MAX
				0x8570, 0x02,	//ISP_FCRD_MIN
				0x8572, 0x90,	//ISP_FCRD_CFG
				0x8571, 0x12,	//ISP_FCRD_YCUTS

				//3DNR
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
		0,// 3,		// A light U offset
		0,// 4,		// A light V offset
		0,// 3,		// D65 light U offset
		0,// 4,		// D65 light V offset
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
	{0xe62d0, 0x7494, 0x4de7, 0x3dc08, 0x43e31, 0x783bc, 0x4ff, 0x2cf, 0x18f601, 0x7e361, 0, },
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
			40,	// YMean Target Low
			50,	// YMean Target
			60,	// YMean Target High
			8,	// Histogram Position Low
			190,// Histogram Position High
			3	// Dynamic AE Target decrease value
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
			64*16,	// dynamic CCM Gain Threshold Low
			64*16,	// dynamic CCM Gain Threshold High
		}
	},

	// IR Gamma
	{
		// normal light gamma
		//{0, 14, 28, 42, 53, 64, 74, 83, 89, 103, 115, 125, 134, 142, 149, 157, 163, 169, 175, 180, 185, 196, 206, 215, 223, 232, 240, 248,}, //Neil 0629 chicony tuning
		//{ 0, 15, 30, 45, 55, 65, 74, 83, 90, 103, 115, 125, 134, 142, 149, 156, 163, 169, 175, 180, 185, 195, 205, 215, 223, 232, 240, 248, },
		//{ 0, 15, 30, 45, 57, 69, 79, 89, 97, 110, 122, 132, 141, 149, 157, 164, 170, 176, 182, 187, 192, 202, 211, 220, 227, 234, 241, 248, },
//		{ 0, 16, 32, 47, 60, 72, 82, 91, 99, 113, 126, 137, 146, 155, 162, 169, 175, 180, 185, 190, 195, 204, 212, 220, 227, 234, 241, 248, },
//		{0, 20, 40, 56, 69, 80, 87, 93, 99, 109, 119, 128, 136, 143, 150, 157, 163, 169, 175, 181, 186, 196, 206, 215, 224, 232, 240, 248,}, //[Albert, 2011/06/09]
		{ 0, 16, 31, 44, 56, 66, 76, 84, 92, 105, 116, 126, 135, 142, 149, 156, 163, 169, 174, 180, 185, 195, 206, 215, 223, 232, 240, 248, },
		// low light gamma
		{ 0, 16, 31, 44, 56, 66, 76, 84, 92, 105, 116, 126, 135, 142, 149, 156, 163, 169, 174, 180, 185, 195, 206, 215, 223, 232, 240, 248, },
		1024,	// dynamic Gamma Gain Threshold Low
		1024	// dynamic Gamma Gain Threshold High
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
				0xB4,		//ISP_SHARPNESS  (0x8575)
				0xB4,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M1
				0xB4,		//ISP_SHARPNESS  (0x8575)
				0xB4,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M2
				0xB4,		//ISP_SHARPNESS  (0x8575)
				0xB4,		//ISP_SHARP_V  (0x85A7)
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
				0x78,		//ISP_SHARPNESS  (0x8575)
				0x78,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M6
				0x78,		//ISP_SHARPNESS  (0x8575)
				0x78,		//ISP_SHARP_V  (0x85A7)
			},
			{	// M7
				0x78,		//ISP_SHARPNESS  (0x8575)
				0x78,		//ISP_SHARP_V  (0x85A7)
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
				0x8520, 0x00,	//ISP_NR_GRGB_CTRL
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
				0x8552, 0x35,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x40,	//ISP_RGB_VIIR_G_COEF
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
				0x85B5, 0x19,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x08,	//ISP_EDG_DIFF_C0
				0x8561, 0x04,	//ISP_EDG_DIFF_C1
				0x8562, 0x02,	//ISP_EDG_DIFF_C2
				0x8563, 0xFC,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0C,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFC,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFE,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x14,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x10,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x1F,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x1F,	//ISP_DARK_RATE
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
				0x8886, 0xE0,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x03,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0xC0,	//TPNR_REGF_DIST_OUTERRADIUS_L
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
				0x8520, 0x00,	//ISP_NR_GRGB_CTRL
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
				0x8552, 0x35,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x40,	//ISP_RGB_VIIR_G_COEF
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
				0x85B5, 0x19,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x08,	//ISP_EDG_DIFF_C0
				0x8561, 0x04,	//ISP_EDG_DIFF_C1
				0x8562, 0x02,	//ISP_EDG_DIFF_C2
				0x8563, 0xFC,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0C,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFC,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFE,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x14,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x10,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x1F,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x1F,	//ISP_DARK_RATE
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
				0x8886, 0xE0,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x03,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0xC0,	//TPNR_REGF_DIST_OUTERRADIUS_L
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
				0x8520, 0x00,	//ISP_NR_GRGB_CTRL
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
				0x8552, 0x35,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x40,	//ISP_RGB_VIIR_G_COEF
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
				0x85B5, 0x19,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x08,	//ISP_EDG_DIFF_C0
				0x8561, 0x04,	//ISP_EDG_DIFF_C1
				0x8562, 0x02,	//ISP_EDG_DIFF_C2
				0x8563, 0xFC,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0C,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFC,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFE,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x14,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x10,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x1F,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x1F,	//ISP_DARK_RATE
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
				0x8886, 0xE0,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x03,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0xC0,	//TPNR_REGF_DIST_OUTERRADIUS_L
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
				0x8520, 0x00,	//ISP_NR_GRGB_CTRL
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
				0x8552, 0x35,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x40,	//ISP_RGB_VIIR_G_COEF
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
				0x85B5, 0x19,	//ISP_LOC_RATE
				0x85B6, 0x00,	//ISP_LOC_ENABLE
				0x8560, 0x08,	//ISP_EDG_DIFF_C0
				0x8561, 0x04,	//ISP_EDG_DIFF_C1
				0x8562, 0x02,	//ISP_EDG_DIFF_C2
				0x8563, 0xFC,	//ISP_EDG_DIFF_C3
				0x8564, 0xFE,	//ISP_EDG_DIFF_C4
				0x85A3, 0x0C,	//ISP_EDG_DIFF_C5
				0x85A4, 0xFC,	//ISP_EDG_DIFF_C6
				0x85A5, 0xFE,	//ISP_EDG_DIFF_C7
				0x85A6, 0x01,	//ISP_INDEP_SHARPV_EN
				0x85E4, 0x08,	//ISP_EEH_SHARP_ARRAY0
				0x85E5, 0x0C,	//ISP_EEH_SHARP_ARRAY1
				0x85E6, 0x1A,	//ISP_EEH_SHARP_ARRAY2
				0x85E7, 0x0C,	//ISP_EEH_SHARP_ARRAY3
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x14,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x10,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x1F,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x1F,	//ISP_DARK_RATE
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
				0x8886, 0xE0,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x03,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0xC0,	//TPNR_REGF_DIST_OUTERRADIUS_L
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
				0x8520, 0x00,	//ISP_NR_GRGB_CTRL
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
				0x851F, 0x33,	//ISP_NR_MODE
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
				0x8552, 0x8C,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x80,	//ISP_RGB_VIIR_G_COEF
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
				0x8565, 0x0C,	//ISP_EDG_DCT_THD1
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
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x14,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x10,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x1F,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x1F,	//ISP_DARK_RATE
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
				0x8886, 0xE0,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x03,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0xC0,	//TPNR_REGF_DIST_OUTERRADIUS_L
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
				0x8520, 0x00,	//ISP_NR_GRGB_CTRL
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
				0x851F, 0x33,	//ISP_NR_MODE
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
				0x8552, 0x8C,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x80,	//ISP_RGB_VIIR_G_COEF
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
				0x8565, 0x0C,	//ISP_EDG_DCT_THD1
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
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x14,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x10,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x1F,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x1F,	//ISP_DARK_RATE
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
				0x8886, 0xE0,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x03,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0xC0,	//TPNR_REGF_DIST_OUTERRADIUS_L
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
				0x8520, 0x00,	//ISP_NR_GRGB_CTRL
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
				0x851F, 0x33,	//ISP_NR_MODE
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
				0x8552, 0x8C,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x80,	//ISP_RGB_VIIR_G_COEF
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
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x14,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x10,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x1F,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x1F,	//ISP_DARK_RATE
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
				0x8886, 0xE0,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x03,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0xC0,	//TPNR_REGF_DIST_OUTERRADIUS_L
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
				0x8520, 0x00,	//ISP_NR_GRGB_CTRL
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
				0x851F, 0x33,	//ISP_NR_MODE
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
				0x8552, 0x8C,	//ISP_RGB_HLPF_G_COEF
				0x8551, 0x80,	//ISP_RGB_VIIR_G_COEF
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
				0x85E8, 0x10,	//ISP_EEH_SHARP_ARRAY4
				0x85E9, 0x14,	//ISP_EEH_SHARP_ARRAY5
				0x85EA, 0x10,	//ISP_EEH_SHARP_ARRAY6
				0x85EB, 0x14,	//ISP_EEH_SHARP_ARRAY7
				0x85EC, 0x12,	//ISP_EEH_SHARP_ARRAY8
				0x85ED, 0x0C,	//ISP_EEH_SHARP_ARRAY9
				0x85EE, 0x14,	//ISP_EEH_SHARP_ARRAY10
				0x85EF, 0x10,	//ISP_EEH_SHARP_ARRAY11
				0x85F0, 0x0A,	//ISP_BRIGHT_TRM_B1
				0x85F1, 0x16,	//ISP_BRIGHT_TRM_B2
				0x85F2, 0x0A,	//ISP_BRIGHT_TRM_THD0
				0x85F3, 0x1F,	//ISP_BRIGHT_TRM_THD1
				0x85F4, 0x09,	//ISP_BRIGHT_TRM_K
				0x85FA, 0x1F,	//ISP_BRIGHT_RATE
				0x85F5, 0x0A,	//ISP_DARK_TRM_B1
				0x85F6, 0x16,	//ISP_DARK_TRM_B2
				0x85F7, 0x0A,	//ISP_DARK_TRM_THD0
				0x85F8, 0x1F,	//ISP_DARK_TRM_THD1
				0x85F9, 0x09,	//ISP_DARK_TRM_K
				0x85FB, 0x1F,	//ISP_DARK_RATE
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
				0x8886, 0xE0,	//TPNR_REGF_DIST_INNERRADIUS_L
				0x8887, 0x03,	//TPNR_REGF_DIST_OUTERRADIUS_H
				0x8888, 0xC0,	//TPNR_REGF_DIST_OUTERRADIUS_L
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
#endif // _OV9732_IQ_H_

