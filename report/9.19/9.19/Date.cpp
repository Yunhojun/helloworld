#include "Date.h"

Date::Date(int day_, int year_)
	:DDD(day_), Year(year_)
{
	DDDtoDay();
}

Date::Date(int month_, int day_, int year_)
	: Year(year_)
{
	Month = checkMonth(month_);
	Day = checkDay(day_);
	DaytoDDD();
}

Date::Date(std::string month_string, int day, int year)
: Year(year)
{
	Month=monthtoI(month_string);
	Day = checkDay(day);
	DaytoDDD();
}

Date::~Date() {

}

std::string Date::toString() {
	std::string output_a = std::to_string(DDD) + " " + std::to_string(Year);
	std::string output_b = std::to_string(Month) + "/" + std::to_string(Day) + "/" + std::to_string(Year);

	std::string month_string;
	switch (Month)
	{
	case 1:month_string = "January";
		break;
	case 2:month_string = "February";
		break;
	case 3:month_string = "March";
		break;
	case 4:month_string = "Aprill";
		break;
	case 5:month_string = "May";
		break;
	case 6:month_string = "June";
		break;
	case 7:month_string = "July";
		break;
	case 8:month_string = "August";
		break;
	case 9:month_string = "September";
		break;
	case 10:month_string = "October";
		break;
	case 11:month_string = "November";
		break;
	case 12:month_string = "December";
		break;

	default:
		break;
	}

	std::string output_c = month_string + " " + std::to_string(Day) + ", " + std::to_string(Year);

	return output_a + "\n" + output_b + "\n" + output_c;
}

int Date::checkMonth(int testMonth) {
	if (testMonth > 12 || testMonth < 1) {
		throw std::invalid_argument("Invalid month");
	}
	else return testMonth;
}

int Date::checkDay(int testDay) {
	if (testDay > 0 && testDay <= arr[Month-1]) {
		return testDay;
	}
	else if (Month == 2 && testDay == 29 && (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0))) {
		return testDay;
	}

	throw std::invalid_argument("Invalid day for current month and year");
}

bool Date::checkDayLeap() {
	if (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0)){
		return true;//À±³â 29ÀÏ
	}
	else return false;//À±³â x 28ÀÏ
}

void Date::DDDtoDay() {
	int temp = DDD;
	int i;
	for (i = 0; temp > 0; i++) {
		if (i == 1 && checkDayLeap() == true) {
			if (temp > 29) {
				temp -= 29;
			}
			else break;
		}
		else if (i == 1 && checkDayLeap() == false) {
			if (temp > 28) {
				temp -= 28;
			}
			else {
				break;
			}
		}
		else {
			if (temp > arr[i]) {
				temp -= arr[i];
			}
			else {
				break;
			}
		}
	}

	Month = i+1;
	Day = temp;
}

void Date::DaytoDDD() {
	int temp = 0;
	for (int i = 0; i < Month - 1; i++) {
		if (i == 1 && checkDayLeap() == true) {
			temp += 29;
		}
		else if (i == 1 && checkDayLeap() == false) {
			temp += 28;
		}
		else {
			temp += arr[i];
		}
	}

	temp += Day;
	DDD = temp;
}

int Date::monthtoI(std::string month) {
	if (month == "January") {
		return 1;
	}
	if (month == "February") {
		return 2;
	}
	if (month == "March") {
		return 3;
	}

	if (month == "Aprill") {
		return 4;
	}
	if (month == "May") {
		return 5;
	}
	if (month == "June") {
		return 6;
	}
	if (month == "July") {
		return 7;
	}
	if (month == "August") {
		return 8;
	}
	if (month == "September") {
		return 9;
	}
	if (month == "October") {
		return 10;
	}
	if (month == "November") {
		return 11;
	}
	if (month == "December" ) {
		return 12;
	}
	else {
		throw std::invalid_argument("Invalid month");
	}
}