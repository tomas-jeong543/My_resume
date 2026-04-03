#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
class Department; // 전방 선언

class Employee {
private:
    std::string name;
    int id;
    int age;
    Department* department;

public:
    Employee(const std::string& name, int id, int age);
    ~Employee();
    void displayInfo() const;
    void setDepartment(Department* dept);
    int getId() const;
    int getAge() const;
};

#endif



