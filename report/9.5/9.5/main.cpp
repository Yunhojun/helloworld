#include "Q_Equations.h"
#include <iostream>
using namespace std;

int main() {
	Q_Equations Fa(1, 2, 1);
	Q_Equations Fb(2, 4, 2);

	cout << "The Fa is: " << endl;
	cout << Fa.toString() << endl;

	cout << "\nThe Fb is: " << endl;
	cout << Fb.toString() << endl;

	cout << "\nFa + Fb = ";
	Fa.add(Fb);
	cout << Fa.toString() << endl;

	Fa.subtract(Fb);

	cout << "\nFb - Fa = ";
	Fb.subtract(Fa);
	cout << Fb.toString() << endl;

	cout << "\nThe solution of Fa is: ";
	Fa.solve();
}