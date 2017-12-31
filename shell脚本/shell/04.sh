#!/bin/bash
testuser=lady
#
if grep $testuser /etc/passwd 
then
	echo "ok"
	ls -a /home/$testuser/
#	
elif ls -d /home/$testuser
then
	echo "用户不存在，主目录仍然存在"
#	
else
	##嵌套if
	#if 
	#then
	echo "$testuser not exist"
fi	
#

