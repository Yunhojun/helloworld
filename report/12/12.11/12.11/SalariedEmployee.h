// Fig. 12.11: SalariedEmployee.
#ifndef SALARIED_H
#define SALARIED_H

#include <string>
#include "Employee.h"

class SalariedEmployee : public Employee {
public:
	SalariedEmployee(int, int, int, const std::string&, const std::string&, 
		const std::string&, double = 0.0);
   virtual ~SalariedEmployee() = default;

   void setMonthlySalary(double);
   double getMonthlySalary() const;
               
   virtual double earnings(int) const override;
   virtual std::string toString() const override;
private:
   double monthlySalary;
};

#endif // SALARIED_H