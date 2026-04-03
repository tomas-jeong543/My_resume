#include"func.h"

int menu()
{
	using namespace std;
	int choice;

	cout << "**** Menu ****\n\n";
	cout << "(1) Choice one. \n";
	cout << "(2) choice two. \n";
	cout << "(3) Choice three. \n";
	cout << "(4) Redisplay menu. \n";
	cout << "(5) Quit. \n\n";
	cout << ": ";
	cin >> choice;

	return choice;
}

void DoTask(int n)
{
	std::cout << "Task " << n << std::endl;
}