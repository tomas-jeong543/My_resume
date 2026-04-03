#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

#include<iostream>
#include"Player.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Player p1("홍길동"), p2("고길동");
	Dice d1, d2;
	//그냥 모든 형태(포인터 참조자 동적할당 그냥 변수라 생각하면 된다)로 사용이 가능하다 
	Dice* pdice = &d1;

	Dice** dicearray = new Dice * [3];
	cout << "202211364 정명훈" << endl;
	//주사위를 굴리는 과정
	cout << "p1가 주사위를 굴립니다" << endl;
	p1.roll(d1, d2);
	system("pause");
	cout << "p2가 주사위를 굴립니다" << endl;
	p2.roll(d1, d2);
	//주사위의 눈의 합 출력
	cout << p1.Get_Total() << " " << p2.Get_Total() << endl;

	//주사위 눈의 합에 따른 승부 출력
	if (p1.Get_Total() > p2.Get_Total()) {
		
		cout << p1.Getname() << "승리" << endl;
	}
	else if (p1.Get_Total() == p2.Get_Total()) {
		cout << "무승부" << endl;
	}
	else 	cout << p2.Getname()<< "승리" << endl;

	delete[] dicearray;
	dicearray = nullptr;
}