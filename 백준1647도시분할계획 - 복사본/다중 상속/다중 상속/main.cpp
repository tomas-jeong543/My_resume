#include"Pegasus.h"

const int magic_num = 2;

int main()
{
	Horse* Ranch[magic_num];
	Bird* Aviary[magic_num];
	Horse* pHorse;
	Bird* pBird;
	int choice, i;

	for (int i = 0; i < magic_num; i++) {
		cout << "\n1horse 2pegasus: ";
		cin >> choice;
		if (choice == 2)
			pHorse = new Pegasus;
		else
			pHorse = new Horse;
		Ranch[i] = pHorse;
	}

	for (int i = 0; i < magic_num; i++) {
		cout << "\n 1bird 2pegasus: ";
		cin >> choice;
		if (choice == 2)
			pBird = new Pegasus;
		else
			pBird = new Bird;
		
		Aviary[i] = pBird;
	}

	cout << endl;

	for (int i = 0; i < magic_num; i++) {
		cout << "\nRanch[" << i << "]: ";
		Ranch[i]->Whinny();
		delete Ranch[i];
		Ranch[i] = nullptr;
	}

	for (int i = 0; i < magic_num; i++) {
		cout << "\bird[" << i << "]: ";
		Aviary[i]->Chrip();
		Aviary[i]->Fly();
		delete Aviary[i];
		Aviary[i] = nullptr;
	}
	return 0;
}