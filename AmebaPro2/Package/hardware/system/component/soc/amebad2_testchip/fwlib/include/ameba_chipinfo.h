#ifndef _AMEBAD2_CHIPINFO_H_
#define _AMEBAD2_CHIPINFO_H_

/** @defgroup Memory_Type
  * @{
  */
enum Memory_Type {
	Memory_Type_DDR = 0x01,
	Memory_Type_PSRAM = 0x02,
	Memory_Type_None = 0xFF,
};

/**
  * @}
  */

/** @defgroup DDR_Type_define
  * @{
  */
enum DDR_Type {
	DDR_Type_DDR2 = 0x01,
	DDR_Type_DDR3 = 0x02, /*not real DDR3 in testchip, it's for debug package*/
	DDR_Type_LPDDR1 = 0x03,
	DDR_Type_None = 0xFF,
};
/**
  * @}
  */

/** @defgroup DDR_Size_define
  * @{
  */
enum DDR_Size {
	DDR_Size_256M = 0x01,
	DDR_Size_512M = 0x02,
	DDR_Size_1G = 0x03,
	DDR_Size_None = 0xFF,
};
/**
  * @}
  */

/** @defgroup Memory_vendor_define
  * @{
  */
enum Memory_vendor {
	Vendor_PSRAM_APM = 0x01,
	Vendor_PSRAM_Winbond = 0x02,
	Vendor_None = 0xFF,
};
/**
  * @}
  */

/** @defgroup MemoryInfo_TypeDef
  * @{
  */
typedef struct {
	u16 bdnum;
	u8 memory_type;
	u8 ddr_type;
	u8 ddr_size;
	u8 memory_vendor;
} MemoryInfo_TypeDef;
/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup HWINFO_Exported_Functions HWINFO Exported Functions
  * @{
  */
_LONG_CALL_ u16 ChipInfo_BDNum(void);
_LONG_CALL_ u8 ChipInfo_MemoryType(void);
_LONG_CALL_ u8 ChipInfo_DDRType(void);
_LONG_CALL_ u8 ChipInfo_DDRSize(void);
_LONG_CALL_ u8 ChipInfo_MemoryVendor(void);
/**
  * @}
  */

#endif
