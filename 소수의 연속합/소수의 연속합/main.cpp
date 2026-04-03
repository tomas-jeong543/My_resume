#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

void prime_check( vector<int>& primenum, int n) {
	int limit = int(sqrt(n)) + 1;
	bool det = false;
	primenum.push_back(2);

	for (int i = 3; i < n + 1; i++) {
		det = false;
		for (auto num : primenum) {
			if (num > sqrt(i)) {
				break;
			}
			if (i % num == 0) {
				det = true;
				break;
			}
		}
		if (!det) {
			primenum.push_back(i);
		}

	}
}


int main()
{
	int n, psize,ans = 0;
	long long ins;
	vector<int> primenum;
	vector<long long> sum;
	//이걸 지우고 위의 sum만 이용해서 문제를 풀면된다
	map<int, int> info;

	cin >> n;
	cin.ignore();
	
	prime_check(primenum, n);
	psize = primenum.size();

	if (psize == 0) {
		cout << "0\n";
		return 0;
	}

	//cout << "check: " << psize << "\n";

	sum.assign(psize, 0);

	sum[0] = 2;

	for (int i = 1; i < psize; i++) {
		sum[i] = sum[i - 1] + primenum[i];
	}

	for (int i = 0; i < psize; i++) {
		for (int j = i; j < psize; j++) {
			ins = sum[j] - sum[i] + primenum[i];
			if (ins == n) {
				ans++;
			}
			else if (ins > n)
				break;
		}
	}
	cout << ans << "\n";
	return 0;
}