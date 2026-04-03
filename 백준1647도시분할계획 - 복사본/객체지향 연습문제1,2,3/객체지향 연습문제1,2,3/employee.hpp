#include<iostream>
class Employee
{
private:
	int Age, Years_Of_Service, Salary;

public:
	Employee(int age, int year, int salary);
	~Employee() {};
	int Get_Age() const { return Age; }
	int Get_Years_Of_Service() const { return Years_Of_Service; }
	int Get_Salary() const { return Salary; }

	void Set_Age(int age)  { Age = age; }
	void Set_years_Of_Service(int years_of_service) { Years_Of_Service = years_of_service; }
	void Set_Salary(int salary) { Salary = salary; }
};

int main()
{	
	using namespace std;
	Employee a(25,1,2856), b(30,6,4302);

	cout << "A info " << endl;
	cout << "age: " << a.Get_Age() << "years of service: " << a.Get_Years_Of_Service() << "salary: " << (a.Get_Salary() / 1000) * 1000;
	cout << "\n";

	cout << "B info" << endl;
	cout << "age: " << b.Get_Age() << "years of service: " << b.Get_Years_Of_Service() << "salary: " << (b.Get_Salary() / 1000) * 1000;

	return 0;
}
