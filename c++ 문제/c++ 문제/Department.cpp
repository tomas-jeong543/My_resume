#include "Department.h"
#include "Department.h"
#include <iostream>
using namespace std;

Department::Department(const std::string& name)
    : name(name) {
}

const std::string& Department::getName() const {
    return name;
}

void Department::addEmployee(std::unique_ptr<Employee> employee) {
    employee->setDepartment(this);
    employees.push_back(std::move(employee));
}

void Department::removeEmployee(int id) {
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if ((*it)->getId() == id) {
            employees.erase(it);
            cout << "Employee with ID " << id << " removed!" << endl;
            return;
        }
    }
    cout << "Employee with ID " << id << " not found!" << endl;
}

void Department::displayAllEmployees() const {
    cout << "Department: " << name << endl;
    for (const auto& employee : employees) {
        employee->displayInfo();
    }
}
