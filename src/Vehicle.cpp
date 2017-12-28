/*
 * Vehicle.cpp
 *
 *  Created on: 18/12/2017
 *      Author: up201603265
 */

#include "Vehicle.h"

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
	else
		return	(!(this->expectable_time < v1.expectable_time));
}

bool Vehicle::operator ==(const Vehicle& v1) const {

	return ( (this->brand == v1.brand) && (this->model == v1.model) && (this->plate == v1.plate) );
}

std::ostream& operator <<(std::ostream& os, const Vehicle& dt) {

	os << dt.plate << ": " << dt.brand << " " << dt.model << std::endl << "Birthday: "
			<< dt.birthday << " Expectable time: " << dt.expectable_time << std::endl;
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
}


Vehicle::Vehicle(std::string plate, std::string brand, std::string model,
		Date birthday, Hour expectable_time, Date maintenance, bool available, bool inMaintenance) {

	this->plate = plate;
	this->brand = brand;
	this->model = model;
	this->birthday = birthday;
	this->expectable_time = expectable_time;
	this->maintenance = maintenance;
	this->available = available;
	this->inMaintenance = inMaintenance;
}

Vehicle::Vehicle(std::string plate, std::string brand, std::string model) {
	this->plate = plate;
	this->brand = brand;
	this->model = model;
	this->available = true;
	this->inMaintenance = false;
}
