 #!/bin/bash

##标准输入输出---> ./14.sh 1> test7 将标准输出重定向到test7文件，不再输出到屏幕上
#0 STDIN 
#1 STDOUT 标准输出
#2 STDERR 标准错误

#永久重定向
exec 1>test7
exec 2>test8

#自定义输出
exec 7>test9

echo "cc zz" >&7
echo "cc yy"

ls -a ./ff



