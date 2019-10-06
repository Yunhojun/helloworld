#include "Rational.h"

Rational::Rational(int num_value, int denom_value)
: numerator(num_value)
{
	if (denom_value == 0) {
		std::cout << "You can't input 0 to denominater. The denominator is 1 now." << std::endl;
		denominator = 1;
	}
	else {
		denominator = denom_value;
	}
	reduce();
};

void Rational::reduce() {
	for (int x = denominator; x > 1; x--) {
		if (denominator%x == 0) {
			if (numerator%x == 0) {
				numerator /= x;
				denominator /= x;
				break;
			}
		}
	}
}

const Rational Rational::operator+(Rational& right) {
	int num_value = getnum()*right.getdenom() + right.getnum()*getdenom();
	int denom_value = getdenom()*right.getdenom();
	
	Rational C(num_value, denom_value);
	return C;
}

const Rational Rational::operator-(Rational& right) {
	int num_value = getnum()*right.getdenom() - right.getnum()*getdenom();
	int denom_value = getdenom()*right.getdenom();

	Rational C(num_value, denom_value);
	return C;
}

const Rational Rational::operator*(Rational& right) {
	int num_value = getnum()*right.getnum();
	int denom_value = getdenom()*right.getdenom();

	Rational C(num_value, denom_value);
	return C;
}

const Rational Rational::operator/(Rational& right) {
	int num_value = getnum() * right.getdenom();
	int denom_value = getdenom() * right.getnum();

	Rational C(num_value, denom_value);
	return C;
}

std::ostream& operator<<(std::ostream& output, Rational& A) {
	output << A.toRaionalString();
	return output;
}

std::string Rational::toRaionalString() {
	return std::to_string(numerator) + " / " + std::to_string(denominator);
}

double Rational::toDouble() {
	return double(numerator) / double(denominator);
}

int Rational::getnum() {
	return numerator;
}

int Rational::getdenom() {
	return denominator;
}

void Rational::setnum(int num_value) {
	numerator = num_value;
}

void Rational::setdenom(int denom_value) {
	denominator = denom_value;
}