#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
private:
    double* radius;
public:
    Circle(const double& r);
    virtual ~Circle();
    double area() const override;
    virtual bool operator>(Shape& rhs) override;
};

