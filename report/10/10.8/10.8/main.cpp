#include "MotorVehicle.h"
using namespace std;

int main() {
	MotorVehicle mV_A("AAA", "Fueeeeel", "Reeeeed");
	mV_A.setyearOfManufacture(1234);
	mV_A.setengineCapacity(100);
	MotorVehicle mV_B("AAA", "Fueeeeel", "Blueeeee");
	mV_B.setyearOfManufacture(2314);
	mV_B.setengineCapacity(99);

	cout << "Information of A: ";
	cout << mV_A << endl;

	cout << "Information of B: ";
	cout << mV_B << endl;

	cout << "Is A equal to B? : " << mV_A + mV_B;
}