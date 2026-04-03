#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int dx[4] = {0,0,-1,1 };
int dy[4] = {1,-1,0,0};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, curx, cury, gpnum = 0,gpcount = 0, bx ,by;
	string input;
	stringstream buf;
	vector<vector<char>> mapinfo;
	vector<vector<int>> parent;
	map<char, int> info;

	cin >> n >> m;
	cin.ignore();

	mapinfo.assign(n, vector<char>());
	parent.assign(n, vector<int>());

	info['D'] = 0, info['U'] = 1, info['L'] = 2, info['R'] = 3;
	
	for (int i = 0; i < n; i++) {
		mapinfo[i].assign(m, 0);
		getline(cin, input);
		buf << input;
		for (int j = 0; j < m; j++) {
			buf >> mapinfo[i][j];
		}
		buf.str("");
		buf.clear();
		parent[i].assign(m, -1);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (parent[i][j] == -1) {
			
				parent[i][j] = gpnum;
				cury = j + dx[info[mapinfo[i][j]]];
				curx = i + dy[info[mapinfo[i][j]]];
				//cout << i << " " << j << " curx: " << curx << " " << cury << "\n";
				while ((curx != i || cury != j) && parent[curx][cury] == -1) {
					//cout << "curx: " << curx << " cury: " << cury << "\n";
					parent[curx][cury] = gpnum;
					bx = curx;
					by = cury;
					cury = by + dx[info[mapinfo[bx][by]]];
					curx = bx + dy[info[mapinfo[bx][by]]];
				}

				if (parent[curx][cury] == gpnum) {
					gpcount++;
				}

				gpnum++;
			}
		}
	}

	cout << gpcount << "\n";

	return 0;
}