#include<iostream>
#include<sstream>
#include<string>
#include<vector>
//문제의 해결방법은 부르토포스 알고리즘이다. 아니다 이건 do 다이내믹 프로그래밍으로 문제를 풀어야 한다

using namespace std;

vector<bool> visited;
vector<vector<int>> dict;
string ins;
int ans = 0;

int DP(string a, string b, int apos, int bpos) {

	cout << apos << " " << bpos << "\n";
	cout << dict[apos][bpos] << "\n";

	if (dict[apos][bpos] != -1) {
		return dict[apos][bpos];
	}


	char alpha = b[bpos];
	int ins;
	bool det = false;
	for (int i = bpos; i < b.length(); i++) {
		if (b[i] == alpha) {
			bpos = i + 1;
			det = true;
			break;
		}
	}

	if (det) {
		for (int i = apos + 1; i < a.length(); i++) {
			dict[i][bpos] = DP(a, b, i, bpos) + 1;
			if (dict[i][bpos] > ans)
				ans = dict[i][bpos];
		}
	}
	else {
		for (int i = apos + 1; i < a.length(); i++) {
			dict[i][bpos] = DP(a, b, i, bpos);
			if (dict[i][bpos] > ans)
				ans = dict[i][bpos];
		}
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	stringstream buf;
	string a, b,ans, ins;
	
	dict.assign(a.length(), vector<int>());
	for (int i = 0; i < a.length(); i++) {
		dict[i].assign(b.length(), -1);
	}
	visited.assign(26, false);
	
	cout << DP(a, b, 0, 0) << "\n";

	return 0;
}