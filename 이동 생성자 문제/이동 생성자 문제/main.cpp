#include <iostream>
#include"DynamicArray.h"
#include <utility>  // std::move 필요

using namespace std;

int main() {
    // 기본 생성자 사용 (초기 capacity = 10)
    DynamicArray arr1;
    for (int i = 0; i < 8; ++i) {
        arr1.push_back(i);
    }

    cout << "arr1 내용: ";
    arr1.print();
    cout << endl;
    // 매개변수 생성자 사용 (초기 capacity = 5)
    DynamicArray arr2(5);
    for (int i = 100; i < 105; ++i) {
        arr2.push_back(i);
    }
    cout << "arr2 내용: ";
    arr2.print();
    cout << endl;


    // 이동 생성자 사용: arr3는 arr2의 자원을 가져감
    DynamicArray arr3(arr2);
    cout << "arr3 (이동 후) 내용: ";
    arr3.print();
    cout << endl;
    cout << "arr2 (이동 후, 안전 상태) 내용: ";
    arr2.print();

    //// 이동 대입 연산자 사용
    //DynamicArray arr4;
    //arr4 = arr3;
    //cout << "arr4 (이동 대입 후) 내용: ";
    //arr4.print();
    //cout << "arr3 (이동 후, 안전 상태) 내용: ";
    //arr3.print();

    return 0;
}
