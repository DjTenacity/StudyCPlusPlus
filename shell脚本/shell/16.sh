#!/bin/bash

#引入./17.sh
#source ./17.sh
#.source快捷别名
. ./17.sh

function myfun()
{
	echo $value
}

value=20
myfun

echo "add value:$(add 10 30)"

jason
