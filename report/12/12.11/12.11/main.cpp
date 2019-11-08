#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h" 
#include "CommissionEmployee.h"  
#include "BasePlusCommissionEmployee.h" 
using namespace std;

void virtualViaPointer(const Employee* const);
void virtualViaReference(const Employee&);

int main() {
   cout << fixed << setprecision(2);                      
   SalariedEmployee salariedEmployee{2,9,2000,
      "John", "Smith", "111-11-1111", 800};
   CommissionEmployee commissionEmployee{11,14,2000,
      "Sue", "Jones", "333-33-3333", 10000, .06};
   BasePlusCommissionEmployee basePlusCommissionEmployee{1,1,2000,
      "Bob", "Lewis", "444-44-4444", 5000, .04, 300};


   vector<Employee *> employees{&salariedEmployee, &commissionEmployee,
      &basePlusCommissionEmployee};

   for (int j = 0; j < 3; j++){
		cout << employees[j]->toString() << endl;
		cout << "month  earning" << endl;
		for (int i = 1; i <= 12; i++) {
			cout << i;
			if (i >= 10) {
				cout << "     ";
			}
			else {
				cout << "      ";
			}
			cout << employees[j]->earnings(i) << endl;
		}
		cout << endl;
	}

   return 0;
}