#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
//이거 inf값을 충분히 높게 설정하지 않았다가 틀렸다
#define INF 10000001
using namespace std;

int caldis(int bx, int by, int ax, int ay, int opt)
{
	int sum = 0;
	if (opt == 0) {
		if (bx == 0 && ax != 0) {
			sum += 2;
		}
		else if (abs(ax - bx) == 2) {
			sum += 4;
		}
		else if (abs(ax - bx) == 0) {
			sum += 1;
		}
		else {
			sum += 3;
		}
	}
	else {
		if (by == 0 && ay != 0) {
			sum += 2;
		}
		else if (abs(ay - by) == 2) {
			sum += 4;
		}
		else if (abs(ay - by) == 0) {
			sum += 1;
		}
		else {
			sum += 3;
		}
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string input;
	int n,ins, ans = INF, idx = 0;
	vector<int> info;
	vector<vector<vector<int>>> dp;
	stringstream buf;
	
	getline(cin,input);
	n = input.length() - 1;
	
	info.assign(n, 0);
	dp.assign(n + 1, vector<vector<int>>());

	buf << input;

	for (int i = 0; i < n; i++) {
		buf >> info[i];
	}

	for (int i = 0; i < n + 1; i++) {
		dp[i].assign(5, vector<int>());
		for (int j = 0; j < 5; j++) {
			dp[i][j].assign(5, INF);
		}
	}

	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++) {
		
		if (info[i] == 0) {
			idx = i;
			break;
		}
		
		if (i == 0) {
			dp[1][0][info[i]] = caldis(0, 0, 0, info[i], 1);
			dp[1][info[i]][0] = caldis(0, 0, info[i], 0, 0);
		}
		else {
			for (int j = 0; j < 5;j++) {
				if (j != info[i]) {
					for (int m = 0; m < 2; m++) {
						ins = INF;
						if (m == 0) {
							for (int k = 0; k < 5; k++) {
								ins = min(min(ins, dp[i][k][j] +caldis(k,j,info[i],j,m)), min(ins, dp[i][info[i]][k] + caldis(info[i],k,info[i],j,m + 1)));
							}

							if (ins < dp[i + 1][info[i]][j]) {
								dp[i + 1][info[i]][j] = ins;
							}
						}
						else {
							for (int k = 0; k < 5; k++) {
								ins = min(min(ins, dp[i ][j][k] + caldis(j, k, j,info[i], m)), min(ins, dp[i ][k][info[i]] + caldis( k,info[i], j, info[i], m - 1)));
							}

							if (ins < dp[i + 1][j][info[i]]) {
								dp[i + 1][j][info[i]] = ins;
							}
						}
					}

				}
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (ans > dp[idx][i][j]) {
				ans = dp[idx][i][j];
			}
		}
	}
	

	cout << ans << "\n";
	return 0;
}