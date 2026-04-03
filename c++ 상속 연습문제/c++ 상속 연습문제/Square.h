#pragma once
#include<iostream>
using namespace std;

#include"Rectangle.h"
class Square :public Rectangle
{
public:
	Square() {};
	Square(int height);
	virtual ~Square() {};

	Square(Square& rhs );
	//가상 복사 생성자
	Square* clone() { return new Square(*this); }
};