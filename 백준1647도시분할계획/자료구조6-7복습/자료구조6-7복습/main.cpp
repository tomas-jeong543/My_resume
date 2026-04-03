#include<iostream>
#include<string>
#include<sstream>
using namespace std;

void merge(int& x, int& y) {

	
}

void prac1() {




	int n;
	cin >> n;
	int* arr = new int[n * n * 4];
	int* parent = new int[n * n * 4];
	string input;

	char* slashes = new char[n * n];
	getline(cin, input);

	char slash;
	stringstream buf(input);
	int idx = 0;
	while (buf >> slash) {
		slashes[idx++] = slash;
	}

	for (int i = 0; i < n * n; i++) {
		arr[i] = i;
		parent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int startidx = i * n * n + j * n;


			for (int k = 0; k < 4; k++) {

			}
		}
	}



	delete[] parent;
	delete[] slashes;
	delete[] arr;
	return;
}


int main()
{
	return 0;
}