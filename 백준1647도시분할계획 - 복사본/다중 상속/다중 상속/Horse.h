#pragma once
#include<iostream>
using namespace std;

class Horse
{
private:
	int its_age;
public:
	Horse(): its_age(5) { cout << "Horse constructor ... "; }
	virtual ~Horse() { cout << "Horse distructor ..."; }
	virtual void Whinny() const { cout << "Whinny!... "; }
};