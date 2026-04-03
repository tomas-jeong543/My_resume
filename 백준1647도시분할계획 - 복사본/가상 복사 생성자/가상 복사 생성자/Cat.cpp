#include"Cat.h"

Cat::Cat(const Cat& rhs) :Mammal(rhs)
{
	cout << "Cat Copy constructor.. \n";
}