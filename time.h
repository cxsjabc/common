#ifndef TIME_XI_H
#define TIME_XI_H

#include <stdio.h>

#ifndef TIME_START
#define TIME_START(times)	\
	{  \
		clock_t __19870814_xixi_tag_you_not_used_start, __19870814_xixi_tag_you_not_used_finish; \
		int __19870814_xixi_tag_you_not_used_i; \
		__19870814_xixi_tag_you_not_used_start = clock(); \
				\
		for(__19870814_xixi_tag_you_not_used_i = 0; __19870814_xixi_tag_you_not_used_i < (times); ++__19870814_xixi_tag_you_not_used_i) \
		{ 
#endif

#ifndef TIME_END
#define TIME_END \
		} \
		__19870814_xixi_tag_you_not_used_finish = clock(); \
		printf("Time Elapsed:%5f seconds\n", 1.0 * (__19870814_xixi_tag_you_not_used_finish - __19870814_xixi_tag_you_not_used_start) / CLOCKS_PER_SEC); \
	} 
#endif

#ifndef TS
#define TS			TIME_START
#endif

#ifndef TE
#define TE			TIME_END
#endif

#endif
