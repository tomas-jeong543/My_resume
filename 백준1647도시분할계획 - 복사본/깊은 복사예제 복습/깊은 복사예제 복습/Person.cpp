#include "Person.h"
Person::Person(Person& person) { // 	복사생성자bid 복사
	this->id = person.id; // id 값 복사
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
	cout << "복사 생성자 실행. 원본 객체의 이름 " << this->name << endl;
	
}
Person::~Person() {// 소멸자
	if (name) // 만일 name에 동적 할당된 배열이 있으면
		delete[] name; // 동적 할당 메모리 소멸
}

void Person::changeName(const char* name) { // 이름 변경
	if (strlen(name) > strlen(this->name))
		return; // 현재 name에 할당된 메모리보다 긴 이름으로 바꿀 수 없다.
	strcpy(this->name, name);
}