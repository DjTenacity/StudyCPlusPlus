#!/bin/bash
testuser=ricky
if [ $USER = $testuser ]
then
	echo "welcome $USER"
elif [ $USER = "jack" ]	
then
	echo "hello jack"
else
	echo "bye"
fi
