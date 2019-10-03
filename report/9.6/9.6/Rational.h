#include <string>
#include <iostream>

class Rational {
	friend std::ostream& operator<<(std::ostream&, Rational&);

public:
	explicit Rational(int, int);

	const Rational operator+ (Rational&);
	const Rational operator-(Rational&);
	const Rational operator*(Rational&);
	const Rational operator/(Rational&);

	std::string toRaionalString();
	double toDouble();
	void reduce();

	int getnum();
	int getdenom();

	void setnum(int);
	void setdenom(int);

private:
	int numerator;
	int denominator;//분모
};


//분수 계산하기/정수 변수 사용/기약분수로 표현
//오버로드를 이용해서 + - * / >> 표현