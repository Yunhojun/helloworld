#include "HugeInteger.h"
using namespace std;

int main() {
	HugeInteger A;
	HugeInteger B;
	
	A.input();
	B.input();

	cout << "\nA + B = ";
	A.add(B);

	cout << "\nA - B = ";
	A.subtract(B);

	cout << "\nis A Equal to B? ";
	if (A.isEqualTo(B) == true) cout << "True" << endl;
	else cout << "False" << endl;

	cout << "is A Not Equal to B? ";
	if (A.isNotEqualTo(B) == true) cout << "True" << endl;
	else cout << "False" << endl;

	cout << "is A Greater than B? ";
	if (A.isGreaterThan(B) == true) cout << "True" << endl;
	else cout << "False" << endl;

	cout << "is A Less than B? ";
	if (A.isLessThan(B) == true) cout << "True" << endl;
	else cout << "False" << endl;

	cout << "is A Greater than or Equal to B? ";
	if (A.isGreaterThanOrEqualTo(B) == true) cout << "True" << endl;
	else cout << "False" << endl;

	cout << "is A Less than or Equal to B? ";
	if (A.isLessThanOrEqualTo(B) == true) cout << "True" << endl;
	else cout << "False" << endl;

	cout << "is A Zero? ";
	if (A.isZero() == true) cout << "True" << endl;
	else cout << "False" << endl;
}