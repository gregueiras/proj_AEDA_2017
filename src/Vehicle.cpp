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
	else
		return	(!(this->expectable_time < v1.expectable_time));
}

bool Vehicle::operator ==(const Vehicle& v1) const {

	return ( (this->brand == v1.brand) && (this->model == v1.model) && (this->name == v1.name) );
}

std::ostream& operator <<(std::ostream& os, const Vehicle& dt) {

	os << dt.name << ": " << dt.brand << " " << dt.model << std::endl << "Birthday: "
			<< dt.birthday << " Expectable time: " << dt.expectable_time << std::endl;
	return os;
}

Vehicle::Vehicle(std::string name, std::string brand, std::string model,
		Date birthday, Hour expectable_time, Date maintenance) {

	this->name = name;
	this->brand = brand;
	this->model = model;
	this->birthday = birthday;
	this->expectable_time = expectable_time;
	this->maintenance = maintenance;
	this->available = true;
}

Vehicle::Vehicle(std::string name, std::string brand, std::string model) {
	this->name = name;
	this->brand = brand;
	this->model = model;
}
