#ifndef LOG_H
#define LOG_H

#include <stdio.h>
// 'v', 	'd', 	'i', 	'w', 	'e', 	'f'
//  10    	20    	30    	40    	50    	60

#define VERBOSE		10
#define DEBUG		20
#define INFO		30
#define WARN		40
#define ERROR		50
#define FATAL		60

#ifndef LOG_LEVEL
#define LOG_LEVEL 	VERBOSE 
#endif

#define log_v(fmt, ...)	do { if(LOG_LEVEL <= VERBOSE)	printf(fmt, ##__VA_ARGS__); } while(0)
#define log_d(fmt, ...)	do { if(LOG_LEVEL <= DEBUG)	printf(fmt, ##__VA_ARGS__); } while(0)


#endif
