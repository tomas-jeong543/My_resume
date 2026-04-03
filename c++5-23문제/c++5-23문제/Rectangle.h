#pragma once
#include "Shape.h"
class Rectangle :
    public Shape
{
private:
    double* width;
    double* height;
public:
    Rectangle(const double& w, const double& h);
    virtual ~Rectangle();
    double area()const override;
    bool operator>(Shape& rhs) override;
};

