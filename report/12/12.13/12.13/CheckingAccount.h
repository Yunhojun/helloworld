#pragma once
#include "Account.h"
class CheckingAccount :public Account
{
public:
	CheckingAccount(double, double);
	virtual ~CheckingAccount();
	void credit(double);
	void debit(double);//부모클래스의 함수를 호출할 것, 돈이 실제로 빠질때에만 요금을 뺄 것

private:
	double transactionFee;
};