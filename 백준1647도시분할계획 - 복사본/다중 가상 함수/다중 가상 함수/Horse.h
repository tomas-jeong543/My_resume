#pragma once
#include"Mammal.h"
class Horse:public Mammal
{
public:
	void Speak() const { cout << "Winnie!\n"; }
};