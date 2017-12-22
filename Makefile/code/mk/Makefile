#三要素
#目标，依赖，命令

#myapp目标（最终目标，第一行是最终目标）
#:后的文件，这些都是依赖
#命令TAB键开头，如何由依赖文件得到目标,,,,会去检查依赖文件是否比目标文件 更新(创建时间更接近)
#step 1
#myapp:main.o plus.o minus.o multi.o divi.o
#	gcc main.o plus.o minus.o multi.o divi.o -o myapp

#目标：main.o
#依赖：main.c
#命令：gcc -c main.c
#main.o:main.c
#	gcc -c main.c
#plus.o:plus.c
#	gcc -c plus.c
#minus.o:minus.c
#	gcc -c minus.c
#multi.o:multi.c
#	gcc -c multi.c
#divi.o:divi.c
#	gcc -c divi.c

#step 2
#变量
#OBJECTS=main.o plus.o minus.o multi.o divi.o

#step 3
#所有.c源文件
SOURCES=$(wildcard *.c)
#把.c后缀，替换成.o后缀
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

myapp:$(OBJECTS)
#自动化变量 $^表示所有依赖，$@表示目标
	gcc $^ -o $@

#通配符
#main.o:main.c
%.o:%.c
#gcc -c main.c -o main.o
	gcc -c $^ -o $@


#没有依赖
#clean清除所有的.o中间文件
#伪目标
.PHONY:clean

clean:
	rm -f *.o
	rm -f myapp

#递归展开式
#可以引用还没有定义的变量，展开是引用时展开
str2=$(str1)
str1=hello

#直接展开式
#必须引用定义好了的变量，定义之后就会展开
str3 := android
str4 := $(str3)
str5 := $(str1) world

#变量的值追加
str5 += hello

#自定义函数
myfun=$2 $1
#变量等于函数的执行结构
myfun_ret=$(call myfun,20,10)

test:
	@echo $(SOURCES)
	@echo $(OBJECTS)
	@echo $(str2)
	@echo $(str4)
	@echo $(str5)
	@echo $(myfun_ret)
	@echo $(call myfun,30,40)
