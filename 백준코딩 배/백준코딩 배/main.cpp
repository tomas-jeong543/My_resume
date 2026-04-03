#include<iostream>
#include<sstream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

void swapNum(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void bubbleSort(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] <  arr[j]) {
				swapNum(arr[i], arr[j]);
			}
		}
	}
}


void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << endl;

}

void init(int size, int* arr, priority_queue<int, vector<int>, less<int>>& info) {

	for (int i = 0; i < size; i++) {
		info.push(arr[i]);
	}
}


int main()
{
	int N, M;
	int* craneWeights;
	int* boxWeights;
	bool* delivered;

	int maxbox = -1;
	int maxcrane = -1;
	int time = 0;
	int count = 0;
	string input;
	stringstream buf;

	cin >> N;
	craneWeights = new int[N];
	
	cin.ignore();
	getline(cin, input);
	buf << input;
	
	for (int i = 0; i < N; i++) {
		buf >> craneWeights[i];
		if (craneWeights[i] > maxcrane) {
			maxcrane = craneWeights[i];
		}
	}
	buf.clear();

	cin >> M;
	delivered = new bool[M];
	boxWeights = new int[M];
	cin.ignore();
	getline(cin, input);
	buf << input;


	for (int i = 0; i < M; i++) {
		int box;
		buf >> box;
		delivered[i] = false;
		boxWeights[i] = box;
		if (box > maxbox) {
			maxbox = box;
		}
	}

	if (maxbox > maxcrane) {
		std::cout << "-1" << endl;
		return 0;
	}
	
	
	bubbleSort(craneWeights, N);
	bubbleSort(boxWeights, M);

	while (count < M) {
		for (int i = 0; i < N; i++) {
			int cw = craneWeights[i];
			int idx = 0;
			if (cw < boxWeights[M -1]) {
				continue;
			}


			while (idx < M) {
				
				if (!delivered[idx] && boxWeights[idx] <= cw) {
					count++;
					delivered[idx] = true;
					break;
					
				}
				else {
					idx++;
				}
			}
		}
		time += 1;
	}

	std::cout << time << endl;
	delete[] craneWeights;
	return 0;
}