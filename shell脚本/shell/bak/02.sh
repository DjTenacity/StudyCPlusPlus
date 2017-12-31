#!/bin/bash
testuser=jack
#if 条件状态码必须是0
if grep $testuser /etc/passwd
then
	ls -a /home/$testuser/
	echo
else
	echo $testuser not exist
fi
