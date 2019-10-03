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
	int denominator;//�и�
};


//�м� ����ϱ�/���� ���� ���/���м��� ǥ��
//�����ε带 �̿��ؼ� + - * / >> ǥ��