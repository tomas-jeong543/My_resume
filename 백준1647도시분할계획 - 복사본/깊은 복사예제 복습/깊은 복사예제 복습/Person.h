#define CRT_NO_WARNNINGS
#pragma once

#include<iostream>
#include<string>

using namespace std;

class Person { // Person 클래스 선언
	char* name;
	int id;
public:
	Person(int id, const char* name); // 생성자
	Person(Person& person); // 복사 생성자
	~Person(); // 소멸자
	void changeName(const char* name);
	void show() { cout << id << ',' << name << endl; }
};
Person::Person(int id, const char* name) { // 생성자
	this->id = id;
	int len = strlen(name); // name의 문자 개수
	this->name = new char[len + 1]; // name 문자열 공간 핟당
	strcpy(this->name, name); // name에 문자열 복사
}