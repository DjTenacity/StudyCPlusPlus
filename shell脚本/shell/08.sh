#!/bin/bash
mydir=/usr/jason
#-d检查目录是否存在
if [ -d $mydir ]
then
	echo "$mydir exist"
	cd $mydir
	ls
else
	echo "mydir not exist"
fi

