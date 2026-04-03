#include<iostream>
#include<queue>
#include<vector>
#include<sstream>
#include<string>

using namespace std;

struct cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;

	}
};


int main() {

	int N, M;
	vector<pair<int, int>>* route;
	priority_queue< pair<int, int>, vector<pair<int, int>>, cmp> nextRoute;
	int* distance;
	int* visited;
	
	stringstream buf;
	
	cin >> N;
	cin >> M;
	cin.ignore();
	route = new vector < pair<int, int>>(N);
	distance = new int[N] {1000000001};
	visited = new int[ N ]{ 0 };

	for (int i = 0; i < M; i++) {
		int arr[3];
		string input;
		getline(cin, input);
		buf << input;

		for (int i = 0; i < 3; i++) {
			buf >> arr[i];
		}
		
		route[arr[0] - 1].emplace_back(arr[1] - 1, arr[2] - 1);
	}

	string StartEnd;
	getline(cin, StartEnd);
	buf << StartEnd;
	int start, end;

	buf >> start;
	buf >> end;
	
	distance[start - 1] = 0;
	visited[start - 1] = 0;
	
	for (auto info : route[start - 1]) {
		nextRoute.push(make_pair(info.first, info.second));
	}
	
	while (!nextRoute.empty()) {
		auto node = nextRoute.top();
		
		while (!nextRoute.empty()) {
			node = nextRoute.top();
			nextRoute.pop();
			if (visited[node.first - 1] == 0) {
				visited[node.first - 1] = 1;
				break;
			}
		}
		
		for (auto info : route[node.first - 1]) {
			if (distance[info.first - 1] > node.second + info.second) {
				distance[info.first - 1] = node.second + info.second;
			}
		}
	}


	delete route;
	return 0;
}