/*
 * Vehicle.cpp
 *
 *  Created on: 18/12/2017
 *      Author: up201603265
 */

#include "Vehicle.h"
#include <iomanip>
#include <sstream>
using namespace std;
Vehicle::Vehicle() {
	// TODO Auto-generated constructor stub

}

Vehicle::~Vehicle() {
	// TODO Auto-generated destructor stub
}

bool Vehicle::operator <(const Vehicle& v1) const {

	if ( ((this->available) == true) && ((v1.available) == false) )
		return false;
	else if ( ((this->available) == false) &&  ((v1.available) == true) )
		return true;
	else if ( ((this->inMaintenance) == true) && ((v1.inMaintenance) == false) )
		return false;
	else if ( ((this->inMaintenance) == false) &&  ((v1.inMaintenance) == true) )
		return true;
	else if (!(this->expectable_day == v1.expectable_day))
		return (!(this->expectable_day < v1.expectable_day));
	else
		return	(!(this->expectable_time < v1.expectable_time));
}

bool Vehicle::operator ==(const Vehicle& v1) const {

	return ( (this->brand == v1.brand) && (this->model == v1.model) && (this->plate == v1.plate) );
}

std::ostream& operator <<(std::ostream& os, const Vehicle& dt) {

	os << dt.getPlate() << ": ";
	os << left << setw(8) << setfill(' ') << dt.getBrand() << " ";
	os << left << setw(8) << setfill(' ') << dt.getModel();
	os << " Birthday: " << dt.getBirthday().toStr() << " Expected time: " << dt.getExpectableDay().toStr() << " " << dt.getExpectableTime().toStr();
	os << left << setw(15) << setfill(' ') << ( (dt.isAvailable()) ? " Available " : " Not Available ");
	os << left << setw(20) << setfill(' ') << ( (dt.isInMaintenance()) ? " In Maintenance " : " Not In Maintenance ") << "Maintenance date: " << dt.getMaintenance().toStr() << endl;

	return os;
}

Vehicle::Vehicle(std::string plate, std::string brand, std::string model,
		Date birthday, Hour expectable_time, Date maintenance) {

	this->plate = plate;
	this->brand = brand;
	this->model = model;
	this->birthday = birthday;
	this->expectable_time = expectable_time;
	this->maintenance = maintenance;
	this->available = true;
	this->inMaintenance = false;
	this->expectable_day = Date(0,0,0);

}


Vehicle::Vehicle(std::string plate, std::string brand, std::string model,
		Date birthday, Hour expectable_time, Date maintenance, bool available, bool inMaintenance, Date expectable_day) {

	this->plate = plate;
	this->brand = brand;
	this->model = model;
	this->birthday = birthday;
	this->expectable_time = expectable_time;
	this->maintenance = maintenance;
	this->available = available;
	this->inMaintenance = inMaintenance;
	this->expectable_day = expectable_day;
}

Vehicle::Vehicle(std::string plate, std::string brand, std::string model) {
	this->plate = plate;
	this->brand = brand;
	this->model = model;
	this->available = true;
	this->inMaintenance = false;
	this->expectable_day = Date(0,0,0);
	this->expectable_time = Hour (0,0);
}

std::string Vehicle::toStrComplete() {
	std::stringstream s1;

	s1 << this->getPlate() << ": ";
	s1 << left << setw(8) << setfill(' ') << this->getBrand() << " ";
	s1 << left << setw(8) << setfill(' ') << this->getModel();
	s1 << " Birthday: " << this->getBirthday().toStr() << " Expected time: " << this->getExpectableDay().toStr() << " " << this->getExpectableTime().toStr();
	s1 << left << setw(15) << setfill(' ') << ( (this->isAvailable()) ? " Available " : " Not Available ");
	s1 << left << setw(20) << setfill(' ') << ( (this->isInMaintenance()) ? " In Maintenance " : " Not In Maintenance ") << "Maintenance date: " << this->getMaintenance().toStr() << endl;

	return s1.str();
}

std::string Vehicle::toStrShort() {
	std::stringstream s1;

	s1 << this->getPlate() << ": ";
	s1 << left << setw(8) << setfill(' ') << this->getBrand() << " ";
	s1 << left << setw(8) << setfill(' ') << this->getModel() << endl;

	return s1.str();
}

const Date& Vehicle::getExpectableDay() const {
	return expectable_day;
}

void Vehicle::setExpectableDay(const Date& expectableDay) {
	expectable_day = expectableDay;
}

Vehicle::Vehicle(std::string plate, std::string brand, std::string model,
		Date birthday, Hour expectable_time, Date maintenance, bool available,
		bool inMaintenance) {

	this->plate = plate;
	this->brand = brand;
	this->model = model;
	this->birthday = birthday;
	this->expectable_time = expectable_time;
	this->maintenance = maintenance;
	this->available = available;
	this->inMaintenance = inMaintenance;
	this->expectable_day = Date(0,0,0);
}
