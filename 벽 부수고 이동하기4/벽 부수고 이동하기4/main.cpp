#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;


//지금 너비 탐색에서 그룹별 그룹 인원 수를 제는 개 중요한 거 같다.
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, ans = 0, gpid = 2, cx,cy,nx,ny;
	string input;
	stringstream buf;
	vector<vector<int>> mapinfo;
	vector<vector<bool>> visited;
	vector < vector<int>> group;
	queue<pair<int,int>> que;
	set<int> nums;
	map<int, int> gpinfo;


	cin >> n >> m;
	cin.ignore();

	mapinfo.assign(n, vector<int>());
	visited.assign(n, vector<bool>());
	group.assign(n, vector<int>());

	for (int i = 0; i < n; i++) {
		mapinfo[i].assign(m, 0);
		visited[i].assign(m, false);
		group[i].assign(m, 0);
		getline(cin, input);
		
		for (int j = 0; j < m; j++) {
			mapinfo[i][j] = input[j] - '0';
			group[i][j] = mapinfo[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (group[i][j] == 0) {
				que.push({ i,j });
				group[i][j] = gpid;
				gpinfo[gpid] = 1;

				while (!que.empty()) {
					auto node = que.front();

					cx = node.first;
					cy = node.second;
					que.pop();
					
					for (int k = 0; k < 4; k++) {
						ny = cy + dy[k];
						nx = cx + dx[k];

						if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || group[nx][ny] != 0) {
							continue;
						}
						else {
							que.push({ nx,ny });
							group[nx][ny] = gpid;
							gpinfo[gpid]++;
						}
					}

				}
				gpid++;
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << group[i][j] << " ";
		}
		cout << "\n";
	}*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mapinfo[i][j] == 0) {
				cout << "0";
			}
			else{

				ans = 1;
				for (int k = 0; k < 4; k++) {
					nx = i + dx[k];
					ny = j + dy[k];
					if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || group[nx][ny] == 1) {		
						continue;
					}
					else {
						nums.insert(group[nx][ny]);
					}
				}

				for (int num : nums) {
					
					ans += gpinfo[num];
				}

				nums.clear();
				cout << ans % 10;
			}
		}
		cout << "\n";
	}


	return 0;
}