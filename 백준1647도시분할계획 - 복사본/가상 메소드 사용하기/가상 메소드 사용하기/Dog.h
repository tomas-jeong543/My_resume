#pragma once
#include"Mammal.h"
class Dog :public Mammal
{
public:
	Dog() { cout << "Dog construcot ... \n"; }
	
	virtual ~Dog() { cout << "Dog distructor ... \n"; }
	
	void Speak() const { cout << "Woof!\n"; }
	void  WagTail() { cout << "Wagging tail \n"; }
	void Move() const { cout << "Dog moves 5 steps ... \n"; }

};