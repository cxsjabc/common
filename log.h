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

enum 
{
	LOG_LEVEL_VERBOSE 	= VERBOSE,
	LOG_LEVEL_DEBUG 	= DEBUG,
	LOG_LEVEL_INFO		= INFO,
	LOG_LEVEL_WARNING	= WARN,
	LOG_LEVEL_ERROR		= ERROR,
	LOG_LEVEL_FATAL		= FATAL,
	LOG_V = LOG_LEVEL_VERBOSE,
	LOG_D = LOG_LEVEL_DEBUG,
	LOG_I = LOG_LEVEL_INFO,
	LOG_W = LOG_LEVEL_WARNING,
	LOG_E = LOG_LEVEL_ERROR,
	LOG_F = LOG_LEVEL_FATAL,

	LOG_LEVEL_MAX
};

#ifndef _LOG_LEVEL
#define _LOG_LEVEL LOG_LEVEL_VERBOSE		// we use verbose for debugging
#endif

#ifndef LOG_LEVEL
#define LOG_LEVEL 	_LOG_LEVEL 
#endif

#define log_v(fmt, ...)	do { if(_LOG_ENABLE && LOG_LEVEL <= VERBOSE)	printf(fmt, ##__VA_ARGS__); } while(0)
#define log_d(fmt, ...)	do { if(_LOG_ENABLE && LOG_LEVEL <= DEBUG)	printf(fmt, ##__VA_ARGS__); } while(0)

#ifndef _LOG_ENABLE
#define _LOG_ENABLE 1
#endif
// it needs macro: _LOG_ENABLE
#define	LOG_HERE	do { \
						if(_LOG_ENABLE && _LOG_LEVEL <= LOG_LEVEL_VERBOSE) \
							printf("Log Here:%s@%d\n", __FUNCTION__, __LINE__); \
					} while(0)

// log level: VERBOSE,DEBUG,INFO,WARNING,ERROR,FATAL
// it needs macro: _LOG_LEVEL
#define LOG_V(fmt, args...) \
		do { \
			if(_LOG_ENABLE && _LOG_LEVEL <= LOG_LEVEL_VERBOSE) \
				printf("[V]" fmt "\n", ##args); \
		} while(0)	

#define LOG_D(fmt, args...) \
		do { \
			if(_LOG_ENABLE && _LOG_LEVEL <= LOG_LEVEL_DEBUG) \
				printf("[D]" fmt "\n", ##args); \
		} while(0)	

#define LOG_I(fmt, args...) \
		do { \
			if(_LOG_ENABLE && _LOG_LEVEL <= LOG_LEVEL_INFO) \
				printf("[I]" fmt "\n", ##args); \
		} while(0)	

#define LOG_W(fmt, args...) \
		do { \
			if(_LOG_ENABLE && _LOG_LEVEL <= LOG_LEVEL_WARNING) \
				printf("[W]" fmt "\n", ##args); \
		} while(0)	


#define LOG_E(fmt, args...) \
		do { \
			if(_LOG_ENABLE && _LOG_LEVEL <= LOG_LEVEL_ERROR) \
				printf("[E]" fmt "\n", ##args); \
		} while(0)	


#define LOG_F(fmt, args...) \
		do { \
			if(_LOG_ENABLE && _LOG_LEVEL <= LOG_LEVEL_FATAL) \
				printf("[F]" fmt "\n", ##args); \
		} while(0)	

#endif
