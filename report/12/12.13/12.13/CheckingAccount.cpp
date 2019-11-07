#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(double initBalance, double tF) :transactionFee(tF), Account(initBalance) {

}

CheckingAccount::~CheckingAccount() {

}

void CheckingAccount::credit(double amount) {
	Account::credit(amount - transactionFee);
}

void CheckingAccount::debit(double amount) {
	double x = getBalance();
	Account::debit(amount);
	double y = getBalance();
	if (x > y) {
		Account::debit(transactionFee);
	}
}