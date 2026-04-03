#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;




vector<pair<int,pair<int,int>>> graph;
vector<pair<int, pair<int, int>>> mst;
vector<int> parent;
vector<int> degree;

bool compare(pair<int, pair<int, int>>& a, pair<int, pair<int, int>> b) {
	if (a.second.second < b.second.second)
		return true;
	else
		return false;
};

int union_find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		parent[x] = union_find(parent[x]);
		
	}
	return parent[x];
}

bool union_merge(int x, int y)
{
	int rootx, rooty;

	rootx = union_find(x);
	rooty = union_find(y);

	if (rootx == rooty)
		return false;
	else {
		if (degree[rootx] > degree[rooty]) {
			degree[rootx]++;
			parent[rooty] = rootx;
		}
		else {
			degree[rooty]++;
			parent[rootx] = rooty;
		}
		return true;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	int a, b, dis;
	int totaldis = 0;
	stringstream buf;
	string input;
	cin >> n >> m;
	cin.ignore();

	parent.assign(n + 2, 0);
	degree.assign(n + 2, 1);

	for (int i = 1; i < n + 2; i++) {
		parent[i] = i;
		degree[i] = i;
	}
		
	for (int i = 0; i < m; i++) {
		getline(cin, input);
		buf << input;
		
		buf >> a >> b >> dis;
		buf.str("");
		buf.clear();
		graph.push_back(make_pair(a, make_pair(b, dis)));
	}
	
	//cout << "--------------------------------------\n";
	sort(graph.begin(),graph.end(), compare);
	for (int i = 0; i < m; i++) {
		//cout << graph[i].first << " " << graph[i].second.first << " " << graph[i].second.second << "\n";
		a = graph[i].first;
		b = graph[i].second.first;
		dis = graph[i].second.second;
		
		if (union_merge(a, b)) {
			mst.push_back(make_pair(a, make_pair(b, dis)));
			//cout << a << " " << b  << " dis: " << dis << "\n";
		}

		
	}

	for (auto i = 0; i < mst.size() - 1; i++) {
		totaldis += mst[i].second.second;
		//cout << "totaldis: " << totaldis << "\n";
	}


	cout << totaldis << "\n";

	return 0;
}