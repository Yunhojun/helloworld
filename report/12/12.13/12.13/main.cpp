#include "SavingAccount.h"
#include "Account.h"
#include "CheckingAccount.h"
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	SavingAccount AccountA(100.0, 30);
	CheckingAccount AccountB(150.0, 5.0);
	
	vector<Account*>Accounts{
		&AccountA, &AccountB
	};

	cout << fixed << setprecision(2);

	for (Account* AccountPtr : Accounts) {
		CheckingAccount* newPtr = dynamic_cast<CheckingAccount*>(AccountPtr);
		if(newPtr!=nullptr){
			cout << "Balance in Checking Account: " << newPtr->getBalance() << endl;

			cout << "credit 50 to Checking Account" << endl;
			newPtr->credit(50.0);
			cout << "Balance in Checking Account" << newPtr->getBalance() << endl << endl;

			cout << "debit 30 to Checking Account" << endl;
			newPtr->debit(30.0);
			cout << "Balance in Checking Account" << newPtr->getBalance() << endl << endl;

			cout << "debit 200 to Checking Account" << endl;
			newPtr->debit(200.0);
			cout << "Balance in Checking Account" << newPtr->getBalance() << endl << endl;
		}
		else {
			SavingAccount* newPtr = dynamic_cast<SavingAccount*>(AccountPtr);
			cout << "Balance in Saving Account: " << newPtr->getBalance() << endl;

			cout << "credit 50 to Saving Account" << endl;
			newPtr->credit(50.0);
			cout << "Balance in Saving Account" << newPtr->getBalance() << endl << endl;

			cout << "debit 30 to Saving Account" << endl;
			newPtr->debit(30.0);
			cout << "Balance in Saving Account" << newPtr->getBalance() << endl << endl;

			cout << "debit 200 to Saving Account" << endl;
			newPtr->debit(200.0);
			cout << "Balance in Saving Account" << newPtr->getBalance() << endl << endl;

			cout << "Add Interest to Saving Account" << endl;
			newPtr->credit(newPtr->caculateInterest());
			cout << "Balance in Saving Account" << newPtr->getBalance() << endl << endl;
		}
	}
}