##################################################################################
#                                                                                #
#                      		POWER_SAVE_LONGRUN TEST                          #
#                                                                                #
##################################################################################

Date: 2022-03-08

Table of Contents
~~~~~~~~~~~~~~~~~
 - Description
 - Setup Guide
 - Parameter Setting and Configuration
 - Result description
 - Supported List


Description
~~~~~~~~~~~
    This example is designed for power save multi wake up test.


Setup Guide
~~~~~~~~~~~
        1. Build and download firmware.
	2. Connect to AP, reset DUT and the DUT will go into sleep mode for 15 sec.
	3. Stimer start 10sec then 15sec sleep mood the cycle repeats.
	4. when DUT is in sleep mood do a ping to DUT will wakeup and do a reset.(PingInfoView auto ping)
	5. when DUT is in sleep mood, Use a jumper cable to link GPIO PA_2 to GND, Remove GND and connect to 3v3, remove 3v3 back to GND instantly. 


Parameter Setting and Configuration
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



Result description
~~~~~~~~~~~~~~~~~~
	Verify the stimer, GPIO wake up and WOWLan is working correctly.


Supported List
~~~~~~~~~~~~~~
[Supported Lis]
        Supported IC:
                Ameba-pro2