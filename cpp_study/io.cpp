#include <iostream>	
using namespace std;

#include <fstream>

//IO��
//�ı���������
void mainTxt(){
	char* fname = "D://dest.txt";
	//�����
	ofstream fout(fname);
	//����ʧ��
	if (fout.bad()){
		return;
	}
	fout << "sbdjskldnkls" << endl;
	fout << "=============" << endl;
	//�ر�
	fout.close();

	//��ȡ
	ifstream fin(fname);
	if (fin.bad()){
		return;
	}
	char ch;
	while (fin.get(ch)){
		//���
		cout << ch;
	}
fin.close();
	system("pause");
}

//�������ļ�
/*
void mainB(){
	char* src = "D://src.jpg";
	char* dest = "D://dest.jpg";

	//	������
	ifstream fin(src,ios::binary);
	//�����
	ofstream fout(dest, ios::binary);

	if (fin.bad() ||fout.bad()){
		return;
	}
	while (!fin.eof()){
		//��ȡ
		char buff[1024] = { 0 };
		fin.read(buff, 1024);

		//д��
		fout.write(buff,1024);
	}
	//�ر�
	fout.close();
	fin.close();

	system("pause"); 
}
*/
/*
//C++����ĳ־û�
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
	Person p1("����", 22);
	Person p2("rose", 18);
	//�����
	ofstream fout("c://c_obj.data", ios::binary);
	fout.write((char*)(&p1), sizeof(Person)); //ָ���ܹ���ȡ����ȷ�����ݣ���ȡ�ڴ����ĳ���
	fout.write((char*)(&p2), sizeof(Person));
	fout.close();

	//������
	ifstream fin("c://c_obj.data", ios::binary);
	Person tmp;
	fin.read((char*)(&tmp), sizeof(Person));
	tmp.print();

	fin.read((char*)(&tmp), sizeof(Person));
	tmp.print();

	system("pause");

}
*/


//stl standard template library ��׼ģ���
//util
//c++ ����-> java ����

#include <string>

/*
void main()
{
	//string-->C++��
	string s1 = "craig david";
	string s2(" 7 days");
	string s3 = s1 + s2;

	cout << s3 << endl;

	//תc�ַ���
	const char* c_str = s3.c_str();
	cout << c_str << endl;

	//s1.at(2);

	system("pause");
}
*/
//����-->��̬����
#include <vector>

void main()
{
	//��̬����
	//����Ҫʹ�ö�̬�ڴ���䣬�Ϳ���ʹ�ö�̬����
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

