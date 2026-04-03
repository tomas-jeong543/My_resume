#pragma once
#include"Dice.h"
#include<iostream>
#include<string>

using namespace std;

class Player
{
private:
	string name;
	int total;
public:
	Player() = delete;
	Player(string name) { this->name = name; }

	void Setname(const string & name);
	string Getname() { return name; }
	void roll(Dice& d1, Dice& d2);
	int Get_Total() { return total; }

};