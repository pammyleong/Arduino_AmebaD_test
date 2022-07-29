#ifndef __WIFIFW_INT_H__
#define __WIFIFW_INT_H__

#ifndef __ASSEMBLY__
/*--------------------Define --------------------------------------------*/
#define CLKIs32K  1
#define CLKIs40M  0
/*--------------------Function declaration---------------------------------*/
extern void ClrAllFWUsedIMR_8730A_ROM(void);
extern void ClrAllFWUsedISR_8730A_ROM(void);
extern void UpdateISRWlan_8730A_ROM(void);
extern void UpdateISRFT_8730A_ROM(void);
extern void setfwimr_8730A_ROM(u32 index, u32 bitmask);
extern void clrfwimr_8730A_ROM(u32 index, u32 bitmask);
extern void setwlanimr_8730A_ROM(u32 index, u32 bitmask);
extern void clrwlanimr_8730A_ROM(u32 index, u32 bitmask);
extern void setftimr_8730A_ROM(u32 index, u32 bitmask);
extern void clrftimr_8730A_ROM(u32 index, u32 bitmask);

#endif  /* #ifndef __ASSEMBLY__ */
#endif /* __WIFIFW_INT_H__ */
