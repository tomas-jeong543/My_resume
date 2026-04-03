#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define INF 500000000000001
using namespace std;

vector<long long> nums;

long long calsum(int a, int b, int c) {
	return nums[a] + nums[b] + nums[c];
}

int binary_search(int left, int right, int low, int high) {

	int newmid, cmp;
	long long cursum, newsum, newsum2 = INF;

	//cout << "left: " << left << " mid: " << mid << " right: " << right << "\n";
	
	if (low > high) {
		if (low >= right)return high;
		if (high <= left)return low;

		if (llabs(calsum(left, right, low)) < llabs(calsum(left, right, high)))
			return low;
		else
			return high;
	}
	else {
		newmid = low + (high - low) / 2;
		cursum = calsum(left, newmid, right);
		if (cursum == 0) {
			return newmid;
		}
		else if (cursum < 0) {
			return binary_search(left, right, newmid + 1, high);
		}
		else {
			return binary_search(left, right, low, newmid - 1);
	}
	
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	stringstream buf;
	int n;
	long long num;
	long long left, right, mid;
	long long ansleft = 0, ansright = 0, ansmid = 0;
	long long ans = INF;
	cin >> n;
	cin.ignore();
	nums.assign(n, 0);

	getline(cin, input);
	buf << input;
	for (int i = 0; i < n; i++) {
		buf >> num;
		nums[i] = num;
	}

	sort(nums.begin(), nums.end());


	for (int i = 0; i < n; i++) {
		for (int j = i + 2; j < n; j++) {
			left = nums[i];
			right = nums[j];

			mid = binary_search(i, j, i + 1, j -1);
			//cout << " left: " << left << " mid: " << nums[mid] << " right: " << right << "\n";
			if (abs(ans) > abs(left + right + nums[mid])) {
				//cout << "change made\n";
				ansleft = left;
				ansmid = nums[mid];
				ansright = right;
				ans = left + nums[mid] + right;
			}
			if (ans == 0) {
				break;
			}
		}
	}
	cout << ansleft << " " << ansmid << " " << ansright << "\n";
	return 0;
}