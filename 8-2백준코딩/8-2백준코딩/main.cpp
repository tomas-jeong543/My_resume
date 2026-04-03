#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
//문제의 해결방법은 부르토포스 알고리즘이다. 아니다 이건 do 다이내믹 프로그래밍으로 문제를 풀어야 한다

using namespace std;

vector<vector<int>> dp;
vector<char> alpha;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	stringstream buf;
	string a, b;
	string ansstr, ins;
	bool det = true;
	getline(cin, a);
	getline(cin, b);


	dp.assign(a.length() + 1, vector<int>());

	for (int i = 0; i < a.length() + 1; i++)
		dp[i].assign(b.length() + 1, 0);

	for (int i = 1; i < a.length() + 1; i++) {
		det = true;
		for (int j = 1; j < b.length() + 1; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				
			}
		}
	}

	int N = a.length() + 1;
	int M = b.length() + 1;
	int i = N, j = M;

	while (i > 0&& j > 0) {

		if (a[i - 1] == b[j - 1]) {
			alpha.push_back(a[i - 1]);
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) {
			i--;
		}
		else {
			j--;
		}
	}


	cout << dp[a.length()][b.length()] << "\n";

	if (dp[a.length()][b.length()] == 0) {
		return 0;
	}

	reverse(alpha.begin(), alpha.end());

	for (int i = 0; i < alpha.size() -1; i++) {
		cout << alpha[i];
	}
	return 0;
}