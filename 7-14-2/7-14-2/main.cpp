#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

//무한대를 임의의 큰 값으로 설정함
const int INF = 1e9;

int N, M;
//인접 리스트
vector<vector<pair<int, int>>> adjList;
//방문 어부 확인 배열
vector<vector<bool>> visited;
//거리 정보 저장용
vector<int> dist;


//다익스트라 알고리즘
void dijkstra(int start) {
    //무한대의 값으로 초기화
    dist.assign(N, INF);
    //시작점만 0으로 만든다
    dist[start] = 0;
    //최소 힙 구조를 선언한다
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    //거리와 시작점을 힙구조에 삽입한다
    pq.push({ 0, start });


    //while문을 이용한다
    while (!pq.empty()) {
        //점 정보 획득 및 삭제
        auto [cost, u] = pq.top();
        pq.pop();

        //목표점까지 가는 최단 거리 정보의 갱신이 필요없는 경우에 대해서는 넘어간다 이 부분에 대해
        //의문 해결 이 점에서 다른 점으로 가는 점의 정보는 늘 그대로이다 그 뜻은 cost가 더 크면 비교가 무의미하다는 것이다
        if (cost > dist[u]) continue;

        for (auto& [v, weight] : adjList[u]) {
            //이미 방문한 점이면 넘어간다 이 부분은 이따가 최단 경로 지점을 지나지 않기 위해서 삽입된 구문이다
            if (visited[u][v]) continue;
            
            //인접한 점의 최단 경로 정보의 갱신이 필요하다면 갱신하고 갱신된 점의 정보를 힙에 넣는다.
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }
}



int main() {
    //최적화
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int start;

    cin >> N>> M;
    cin.ignore();
    cin >> start;
    cin.ignore();
    //초기화
    adjList.assign(N, vector<pair<int, int>>());
    visited.assign(N , vector<bool>(N, false));

    for (int i = 0; i < M; ++i) {
        int u, v, p;
        cin >> u >> v >> p;
        cin.ignore();
        adjList[u - 1].push_back({ v - 1, p });
    }
    //다익스트라 알고리즘 적용한 후에 최단 경로를 지우고 다시 다익스트라 알고리즘을 실행시켜 거의 최단 경로를 찾아낸다
    dijkstra(start - 1);

    //경로가 존재하지 않으면 -1 존재하면 경로의 거의 최단 경로를 출력한다
   
    for (int i = 0; i < N; i++) {
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}