#!/bin/bash
a=10
while [ $a -gt 0 ]
do
	echo "num:$a"
	#赋值不用使用$符号
	a=$[ $a - 1 ]
	if [ $a -eq 5 ]
	then
		echo "break"
		break
	fi	
done

