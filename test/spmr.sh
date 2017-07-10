#!/bin/bash

if [ -z $1 ]
then
	echo "No argument..."
	exit -1
fi

g++ -o $1.cpp.simple.elf $1.cpp

if [ $? -eq 0 ]
then
./$1.cpp.simple.elf
fi
