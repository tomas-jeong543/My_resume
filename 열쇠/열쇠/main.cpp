#include<iostream>
#include<sstream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

int foundpaper = 0;
int lr[4] = { -1,1, 0, 0 };
int lh[4] = { 0,0,-1,1 };


bool key_found(char alpha, vector<bool>& alphabet, vector<vector<pair<int, int>>>& dict, queue<pair<int, int>>& curpos, vector<vector<bool>>& visited,
	vector<vector<bool>>& reachable, int w, int h) {

	int idx = static_cast<int>(alpha);
	int x, y;
	if (idx >= 97 && idx <= 122 && !alphabet[idx - 97]) {

		int pos = idx - 97;
		if (alphabet[pos]) {
			return true;
		}
		else
			alphabet[pos] = true;


		for (int i = 0; i < dict[pos].size(); i++) {
			x = dict[pos][i].first;
			y = dict[pos][i].second;
			if (visited[x][y])
				continue;
			else if (reachable[x][y] || x == 0 || x == h - 1 || y == 0 || y == w - 1) {
				curpos.push({ x,y });
				visited[x][y] = true;
			}
		}

		return true;
	}
	return false;
}

bool door_check(char ch, vector<bool>& alphabet) {
	int idx = static_cast<int>(ch);
	if (idx < 65 || idx > 90 || !alphabet[idx - 65]) {
		return false;
	}
	else {
		return true;
	}
}




void bfs_search(int& w, int& h, vector<vector<bool>>& visited, vector<vector<char>>& graph, queue<pair<int, int>>& curpos, vector<bool>& alphabet,
	vector<vector<pair<int, int>>>& dict, vector<vector<bool>>& reachable) {

	int xpos, ypos, nextx, nexty;

	while (!curpos.empty()) {
		xpos = curpos.front().first;
		ypos = curpos.front().second;
		curpos.pop();

		key_found(graph[xpos][ypos], alphabet, dict, curpos, visited, reachable, w, h);
	
		for (int i = 0; i < 4; i++) {
			nextx = xpos + lr[i];
			nexty = ypos + lh[i];

			if (xpos + lr[i] < 0 || xpos + lr[i] >= h || ypos + lh[i] < 0 || ypos + lh[i] >= w || visited[nextx][nexty]) {
				continue;
			}
			else {
				nextx = xpos + lr[i];
				nexty = ypos + lh[i];
				char ch = graph[nextx][nexty];
				int idx = static_cast<int>(ch);

				if (ch == '.' || door_check(ch, alphabet) || ch == '$' || idx >= 97 && idx <= 122) {
					curpos.push(make_pair(nextx, nexty));
					visited[nextx][nexty] = true;
					if (ch == '$') {
						foundpaper += 1;
					}
				}
				else if (!door_check(ch, alphabet) && !visited[nextx][nexty]) {
					reachable[nextx][nexty] = true;
				}
			}
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	stringstream buf;
	int w, h, T, idx;
	vector<vector<bool>> visited;
	vector<vector<bool>> reachable;
	vector<vector<char>>graph;
	queue<pair<int, int>> curpos;
	vector<bool> alphabet;
	vector<vector<pair<int, int>>> dict;
	char ch;

	cin >> T;
	cin.ignore();

	for (int i = 0; i < T; i++) {
		cin >> h >> w;
		cin.ignore();

		foundpaper = 0;
		visited.assign(h, vector<bool>());
		reachable.assign(h, vector<bool>());
		graph.assign(h, vector<char>());
		alphabet.assign(26, false);
		dict.assign(26, vector<pair<int, int>>());


		for (int i = 0; i < h; i++) {
			visited[i].assign(w, false);
			reachable[i].assign(w, false);
			graph[i].assign(w, ' ');
			cin >> input;
			cin.ignore();

			for (int j = 0; j < w; j++) {
				graph[i][j] = input[j];
				idx = static_cast<int>(graph[i][j]);
				if (idx >= 65 && idx <= 90) {
					dict[idx - 65].push_back({ i,j });
				}

			}
		}

		cin >> input;
		cin.ignore();

		for (int i = 0; i < input.size(); i++) {
			idx = static_cast<int>(input[i]);
			if (idx >= 97 && idx <= 122)
				alphabet[idx - 97] = true;
		}

		for (int i = 0; i < w; i++) {
			int idx = static_cast<int>(graph[0][i]);
			if (graph[0][i] == '*')
				continue;
			else if ((idx >= 65 && idx <= 90 && !door_check(graph[0][i], alphabet))) {
				reachable[0][i] = true;
			}
			else {
				curpos.push(make_pair(0, i));
				visited[0][i] = true;
				if (graph[0][i] == '$')
					foundpaper++;
			}
		}

		for (int i = 0; i < w; i++) {
			int idx = static_cast<int>(graph[h - 1][i]);
			if (graph[h - 1][i] == '*')
				continue;
			else if ((idx >= 65 && idx <= 90 && !door_check(graph[h - 1][i], alphabet))) {
				reachable[h - 1][i] = true;
			}
			else {
				curpos.push(make_pair(h - 1, i));
				visited[h -1][i] = true;
				if (graph[h -1][i] == '$')
					foundpaper++;
			}
		}

		for (int i = 1; i < h - 1; i++) {
			int idx = static_cast<int>(graph[i][0]);
			if (graph[i][0] == '*')
				continue;
			else if ((idx >= 65 && idx <= 90 && !door_check(graph[i][0], alphabet))) {
				reachable[i][0] = true;
			}
			else {
				curpos.push(make_pair(i, 0));
				visited[i][0] = true;
				if (graph[i][0] == '$')
					foundpaper++;
			}
		}

		for (int i = 1; i < h - 1; i++) {
			int idx = static_cast<int>(graph[i][w - 1]);
			if (graph[i][w - 1] == '*')
				continue;
			else if ((idx >= 65 && idx <= 90 && !door_check(graph[i][w - 1], alphabet))) {
				reachable[i][w - 1] = true;
			}
			else {
				curpos.push(make_pair(i, w - 1));
				visited[i][w - 1] = true;
				if (graph[i][w -1] == '$')
					foundpaper++;
			}
		}
		bfs_search(w, h, visited, graph, curpos, alphabet, dict, reachable);
		cout << foundpaper << "\n";
	}


	return 0;
}