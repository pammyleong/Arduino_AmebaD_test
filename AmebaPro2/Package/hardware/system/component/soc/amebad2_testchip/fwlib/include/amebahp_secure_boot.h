
#include "mbedtls/ecp.h"

#define SBOOT_ERR_AUTH_NOT_SUPPORT					-1
#define SBOOT_ERR_PK_HASH_INVALID					-2
#define SBOOT_ERR_SIGN_INVALID						-3
#define SBOOT_ERR_ECDSA_CURVE_NOT_SUPPORT			-4
#define SBOOT_ERR_HASH_NOT_SUPPORT					-6
#define SBOOT_ERR_IMG_HASH_INVALID					-7
#define SBOOT_ERR_PK_HASH_ENGINE_ERROR				-8
#define SBOOT_ERR_EDDSA_HASH_ENGINE					-9
#define SBOOT_ERR_ECDSA_HASH_ENGINE					-10
#define SBOOT_ERR_IMG_HASH_ENGINE					-11

/*ImgID_TypeDef*/
#define IMGID_BOOT	0
#define IMGID_NSPE	1
#define IMGID_SPE	2
#define IMGID_BL1	3

/*AuthAlg_TypeDef*/
#define AUTHID_EDDSA_25519				0
#define AUTHID_ECDSA_SECP192R1			1
#define AUTHID_ECDSA_SECP224R1			2
#define AUTHID_ECDSA_SECP256R1			3
#define AUTHID_ECDSA_BP256R1			6
#define AUTHID_ECDSA_CURVE25519			9
#define AUTHID_ECDSA_SECP192K1			10
#define AUTHID_ECDSA_SECP224K1			11
#define AUTHID_ECDSA_SECP256K1			12

#define ECP_MAX_BITS     				256   /**< Maximum bit size of groups */
#define ECP_MAX_BYTES    				( ( ECP_MAX_BITS + 7 ) / 8 )
#define ECP_MAX_PT_LEN   				( 2 * ECP_MAX_BYTES)

#define IS_EDDSA(x)				(x == AUTHID_EDDSA_25519)
#define IS_ECDSA(x)				(x == AUTHID_ECDSA_SECP192R1) || \
								(x == AUTHID_ECDSA_SECP224R1) || \
								(x == AUTHID_ECDSA_SECP256R1) || \
								(x == AUTHID_ECDSA_BP256R1) || \
								(x == AUTHID_ECDSA_CURVE25519) || \
								(x == AUTHID_ECDSA_SECP192K1) || \
								(x == AUTHID_ECDSA_SECP224K1) || \
								(x == AUTHID_ECDSA_SECP256K1)

/*HashAlg_TypeDef*/
#define HASHID_SHA256		0
#define HASHID_SHA384		1
#define HASHID_SHA512		2
#define HASHID_HMAC256		3
#define HASHID_HMAC384		4
#define HASHID_HMAC512		5

#define HASH_MAX_LEN		64
#define PKEY_MAX_LEN		((((2 * MBEDTLS_ECP_MAX_BYTES -1) >> 4) + 1) << 4) //144 byte (16-byte aligned, format type field not included)
#define SIGN_MAX_LEN		((((2 * MBEDTLS_ECP_MAX_BYTES -1) >> 4) + 1) << 4) //144 byte (16-byte aligned, raw data format, not ASN.1)

#define CRYPTO_CHK(f, errno) do { if( ( ret = f ) != 0 ) { ret = errno; goto exit; }} while( 0 )

#define MANIFEST_SIZE_4K_ALIGN		0x1000

typedef struct {
	unsigned int Pattern[2];
	unsigned char Rsvd1[8];
	unsigned char Ver;
	unsigned char ImgID;
	unsigned char AuthAlg;
	unsigned char HashAlg;
	unsigned int ImgVer;
	unsigned int ImgSize;
	unsigned int SecEpoch;
	unsigned char RsipIV[16];
	unsigned char ImgHash[HASH_MAX_LEN];
	unsigned char SBPubKey[PKEY_MAX_LEN];
	unsigned char Signature[SIGN_MAX_LEN];

} Manifest_TypeDef;

typedef struct {
	unsigned int Addr;
	unsigned int Len;
} SubImgInfo_TypeDef;

int SBOOT_SignatureVerify(u8 *PubKeyHash, Manifest_TypeDef *Manifest, SubImgInfo_TypeDef *SubImgInfo, u8 SubImgCnt);


