#pragma once
#include <iostream>

using namespace std;

class DynamicArray
{
private:
	int* data;
	size_t size;
	size_t capacity;
public:
	DynamicArray():DynamicArray(10)
	{ }
	DynamicArray(size_t capcity2, size_t size2 = 0):capacity(capcity2), size(size2)
	{
		data = new int[capacity];
	}

	explicit DynamicArray( DynamicArray& ins) : DynamicArray(ins.capacity, ins.size)
	{
		for (int i = 0; i < this->size; i++) {
			data[i] = ins.data[i];
		}
	}

	DynamicArray(DynamicArray&& ins)noexcept : DynamicArray(ins.capacity, ins.size) 
	{
		ins.data = nullptr;
	}

	~DynamicArray(){
		delete[] data;
	}

	void push_back(int value);
	void print() const;

};

