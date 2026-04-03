/*
문제
소수를 유난히도 좋아하는 창영이는 게임 아이디 비밀번호를 4자리 ‘소수’로 정해놓았다. 어느 날 창영이는 친한 친구와 대화를 나누었는데:

“이제 슬슬 비번 바꿀 때도 됐잖아”
“응 지금은 1033으로 해놨는데... 다음 소수를 무엇으로 할지 고민중이야"
“그럼 8179로 해”
“흠... 생각 좀 해볼게. 이 게임은 좀 이상해서 비밀번호를 한 번에 한 자리 밖에 못 바꾼단 말이야. 예를 들어 내가 첫 자리만 바꾸면 8033이 되니까 소수가 아니잖아. 여러 단계를 거쳐야 만들 수 있을 것 같은데.
.. 예를 들면... 1033 1733 3733 3739 3779 8779 8179처럼 말이야.”
“흠...역시 소수에 미쳤군. 그럼 아예 프로그램을 짜지 그래. 네 자리 소수 두 개를 입력받아서 바꾸는데 몇 단계나 필요한지 계산하게 말야.”
“귀찮아”
그렇다. 그래서 여러분이 이 문제를 풀게 되었다. 입력은 항상 네 자리 소수만(1000 이상) 주어진다고 가정하자. 주어진 두 소수 A에서 B로 바꾸는 과정에서도 항상 네 자리 소수임을 유지해야 하고, 
‘네 자리 수’라 하였기 때문에 0039 와 같은 1000 미만의 비밀번호는 허용되지 않는다.
*/
#include<deque>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


bool Check_vec(vector <string> arr , string target) {

	for (int i = 0; i < arr.size(); i++) {
		if (target.compare(arr[i]) == 0)
			return true;
	}

	return false;
}

bool Check_Prime(int num)
{
	for (int i = 2; i < static_cast<int>(sqrt(num)); i++) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

int dfs_search(string prime1, string prime2, int time, int maxtime , deque<string> route ,bool det)
{
	route.push_back(prime1);

	unordered_map<string, deque<string> > visited;


	while (route.size() > 0 || prime1.compare(prime2) != 0) {

		
		string node = route[0];
		cout << "node: " << node << endl;
		route.pop_back();
		
		int before = route.size();

		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < 10; j++) {
				
				if (i == 0 && j == 0 || i == j)
					continue;
				string org = node;
				char ins = node[i];
				node[i] = j + '0';
				if (Check_Prime(stoi(node))) {

					if (visited.count(node) > 0) {

						deque<string> info = visited[org];

						for (int i = 0; i < info.size(); i++) {
							if (info[i].compare(node) == 0)
								continue;
							}	
					
					}
					route.push_front(node);
					visited[org].push_back(node);
				}
			}
		}

		if (before == route.size()) {
			visited[node].clear();
		}
	}

	return maxtime;
}


int main()
{
	int T;

	cin >> T;
	string prev = "0000";
	deque<string> route = {};

	for (int i = 0; i < T; i++) {
		int prime1, prime2;

		cin >> prime1 >> prime2;

		if (prime1 ==  prime2) {
			cout << "0\n";
			continue;
		}
		
		string a = to_string(prime1);
		string b = to_string(prime2);
		int time = 0;
		int ans = 1;
		ans = dfs_search(a, b, time, 2100000, route, false);
		cout << "ans: " << ans << endl;
	}

	return 0;
}