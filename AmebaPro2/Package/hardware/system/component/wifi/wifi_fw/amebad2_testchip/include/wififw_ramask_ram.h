#ifndef __WIFIFW_RAMASK_RAM_H__
#define __WIFIFW_RAMASK_RAM_H__


#if CONFIG_RATE_ADAPTIVE
extern u8 ReadRAMASKByte(u8 macid, u8 offset);
extern u32 ReadRAMASKDWORD(u8 macid, u8 offset);
extern void WriteRAMASKByte(u8 macid, u8 offset, u8 val);
extern void WriteRAMASKDword(u8 macid, u8 offset, u32 val);
#endif



#endif