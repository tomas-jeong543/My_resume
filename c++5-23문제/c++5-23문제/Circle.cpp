#include "Circle.h"
#include"Rectangle.h"
#include<iostream>

using namespace std;

Circle::Circle(const double& r)
{
	this->radius = new double(r);
}

Circle::~Circle()
{
	delete radius;
}

double Circle::area() const
{
	return (*radius) * (*radius) * 3.14 ;
}

bool Circle::operator>(Shape& rhs)
{
	Shape* insptr = &rhs;
	
	return this->area() > insptr->area();

}
