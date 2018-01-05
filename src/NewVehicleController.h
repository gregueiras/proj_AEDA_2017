/*
 * NewVehicleController.h
 *
 *  Created on: 28 Dec 2017
 *      Author: jotaa
 */

#ifndef SRC_NEWVEHICLECONTROLLER_H_
#define SRC_NEWVEHICLECONTROLLER_H_

#include "Company.h"
#include "NewVehicleView.h"
#include "VehicleMenuController.h"

class NewVehicleController {
private:
	NewVehicleView *theView;
	Company *company;
	Validation *v;
	string plate, brand, model;
	Date *birthday, *maintenance;
	Hour *expectable_time;

	/**
	 * user interaction method to get new vehicle information
	 */
	void getNewVehicleInformation();

	/**
	 * user interaction method to read plate information
	 * @return the plate
	 */
	string getPlate();

	/**
	 * user interaction method to read brand information
	 * @return the brand
	 */
	string getBrand();

	/**
	 * user interaction method to read model information
	 * @return the model
	 */
	string getModel();

	/**
	 * user interaction method to read birthday date information
	 * @return the birthday date
	 */
	Date * getBirthdayDate();

	/**
	 * user interaction method to read expectable timeinformation
	 * @return the expectable time
	 */
	Hour* getExpectableTime();

	/**
	 * user interaction method to read maintenance date information
	 * @return the maintenance date
	 */
	Date * getMaintenanceDate();

	/**
	 * method to create new vehicle
	 */
	void createVehicle();

	/**
	 * opens new vehicle menu
	 */
	void newVehicleMenuController();

public:
	/**
	 * Contructor that initalizes all variables
	 * @param company pointer to the company object
	 */
	NewVehicleController(Company *company);

	/**
	 * destructor
	 */
	virtual ~NewVehicleController();

	/**
	 * prints initial message and calls the user interaction method
	 */
	void menu();
};

#endif /* SRC_NEWVEHICLECONTROLLER_H_ */
