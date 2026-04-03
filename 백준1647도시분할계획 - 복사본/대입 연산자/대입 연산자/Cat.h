#pragma once
#include<iostream>
using namespace std;

class Cat
{
private:
	int *its_age;
	int *its_weight;

public:
	//기본 생성자
	Cat();
	~Cat();
	Cat(const Cat&);
	int Get_Age() const { return *its_age; }
	int Get_Weight() const { return *its_weight; }
	void Set_Age(int x) { *its_age = x; }
	void Set_Weight(int y) { *its_weight = y; }
	Cat& operator = (const Cat &);
	
};
