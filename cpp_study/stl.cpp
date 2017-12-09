#ifndef _ITERATOR_DEBUG_LEVEL
#define _ITERATOR_DEBUG_LEVEL 0
#else
#undef _ITERATOR_DEBUG_LEVEL
#define _ITERATOR_DEBUG_LEVEL 0
#endif

#include <iostream>
#include <string>
#include <algorithm> //算法

using namespace std;

//STL standard template libary 标准模(mu)板库 C++一部分，编译器自带
//Android NDK支持
//java.lang java.util包中API，java的一部分

//string初始化
/*
void main1()
{
	//string由c字符串衍生过来的
	string s1 = "craig david";
	string s2("7 days");
	string s3 = s2;
	string s4(10,'a');

	cout << s4 << endl;

	system("pause");
}

//string遍历
void main2()
{
	string s1 = "craig david";
	//			 ^
	int i = 0;
	//1 数组方式
	for (; i < s1.length(); i++)
	{
		cout << s1[i] << endl;
	}
	//2 迭代器指针
	for (string::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//3 at函数(charAt)
	// 可能会抛出异常
	try
	{
		for (int i = 0; i < s1.length() + 3; i++)
		{
			cout << s1.at(i) << " ";
		}
	}
	catch (...)
	{
		cout << "异常" << endl;
	}


	system("pause");
}


//string字符串->c字符串转换
void main3()
{
	//string -> char*
	string s1 = "walking away";
	const char* c = s1.c_str();
	printf("%s\n",c);

	//
	string s2 = c;

	//string->char[]
	//从string中赋值字符到char[]
	char arr[50] = {0};
	s1.copy(arr,4,0);
	
	cout << arr << endl;

	system("pause");
}


//字符串拼接
void main4()
{
	string s1 = "alan";
	string s2 = "jackson";
	
	//1.
	string s3 = s1 + s2;

	string s4 = " pray";

	//2.
	s3.append(s4);

	cout << s3 << endl;

	system("pause");
}

//字符串查找替换
void main5()
{
	string s1 = "apple google apple iphone";
	//从0开始查找"google"的位置
	int idx = s1.find("google", 0);
	cout << idx << endl;

	//统计apple出现的次数
	int idx_app = s1.find("apple",0);
	//npos大于任何有效下标的值
	int num = 0;
	while (idx_app != string::npos)
	{
		num++;
		cout << "找到的索引:" << idx_app << endl;
		idx_app+=5;
		idx_app = s1.find("apple", idx_app);
	}

	cout << num << endl;
	system("pause");
}

void main6()
{
	string s1 = "apple google apple iphone";
	//0-5（不包含5）替换为jobs
	s1.replace(0, 5, "jobs");
	cout << s1 << endl;

	//所有apple替换为jobs
	int idx = s1.find("apple", 0);
	while (idx != string::npos)
	{
		s1.replace(idx, 5, "jobs");
		idx += 5;
		idx = s1.find("apple", idx);
	}

	cout << s1 << endl;
	system("pause");
}

//删除（截取）和插入
void main7()
{
	string s1 = "apple google apple iphone";
	//删除a，找到a所在的指针
	string::iterator it = find(s1.begin(),s1.end(),'g');
	//只能删除一个字符
	s1.erase(it);
	
	//开头末尾插入字符串
	s1.insert(0, "macos");
	s1.insert(s1.length(), " facebook");

	cout << s1 << endl;
	system("pause");
}

//java StringBuffer才可变
//String 不可变
//大小写转换
void main8()
{
	string s1 = "JASON";
	//原始字符串的起始地址，原始字符串的结束地址, 目标字符串的起始地址, 函数名称
	transform(s1.begin(), s1.end()-1,s1.begin(), tolower);
	cout << s1 << endl;


	transform(s1.begin(), s1.end() - 1, s1.begin(), toupper);
	cout << s1 << endl;

	system("pause");
}


//容器
//Vector
//初始化
#include <vector>
void printVector(vector<int> &v)
{
	//通过数组的方式遍历
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}
void main9()
{
	//1.
	vector<int> v1;
	v1.push_back(20);
	v1.push_back(40);
	v1.push_back(15);
	v1.push_back(7);

	//2.
	vector<int> v2 = v1;

	//3.部分复制
	vector<int> v3(v1.begin(),v1.begin()+2);
	
	printVector(v3);
	

	system("pause");
}

//添加 删除
void mainA()
{
	//添加到结尾
	vector<int> v1;
	v1.push_back(20);
	v1.push_back(40);
	v1.push_back(15);
	v1.push_back(7);

	//访问头部
	v1.front() = 11;
	//访问尾部
	v1.back() = 90;

	//删除结尾的元素
	//v1.pop_back();
	while (v1.size() > 0)
	{
		cout << "末尾的元素：" << v1.back() << endl;
		v1.pop_back();
	}

	printVector(v1);

	system("pause");
}

//数组的方式
void mainB()
{
	vector<int> v1;
	v1.push_back(20);
	v1.push_back(40);
	v1.push_back(15);
	v1.push_back(7);

	v1[2] = v1[2] +10;

	//容器等价于动态数组	
	vector<int> v2(10);
	for (int i = 0; i < v2.size(); i++)
	{
		v2[i] = i + 1;
	}

	printVector(v2);

	system("pause");
}

//迭代器遍历
//迭代器的种类（正向，反向迭代器）
void mainC()
{
	vector<int> v1;
	v1.push_back(20);
	v1.push_back(40);
	v1.push_back(15);
	v1.push_back(7);
	//正向
	for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "-----------------" << endl;
	//反向迭代
	for (vector<int>::reverse_iterator it = v1.rbegin(); it < v1.rend(); it++)
	{
		cout << *it << endl;
	}

	system("pause");
}

//删除
void mainD()
{
	vector<int> v1(10);
	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] = i + 1;
	}

	//删除指定位置
	vector<int>::iterator it = v1.begin();
	it += 3;
	v1.erase(it);

	//distance(v1.begin(), it);

	//删除区间
	v1.erase(v1.begin(), v1.begin() + 3);

	for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
	{
		if (*it == 5)
		{		
			printf("%x\n", it);
			vector<int>::iterator tmp = v1.erase(it); //注意以后开发中编译器版本问题
			printf("%x,%x\n",it,tmp);
		}
	}

	//插入
	v1.insert(v1.begin() + 2, 100);
	v1.insert(v1.end() - 1, 200);

	printVector(v1);

	system("pause");
}

//双向队列
#include <deque>
void printDeque(deque<int>& q)
{
	for (int i = 0; i < q.size(); i++)
	{
		cout << q[i] << endl;
	}
}

void mainE()
{
	deque<int> d1;
	//添加到尾部
	d1.push_back(2);
	d1.push_back(10);
	//添加到头部
	d1.push_front(-90);
	d1.push_front(-30);	

	//printDeque(d1);

	//cout << d1.front() << endl;
	//cout << d1.back() << endl;

	//两个方向弹出
	//d1.pop_back();
	//d1.pop_front();

	printDeque(d1);

	//查找第一个-90元素索引位置，无需遍历
	deque<int>::iterator it = find(d1.begin(),d1.end(),-90);
	if (it != d1.end())
	{
		int idx = distance(d1.begin(), it);
		cout << "索引位置为：" << idx << endl;
	}


	system("pause");
}

//数据结构 算法 分离
//Collections.shuff sort
*/