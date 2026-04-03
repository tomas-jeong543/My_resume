#include "Rectangle.h"
#include<iostream>
#include"Circle.h"
using namespace std;
Rectangle::Rectangle(const double& w, const double& h)
{
	this->width = new double(w);
	this->height = new double(h);
}

Rectangle::~Rectangle()
{
	delete width;
	delete height;
}

double Rectangle::area() const
{
	return (*width) * (*height);
}

bool Rectangle::operator>(Shape& rhs)
{

	Shape* insptr = &rhs;
	return this->area() > insptr->area();
	
}


