#ifndef NOUSE_XI_ERR

#ifndef ERR_H
#define	ERR_H

// there functions are hard to define the names...
//  Just leave them alone, if i find a better way to
// name them, i will update.

void	usage_err(const char *fmt, ...);
void	err_exit(const char *fmt, ...);

// print error if res < 0
void	print_err(int res, const char *fmt, ...);
// print error if:
//    cond: 1  means if > dest
//    cond: 0  means if == dest
//    cond: -1  means if < dest
void	print_err_if(int res, int cond, int dest, const char *fmt, ...);

#ifndef PE
#define	PE		print_err	
#endif
#ifndef PEI
#define	PEI		print_err_if	
#endif

#endif

#endif
