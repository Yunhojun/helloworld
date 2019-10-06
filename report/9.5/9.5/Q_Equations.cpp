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

void Q_Equations::add(Q_Equations A) {
	double a = geta();
	a += A.geta();
	seta(a);

	double b = getb();
	b += A.getb();
	setb(b);

	double c = getc();
	c += A.getc();
	setc(c);
}//add Fa and Fb

void Q_Equations::subtract(Q_Equations A) {
	double a = geta();
	a -= A.geta();
	seta(a);

	double b = getb();
	b -= A.getb();
	setb(b);

	double c = getc();
	c -= A.getc();
	setc(c);
}//subtract Fa and Fb

string Q_Equations::toString() {
	string tostring[3] = { to_string(geta()),to_string(getb()),to_string(getc()) };

	for (int i = 0; i < 3; i++) {
		int len = tostring[i].length();
		while ((tostring[i])[len-1] == '0' || (tostring[i])[len-1] == '.') {
			tostring[i].erase(len-1);
			if ((tostring[i])[len - 1] == '.') {
				break;
			}
			len--;
		}
	}

	return tostring[0] + "X^2 + " + tostring[1] + "X + " + tostring[2];
}//make equation to string

void Q_Equations::solve() {
	double a = geta();
	double b = getb();
	double c = getc();

	double D = pow(b, 2) - 4 * a*c;
	if (D < 0) {
		cout << "No Real Roots." << endl;
	}
	if (D == 0) {
		cout << (-b) / 2 * a << endl;
	}
	else {
		cout << (-b + sqrt(D)) / 2 * a << " , " << (-b - sqrt(D)) / 2 * a << endl;
	}
}//display value x

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