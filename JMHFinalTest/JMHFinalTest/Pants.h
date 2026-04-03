#pragma once
#include "Clothing.h"
class Pants :
    public Clothing
{
protected:
    int waistLen;
    int gijang;
public:
    Pants(const string name, const int price, const string gen, const string size, const int waist, const int gijang);
    friend ostream& operator<<(ostream& out, const Pants& rhs);
};

ostream& operator<<(ostream& out, const Pants& rhs);