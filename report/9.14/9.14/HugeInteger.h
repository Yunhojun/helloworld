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
//���ϱ� ���� �Է� ��� ������ �Ȱ����� ū�� ������ ũ�ų������� �۰ų������� 0����
//ũ�Ⱑ 40�� �迭�� �����
//�迭�� �� �ڸ����� �����Ѵ�.
//��Ʈ������ �Է��� �޴´�