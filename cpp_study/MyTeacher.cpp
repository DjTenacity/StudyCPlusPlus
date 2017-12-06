#include "MyTeacher.h"
#pragma once


void MyTeacher::setAge(int age){
	this->age = age;
};
int MyTeacher::getAge(){
	return  this->age;
};
void MyTeacher::setName(char* name){
	this->name = name;
};
char* MyTeacher::getName(){
	return  this->name;
};