#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
class Shelter; // 傈规 急攫

class Animal {
private:
    std::string name;
    std::string type;
    int age;
    Shelter* shelter; // 家加等 焊龋家

public:
    Animal(const std::string& name, const std::string& type, int age);
    ~Animal();
    void displayInfo() const;
    void setShelter(Shelter* shelter);
    const std::string& getName() const;
};

#endif

