#include"Rectangle.h"
//생성자
Rectangle::Rectangle(int width, int height)
{
	its_Height = height;
	its_Width = width;
}
//너비와 높이 설정
void Rectangle::Set_Size(int new_Width, int new_Height)
{
	its_Height = new_Height;
	its_Width = new_Width;
}