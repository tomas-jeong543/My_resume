
/*정렬 게임
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	128 MB	2659	435	333	27.453%
문제
즐거운 컴퓨터 프로그래밍 시간! 이번 시간의 수업 내용은 정렬이었다. 학생들은 오름차순 또는 내림차순으로 입력받은 값을 정렬해보기 시작하였다. 수업이 끝나갈 무렵, 오늘도 어김없이 조교의 과제가 주어졌다.
과제 이름은 정렬 게임. 과제 내용은 다음과 같다. 처음에 임의의 수열이 있고, 처음 위치부터 지정된 위치까지 오름차순, 내림차순, 오름차순, 내림차순, ... 의 순서를 반복하여 정렬하였을 때, 
어떠한 수가 나타나는지 출력하는 프로그램을 작성하는 것이었다.

예를 들어, 과제로 주어진 수열이 [4,1,2,3] 이고, 처음 위치부터 3번째 원소까지 오름차순, 그 다음 2번째 원소까지 내림차순으로 정렬한 결과를 출력하라고 할 경우를 보자. 처음 오름차순 정렬을 수행하면 [1,2,4,3] 이 
되고, 여기서 2번째 원소까지 내림차순으로 정렬하면 [2,1,4,3] 이 된다. 그리고 이것이 최종 정답이 된다. 정렬 게임에서 오름차순, 내림차순을 1번씩 하는 것을 한 세트를 진행했다고 정의한다. 수열과 K개의 세트가 주어질 
때, 최종 수열을 출력하는 프로그램을 작성하시오.

입력
입력 데이터는 표준 입력을 사용한다. 입력은 1개의 테스트 데이터로 구성된다. 입력의 첫 번째 줄에는 수열의 개수 N이 주어진다. (1 ≤ N ≤ 100,000)

입력의 두 번째 줄에는 N개의 수열의 원소가 공백으로 구분되어 주어진다. 수열의 원소는 -10,000보다 크거나 같고, 10,000보다 작거나 같은 정수이다.

입력의 세 번째 줄에는 세트의 개수 K가 주어진다. (1 ≤ K ≤ 100,000)

입력의 네 번째 줄부터 한 줄에 한 개씩 오름차순, 내림차순을 하는 구간을 뜻하는 두 수 A, B가 주어진다. 이는 1번째 원소부터 A번째 원소까지 오름차순 정렬을 한 후, 1번째 원소부터 B번째 원소까지
내림차순 정렬을 해야함을 의미한다.

출력
출력은 표준 출력을 사용한다. 입력받은 데이터에 대해, K개의 세트를 모두 진행하고 난 뒤 수열의 모든 원소를 출력한다.*/

#include<iostream>
#include<sstream>
#include<string>
#include<deque>
using namespace std;

void printArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void merge(int *arr, int low, int mid, int high, int opt) {

	int lsize = mid - low + 1;
	int rsize = high - mid;

	int* L = new int[lsize];
	int* R = new int[rsize];

	if (L == nullptr || R == nullptr) {
		exit(-1);
	}


	for (int i = 0; i < lsize; i++) {
		L[i] = arr[i + low];
	}
		

	for (int i = 0; i < rsize; i++) {
		R[i] = arr[mid + i + 1];
	}

	


	int x = 0, y = 0, z = low;

	if (opt == 1) {
		while (x < lsize && y < rsize) {
			if (L[x] > R[y]) {
				arr[z++] = R[y++];
			}
			else {
				arr[z++] = L[x++];
			}
		}

		while (y < rsize ) {
			arr[z++] = R[y++];
		}

		while (x < lsize) {
			arr[z++] = L[x++];
		}

		

	}
	else if(opt == 0 ){
		while (x < lsize && y < rsize) {
			if (L[x] < R[y]) {
				arr[z++] = R[y++];
			}
			else {
				arr[z++] = L[x++];
			}
		}

		while (x < lsize) {
			arr[z++] = L[x++];
		}

		while (y < rsize) {
			arr[z++] = R[y++];
		}
	}

	delete[] L;
	delete[] R;
}

int mergeSort(int arr[], int low, int high, int opt) {
	if (low < high) {
		int mid = low + (high - low) / 2;

		mergeSort(arr, low, mid, opt);
		mergeSort(arr, mid + 1 , high, opt);
		merge(arr, low, mid, high,opt);
		
	}
	return 1;
}


int maxNumk(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int main()
{
	int N, k;
	int a = 0, b = 0;
	int* Numbers;
	deque<pair<int, int>> info;

	string input;
	stringstream buf;
	cin >> N;
	cin.ignore();
	getline(cin, input);
	buf << input;
	cin >> k;
	Numbers = new int[N];

	for (int i = 0; i < N; i++) {
		buf >> Numbers[i];
	}
	buf.clear();
	buf.str("");
	cin.ignore();

	for (int i = 0; i < k; i++) {
		getline(cin, input);
		buf << input;
		buf >> a;
		buf >> b;
		buf.clear();
		buf.str("");

	

		if (info.empty()) {
			info.push_back(make_pair(a, b));
			continue;
		}

		if (maxNumk(a, b) < maxNumk(info.back().first, info.back().second)) {
			info.push_back(make_pair(a, b));
			
		}
		else {
			while (!info.empty() && maxNumk(a, b) >= maxNumk(info.back().first, info.back().second)) {
				
				info.pop_back();
				
			}
			info.push_back(make_pair(a, b));
			
		}
	}

	while (!info.empty()) {
		a = info.front().first;
		b = info.front().second;
		mergeSort(Numbers, 0, a - 1, 1);
		mergeSort(Numbers, 0, b - 1, 0);
		info.pop_front();
	}

	printArr(Numbers, N);
	delete[] Numbers;
	return 0;
}