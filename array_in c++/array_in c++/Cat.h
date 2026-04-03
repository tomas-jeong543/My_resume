#pragma once
#include<iostream>
using namespace std;

class Cat
{
private:
	int its_age;
	int its_weight;
public:
	Cat() {	its_age = 1, its_weight = 5;}
	~Cat() {}
	int Get_Age() const { return its_age; }
	int Get_Weight() const { return its_weight; }
	void Set_Age(int x) { its_age = x; }

};