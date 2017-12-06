#include "common.h"


int		_is0(void *p, size_t size)
{
	size_t i = 0;
	unsigned char *pc = (unsigned char *)p;

	while(i < size) {
		if(*(pc + i) != '\0')
			return 0;
		++i;
	}
	return 1;
}

int		is0(void *p, size_t size)
{
	size_t i = 0;
	unsigned char *pc;
	long *pl = (long *)p;

	size_t temp = size & ~(sizeof(long));
	
	while(i < temp) {
		if(*pl != 0)
			return 0;
		i += sizeof(long);
		pl += 1;
	}
	
	pc = (unsigned char *)pl;
	while(i < size) {
		if(*pc != '\0')
			return 0;
		++i;
	}

	return 1;
}
