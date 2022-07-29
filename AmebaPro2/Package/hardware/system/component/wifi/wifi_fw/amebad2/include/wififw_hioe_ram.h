#ifndef __WIFIFW_HIOE_RAM_H__
#define __WIFIFW_HIOE_RAM_H__

#define SET_HIOE_BACKUP		1
#define SET_HIOE_RESTORE	1

extern u32 PG_BackupRestoreREGTable[];
extern void SetHIOEConfigFile_8730A(void);
extern void HIOEBackupRestore_8730A(bool mode);
extern void CHKHigh8kTXFFPGUseOverlap_8730A(void);
#endif
