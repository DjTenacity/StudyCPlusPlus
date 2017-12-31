#!/bin/bash

testuser=tom
case $testuser in
jack | rose)
	echo "hello, $testuser";;
ricky)
	echo "hi, $ricky";;
*)
	echo "others";;
esac
