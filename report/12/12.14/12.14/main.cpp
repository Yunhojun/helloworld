#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h" 
#include "CommissionEmployee.h"  
#include "BasePlusCommissionEmployee.h" 
#include "PieceWorker.h"
#include "HourlyWorker.h"
using namespace std;

void virtualViaPointer(const Employee* const);
void virtualViaReference(const Employee&);

int main() {
   cout << fixed << setprecision(2);                      
   SalariedEmployee salariedEmployee{
      "John", "Smith", "111-11-1111", 800};
   CommissionEmployee commissionEmployee{
      "Sue", "Jones", "333-33-3333", 10000, .06};
   BasePlusCommissionEmployee basePlusCommissionEmployee{
      "Bob", "Lewis", "444-44-4444", 5000, .04, 300};
   PieceWorker PieceWorker(
	   "Harry", "Owen", "555-55-5555", 100, 50
   );
   HourlyWorker HourlyWorker(
	   "Sarah", "Brown", "666-66-6666", 100, 48
   );

   vector<Employee *> employees{&salariedEmployee, &commissionEmployee,
      &basePlusCommissionEmployee, &PieceWorker, &HourlyWorker};

   for (const Employee* employeePtr : employees) {
	   cout << fixed << setprecision(2);
	   cout << employeePtr->toString() << endl << "earned $" << employeePtr->earnings() << endl << endl;
   }
}