#include <iostream>
#include <string>

class HugeInteger
{
public:
	HugeInteger();

	void input();

	void output();

	void add(HugeInteger);

	void subtract(HugeInteger);

	bool isEqualTo(HugeInteger);

	bool isNotEqualTo(HugeInteger);

	bool isGreaterThan(HugeInteger);

	bool isLessThan(HugeInteger);

	bool isGreaterThanOrEqualTo(HugeInteger);

	bool isLessThanOrEqualTo(HugeInteger);

	bool isZero();

	char getarr(int i);

	void setarr(char, int);

private:
	char arr[40];
};
//더하기 빼기 입력 출력 같은지 안같은지 큰지 작은지 크거나같은지 작거나같은지 0인지
//크기가 40인 배열을 만든다
//배열에 각 자릿수를 저장한다.
//스트링으로 입력을 받는다