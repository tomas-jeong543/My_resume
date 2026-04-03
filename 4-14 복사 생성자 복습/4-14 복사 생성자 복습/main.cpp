#include<iostream>
#include"EX.h"
#include<string>

using namespace std;

EX MakeEx(string name)
{
	return EX(name);
}


int main()
{
	string name1 = "tomas";
	EX a1(name1);

	EX a2 = a1;

	cout << a1.GetEx() << " " << a2.GetEx() << endl;

	a2.SetEx("alan");

	cout << a1.GetEx() << " " << a2.GetEx() << endl;


	EX a3 = move(a2);
	
	cout << a3.GetEx() << endl;
	return 0;
}