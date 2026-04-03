#pragma once
#include<iostream>

using namespace std;

class Mammal
{
protected:
	int its_age;
public:

	Mammal() :its_age(1) { cout << "Mammal constructor ... \n"; }
	virtual ~Mammal() { cout << "Mammal distructor ... \n"; }
	void Move() const { cout << "Mammal move one sep... \n"; }
	virtual void Speak() const { cout << "Mammal sound ... \n"; }
};