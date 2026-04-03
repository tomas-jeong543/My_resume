#include"Cat.h"

int main()
{
	Cat Frisky;
	cout << "frisky's age: " << Frisky.Get_Age() << "\n";
	cout << "Setting frisky to 6 ...\n";
	Frisky.Set_Age(6);
	Cat whiskers;
	cout << "whisker's age: " << whiskers.Get_Age() << "\n";
	cout << "copying frisky to whiskers... \n";
	whiskers = Frisky;
	cout << "whisker's age: " << whiskers.Get_Age() << "\n";
	return 0;
}