802.1X EAP METHOD SUPPLICANT EXAMPLE

Description:
Use 802.1X EAP methods to connect to AP and authenticate with backend radius server.
Current supported methods are EAP-TLS, PEAPv0/EAP-MSCHAPv2, and EAP-TTLS/MSCHAPv2.

Configuration:
Modify the argument of example_eap() in example_entry.c to set which EAP methods you want to use.
Modify the connection config (ssid, identity, password, cert) in example_eap_config() of example_eap.c based on your server's setting.
1.[FreeRTOSConfig.h]
	#define configTOTAL_HEAP_SIZE          ( ( size_t ) ( 70 * 1024 ) )
2.[platform_opts.h]
	# define CONFIG_EXAMPLE_EAP	1

	// Turn on/off the specified method
	# define CONFIG_ENABLE_PEAP	1
	# define CONFIG_ENABLE_TLS	1
	# define CONFIG_ENABLE_TTLS	1

	// If you want to verify the certificate of radius server, turn this on
	# define ENABLE_EAP_SSL_VERIFY_SERVER	1

3. get config arguments from wifi_eap_config.c
	#define PRE_CONFIG_EAP in autoconf_eap.h
	#define CONFIG_TLS 
	#define CONFIG_PEAP 
	#define CONFIG_TTLS

4. For AmebaD2 :Amebad2 Changes how example is compiled, and Removed macro controls (CONFIG_EXAMPLE_XXX)in platform_opts.h
	(a) Build lib_eap (for example:GCC-RELEASE\project_ap\asdk\make\network\makefile)
		make -C eap all
		make -C eap clean
	(b) Add lib_eap.a to project and modify makefile/IAR project setting to link it
		LINK_APP_LIB += $(ROOTDIR)/lib/application/lib_eap.a
	(c) GCC:use CMD "make xip EXAMPLE=eap" to compile eap example

Execution:
An EAP connection thread will be started automatically when booting.

Note:
Please make sure the lib_wps, polarssl/mbedtls, ssl_ram_map are also builded.

If the connection failed, you can try the following directions to make it work:
1. Make sure the config_rsa.h of PolarSSL/MbedTLS include the SSL/TLS cipher suite supported by radius server.
2. Set a larger value to SSL_MAX_CONTENT_LEN in config_rsa.h
3. Increase the FreeRTOS heap in FreeRTOSConfig.h, for example you can increase the heap to 80kbytes:
	#define configTOTAL_HEAP_SIZE	( ( size_t ) ( 80 * 1024 ) )
4. Try to change using SW crypto instead of HW crypto.


[Supported List]
	Supported :
	    Ameba-1, Ameba-z, Ameba-pro, Ameba-D
		
Note:
For Ameba-D, lib_eap is not included by default, it need to be add to your project and then build.
For GCC, please modify project/realtek_amebaD_va0_example\GCC-RELEASE\project_hp\asdk\makefile to link lib_eap.a, should add "LINK_APP_LIB += $(ROOTDIR)/lib/application/lib_eap.a" in make file.
For IAR, please add lib_eap.a to the lib fold in km4_application project.