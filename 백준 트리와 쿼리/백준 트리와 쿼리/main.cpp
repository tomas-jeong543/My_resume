#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;
vector<vector<int>> graph;
vector<vector<int>> Tree;
vector<int> size_info;


void Make_Tree(int curnode, int parent) {
	for (int node : graph[curnode]) {
		if (node != parent) {
			Tree[curnode].push_back(node);
			Make_Tree(node, curnode);
		}
	}
}

void CountSubtreeNodes(int node) {
	size_info[node] = 1;
	for (int child : Tree[node]) {
		CountSubtreeNodes(child);
		size_info[node] += size_info[child];
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, r, q, a, b;

	cin >> n >> r >> q;
	cin.ignore();

	Tree.assign(n + 1, vector<int>());
	graph.assign(n + 1, vector<int>());
	size_info.assign(n + 1, 0);

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		cin.ignore();
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	Make_Tree(r, -1);
	CountSubtreeNodes(r);

	for (int i = 0; i < q; i++) {
		cin >> a;
		cin.ignore();
		cout << size_info[a] << "\n";
	}

	return 0;
}