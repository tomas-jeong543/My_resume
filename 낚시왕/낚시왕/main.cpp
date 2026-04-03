#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };


void Fishing(int& price, vector<vector<vector<vector<int>>>>& locinfo, int row, int col) {

	for (int i = 0; i < col; i++) {
		if (locinfo[i][row].size() != 0) {
			//cout << "i: " << i << " row: " << row << " " << locinfo[i][row][0][2] << "\n";
			//cout << locinfo[i][row][0][0] << " " << locinfo[i][row][0][1] << " " << locinfo[i][row][0][2] << "\n";
			price += locinfo[i][row][0][2];
			locinfo[i][row].clear();
			return;
		}
	}
}


pair<int,int> cal_loc(int curx, int cury, int speed, int& dir, int r, int c) {

	int ny, nx;

	ny = cury + speed * dy[dir - 1];
	nx = curx + speed * dx[dir - 1];

	while(nx < 0 || nx >= r ) {
		if (nx < 0) {
			nx *= -1;
			dir = 2;
		}
		else if (nx >= r) {
			nx = 2 * r - 2 - nx;
			dir = 1;
		}
	}

	while (ny < 0 || ny >= c) {
		if (ny < 0) {
			ny *= -1;
			dir = 3;
		}
		else if (ny >= c) {
			ny = 2 * c - 2 - ny;
			dir = 4;
		}
	}
	//cout << nx << " " << ny << "\n";
	return make_pair(nx, ny);
}


void move(vector<vector<vector<vector<int>>>>& locinfo, int r, int c) {

	vector<vector<int>> ins_vec;
	vector<int> ins;
	vector<int> ins2;
	int x, y;
	ins.assign(5, 0);
	ins2.assign(3, 0);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {

				if (locinfo[i][j].size() == 0)
					continue;
			
				pair<int,int> inspair = cal_loc(i, j, locinfo[i][j][0][0], locinfo[i][j][0][1],r,c);
				ins[0] = inspair.first;
				ins[1] = inspair.second;
				ins[2] = locinfo[i][j][0][0];
				ins[3] = locinfo[i][j][0][1];
				ins[4] = locinfo[i][j][0][2];

			ins_vec.push_back(ins);
			locinfo[i][j].clear();
		}
	}
	
	for (auto vec : ins_vec) {

		x = vec[0];
		y = vec[1];

		for (int i = 0; i < 3; i++) {
			ins2[i] = vec[i + 2];
		}

		if (locinfo[x][y].size() == 0) {
			locinfo[x][y].push_back(ins2);
		}
		else {
			if (locinfo[x][y][0][2] < vec[4]) {
				for (int i = 0; i < 3; i++) {
					locinfo[x][y][0][i] = ins2[i];
				}
			}
		}
	}
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	stringstream buf;
	int r, c, m, price = 0;
	vector<vector<int>> info;
	vector<vector<vector<vector<int>>>> locinfo;
	vector<int> insvec;


	cin >> r >> c >> m;
	cin.ignore();

	insvec.assign(3, 0);
	info.assign(m, vector<int>());
	locinfo.assign(r, vector<vector<vector<int>>>());

	for (int i = 0; i < r; i++) {
		locinfo[i].assign(c, vector<vector<int>>());
	}

	for (int i = 0; i < m; i++) {

		info[i].assign(5, 0);
		getline(cin, input);
		buf << input;
		for (int j = 0; j < 5; j++) {
			buf >> info[i][j];
		}
		
		for (int j = 0; j < 3; j++) {
			insvec[j] = info[i][j + 2];
		}
		
		locinfo[info[i][0] -1][info[i][1] -1].push_back(insvec);
		buf.str("");
		buf.clear();
	}
	
	for (int i = 0; i < c; i++) {
		//cout << "i: " << i  << " price: " << price << "\n";
		Fishing(price, locinfo, i, r);
		move(locinfo, r, c);
		
	}
	
	cout << price << "\n";

	return 0;
}