#ifndef __RTL8721D_DMA_H__
#define __RTL8721D_DMA_H__

#ifndef __ASSEMBLY__
/*--------------------Define -------------------------------------------*/
#define DDMACH0_MSK       BIT0
#define DDMACH1_MSK       BIT1
#define DDMACH0_ISR_CLEAR       BIT0
#define DDMACH1_ISR_CLEAR       BIT1
#define DDMACH0_ISR       BIT0//8 
#define DDMACH1_ISR       BIT1//9 

#define BIT_MASK_DDMA_DLEN       0x3FFFF
#define BIT_DDMA_OWN             BIT31
#define BIT_DDMA_CHKSUM_EN       BIT29
#define BIT_DDMA_DDMA_MODE       BIT26
#define BIT_DDMA_SPICBURST_MODE  BIT21
#define BIT_DDMA_FLASHBURST_MODE BIT20

#define BIT_MASK_DDMA_ADDR       0xFFFFFFFF

#define BIT_DDMA_CHKSUM_STS      BIT3

#define DDMACH_DEST_OFSET       0x4
#define DDMACH_CTRL_OFSET       0x8

#define DDMA_BB_BASEADDR            0x43000800 //2k size
#define DDMA_RFC_BASEADDR           0x43003800 //1k size
#define DDMA_TXFF_BASEADDR          0x43010000
#define DDMA_REG_BASEADDR           0x43000000
#define DDMA_EXT_PTCL_BASEADDR      0x43001400 //256byte
#define DDMA_BACAM_BASEADDR         0x43051000 //512 byte
#define DDMA_SECCAM_BASEADDR        0x43050800 //640 byte
/*--------------------Define Enum---------------------------------------*/

/*--------------------Define MACRO--------------------------------------*/

/*--------------------Define Struct-------------------------------------*/

/*--------------------Export global variable----------------------------*/

/*--------------------Function declaration------------------------------*/

extern BOOLEAN
InitDDMA_8721D_ROM(
	IN  u8  ch_num,
	IN  u32 saddr,
	IN  u32 daddr,
	IN  u32 dma_size,
	IN  BOOLEAN chksum_en,
	IN  BOOLEAN blockcpu,
	IN  BOOLEAN spic_burst_mode,
	IN  BOOLEAN flash_burst_mode
);

extern BOOLEAN
WaitDDMARDY_8721D_ROM(
	u8 ch_num
);

extern BOOLEAN
ChkDDMAChksum_8721D_ROM(
	u8 ch_num
);

extern BOOLEAN
CheckDDMADone_8721D_ROM(
	IN u8 ch_num,
	IN u8 chk_chksum
);

#endif  //#ifndef __ASSEMBLY__
#endif  //#ifndef   __RTL8721D_DMA_H__
