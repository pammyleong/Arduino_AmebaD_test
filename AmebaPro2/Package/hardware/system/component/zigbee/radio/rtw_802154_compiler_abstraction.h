
#ifndef RTW_802154_COMPILER_ABSTRACTION_H_
#define RTW_802154_COMPILER_ABSTRACTION_H_

#include <core_ca.h>
//TODO: according to arm

#if   defined ( __CC_ARM )
#define __ASM            __asm                                      /*!< asm keyword for ARM Compiler */
#define __INLINE         __inline                                   /*!< inline keyword for ARM Compiler */
#define __STATIC_INLINE  static __inline
#ifndef __ASM
#define __ASM				__asm
#endif

#ifndef __INLINE
#define __INLINE			__inline
#endif

#ifndef __WEAK
#define __WEAK				__weak
#endif

#ifndef __ALIGN
#define __ALIGN(n)			__align(n)
#endif

#ifndef __PACKED
#define __PACKED			__packed
#endif

#define GET_SP()				__current_sp()

#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#define __ASM            __asm                                      /*!< asm keyword for ARM Compiler */
#define __INLINE         __inline                                   /*!< inline keyword for ARM Compiler */
#define __STATIC_INLINE  static __inline
#ifndef __ASM
#define __ASM				__asm
#endif

#ifndef __INLINE
#define __INLINE			__inline
#endif

#ifndef __WEAK
#define __WEAK				__attribute__((weak))
#endif

#ifndef __ALIGN
#define __ALIGN(n)			__attribute__((aligned(n)))
#endif

#ifndef __PACKED
#define __PACKED			__attribute__((packed, aligned(1)))
#endif

#define GET_SP()				__current_sp()

#elif defined ( __GNUC__ )
#define __ASM            __asm                                      /*!< asm keyword for GNU Compiler */
#define __INLINE         inline                                     /*!< inline keyword for GNU Compiler */
#define __STATIC_INLINE  static inline
#ifndef __ASM
#define __ASM				__asm
#endif

#ifndef __INLINE
#define __INLINE			inline
#endif

#ifndef __WEAK
#define __WEAK				__attribute__((weak))
#endif

#ifndef __ALIGN
#define __ALIGN(n)			__attribute__((aligned(n)))
#endif

#ifndef __PACKED
#define __PACKED		   __attribute__((packed))
#endif

#define GET_SP()				gcc_current_sp()

static inline unsigned int gcc_current_sp(void)
{
	register unsigned sp __ASM("sp");
	return sp;
}

#elif defined ( __ICCARM__ )
#define __ASM            __asm                                      /*!< asm keyword for IAR Compiler */
#define __INLINE         inline                                     /*!< inline keyword for IAR Compiler. Only available in High optimization mode! */
#define __STATIC_INLINE  static inline
#ifndef __ASM
#define __ASM				__asm
#endif

#ifndef __INLINE
#define __INLINE			inline
#endif

#ifndef __WEAK
#define __WEAK				__weak
#endif

#ifndef __ALIGN
#define STRING_PRAGMA(x) _Pragma(#x)
#define __ALIGN(n) STRING_PRAGMA(data_alignment = n)
#endif

#ifndef __PACKED
#define __PACKED			__packed
#endif

#define GET_SP()				__get_SP()

#elif defined ( __TMS470__ )
#define __ASM            __asm                                      /*!< asm keyword for TI CCS Compiler */
#define __STATIC_INLINE  static inline

#elif defined ( __TASKING__ )
#define __ASM            __asm                                      /*!< asm keyword for TASKING Compiler */
#define __INLINE         inline                                     /*!< inline keyword for TASKING Compiler */
#define __STATIC_INLINE  static inline
#ifndef __ASM
#define __ASM				__asm
#endif

#ifndef __INLINE
#define __INLINE			inline
#endif

#ifndef __WEAK
#define __WEAK				__attribute__((weak))
#endif

#ifndef __ALIGN
#define __ALIGN(n)			__align(n)
#endif

/* Not defined for TASKING. */
#ifndef __PACKED
#define __PACKED
#endif

#define GET_SP()				__get_MSP()

#elif defined ( __CSMC__ )
#define __packed
#define __ASM            _asm                                      /*!< asm keyword for COSMIC Compiler */
#define __INLINE         inline                                    /*!< inline keyword for COSMIC Compiler. Use -pc99 on compile line */
#define __STATIC_INLINE  static inline
#endif

#endif /* RTW_802154_COMPILER_ABSTRACTION_H_ */
