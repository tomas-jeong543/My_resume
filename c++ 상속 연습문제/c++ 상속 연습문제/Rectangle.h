#pragma once
#include"Shape.h"
class Rectangle: public Shape 
{
public:
	Rectangle() {};
	Rectangle(int height, int width) { its_height = height, its_width = width;
	cout << "Rectangle constructor\n";}
	Rectangle(Rectangle& rhs):Shape(rhs) { cout << "Rectangle copy constructor \n"; };
	virtual ~Rectangle(){}
	
	int Get_width() const { return its_width; }
	int Get_height()const { return its_height; }
	void Set_width(int w) { its_width = w; }
	void Set_height(int h) { its_height = h; }

	//가상 복사 생성자는 사실상 그냥 복사 생성자를 호출하는 함수라고 생각하면 된다
	 virtual Rectangle* clone()  { return  new Rectangle(*this); }
};