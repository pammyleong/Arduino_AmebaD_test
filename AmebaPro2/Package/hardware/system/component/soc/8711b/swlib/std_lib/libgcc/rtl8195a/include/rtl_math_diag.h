/*
 * rtl_math_types.h
 *
 * Definitions for basic types / macro functions
 */
 
#ifndef _RTL_MATH_DIAG_H_
#define	_RTL_MATH_DIAG_H_

#include <basic_types.h>
#include <diag.h>



//
// other macro, will be modified /taken off in the future. 
//

#undef printk
#define printk DiagPrintf


#undef dbg_printk
#define dbg_printk(fmt, args...) \
	     	printk("%s():%d : " fmt "\n", __FUNCTION__, __LINE__, ##args); 

#endif /* _RTL_MATH_DIAG_H_ */
