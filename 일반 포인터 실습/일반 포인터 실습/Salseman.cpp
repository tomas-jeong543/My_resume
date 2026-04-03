#include "﻿Salseman.h"
#include<string>
#include<iostream>
using namespace std;

//static맴버 변수의 주된 선언 위치는 class의 cpp파일이다
//int Salseman::counter = 0; 하지만 요즘은 그냥 클래스 내부에서 인라인 방식으로 선언가능하다
 
Salseman::Salseman(const Salseman& man):Salseman(man.name, man.sales)
{

}

//위임 생성자
Salseman::Salseman(const string & name) :Salseman(name, 0.0) {}
Salseman::Salseman(const string& name, const double& sales) : name(name), sales(sales)
{
	cout << "" << endl;
}


void Salseman::setName(const string& name) {
	this->name = name;
}

void Salseman::readinput()
{
	cout << "이름: ";
	cin >> name;
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