#ifndef _ROM_RTW_MESSAGE_
#define _ROM_RTW_MESSAGE_

#include <platform_stdlib.h>

// e-version
typedef enum {
#define ROM_E_RTW_MSGPOOL(name,str)  ROM_E_RTW_MSGP_##name,
#include "rom_rtw_message_e.h"
  ROM_E_RTW_MSGP_MAX
} rom_e_rtw_msgp_t;

// f-version
typedef enum {
#define ROM_F_RTW_MSGPOOL(name,str)  ROM_F_RTW_MSGP_##name,
#include "rom_rtw_message_f.h"
  ROM_F_RTW_MSGP_MAX
} rom_f_rtw_msgp_t;

#if ROM_E_RTW_MSG
extern const char *rom_e_rtw_msgp_str_[];
#define rom_e_rtw_msg_printf(name, fmt, args...) \
	do {\
		if(GlobalDebugEnable){\
			printf((char*)rom_e_rtw_msgp_str_[ROM_E_RTW_MSGP_##name], ## args);\
		}\
	}while(0)
	
#define rom_e_rtw_msg_871X_LEVEL(name, level, fmt, args...) \
	do {\
		if(GlobalDebugEnable){\
			printf("\n\r");\
			printf((char*)rom_e_rtw_msgp_str_[ROM_E_RTW_MSGP_##name], ## args);\
		}\
	}while(0)
#else
#define rom_e_rtw_msg_printf(name, fmt, args...) \
	do {\
		if(GlobalDebugEnable){\
			printf(fmt, ## args);\
		}\
	}while(0)
	
#define rom_e_rtw_msg_871X_LEVEL(name, level, fmt, args...) \
	do {\
		if(GlobalDebugEnable){\
			printf("\n\r");\
			printf(DRIVER_PREFIX ##fmt, ## args);\
		}\
	}while(0)
#endif //ROM_E_RTW_MSG

#if ROM_F_RTW_MSG
extern const char *rom_f_rtw_msgp_str_[];
#define rom_f_rtw_msg_printf(name, fmt, args...) \
	do {\
		if(GlobalDebugEnable){\
			printf((char*)rom_f_rtw_msgp_str_[ROM_F_RTW_MSGP_##name], ## args);\
		}\
	}while(0)

#define rom_f_rtw_msg_871X_LEVEL(name, level, fmt, args...) \
	do {\
		if(GlobalDebugEnable){\
			printf("\n\r");\
			printf((char*)rom_f_rtw_msgp_str_[ROM_F_RTW_MSGP_##name], ## args);\
		}\
	}while(0)
#else
#define rom_f_rtw_msg_printf(name, fmt, args...) \
	do {\
		if(GlobalDebugEnable){\
				printf(fmt, ## args);\
		}\
	}while(0)
	
#define rom_f_rtw_msg_871X_LEVEL(name, level, fmt, args...) \
	do {\
		if(GlobalDebugEnable){\
			printf("\n\r");\
			printf(DRIVER_PREFIX ##fmt, ## args);\
		}\
	}while(0)
#endif //ROM_F_RTW_MSG

#endif //_ROM_RTW_MESSAGE_
