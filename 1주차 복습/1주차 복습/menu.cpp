#include"menu.h"

using namespace std;
//매뉴판
int Do_Menu()
{
	int choice;
	cout << "\n\n *** Menu *** \n";
	cout << "(1) Draw Rectangle \n";
	cout << "(2) Area \n";
	cout << "(3) Perimeter \n";
	cout << "(4) Resize\n";
	cout << "(5) Quit\n";

	cin >> choice;
	return choice;
}
// 직사각형 그리는 메소드
void Do_Draw_Rect(Rectangle theRect)
{
	int height = theRect.Get_Height();
	int width = theRect.Get_Width();

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			cout << "*";
		cout << "\n";
	}
}
//넓이 구하는 메소드
void Do_Get_Area(Rectangle theRect)
{
	cout << "Area: " << theRect.Get_Area() << endl;
}
//둘레 구하는 메소드
void Do_Get_Perim(Rectangle theRect)
{
	cout << "Perimeter: " << theRect.Get_Perim() << endl;
}