#include "MotorVehicle.h"
using namespace std;

int main() {
	MotorVehicle mV_A("AAA", "Fueeeeel", "Reeeeed");
	mV_A.setyearOfManufacture(1234);
	mV_A.setengineCapacity(100);
	MotorVehicle mV_B("AAA", "Fueeeeel", "Reeeeed");
	mV_B.setyearOfManufacture(1234);
	mV_B.setengineCapacity(100);
	MotorVehicle mV_C("CCC", "Fueeeel", "Blueeee");
	mV_C.setyearOfManufacture(5346);
	mV_C.setengineCapacity(99);

	cout << "Information of A: ";
	cout << mV_A << endl << endl;

	cout << "Information of B: ";
	cout << mV_B << endl <<endl;

	cout << "Information of C: ";
	cout << mV_C << endl << endl;

	cout << "Is A equal to B? : " << (mV_A == mV_B) << endl;
	cout << "Is A not equal to B? : " << (mV_A != mV_B) << endl;
	cout << "Is A greater than B? : " << (mV_A > mV_B) << endl << endl;
	cout << "Is A equal to C? : " << (mV_A == mV_C) << endl;
	cout << "Is A not equal to C? : " << (mV_A != mV_C) << endl;
	cout << "Is A greater than C? : " << (mV_A > mV_C) << endl;

}