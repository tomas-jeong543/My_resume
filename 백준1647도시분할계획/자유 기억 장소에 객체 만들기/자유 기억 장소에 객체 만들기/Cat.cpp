#include"Cat.h"

Cat::Cat()
{
	std::cout << "Constructor called \n" ;
	its_Age = 1;
}

Cat:: ~Cat()
{
	std::cout << "Destructor called \n";
}