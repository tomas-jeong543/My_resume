#define INF 10000001
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

vector<int> distances;
vector<vector<pair<int, int>>> adjList;
vector<int> Maxdises;
priority_queue<int,vector<int>, less<>> maxnums;

int AssignMaxDis(int node)
{

	int max = 0;
	int ins;
	bool det = true;
	priority_queue<int, vector<int>, less<>> insque;


	if(Maxdises[node] != -1){
		return Maxdises[node];
	}

	if (adjList[node].size() == 0) {
		Maxdises[node] = 0;
		return 0;
	}

	for (auto [v, weight] : adjList[node]) {
		ins = weight + AssignMaxDis(v);
		if (adjList[v].size() > 0)
			det = false;

		insque.push(ins);
	}

	ins = insque.top();

	
	for (int i = 0; i < 2; i++) {
		if (insque.empty())
			break;
		max += insque.top();
		insque.pop();
	}
	

	while (!insque.empty()) {
		insque.pop();
	}


	Maxdises[node] = max;
	return ins;
}



int main()
{
	int maxlen = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	stringstream buf;
	string input;
	int n, s, e, dis;
	int ans = -1, ins;

	cin >> n;
	cin.ignore();


	distances.assign(n, INF);
	adjList.assign(n, vector<pair<int, int>>());
	Maxdises.assign(n, -1);

	for (int i = 0; i < n - 1; i++) {
		cin >> s >> e >> dis;
		cin.ignore();
		adjList[s - 1].push_back(make_pair(e - 1, dis));
	}

	for (int i = 0; i < n ; i++) {
		if (Maxdises[i] == -1)
			AssignMaxDis(i);
	}

	for (int i = 0; i < n; i++) {
		if (Maxdises[i] > ans) {
			ans = Maxdises[i];
		}
	}


	cout << ans << "\n";
	return 0;
}