#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
#include<vector>
#include<stack>
using namespace std;

vector<int> info;
vector<int> dp;
stack<int> ins;
stack<int> ans;
int* arr;


int main()
{
	
	
	int n;
	int pos = 0;
	string input;
	stringstream buf;
	cin >> n;
	cin.ignore();
	arr = new int[n];
	getline(cin, input);
	buf << input;
	dp.assign(n, 1);
	for (int i = 0; i < n; i++) {
		buf >> arr[i];
	}

	buf.str("");
	buf.clear();


	int dis;

	info.push_back(arr[0]);

	for (int i = 1; i < n; i++) {
		if (arr[i] > info.back()) {
			info.push_back(arr[i]);
			dp[i] = info.size();
		}
		else {
			auto it = lower_bound(info.begin(), info.end(), arr[i]);
			*it = arr[i];
			dis = distance(info.begin(), it) + 1;
			dp[i] = dis;
		}		
	}

	int target = info[info.size() - 1];
	int startpos;
	int num = info.size();
	int prevpos;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == target) {
			startpos = i;
			break;
		}
	}

	ins.push(startpos);
	int prevval = arr[startpos] + 1;
	cout << info.size() << "\n";
	//cout << "mys: " << arr[startpos] << " " << startpos << "\n";


	while (!ins.empty()) {

		int curpos = ins.top();
		ans.push(curpos);
		ins.pop();
		
		for (int i = curpos - 1; i >= 0; i--) {
			if (dp[i] == num - 1 && arr[i] < prevval) {
				ins.push(i);
				//cout << prevval << " " << arr[i] << "\n";
				break;
			}
		}
		prevval = arr[curpos];
		num--;
	}

	while (!ans.empty()) {
		cout << arr[ans.top()] << " ";
		ans.pop();
	}

	delete[] arr;
}