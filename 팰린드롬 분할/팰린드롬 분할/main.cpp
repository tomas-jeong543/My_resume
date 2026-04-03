#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
string input;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> dp;
	vector<vector<bool>> palch;
	int n, ans = 0;

	getline(cin, input);
	
	n = input.length();
	dp.assign(n, 100000);
	palch.assign(n, vector<bool>());

	for (int i = 0;i < n; i++) {
		palch[i].assign(n, false);
		dp[i] = n - i;
	}
	
	for (int i = 0; i < n; i++) {
		palch[i][i] = true;
		
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j + i < n; j++) {
			if (i == 1) {
				if (input[j] == input[i + j]) {
					palch[j][i + j] = true;
				}
			}
			else {
				if (input[j] == input[i + j] && palch[j + 1][i + j - 1]) {
					palch[j][i + j] = true;
				}
			}
		}
	}

	if (palch[n - 2][n - 1]) {
		dp[n - 2] = 1;
	}
	

	//핵심 i번째 부터 분할 횟수를 계산하기 + j == n -1일 때의 예외처리가 핵심
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 1; j >= i; j--) {
			if (palch[i][j]) {
				if (j == n - 1) {
					dp[i] = 1;
				}
				else if (dp[i] > dp[j + 1] + 1) {
					dp[i] = dp[j + 1] + 1;
				}
			}
		}
	}


	/*for (int i = 0; i < n; i++) {
		cout << dp[i] << " ";
	}*/
	cout  << dp[0] << "\n";
	return 0;
}