#pragma once
#include<iostream>
#include<string>
#include<ostream>
using std::ostream;
using std::string;


class Clothing
{
protected:
	string name;
	int price;
	string gender;
	string size;
	int viewTime = 0;
public:
	Clothing(const string name, const int price, const string gen, const string size);
	friend virtual ostream& operator<<(ostream& out, const Clothing& rhs);
	bool operator==(const Clothing& rhs) const;
	string getName() { return name; }
	void PlusView() { this->viewTime++; }
	bool operator>(Clothing& rhs)const;
	int getViewTime()const { return this->viewTime; }
};

ostream& operator<<(ostream& out, const Clothing& rhs);