##################################################################################
#                                                                                #
#                                 RARP EXAMPLE                                   #
#                                                                                #
##################################################################################

Date: 2019-10-24

Table of Contents
~~~~~~~~~~~~~~~~~
 - Description
 - Setup Guide
 - Parameter Setting and Configuration
 - Result description
 - Supported List


Description
~~~~~~~~~~~
    In this example, it will send rarp request for 3 times. And the rarp reply callback 
        will print the received reply IP address.


Setup Guide
~~~~~~~~~~~
        1. Add rarp example to SDK
        
        /component/common/example/rarp
        .
        |-- example_rarp.c
        |-- example_rarp.h
        `-- readme.txt

        2. Enable CONFIG_EXAMPLE_RARP in [platform_opts.h]
        /* For rarp example */
        #define CONFIG_EXAMPLE_RARP     1

        3. Add example_rarp() to [example_entry.c]
        #if CONFIG_EXAMPLE_RARP
            #include <rarp/example_rarp.h>
        #endif
        void example_entry(void)
        {
        #if CONFIG_EXAMPLE_RARP
            example_rarp();
        #endif 
        }
        
        4. Add rarp example source files to project
        (a) For IAR project, add ota http example to group <example> 
            $PROJ_DIR$\..\..\..\component\common\example\rarp\example_rarp.c
        (b) For GCC project, add ota http example to example Makefile
            CSRC += $(DIR)/rarp/example_rarp.c

	For AmebaD2 :Amebad2 Changes how example is compiled, and Removed macro controls (CONFIG_EXAMPLE_XXX)in platform_opts.h
		GCC:use CMD "make xip EXAMPLE=rarp" to compile rarp example.

Result description
~~~~~~~~~~~~~~~~~~
    You need to connect to WiFi manually by AT command. 
    After connected the rarp request will be sent.

RARP server:
    For Ubuntu, you can try to setup the RARP server as doing this:
        apt-get install rarpd
        touch /etc/ethers
        Add Ameba's MAC address such as "00:e0:4c:87:00:09  client"     in /etc/ethers
        Add Ameba's IP  address such as "192.168.0.100  client"     in /etc/hosts


Supported List
~~~~~~~~~~~~~~
[Supported List]
        Supported :
            Ameba-1, Ameba-z, Ameba-pro, Ameba-z2, AmebaD, Ameba-D2