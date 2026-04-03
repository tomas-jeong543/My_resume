#include<iostream>
#include"Library.h"

int main()
{
	Library mylab;
	for (int i = 0; i < 11; i++) {
		mylab.addBook("tomas" + to_string(i), 10);
	}	
	mylab.printBooks();

	return 0;
}