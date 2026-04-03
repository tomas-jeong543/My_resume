#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n;
	int num;
	int count = 0;
	int sum = 0;
	int comb_file = 0;
	priority_queue<int, vector<int>> p;

	cin >> n;
	
	for (int i = 1; i < n + 1; i++) {
		cin >> num;
		p.push(-num);
	}

	while (!p.empty()) {
		
		
		if (count == 0) {
			comb_file += -1 * p.top();
			p.pop();
			
		}
		if (count == 1) {
			comb_file += -1 * p.top();
			p.pop();
			
			sum += comb_file;

			p.push(-1 * comb_file);
			comb_file = 0;
		}
		count = (count + 1) %2;
	}

	cout << sum << endl;

	return 0;
}


