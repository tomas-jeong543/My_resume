#include "Company.h"
#include <iostream>

using namespace std;

void Company::addDepartment(const std::string& deptName) {
    departments[deptName] = std::make_unique<Department>(deptName);
}

void Company::addEmployeeToDepartment(const std::string& deptName, std::unique_ptr<Employee> employee) {
    auto it = departments.find(deptName);
    if (it != departments.end()) {
        it->second->addEmployee(std::move(employee));
    }
    else {
        cout << "Department not found: " << deptName << endl;
    }
}

void Company::removeDepartment(const std::string& deptName) {
    auto it = departments.find(deptName);
    if (it != departments.end()) {
        departments.erase(it);
        cout << "Department " << deptName << " removed!" << endl;
    }
    else {
        cout << "Department not found: " << deptName << endl;
    }
}

void Company::searchEmployeeById(int id) const {
    for (const auto& [name, department] : departments) {
        department->displayAllEmployees(); // 여기서 ID를 확인하도록 구현 필요
    }
}

double Company::calculateAverageAge() const {
    int totalAge = 0;
    int totalEmployees = 0;

    for (const auto& [name, department] : departments) {
        for (const auto& employee : department->displayAllEmployees()) {
            totalAge += employee->getAge();
            totalEmployees++;
        }
    }

    return totalEmployees > 0 ? (double)totalAge / totalEmployees : 0.0;
}
