#pragma once
#include "Account.h"
class SavingAccount : public Account
{
public:
	SavingAccount(double, double);
	virtual ~SavingAccount();
	double caculateInterest();

private:
	double interestRate;
};
//