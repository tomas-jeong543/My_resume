#include<iostream>
#include<vector>
using namespace std;

//이번 파일에서는 백터를 사용하는 방법에 대해 알아볼 것이다 백터는 기본적으로 동적으로 할당이 되는 파이썬의 리스트와 유사한 자료구조이다

int main()
{
	/*vector<int> v;
	//백터 변수 초기화
	vector<int> v = { 1,2,3 };
	//int 타입의 백터 배열 크기(10) 선언
	vector<int> v[10];
	//행은 가변이지만 열은 고정된 백터 변수 선언
	vector<int> v[] = { {1,2} ,{ 3, 4 } };
	//2차원 백터 변수 선언
	vector<vector<int>> v;
	//5개의 변수를 0으로 초기화
	vector<int> v(5);*/
	//5개의 변수를 3으로 초기화
	vector<int>v(5, 3);
	//v를 복사해서 백터 v2를 생성한다
	vector<int> v2(v);


	//vector는 capacity 가 부족하면 capacity의 반 만큼 추가로 메모리를 동적 할당한다 그렇기 때문에 reversed함수와 입력되는 데이터의
	//수량을 잘 안다면 vector의 메모리를 조금 더 효율적으로 이용할 수 있다
	
	//아래 두 함수는 다르다 이 점에 유의해야 한다 reserve는 메모리 공간을 더 받아오는 것이고 resize는 원소의 개수를 늘리는 것이다
	v.reserve(10);
	v.resize(10);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	//10을 마지막 원소 뒤에 넣는다
	//이 때에도 메모리 용량을 11개로 안잡아 놓으면 15개의 메모리 공간을 자기가 잡아 버려서 메모리 손실이 발생한다
	v.reserve(16);
	v.push_back(10);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n" << v.capacity() << "\n";

	//시작점을 가르키는 메소드를 it으로 대체
	vector<int> ::iterator it = v.begin();
	//맨 앞에 2삽입
	it = v.insert(it, 2);
	//맨 앞에서 부터 3을 2개 추가
	it = v.insert(it, 2, 3);
	//2번째 부터  4를 2개 추가
	it = v.insert(it + 2, 2, 4);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	//iteratoe를 이용한 백터 출력
	vector<int> v3;
	for (int i = 1; i < 6; i++) {
		v3.push_back(i);
	}

	cout << "\n";
  // Iterator로 Vector의 아이템을 출력
  // begin() : 첫번째 위치의 Iterator를 리턴
  // v1.end() : 마지막 아이템 다음 위치의 Iterator를 리턴
	for (auto i = v3.begin(); i != v3.end(); i++) {
		cout << *i << " ";
	}
	cout << "\n";
	// 반대 방향으로 아이템을 출력
  // rbegin(), rend()는 역순(reverse)의 Iterator를 리턴
	for (auto i = v3.rbegin(); i != v3.rend(); i++) {
		cout << *i << " ";
	}
	//at을 이용해서 출력할 수도 있다
	cout << "\n";
	for (int i = 0; i < v3.size(); i++) {
		cout << v3.at(i) << " ";
	}
}