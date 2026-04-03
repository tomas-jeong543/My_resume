#pragma once
#include<iostream>
#include<string>

using namespace std;


class JMHStudent
{
private:
	string stdid;
	string name;
public:
	JMHStudent() = delete;
	JMHStudent(const string& stdidinfo, const string& nameinfo):stdid(stdidinfo) ,name(nameinfo){}

	void display() 
	{
		cout << stdid << " : " << name << endl;
	};

	string getid() const
	{
		return stdid;
	}
};

