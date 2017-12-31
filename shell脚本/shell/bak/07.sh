#!/bin/bash

#向函数传递参数
function myfun {
	echo $[ $1 + $2 ]
}

value=$(myfun 20 30)

echo "result $value"
