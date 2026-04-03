#include "DynamicArray.h"

void DynamicArray::push_back(int value)
{
	if (size < capacity) {
		data[size++] = value;
	}
	else if (size == capacity) {
		capacity *= 2;
		int* ins = new int[capacity];

		for (int i = 0; i < size; i++) {
			ins[i] = data[i];
		}
		delete[] data;
		data = nullptr;
		
		data = ins;
		ins = nullptr;

		data[size++] = value;
	}
}

void DynamicArray::print() const
{
	for (int i = 0; i < size; i++) {
		cout << data[i] << '\t';
	}
}
