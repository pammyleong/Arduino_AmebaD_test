##################################################################################
#                                                                                #
#                           example_wifi_mac_monitor                             #
#                                                                                #
##################################################################################

Date: 2019-11-14

Table of Contents
~~~~~~~~~~~~~~~~~
 - Description
 - Setup Guide
 - Parameter Setting and Configuration
 - Result description
 - Supported List

 
Description
~~~~~~~~~~~
        This example realizes wifi roaming among local area network with the same SSID. 

Setup Guide
~~~~~~~~~~~
        1. In platform_opts.h, please set 
		#define CONFIG_EXAMPLE_WLAN_FAST_CONNECT	1		
		#define CONFIG_EXAMPLE_WIFI_ROAMING		1

		2.For AmebaD2 :Amebad2 Changes how example is compiled, and Removed macro controls (CONFIG_EXAMPLE_XXX)in platform_opts.h
			1.set wifi_fast_connect_enable(1) in main.c
			2.GCC:use CMD "make xip EXAMPLE=wifi_roaming" to compile wifi_roaming example.

Parameter Setting and Configuration
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        Set the RSSI_THRESHOLD according to the WLAN envrionment.

Result description
~~~~~~~~~~~~~~~~~~
         The device can connect to a better RSSI AP and store the connection message to flash.

Supported List
~~~~~~~~~~~~~~
[Supported List]
	Supported :
	    Ameba-1, Ameba-z, Ameba-pro, Ameba-z2, Ameba-D, Ameba-D2