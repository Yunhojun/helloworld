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
	int denominator;//�и�
};


//�м� ����ϱ�/���� ���� ���/���м��� ǥ��
//�����ε带 �̿��ؼ� + - * / >> ǥ��