#include "Pakage.h"
#include <iostream>
using namespace std;

Pakage::Pakage(string nm, string add, string ct, string stt, string zipS, string zipR, double w, double cpo)
	:name(nm), address(add), city(ct), state(stt), ZIPcodeSender(zipS), ZIPcodeRecipient(zipR), weight(w), costPerOunce(cpo)
{

}

Pakage::~Pakage() {

}

double Pakage::calculateCost()const{
	return weight * costPerOunce;
}