#pragma once
#include"DynamicArray.h"
#include<vector>
#include<iostream>

using namespace std;

template<typename T>
DynamicArray<T>::DynamicArray()
{
	//data = vector<T>(10);
}

template<typename T>
DynamicArray<T>::DynamicArray( DynamicArray<T>& rhs)
{
	for(int i = 0; i < rhs.data.size(); i++){
		this->data.push_back(rhs.data[i]);
	}
}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T>&& rhs)
{
	 this->data = std::move(rhs.data);
}


template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T>&& rhs)
{
	 if (&rhs != this) {
		 this->data.clear();
		 this->data = move(rhs.data);

	 }

	 return *this;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T>& rhs)
{
	 if (&rhs.data != this) {
		 this->data.assign(rhs.data);
	 }

	 return *this;
}


template<typename T>
 void DynamicArray<T>::push_back(const T& item)
{
	 this->data.push_back(item);
}

template<typename T>
 void DynamicArray<T>::pop_back()
{
	 if (this->data.size() == 0)
		 return;

	 this->data.pop_back();
}

 template<typename T>
 void DynamicArray<T>::pop(size_t index){
	 this->data.erase(this->data.begin() + index);
 }


template<typename T>
 T& DynamicArray<T>::operator[](size_t index){
	 if (index >= 0 && index < this->data.size()) {
		 return this->data[index];
	}
	else {
		 std::cout << "인덱스 접근 문제" << std::endl;
		 exit(0);
	 }
}

template<typename T>
size_t DynamicArray<T>::size() const
{
	return  this->data.size();
}

 template<typename T>
 void DynamicArray<T>::printArray(){
	 
	 int count = 0;
	 for (auto shape : this->data) {
		 std::cout << shape << " ";
		 count++;

		 if (count % 10 == 0 && count > 0) {
			 std::cout << std::endl;
		 }
	 }

	 cout << endl;
}


