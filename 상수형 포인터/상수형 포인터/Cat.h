#pragma once
#include<iostream>
using namespace std;
class Cat {

private:
	int its_age;
public:
	Cat();
	Cat(Cat&);
	~Cat();

	int Get_Age() const {
		return its_age;}
	void Set_Age(int age) { its_age = age; }
};