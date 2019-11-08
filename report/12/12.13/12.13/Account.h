#pragma once
#include <iostream>

class Account
{
public:
	Account(double = 0.0);
	virtual ~Account();
	void credit(double);
	void debit(double);
	double getBalance()const;

private:
	double balance;
};


/*
saving, check ��ī��Ʈ�� ��ī��Ʈ�� ���
account: �뷱�� �������, �����ڰ� �ʱ� �뷱���� �����ϰ� 0���� ũ�ų� ������ �븮���̼�/0���� �۴ٸ� ���������� 0����
	credit�Լ�: ���� �뷱���� ���Ʈ�� ����
	debit �Լ�: ���Ʈ�� ����/�뷱������ ���� ������ "Debit amount exceeded account balabce."
	getBalance�Լ�: �뷱�� ����
*/