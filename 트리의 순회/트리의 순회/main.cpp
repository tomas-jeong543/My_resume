#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;

}typedef TNode;

vector<int> subvector(vector<int> orgin, int a, int b) {

	if (b < orgin.size()) {
		return vector<int>(orgin.begin() + a, orgin.begin() + b);
	}
	else {
		return vector<int>(orgin.begin() + a, orgin.begin() + orgin.size());
	}
}

int getIndex(const std::vector<int>& vec, int value) {
	auto it = std::find(vec.begin(), vec.end(), value); // 값 탐색
	if (it != vec.end()) {
		return static_cast<int>(std::distance(vec.begin(), it)); // 인덱스 계산
	}
}

void preorder_search(vector<int>& inorder, vector<int>& postorder, int instart, int inend,int poststart, int postend) {
	//cout << " " << instart << " " << inend << " " << poststart << " " << postend << "\n";
	if (poststart == postend || inend == instart) {
		cout << postorder[postend] << " ";
		return;
	}
	
	int root = postorder[postend];
	int inpos = getIndex(inorder, root);
	int lsize = inpos - instart;
	int rsize = inend - inpos;
	cout << root << " ";
	
	if (lsize > 0 && instart + lsize - 1 < inorder.size()) {
		preorder_search(inorder, postorder, instart, instart + lsize - 1, poststart, poststart + lsize - 1);
	}
	
	if (rsize > 0 && inpos + rsize < inorder.size()) {
		preorder_search(inorder, postorder, inpos +1, inpos  + rsize, poststart + lsize, poststart + lsize  +rsize - 1);
	}
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int count = 0;
	int n, inpos, postpos;
	TreeNode* root = new TreeNode();
	string input;
	stringstream buf;
	vector<vector<int>> orders;
	map<int, int> locin;
	map<int, int> locpost;
	cin >> n;
	cin.ignore();

	orders.assign(3, vector<int>());


	for (int i = 0; i < 3; i++) {
		orders[i].assign(n, 0);
	}

	for (int i = 0; i < 2; i++) {
		getline(cin, input);
		buf << input;



		for (int j = 0; j < n; j++) {
			buf >> orders[i][j];
			if (i == 0) {
				locin[orders[i][j]] = j;
			}
			else{
				locpost[orders[i][j]] = j;
			}
		}
		buf.str("");
		buf.clear();
	}

	//재귀적인 기법을 이용해서 트리의 탐색을 이어나아가야 한다
	preorder_search(orders[0], orders[1],0, n - 1 ,0,n - 1 );
	

	return 0;
}