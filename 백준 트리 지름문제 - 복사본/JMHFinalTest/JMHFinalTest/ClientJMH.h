#pragma once
#include<iostream>
#include<string>
#include<ostream>
using std::ostream;
using std::string;

class ClientJMH
{
protected:
	string name;
	string gender;
	int height;
	int weight;
public:
	ClientJMH(const string name, const string gender, const int h, const int w);
	friend ostream& operator<<(ostream& out, const ClientJMH& rhs);
	int getHeight()const { return this->height; }
	int getWeight()const { return this->height; }

};

ostream& operator<<(ostream& out, const ClientJMH& rhs);
