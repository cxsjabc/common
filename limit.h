#ifndef LIMIT_H
#define LIMIT_H

//#define _DEBUG

#ifdef USE_XI_DEF
#ifndef INT_MAX
#ifdef _DEBUG
#warning "Use My Defined INT_MAX!"
#endif
#define INT_MAX		((1 << (sizeof(int) * 8)) - 1)
#endif
#endif

#endif
