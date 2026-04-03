#include "BankAccount.h"

void BankAccount::deposit(double amount)
{
	if (amount < 0.0) {
		cerr << "입금 금액은 양수여야 합니다" << endl;
		return;
	}
	this->balance += amount;
}

void BankAccount::withdraw(double amount)
{
	if (amount < 0.0) {
		cerr << "출금 금액은 양수여야 합니다" << endl;
		return;
	}

	if (amount > balance) {
		cerr << "출금하려는 돈이 계좌에 있는 금액보다 많습니다" << endl;
	}
	this->balance -= amount;
}

void BankAccount::displayAccount()
{
	cout << "계좌 정보" << endl;
	cout << "이름" << this->ownerName << endl << "계좌번호" << this->accountNumber << endl <<  "잔액 정보" << this->balance << endl;
}
