#include <iostream>
#include <vector>
using namespace std;

// 전역 변수로 상태 관리
vector<int> info;          // 학생이 선택한 상대
vector<bool> visited;      // 전체 DFS 방문 여부
vector<bool> inStack;      // 현재 DFS 경로 상에 있는지 여부
vector<bool> cleared;      // 사이클(팀) 처리 완료 여부
int teamCount;             // 팀(사이클)에 속한 학생 수

// u 노드에서 출발해 사이클이 생기면 카운트
void dfs(int u) {

    //방문 여부와 현재 경로상 정보 초기화
    visited[u] = true;
    inStack[u] = true;

    //다음 점 정보 획득
    int v = info[u];
    if (!visited[v]) {
        //재귀
        dfs(v);
    }
    else if (inStack[v]) {
        // v부터 u까지 순회하며 사이클에 속한 노드 처리 사이클 감지
        for (int w = v; ; w = info[w]) {
            //정보처리 완료
            cleared[w] = true;
            //팀 숫자 정보 증가
            teamCount++;
            //현재 점 도달 시 탈출
            if (w == u) break;
        }
    }

    //방문 처리를 거짓으로 바꾼다
    inStack[u] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        // 배열 크기 초기화
        info.assign(N, 0);
        visited.assign(N, false);
        inStack.assign(N, false);
        cleared.assign(N, false);
        teamCount = 0;

        // 입력 바로 받기
        for (int i = 0; i < N; i++) {
            cin >> info[i];
            --info[i];
        }

        // 아직 방문하지 않은 노드에서만 DFS 시작
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        // 팀에 포함되지 못한 학생 수 = 총 N - 팀원 수
        cout << (N - teamCount) << "\n";
    }

    return 0;
}
