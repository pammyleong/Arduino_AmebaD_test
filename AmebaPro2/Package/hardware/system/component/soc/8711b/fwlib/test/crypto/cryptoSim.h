/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */

#ifndef _CRYPTOSIM_H_
#define _CRYPTOSIM_H_


#include "hal_crypto.h"
#include "rtl8711b_crypto.h"

/**************************************************************************
 * Definitions for basic types in crypto
 **************************************************************************/


#ifndef SUCCESS
#define SUCCESS     0
#endif

#ifndef FAILED
#define FAILED -1
#endif

typedef unsigned long long  	uint64;
typedef long long       		int64;
typedef unsigned int    		uint32;
typedef int         			int32;
typedef unsigned short  		uint16;
typedef short           		int16;
typedef unsigned char   		uint8;
typedef char            		int8;

typedef unsigned int			size_t;

// Authentication

#define SWHASH_SHA1		0x00
#define SWHASH_SHA2		0x01
#define SWHASH_MD5		0x02
#define SWHMAC_SHA1		0x04
#define SWHMAC_SHA2		0x05
#define SWHMAC_MD5		0x06
#define SW_POLY1305		0x07

extern int authSim(const u32 mode, const u8 * data, const u32 dataLen, const u8 * key, const u32 keyLen, u8 * digest, const u32 digestlen);


#define HMAC_MAX_MD_CBLOCK	64

extern int32 HMACMD5(uint8 * data, uint32 dataLen, uint8 * key, uint32 keyLen, uint8 * digest);


// DES

#define SWDECRYPT_CBC_DES		0x00
#define SWDECRYPT_CBC_3DES		0x10
#define SWDECRYPT_ECB_DES		0x02
#define SWDECRYPT_ECB_3DES		0x12
#define SWENCRYPT_CBC_DES		0x80
#define SWENCRYPT_CBC_3DES		0x90
#define SWENCRYPT_ECB_DES		0x82
#define SWENCRYPT_ECB_3DES		0x92

// AES

extern int aesSim_aes(const u32 mode, const u8 *input, const u32 len, const u32 klen, const u8 *key, const u8 *iv, u8* output);


#define AES_ENCRYPT	1
#define AES_DECRYPT	0

/* Because array size can't be a const in C, the following two are macros.
   Both sizes are in bytes. */
//#define AES_MAXNR 14
#define AES_BLOCK_SIZE 16




#define SWDECRYPT_CBC_AES 0x20
#define SWDECRYPT_ECB_AES 0x22
#define SWDECRYPT_CTR_AES 0x23
#define SWDECRYPT_CFB_AES 0x24
#define SWDECRYPT_OFB_AES 0x25

#define SWENCRYPT_CBC_AES 0xa0
#define SWENCRYPT_ECB_AES 0xa2
#define SWENCRYPT_CTR_AES 0xa3
#define SWENCRYPT_CFB_AES 0xa4
#define SWENCRYPT_OFB_AES 0xa5


#define GETU32(pt) (((uint32)(pt)[0] << 24) ^ ((uint32)(pt)[1] << 16) ^ ((uint32)(pt)[2] <<  8) ^ ((uint32)(pt)[3]))
#define PUTU32(ct, st) { (ct)[0] = (uint8)((st) >> 24); (ct)[1] = (uint8)((st) >> 16); (ct)[2] = (uint8)((st) >>  8); (ct)[3] = (uint8)(st); }


#define MAXKC   (256/32)
#define MAXKB   (256/8)
#define MAXNR   14


/* This should be a hidden type, but EVP requires that the size be known */
//struct aes_key_st {
//    uint32 rd_key[4 *(CIPHER_AES_MAXNR + 1)];
//    int32 rounds;
//};
//typedef struct aes_key_st AES_KEY;
typedef RTL_SW_AES_KEY AES_KEY;


//
// chacha
//

extern void CRYPTO_sim_chacha_20(unsigned char *out,
		      const unsigned char *in, size_t in_len,
		      const unsigned char key[32],
		      const unsigned char nonce[8],
		      size_t counter);

//
// poly1305
//
struct poly1305_state_st
{
	uint32_t r0,r1,r2,r3,r4;
	uint32_t s1,s2,s3,s4;
	uint32_t h0,h1,h2,h3,h4;
	unsigned char buf[16];
	unsigned int buf_used;
	unsigned char key[16];
};

typedef struct poly1305_state_st poly1305_state;


extern void CRYPTO_sim_poly1305_init(poly1305_state *state, const unsigned char key[32]);
extern void CRYPTO_sim_poly1305_update(poly1305_state *state, const unsigned char *in,
		     size_t in_len);
extern void CRYPTO_sim_poly1305_finish(poly1305_state *state, unsigned char mac[16]);



#endif
