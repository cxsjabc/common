#ifndef COMMON_H
#define COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

/* move my header above system header files: I need to trust my files! */
#include "log.h"
#include "assert.h"
#include "gen.h"
#include "arr.h"
#include "time.h"
#include "matrix.h"
#include "stack.h"
#include "tree.h"
#include "limit.h"
#include "list.h"
#include "num.h"
#include "mem.h"
#include "err.h"

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>
#include <assert.h>
#include <dirent.h>


#ifndef PNL
#define PNL()		printf("\n")
#endif

#ifndef PD
#define PD(str)		printf(#str ":%d\n", (str))
#endif
#ifndef PN
#define PN(n)		printf(#n " is %d\n", (n))
#endif
#ifndef PC
#define PC(n)		printf(#n " is %c\n", (n))
#endif
#ifndef PS
#define PS(n)		printf(#n " is %s\n", (n) != NULL ? (n) : "NULL")
#endif
#ifndef PU
#define PU(n)		printf(#n " is %u\n", (n))
#endif
#ifndef PL
#define PL(n)		printf(#n " is %ld\n", (n))
#endif
#ifndef PUL
#define PUL(n)		printf(#n " is %lu\n", (n))
#endif
#ifndef PLL
#define PLL(n)		printf(#n " is %lld\n", (n))
#endif
#ifndef PP
#define PP(n)		printf(#n " is %p\n", (n))
#endif

#ifndef PSS
#define PSS(n)		printf(#n " is |%s|\n", (n))
#endif

#ifndef PN2
#define PN2(n1, n2)		printf(#n1 ":%d, " #n2 ":%d." "\n", (n1), (n2))
#endif

#ifndef P_HERE
#define P_HERE()	printf("execute %s@%d\n", __FUNCTION__, __LINE__);
#endif

#ifndef LH
#define	LH			P_HERE();
#endif

#define	LOG			printf

#ifndef MAX
#define MAX(a, b)  ((a) > (b) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b)  ((a) < (b) ? (a) : (b))
#endif

#ifndef MAX3
#define MAX3(a, b, c)  (MAX(MAX((a), (b)), (c)))
#endif

#ifndef MIN3
#define MIN3(a, b, c)  (MIN(MIN((a), (b)), (c)))
#endif


#define ARR_SIZE(arr)		(sizeof(arr) / sizeof(arr[0]))


#ifndef swap
#define swap		swap_by_addr
#endif

#ifndef SWAP
#define SWAP		swap_by_addr
#endif

void print_by_byte(const void *p, int size);
void print_str(const void *p, int size);

/* this is for int compare common function: eg: qsort */
static inline int int_compare(const void *v1, const void *v2)
{
	return *(int *)v1 - *(int *)v2;
}
static inline int int_compare_desc(const void *v1, const void *v2)
{
	return *(int *)v2 - *(int *)v1;
}

#ifdef __cplusplus
}
#endif

#ifndef __cplusplus
static inline void swap_by_addr(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}
#else
template <class T>
static inline void swap_by_addr(T *pa, T *pb)
{
	T temp = *pa;
	*pa = *pb;
	*pb = temp;
}
#endif

#endif
