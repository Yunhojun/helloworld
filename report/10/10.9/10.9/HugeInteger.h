#ifndef  HUGEINTEGER_H
#define HUGEINTEGER_H
#include <iostream>
#include <string>

class HugeInteger
{
	friend std::ostream& operator<<(std::ostream&, const HugeInteger&);
public:
	static const int digits = 80;

	HugeInteger(long = 0);
	HugeInteger(const std::string&);

	~HugeInteger();

	HugeInteger operator+(const HugeInteger&) const;
	HugeInteger operator+(int)const;
	HugeInteger operator+(const std::string&) const;

	HugeInteger operator*(const HugeInteger&) const;
	HugeInteger operator*(int)const;
	HugeInteger operator*(const std::string&) const;


	HugeInteger operator/(const HugeInteger&) const;
	HugeInteger operator/(int)const;
	HugeInteger operator/(const std::string&) const;
private:
	short integer[digits] = { 0 };
};
#endif // ! HUGEINTEGER_H
