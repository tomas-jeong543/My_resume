#pragma once
#include<iostream>
class Rectangle
{

private:
	int its_width;
	int its_height;
public:
	//중첩 생성자 이는 매우 강력하고 융퉁성이 있는 개념이다
	Rectangle();
	Rectangle(int width, int height);
	~Rectangle() {};

	//높이와 너비 반환 함수
	int Get_Height() const{ return its_height; }
	int Get_Width() const { return its_width; }

	//중첩된 클래스 함수 DrawShape
	void Draw_Shape() const;
	void Draw_Shape(int awidth, int aheight, bool use_curr_value = false) const;
};