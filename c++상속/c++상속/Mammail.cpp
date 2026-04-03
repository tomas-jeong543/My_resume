#include"MAmmal.h"

Mammal::Mammal()
	:its_age(1), its_weight(5)
{
	cout << "Mammal constructor\n";
}

Mammal::Mammal(int age) :
	its_age(age)
	, its_weight(5)
{
	cout << "Mammal constructor\n";
}

Mammal::~Mammal()
{
	cout << "Mammal distructor\n";
}