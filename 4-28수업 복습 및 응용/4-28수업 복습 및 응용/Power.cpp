#include "Power.h"
#include<iostream>
using namespace std;

Power& Power::operator<<(ostream& out)
{
	out << "kick=" << this->kick << "," << "punch=" << this->punch << endl;
	return *this;
}

void Power::show() const
{
	cout << "kick: " << this->kick << " punch: " << this->punch << endl;
}

Power Power::operator+(Power op2)
{
	Power tmp(0, 0);
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;
	return tmp;
}

bool Power::operator==(Power op2){
	if (this->punch == op2.punch && this->kick == op2.kick) {
		return true;
	}
	else {
		return false;
	}

}

Power& Power::operator+=(Power op2)
{
	this->kick += op2.kick;
	this->punch += op2.punch;

	return *this;
}

Power& Power::operator+=(int num)
{
	this->kick += num;
	this->punch += num;
	// TODO: 여기에 return 문을 삽입합니다
	return *this; 
}

Power Power::operator<<(int num)
{
	this->kick += num;
	this->punch += num;
	return *this;
}

Power& Power::operator--()
{
	punch -= 1;
	kick -= 1;
	return *this;
}

Power Power::operator--(int x)
{
	Power tmp = *this;
	kick -= 1;
	punch -= 1;
	return tmp;
}