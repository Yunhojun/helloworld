#include <string>

class Rational {
public:
	explicit Rational(int, int);

	void add(Rational);
	void subtract(Rational);
	void multiply(Rational);
	void divide(Rational);
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