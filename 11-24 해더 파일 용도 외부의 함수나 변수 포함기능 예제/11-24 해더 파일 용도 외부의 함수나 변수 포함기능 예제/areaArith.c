#include "basicArith.h"

double TriangularArea(double base, double height)
{
	return Div(Mul(base, height), 2);
}

double CircleArea(double rad)
{
	return Mul(Mul(rad, rad), PI);
}