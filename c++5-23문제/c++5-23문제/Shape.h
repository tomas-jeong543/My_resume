#pragma once
class Shape
{
public:
	virtual double area() const = 0;
	virtual bool operator>(Shape& rhs) = 0;
	Shape() = default;
	virtual ~Shape() {};
};

