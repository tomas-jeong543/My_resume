#include "ArrayData.h"
#include <iostream>
using namespace std;
//기본 생성자 방 3개 생성
ArrayData::ArrayData() :ArrayData(3){}

ArrayData::ArrayData(const int& capacity, const int& used) :capacity(capacity), used(used)
{
	cout << "생성자" << endl;
	//공간 만큼 할당
	//data = new double[this->capacity];
	//data = make_unique<double[]>(this->capacity);
	data = shared_ptr<double[]>(new double[this->capacity]);
}
//소멸자
ArrayData::~ArrayData()
{
	cout << "소멸자 호출" << endl;
	/*if (data != nullptr)
		delete[] data;
	data = nullptr;*/
}

ArrayData& ArrayData::operator=(const ArrayData& rhs)
{
	if (this == &rhs) {
		return *this;
	}
	this->capacity = rhs.capacity;
	this->used = rhs.used;
	data.reset(new double[capacity]);
	//data = static_cast<shared_ptr<double[]>>(new double[capacity]);
	for (size_t i = 0; i < used; i++) {
		data[i] = rhs.data[i];
	}
	return *this;
}

ArrayData& ArrayData::operator=(ArrayData&& rhs) noexcept
{
	this->capacity = rhs.capacity;
	this->used = rhs.used;
	data = move(rhs.data);
	return *this;
	// TODO: 여기에 return 문을 삽입합니다.
}

double& ArrayData::operator[](size_t num)
{
	//이전 요소가 정의가 되있지 않으면 접근 불가 오류 발생
	if (num > (this->used) ) {
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

const double& ArrayData::operator[](size_t num) const
{
	if (num >= 0 && num < capacity)
		return data[num];
	
	else {
		cout << "배열 참조 오류" << endl;
		exit(0);
	}
	// TODO: 여기에 return 문을 삽입합니다.
}


void ArrayData::addElement(const double& num)
{
	//공간 존재 시에는 그 값을 넣어주고 아니면 빈 방이 없다는 것을 알려줌
	if (!full())
		data[used++] = num;
	else
		cout << "빈방이 없음\n";
}

bool ArrayData::full() const
{
	//용량과 현재 사용 공간 비교한다
	return this->capacity == this->used;
}

//배열 비우기
void ArrayData::emptyArray()
{
	this->used = 0;
}

void ArrayData::plusUsed()
{
	this->used += 1;
}

void ArrayData::showData() const
{
	if (data == nullptr) {
		cout << "내용물이 존재하지 않습니다" << endl;
		return;
	}

	for (size_t i = 0; i < used; i++)
		cout << data[i] << " ";
	cout << endl;
}