#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<vector<int>> mat(N, vector<int>(N));

    // N^2 / 2 개의 숫자를 사용해야 함.
    // 2x2 블록 (i, j), (i, j+1), (i+1, j), (i+1, j+1)을 하나의 단위로 봅니다.
    int count = 1;
    int half_total = (N * N) / 4;

    for (int i = 0; i < N; i += 2) {
        for (int j = 0; j < N; j += 2) {
            // p와 q를 한 블록에 배치
            // p = 현재 번호, q = 현재 번호 + (전체 숫자의 절반)
            // 이렇게 하면 p와 q가 서로 멀리 떨어져서 합의 성질이 안정화됩니다.
            int p = count;
            int q = count + half_total;

            // 대각선 배치로 거리 2 확보
            mat[i][j] = p;
            mat[i + 1][j + 1] = p;

            mat[i][j + 1] = q;
            mat[i + 1][j] = q;

            count++;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mat[i][j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}