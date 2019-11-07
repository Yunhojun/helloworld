#include "SavingAccount.h"

SavingAccount::SavingAccount(double initBalance, double intRate):Account(initBalance), interestRate(intRate) {

}

SavingAccount::~SavingAccount() {

}

double SavingAccount::caculateInterest() {
	return getBalance() * (interestRate / 100.0);
}