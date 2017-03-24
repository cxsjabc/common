#include "common.h"


int	is_odd(unsigned int n)
{
	return n & 1;
}

int	is_even(unsigned int n)
{
	return !(n & 1);
}
