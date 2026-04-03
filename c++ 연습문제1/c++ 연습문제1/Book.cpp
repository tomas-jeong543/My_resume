#include "Book.h"

Book::Book(string nameinfo, int pageinfo)
{
	name = make_unique<string>(nameinfo);
	page = make_unique<int>(pageinfo);

}

void Book::Get_Book_info() const
{
	cout << "책 이름: " << *name << endl;
	cout << "책 페이지 수: " << *page << endl;
}

void Book::Set_page(int pageinfo)
{
	page.reset(new int(pageinfo));
}

void Book::Set_name(string nameinfo)
{
	name.reset(new string(nameinfo));
}


