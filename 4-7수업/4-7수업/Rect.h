#pragma once
#include"Point.h"

class Rect
{
private:

	Point upleft, lowright;
public:
	Rect(const int& x1, const int& y1, const int& x2, const int& y2);
	void DrqwRect();
	~Rect();
};

