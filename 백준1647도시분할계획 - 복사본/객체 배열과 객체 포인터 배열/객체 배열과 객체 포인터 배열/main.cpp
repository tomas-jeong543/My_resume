#include<iostream>
#include"Sosimple.h"
#include<memory>
using namespace std;

int main()
{
	unique_ptr<Sosimple[]> info1 = make_unique<Sosimple[]>(10);
	unique_ptr<Sosimple> infoarray[3];

	for (int i = 0; i < 3; i++) {
		infoarray[i] = make_unique<Sosimple>(11 + i);
	}

	for (int i = 0; i < 3; i++) {
		infoarray[i]->display();
	}

	cout << "------------------------------------------------------------" << endl;
	for (int i = 0; i < 10; i++) {
		info1[i] = Sosimple(i);
	}

	for (int i = 0; i < 10; i++) {
		info1[i].display();
	}

	return 0;
}