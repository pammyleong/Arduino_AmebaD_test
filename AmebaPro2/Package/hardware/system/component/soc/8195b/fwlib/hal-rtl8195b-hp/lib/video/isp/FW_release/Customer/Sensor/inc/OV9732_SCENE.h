#ifndef _OV9732_SCENE_H_
#define _OV9732_SCENE_H_
#ifdef _SCENE_MODE_
SceneModePrm_t  code tSceneModePrm=
{
	150,		//bySnowModeAETargetShiftRate
	150,		//byBacklitModeAETargetShiftRate
	290,		//wCandlelightAWBGainR
	759,		//wCandlelightAWBGainB
	17,	//sK3
	28,	//sB3
	17,	//sK4
	1,	//sB4
	65,	//sK5
	-60,	//sB5
	5,	//sK6
	37,	//sB6
	38,	//sleft
	-9,	//sright

	//AUTO
	{
		{
		//AWB
		100,		//wAWBRGainShiftRate
		100,		//wAWBBGainShiftRate
		//AF
		0,		//byAFPosStart
		23,		//byAFPosEnd
		},

		//Macro
		{
		//AWB
		100,		//wAWBRGainShiftRate
		100,		//wAWBBGainShiftRate
		//AF
		10,		//byAFPosStart
		23,		//byAFPosEnd
		},

		//PORTRAIT
		{
		//AWB
		100,		//wAWBRGainShiftRate
		100,		//wAWBBGainShiftRate
		//AF
		10,		//byAFPosStart
		23,		//byAFPosEnd
		},

		//SPORT
		{
		//AWB
		100,		//wAWBRGainShiftRate
		100,		//wAWBBGainShiftRate
		//AF
		0,		//byAFPosStart
		10,		//byAFPosEnd
		},

		//SNOW
		{
		//AWB
		100,		//wAWBRGainShiftRate
		100,		//wAWBBGainShiftRate
		//AF
		0,		//byAFPosStart
		10,		//byAFPosEnd
		},

		//NIGHT
		{1},

		//BEACH
		{
		//AWB
		100,		//wAWBRGainShiftRate
		150,		//wAWBBGainShiftRate
		//AF
		0,		//byAFPosStart
		10,		//byAFPosEnd
		},

		//SUNSET
		{
		//AWB
		150,		//wAWBRGainShiftRate
		80,		//wAWBBGainShiftRate
		//AF
		0,		//byAFPosStart
		10,		//byAFPosEnd
		},
		//CANDLELIGHT
		{
		//AWB
		100,		//wAWBRGainShiftRate
		100,		//wAWBBGainShiftRate
		//AF
		0,		//byAFPosStart
		23,		//byAFPosEnd
		},
		//LANDSCAPE
		{
		//AWB
		100,		//wAWBRGainShiftRate
		100,		//wAWBBGainShiftRate
		//AF
		0,		//byAFPosStart
		10,		//byAFPosEnd
		},
		//NIGHTPORTRAIT
		{1},
		//BACKLIT
		{
		//AWB
		100,		//wAWBRGainShiftRate
		100,		//wAWBBGainShiftRate
		//AF
		0,		//byAFPosStart
		10,		//byAFPosEnd
		},
		//MANUAL
	},
};
#endif // _SCENE_MODE_
#endif // _OV9732_SCENE_H_

