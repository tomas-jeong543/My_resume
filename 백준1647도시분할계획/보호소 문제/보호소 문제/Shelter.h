#ifndef SHELTER_H
#define SHELTER_H

#include <string>
#include <vector>
#include <memory>
#include "Animal.h"

class Shelter {
private:
    std::string name;
    std::vector<std::unique_ptr<Animal>> animals;
    int capacity;

public:
    // 기본 생성자
    Shelter(const std::string& name, int capacity);

    // 🔹 복사 생성자 구현 필요
    Shelter(const Shelter& other);

    // 🔹 대입 연산자 구현 필요
    Shelter& operator=(const Shelter& other);

    // 소멸자
    ~Shelter();

    // 동물 추가
    void addAnimal(std::unique_ptr<Animal> animal);

    // 보호소 정보 출력
    void displayAnimals() const;
};

#endif

