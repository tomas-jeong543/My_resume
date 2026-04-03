#include<iostream>
#include<sstream>
#include<string>
#include<vector>

#define INF 1000000001

using namespace std;

int Dp(int n, int startpos, int pos, vector<vector<int>>& dis, vector<vector<int>>& info)
{
	int ins;
	bool det = false;

	if (n == 0) {
		return dis[n][pos];
	}

	if (dis[n][pos] != INF) {
		return dis[n][pos];
	}
	else if (n == 1) {
		for (int i = 0; i < 3; i++) {
			if (i != pos && i != startpos) {
				ins = Dp(n - 1, startpos, i, dis, info) + info[n][pos];
				if (!det) {
					dis[n][pos] = ins;
					det = true;
				}

				if (ins < dis[n][pos]) {
					dis[n][pos] = ins;
				}
			}
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			if (i != pos) {
				ins = Dp(n - 1, startpos, i, dis, info) + info[n][pos];
				if (!det) {
					dis[n][pos] = ins;
					det = true;
				}

				if (ins < dis[n][pos]) {
					dis[n][pos] = ins;
				}
			}
		}
	}
	return dis[n][pos];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<int>> dis;
	vector<vector<int>> info;
	int n, ins, ans = INF;
	string input;
	stringstream buf;

	cin >> n;
	cin.ignore();

	info.assign(n, vector<int>());
	dis.assign(n, vector<int>());

	for (int i = 0; i < n; i++) {
		info[i].assign(3, 0);
		dis[i].assign(3, INF);
		getline(cin, input);
		buf << input;

		for (int j = 0; j < 3; j++) {
			buf >> info[i][j];
		}
		buf.clear();
		buf.str("");

	}

	for (int i = 0; i < 3; i++) {
		dis[0][i] = info[0][i];
	}

	for (int i = 0; i < 3; i++) {
		ins = Dp(n - 1, i, i, dis, info);
		if (ins < ans)
			ans = ins;
		for (int j = 1; j < n; j++) {
			dis[j].assign(3, INF);
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cout << dis[i][j] << " ";
		}
		cout << "\n";
	}*/

	cout << ans << "\n";
	return 0;
}