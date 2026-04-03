#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

vector<int> dp;
vector<int> arr;
vector<int> lts;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	stringstream buf;

	int N;
	int ans = 0;
	
	cin >> N;
	cin.ignore();
	getline(cin, input);

	buf << input;
	arr.assign(N, 0);
	dp.assign(N, -1);

	for (int i = 0; i < N; i++) {
		buf >> arr[i];
	}
	
	lts.push_back(0);
	
	for (int i = 0; i < N; i++) {
		if (lts[lts.size() - 1] < arr[i]) {
			lts.push_back(arr[i]);
		}
		else {
			int L = 0;
			int R = lts.size();

			while (L < R) {
				int mid = int(L + R ) / 2 ;

				if (lts[mid] < arr[i]) {
					L = mid + 1;
				}
				else  {
					R = mid;
				}
				
			}
			lts[R] = arr[i];
		}
	}

	for (int i = 0; i < lts.size(); i++) {
		cout << lts[i] << " ";
	}
	cout << "\n";
	cout << lts.size() -1 << "\n";
}