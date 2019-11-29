#pragma once
#include <string>
using namespace std;

class ClientData
{
public:
	ClientData(int = 0, const std::string& ="", const std::string& = "", double = 0.0);
	~ClientData();

	void setAccountNumber(int);
	int getAccountNumber()const;

	void setLastName(const std::string&);
	std::string getLastName()const;

	void setFirstName(const std::string&);
	std::string getFirstName()const;

	void setBalance(double);
	double getBalance()const;

private:
	int accountNumber;
	char lastName[10];
	char firstName[15];
	double balance;
};