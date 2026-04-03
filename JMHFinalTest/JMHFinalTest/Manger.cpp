#include "Manger.h"
#include<iostream>
#include<algorithm>

using namespace std;

void Manger::additem(Clothing* ins)
{
	for (auto it = this->itemList.begin(); it != this->itemList.end(); it++) {
		if (*(*it) == *ins)
			return;
	}

	this->itemList.push_back(ins);

}

Manger::~Manger()
{
	for (auto it = this->itemList.begin(); it != this->itemList.end(); it++) {
		delete* it;
	}

}

void Manger::searchByKeyWord(const string& name)
{
	bool det = true;
	for (auto it = this->itemList.begin(); it != this->itemList.end(); it++) {
		string namecheck = (*it)->getName();

		auto it1 = search(namecheck.begin(), namecheck.end(), name.begin(), name.end());
		if (it1 != namecheck.end()) {
			cout << **it << endl;
			(*it)->PlusView();
		}
			
		
	}
}

bool Manger::cmp(const Clothing* rhs1, const Clothing* rhs2)
{
	return rhs1->getViewTime() > rhs2->getViewTime();
}

vector<Clothing> Manger::getFititemsForClient(const ClientJMH& rhs)
{
	
}

int Manger::getMostFrequentKeyWord()
{
	return 0;
}

void Manger::printMostSearcheditems()
{
	vector<Clothing> listinfo;

	for (auto it = this->itemList.begin(); it != this->itemList.end(); it++) {
		listinfo.emplace_back(**it);
	}

	sort(listinfo.begin(), listinfo.end(), greater<>());

	for_each(listinfo.begin(), listinfo.end(), [](auto i) {cout << i << endl;});
}


