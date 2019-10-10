#include "HugeInteger.h"
using namespace std;

HugeInteger::HugeInteger(long value) {
	for (int j = digits - 1; value != 0 && j >= 0; j--) {
		integer[j] = value % 10;
		value /= 10;
	}
}

HugeInteger::HugeInteger(const string& number) {
	int length = number.size();

	for (int j = digits - length, k = 0; j < digits; j++, k++) {
		if ('0' <= number[k] && number[k] <= '9') {
			integer[j] = number[k] -48;
		}
	}
}

HugeInteger::~HugeInteger() {
	;
}

HugeInteger HugeInteger::operator+(const HugeInteger& op2)const {
	int carry = 0;
	HugeInteger temp;

	for (int i = digits - 1; i >= 0; i--) {
		temp.integer[i] = integer[i] + op2.integer[i] + carry;
		if (temp.integer[i] > 9) {
			temp.integer[i] %= 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
	}
	return temp;
}


HugeInteger HugeInteger::operator+(int op2)const {
	return *this + HugeInteger(op2);
}

HugeInteger HugeInteger::operator+(const string& op2) const {
	return *this + HugeInteger(op2);
}

HugeInteger HugeInteger::operator*(const HugeInteger& op2)const {
	HugeInteger temp;
	int carry = 0;

	for (int i = 0; i < digits; i++) {

	}
}

HugeInteger HugeInteger::operator*(int op2)const {
	for (int i = 0; i <= digits; i++) {

	}
}

HugeInteger HugeInteger::operator*(const std::string& op2) const {

}

ostream& operator<<(ostream& output, const HugeInteger& num) {
	int i;

	for (i = 0; (i < HugeInteger::digits) && (num.integer[i] == 0); i++) {
		;
	}
	if (i == HugeInteger::digits) {
		output << 0;
	}
	else {
		for (; i < HugeInteger::digits; i++) {
			output << num.integer[i];
		}
	}
	return output;
}