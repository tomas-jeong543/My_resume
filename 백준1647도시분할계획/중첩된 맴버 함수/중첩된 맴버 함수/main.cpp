#include"Rectangle.h"
using namespace std;



int main()
{
	Rectangle the_rect(30, 5);
	std::cout << "Draw_Shape(): \n";
	the_rect.Draw_Shape();
	std::cout << "\n Draw_Shape(40,2,  flase): \n";
	the_rect.Draw_Shape(40, 2, false);
	std::cout << "\n Draw_Shape(40,2, true): \n";
	the_rect.Draw_Shape(40, 2, true);

	Rectangle the_rect2;
	std::cout << "the rect2 widtht: "<<  the_rect2.Get_Width() << "\n";
	std::cout << "the rect2 height: " << the_rect2.Get_Height() << "\n";
	return 0;
}