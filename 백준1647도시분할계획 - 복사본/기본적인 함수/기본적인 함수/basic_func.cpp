#include<iostream>

int Area(int length, int width);

int main()
{
	using namespace std;
	
	int lengthof_Yard, widthof_Yard, areaof_Yard;

	cout << "\nHow wide is your yard: ";
	cin >> widthof_Yard;
	cout << "\nHow long is your yard: ";
	cin >> lengthof_Yard;

	areaof_Yard = Area(widthof_Yard, lengthof_Yard);

	cout << "\n Your yard is ";
	cout << areaof_Yard;
	cout << " square feet \n\n";
	
	return 0;
}

int Area(int l, int w)
{
	return l * w;
}