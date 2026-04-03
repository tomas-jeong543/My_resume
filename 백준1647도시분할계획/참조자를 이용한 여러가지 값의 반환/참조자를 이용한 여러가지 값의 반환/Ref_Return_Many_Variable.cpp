#include<iostream>
using namespace std;
typedef unsigned short USHORT;
enum ERR_CODE {SUCESS, FAILURE};

enum ERR_CODE Factor(USHORT, USHORT&, USHORT&);

int main()
{
	USHORT number, squared, cubed;
	ERR_CODE result;
	cout << "Enter a number(0 ~ 20): ";
	cin >> number;

	result = Factor(number, squared, cubed);

	if (result == SUCESS) {
		cout << "number: " << number << endl;
		cout << "square: " << squared << endl;
		cout << "cubed: " << cubed << endl;
	}
	else {
		cout << "Error Rncounterd !\n";
		return 0;
	}
}

ERR_CODE Factor(USHORT n, USHORT& squared, USHORT& cubed) {
	if (n > 20 || n < 1)
		return FAILURE;
	else {
		squared = n * n;
		cubed = n * n * n;
		return SUCESS;
	}
}