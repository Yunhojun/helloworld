// Fig. 12.9: Employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string> 
#include "Date.h"
class Employee {
public:
	Employee(int, int, int, const std::string&, const std::string&, const std::string &);
	virtual ~Employee();

   void setFirstName(const std::string&);
   std::string getFirstName() const;

   void setLastName(const std::string&);
   std::string getLastName() const;

   void setSocialSecurityNumber(const std::string&);
   std::string getSocialSecurityNumber() const;
   
   int getmonth()const;

   virtual double earnings(int) const = 0;
   virtual std::string toString() const;
private:
   std::string firstName;
   std::string lastName;
   std::string socialSecurityNumber;
   Date birthDay;
};

#endif // EMPLOYEE_H