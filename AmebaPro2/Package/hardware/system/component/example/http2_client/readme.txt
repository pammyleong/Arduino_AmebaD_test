##################################################################################
#                                                                                #
#                           example_http2_client                                  #
#                                                                                #
##################################################################################

Date: 2019-11-21

Table of Contents
~~~~~~~~~~~~~~~~~
 - Description
 - Setup Guide
 - Result description
 - Parameter Setting and Configuration
 - Other Reference
 - Supported List

 
Description
~~~~~~~~~~~
        In this example, http2 client send request to get server response.
	
Setup Guide
~~~~~~~~~~~
		1)Add/Enable CONFIG_EXAMPLE_HTTP2_CLIENT in platform_opts.h
		#define CONFIG_EXAMPLE_HTTP2_CLIENT 1
		For AmebaD2 :Amebad2 Changes how example is compiled, and Removed macro controls (CONFIG_EXAMPLE_XXX)in platform_opts.h
			GCC:use CMD "make xip EXAMPLE=http2_client" to compile http2_client example.
		
		2)Add example to project
		/component/common/example/http2_client
		.
        |-- example_http2_client.c
		
		4) Add include directories to project
        $PROJ_DIR$\..\..\..\component/common/network/http2/nghttp2-1.31.0/includes
		
		4)Add lib_http2.a to project and modify makefile/IAR project setting to link it
		
Parameter Setting and Configuration
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        Change REQ_HOST, REQ_PORT, REQ_PATH, REQ_HOSTPORT to user define.
	
Result description
~~~~~~~~~~~~~~~~~~
        This example will send http2 request to server.

Supported List
~~~~~~~~~~~~~~
[Supported List]
        Supported IC :
				AmebaD, Ameba-D2

		Source code not in project :
				Ameba-1, Ameba-z, Ameba-pro, AmebaD