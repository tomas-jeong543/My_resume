#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#define INF 100001

using namespace std;

map<vector<int>, int> hash_info;
vector<vector<int>> opt;
vector<int> sorted_vec;

void switch_func(vector<int>& vec, int a, int b) {
	int tmp;
	tmp = vec[a];
	vec[a] = vec[b];
	vec[b] = tmp;
}

bool cmpvec(vector<int>&  a, vector<int>&  b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

bool detend(int val) {
	if (hash_info.find(sorted_vec) == hash_info.end()) {
		return false;
	}
	else {
		if (hash_info[sorted_vec] <= val) {
			return true;
		}
		else {
			return false;
		}
	}
}

void bfs_search(vector<int>& curstate ) {
	
	queue<vector<int>> que;
	que.push(curstate);

	while (!que.empty()) {
		
		int price = hash_info[que.front()];


		for (auto op : opt) {
			switch_func(que.front(), op[0], op[1]);
			if (hash_info.find(que.front()) == hash_info.end()  || hash_info[que.front()] > price + op[2]) {
				hash_info[que.front()] = price + op[2];
				if (hash_info.find(sorted_vec) == hash_info.end() || hash_info[sorted_vec] > price + op[2]) {
					que.push(que.front());
				}
			}
			switch_func(que.front(), op[0], op[1]);
		}
		
			que.pop();
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string input;
	stringstream buf;
	int n,m, ans = 0;
	vector<int> nums;
	vector<int> visited;
	
	cin >> n;
	cin.ignore();
	getline(cin, input);

	sorted_vec.assign(n, 0);
	visited.assign(n, false);
	nums.assign(n, 0);

	buf << input;
	for (int i = 0; i < n; i++) {
		buf >> nums[i];
		sorted_vec[i] = nums[i];
	}
	buf.str("");
	buf.clear();

	cin >> m;
	cin.ignore();

	opt.assign(m, vector<int>());

	for (int i = 0; i < m; i++) {
		opt[i].assign(3, 0);
		getline(cin, input);
		buf << input;
		for (int j = 0; j < 3; j++) {
			buf >> opt[i][j];
			if (j != 2) {
				opt[i][j]--;
			}
		}
		buf.str("");
		buf.clear();
	}

	sort(sorted_vec.begin(), sorted_vec.end());

	hash_info[nums] = 0;
	bfs_search(nums);

	if (hash_info.find(sorted_vec) == hash_info.end()) {
		cout << "-1\n";
	}
	else
		cout << hash_info[sorted_vec] << "\n";
	return 0;
}