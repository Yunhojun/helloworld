#include "OvernightPakage.h"
#include <iostream>
using namespace std;

OvernightPakage::OvernightPakage(string nm, string add, string ct, string stt, string zipS, string zipR, double w, double cpo, double adf)
	:Pakage(nm, add, ct, stt, zipS, zipR, w, cpo), additionalFee(adf) {

}

OvernightPakage::~OvernightPakage() {

}

double OvernightPakage::calculateCost()const {
	return (additionalFee + costPerOunce) * weight;
}