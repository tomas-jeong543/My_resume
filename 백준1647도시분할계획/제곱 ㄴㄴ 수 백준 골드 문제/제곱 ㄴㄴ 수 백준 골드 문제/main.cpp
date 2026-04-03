
/*/제곱 ㄴㄴ 수
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	512 MB	74370	15281	10824	22.579 %
문제
어떤 정수 X가 1보다 큰 제곱수로 나누어 떨어지지 않을 때, 그 수를 제곱ㄴㄴ수라고 한다.제곱수는 정수의 제곱이다.min과 max가 주어지면, 
min보다 크거나 같고, max보다 작거나 같은 제곱ㄴㄴ수가 몇 개 있는지 출력한다.

입력
첫째 줄에 두 정수 min과 max가 주어진다.

출력
첫째 줄에 min보다 크거나 같고, max보다 작거나 같은 제곱ㄴㄴ수의 개수를 출력한다.

제한
1 ≤ min ≤ 1, 000, 000, 000, 000
min ≤ max ≤ min + 1, 000, 000*/
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
	long long int min;
	long long int max;
	int num = 0;

	cin >> min >> max;
	int size = max - min + 1;

	vector< bool> check_num(size, true);
	
	for (long long int i = 2; i * i <= max; i++) {
		long long square = i * i;
		long long start = ((min - 1 + square) / square) * square;
		for (long long j = start; j <= max; j += square) {
			check_num[j - min] = false;
		}
	}

	int sum = 0;
	for (auto n : check_num) {
		if (n) { sum += 1; }
	}

	cout << sum << endl;

	return 0;
}