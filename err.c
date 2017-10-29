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

void	err_exit(const char *fmt, ...)
{
	va_list args;

	fflush(stdout);	
	fprintf(stderr, "Error: ");	
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);

	fflush(stderr);
	exit(EXIT_FAILURE);
	
}

void	print_err(int res, const char *fmt, ...)
{
	va_list args;

	if(res >= 0)
		return;

	va_start(args, fmt);
	fprintf(stderr, "[%d]: ", res);
	perror("");
	vfprintf(stderr, fmt, args);
	va_end(args);
}

void	print_err_if(int res, int cond, int dest, const char *fmt, ...)
{
	va_list args;

	if(cond == 1 && res <= dest)
		return;
	if(cond == 0 && res != dest)
		return;
	if(cond == -1 && res >= dest)
		return;

	va_start(args, fmt);
	fprintf(stderr, "[%d]: ", res);
	perror("");
	vfprintf(stderr, fmt, args);
	va_end(args);
}

#endif
