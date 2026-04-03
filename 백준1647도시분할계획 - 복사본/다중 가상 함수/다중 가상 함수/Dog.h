#pragma once
#include"Mammal.h"
class Dog :public Mammal
{
public:
	virtual void Speak() const { cout << "Woof!\n"; }
};