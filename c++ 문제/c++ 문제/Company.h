#ifndef COMPANY_H
#define COMPANY_H

#include <map>
#include <string>
#include <memory>
#include "Department.h"

class Company {
private:
    std::map<std::string, std::unique_ptr<Department>> departments;

public:
    void addDepartment(const std::string& deptName);
    void addEmployeeToDepartment(const std::string& deptName, std::unique_ptr<Employee> employee);
    void removeDepartment(const std::string& deptName);
    void searchEmployeeById(int id) const;
    double calculateAverageAge() const;
};

#endif


