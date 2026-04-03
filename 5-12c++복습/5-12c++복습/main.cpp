#include<iostream>

using namespace std;

int main()
{
	int* arr = new int[5];

	delete[] arr;

	arr = nullptr;

	arr = new int[7];

	for (int i = 0; i < 7; i++) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < 7; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
	int* arr2 = move(arr);
	for (int i = 0; i < 7; i++) {
		cout << arr2[i] << "\t";
	}
	return 0;
}