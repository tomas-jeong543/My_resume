#include<iostream>
#include<sstream>
#include<string>
//#include<set>
//#include<queue>
using namespace std;

int bluenum = 0;
int whitenum = 0;

void divideNUm(int N, int** arr, int xpos = 0, int ypos = 0) {
	
	if (N == 1) {
		if (arr[xpos][ypos] == 1) {
			bluenum++;
		}
		else {
			whitenum++;
		}
		return;
	}


	int check = arr[xpos][ypos];
	bool det = true;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[xpos + i][ypos + j] != check) {
				det = false;
				break;
			}
			if (!det) {
				break;
			}
		}
	}

	if (det) {
		if (check == 1) {
			bluenum++;
		}
		else {
			whitenum++;
		}
	}
	else {
		divideNUm(N / 2, arr, xpos, ypos);
		divideNUm(N / 2, arr, xpos,ypos + N / 2);
		divideNUm(N / 2, arr, xpos + N / 2, ypos);
		divideNUm(N / 2, arr, xpos + N / 2,  ypos + N / 2);

	}
}


int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(nullptr);
	stringstream buf;
	string input;
	int N, num;
	int** block;
	cin >> N;
	cin.ignore();
	
	num = 4;

	block = new int*[N];
	for (int i = 0; i < N; i++) {
		block[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		getline(cin, input);
		buf << input;
		for (int j = 0; j < N; j++) {
			buf >> block[i][j];
		}
		buf.str("");
		buf.clear();
	}

	int check = block[0][0];
	bool det = true;

	divideNUm(N, block);
	cout << whitenum << endl;
	cout << bluenum << endl;


	for (int i = 0; i < N; i++) {
		delete[] block[i];
	}
	delete[] block;
	return  0;
}