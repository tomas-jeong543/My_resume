#include <iostream>
using namespace std;
//enum연산자 1,2,3,4,5
enum CHOICE { Draw_Rect = 1, Get_Area, GetPerim, Change_Dimensions, Quit };
//클래스 선언
class Rectangle
{
private:
	int its_Width;
	int its_Height;

public:
	//생성자 소몋자
	Rectangle(int width, int height);
	~Rectangle() {};
	//인라인 함수들
	int Get_Height() const { return its_Height; }
	int Get_Width() const { return its_Width; }
	int Get_Perim() const { return 2 * its_Height + 2 * its_Width; }
	int Get_Area() const { return its_Height * its_Width; }
	//
	void Set_Size(int new_Width, int new_Height);
};
