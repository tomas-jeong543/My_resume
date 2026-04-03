#pragma once
#include<iostream>
using namespace std;

enum BREED {GOLDEN, CAIRN, DANDTE, SHETLAND, DOBERMAN, LAB};

class Mammal
{
protected:
	int its_age;
	int its_weight;
public:
	Mammal() { cout << "Mammal consructor ... \n"; }
	~Mammal() { cout << "MAmmal distructor ... \n"; }

	void Speak() const { cout << "Mammal sound... \n"; }
	void  Sleep() const { cout << "shh i'm sleeping\n"; }
};