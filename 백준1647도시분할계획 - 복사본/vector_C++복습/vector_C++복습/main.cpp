#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void printArray(vector<T> ins) {
	for (auto i : ins) {
		cout << i << "\t";
	}
	cout << endl;
}


int main()
{
	string str(5, 'a');
	vector<string> vec;
	//복제본 추가
	vec.push_back(str);
	printArray(vec);
	//str은 상태가 불분명할 수 있으므로 사용하지 말 것
	vec.push_back(move(str));
	printArray(vec);
	//이동 의미론 버전 추가
	vec.push_back(string(5, 'a'));
	printArray(vec);
	//임플레이스 연산 복제나 이동 연산을 수행하지 않고 바로 생성하는 방법
	vector<string> vec2;
	cout << "emplace practice " << endl;
	vec2.emplace_back(5, 'a');
	vec2.emplace_back(4, 'a');
	vec2.emplace_back(3, 'a');
	vec2.emplace_back(2, 'a');
	vec2.emplace_back(1, 'a');

	string* pstr = vec2.data();
	pstr[2] = "greenjoa";
	for (auto& s : vec2) {
		cout << s << endl;
	}

	cout << endl; 
	cout << "iterator를 이용한 삽입과 삭제 예시" << endl;
	vector<int> intvec(2, 5);

	vector<int>::iterator it = intvec.begin();
	// 주어진 포인터가 가르키는 위치에 데이터를 삽입하는 함수insert
	intvec.insert(it, 100);
	intvec.erase(intvec.end(), intvec.end());
	printArray(intvec);

	cout << endl << "백터의 재할당" << endl;
	vector<int> intvec2(10);
	printArray(intvec2);
	intvec2.assign(5, 100);
	printArray(intvec2);
	intvec2.assign({ 1,2,3,4 });
	printArray(intvec2);
	return 0;
}