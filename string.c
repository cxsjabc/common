#include "string.h"

int		strcmp(const char *s1, const char *s2)
{
	//printf("xi_strcmp:s1:[%s],s2:[%s]\n", s1, s2);

	while(*s1 && *s2) {
		if(*s1 == *s2) {
			++s1, ++s2;
			 continue;
		} else
			return *s1 - *s2;
	}
	if(*s1)
		return *s1;
	else	
		return *s2;
}
