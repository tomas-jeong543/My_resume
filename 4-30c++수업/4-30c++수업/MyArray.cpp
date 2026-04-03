#include "MyArray.h"
#include<iostream>

using namespace std;
MyArray::MyArray(size_t s):size(s),data(new int[this->size])
{
	cout << "크기가" << size << "인 배열 객체 생성자 호출" << endl;
}

MyArray::MyArray(const MyArray& other)
{
	cout << "복사 생성자 호출" << endl;
	this->size = other.size;
	this->data = new int[this->size];

	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

MyArray::MyArray(MyArray&& other) noexcept
{
	this->size = other.size;
	data = move(other.data);
}

MyArray& MyArray::operator=(const MyArray& other)
{
	if (this == &other) {
		return *this;
	}
	else {
		delete[] data;
		data = nullptr;
		this->size = other.size;
		this->data = new int[this->size];
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
		return *this;
	}
}

MyArray& MyArray::operator=(MyArray&& other) noexcept
{
	if(this != &other) {
		delete[] data;
		this->size = other.size;
		this->data = new int[this->size];
		data = nullptr;
		other.size = 0;
		return *this;
	}
}

MyArray::~MyArray()
{
	cout << "크기가" << size << "인 배열 객체 소멸자 호출" << endl;
	delete[] data;
}

int& MyArray::operator[](size_t index)
{
	if (index >= 0 && index < size) {
		return data[index];
	}
	else {
		cout << "배열 접근 오류" << endl;
		exit(0);
	}
}

const int& MyArray::operator[](size_t index) const
{
	if (index >= 0 && index < size) {
		return data[index];
	}
	else {
		cout << "배열 접근 오류" << endl;
		exit(0);
	}
}

void MyArray::setValue(size_t index, int value)
{
	if (index >= 0 && index < size) {
		this->data[index] = value;
	}
	else {
		cout << "배열 접근 오류" << endl;
		exit(0);
	}
}

void MyArray::printValue()
{
	for (int i = 0; i < size; i++) {
		cout << data[i] << "\t";
	}
	cout << endl;
}
