#include "Shelter.h"
#include <iostream>
#include<memory>

using namespace std;

Shelter::Shelter(const std::string& name, int capacity)
    : name(name), capacity(capacity) {
}

// 🔹 복사 생성자 구현
Shelter::Shelter(const Shelter& other) {
    // TODO: name, capacity 복사
    this->name = other.name;
    this->capacity = other.capacity;

    // TODO: 동물 목록 깊은 복사

}

// 🔹 대입 연산자 구현
Shelter& Shelter::operator=(const Shelter& other) {
    if (this != &other) { // 자기 자신 대입 방지
        // TODO: 기존 동물 목록 삭제
        
        for (int i = 0; i < animals.size(); i++) {
             animals[i] = nullptr;
        }

        // TODO: 새 동물 목록 깊은 복사
    }
    return *this;
}

// 🔹 소멸자 구현
Shelter::~Shelter() {
    // TODO: 동물 목록 메모리 정리
}

