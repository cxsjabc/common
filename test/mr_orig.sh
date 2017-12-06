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
#source common_non_sys.sh
source common.sh
#echo "COMMON_C:${COMMON_C}"

EXTRAS=-I..

DEST=$1
shift

gcc $@ ${EXTRAS} ${DEFINES} -Wall -g -o $DEST.elf $DEST ${COMMON_C} && ./$DEST.elf
