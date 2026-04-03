#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

#include<iostream>
#include"ArrayDataSmart.h"
#include <vector>

using namespace std;

ostream& operator<<(ostream& out, const ArrayData& p) {
	for (int i = 0; i < p.getUsed(); i++) {
		cout << p[i] << "\t";
	}
	cout << endl;
	return out;
}
//복사 생성자를 호출하는 함수들
void showArrayData(ArrayData& arr)
{
	cout << __FUNCTION__ << "(&)" << endl;
	arr.showData();
}

//임시 객체가 들어오는 경우 여기로 옴
void showArrayData(ArrayData&& arr)
{
	cout << __FUNCTION__ << "(&&)" << endl;
	arr.showData();
}

/* rvalue인지 lvalue인지 구분이 어렵다
void showArrayData(const ArrayData& arr)
{
	arr.showData();
}*/

ArrayData getArrayData(const int num) {
	ArrayData arr(num);
	//임시 객체 반환
	return arr;
}

void showArr(const ArrayData& arr) {
	for (int i = 0; i < arr.getUsed(); i++) {
		cout << arr[i] << endl;
	}

}





int main()
{
	////main부분
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//cout << "202211364 정명훈" << endl;

	//ArrayData arr1 = getArrayData(10);
	//arr1.addElement(5.5);
	//arr1.addElement(2.5);
	//arr1.showData();


	//추가로 작성한 코드 이동 생성자 작동하는지 확인하는 과정
	/*ArrayData arr2 = getArrayData(10);
	arr2.addElement(6.5);
	arr2.addElement(3.5);*/
	//showArrayData(arr2);

	//showArrayData(getArrayData(5));

	//explict을 통해 명시적 형변환만 허용
	/*ArrayData arr3(arr2);
	ArrayData arr4(move(arr2));
	showArrayData(arr2);
	arr2.showData();*/
	//임시 객체를 인자로 전달하는 경우에는 이동 연산자가 호출이 된다 상당히 중요
	//showArrayData(getArrayData(5));

	//vector<ArrayData> vec;
	//cout << "==============" << endl;
	//for (int i = 0; i < 5; i++) {
	//	//데이터를 복사해 저장 매번 갱신될 때마다 이동 생성자를 호출하며 정보를 갱신한다
	//	vec.push_back(ArrayData(5));
	//}

	////내부에서 동적할당을 하는 객체이다
	//ArrayData arr1(5);
	//arr1.addElement(10.5);
	//arr1.addElement(11.5);
	//arr1.addElement(12.5);
	//arr1.showData();
	//
	////복사 생성자 호출
	////ArrayData arr2 = arr1;
	//cout << "=======================" << endl;
	//ArrayData arr2(arr1);
	//arr1.addElement(5.7);
	//arr2.showData();
	//cout << "=======================" << endl;
	//showArrayData(arr1);
	//cout << "=======================" << endl;
	////ArrayData arr = ArrayData(7); 와 동일한 의미를 가지고 최적하기가  작동하고 생성자가 호출된다는 점에서 같다
	//ArrayData arr = getArrayData(7);
	/*cout << "after programing" << endl;*/


	ArrayDataSmart arr1(5);
	arr1.addElement(5.5);
	arr1.addElement(2.5);
	arr1.backup();
	arr1.addElement(3.5);
	cout << "================" << endl;
	cout << arr1 << endl;
	arr1.restore();
	cout << "================" << endl;
	cout << arr1 << endl;


	//여기부터는 다시 만들어야 한다.
	ArrayDataSmart arr2, arr3;
	arr2 = arr1;
	arr3 = move(arr1);

	cout << arr2 << endl;
	cout << arr3 << endl;
	return 0;
}