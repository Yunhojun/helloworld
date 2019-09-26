#include "Q_Equations.h"
#include <iostream>
#include <cmath>
using namespace std;

Q_Equations::Q_Equations(double a,double b,double c) 
	:a_value(a),b_value(b),c_value(c) {
	if (a == 0) {
		a = 1;
	}
}

void Q_Equations::add(Q_Equations A, double a, double b, double c) {
	a += A.geta();
	b += A.getb();
	c += A.getc();
}

void Q_Equations::subtract(Q_Equations A, double a, double b, double c) {
	a -= A.geta();
	b -= A.getb();
	c -= A.getc();
}

string Q_Equations::toString() {
	string a_string = to_string(geta());
	return to_string(geta()) + "X^2 + " + to_string(getb()) + "X + " + to_string(getc());
}

double Q_Equations::geta() {
	return a_value;
}

double Q_Equations::getb() {
	return b_value;
}

double Q_Equations::getc() {
	return c_value;
}

void Q_Equations::seta(double a) {
	a_value = a;
}

void Q_Equations::setb(double b) {
	b_value = b;
}

void Q_Equations::setc(double c) {
	c_value = c;
}