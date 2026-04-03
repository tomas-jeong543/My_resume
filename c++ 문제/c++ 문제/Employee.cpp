#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(const std::string& name, int id, int age)
    : name(name), id(id), age(age), department(nullptr) {
}

Employee::~Employee() {}

void Employee::displayInfo() const {
    cout << "Employee ID: " << id << ", Name: " << name
        << ", Age: " << age;
    if (department) {
        cout << ", Department: (linked)";
    }
    cout << endl;
}

void Employee::setDepartment(Department* dept) {
    department = dept;
}

int Employee::getId() const {
    return id;
}

int Employee::getAge() const {
    return age;
}

