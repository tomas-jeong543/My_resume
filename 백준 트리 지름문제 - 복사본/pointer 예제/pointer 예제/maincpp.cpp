#include<iostream>
using namespace std;

int main()
{
	unsigned int Your_Age;
	unsigned int* Your_Age_ptr = 0;
	Your_Age_ptr = &Your_Age;

	*Your_Age_ptr = 50;

	cout << "your age: " << Your_Age << endl;
}