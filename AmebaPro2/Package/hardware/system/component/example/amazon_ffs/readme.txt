Amazon Frustration Free Setup EXAMPLE

Description:
Perform the amazon frustration free setup.
So far, only Echo Dot 3rd Gen without Clock support FFS wifi provisioner function
The Software Version of the Echo Dot should be the latest version: 3926569348 or 3926570628
The Echo Dot only support 2.4GHz wifi to achieve FFS

Configuration:

[platform_opts.h]
	#define CONFIG_EXAMPLE_FFS         1

[Supported List]
	Supported :
	    Ameba-z2