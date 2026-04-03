#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

long long dp[56];


void init() {
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i < 56; i++) {
		dp[i] = 0;
		for (int j = 0; j < i; j++) {
			dp[i] += dp[j];
		}
		
		dp[i] += static_cast<long long>(pow(2, i ));
	}

	/*for (int i = 0; i < 55; i++) {
		cout << i << " " << dp[i] << "\n";
	}*/
}

long long findsum(vector<long long> num) {
	long long sum = 0;
	int maxdigit = 0;
	long long onenum = 0;

	for (int i = 10; i < 64; i++) {
		if (num[i] == 1) {
			maxdigit = i;
			break;
		}
	}
	
	if (maxdigit == 63)
		return 1;

	for (int i = 0; i < 63 - maxdigit; i++) {
		sum += dp[i];
	}
	onenum++;

	for (int i = maxdigit + 1; i < 64; i++) {
		if (num[i] == 1) {
			for (int j = 0; j < 63 - i; j++) {
				sum += dp[j];
			}

			if (i == 63) {
				sum += (2 *onenum + 1);
			}
			else {
				sum += static_cast<long long>(pow(2, 63 - i) * onenum);
				onenum++;
			}
		}
	}

	if (num[63] == 0) {
		sum += onenum;
	}

	return sum;
}

int main()
{
	long long a, b;
	vector<long long> avec, bvec;
	avec.clear();
	bvec.clear();
	long long asum = 0;
	cin >> a >> b;
	cin.ignore();
	init();
	
	while (a > 0) {
		avec.push_back(a % 2);
		a = a / 2;
	}

	while (b > 0) {
		bvec.push_back(b % 2);
		b = b / 2;
	}

	reverse(avec.begin(), avec.end());
	reverse(bvec.begin(), bvec.end());

	while (avec.size() < 64) {
		avec.insert(avec.cbegin(), 0);
	}

	while (bvec.size() < 64) {
		bvec.insert(bvec.cbegin(), 0);
	}


	for (auto num: avec) {
		asum += num;
	}

	/*cout << findsum(bvec) << "\n";
	cout << findsum(avec) << "\n";
	cout << asum << "\n";*/
	long long ans = findsum(bvec) - findsum(avec) + asum;
	cout << ans << "\n";

	return 0;
}