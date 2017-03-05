#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

#include "log.h"
#include "assert.h"
#include "gen.h"
#include "arr.h"

#define PD(str)		printf(#str ":%d\n", (str))

void print_by_byte(const void *p, int size);

#endif
