#include "Animal.h"
#include "Shelter.h"
#include <iostream>

Animal::Animal(const std::string& name, const std::string& type, int age)
    : name(name), type(type), age(age), shelter(nullptr) {
}

Animal::~Animal() {}

void Animal::displayInfo() const {
    std::cout << "Name: " << name << ", Type: " << type
        << ", Age: " << age;
    if (shelter) {
        std::cout << ", Shelter: " << shelter->getName();
    }
    std::cout << std::endl;
}

void Animal::setShelter(Shelter* shelter) {
    this->shelter = shelter;
}

const std::string& Animal::getName() const {
    return name;
}

