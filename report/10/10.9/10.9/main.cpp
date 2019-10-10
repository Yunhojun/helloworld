#include "HugeInteger.h"
using namespace std;

int main() {
	HugeInteger num1("9999999999999999999999999999999999999999");
	HugeInteger num2("2135346375485796898696574574562423435346");

	cout << num1 << endl;
	cout << num2 << endl;

	HugeInteger num3 = num1 + num2;
	cout << num3;
}