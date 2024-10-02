#! /usr/bin/bash

set -f

for I in {1..5}
do
	N=$(($RANDOM))
	printf "%s " $N
done
