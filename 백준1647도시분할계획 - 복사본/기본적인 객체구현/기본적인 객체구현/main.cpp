#include<iostream>
#include"DynamicArray.h"
using namespace std;

int main() {
	DynamicArray arr1(5);
	DynamicArray arr2 = arr1; // 복사 생성자 호출
	DynamicArray arr3 = std::move(arr1); // 이동 생성자 호출
	arr2 = arr3; // 복사 대입 연산자 호출
	//arr1은 null로 존재는 하지만 배열 요소나 동적 할당된 요소 접근시 런타임 애러가 발생할 수 있다
	cout << arr1.sizeinfo() << " " << arr2.sizeinfo() << " " << arr3.sizeinfo() << endl;
	arr3 = std::move(arr2); // 이동 대입 연산자 호출
	
	return 0;
}