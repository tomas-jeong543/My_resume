#include"Rectangle.h"
// const는 포인터 형의 전 후 어느 곳에도 위치가 가능하다 하지만 그 의미는 다르다
// const int *pone은 상수형 정수에 대한 포인터로 포인트 된 값은 변할 수 없다
//int *const p2는 상수형 포인터로  포인트된 정수값은 바뀔 수 있지만 다른 주소를 가르킬 수 없다
//cost int * const p3는 상수형 정수에 대한 상수형 포인터로 포인터의 값과 포인팅된 값 둘 다 변경할 수 없다

//예제

int main()
{
	Rectangle* pRect = new Rectangle;
	const Rectangle* pConstRect = new Rectangle;
	Rectangle* const pConstptr = new Rectangle;

	cout << "pRect width: " << pRect->Get_Width() << "feet \n";
	cout << "PConstant Width: " << pConstRect->Get_Width() << "feet \n";
	cout << "pConstptr: " << pConstptr->Get_Width() << "feet\n";

	pRect->Set_Width(10);
	//상수형으로 선언되었기 때문에 사각형의 길이는 변할 수 없다
	// pConstRect->Set_Width(10);
	pConstptr->Set_Width(10);
	cout << endl;

	cout << "pRect width: " << pRect->Get_Width() << "feet \n";
	cout << "pConstant width: " << pConstRect->Get_Width() << "feet \n";
	cout << "pConstptr width; " << pConstptr->Get_Width() << "feet \n";

	return 0;
}
/*
추가 내용 객체의 값이 변동이 없어야 하는 경우에는 상수형으로 설정 및 전달해 그 값을 보호하고 변할 수 있는 객체는 참조로 전달한다
변하지 않는 작은 객체는 값으로 전달한다
*/

