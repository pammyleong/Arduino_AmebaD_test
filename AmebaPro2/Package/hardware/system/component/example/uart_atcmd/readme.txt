atcmd feature, ssl supported

Description:
This example shows how to run the atcmd feature

Configuration:

[platform_opts.h] 
	#define CONFIG_EXAMPLE_UART_ATCMD	1
[config_rsa.h]
	#define MBEDTLS_BIGNUM_C
	#define MBEDTLS_CERTS_C
	#define MBEDTLS_SSL_TLS_C
	#define MBEDTLS_SSL_SRV_C
	#define MBEDTLS_SSL_CLI_C
	#define MBEDTLS_NET_C
	#define MBEDTLS_RSA_C
	#define MBEDTLS_X509_CRT_PARSE_C
if use ssl:
[atcmd_lwip.h]
	#define ATCMD_SUPPORT_SSL	1

Steps to use:
	ATPW -> ATPN -> ATCK -> ATPC

[Supported List]
	Supported :
	    Ameba-1, Ameba-z, Ameba-pro, Ameba-z2