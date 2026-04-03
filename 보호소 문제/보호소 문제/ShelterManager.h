#ifndef SHELTERMANAGER_H
#define SHELTERMANAGER_H

#include <map>
#include <string>
#include <memory>
#include "Shelter.h"

class ShelterManager {
private:
    std::map<std::string, std::unique_ptr<Shelter>> shelters;

public:
    void addShelter(const std::string& shelterName, int capacity);
    void addAnimalToShelter(const std::string& shelterName, std::unique_ptr<Animal> animal);
    void removeShelter(const std::string& shelterName);
    void searchAnimal(const std::string& name) const;
};

#endif
