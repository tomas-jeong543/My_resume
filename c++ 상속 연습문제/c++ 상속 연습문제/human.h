#pragma once
#include<iostream>
using namespace std;

class Human
{
private:
	int its_age;
public:
	Human() {};
	virtual ~Human() {};
	virtual void sol_1(int num);
};