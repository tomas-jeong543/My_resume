#include<iostream>
#include"Mammalh.h"
#include"Cat.h"
#include"Dog.h"
enum ANIMALS {MAMMAL, DOG, CAT};
const int NUM = 3;
using namespace std;

int main(){

	Mammal * theArray[NUM];
	Mammal* ptr;
	int choice, i;

	for (i = 0; i < NUM; i++) {
		cout << "(1)dog (2)cat (3)Mammal: ";
		cin >> choice;

		switch (choice)
		{
		case DOG:ptr = new Dog; break;
		case CAT:ptr = new Cat; break;
		default: ptr = new Mammal; break;

		}
		theArray[i] = ptr;
	}

	Mammal* otherArray[NUM];
	for (int i = 0; i < NUM; i++) {
		theArray[i]->Speak();
		otherArray[i] = theArray[i]->Clone();
	}

	for (int i = 0; i < NUM; i++) {
		otherArray[i]->Speak();
	}
	return 0;
}