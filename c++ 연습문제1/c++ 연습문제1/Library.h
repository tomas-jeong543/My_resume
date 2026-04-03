
#include"Book.h"

using namespace std;

class Library
{
private:
	unique_ptr<Book[]> booklist;
	int size;
	int capcity;
public:

	Library() :Library(10)
	{};

	Library(int capcity, int size = -1):capcity(capcity), size(size)
	{
		booklist = make_unique<Book[]>(capcity);
	};
	~Library() {};

	void addBook(const string& name, int pages);
	void printBooks() const;

	bool isfull() {
		return size == capcity - 1;
	}
};



