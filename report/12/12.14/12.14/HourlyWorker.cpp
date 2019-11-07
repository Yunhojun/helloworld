#include "HourlyWorker.h"
#include <sstream>
#include <iomanip>
using namespace std;

HourlyWorker::HourlyWorker(const std::string& first, const std::string& last, const std::string & ssn, double wg, int h)
	:Employee(first, last, ssn), wage(wg), hour(h) {

}

double HourlyWorker::getWage()const {
	return wage;
}

int HourlyWorker::getHour()const {
	return hour;
}

double HourlyWorker::earnings()const {
	if (getHour() <= 40) {
		return getHour()*getWage();
	}
	else {
		return getWage()*(1.5*getHour() - 20);
	}
}

string HourlyWorker::toString()const {
	ostringstream output;
	output << fixed << setprecision(2);
	output << "hourly worker: " << Employee::toString() << endl
		<< "wage: " << getWage() << endl
		<< "hour: " << getHour();
	return output.str();
}