#define INF 1000000001
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

void printArr(int N, vector<vector<int>> distance) {
	cout << "-------------------------------------------------\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << distance[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "-------------------------------------------------\n";
}

//벨만 포드 방식으로 모든 점에 대한 가중치를 계산해 거리 정보를 갱신한다
bool belmanFord(vector<int>& distance, vector<vector<pair<int, int>>>& graph, int N, int startpoint, int opt = 0) {
	
	bool det = true;

	//시작점을 설정하고 그 시작점과 연결된 모든 간선에 대해서 기존 거리와 정보를 비교해서 최단거리 정보를 갱신한다
	for (auto [w, v] : graph[startpoint]) {
		
			if (distance[v] > w + distance[startpoint] && distance[startpoint] != INF) {
				distance[v] = w + distance[startpoint];
				
				if (opt == 1)
					det = false;
		}
	}

	//변화한 값이 존재하면 false 그대로 이면 true를 반환한다
	return det;
}

bool sol(vector<vector<pair<int, int>>>& graph,int N, int M, int W ) {

	vector<int> distance;
	//임의의 점 하나를 잡고 그 점과 나머지 점의 거리를 0이라고 가정한다
	distance.assign(N,0);
	//종료접보
	bool detend = false;

	for (int k = 0; k < N -1; k++) {
		detend = true;
		//벨만 포드를 한 번 돌린다
		for (int i = 0; i < N; i++) {

			if (!belmanFord(distance, graph, N, i, 1)) {
				detend = false;
			}
		}
		//만약 벨만포드 방식을 1번 사용했어도 최단거리가 바귀지 않았다면 벨만 포드 방식을 더이상 실시하지 않는다.
		if (detend)
			break;
	}
	
	//벨만포드 방식을 한 번 더 사용했을 때 최단 거리가 감소했다면 이는 시간 여행이 가능하다는 의미 임으로true를 반환
	for (int i = 0; i < N; i++) {
		if (!belmanFord(distance, graph, N, i, 1)) {
			return true;
		}
	}
	//기존의 최단거리와 동일한 경우에는 시간여행이 불가능함으로 false를 반환한다 
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	stringstream buf;
	string input;
	int T, N, M, W;
	int s, e, time;
	bool det = false;
	vector<vector<pair<int, int>>> graph;

	cin >> T;
	cin.ignore();

	for (int i = 0; i < T; i++) {
		//입력 받기 및 공간 할당
		cin >> N >> M >> W;
		cin.ignore();
		graph.assign(N , vector<pair<int,int>>());
		det = false;

		for (int i = 0; i < M; i++) {
			cin >> s >> e >> time;
			cin.ignore();
			graph[s -1 ].push_back(make_pair(time, e - 1));
			graph[e - 1].push_back(make_pair(time, s - 1));
		}

		for (int i = 0; i < W; i++) {
			cin >> s >> e >> time;
			
			cin.ignore();
			graph[s - 1].push_back(make_pair(-1 * time, e - 1));
		}
		
		if (det)
			continue;


		//만약 시간 여행을 할 수 있다면 yes,아니면 no출력
		if (sol(graph,N,M,W)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}


		//메모리 할당 해제 과정
		for (int i = 0; i < N; i++) {
			graph[i].clear();
		}
		graph.clear();
	}

	return 0;
}