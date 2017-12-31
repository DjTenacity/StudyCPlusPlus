#!/bin/bash
testuser=rose

case $testuser in
rose)
	echo "hi,$testuser";;
ricky)
	echo "hello, ricky";;
*)
	echo "defaults";;
esac	

