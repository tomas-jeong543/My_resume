#include<iostream>

using namespace std;
short Factor(int n, int* pAquared, int* pCubed);
//enum을 이용해 프로그램의 수준을 한 단계 올린다
enum Error_Value {Sucess, Failure};

int main()
{
	int number, squared, cubed;
	short error;
	
	cout << "Enter a number(0 - 20): ";
	cin >> number;
	
	error = Factor(number, &squared, &cubed);

	if (!error) {

		cout << "number: " << number << "\n";
		cout << "square: " << squared << "\n";
		cout << "cubed: " << cubed << "\n";

	}
	else {
		cout << "Error encounterd! \n";
		return 0;
	}
}

short Factor(int n, int* pSquared, int* pCubed)
{
	short Value = 0;
	//범위 바깥의 수를 입력 받으면 오류 반환
	if (n > 20 || n <= 0)
		Value = Failure;
	else
	{
		//범위 안의 수의 경우 넓이와 부피값을 반환한다
		//포인터를 이용해서 값들을 저장한다
		*pSquared = n * n;
		*pCubed = n * n * n;
		Value = Sucess;
	}
	return Value;
}
