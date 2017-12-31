#!/bin/bash
NDK=10
text="i love shell"

#命令的执行结果的输出作为变量的值
text1=`date`
text2=$(who)

echo $NDK
echo $text
echo "$text very much"
echo "\$NDK"
echo $text1
echo $text2

#输出重定向
ls -al > test2

#输入重定向
wc < test3


