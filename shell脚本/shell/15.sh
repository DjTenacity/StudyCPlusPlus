#!/bin/bash

#函数的传参，返回值
function myfun
{
	echo $[ $1 + $2 ]
}

value=$(myfun 10 90)
echo "value:$value"




