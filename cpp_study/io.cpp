#include <iostream>	
using namespace std;

#include <fstream>

//IO流
//文本本件操作
void mainTxt(){
	char* fname = "D://dest.txt";
	//输出流
	ofstream fout(fname);
	//创建失败
	if (fout.bad()){
		return;
	}
	fout << "sbdjskldnkls" << endl;
	fout << "=============" << endl;
	//关闭
	fout.close();

	//读取
	ifstream fin(fname);
	if (fin.bad()){
		return;
	}
	char ch;
	while (fin.get(ch)){
		//输出
		cout << ch;
	}
fin.close();
	system("pause");
}

//二进制文件
/*
void mainB(){
	char* src = "D://src.jpg";
	char* dest = "D://dest.jpg";

	//	输入流
	ifstream fin(src,ios::binary);
	//输出流
	ofstream fout(dest, ios::binary);

	if (fin.bad() ||fout.bad()){
		return;
	}
	while (!fin.eof()){
		//读取
		char buff[1024] = { 0 };
		fin.read(buff, 1024);

		//写入
		fout.write(buff,1024);
	}
	//关闭
	fout.close();
	fin.close();

	system("pause"); 
}
*/
/*
//C++对象的持久化
class Person
{
public:
	Person()
	{

	}
	Person(char * name, int age)
	{
		this->name = name;
		this->age = age;
	}
	void print()
	{
		cout << name << "," << age << endl;
	}
private:
	char * name;
	int age;
};


void main()
{
	Person p1("柳岩", 22);
	Person p2("rose", 18);
	//输出流
	ofstream fout("c://c_obj.data", ios::binary);
	fout.write((char*)(&p1), sizeof(Person)); //指针能够读取到正确的数据，读取内存区的长度
	fout.write((char*)(&p2), sizeof(Person));
	fout.close();

	//输入流
	ifstream fin("c://c_obj.data", ios::binary);
	Person tmp;
	fin.read((char*)(&tmp), sizeof(Person));
	tmp.print();

	fin.read((char*)(&tmp), sizeof(Person));
	tmp.print();

	system("pause");

}
*/


//stl standard template library 标准模板库
//util
//c++ 集合-> java 集合

#include <string>

/*
void main()
{
	//string-->C++的
	string s1 = "craig david";
	string s2(" 7 days");
	string s3 = s1 + s2;

	cout << s3 << endl;

	//转c字符串
	const char* c_str = s3.c_str();
	cout << c_str << endl;

	//s1.at(2);

	system("pause");
}
*/
//容器-->动态数组
#include <vector>

void main()
{
	//动态数组
	//不需要使用动态内存分配，就可以使用动态数组
	vector<int> v;
	v.push_back(12);
	v.push_back(10);
	v.push_back(5);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	system("pause");
}

