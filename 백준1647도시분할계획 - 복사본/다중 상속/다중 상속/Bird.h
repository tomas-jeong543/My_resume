#pragma once
#include<iostream>
using namespace std;

class Bird
{
private:
	int its_age;
public:
	Bird() { cout << "Bird constructor... "; }
	virtual ~Bird(){ cout << "Bird distructor.. "; }
	virtual void Chrip() const { cout << "chrip... "; }
	virtual void Fly() const {
		cout << "I can fly i can fly i can fly \n";
	}
};