#include "TicketManger.h"
#include<iostream>
#include"GeneralTicket.h"
#include"AdvancedTicket.h"
using namespace std;

TicketManger::~TicketManger()
{
	if (ticket != nullptr) {
		for (int i = 0; i < totalNumber; i++) {
			if (ticket[i] != nullptr) {
				//cout << ticket[i] << endl;
				delete ticket[i];
			}
		}
		delete[] ticket;
	}
}

TicketManger::TicketManger(const string& name, const int number)
{
	this->m_name = name;
	this->totalNumber = number;
	ticket = new Ticket * [totalNumber];
	for (int i = 0; i < totalNumber; i++) {
		ticket[i] = nullptr;
	}
	if (ticket == nullptr) { return; }
}

void TicketManger::buy(Ticket* t)
{
	if (count < totalNumber) {
		ticket[count++] = t;
	}
	else {
		cout << "티켓을 더 이상 예약할 수 없습니다." << endl;
	}
}

void TicketManger::show() const
{
	double totalprice = 0;
	cout << "--------티켓 예약 현황----------------" << endl;
	cout << "총 예약 매수: " << count << endl;
	cout << "-------------------------------------" << endl;
	for (size_t i = 0; i < count; i++) {
		ticket[i]->show();
		cout << endl;
		totalprice += ticket[i]->getPrice();
		//cout << "mys: " << totalprice << endl;
	}
	cout << "-------------------------------------" << endl;
	cout << "총 예약 금액: " << totalprice << endl;
	cout << "-------------------------------------" << endl;
}

void TicketManger::showGeneralTicket(const bool& card)
{
	double totalprice = 0;
	cout << "--------일반 예약 현황-------------" << endl;
	cout << "카드 결제 여부: " << (card ? "true":"false") << endl;
	cout << "-----------------------------------" << endl;
	for (size_t i = 0; i < count; i++) {


		//동적 케스팅을 하면 다운 케스팅이 가능하며 이 값이 null이 아니면 다운 캐스팅이 성공한 거다
		GeneralTicket* ins = dynamic_cast<GeneralTicket*>(ticket[i]);
		if (ins != nullptr && card == ins->getpaybyCredit()) {
			ins->show();
			cout << endl;
			totalprice += ins->getPrice();
			
		}
	}
	cout << "-----------------------------------" << endl;
	cout << "총 예약 금액: " << totalprice << endl;
	cout << "-----------------------------------" << endl;
}

void TicketManger::showAdvancedTicket()
{
	double totalprice = 0;
	cout << "--------사전 예약 현황-------------" << endl;
	cout << endl;
	for (size_t i = 0; i < count; i++) {

		AdvancedTicket* ins = dynamic_cast<AdvancedTicket*>(ticket[i]);
		if (ins != nullptr) {
			ins->show();
			cout << endl;
			totalprice += ins->getPrice();
		}
	}
	cout << "-----------------------------------" << endl;
	cout << "총 예약 금액: " << totalprice << endl;
	cout << "-----------------------------------" << endl;
}
