#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool compare1(pair<int, int> a, pair<int, int> b) {

	if (a.first == b.first) {
		return a.second < b.second;
	}

	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, k, gpnum = 0, a, b;
	string input;
	stringstream buf;

	vector<int> nums;
	vector<bool> visited;
	vector<vector<int>> frinedlist;
	vector<vector<int>> dp;
	vector<pair<int,int>> gpinfo;
	queue<int> route;

	cin >> n >> m >> k;
	cin.ignore();
	getline(cin, input);
	buf << input;

	nums.assign(n, 0);
	visited.assign(n, false);
	frinedlist.assign(n, vector<int>());

	for (int i = 0; i < n; i++) {
		buf >> nums[i];
	}

	buf.str("");
	buf.clear();

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cin.ignore();
		frinedlist[a - 1].push_back(b - 1);
		frinedlist[b - 1].push_back(a - 1);

	}

	int node, sum = 0, nodenum = 0;
	for (int i = 0; i < n; i++) {
		
		if (!visited[i]) {
			sum = 0;
			nodenum = 0;
			route.push(i);
			//cout << "startpos: " << i << "\n";
			while (!route.empty()) {
				
				node = route.front();
				visited[node] = true;
				sum += nums[node];
				route.pop();
				nodenum++;

				for (int j = 0; j < frinedlist[node].size(); j++) {
					if (!visited[frinedlist[node][j]]) {
						route.push(frinedlist[node][j]);
						visited[frinedlist[node][j]] = true;
					}
				}
			}
			gpinfo.push_back({ nodenum, sum });
		}
	}

	sort(gpinfo.begin(), gpinfo.end(), compare1);
	/*cout << "--------------------\n";
	for (int i = 0; i < gpinfo.size(); i++) {
		cout << gpinfo[i].first << " " << gpinfo[i].second << "\n";
	}
	cout << "--------------------\n";*/
	dp.assign(gpinfo.size(), vector<int>());
	for (int i = 0; i < gpinfo.size(); i++) {
		dp[i].assign(k , 0);
	}

	for (int i = 0; i < gpinfo.size(); i++) {
		for (int j = 0; j < k; j++) {
			if (i == 0) {
				if (j >= gpinfo[i].first) {
					dp[i][j] = gpinfo[i].second;
				}
			}
			else if (j < gpinfo[i].first) {
				dp[i][j] = dp[i - 1][j];
			}
			else{

				if (dp[i - 1][j] < dp[i - 1][j - gpinfo[i].first] + gpinfo[i].second) {
					dp[i][j] = dp[i - 1][j - gpinfo[i].first] + gpinfo[i].second;
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
	}

	/*for (int j = 0; j < gpinfo.size(); j++) {
		for (int i = 0; i < k ; i++) {
			cout << dp[j][i] << " ";
		}
		cout << "\n";
	}
	*/

	cout << dp[gpinfo.size() - 1][k - 1] << "\n";
}