/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#define _USE_COMMON_SRC
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#ifdef _USE_COMMON_SRC
#define	LOG_LEVEL		LOG_LEVEL_VERBOSE
#include "common_local.h"
#endif

int main()
{
	int arr[128];
	gen_fixed_arr(arr, 128, 0);

	print_by_byte(arr, 128);
	PD(is0(arr, 128 * sizeof(int)));

	return 0;
}
