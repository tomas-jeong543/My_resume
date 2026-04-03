#pragma once
#include <memory>
using namespace std;

template<typename T>
class ArrayData{
protected:
	//double* data=nullptr;
	unique_ptr<T[]> data; 
	// //유니크 포인터는 대입 연산이 불가능
	//shared_ptr<T[]> data; //대입 가능
	int capacity;
	int used;
public:
	ArrayData();
	//매개변수는 default 값을 가질 수 있다 파이썬과 동일 순서 존재 무조건 뒤에서 부터 작성되어야 한다
	ArrayData(const int& capacity, const int& used = 0);
	
	//소멸자
	~ArrayData();
	
	//: 배열 생성하는 복사 생성자 족사 생성자는 하나만 존재가능하며 형태는 고정이 되어 있다
	ArrayData(const ArrayData& ins) :ArrayData(ins.capacity, ins.used);
	//이동 생성자
	ArrayData(ArrayData&& arr) noexcept;

	//4/30일 추가 내용

	//대입 연산자
	ArrayData& operator= (const ArrayData& rhs);
	//이동 대입 연산자
	ArrayData& operator= ( ArrayData&& rhs) noexcept;

	//배열 연산자 2개
	T& operator[] (size_t num);
	const T& operator[] (size_t num) const;

	void addElement(const T& num);
	
	//맴버 변수가 변하지 않는 함수 = const함수
	bool full() const;
	
	//배열 비우는 작업
	void emptyArray();
	void plusUsed();
	void showData() const;
	int getCapacity() const {
		return this->capacity;
	};

	//사용 횟수 반환
	int getUsed() const {
		return this->used;
	};
	template<typename T>
	friend ostream& operator<<(ostream& out, const ArrayData<T>& p);
};

#include"ArrayDataDef.h"
