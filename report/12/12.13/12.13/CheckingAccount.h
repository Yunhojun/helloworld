#pragma once
#include "Account.h"
class CheckingAccount :public Account
{
public:
	CheckingAccount(double, double);
	virtual ~CheckingAccount();
	void credit(double);
	void debit(double);//�θ�Ŭ������ �Լ��� ȣ���� ��, ���� ������ ���������� ����� �� ��

private:
	double transactionFee;
};