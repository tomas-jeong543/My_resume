#include<iostream>
// 다형성 함수의 예 및 주의점 다형성 함수 선언시 이름과 매개변수의 타입과 개수가 같고 반환 타입만 다르면 애러가 발생할 수 있다

int Double(int);
float Double(float);
double Double(double);
long Double(long);

using namespace std;

int main()
{
	int myInt = 6500;
	long myLong = 65000;
	float myFloat = 6.5F;
	double myDouble = 6.5e20;

	int doubledInt;
	long doubledLong;
	float doubledfloat;
	double doubledDouble;

	cout << "myInt: " << myInt << "\n";
	cout << "myLong: " << myLong << "\n";
	cout << "myFloat: " << myFloat << "\n";
	cout << "myDouble: " << myDouble << "\n";

	doubledInt = Double(myInt);
	doubledLong = Double(myLong);
	doubledfloat = Double(myFloat);
	doubledDouble = Double(myDouble);

	cout << "Doubledint: " << doubledInt << endl;
	cout << "DoubledLong: " << doubledLong<< endl;
	cout << "DoubledFloat: " << doubledfloat << endl;
	cout << "DoubledDouble: " << doubledDouble << endl;

	return 0;
}

int Double(int orginal)
{
	return orginal * 2;
}

float Double(float orginal)
{
	return orginal * 2;
}

long Double(long original)
{
	return original * 2;
}

double Double(double original)
{
	return original * 2;
}