#include<iostream>
#include<string>
#include<sstream>
#include<vector>

//union_find문제

using namespace std;

int find_parent(int i, vector<int>& parent) {
	if (parent[i] == i) {
		return i;
	}
	else {
		parent[i] = find_parent(parent[i], parent);
	}

	return parent[i];
}

bool merge(int i, int j , vector<int>& parent) {
	
	int Jp = find_parent(i,parent);
	int Ip = find_parent(j, parent);

	if (Ip == Jp) {
		return false;
	}

	parent[Jp] = Ip;
	return true;
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, a, b;
	vector<int> parent;

	cin >> n >> m;
	cin.ignore();
	parent.assign(n, 0);

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cin.ignore();

		if (!merge(a, b, parent)) {
			cout << i + 1 << "\n";
			return 0;
		}
	}

	cout << "0\n";
	return 0;
}