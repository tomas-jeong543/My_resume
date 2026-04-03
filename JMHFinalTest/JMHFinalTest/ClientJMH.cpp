#include "ClientJMH.h"
#include<iostream>

using namespace std;
ClientJMH::ClientJMH(const string name, const string gender, const int h, const int w):name(name), gender(gender),height(h),weight(w)
{
}

ostream& operator<<(ostream& out, const ClientJMH& rhs)
{
	out << "이름: " << rhs.name << ", 성별: " << rhs.gender << ", 키: " << rhs.height << ", 몸무게: " << rhs.weight << "kg" ;

	return out;
}
