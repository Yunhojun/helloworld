#include "MotorVehicle.h"

MotorVehicle::MotorVehicle(std::string _make, std::string _fuelType, std::string _color)
	:make(_make), fuelType(_fuelType), color(_color)
{
	
}

std::ostream& operator<<(std::ostream& output, MotorVehicle& A) {
	output << A.displayCarDetails();
	return output;
};

bool MotorVehicle::operator==(MotorVehicle& A) {
	if (getmake() != A.getmake()) {
		return false;
	}
	if (getfuelType() != A.getfuelType) {
		return false;
	}
	if (getyearOfManufacture() != A.getyearOfManufacture()) {
		return false;
	}
	if (getcolor() != A.getcolor()) {
		return false;
	}
	if (getengineCapacity() != A.getengineCapacity()) {
		return false;
	}
	return true;
}

bool MotorVehicle::operator!=(MotorVehicle& A) {
	if (operator== == false) {
		return true;
	}
	else return false;
}

bool MotorVehicle::operator>(MotorVehicle& A) {
	if (getyearOfManufacture() < A.getyearOfManufacture()) {
		return true;
	}
	else return false;
}




std::string MotorVehicle::displayCarDetails() {
	std::string output_make = "\nmake: " + getmake();
	std::string output_fuel = "\nfuelType: " + getfuelType();
	std::string output_year = "\nyearOfManufactur: " + getyearOfManufacture();
	std::string output_color = "\ncolor: " + getcolor();
	std::string output_capacity = "\nengineCapacity: " + getengineCapacity();

	return output_make + output_fuel + output_year + output_color + output_capacity;
}

void MotorVehicle::setmake(std::string _make) {
	make = _make;
}

std::string MotorVehicle::getmake()const {
	return make;
}

void MotorVehicle::setfuelType(std::string _fuelType) {
	fuelType = _fuelType;
}

std::string MotorVehicle::getfuelType()const {
	return fuelType;
}

void MotorVehicle::setyearOfManufacture(int _yearOfManufacture) {
	yearOfManufacture = _yearOfManufacture;
}

int MotorVehicle::getyearOfManufacture()const {
	return yearOfManufacture;
}

void MotorVehicle::setcolor(std::string _color) {
	color = _color;
}

std::string MotorVehicle::getcolor()const {
	return color;
}

void MotorVehicle::setengineCapacity(int _engineCapacity) {
	engineCapacity = _engineCapacity;
}

int MotorVehicle::getengineCapacity()const {
	return engineCapacity;
}