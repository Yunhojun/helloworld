// Fig. 12.12: SalariedEmployee.cpp
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "SalariedEmployee.h"
using namespace std;

SalariedEmployee::SalariedEmployee(int m, int d, int y, const string& first,
	const string& last, const string& ssn, double salary)
	: Employee(m, d, y, first, last, ssn) {
	setMonthlySalary(salary);
}

void SalariedEmployee::setMonthlySalary(double salary) {
   if (salary < 0.0) {
      throw invalid_argument("Monthly salary must be >= 0.0");
   }

   monthlySalary = salary;
}

double SalariedEmployee::getMonthlySalary() const { 
	return monthlySalary;
}

double SalariedEmployee::earnings(int month) const { 
	if (month == Employee::getmonth()) {
		return getMonthlySalary() + 100;
	}
	else {
		return getMonthlySalary();
	}
}

string SalariedEmployee::toString() const {
   ostringstream output;
   output << fixed << setprecision(2);
   output << "salaried employee: "
      << Employee::toString()
      << "\nmonthly salary: " << getMonthlySalary();
   return output.str();
}