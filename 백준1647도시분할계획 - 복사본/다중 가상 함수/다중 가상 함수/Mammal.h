#pragma once
#include<iostream>
using namespace std;

class Mammal
{
protected:
	int its_age;
public:
	Mammal() : its_age(1){}
	virtual ~Mammal() {}
	virtual void Speak() const { cout << "Mammal speak! \n"; }

};