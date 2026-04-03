#include "Shirt.h"

Shirt::Shirt(const string name, const int price, const string gen, const string size, const int chest):Clothing(name, price, gen, size),chestLen(chest)
{
}

ostream& operator<<(ostream& out, const Shirt& rhs)
{
	out << "이름: " << rhs.name << ", 가격: " << rhs.price << ", 성별: " << rhs.gender << ", 사이즈: " << rhs.size << ", 가슴둘레: " << rhs.chestLen <<
		", 검색횟수:" << rhs.viewTime;
	return out;
}
