#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Clothing.h"
#include"ClientJMH.h"
using std::vector;
using std::string;

class Manger
{
protected:
	vector<Clothing*> itemList;
public:
	void additem(Clothing* ins);
	Manger() = default;
	~Manger();
	int getSize() { return itemList.size(); }
	void searchByKeyWord(const string& name);
	void printMostSearcheditems();
	bool cmp(const Clothing* rhs1, const Clothing* rhs2);
	vector<Clothing> getFititemsForClient(const ClientJMH& rhs);
	int getMostFrequentKeyWord();
};

