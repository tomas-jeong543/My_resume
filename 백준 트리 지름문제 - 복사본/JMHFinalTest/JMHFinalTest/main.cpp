#include<iostream>
#include"ClientJMH.h"
#include"Shirt.h"
#include"Pants.h"
#include"Manger.h"
using namespace std;

int main()
{
	cout << "202211364 정명훈" << endl;
	ClientJMH greenjoa1("김철수", "M", 175, 70);
	cout << greenjoa1 << endl;

	Clothing* shirt = new Shirt("화이트 셔츠", 29000, "M", "L", 98);
	Clothing* pants = new Pants("청바지", 42000, "M", "XL", 88, 105);
	cout << *shirt << endl;
	cout << *pants << endl;

	Manger manger;
	manger.additem(new Shirt("화이트 셔츠", 29000, "M", "L", 98));
	cout << manger.getSize() << endl;
	manger.additem(new Shirt("화이트 셔츠", 27000, "M", "L", 98));
	cout << manger.getSize() << endl;
	manger.additem(new Shirt("블랙 셔츠", 27000, "M", "L", 98));
	manger.additem(new Pants("청바지", 42000, "M", "XL", 88, 105));
	//둘 다 1로 동일

	manger.searchByKeyWord("셔츠");
	manger.searchByKeyWord("셔츠");
	//검색 횟수 증가 확인용
	
	cout << endl;
	manger.printMostSearcheditems();
}