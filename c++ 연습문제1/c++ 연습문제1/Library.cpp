
#include"Library.h"

void Library::addBook(const string& name, int pages)
{
	/*if (isfull()) {
		capcity *= 2;

		unique_ptr<Book[]> new_booklist = make_unique<Book[]>(capcity);

		for (int i = 0; i < size + 1; i++) {
			string insname = booklist[i].Get_name();
			int inspage = booklist[i].Get_page();
			new_booklist[i].Set_name(insname);
			new_booklist[i].Set_page(inspage);
		}

		booklist = move(new_booklist);
		;
	}*/

	if (isfull()) {
		// 용량을 2배로 증가
		capcity *= 2;
		unique_ptr<Book[]> new_booklist = make_unique<Book[]>(capcity);

		// 복사 생성자를 이용하여 도서 복사
		for (int i = 0; i < size + 1; i++) {
			new_booklist[i] = booklist[i];
		}

		// 새로운 배열로 소유권 이동
		booklist = move(new_booklist);
	}



	size += 1;
	booklist[size].Set_name(name);
	booklist[size].Set_page(pages);
	
}

void Library::printBooks() const
{
	if (size < 0) {
		cout << "도서관에 책이 존재하지 않습니다" << endl;
		return;
	}

	for (int i = 0; i <= size; i++) {
		 booklist[i].Get_Book_info();
	}

}
