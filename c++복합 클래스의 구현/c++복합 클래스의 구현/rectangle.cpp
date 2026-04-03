#include"rectangle.hpp"
//그리고 맴버 함수는cpp파일에 만든다
//최대한 할 수 있는 많은 곳에서 const를 사용한다

Rectangle::Rectangle(int top, int left, int bottom, int right)
{
	itsTop = top;
	itsLeft = left;
	itsBottom = bottom;
	itsRight = right;

	itsUpper_Left.setX(left);
	itsUpper_Left.setY(top);

	itsUpper_Right.setX(right);
	itsUpper_Right.setY(top);

	itsLower_Left.setX(left);
	itsLower_Left.setY(bottom);

	itsLower_Right.setX(right);
	itsLower_Right.setY(bottom);
}

int Rectangle::GetArea() const
{
	int Width = itsRight - itsLeft;
	int height = itsTop - itsBottom;
	return (Width * height);
}
//
int main()
{
	Rectangle MyRectangle(100, 20, 50, 80);

	int Area = MyRectangle.GetArea();

	std::cout << "Area: " << Area << "\n";
	std::cout << "Upper Left X coordinate: ";
	std::cout << MyRectangle.GetUpper_Left().getX();
	std::cout << "Upper_Left Point: ";
	
	return 0;
}