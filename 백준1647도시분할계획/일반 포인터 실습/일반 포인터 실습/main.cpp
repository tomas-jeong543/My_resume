#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif


#include<iostream>
#include"﻿SalesReport.h"

//1 이 함수들 다 완성 2 스마트 포인터로 표현

void show(const Salseman& man) {
	cout << man.name << endl;
}

int main()
{
	Salseman s1("greenjoa", 100.5);
	show(s1);
	//뒤에 s을 붙히면 string이 됨 단 using 구문이 들어가야 함
	//Salseman s2 = "greenjoa2"s;
	/*Salseman* s1 = Salseman::Get_instance();*/

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	cout << "202211364 정명훈" << endl;
	Salseman s1("greenjoa", 100.5);
	show(s1);
	SalesReport team1(5);
	

	for (int i = 0; i < 5; i++) {
		team1.addMember();
	}

	cout << "최고 판매 사원" << endl;
	cout << team1.getBestClerk().get_Salesman_Info() << endl;
	cout << "팀 정보" << endl;
	cout << team1.getTeamInfo() << endl;

	return 0;
}