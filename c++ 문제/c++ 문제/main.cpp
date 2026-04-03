#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

// Student 클래스 정의
class Student {
private:
    char* name; // 동적 메모리로 관리되는 이름
    int id;
    int age;

public:
    // 생성자
    Student(const char* name, int id, int age) {
        this->id = id;
        this->age = age;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // 복사 생성자
    Student(const Student& other) {
        this->id = other.id;
        this->age = other.age;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }

    // 소멸자
    ~Student() {
        delete[] name;
    }

    // 학생 정보 출력
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age << endl;
    }

    // 학번 반환
    int getId() const {
        return id;
    }
};

// StudentManager 클래스 정의
class StudentManager {
private:
    Student** students; // 학생 객체 배열
    int size;           // 현재 학생 수
    int capacity;       // 배열의 최대 크기

public:
    // 생성자
    StudentManager(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->students = new Student * [capacity];
    }

    // 소멸자
    ~StudentManager() {
        for (int i = 0; i < size; ++i) {
            delete students[i]; // 각 학생 메모리 해제
        }
        delete[] students; // 배열 메모리 해제
    }

    // 학생 추가
    void addStudent(const Student& student) {
        if (size >= capacity) {
            cout << "Capacity full, cannot add student!" << endl;
            return;
        }
        students[size++] = new Student(student); // 복사 생성자를 활용한 깊은 복사
    }

    // 학생 삭제
    void removeStudent(int id) {
        for (int i = 0; i < size; ++i) {
            if (students[i]->getId() == id) {
                delete students[i]; // 메모리 해제
                for (int j = i; j < size - 1; ++j) {
                    students[j] = students[j + 1];
                }
                --size;
                cout << "Student with ID " << id << " removed!" << endl;
                return;
            }
        }
        cout << "Student with ID " << id << " not found!" << endl;
    }

    // 전체 학생 출력
    void printAllStudents() const {
        for (int i = 0; i < size; ++i) {
            students[i]->display();
        }
    }

    // 특정 학생 검색
    void findStudent(int id) const {
        for (int i = 0; i < size; ++i) {
            if (students[i]->getId() == id) {
                cout << "Student found: ";
                students[i]->display();
                return;
            }
        }
        cout << "Student with ID " << id << " not found!" << endl;
    }
};

int main() {
    StudentManager manager(10); // 최대 10명의 학생 저장 가능

    // 학생 추가
    manager.addStudent(Student("Alice", 1, 20));
    manager.addStudent(Student("Bob", 2, 22));
    manager.addStudent(Student("Charlie", 3, 19));

    // 전체 학생 출력
    cout << "All students:" << endl;
    manager.printAllStudents();

    // 특정 학생 검색
    manager.findStudent(2);

    // 학생 삭제
    manager.removeStudent(1);

    // 삭제 후 학생 목록 출력
    cout << "After removal:" << endl;
    manager.printAllStudents();

    return 0;
}
