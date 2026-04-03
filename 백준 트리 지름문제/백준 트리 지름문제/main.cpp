#include<iostream>
#include<sstream>
#include<string>
#include<queue>
using namespace std;

void search(bool* leafinfo, int N,int eraseNode, int* parentNode) {

	queue<int> erasedNodes;

	erasedNodes.push(eraseNode);
	leafinfo[eraseNode] = false;

	while (!erasedNodes.empty()) {
		int node = erasedNodes.front();
		erasedNodes.pop();

		for (int i = 0; i < N; i++) {
		
			if (parentNode[i] == node) {
				leafinfo[i] = false;
				erasedNodes.push(i);
			}
		}
	}
}

int main() {
	int N, eraseNode;
	int* info;
	bool* leafNode;
	bool* existNode;
	stringstream buf;
	string infostr;
	int num;
	int idx = 0;
	cin >> N;
	info = new int[N];
	leafNode = new bool[N];
	existNode = new bool[N];
	cin.ignore();

	getline(cin, infostr);
	buf << infostr;
	cin >> eraseNode;

	for (int i = 0; i < N; i++) {
		buf >> num;
		info[i] = num;
		leafNode[i] = true;
		existNode[i] = true;
	}


	search(existNode, N, eraseNode, info);

	for (int i = 0; i < N; i++) {
		leafNode[i] = existNode[i];
	}

	for (int i = 0; i < N; i++) {
		if (info[i] >= 0 && existNode[i]) {
			leafNode[info[i]] = false;
		}
	}


	int leafcount = 0;
	for (int i = 0; i < N; i++) {
		if (leafNode[i] == true) {
			leafcount++;
		}
	}
	cout << leafcount << endl;

	delete[] info;
	delete[] leafNode;
	delete[] existNode;
	return 0;
}