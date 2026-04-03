#include "Point.h"

Point::Point(const int& x, const int& y)
{
	this->xpos = make_shared<int>(x);
	this->ypos = new int(y);
}
