#pragma once
#include<iostream>
using namespace std;

class Horse
{
private: 
	int its_age;
public:
	virtual void Gallop() { cout << "Galloping ... \n"; }
};