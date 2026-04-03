#include"Dog.h"

Dog::Dog(const Dog& rhs):
	Mammal(rhs)
{
	cout << "Dog Copy constructor... \n";
}