#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int ansl = 0, ansr = 0;

//대각선임을 확인하는 경우에 대한 구현
bool digit1[20];
bool digit2[20];

//이 부분에 대해서 백트레킹을 구현해야 한다
void dfs(int r, int c, int count, int opt, int n, vector<vector<int>>& bord) {
	if (c >= n) {
		r++;
		
		// 행(r)에 따라 시작 열을 결정 (r+c의 합이 짝수/홀수임을 유지)
		if (opt == 0) { // 흰 칸 그룹 (r+c가 짝수라고 가정)
			c = (r % 2 == 0) ? 0 : 1;
		}
		else {        // 검은 칸 그룹 (r+c가 홀수라고 가정)
			c = (r % 2 == 0) ? 1 : 0;
		}
	}

	if (r >= n) {
		if (opt == 0) ansl = max(ansl, count);
		else ansr = max(ansr, count);
		return;
	}

	// 3. 현재 칸(r, c)에 비숍을 놓을 수 있는가?
	if (bord[r][c] == 1 && !digit1[r + c] && !digit2[r - c + n - 1]) {
		digit1[r + c] = digit2[r - c + n - 1] = true;
		dfs(r, c + 2, count + 1, opt, n, bord); // 놓는 경우
		digit1[r + c] = digit2[r - c + n - 1] = false; // 복구
	}

	// 4. 안 놓는 경우 (항상 시도)
	dfs(r, c + 2, count, opt, n, bord);
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, maxposible = 0 ;
	string input;
	stringstream buf;
	vector<vector<int>> bord;

	cin >> n;
	cin.ignore();

	bord.assign(n, vector<int>());

	for (int i = 0; i < n; i++) {
		bord[i].assign(n, 0);
		getline(cin, input);
		buf << input;
		for (int j = 0; j < n; j++) {
			buf >> bord[i][j];
			if (bord[i][j] == 1) {
				maxposible++;
			}
		}
		buf.str("");
		buf.clear();

	}

	for (int i = 0; i < 20; i++) {
		digit1[i] = false;
		digit2[i] = false;
	}

	dfs(0, 0, 0, 0, n, bord);
	dfs(0, 1, 0, 1, n, bord);


	std::cout << ansl +  ansr << "\n";
}