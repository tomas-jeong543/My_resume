#pragma once
#include<iostream>

using namespace std;

class Salseman
{
private:
	string name;
	double sales;

public:

	Salseman() = default;
	Salseman(const string& name);
	Salseman(const string & name, const double  & sales);
	void setName(const string & name);
	void readinput();
	string get_Salesman_Info();
	double getSales() const;

};

