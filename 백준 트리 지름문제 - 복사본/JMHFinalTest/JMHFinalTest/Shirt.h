#pragma once
#include "Clothing.h"
class Shirt :
    public Clothing
{
protected:
    int chestLen;
public:
    Shirt(const string name, const int price, const string gen, const string size, const int chest);
    friend ostream& operator<<(ostream& out, const Shirt& rhs);
};

ostream& operator<<(ostream& out, const Shirt& rhs);