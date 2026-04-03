#pragma once
#include<iostream>

using namespace std;
class Gadget
{
private:
	string name;
	int id;
	static inline int nextId = 0;
	static inline int liveCount = 0;
public:
	Gadget(const string name) :name(name) {
		id = nextId; nextId += 1; liveCount
			+= 1;
	}
	Gadget(Gadget& ins):Gadget(ins.name)
	{
		cout << "Gadget copied" << ins.name << "id:" << nextId << endl;
	}

	Gadget(Gadget&& ins) noexcept:Gadget(move(ins.name))
	{
		cout << "Gadget moved" << ins.name << "id:" << nextId << endl;
		ins.name = "";
		ins.id = -1;
	}
	~Gadget() {
		cout << "Gadget removed" << this->name << "id:" << this->id << endl;
		liveCount -= 1;
	}
	void display() const {
		cout << "Gadget info name:" << this->name << "id:" << this->id << endl;
	}
};

