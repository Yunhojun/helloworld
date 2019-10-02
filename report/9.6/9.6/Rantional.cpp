#include "Rational.h"

Rational::Rational(int num_value, int denom_value)
: numerator(num_value),denominator(denom_value)
{
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