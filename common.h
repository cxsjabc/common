#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

#include "log.h"
#include "assert.h"
#include "gen.h"
#include "arr.h"

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

static inline void swap_by_addr(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void print_by_byte(const void *p, int size);

/* this is for int compare common function: eg: qsort */
static inline int int_compare(const void *v1, const void *v2)
{
	return *(int *)v1 - *(int *)v2;
}

#endif
