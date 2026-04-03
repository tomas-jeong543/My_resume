#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string info;
	string input;
	string opt;
	stringstream buf;
	bool arr[20];
	for (int i = 0; i < 20; i++) {
		arr[i] = false;
	}


	int N, num;

	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		getline(cin, input);
		buf << input;
		buf >> opt;

		if (opt[0] == 'a' && opt[1] == 'd') {
			buf >> num;
			if (!arr[num -1]) {
				arr[num - 1] = true;
			}
		}
		else if (opt[0] == 'r') {
			buf >> num;
			if (arr[num - 1]) {
				arr[num - 1] = false;
			}
		}
		else if (opt[0] == 'c') {
			buf >> num;
			if (arr[num - 1]){
				 cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (opt[0] == 't') {
			buf >> num;
			arr[num - 1] = !arr[num - 1];
		}
		else if (opt[0] == 'a') {
			
			for (int i = 0; i < 20; i++) {
				arr[i] = true;
			}

		}
		else if (opt[0] == 'e') {
			for (int i = 0; i < 20; i++) {
				arr[i] = false;
			}
		}
		buf.str("");
		buf.clear();
	}

	return 0;
}