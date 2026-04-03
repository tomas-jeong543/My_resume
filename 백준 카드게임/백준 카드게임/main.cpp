#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, k, card, curpos, nextpos;
string input;
stringstream buf;
vector<bool> used;
vector<int> posinfo;
vector<int> MyCard;
vector<int> EnemyCard;
vector<int> parent;


int find(int pos) {
	if (parent[pos] == pos) {
		return pos;
	}
	else {
		parent[pos] = find(parent[pos]);
	}
	return parent[pos];
}

void Merge(int i, int j) {
	
	int Ip = find(i);
	int Jp = find(j);

	if (Jp > Ip) {
		parent[Ip] = Jp;
	}
	else if(Ip < Jp){
		parent[Jp] = Ip;
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	cin.ignore();

	MyCard.assign(m, 0);
	EnemyCard.assign(k, 0);
	used.assign(m, false);
	parent.assign(m, 0);
	
	getline(cin, input);
	buf << input;

	for (int i = 0; i < m; i++) {
		buf >> MyCard[i];
		parent[i] = i;
	}

	buf.clear();
	buf.str("");

	getline(cin, input);
	buf << input;

	for (int i = 0; i < k; i++) {
		buf >> EnemyCard[i];
	}

	sort(MyCard.begin(), MyCard.end());

	for (int i = 0; i < k; i++) {
		auto it = upper_bound(MyCard.begin(), MyCard.end(), EnemyCard[i]);
		int pos = it - MyCard.begin();
		//cout << " before pos: " << pos << " parent[pos]: " << parent[pos] << "\n";
		
		int p = find(pos);
		cout << MyCard[p] << "\n";
		if(p + 1 < m)
			parent[p] = find(p + 1);

	}
	
	return 0;
}