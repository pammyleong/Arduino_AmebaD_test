COAP CLIENT EXAMPLE

Description:
This example demonstrates how to use libcoap C library to build a CoAP client.

Configuration:
Modify SERVER_HOST, SERVER_PORT in example_coap_client.c based on your CoAP server.
Exclude component\common\network\coap from build in IAR.
Make menuconfig to enable CONFIG_LIBCOAP_ON in GCC project.

1. [platform_opts.h]
#define CONFIG_EXAMPLE_COAP                 0
#define CONFIG_EXAMPLE_COAP_CLIENT	        1

// The configurations below have been added in lwipopts.h 
2. [lwipopts.h]
#define LWIP_TIMEVAL_PRIVATE            1
#define SO_REUSE                        1
#define MEMP_USE_CUSTOM_POOLS           1
#define LWIP_IPV6                       1
#ifndef xchar
#define xchar(i)             ((i) < 10 ? '0' + (i) : 'A' + (i) - 10)
#endif

3. For AmebaD2 :Amebad2 Changes how example is compiled, and Removed macro controls (CONFIG_EXAMPLE_XXX)in platform_opts.h
	(a) #define CONFIG_EXAMPLE_COAP_CLIENT in lwipopts.h to ensure that the Settings in Step 2 have been set.
	(b) Add include directories to project(for example:GCC-RELEASE/project_ap/asdk/Makefile.include.gen)
		IFLAGS               += -I$(BASEDIR)/component/network/libcoap/include
	(c) Build libcoap (for example:GCC-RELEASE\project_ap\asdk\make\network\makefile)
		make -C libcoap all
		make -C libcoap clean
	(d) Add lib_coap.a to project and modify makefile/IAR project setting to link it
		LINK_APP_LIB += $(ROOTDIR)/lib/application/lib_coap.a
	(e) GCC:use CMD "make xip EXAMPLE=coap_client" to compile coap_client example

Execution:
Can make automatical Wi-Fi connection when booting by using wlan fast connect example.
A CoAP client example thread will be started automatically when booting.

In default, the client will attempt to contact the server at coap://coap.me/hello with port 5683.
The server will return a string with the word "world" to the client.

Note:
Company Firewall may block CoAP message. You can use copper (https://addons.mozilla.org/en-US/firefox/addon/copper-270430/) to test the server's reachability.


Supported IC : 
        Ameba-1, Ameba-z2, AmebaD, AmebaD2