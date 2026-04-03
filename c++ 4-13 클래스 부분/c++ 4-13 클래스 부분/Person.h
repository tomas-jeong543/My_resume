#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include<iostream>

using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(char* myname, int myage) :age(myage) {
		size_t len = strlen(myname) + 1;
	
		//생성자에서 동적 할당이 이루어진 경우
		name = new char[len];
		strcpy(name, myname);
	}



	void Show_info()
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	~Person() {
		cout << name << " 객체 소멸" << endl;
		//소멸자에서 동적 할당을 해제해야 한다
		delete[] name;
		
	}
};

