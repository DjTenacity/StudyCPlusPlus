#!/bin/bash
#多个条件 []
mydir=/usr/jason/shell
#任意数学赋值或者比较表达式
#if (( a++ > 90 ))
if [ -d $HOME ] && [ -w $mydir ]
then
	cd $mydir
	touch test5
else
	echo "no"
fi	


