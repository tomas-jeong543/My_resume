#pragma once
#include<iostream>
#include<string>

using namespace std;

class Student
{
private:
	int its_age;
	string student_id;
	float grade;
public:
	Student(){
		its_age = 10;
		student_id = "100";
		grade = 3.7f;
	}

	Student(int age, string id, float grade) {
		its_age = age;
		this->student_id = id;
		this->grade = grade;
	}

	void Set_Age(int age) { its_age = age; }
	void Set_Student_id(string id) { student_id = id; }
	void Set_Grade(float x) { grade = x; }
	int Get_Age() { return its_age; }
	string Get_id() { return student_id; }
	float Get_grade() { return grade;  }
	~Student(){}


};