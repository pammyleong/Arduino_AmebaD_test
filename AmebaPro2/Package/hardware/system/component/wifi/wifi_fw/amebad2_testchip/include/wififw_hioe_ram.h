#ifndef __WIFIFW_HIOE_RAM_H__
#define __WIFIFW_HIOE_RAM_H__

#define RFC_BACKUP      1
#define RFC_RESTORE    0

#define HIOE_BACKUP	1
#define HIOE_RESTORE	0
#define SET_HIOE_RESTORE 1
#define SET_HIOE_BACKUP 1

#define SET_DDMA_BACKUP 	0
#define SET_DDMA_RESTORE	0
#define HIOE_REG_ADDR_MASK	0x007FFFFF
#define HIOE_ACCESS_BYTE_MODE		0x00000000
#define HIOE_ACCESS_DWORD_MODE		0x00000001
#define HIOE_BYTE_SEL_MASK		0x0000000F
#define HIOECMD_WM0(reg_addr)		\
	(HIOE_ACCESS_DWORD_MODE | ((((u32)(reg_addr)) & HIOE_REG_ADDR_MASK)<<1))

#define HIOECMD_WM1(byte_sel)		(((u32)(byte_sel) & HIOE_BYTE_SEL_MASK)<<24)


#define HIOECMD_BM(reg_addr)		\
	(HIOE_ACCESS_BYTE_MODE | ((((u32)(reg_addr)) & HIOE_REG_ADDR_MASK)<<1))

extern u32 PG_BackupRestoreREGTable[];


extern void
SetHIOEConfigFile(
	void
);

extern void
HIOEBackupRestore(
	bool mode
);

extern void
DDMABackupRestore(
	bool mode
);

extern void
CHKHigh8kTXFFPGUseOverlap(
	void
);

#endif
