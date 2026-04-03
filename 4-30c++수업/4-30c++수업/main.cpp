#include<iostream>
#include"MyArray.h"

using namespace std;
int main()
{
	cout << "202211364 Á¤¸íÈÆ" << endl;

	MyArray arr1(5);

	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 3;
	arr1[3] = 4;
	arr1[4] = 5;
	
	MyArray arr2 = arr1;
	arr2[0] = 2;
	
	MyArray arr3(5);
	
	arr3 = arr2;
	arr3[0] = 3;

	arr1.printValue();
	arr2.printValue();
	arr3.printValue();
	cout << "mys: " << &arr1 << " " << &arr2 << " " << &arr3 << endl;
	return 0;
}