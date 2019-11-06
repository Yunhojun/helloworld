#pragma once
#include "Pakage.h"
#include <string>

class OvernightPakage : public Pakage
{
public:
	OvernightPakage(std::string, std::string, std::string, std::string, std::string, std::string, double, double, double);
	virtual ~OvernightPakage();
	double calculateCost()const;

private:
	double additionalFee;
};