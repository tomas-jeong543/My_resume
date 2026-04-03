#pragma once
#include<iostream>

class Cat {

private:
	int its_Age;
	int its_Weight;
public:
	Cat(int age, int weight);
	~Cat(){}
	int Get_Age() const { return its_Age; }
	int Get_Weight() const { return its_Weight; }
};
