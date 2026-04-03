#include<iostream>
#include"is_Radius.h"
using namespace std;

void problem4()
{
	is_Radius a;
	is_Radius b(9);

	for (int i = 0; i < 10; i++) {
		std::cout << a.Get_Radius() << " " << b.Get_Radius() << endl;
		
		a++;
		b++;
	}

	b = a;
	cout << a.Get_Radius() << " " << b.Get_Radius() << endl;
}

int main()
{
	problem4();
	return 0;
}