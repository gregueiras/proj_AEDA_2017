/*
 * Vehicle.h
 *
 *  Created on: 18/12/2017
 *      Author: up201603265
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>
#include <iostream>
#include "Date.h"

class Vehicle {
public:
	std::string plate;
	std::string brand;
	std::string model;
	Date birthday;
	Hour expectable_time;
	Date maintenance;
	bool available;
	bool inMaintenance;

	Vehicle();
	Vehicle(std::string plate, std::string brand, std::string model, Date birthday, Hour expectable_time, Date maintenance);
	Vehicle(std::string plate, std::string brand, std::string model);
	Vehicle(std::string plate, std::string brand, std::string model, Date birthday, Hour expectable_time, Date maintenance, bool available, bool inMaintenance);


	virtual ~Vehicle();

	const Date& getBirthday() const {
		return birthday;
	}

	void setBirthday(const Date& birthday) {
		this->birthday = birthday;
	}

	const std::string& getBrand() const {
		return brand;
	}

	void setBrand(const std::string& brand) {
		this->brand = brand;
	}

	const Hour& getExpectableTime() const {
		return expectable_time;
	}

	void setExpectableTime(const Hour& expectableTime) {
		expectable_time = expectableTime;
	}

	const std::string& getModel() const {
		return model;
	}

	void setModel(const std::string& model) {
		this->model = model;
	}

	const std::string& getPlate() const {
		return plate;
	}

	void setPlate(const std::string& name) {
		this->plate = name;
	}

	const Date& getMaintenance() const {
		return maintenance;
	}

	void setMaintenance(const Date& maintenance) {
		this->maintenance = maintenance;
	}


	bool isAvailable() const {
		return available;
	}

	void setAvailable(bool available) {
		this->available = available;
	}

	bool operator<(const Vehicle &v1) const;

	bool operator==(const Vehicle &v1) const;

	friend std::ostream& operator<<(std::ostream& os, const Vehicle& dt);

	bool isInMaintenance() const {
		return inMaintenance;
	}

	void setInMaintenance(bool inMaintenance) {
		this->inMaintenance = inMaintenance;
	}

	/**
	 * Converts the Vehicle to a string with all info
	 * @return Vehicle info
	 */
	std::string toStrComplete();

	/**
	 * Converts the Vehicle to a string with just the plate, brand and model
	 * @return plate, brand and model of the Vehicle
	 */
	std::string toStrShort();
};


std::ostream& operator<<(std::ostream& os, const Vehicle& dt);

#endif /* VEHICLE_H_ */
