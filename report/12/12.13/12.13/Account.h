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
saving, check 어카운트가 어카운트를 상속
account: 밸런스 멤버변수, 생성자가 초기 밸런스를 설정하고 0보다 크거나 같도록 밸리데이션/0보다 작다면 에러를띄우고 0으로
	credit함수: 현재 밸런스에 어마운트를 더함
	debit 함수: 어마운트를 빼냄/밸런스보다 많이 빼내명 "Debit amount exceeded account balabce."
	getBalance함수: 밸런스 리턴
*/