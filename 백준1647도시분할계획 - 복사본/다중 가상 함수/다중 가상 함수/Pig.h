#pragma once
#include"Mammal.h"
class Pig :public Mammal
{
public:
	void Speak() const { cout << "Oink\n"; }
};