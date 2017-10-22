#ifndef NOUSE_XI_ERR
#include "common.h"

// refer to linux/unix system programming manual: page:45 func:usageErr
void	usage_err(const char *fmt, ...)
{
	va_list args;

	fflush(stdout);	
	fprintf(stderr, "Usage: ");	
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);

	fflush(stderr);
	exit(EXIT_FAILURE);
}

#endif
