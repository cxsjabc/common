#include "common.h"


void print_by_byte(const void *p, int size)
{
	int i;
	const unsigned char *pc = (const unsigned char *)p;
	for(i = 0; i < size; ++i) {
		printf("%x ", *(pc + i));
	}
	printf("\n");
}

void print_str(const void *p, int size)
{
	int i;
	const unsigned char *pc = (const unsigned char *)p;
	for(i = 0; i < size; ++i)
		putchar(*(pc + i));
	putchar('\n');
}
