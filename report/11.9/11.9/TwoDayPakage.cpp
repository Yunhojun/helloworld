#include "TwoDayPakage.h"
#include <iostream>
using namespace std;

TwoDayPakage::TwoDayPakage(string nm, string add, string ct, string stt, string zipS, string zipR, double w, double cpo, double ff)
	:Pakage(nm, add, ct, stt, zipS, zipR, w, cpo), flatFee(ff) {

	}

TwoDayPakage::~TwoDayPakage() {

}

double TwoDayPakage::calculateCost()const{
	return flatFee + Pakage::calculateCost();
}