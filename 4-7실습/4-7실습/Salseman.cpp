#include "Salseman.h"
#include<string>
//위임 생성자
Salseman::Salseman(const string& name):Salseman(name, 0.0){}

Salseman::Salseman(const string& name, const double& sales): name(name), sales(sales)
{
	cout << "" << endl;
}


void Salseman::setName(const string& name) {
	this->name = name;
}

void Salseman::readinput()
{
	cout << "이름: ";
	cin >> name ;
	cout << "판매 금액: ";
	cin >> sales;
}

string Salseman::get_Salesman_Info()
{
	string str = "이름: " + name + " 판매 금액: " + to_string(sales) + "\n";
	return str;
}

double Salseman::getSales() const
{
	return sales;
}
