#!/bin/bash
a=10
b=20
#
if [ $a -gt $b ]
then
	echo "$a greater than $b"
fi
#
if [ $a -eq $b ]
then
	echo "$a equal $b"
else
	echo "$a smaller than $b"
fi
#
