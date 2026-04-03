#pragma once
#include"Mammalh.h"
class Dog : public Mammal
{
public:
	Dog() { cout << "Dog Constructor ... \n"; }
	virtual ~Dog() { cout << "Dog distructor ... \n"; }
	Dog(const Dog& rhs);
	void Speak() const { cout << "Woof!\n"; }
	//개 자신과 포유류의 복사 생성자를 호출한다
	virtual Mammal* Clone() { return new Dog(*this); }
};