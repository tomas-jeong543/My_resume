#pragma once
#include"Gadget.h"
#include<iostream>
#include<vector>

class GadgetManager
{
private:
	static inline std::vector<std::shared_ptr<Gadget>> gadgets;
public:
	static int getInventoryCount();
	void displayAll() const;
};

