#include "Rect.h"
#include<iostream>

using namespace std;
//하위 객체를 객체의 생성자를 이용해서 초기화시킨다
Rect::Rect(const int& x1, const int& y1, const int& x2, const int& y2):upleft(x1,y1), lowright(x2,y2)
{
	cout << x1 << "Rectangle 객체 생성" << endl;
}

void Rect::DrqwRect()
{
	upleft.DrawPoint();
	lowright.DrawPoint();
}

Rect::~Rect()
{
	cout << upleft.Getx()  << "Rectangle 객체 소멸" << endl;
}
