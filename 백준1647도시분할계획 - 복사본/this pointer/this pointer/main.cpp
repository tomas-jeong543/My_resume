#include<iostream>
#include"Rectangle.h"
using namespace std;

int main()
{
	Rectangle theRect;
	cout << "theRect is " << theRect.Get_Length() << "feet long. \n";
	cout << "theRect is " << theRect.Get_Width() << "feet wide. \n";
	
	theRect.Set_Length(20);
	theRect.Set_Width(10);

	cout << "theRect is " << theRect.Get_Length() << "feet long. \n";
	cout << "theRect is " << theRect.Get_Width() << "feet wide. \n";

	return 0;
	
}
