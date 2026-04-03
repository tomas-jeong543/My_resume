#include "DynamicArray.h"
#include<iostream>

using namespace std;

DynamicArray::DynamicArray(int cap, int size) :capcity(cap), size(size)
{
	arr = new int[cap];
	cout << "생성자 호출" << endl;
}

DynamicArray::~DynamicArray()
{
	if (arr != nullptr) {
		delete[] arr;
	}
}

DynamicArray::DynamicArray(const DynamicArray & rhs):DynamicArray(rhs.capcity, rhs.size)
{
	for (int i = 0; i < this->size; i++) {
		this->arr[i] = rhs.arr[i];
	}
}

DynamicArray::DynamicArray(DynamicArray && rhs) noexcept
{
	this->capcity = rhs.capcity;
	this->size = rhs.size;
	this->arr = rhs.arr;
	rhs.arr = nullptr;

}

DynamicArray& DynamicArray::operator=(const DynamicArray & rhs)
{
	if (this == &rhs) {
		return *this;
	}
	swap(*this, const_cast<DynamicArray&>(rhs));
	return *this;
}

DynamicArray& DynamicArray::operator=(DynamicArray && rhs)noexcept
{
	if (this != &rhs) {
		delete[] arr;
		this->capcity = rhs.capcity;
		this->size = rhs.size;
		this->arr = rhs.arr;
		rhs.arr = nullptr;

		return *this;
	}
	return *this;
}

int& DynamicArray::operator[](size_t num)
{
	if ( num < capcity) {
		return arr[num];
	}
	else {
		cout << "메모리 접근 오류" << endl;
		exit(0);
	}
}

const int& DynamicArray::operator[](size_t num) const
{
	if ( num < capcity) {
		return arr[num];
	}
	else {
		cout << "메모리 접근 오류" << endl;
		exit(0);
	}
}

void DynamicArray::swap(DynamicArray& first, DynamicArray& second) noexcept
{
	using std::swap;
	swap(first.size, second.size);
	swap(first.capcity, second.capcity);
	swap(first.arr, second.arr);
}
