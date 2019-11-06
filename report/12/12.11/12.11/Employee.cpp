// Fig. 12.10: Employee.cpp
#include <sstream>
#include "Employee.h" 
using namespace std;

Employee::Employee(int m, int d, int y, const string& first, const string& last,
	const string& ssn)
   : firstName(first), lastName(last), socialSecurityNumber(ssn) {
	birthDay = *(new Date(m, d, y));
}

Employee::~Employee() {
	delete &birthDay;
}

void Employee::setFirstName(const string& first) { 
	firstName = first;
}

string Employee::getFirstName() const { 
	return firstName;
}

void Employee::setLastName(const string& last) { 
	lastName = last; 
}

string Employee::getLastName() const { 
	return lastName;
}

void Employee::setSocialSecurityNumber(const string& ssn) {
   socialSecurityNumber = ssn; // should validate
}

string Employee::getSocialSecurityNumber() const {
   return socialSecurityNumber;
}

int Employee::getmonth()const {
	return birthDay.getmonth();
}

string Employee::toString() const {
	ostringstream output;
	output << getFirstName() + " "s + getLastName() +
		"\nsocial security number: "s + getSocialSecurityNumber() + "\n" << birthDay;
	return output.str();
}