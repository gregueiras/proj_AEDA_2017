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
	Date expectable_day;
	Date maintenance;
	bool available;
	bool inMaintenance;

	Vehicle();
	Vehicle(std::string plate, std::string brand, std::string model, Date birthday, Hour expectable_time, Date maintenance);
	Vehicle(std::string plate, std::string brand, std::string model);
	Vehicle(std::string plate, std::string brand, std::string model, Date birthday, Hour expectable_time, Date maintenance, bool available, bool inMaintenance, Date expectable_day);
	Vehicle(std::string plate, std::string brand, std::string model, Date birthday, Hour expectable_time, Date maintenance, bool available, bool inMaintenance);


	virtual ~Vehicle();

	/**
	 * Get vehicle "birthday"
	 * @return vehicle "birthday"
	 */
	const Date& getBirthday() const {
		return birthday;
	}

	/**
	 * Set vehicle "birthday"
	 * @param birthday new vehicle "birthday"
	 */
	void setBirthday(const Date& birthday) {
		this->birthday = birthday;
	}

	/**
	 * Get vehicle brand
	 * @return vehicle brand
	 */
	const std::string& getBrand() const {
		return brand;
	}

	/**
	 * Set vehicle brand
	 * @param brand new vehicle brand
	 */
	void setBrand(const std::string& brand) {
		this->brand = brand;
	}

	/**
	 * Get vehicle expectable time
	 * @return vehicle expectable time
	 */
	const Hour& getExpectableTime() const {
		return expectable_time;
	}

	/**
	 * Set vehicle expectable time
	 * @param expectableTime new vehicle expectable time
	 */
	void setExpectableTime(const Hour& expectableTime) {
		expectable_time = expectableTime;
	}

	/**
	 * Get vehicle model
	 * @return vehicle model
	 */
	const std::string& getModel() const {
		return model;
	}

	/**
	 * Set vehicle model
	 * @param model new vehicle model
	 */
	void setModel(const std::string& model) {
		this->model = model;
	}

	/**
	 * Get vehicle plate
	 * @return vehicle plate
	 */
	const std::string& getPlate() const {
		return plate;
	}

	/**
	 * Set vehicle plate
	 * @param name new vehicle plate
	 */
	void setPlate(const std::string& plate) {
		this->plate = plate;
	}

	/**
	 * Get vehicle next maintenance date
	 * @return vehicle next maintenance date
	 */
	const Date& getMaintenance() const {
		return maintenance;
	}

	/**
	 * Set vehicle next maintenance date
	 * @param maintenance vehicle next maintenance date
	 */
	void setMaintenance(const Date& maintenance) {
		this->maintenance = maintenance;
	}

	/**
	 * Get available flag
	 * @return true if vehicle available, false if vehicle is in a service
	 */
	bool isAvailable() const {
		return available;
	}

	/**
	 * Set available flag
	 * @param available true if vehicle will be available, false if vehicle will be in a service
	 */
	void setAvailable(bool available) {
		this->available = available;
	}

	/**
	 * Operator <, used to sort vehicles in vehicles priority_queue
	 * @param v1 vehicle to be compared to "this" vehicle
	 * @return true if v1 should be in front of "this" vehicle in vehicles priority_queue
	 */
	bool operator<(const Vehicle &v1) const;

	/**
	 * Operator ==, compares vehicle brand, model and plate
	 * @param v1 vehicle to be compared to "this" vehicle
	 * @return true if brand, model and plate are the same in both cars, false if not
	 */
	bool operator==(const Vehicle &v1) const;

	friend std::ostream& operator<<(std::ostream& os, const Vehicle& dt);

	/**
	 * Get inMaintenance flag
	 * @return true if vehicle is in maintenance, false if it isn't
	 */
	bool isInMaintenance() const {
		return inMaintenance;
	}

	/**
	 * Set inMaintenance flag
	 * true if vehicle is in maintenance, false if it isn't
	 * @param inMaintenance new inMaintenance flag
	 */
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
	const Date& getExpectableDay() const;
	void setExpectableDay(const Date& expectableDay);
};


/**
 * Operator <<, used to print a vehicle
 * @param os ostream where the vehicle will be printed to
 * @param dt vehicle to be printed
 * @return the ostream used
 */
std::ostream& operator<<(std::ostream& os, const Vehicle& dt);

#endif /* VEHICLE_H_ */
