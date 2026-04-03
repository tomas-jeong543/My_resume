#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

#include "GeneralTicket.h"
#include<iostream>
using namespace std;
GeneralTicket::GeneralTicket(const double& price, bool card) :Ticket(price), payByCredit(card)
{}

double GeneralTicket::getPrice() const
{
	if (getpaybyCredit()) {
		return price * 1.1;
	}
	else {
		return price;
	}
	
}

bool GeneralTicket::getpaybyCredit() const
{
	return payByCredit;
}

void GeneralTicket::show() const
{
	
	Ticket::show();
	cout << "카드 결재여부: " << (getpaybyCredit() ? "true" : "false") << endl;
	if (getpaybyCredit()) {
		cout << "지불금액: " << price * 1.1 << endl;
	}
	else {
		cout << "지불금액: " << price << endl;
	}
}
