#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	stringstream buf;
	string input;
	string s1, s2;

	int candidate = 0;
	int len1, len2;
	char ins;
	int idx = 0;
	bool det;
	getline(cin, s1);
	getline(cin, s2);
	len1 = s1.length();
	len2 = s2.length();

	

	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = len1 - 1; i >= 0; --i) {
		for (int j = len2 - 1; j >= 0; --j) {
			if (s1[i] == s2[j])
				dp[i][j] = dp[i + 1][j + 1] + 1;
			else
				dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	}
	cout << dp[0][0] << "\n";
	return 0;
}