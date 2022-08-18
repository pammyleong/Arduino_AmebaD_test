##################################################################################
#                                                                                #
#                           bt_ces_dem                                  #
#                                                                                #
##################################################################################

Date: 2021 - 10 - 26

Description
~~~~~~~~~~~
Initialize ces example for ca7 and km4.

Setup Guide
~~~~~~~~~~~
In both ca7 and km4's platform_opts.h, please set #define CONFIG_BT_CES_DEMO 1
If need the lcd gui demo, in ca7 platform_opts.h, please set #define BT_CES_DEMO_LCD_MONITOR 1
sdk\project\realtek_amebaD2_testchip_va0_example\GCC - RELEASE\project_ap\asdk\make\bluetooth\Makefile Enable make - C bt_mesh_provisioner_ces_demo all
sdk\project\realtek_amebaD2_testchip_va0_example\GCC - RELEASE\project_hp\asdk\make\bluetooth\Makefile Enable make - C bt_mesh_provisioner_ces_demo all
GCC :
use CMD "make xip EXAMPLE=bt_ces_demo" to compile ces example on both project_hp and project_ap

[Supported List]
Supported IC :
	Ameba - D2
