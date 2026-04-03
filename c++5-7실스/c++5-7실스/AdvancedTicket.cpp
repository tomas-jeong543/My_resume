#include "AdvancedTicket.h"
#include<iostream>

using namespace std;
AdvancedTicket::AdvancedTicket( const double& price, const int& days):Ticket( price), advanceDays(days)
{}

double AdvancedTicket::getPrice() const
{

	if (advanceDays >= 30) {
		return price * 0.5;
	}
	else if (advanceDays >= 20) {
		return price * 0.7;
	}
	else if (advanceDays >= 10) {
		return price * 0.9;
	}
	else {
		return price;
	}
}
int AdvancedTicket::getAdvanceDays() const
{
	return advanceDays;
}

void AdvancedTicket::show() const
{
	Ticket::show();
	cout << "사전예약일: " << advanceDays << endl;
	if (advanceDays >= 30) {
		cout << "지불금액: " << price * 0.5 << endl;
	}
	else if (advanceDays >= 20) {
		cout << "지불금액 " << price * 0.7 << endl;
	}
	else if (advanceDays >= 10) {
		cout << "지불금액: " << price * 0.9 << endl;
	}
	else {
		cout << "지불금액: " << price << endl;
	}
}
