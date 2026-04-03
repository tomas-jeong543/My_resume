#include<cmath>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>

using namespace std;

map<int, int> gpnum;
vector<int> parent;

pair<double, double> getpos(vector<int>& arr1, vector<int>& arr2) {
	pair<double, double> pos; 
	double x1 = arr1[0], y1 = arr1[1]; double x2 = arr1[2], y2 = arr1[3]; double x3 = arr2[0], y3 = arr2[1]; double x4 = arr2[2], y4 = arr2[3];
	double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4); 
	double numeratorX = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
	double numeratorY = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);
	pos.first = numeratorX / denominator; pos.second = numeratorY / denominator; 
	return pos; 
}

//  return값으로 0이면 겹치지 않는 다는 뜻이고 1이면 arr1안에 arr2가 포함된다는 의미이고 2이면 arr2에 arr1이 포함된다는 의미이고 3이면 그냥 둘이 교점이 있다는 의미로 해석

int check_colision(vector<int>& arr1, vector<int>& arr2) {
	
	if (arr1[2] - arr1[0] == 0) {
		if (arr2[2] - arr2[0] == 0) {
			if (arr1[2] != arr2[2]) {
				return 0;
			}

			if (arr1[3] >= arr2[3] && arr1[0] <= arr2[0]) {
				return 1;
			}
			else if (arr2[3] >= arr1[3] && arr2[0] <= arr1[0]) {
				return 2;
			}
			else if (arr1[1] > arr2[3] || arr1[3] < arr2[1]) {
				return 0;
			}
			else {
				return 3;
			}
		}
		else {
			pair<double, double> pos = getpos(arr1, arr2);
			
			if (pos.first >= max(arr1[0], arr2[0]) && pos.first <= min(arr1[2], arr2[2]) && pos.second >= max(arr1[1], arr2[1]) && pos.second <= min(arr1[3], arr2[3])) {
				return 3;
			}
			else {
				return 0;
			}

		}
	}

	if (arr2[2] - arr2[0] == 0) {
		if (arr1[2] - arr1[0] == 0) {
			if (arr1[2] != arr2[2]) {
				return 0;
			}
			
			if (arr1[3] >= arr2[3] && arr1[0] <= arr2[0]) {
				return 1;
			}
			else if (arr2[3] >= arr1[3] && arr2[0] <= arr1[0]) {
				return 2;
			}
			else if (arr1[1] > arr2[3] || arr1[3] < arr2[1]) {
				return 0;
			}
			else {
				return 3;
			}
		}
		else {
			pair<double, double> pos = getpos(arr1, arr2);

			if (pos.first >= max(arr1[0], arr2[0]) && pos.first <= min(arr1[2], arr2[2]) && pos.second >= max(arr1[1], arr2[1]) && pos.second <= min(arr1[3], arr2[3])) {
				return 3;
			}
			else {
				return 0;
			}

		}
	}
	double angle1 = static_cast<double>(arr1[3] - arr1[1]) / static_cast<double>(arr1[2] - arr1[0]);
	double angle2 = static_cast<double>(arr2[3] - arr2[1]) / static_cast<double>(arr2[2] - arr2[0]);

	if (angle1 == angle2) {
		if (arr1[0] <= arr2[0] && arr2[2] <= arr1[2]) {
			return 1;
		}
		else if (arr2[0] <= arr1[0] && arr1[2] <= arr2[2]) {
			return 2;
		}
		else if (arr1[2] < arr2[0] || arr1[0] > arr2[2]) {
			return 0;
		}
		else {
			return 3;
		}
	}
	else {
		pair<double, double> pos = getpos(arr1, arr2);

		if (pos.first >= max(arr1[0], arr2[0]) && pos.first <= min(arr1[2], arr2[2]) && pos.second >= max(arr1[1], arr2[1]) && pos.second <= min(arr1[3], arr2[3])) {
			return 3;
		}
		else {
			return 0;
		}
	}
}

int find_parent(int i) {
	if (parent[i] == i) {
		return i;
	}
	else {
		parent[i] = find_parent(parent[i]);
	}
}

void merge_gp(int i, int j,int opt) {

	int rootx, rooty;

	rootx = parent[i];
	rooty = parent[j];

	if (rootx == rooty)
		return;

	if (opt == 1) {
		parent[rooty] = rootx;
		gpnum[rootx] += gpnum[rooty];
		gpnum[rooty] = 0;
	}
	else if (opt == 2) {
		parent[rootx] = rooty;
		gpnum[rooty] += gpnum[rootx];
		gpnum[rootx] = 0;
	}
	else {
		if (gpnum[rootx] > gpnum[rooty]) {
			parent[rooty] = rootx;
			gpnum[rootx] += gpnum[rooty];
			gpnum[rooty] = 0;
		}
		else {
			parent[rootx] = rooty;
			gpnum[rooty] += gpnum[rootx];
			gpnum[rootx] = 0;
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	
	vector<vector<int>> info;
	int n, group_num = 0, maxnum = 1, opt;
	string input;
	stringstream buf;

	cin >> n;
	cin.ignore();

	info.assign(n, vector<int>());
	parent.assign(n, 0);

	for (int i = 0; i < n; i++) {
		info[i].assign(4, 0);
		parent[i] = i;
		gpnum[parent[i]] = 1;
	}

	for (int i = 0; i < n; i++) {
		getline(cin, input);
		buf << input;
		for (int j = 0; j < 4; j++) {
			buf >> info[i][j];
		}	
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				opt = check_colision(info[i], info[j]);
				cout << i << " " << j << " " << opt << "\n";
				if (opt != 0) {
					merge_gp(i, j, opt);
				}
			}
			
		}
	}

	for (int i = 0; i < n; i++) {
		if (gpnum[i] != 0) {
			group_num++;
			if (gpnum[i] > maxnum) {
				maxnum = gpnum[i];
			}
		}
	}

	cout << group_num << "\n";
	cout << maxnum << "\n";
}