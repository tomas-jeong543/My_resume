#include "Clothing.h"
#include"Pants.h"
#include"Shirt.h"
#include<iostream>

using namespace std;
Clothing::Clothing(const string name, const int price, const string gen, const string size):name(name),price(price),gender(gen),size(size)
{
}

bool Clothing::operator==(const Clothing& rhs)const
{
	return this->name == rhs.name && this->gender.compare(rhs.gender) == 0;
}

bool Clothing::operator>( Clothing& rhs) const
{
	return this->viewTime > rhs.viewTime;
}


ostream& operator<<(ostream& out, const Clothing& rhs)
{

	out << "이름: " << rhs.name << ", 가격: " << rhs.price << ", 성별: " << rhs.gender << ", 사이즈: " << rhs.size << ",검색 횟수: " << rhs.viewTime;
	return out;
}
