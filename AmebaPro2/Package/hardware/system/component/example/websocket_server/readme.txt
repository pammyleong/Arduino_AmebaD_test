Websocket Server Example

Description:
A simple websocket server example which echo all the messages.


Configuration:

	1.[platform_opts.h]
		#define CONFIG_EXAMPLE_WEBSOCKET_SERVER 	1
	For AmebaD2 :Amebad2 Changes how example is compiled, and Removed macro controls (CONFIG_EXAMPLE_XXX)in platform_opts.h
		1.GCC:use CMD "make xip EXAMPLE=mqtt" to compile mqtt example

	2. [FreeRTOSConfig.h]
		Modify configTOTAL_HEAP_SIZE to make sure the heap size is enough

    3. If acting as the WSS server:

	[config_rsa.h]
		If using POLARSSL:
			#define POLARSSL_CERTS_C
			#define POLARSSL_SSL_SRV_C
			#define POLARSSL_X509_CRT_PARSE_C
		If using MBEDTLS:
			#define MBEDTLS_CERTS_C
			#define MBEDTLS_SSL_SRV_C
			#define MBEDTLS_X509_CRT_PARSE_C	


	[example_ws_server.c]
		#define USE_WSS    1


    4. If acting as the WS server:

	[example_ws_server.c]
		#define USE_WSS    0


Execution:
Can make automatical Wi-Fi connection when booting by using wlan fast connect example.
A websocket server example thread will be started automatically when booting.

[Supported List]
	Supported :
	    Ameba-1, Ameba-pro, Ameba-D2
	Source code not in project:
	    Ameba-z