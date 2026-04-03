#include"Cat.h"

int main()
{
	//객체를 배열에 선언하기 위해서는 기본 생성자가 필수로 존재해야 한다
	Cat liter[5];
	int i;

	for (i = 0; i < 5; i++)
		liter[i].Set_Age(2 * i + 1);

	for (i = 0; i < 5; i++) {
		cout << "cat: #" << i << ": " << liter[i].Get_Age() << endl;
	}

	//포인터 배열 객체는 자유 기억 공간 heap에 저장하고 포인터를 배열 안의 객체에 저장하는 방식 대규모 저장에 효과적이다

	Cat* Family[500];
	Cat* pcat;
	
	for (int i = 0; i < 500; i++)
	{
		pcat = new Cat;
		pcat->Set_Age(2 * i + 1);
		Family[i] = pcat;
	}

	for (int i = 0; i < 500; i++) {
		cout << "Cat # " << i + 1 << ": ";
		cout << Family[i]->Get_Age() << endl;
		
	}

	


	Cat** Family2 = new Cat * [10];

	if (Family2 == nullptr) { return 1; }

	for (int i = 0; i < 10; i++) {
		*(Family2 + i) = new  Cat[10];
		if (Family2[i] == nullptr) { return 1; }
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 3; j++) {
			Family2[i][j].Set_Age(i + j);
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 3; j++) {
			Family2[i][j].Set_Age(i + j);
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "Family[" << i << "]" << "[" << j << "]" << Family2[i][j].Get_Age() << "\t";
		}
		cout << "\n";
	}
	
	delete[] Family2;
	
	for (int i = 0; i < 500; i++) {
		delete Family[i];
	}

	return 0;
}