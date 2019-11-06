#pragma once
#include <string>

class Pakage {
protected:
	std::string name;
	std::string address;
	std::string city;
	std::string state;
	std::string ZIPcodeSender;
	std::string ZIPcodeRecipient;
	double weight;
	double costPerOunce;
public:
	Pakage(std::string, std::string, std::string, std::string, std::string, std::string, double, double);
	virtual ~Pakage();
	double calculateCost()const;
};
