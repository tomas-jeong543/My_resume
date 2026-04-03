#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);  // 입출력 속도 향상
	unsigned int max = -1;
	int M, N;
	cin >> M >> N;
	cout << M << N << endl;
	int** arr;

	arr = new int*[M];
	for (int i = 0; i < M; i++) {
		arr[i] = new int[N];
	}
	cin.ignore();
	
	string line;
	for (int i = 0; i < M; i++) {
		string ins;
		int j = 0;
		
		getline(cin, line);
		stringstream strinfo(line);
		while (strinfo >> ins && j < N) {
			arr[i][j] = stoi(ins);
			j += 1;
		}
	
	}

	/*for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}*/
		
	return 0;
}

