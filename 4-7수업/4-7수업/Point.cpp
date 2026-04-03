#include "Point.h"
#include<iostream>

using namespace std;

Point::Point(int x):Point(x,10){}

Point::Point(int x, int y): x(x), y(y)
{
	cout << x << "," << y << "포인트 생성" << endl;
}

void Point::DrawPoint()
{
	cout << x << "," << y << endl;
}

Point::~Point()
{
	cout << x << "," << y << "포인트 소멸" << endl;
}
