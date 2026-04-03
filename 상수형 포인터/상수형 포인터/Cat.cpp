#include"Cat.h"

Cat::Cat()
{
	cout << "Cat constructor ... \n";
	its_age = 1;
}

Cat::Cat(Cat&){
	cout << "simple Cat copy constructor ... \n";
	its_age = 1;
}

Cat::~Cat()
{
	cout << "Simple Cat distructor... \n";
}
