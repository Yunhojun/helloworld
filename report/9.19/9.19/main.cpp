#include "Date.h"

using namespace std;

int main() {
	Date A(100, 2000);
	cout << A.toString() << endl << endl;

	Date B(4, 10, 2000);
	cout << B.toString() << endl << endl;

	Date C("Aprill", 10, 2000);
	cout << C.toString() << endl << endl;

	Date current_Date;
	cout << current_Date.toString() << endl;
}