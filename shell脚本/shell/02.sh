#!/bin/bash
a=10
b=20
#expr命令
c=$(expr $b / $a)
#方括号
d=$[$a * 2]
#bc 浮点数计算
#| 管道，一个命令的输出作为另外一个命令的输入
#scale是自带的内建变量
e=$(echo "scale=4; $a / 3" | bc)

#内联输入重定向
f=$(bc << EOF
scale=4
a1 = ($a * $b)
a1 / 3
EOF
)


echo "c:$c"
echo "d:$d"
echo "e:$e"
echo "f:$f"
