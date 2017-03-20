#ifndef ASSERT_H
#define ASSERT_H

#include <stdlib.h>

#ifndef ASSERT
#define ASSERT(n)	\
	do { if(!(n))  { fprintf(stderr, "Assert Fail:%d, File:%s, Line:%d\n", (int)(n), __FILE__, __LINE__); abort(); } } while(0)
#endif

#endif
