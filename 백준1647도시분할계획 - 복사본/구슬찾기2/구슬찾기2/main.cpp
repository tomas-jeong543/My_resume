#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
#include<map>

using namespace std;

map<int, int> dict;
set<pair<pair<int, int>, pair<int, int> >> visited;
bool detend = false;
bool detfail = false;
//bord update관련 내용은 필요 bfs_search함수에 작성하면 된다.
int xmove[4] = { 1,-1,0,0 };
int ymove[4] = { 0,0,1,-1 };


void moveobj(int opt, int* xpos, int* ypos, int n, int m, vector<vector<char>> bord) {

	if ((xpos[0] == xpos[1]) && (opt == 2 || opt == 3)) {
		if (opt == 2) {
			if (ypos[0] > ypos[1]) {
				while (bord[xpos[0]][ypos[0]] != 'O' && bord[xpos[0]][ypos[0]] != '#') {
					xpos[0] += xmove[opt];
					ypos[0] += ymove[opt];
				}

				if (bord[xpos[0]][ypos[0]] == 'O')
				{

					while (bord[xpos[1]][ypos[1]] != 'O' && bord[xpos[1]][ypos[1]] != '#' && ypos[1] < ypos[0]) {
						xpos[1] += xmove[opt];
						ypos[1] += ymove[opt];
					}

					if (bord[xpos[1]][ypos[1]] == 'O' || ypos[0] == ypos[1] ) {
						detfail = true;
						return;
					}
					else {
						detend = true;
						return;
					}
				}
				else if (bord[xpos[0]][ypos[0]] == '#') {
					xpos[0] -= xmove[opt];
					ypos[0] -= ymove[opt];

					while (bord[xpos[1]][ypos[1]] != 'O' && bord[xpos[1]][ypos[1]] != '#' && ypos[1] < ypos[0]) {
						xpos[1] += xmove[opt];
						ypos[1] += ymove[opt];
					}

					if (bord[xpos[1]][ypos[1]] == 'O') {
						detfail = true;
					}
					else {
						xpos[1] -= xmove[opt];
						ypos[1] -= ymove[opt];
					}
				}
			}
			else {
				while (bord[xpos[1]][ypos[1]] != 'O' && bord[xpos[1]][ypos[1]] != '#') {
					xpos[1] += xmove[opt];
					ypos[1] += ymove[opt];
				}

				if (bord[xpos[1]][ypos[1]] == 'O')
				{
					detfail = true;
					return;
				}
				else if (bord[xpos[1]][ypos[1]] == '#') {
					xpos[1] -= xmove[opt];
					ypos[1] -= ymove[opt];

					while (bord[xpos[0]][ypos[0]] != 'O' && bord[xpos[0]][ypos[0]] != '#' && ypos[0] < ypos[1]) {
						xpos[0] += xmove[opt];
						ypos[0] += ymove[opt];
					}

					if (bord[xpos[0]][ypos[0]] == 'O') {
						detend = true;
					}
					else {
						xpos[0] -= xmove[opt];
						ypos[0] -= ymove[opt];
					}
				}
			}
		}
		else if (opt == 3) {
			if (ypos[0] < ypos[1]) {
				while (bord[xpos[0]][ypos[0]] != 'O' && bord[xpos[0]][ypos[0]] != '#') {
					xpos[0] += xmove[opt];
					ypos[0] += ymove[opt];
				}

				if (bord[xpos[0]][ypos[0]] == 'O')
				{

					while (bord[xpos[1]][ypos[1]] != 'O' && bord[xpos[1]][ypos[1]] != '#' && ypos[1] > ypos[0]) {
						xpos[1] += xmove[opt];
						ypos[1] += ymove[opt];
					}

					if (bord[xpos[1]][ypos[1]] == 'O' || ypos[0] == ypos[1]) {
						detfail = true;
						return;
					}
					else if(bord[xpos[1]][ypos[1]] == '#'){
						detend = true;
						return;
					}
					
				}
				else if (bord[xpos[0]][ypos[0]] == '#') {
					xpos[0] -= xmove[opt];
					ypos[0] -= ymove[opt];

					while (bord[xpos[1]][ypos[1]] != 'O' && bord[xpos[1]][ypos[1]] != '#' && ypos[0] < ypos[1]) {
						xpos[1] += xmove[opt];
						ypos[1] += ymove[opt];
					}

					if (bord[xpos[1]][ypos[1]] == 'O') {
						detfail = true;
					}
					else {
						xpos[1] -= xmove[opt];
						ypos[1] -= ymove[opt];
					}
				}
			}
			else {
				while (bord[xpos[1]][ypos[1]] != 'O' && bord[xpos[1]][ypos[1]] != '#') {
					xpos[1] += xmove[opt];
					ypos[1] += ymove[opt];
				}

				if (bord[xpos[1]][ypos[1]] == 'O')
				{
					detfail = true;
					return;
				}
				else if (bord[xpos[1]][ypos[1]] == '#') {
					xpos[1] -= xmove[opt];
					ypos[1] -= ymove[opt];

					while (bord[xpos[0]][ypos[0]] != 'O' && bord[xpos[0]][ypos[0]] != '#' && ypos[1] < ypos[0]) {
						xpos[0] += xmove[opt];
						ypos[0] += ymove[opt];
					}

					if (bord[xpos[0]][ypos[0]] == 'O') {
						detend = true;
					}
					else {
						xpos[0] -= xmove[opt];
						ypos[0] -= ymove[opt];
					}
				}
			}
		}
	}
	else if (ypos[0] == ypos[1] && (opt == 0 || opt == 1)) {
		if (opt == 0) {
			if (xpos[0] > xpos[1]) {
				while (bord[xpos[0]][ypos[0]] != 'O' && bord[xpos[0]][ypos[0]] != '#') {
					xpos[0] += xmove[opt];
					ypos[0] += ymove[opt];
				}

				if (bord[xpos[0]][ypos[0]] == 'O')
				{

					while (bord[xpos[1]][ypos[1]] != 'O' && bord[xpos[1]][ypos[1]] != '#' && xpos[1] < xpos[0]) {
						xpos[1] += xmove[opt];
						ypos[1] += ymove[opt];
					}

					if (bord[xpos[1]][ypos[1]] == 'O' || xpos[0] == xpos[1]) {
						detfail = true;
						return;
					}
					else {
						detend = true;
						return;
					}
				}
				else if (bord[xpos[0]][ypos[0]] == '#') {
					xpos[0] -= xmove[opt];
					ypos[0] -= ymove[opt];

					while (bord[xpos[1]][ypos[1]] != 'O' && bord[xpos[1]][ypos[1]] != '#' && xpos[1] < xpos[0]) {
						xpos[1] += xmove[opt];
						ypos[1] += ymove[opt];
					}

					if (bord[xpos[1]][ypos[1]] == 'O') {
						detfail = true;
					}
					else {
						xpos[1] -= xmove[opt];
						ypos[1] -= ymove[opt];
					}
				}
			}
			else {
				while (bord[xpos[1]][ypos[1]] != 'O' && bord[xpos[1]][ypos[1]] != '#') {
					xpos[1] += xmove[opt];
					ypos[1] += ymove[opt];
				}

				if (bord[xpos[1]][ypos[1]] == 'O')
				{
					detfail = true;
					return;
				}
				else if (bord[xpos[1]][ypos[1]] == '#') {
					xpos[1] -= xmove[opt];
					ypos[1] -= ymove[opt];

					while (bord[xpos[0]][ypos[0]] != 'O' && bord[xpos[0]][ypos[0]] != '#' && xpos[0] < xpos[1]) {
						xpos[0] += xmove[opt];
						ypos[0] += ymove[opt];
					}

					if (bord[xpos[0]][ypos[0]] == 'O') {
						detend = true;
					}
					else {
						xpos[0] -= xmove[opt];
						ypos[0] -= ymove[opt];
					}
				}
			}
		}
		else if (opt == 1) {
			if (xpos[0] < xpos[1]) {
				while (bord[xpos[0]][ypos[0]] != 'O' && bord[xpos[0]][ypos[0]] != '#') {
					xpos[0] += xmove[opt];
					ypos[0] += ymove[opt];
				}

				if (bord[xpos[0]][ypos[0]] == 'O')
				{

					while (bord[xpos[1]][ypos[1]] != 'O' && bord[xpos[1]][ypos[1]] != '#' && xpos[1] > xpos[0]) {
						xpos[1] += xmove[opt];
						ypos[1] += ymove[opt];
					}

					if (bord[xpos[1]][ypos[1]] == 'O' || xpos[1] == xpos[0]) {
						detfail = true;
						return;
					}
					else {
						detend = true;
						return;
					}
				}
				else if (bord[xpos[0]][ypos[0]] == '#') {
					xpos[0] -= xmove[opt];
					ypos[0] -= ymove[opt];

					while (bord[xpos[1]][ypos[1]] != 'O' && bord[xpos[1]][ypos[1]] != '#' && xpos[1] > xpos[0]) {
						xpos[1] += xmove[opt];
						ypos[1] += ymove[opt];
					}

					if (bord[xpos[1]][ypos[1]] == 'O') {
						detfail = true;
					}
					else {
						xpos[1] -= xmove[opt];
						ypos[1] -= ymove[opt];
					}
				}
			}
			else {
				while (bord[xpos[1]][ypos[1]] != 'O' && bord[xpos[1]][ypos[1]] != '#') {
					xpos[1] += xmove[opt];
					ypos[1] += ymove[opt];
				}

				if (bord[xpos[1]][ypos[1]] == 'O')
				{
					detfail = true;
					return;
				}
				else if (bord[xpos[1]][ypos[1]] == '#') {
					xpos[1] -= xmove[opt];
					ypos[1] -= ymove[opt];

					while (bord[xpos[0]][ypos[0]] != 'O' && bord[xpos[0]][ypos[0]] != '#' && xpos[0] > xpos[1]) {
						xpos[0] += xmove[opt];
						ypos[0] += ymove[opt];
					}

					if (bord[xpos[0]][ypos[0]] == 'O') {
						detend = true;
					}
					else {
						xpos[0] -= xmove[opt];
						ypos[0] -= ymove[opt];
					}
				}
			}
		}
	}
	else {
			while (bord[xpos[0]][ypos[0]] != 'O' && bord[xpos[0]][ypos[0]] != '#') {
				xpos[0] += xmove[opt];
				ypos[0] += ymove[opt];
			}

			if (bord[xpos[0]][ypos[0]] == 'O') {
				detend = true;
				return;
			}
			else if (bord[xpos[0]][ypos[0]] == '#') {
				xpos[0] -= xmove[opt];
				ypos[0] -= ymove[opt];
			}

			while (bord[xpos[1]][ypos[1]] != 'O' && bord[xpos[1]][ypos[1]] != '#') {
				xpos[1] += xmove[opt];
				ypos[1] += ymove[opt];
			}

			if (bord[xpos[1]][ypos[1]] == 'O') {
				detfail = true;
				return;
			}
			else if (bord[xpos[1]][ypos[1]] == '#') {
				xpos[1] -= xmove[opt];
				ypos[1] -= ymove[opt];
			}
	}
}

	void bfs_search(vector<vector<char>> bord, int xpos[2], int ypos[2], int n, int m) {

		queue<pair<pair<int, int>, pair<int, int> >> info;

		int depth = 1;
		int xp[2], yp[2];
		int rxp[2], ryp[2];
		int prevx[2], prevy[2];
		info.push({ {xpos[0],ypos[0]},{xpos[1],ypos[1]} });
		visited.insert({ {xpos[0],ypos[0]},{xpos[1],ypos[1]} });
		dict[1000 * xpos[0] + 100 * ypos[0] + 10 * xpos[1] + ypos[1]] = 1;


		while (!info.empty()) {


			rxp[0] = info.front().first.first;
			rxp[1] = info.front().second.first;
			ryp[0] = info.front().first.second;
			ryp[1] = info.front().second.second;
			depth = dict[1000 * rxp[0] + 100 * ryp[0] + 10 * rxp[1] + ryp[1]];
			//cout << "start: " << rxp[0] << " " << ryp[0] << " " << rxp[1] << " " << ryp[1] << "\n";
			info.pop();

			if (detend) {
				std::cout << depth << "\n";
				return;
			}

			if (depth > 10) {
				break;
			}

			for (int i = 0; i < 4; i++) {

				for (int j = 0; j < 2; j++) {
					xp[j] = rxp[j];
					yp[j] = ryp[j];
				}

				detfail = false;
				moveobj(i, xp, yp, n, m, bord);

				/*if (!detfail && (xp[0] <= 0 || xp[1] <= 0 || yp[0] <= 0 || yp[1] <= 0)) {
					cout << "depth: " << depth << " opt: " << i << " " << "rpos: " << xp[0] << " " << yp[0] << " bpos: " << xp[1] << " " << yp[1] << "\n";
				}*/
			/*	if (!detfail) {
					cout << "depth: " << depth << " opt: " << i << " " << "rpos: " << xp[0] << " " << yp[0] << " bpos: " << xp[1] << " " << yp[1] << "\n";
				}*/

				if (detend) {
					cout << depth << "\n";
					return;
				}

				if (!detfail && visited.find({ {xp[0],yp[0]},{xp[1],yp[1]} }) == visited.end()) {
					//cout << "check: " << xp[0] << " " << yp[0] << " " << xp[1] << " " << yp[1] << "\n";
					info.push({ { xp[0],yp[0] }, { xp[1],yp[1] } });
					visited.insert({ {xp[0],yp[0]},{xp[1],yp[1]} });
					dict[1000 * xp[0] + 100 * yp[0] + 10 * xp[1] + yp[1]] = depth + 1;
				}
			}
			depth += 1;
		}

		cout << "-1\n";

		return;
	}

	int main() {

		int n, m, count = 0;
		stringstream buf;
		string input;
		vector<vector<char>> bord;
		int xpos[2];
		int ypos[2];

		cin >> n >> m;
		cin.ignore();

		bord.assign(n, vector<char>());


		for (int i = 0; i < n; i++) {
			bord[i].assign(m, ' ');
			getline(cin, input);

			for (int j = 0; j < m; j++) {
				bord[i][j] = input[j];
				if (bord[i][j] == 'B') {
					xpos[1] = i;
					ypos[1] = j;
					bord[i][j] = '.';
				}
				else if (bord[i][j] == 'R') {
					xpos[0] = i;
					ypos[0] = j;
					bord[i][j] = '.';
				}
			}

		}

		bfs_search(bord, xpos, ypos, n, m);

		return 0;
	}