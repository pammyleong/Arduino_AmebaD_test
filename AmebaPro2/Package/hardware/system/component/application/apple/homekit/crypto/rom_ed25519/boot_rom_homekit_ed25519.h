#ifndef _BOOT_ROM_HOMEKIT_ED25519_H_
#define _BOOT_ROM_HOMEKIT_ED25519_H_

#define ED25519_SKEY_LEN      32
#define ED25519_PUBKEY_LEN    32
#define ED25519_SIG_SIZE      64

int boot_rom_ed25519_verify_signature(const unsigned char sig[ED25519_SIG_SIZE],
                                 const unsigned char *m, unsigned long long mlen,
                                 const unsigned char pk[ED25519_PUBKEY_LEN]);

/* internal */
int boot_rom_ed25519_crypto_sign_verify_detached(const unsigned char *sig, const unsigned char *m,
										 unsigned long long mlen, const unsigned char *pk);

#endif	/* _ROM_HOMEKIT_ED25519_H_ */
