//트리인가 ? 다국어
//시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
//1 초	128 MB	8896	1664	1163	20.472 %
//문제
//트리는 굉장히 잘 알려진 자료 구조이다.트리를 만족하는 자료 구조는 비어 있거나(노드의 개수가 0개), 노드의 개수가 1개 이상이고 방향 간선이 존재하며 다음과 같은 조건을 만족해야 한다.
// 이때, 노드 u에서 노드 v로 가는 간선이 존재하면 간선을 u에 대해서는 '나가는 간선', v에 대해서는 '들어오는 간선'이라고 하자.
//
//들어오는 간선이 하나도 없는 단 하나의 노드가 존재한다.이를 루트(root) 노드라고 부른다.
//루트 노드를 제외한 모든 노드는 반드시 단 하나의 들어오는 간선이 존재한다.
//루트에서 다른 노드로 가는 경로는 반드시 가능하며, 유일하다.이는 루트를 제외한 모든 노드에 성립해야 한다.
//아래의 그림을 보자.원은 노드, 화살표는 간선을 의미하며, 화살표의 방향이 노드 u에서 노드 v로 향하는 경우 이는 이 간선이 u에서 나가는 간선이며 v로 들어오는 간선이다.
// 3개의 그림 중 앞의 2개는 트리지만 뒤의 1개는 트리가 아니다.
//
//
//
//당신은 간선의 정보들을 받아서 해당 케이스가 트리인지를 판별해야 한다.
//
//입력
//입력은 여러 개의 테스트 케이스로 이루어져 있으며, 입력의 끝에는 두 개의 음의 정수가 주어진다.
//
//각 테스트 케이스는 여러 개의 정수쌍으로 이루어져 있으며, 테스트 케이스의 끝에는 두 개의 0이 주어진다.
//
//각 정수쌍 u, v에 대해서 이는 노드 u에서 노드 v로 가는 간선이 존재함을 의미한다.u와 v는 0보다 크다.
//
//출력
//각 테스트 케이스에 대해서, 테스트 케이스의 번호가 k일 때(k는 1부터 시작하며, 1씩 증가한다) 트리일 경우 "Case k is a tree."를, 트리가 아닐 경우 "Case k is not a tree."를 출력한다.
#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

class Point{
public:
	int val;
	vector<int> children;
	Point(int value) :val(value) {
	}

	void appendChild(int val) {
		children.push_back(val);
	}

	int getPoint()const { return this->val; }
	bool exist(int val) {
		for (int i = 0; i < this->children.size(); i++) {
			if (this->children[i] == val)
				return false;
		}
		return true;
	}
};

//루트에서 모든 점 방문 가능한지 확인하는 함수
bool bfsSearch(vector<Point*>& plist, set<int> notrootNodes, const int& rootNode) {
	queue<int> visited;
	visited.push(rootNode);
	//cout << "root" << rootNode << endl;
	while (!visited.empty()) {
		int node = visited.front();
		visited.pop();
		for (auto p : plist) {
			if (p->getPoint() == node) {
				for (int child : p->children) {
					visited.push(child);
					//cout << "child: " << child << endl;
					notrootNodes.erase(child);
				}
				break;
			}
		}
	}

	if (notrootNodes.empty()) {
		return true;
	}
	else{
		return false;
	}
}

int main()
{
	
	int k = 1;
	bool detend = false;

	while (!detend) {
		//변수들
		vector<Point*> plist;
		set<int> notrootNodes;
		set<int> rootCandidates;
		
		int pointnum = 0;
		bool multiway = false;
		int root = -1;
		detend = false;
		//한 개의 트리를 입력받는 과정

		while (true) {
			bool end = false;
			int x, y;
			pointnum += 1;

			while (x < 0 && y > 0 || x > 0 && y < 0) {
				cin >> x >> y;
			}
			if (x < 0 && y < 0) {
				detend = true;
			}

			if (x == 0 && y == 0) {
				end = true;
			}



			if (detend || end) {
				break;
			}

			rootCandidates.insert(x);

			plist.push_back(new Point(x));
			//cout << "mys" << plist.size() - 1 << endl;
			int idx = 0;
			for (int i = 0; i < plist.size(); i++) {
				if (plist[i]->getPoint() == x) {
					idx = i;
					
				}
			}
			plist[idx]->appendChild(y);

			if (notrootNodes.find(y) == notrootNodes.end()) {
				notrootNodes.insert(y);
			}//한 점으로 가는 여러 개의 간선이 존재한다. 이 경우 그냥 빠져나간다.
			else{
				//cout << "here" << endl;
				multiway = true;
			}

		}
		
		if (detend) { 
			
			break; } 

		//루트 노드가 1개가 아님 혹은 한 점으로 가는 여러 간선이 존재한다.
		if (multiway || pointnum - 1 != notrootNodes.size()) {
			cout << "Case " << k << " is not a tree." << endl;
		}
		else {
			for (int num : notrootNodes) {
				rootCandidates.erase(num);
			}
			for (auto num : rootCandidates) {
				root = num;
				break;
			}
			if (bfsSearch(plist, notrootNodes, root)) {
				cout << "Case " << k << " is a tree." << endl;
			}
			else {
				cout << "Case " << k << " is not a tree." << endl; 
			}
		}
		k += 1;
		//메모리 할당 해제 부분
		for (int i = 0; i < plist.size(); i++) {
			delete plist[i];
		}
		//notrootNodes.clear();
	}
	return 0;
}