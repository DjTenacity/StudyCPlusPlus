#!/bin/bash
a=10
b=2
c=$[$a / $b]
echo result is $c

var1=20
var2=3.1333
var3=$(echo "scale=4; $var1 * $var2" | bc)
echo result is $var3

#退出状态码
exit 5


