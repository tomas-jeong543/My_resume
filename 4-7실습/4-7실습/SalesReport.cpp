

#include "SalesReport.h"
#include<iostream>
using namespace std;

SalesReport::SalesReport(const int& num) : NUM(num)
{
	
	//동적할당만 생성자에서는 담당
	if (NUM > 0) {
		team = make_unique<unique_ptr<Salseman>[]>(NUM);
		if (team == nullptr) {
			cout << "메모리 오류" << endl;
			exit(1);
		}
	}
	else {
		team.release();
	}
}

SalesReport::~SalesReport()
{
	//f (team != nullptr) {
	//	//지금은 포인터 배열을 삭제하고 있음으로 포인터가 동적으로 할당받은 영업사원 내용 역시 지워야 한다
	//	for (int i = 0; i < counter; i++) {
	//		if (team[i] != nullptr) {
	//			delete team[i];
	//		}
	//		team[i] = nullptr;
	//	}

	//	delete[] team;
	//	team = nullptr;
	

	//delete[] team.get();
	for (int i = 0; i < counter; i++) {
		delete team[i].get();
	}
	delete[] team.get();
	team.release();
	
}

void SalesReport::computeStates()
{
	if (team == nullptr || counter == 0){
		cout << "팀원이 아무도 없습니다" << endl;
		return;
	}

	double sum = 0;

	highestSales = team[0].get()->getSales();

	for (int i = 0; i < counter; i++)
	{
		sum += team[i].get()->getSales();
		if (highestSales < team[i].get()->getSales()) {
			highestSales = team[i].get()->getSales();
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

	Salseman& Best_Salesma = *team[0].get();
	double max = Best_Salesma.getSales();


	for (int i = 1; i < counter; i++) {
		if (max < team[i].get()->getSales()) {
			max = team[i].get()->getSales();
			Best_Salesma = *team[i].get();
			
		}
	}

	return Best_Salesma;

}

string SalesReport::getTeamInfo()
{
	string teaminfo = "";

	//팀원이 없는 경우에 대한 예외처리
	if (team == nullptr || counter == 0) {
		cout << "팀원이 아무도 없습니다" << endl;
		return teaminfo;
	}

	
	for (int i = 0; i < counter; i++) {
		teaminfo += team[i].get()->get_Salesman_Info();
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

	//팀원 정보를 초기화 할 떼 유니크 포인터의 경우에는 reset이 필요하다
	if (counter < NUM && team != nullptr) {
		team[counter++].reset(new Salseman(name, sales));
	}
}
