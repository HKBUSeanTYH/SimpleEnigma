#! /bin/bash

input=$1
counter=0
for x in {A..Z}:
do
	echo -n $x"${input:counter:1} "
	counter=$counter+1
done
