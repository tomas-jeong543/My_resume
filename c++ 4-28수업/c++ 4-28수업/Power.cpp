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
	Power tmp(0,0);
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;
	return tmp;
}

bool Power::operator==(Power op2)
{
	if (this->punch == op2.punch && this->kick == op2.kick) {
		return true;
	}
	else {
		return false;
	}
}
