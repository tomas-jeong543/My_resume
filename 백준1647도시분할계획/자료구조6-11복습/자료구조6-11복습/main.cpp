#include<iostream>

using namespace std;



int find(int parent[], int x) {
	if (parent[x] != x) {
		return	parent[x] = find(parent,parent[x]);
	}
	else {
		return x;
	}
}

bool isUnion(int parent[], int x, int y) {
	if (parent[x] == parent[y]) {
		return true;
	}
	return false;
}

void MakeUnion(int parent[], int x, int y) {

	if (isUnion(parent, x, y))
		return;

	parent[x] = y;
}

int main()
{
	int G;
	int P;
	cin >> G;
	cin >> P;


	int* Parr = new int[P];
	int* Garr = new int[G + 1];
	int total_num = 0;

	for (int i = 0; i < G + 1; i++) {
		Garr[i] = i;
	}


	for (int i = 0; i < P; i++) {
		cin >> Parr[i];
	}
	
	for (int i = 0; i < P; i++) {
		
		int root = find(Garr, Parr[i]);
		if (root == 0) {
			break;
		}

		total_num++;
		MakeUnion(Garr, root, root - 1);

	}
	

	cout  <<  total_num << endl;
	delete[] Parr;
	delete[] Garr;
	return 0;
}


int Jump_search(int arr[], int size, int key) {

	int step = sqrt(size);
	int prev = 0;

	while (arr[(step < size ? step : size) - 1] < key) {

		prev = step;
		step += sqrt(size);
		if (prev >= size) {
			return -1;
		}
	}

	while (arr[prev] < key) {
		prev++;
		if (prev >= size || prev == step)
			return -1;

	}

	return (arr[prev] == key) ? prev : -1;
}
