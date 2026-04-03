#pragma once
#include"Mammalh.h"
class Cat :public Mammal
{
public:
	Cat() { cout << "Cat constructor... \n"; }
	~Cat() { cout << "Cat distructor... \n"; }
	Cat(const Cat& );
	void Speak() const { cout << "Meow\n"; }
	virtual Mammal* Clone() { return new Cat(*this); }
};