#!/bin/bash

if [ -z $1 ]; then
DIR=.
else
DIR=$1
fi

echo "DIR:${DIR}"

ELF="*.elf"
DSYM="*.dSYM"
PRECESSED="*.precessed"
PRECESSED1="*.p"

FILES=`find $DIR -name "$ELF" -or -name "$DSYM" -or -name "$PRECESSED" -or -name "$PRECESSED1"` 
echo "FILES:$FILES"
echo $FILES | xargs rm -rf

#rm -rf *.elf
#rm -rf *.dSYM
