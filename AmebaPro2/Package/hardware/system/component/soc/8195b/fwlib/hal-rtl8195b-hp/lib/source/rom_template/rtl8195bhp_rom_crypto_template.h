/**************************************************************************//**
 * @file     rtl8195bhp_rom_crypto_template.h
 * @brief    This file implements the CRYPTO HAL template functions in ROM.
 * 
 * @version  V1.00
 * @date     2017-10-05
 *
 * @note
 *
 ******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/

#include <stdint.h>
#include <string.h>
#include "cmsis.h"

#include "hal_crypto.h"
#include "rtl8195bhp_crypto.h"
#include "rtl8195bhp_crypto_ctrl.h"
#include "rtl8195bhp_crypto_type.h"

#define IPSEC_INFO_PREFIX       "[CRYP Inf]"
#undef __printk
#define __printk(fmt, args...) 

#undef __dbg_printk
#define __dbg_printk(fmt, args...) 

//
/** 
 * @addtogroup hs_hal_crypto CRYPTO
 * @{
 */

//
extern hal_crypto_adapter_t *CRYPTO_ADAPTER;
extern void dump_for_one_bytes(u8 *pdata, u32 len);

/// Timeout value of waiting available source descriptor FIFO nodes
#define FIFOCNT_TIMEOUT		0x100000

/// Cipher type none for Crypto ROM Code self-define index.
#define CIPHER_TYPE_NONE			0xFF
/// DES_ECB for Crypto ROM Code self-define index.
#define CIPHER_TYPE_DES_ECB			0x0
/// DES_CBC for Crypto ROM Code self-define index.
#define CIPHER_TYPE_DES_CBC 		0x1
/// 3DES_ECB for Crypto ROM Code self-define index.
#define CIPHER_TYPE_3DES_ECB		0x10
/// 3DES_CBC for Crypto ROM Code self-define index.
#define CIPHER_TYPE_3DES_CBC		0x11
/// AES_ECB for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_ECB			0x20
/// AES_CBC for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_CBC			0x21
/// AES_CFB for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_CFB			0x22
/// AES_OFB for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_OFB			0x23
/// AES_CTR for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_CTR			0x24  // 0x29
/// AES_GCTR for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_GCTR		0x25
/// AES_GMAC for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_GMAC		0x26
/// AES_GHASH for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_GHASH		0x27
/// AES_GCM for Crypto ROM Code self-define index.
#define CIPHER_TYPE_AES_GCM			0x28

/// Chacha20_Poly1305 for Crypto ROM Code self-define index.
#define CIPHER_TYPE_CHACHA_POLY1305	0x30 // chacha+poly1305
/// Chacha20 for Crypto ROM Code self-define index.
#define CIPHER_TYPE_CHACHA			0x31
/// Poly1305_mode2 for Crypto ROM Code self-define index.
#define CIPHER_TYPE_POLY1305		0x33 // poly1305 - mode 2
//
//
static const u8 gcm_iv_tail[] __attribute__((aligned(64))) = {0x00, 0x00, 0x00, 0x01};

static const u8 digest_len[] = {
    CRYPTO_MD5_DIGEST_LENGTH,
    CRYPTO_SHA1_DIGEST_LENGTH,
    CRYPTO_SHA2_DIGEST_LENGTH,
    CRYPTO_MD5_DIGEST_LENGTH,
    CRYPTO_SHA1_DIGEST_LENGTH,
    CRYPTO_SHA2_DIGEST_LENGTH,
};

//


//#define __dbg_printk(fmt, args...) 
//	     DBG_CRYPTO_INFO("%s(): " fmt "\n", "crypto info: ", ##args);

/**  \brief     __err_printk is only used to print out error messages of CRYPTO IP.
 */ 
#undef __err_printk
#define __err_printk(fmt, args...) do{ \
    DBG_CRYPTO_ERR(fmt, ##args);\
}while(0)
//#define __err_printk(fmt, args...) 
//	     __printk("%s(): " fmt "\n", "crypto error: ", ##args);

/**  \brief     __dbg_mem_dump is only used to print out memory information of CRYPTO IP. \n
 *              Use \em enable to enable/disable this function which dumps \em size bytes of momery information 
 *              from the \em start address.
 */ 
#undef __dbg_mem_dump
#define __dbg_mem_dump(enable, start, size, str_header) do{ \
    if(enable){ \
        DBG_CRYPTO_INFO(str_header "\r\n");\
        dump_for_one_bytes ((u8 *)start, size);}\
}while(0)

//#define __dbg_mem_dump(start, size, str_header) 
//			if ( crypto_debug_on ) { 
//		    	__printk("%s(): memdump : address: %08x, size: %d\n", "rtl_cryptoEngine_dbg", start, size); 
//		    	__memDump((const u8*)(start), size, (char*)(str_header)); 
//			}


#if   defined (__CC_ARM)
#pragma push
#pragma anon_unions
#endif


/* Data Struct for hp crypto source descriptor */
/**
 *  \brief Define data struct for hp crypto source descriptor.
 */
typedef union {
    /**
     *  \brief Set source descriptor to prepare essential parameters that crypto engine needs.
     */
    struct {
        uint32_t key_len:4;         //!<  [3..0] Key length
        uint32_t iv_len:4;          //!<  [7..4] Initial vector length
        uint32_t keypad_len:8;      //!<  [15..8] HMAC key padding length
        uint32_t hash_iv_len:6;     //!<  [21..16] Hash initial value length

        /**
          *     - 2'b00: disable auto-padding
          *     - 2'b01: auto-padding for MD5/SHA1/SHA2-224/SHA2-256
          *     - 2'b1x: auto-padding for SHA2-384/SHA2-512
          */
        uint32_t ap:2;              //!<  [23..22] Auto-padding
        uint32_t cl:2;              //!<  [25..24] Command(setting registers length). When set CL=3, it indicates that this descriptor is pointing to the command setting buffer.

        /**
          *     - 2'd0: Normal mode(not use secure key)
          *     - 2'd1: Use secure key 0
          *     - 2'd2: Use secure key 1
          *     - 2'd3: Use secure key 2
          */
        uint32_t sec_key:2;         //!<  [27..26] Secure key 

        /**
          * For descriptor which prepares essential parameters, when set, it indicates that this is the last descriptor of an IP packet.
          */
        uint32_t ls:1;              //!<  [28..28] Last segment descriptor.

        /**
          * For descriptor which prepares essential parameters, when set this bit with CL=3,
          * it indicates that this is the first descriptor of an IP packet. Except setting message buffer address to descriptor, 
          * other setting situations(Key Array, IV Array, PAD Array, SHIVL) need set this field is "1" as well.
          */
        uint32_t fs:1;              //!<  [29..29] First segment descriptor. 
        uint32_t rs:1;              //!<  [30..30] Read data from Non-Secure/Secure master port: 1=Secure port, 0=Non-secure port
        uint32_t rsvd:1;            //!<  [31..31] Reserve
    } b;

    /**
     *  \brief Set source descriptor to prepare data that crypto engine will process.
     */
    struct {
        uint32_t apl:8;             //!<  [7..0] Authentication padding length
        uint32_t a2eo:5;            //!<  [12..8] Additional authentication data length
        uint32_t zero:1;            //!<  [13..13] this bit is set to zero, it indicates bit field[12..8] is used to set Additional authentication data length.
        uint32_t enl:14;            //!<  [27..14] Encryption length(The message buffer length of Hash/Cipher handling).

        /**
          * For descriptor which prepares data, when set, it indicates that this is the last descriptor of an IP packet.
          */
        uint32_t ls:1;              //!<  [28..28] Last segment descriptor.

        /**
          * For descriptor which prepares data, when this field is set "0", 
          * it indicates that this descriptor is used to set message buffer.
          */
        uint32_t fs:1;              //!<  [29..29] First segment descriptor.
        uint32_t rs:1;              //!<  [30..30] Read data from Non-Secure/Secure master port: 1=Secure port, 0=Non-secure port
        uint32_t rsvd:1;            //!<  [31..31] Reserve
    } d;

    uint32_t w;
} rtl_crypto_srcdesc_t;

/* Data Struct for hp crypto destination descriptor */
/**
 *  \brief Define data struct for hp crypto destination descriptor.
 */
typedef union {
    /**
     *  \brief Set Destination descriptor to get auth digest after crypto engine process.
     */
    struct {
        /**
         * The length of digest which uses 1 byte as a unit for Hash algorithms and Tag value in cipher algorithms.
         */
        uint32_t adl:8;             //!<  [7..0] Authentication Data length
        uint32_t rsvd1:19;          //!<  [26..8] Reserve
        /**
         * For descriptor which sets auth digest,set this field is "0",it indicates this destination descriptor is set for authentication.
         */
        uint32_t enc:1;             //!<  [27..27] Flag of encryption: 1=Cipher, 0=Hash(authentication)
        uint32_t ls:1;              //!<  [28..28] Last segment descriptor. When set, indicates that this is the last descriptor of an IP packket
        uint32_t fs:1;              //!<  [29..29] First segment descriptor. When set, indicates that this is the first descriptor of an IP packket
        uint32_t ws:1;              //!<  [29..29] Write data from Non-Secure/Secure master port: 1=Secure port, 0=Non-secure port
        uint32_t rsvd2:1;           //!<  [31..31] Reserve
    } auth;

    /**
     *  \brief Set Destination descriptor to get cipher result after crypto engine process.
     */
    struct {
        /**
         * The length of cipher result which uses 1 byte as a unit.
         */
        uint32_t enl:24;            //!<  [23..0] Encryption length(The result length of Cipher handling)
        uint32_t rsvd1:3;           //!<  [26..24] Reserve
        /**
         * For descriptor which sets cipher result,set this field is "1",it indicates this destination descriptor is set for cipher.
         */
        uint32_t enc:1;             //!<  [27..27] Flag of encryption: 1=Cipher, 0=Hash(authentication)
        uint32_t ls:1;              //!<  [28..28] Last segment descriptor. When set, indicates that this is the last descriptor of an IP packket
        uint32_t fs:1;              //!<  [29..29] First segment descriptor. When set, indicates that this is the first descriptor of an IP packket
        uint32_t ws:1;              //!<  [30..30] Write data from Non-Secure/Secure master port: 1=Secure port, 0=Non-secure port
        uint32_t rsvd2:1;           //!<  [31..31] Reserve
    } cipher;

    uint32_t w;

} rtl_crypto_dstdesc_t;

/* Data Struct for hp crypto source descriptor(Command setting)*/
/**
 *  \brief Define data struct for hp crypto source descriptor command setting.
 */
typedef struct rtl_crypto_cl_struct_s {
    // offset 0
    /**
      *     - DES engine:
      *         - 4'd0: ECB
      *         - 4'd1: CBC
      *         - 4'd2: CFB
      *         - 4'd3: OFB
      *         - 4'd4: CTR
      *     - AES engine:
      *         - 4'd0: ECB
      *         - 4'd1: CBC
      *         - 4'd2: CFB
      *         - 4'd3: OFB
      *         - 4'd4: CTR
      *         - 4'd5: GCTR
      *         - 4'd6: GMAC
      *         - 4'd7: GHASH
      *         - 4'd8: GCM
      *         - 4'd9: AES_CTR32
      *     - Chacha+Poly1305 engine:
      *         - 4'd0: Chacha20+poly1305
      *         - 4'd1: Chacha20
      *         - 4'd2: poly1305 mode1
      *         - 4'd3: poly1305 mode2
      */
    u32 cipher_mode:4;              //!<  Command setting offset 0x0: [3..0] Cipher mode

    /**
      *     - 2'd0: AES
      *     - 2'd1: DES
      *     - 2'd2: Chacha20+Poly1305
      */
    u32 cipher_eng_sel:2;           //!<  [5..4] Cipher engine select
    u32 rsvd1:1;                    //!<  [6..6] Reserve
    u32 cipher_encrypt:1;           //!<  [7..7] Flag of cipher encryption: 1=Cipher encrypt, 0=Cipher decrypt

    /**
      *     - 2'd0: 128-bits key
      *     - 2'd1: 192-bits key
      *     - 2'd2: 256-bits key
      */    
    u32 aes_key_sel:2;              //!<  [9..8] AES key type select
    u32 des3_en:1;                  //!<  [10..10] Flag of 3DES enable: 1=3DES enable, 0=3DES disable

    /**
      *     - 1'd0: enc->dec->enc; dec->enc->dec
      *     - 1'd1: enc->enc->enc; dec->dec->dec
      */
    u32 des3_type:1;                //!<  [11..11] 3DES type
    u32 ckbs:1;                     //!<  [12..12] Cipher key byte swap 1=Enable, 0=Disable
    u32 hmac_en:1;                  //!<  [13..13] Flag of HMAC enable: 1=Enable, 0=Disable

    /**
      *     - 3'd0: MD5
      *     - 3'd1: SHA1
      *     - 3'd2: SHA2_224
      *     - 3'd3: SHA2_256
      *     - 3'd4: SHA2_384
      *     - 3'd5: SHA2_512
      */
    u32 hmac_mode:3;                //!<  [16..14] HMAC mode

    /**
      * 1=This message buffer is sequential hash last one, 0=This message buffer isn't sequential hash last one
      */
    u32 hmac_seq_hash_last:1;       //!<  [17..17] Sequential hash last one state:

    /**
      *     - 3'd0: Cipher only
      *     - 3'd1: Hash only
      */
    u32 engine_mode:3;              //!<  [20..18] Engine mode
    
    /**
      * 1=This message buffer is sequential hash first one, 0=This message buffer isn't sequential hash first one
      */
    u32 hmac_seq_hash_first:1;      //!<  [21..21] Sequential hash first one state:
    u32 hmac_seq_hash:1;            //!<  [22..22] Sequential hash mechanism enable: 1=Enable, 0=Disable
    u32 hmac_seq_hash_no_wb:1;      //!<  [23..23] Sequential hash no write back: 1=no write back, 0=wirte back
    u32 icv_total_length:8;         //!<  [31..24] Initial Check Vector Total Length

    // offset 4
    u32 aad_last_data_size:4;       //!<  Command setting offset 0x4: [3..0] AAD last data size
    u32 enc_last_data_size:4;       //!<  [7..4] Encryption last data size
    u32 pad_last_data_size:3;       //!<  [10..8] Padding last data size
    u32 ckws:1;                     //!<  [11..11] Cipher key word swap: 1=Enable, 0=Disable
    u32 enc_pad_last_data_size:3;   //!<  [14..12] Encryption padding last data size
    u32 hsibs:1;                    //!<  [15..15] Hash sequential initial value byte swap: 1=Enable, 0=Disable
    u32 caws:1;                     //!<  [16..16] Cipher aligned word swap: 1=Enable, 0=Disable
    u32 cabs:1;                     //!<  [17..17] Cipher aligned byte swap: 1=Enable, 0=Disable
    u32 ciws:1;                     //!<  [18..18] Cipher input word swap 1=Enable, 0=Disable
    u32 cibs:1;                     //!<  [19..19] Cipher input byte swap: 1=Enable, 0=Disable
    u32 cows:1;                     //!<  [20..20] Cipher output word swap: 1=Enable, 0=Disable
    u32 cobs:1;                     //!<  [21..21] Cipher output byte swap: 1=Enable, 0=Disable
    u32 codws:1;                    //!<  [22..22] Cipher output double word swap: 1=Enable, 0=Disable
    u32 cidws:1;                    //!<  [23..23] Cipher input double word swap: 1=Enable, 0=Disable
    u32 haws:1;                     //!<  [24..24] Hash aligned word swap: 1=Enable, 0=Disable
    u32 habs:1;                     //!<  [25..25] Hash aligned byte swap: 1=Enable, 0=Disable
    u32 hiws:1;                     //!<  [26..26] Hash input word swap: 1=Enable, 0=Disable
    u32 hibs:1;                     //!<  [27..27] Hash input byte swap: 1=Enable, 0=Disable
    u32 hows:1;                     //!<  [28..28] Hash output word swap: 1=Enable, 0=Disable
    u32 hobs:1;                     //!<  [29..29] Hash output byte swap: 1=Enable, 0=Disable
    u32 hkws:1;                     //!<  [30..30] Hash key word swap: 1=Enable, 0=Disable
    u32 hkbs:1;                     //!<  [31..31] Hash key byte swap: 1=Enable, 0=Disable

    // offset 8
    u32 hash_pad_len:8;             //!<  Command setting offset 0x8: [7..0] Hash padding total length
    
    /**
     * This is the total length of AAD data. For AES_GCM and Chacha20_Poly1305, they use 16bytes as a unit.
     */
    u32 header_total_len:6;         //!<  [13..8] Header total length(AAD total length):
    u32 apl:2;                      //!<  [15..14] Encryption padding total length

    /**
     * This is the total length of message buffer that crypto engine can calculate. 
     * A unit for different cryptographic features has different length meanings. 
     * The details are listed below:
     * - Hash (MD5/SHA1/SHA2-224/SHA2-256): 64 bytes as a unit
     * - Hash (MD5/SHA1/SHA2-224/SHA2-256) Auto Padding: 16 bytes as a unit
     * - Cipher (AES/Chacha20poly1305): 16 bytes as a unit
     * - Cipher (DES/3DES): 8 bytes as a unit
     */
    u32 enl:16;                     //!<  [31..16] Encryption total length(Cipher/Hash)

    // offset
    u32 ap0;                        //!<  Command setting offset 0xC: [31..0] padding information0(all message length)
    u32 ap1;                        //!<  Command setting offset 0x10: [31..0] padding information1(all message length)
    u32 ap2;                        //!<  Command setting offset 0x14: [31..0] padding information2(all message length)
    u32 ap3;                        //!<  Command setting offset 0x18: [31..0] padding information3(all message length)
} rtl_crypto_cl_t;
/** @} */ /* End of group hs_hal_crypto */

__STATIC_INLINE
void __rtl_crypto_set_debug(int val)
{
    crypto_debug_on = val;
    DBG_CRYPTO_INFO("crypto_debug_on = %d \r\n",crypto_debug_on);
    //__printk("crypto_debug_on = %d \r\n", crypto_debug_on);
}

__STATIC_INLINE
uint32_t __rtl_crypto_srcdesc_set_pk_up(int val)
{
    (CRYPTO_MODULE->srcdesc_status_reg_b.pk_up) = val;
    return (CRYPTO_MODULE->srcdesc_status_reg);

}

/** 
 * @addtogroup hs_hal_crypto CRYPTO
 * @{
 */

/* Functions for hp crypto module */
/// @cond DOXYGEN_ROM_HAL_API

/** 
 * @addtogroup hs_hal_crypto_rom_func CRYPTO HAL ROM APIs.
 * @ingroup hs_hal_crypto
 * @{
 * @brief CRYPTO HAL ROM API. The user application(in RAM space) should not call these APIs directly. 
 *        There is another set of CRYPTO HAL APIs in the RAM space is provided for the user application.
 */

     
// cache functions
/**
 *  \fn          static inline int isDCacheDisabled(void)
 *  \brief       Make sure Dcache state.
 *  \param       void
 *  \return      value 0   Dcache enable       
 *  \return      value 1   Dcache disable     
 */
__STATIC_INLINE
int isDCacheDisabled(void)
{
    int ret;
    ret = (!(SCB->CCR & (uint32_t)(SCB_CCR_DC_Msk)));

    return ret;
}

/**
 *  \fn          static inline u32 __rtl_cpu_to_be32(u32 val)
 *  \brief       Reverse \em val to byte order in a word.
 *  \param[in]   val The value to be reversed
 *  \return      value  Reverse result
 */
__STATIC_INLINE
u32 __rtl_cpu_to_be32(u32 val)
{
    asm volatile(
        "rev %0, %0"
        : "=r" (val)
        : "0" (val));

    return val;
}

/**
 *  \fn          static inline void arch_invalidate_dcache(uint32_t start_address, uint32_t end_address)
 *  \brief       Make sure \em start_address and \em end_address are 32 bytes alignment, then invalidate dcache 
 *               from \em start_address to \em end_address .
 *  \param[in]   start_address Pointer to start address
 *  \param[in]   end_address Pointer to end address
 *  \return      void
 */
__STATIC_INLINE
void arch_invalidate_dcache(uint32_t start_address, uint32_t end_address)
{
    uint32_t addr1, addr2;
    int32_t linesize = 32;				  /* in Cortex-M7 size of cache line is fixed to 8 words (32 bytes) */
    volatile uint32_t op_addr;
    
    addr1 = start_address & 0xFFFFFFE0;
    addr2 = (end_address-1) & 0xFFFFFFE0;

    //SCB_InvalidateDCache_by_Addr(addr1, size);
    op_addr = addr1;

    __DSB();

    //rtl_printf("%s : addr1: 0x%x, addr2: 0x%x \r\n", __FUNCTION__, op_addr, addr2);
    //rtl_printf("%s : DCIMVAC: 0x%x \r\n", __FUNCTION__, (uint32_t)(&(SCB->DCIMVAC)));

    while (op_addr <= addr2) {
        SCB->DCIMVAC = op_addr;
        op_addr += (uint32_t)linesize;
    }

    __DSB();
    __ISB();
}

/**
 *  \fn          static inline void arch_invalidate_dcache_by_size(hal_crypto_adapter_t *pcrypto_adapter, uint32_t start_address, uint32_t size)
 *  \brief       Invalidate the first \em size bytes of the block of memory pointed by \em start_address .
 *  \note        If programmer registers an other invalidating dcache function, then the registered function will be called.
 *  \param[in]   pcrypto_adapter Pointer to crypto adapter data
 *  \param[in]   start_address Pointer to start address
 *  \param[in]   size Number of bytes to be clean
 *  \return      void
 */
__STATIC_INLINE
void arch_invalidate_dcache_by_size(hal_crypto_adapter_t *pcrypto_adapter, uint32_t start_address, uint32_t size)
{
    uint32_t end_address;

    if (isDCacheDisabled()) {
        return;
    }
    if ((pcrypto_adapter != NULL) && (pcrypto_adapter->arch_invalidate_dcache_by_size != NULL)) {
        pcrypto_adapter->arch_invalidate_dcache_by_size(start_address, size);
        return;
    }
    if (start_address & 0x1F) {
        __err_printk("start_address is not 32 byte alignment : 0x%x ", start_address);
    }
    if (size & 0x1F) {
        __err_printk("error : size is not 32 byte alignment : 0x%x ", size);
    }

    end_address = start_address + size;
    arch_invalidate_dcache(start_address, end_address);
}

/**
 *  \fn          static inline void arch_clean_dcache(uint32_t start_address, uint32_t end_address)
 *  \brief       Make sure \em start_address and \em end_address are 32 bytes alignment, then clean dcache 
 *               from \em start_address to \em end_address .
 *  \param[in]   start_address Pointer to start address
 *  \param[in]   end_address Pointer to end address
 *  \return      void
 */
__STATIC_INLINE
void arch_clean_dcache(uint32_t start_address, uint32_t end_address)
{
    uint32_t addr1, addr2;
    int32_t linesize = 32;				  /* in Cortex-M7 size of cache line is fixed to 8 words (32 bytes) */
    volatile uint32_t op_addr;

    addr1 = start_address & 0xFFFFFFE0;
    addr2 = (end_address - 1) & 0xFFFFFFE0;

    //SCB_CleanDCache_by_Addr(addr1, size);
    op_addr = addr1;

    //rtl_printf("%s : addr1: 0x%x, addr2: 0x%x \r\n", __FUNCTION__, op_addr, addr2);

    __DSB();

    //rtl_printf("%s : DCCMVAC: 0x%x \r\n", __FUNCTION__, (uint32_t)(&(SCB->DCCMVAC)));

    while (op_addr <= addr2) {
        SCB->DCCMVAC = op_addr;
        //rtl_printf("cache clean: 0x%x \r\n", op_addr);
        op_addr += (uint32_t)linesize;
    }

    __DSB();
    __ISB();
}

/**
 *  \fn          static inline void arch_clean_dcache_by_size(hal_crypto_adapter_t *pcrypto_adapter, uint32_t start_address, uint32_t size)
 *  \brief       Clean the first \em size bytes of the block of memory pointed by \em start_address .
 *  \note        If programmer registers an other cleaning dcache function, then the registered function will be called.
 *  \param[in]   pcrypto_adapter Pointer to crypto adapter data
 *  \param[in]   start_address Pointer to start address
 *  \param[in]   size Number of bytes to be clean
 *  \return      none
 */
__STATIC_INLINE
void arch_clean_dcache_by_size(hal_crypto_adapter_t *pcrypto_adapter, uint32_t start_address, uint32_t size)
{
    uint32_t end_address;

    if (isDCacheDisabled()) {
        return;
    }
    if ((pcrypto_adapter != NULL) && (pcrypto_adapter->arch_clean_dcache_by_size != NULL)) {
        pcrypto_adapter->arch_clean_dcache_by_size(start_address, size);
        return;
    }
    if (start_address & 0x1F) {
        __err_printk("start_address is not 32 byte alignment : 0x%x ", start_address);
    }
    if (size & 0x1F) {
        __err_printk("error : size is not 32 byte alignment : 0x%x ", size);
        size = ((size / 32) + 1) * 32;
    }

    end_address = start_address + size;

    arch_clean_dcache(start_address, end_address);
}

//
/**
 *  \fn          static inline void *rtlc_memset(void *dst, int c, size_t n)
 *  \brief       Sets the first \em c bytes of the block of memory pointed by \em dst to the specified \em value .
 *  \param[in]   dst Pointer to destination address
 *  \param[in]   c Value to be set
 *  \param[in]   n Number of bytes to be set to the \em value
 *  \return      value  destination address
 */
__STATIC_INLINE
void *rtlc_memset(void *dst, int c, size_t n)
{
    if (n != 0) {
        char *d = dst;

        do {
            *d++ = c;
        } while (--n > 0);
    }
    return dst;
}

/**
 *  \fn          static inline void *rtlc_memcpy( void *s1, const void *s2, size_t n )
 *  \brief       Copies the values of \em n bytes from the location pointed to by \em s2 directly to the memory block pointed to by \em s1 .
 *  \param[in]   s1 Pointer to the destination array where the content is to be copied
 *  \param[in]   s2 Pointer to the source of data to be copied
 *  \param[in]   n Number of bytes to copy
 *  \return      value  destination address
 */
__STATIC_INLINE
void *rtlc_memcpy( void *s1, const void *s2, size_t n )
{
    char *dst = (char *) s1;
    const char *src = (const char *) s2;

    while (n--) {
        *dst++ = *src++;
    }
    return s1;
}



//
// internal functions
//
/**
 *  \fn          static inline uint32_t __rtl_crypto_srcdesc_fifo_cnt(void)
 *  \brief       Know how many source descripter fifo nodes are available to use.
 *  \param       void
 *  \return      value >= 0     fifo empty nodes count value
 */
__STATIC_INLINE
uint32_t __rtl_crypto_srcdesc_fifo_cnt(void)
{
    return ((CRYPTO_MODULE->srcdesc_status_reg_b.fifo_empty_cnt) - 1);
}

/**
 *  \fn          static inline void __rtl_crypto_set_srcdesc(hal_crypto_adapter_t *pcrypto_adapter, uint32_t sd1, uint32_t sdpr)
 *  \brief       Check whether there are enough fifo nodes for source descripter, if there're enough,
 *               then set source descripter first/second words to crypto source descripter registers,
 *               or wait until timeout value count down to zero then break.
 *  \param[in]   pcrypto_adapter Pointer to crypto adapter data
 *  \param[in]   sd1 Source descripter first word pointer value 
 *  \param[in]   sdpr Source descripter second word pointer value(data pointer value)
 *  \return      void
 */
__STATIC_INLINE
void __rtl_crypto_set_srcdesc(hal_crypto_adapter_t *pcrypto_adapter, uint32_t sd1, uint32_t sdpr)
{
    uint32_t cnt, timeout;

    timeout = FIFOCNT_TIMEOUT;
    while (1) {
        if ((cnt = __rtl_crypto_srcdesc_fifo_cnt()) > 0) {
            //DBG_CRYPTO_INFO("sd1=0x%x , sdpr=0x%x\r\n",sd1, sdpr);
            (CRYPTO_MODULE->sdfw_reg) = (sd1 | 0x80000000);
            (CRYPTO_MODULE->sdsw_reg) = (sdpr);
            break;
        }
        if ((pcrypto_adapter != NULL) && (pcrypto_adapter->fifo_wait_func != NULL)) {
            pcrypto_adapter->fifo_wait_func(pcrypto_adapter);
        } else {
            __err_printk("src fifo_cnt is FULL: %d \r\n", cnt);
            timeout--;
            if (timeout == 0) {
                break;
            }
        }
    }

}

typedef union {
    struct {
        uint32_t fifo_empty_cnt:8;
        uint32_t swptr:8;
        uint32_t srptr:8;
        uint32_t src_fail:1;
        uint32_t src_fail_status:2;
        uint32_t src_fail_m:1;
        uint32_t rsvd1:2;
        uint32_t pk_up:1;
        uint32_t src_rst:1;
    } b;

    uint32_t w;

} rtl_crypto_srcdesc_status_t;

/**
 *  \fn          static inline uint32_t __rtl_crypto_dstdesc_fifo_cnt(void)
 *  \brief       Know how many destination descripter fifo nodes are available to use.
 *  \param       void
 *  \return      value >= 0     fifo empty nodes count value
 */
__STATIC_INLINE
uint32_t  __rtl_crypto_dstdesc_fifo_cnt(void)
{
    return ((CRYPTO_MODULE->dstdesc_status_reg_b.fifo_empty_cnt) - 1);
}

/**
 *  \fn          static inline void __rtl_crypto_set_dstdesc(uint32_t dd1, uint32_t ddpr)
 *  \brief       Check whether there are enough fifo nodes for destination descripter, if there're enough,
 *               then set destination descripter first/second words to crypto destination descripter registers.
 *  \param[in]   dd1 Destination descripter first word pointer value 
 *  \param[in]   ddpr Destination descripter second word pointer value(data pointer value)
 *  \return      void
 */
__STATIC_INLINE
void __rtl_crypto_set_dstdesc(uint32_t dd1, uint32_t ddpr)
{
    if (__rtl_crypto_dstdesc_fifo_cnt() > 0) {
        //rtl_crypto_dstdesc_t dst_desc;
        //dst_desc.w = dd1;
        //__dbg_printk("dd1=0x%x , ddpr=0x%x \r\n", dd1, ddpr);
        //__dbg_printk("dd1.len=%d\r\n", dst_desc.cipher.enl);
        //DBG_CRYPTO_INFO("dd1=0x%x , ddpr=0x%x\r\n", dd1, ddpr);
        (CRYPTO_MODULE->ddfw_reg) = dd1;
        (CRYPTO_MODULE->ddsw_reg) = ddpr;
    } else {
        __err_printk("dst fifo_cnt is not correct: %d \r\n", __rtl_crypto_dstdesc_fifo_cnt());
    }
}

/**
 *  \fn          static inline void __rtl_crypto_start_packet_init(void)
 *  \brief       Clear command ok interrupt and error interrupts.
 *  \return      void
 */
__STATIC_INLINE
void __rtl_crypto_start_packet_init(void)
{
    DBG_CRYPTO_INFO("[Crypto_engine] start packet init\r\n");
    (CRYPTO_MODULE->ipscsr_err_stats_reg) = 0x3FFF;

    (CRYPTO_MODULE->ipscsr_reset_isr_conf_reg_b.cmd_ok) = 1;
}

/**
 *  \fn          static inline void __rtl_cryptoEngine_auth_calc_apl(hal_crypto_adapter_t *pcrypto_adapter, IN const uint32_t a2eo, IN const uint32_t msglen)
 *  \brief       Set crypto the last valid data size and padding data length in crypto adapter.
 *  \details     DES/3DES need 8 bytes alignment message buffer; AES,Chacha,Hash need 16 bytes alignment message buffer
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[in]   a2eo Additional authentication data buffer length
 *  \param[in]   msglen crypto message buffer length
 *  \return      void
 */
__STATIC_INLINE
void __rtl_cryptoEngine_auth_calc_apl(hal_crypto_adapter_t *pcrypto_adapter, IN const uint32_t a2eo, IN const uint32_t msglen)
{
    DBG_CRYPTO_INFO("[Crypto_engine] set engine needs relative length data\r\n");
    DBG_CRYPTO_INFO("[Crypto_engine] a2eo = %d, msglen = %d\r\n",a2eo,msglen);
    pcrypto_adapter->a2eo = a2eo;
    pcrypto_adapter->enl  = msglen;

    // DES / 3DES : 8 byte alignment
    if ((pcrypto_adapter->des == 1) || (pcrypto_adapter->trides == 1)) {
        pcrypto_adapter->enc_last_data_size = msglen % 8;
        pcrypto_adapter->apl = (8 - pcrypto_adapter->enc_last_data_size) % 8;

        pcrypto_adapter->aad_last_data_size = a2eo % 8;
        pcrypto_adapter->apl_aad = (8 - pcrypto_adapter->aad_last_data_size) % 8;
    } else { // AES,Chacha,Hash : 16 byte alignment
        pcrypto_adapter->enc_last_data_size = msglen % 16;
        pcrypto_adapter->apl = (16 - pcrypto_adapter->enc_last_data_size) % 16;

        pcrypto_adapter->aad_last_data_size = a2eo % 16;
        pcrypto_adapter->apl_aad = (16 - pcrypto_adapter->aad_last_data_size) % 16;
    }
}

/**
 *  \fn          static inline void __rtl_cryptoEngine_set_digestlen(hal_crypto_adapter_t *pcrypto_adapter, IN const uint32_t auth_type)
 *  \brief       Set authentication digest length in crypto adapter.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[in]   auth_type Authentication type ID
 *  \return      void
 */
__STATIC_INLINE
void __rtl_cryptoEngine_set_digestlen(hal_crypto_adapter_t *pcrypto_adapter, IN const uint32_t auth_type)
{
    int digestlen;

    switch (auth_type &  AUTH_TYPE_MASK_FUNC) {
        case AUTH_TYPE_MD5:
            digestlen = CRYPTO_MD5_DIGEST_LENGTH;
            break;

        case AUTH_TYPE_SHA1:
            digestlen = CRYPTO_SHA1_DIGEST_LENGTH;
            break;

        case AUTH_TYPE_SHA2:
            digestlen = pcrypto_adapter->sha2type;
            break;

        default:
            digestlen = 0;
            break;
    }

    pcrypto_adapter->digestlen = digestlen;
    DBG_CRYPTO_INFO("[Set digestlen] digestlen = %d\r\n",digestlen);
}

/**
 *  \fn          static inline int __rtl_cryptoEngine_set_key(hal_crypto_adapter_t *pcrypto_adapter,
                                                              IN const u8* pCipherKey, IN const int lenCipherKey,
                                                              IN const u8* pAuthKey, IN const int lenAuthKey )
 *  \brief       Set cipher key, authentication key information in crypto adapter.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[in]   pCipherKey Pointer to crypto cipher key buffer
 *  \param[in]   lenCipherKey Crypto cipher key buffer length
 *  \param[in]   pAuthKey Pointer to authentication key buffer
 *  \param[in]   lenAuthKey Authentication key buffer length
 *  \return      Always return SUCCESS
 */
__STATIC_INLINE
int __rtl_cryptoEngine_set_key(hal_crypto_adapter_t *pcrypto_adapter,
                               IN const u8* pCipherKey, IN const int lenCipherKey,
                               IN const u8* pAuthKey, IN const int lenAuthKey )
{
    DBG_CRYPTO_INFO("[Set Cipherkey/Authkey] lenCipherKey = %d,lenAuthKey = %d\r\n",lenCipherKey,lenAuthKey);

    pcrypto_adapter->lenCipherKey = lenCipherKey;
    pcrypto_adapter->pCipherKey = pCipherKey;

    pcrypto_adapter->pAuthKey = pAuthKey;
    pcrypto_adapter->lenAuthKey = lenAuthKey;

    if (lenAuthKey > 0) {
        int i;

        pcrypto_adapter->ipad = (u8 *)(&(pcrypto_adapter->g_IOPAD[0]));
        pcrypto_adapter->opad = (u8 *)(&(pcrypto_adapter->g_IOPAD[CRYPTO_PADSIZE]));

        rtlc_memset(pcrypto_adapter->ipad, 0x36, CRYPTO_PADSIZE);
        rtlc_memset(pcrypto_adapter->opad, 0x5c, CRYPTO_PADSIZE);

        for (i = 0; i < lenAuthKey; i++) {
            pcrypto_adapter->ipad[i] ^= ((u8*) pcrypto_adapter->pAuthKey)[i];
            pcrypto_adapter->opad[i] ^= ((u8*) pcrypto_adapter->pAuthKey)[i];
        }
    } else {
        pcrypto_adapter->ipad = 0;
        pcrypto_adapter->opad = 0;
    }

    return SUCCESS;
}

/**
 *  \fn          static inline void __rtl_cryptoEngine_setup_cl_buffer(hal_crypto_adapter_t *pcrypto_adapter)
 *  \brief       Use crypto adatper information to set crypto command setting buffer.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \return      void
 */
__STATIC_INLINE
void __rtl_cryptoEngine_setup_cl_buffer(hal_crypto_adapter_t *pcrypto_adapter)
{
    rtl_crypto_cl_t *pCL;
    uint32_t a2eo;
    uint32_t enl;

    DBG_CRYPTO_INFO("Set up src_desc command register\r\n");
    a2eo = pcrypto_adapter->a2eo;
    enl  = pcrypto_adapter->enl;

    //allocate a 32byte-aligned buffer and memset 
    pCL = (rtl_crypto_cl_t *)pcrypto_adapter->cl_buffer;
    rtlc_memset((u8*)pCL, 0, sizeof(pcrypto_adapter->cl_buffer));

    if (pcrypto_adapter->auth_type != AUTH_TYPE_NO_AUTH) {
        pCL->engine_mode = 1; //hash only

        //Enable seq_hash mechanism
        pCL->hmac_seq_hash = 1;

        //Check seq_hash first msg payload
        pCL->hmac_seq_hash_first = 0;
        if (pcrypto_adapter->hmac_seq_hash_first == 1) {
            pCL->hmac_seq_hash_first = 1;
            pcrypto_adapter->hmac_seq_hash_first = 0;
        }

        //Set mode parameters depend on what hash algorithm is
        if (pcrypto_adapter->isMD5) {
            pCL->habs = 1;
            pCL->hibs = 1;
            pCL->hobs = 1;
            pCL->hkbs = 1;
        } else if (pcrypto_adapter->isSHA1) {
            pCL->hmac_mode = 1;
            pCL->habs = 1;
        } else if (pcrypto_adapter->sha2type != SHA2_NONE) {
            pCL->hmac_mode = (pcrypto_adapter->sha2type == SHA2_224 )? 2 : 3 ; // currently only support SHA2_224 / SHA2_256
            pCL->habs = 1;
        }

        if (pcrypto_adapter->isHMAC) {
            pCL->hmac_en = 1;
        }

        if (pcrypto_adapter->hmac_seq_hash_last == 1) {
            
            // last msg payload always uses auto padding
            pCL->enl = (enl + 15)/16 ;
            pCL->enc_last_data_size = pcrypto_adapter->enc_last_data_size;
            pCL->ap0 = pcrypto_adapter->hmac_seq_hash_total_len * 8;
            DBG_CRYPTO_INFO("[Set src_desc_cmd_rst] enl = %d, enc_last_data_size = %d\r\n",pCL->enl,pcrypto_adapter->enc_last_data_size);
            DBG_CRYPTO_INFO("[Set src_desc_cmd_rst] hmac_seq_hash_total_len = %d\r\n",pcrypto_adapter->hmac_seq_hash_total_len);
            if (pcrypto_adapter->isHMAC) {
                pCL->ap0 += (64 * 8);
            }
        } else {
            pCL->enl = enl/64;
        }

        //Check seq_hash last msg payload. If it's the last msg payload,need to write back(Hash out result)
        pCL->hmac_seq_hash_last = 0;
        pCL->hmac_seq_hash_no_wb = 1;
        if (pcrypto_adapter->hmac_seq_hash_last == 1) {
            pCL->hmac_seq_hash_last = 1;
            pCL->hmac_seq_hash_no_wb = 0;
        }
    } else { // cipher - encryption / decryption

        uint32_t cipher_type;
        uint32_t block_mode;

        // ECB / CBC / CTR;
        cipher_type = pcrypto_adapter->cipher_type;
        block_mode = cipher_type & CIPHER_TYPE_MASK_BLOCK;
        pCL->cipher_mode = block_mode;
        DBG_CRYPTO_INFO("[Set src_desc_cmd_rst] cipher_type = 0x%x,cipher_mode = 0x%x\r\n",cipher_type,block_mode);

        if (pcrypto_adapter->aes) {
            pCL->cipher_eng_sel = 0;
            switch (pcrypto_adapter->lenCipherKey) {
                case 128/8 :
                    pCL->aes_key_sel = 0;
                    break;
                case 192/8 :
                    pCL->aes_key_sel = 1;
                    break;
                case 256/8 :
                    pCL->aes_key_sel = 2;
                    break;
                default:
                    break;
            }

            //AES,Chacha take 16bytes as a block to process data
            pCL->enl = (enl + 15)/16;
            pCL->enc_last_data_size = pcrypto_adapter->enc_last_data_size;

            if (block_mode ==  CIPHER_TYPE_BLOCK_GCM) {
                pCL->header_total_len = (a2eo + 15)/16;
                pCL->aad_last_data_size = pcrypto_adapter->aad_last_data_size;
            }

        } else if ( pcrypto_adapter->des ) { //DES,3DES take 8bytes as a block to process data
            pCL->cipher_eng_sel = 1;
            pCL->des3_en = 0;
            pCL->enl = (enl + 7)/8;
            pCL->enc_last_data_size = pcrypto_adapter->enc_last_data_size;
        } else if (pcrypto_adapter->trides) {
            pCL->cipher_eng_sel = 1;
            pCL->des3_en = 1;
            pCL->enl = (enl + 7)/8;
            pCL->enc_last_data_size = pcrypto_adapter->enc_last_data_size;
        } else if (pcrypto_adapter->chacha) {
            pCL->cipher_eng_sel = 2;
            pCL->enl = (enl + 15)/16;
            pCL->enc_last_data_size = pcrypto_adapter->enc_last_data_size;

            pCL->header_total_len = (a2eo + 15)/16;
            pCL->aad_last_data_size = pcrypto_adapter->aad_last_data_size;
        }

        DBG_CRYPTO_INFO("[Set src_desc_cmd_rst] enl = %d, enc_last_data_size = %d\r\n",pCL->enl,pCL->enc_last_data_size);
        DBG_CRYPTO_INFO("[Set src_desc_cmd_rst] header_total_len = %d, aad_last_data_size = %d\r\n",pCL->header_total_len,pCL->aad_last_data_size);
        
        if (pcrypto_adapter->isDecrypt == 0)
            pCL->cipher_encrypt = 1;

        if (pcrypto_adapter->chacha) {
            pCL->ckws = 1;
            pCL->cabs = 1;
            pCL->ciws = 1;
            pCL->cibs = 1;
            pCL->cows = 1;
            pCL->cobs = 1;
            pCL->codws = 1;
            pCL->cidws = 1;
        } else {
            pCL->cabs = 1;
        }
    }

    if (pcrypto_adapter->chacha) {
        pCL->ckbs = 1;
    }

    pCL->icv_total_length = 0x40; // for mix mode, but need to set a value 0x40
}

/**
 *  \fn          static inline void __rtl_cryptoEngine_srcDesc_generate_cl_key_IV(hal_crypto_adapter_t *pcrypto_adapter,
 *                                                                           const u8* p_iv, uint32_t ivLen)
 *  \brief       Set command setting buffer, key buffer, initial vector buffer, HMAC padding buffer in source descripter.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[in]   p_iv Pointer to crypto initial vector buffer
 *  \param[in]   ivLen Crypto initial vector buffer length
 *  \return      void
 */
__STATIC_INLINE
void __rtl_cryptoEngine_srcDesc_generate_cl_key_IV(hal_crypto_adapter_t *pcrypto_adapter,
        const u8* p_iv, uint32_t ivLen)
{
    rtl_crypto_srcdesc_t src_desc;
    //uint32_t val;

    src_desc.w = 0;

    // FS=1, CL=3
    src_desc.b.rs = 1;
    src_desc.b.fs = 1;
    src_desc.b.cl= 3;

    // auto padding[Hash algorithms need to set this]
    // It doesn't mean padding that makes up 16bytes aligned msglen]
    if (pcrypto_adapter->hmac_seq_hash_last) {
        src_desc.b.ap = 0x01;
    }
    __rtl_cryptoEngine_setup_cl_buffer(pcrypto_adapter);

    arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)(&(pcrypto_adapter->cl_buffer)[0]), 32);
    __dbg_mem_dump(pcrypto_adapter->isMemDump,(uint32_t)(&(pcrypto_adapter->cl_buffer)[0]), sizeof(pcrypto_adapter->cl_buffer), "Command Setting: ");
    __rtl_crypto_set_srcdesc(pcrypto_adapter, src_desc.w, (uint32_t)(&(pcrypto_adapter->cl_buffer)[0]));

    // Set key
    if (pcrypto_adapter->cipher_type != CIPHER_TYPE_NO_CIPHER) {
        uint32_t lenCipherKey;
        u8  *pCipherKey;
        uint32_t cache_len;

        lenCipherKey = (uint32_t) pcrypto_adapter->lenCipherKey;
        pCipherKey = (u8*) pcrypto_adapter->pCipherKey;
        DBG_CRYPTO_INFO("[Set src_desc_set_key] lenCipherKey = %d\r\n",lenCipherKey);

        src_desc.w = 0;
        src_desc.b.rs = 1;
        src_desc.b.fs = 1;
        src_desc.b.key_len = lenCipherKey/4;  //key_len use 4bytes as a unit

        cache_len = (lenCipherKey & 0x1F)? ((lenCipherKey/32) + 1) * 32: lenCipherKey;
        arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)(pCipherKey), cache_len);
        __dbg_mem_dump(pcrypto_adapter->isMemDump,(uint32_t)(pCipherKey), lenCipherKey, "KEY: ");
        __rtl_crypto_set_srcdesc(pcrypto_adapter, src_desc.w, (uint32_t)(pCipherKey));
    }

    // Set IV
    if (p_iv != NULL && ivLen > 0) {
        DBG_CRYPTO_INFO("[Set src_desc_set_IV] ivLen = %d\r\n",ivLen);
        uint32_t cache_len;
        src_desc.w = 0;
        src_desc.b.rs = 1;
        src_desc.b.fs = 1;
        src_desc.b.iv_len = ivLen/4;  //iv_len use 4bytes as a unit

        if (ivLen & 0x1F) {
            cache_len = ((ivLen/32) + 1) * 32;
        } else {
            cache_len = ivLen;
        }
        arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)(p_iv), cache_len);
        __dbg_mem_dump(pcrypto_adapter->isMemDump,(uint32_t)(p_iv), ivLen, "IV: ");
        __rtl_crypto_set_srcdesc(pcrypto_adapter, src_desc.w, (uint32_t)(p_iv));
    }

    // Set Pad
    if (pcrypto_adapter->isHMAC) {
        src_desc.w = 0;
        src_desc.b.rs = 1;
        src_desc.b.fs = 1;
        src_desc.b.keypad_len = 128/4; //HMAC keypad_len use 4bytes as a unit 

        arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)(&(pcrypto_adapter->g_IOPAD[0])), 128);
        __dbg_mem_dump(pcrypto_adapter->isMemDump,(uint32_t)(&(pcrypto_adapter->g_IOPAD[0])), 128, "HMAC Key PAD: ");
        __rtl_crypto_set_srcdesc(pcrypto_adapter, src_desc.w, (uint32_t)(&(pcrypto_adapter->g_IOPAD[0])));
    }
}

/**
 *  \fn          static inline int __rtl_cryptoEngine_pre_exec(hal_crypto_adapter_t *pcrypto_adapter)
 *  \brief       If programmer has registered a pre_exec function, it indicates using interrupt handler. So it calls 
 *               a registered function to initialize the notified flag before crypto calculating result interrupt triggers ISR.\n
 *               If programmer didn't register a function, it indicates using polling way to detect interrupt.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \return      value == 0     success
 *  \return      value == -1    fail
 */
__STATIC_INLINE
int __rtl_cryptoEngine_pre_exec(hal_crypto_adapter_t *pcrypto_adapter)
{
    if ((pcrypto_adapter != NULL) && (pcrypto_adapter->pre_exec_func != NULL)) {
        DBG_CRYPTO_INFO("Use pcrypto_adapter->pre_exec_func!\r\n");
        return pcrypto_adapter->pre_exec_func(pcrypto_adapter);
    }
    return SUCCESS;
}

/**
 *  \fn          static inline int __rtl_cryptoEngine_wait_done(hal_crypto_adapter_t *pcrypto_adapter)
 *  \brief       If programmer has registered a wait_done function, it indicates using interrupt handler. So it calls 
 *               a registered function waiting to be notified\n
 *               If programmer didn't register a function, it indicates using polling way. So it will busy-waiting the
 *               crypto calculating result interrupt arrives, or wait until timeout value count down to zero then return fail.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \return      value == 0     success
 *  \return      value == -1    fail
 */
__STATIC_INLINE
int __rtl_cryptoEngine_wait_done(hal_crypto_adapter_t *pcrypto_adapter)
{
    volatile uint32_t ips_err;
    volatile uint32_t ips_10_status;
    uint32_t loopWait;

    if ((pcrypto_adapter != NULL) && (pcrypto_adapter->wait_done_func != NULL)) {
        DBG_CRYPTO_INFO("Interrupt Handler way[Use pcrypto_adapter->wait_done_func]!\r\n");
        return pcrypto_adapter->wait_done_func(pcrypto_adapter);
    }

    // wait until ipsec engine stop
    loopWait = 1000000; /* hope long enough */
    while (1) {
        if (CRYPTO_MODULE->ipscsr_reset_isr_conf_reg_b.cmd_ok) {
            break;
        }

        ips_err = (CRYPTO_MODULE->ipscsr_err_stats_reg);
        if (ips_err) {
            __err_printk("ips 0x1C err = 0x%08x\r\n", ips_err);
            return FAIL;
        }

        loopWait--;
        if (loopWait == 0) {
            ips_10_status = (CRYPTO_MODULE->ipscsr_reset_isr_conf_reg);
            ips_err = (CRYPTO_MODULE->ipscsr_err_stats_reg);
            __err_printk("Wait Timeout ips status =0x%08x, ips err = 0x%08x\r\n", ips_10_status, ips_err);
            return FAIL; /* error occurs */
        }
    }
    return SUCCESS;
}

/**
 *  \fn          static inline void __rtl_cryptoEngine_set_encrypt(hal_crypto_adapter_t *pcrypto_adapter)
 *  \brief       Set encrypt information in crypto adapter data.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \return      void
 */
__STATIC_INLINE
void __rtl_cryptoEngine_set_encrypt(hal_crypto_adapter_t *pcrypto_adapter)
{
    pcrypto_adapter->cipher_type |= CIPHER_TYPE_MODE_ENCRYPT;
    pcrypto_adapter->isDecrypt = _FALSE;
}

/**
 *  \fn          static inline void __rtl_cryptoEngine_set_decrypt(hal_crypto_adapter_t *pcrypto_adapter)
 *  \brief       Set decrypt information in crypto adapter data
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \return      void
 */
__STATIC_INLINE
void __rtl_cryptoEngine_set_decrypt(hal_crypto_adapter_t *pcrypto_adapter)
{
    pcrypto_adapter->cipher_type ^= CIPHER_TYPE_MODE_ENCRYPT;
    pcrypto_adapter->isDecrypt = _TRUE;
}


//
// External Functions
//
/**
 *  \fn          static inline void __rtl_crypto_reset(void)
 *  \brief       Reset crypto engine DMA arbiter mode, clock, swap setting, endian setting, DMA burst length setting.
 *  \return      void
 */
__STATIC_INLINE
void __rtl_crypto_reset(void)
{
    // Crypto engine : Software Reset
    (CRYPTO_MODULE->ipscsr_reset_isr_conf_reg_b.soft_rst) = 1;

#if (LEXRA_BIG_ENDIAN == 1)
    {
        crypto_ipscsr_swap_burst_reg_t val;
        val.w = 0;
        val.b.set_swap = 1;
        //val.b.dma_burst_length = burstSize;
        val.b.dma_burst_length = 16;
        (CRYPTO_MODULE->ipscsr_swap_burst_reg) = val.w;
    }
#else
    {
        crypto_ipscsr_swap_burst_reg_t val;
        val.w = 0;
        val.b.key_iv_swap = 1;
        val.b.key_pad_swap = 1;
        val.b.hash_inital_value_swap = 1;
        val.b.dma_in_little_endian = 1;
        val.b.data_out_little_endian = 1;
        val.b.mac_out_little_endian = 1;
        val.b.dma_burst_length = 16;
        (CRYPTO_MODULE->ipscsr_swap_burst_reg) = val.w;
    }
#endif

    // Crypto Engine : DMA arbiter , clock enable
    {
        crypto_ipscsr_debug_reg_t val;

        val.w = 0;
        val.b.arbiter_mode = 1;
        val.b.engine_clk_en = 1;
        (CRYPTO_MODULE->ipscsr_debug_reg) = val.w;
    }

}

/**
 *  \fn          static inline int __rtl_cryptoEngine_set_security_mode(hal_crypto_adapter_t *pcrypto_adapter,
                                                                        IN const uint32_t cipher_type, IN const uint32_t auth_type,
                                                                        IN const void* pCipherKey, IN const uint32_t lenCipherKey,
                                                                        IN const void* pAuthKey, IN const uint32_t lenAuthKey)
 *  \brief       Set basic crypto information in crypto adapter data.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[in]   cipher_type Cipher type ID
 *  \param[in]   auth_type Authentication type ID
 *  \param[in]   pCipherKey Pointer to Crypto cipher key buffer
 *  \param[in]   lenCipherKey Crypto cipher key buffer length
 *  \param[in]   pAuthKey Pointer to Authentication key buffer
 *  \param[in]   lenAuthKey Authentication key buffer length
 *  \return      value == 0     success
 *  \return      value < 0      fail(error code)
 */
__STATIC_INLINE
int __rtl_cryptoEngine_set_security_mode(hal_crypto_adapter_t *pcrypto_adapter,
        IN const uint32_t cipher_type, IN const uint32_t auth_type,
        IN const void* pCipherKey, IN const uint32_t lenCipherKey,
        IN const void* pAuthKey, IN const uint32_t lenAuthKey
                                        )
{
    //int i;
    if (pcrypto_adapter == NULL) {
        return _ERRNO_CRYPTO_NULL_POINTER;
    }
    if (pcrypto_adapter->isInit != _TRUE) {
        return _ERRNO_CRYPTO_ENGINE_NOT_INIT;
    }
    if (lenAuthKey > 0) { // Authentication
        if (pAuthKey == NULL) {
            return _ERRNO_CRYPTO_NULL_POINTER;
        }
        if (lenAuthKey > CRYPTO_AUTH_PADDING) {
            return _ERRNO_CRYPTO_KEY_OutRange;
        }
    }
    //pcrypto_adapter->mode_select = mode_select;

    // Crypto
    pcrypto_adapter->trides      = 0;
    pcrypto_adapter->aes		 = 0;
    pcrypto_adapter->des		 = 0;
    pcrypto_adapter->chacha		 = 0;
    pcrypto_adapter->isDecrypt	 = 0;
    pcrypto_adapter->cipher_type = cipher_type;

    if (cipher_type != CIPHER_TYPE_NO_CIPHER) {
        switch (cipher_type & CIPHER_TYPE_MASK_FUNC) {
            case CIPHER_TYPE_FUNC_DES :
                pcrypto_adapter->des = 1;
                break;
            case CIPHER_TYPE_FUNC_3DES :
                pcrypto_adapter->trides = 1;
                break;
            case CIPHER_TYPE_FUNC_AES :
                pcrypto_adapter->aes = 1;
                break;
            case CIPHER_TYPE_FUNC_CHACHA :
                pcrypto_adapter->chacha = 1;
                break;
        }
        pcrypto_adapter->isDecrypt = (cipher_type & CIPHER_TYPE_MODE_ENCRYPT)? 0: 1;
    }

    // Auth
    pcrypto_adapter->auth_type = auth_type;
    if (auth_type != AUTH_TYPE_NO_AUTH) {
        pcrypto_adapter->isHMAC = (auth_type & AUTH_TYPE_MASK_HMAC) ? 1 : 0;
        pcrypto_adapter->isMD5  = ((auth_type & AUTH_TYPE_MASK_FUNC) == AUTH_TYPE_MD5 )? 1 : 0;
        pcrypto_adapter->isSHA1 = ((auth_type & AUTH_TYPE_MASK_FUNC) == AUTH_TYPE_SHA1 )? 1 : 0;
        pcrypto_adapter->isSHA2 = ((auth_type & AUTH_TYPE_MASK_FUNC) == AUTH_TYPE_SHA2 )? 1 : 0;
        if (pcrypto_adapter->isSHA2) {
            switch (auth_type & AUTH_TYPE_MASK_SHA2) {
                case AUTH_TYPE_SHA2_224 :
                    pcrypto_adapter->sha2type = SHA2_224;
                    break;
                case AUTH_TYPE_SHA2_256 :
                    pcrypto_adapter->sha2type = SHA2_256;
                    break;
                default :
                    __err_printk("No this auth_type(%d) for SHA2\n", auth_type);
                    pcrypto_adapter->sha2type = SHA2_NONE;
                    break;
            }
        } else {
            pcrypto_adapter->sha2type = SHA2_NONE;
        }
    } else {
        pcrypto_adapter->isMD5    = 0;
        pcrypto_adapter->isHMAC   = 0;
        pcrypto_adapter->isSHA1   = 0;
        pcrypto_adapter->isSHA2   = 0;
        pcrypto_adapter->sha2type = SHA2_NONE;
    }

    __rtl_cryptoEngine_set_digestlen(pcrypto_adapter, auth_type);
    __rtl_cryptoEngine_set_key(pcrypto_adapter, pCipherKey, lenCipherKey, pAuthKey, lenAuthKey);

    if (auth_type != AUTH_TYPE_NO_AUTH) {
        pcrypto_adapter->hmac_seq_hash_first = 1;
        pcrypto_adapter->hmac_seq_hash_last = 0;
        pcrypto_adapter->hmac_seq_hash_total_len = 0;
    }
    return SUCCESS;
}

/**
 *  \fn          static inline int __rtl_cryptoEngine_init(hal_crypto_adapter_t *pcrypto_adapter)
 *  \brief       Reset crypto engine, then set initial state and reset interrupt state in crypto adapter data
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \return      Always return SUCCESS
 */
__STATIC_INLINE
int __rtl_cryptoEngine_init(hal_crypto_adapter_t *pcrypto_adapter)
{

    CRYPTO_ADAPTER = pcrypto_adapter;

    __rtl_crypto_reset();

    //__rtl_crypto_irq_enable();

    pcrypto_adapter->isInit = 1;
    pcrypto_adapter->isIntMode = 0;
    DBG_CRYPTO_INFO("After CryptoEngine reset: isInit = %d, isIntMode = %d\r\n",pcrypto_adapter->isInit,pcrypto_adapter->isIntMode);

    return SUCCESS;
}

/**
 *  \fn          static inline void __rtl_crypto_modify_enc_last_data_size(hal_crypto_adapter_t *pcrypto_adapter,
                                                                           IN const u8 *message,IN const uint32_t msglen)
 *  \brief       Only AES_GCM or Chacha20_Poly1305 may modify enc_last_data_size in decryption to match with the tag value of encryption.
 *  \note        Observe if AES_GCM or Chacha_poly1305 use non-16 bytes aligned plaintext as an input,
 *               it will generate a 16 bytes aligned ciphertext which is composed of ori_len(plaintext)+padding_len(0). \n
 *               And then use this 16 bytes aligned msglen of ciphertext as decryption input,
 *               this could recover back to the plaintext; however, the enc_last_data_size is different from encryption,
 *               so it leads to different tag value of decryption. That's why need to modify the enc_last_data_size same as encryption.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[in]   message Pointer to Crypto cipher message buffer
 *  \param[in]   msglen Crypto cipher message buffer length
 *  \return      void
 */
__STATIC_INLINE
void __rtl_crypto_modify_enc_last_data_size(hal_crypto_adapter_t *pcrypto_adapter,
                                           IN const u8 *message,IN const uint32_t msglen){
    int vLaid_byte = 0;
    int find_zero = 0;
    // Because AES_GCM,Chacha_poly1305 only allow 16bytes aligned msglen to decrypt,
    // jump to the start_addr of the last 16 bytes msg. 
    int offset_byte = (msglen - 16);
    u8 *pLast_start = (u8 *)message + offset_byte;
    
    while(vLaid_byte < 16){
        
        if(*pLast_start != 0x00){
            if(find_zero != 0){
                find_zero = 0;
            }
        }else{
            ++find_zero;
        }
        ++vLaid_byte;
        ++pLast_start;
    }
    
    if(16 == vLaid_byte){
        // The last one
        if(1 == find_zero){
            find_zero = 0;    
        }

        vLaid_byte = 16 - find_zero;
    }

    DBG_CRYPTO_INFO("vLaid_byte = %d\r\n",vLaid_byte);
    pcrypto_adapter->enc_last_data_size = vLaid_byte;
}

/**
 *  \fn          static inline int __rtl_cryptoEngine(hal_crypto_adapter_t *pcrypto_adapter,
                                                      IN const u8 *message, 	IN const uint32_t msglen,
                                                      IN const u8 *pIv, 		IN const uint32_t ivlen,
                                                      IN const u8 *paad, 		IN const uint32_t aadlen,
                                                      OUT u8 *pResult, OUT u8 *pTag)
 *  \brief       Check input parameters, and set crypto engine registers, then make crypto engine handle this algorithm.
 *  \details     The executing order of crypto engine setting: \n
 *               - Initialize the notified mechanism.
 *               - Set essential buffers and buffer lengths of the cryptographic feature to crypto adapter
 *               - Setup desitination descriptor
 *               - Setup source descriptor
 *                  - Setup command setting buffer
 *                  - Setup key, initial vector, HMAC padding buffer
 *                  - Prepare Data1 ~ DataN
 *               - Wait to be notified after interrupt service routine processed over.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[in]   message Pointer to Crypto cipher message buffer
 *  \param[in]   msglen Crypto cipher message buffer length
 *  \param[in]   pIv Pointer to Crypto cipher initial vector buffer
 *  \param[in]   ivlen Crypto cipher initial vector buffer length
 *  \param[in]   paad Pointer to Crypto cipher additional authentication data buffer
 *  \param[in]   aadlen Crypto cipher additional authentication data buffer length
 *  \param[out]  pResult Pointer to Crypto cipher result buffer
 *  \param[out]  pTag Pointer to Crypto cipher Tag buffer
 *  \return      value == 0     success
 *  \return      value < 0      fail(error code)
 */
__STATIC_INLINE
int __rtl_cryptoEngine(hal_crypto_adapter_t *pcrypto_adapter,
                       IN const u8 *message, 	IN const uint32_t msglen,
                       IN const u8 *pIv, 		IN const uint32_t ivlen,
                       IN const u8 *paad, 		IN const uint32_t aadlen,
                       OUT u8 *pResult, OUT u8 *pTag)
{
    rtl_crypto_srcdesc_t srcdesc;

    uint32_t a2eo;
    uint32_t enl;
    uint32_t digestlen;
    uint32_t cipher_type = CIPHER_TYPE_NONE;
    uint32_t block_mode;
    volatile uint8_t *padding = NULL;
    int ret = SUCCESS;
    
    if (pcrypto_adapter == NULL) {
        return _ERRNO_CRYPTO_NULL_POINTER;
    } else {
        padding = (&(pcrypto_adapter->padding[0]));
    }
    __rtl_cryptoEngine_pre_exec(pcrypto_adapter);

    if ((paad != NULL) && (aadlen > 0)) {
        uint32_t cache_len;
        if (aadlen & 0x1F) {
            cache_len = ((aadlen/32) + 1) * 32;
        } else {
            cache_len = aadlen;
        }
        arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)paad, cache_len);
    }

    // Use only one scatter
    a2eo = aadlen;
    enl = msglen;

    __rtl_crypto_start_packet_init();
//
//   Set relative length data
//
    __rtl_cryptoEngine_auth_calc_apl(pcrypto_adapter, a2eo, enl);
    //Only AES_GCM or Chacha_poly1305 may modify enc_last_data_size in decryption to match with the tag value of encryption
    if (pcrypto_adapter->isDecrypt){
        cipher_type = pcrypto_adapter->cipher_type;
        block_mode  = cipher_type & CIPHER_TYPE_MASK_BLOCK;
        if (((pcrypto_adapter->aes) && (block_mode ==  CIPHER_TYPE_BLOCK_GCM)) ||
            ((pcrypto_adapter->chacha) && (block_mode ==  CIPHER_TYPE_BLOCK_CHACHA_POLY1305))) {
            __rtl_crypto_modify_enc_last_data_size(pcrypto_adapter,message,enl);
        }
    }

    //Hash result length
    digestlen = pcrypto_adapter->digestlen;

    if (pcrypto_adapter->auth_type != AUTH_TYPE_NO_AUTH) {

        //Sum of seq_hash msglen
        pcrypto_adapter->hmac_seq_hash_total_len += msglen;

        //Make sure if it's the last seq_hash msg payload
        if (pResult != NULL) {
            pcrypto_adapter->hmac_seq_hash_last = 1;
        }
    }

    /********************************************
     * step 1: Setup desitination descriptor
     ********************************************/
    pcrypto_adapter->is_dst_first_cache_used = 0;
    pcrypto_adapter->is_dst_last_cache_used  = 0;

    if (pcrypto_adapter->auth_type != AUTH_TYPE_NO_AUTH) {
        rtl_crypto_dstdesc_t dst_desc;

        //It's the last seq_hash msg payload, so need to hash out the result
        if (pResult != NULL) {
            dst_desc.w = 0;
            dst_desc.auth.ws  = 1;
            dst_desc.auth.fs  = 1;
            dst_desc.auth.ls  = 1;
            dst_desc.auth.adl = digestlen;
            arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)pcrypto_adapter->digest_result, 32);
            __rtl_crypto_set_dstdesc(dst_desc.w, (uint32_t)pcrypto_adapter->digest_result);
        }

    } else { // cipher(also need dst_auth_desc(such as AES_GCM or Chacha_poly1305) or poly1305)
        rtl_crypto_dstdesc_t  dst_auth_desc;
        rtl_crypto_dstdesc_t  dst_cipher_desc;
        int8_t first_cache_pos = 0;
        int8_t first_cache_len = 0;
        int8_t last_cache_pos  = 0;
        int8_t last_cache_len  = 0;
        int dst_len;

        if (pResult != NULL) {
            //Destination descriptor may change msglen, because of encryption padding
            dst_len = (pcrypto_adapter->enl + (pcrypto_adapter->apl));
            DBG_CRYPTO_INFO("[Set dest_desc] dst_len = %d,enl = %d,apl = %d\r\n",dst_len,(pcrypto_adapter->enl),(pcrypto_adapter->apl));
            
            first_cache_pos = (uint32_t)pResult & 0x1F;
            first_cache_len = (32 - first_cache_pos) % 32;
            if (first_cache_len >= dst_len) {
                //There's an enough space of first_cache_line for dst_len
                first_cache_len = dst_len;
                last_cache_len  = 0;
            } else {
                last_cache_pos = (uint32_t)(pResult + dst_len - 1) & 0x1F;
                last_cache_len = last_cache_pos + 1;
                if (last_cache_len == 32) {
                    last_cache_len = 0;
                }
            }
            DBG_CRYPTO_INFO("[Set dest_desc] f_cache_pos = %d,f_cache_len = %d\r\n",first_cache_pos,first_cache_len);
            DBG_CRYPTO_INFO("[Set dest_desc] l_cache_pos = %d,l_cache_len = %d\r\n",last_cache_pos,last_cache_len);
            
            dst_cipher_desc.w = 0;
            dst_cipher_desc.cipher.ws  = 1;
            dst_cipher_desc.cipher.fs  = 1;
            dst_cipher_desc.cipher.enc = 1;

            if (first_cache_len != 0) { //
                pcrypto_adapter->is_dst_first_cache_used = 1;
                dst_cipher_desc.cipher.enl = first_cache_len;
                DBG_CRYPTO_INFO("[Set dest_desc] f_cache_line_enl = %d\r\n",first_cache_len);
                if ((first_cache_len >= dst_len) && (pTag == NULL)) {
                    dst_cipher_desc.cipher.ls = 1;
                }
                arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)pcrypto_adapter->dst_first_cache_line, 32);
                __rtl_crypto_set_dstdesc(dst_cipher_desc.w, (uint32_t)pcrypto_adapter->dst_first_cache_line);

                dst_len -= first_cache_len;
                pResult += first_cache_len;

                dst_cipher_desc.w = 0;
                dst_cipher_desc.cipher.ws = 1;
                dst_cipher_desc.cipher.enc = 1;
            }

            if (dst_len > 0) {
                //Cut off valid msg of last_cache_line
                //It means leave 32 bytes alignment addr of msg_body
                dst_cipher_desc.cipher.enl = (dst_len - last_cache_len);

                if (last_cache_len != 0) {
                    pcrypto_adapter->is_dst_last_cache_used = 1;
                    if (dst_len > last_cache_len) { // body
                        arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)pResult, (dst_len - last_cache_len));
                        __rtl_crypto_set_dstdesc(dst_cipher_desc.w, (uint32_t)pResult);
                    }
                    pResult += (dst_len - last_cache_len);
                    dst_len = last_cache_len;

                    dst_cipher_desc.w = 0;
                    dst_cipher_desc.cipher.ws  = 1;
                    dst_cipher_desc.cipher.enc = 1;
                    dst_cipher_desc.cipher.enl = last_cache_len;
                    DBG_CRYPTO_INFO("[Set dest_desc] l_cache_line_enl = %d\r\n",last_cache_len);
                    if (pTag == NULL) {
                        dst_cipher_desc.cipher.ls = 1;
                    }
                    arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)pcrypto_adapter->dst_last_cache_line, 32);
                    __rtl_crypto_set_dstdesc(dst_cipher_desc.w, (uint32_t)pcrypto_adapter->dst_last_cache_line);
                } else {
                    if (pTag == NULL) {
                        dst_cipher_desc.cipher.ls = 1;
                    }
                    arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)pResult, dst_cipher_desc.cipher.enl);
                    __rtl_crypto_set_dstdesc(dst_cipher_desc.w, (uint32_t)pResult);
                }
            }
        }

        if (pTag != NULL) {
            //Calculate cipher Tag,use adl not enc!
            dst_auth_desc.w = 0;
            
            if (CIPHER_TYPE_POLY1305 == (cipher_type & CIPHER_TYPE_MASK_ALL)) {
                dst_auth_desc.auth.fs = 1;
            }
            dst_auth_desc.auth.ws  = 1;
            dst_auth_desc.auth.enc = 0;
            dst_auth_desc.auth.adl = 16;
            dst_auth_desc.auth.ls  = 1;
            arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)pcrypto_adapter->tag_result, 32);
            __rtl_crypto_set_dstdesc(dst_auth_desc.w, (uint32_t)pcrypto_adapter->tag_result);
        }
    }

    /********************************************
     * step 2: Setup source descriptor
     ********************************************/
    /********************************************
      * step 2-1: prepare Key & IV array:
      ********************************************/

    __rtl_cryptoEngine_srcDesc_generate_cl_key_IV(pcrypto_adapter, pIv, ivlen);


    /********************************************
     * step 2-2: prepare Data1 ~ DataN
     ********************************************/

    srcdesc.w = 0;
    srcdesc.d.rs = 1;

    if (paad != NULL) {
        while (a2eo > 16) {
            srcdesc.d.a2eo = 16;

            __dbg_mem_dump(pcrypto_adapter->isMemDump,paad, 16, "AAD[while-loop]: ");
            __rtl_crypto_set_srcdesc(pcrypto_adapter, srcdesc.w, (uint32_t)paad);

            paad += 16;
            a2eo -= 16;
            srcdesc.w = 0;
            srcdesc.d.rs = 1;
        }

        if (a2eo > 0) {
            DBG_CRYPTO_INFO("[Set src_desc_data] a2eo = %d\r\n",a2eo);
            srcdesc.d.a2eo = a2eo;
            __dbg_mem_dump(pcrypto_adapter->isMemDump,paad, a2eo, "AAD[rest]: ");
            __rtl_crypto_set_srcdesc(pcrypto_adapter, srcdesc.w, (uint32_t)paad);
            srcdesc.w = 0;
            srcdesc.d.rs = 1;
        }

        //Handle padding issue
        if (pcrypto_adapter->apl_aad > 0) {
            DBG_CRYPTO_INFO("[Set src_desc_data] apl_aad = %d\r\n",pcrypto_adapter->apl_aad);
            srcdesc.d.a2eo = pcrypto_adapter->apl_aad;
            //rtl_printf("clean padding: 0x%x \r\n", padding);
            arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)padding, 64);
            __dbg_mem_dump(pcrypto_adapter->isMemDump,padding, pcrypto_adapter->apl_aad, "AAD padding ");
            __rtl_crypto_set_srcdesc(pcrypto_adapter, srcdesc.w, (uint32_t)padding);
            srcdesc.w = 0;
            srcdesc.d.rs = 1;
        }

    }

    {
        int8_t first_cache_pos = 0;
        int8_t first_cache_len = 0;
        int8_t last_cache_pos  = 0;
        int8_t last_cache_len  = 0;

        first_cache_pos = (uint32_t) message & 0x1F;
        first_cache_len = (32 - first_cache_pos) % 32;
        if ((uint32_t)first_cache_len >= enl) { // the same one
            first_cache_len = enl;
            last_cache_len  = 0;
        } else {
            last_cache_pos = ((uint32_t)(message) + enl - 1) & 0x1F;
            last_cache_len = last_cache_pos + 1;
        }

        DBG_CRYPTO_INFO("[Set src_desc_data] f_cache_pos = %d,f_cache_len = %d\r\n",first_cache_pos,first_cache_len);
        DBG_CRYPTO_INFO("[Set src_desc_data] l_cache_pos = %d,l_cache_len = %d\r\n",last_cache_pos,last_cache_len);

        if (first_cache_len != 0) {
            rtlc_memcpy((void*)(&(pcrypto_adapter->src_first_cache_line[0])), (const void*)(message), first_cache_len);

            if (((uint32_t)first_cache_len >= enl) && (pcrypto_adapter->apl == 0)){
                srcdesc.d.ls = 1;
            }
            srcdesc.d.enl = first_cache_len;
            DBG_CRYPTO_INFO("[Set src_desc_data] f_cache_line_enl = %d\r\n",first_cache_len);
            __dbg_mem_dump(pcrypto_adapter->isMemDump,&(pcrypto_adapter->src_first_cache_line[0]), first_cache_len, "src_data[first_cache_line]: ");
            arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)(&(pcrypto_adapter->src_first_cache_line[0])), 32);
            __rtl_crypto_set_srcdesc(pcrypto_adapter, srcdesc.w, (uint32_t)(&(pcrypto_adapter->src_first_cache_line[0])));
            message += first_cache_len;
            enl -= first_cache_len;
            srcdesc.w = 0;
            srcdesc.d.rs = 1;
        }

        // 16352 bytes is the max size of enl could set!
        while (enl > 16352) {
            arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)message, 16352);
            srcdesc.d.enl = 16352;
            __rtl_crypto_set_srcdesc(pcrypto_adapter, srcdesc.w, (uint32_t)message);

            message += 16352;
            enl -= 16352;
            srcdesc.w = 0;
            srcdesc.d.rs = 1;
        }

        //Cut off valid msg of last_cache_line
        //It means leave 32 bytes alignment addr of msg_body
        // message aligned body
        if (enl > (uint32_t)(last_cache_len)) {
            uint32_t dst_len = enl - (uint32_t)(last_cache_len);

            // assert
            if ((dst_len & 0x1F) != 0) {
                __err_printk("Strange : enl(%d), last_cache_len(%d)", enl, last_cache_len);
                return _ERRNO_CRYPTO_CACHE_HANDLE;
            }

            DBG_CRYPTO_INFO("[Set src_desc_data] dst_len = %d\r\n",dst_len);
            srcdesc.d.enl = dst_len;
            arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)message, srcdesc.d.enl);
            __dbg_mem_dump(pcrypto_adapter->isMemDump,message, msglen, "src_data[msg_32align_body]: ");
            __rtl_crypto_set_srcdesc(pcrypto_adapter, srcdesc.w, (uint32_t)message);
            message += dst_len;
            enl -= dst_len;

            srcdesc.w = 0;
            srcdesc.d.rs = 1;
        } else if (enl < (uint32_t)(last_cache_len)) {
            // can change to use assert function
            __err_printk("Strange : enl(%d), last_cache_len(%d)", enl, last_cache_len);
            return _ERRNO_CRYPTO_CACHE_HANDLE;
        }

        if (last_cache_len == 32) {
            if (pcrypto_adapter->apl == 0) {
                srcdesc.d.ls = 1;
            }
            srcdesc.d.enl = 32;
            __dbg_mem_dump(pcrypto_adapter->isMemDump,message, 32, "src_data[last_cache_len_equal_32]: ");
            arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)message, 32);
            __rtl_crypto_set_srcdesc(pcrypto_adapter, srcdesc.w, (uint32_t)message);
        } else if (last_cache_len != 0)  {
            rtlc_memcpy((void*)(pcrypto_adapter->src_last_cache_line), (const void*)(message), last_cache_len);
            DBG_CRYPTO_INFO("[Set src_desc_data] l_cache_len(below 32) = %d\r\n",last_cache_len);
            if (pcrypto_adapter->apl == 0) {
                srcdesc.d.ls = 1;
            }
            srcdesc.d.enl = last_cache_len;
            __dbg_mem_dump(pcrypto_adapter->isMemDump,pcrypto_adapter->src_last_cache_line, last_cache_len, "src_data[last_cache_len_below_32]: ");
            arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)pcrypto_adapter->src_last_cache_line, 32);
            __rtl_crypto_set_srcdesc(pcrypto_adapter, srcdesc.w, (uint32_t)pcrypto_adapter->src_last_cache_line);
        }

        if (pcrypto_adapter->apl != 0) {
            DBG_CRYPTO_INFO("[Set src_desc_data] pcrypto_adapter->apl = %d\r\n",pcrypto_adapter->apl);
            srcdesc.w = 0;
            srcdesc.d.rs  = 1;
            srcdesc.d.enl = pcrypto_adapter->apl;
            srcdesc.d.ls  = 1;
            arch_clean_dcache_by_size(pcrypto_adapter, (uint32_t)padding, 64);
            __dbg_mem_dump(pcrypto_adapter->isMemDump,padding, srcdesc.d.enl, "src_data padding ");
            __rtl_crypto_set_srcdesc(pcrypto_adapter, srcdesc.w, (uint32_t)padding);
        }
    }
    ret = __rtl_cryptoEngine_wait_done(pcrypto_adapter);

    return ret;
}

//
/**
 *  \fn          static inline int __rtl_crypto_cipher_init(hal_crypto_adapter_t *pcrypto_adapter,
                                                            IN const uint32_t cipher_type,
                                                            IN const u8 *key, IN const uint32_t keylen)
 *  \brief       Set crypto cipher information in crypto adapter data.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[in]   cipher_type  Cipher type ID
 *  \param[in]   key Pointer to crypto cipher key buffer
 *  \param[in]   keylen Cipher key buffer length
 *  \return      value == 0     success
 *  \return      value < 0      fail(error code)
 */
__STATIC_INLINE
int __rtl_crypto_cipher_init(hal_crypto_adapter_t *pcrypto_adapter,
                             IN const uint32_t cipher_type,
                             IN const u8 *key, IN const uint32_t keylen)
{
    u8* pAuthKey = NULL;
    uint32_t lenAuthKey = 0;

    return __rtl_cryptoEngine_set_security_mode(pcrypto_adapter,
            cipher_type, AUTH_TYPE_NO_AUTH,
            key, keylen, pAuthKey, lenAuthKey);
}

/**
 *  \fn          static inline int __rtl_crypto_cipher_encrypt(hal_crypto_adapter_t *pcrypto_adapter,
                                                               IN const u8* message, IN const uint32_t msglen,
                                                               IN const u8* piv, IN const uint32_t ivlen,
                                                               IN const u8* paad, IN const uint32_t aadlen,
                                                               OUT u8* pResult, OUT u8* pTag)
 *  \brief       Set encrypt information and make crypto engine process plaintext.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[in]   message Pointer to Crypto cipher message buffer
 *  \param[in]   msglen Crypto cipher message buffer length
 *  \param[in]   piv Pointer to Crypto cipher initial vector buffer
 *  \param[in]   ivlen Crypto cipher initial vector buffer length
 *  \param[in]   paad Pointer to Crypto cipher additional authentication data buffer
 *  \param[in]   aadlen Crypto cipher additional authentication data buffer length
 *  \param[out]  pResult Pointer to Crypto cipher result buffer
 *  \param[out]  pTag Pointer to Crypto cipher Tag buffer
 *  \return      value == 0     success
 *  \return      value < 0      fail(error code)
 */
__STATIC_INLINE
int __rtl_crypto_cipher_encrypt(hal_crypto_adapter_t *pcrypto_adapter,
                                IN const u8* message, 	IN const uint32_t msglen,
                                IN const u8* piv, 		IN const uint32_t ivlen,
                                IN const u8* paad, 		IN const uint32_t aadlen,
                                OUT u8* pResult, OUT u8* pTag)
{
    int ret;

    __rtl_cryptoEngine_set_encrypt(pcrypto_adapter);

    ret = __rtl_cryptoEngine(pcrypto_adapter, message, msglen, piv, ivlen, paad, aadlen, pResult, pTag);
    
    return ret;
}

/**
 *  \fn          static inline int __rtl_crypto_cipher_decrypt(hal_crypto_adapter_t *pcrypto_adapter, IN const u8* message, IN const uint32_t msglen,
                                                               IN const u8* piv, IN const uint32_t ivlen,
                                                               IN const u8* paad, IN const uint32_t aadlen,
                                                               OUT u8* pResult, OUT u8* pTag )
 *  \brief       Set decrypt information and make crypto engine process ciphertext.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[in]   message Pointer to Crypto cipher message buffer
 *  \param[in]   msglen Crypto cipher message buffer length
 *  \param[in]   piv Pointer to Crypto cipher initial vector buffer
 *  \param[in]   ivlen Crypto cipher initial vector buffer length
 *  \param[in]   paad Pointer to Crypto cipher additional authentication data buffer
 *  \param[in]   aadlen Crypto cipher additional authentication data buffer length
 *  \param[out]  pResult Pointer to Crypto cipher result buffer
 *  \param[out]  pTag Pointer to Crypto cipher Tag buffer
 *  \return      value == 0     success
 *  \return      value < 0      fail(error code)
 */
__STATIC_INLINE
int __rtl_crypto_cipher_decrypt(
    hal_crypto_adapter_t *pcrypto_adapter,
    IN const u8* message, 	IN const uint32_t msglen,
    IN const u8* piv, 			IN const uint32_t ivlen,
    IN const u8* paad,			IN const uint32_t aadlen,
    OUT u8* pResult, OUT u8* pTag )
{
    int ret;

    __rtl_cryptoEngine_set_decrypt(pcrypto_adapter);
    ret = __rtl_cryptoEngine(pcrypto_adapter, message, msglen, piv, ivlen, paad, aadlen, pResult, pTag);

    return ret;
}

//
//

/**
 *  \fn          static inline void rtl_cryptoEngine_get_result(hal_crypto_adapter_t *pcrypto_adapter, u8 *pDigest, u8 *pResult,
 *                                                              uint32_t len, u8 *pTag)
 *  \brief       Get crypto cipher result/authetication digest or crypto cipher tag.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[in]   len Crypto cipher message buffer length
 *  \param[out]  pDigest Pointer to authentication digest buffer
 *  \param[out]  pResult Pointer to crypto cipher result buffer
 *  \param[out]  pTag Pointer to crypto cipher Tag buffer
 *  \return      void
 */
__STATIC_INLINE
void rtl_cryptoEngine_get_result(hal_crypto_adapter_t *pcrypto_adapter, u8 *pDigest, u8 *pResult, uint32_t len, u8 *pTag)
{
    if (pcrypto_adapter->auth_type != AUTH_TYPE_NO_AUTH) {
        arch_invalidate_dcache_by_size(pcrypto_adapter, (uint32_t)(pcrypto_adapter->digest_result), 32);
        __dbg_mem_dump(pcrypto_adapter->isMemDump,pcrypto_adapter->digest_result, 32, "digest_result: ");
        rtlc_memcpy((void*)(pDigest), (const void*)(pcrypto_adapter->digest_result), pcrypto_adapter->digestlen);
    } else {

        uint32_t dst_len = 0;
        uint32_t first_cache_pos = 0;
        uint32_t first_cache_len = 0;
        uint32_t last_cache_pos  = 0;
        uint32_t last_cache_len  = 0;

        first_cache_pos = (uint32_t)(pResult) & 0x1F;
        first_cache_len = (32 - first_cache_pos) % 32;
        if (first_cache_len >= len) { // the same one
            first_cache_len = len;
            last_cache_len  = 0;
        } else {
            last_cache_pos = ((uint32_t)(pResult) + len - 1) & 0x1F;
            last_cache_len = last_cache_pos + 1;
            if (last_cache_len == 32) {
                last_cache_len = 0;
            }
        }

        DBG_CRYPTO_INFO("[Get cipher_result] f_cache_pos = %d,f_cache_len = %d\r\n",first_cache_pos,first_cache_len);
        DBG_CRYPTO_INFO("[Get cipher_result] l_cache_pos = %d,l_cache_len = %d\r\n",last_cache_pos,last_cache_len);

        if (pcrypto_adapter->is_dst_first_cache_used != 0) {
            arch_invalidate_dcache_by_size(pcrypto_adapter, (uint32_t)(pcrypto_adapter->dst_first_cache_line), 32);
            rtlc_memcpy((void*)(pResult), (const void*)(pcrypto_adapter->dst_first_cache_line), first_cache_len);
            dst_len += first_cache_len;
        }

        //32 byte aligned msg body which doesn't need memcpy
        if (len > (dst_len + last_cache_len)) {
            DBG_CRYPTO_INFO("[Get cipher_result] msg_body_len = %d\r\n",(len - dst_len - last_cache_len));
            //rtl_printf("arch_invalidate - %d \r\n", (len-dst_len-last_cache_len));
            arch_invalidate_dcache_by_size(pcrypto_adapter, (uint32_t)(pResult) + dst_len, (len - dst_len - last_cache_len));
        }
        
        //Handle last_cache_line
        dst_len = len - last_cache_len;
        if (pcrypto_adapter->is_dst_last_cache_used != 0) {
            arch_invalidate_dcache_by_size(pcrypto_adapter, (uint32_t)(pcrypto_adapter->dst_last_cache_line), 32);
            rtlc_memcpy((void*)(pResult + dst_len), (const void*)(pcrypto_adapter->dst_last_cache_line), last_cache_len);
        }
    }
    if (pTag != NULL) {
        arch_invalidate_dcache_by_size(pcrypto_adapter, (uint32_t)(pcrypto_adapter->tag_result), sizeof(pcrypto_adapter->tag_result));
        rtlc_memcpy((void*)pTag, (const void*)(pcrypto_adapter->tag_result), 16);
    }
}

//
//

//AUTH
/**
 *  \fn          static inline int rtl_crypto_auth_init(hal_crypto_adapter_t *pcrypto_adapter, uint32_t type, const u8* pAuthKey, const u32 lenAuthKey)
 *  \brief       Check input parameters which authentication Hash/HMAC needs, 
 *               and set related authentication Hash/HMAC initial values to crypto adapter.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[in]   type Hash/HMAC type ID
 *  \param[in]   pAuthKey Pointer to authentication key buffer
 *  \param[in]   lenAuthKey Authentication key buffer length
 *  \return      value == 0     success
 *  \return      value < 0      fail(error code)
 */
__STATIC_INLINE
int rtl_crypto_auth_init(hal_crypto_adapter_t *pcrypto_adapter, uint32_t type,
                         const u8* pAuthKey, const u32 lenAuthKey)
{
    int ret;
    const u8* pCipherKey 	= NULL;
    const u32 lenCipherKey 	= 0;

    //rtl_assert( (pcrypto_adapter != NULL) && (pcrypto_adapter->isInit == _TRUE) );
    if (pcrypto_adapter->isInit != _TRUE) {
        return _ERRNO_CRYPTO_ENGINE_NOT_INIT; // not init yet
    }

    // for sequential hash
    pcrypto_adapter->hmac_seq_is_recorded = 0;
    pcrypto_adapter->hmac_seq_buf_is_used_bytes = 0;

    ret = __rtl_cryptoEngine_set_security_mode(pcrypto_adapter, CIPHER_TYPE_NO_CIPHER, type,
                                               pCipherKey, lenCipherKey, pAuthKey, lenAuthKey);
    return ret;
}

/**
 *  \fn          static inline int rtl_crypto_auth_hmac_init(hal_crypto_adapter_t *pcrypto_adapter, uint32_t type,
                                                             const u8* key, const u32 keylen)
 *  \brief       Check input parameters which authentication HMAC needs,
 *               and set related authentication initial values to crypto adapter.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[in]   type Hash/HMAC type ID
 *  \param[in]   key Pointer to authentication key buffer
 *  \param[in]   keylen Authentication key buffer length
 *  \return      value == 0     success
 *  \return      value < 0      fail(error code)
 */
__STATIC_INLINE
int rtl_crypto_auth_hmac_init(
    hal_crypto_adapter_t *pcrypto_adapter, uint32_t type,
    const u8* key, const u32 keylen)
{
    if (key == NULL) {
        return _ERRNO_CRYPTO_NULL_POINTER;
    }
    if ((u32)(key) & 0x1F) {
        return _ERRNO_CRYPTO_ADDR_NOT_32Byte_Aligned;
    }
    if (keylen == 0) {
        return _ERRNO_CRYPTO_KEY_OutRange; 
    }
    if (keylen > CRYPTO_AUTH_PADDING) {
        return _ERRNO_CRYPTO_KEY_OutRange;
    }

    return rtl_crypto_auth_init(pcrypto_adapter, type, key, keylen);
}

/**
 *  \fn          static inline rtl_crypto_auth_process(hal_crypto_adapter_t *pcrypto_adapter, uint32_t type,
                                                       IN const u8* message, IN const u32 msglen,
                                                       OUT u8* pDigest)
 *  \brief       Check input parameters which authentication Hash/HMAC needs,
 *               and make crypto engine run Hash/HMAC algorithm. After that, get the hash digest.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[in]   type Hash/HMAC type ID
 *  \param[in]   message Pointer to authentication message buffer
 *  \param[in]   msglen Authentication message buffer length
 *  \param[out]  pDigest Pointer to authentication digest buffer
 *  \return      value == 0     success
 *  \return      value < 0      fail(error code)
 */
__STATIC_INLINE
int rtl_crypto_auth_process(hal_crypto_adapter_t *pcrypto_adapter, uint32_t type,
                            IN const u8* message, IN const u32 msglen,
                            OUT u8* pDigest)
{
    int ret;
    const u8* pIV 	= NULL;
    const u32 ivlen = 0;
    const u32 a2eo 	= 0;

    if (pcrypto_adapter->isInit != _TRUE) {
        return _ERRNO_CRYPTO_ENGINE_NOT_INIT; // not init yet
    }
    if (pDigest == NULL) {
        return _ERRNO_CRYPTO_NULL_POINTER;
    }
    if ((pcrypto_adapter->auth_type & AUTH_TYPE_MASK_FUNC_ALL) != (type & AUTH_TYPE_MASK_FUNC_ALL)) {
        return _ERRNO_CRYPTO_AUTH_TYPE_NOT_MATCH;
    }
    if (message == NULL) {
        return _ERRNO_CRYPTO_NULL_POINTER;
    }
    if (msglen == 0) {
        return _ERRNO_CRYPTO_MSG_OutRange;
    }
    //if ( msglen > CRYPTO_MAX_MSG_LENGTH ) return _ERRNO_CRYPTO_MSG_OutRange;

    ret = __rtl_cryptoEngine(pcrypto_adapter, message, msglen, pIV, ivlen, NULL, a2eo, pDigest, NULL);
    if ( ret != SUCCESS ) return ret;

    rtl_cryptoEngine_get_result(pcrypto_adapter, pDigest, NULL, 0, NULL);
    return ret;
}

/**
 *  \fn          static inline rtl_crypto_send_seq_buf(hal_crypto_adapter_t *pcrypto_adapter, u8 *pDigest)
 *  \brief       A workaround for sequential hash to make sure crypto engine handle message buffer length as 64 bytes-aligned,
 *               except the last one is 16 bytes-aligned.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[out]  pDigest Pointer to authentication digest buffer
 *  \return      value == 0     success
 *  \return      value < 0      fail(error code)
 */
// Note:
// two buffers : last_message / seq_buf
//    last_message : store the previous message pointer
//    seq_buf : store the data less than 64
//
__STATIC_INLINE
int rtl_crypto_send_seq_buf(hal_crypto_adapter_t *pcrypto_adapter, u8 *pDigest)
{
    int ret = SUCCESS;
    const u8* pIV 	= NULL;
    const u32 ivlen = 0;
    const u32 a2eo 	= 0;
#if 0
    ret =  __rtl_cryptoEngine(pcrypto_adapter, pcrypto_adapter->hmac_seq_last_message, pcrypto_adapter->hmac_seq_last_msglen, pIV, ivlen, NULL, a2eo, pDigest, NULL);
#else
    int total_len  = pcrypto_adapter->hmac_seq_last_msglen;
    int buf_pos    = pcrypto_adapter->hmac_seq_buf_is_used_bytes;
    int rest_bytes = (64 - buf_pos);
    int bodylen, restlen;

    // There's an enough space of seq_buf for total_len
    if (total_len < rest_bytes) {
        rtlc_memcpy((void*)(&pcrypto_adapter->hmac_seq_buf[buf_pos]), (const void*)(pcrypto_adapter->hmac_seq_last_message), total_len);
        pcrypto_adapter->hmac_seq_buf_is_used_bytes += total_len;
    } else {
        /*********************************************************** 
         * send out all the hmac_seq_last_message or store into buf 
         ***********************************************************/
        // Make up seq_buf 
        rtlc_memcpy((void*)(&pcrypto_adapter->hmac_seq_buf[buf_pos]), (const void*)(pcrypto_adapter->hmac_seq_last_message), rest_bytes);
        ret = __rtl_cryptoEngine(pcrypto_adapter, (u8*)(pcrypto_adapter->hmac_seq_buf), 64, pIV, ivlen, NULL, a2eo, (total_len == rest_bytes)?pDigest:NULL, NULL);
        if (ret != SUCCESS) {
            return ret;
        }

        pcrypto_adapter->hmac_seq_buf_is_used_bytes = 0;
        buf_pos = 0;

        total_len -= rest_bytes;
        pcrypto_adapter->hmac_seq_last_msglen = total_len;
        pcrypto_adapter->hmac_seq_last_message += rest_bytes;

        // message(distinguish restlen[non_64bytes aligned] & bodylen[64bytes aligned])
        restlen = total_len & 0x3F;
        bodylen = total_len - restlen;
        if (bodylen > 0) { // there are 64x messages
            ret = __rtl_cryptoEngine(pcrypto_adapter, pcrypto_adapter->hmac_seq_last_message, bodylen, pIV, ivlen, NULL, a2eo, (restlen==0)?pDigest:NULL, NULL);
            if (ret != SUCCESS) {
                return ret;
            }
            pcrypto_adapter->hmac_seq_last_message += bodylen;
        }

        // backup the rest into seq_buf
        if (restlen > 0) {
            rtlc_memcpy((void*)(&pcrypto_adapter->hmac_seq_buf[0]), (const void*)(pcrypto_adapter->hmac_seq_last_message), restlen);
        }
        pcrypto_adapter->hmac_seq_buf_is_used_bytes = restlen;
    }

    if ((pDigest != NULL) &&
        (pcrypto_adapter->hmac_seq_buf_is_used_bytes > 0)) { // last one put into cryptoEngine, may need to pad 16bytes aligned msglen
        ret = __rtl_cryptoEngine(pcrypto_adapter, (u8*)(pcrypto_adapter->hmac_seq_buf), pcrypto_adapter->hmac_seq_buf_is_used_bytes, pIV, ivlen, NULL, a2eo, pDigest, NULL);
    }
#endif

    return ret;
}

/**
 *  \fn          static inline rtl_crypto_auth_update(hal_crypto_adapter_t *pcrypto_adapter, uint32_t type,
                                                      IN const u8* message, IN const u32 msglen)
 *  \brief       Check input parameters which authentication needs,and use a sequential buffer to help crypto engine 
 *               to pre-process authentication message buffer.After that, update related sequential hash data in crypto adapter.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[in]   type Hash/HMAC type ID
 *  \param[in]   message Pointer to authentication message buffer
 *  \param[in]   msglen Authentication message buffer length
 *  \return      value == 0     success
 *  \return      value < 0      fail(error code)
 */
__STATIC_INLINE
int rtl_crypto_auth_update(hal_crypto_adapter_t *pcrypto_adapter, uint32_t type,
                           IN const u8* message, IN const u32 msglen)
{
    int ret = SUCCESS;

    if (pcrypto_adapter->isInit != _TRUE) {
        return _ERRNO_CRYPTO_ENGINE_NOT_INIT; // not init yet
    }
    if (message == NULL) {
        return _ERRNO_CRYPTO_NULL_POINTER;
    }
    //if ( msglen > CRYPTO_MAX_MSG_LENGTH ) return _ERRNO_CRYPTO_MSG_OutRange;

    if ((pcrypto_adapter->auth_type & AUTH_TYPE_MASK_FUNC_ALL) != ( type & AUTH_TYPE_MASK_FUNC_ALL)) {
        return _ERRNO_CRYPTO_AUTH_TYPE_NOT_MATCH;
    }
    if (pcrypto_adapter->hmac_seq_is_recorded != 0) {
        ret = rtl_crypto_send_seq_buf(pcrypto_adapter, NULL);
        if (ret != SUCCESS) {
            return ret;
        }
    }
    pcrypto_adapter->hmac_seq_last_message = (u8*)message;
    pcrypto_adapter->hmac_seq_last_msglen  = msglen;
    pcrypto_adapter->hmac_seq_is_recorded  = 1;

    return ret;
}

/**
 *  \fn          static inline rtl_crypto_auth_final(hal_crypto_adapter_t *pcrypto_adapter, uint32_t type, OUT u8* pDigest)
 *  \brief       Check input parameters which authentication needs,and process authentication last message buffer. 
 *               After that, get the hash digest.
 *  \param[in]   pcrypto_adapter  Pointer to crypto adapter data
 *  \param[in]   type Hash/HMAC type ID
 *  \param[out]  pDigest Pointer to authentication digest buffer
 *  \return      value == 0     success
 *  \return      value < 0      fail(error code)
 */
__STATIC_INLINE
int rtl_crypto_auth_final(hal_crypto_adapter_t *pcrypto_adapter, uint32_t type,
                          OUT u8* pDigest)
{
    int ret = SUCCESS;;

    if (pcrypto_adapter->isInit != _TRUE) {
        return _ERRNO_CRYPTO_ENGINE_NOT_INIT; // not init yet
    }
    if ((pcrypto_adapter->auth_type & AUTH_TYPE_MASK_FUNC_ALL) != (type & AUTH_TYPE_MASK_FUNC_ALL)) {
        return _ERRNO_CRYPTO_AUTH_TYPE_NOT_MATCH;
    }
    if (pDigest == NULL) {
        return _ERRNO_CRYPTO_NULL_POINTER;
    }
    if (pcrypto_adapter->hmac_seq_is_recorded == 0) {
        return _ERRNO_CRYPTO_HASH_FINAL_NO_UPDATE;
    }

    {
        ret = rtl_crypto_send_seq_buf(pcrypto_adapter, pDigest);
        //ret =  __rtl_cryptoEngine(pcrypto_adapter, pcrypto_adapter->hmac_seq_last_message, pcrypto_adapter->hmac_seq_last_msglen, pIV, ivlen, NULL, a2eo, pDigest, NULL);
        if (ret != SUCCESS) {
            return ret;
        }
    }

    rtl_cryptoEngine_get_result(pcrypto_adapter, pDigest, NULL, 0, NULL);
    pcrypto_adapter->hmac_seq_is_recorded = 0;

    return ret;
}

//
// Authentication
//
//
/* Macros for Authentication functions in hp crypto module */
/**  \brief     rtl_crypto_auth_init_def is used to declare rtl_crypto_\#\#authtype\#\#_init\#\#postfix function.\n
 *              Use \em authtype and \em postfix to concatenate a function that for all crypto Hash algorithms,
 *              and call \ref rtl_crypto_auth_init(): Initialize crypto authentication algorithms.
 *   \details
 *              - authtype
 *                  - md5, sha1, sha2_224, sha2_256
 *              - postfix
 *                  - _s: secure, _ns: non-secure
 *   \note      Poly1305 isn't via this way to initialize.
 */
#define rtl_crypto_auth_init_def(authtype, postfix) \
int rtl_crypto_##authtype##_init##postfix(void) \
{ \
    const u8* pAuthKey 		= NULL; \
    const u32 lenAuthKey 	= 0; \
    hal_crypto_adapter_t *pcrypto_adapter = CRYPTO_ADAPTER; \
\
    if (pcrypto_adapter == NULL) { \
        return _ERRNO_CRYPTO_NULL_POINTER; \
    } \
    return rtl_crypto_auth_init(pcrypto_adapter, AUTH_TYPE_##authtype, pAuthKey, lenAuthKey); \
}

/**  \brief     rtl_crypto_hmac_auth_init_def is used to declare rtl_crypto_\#\#authtype\#\#_init\#\#postfix function.\n
 *              Use \em authtype and \em postfix to concatenate a function that for all crypto HMAC algorithms,
 *              and call \ref rtl_crypto_auth_hmac_init(): Initialize crypto HMAC algorithms .
 *   \details
 *              - authtype
 *                  - hmac_md5, hmac_sha1, hmac_sha2_224, hmac_sha2_256
 *              - postfix
 *                  - _s: secure, _ns: non-secure
 */
#define rtl_crypto_hmac_auth_init_def(authtype, postfix) \
int rtl_crypto_##authtype##_init##postfix(const u8* key, const u32 keylen) \
{ \
    hal_crypto_adapter_t *pcrypto_adapter = CRYPTO_ADAPTER; \
\
    if (pcrypto_adapter == NULL) { \
        return _ERRNO_CRYPTO_NULL_POINTER; \
    } \
    return rtl_crypto_auth_hmac_init(pcrypto_adapter, AUTH_TYPE_##authtype, key, keylen); \
}

/**  \brief     rtl_crypto_auth_process_def is used to declare rtl_crypto_\#\#authtype\#\#_process\#\#postfix function.\n
 *              Use \em authtype and \em postfix to concatenate a function that for all crypto Hash/HMAC algorithms,
 *              and call \ref rtl_crypto_auth_process(): Initialize crypto Hash/HMAC algorithms.
 *   \details
 *              - authtype
 *                  - md5, sha1, sha2_224, sha2_256, hmac_md5, hmac_sha1, hmac_sha2_224, hmac_sha2_256
 *              - postfix
 *                  - _s: secure, _ns: non-secure
 *   \note      Poly1305 isn't via this way to process.
 */
#define rtl_crypto_auth_process_def(authtype, postfix) \
int rtl_crypto_##authtype##_process##postfix( \
    IN const u8* message, IN const u32 msglen, \
    OUT u8* pDigest) \
{ \
    hal_crypto_adapter_t *pcrypto_adapter = CRYPTO_ADAPTER; \
\
    if (pcrypto_adapter == NULL) { \
        return _ERRNO_CRYPTO_NULL_POINTER; \
    } \
    return rtl_crypto_auth_process(pcrypto_adapter, AUTH_TYPE_##authtype, message, msglen, pDigest); \
}

/**  \brief     rtl_crypto_auth_update_def is used to declare rtl_crypto_\#\#authtype\#\#_update\#\#postfix function.\n
 *              Use \em authtype and \em postfix to concatenate a function that for all crypto Hash/HMAC algorithms,
 *              and call \ref rtl_crypto_auth_update(): Initialize crypto Hash/HMAC algorithms.
 *   \details
 *              - authtype
 *                  - md5, sha1, sha2_224, sha2_256, hmac_md5, hmac_sha1, hmac_sha2_224, hmac_sha2_256
 *              - postfix
 *                  - _s: secure, _ns: non-secure
 *   \note      Poly1305 isn't via this way to process.          
 */
#define rtl_crypto_auth_update_def(authtype, postfix) \
int rtl_crypto_##authtype##_update##postfix( \
    IN const u8* message, IN const u32 msglen) \
{ \
    hal_crypto_adapter_t *pcrypto_adapter = CRYPTO_ADAPTER; \
\
    if (pcrypto_adapter == NULL) { \
        return _ERRNO_CRYPTO_NULL_POINTER; \
    } \
    return rtl_crypto_auth_update(pcrypto_adapter, AUTH_TYPE_##authtype, message, msglen); \
}

/**  \brief     rtl_crypto_auth_final_def is used to declare rtl_crypto_\#\#authtype\#\#_final\#\#postfix function.\n
 *              Use \em authtype and \em postfix to concatenate a function that for all crypto Hash/HMAC algorithms,
 *              and call \ref rtl_crypto_auth_final(): Initialize crypto Hash/HMAC algorithms.
 *   \details
 *              - authtype
 *                  - md5, sha1, sha2_224, sha2_256, hmac_md5, hmac_sha1, hmac_sha2_224, hmac_sha2_256
 *              - postfix
 *                  - _s: secure, _ns: non-secure
 *   \note      Poly1305 isn't via this way to process.          
 */
#define rtl_crypto_auth_final_def(authtype, postfix) \
int rtl_crypto_##authtype##_final##postfix( \
    OUT u8* pDigest) \
{ \
    hal_crypto_adapter_t *pcrypto_adapter = CRYPTO_ADAPTER; \
\
    if (pcrypto_adapter == NULL) { \
        return _ERRNO_CRYPTO_NULL_POINTER; \
    } \
    return rtl_crypto_auth_final(pcrypto_adapter, AUTH_TYPE_##authtype, pDigest); \
}

/**  \brief     rtl_crypto_auth_funcs_def is used to call 4 kinds of macro functions for crypto Hash algorithms.
 *   \details
 *              - authtype
 *                  - md5, sha1, sha2_224, sha2_256
 *              - postfix
 *                  - _s: secure, _ns: non-secure
 */
#define rtl_crypto_auth_funcs_def(authtype, postfix) \
rtl_crypto_auth_init_def(authtype, postfix) \
rtl_crypto_auth_process_def(authtype, postfix) \
rtl_crypto_auth_update_def(authtype, postfix) \
rtl_crypto_auth_final_def(authtype, postfix)

/**  \brief     rtl_crypto_auth_funcs_def is used to call 4 kinds of macro functions for crypto HMAC algorithms.
 *   \details
 *              - authtype
 *                  - hmac_md5, hmac_sha1, hmac_sha2_224, hmac_sha2_256
 *              - postfix
 *                  - _s: secure, _ns: non-secure
 */
#define rtl_crypto_hmac_auth_funcs_def(authtype, postfix) \
rtl_crypto_hmac_auth_init_def(authtype, postfix) \
rtl_crypto_auth_process_def(authtype, postfix) \
rtl_crypto_auth_update_def(authtype, postfix) \
rtl_crypto_auth_final_def(authtype, postfix)
    
/**
 *  \fn          static inline int rtl_crypto_cipher_init(IN const uint32_t cipher_type, IN const u8* key, IN const u32 keylen)
 *  \brief       Check input parameters which cipher needs, and set related cipher initial values to crypto adapter.
 *  \param[in]   cipher_type  Cipher type ID
 *  \param[in]   key Pointer to crypto cipher key buffer
 *  \param[in]   keylen Cipher key buffer length
 *  \return      value == 0     success
 *  \return      value < 0      fail(error code)
 */
__STATIC_INLINE
int rtl_crypto_cipher_init(
    IN const uint32_t cipher_type, IN const u8* key, IN const u32 keylen)
{
    int ret;
    hal_crypto_adapter_t *pcrypto_adapter = CRYPTO_ADAPTER;
    if (pcrypto_adapter == NULL) {
        return _ERRNO_CRYPTO_NULL_POINTER;
    }
    if (pcrypto_adapter->isInit != _TRUE) {
        return _ERRNO_CRYPTO_ENGINE_NOT_INIT; // not init yet
    }
    if (key == NULL) {
        return _ERRNO_CRYPTO_NULL_POINTER;
    }
    if ((u32)(key) & 0x1f) {
        return _ERRNO_CRYPTO_ADDR_NOT_32Byte_Aligned; // need to be 4-byte alignment
    }
    //if ( (keylen != 128/8) && (keylen != 192/8) && (keylen != 256/8) ) return _ERRNO_CRYPTO_KEY_OutRange;
    ret = __rtl_crypto_cipher_init(pcrypto_adapter, cipher_type, key, keylen);

    return ret;
}

//static u8 gcm_iv[16];
//static u8 gcm_iv_tail[]= {0x00, 0x00, 0x00, 0x01};

/**
 *  \fn          static inline int rtl_crypto_cipher_process(IN const uint8_t isEncrypt, IN const uint32_t cipher_type,
                                                             IN const u8 *message, 	IN const u32 msglen,
                                                             IN const u8 *iv, 		IN const u32 ivlen,
                                                             IN const u8 *aad,		IN const u32 aadlen,
                                                             OUT u8* pResult,
                                                             OUT u8 *pTag)
 *  \brief       Check input parameters which cipher needs, and make crypto engine encrypt the plaintext or decrypt the ciphertext.
 *               After that, get the cipher result.
 *  \param[in]   isEncrypt Indicate that crypto engine now is processing encryption or decryption
 *  \param[in]   cipher_type  Cipher type ID
 *  \param[in]   message Pointer to Crypto cipher message data
 *  \param[in]   msglen Crypto cipher message data length
 *  \param[in]   iv Pointer to Crypto cipher initial vector data
 *  \param[in]   ivlen Crypto cipher initial vector data length
 *  \param[in]   aad Pointer to Crypto cipher additional authentication data
 *  \param[in]   aadlen Crypto cipher additional authentication data length
 *  \param[out]  pResult Pointer to Crypto cipher result data
 *  \param[out]  pTag Pointer to Crypto cipher Tag data
 *  \return      value == 0     success
 *  \return      value < 0      fail(error code)
 */
__STATIC_INLINE
int rtl_crypto_cipher_process(
    IN const uint8_t isEncrypt, IN const uint32_t cipher_type,
    IN const u8 *message, 	IN const u32 msglen,
    IN const u8 *iv, 		IN const u32 ivlen,
    IN const u8 *aad,		IN const u32 aadlen,
    OUT u8* pResult,
    OUT u8 *pTag)
{
    hal_crypto_adapter_t *pcrypto_adapter = CRYPTO_ADAPTER;
    int ret;
    u32 count_be;
    u8  count_str[4];

    if (pcrypto_adapter == NULL) {
        return _ERRNO_CRYPTO_NULL_POINTER;
    }
    if ((u32)(iv) & 0x1f) {
        return _ERRNO_CRYPTO_ADDR_NOT_32Byte_Aligned;
    }
    if ((u32)(aad) & 0x1f) {
        return _ERRNO_CRYPTO_ADDR_NOT_32Byte_Aligned;
    }

    do {
        if (pcrypto_adapter->isInit != _TRUE) {
            ret = _ERRNO_CRYPTO_ENGINE_NOT_INIT; // not init yet
            break;
        }

        if (message == NULL) {
            DBG_CRYPTO_ERR("message is null pointer\r\n");
            ret = _ERRNO_CRYPTO_NULL_POINTER;
            break;
        }

        //if ( (msglen % 16) != 0 ) {
        //    ret =  _ERRNO_CRYPTO_AES_MSGLEN_NOT_16Byte_Aligned;
        //    break;
        //}

        // DES,3DES
        if ((CIPHER_TYPE_FUNC_DES == (cipher_type & CIPHER_TYPE_MASK_FUNC)) || 
            (CIPHER_TYPE_FUNC_3DES == (cipher_type & CIPHER_TYPE_MASK_FUNC))) {

            DBG_CRYPTO_INFO("msglen non_8_aligned %d bytes\r\n",(msglen % 8));
            if (((msglen % 8) != 0) && (!isEncrypt)) {
                ret = _ERRNO_CRYPTO_DES_MSGLEN_NOT_8Byte_Aligned;
                break;
            }
        } else if ((CIPHER_TYPE_FUNC_AES == (cipher_type & CIPHER_TYPE_MASK_FUNC)) || 
                   (CIPHER_TYPE_FUNC_CHACHA_POLY1305 == (cipher_type & 0x33)) || 
                   (CIPHER_TYPE_FUNC_CHACHA20 == (cipher_type & 0x33))) { //AES,Chacha(except poly1305)

            DBG_CRYPTO_INFO("msglen non_16_aligned %d bytes\r\n",(msglen % 16));
            if (((msglen % 16) != 0) && (!isEncrypt)) {
                ret = _ERRNO_CRYPTO_AES_MSGLEN_NOT_16Byte_Aligned;
                break;
            }
        }

        if (cipher_type == CIPHER_TYPE_POLY1305) {
            if (pTag == NULL) {
                ret = _ERRNO_CRYPTO_NULL_POINTER;
                break;
            }
        } else {
            if (pResult == NULL) {
                DBG_CRYPTO_ERR("pResult is null pointer\r\n");
                ret = _ERRNO_CRYPTO_NULL_POINTER;
                break;
            }
            if (cipher_type == CIPHER_TYPE_CHACHA_POLY1305) {
                if (pTag == NULL) {
                    ret = _ERRNO_CRYPTO_NULL_POINTER;
                    break;
                }
            }
        }

        if (cipher_type == CIPHER_TYPE_AES_GCM) {
            rtlc_memcpy((void*)(pcrypto_adapter->gcm_iv), (const void*)(iv), 96/8);
            rtlc_memcpy((void*)(&(pcrypto_adapter->gcm_iv)[12]), (const void*)(gcm_iv_tail), 4);

            if (isEncrypt) {
                ret = __rtl_crypto_cipher_encrypt(pcrypto_adapter, message, msglen, (u8*)(pcrypto_adapter->gcm_iv), 16, aad, aadlen, pResult, pTag);
            } else {
                ret = __rtl_crypto_cipher_decrypt(pcrypto_adapter, message, msglen, (u8*)(pcrypto_adapter->gcm_iv), 16, aad, aadlen, pResult, pTag);
            }
        } else if (cipher_type == CIPHER_TYPE_CHACHA) {
            count_be = ivlen;
            __rtl_cpu_to_be32(count_be);
            rtlc_memcpy((void*)count_str, (const void*)(&count_be), sizeof(u32));
            rtlc_memcpy((void*)(&(pcrypto_adapter->gcm_iv)[0]), count_str, 4);
            rtlc_memcpy((void*)(&(pcrypto_adapter->gcm_iv)[4]), iv, 96/8);

            if (isEncrypt) {
                ret = __rtl_crypto_cipher_encrypt(pcrypto_adapter, message, msglen, (u8*)(pcrypto_adapter->gcm_iv), 16, NULL, 0, pResult, NULL);
            } else {
                ret = __rtl_crypto_cipher_decrypt(pcrypto_adapter, message, msglen, (u8*)(pcrypto_adapter->gcm_iv), 16, NULL, 0, pResult, NULL);
            }
        } else if (cipher_type == CIPHER_TYPE_CHACHA_POLY1305) {
            count_be = 1;
            __rtl_cpu_to_be32(count_be);
            rtlc_memcpy((void*)count_str, (const void*)(&count_be), sizeof(u32));
            rtlc_memcpy((void*)(&(pcrypto_adapter->gcm_iv)[0]), count_str, 4);
            rtlc_memcpy((void*)(&(pcrypto_adapter->gcm_iv)[4]), iv, 96/8);

            if (isEncrypt) {
                ret = __rtl_crypto_cipher_encrypt(pcrypto_adapter, message, msglen, (u8*)(pcrypto_adapter->gcm_iv), 16, aad, aadlen, pResult, pTag);
            } else {
                ret = __rtl_crypto_cipher_decrypt(pcrypto_adapter, message, msglen, (u8*)(pcrypto_adapter->gcm_iv), 16, aad, aadlen, pResult, pTag);
            }
        } else {
            if (isEncrypt) {
                ret = __rtl_crypto_cipher_encrypt(pcrypto_adapter, message, msglen, iv, ivlen, NULL, 0, pResult, pTag);
            } else {
                ret = __rtl_crypto_cipher_decrypt(pcrypto_adapter, message, msglen, iv, ivlen, NULL, 0, pResult, pTag);
            }
        }

        if (isEncrypt) {
            //Encryption may need to modify msglen of destination descriptor,because of padding length
            rtl_cryptoEngine_get_result(pcrypto_adapter, NULL, pResult, (msglen + (pcrypto_adapter->apl)), pTag);
        } else {
            rtl_cryptoEngine_get_result(pcrypto_adapter, NULL, pResult, msglen, pTag);
        }
    } while (0);

    return ret;
}



/* Macros for Cipher functions in hp crypto module */
/**  \brief     rtl_crypto_cipher_init_def is used to declare rtl_crypto_\#\#cipher_func\#\#_init\#\#postfix function.\n
 *              Use \em cipher_func and \em postfix to concatenate a function that for all crypto Cipher algorithms,
 *              and call \ref rtl_crypto_cipher_init(): Initialize crypto cipher algorithms.
 *   \details    
 *              - cipher_func:
 *                  - des_ecb, des_cbc, 3des_ecb, 3des_cbc, aes_ecb, aes_cbc, aes_ctr, aes_cfb, aes_ofb, aes_gcm
 *              - postfix:
 *                  - _s, _ns
 *   \note      Poly1305, Chacha20, Chacha_poly1305 aren't via this way to declare.
 */
#define rtl_crypto_cipher_init_def(cipher_func, postfix) \
int rtl_crypto_##cipher_func##_init##postfix( \
    IN const u8* key, IN const u32 keylen) \
{ \
    return rtl_crypto_cipher_init(CIPHER_TYPE_##cipher_func, key, keylen); \
}

/**  \brief     rtl_crypto_cipher_process_def is used to declare rtl_crypto_\#\#cipher_func\#\#cipher_type\#\#postfix function.\n
 *              Use \em cipher_func , \em cipher_type, and \em postfix to concatenate a function that for all crypto Cipher algorithms,
 *              and call \ref rtl_crypto_cipher_process(): Process crypto cipher algorithms.
 *   \details    
 *              - cipher_func:
 *                  - des_ecb, des_cbc, 3des_ecb, 3des_cbc, aes_ecb, aes_cbc, aes_ctr, aes_cfb, aes_ofb
 *              - cipher_type:
 *                  - _encrypt, _decrypt
 *              - postfix:
 *                  - _s, _ns
 *   \note      AES_GCM, Poly1305, Chacha20, Chacha_poly1305 aren't via this way to declare.
 */
#define rtl_crypto_cipher_process_def(cipher_func, cipher_type, postfix) \
int rtl_crypto_##cipher_func##cipher_type##postfix( \
    IN const u8* message, 	IN const u32 msglen, \
    IN const u8* iv, 		IN const u32 ivlen, \
    OUT u8* pResult) \
{ \
    return rtl_crypto_cipher_process(TYPE##cipher_type, CIPHER_TYPE_##cipher_func, \
        message, msglen, iv, ivlen, NULL, 0, pResult, NULL); \
}

/**  \brief     rtl_crypto_cipher_process_def1 is used to declare rtl_crypto_\#\#cipher_func\#\#cipher_type\#\#postfix function.\n
 *              Use \em cipher_func , \em cipher_type, and \em postfix to concatenate a function that for AES_GCM
 *              and call \ref rtl_crypto_cipher_process(): Process AES_GCM .
 *   \details    
 *              - cipher_func:
 *                  - aes_gcm
 *              - cipher_type:
 *                  - _encrypt, _decrypt
 *              - postfix:
 *                  - _s, _ns
 *   \note      Except AES_GCM ,other crypto cipher algorithms aren't via this way to declare.
 */
#define rtl_crypto_cipher_process_def1(cipher_func, cipher_type, postfix) \
int rtl_crypto_##cipher_func##cipher_type##postfix( \
    IN const u8 *message, 	IN const u32 msglen, \
    IN const u8 *iv, 		\
    IN const u8 *aad,		IN const u32 aadlen, \
    OUT u8 *pResult, OUT u8 *pTag) \
{ \
    return rtl_crypto_cipher_process(TYPE##cipher_type, CIPHER_TYPE_##cipher_func, \
        message, msglen, iv, 0, aad, aadlen, pResult, pTag); \
}

/**  \brief     rtl_crypto_cipher_func_def is used to call 3 kinds of macro functions for crypto Cipher algorithms.
 *   \details
 *              - cipher_func
 *                  - des_ecb, des_cbc, 3des_ecb, 3des_cbc, aes_ecb, aes_cbc, aes_ctr, aes_cfb, aes_ofb
 *              - postfix
 *                  - _s: secure, _ns: non-secure
 */
#define rtl_crypto_cipher_func_def(cipher_func, postfix) \
rtl_crypto_cipher_init_def(cipher_func, postfix) \
rtl_crypto_cipher_process_def(cipher_func, _encrypt, postfix) \
rtl_crypto_cipher_process_def(cipher_func, _decrypt, postfix)

/**  \brief     rtl_crypto_cipher_func_def is used to call 3 kinds of macro functions for AES_GCM algorithms.
 *   \details
 *              - cipher_func
 *                  - aes_gcm
 *              - postfix
 *                  - _s: secure, _ns: non-secure
 */
#define rtl_crypto_cipher_func_def1(cipher_func, postfix) \
rtl_crypto_cipher_init_def(cipher_func, postfix) \
rtl_crypto_cipher_process_def1(cipher_func, _encrypt, postfix) \
rtl_crypto_cipher_process_def1(cipher_func, _decrypt, postfix)
    
/* Macros for hp crypto module cipher type configuration */
/// Crypto cipher encrypt self-define index
#define TYPE_encrypt 1
/// Crypto cipher decrypt self-define index
#define TYPE_decrypt 0

// Change some lowercase letters to capital letters
#define CIPHER_TYPE_des_cbc CIPHER_TYPE_DES_CBC
#define CIPHER_TYPE_des_ecb CIPHER_TYPE_DES_ECB
#define CIPHER_TYPE_3des_cbc CIPHER_TYPE_3DES_CBC
#define CIPHER_TYPE_3des_ecb CIPHER_TYPE_3DES_ECB
#define CIPHER_TYPE_aes_cbc CIPHER_TYPE_AES_CBC
#define CIPHER_TYPE_aes_ecb CIPHER_TYPE_AES_ECB
#define CIPHER_TYPE_aes_ctr CIPHER_TYPE_AES_CTR
#define CIPHER_TYPE_aes_cfb CIPHER_TYPE_AES_CFB
#define CIPHER_TYPE_aes_ofb CIPHER_TYPE_AES_OFB
#define CIPHER_TYPE_aes_gcm CIPHER_TYPE_AES_GCM

/* Macros for Authentication functions in hp crypto module */
/**  \brief     rtl_crypto_auth_def is used to declare rtl_crypto_\#\#authtype\#\#postfix function.\n
 *              Use \em authtype and \em postfix to concatenate a function that for all crypto Hash algorithms,
 *              and call Initialize and Process macro functions.
 *   \note      Poly1305 isn't via this way to initialize.
 */
#define rtl_crypto_auth_def(authtype, postfix) \
int rtl_crypto_##authtype##postfix(IN const u8* message, IN const u32 msglen, OUT u8* pDigest) \
{ \
    int ret; \
\
    do { \
        ret = rtl_crypto_##authtype##_init##postfix(); \
        if ( ret != SUCCESS ) break; \
\
        ret = rtl_crypto_##authtype##_process##postfix(message, msglen, pDigest); \
    } while (0); \
\
    return ret;\
}

/**  \brief     rtl_crypto_hmac_auth_def is used to declare rtl_crypto_\#\#authtype\#\#postfix function.\n
 *              Use \em authtype and \em postfix to concatenate a function that for all crypto HMAC algorithms,
 *              and call Initialize and Process macro functions.
 */
#define rtl_crypto_hmac_auth_def(authtype, postfix) \
int rtl_crypto_##authtype##postfix( \
IN const u8* message, IN const u32 msglen, \
IN const u8* key, IN const u32 keylen, \
OUT u8* pDigest) \
{ \
    int ret; \
\
    do { \
        ret = rtl_crypto_##authtype##_init##postfix(key, keylen); \
        if ( ret != SUCCESS ) break; \
\
        ret = rtl_crypto_##authtype##_process##postfix(message, msglen, pDigest); \
    } while (0); \
\
    return ret;\
}
/** @} */ /* End of group hs_hal_crypto_rom_func */
/// @endcond
/** @} */ /* End of group hs_hal_crypto */

