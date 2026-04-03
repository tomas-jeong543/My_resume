#pragma once
#include"Mammal.h"
class Cat:public Mammal
{
public:
	void Speak() const { cout << "Meow\n"; }
};