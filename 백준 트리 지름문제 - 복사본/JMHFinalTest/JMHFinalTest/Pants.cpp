#include "Pants.h"

Pants::Pants(const string name, const int price, const string gen, const string size, const int waist, const int gijang):Clothing(name,price,gen,size),waistLen(waist),gijang(gijang)
{
}

ostream& operator<<(ostream& out, const Pants& rhs)
{
	
	out << "이름: " << rhs.name << ", 가격: " << rhs.price << ", 성별: " << rhs.gender << ", 사이즈: " << rhs.size << ", 허리둘레: " << rhs.waistLen << ", 기장: " << rhs.gijang << 
		", 검색횟수:" << rhs.viewTime;
	return out;
}
