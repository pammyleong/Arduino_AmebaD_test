/*
 * Copyright (c) 2020 Realtek Semiconductor Corp.	All rights reserved.
 *
 * Author: PSP Software Group
 */
#ifndef _CSTUB_H
#define _CSTUB_H

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define HEAP_START		__HeapBase
#define MAX_HEAPSIZE	__HeapSize

#ifndef _ASMLANGUAGE

/* HEAP_START, MAX_HEAPSIZE are set in the linker command file */
extern caddr_t HEAP_START, MAX_HEAPSIZE;

/*
** The RAMSIZE value must be greater than HEAP_START
** for malloc to work.
*/

#define RAMSIZE		(caddr_t)(((unsigned long)&HEAP_START + (unsigned long)MAX_HEAPSIZE) \
					& ~((unsigned long)0xf))

#endif /* !_ASMLANGUAGE */

#endif
