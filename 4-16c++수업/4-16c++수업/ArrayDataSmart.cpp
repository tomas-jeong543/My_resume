#include "ArrayDataSmart.h"
#include <iostream>
using namespace std;
ArrayDataSmart::ArrayDataSmart()
	:ArrayDataSmart(3)
{

}

ArrayDataSmart::ArrayDataSmart(const ArrayDataSmart& arr):ArrayData(arr), usedB(arr.usedB), backdata(make_unique<double[]>(arr.capacity))
{
	cout << "ArrayDataSmart 복사생성자" << endl;
	for (size_t i = 0; i < usedB; i++) {
		backdata[i] = arr.backdata[i];
	}
}

//얕은 복사
ArrayDataSmart::ArrayDataSmart(ArrayDataSmart&& arr) noexcept
	:ArrayData(move(arr)), usedB(arr.usedB), backdata(move(arr.backdata))
{
	cout << "ArrayDataSmart 이동생성자" << endl;
}

ArrayDataSmart::ArrayDataSmart(const int& capacity, const int& used)
	: ArrayData(capacity, used), usedB(0), backdata(make_unique<double[]>(capacity))
{
	cout << "ArrayDataSmart 생성자" << endl;
}

ArrayDataSmart::~ArrayDataSmart() {
	cout << "ArrayDataSmart 소멸자" << endl;
}


//아래 두 과정은 서로 반대이다. 기존 정보를 저장하는 과정이다
void ArrayDataSmart::backup() {
	if (backdata != nullptr) {
		usedB = used;
		for (size_t i = 0; i < usedB; i++) {
			backdata[i] = data[i];
		}
	}
}
//저장된 정보를 불러오는 함수이다.
void ArrayDataSmart::restore() {
	if (backdata != nullptr) {
		used = usedB;
		for (size_t i = 0; i < usedB; i++) {
			data[i] = backdata[i];
		}
	}
}

ArrayDataSmart& ArrayDataSmart::operator=(const ArrayDataSmart& rhs)
{
	
	if (this == &rhs) {
		return *this;
	}
	//부모 클래스의 대입 연산자를 호출한다.
	ArrayData::operator=(rhs);
	this->usedB = rhs.usedB;
	//data = static_cast<shared_ptr<double[]>>(new double[capacity]);

	return *this;

	
}

ArrayDataSmart& ArrayDataSmart::operator=(const ArrayDataSmart&& rhs) noexcept
{
	if (this == &rhs) {
		return *this;
	}
	//const형 제거 한 후에 부모의 이동 생성자를 호출하기 위해 rvalue를 lvalue로 바꾼다
	ArrayDataSmart && ins = const_cast<ArrayDataSmart&&>(rhs);
	ArrayData::operator=(std::move(ins));

	//this->capacity = rhs.capacity;
	//this->used = rhs.used;
	//this->usedB = rhs.usedB;
	//std::exchange(data, rhs.data);
	
	return *this;
}
