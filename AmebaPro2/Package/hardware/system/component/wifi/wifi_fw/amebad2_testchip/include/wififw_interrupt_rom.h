#ifndef __RTL8721D_INT_H__
#define __RTL8721D_INT_H__

#ifndef __ASSEMBLY__
/*--------------------Define --------------------------------------------*/
#define BIT_DBG_TRIGGER     BIT0
#define BIT_CD_TRIGGER      BIT5

#define CLKIs32K  1
#define CLKIs40M  0

/*--------------------Function declaration---------------------------------*/
extern void
ClrAllFWUsedIMR_8721D_ROM(
	void
);

extern void
ClrAllFWUsedISR_8721D_ROM(
	void
);

extern void
UpdateISRWlan_8721D_ROM(
	void
);

extern void
UpdateISRFT_8721D_ROM(
	void
);

extern void
setfwimr_8721D_ROM(
	IN u32 index,
	IN u32 bitmask
);

void
clrfwimr_8721D_ROM(
	IN u32 index,
	IN u32 bitmask
);

extern void
setwlanimr_8721D_ROM(
	IN u32 index,
	IN u32 bitmask
);

extern void
clrwlanimr_8721D_ROM(
	IN u32 index,
	IN u32 bitmask
);

extern void
setftimr_8721D_ROM(
	IN u32 index,
	IN u32 bitmask
);

extern void
clrftimr_8721D_ROM(
	IN u32 index,
	IN u32 bitmask
);

#endif  //#ifndef __ASSEMBLY__
#endif  //__RTL8721D_INT_H__

