#include<iostream>
#include<string>
#include<memory>
#include"Point.h"
#include"Rect.h"
using namespace std;
//생성자 수업

int main()
{
	cout << "202211364 정명훈" << endl;
	// 애러 발생Point pt;
	
	/*Point pt1(10);
	Point pt2(100, 100);
	pt1.DrawPoint();
	pt2.DrawPoint();*/

	//객체 만들어진 순서 중요
	//Rect rect(10, 10, 100, 100);
	//Rect rect2(200, 200, 400, 400);
	//rect.DrqwRect();
	//rect2.DrqwRect();


	Rect* prect = new Rect(10, 10, 100, 100);
	//new로 생성시 소멸자 호출을 위해서는 delete가 필요하다
	delete prect;

	return 0;
}