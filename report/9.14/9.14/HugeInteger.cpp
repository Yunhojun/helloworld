#include "HugeInteger.h"

HugeInteger::HugeInteger() {
	for (int i = 0; i < 40; i++) {
		arr[i] = '0';
	}
}

void HugeInteger::add (HugeInteger A) {
	int temp[41] = { 0 };
	for (int i = 39; i >= 0; i--) {
		if (int(getarr(i) - 48) + int(A.getarr(i) - 48) + temp[i + 1] < 10) {
			temp[i + 1] += int(getarr(i) - 48) + int(A.getarr(i) - 48);
		}
		else {
			temp[i + 1] += int(getarr(i) - 48) + int(A.getarr(i) - 48) - 10;
			temp[i]++;
		}
	}

	if (temp[0] == 0) {
		for (int i = 1; i < 41; i++) {
			std::cout << temp[i];
		}
	}
	else {
		for (int i = 0; i < 41; i++) {
			std::cout << temp[i];
		}
	}
}

void HugeInteger::subtract(HugeInteger A) {
	int temp[40] = { 0 };
	if (isLessThanOrEqualTo(A) == false) {
		for (int i = 39; i >= 1; i--) {
			if (int(getarr(i)) - int(A.getarr(i)) + temp[i] >= 0) {
				temp[i] += int(getarr(i)) - int(A.getarr(i));
			}
			else {
				temp[i] += (int(getarr(i)) - int(A.getarr(i))) + 10;
				temp[i - 1]--;
			}
		}

		if (int(getarr(0)) - int(A.getarr(0) + temp[0]) >= 0) {
			temp[0] = int(getarr(0)) - int(A.getarr(0));
		}
		else {
			temp[0] = (int(getarr(0)) - int(A.getarr(0))) + 10;
			std::cout << "-";
		}

		for (int i = 0; i < 40; i++) {
			std::cout << temp[i];
		}
	}

	else if (isEqualTo(A) == true) {
		std::cout << 0;
	}

	else {
		for (int i = 39; i >= 1; i--) {
			if (int(A.getarr(i)) - int(getarr(i)) + temp[i] >= 0) {
				temp[i] += int(A.getarr(i)) - int(getarr(i));
			}
			else {
				temp[i] += (int(A.getarr(i)) - int(getarr(i))) + 10;
				temp[i - 1]--;
			}
		}

		if (int(A.getarr(0)) - int(getarr(0) + temp[0]) >= 0) {
			temp[0] = int(A.getarr(0)) - int(getarr(0));
			std::cout << "-";
		}
		else {
			temp[0] = (int(A.getarr(0)) - int(getarr(0))) + 10;
		}

		for (int i = 0; i < 40; i++) {
			std::cout << temp[i];
		}
	}
}

void HugeInteger::input() {
	std::string A;
	std::cout << "Please input 40 digits integer: ";

	while (true) {
		try {
			std::cin >> A;
			if (A.length() != 40) {
				throw ("You didn't input 40 digits");

			}
			for (int i = 0; i < 40; i++) {
				arr[i] = A[i];
			}
		}
		catch (const char*){
			std::cout << "Please input 40 digits integer again: ";
			continue;
		}
		break;
	}
}

void HugeInteger::output() {
	std::cout << arr << std::endl;
}

bool HugeInteger::isEqualTo(HugeInteger A) {
	for (int i = 0; i < 40; i++) {
		if (getarr(i) != A.getarr(i)) {
			return false;
		}
	}
	return true;
}

bool HugeInteger::isGreaterThan(HugeInteger A) {
	for (int i = 0; i < 40; i++) {
		if (getarr(i) > A.getarr(i)) {
			return true;
		}
		else if (getarr(i) < A.getarr(i)) {
			return false;
		}
	}
	return false;
}

bool HugeInteger::isGreaterThanOrEqualTo(HugeInteger A) {
	for (int i = 0; i < 40; i++) {
		if (getarr(i) > A.getarr(i)) {
			return true;
		}
		else if (getarr(i) < A.getarr(i)) {
			return false;
		}
	}
	return true;
}

bool HugeInteger::isLessThan(HugeInteger A) {
	for (int i = 0; i < 40; i++) {
		if (getarr(i) < A.getarr(i)) {
			return true;
		}
		else if (getarr(i) > A.getarr(i)) {
			return false;
		}
	}
	return false;
}

bool HugeInteger::isLessThanOrEqualTo(HugeInteger A) {
	for (int i = 0; i < 40; i++) {
		if (getarr(i) < A.getarr(i)) {
			return true;
		}
		else if (getarr(i) > A.getarr(i)) {
			return false;
		}
	}
	return true;
}

bool HugeInteger::isNotEqualTo(HugeInteger A) {
	for (int i = 0; i < 40; i++) {
		if (getarr(i) != A.getarr(i)) {
			return true;
		}
	}
	return false;
}

bool HugeInteger::isZero() {
	for (int i = 0; i < 40; i++) {
		if (getarr(i) != 0) {
			return false;
		}
	}
	return true;
}

char HugeInteger::getarr(int i) {
	return arr[i];
}

void HugeInteger::setarr(char a, int i) {
	arr[i] = a;
}