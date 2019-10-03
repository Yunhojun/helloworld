#include "Rational.h"
#include <iostream>
using namespace std;

int main() {
	Rational A(1, 2);
	Rational B(2, 3);

	cout << "Rational A is : " << A << endl;
	cout << "Rational B is : " << B << endl;

	Rational C = A + B;
	cout << "A + B = " << C << endl;
	C = A - B;
	cout << "A - B = " << C << endl;
	C = A * B;
	cout << "A * B = " << C << endl;
	C = A / B;
	cout << "A / B = " << C << endl;

	cout << "A in Double is : " << A.toDouble() << endl;
}