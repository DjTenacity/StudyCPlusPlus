#!/bin/bash

filename=$(basename $0)
#内建变量
echo "参数的总数：$#"
echo filename
echo $1
echo $2
echo $3

#使用$@遍历所有参数
#getopt
echo "遍历"
for param in "$@"
do
	echo "param:$param"
done




