#!/bin/bash
a=10
b=5
#test命令简单形式
if [ $a -gt $b ]
then
	echo "$a greater than $b"
else
	echo "$a smaller than $b"
fi

