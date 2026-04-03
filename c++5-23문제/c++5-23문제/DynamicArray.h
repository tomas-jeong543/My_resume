#pragma once
#include<vector>
#include<iostream>

using std::vector;

template<typename T>
class DynamicArray
{
private:
	vector<T> data;
public:

	DynamicArray();
	~DynamicArray() { this->data.clear(); };
	DynamicArray( DynamicArray& rhs);
	DynamicArray(DynamicArray&& rhs);
	DynamicArray& operator=(DynamicArray&& rhs);
	DynamicArray& operator=(DynamicArray& rhs);
	void push_back(const T& item);
	void pop_back(); //배열 마지막 요소 삭제.
	void pop(size_t index);
	T& operator[](size_t index); // 인덱스를 통한 요소 접근.
	size_t size() const;//저장된 요소의 개수를 반환.
	void printArray();
};

#include"DynamicArrayDef.h"