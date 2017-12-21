/*
 * Utilities.cpp
 *
 *  Created on: 04/11/2017
 *      Author: jotaa
 */

#include "Utilities.h"

Utilities::Utilities() {
	// TODO Auto-generated constructor stub

}

Utilities::~Utilities() {
	// TODO Auto-generated destructor stub
}

bool Sort::auxSortbyDate(Services* a, Services* b) {
	if (a->getPackaging().getStart_date() < b->getPackaging().getStart_date())
		return true;
	else if (a->getPackaging().getStart_date()
			> b->getPackaging().getStart_date())
		return false;
	else if (a->getShipping().getArrival_date()
			< b->getShipping().getArrival_date())
		return true;
	else if (a->getShipping().getArrival_date()
			> b->getShipping().getArrival_date())
		return false;
	else if (a->getDelivery().getStart_date()
			< b->getDelivery().getStart_date())
		return true;
	else if (a->getDelivery().getStart_date()
			> b->getDelivery().getStart_date())
		return false;
	else if (a->getDelivery().getEnd_date() < b->getDelivery().getEnd_date())
		return true;
	else if (a->getDelivery().getEnd_date() > b->getDelivery().getEnd_date())
		return false;

	return false;
}

bool Sort::auxSortbyPrice(Services* a, Services* b) {
	if (a->getPrice() < b->getPrice())
		return true;
	else
		return false;
}

bool Sort::auxSortbyVolume(Services* a, Services* b) {
	if (a->getVolume() < b->getVolume())
		return true;
	else
		return false;
}

bool Sort::auxSortbyDistance(Services* a, Services* b) {
	if (a->getDistance() < b->getDistance())
		return true;
	else
		return false;
}

bool Sort::auxSortbyID(Services* a, Services* b) {
	if (a->getId() < b->getId())
		return true;
	else
		return false;
}

bool Utilities::isCapitalDistrito(const string city) {

	vector<string> citys;
	citys.push_back("Aveiro");
	citys.push_back("Beja");
	citys.push_back("Braga");
	citys.push_back("Braganca");
	citys.push_back("Castelo Branco");
	citys.push_back("Coimbra");
	citys.push_back("Evora");
	citys.push_back("Faro");
	citys.push_back("Guarda");
	citys.push_back("Leiria");
	citys.push_back("Lisboa");
	citys.push_back("Portalegre");
	citys.push_back("Porto");
	citys.push_back("Santarem");
	citys.push_back("Setubal");
	citys.push_back("Viana do Castelo");
	citys.push_back("Vila Real");
	citys.push_back("Viseu");

	//return std::binary_search(citys.begin(), citys.end(), city);

	for (unsigned int i = 0; i < citys.size(); i++) {
		if (city == citys.at(i)) {
			return true;
		}
	}
	return false;
}

Date Utilities::lastDayofMonth(unsigned int month, unsigned int year) {
	if (month > 12 || month < 0)
		return Date(1, month, year);
	switch (month) {
	case 4:
	case 6:
	case 9:
	case 11:
		return Date(30, month, year);

	case 2:
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return Date(29, month, year);
		else
			return Date(28, month, year);
	default:
		return Date(31, month, year);
	}
}

string generateRandom(int length) {
	string random = "";
	int r = rand();
	for (int i = 0; i < length; i++) {
		srand((int)time(NULL) + r);
		r = rand();
		random += to_string(r % 10);
		;
	}

	return random;
}

string Utilities::readLine() {
	string line;
	getline(cin, line);
	return line;
}

bool Sort::auxSortbyMaintenanceDate(Vehicle a, Vehicle b) {

	return (a.getMaintenance() < b.getMaintenance());
}
