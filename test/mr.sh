#!/bin/bash

if [ -z "$1" ]
then
	echo "Need argument..."
	exit -1
fi

#DEFINES=
#DEFINES+=-D_USE_COMMON_SRC

REL_PATH=../../
#COMMON_C="../../common/common.c ../../common/gen.c ../../common/arr.c"
source common_non_sys.sh
#echo "COMMON_C:${COMMON_C}"

DEST=$1
shift

gcc $@ ${DEFINES} -Wall -g -o $DEST.elf $DEST.c ${COMMON_C} && ./$DEST.elf
