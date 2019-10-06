#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <stdexcept>
#include <ctime>

#ifndef DATE_H
#define DATE_H

class Date
{
public:
	Date();
	Date(int, int);
	Date(int, int, int);
	Date(std::string, int, int);
	std::string toString();
	~Date();
	void DDDtoDay();
	void DaytoDDD();
	int monthtoI(std::string);
	bool checkDayLeap();//���� üũ�ϴ� �Լ�
private:
	int Day;
	int Month;
	int Year;
	int DDD;

	int checkDay(int);
	int checkMonth(int);
	const int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
};

#endif // !DATE_H

//output DDD YYYY
//	MM/DD/YY
//	June 14, 1992

//�Է����¿� ���� �ٸ��� �ʱ�ȭ�ϵ��� �����ε� ������
//<ctime> ���