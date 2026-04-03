
#include<iostream>
#include<string>
#include<memory>



using namespace std;

class Book
{
private:
	unique_ptr<int> page;
	unique_ptr<string> name;
public:
	Book() :Book("undefind", 0){}
	Book(string nameinfo, int pageinfo);
	~Book() {};
	Book(const Book& ins)
	{
		page = make_unique<int>(*ins.page);
		name = make_unique<string>(*ins.name);
	}
	Book(Book&& ins)noexcept
	{
		page = std::move(ins.page);
		name = std::move(ins.name);
	}

	Book& operator=(Book& ins) noexcept {
		if (this != &ins) { // 자기 자신과의 대입 방지
			page = std::move(ins.page);
			name = std::move(ins.name);
		}
		return *this;
	}

	//임시 객체의 경우
	Book& operator=(Book&& ins) noexcept {
		if (this != &ins) { // 자기 자신과의 대입 방지
			page = std::move(ins.page);
			name = std::move(ins.name);
		}
		return *this;
	}


	void Get_Book_info() const;

	int Get_page()const { return *page; }
	string Get_name()const { return *name; }

	void Set_page(int pageinfo);
	void Set_name(string nameinfo);
};

