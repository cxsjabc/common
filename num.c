#include "common.h"


int	is_odd(unsigned int n)
{
	return n & 1;
}

int	is_even(unsigned int n)
{
	return !(n & 1);
}

int	is_square(long n)
{
	long i;
	for(i = 1; n > 0; i += 2)	// square num is always: 1, 1 + 3, 1 + 3 + 5, ...
		n -= i;
	return !(n);
}
