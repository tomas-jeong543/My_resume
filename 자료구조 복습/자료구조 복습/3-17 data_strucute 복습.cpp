#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//구조체는 선언될 때 크기는 늘 가장 구조체 내의 가장 큰 데이터 * n꼴로 형성되며 위치 배열에 따라서 사이즈가 달라질 수 있음으로 이에 유의해야 한다
struct Student {
    char name[20];
    int age;
    double grade;
};


// 이 둘의 사이즈는 다르다
struct efficent
{

    int age;
    char gender;
    short grade;
}typedef EF;


struct un_efficent
{
    char a;
    int b;
    short c;
   
   
}typedef UN_EF;


void Check_Sizw_Struct()
{
    //명시적인 기본 자료형 변환시에는 static_cast<자료형>을 이용한다
    printf("EF: %d Un-EF: %d\n", static_cast<int>(sizeof(EF)), static_cast<int>(sizeof(UN_EF)));
}


int main() {

    //구조체 선언 순서에 따른 크기 차이 비교를 하기 위한 함수
    Check_Sizw_Struct();

    /////////////////////////////////////////////////////////////////////////////////
    // How to access members
    //정적 구조체
    struct Student s1 = { "Salah", 32, 3.8 }; // Declare and initialize struct variable

    // Access members using the dot operator
    printf("Name: %s\n", s1.name);
    printf("Age: %d\n", s1.age);
    printf("Grade: %.2f\n", s1.grade);
    printf("\n");
    printf("\n");

    // Allocate memory dynamically
    struct Student* s2 = (struct Student*)malloc(sizeof(struct Student));

    if (s2 == NULL) {
        printf("s2 메모리 동적 할당 중 오류 발생");
        return 1;
    }

    // Assign values using the arrow operator
    //문자열은 strcpy함수를 이용해 접근해야 함 또한 포인터로 객체를 가르키는 경우에는 ->을 이용해 맴버 변수에 접근해야 한다 이는
    // (*s2). 과 동일한 접근이다
    strcpy_s(s2->name, "Virgil");
    s2->age = 33;
    s2->grade = 4.5;

    // Access members using the arrow operator
    printf("Name: %s\n", s2->name);
    printf("Age: %d\n", s2->age);
    printf("Grade: %.2f\n", s2->grade);

    printf("\n");
    printf("\n");

    // Access members using the dot operator 2
    printf("* Name: %s\n", (*s2).name);
    printf("* Age: %d\n", (*s2).age);
    printf("* Grade: %.2f\n", (*s2).grade);

    printf("\n");
    printf("\n");

    // Free allocated memory 매우 중요 늘 메모리를 할당해제 해야 한다
    free(s2);

    /////////////////////////////////////////////////////////////////////////////////
    // Structure array

    // Static memory allocation 정적인 배열 선언
    struct Student students_static[3] = {
        {"Alice", 20, 3.8},
        {"Bob", 22, 3.5},
        {"Charlie", 21, 3.9}
    };

    // Print static allocation
    printf("Static Memory Allocation:\n");
    for (int i = 0; i < 3; i++) {
        printf("Student %d: Name = %s, Age = %d, Grade = %.2f\n",
            i + 1, students_static[i].name, students_static[i].age, students_static[i].grade);
    }

    // Dynamic memory allocation
    int n = 3;
    //동적 메모리 할당 calloc으로 할당했다
    struct Student* students_dynamic = (struct Student*)calloc(n, sizeof(struct Student));

    if (students_dynamic == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    //내용 접근 및 내용 초기화
    int i = 0;
    strcpy_s(students_dynamic[i].name, "Alice");
    students_dynamic[i].age = 20;
    students_dynamic[i].grade = 3.8;

    i = 1;
    strcpy_s(students_dynamic[i].name, "Bob");
    students_dynamic[i].age = 22;
    students_dynamic[i].grade = 3.5;

    i = 2;
    strcpy_s(students_dynamic[i].name, "Charlie");
    students_dynamic[i].age = 21;
    students_dynamic[i].grade = 3.9;

    // Print dynamic allocation
    printf("\nDynamic Memory Allocation:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: Name = %s, Age = %d, Grade = %.2f\n",
            i + 1, students_dynamic[i].name, students_dynamic[i].age, students_dynamic[i].grade);
    }

    free(students_dynamic);
    return 0;
}
