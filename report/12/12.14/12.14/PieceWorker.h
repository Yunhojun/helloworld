#pragma once
#include "Employee.h"
class PieceWorker: public Employee
{
public:
	PieceWorker(const std::string&, const std::string&, const std::string &, double, int);
	virtual ~PieceWorker()= default;

	double getwage()const;
	int getpiece()const;

	virtual double earnings()const override;
	virtual std::string toString()const override;
private:
	double wage;
	int piece;
};