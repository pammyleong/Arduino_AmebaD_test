#ifndef __ROM_SSL_PARSE_H_
#define __ROM_SSL_PARSE_H_

#include <basic_types.h>
#include <drv_types.h>
#include <rtl_math_types.h>

#include "ed25519/rom_homekit_ed25519.h"
#include "ed25519/core/rom_homekit_ed25519_ge.h"
#include "poly1305/rom_homekit_poly1305.h"
#include "sha512/rom_homekit_sha512.h"
#include "rom_wac_aesopt.h"




extern int rom_hmac_sha256_vector_A(const u8 *key, size_t key_len, size_t num_elem,
		       const u8 *addr[], const size_t *len, u8 *mac);
extern int rom_hmac_sha256_vector_B(const u8 *key, size_t key_len, size_t num_elem,
		       const u8 *addr[], const size_t *len, u8 *mac);

extern int rom_hmac_sha256_A(const u8 *key, size_t key_len, const u8 *data,
		size_t data_len, u8 *mac);
extern int rom_hmac_sha256_B(const u8 *key, size_t key_len, const u8 *data,
		size_t data_len, u8 *mac);

extern int rom_sha256_vector_A(size_t num_elem, const u8 *addr[], const size_t *len,
		  u8 *mac);
extern int rom_sha256_vector_B(size_t num_elem, const u8 *addr[], const size_t *len,
		  u8 *mac);

extern void CRYPTO_chacha_20_A(unsigned char *out,
		      const unsigned char *in, size_t in_len,
		      const unsigned char key[32],
		      const unsigned char nonce[8],
		      size_t counter);
extern void CRYPTO_chacha_20_B(unsigned char *out,
		      const unsigned char *in, size_t in_len,
		      const unsigned char key[32],
		      const unsigned char nonce[8],
		      size_t counter);

extern int rom_ed25519_gen_keypair_A(unsigned char pk[ED25519_PUBKEY_LEN],
                            unsigned char skpk[ED25519_SKEY_LEN + ED25519_PUBKEY_LEN], 
                            unsigned char seed[ED25519_SKEY_LEN]);
extern int rom_ed25519_gen_keypair_B(unsigned char pk[ED25519_PUBKEY_LEN],
                            unsigned char skpk[ED25519_SKEY_LEN + ED25519_PUBKEY_LEN], 
                            unsigned char seed[ED25519_SKEY_LEN]);

extern int rom_ed25519_gen_signature_A(unsigned char sig[ED25519_SIG_SIZE],
                              const unsigned char *m, unsigned long long mlen,
                              const unsigned char skpk[ED25519_SKEY_LEN + ED25519_PUBKEY_LEN]);
extern int rom_ed25519_gen_signature_B(unsigned char sig[ED25519_SIG_SIZE],
                              const unsigned char *m, unsigned long long mlen,
                              const unsigned char skpk[ED25519_SKEY_LEN + ED25519_PUBKEY_LEN]);

extern int rom_ed25519_verify_signature_A(const unsigned char sig[],
                                 const unsigned char *m, unsigned long long mlen,
                                 const unsigned char pk[]);
extern int rom_ed25519_verify_signature_B(const unsigned char sig[],
                                 const unsigned char *m, unsigned long long mlen,
                                 const unsigned char pk[]);

extern void rom_ed25519_ge_double_scalarmult_vartime_A(ge_p2 *r,const unsigned char *a,const ge_p3 *A,const unsigned char *b);
extern void rom_ed25519_ge_double_scalarmult_vartime_B(ge_p2 *r,const unsigned char *a,const ge_p3 *A,const unsigned char *b);

extern int rom_ed25519_ge_frombytes_negate_vartime_A(ge_p3 *h,const unsigned char *s);
extern int rom_ed25519_ge_frombytes_negate_vartime_B(ge_p3 *h,const unsigned char *s);

extern void rom_ed25519_ge_p3_tobytes_A(unsigned char *s,const ge_p3 *h);
extern void rom_ed25519_ge_p3_tobytes_B(unsigned char *s,const ge_p3 *h);

extern void rom_ed25519_ge_scalarmult_base_A(ge_p3 *h,const unsigned char *a);
extern void rom_ed25519_ge_scalarmult_base_B(ge_p3 *h,const unsigned char *a);

extern void rom_ed25519_ge_tobytes_A(unsigned char *s,const ge_p2 *h);
extern void rom_ed25519_ge_tobytes_B(unsigned char *s,const ge_p2 *h);

extern int rom_ed25519_crypto_sign_seed_keypair_A(unsigned char *pk, unsigned char *sk,
                                         const unsigned char *seed);
extern int rom_ed25519_crypto_sign_seed_keypair_B(unsigned char *pk, unsigned char *sk,
                                         const unsigned char *seed);

extern int rom_ed25519_crypto_sign_verify_detached_A(const unsigned char *sig, const unsigned char *m,
                                        unsigned long long mlen, const unsigned char *pk);
extern int rom_ed25519_crypto_sign_verify_detached_B(const unsigned char *sig, const unsigned char *m,
                                        unsigned long long mlen, const unsigned char *pk);

extern void rom_ed25519_sc_muladd_A(unsigned char *s,const unsigned char *a,const unsigned char *b,const unsigned char *c);
extern void rom_ed25519_sc_muladd_B(unsigned char *s,const unsigned char *a,const unsigned char *b,const unsigned char *c);

extern void rom_ed25519_sc_reduce_A(unsigned char *s);
extern void rom_ed25519_sc_reduce_B(unsigned char *s);

extern int rom_ed25519_crypto_sign_detached_A(unsigned char *sig, unsigned long long *siglen,
                                 const unsigned char *m, unsigned long long mlen,
                                 const unsigned char *sk);
extern int rom_ed25519_crypto_sign_detached_B(unsigned char *sig, unsigned long long *siglen,
                                 const unsigned char *m, unsigned long long mlen,
                                 const unsigned char *sk);

extern void CRYPTO_poly1305_init_A(poly1305_state *state, const unsigned char key[32]);
extern void CRYPTO_poly1305_init_B(poly1305_state *state, const unsigned char key[32]);

extern void CRYPTO_poly1305_update_A(poly1305_state *state, const unsigned char *in,
		     size_t in_len);
extern void CRYPTO_poly1305_update_B(poly1305_state *state, const unsigned char *in,
		     size_t in_len);

extern void CRYPTO_poly1305_finish_A(poly1305_state *state, unsigned char mac[16]);
extern void CRYPTO_poly1305_finish_B(poly1305_state *state, unsigned char mac[16]);

extern void rom_sha512_starts_A( sha512_context *ctx, int is384 );
extern void rom_sha512_starts_B( sha512_context *ctx, int is384 );

extern void rom_sha512_update_A( sha512_context *ctx, const unsigned char *input, size_t ilen );
extern void rom_sha512_update_B( sha512_context *ctx, const unsigned char *input, size_t ilen );

extern void rom_sha512_finish_A( sha512_context *ctx, unsigned char output[64] );
extern void rom_sha512_finish_B( sha512_context *ctx, unsigned char output[64] );

extern void rom_sha512_A( const unsigned char *input, size_t ilen,
                 unsigned char output[64], int is384 );
extern void rom_sha512_B( const unsigned char *input, size_t ilen,
                 unsigned char output[64], int is384 );

extern void rom_sha512_hmac_starts_A( sha512_context *ctx, const unsigned char *key,
                             size_t keylen, int is384 );
extern void rom_sha512_hmac_starts_B( sha512_context *ctx, const unsigned char *key,
                             size_t keylen, int is384 );

extern void rom_sha512_hmac_update_A( sha512_context  *ctx,
                             const unsigned char *input, size_t ilen );
extern void rom_sha512_hmac_update_B( sha512_context  *ctx,
                             const unsigned char *input, size_t ilen );

extern void rom_sha512_hmac_finish_A( sha512_context *ctx, unsigned char output[64] );
extern void rom_sha512_hmac_finish_B( sha512_context *ctx, unsigned char output[64] );

extern void rom_sha512_hmac_reset_A( sha512_context *ctx );
extern void rom_sha512_hmac_reset_B( sha512_context *ctx );

extern void rom_sha512_hmac_A( const unsigned char *key, size_t keylen,
                      const unsigned char *input, size_t ilen,
                      unsigned char output[64], int is384 );
extern void rom_sha512_hmac_B( const unsigned char *key, size_t keylen,
                      const unsigned char *input, size_t ilen,
                      unsigned char output[64], int is384 );

extern int rom_sha512_hkdf_A(const unsigned char *ikm, size_t ikm_len,
                    const unsigned char *salt, size_t salt_len,
                    const unsigned char *info, size_t info_len,
                    unsigned char *okm, size_t okm_len);
extern int rom_sha512_hkdf_B(const unsigned char *ikm, size_t ikm_len,
                    const unsigned char *salt, size_t salt_len,
                    const unsigned char *info, size_t info_len,
                    unsigned char *okm, size_t okm_len);

extern AES_RETURN aes_test_alignment_detection_A(unsigned int n);
extern AES_RETURN aes_test_alignment_detection_B(unsigned int n);

extern AES_RETURN aes_mode_reset_A(aes_encrypt_ctx ctx[1]);
extern AES_RETURN aes_mode_reset_B(aes_encrypt_ctx ctx[1]);

extern AES_RETURN aes_ecb_encrypt_A(const unsigned char *ibuf, unsigned char *obuf,
                    int len, const aes_encrypt_ctx ctx[1]);
extern AES_RETURN aes_ecb_encrypt_B(const unsigned char *ibuf, unsigned char *obuf,
                    int len, const aes_encrypt_ctx ctx[1]);

extern AES_RETURN aes_ecb_decrypt_A(const unsigned char *ibuf, unsigned char *obuf,
                    int len, const aes_decrypt_ctx ctx[1]);
extern AES_RETURN aes_ecb_decrypt_B(const unsigned char *ibuf, unsigned char *obuf,
                    int len, const aes_decrypt_ctx ctx[1]);

extern AES_RETURN aes_cbc_encrypt_A(const unsigned char *ibuf, unsigned char *obuf,
                    int len, unsigned char *iv, const aes_encrypt_ctx ctx[1]);
extern AES_RETURN aes_cbc_encrypt_B(const unsigned char *ibuf, unsigned char *obuf,
                    int len, unsigned char *iv, const aes_encrypt_ctx ctx[1]);

extern AES_RETURN aes_cbc_decrypt_A(const unsigned char *ibuf, unsigned char *obuf,
                    int len, unsigned char *iv, const aes_decrypt_ctx ctx[1]);
extern AES_RETURN aes_cbc_decrypt_B(const unsigned char *ibuf, unsigned char *obuf,
                    int len, unsigned char *iv, const aes_decrypt_ctx ctx[1]);

extern AES_RETURN aes_cfb_encrypt_A(const unsigned char *ibuf, unsigned char *obuf,
                    int len, unsigned char *iv, aes_encrypt_ctx ctx[1]);
extern AES_RETURN aes_cfb_encrypt_B(const unsigned char *ibuf, unsigned char *obuf,
                    int len, unsigned char *iv, aes_encrypt_ctx ctx[1]);

extern AES_RETURN aes_cfb_decrypt_A(const unsigned char *ibuf, unsigned char *obuf,
                    int len, unsigned char *iv, aes_encrypt_ctx ctx[1]);
extern AES_RETURN aes_cfb_decrypt_B(const unsigned char *ibuf, unsigned char *obuf,
                    int len, unsigned char *iv, aes_encrypt_ctx ctx[1]);

extern AES_RETURN aes_ofb_crypt_A(const unsigned char *ibuf, unsigned char *obuf,
                    int len, unsigned char *iv, aes_encrypt_ctx ctx[1]);
extern AES_RETURN aes_ofb_crypt_B(const unsigned char *ibuf, unsigned char *obuf,
                    int len, unsigned char *iv, aes_encrypt_ctx ctx[1]);

extern AES_RETURN aes_ctr_crypt_A(const unsigned char *ibuf, unsigned char *obuf,
            int len, unsigned char *cbuf, cbuf_inc ctr_inc, aes_encrypt_ctx ctx[1]);
extern AES_RETURN aes_ctr_crypt_B(const unsigned char *ibuf, unsigned char *obuf,
            int len, unsigned char *cbuf, cbuf_inc ctr_inc, aes_encrypt_ctx ctx[1]);

extern AES_RETURN aes_encrypt_key128_A(const unsigned char *key, aes_encrypt_ctx cx[1]);
extern AES_RETURN aes_encrypt_key128_B(const unsigned char *key, aes_encrypt_ctx cx[1]);

extern AES_RETURN aes_encrypt_key192_A(const unsigned char *key, aes_encrypt_ctx cx[1]);
extern AES_RETURN aes_encrypt_key192_B(const unsigned char *key, aes_encrypt_ctx cx[1]);

extern AES_RETURN aes_encrypt_key256_A(const unsigned char *key, aes_encrypt_ctx cx[1]);
extern AES_RETURN aes_encrypt_key256_B(const unsigned char *key, aes_encrypt_ctx cx[1]);

extern AES_RETURN aes_encrypt_key_A(const unsigned char *key, int key_len, aes_encrypt_ctx cx[1]);
extern AES_RETURN aes_encrypt_key_B(const unsigned char *key, int key_len, aes_encrypt_ctx cx[1]);

extern AES_RETURN aes_decrypt_key128_A(const unsigned char *key, aes_decrypt_ctx cx[1]);
extern AES_RETURN aes_decrypt_key128_B(const unsigned char *key, aes_decrypt_ctx cx[1]);

extern AES_RETURN aes_decrypt_key192_A(const unsigned char *key, aes_decrypt_ctx cx[1]);
extern AES_RETURN aes_decrypt_key192_B(const unsigned char *key, aes_decrypt_ctx cx[1]);

extern AES_RETURN aes_decrypt_key256_A(const unsigned char *key, aes_decrypt_ctx cx[1]);
extern AES_RETURN aes_decrypt_key256_B(const unsigned char *key, aes_decrypt_ctx cx[1]);

extern AES_RETURN aes_decrypt_key_A(const unsigned char *key, int key_len, aes_decrypt_ctx cx[1]);
extern AES_RETURN aes_decrypt_key_B(const unsigned char *key, int key_len, aes_decrypt_ctx cx[1]);

extern AES_RETURN aes_init_A(void);
extern AES_RETURN aes_init_B(void);

extern void curve25519_donna_A(u8 *mypublic, const u8 *secret, const u8 *basepoint);
extern void curve25519_donna_B(u8 *mypublic, const u8 *secret, const u8 *basepoint);


#endif
