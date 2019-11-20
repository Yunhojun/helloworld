#include "ClientData.h"
using namespace std;

ClientData::ClientData(int AccNum, const string& lastName, const string& firstName, double b)
	:accountNumber(AccNum), balance(b) {
	setLastName(lastName);
	setFirstName(firstName);
}

ClientData::~ClientData() {
	;
}

void ClientData::setAccountNumber(int AccNum) {
	accountNumber = AccNum;
}

int ClientData::getAccountNumber() const{
	return accountNumber;
}

void ClientData::setLastName(const string& LN) {
	unsigned int len = LN.length();
	if (len > 15) {
		len = 14;
	}
	LN.copy(lastName, len);
	lastName[len] = '\0';
}

string ClientData::getLastName()const {
	return lastName;
}

void ClientData::setFirstName(const string& FN) {
	unsigned int len = FN.length();
	if (len > 10) {
		len = 9;
	}
	FN.copy(firstName, len);
	firstName[len] = '\0';
}

string ClientData::getFirstName()const {
	return firstName;
}

double ClientData::getBalance()const {
	return balance;
}

void ClientData::setBalance(double b) {
	balance = b;
}