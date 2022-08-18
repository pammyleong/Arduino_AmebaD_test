WIFI SCAN MCC EXAMPLE

Description:
This example performs scan which use partial scan and delay to make AP mode can send beacon during STA scan.

Configuration:
[platform_opts.h]
	#define CONFIG_EXAMPLE_WIFI_SCAN_MCC	1

For AmebaD2 :Amebad2 Changes how example is compiled, and Removed macro controls (CONFIG_EXAMPLE_XXX)in platform_opts.h
		GCC:use CMD "make xip EXAMPLE=wifi_scan_mcc" to compile wifi_scan_mcc example.

[Supported List]
	Supported :
	    Ameba-1, Ameba-z, Ameba-pro, Ameba-z2, Ameba-D, Ameba-D2