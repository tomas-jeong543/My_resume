#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

#define MAX 1000000
using namespace std;

vector<int> primenums;

void findPrime() {
	primenums.push_back(2);
	bool detcheck = false;

	for (int i = 3; i < 1001; i++) {
		detcheck = false;

		for (int j = 0; j < primenums.size(); i++) {
			if (i % primenums[i] == 0) {
				detcheck = true;
				break;
			}

			if (primenums[i] > 32) {
				break;
			}
		}

		if (!detcheck) {
			primenums.push_back(i);
		}
	}
}


int main()
{
	int n;
	vector<int> numbers;
	vector<int> sortednums;
	vector<bool> numcheck;
	stringstream buf;
	string input;
	map<int, int> count;
	int sizeinfo;
	int limit;

	cin >> n;
	cin.ignore();
	getline(cin, input);
	buf << input;
	numbers.assign(n, 0);
	sortednums.assign(n, 0);
	numcheck.assign(MAX + 1, false);


	for (int i = 0; i < n; i++) {
		buf >> numbers[i];
		sortednums[i] = numbers[i];
		count[numbers[i]] = 0;
		numcheck[numbers[i]] = true;
	}

	for (int i = 0; i < n; i++) {
		limit = MAX / numbers[i];

		for (int j = 2; j < limit + 1; j++) {
			if (numcheck[j * numbers[i]]) {
				count[j * numbers[i]] -= 1;
				count[numbers[i]] += 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << count[numbers[i]] << " ";
	}

	return 0;
}