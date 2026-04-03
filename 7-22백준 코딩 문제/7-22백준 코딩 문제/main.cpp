#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#define SIZE 10000000
using namespace std;

vector<long long> dp;
map<long long, long long> info;

long long fib(long long x) {
	//cout << x << "\n";
	if (x == 0) {
		return 0;
	}
	else if (x == 1 || x == 2) {
		return 1;
	}
	else {

		if (x < SIZE && dp[x] != -1)
			return dp[x];


		if (x > SIZE) {

			if (info.find(x) != info.end()) {
				return info[x];
			}


			if (x % 2 == 0) {
				info[x] = (fib(x / 2 + 1) * fib(x / 2) + fib(x / 2) * fib(x / 2 - 1)) % 1000000007;
			}
			else {
				if (info.find((x + 1) / 2) == info.end()) {
					info[(x + 1) / 2] = fib((x + 1) / 2) % 1000000007;
				}
				
				if (info.find((x - 1) / 2) == info.end()) {
					info[(x - 1) / 2] = fib((x - 1) / 2) % 1000000007;
				}
				
				info[x] = (info[(x + 1) / 2] * info[(x + 1) / 2] + info[(x - 1) / 2] * info[(x - 1) / 2]) % 1000000007;
			}
			return info[x];
		}
		else {
			if (dp[x] != -1) {
				return dp[x];
			}
			else {
				if (x % 2 == 0) {
					dp[x] = (fib(x / 2 + 1) * fib(x / 2) + fib(x / 2) * fib(x / 2 - 1) ) % 1000000007;
				}
				else {
					long long num1 = fib((x + 1) / 2) % 1000000007;
					long long num2 = fib((x - 1) / 2) % 1000000007;

					dp[x] =( num1 * num1 + num2 * num2) % 1000000007;
				}
				return dp[x];
			}
		}
	}

}

int main()
{

	stringstream buf;
	string input;
	long long N;
	dp.assign(SIZE, -1);
	cin >> N;
	cin.ignore();
	
	long long num1 = 0;
	long long num2 = 1;
	long long num3 = 0;

	cout << fib(N) << "\n";

	return 0;
}		