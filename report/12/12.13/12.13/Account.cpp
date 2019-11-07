#include "Account.h"

Account::Account(double initBalance) {
	if (initBalance >= 0.0) {
		balance = initBalance;
	}
	else {
		balance = 0.0;
	}
}

Account::~Account() {

}

void Account::credit(double amount) {
	balance += amount;
}

void Account::debit(double amount) {
	if (getBalance() < amount) {
		std::cout << "Debit amount exceeded account balabce." << std::endl;
	}
	else {
		balance -= amount;
	}
}

double Account::getBalance()const {
	return balance;
}