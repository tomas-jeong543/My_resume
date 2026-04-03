#include<iostream>
#include"menu.h"
int main()
{
	//변수들 선언 및 초기화
	Rectangle the_Rect(30, 5);
	int choice = Draw_Rect;
	int fQuit = false;
	//종료 메뉴 선택전 까지 계속 반복
	while (!fQuit)
	{
		//메뉴 선택
		choice = Do_Menu();
		//메뉴판 번호 범위 바깥의 숫자인 경우에는 예외처리
		if (choice < Draw_Rect || choice > Quit)
		{
			cout << "\n invailid choice, please try again \n\n";
			continue;
		}
		//스위치 문으로 동작들 구현
		switch (choice)
		{
		case Draw_Rect:
			Do_Draw_Rect(the_Rect);
			break;
		case Get_Area:
			Do_Get_Area(the_Rect);
			break;
		case GetPerim:
			Do_Get_Perim(the_Rect);
			break;
		case Change_Dimensions:
			//유일하게 다른 메소드들로 구현
			int new_Length, new_Width;
			cout << "\n New width: ";
			cin >> new_Width;
			cout << "New height: ";
			cin >> new_Length;
			the_Rect.Set_Size(new_Width, new_Length);
			Do_Draw_Rect(the_Rect);
			break;
		case Quit:
			fQuit = true;
			break;
		default:
			cout << "Error in Choice\n";
			fQuit = true;
			break;

		}
	}
	return 0;
}