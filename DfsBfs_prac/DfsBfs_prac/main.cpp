#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int dx[8] = { 2,2,-2,-2, 1,1 , -1,-1 };
int dy[8] = { 1,-1,1,-1,2,-2,2,-2 };
int maxDepth = 0;
int max(int x, int y) {
	if (x > y)
		return x;
	else
		return y;

}
void dfs(int x, int y,int R, int C, bool** visited, char** map, int depth = 0) {
	maxDepth = max(maxDepth, depth);
	for (int dir = 0; dir < 8; dir++) {
		
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= R || ny >= C || map[nx][ny] == '#')continue;

		if (!visited[nx][ny]) {
			visited[nx][ny] = true;
			dfs(nx, ny, R, C, visited, map, depth + 1);
			visited[nx][ny] = false;
		}
	}
}

int main()
{
	int N, M;
	char** bord;
	bool** visited;

	cin >> N >> M;

	bord = new char*[N];
	visited = new bool* [N];
	
	if (bord != nullptr && visited != nullptr) {
		for (int i = 0; i < N; i++) {
			bord[i] = new char[M];
			visited[i] = new bool[M] {false};
		}
	}
	string input;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		input = "";
		getline(cin,input);
		for (int j = 0; j < M; j++) {
			bord[i][j] = input[j];
		}
	}
	visited[0][0] = true;
	dfs(0, 0, N, M, visited, bord);

	cout << "ans: " << maxDepth << endl;
	return 0;
}