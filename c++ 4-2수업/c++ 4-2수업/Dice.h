#pragma once
#include<iostream>

class Dice
{
private:
	int faceValue;
public:
	Dice() :Dice(0) {}
	Dice(int i) { faceValue = i; }
	void roll();
	int getFaceValue() { return faceValue; }
};