// Fig. 12.15: BasePlusCommissionEmployee.h
#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string> 
#include "CommissionEmployee.h" 

class BasePlusCommissionEmployee : public CommissionEmployee {
public:
	BasePlusCommissionEmployee(int, int, int, const std::string&, const std::string&, 
      const std::string&, double = 0.0, double = 0.0, double = 0.0);
   virtual ~BasePlusCommissionEmployee() = default; 

   void setBaseSalary(double); 
   double getBaseSalary() const; 

   virtual double earnings(int) const override; 
   virtual std::string toString() const override;            
private:
   double baseSalary; 
};

#endif // BASEPLUS_H