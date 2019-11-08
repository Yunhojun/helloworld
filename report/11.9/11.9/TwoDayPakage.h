#pragma once
#include "Pakage.h"
class TwoDayPakage : public Pakage
{
public:
	TwoDayPakage(std::string, std::string, std::string, std::string, std::string, std::string, double, double, double);
	virtual ~TwoDayPakage();
	double calculateCost()const;

private:
	double flatFee;
};