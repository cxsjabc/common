#!/bin/bash

if [ -z $1 ]
then
	echo "No argument..."
	exit -1
fi

EXE=$1

shift

gcc -o $EXE.c.simple.elf $EXE.c $@

if [ $? -eq 0 ]
then
./$EXE.c.simple.elf
fi
