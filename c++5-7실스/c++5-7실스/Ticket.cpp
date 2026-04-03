#include "Ticket.h"
#include<iostream>
using namespace std;

Ticket::Ticket( const double& price):price(price)
{
	ticketnum += 1;
	number = ticketnum;
}

int Ticket::getNumber() const
{
	return number;
}

double Ticket::getPrice() const
{
	return price;
}

void Ticket::setPrice(const double& price)
{
	this->price = price;
}

void Ticket::show() const
{
	cout << "티켓번호: " << number << endl;
	cout << "가격정보: " << price << endl;
}

