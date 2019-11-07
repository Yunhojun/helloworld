#include "PieceWorker.h"
#include <sstream>
#include <iomanip>
using namespace std;

PieceWorker::PieceWorker(const std::string& first, const std::string& last, const std::string & ssn, double wg, int pc)
	:Employee(first, last, ssn), wage(wg), piece(pc) {

}

double PieceWorker::earnings()const {
	return getwage() * getpiece();
}

double PieceWorker::getwage()const {
	return wage;
}

int PieceWorker::getpiece()const {
	return piece;
}

std::string PieceWorker::toString()const {
	ostringstream output;
	output << fixed << setprecision(2);
	output << "piece worker: " << Employee::toString() << endl
		<< "wage: " << getwage() << endl
		<< "piece: " << getpiece();
	return output.str();
}