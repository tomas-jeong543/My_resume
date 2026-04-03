#include<iostream>
#include<sstream>
#include<string>

using namespace std;

void init(int** parent, int N, int * unifiedNum, int * popluation, int ** arr) {
	for (int i = 0; i < N; i++) {
		for (int j = 0;j < N; j++) {
			parent[i][j] = i * N + j;
			popluation[N * i + j] = 0;
		}
	}

	for (int i = 0; i < N * N; i++) {
		unifiedNum[i] = 0;

	}

	
}

void changeArr(int** arr, int target, int change, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0;j < N; j++) {
			if (arr[i][j] == target) {
				arr[i][j] = change;
			}
		}
		
	}
	
}

int main()
{
	int N, L, R;
	int ans = 0;
	string input;
	stringstream buf;
	int** arr;
	int** parent;
	int* popluation;
	int* unifiedNum;
	getline(cin, input);
	buf << input;

	buf >> N;
	buf >> L;
	buf >> R;
	buf.clear();

	arr = new int* [N];
	parent = new int* [N];
	popluation = new int[N * N];
	unifiedNum = new int[N * N];

	for (int i = 0; i < N * N; i++) {
		unifiedNum[i] = 0;
	}


	for (int i = 0; i < N; i++) {
		getline(cin, input);
		buf << input;

		parent[i] = new int[N];
		arr[i] = new int[N];
		for (int j = 0; j < N; j++) {
			buf >> arr[i][j];
			parent[i][j] = N * i + j;
			popluation[N * i + j] = 0;
		}
		buf.clear();
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}*/


	bool detEnd = false;
	bool detMove = false;

	while (!detEnd) {

		detMove = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i > 0) {
					int dif = abs(arr[i][j] - arr[i - 1][j]);
					
					if (dif >= L && dif <= R) {
					
						
						changeArr(parent, parent[i][j], parent[i - 1][j],N);
						detMove = true;
					}
				}

				if (j > 0) {
					int dif = abs(arr[i][j] - arr[i][j - 1]);

					if (dif >= L && dif <= R) {
						
						changeArr(parent, parent[i][j], parent[i][j - 1], N);
						detMove = true;
					}
				}
			}
		}

		if (!detMove) {
			detEnd = true;
			continue;
		}

		ans += 1;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				unifiedNum[parent[i][j]]++;
				popluation[parent[i][j]] += arr[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int idx = parent[i][j];
				arr[i][j] = popluation[idx] / unifiedNum[idx];
			}
		}
		
		init(parent, N, unifiedNum, popluation, arr);
	}
	
	cout << ans << endl;


	for (int i = 0; i < N; i++) {
			delete[] parent[i];
			delete[] arr[i];
	}

	delete[] parent;
	delete[] arr;
	delete[] popluation;
	delete[] unifiedNum;
	return 0;
}