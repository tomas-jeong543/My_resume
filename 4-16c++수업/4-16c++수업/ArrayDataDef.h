#pragma once
#include"ArrayData.h"
#include <iostream>
using namespace std;

//기본 생성자 방 3개 생성
template<typename T>
ArrayData<T>::ArrayData():ArrayData(3){}

template<typename T>
ArrayData<T>::ArrayData(const int& capacity, const int& used) :capacity(capacity), used(used)
{
	cout << "생성자" << endl;
	//공간 만큼 할당
	//data = new double[this->capacity];
	data = make_unique<T[]>(this->capacity);
	//data = shared_ptr<double[]>(new double[this->capacity]);
}
template<typename T>
ArrayData<T>:: ArrayData(const ArrayData& ins) :ArrayData(ins.capacity, ins.used) {
	cout << "복사 생성자 호출" << endl;
	//방 대 방 복사
	for (int i = 0; i < this->used; i++) {
		data[i] = ins.data[i];
	}
}
template<typename T>
ArrayData<T>::ArrayData(ArrayData&& arr) noexcept
//여기 까지는 얕은 복사 과정이다
//유니크 포인터 사용시 move함수를 이용해서 r-value로 바꾸면 된다. 그러면 이동이 가능하다
	:capacity(arr.capacity), used(arr.used), data(move(arr.data))
{
	//포인터 전달 후에는 임시객체는 null값으로 설정한다 이문장이 매우 중요하다
	cout << "이동 생성자 호출" << endl;
	arr.data = nullptr;
}

//소멸자
template<typename T>
ArrayData<T>::~ArrayData()
{
	cout << "소멸자 호출" << endl;
	/*if (data != nullptr)
		delete[] data;
	data = nullptr;*/
}
template<typename T>
ArrayData<T>& ArrayData<T>::operator=(const ArrayData<T>& rhs)
{
	if (this == &rhs) {
		return *this;
	}
	this->capacity = rhs.capacity;
	this->used = rhs.used;
	data.reset(new T[capacity]);
	//data = static_cast<shared_ptr<double[]>>(new double[capacity]);
	for (size_t i = 0; i < used; i++) {
		data[i] = rhs.data[i];
	}
	return *this;
}

template<typename T>
ArrayData<T>& ArrayData<T>::operator=(ArrayData<T>&& rhs) noexcept
{
	this->capacity = rhs.capacity;
	this->used = rhs.used;
	data = move(rhs.data);
	return *this;
	// TODO: 여기에 return 문을 삽입합니다.
}

template<typename T>
T& ArrayData<T>::operator[](size_t num)
{
	//이전 요소가 정의가 되있지 않으면 접근 불가 오류 발생
	if (num > (this->used)) {
		cout << "접근 불가 오류" << endl;
		exit(0);
	}

	//개선 방안 안에서 증가시킴 + 
	if (num == this->used) {
		plusUsed();
	}

	if (num >= 0 && num < capacity)
		return data[num];


	else {
		cout << "배열 참조 오류" << endl;
		exit(0);
	}
	// TODO: 여기에 return 문을 삽입합니다.
}


template<typename T>
const T& ArrayData<T>::operator[](size_t num) const
{
	if (num >= 0 && num < capacity)
		return data[num];

	else {
		cout << "배열 참조 오류" << endl;
		exit(0);
	}
	// TODO: 여기에 return 문을 삽입합니다.
}

template<typename T>
void ArrayData<T>::addElement(const T& num)
{
	//공간 존재 시에는 그 값을 넣어주고 아니면 빈 방이 없다는 것을 알려줌
	if (!full())
		data[used++] = num;
	else
		cout << "빈방이 없음\n";
}

template<typename T>
bool ArrayData<T>::full() const
{
	//용량과 현재 사용 공간 비교한다
	return this->capacity == this->used;
}

//배열 비우기
template<typename T>
void ArrayData<T>::emptyArray()
{
	this->used = 0;
}

template<typename T>
void ArrayData<T>::plusUsed()
{
	this->used += 1;
}

template<typename T>
void ArrayData<T>::showData() const
{
	if (data == nullptr) {
		cout << "내용물이 존재하지 않습니다" << endl;
		return;
	}

	for (size_t i = 0; i < used; i++)
		cout << data[i] << " ";
	cout << endl;
}

template<typename T>
ostream& operator<<(ostream& out, const ArrayData<T>& p) {
	for (int i = 0; i < p.getUsed(); i++) {
		cout << p[i] << "\t";
	}
	cout << endl;
	return out;
}