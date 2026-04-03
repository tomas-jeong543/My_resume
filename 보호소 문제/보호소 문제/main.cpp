#include "Shelter.h"
#include <iostream>

using namespace std;

int main() {
    Shelter original("Happy Shelter", 5);
    original.addAnimal(std::make_unique<Animal>("Charlie", "Dog", 4));
    original.addAnimal(std::make_unique<Animal>("Luna", "Cat", 2));

    // 🔹 복사 생성자 테스트
    Shelter copyShelter = original;

    // 🔹 대입 연산자 테스트
    Shelter anotherShelter("Safe Haven", 3);
    anotherShelter = original;

    // 결과 출력
    std::cout << "=== Original Shelter ===" << std::endl;
    original.displayAnimals();

    std::cout << "=== Copied Shelter ===" << std::endl;
    copyShelter.displayAnimals();

    std::cout << "=== Assigned Shelter ===" << std::endl;
    anotherShelter.displayAnimals();

    return 0;
}
