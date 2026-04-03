#include<iostream>
#include "cat.h"
//생성자와 소멸자 구현
Cat::Cat(int initalAge)
{
	itsAge = initalAge;
}

Cat:: ~Cat()
{

}

//실제로 테스트 하는 경우의 수
int main()
{
	Cat Frisky(5);
	Frisky.Meow();
	std::cout << "Frisky is a cat who is ";
	std::cout << Frisky.GetAge() << " Years old. \n";
	Frisky.Meow();
	Frisky.SetAge(7);
	std::cout << "Frisky is now ";
	std::cout << Frisky.GetAge() << "Years old\n";
	Frisky.~Cat();
	return 0;
}