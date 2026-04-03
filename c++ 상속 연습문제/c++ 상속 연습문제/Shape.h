#pragma once
#include<iostream>
using namespace std;
class Shape
{
protected:
	int its_height;
	int its_width;


public:
	Shape() { cout << "shape constructor" << endl; }
	Shape(Shape& rhs):
		its_height(rhs.its_height),
		its_width(rhs.its_width)
	{ cout << "shape copy constructor" << endl; };

	virtual ~Shape() {}

	virtual Shape * clone() { return new Shape(*this); }
};