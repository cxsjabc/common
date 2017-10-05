#include "common.h"

void	mem_zero( void *p, int size)		// '\0'
{
	int i;
	unsigned char *pc = ( unsigned char *)p;

	for(i = 0; i < size; ++i)
		*(pc + i) = '\0';
}

void	mem_set(void *p, int size, char c)
{
	int i;
	unsigned char *pc = (unsigned char *)p;

	for(i = 0; i < size; ++i)
		*(pc + i) = c;
}

void	mem_set_c0(void *p, int size)	// '0'
{
	mem_set(p, size, '0');
}
