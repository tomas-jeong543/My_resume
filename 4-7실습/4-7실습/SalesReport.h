#pragma once
#include"Salseman.h"
#include<string>
#include<memory>
using namespace std;

using DoubleSalsemanptr =  unique_ptr<unique_ptr<Salseman>[]>;

class SalesReport
{
private:
	const int NUM;
	double averageSales;
	double highestSales;
	//	Salseman* team = new Slaseman[NUMBER; 이거는 포인터가 아닌 객체를 default로 다 저장하는 배열을 선언하는 거다
	//이 문장의 의미는 Salseman*타입의 주소를 가르키는 변수이다
	DoubleSalsemanptr team;
	int counter = 0;
public:
	//기본 생성자 제거
	SalesReport() = delete;
	
	SalesReport(const int& num);
	//동적 할당이 이루어짐으로 소멸자는 반드시 필요하다
	~SalesReport();

	void computeStates();
	Salseman& getBestClerk();
	string getTeamInfo();
	void addMember();
};