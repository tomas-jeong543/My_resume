#include<iostream>
//hpp 파일에는 클래스 선언만 한다
class Point
{
private:
	int itsX;
	int itsY;

public:
	void setX(int x) { itsX = x; }
	void setY(int y) { itsY = y; }
	int getX() const { return itsX; }
	int getY() const { return itsY; }
};

class Rectangle
{
private:
	Point itsUpper_Left, itsUpper_Right, itsLower_Left, itsLower_Right;
	int itsTop, itsLeft, itsBottom, itsRight;

public:

	Rectangle(int top, int left, int bottom, int right);
	~Rectangle() {};
	
	int Get_Top() const { return itsTop; }
	int Get_Left() const { return itsLeft; }
	int get_Bottom() const { return itsBottom; }
	int Get_Right() const { return itsRight; }

	Point GetUpper_Left() const { return itsUpper_Left; }
	Point GetUpper_Right() const { return itsUpper_Right; }
	Point GetLower_Left() const { return itsLower_Left;  }
	Point FetLower_Right() const { return itsLower_Right; }

	void SetUpper_Left(Point Location) { itsUpper_Left = Location; }
	void SetLower_Left(Point Location) { itsLower_Left = Location; }
	void SetUpper_Right(Point Location) { itsUpper_Right = Location; }
	void SetUppert_Left(Point Location) { itsLower_Right = Location; }

	void Set_Top(int top) { itsTop = top; }
	void Set_Bottom(int bottom) { itsBottom = bottom; }
	void Set_Right(int right) { itsRight = right; }
	void Set_Left(int left) { itsLeft = left; }

	int GetArea() const;
};