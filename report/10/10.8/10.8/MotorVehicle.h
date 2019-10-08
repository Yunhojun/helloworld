#include <string>
#include <iostream>

#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H


class MotorVehicle {
	friend std::ostream& operator<<(std::ostream&, MotorVehicle&);

private:
	std::string make;
	std::string fuelType;
	int yearOfManufacture;
	std::string color;
	int engineCapacity;

public:
	MotorVehicle(std::string, std::string, std::string);

	bool operator==(MotorVehicle&);
	bool operator!=(MotorVehicle&);
	bool operator>(MotorVehicle&);

	std::string displayCarDetails();

	void setmake(std::string);
	void setfuelType(std::string);
	void setyearOfManufacture(int);
	void setcolor(std::string);
	void setengineCapacity(int);

	std::string getmake()const;
	std::string getfuelType()const;
	int getyearOfManufacture()const;
	std::string getcolor()const;
	int getengineCapacity()const;
};


#endif // !MOTORVEHICLE_H