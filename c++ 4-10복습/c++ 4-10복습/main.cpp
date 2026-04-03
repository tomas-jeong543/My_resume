#include<iostream>
#include<memory>
#include<ctime>
#include <time.h>
using namespace std;

using SharedDptr1 = shared_ptr<shared_ptr<int[]>[]>;
using SharedDptr2 = shared_ptr<shared_ptr<int>[]>;

void check_difference()
{
	SharedDptr1 orgin = make_shared<shared_ptr<int[]>[]>(5);
	SharedDptr2 compare = make_shared<shared_ptr<int>[]>(5);

	if (orgin == nullptr || compare == nullptr)
	{
		cout << "memory error" << endl;
		return;
	}

	for (int i = 0; i < 5; i++) {
		orgin[i] = make_shared<int[]>(10);

		compare[i] = make_shared<int>(10);
		//이는 int * arr = new int(10); 과 비슷한 의미이다
	}



	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			orgin[i][j] = i + j;
			//compare[i][j] = i + j; 이 문장은 실행이 불가능하다 왜냐하면 compare는 포인터 변수를 가지고 있기 때문 한 마디로 정수형 이차원 배열이 아니라 일차원 포인터를 가르키는 이차원포인터라는 의미이다
			
		}
		cout << "before: " << *compare[i] << endl;
		*(compare[i]) = i;
		cout << "after: " << *compare[i] << endl;
		cout << endl;
	}


}

inline int inline_func(int x)
{
	return x % 3;
}


int noneinline_func(int x)
{
	return x % 3;
}

int main()
{
	//check_difference();
	clock_t start = clock();
	for (int i = 0; i < 10000000; i++) {
		inline_func(i);
		//cout << inline_func(i) << endl;;
	}
	clock_t end = clock();

	cout << "인라인  함수" << endl;
	cout << static_cast<double>(end -start) << endl;



	clock_t start2 = clock();
	for (int i = 0; i < 10000000; i++) {
		noneinline_func(i);
		//cout << noneinline_func(i) << endl;;
	}
	clock_t end2 = clock();

	cout << "인라인 아닌 함수" << endl;
	cout << static_cast<double>(end2 - start2) << endl;

	return 0;
}