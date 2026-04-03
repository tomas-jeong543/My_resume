#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>
#include <memory>
#include "Employee.h"

class Department {
private:
    std::string name;
    std::vector<std::unique_ptr<Employee>> employees;

public:
    Department(const std::string& name);
    const std::string& getName() const;
    void addEmployee(std::unique_ptr<Employee> employee);
    void removeEmployee(int id);
    void displayAllEmployees() const;
};

#endif

