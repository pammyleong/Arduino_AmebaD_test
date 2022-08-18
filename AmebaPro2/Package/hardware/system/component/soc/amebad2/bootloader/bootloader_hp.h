/**
  ******************************************************************************
  * @file    bootloader_hp.h
  * @author
  * @version V1.0.0
  * @date    2016-05-17
  * @brief   This file contains all the definations of platform.
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2016, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef _HAL_BOOT_
#define _HAL_BOOT_

#define CERT_SIZE_4K_ALIGN		0x1000
#define CERT_MAX_KEYINFO		5

#define KEYID_NSPE				0
#define KEYID_SPE				1
#define KEYID_AP				2

#define NAND_L2P_TABLE_MARK_BAD				0x2
#define NAND_L2P_TABLE_MARK_GOOD			0x1
/*each block id occupy two bits to decide block status: 0b00 is not check, 0b01 is good, 0b10 is bad.*/
#define NAND_L2P_TABLE_SET_BAD(block_id)	(nand_l2p_table[(block_id) >> 4] |= (NAND_L2P_TABLE_MARK_BAD << (((block_id) & 0xF) << 1)))
#define NAND_L2P_TABLE_SET_GOOD(block_id)	(nand_l2p_table[(block_id) >> 4] |= (NAND_L2P_TABLE_MARK_GOOD << (((block_id) & 0xF) << 1)))
#define NAND_L2P_TABLE_GET(block_id)		((nand_l2p_table[(block_id) >> 4] >> (((block_id) & 0xF) << 1)) & 0x3)

typedef struct {
	unsigned int KeyID;
	unsigned char Hash[32];

} CertEntry_TypeDef;

typedef struct {
	unsigned char Pattern[8];
	unsigned char Rsvd1[8];
	unsigned char Ver;
	unsigned char ImgID;
	unsigned char AuthAlg;
	unsigned char HashAlg;
	unsigned int KeyVer;
	unsigned int TableSize;
	unsigned int EntryNum;
	unsigned char SBPubKey[PKEY_MAX_LEN];
	CertEntry_TypeDef PKInfo[CERT_MAX_KEYINFO];
	// Signature
} Certificate_TypeDef;

void BOOT_ImgCopy(void *__restrict dst0, const void *__restrict src0, size_t len0);
void BOOT_OTFMaskConfig(void);
int BOOT_LoadRDPImg(Manifest_TypeDef *Manifest, SubImgInfo_TypeDef *SubImgInfo);
void BOOT_SignatureCheck(Manifest_TypeDef *Manifest, SubImgInfo_TypeDef *SubImgInfo, u8 SubImgNum, Certificate_TypeDef *Cert, u32 KeyID);
void BOOT_CertificateCheck(Certificate_TypeDef *Cert, u32 addr);
#endif

