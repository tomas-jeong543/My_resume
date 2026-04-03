#pragma once
#include<iostream>
#include<string>

using namespace std;
class BankAccount
{
private:
	string ownerName;
	int accountNumber;
	double balance;
public:
	//생성자 부분
	BankAccount():ownerName("unknoen"), accountNumber(0), balance(0.0)
	{}
	BankAccount(string name, int num, double balance):ownerName(name), accountNumber(num), balance(balance)
	{}
	//복사 생성자
	BankAccount(BankAccount& ins) {
		this->accountNumber = ins.accountNumber;
		this->balance = ins.balance;
		this->ownerName = ins.ownerName;
	}

	//소멸자
	~BankAccount()
	{
		cout << "이름" << this->ownerName << "계좌번호" << this->accountNumber << "잔액 정보" << this->balance << endl;
	}

	//함수들
	void deposit(double amount);
	void withdraw(double amount);
	void displayAccount();
};

