#include<iostream>
#include<sstream>
#include<string>
#include<stdio.h>
using namespace std;

void func1()
{
	int x, y;
	cin >> x >> y;
	cin.ignore();
	if (!((x | y) ^ x)) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	return;
}

void func2()
{
	int x = -1;
	unsigned u = 2147483648;
	

	cout << (int)2147483648U << "\n";
	printf("x = %u = %d\n",x,x);
	printf("u = %u = %d\n", u, u);

}

int strlonger(char* s, char* t) {
	return (int)strlen(s) - (int)strlen(t) > 0;
}

int main()
{
	const int size1 = 8;
	const int size2 = 10;
	string ins1 = "ab";
	string ins2 = "cd";
	char* ins1ptr = new char[size1];
	char* ins2ptr = new char[size2];

	for (int i = 0; i < size1 - 1; i++) {
		ins1ptr[i] = '1';
	}

	ins1ptr[size1 - 1] = '\0';

	for (int i = 0; i < size2 - 1; i++) {
		ins2ptr[i] = '1';
	}
	ins2ptr[size2 - 1] = '\0';

	cout << strlonger(ins1ptr, ins2ptr) << endl;
	//func2();
	return 0;
}