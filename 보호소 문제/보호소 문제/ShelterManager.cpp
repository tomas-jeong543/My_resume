#include "ShelterManager.h"
#include <iostream>
#include"Shelter.h"

void ShelterManager::addShelter(const std::string& shelterName, int capacity) {
    shelters[shelterName] = std::make_unique<Shelter>(shelterName, capacity);
}

void ShelterManager::addAnimalToShelter(const std::string& shelterName, std::unique_ptr<Animal> animal) {
    auto it = shelters.find(shelterName);
    if (it != shelters.end()) {
        it->second->addAnimal(std::move(animal));
    }
    else {
        std::cout << "Shelter not found: " << shelterName << std::endl;
    }
}

void ShelterManager::removeShelter(const std::string& shelterName) {
    auto it = shelters.find(shelterName);
    if (it != shelters.end()) {
        shelters.erase(it);
        std::cout << "Shelter " << shelterName << " removed!" << std::endl;
    }
    else {
        std::cout << "Shelter not found: " << shelterName << std::endl;
    }
}

void ShelterManager::searchAnimal(const std::string& name) const {
    for (const auto& [name, shelter] : shelters) {
        shelter->displayAnimals(); // 이름 검색 구현 필요
    }
}
