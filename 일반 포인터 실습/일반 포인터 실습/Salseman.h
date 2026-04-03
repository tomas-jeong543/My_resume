#pragma once
#include<string>

using namespace std;

class Salseman
{
private:
	string name;
	double sales;

public:
	static inline int counter = 0;
	Salseman() = default;
	explicit Salseman(const Salseman & man);
	explicit Salseman(const string& name);
	Salseman(const string& name, const double& sales);
	
	void setName(const string& name);
	void readinput();
	
	string get_Salesman_Info();
	double getSales() const;
	string getName() {
		return this->name;
	}
	string getName() const{
		return this->name;
	}
	friend void show(const Salseman& man);

	//클래스를 만드는 방법
	static Salseman & Get_instance()
	{
		Salseman* ins = new Salseman;
		return *ins;
	}

};

//클래스 밖에서 초기화는 곤란하다
//int Salseman:: counter = 0;
