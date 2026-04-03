#include"Mammalh.h"

Mammal::Mammal(const Mammal& rhs) : its_age(rhs.Get_Age())
{
	cout << "Mammal copy Constructor ... \n";
}

