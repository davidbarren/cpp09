#! /usr/bin/bash

set -f

opArray=("+" "-" '*'  "/")
printf "%s " $(($RANDOM % 9))
for I in {1..5000}
do
	N=$((1 + $RANDOM % 8))
	printf "%s " $N
	J=$(($RANDOM % 4))
	if [ $I == 5000 ]; then
		printf "%s" ${opArray[$J]}
	else
		printf "%s " ${opArray[$J]}
	fi
done
