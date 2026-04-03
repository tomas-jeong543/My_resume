#include "﻿SalesReport.h"
#include<iostream>

using namespace std;
using ShareddDptr = shared_ptr<shared_ptr<Salseman>[]>;

SalesReport::SalesReport(const int& num) : NUM(num)
{
	averageSales = 0.0;
	highestSales = 0.0;
	//동적할당만 생성자에서는 담당
	if (NUM > 0) {
		team = make_shared<shared_ptr<Salseman>[]>(NUM);
		
		for (int i = 0; i < NUM; i++) {
			team[i] = nullptr;
		}
	}
	else {

		team = nullptr;
	}
}

SalesReport::~SalesReport()
{
	//team.reset();
	this->team.reset();
}

void SalesReport::computeStates()
{
	if (team == nullptr || counter <= 0 || counter > NUM + 1) {
		cout << "팀원이 아무도 없거나 모든 팀원이 정원을 초과했습니다" << endl;
		return;
	}


	double sum = 0;
	Salseman* ins = team[0].get()
		;

	highestSales = ins->getSales();
	

	for (int i = 0; i < counter; i++)
	{
		Salseman* ins = team[i].get();
		sum += ins->getSales();
		if (highestSales < ins->getSales()) {
			highestSales = ins->getSales();
		}

	}

	averageSales = sum / counter;

	cout << "평군 팜매액: " << averageSales << "최고 판매액: " << highestSales << endl;

}

Salseman& SalesReport::getBestClerk()
{
	if (team == nullptr || counter == 0) {
		cout << "팀원이 아무도 없습니다" << endl;
		//애초에 팀원이 존재하지 않으면 누가 최고인지도 알 수 없어 그냥 프로그앰 종료시킨다
		exit(1);
	}

	double max = team[0].get()->getSales();


	for (int i = 1; i < counter; i++) {
		if (team[i] == nullptr) {
			continue;
		}

		Salseman* ins = team[i].get();
		if (max < ins->getSales()) {
			max = ins->getSales();
		}
	}

	for (int i = 1; i < counter; i++) {
		Salseman* ins = team[i].get();
		if (max == ins->getSales()) {
			Salseman& Best_Salesma = *ins;
			return Best_Salesma;
			
		}
	}
}

string SalesReport::getTeamInfo()
{
	string teaminfo = "";

	//팀원이 없는 경우에 대한 예외처리
	if (team == nullptr || counter <= 0 || counter > NUM + 1) {

		cout << "팀원이 아무도 없습니다" << endl;
		return teaminfo;
	}

	for (int i = 0; i < counter; i++) {
		if (team[i] == nullptr) {
			continue;
		}
		Salseman* ins = team[i].get();
		teaminfo += ins->get_Salesman_Info();
	}

	return teaminfo;
}

void SalesReport::addMember()
{
	cout << "이름과 판매금액 입력" << endl;
	string name;
	double sales;
	cin >> name >> sales;

	//team이 nullptr인 경우도 고려가 필요
	if (counter < NUM && team != nullptr) {
		while (team[counter] == nullptr) {
			team[counter] = make_shared<Salseman>(name, sales);
		}
		counter += 1;
	}

}