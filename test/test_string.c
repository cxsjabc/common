/*
* Copyright by xichen(Xi.chen)  511272827@qq.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <assert.h> 

#include <string.h> 
#include "../string.h" 

#ifdef _USE_COMMON_SRC
#define	LOG_LEVEL		LOG_LEVEL_VERBOSE
#endif

int main()
{
	int r;
	char s1[128], s2[128];

	while(1) {
		int t;
		t = scanf("%s", s1);
		if(t <= 0)
			break;
		t = scanf("%s", s2);
		if(t <= 0)
			break;

		r = strcmp(s1, s2);
		printf("strcmp:%d\n", r);
	
	}

	return 0;
}
