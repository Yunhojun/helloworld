#include "ClientData.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void outputLine(ostream& cout, const ClientData client);
int main() {
	ifstream inCredit("credit.txt", ios::in | ios::out | ios::binary);

	if (!inCredit) {
		cerr << "File could not be opened!" << endl;
		exit(EXIT_FAILURE);
	}

	cout << left << setw(10) << "Account" << setw(16) << "Last Name" << setw(11) << "First Name"
		<< setw(10) << right << "Balance" << endl;

	ClientData client;

	inCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

	while (inCredit) {
		{
			if (client.getAccountNumber() != 0) {
				outputLine(cout, client);
			}
			inCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
		}
	}
}

void outputLine(ostream& cout, const ClientData client) {
	cout << left << setw(10) << client.getAccountNumber() << setw(16) << client.getLastName() << setw(11) << client.getFirstName()
		<< setw(10) << setprecision(2) <<  right << fixed << client.getBalance() << endl;
}
