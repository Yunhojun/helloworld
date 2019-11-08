#pragma once
#include <string>
#include "Employee.h"

class HourlyWorker : public Employee
{
public:
	HourlyWorker(const std::string& first, const std::string& last, const std::string & ssn, double wg, int h);
	virtual ~HourlyWorker() = default;

	int getHour()const;
	double getWage()const;

	virtual double earnings()const;
	virtual std::string toString()const;

private:
	int hour;
	double wage;
};