#include"Square.h"
#include"Rectangle.h"
Square::Square(int height):
	Rectangle::Rectangle(height, 10){
	cout << "Squre construcor\n";
}

Square::Square(Square& rhs) :
	Rectangle(rhs)
{
	cout << "Square copy constructor" << endl;
}