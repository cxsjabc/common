#ifndef COMMON_H
#define COMMON_H

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>


#define PD(str)		printf(#str ":%d\n", (str))
#define PN(n)		printf(#n " is %d\n", (n));
#define PC(n)		printf(#n " is %c\n", (n));
#define PU(n)		printf(#n " is %u\n", (n));
#define PL(n)		printf(#n " is %ld\n", (n));
#define PP(n)		printf(#n " is %p\n", (n));

#define P_HERE()	printf("execute %s@%d\n", __FUNCTION__, __LINE__);

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

#ifndef swap
#define swap		swap_by_addr
#endif

#ifndef SWAP
#define SWAP		swap_by_addr
#endif

void print_by_byte(const void *p, int size);

/* this is for int compare common function: eg: qsort */
static inline int int_compare(const void *v1, const void *v2)
{
	return *(int *)v1 - *(int *)v2;
}
static inline int int_compare_desc(const void *v1, const void *v2)
{
	return *(int *)v2 - *(int *)v1;
}

#endif
