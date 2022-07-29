#ifndef _RTLWISOCFW_CONFIG_H
#define _RTLWISOCFW_CONFIG_H

/* 1 1.) Common */

/* AmebaD SOC */
#include "ameba_soc.h"
#include "wififw_rtlchip.h"
#include "RTL8730A_autoconf.h"
#ifndef __ASSEMBLY__
#include "wififw_generaldef.h"
#include "wififw_types.h"
#endif

/* 1 2.) Each Chip */
#ifndef __ASSEMBLY__
#include "wififw_rom.h"
#endif  //#ifndef   __ASSEMBLY__
#include "wififw_hal_rom.h"
#include "wififw_global_declaration.h"
#include "wififw_funcptr_rom.h"
#endif  /* _RTLWISOCFW_CONFIG_H */



