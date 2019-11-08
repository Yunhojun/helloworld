#include "Pakage.h"
#include "TwoDayPakage.h"
#include "OvernightPakage.h"
#include <iostream>
using namespace std;

int main() {
	Pakage A("A", "1111", "cityA", "stateA", "AAAAA", "BBBBB", 100, 10);
	cout << A.calculateCost() <<endl;

	TwoDayPakage B("B", "2222", "cityB", "stateB", "BBBBB", "CCCCC", 200, 4, 20);
	cout << B.calculateCost() << endl;

	OvernightPakage C("C", "3333", "cityC", "stateC", "CCCCC", "DDDDD", 300, 3, 10);
	cout << C.calculateCost() << endl;
}